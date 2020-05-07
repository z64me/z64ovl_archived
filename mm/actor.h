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

/* Actor Structure : */
typedef struct z64_actor_s z64_actor_t;
struct z64_actor_s {                    /* Common Actor Instance Structure */
    int16_t actor_id;                   /* Actor Number */
    uint8_t actor_type;                 /* Actor Type */
    uint8_t room_index;                 /* Room Index (0xFF means actor won't despawn on room change.) */
    uint32_t flags;                     /* Special Actor Flags */
    vec3f_t pos_init;                   /* Initial Position */
    vec3s_t rot_init;                   /* Initial Rotation */
    uint8_t __pad_0x1A[2];              /* initPosRot Padding for 4-byte alignment */
    uint16_t variable;                  /* Actor Variable */
    uint8_t alloc_index;                /* Object Table Allocation Index */
    uint8_t target_dist_index;          /* Indexes into table at 0x80115FFC */
    uint16_t sound_effect;              /* Actor Sound Effect (Relative to Actor Location) */
    uint8_t __pad_0x22[2];              /* Padding for 4-byte alignment */
    vec3f_t pos;                        /* Active Position */
    vec3s_t dir;                        /* Direction / Rotation */
    uint8_t __pad_0x36[2];              /* PosRot Padding for 4-byte alignment */
    uint8_t unk_0x38[4];                /* Undocumented */
    vec3f_t pos_focus;                  /* Position to Focus Camera on (Z-Target) */
    vec3s_t rot_focus;                  /* Rotation to Focus Camera on (Z-Target) */
    uint8_t __pad_0x4A[2];              /* focusPosRot Padding for 4-byte alignment */
    float unk_0x4C;                     /* (NZLE: 8002BF60) */
    float unk_0x54;                     /* Undocumented */
    vec3f_t scale;                      /* Actor Scale */
    vec3f_t velocity;                   /* Velocity */
    float xz_speed;                     /* Speed (X and Z axes) */
    float gravity;                      /* Gravity */
    float min_vel_y;                    /* Minimum Velocity (Y axis) */
    z64_col_poly_t* wall_poly;          /* Wall Polygon (Actor is touching) */
    z64_col_poly_t* floor_poly;         /* Floor Polygon (Actor is over or touching) */
    uint8_t wall_poly_source;           /* Complex Poly Surface Source */
    uint8_t floor_poly_source;          /* Complex Poly Surface Source */
    int16_t wall_rot;                   /* Rotation Towards Wall */
    float floor_height;                 /* Height of Floor (Maybe?) */
    float water_surface_dist;           /* Distance to Water Surface */
    uint16_t bgcheck_flags;             /* Bitfield Determining Collision State */
    int16_t rot_toward_link_y;          /* Y Rotation to face Player */
    float dist_from_link_squared;       /* Square Distance From Player (dist_xz^2) + (dist_y^2) */
    float dist_from_link_xz;            /* Distance From Player (X and Z axes) */
    float dist_from_link_y;             /* Distance From Player (Y axis) */
    void* damage_table;                 /* Collision Check Substruct / Decomp's "SubActorStruct98" */
    vec3f_t displacement;               /* Amount to correct velocity by when colliding into a body */
    int16_t unk_0xA8;                   /* (NZLE: 80061ED4) */
    int16_t unk_0xAA;                   /* (NZLE: 80061ED4) */
    uint8_t __pad_0xAC[2];              /* Padding for 4-byte alignment */
    uint8_t mass;                       /* Used to Calculate Displacement (0xFF is Infinite Mass, 50 is common.) */
    uint8_t health;                     /* Health */
    uint8_t damage;                     /* Damage Dealt, Decrement Health by this amount. */
    uint8_t damage_effect;              /* Elemental Damage Effect */
    uint8_t impact_effect;              /* Set on Deku Nut when Deku Nut collides with Gossip Stone */
    uint8_t unk_0xB3;                   /* Undocumented */
    vec3s_t rot;                        /* Current Rotation / Decomp's "ActorShape" Substruct */
    int16_t unk_0xBA;                   /* Undocumented */
    float unk_0xBC;                     /* Model Y Axis Offset; Collision Mesh Related (NZLE: 80030BE8) */
    void* shadow_func;                  /* Draw Function for Drop Shadow */
    float shadow_radius;                /* Drop Shadow Radius */
    uint8_t shadow_alpha;               /* Drop Shadow Opacity */
    uint8_t unk_0xC9;                   /* Used in Z_SHADOW_TEARDROP */
    uint8_t __pad_0xCA[2];              /* Padding for 4-byte alignment */
    vec3f_t unk_0xCC;                   /* Used in Z_SHADOW_TEARDROP */
    vec3f_t unk_0xD8;                   /* Undocumented */
    vec3f_t unk_0xE4;                   /* (NZLE: 800314D4), Position Vector */
    float unk_0xF0;                     /* (NZLE: 800314D4) */
    float draw_dist;                    /* Draw Distance */
    float cam_clip_near;                /* Camera Clipping Distance (Near) */
    float cam_clip_far;                 /* Camera Clipping Distance (Far) */
    vec3f_t pos_5;                      /* Final Position (5); Last Frame */
    uint8_t unk_0x10C;                  /* Used for Tade Sequence */
    uint8_t unk_0x10D;                  /* Undocumented */
    uint16_t text_id;                   /* Actor Message ID */
    int16_t frozen;                     /* Used in "ReDead Freeze Attack" */
    uint16_t damage_color;              /* First 12 bits control color which can only be blue, red, or white. The last 4 bits are unknown, but they can't be zero. */
    uint8_t damage_color_timer;         /* Damage Color Effect Timer */
    uint8_t active;                     /* Determines if Actor Instance should be processed. 01 = True, 00 = False */
    uint8_t unk_0x116;                  /* Sets a collision related routine. (NZLE: 8003573C) */
    uint8_t tatl_enemy_text_id;         /* Tatl Info Message ID */
    z64_actor_t* attached_a;            /* Attached Actor A (Interfacing Actor) */
    z64_actor_t* attached_b;            /* Attached Actor B (Attached to Actor) */
    z64_actor_t* prev;                  /* Previous Actor */
    z64_actor_t* next;                  /* Next Actor */
    void* ctor;                         /* Constructor */
    void* dtor;                         /* Destructor */
    void* main_proc;                    /* Main Function */
    void* draw_proc;                    /* Draw Function */
    void* code_entry;                   /* Code Entry */
};

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
