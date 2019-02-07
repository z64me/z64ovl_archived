#ifndef __Z64OVL_OOT_TYPES_H__
#define __Z64OVL_OOT_TYPES_H__

#include <stdint.h>
#include "n64.h"
#include "mips.h"

// Controller Input
typedef enum {
	INPUT_NONE = 0b0000000000000000,
	INPUT_C_RIGHT = 0b0000000000000001,
	INPUT_C_LEFT = 0b0000000000000010,
	INPUT_C_DOWN = 0b0000000000000100,
	INPUT_C_UP = 0b0000000000001000,
	INPUT_R_TRIGGER = 0b0000000000010000,
	INPUT_L_TRIGGER = 0b0000000000100000,
	INPUT_D_RIGHT = 0b0000000100000000,
	INPUT_D_LEFT = 0b0000001000000000,
	INPUT_D_DOWN = 0b0000010000000000,
	INPUT_D_UP = 0b0000100000000000,
	INPUT_START = 0b0001000000000000,
	INPUT_Z = 0b0010000000000000,
	INPUT_B = 0b0100000000000000,
	INPUT_A = 0b1000000000000000
} z64_button_t;

typedef struct {
	z64_button_t	button;
	char	stick_x;
	char	stick_y;
	char	errno;
} OSContPad;

typedef struct {
	OSContPad current;
	OSContPad last;
	OSContPad pressEdge;
	OSContPad releaseEdge;
} z64_controller_t;

// Global Context
typedef struct{
	int *gfx_ctxt;
	int *update;
	int *destuctor;
	int *init_next;
	int size;
	z64_controller_t controller[4];
	uint32_t heap_size;
	int *heap;
	int *heap_free_start;
	int *heap_free_end;
	int *unk1;
	int *unk2;
	int *unk3;
	int *unk4;
	int *unk5;
	int execute;
	int update_count;
	int unk6;
} z64_game_state_t;

// Graphics Context
typedef struct{
	int size;
	int *disp;
	int *append;
	int *append_end;
} z64_disp_t;

typedef struct{
	int *w_poly_opa_start;
	int *w_poly_xlu_start;
	int *w_overlay_start;
	OSMesg unk1[8];
	OSMesgQueue unk2;
	int unk3; //Set to 1
	int unk4; //Set to 4
	int *ucode_pointer;
	int ucode_length;
	int *ucode_pointer_2; //?
	int ucode_length_2; //?
	int *dmem_data;
	int unk5; //Set to 0x0800
	int *unk6; //Set to 0x8016A240
	int unk7; // Set to 0x0400
	int unk8; // Set to 0x80151640
	int unk9; //Set to 0x80169640
	int *c_work_disp_start;
	int c_work_disp_size;
	int *unk_buffer_start;
	int unk_buffer_size;
	int *w_work_disp_start;
	z64_disp_t work;
	z64_disp_t overlay;
	z64_disp_t poly_opa;
	z64_disp_t poly_xlu;
	int frame_counter_1;
	int *w_framebuffer;
	int frame_counter_2;
	int *function; //?
	int *global_context;
} z64_graphics_context_t;

enum DISP{
	WORK = 0x01BC,
	OVERLAY = 0x02B0,
	POLY_OPA = 0x02C0,
	POLY_XLU = 0x02D0
};

/* Actor Specific? */
typedef struct {
  /* 0x00 */ uint8_t limb_count;
  /* 0x01 */ uint8_t unk1; /* Probably Padding*/
  /* 0x02 */ uint8_t dlist_count;
  /* 0x03 */ uint8_t unk2; /* Probably Padding */
  /* 0x04 */ uint32_t limb_index;
  /* 0x08 */ uint32_t anim_current;
  /* 0x0C */ int unk3; /* 0x00000000 */
  /* 0x10 */ float anim_frame_count;
  /* 0x14 */ float unk4;
  /* 0x18 */ float anim_current_frame;
  /* 0x1C */ float anim_playback_speed;
  /* 0x20 */ uint32_t unk5; /* Actor Drawing Table? */
  /* 0x24 */ uint32_t unk6;
  /* 0x28 */ uint32_t unk7;
  /* 0x2C */ uint32_t unk8;
  /* 0x30 */ uint32_t func_unk9; /* Some function pointer */
  /* 0x34 */ int pad1; /* 0x00000000 */
  /* 0x38 */ int pad2; /* 0x00000000 */
  /* 0x3C */ uint16_t unk10;
  /* 0x3E */ uint16_t unk11; /* Probably Padding */
  /* 0x40 */
} z64_skelanime_t;

// Actor Collision
typedef struct z64_capsule_init_s {
  /* 0x00 */ uint32_t unk1;
  /* 0x04 */ uint32_t unk2;
  /* 0x08 */ uint32_t unk3;
  /* 0x0C */ uint32_t unk4;
  /* 0x10 */ uint8_t damage_type;
  /* 0x11 */ uint8_t damage_amount;
  /* 0x12 */ uint16_t unk5;
  /* 0x14 */ uint32_t unk6;
  /* 0x18 */ uint32_t unk7;
  /* 0x1C */ uint32_t unk8;
  /* 0x20 */ uint16_t radius;
  /* 0x22 */ uint16_t height;
  /* 0x24 */ uint32_t unk9;
	/* 0x28 */ uint32_t unk10;
  /* 0x2C */
} z64_capsule_init_t;

typedef struct {
	uint8 filling[0x4C];
} z64_capsule_t;

typedef struct vec3f_s {
    f32 x, y, z;
} vec3f_t, z64_point_t;

typedef struct vec3s_s {
	s16 x, y, z;
} vec3s_t;

#endif
