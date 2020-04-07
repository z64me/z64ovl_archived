#ifndef __Z64OVL_ACTOR_OOT_H__
#define __Z64OVL_ACTOR_OOT_H__

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
    vec3f_t pos_focus;                  /* Position to Focus Camera on (Z-Target) */
    vec3s_t rot_focus;                  /* Rotation to Focus Camera on (Z-Target) */
    uint8_t __pad_0x4A[2];              /* focusPosRot Padding for 4-byte alignment */
    float unk_0x4C;                     /* (NZLE: 8002BF60) */
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
    uint8_t navi_enemy_text_id;         /* Navi Info Message ID */
    z64_actor_t* attached_a;            /* Attached Actor A (Interfacing Actor) */
    z64_actor_t* attached_b;            /* Attached Actor B (Attached to Actor) */
    z64_actor_t* prev;                  /* Previous Actor */
    z64_actor_t* next;                  /* Next Actor */
    void* ctor;                         /* Constructor */
    void* dtor;                         /* Destructor */
    void* main_proc;                    /* Main Function */
    void* draw_proc;                    /* Draw Function */
    void* code_entry;                   /* Code Entry */
#ifdef OOT_DEBUG
    uint8_t debug_ex[16];               /* Debug Extended Instance Padding */
#endif
};

typedef void (z64_actorfunc_t)(void *entity, void *global);

/* z64_player_t_old */
  //z64_actor_t       actor;                    /* 0x0000 */
  //int16_t           unk_00_[0x02F8];          /* 0x013C */
  //uint8_t           action;                   /* 0x0434 */
  //int16_t           unk_01_[0x0237];          /* 0x0435 */
  //uint32_t          state_flags_1;            /* 0x066C */
  //uint32_t          state_flags_2;            /* 0x0670 */
  //uint32_t          unk_02_1;                 /* 0x0674 */
  //uint32_t          unk_02_2;                 /* 0x0678 */
  //uint32_t          unk_02_3;                 /* 0x067C */
  //uint32_t          reflection_flag;          /* 0x0680 */
  //int16_t           unk_02_4[0x01A8];         /* 0x0684 */
  //float             linear_vel;               /* 0x0828 */
  //int16_t           unk_03_[0x0002];          /* 0x082C */
  //uint16_t          target_yaw;               /* 0x082E */
  //int16_t           unk_04_[0x0003];          /* 0x0830 */
  //int8_t            sword_state;              /* 0x0833 */
  //int16_t           unk_05_[0x0050];          /* 0x0834 */
  //int16_t           drop_y;                   /* 0x0884 */
  //int16_t           drop_distance;            /* 0x0886 */
                                              /* 0x0888 */
typedef struct {
    z64_actor_t actor; /* Base Actor */
    //char debug_ex[16]; /* Debug Extended Actor */
    uint8_t tunic_idx; /* Equipped Tunic Index */
    uint8_t sword_idx; /* Equipped Sword Index (?) */
    uint8_t shield_idx; /* Equipped Shield Index */
    uint8_t boot_idx; /* Equipped Boots Index */
    uint8_t held_button; /* Held Item (Button ID) */
    uint8_t held_action; /* Held Item (Action Parameter) */
    uint8_t held_item_id; /* Held Item ID */
    uint8_t field_0x153;
    uint8_t held_action_2; /* Held Item (Action Parameter 2) */
    uint8_t field_0x155[3];
    uint8_t shield_on_back; /* (?) 0 = no, 1 = yes */
    uint8_t field_0x159[2];
    uint8_t shield_in_hand; /* (?) 1 = yes */
    uint8_t field_0x15c;
    uint8_t right_hand_item; /* Possible? 08 = Neutral, 09 = Too heavy to shield, 0A = shielding */
    uint8_t mask_now; /* Current Mask Index */
    uint8_t inst015F[2];
    uint32_t * rhand_dlist; /* Right Hand Display List */
    uint32_t * lhand_dlist; /* Left Hand Display List */
    uint32_t * sheath_dlist; /* Sheath Display List */
    uint32_t * torso_dlist; /* Torso Display List */
    uint8_t field_0x174[60];
    void * title_card; /* Title Card / Get Item Object File */
    uint8_t field_0x1b4;
    uint8_t field_0x1b5[75];
    uint8_t anime_now_1[134]; /* Current Animation Raw Data 1 */
    uint8_t field_0x286[10];
    uint8_t anime_now_2[134]; /* Current Animation Raw Data 2 */
    uint8_t field_0x316[148];
    z64_actor_t * held_actor; /* Held Item Actor (Like Arms_Hook) */
    uint8_t inst03B0[708];
    void * state_function; /* Machine State */
    uint32_t * age_properties; /* Collision, Sound Effects, Other */
    uint32_t state_flags_1;
    uint32_t state_flags_2;
    uint8_t field_0x684[8];
    z64_actor_t * navi; /* Navi's Instance */
    uint16_t navi_msg; /* Message ID for Navi's Info */
    uint8_t field_0x692[62];
    uint32_t anime_now_id; /* Current Animation ID */
    uint8_t field_0x6d4[780];
    float sword_mf[4][4]; /* Sword / Left Hand Floating Point Matrix */
    float shield_mf[4][4]; /* Shield / Right Hand Floating Point Matrix */
    uint8_t field_0xa60[8];
} z64_player_t;

#endif
