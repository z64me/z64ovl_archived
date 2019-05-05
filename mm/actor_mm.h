#ifndef __ZELDA64_ACTOR_MM_H__
#define __ZELDA64_ACTOR_MM_H__

#include <stdint.h>
#include <mips.h>

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
  int16_t number; /* Actor Number */
  uint8_t type; /* Actor Type */
  uint8_t room; /* Room that the instance was spawned in*/
  int flags; /* Not completely documented */
  int16_t object; /* Object Number */
  int16_t padding;
  int instance_size; /* Size of the actor instance */
  void *init; /* Constructor */
  void *dest; /* Destructor */
  void *main; /* Main Update Function */
  void *draw; /* Draw Function */
} z64_actor_init_t;

/* Legacy Macros */
/* Get a value of arbitrary type from any address in the actor */
#define AVAL(base,type,offset)  (*(type*)((u8*)(base)+(offset)))

/* Get the address */
#define AADDR(a,o)  ((void*)((u8*)(a)+(o)))

// Borrowed from OoT gz
typedef struct
{
  int16_t           x;                        /* 0x0000 */
  int16_t           y;                        /* 0x0002 */
  int16_t           z;                        /* 0x0004 */
                                              /* 0x0006 */
} z64_xyz_t, vec3s_t, z64_point_t;

typedef struct
{
  float             x;                        /* 0x0000 */
  float             y;                        /* 0x0004 */
  float             z;                        /* 0x0008 */
                                              /* 0x000C */
} z64_xyzf_t, vec3f_t;

typedef uint16_t z64_angle_t;
typedef struct
{
  z64_angle_t       x;                        /* 0x0000 */
  z64_angle_t       y;                        /* 0x0002 */
  z64_angle_t       z;                        /* 0x0004 */
                                              /* 0x0006 */
} z64_rot_t;

typedef struct
{
  /* index of z64_col_type in col_hdr */
  uint16_t          type;                     /* 0x0000 */
  /* vertex indices, a and b are bitmasked for some reason */
  struct
  {
    uint16_t        unk_00_             : 3;
    uint16_t        va                  : 13;
  };                                          /* 0x0002 */
  struct
  {
    uint16_t        unk_01_             : 3;
    uint16_t        vb                  : 13;
  };                                          /* 0x0004 */
  uint16_t          vc;                       /* 0x0006 */
  /* normal vector */
  z64_xyz_t         norm;                     /* 0x0008 */
  /* plane distance from origin */
  int16_t           dist;                     /* 0x000E */
                                              /* 0x0010 */
} z64_col_poly_t;

/* ----------------------------------------------
   Data types & structures
   ---------------------------------------------- */

typedef struct
{
  struct
  {
    char damage : 4;
    char effect : 4;
  } attack[0x20];
} z64_damage_table_t;

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
  char              unk_02_;                  /* 0x001F */
  uint16_t          sound_effect;             /* 0x0020 */
  char              unk_03_[0x0002];          /* 0x0022 */
  vec3f_t           pos_2;                    /* 0x0024 */
  z64_rot_t         speedRot;                 /* 0x0030 */
  uint32_t          unk_0x038;                /* 0x0038 */
  vec3f_t           pos_3;                    /* 0x003C */
  z64_rot_t         rot_1;                    /* 0x0048 */
  uint16_t          unk_0x04E;                /* 0x004E */
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
  char              unk_0D;                   /* 0x00BB */
  z64_rot_t         rot_2;                    /* 0x00BC */
  char              unk_0E_[0x4D];            /* 0x00C8 */
  char              runActor;                 /* 0x0115 */
  char              unk_0F_[0x0F];            /* 0x0119 */
  z64_actor_t      *prev;                     /* 0x0128 */
  z64_actor_t      *next;                     /* 0x012C */
  void             *ctor;                     /* 0x0130 */
  void             *dtor;                     /* 0x0134 */
  void             *main_proc;                /* 0x0138 */
  void             *draw_proc;                /* 0x013C */
  void             *code_entry;               /* 0x0140 */
                                              /* 0x0144 */
};

typedef void (z64_actorfunc_t)(void *entity, void *global);

#endif /* __ZELDA64_ACTOR_H__ */
