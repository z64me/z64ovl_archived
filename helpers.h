#ifndef Z64OVL_HELPERS_H_INCLUDED
#define Z64OVL_HELPERS_H_INCLUDED

/****
 * helpers.h
 * A collection of functions and macros to
 * help simplify custom enemies/NPCs/bosses.
 ***/
 
 /****
 * makes helper_limb_focus available
 * helper_limb_focus sets the limb to be Z-Targeted as well as camera focus information
 * the address of the function helper_limb_focus can then be used inside actor_skelanime_draw_mtx
 * TODO a2 and a3; names would be nice, although they do seem to be abstracted for us
 * example, from Grog:
 * * #include <z64ovl/helper.h>
 * * ...
 * * HELPER_INCLUDE_helper_limb_focus( 9, 300.0f, 1000.0f, 0.0f )
 * * ...
 * * actor_skelanime_draw_mtx(x, x, x, x, x, &helper_limb_focus, x);
 ***/
#define HELPER_INCLUDE_helper_limb_focus( TARGET_LIMB, IN_VEC3_X, IN_VEC3_Y, IN_VEC3_Z )\
void helper_limb_focus(uint32_t global_context, uint8_t current_limb, uint32_t a2, uint32_t a3, z64_actor_t *actor)\
{\
	if (current_limb == TARGET_LIMB)\
	{\
		vec3f_t in = { IN_VEC3_X, IN_VEC3_Y, IN_VEC3_Z };\
		external_func_800D1AF4(&in, AADDR(actor, 0x0038));\
	}\
}

#endif // Z64OVL_HELPERS_H_INCLUDED
