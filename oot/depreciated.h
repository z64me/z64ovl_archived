#ifndef __ZELDA64_DEPRECIATED_H__
#define __ZELDA64_DEPRECIATED_H__

#include "actor.h"

/* Old structure... */
typedef struct z64_actor_old_s z64_actor_old_t;
struct z64_actor_old_s
{
  int16_t           actor_id;                 /* 0x0000 */
  uint8_t           actor_type;               /* 0x0002 */
  int8_t            room_index;               /* 0x0003 */
  uint32_t          flags;                    /* 0x0004 */
  vec3f_t           pos_1;                    /* 0x0008 */
  z64_rot_t         rot_init;                 /* 0x0014 */
  char              unk_01_[0x0002];          /* 0x001A */
  int16_t           variable;                 /* 0x001C */
  uint8_t           alloc_index;              /* 0x001E */
  char              target_distance_index;    /* 0x001F */ // Indexes into table at 0x80115FFC
  uint16_t          sound_effect;             /* 0x0020 */
  char              unk_03_[0x0002];          /* 0x0022 */
  vec3f_t           pos_2;                    /* 0x0024 */
  int16_t           unk30;                    /* 0x0030 */ // possibly rot_0...
  int16_t           xz_dir;                   /* 0x0032 */
  int16_t           unk34;                    /* 0x0034 */
  uint16_t          unk36;                    /* 0x0036 */
  vec3f_t           pos_3;                    /* 0x0038 */
  z64_rot_t         rot_1;                    /* 0x0044 */
  char              unk_06_[0x0002];          /* 0x004A */
  float             unk_07_;                  /* 0x004C */
  vec3f_t           scale;                    /* 0x0050 */
  vec3f_t           vel_1;                    /* 0x005C */
  float             xz_speed;                 /* 0x0068 */
  float             gravity;                  /* 0x006C */
  float             min_vel_y;                /* 0x0070 */
  /* struct bgcheck common */
  z64_col_poly_t   *wall_poly;                /* 0x0074 */
  z64_col_poly_t   *floor_poly;               /* 0x0078 */
  uint8_t           wall_poly_source;         /* 0x007C */
  uint8_t           floor_poly_source;        /* 0x007D */
  int16_t           wall_rot;                 /* 0x007E */
  float             floor_height;             /* 0x0080 */ //maybe?
  float             water_surface_dist;       /* 0x0084 */
  uint16_t          bgcheck_flags;            /* 0x0088 */
  int16_t           rot_toward_link_y;        /* 0x008A */
  float             unk_0x8C;                 /* 0x008C */
  float             dist_from_link_xz;        /* 0x0090 */
  float             dist_from_link_y;         /* 0x0094 */
  /* struct collision_check common */
  void             *damage_table;             /* 0x0098 */
  vec3f_t           vel_2;                    /* 0x009C */
  int16_t           unk_0B_0;                 /* 0x00A8 */
  int16_t           unk_0B_1;                 /* 0x00AA */
  uint16_t          unk_0B_2;                 /* 0x00AC */
  uint8_t           mass;                     /* 0x00AE */
  uint8_t           health;                   /* 0x00AF */
  uint8_t           damage;                   /* 0x00B0 */
  uint8_t           damage_effect;            /* 0x00B1 */
  uint8_t           impact_effect;            /* 0x00B2 */
  char              unk_0D;                   /* 0x00B3 */
  /* end CollisionCheck common */
  z64_rot_t         rot_2;                    /* 0x00B4 */
  char              unk_0E_[0x0002];          /* 0x00BA */
  float             unk_0xBC;                 /* 0x00BC */
  void             *draw_drop_shadow;         /* 0x00C0 */
  float             shadow_radius;            /* 0x00C4 */
  uint8_t           unk_0xC8;                 /* 0x00C8 */
  char              pad_0xC9_[0x0003];        /* 0x00C9 */
  /* 0x00B4 End */
  z64_xyzf_t        unk_0xCC;                 /* 0x00CC */
  z64_xyzf_t        unk_0xD8;                 /* 0x00D8 */
  z64_xyzf_t        unk_0xE4;                 /* 0x00E4 */
  float             unk_0xF0;                 /* 0x00F0 */
  float             draw_distance;            /* 0x00F4 */ /* based on Link's proximity */
  float             camera_clip_near;         /* 0x00F8 */ /* TODO confirm this is correct */
  float             camera_clip_far;          /* 0x00FC */ /* TODO confirm this is correct */
  z64_xyzf_t        pos_4;                    /* 0x0100 */
  uint8_t           unk_0x10C;                /* 0x010C */ /* used for trade sequence... */
  uint8_t           unk_0x10D;                /* 0x010D */
  uint16_t          text_id;                  /* 0x010E */
  int16_t           frozen;                   /* 0x0110 */
  uint16_t          damage_color;             /* 0x0112 */
  uint8_t           damage_color_timer;       /* 0x0114 */
  uint8_t           active;                   /* 0x0115 */
  uint8_t           unk_11_;                  /* 0x0116 */
  uint8_t           navi_enemy_text_id;       /* 0x0117 */
  z64_actor_old_t      *attached_a;               /* 0x0118 */
  z64_actor_old_t      *attached_b;               /* 0x011C */
  z64_actor_old_t      *prev;                     /* 0x0120 */
  z64_actor_old_t      *next;                     /* 0x0124 */
  void             *ctor;                     /* 0x0128 */
  void             *dtor;                     /* 0x012C */
  void             *main_proc;                /* 0x0130 */
  void             *draw_proc;                /* 0x0134 */
  void             *code_entry;               /* 0x0138 */
#ifdef OOT_DEBUG
  unsigned char    unk0x13C[0x10];            /* 0x013C */ /* debug rom only */
#endif
};                                            /* 0x014C */ /* (length) */

/* Damage chart notes
 * sword0 and sword1 refer to the Kokiri/Master Sword,
   longsword refers to the Biggoron Sword / Giant's Knife,
   and brokensword refers to the broken longsword
 * everything held together in a union { ... } shares the same setting
 */
typedef struct z64_damagechart_init {
// TODO: would there be a hammer_shockwave, or do actors that respond to it do it differently?
	u8
/* 00 */
			misc_dekunut
	;
/* 01 */	union {
				u8
					misc_dekustick,

					misc_pot
				;
			};
	u8
/* 02 */	misc_slingshot,
/* 03 */	misc_explosion,
/* 04 */	misc_boomerang,

/* 05 */	arrow,

/* 06 */	hammer_swing,

/* 07 */	misc_hookshot,

/* 08 */	sword0_slash,
/* 09 */	sword1_slash,
/* 0A */	longsword_slash,

/* 0B */	arrow_fire,
/* 0C */	arrow_ice,
/* 0D */	arrow_light,
/* 0E */	arrow_wind,  // TODO are these really Wind/Spirit/Shadow?
/* 0F */	arrow_spirit,
/* 10 */	arrow_shadow,

/* 11 */	magic_fire,
/* 12 */	magic_ice,   // confirmed
/* 13 */	magic_light, // confirmed

/* 14 */	unk0,
/* 15 */	unk1,

/* 16 */	sword0_spin,
/* 17 */	longsword_spin, // TODO confirm if this is correct
/* 18 */	sword1_spin
	;
/* 19 */	union {
				u8
					sword0_jump,
					sword0_bigspin,

					brokensword_jump,
					brokensword_bigspin
				;
			};
/* 1A */	union {
				u8
					longsword_jump,
					longsword_bigspin
				;
			};
/* 1B */	union {
				u8
					sword1_jump,
					sword1_bigspin
				;
			};
	u8
/* 1C */	unk2,
/* 1D */	unk3,
/* 1E */	hammer_jump,
/* 1F */	unk4
	;
} z64_damagechart_init_t_old;

/* collision */
typedef enum z64_bumper_effect_e { /* Elemental Damage Effects */
    BUMP_FX_ELECTRIC=3,
    BUMP_FX_FIRE=1,
    BUMP_FX_ICE=2,
    BUMP_FX_KNOCKBACK=0
} z64_bumper_effect_t;

typedef enum z64_collider_type_e { /* Collider Types */
    COL_TYPE_CYLINDER=1,
    COL_TYPE_CYLINDER_GROUP=0,
    COL_TYPE_QUAD=3,
    COL_TYPE_TRIANGLE_GROUP=2
} z64_collider_type_t;

typedef struct z64_collider_s { /* Collider Structure */
    z64_actor_t* actor; /* Actor Instance */
    z64_actor_t* unk_actor_1;
    z64_actor_t* colliding_actor; /* Hit with an item */
    z64_actor_t* unk_actor_3;
    uint8_t collider_flags; /* Compared to 0x11 */
    uint8_t collide_flags; /* Compared to 0x10 */
    uint8_t mask_a; /* Bitwise-and compared to 0x13 */
    uint8_t mask_b; /* Bitwise-and compared to 0x12 */
    uint8_t unk_0x14;
    uint8_t type; /* Cylinder Collection, Cylinder, Triangle Collection, Quad */
} z64_collider_t;

typedef struct z64_collider_bump_s {
    int32_t flags; /* Collision Exclusion Mask */
    uint8_t effect; /* Damage Effect (Knockback, Fire, etc.) */
    uint8_t unk_0x05;
    int32_t unk_0x08;
} z64_collider_bump_t;

typedef struct z64_collider_touch_s {
    int32_t flags; /* Toucher Attack Identifier Flags */
    uint8_t unk_0x04;
    uint8_t damage; /* Damage or Stun Timer */
} z64_collider_touch_t;

typedef struct z64_collider_body_s { /* Collider Body typedef structure */
    z64_collider_touch_t toucher;
    z64_collider_bump_t bumper;
    uint8_t flags;
    uint8_t toucher_flags;
    uint8_t bumper_flags;
    uint8_t flags_2;
    int32_t unk_0x18;
    z64_collider_t * collider;
    int32_t unk_0x20;
    void * colliding;
} z64_collider_body_t;

typedef struct z64_collider_cylinder_s {
    z64_collider_body_t body;
    vec3s_t unk_0x28;
    int16_t unk_0x2E;
    vec3s_t position;
    int16_t unk_0x36;
    int32_t unk_0x38;
    uint8_t unk_0x3C;
} z64_collider_cylinder_t;

typedef struct z64_collider_tri_s {
    z64_collider_body_t body;
    vec3f_t point_a;
    vec3f_t point_b;
    vec3f_t point_c;
    vec3f_t unit_normal;
    float normal_dist;
} z64_collider_tri_t;

typedef struct z64_collider_cylinder_collection_s {
    z64_collider_t base;
    int32_t count;
    z64_collider_cylinder_t * list;
} z64_collider_cylinder_collection_t;

typedef struct z64_collider_cylinder_collection_init_s {
  uint8_t unk_0x0000;
  uint8_t unk_0x0001;
  uint8_t unk_0x0002;
  uint8_t unk_0x0003;
  uint8_t unk_0x0004;
  uint8_t pad_0x0005; /* Likely Padding for Alignment */
  uint32_t collider_n; /* Number of Colliders */
  void* pointer; /* Pointer to Collider Initialization Data */
} z64_collider_cylinder_collection_init_t;

typedef struct z64_collision_body_info_s { /* Initialization Variables (in overlay) for z64_collider */
    uint8_t unk_0x14;
    uint8_t collider_flags; /* Collider Flags */
    uint8_t collide_flags; /* Collide Flags */
    uint8_t mask_a; /* Bitwise-And with Mask B */
    uint8_t mask_b; /* Bitwise-And with Mask A */
    uint8_t type; /* Collider Type */
    uint8_t unk_0x06_[2]; /* 0000 */
    uint8_t body_flags;
    uint8_t unk_0x09_[3]; /* 000000 */
    int32_t toucher_mask; /* Attack Toucher Exclusion Mask */
    uint8_t bumper_effect; /* Damage Effect (Knockback, Fire, etc.) */
    uint8_t toucher_damage; /* Damage Amount or Stun Timer */
    uint8_t unk_0x12_[2]; /* 0000 */
    int32_t bumper_mask; /* Bumper Exclusion Mask */
    uint8_t unk_0x18_[4]; /* 00000000 */
    uint8_t toucher_flags; /* Attack Toucher Flags */
    uint8_t bumper_flags; /* Bumper Flags */
    uint8_t body_flags_2;
    uint8_t unk_0x1F; /* 00 */
} z64_collision_body_info_t;

typedef struct z64_collider_cylinder_init_s { /* Initialization Variables (in overlay) for z64_collider_cylinder_main_t */
    z64_collision_body_info_t body;
    int16_t radius; /* Cylinder Radius */
    int16_t height; /* Cylinder Height */
    int16_t y_shift; /* Shift Cylinder on Y Axis */
    vec3s_t position; /* {X, Y, Z} position of Cylinder */
} z64_collider_cylinder_init_t;

typedef struct z64_collider_cylinder_main_s { /* Previously (z64_capsule) */
    z64_collider_t base;
    z64_collider_body_t body;
    int16_t radius;
    int16_t height;
    int16_t y_shift;
    vec3s_t position;
} z64_collider_cylinder_main_t;

typedef struct z64_collider_quad_s {
    z64_collider_t base;
    z64_collider_body_t body;
    vec3f_t point_a;
    vec3f_t point_b;
    vec3f_t point_c;
    vec3f_t point_d;
    vec3s_t bounding_max;
    vec3s_t bounding_min;
} z64_collider_quad_t;

typedef struct z64_collider_tri_collection_s {
    z64_collider_t base;
    int32_t count;
    z64_collider_tri_t * list;
} z64_collider_tri_collection_t;

typedef struct {
  uint8_t unk_9_[8];
  uint16_t unk_1;
  uint16_t hitbox_count;
  void *hitbox_data;
} z64_hitbox_header_t;

#endif
