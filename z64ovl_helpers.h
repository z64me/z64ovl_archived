#ifndef Z64OVL_HELPERS_H_INCLUDED_MAIN
#define Z64OVL_HELPERS_H_INCLUDED_MAIN

/****
 * helpers.h
 * A collection of functions and macros to
 * help simplify custom enemies/NPCs/bosses.
 ***/

#if 0
	/* helpers.h is meant to work with both OoT and MM.   *
	 * This way, shared helpers needn't be maintained     *
	 * separately, names remain consistent, and compiling *
	 * overlays for both games will be easier.            *
	 * Write helpers using the following structure:       */
	static
	inline
	z64_player_t *
	zh_get_player(z64_global_t *global)
	{
	#if ZH_OOT
		/* OoT-specific code */
	#elif ZH_MM
		/* MM-specific code */
	#endif
	}
#endif

#if OOT_DEBUG || OOT_U_1_0
#	define ZH_OOT 1
#elif MM_U_1_0
#	define ZH_MM  1
#else
#	error z64_helpers.h: must define OOT_DEBUG, OOT_U_1_0, or MM_U_1_0 before including!
#endif

/*** Macros ***/

 /* Shorthand for referencing Graphics Context display list buffers "Zelda Quick Display List" */
#define ZQDL(ZQDL_A0, ZQDL_A1) ZQDL_A0->common.gfx_ctxt->ZQDL_A1

/****
 * convert a relative segment address to an absolute RAM address
 ***/
static
inline
uint32_t
zh_seg2ram(uint32_t addr)
{
	return (
		AVAL(
			(RAM_SEGMENT_TABLE + (addr >> 22) )
			, uint32_t
			, 0
		) + (addr & 0x00FFFFFF)) | 0x80000000
	;
}

/****
 * test for Link's age
 ***/
static
inline
int
zh_link_is_child(void)
{
	return AVAL(SAVE_CONTEXT, int, 0x0004);
}

static
inline
int
zh_link_is_adult(void)
{
	return !zh_link_is_child();
}

/****
 * zh_player_textbox_selection
 * use this function if player_responded_to_textbox() returns true (1).
 * returns the last textbox selection made by the player
 * 0 = first option was selected
 * 1 = second
 * 2 = third
 ***/
static
inline
int
zh_player_textbox_selection(z64_global_t *global)
{
	/* TODO use named structure element instead *
	 *      of AVAL + magic number              */
	return
		AVAL(
			global
			, uint8_t
			#if ZH_OOT
			, 0x104BD
			#elif ZH_MM
			, 0x16929
			#warning needs (NZSE) confirmation!
			#endif
		)
	;
}


/****
 * zh_get_pointer_to_object_data
 * given an object ID, returns a pointer to its location in ram, or NULL if not loaded
 ***/
static
inline
void *
zh_get_pointer_to_object_data(uint16_t object_id, z64_global_t *global)
{
	/* TODO use named structure element *
	 *      instead of magic number     */

	int index;

	index =
		object_get_index
		(
			(u32)AADDR
			(
				global
				#if ZH_OOT
				, 0x117A4
				#elif ZH_MM
				, 0x17D88
				#warning needs (NZSE) confirmation!
				#endif
			)
			, object_id
		)
	;

	if(index < 0)
		return NULL;

	return
		*(u32*)AADDR
		(
			(((index << 4) + index) << 2) + (u32)global
			, 0x117B4
		)
	;
}


/****
 * zh_get_save_context
 * Returns a pointer to Save Context
 ***/
static
inline
void *
zh_get_save_context(z64_global_t *global)
{
	/* TODO returning type z64_saveContext_t would be nice */
	/* TODO also, grab it from within global to avoid magic numbers */
	return (void*)AADDR(SAVE_CONTEXT, 0);
}

/****
 * zh_get_player
 * Used to return a pointer to the player's instance.
 ***/
static
inline
z64_player_t *
zh_get_player(z64_global_t *global)
{
	/* TODO cleanup */
	/* TODO eliminate magic numbers; grab from global directly */
	/* TODO must also support MM */
	uint8_t *g = (uint8_t*) global;
#if ZH_OOT
	g += 0x1C44;
#elif ZH_MM
	g += 0x1CCC;
#endif
	uint32_t p32 = (g[0]<<24)|(g[1]<<16)|(g[2]<<8)|g[3];
	return (z64_player_t*)p32;
}

/****
 * Tests if object can be lifted with "grab" action.
 * Give an Item ID of 0
 ****/
static
inline
void
helper_lift_test(
	z64_actor_t *a
	, z64_global_t *gl
	, float range_xz
	, float range_y
)
{
	int temp_v0;
	int phi_v1;

	temp_v0 =
		(int)
		(
			(a->rot_toward_link_y - (zh_get_player(gl)->actor.xz_dir))
			<< 0x10
		) >> 0x10
	;

	phi_v1 = (0 - temp_v0);

	if (temp_v0 >= 0)
		phi_v1 = temp_v0;

	if (phi_v1 >= 0x5556)
		actor_give_item(a, gl, 0, range_xz, range_y);
}

 /****
 * makes helper_limb_focus available
 * helper_limb_focus sets the limb to be Z-Targeted as well as camera focus information
 * the address of the function helper_limb_focus can then be used inside actor_skelanime_draw_mtx
 * TODO a2 and a3; names would be nice, although they do seem to be abstracted for us
 * TODO does this work in MM?
 * example, from Grog:
 * * #include <z64ovl/helpers.h>
 * * ...
 * * HELPER_INCLUDE_helper_limb_focus( 9, 300.0f, 1000.0f, 0.0f )
 * * ...
 * * actor_skelanime_draw_mtx(x, x, x, x, x, &helper_limb_focus, x);
 ***/
#define HELPER_INCLUDE_helper_limb_focus( TARGET_LIMB, IN_VEC3_X, IN_VEC3_Y, IN_VEC3_Z )\
static void helper_limb_focus(z64_global_t *global, uint8_t limb, uint32_t dlist, vec3s_t *rot, z64_actor_t *actor)\
{\
	if (limb == TARGET_LIMB)\
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
static
inline
unsigned char
helper_eye_blink(int16_t *frame) {
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

#define G_TX_ANCHOR_C  0b0000
#define G_TX_ANCHOR_U  0b0001
#define G_TX_ANCHOR_R  0b0010
#define G_TX_ANCHOR_D  0b0100
#define G_TX_ANCHOR_L  0b1000
#define G_TX_ANCHOR_UR G_TX_ANCHOR_U + G_TX_ANCHOR_R
#define G_TX_ANCHOR_DR G_TX_ANCHOR_D + G_TX_ANCHOR_R
#define G_TX_ANCHOR_DL G_TX_ANCHOR_D + G_TX_ANCHOR_L
#define G_TX_ANCHOR_UL G_TX_ANCHOR_U + G_TX_ANCHOR_L
#define G_TX_ANCHOR_UD G_TX_ANCHOR_U + G_TX_ANCHOR_D
#define G_TX_ANCHOR_RL G_TX_ANCHOR_R + G_TX_ANCHOR_L
#define TIMG_A(TA0) G_TX_ANCHOR_##TA0
#define to_rgba16(r, g, b, a) (((r >> 3) & 0x1F) << 11) | (((g >> 3) & 0x1F) << 6) | (((b >> 3) & 0x1F) << 1) | (((a >> 7) & 0x1) << 0)

static
void
zh_draw_ui_sprite(
	z64_disp_buf_t *buf
	, gfx_texture_t *img
	, gfx_screen_tile_t *tile
)
{
	gfx_screen_tile_t tile_copy = *tile;
	tile = &tile_copy;
	if (tile->origin_anchor == 0x0000)
	{
		tile->x -= (tile->width/2); tile->y -= (tile->height/2);
	}
	else
	{
		if (tile->origin_anchor & TIMG_A(U))
			tile->height /= 2;
		if (tile->origin_anchor & TIMG_A(R))
			tile->x -= tile->width;
		if (tile->origin_anchor & TIMG_A(D))
			tile->y -= tile->height;
		if (tile->origin_anchor & TIMG_A(L))
			tile->width /= 2;
	}
	/*switch (tile->origin_anchor)
	{
		case 0b0000: /* Center
			tile->x -= (tile->width/2); tile->y -= (tile->height/2);
		break;
		case 0b0001: /* Up
			tile->height /= 2;
		break;
		case 0b0010: /* Right
			tile->x -= tile->width;
		break;
		case 0b0100: /* Down
			tile->y -= tile->height;
		break;
		case 0b1000: /* Left
			tile->width /= 2;
		break;
	}*/


	gSPDisplayList(buf->p++, 0x801269D0);
	gDPSetCombineLERP(
		buf->p++
		, PRIMITIVE
		, ENVIRONMENT
		, TEXEL0
		, ENVIRONMENT
		, TEXEL0
		, 0
		, PRIMITIVE
		, 0
		, PRIMITIVE
		, ENVIRONMENT
		, TEXEL0
		, ENVIRONMENT
		, TEXEL0
		, 0
		, PRIMITIVE
		, 0
	);
	//buf->p->hi = 0xFC309661;
	//buf->p->lo = 0x552EFF7F;
	//buf->p++;
	gDPSetPrimColor(buf->p++, 0, 0, 255, 255, 255, 255);
	gDPSetEnvColor(buf->p++, 0, 0, 0, 255);
	//gDPPipeSync(buf->p++);
	gDPLoadTextureBlock(
		buf->p++
		, img->timg, img->fmt, img->bitsiz
		, img->width, img->height
		, 0
		, G_TX_WRAP, G_TX_WRAP
		, G_TX_NOMASK, G_TX_NOMASK
		, G_TX_NOLOD, G_TX_NOLOD
	);
	gSPTextureRectangle(
		buf->p++
		, qs102(tile->x) & ~3
		, qs102(tile->y) & ~3
		, qs102(tile->x + tile->width) & ~3
		, qs102(tile->y + tile->height) & ~3
		, G_TX_RENDERTILE
		, qu105(0), qu105(0)
		, qu510(img->width / tile->width)
		, qu510(img->height / tile->height)
	);
}

#endif /* Z64OVL_HELPERS_H_INCLUDED_MAIN */
