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

typedef struct z64_sub_0x00B4_s {
    vec3s_t rot_2; /* Rotation (2) */
    int8_t unk_0x0006[2]; /* Collision Mesh Related (Y axis shift?) */
    uint32_t unk_0x0008; /* Unused / Undocumented */
    void * drop_shadow; /* Drop Shadow Drawing Function */
    uint32_t shadow_radius; /* Drop Shadow Radius */
    int8_t unk_0x0014; /* Unused / Undocumented */
    uint8_t unk_0x0015[3]; /* Unused / Undocumented */
} z64_sub_0x00B4_t;

typedef struct z64_collision_check_s {
    z64_damagechart_init_t * damge_table; /* Damage Table Pointer */
    vec3f_t vel_2; /* Displacement */
    int16_t unk_0B_0;
    int16_t unk_0B_1;
    uint16_t unk_0B_2;
    uint8_t mass; /* Mass */
    uint8_t health; /* Health / Durability */
    uint8_t damage; /* Damage Dealt */
    uint8_t damage_effect;
    uint8_t impact_effect;
    int8_t unk_0D;
} z64_collision_check_t;

typedef struct z64_actor_s z64_actor_t;
struct z64_actor_s { /* Common Actor Instance Structure */
    int16_t actor_id; /* Actor Number */
    z64_actor_type_t actor_type; /* Actor Type */
    int8_t room_index; /* Room Index (0xFF means actor won't despawn on room change.) */
    uint32_t flags; /* Special Actor Flags */
    PosRot_t init; /* Initial Spawn Coordinates */
    char unk_01_[2]; /* Undocumented / Unused */
    uint16_t variable; /* Actor Variable */
    uint8_t obj_alloc_index; /* Object Table Allocation Index */
    char unk1F; /* Undocumented / Unused */
    uint16_t sound_effect; /* Actor Sound Effect (Relative to Actor Location) */
    char unk_03_[2]; /* Undocumented / Unused */
    vec3f_t pos_2; /* Current Position (2) */
    int16_t unk30; /* Undocumented / Unused */
    int16_t xz_dir; /* Direction (X and Z axes) */
    int16_t unk34; /* Undocumented / Unused */
    int16_t unk36; /* Undocumented / Unused */
    vec3f_t pos_3; /* Camera Related Position (3) */
    vec3s_t rot_1; /* Rotation (1) */
    char unk_06_[2]; /* Undocumented / Unused */
    float unk_07_; /* Undocumented / Unused */
    vec3f_t scale; /* Actor Scale */
    vec3f_t velocity; /* Velocity */
    float xz_speed; /* Speed (X and Z axes) */
    float gravity; /* Gravity */
    float min_vel_y; /* Minimum Velocity (Y axis) */
    z64_col_poly_t * wall_poly; /* Wall Polygon (Actor is touching) */
    z64_col_poly_t * floor_poly; /* Floor Polygon (Actor is over or touching) */
    uint8_t wall_poly_source; /* Complex Poly Surface Source */
    uint8_t floor_poly_source; /* Complex Poly Surface Source */
    int16_t wall_rot; /* Rotation Towards Wall */
    float floor_height; /* Height of Floor (Maybe?) */
    float water_surface_dist; /* Distance to Water Surface */
    uint16_t bgcheck_flags;
    int16_t rot_toward_link_y; /* Y Rotation to face Player */
    float unk_0x8C; /* Undocumented / Unused */
    float dist_from_link_xz; /* Distance From Player (X and Z axes) */
    float dist_from_link_y; /* Distance From Player (Y axis) */
    z64_collision_check_t sub_col_check; /* Collision Check Substruct */
    z64_sub_0x00B4_t sub_0x00B4; /* Draw Shadow(?) Substruct */
    vec3f_t unk_0xCC; /* Undocumented / Unused */
    vec3f_t unk_0xD8; /* Undocumented / Unused */
    vec3f_t unk_0xE4; /* Undocumented / Unused */
    float unk_0xF0; /* Undocumented / Unused */
    float draw_dist; /* Draw Distance */
    float cclip_near; /* Camera Clipping Distance (Near) */
    float cclip_far; /* Camera Clipping Distance (Far) */
    vec3f_t pos_4; /* Final Position (4); Last Frame */
    uint16_t unk_0F_; /* Undocumented / Unused */
    uint16_t text_id; /* Actor Message ID */
    int16_t frozen; /* Used in "ReDead Freeze Attack" */
    uint16_t damage_color; /* First 12 bits control color which can only be blue, red, or white. The last 4 bits are unknown, but they can't be zero. */
    uint8_t damage_color_timer; /* Damage Color Effect Timer */
    uint8_t runActor; /* Determines if Actor Instance should be processed. 01 = True, 00 = False */
    uint8_t unk_11_; /* Sets a collision related routine. */
    uint8_t navi_enemy_text_id; /* Navi Info Message ID */
    z64_actor_t * attached_a; /* Attached Actor A (Interfacing Actor) */
    z64_actor_t * attached_b; /* Attached Actor B (Attached to Actor) */
    z64_actor_t * prev; /* Previous Actor */
    z64_actor_t * next; /* Next Actor */
    void * ctor; /* Constructor */
    void * dtor; /* Destructor */
    void * main_proc; /* Main Function */
    void * draw_proc; /* Draw Function */
    void * code_entry; /* Code Entry */
    #ifdef OOT_DEBUG
      unsigned char    debug_ex[0x10]; /* Debug Extended */
    #endif
}; /* 0x014C */

typedef void (z64_actorfunc_t)(void *entity, void *global);

typedef struct
{
  z64_actor_t       actor;                    /* 0x0000 */
  uint8_t           unk_00_[0x0270];          /* 0x013C */
  uint32_t          unk_00_1;                 /* 0x03AC */
  uint8_t           unk_00_2[0x0084];         /* 0x03B0 */
  uint32_t          action;                   /* 0x0434 */
  uint32_t          unk_01_1;                 /* 0x0438 */
  uint8_t           unk_01_[0x0230];          /* 0x043C */
  uint32_t          state_flags_1;            /* 0x066C */
  uint32_t          state_flags_2;            /* 0x0670 */
  uint32_t          unk_02_1;                 /* 0x0674 */
  uint32_t          unk_02_2;                 /* 0x0678 */
  uint32_t          unk_02_3;                 /* 0x067C */
  uint32_t          reflection_flag;          /* 0x0680 */
  uint8_t           unk_02_4[0x01A8];         /* 0x0684 */
  float             linear_vel;               /* 0x0828 */
  uint8_t           unk_03_[0x0002];          /* 0x082C */
  uint16_t          target_yaw;               /* 0x082E */
  uint8_t           unk_04_[0x0003];          /* 0x0830 */
  int8_t            sword_state;              /* 0x0833 */
  uint8_t           unk_05_[0x0050];          /* 0x0834 */
  int16_t           drop_y;                   /* 0x0884 */
  int16_t           drop_distance;            /* 0x0886 */
                                              /* 0x0888 */
} z64_player_t;

#endif
