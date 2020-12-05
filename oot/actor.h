#ifndef __Z64OVL_ACTOR_OOT_H__
#define __Z64OVL_ACTOR_OOT_H__

typedef void (z64_actorfunc_t)(void *entity, void *global);

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

/* Offset / Member / Comment */
typedef struct z64_actor_init_s{    /* Actor Overlay Initialization Variables */
/* 0x0000 */ int16_t number;        /* Actor Number */
/* 0x0002 */ uint8_t type;          /* Actor Type */
/* 0x0003 */ uint8_t room;          /* Room that the instance was spawned in*/
/* 0x0004 */ int32_t flags;         /* Not completely documented */
/* 0x0008 */ int16_t object;        /* Object Number */
/* 0x000A */ int16_t padding;       /* Padding for alignment */
/* 0x000C */ int32_t instance_size; /* Size of the actor instance */
/* 0x0010 */ void *init;            /* Constructor */
/* 0x0014 */ void *dest;            /* Destructor */
/* 0x0018 */ void *main;            /* Main Update Function */
/* 0x001C */ void *draw;            /* Draw Function */
} z64_actor_init_t;                 /* Length: 0x0020 */

/* Offset / Member / Comment */
typedef struct z64_actor_s z64_actor_t;
struct z64_actor_s {                             /* Common Actor Instance Structure */
/* 0x0000 */ int16_t actor_id;                   /* Actor Number */
/* 0x0002 */ uint8_t actor_type;                 /* Actor Type */
/* 0x0003 */ uint8_t room_index;                 /* Room Index (0xFF means actor won't despawn on room change.) */
/* 0x0004 */ uint32_t flags;                     /* Special Actor Flags */
/* 0x0008 */ vec3f_t pos_init;                   /* Initial Position */
/* 0x0014 */ vec3s_t rot_init;                   /* Initial Rotation */
/* 0x001A */ uint8_t __pad_0x1A[2];              /* initPosRot Padding for 4-byte alignment */
/* 0x001C */ uint16_t variable;                  /* Actor Variable */
/* 0x001E */ uint8_t alloc_index;                /* Object Table Allocation Index */
/* 0x001F */ uint8_t target_dist_index;          /* Indexes into table at 0x80115FFC */
/* 0x0020 */ uint16_t sound_effect;              /* Actor Sound Effect (Relative to Actor Location) */
/* 0x0022 */ uint8_t __pad_0x22[2];              /* Padding for 4-byte alignment */
/* 0x0024 */ vec3f_t pos;                        /* Active Position */
/* 0x0030 */ vec3s_t dir;                        /* Direction / Rotation */
/* 0x0036 */ uint8_t __pad_0x36[2];              /* PosRot Padding for 4-byte alignment */
/* 0x0038 */ vec3f_t pos_focus;                  /* Position to Focus Camera on (Z-Target) */
/* 0x0044 */ vec3s_t rot_focus;                  /* Rotation to Focus Camera on (Z-Target) */
/* 0x004A */ uint8_t __pad_0x4A[2];              /* focusPosRot Padding for 4-byte alignment */
/* 0x004C */ float unk_0x4C;                     /* (NZLE: 8002BF60) */
/* 0x0050 */ vec3f_t scale;                      /* Actor Scale */
/* 0x005C */ vec3f_t velocity;                   /* Velocity */
/* 0x0068 */ float xz_speed;                     /* Speed (X and Z axes) */
/* 0x006C */ float gravity;                      /* Gravity */
/* 0x0070 */ float min_vel_y;                    /* Minimum Velocity (Y axis) */
/* 0x0074 */ z64_col_poly_t* wall_poly;          /* Wall Polygon (Actor is touching) */
/* 0x0078 */ z64_col_poly_t* floor_poly;         /* Floor Polygon (Actor is over or touching) */
/* 0x007C */ uint8_t wall_poly_source;           /* Complex Poly Surface Source */
/* 0x007D */ uint8_t floor_poly_source;          /* Complex Poly Surface Source */
/* 0x007E */ int16_t wall_rot;                   /* Rotation Towards Wall */
/* 0x0080 */ float floor_height;                 /* Height of Floor (Maybe?) */
/* 0x0084 */ float water_surface_dist;           /* Distance to Water Surface */
/* 0x0088 */ uint16_t bgcheck_flags;             /* Bitfield Determining Collision State */
/* 0x008A */ int16_t rot_toward_link_y;          /* Y Rotation to face Player */
/* 0x008C */ float dist_from_link_squared;       /* Square Distance From Player (dist_xz^2) + (dist_y^2) */
/* 0x0090 */ float dist_from_link_xz;            /* Distance From Player (X and Z axes) */
/* 0x0094 */ float dist_from_link_y;             /* Distance From Player (Y axis) */
/* 0x0098 */ void* damage_table;                 /* Collision Check Substruct / Decomp's "SubActorStruct98" */
/* 0x009C */ vec3f_t displacement;               /* Amount to correct velocity by when colliding into a body */
/* 0x00A8 */ int16_t unk_0xA8;                   /* (NZLE: 80061ED4) */
/* 0x00AA */ int16_t unk_0xAA;                   /* (NZLE: 80061ED4) */
/* 0x00AC */ uint8_t __pad_0xAC[2];              /* Padding for 4-byte alignment */
/* 0x00AE */ uint8_t mass;                       /* Used to Calculate Displacement (0xFF is Infinite Mass, 50 is common.) */
/* 0x00AF */ uint8_t health;                     /* Health */
/* 0x00B0 */ uint8_t damage;                     /* Damage Dealt, Decrement Health by this amount. */
/* 0x00B1 */ uint8_t damage_effect;              /* Elemental Damage Effect */
/* 0x00B2 */ uint8_t impact_effect;              /* Set on Deku Nut when Deku Nut collides with Gossip Stone */
/* 0x00B3 */ uint8_t unk_0xB3;                   /* Undocumented */
/* 0x00B4 */ vec3s_t rot;                        /* Current Rotation / Decomp's "ActorShape" Substruct */
/* 0x00BA */ int16_t unk_0xBA;                   /* Undocumented */
/* 0x00BC */ float unk_0xBC;                     /* Model Y Axis Offset; Collision Mesh Related (NZLE: 80030BE8) */
/* 0x00C0 */ void* shadow_func;                  /* Draw Function for Drop Shadow */
/* 0x00C4 */ float shadow_radius;                /* Drop Shadow Radius */
/* 0x00C8 */ uint8_t shadow_alpha;               /* Drop Shadow Opacity */
/* 0x00C9 */ uint8_t unk_0xC9;                   /* Used in Z_SHADOW_TEARDROP */
/* 0x00CA */ uint8_t __pad_0xCA[2];              /* Padding for 4-byte alignment */
/* 0x00CC */ vec3f_t unk_0xCC;                   /* Used in Z_SHADOW_TEARDROP */
/* 0x00D8 */ vec3f_t unk_0xD8;                   /* Undocumented */
/* 0x00E4 */ vec3f_t unk_0xE4;                   /* (NZLE: 800314D4), Position Vector */
/* 0x00F0 */ float unk_0xF0;                     /* (NZLE: 800314D4) */
/* 0x00F4 */ float draw_dist;                    /* Draw Distance */
/* 0x00F8 */ float cam_clip_near;                /* Camera Clipping Distance (Near) */
/* 0x00FC */ float cam_clip_far;                 /* Camera Clipping Distance (Far) */
/* 0x0100 */ vec3f_t pos_5;                      /* Final Position (5); Last Frame */
/* 0x010C */ uint8_t unk_0x10C;                  /* Used for Tade Sequence */
/* 0x010D */ uint8_t unk_0x10D;                  /* Undocumented */
/* 0x010E */ uint16_t text_id;                   /* Actor Message ID */
/* 0x0110 */ int16_t frozen;                     /* Used in "ReDead Freeze Attack" */
/* 0x0112 */ uint16_t damage_color;              /* First 12 bits control color which can only be blue, red, or white. The last 4 bits are unknown, but they can't be zero. */
/* 0x0114 */ uint8_t damage_color_timer;         /* Damage Color Effect Timer */
/* 0x0115 */ uint8_t active;                     /* Determines if Actor Instance should be processed. 01 = True, 00 = False */
/* 0x0116 */ uint8_t unk_0x116;                  /* Sets a collision related routine. (NZLE: 8003573C) */
/* 0x0117 */ uint8_t navi_enemy_text_id;         /* Navi Info Message ID */
/* 0x0118 */ z64_actor_t* attached_a;            /* Attached Actor A (Interfacing Actor) */
/* 0x011C */ z64_actor_t* attached_b;            /* Attached Actor B (Attached to Actor) */
/* 0x0120 */ z64_actor_t* prev;                  /* Previous Actor */
/* 0x0124 */ z64_actor_t* next;                  /* Next Actor */
/* 0x0128 */ z64_actorfunc_t* ctor;              /* Constructor */
/* 0x012C */ z64_actorfunc_t* dtor;              /* Destructor */
/* 0x0130 */ z64_actorfunc_t* main_proc;         /* Main Function */
/* 0x0134 */ z64_actorfunc_t* draw_proc;         /* Draw Function */
/* 0x0138 */ void* code_entry;                   /* Code Entry */
#ifdef OOT_DEBUG                                 /* Length: 0x013C */
/* 0x013C */ uint8_t debug_ex[16];               /* Debug Extended Instance Padding */
#endif                                           /* Length: 0x014C */
};

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
typedef struct z64_player_s {
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
    uint8_t field_0x15e;
    uint8_t mask_now; /* Current Mask Index */
    uint32_t * rhand_dlist; /* Right Hand Display List */
    uint32_t * lhand_dlist; /* Left Hand Display List */
    uint32_t * sheath_dlist; /* Sheath Display List */
    uint32_t * torso_dlist; /* Torso Display List */
    uint8_t field_0x170[64];
    void * title_card; /* Title Card / Get Item Object File */
    uint8_t field_0x1b4;
    uint8_t field_0x1b5[75];
    uint8_t anime_now_1[134]; /* Current Animation Raw Data 1 */
    uint8_t field_0x286[10];
    uint8_t anime_now_2[134]; /* Current Animation Raw Data 2 */
    uint8_t field_0x316[148];
    z64_actor_t * held_actor; /* Held Item Actor (Like Arms_Hook) */
    uint8_t field_0x3b0[132];
    uint8_t get_item_id_chest; /* Item Obtained from Nearby Chest */
    int16_t gi_face_dir; /* Face this direction on Get Item */
    z64_actor_t * interacted_range_actor; /* Getting Items, Bushed, Rocks, Bugs */
    uint8_t field_0x43c[4];
    z64_actor_t * riding_actor; /* Riding Actor (Epona, Horse) */
    uint8_t field_0x444;
    uint8_t field_0x445[3];
    uint8_t col_struct_1[80]; /* [?] */
    uint8_t col_struct_2[76]; /* Body [?] */
    uint8_t col_struct_3[128]; /* Sword Attacks 1 [?] */
    uint8_t col_struct_4[128]; /* Sword Attacks 2 [?] */
    uint8_t shield_col_struct[128]; /* Shield Collision Structure */
    uint8_t field_0x664[16];
    void * state_function; /* Machine State */
    uint32_t * age_properties; /* Collision, Sound Effects, Other */
    int32_t state_flags_1;
    int32_t state_flags_2;
    uint8_t field_0x684[8];
    z64_actor_t * navi; /* Navi's Instance */
    uint16_t navi_msg; /* Message ID for Navi's Info */
    uint8_t field_0x692[62];
    uint32_t anime_now_id; /* Current Animation ID */
    uint8_t field_0x6d4[18];
    void * field_0x6e8;
    void * field_0x6ec;
    uint8_t field_0x6f0[8];
    void * field_0x6f8;
    uint8_t field_0x6fc[20];
    uint8_t field_0x710[132];
    uint8_t field_0x794[152];
    void * field_0x82c;
    uint8_t field_0x830[18];
    uint8_t sword_anim_index; /* [?] */
    uint8_t field_0x843[21];
    float field_0x858;
    float deku_stick_y_scale;
    int16_t deku_stick_flame_timer;
    uint8_t get_item_id; /* Obtained Item; Link holds this item over his head. */
    uint8_t field_0x863[73];
    float fan_wind_speed; /* Fan Wind Speed */
    int16_t fan_wind_dir; /* Fan Direction */
    uint8_t field_0x8b2[6];
    vec3f_t deku_stick_tip;
    uint8_t field_0x8c4[68];
    vec3f_t field_0x908;
    uint8_t field_0x914[204];
    float sword_mf[4][4]; /* Sword / Left Hand Floating Point Matrix */
    float shield_mf[4][4]; /* Shield / Right Hand Floating Point Matrix */
    uint8_t field_0xa60[24];
    uint8_t inv_frames; /* Invincibility Frames */
} z64_player_t;

#endif
