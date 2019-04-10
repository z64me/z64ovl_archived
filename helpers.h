#ifndef Z64OVL_HELPERS_H_INCLUDED
#define Z64OVL_HELPERS_H_INCLUDED

/****
 * helpers.h
 * A collection of functions and macros to
 * help simplify custom enemies/NPCs/bosses.
 ***/


/****
 * helper_get_link_actor
 * Returns a pointer to Link's actor
 ***/
static z64_actor_t *helper_get_link_actor(z64_global_t *global) {
	uint8_t *g = (uint8_t*) global + 0x1C44;
	uint32_t p32 = (g[0]<<24)|(g[1]<<16)|(g[2]<<8)|g[3];
	return (z64_actor_t*)p32;
}

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

 /* Shorthand for referencing Graphics Context display list buffers "Zelda Quick Display List" */
 #define ZQDL(ZQDL_A0, ZQDL_A1) ZQDL_A0->common.gfx_ctxt->ZQDL_A1

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

/****
* Overlay Display List Drawing
*****/

typedef struct {
  u32 timg;
  f32 width;
  f32 height;
  u8  fmt;
  u8  bitsiz;
} gfx_texture_t;

typedef struct {
  f32 x;
  f32 y;
  u8  origin_anchor;
  f32 width;
  f32 height;
} gfx_screen_tile_t;

#define G_TX_ANCHOR_C 0b0000
#define G_TX_ANCHOR_U 0b0001
#define G_TX_ANCHOR_R 0b0010
#define G_TX_ANCHOR_D 0b0100
#define G_TX_ANCHOR_L 0b1000
#define to_rgba16(r, g, b, a) (((r >> 3) & 0x1F) << 11) | (((g >> 3) & 0x1F) << 6) | (((b >> 3) & 0x1F) << 1) | (((a >> 7) & 0x1) << 0)

static void draw_ui_sprite(z64_disp_buf_t *buf, gfx_texture_t *img, gfx_screen_tile_t *tile)
{
  switch (tile->origin_anchor)
  {
    case 0b0000: /* Center */
      tile->x -= (tile->width/2); tile->y -= (tile->height/2);
    break;
    case 0b0001: /* Up */
      tile->height /= 2;
    break;
    case 0b0010: /* Right */
      tile->x -= tile->width;
    break;
    case 0b0100: /* Down */
      tile->y -= tile->height;
    break;
    case 0b1000: /* Left */
      tile->width /= 2;
    break;
  }

  gSPDisplayList(buf->p++, 0x801269D0);
  //gsDPSetCombine()
  buf->p->hi = 0xFC309661;
  buf->p->lo = 0x552EFF7F;
  buf->p++;
  gDPSetPrimColor(buf->p++, 0, 0, 255, 255, 255, 255);
  gDPSetEnvColor(buf->p++, 0, 0, 0, 255);
  //gDPPipeSync(buf->p++);
  gDPLoadTextureBlock(buf->p++,
                      img->timg, img->fmt, img->bitsiz,
                      img->width, img->height,
                      0,
                      G_TX_WRAP, G_TX_WRAP,
                      G_TX_NOMASK, G_TX_NOMASK,
                      G_TX_NOLOD, G_TX_NOLOD);
  gSPTextureRectangle(buf->p++,
                      qs102(tile->x) & ~3,
                      qs102(tile->y) & ~3,
                      qs102(tile->x + tile->width) & ~3,
                      qs102(tile->y + tile->height) & ~3,
                      G_TX_RENDERTILE,
                      qu105(0), qu105(0),
                      qu510(img->width / tile->width), qu510(img->height / tile->height));
}
#endif // Z64OVL_HELPERS_H_INCLUDED
