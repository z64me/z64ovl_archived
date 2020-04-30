#ifndef Z64OVL_REAL_H_INCLUDED
#define Z64OVL_REAL_H_INCLUDED

/* real.h */
/* uglier functions that get masked by cleaner functions reside here */
/* they are all prefixed with _ */

/* Draw a `skelanime` structure.
* This does not support `matrix-enabled` skeletons.
* Debug strings dub this function `Si2_draw()` (Skeleton Info 2; Draw)?
* Source Code Reference File: "z_skelanime.c"
* Formerly `skelanime_draw`
*/
extern void _z_skelanime_draw(
z64_global_t* gl /* Global Context */
, void* limb_index /* Skelanime Limb Index */
, void* dtstart /* Skelanime Draw Table Start */
, int32_t callback0( /* This must return 0 */
	z64_global_t* gl /* Global Context */
	, int32_t limb /* Current Limb */
	, uint32_t* dlist /* Display List Pointer */
	, vec3f_t* translation /* Limb Translation */
	, vec3s_t* rotation /* Limb Rotation */
	, void* instance /* Current instance pointer (entity_t) */
	)
, void callback1( /* An internal callback function. */
	z64_global_t* gl /* Global Context */
	, int32_t limb /* Current Limb */
	, uint32_t dlist /* Display List */
	, vec3s_t* rotation /* Limb Rotation */
	, void* instance /* Current instance pointer (entity_t) */
	)
, void* instance /* A pointer to the actor instance containing the skelanime structure. */
);
#if OOT_DEBUG
  asm("_z_skelanime_draw = 0x800A15C8");
#elif OOT_U_1_0
  asm("_z_skelanime_draw = 0x8008993C");
#elif MM_U_1_0
  asm("_z_skelanime_draw = 0x80133B3C");
#endif

/**
 * Draw Matrix-Enabled Object
 * callback0 and callback1 should be NULL, or pointers
   to functions of their respective descriptions
 * TODO Variable name cleanup, better notes
 * A0 = Global Context | A1 = Hierarchy Limb Index (in Object File, in RAM) | A2 = Pointer to Actor Drawing Table | A3 = Number of Limbs that use display lists. | 0x0010(SP) = 0 | 0x0014(SP) = 0 | 0x0018(SP) = Actor Instance Address
 * TODO confirm dlist argument of callback0
 */
extern
void
_z_skelanime_draw_mtx(
  z64_global_t *global
, void* limb_index
, void* adt
, uint8_t limb_dlists_count
, int32_t callback0(            /* callback0 must return 0 */
	  z64_global_t *global
	, int limb               /* limb index in skeleton */
	, uint32_t *dlist        /* *dlist = 0x06xxxxxx changes limb model */
	, vec3f_t *translation
	, vec3s_t *rotation
	, void *entity
  )
, void callback1(
	  z64_global_t *global
	, int limb
	, uint32_t dlist         /* different from callback0, needs more research */
	, vec3s_t *rotation
	, void *entity
  )
, void *entity
);
#if OOT_DEBUG
	asm("_z_skelanime_draw_mtx = 0x800A1AC8");
#elif OOT_U_1_0
	asm("_z_skelanime_draw_mtx = 0x80089D8C");
#elif MM_U_1_0
	asm("_z_skelanime_draw_mtx = 0x80133F28");
#endif

/* Initialize a "Skelanime Structure"
* This does not support matrices.
* Source Code Reference File: "z_skelanime.c"
* Formerly `skelanime_init`
*/
extern void _z_skelanime_init(
z64_global_t* gl /* Global Context */
, z64_skelanime_t* sk /* Skelanime Structure */
, uint32_t skeleton /* Segment-relative offset of Skeleton */
, uint32_t anim /* Segment-relative offset of animation to initialize with */
, vec3s_t* dt_rot /* Limb-based variable size structure (Draw Table Rotations) If 0, the game automatically allocates memory for this. */
, vec3s_t* dt_pos /* Limb-based variable size structure (Draw Table Positions) If 0, the game automatically allocates memory for this. */
, uint32_t nlimb /* Total Limb Count + 1 */
);
#if OOT_DEBUG
  asm("_z_skelanime_init = 0x800A457C");
#elif OOT_U_1_0
  asm("_z_skelanime_init = 0x8008C684");
#elif MM_U_1_0
  asm("_z_skelanime_init = 0x80136A7C");
#endif

/* Initialize a "Skelanime Structure"
* This supports matrices
* Source Code Reference File: "z_skelanime.c"
* Formerly `skelanime_init_mtx`
* like z_skelanime_init, but with matrix support
*/
extern void _z_skelanime_mtx_init(
z64_global_t* gl /* Global Context */
, z64_skelanime_t* sk /* Skelanime Structure */
, uint32_t skeleton /* Segment-relative offset of Skeleton */
, uint32_t anim /* Segment-relative offset of animation to initialize with */
, vec3s_t* dt_rot /* Limb-based variable size structure (Draw Table Rotations) If 0, the game automatically allocates memory for this. */
, vec3s_t* dt_pos /* Limb-based variable size structure (Draw Table Positions) If 0, the game automatically allocates memory for this. */
, uint32_t nlimb /* Total Limb Count + 1 */
);
#if OOT_DEBUG
  asm("_z_skelanime_mtx_init = 0x800A46F8");
#elif OOT_U_1_0
  asm("_z_skelanime_mtx_init = 0x8008C788");
#elif MM_U_1_0
  asm("_z_skelanime_mtx_init = 0x80136B30");
#endif

#endif /* Z64OVL_REAL_H_INCLUDED */
