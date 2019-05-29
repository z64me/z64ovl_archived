#ifndef __Z64OVL_ACTOR_OOT_H__
#define __Z64OVL_ACTOR_OOT_H__

typedef enum {
  Switch = 0x00,
  Bg = 0x01,
  Player = 0x02,
  Explosives = 0x03,
  NPC = 0x04,
  Enemy = 0x05,
  Prop = 0x06,
  Item_Action = 0x07,
  Misc = 0x08,
  Boss = 0x09,
  Door = 0x0A,
  Chest = 0x0B
} z64_actor_type_t;

typedef struct z64_actor_init_s{
  int16_t number;    /* Actor Number */
  uint8_t type;      /* Actor Type */
  uint8_t room;      /* Room that the instance was spawned in*/
  int flags;         /* Not completely documented */
  int16_t object;    /* Object Number */
  int16_t padding;
  int instance_size; /* Size of the actor instance */
  void *init;        /* Constructor */
  void *dest;        /* Destructor */
  void *main;        /* Main Update Function */
  void *draw;        /* Draw Function */
} z64_actor_init_t;

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
  char              unk_02_;                  /* 0x001F */
  uint16_t          sound_effect;             /* 0x0020 */
  char              unk_03_[0x0002];          /* 0x0022 */
  vec3f_t           pos_2;                    /* 0x0024 */
  char              unk_04_[0x0002];          /* 0x0030 */
  uint16_t          xz_dir;                   /* 0x0032 */
  char              unk_05_[0x0004];          /* 0x0034 */
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
  char              unk_0B_[0x0006];          /* 0x00A8 */
  uint8_t           mass;                     /* 0x00AE */
  uint8_t           health;                   /* 0x00AF */
  uint8_t           damage;                   /* 0x00B0 */
  uint8_t           damage_effect;            /* 0x00B1 */
  uint8_t           impact_effect;            /* 0x00B2 */
  char              unk_0D;                   /* 0x00B3 */
  /* end CollisionCheck common */
  /* struct start */
  z64_rot_t         rot_2;                    /* 0x00B4 */
  char              unk_0E_[0x0002];          /* 0x00BA */
  float             unk_0xBC;                 /* 0x00BC */
  void             *draw_drop_shadow;         /* 0x00C0 */
  float             unk_0xC4;                 /* 0x00C4 */
  uint8_t           unk_0xC8;                 /* 0x00C8 */
  char              pad_0xC9_[0x0003];        /* 0x00C9 */
  /* struct end */
  z64_xyzf_t        unk_0xCC;                 /* 0x00CC */
  z64_xyzf_t        unk_0xD8;                 /* 0x00D8 */
  z64_xyzf_t        unk_0xE4;                 /* 0x00E4 */
  float             unk_0xF0;                 /* 0x00F0 */
  float             unk_0xF4;                 /* 0x00F4 */
  float             unk_0xF8;                 /* 0x00F8 */
  float             unk_0xFC;                 /* 0x00FC */
  z64_xyzf_t        pos_4;                    /* 0x0100 */
  uint16_t          unk_0F_;                  /* 0x010C */
  uint16_t          text_id;                  /* 0x010E */
  int16_t           frozen;                   /* 0x0110 */
  char              unk_10_[0x0003];          /* 0x0112 */
  uint8_t           active;                   /* 0x0115 */
  uint8_t           unk_11_;                  /* 0x0116 */
  uint8_t           navi_enemy_text_id;       /* 0x0117 */
  z64_actor_t      *attached_a;               /* 0x0118 */
  z64_actor_t      *attached_b;               /* 0x011C */
  z64_actor_t      *prev;                     /* 0x0120 */
  z64_actor_t      *next;                     /* 0x0124 */
  void             *ctor;                     /* 0x0128 */
  void             *dtor;                     /* 0x012C */
  void             *main_proc;                /* 0x0130 */
  void             *draw_proc;                /* 0x0134 */
  void             *code_entry;               /* 0x0138 */
                                              /* 0x013C */
};

typedef void (z64_actorfunc_t)(void *entity, void *global);

typedef struct
{
  z64_actor_t       actor;                    /* 0x0000 */
  char              unk_00_[0x02F8];          /* 0x013C */
  uint8_t           action;                   /* 0x0434 */
  char              unk_01_[0x0237];          /* 0x0435 */
  uint32_t          state_flags_1;            /* 0x066C */
  uint32_t          state_flags_2;            /* 0x0670 */
  uint32_t          unk_02_1;                 /* 0x0674 */
  uint32_t          unk_02_2;                 /* 0x0678 */
  uint32_t          unk_02_3;                 /* 0x067C */
  uint32_t          reflection_flag;          /* 0x0680 */
  char              unk_02_4[0x01A8];         /* 0x0684 */
  float             linear_vel;               /* 0x0828 */
  char              unk_03_[0x0002];          /* 0x082C */
  uint16_t          target_yaw;               /* 0x082E */
  char              unk_04_[0x0003];          /* 0x0830 */
  int8_t            sword_state;              /* 0x0833 */
  char              unk_05_[0x0050];          /* 0x0834 */
  int16_t           drop_y;                   /* 0x0884 */
  int16_t           drop_distance;            /* 0x0886 */
                                              /* 0x0888 */
} z64_player_t;

#endif