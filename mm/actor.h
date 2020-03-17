#ifndef __ZELDA64_ACTOR_MM_H__
#define __ZELDA64_ACTOR_MM_H__

typedef enum {
	OVLTYPE_SWITCH = 0x00,
	OVLTYPE_BG = 0x01,
	OVLTYPE_PLAYER = 0x02,
	OVLTYPE_EXPLOSIVE = 0x03,
	OVLTYPE_NPC = 0x04,
	OVLTYPE_ENEMY = 0x05,
	OVLTYPE_PROP = 0x06,
	OVLTYPE_ITEM = 0x07,
	OVLTYPE_MISC = 0x08,
	OVLTYPE_BOSS = 0x09,
	OVLTYPE_DOOR = 0x0A,
	OVLTYPE_CHEST = 0x0B
} z64_actor_type_t;

typedef struct z64_actor_init_s{
	int16_t number;    /* Actor Number */
	uint8_t type;      /* Actor Type */
	uint8_t room;      /* Room that the instance was spawned in*/
	int32_t flags;         /* Not completely documented */
	int16_t object;    /* Object Number */
	int16_t padding;
	int32_t instance_size; /* Size of the actor instance */
	void *init;        /* Constructor */
	void *dest;        /* Destructor */
	void *main;        /* Main Update Function */
	void *draw;        /* Draw Function */
} z64_actor_init_t;

typedef struct collision_check_s { /* Substruct 0x0098 */
	z64_damagechart_t *damage_table;
	vec3f_t           vel_2;
	int16_t           unk_0B_0;
	int16_t           unk_0B_1;
	uint16_t          unk_0B_2;
	uint8_t           mass;
	uint8_t           health;
	uint8_t           damage;
	uint8_t           damage_effect;
	uint8_t           impact_effect;
	int8_t            unk_0D;
} z64_collision_check_t;

/* Actor Structure : */
typedef struct z64_actor_s z64_actor_t;
struct z64_actor_s
{
	int16_t           actor_id;                 /* 0x0000 */
	uint8_t           actor_type;               /* 0x0002 */
	int8_t            room_index;               /* 0x0003 */
	uint32_t          flags;                    /* 0x0004 */
	vec3f_t           pos_1;                    /* 0x0008 */
	z64_rot_t         rot_init;                 /* 0x0014 */
	char              unk_01_[0x0002];          /* 0x001A */
	uint16_t          variable;                 /* 0x001C */
	uint8_t           alloc_index;              /* 0x001E */
	char              target_distance_index;    /* 0x001F */
	uint16_t          sound_effect;             /* 0x0020 */
	char              unk_03_[0x0002];          /* 0x0022 */
	vec3f_t           pos_2;                    /* 0x0024 */
	int16_t           speedRot_unk30;           /* 0x0030 */ // possibly rot_0...
	int16_t           xz_dir;                   /* 0x0032 */
	int16_t           unk34;                    /* 0x0034 */
	char              unk_04_[0x0002];          /* 0x0036 */
	int8_t            unk_0x38;                 /* 0x0038 */
	uint8_t           unk_0x39;                 /* 0x0039 */
	char              unk_0x3A[0x0002];         /* 0x003A */
	vec3f_t           pos_3;                    /* 0x003C */
	z64_rot_t         rot_1;                    /* 0x0048 */
	char              unk_0x06_[0x0002];        /* 0x004E */
	uint32_t          unk_0x050;                /* 0x0050 */
	float             unk_0x054;                /* 0x0054 */
	vec3f_t           scale;                    /* 0x0058 */
	vec3f_t           vel_1;                    /* 0x0064 */
	float             xz_speed;                 /* 0x0070 */
	float             gravity;                  /* 0x0074 */
	float             min_vel_y;                /* 0x0078 */
	z64_col_poly_t   *wall_poly;                /* 0x007C */
	z64_col_poly_t   *floor_poly;               /* 0x0080 */
	uint8_t           wall_poly_source;         /* 0x0084 */
	uint8_t           floor_poly_source;        /* 0x0085 */
	int16_t           wall_rot;                 /* 0x0086 */
	float             floor_height;             /* 0x0088 */ //maybe?
	float             water_surface_dist;       /* 0x008C */
	uint16_t          bgcheck_flags;            /* 0x0090 */
	int16_t           rot_toward_link_y;        /* 0x0092 */
	float             unk_0x94;                 /* 0x0094 */
	float             dist_from_link_xz;        /* 0x0098 */
	float             dist_from_link_y;         /* 0x009C */
	z64_damage_table_t *damage_table;           /* 0x00A0 */
	vec3f_t           vel_2;                    /* 0x00A4 */
	char              unk_0B_[0x0006];          /* 0x00B0 */
	uint8_t           mass;                     /* 0x00B6 */
	uint8_t           health;                   /* 0x00B7 */
	uint8_t           damage;                   /* 0x00B8 */
	uint8_t           damage_effect;            /* 0x00B9 */
	uint8_t           impact_effect;            /* 0x00BA */
	char              unk_0xBB;                 /* 0x00BB */
	z64_rot_t         rot_2;                    /* 0x00BC */
	char              unk_0F[0x0002];           /* 0x00C2 */
	float             unk_0xC4;                 /* 0x00C4 */
	void              *draw_drop_shadow;        /* 0x00C8 */
	float             shadow_radius;            /* 0x00CC */
	uint8_t           unk_0xD0;                 /* 0x00D0 */
	vec3f_t           unk_0xD4;                 /* 0x00D4 */
	vec3f_t           unk_0xE0;                 /* 0x00E0 */
	vec3f_t           unk_0xEC;                 /* 0x00EC */
	float             unk_0xF8;                 /* 0x00F8 */
	float             draw_distance;            /* 0x00FC */
	float             camera_clip_near;         /* 0x0100 */
	float             camera_clip_far;          /* 0x0104 */
	vec3f_t           pos_4;                    /* 0x0108 */
	uint16_t          unk_10_;                  /* 0x0114 */
	uint16_t          text_id;                  /* 0x0116 */
	int16_t           frozen;                   /* 0x0118 */
	uint16_t          damage_color;             /* 0x011A */
    uint8_t           damage_color_timer;       /* 0x011C */
	uint8_t           active;                   /* 0x011D */
	char              unk_0x11E;                /* 0x011E */
	uint8_t           tatl_enemy_text_id;       /* 0x011F */
	z64_actor_t       *attached_a;              /* 0x0120 */
	z64_actor_t       *attached_b;              /* 0x0124 */
	z64_actor_t       *prev;                    /* 0x0128 */
	z64_actor_t       *next;                    /* 0x012C */
	void              *ctor;                    /* 0x0130 */
	void              *dtor;                    /* 0x0134 */
	void              *main_proc;               /* 0x0138 */
	void              *draw_proc;               /* 0x013C */
	void              *code_entry;              /* 0x0140 */
};                                             /* 0x0144 */

typedef void (z64_actorfunc_t)(void *entity, void *global);

/* This still needs updated! */
typedef struct
{
	z64_actor_t         actor;                  /* 0x0000 */
	char                unk_0x144[0x928];       /* 0x0144 */
	uint32_t            state_flags_1;          /* 0x0A6C */
	uint32_t            state_flags_2;          /* 0x0A70 */
	char                unk_0xA74[0x5C];        /* 0x0A74 */
	float               linear_velocity;        /* 0x0AD0 */
	uint16_t            movement_angle;         /* 0x0AD4 */
	char                unk_0xAD6[0x05];        /* 0x0AD6 */
	uint8_t             sword_active;           /* 0x0ADB */
	char                unk_0xADC[0x84];        /* 0x0ADC */
	uint16_t            blast_mask_timer;       /* 0x0B60 */
} z64_player_t;

#endif /* __ZELDA64_ACTOR_MM_H__ */
