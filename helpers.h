#ifndef Z64OVL_HELPERS_H_INCLUDED
#define Z64OVL_HELPERS_H_INCLUDED

/****
 * helpers.h
 * A collection of functions and macros to
 * help simplify custom enemies/NPCs/bosses.
 ***/

 /*static void add_dlist_to_gfx_buffer(z64_global_t *global, z64_disp_buf_t *buffer, uint32_t dlist)
 {
   uint32_t mtx = matrix_alloc(&global->common.gfx_ctxt, 0, 0);  //Allocate Display List Matrix
   uint32_t gfx_array[4] = {                                     //F3DZEX to add to graphics buffer
     0xDA380003,
     mtx,
     0xDE000000,
     dlist
   }
   add_to_gfx_buffer(buffer, gfx_array, 4);                     //Append F3DZEX Data
 }*/

 /****
 * makes helper_limb_focus available
 * helper_limb_focus sets the limb to be Z-Targeted as well as camera focus information
 * the address of the function helper_limb_focus can then be used inside actor_skelanime_draw_mtx
 * TODO a2 and a3; names would be nice, although they do seem to be abstracted for us
 * example, from Grog:
 * * #include <z64ovl/helpers.h>
 * * ...
 * * HELPER_INCLUDE_helper_limb_focus( 9, 300.0f, 1000.0f, 0.0f )
 * * ...
 * * actor_skelanime_draw_mtx(x, x, x, x, x, &helper_limb_focus, x);
 ***/
#define HELPER_INCLUDE_helper_limb_focus( TARGET_LIMB, IN_VEC3_X, IN_VEC3_Y, IN_VEC3_Z )\
static void helper_limb_focus(z64_global_t *global, uint8_t current_limb, uint32_t limb_dlist, vec3s_t *limb_rot, z64_actor_t *actor)\
{\
	if (current_limb == TARGET_LIMB)\
	{\
		vec3f_t in = { IN_VEC3_X, IN_VEC3_Y, IN_VEC3_Z };\
		external_func_800D1AF4(&in, &actor->pos_3);\
	}\
}

/****
 * basic eye blink function
 * returns a value 0, 1, or 2, for use with an array of eye texture offsets, corresponding to open, half-open, and closed eye textures, respectively
 * this function is identical to how NPC eye blinking works in OoT:
 * 1 the random value range (30, 30) comes from OoT
 * 2 eyes are open for a random number of frames
 * 3 half-open for one frame
 * 4 closed for one frame
 * 5 back open, restart from the beginning with a new random value
 ***/
static u8 helper_eye_blink(s16 *frame) {
	if( *frame == 0 ) // get random number of frames until next blink
		*frame = math_rand_s16_offset(30, 30);
	*frame -= 1;
	if( *frame > 1 ) // open
		return 0;
	return 2 - *frame; // half-open for a frame, then closed for a frame
}

/* Shorthand for referencing Graphics Context display list buffers "Zelda Quick Display List" */
#define ZQDL(ZQDL_A0, ZQDL_A1) ZQDL_A0->common.gfx_ctxt->ZQDL_A1

#endif // Z64OVL_HELPERS_H_INCLUDED
