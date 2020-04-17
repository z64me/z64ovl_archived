#ifndef __Z64OVL_OOT_TYPES_H__
#define __Z64OVL_OOT_TYPES_H__

#include "../stdint.h"
#include "../h/mips.h"
#include "../h/n64.h"
#include "../h/various_types.h"

typedef struct
{
  z64_controller_t  raw;                      /* 0x0000 */
  /* 0x0000: ok */
  /* 0x0800: device not present */
  /* 0x0400: transaction error */
  uint16_t          status;                   /* 0x0004 */
  z64_controller_t  raw_prev;                 /* 0x0006 */
  uint16_t          status_prev;              /* 0x000A */
  uint16_t          pad_pressed;              /* 0x000C */
  int8_t            x_diff;                   /* 0x000E */
  int8_t            y_diff;                   /* 0x000F */
  char              unk_02_[0x0002];          /* 0x0010 */
  uint16_t          pad_released;             /* 0x0012 */
  int8_t            adjusted_x;               /* 0x0014 */
  int8_t            adjusted_y;               /* 0x0015 */
  char              unk_03_[0x0002];          /* 0x0016 */
                                              /* 0x0018 */
} z64_input_t;

// Graphics Context
typedef struct
{
  uint32_t          size;                     /* 0x0000 */
  Gfx              *buf;                      /* 0x0004 */
  Gfx              *p;                        /* 0x0008 */
  Gfx              *d;                        /* 0x000C */
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
typedef struct z64_game_state_s { /* Game State Structure */
    z64_gfx_t * gfx_ctxt; /* Graphics Context Address */
    void * state_main;
    void * state_dtor;
    void * next_ctor;
    uint32_t next_size;
    z64_input_t input[4];
    uint32_t state_heap_size;
    void * state_heap;
    void * heap_start;
    void * heap_end;
    void * state_heap_node;
    char unk_00_[16];
    int32_t state_continue;
    int32_t state_frames;
    uint32_t unk_01_;
} z64_game_state_t;

typedef struct
{
  uint32_t          vrom_start;               /* 0x0000 */
  uint32_t          vrom_end;                 /* 0x0004 */
                                              /* 0x0008 */
} z64_vrom_file_t;

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

/* damage chart */
#define Z_DAMAGE(VAL, FX) (uint8_t)(((FX)<< 4) | (VAL))
typedef struct z64_damagechart_init_s { /* Damage Chart Initialization Variables (& 0xF0 = Effect Type, & 0x0F = Damage Amount) */
    uint8_t nut; /* Deku Nut */
    union damage_chart_entry_01 {
        uint8_t stick; /* Deku Stick Slash */
        uint8_t vase; /* Vase / Rock Throw */
    } entry01;
    uint8_t slingshot; /* Fairy Slingshot */
    uint8_t explode; /* Explosions */
    uint8_t boomerang; /* Boomerang */
    uint8_t arrow; /* Normal Arrow */
    uint8_t hammer_swing; /* Hammer Swing (no ground hit) */
    uint8_t hookshot; /* Hookshot and Longshot */
    struct slash {
      uint8_t sword0; /* Kokiri Sword Slash */
      uint8_t sword1; /* Master Sword Slash */
      uint8_t sword2; /* Biggoron Sword and Giant's Knife Slash */
    } slash;
    struct magic_arrow {
      uint8_t fire; /* Fire Arrow */
      uint8_t ice; /* Ice Arrow */
      uint8_t light; /* Light Arrow */
      uint8_t wind; /* (Beta) Wind Arrow */
      uint8_t spirit; /* (Beta) Spirit Arrow */
      uint8_t shadow; /* (Beta) Shadow Arrow */
    } magic_arrow;
    struct magic {
      uint8_t fire; /* Din's Fire */
      uint8_t ice; /* Ice Magic (Beta?) */
      uint8_t light; /* Light Magic (Beta?) */
    } magic;
    uint8_t unk_00; /* Undocumented / Unused */
    uint8_t unk_01; /* Undocumented / Unused */
    struct littlespin {
      uint8_t sword0; /* Kokiri Sword Spin Attack (Half Charge) */
      uint8_t sword2; /* Biggoron Sword and Giant's Knife Spin Attack (Half Charge) */
      uint8_t sword1; /* Master Sword Spin Attack (Half Charge) */
    } littlespin;
    union damage_chart_entry_19 {
        uint8_t sword0_jump; /* Kokiri Sword Jump Attack */
        uint8_t sword0_bigspin; /* Kokiri Sword Spin Attack (Full Charge) */
        uint8_t broken_jump; /* Broken Giant's Knife Jump Attack */
        uint8_t broken_bigspin; /* Broken Giant's Knife Spin Attack (Full Charge) */
    } entry19;
    union damage_chart_entry_1A {
        uint8_t sword2_jump; /* Biggoron Sword and Giant's Knife Jump Attack */
        uint8_t sword2_bigspin; /* Biggoron Sword and Giant's Knife Spin Attack (Full Charge) */
    } entry1A;
    union damage_chart_entry_1B {
        uint8_t sword1_jump; /* Master Sword Jump Attack */
        uint8_t sword1_bigspin; /* Master Sword Spin Attack (Full Charge) */
    } entry1B;
    uint8_t unk_02; /* Undocumented / Unused */
    uint8_t unk_03; /* Undocumented / Unused */
    uint8_t hammer_jump; /* Hammer Jump Attack */
    uint8_t unk_04; /* Undocumented / Unused */
} z64_damagechart_init_t;

typedef struct
{
    struct attack {
        uint8_t damage : 4;
        uint8_t effect : 4;
    } attack[0x20];
} z64_damagechart_t;

#include "actor.h"

typedef struct
{
  struct
  {
    uint32_t        unk_00_             : 1;
    /* link drops one unit into the floor */
    uint32_t        drop                : 1;
    uint32_t        special             : 4;
    uint32_t        interaction         : 5;
    uint32_t        unk_01_             : 3;
    uint32_t        behavior            : 5;
    uint32_t        exit                : 5;
    uint32_t        camera              : 8;
  } flags_1;                                  /* 0x0000 */
  struct
  {
    uint32_t        pad_00_             : 4;
    uint32_t        wall_damage         : 1;
    uint32_t        unk_00_             : 6;
    uint32_t        unk_01_             : 3;
    uint32_t        hookshot            : 1;
    uint32_t        echo                : 6;
    uint32_t        unk_02_             : 5;
    uint32_t        terrain             : 2;
    uint32_t        material            : 4;
  } flags_2;                                  /* 0x0004 */
                                              /* 0x0008 */
} z64_col_type_t;

typedef struct
{
  z64_xyz_t         pos;                      /* 0x0000 */
  z64_xyz_t         rot;                      /* 0x0006 */
  int16_t           fov;                      /* 0x000C */
  int16_t           unk_00_;                  /* 0x000E */
                                              /* 0x0010 */
} z64_camera_params_t;

typedef struct
{
  uint16_t          mode;                     /* 0x0000 */
  uint16_t          unk_01_;                  /* 0x0002 */
  /* segment address of z64_camera_params_t */
  uint32_t          seg_params;               /* 0x0004 */
                                              /* 0x0008 */
} z64_camera_t;

typedef struct
{
  z64_xyz_t         pos;                      /* 0x0000 */
  int16_t           width;                    /* 0x0006 */
  int16_t           depth;                    /* 0x0008 */
  char              pad_00_[0x0002];          /* 0x000A */
  struct
  {
    uint32_t        unk_00_             : 12;
    uint32_t        active              : 1;
     /* ? */
    uint32_t        group               : 6;
    uint32_t        unk_01_             : 5;
    uint32_t        camera              : 8;
  } flags;                                    /* 0x000C */
                                              /* 0x0010 */
} z64_col_water_t;

typedef struct
{
  z64_xyz_t         min;                      /* 0x0000 */
  z64_xyz_t         max;                      /* 0x0006 */
  uint16_t          n_vtx;                    /* 0x000C */
  char              pad_00_[0x0002];          /* 0x000E */
  z64_xyz_t        *vtx;                      /* 0x0010 */
  uint16_t          n_poly;                   /* 0x0014 */
  char              pad_01_[0x0002];          /* 0x0016 */
  z64_col_poly_t   *poly;                     /* 0x0018 */
  z64_col_type_t   *type;                     /* 0x001C */
  z64_camera_t     *camera;                   /* 0x0020 */
  uint16_t          n_water;                  /* 0x0024 */
  char              pad_02_[0x0002];          /* 0x0026 */
  z64_col_water_t  *water;                    /* 0x0028 */
                                              /* 0x002C */
} z64_col_hdr_t;

typedef struct
{
  int16_t           poly_idx;                 /* 0x0000 */
  uint16_t          list_next;                /* 0x0002 */
                                              /* 0x0004 */
} z64_col_list_t;

typedef struct
{
  uint16_t          floor_list_idx;           /* 0x0000 */
  uint16_t          wall_list_idx;            /* 0x0002 */
  uint16_t          ceil_list_idx;            /* 0x0004 */
                                              /* 0x0006 */
} z64_col_lut_t;

typedef struct
{
  /* static collision stuff */
  z64_col_hdr_t    *col_hdr;                  /* 0x0000 */
  z64_xyzf_t        bbox_min;                 /* 0x0004 */
  z64_xyzf_t        bbox_max;                 /* 0x0010 */
  int               n_sect_x;                 /* 0x001C */
  int               n_sect_y;                 /* 0x0020 */
  int               n_sect_z;                 /* 0x0024 */
  z64_xyzf_t        sect_size;                /* 0x0028 */
  z64_xyzf_t        sect_inv;                 /* 0x0034 */
  z64_col_lut_t    *stc_lut;                  /* 0x0040 */
  uint16_t          stc_list_max;             /* 0x0044 */
  uint16_t          stc_list_pos;             /* 0x0046 */
  z64_col_list_t   *stc_list;                 /* 0x0048 */
  uint8_t          *stc_check;                /* 0x004C */
  char              unk_00_[0x13F0];          /* 0x0050 */
  /* dynamic collision stuff */
  z64_col_poly_t   *dyn_poly;                 /* 0x1440 */
  z64_xyz_t        *dyn_vtx;                  /* 0x1444 */
  z64_col_list_t   *dyn_list;                 /* 0x1448 */
  char              unk_01_[0x0008];          /* 0x144C */
  uint32_t          dyn_list_max;             /* 0x1454 */
  uint32_t          dyn_poly_max;             /* 0x1458 */
  uint32_t          dyn_vtx_max;              /* 0x145C */
  char              unk_02_[0x0004];          /* 0x1460 */
                                              /* 0x1464 */
} z64_col_ctxt_t;

typedef struct
{
  /* vrom addresses */
  uint32_t          tex_start;                /* 0x0000 */
  uint32_t          tex_end;                  /* 0x0004 */
  uint32_t          pal_start;                /* 0x0008 */
  uint32_t          pal_end;                  /* 0x000C */
                                              /* 0x0010 */
} z64_sky_image_t;

typedef struct
{
  char              unk_00_[0x0128];          /* 0x0000 */
  char             *textures[2];              /* 0x0128 */
  char             *palettes;                 /* 0x0130 */
  Gfx              *gfx;                      /* 0x0134 */
  char              unk_01_[0x0004];          /* 0x0138 */
  char             *vtx;                      /* 0x013C */
  int16_t           mode;                     /* 0x0140 */
  char              unk_02_[0x0006];          /* 0x0142 */
  float             f148;                     /* 0x0148 */
  char              unk_03_[0x0004];          /* 0x014C */
                                              /* 0x0150 */
} z64_sky_ctxt_t;

typedef struct
{
  /* file loading params */
  uint32_t          vrom_addr;                /* 0x0000 */
  void             *dram_addr;                /* 0x0004 */
  uint32_t          size;                     /* 0x0008 */
  /* debug stuff */
  char             *filename;                 /* 0x000C */
  int32_t           line;                     /* 0x0010 */
  int32_t           unk_00_;                  /* 0x0014 */
  /* completion notification params */
  OSMesgQueue      *notify_mq;                /* 0x0018 */
  OSMesg            notify_msg;               /* 0x001C */
                                              /* 0x0020 */
} z64_getfile_t;

typedef struct
{
  uint32_t          vrom_start;               /* 0x0000 */
  uint32_t          vrom_end;                 /* 0x0004 */
  uint32_t          prom_start;               /* 0x0008 */
  uint32_t          prom_end;                 /* 0x000C */
                                              /* 0x0010 */
} z64_ftab_t;

typedef struct
{
  int16_t           id;                       /* 0x0000 */
  char              pad_00_[0x0002];          /* 0x0002 */
  void             *data;                     /* 0x0004 */
  z64_getfile_t     getfile;                  /* 0x0008 */
  OSMesgQueue       load_mq;                  /* 0x0028 */
  OSMesg            load_m;                   /* 0x0040 */
                                              /* 0x0044 */
} z64_mem_obj_t;

typedef struct
{
  void             *obj_space_start;          /* 0x0000 */
  void             *obj_space_end;            /* 0x0004 */
  uint8_t           n_objects;                /* 0x0008 */
  uint8_t           n_special;                /* 0x0009 */
  uint8_t           keep_index;               /* 0x000A */
  uint8_t           skeep_index;              /* 0x000B */
  z64_mem_obj_t     objects[19];              /* 0x000C */
                                              /* 0x0518 */
} z64_obj_ctxt_t;

typedef struct
{
  char              unk_00_;                  /* 0x0000 */
  int8_t            n_entries;                /* 0x0001 */
  char              pad_00_[0x0002];          /* 0x0002 */
  uint32_t          seg_start;                /* 0x0004 */
  uint32_t          seg_end;                  /* 0x0008 */
                                              /* 0x000C */
} z64_sr_mesh_t;

typedef struct
{
  int8_t            room_idx_1;               /* 0x0000 */
  int8_t            effect_1;                 /* 0x0001 */
  int8_t            room_idx_2;               /* 0x0002 */
  int8_t            effect_2;                 /* 0x0003 */
  int16_t           actor_id;                 /* 0x0004 */
  z64_xyz_t         pos;                      /* 0x0006 */
  z64_angle_t       rot;                      /* 0x000C */
  int16_t           variable;                 /* 0x000E */
                                              /* 0x0010 */
} z64_tnsn_actor_t;

typedef struct
{
  int8_t            index;                    /* 0x0000 */
  char              unk_00_[0x0001];          /* 0x0001 */
  uint8_t           bhv_z;                    /* 0x0002 */
  uint8_t           bhv_x;                    /* 0x0003 */
  uint8_t           echo;                     /* 0x0004 */
  int8_t            show_invis_act;           /* 0x0005 */
  char              pad_00_[0x0002];          /* 0x0006 */
  z64_sr_mesh_t    *mesh_hdr;                 /* 0x0008 */
  void             *file;                     /* 0x000C */
  char              unk_01_[0x0004];          /* 0x0010 */
                                              /* 0x0014 */
} z64_room_t;

typedef struct
{
  /* room info */
  z64_room_t        rooms[2];                 /* 0x0000 */
  void             *room_space_start;         /* 0x0028 */
  void             *room_space_end;           /* 0x002C */
  /* loading info */
  uint8_t           load_slot;                /* 0x0030 */
  int8_t            load_active;              /* 0x0031 */
  char              pad_00_[0x0002];          /* 0x0032 */
  void             *load_ptr;                 /* 0x0034 */
  z64_getfile_t     load_getfile;             /* 0x0038 */
  OSMesgQueue       load_notify_mq;           /* 0x0058 */
  OSMesg            load_notify_msg;          /* 0x0070 */
  /* may also be used for other things, not sure */
  /* handled by the scene config for lost woods */
  int16_t           cojiro_sfx_played;        /* 0x0074 */
  int16_t           cojiro_sfx_timer;         /* 0x0076 */
  /* transition actor list */
  uint8_t           n_tnsn;                   /* 0x0078 */
  char              pad_01_[0x0003];          /* 0x0079 */
  z64_tnsn_actor_t *tnsn_list;                /* 0x007C */
                                              /* 0x0080 */
} z64_room_ctxt_t;

/* interface context */
typedef struct
{
  char              unk_00_[0x0130];          /* 0x0000 */
  char             *parameter;                /* 0x0130 */
  char             *action_texture;           /* 0x0134 */
  char             *item_texture;             /* 0x0138 */
  char             *minimap_texture;          /* 0x013C */
  char              unk_01_[0x00AC];          /* 0x0140 */
  uint16_t          h1EC;                     /* 0x01EC */
  char              unk_02_[0x0002];          /* 0x01EE */
  uint16_t          a_action;                 /* 0x01F0 */
  char              unk_03_[0x0002];          /* 0x01F2 */
  float             f1F4;                     /* 0x01F4 */
  char              unk_04_[0x0004];          /* 0x01F8 */
  int16_t           b_label;                  /* 0x01FC */
  char              unk_05_[0x0064];          /* 0x01FE */
  struct
  {
    uint8_t         unk_00_;
    uint8_t         b_button;
    uint8_t         unk_01_;
    uint8_t         bottles;
    uint8_t         trade_items;
    uint8_t         hookshot;
    uint8_t         ocarina;
    uint8_t         warp_songs;
    uint8_t         suns_song;
    uint8_t         farores_wind;
    uint8_t         dfnl;
    uint8_t         all;
  }                 restriction_flags;        /* 0x0262 */
  char              unk_06_[0x0002];          /* 0x026E */
                                              /* 0x0270 */
} z64_if_ctxt_t;

typedef struct
{
  char              unk_00_[0x0128];          /* 0x0000 */
  void             *icon_item;                /* 0x0128 */
  void             *icon_item_24;             /* 0x012C */
  void             *icon_item_s;              /* 0x0130 */
  void             *icon_item_lang;           /* 0x0134 */
  void             *name_texture;             /* 0x0138 */
  void             *p13C;                     /* 0x013C */
  char              unk_01_[0x0094];          /* 0x0140 */
  uint16_t          state;                    /* 0x01D4 */
  char              unk_02_[0x0012];          /* 0x01D6 */
  uint16_t          screen_idx;               /* 0x01E8 */
  char              unk_03_[0x002E];          /* 0x01EA */
  int16_t           item_cursor;              /* 0x0218 */
  char              unk_04_[0x0002];          /* 0x021A */
  int16_t           quest_cursor;             /* 0x021C */
  int16_t           equip_cursor;             /* 0x021E */
  int16_t           map_cursor;               /* 0x0220 */
  int16_t           item_x;                   /* 0x0222 */
  char              unk_05_[0x0004];          /* 0x0224 */
  int16_t           equipment_x;              /* 0x0228 */
  char              unk_06_[0x0002];          /* 0x022A */
  int16_t           item_y;                   /* 0x022C */
  char              unk_07_[0x0004];          /* 0x022E */
  int16_t           equipment_y;              /* 0x0232 */
  char              unk_08_[0x0004];          /* 0x0234 */
  int16_t           cursor_pos;               /* 0x0238 */
  char              unk_09_[0x0002];          /* 0x023A */
  int16_t           item_id;                  /* 0x023C */
  int16_t           item_item;                /* 0x023E */
  int16_t           map_item;                 /* 0x0240 */
  int16_t           quest_item;               /* 0x0242 */
  int16_t           equip_item;               /* 0x0244 */
  char              unk_0A_[0x0004];          /* 0x0246 */
  int16_t           quest_hilite;             /* 0x024A */
  char              unk_0B_[0x0018];          /* 0x024C */
  int16_t           quest_song;               /* 0x0264 */
  char              unk_0C_[0x0016];          /* 0x0266 */
  /* unknown structure */
  char              s27C[0x0038];             /* 0x027C */
                                              /* 0x02B4 */
} z64_pause_ctxt_t;

/* lighting structs */
typedef struct
{
  int8_t            dir[3];                   /* 0x0000 */
  uint8_t           col[3];                   /* 0x0003 */
                                              /* 0x0006 */
} z64_light1_t;

typedef struct
{
  int16_t           x;                        /* 0x0000 */
  int16_t           y;                        /* 0x0002 */
  int16_t           z;                        /* 0x0004 */
  uint8_t           col[3];                   /* 0x0006 */
  char              pad_00_[0x0001];          /* 0x0009 */
  int16_t           intensity;                /* 0x000A */
                                              /* 0x000C */
} z64_light2_t;

typedef union
{
  z64_light1_t      light1;                   /* 0x0000 */
  z64_light2_t      light2;                   /* 0x0000 */
                                              /* 0x000C */
} z64_lightn_t;

typedef struct
{
  uint8_t           type;                     /* 0x0000 */
  char              pad_00_[0x0001];          /* 0x0001 */
  z64_lightn_t      lightn;                   /* 0x0002 */
                                              /* 0x000E */
} z64_light_t;

typedef struct z64_light_node_s z64_light_node_t;
struct z64_light_node_s
{
  z64_light_t      *light;                    /* 0x0000 */
  z64_light_node_t *prev;                     /* 0x0004 */
  z64_light_node_t *next;                     /* 0x0008 */
                                              /* 0x000C */
};

typedef struct
{
  uint32_t          n_nodes;                  /* 0x0000 */
  uint32_t          current_node;             /* 0x0004 */
  z64_light_node_t  nodes[32];                /* 0x0008 */
                                              /* 0x0188 */
} z64_light_queue_t;

typedef struct
{
  z64_light_node_t *light_list;               /* 0x0000 */
  uint8_t           ambient[3];               /* 0x0004 */
  uint8_t           fog[3];                   /* 0x0007 */
  int16_t           fog_position;             /* 0x000A */
  int16_t           draw_distance;            /* 0x000C */
  char              pad_00_[0x0002];          /* 0x000E */
                                              /* 0x0010 */
} z64_lighting_t;

typedef struct
{
  vec3s_t pos;
  uint8_t r;
  uint8_t g;
  uint8_t b;
  uint8_t unk;
  int16_t radius;
} z64_light_params_pos_t;

typedef struct
{
  uint8_t type;
  z64_light_params_pos_t params;
} z64_lightinfo_pos_t;

typedef struct
{
  uint8_t type;
  uint8_t _pad;
  uint16_t params;
} z64_lightinfo_t;

typedef struct
{
  int8_t            numlights;                /* 0x0000 */
  char              pad_00_[0x0007];          /* 0x0001 */
  Lightsn           lites;                    /* 0x0008 */
                                              /* 0x0080 */
} z64_gbi_lights_t;

typedef void (*z64_light_handler_t)(z64_gbi_lights_t*, z64_lightn_t*,
                                    z64_actor_t*);

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

typedef struct z64_dynapoly {
    uint32_t    polyID;                /* 0x0000  counter, starts from 0, each dynapoly actor gets a new id*/
    float       push_movement;                /* 0x0004 */
    float       unk_03;                /* 0x0008 */
    uint16_t    push_direction;                /* 0x000A */
    uint16_t    unk_05;                /* 0x000C */
    uint32_t    movement;              /* 0x0010 &>>01 updates position of actors on top, &>>02 updates rotation of actors on top */
    uint8_t     flags;                 /* 0x0014 &>>01 actor on top &>>02 Link on top &>>04 Link above it or on top &>>08 heavy actor on top */
    char        padding[0x0003];
} z64_dynapoly_t;

typedef struct
{
  int16_t n_at;
  uint32_t hz_0x02;
  z64_collider_t* at_list[50];
  int32_t n_ac;
  z64_collider_t* ac_list[60];
  int32_t n_ot;
  z64_collider_t* ot_list[50];
} z64_hit_ctxt_t;

typedef struct
{
  int32_t top;    /* Upper Left Y */
  int32_t bottom; /* Lower Right Y */
  int32_t left;   /* Upper Left X */
  int32_t right;  /* Lower Right X */
} z64_viewport_t;

/* game context */
typedef struct
{
  z64_game_state_t  common;                   /* 0x00000 */
  uint16_t          scene_index;              /* 0x000A4 */
  char              unk_00_[0x000A];          /* 0x000A6 */
  void             *scene_file;               /* 0x000B0 */
  char              unk_01_[4];               /* 0x000B4 */
  struct
  {
    char              unk[8];                   /* 0x000B8 */
    uint32_t          screen_top;               /* 0x000C0 */
    uint32_t          screen_bottom;            /* 0x000C4 */
    uint32_t          screen_left;              /* 0x000C8 */
    uint32_t          screen_right;             /* 0x000CC */
    float             camera_distance;          /* 0x000D0 */
    float             fog_distance;             /* 0x000D4 */
    float             z_distance;               /* 0x000D8 */
    float             unk_02_;                  /* 0x000DC */
    vec3f_t           eye;                      /* 0x000E0 */
    char              unk_03_[0x00F4];          /* 0x000EC */
  } view; /* starts at 00B8 */
  struct
  {
    char              unk_0[0x90];              /* 0x001E0 */
    z64_actor_t      *focus;                    /* 0x00270 */
    char              unk_04_[0x00AE];          /* 0x00274 */
    uint16_t          mode;                     /* 0x00322 */
    char              unk_05_[0x001A];          /* 0x00324 */
    uint16_t          flag_1;                   /* 0x0033E */
    char              unk_06_[0x016C];          /* 0x00340 */
    int16_t           event_flag;               /* 0x004AC */
    char              unk_07_[0x02E2];          /* 0x004AE */
    void             *pointer[4];               /* 0x00790 */
    int16_t           active;  /* active cam (0-3) 0x007A0 */
    int16_t           unk_5C2;                  /* 0x007A2 */
  } camera;
  uint8_t           seq_idx;                  /* 0x007A4 */
  uint8_t           night_sfx;                /* 0x007A5 */
  char              unk_08_[0x0002];          /* 0x007A6 */
  z64_lighting_t    lighting;                 /* 0x007A8 */
  char              unk_09_[0x0008];          /* 0x007B8 */
  z64_col_ctxt_t    col_ctxt;                 /* 0x007C0 */
  char              actor_ctxt[0x0008];       /* 0x01C24 */
  uint8_t           n_actors_loaded;          /* 0x01C2C */
  char              unk_0A_[0x0003];          /* 0x01C2D */
  struct
  {
    uint32_t        length;
    z64_actor_t    *first;
  }                 actor_list[12];           /* 0x01C30 */
  char              unk_0B_[0x0038];          /* 0x01C90 */
  z64_actor_t      *arrow_actor;              /* 0x01CC8 */
  z64_actor_t      *target_actor;             /* 0x01CCC */
  char              unk_0C_[0x0058];          /* 0x01CD0 */
  uint32_t          swch_flags;               /* 0x01D28 */
  uint32_t          temp_swch_flags;          /* 0x01D2C */
  uint32_t          unk_flags_0;              /* 0x01D30 */
  uint32_t          unk_flags_1;              /* 0x01D34 */
  uint32_t          chest_flags;              /* 0x01D38 */
  uint32_t          clear_flags;              /* 0x01D3C */
  uint32_t          temp_clear_flags;         /* 0x01D40 */
  uint32_t          collect_flags;            /* 0x01D44 */
  uint32_t          temp_collect_flags;       /* 0x01D48 */
  void             *title_card_texture;       /* 0x01D4C */
  char              unk_0D_[0x0007];          /* 0x01D50 */
  uint8_t           title_card_delay;         /* 0x01D57 */
  char              unk_0E_[0x000C];          /* 0x01D58 */
  struct
  {
    char            unk_0x01D64[4];           /* 0x01D64 */
    void           *ptr;                      /* 0x01D68 */
    int8_t          state;                    /* 0x01D6C */
                        /* = 0 : No Cutscene                    *
                         *   1 : Initializing skippable scene   *
                         *   2 : Skippable cutscene playing     *
                         *   3 : Initializing unskippable scene *
                         *   4 : Unskippable cutscene playing   */
    char            unk_0x01D6D[3];           /* 0x01D6D */
    uint16_t        frame;                    /* 0x01D70 */
    char            unk_0x01D72[6];           /* 0x01D72 */
    uint16_t        frame_lastcmd;            /* 0x01D78 */ /* frame of last cutscene command executed */
    char            unk_0x01D7A[0xA];         /* 0x01D7A */
    void           *camera_current;           /* 0x01D84 */

    /* TODO actor command notes courtesy of Noka; implement them...
     * at 0x1D88 the actor pointers start, there's 11 actor pointers
     * in total but 2 are always used by link and navi meaning there's
     * 9 free slots for custom actors
     * so there's 11 pointers, starting at 0x1D88
     * then inside each pointer
     * * 0x0 -> action
     * * 0x2 -> start frame s16
     * * 0x4 -> end frame s16
     * * 0x6 -> x rot
     * * 0x8 -> y rot
     * * 0xA -> z rot
     * * 0xC -> x start
     * * 0x10 -> y start
     * * 0x14 -> z start
     * * 0x18 -> x end
     * * 0x1C -> y end
     * * 0x20 -> z end
     * call these cutscene actor command struct
     */
  }                 cutscene;                 /* 0x01D64 through 0x01D88 */
  char              unk_0F_[0x01F0];          /* 0x01D88 */
  z64_sky_ctxt_t    sky_ctxt;                 /* 0x01F78 */
  char              unk_10_[0xE2C0];          /* 0x020C8 */
  char             *message_texture;          /* 0x10388 */
  char              unk_11_[0x0049];          /* 0x1038C */
  uint8_t           message_type;             /* 0x103D5 */
  char              unk_12_[0x0006];          /* 0x103D6 */
  uint8_t           message_state_1;          /* 0x103DC */
  char              pad_00_[0x0001];          /* 0x103DD */
  union
  {
    uint8_t         message_data_e[200];
    uint16_t        message_data_j[100];
  };                                          /* 0x103DE */
  char              unk_13_[0x0016];          /* 0x104A6 */
  uint8_t           message_state_2;          /* 0x104BC */
  char              unk_14_[0x0002];          /* 0x104BD */
  uint8_t           message_state_3;          /* 0x104BF */
  char              unk_15_[0x0020];          /* 0x104C0 */
  z64_actor_t      *textbox_actor;            /* 0x104E0 */ /* pointer to last actor that called textbox_begin() *
                                                             * also, pulling out the ocarina resets this to 0    */
  char              unk_104E4[0xC];           /* 0x104E4 */
  z64_if_ctxt_t     if_ctxt;                  /* 0x104F0 */
  z64_pause_ctxt_t  pause_ctxt;               /* 0x10760 */
  char              unk_16_[0x000C];          /* 0x10A14 */
  uint16_t          death_state;              /* 0x10A20 */
  char              unk_17_[0x0012];          /* 0x10A22 */
  uint8_t           sky_image_idx[2];         /* 0x10A34 */
  char              unk_18_[0x00CE];          /* 0x10A36 */
  uint8_t           day_phase;                /* 0x10B04 */
  char              unk_19_[0x000D];          /* 0x10B05 */
  uint8_t           rain_effect_1;            /* 0x10B12 */
  uint8_t           rain_level;               /* 0x10B13 */
  char              unk_1A_[0x0002];          /* 0x10A14 */
  uint8_t           rain_effect_2;            /* 0x10B16 */
  char              unk_1B_[0x0C8D];          /* 0x10B17 */
  z64_obj_ctxt_t    obj_ctxt;                 /* 0x117A4 */
  z64_room_ctxt_t   room_ctxt;                /* 0x11CBC */
  char              unk_1C_[0x0064];          /* 0x11D3C */
  float             unk_player_matrix[16];    /* 0x11DA0 */ /* Float Matrix Related to Link's Coordinates */
  char              unk_1C_2[0x0004];         /* 0x11DE0 */
  uint32_t          gameplay_frames;          /* 0x11DE4 */
  uint8_t           link_age;                 /* 0x11DE8 */
  char              unk_1D_;                  /* 0x11DE9 */
  uint8_t           spawn_index;              /* 0x11DEA */
  uint8_t           n_map_actors;             /* 0x11DEB */
  uint8_t           n_rooms;                  /* 0x11DEC */
  char              unk_1E_[0x0003];          /* 0x11DED */
  z64_vrom_file_t  *room_list;                /* 0x11DF0 */
  char              unk_1F_[0x0004];          /* 0x11DF4 */
  void             *map_actor_list;           /* 0x11DF8 */
  char              unk_20_[0x0008];          /* 0x11DFC */
  void             *scene_exit_list;          /* 0x11E04 */
  char              unk_21_[0x0004];          /* 0x11E08 */
  void             *elf_message;              /* 0x11E0C */
  uint32_t          situdata;                 /* 0x11E10 */ // situational userdata, only known use so far is Arwing
  uint8_t           skybox_type;              /* 0x11E14 */
  int8_t            scene_load_flag;          /* 0x11E15 */
  char              unk_23_[0x0004];          /* 0x11E16 */
  int16_t           entrance_index;           /* 0x11E1A */
  char              unk_24_[0x0042];          /* 0x11E1C */
  uint8_t           fadeout_transition;       /* 0x11E5E */
  char              unk_25_;          				/* 0x11E5F */
	z64_hit_ctxt_t    hit_ctxt;           /* 0x11E60 */ /*TODO: Document Struct */
	char              unk_26_[0x06B4];          /* 0x11E64 */
                                              /* 0x12518 */
} z64_global_t;

typedef struct {
	/* 0x00 */ void *printer; /* 0x800FBB60 */
	/* 0x04 */ uint32_t dlist_end;
	/* 0x08 */ uint16_t x;
	/* 0x0A */ uint16_t y;
	/* 0x0C */ uint16_t unk1;
	/* 0x0E */ uint8_t unk2; /* Set to 0 */
	/* 0x0F */ uint8_t unk3; /* Stuff happens with this. */
	/* 0x10 */ uint32_t string_rgba;
} z64_debug_text_t;

/* skelanime */
typedef struct {
  /* 0x00 */ uint8_t limb_count;
  /* 0x01 */ uint8_t unk1; /* Probably Padding*/
  /* 0x02 */ uint8_t dlist_count;
  /* 0x03 */ uint8_t unk2; /* Probably Padding */
  /* 0x04 */ void* limb_index;
  /* 0x08 */ uint32_t anim_current;
  /* 0x0C */ int32_t unk3; /* 0x00000000 */
  /* 0x10 */ float anim_frame_count;
  /* 0x14 */ float unk4;
  /* 0x18 */ float anim_current_frame;
  /* 0x1C */ float anim_playback_speed;
  /* 0x20 */ void* draw_table_rot;/*uint32_t unk5;*/ /* Actor Drawing Table? */
  /* 0x24 */ void* draw_table_pos;/*uint32_t unk6;*/
  /* 0x28 */ uint32_t unk7;
  /* 0x2C */ uint32_t unk8;
  /* 0x30 */ void* draw_table_func;/*uint32_t func_unk9;*/ /* Some function pointer */
  /* 0x34 */ int32_t pad1; /* 0x00000000 */
  /* 0x38 */ int32_t pad2; /* 0x00000000 */
  /* 0x3C */ uint16_t unk10;
  /* 0x3E */ uint16_t unk11; /* Probably Padding */
  /* 0x40 */
} z64_skelanime_t;

typedef struct
{
  u8 unk00[0x4C];
  z64_skelanime_t skelanime;
} z64_skelanime_weighted_t;


/*struct z64_particle_t;
typedef struct
{
  vec3f_t position;
  vec3f_t velocity;
  vec3f_t acceleration;
  void(*update)(z64_global_t*, int32_t, z64_particle_t*);
  void(*draw)(z64_global_t*, int32_t, z64_particle_t*);
  vec3f_t unk_2C;
  uint32_t unk_38;
  uint32_t unk_3C;
  uint16_t unk_30[13];
  uint16_t flags;
  int16_t life;
  uint8_t priority;
  uint8_t type;
} z64_particle_t;*/

enum dynapoly_move_flag {
  DPM_NONE = 0b00,
	DPM_PLAYER = 0b01,
 	DPM_ENEMY = 0b10
};

#endif
