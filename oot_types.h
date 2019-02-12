#ifndef __Z64OVL_OOT_TYPES_H__
#define __Z64OVL_OOT_TYPES_H__

#include <stdint.h>
#include "n64.h"
#include "mips.h"
#include "actor_oot.h"

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

// Graphics Context
typedef struct
{
  uint32_t          size;                     /* 0x0000 */
  uint32_t         *buf;                      /* 0x0004 */
  uint32_t         *p;                        /* 0x0008 */
  uint32_t         *d;                        /* 0x000C */
                                              /* 0x0010 */
} z64_disp_buf_t;

typedef struct
{
  Gfx              *poly_opa_w;               /* 0x0000 */
  Gfx              *poly_xlu_w;               /* 0x0004 */
  char              unk_00_[0x0008];          /* 0x0008 */
  Gfx              *overlay_w;                /* 0x0010 */
  char              unk_01_[0x0024];          /* 0x0014 */
  OSMesg            task_msg[8];              /* 0x0038 */
  char              unk_02_[0x0004];          /* 0x0058 */
  OSMesgQueue       task_mq;                  /* 0x005C */
  char              pad_00_[0x0004];          /* 0x0074 */
  OSScTask          task;                     /* 0x0078 */
  char              unk_03_[0x00E0];          /* 0x00D0 */
  Gfx              *work_w;                   /* 0x01B0 */
  z64_disp_buf_t    work;                     /* 0x01B4 */
  char              unk_04_[0x00E4];          /* 0x01C4 */
  z64_disp_buf_t    overlay;                  /* 0x02A8 */
  z64_disp_buf_t    poly_opa;                 /* 0x02B8 */
  z64_disp_buf_t    poly_xlu;                 /* 0x02C8 */
  uint32_t          frame_count_1;            /* 0x02D8 */
  void             *frame_buffer;             /* 0x02DC */
  char              unk_05_[0x0008];          /* 0x02E0 */
  uint32_t          frame_count_2;            /* 0x02E8 */
                                              /* 0x02EC */
} z64_gfx_t;

// Global Context
typedef struct{
	z64_gfx_t *gfx_ctxt;
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

typedef struct{
	/* 0x000 */ z64_game_state_t common;
	/* 0x0A4 */ uint16_t current_scene;
	/* 0x0A6 */ uint8_t unk1[0x1A];
	/* 0x0C0 */ uint32_t screen_top;
	/* 0x0C4 */ uint32_t screen_bottom;
	/* 0x0C8 */ uint32_t screen_left;
	/* 0x0CC */ uint32_t screen_right;
	/* 0x0D0 */ float camera_distance;
	/* 0x0D4 */ float fog_distance;
	/* 0x0D8 */ float z_distance;
	/* 0x0DC */ float unk_cam; /* Leave at 1.0 */
	/* 0x0E0 */ uint8_t unk2[0x194];
	/* 0x1E0 = Camera Context */
	/* 0x270 */ z64_actor_t *actor_cam_follow; /* Actor that the camera follows.*/
	/* 0x274 */ uint8_t unk3[0x19B8];
	/* 0x1C2C */ uint8_t actor_total;
	/* 0x1C30 */ z64_actor_t *actor_list[12][2];
	/* 0x1C86 */ uint8_t unk4[0x42];
	/* 0x1CC8 */ z64_actor_t *actor_zcursor_follow; /* Actor that the z-target cursor is over */
	/* 0x1CCC */ z64_actor_t *actor_targeted;
	/* 0x1CD0 */ uint8_t unk5[0x58];
	/* 0x1D28 */ //Will finish later.
} z64_global_t;

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

typedef struct z64_capsule_s {
	z64_actor_t *actor; // actor instance; TODO Is this a z64_actor_t or a typeless instance?
	u32 unk_0x4;
	z64_actor_t *colliding_actor; // colliding actor instance?; TODO Is this a z64_actor_t or a typeless instance?
	u32 unk_0xC;
	// TODO Needs better naming. Also, why are these values out of order?
	u8
		cso_0x01,
		cso_0x02, //if & 0x0002, is detecting a Deku Nut hit?
		cso_0x03, //bitwise-and compared to opposing collision's 0x13 byte
		cso_0x04, //bitwise-and compared to opposing collision's 0x12 byte
		cso_0x00,
		cso_0x05, //used to reference function pointer, start location at 800EFB4C.
				  //Basically, on left compare to right, left's value * 0x10 + right's value * 0x04 = pointer look up
		unk_0x16, // curious that two unknowns somehow lie here; likely cso_0x06
		unk_0x17 // and cso_0x07; types also unknown
	;
	u32 cso_0x0C;
	u8
		cso_0x10,
		cso_0x11, // damage dealt when touched
		unk_0x1E, // unknown, likely cso_0x12
		unk_0x1F // and cso_0x13; types also unknown
	;
	u32 cso_0x14; // (FFCF FFFF)
	u8
		cso_0x18,
		cso_0x19,
		unk_0x26, // unknown, likely also "cso" stuff
		unk_0x27, // types also unknown
		unk_0x28,
		unk_0x29,
		unk_0x2A,
		unk_0x2B,
		cso_0x08,
		cso_0x1C,
		cso_0x1D,
		cso_0x1E
	;
	u8 unk[16];
	s16
		radius, // or diameter? CSO 0x20
		height, // CSO 0x22
		unk_0x44, // CSO 0x24
		x, // coordinates
		y,
		z
	;
} z64_capsule_t;

typedef struct vec3f_s {
    f32 x, y, z;
} vec3f_t, z64_point_t;

typedef struct vec3s_s {
	s16 x, y, z;
} vec3s_t;

typedef struct
{
  float             x;                        /* 0x0000 */
  float             y;                        /* 0x0004 */
  float             z;                        /* 0x0008 */
                                              /* 0x000C */
} z64_xyzf_t;

#endif
