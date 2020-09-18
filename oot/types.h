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

typedef struct
{
  uint8_t health;
  int16_t unk_02;
  int16_t unk_04;
  uint8_t mass;
} z64_collision_check_info_init_t;

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

typedef struct {
  int16_t posX;
  int16_t posY;
  int16_t posZ;
  uint8_t red;
  uint8_t green;
  uint8_t blue;
  uint8_t unk_09;
  int16_t radius;
} z64_lightinfo_params_t;

typedef struct
{
  uint8_t                type;
  z64_lightinfo_params_t params;
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

typedef struct z64_dynapoly {
    uint32_t    poly_id;                /* 0x0000  counter, starts from 0, each dynapoly actor gets a new id*/
    float       push_movement;                /* 0x0004 */
    float       unk_03;                /* 0x0008 */
    uint16_t    push_direction;                /* 0x000A */
    uint16_t    unk_05;                /* 0x000C */
    uint32_t    movement;              /* 0x0010 &>>01 updates position of actors on top, &>>02 updates rotation of actors on top */
    uint8_t     flags;                 /* 0x0014 &>>01 actor on top &>>02 Link on top &>>04 Link above it or on top &>>08 heavy actor on top */
    char        padding[0x0003];
} z64_dynapoly_t;

#include "../h/z64_collision_check.h"

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

typedef struct {
  vec3f_t pos;
  float unk_0C;
  rgb8_t color;
} z64_target_context_entry_t;

typedef struct {
  vec3f_t naviRefPos;
  vec3f_t targetCenterPos;
  struct {
    float red;
    float green;
    float blue;
    float alpha;
  } naviInner;
  struct {
    float red;
    float green;
    float blue;
    float alpha;
  } naviOuter;
  z64_actor_t* arrowPointedActor;
  z64_actor_t* targetedActor;
  float unk_40;
  float unk_44;
  int16_t unk_48;
  uint8_t activeType;
  uint8_t unk_4B;
  int8_t unk_4C;
  char unk_4D[3];
  z64_target_context_entry_t arr_50[3];
  z64_actor_t* unk_8C;
  z64_actor_t* unk_90;
  z64_actor_t* unk_94;
} z64_target_context_t;

typedef struct {
    /* 0x00 */ uint32_t      texture;
    /* 0x04 */ int16_t       unk_4;
    /* 0x06 */ int16_t       unk_6;
    /* 0x08 */ uint8_t       unk_8;
    /* 0x09 */ uint8_t       unk_9;
    /* 0x0A */ uint8_t       delayA;
    /* 0x0B */ uint8_t       delayB;
    /* 0x0C */ int16_t       unk_C;
    /* 0x0E */ int16_t       unk_E;
} z64_title_card_context_t;

typedef struct {
  uint32_t length;
  z64_actor_t* first;
} z64_actor_list_entry_t;

typedef struct {
  uint8_t unk_00;
  char unk_01[1];
  uint8_t unk_02;
  uint8_t unk_03;
  char unk_04[4];
  uint8_t total;
  z64_actor_list_entry_t actor_list[12];
  z64_target_context_t target_ctxt;
  struct {
    uint32_t swch;
    uint32_t temp_swch;
    uint32_t unk0;
    uint32_t unk1;
    uint32_t chest;
    uint32_t clear;
    uint32_t temp_clear;
    uint32_t collect;
    uint32_t temp_collect;
  } flags;
  z64_title_card_context_t title_ctxt;
  char unk_138[4];
  void* absolute_space;
} z64_actor_context_t;

typedef struct {
    float                height;
    int16_t              dist;
} special0;

typedef struct {
    /* 0x0000 */ float   unk_00;
    /* 0x0004 */ float   unk_04;
    /* 0x0008 */ int16_t unk_08;
} special9; // size = 0xC

typedef struct {
    char                 unk_00[0xC];
    int32_t              unk_0C;
    float                target_init_zoom; //Kungfu zoom
    int16_t              unk_14;
    int16_t              unk_16;
    int16_t              unk_18;
    int16_t              unk_1A;
    float                unk_1C;
    float                unk_20;
    int16_t              unk_24;
    int16_t              unk_26;
    int16_t              unk_28; //Angle?
    int16_t              unk_2A;
} normal3_unk20;

typedef struct {
    float                height;
    float                dist; // distance
    float                angle; //z-targeting
    float                unk_0C; //same?
    float                nearby_height;
    float                dist_height; // fov
    float                unk_18;
    int16_t              unk_1C; // theta
    int16_t              unk_1E;
    normal3_unk20        unk_20;
} normal3; //Z-Targeting

typedef struct {
    /* 0x0000 */ float            unk_00;
    /* 0x0004 */ int16_t          unk_04;
} demo1_unk_04; // size = 0x14

typedef struct {
    /* 0x0000 */ int16_t          unk_00;
    /* 0x0002 */ int16_t          unk_02;
    /* 0x0004 */ demo1_unk_04     unk_04;
} demo1; // size = 0x18

typedef struct {
    /* 0x0000 */ z64_actor_t*     door;
    /* 0x0004 */ int16_t          unk_04;
    /* 0x0006 */ int16_t          unk_06;
    /* 0x0008 */ int16_t          unk_08;
    /* 0x000A */ int16_t          unk_0A;
    /* 0x000C */ special9         spec9;
    /* 0x0018 */ int16_t          unk_18;
} z64_camera_door_t; // size = 0x1C

typedef struct {
    /* 0x00 */ int8_t             continueFlag;
    /* 0x01 */ int8_t             cameraRoll;
    /* 0x02 */ uint16_t           nextPointFrame;
    /* 0x04 */ float              viewAngle; // in degrees
    /* 0x08 */ vec3s_t            pos;
} z64_camera_demo_point_t; // size = 0x10

typedef union {
    char                 data[0x50];
    int16_t              sh[2];
    int32_t              w;
    float                f;
    z64_camera_door_t    doorCam;
    special0             spec0;
    demo1                demo1;
    normal3              normal3;
} camera_unk_00;

/* Camera */
typedef struct {
    /* 0x0000 */ camera_unk_00            unk_00;
    /* 0x0050 */ vec3f_t                  at;
    /* 0x005C */ vec3f_t                  eye;
    /* 0x0068 */ vec3f_t                  unk_68;
    /* 0x0074 */ vec3f_t                  eyeNext;
    /* 0x0080 */ vec3f_t                  unk_80;
    /* 0x008C */ struct z64_global_t*     globalCtx;
    /* 0x0090 */ z64_player_t*            player;
    /* 0x00AC */ vec3f_t                  playerPos;
    /* 0x00AC */ vec3s_t                  playerRot;
    /* 0x00A8 */ z64_actor_t*             target;
    /* 0x00AC */ vec3f_t                  targetPos;
    /* 0x00AC */ vec3s_t                  targetRot;
    /* 0x00C0 */ vec3f_t                  unk_C0; // has to do with how quickly the camera rotates link.
    /* 0x00CC */ vec3f_t                  unk_CC; // has to do with how quickly the camera zooms
    /* 0x00D8 */ float                    unk_D8;
    /* 0x00DC */ float                    dist; // possibly a Vec3f
    /* 0x00E0 */ float                    unk_E0;
    /* 0x00E4 */ vec3f_t                  unk_E4; //pos offset
    /* 0x00F0 */ vec3f_t                  unk_F0;
    /* 0x00FC */ float                    fov;
    /* 0x0100 */ float                    unk_100; // update rate of distance from link?
    /* 0x0104 */ float                    unk_104;
    /* 0x0108 */ vec3f_t                  unk_108;
    /* 0x0114 */ char                     unk_114[0x4];
    /* 0x0118 */ int32_t                  unk_118;
    /* 0x011C */ int32_t                  unk_11C;
    /* 0x0120 */ char                     unk_120[0x4];
    /* 0x0124 */ z64_camera_demo_point_t* atPoints;
    /* 0x0128 */ z64_camera_demo_point_t* eyePoints;
    /* 0x012C */ int16_t                  relativeToPlayer; // camera Cutscene points are relative to player's position
    /* 0x012E */ int16_t                  unk_12E;
    /* 0x0130 */ int16_t                  uid;    // Unique identifier of the camera.
    /* 0x0132 */ char                     unk_132[0x02];
    /* 0x0134 */ vec3s_t                  unk_134;
    /* 0x013A */ vec3s_t                  unk_13A; // seems to be a copy of unk_134, but unused for anything different?
    /* 0x0140 */ int16_t                  status;
    /* 0x0142 */ int16_t                  setting; // referred to as set
    /* 0x0144 */ int16_t                  mode;
    /* 0x0146 */ int16_t                  unk_146; // unknown if used
    /* 0x0148 */ int16_t                  unk_148; // ID for door camera? (see func_8005AD40)
    /* 0x014A */ int16_t                  unk_14A; // unknown if used
    /* 0x014C */ int16_t                  unk_14C;
    /* 0x014E */ int16_t                  unk_14E;
    /* 0x0150 */ int16_t                  unk_150; // unknown if used
    /* 0x0152 */ int16_t                  unk_152;
    /* 0x0154 */ uint16_t                 unk_154; // appears to be some clone of setting?
    /* 0x0156 */ int16_t                  unk_156;
    /* 0x0158 */ int16_t                  unk_158; // unknown if used
    /* 0x015A */ int16_t                  roll;
    /* 0x015C */ int16_t                  unk_15C; // unknown if used
    /* 0x015E */ int16_t                  unk_15E;
    /* 0x0160 */ int16_t                  unk_160;
    /* 0x0162 */ int16_t                  unk_162;
    /* 0x0164 */ int16_t                  unk_164;
    /* 0x0166 */ int16_t                  unk_166; // unknown if used
    /* 0x0168 */ int16_t                  unk_168;
    /* 0x016A */ int16_t                  unk_16A; // unknown if used
} z64_gl_camera_t; // size = 0x16C

typedef struct {
    int8_t          continue_flag;            /* 0x00 */
    int8_t          roll;                     /* 0x01 */
    uint16_t        next_point_frame;         /* 0x02 */
    float           view_angle; // in degrees /* 0x04 */
    vec3s_t         pos;                      /* 0x08 */
} z64_cutscene_camera_point_t; // size = 0x10

typedef struct {
    uint16_t        action;                   /* 0x00 */
    uint16_t        start_frame;              /* 0x02 */
    uint16_t        end_frame;                /* 0x04 */
    vec3s_t         rot;                      /* 0x06 */
    struct
    {
      int32_t       x;
      int32_t       y;
      int32_t       z;
    } start_pos;                              /* 0x0C */
    struct
    {
      int32_t       x;
      int32_t       y;
      int32_t       z;
    } end_pos;                                /* 0x18 */
    struct
    {
      int32_t       x;
      int32_t       y;
      int32_t       z;
    } normal;                                /* 0x24 */

} z64_cutscene_actor_action_t; // size = 0x30

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

  z64_gl_camera_t   camera[4];                /* 0x001E0 */
  z64_gl_camera_t*  pointer[4];               /* 0x00790 */
  int16_t           active_camera;            /* active cam (0-3) 0x007A0 */
  int16_t           next_camera;              /* 0x007A2 */
  uint8_t           seq_idx;                  /* 0x007A4 */
  uint8_t           night_sfx;                /* 0x007A5 */
  char              unk_08_[0x0002];          /* 0x007A6 */
  z64_lighting_t    lighting;                 /* 0x007A8 */
  char              unk_09_[0x0008];          /* 0x007B8 */
  z64_col_ctxt_t    col_ctxt;                 /* 0x007C0 */
  z64_actor_context_t actor_ctxt;             /* 0x01C24 */
  struct
  {
    char                           unk_00[0x4];              /* 0x01D64 */
    void                          *ptr;                      /* 0x01D68 */
    uint8_t                        state;                    /* 0x01D6C */
                                   /* = 0 : No Cutscene                    */
                                   /*   1 : Initializing skippable scene   */
                                   /*   2 : Skippable cutscene playing     */
                                   /*   3 : Initializing unskippable scene */
                                   /*   4 : Unskippable cutscene playing   */
    float                          unk_0C;                   /* 0x01D70 */
    uint16_t                       frame;                    /* 0x01D74 */
    uint16_t                       unk_12;                   /* 0x01D76 */
    int32_t                        unk_14;                   /* 0x01D78 */
    uint16_t                       frame_lastcmd;            /* 0x01D7C */ /* frame of last cutscene command executed */
    uint8_t                        unk_1A;                   /* 0x01D7E */
    uint8_t                        unk_1B;                   /* 0x01D7F */
    z64_cutscene_camera_point_t   *cam_focus;                /* 0x01D80 */
    z64_cutscene_camera_point_t   *cam_pos;                  /* 0x01D84 */
    z64_cutscene_actor_action_t   *link_action;              /* 0x01D88 */
    z64_cutscene_actor_action_t   *npc_action[0xA];          /* 0x01D8C */
  }                 cutscene;                 /* 0x01D64 */

  char              unk_0F_[0x01C4];          /* 0x01DB4 */
  z64_sky_ctxt_t    sky_ctxt;                 /* 0x01F78 */
  char              unk_10_[0xE2C0];          /* 0x020C8 */
  char             *message_texture;          /* 0x10388 */
  char              unk_11_[0x0044];          /* 0x1038C */
  uint16_t          message_current;          /* 0x103D0 */
  char              unk_0x103D2[0x0003];         /* 0x103D2 */
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
  char              unk_15_[0x0004];          /* 0x104C0 */
  uint16_t          played_ocarina_song;      /* 0x104C4 */
  char              unk_15_2[0x001A];         /* 0x104C6 */
  z64_actor_t      *textbox_actor;            /* 0x104E0 */ /* pointer to last actor that called textbox_begin() *
                                                             * also, pulling out the ocarina resets this to 0    */
  char              unk_104E4[0xC];           /* 0x104E4 */
  z64_if_ctxt_t     if_ctxt;                  /* 0x104F0 */
  z64_pause_ctxt_t  pause_ctxt;               /* 0x10760 */
  char              unk_16_[0x000C];          /* 0x10A14 */
  uint16_t          death_state;              /* 0x10A20 */
  char              unk_17_[0x0012];          /* 0x10A22 */
  uint8_t           sky_image_idx[2];         /* 0x10A34 */
  char              unk_18_[0x007A];          /* 0x10A36 */
  int16_t           unk_0x10AB0[6];           /* 0x10AB0 */
  char              unk_18_1[0x48];           /* 0x10ABC */
  uint8_t           day_phase;                /* 0x10B04 */
  char              unk_19_[0x000D];          /* 0x10B05 */
  uint8_t           rain_effect_1;            /* 0x10B12 */
  uint8_t           rain_level;               /* 0x10B13 */
  char              unk_1A_[0x0002];          /* 0x10A14 */
  uint8_t           rain_effect_2;            /* 0x10B16 */
  char              unk_1B_[0x0C8D];          /* 0x10B17 */
  z64_obj_ctxt_t    obj_ctxt;                 /* 0x117A4 */
  z64_room_ctxt_t   room_ctxt;                /* 0x11CBC */
  char              unk_11D3C[0x10];          /* 0x11D3C */
  int              (*unk_11D4C)(void*, void*);/* 0x11D4C */
  char              unk_11D50[0x50];          /* 0x11D50 */
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

typedef struct z64_skelanime_s z64_skelanime_t;

typedef enum {
  ANIMATION_LINKANIMETION
  , ANIMATION_TYPE1
  , ANIMATION_TYPE2
  , ANIMATION_TYPE3
  , ANIMATION_TYPE4
  , ANIMATION_TYPE5
} z64_animation_type_e;

typedef struct {
  /* 0x00 */ vec3s_t         translation;
  /* 0x06 */ uint8_t         first_child_index;
  /* 0x07 */ uint8_t         sibling_limb_index;
  /* 0x08 */ Gfx*            dlist[1];
} z64_skel_limb_entry_t;

typedef struct {
  /* 0x00 */ z64_skel_limb_entry_t* limbs[1];
} z64_skeleton_t;

typedef struct {
  /* 0x00 */ z64_skeleton_t* skeleton;
  /* 0x04 */ uint8_t         limb_count;
  /* 0x05 */ uint8_t         ___pad0;
  /* 0x08 */ uint8_t         dlist_count;
} z64_skeleton_header_t;

typedef struct {
  int16_t                    frame_count;
  int16_t                    __pad0;
} z64_anim_header_init_t;

typedef struct {
  z64_anim_header_init_t     common;
  uint32_t                   rotation_values;
  uint32_t                   rotation_index;
  uint16_t                   limit;
} z64_anim_header_t;

typedef struct {
  uint8_t                    req[0x20]; /* DmaRequest */
  OSMesgQueue                msgQueue;
  OSMesg                     msg;
} z64_animation_type_0_t;

typedef struct {
  uint8_t                    unk0;
  uint8_t                    vec_count;
  vec3s_t*                   dst;
  vec3s_t*                   src;
} z64_animation_type_1_t;

typedef struct {
  uint8_t                    unk0;
  uint8_t                    limb_count;
  vec3s_t*                   unk_04;
  vec3s_t*                   unk_08;
  float                      unk_0C;
} z64_animation_type_2_t;

typedef struct {
  uint8_t                    unk0;
  uint8_t                    vec_count;
  vec3s_t*                   dst;
  vec3s_t*                   src;
  uint8_t*                   index;
} z64_animation_type_3_t;

typedef struct {
  uint8_t                    unk0;
  uint8_t                    vec_count;
  uint8_t                    unk_02[2];
  vec3s_t*                   dst;
  vec3s_t*                   src;
  uint8_t*                   index;
} z64_animation_type_4_t;

typedef struct {
  z64_actor_t*               actor;
  z64_skelanime_t*           skelanime;
  float                      unk_08;
} z64_animation_type_5_t;

typedef struct {
  uint8_t                    raw[0x3C];
} z64_animation_type_raw_t;

typedef union {
  z64_animation_type_raw_t   raw;
  z64_animation_type_1_t     type0;
  z64_animation_type_2_t     type1;
  z64_animation_type_3_t     type2;
  z64_animation_type_4_t     type3;
  z64_animation_type_5_t     type5;
} z64_animation_type_t;

typedef struct {
  uint8_t                    type;
  uint8_t                    unk_01;
  z64_animation_type_t       types;
} z64_animation_entry_t;

typedef struct {
  z64_anim_header_init_t     common;
  uint32_t                   anim; /* Animation Segment Address */
} z64_animation_entry_link_t;

struct z64_skelanime_s {
   uint8_t         limb_count;                                /* 0x00 */
   uint8_t         mode;                                      /* 0x01 */
   uint8_t         dlist_count;                               /* 0x02 */
   uint8_t         _pad0;                                     /* 0x03 */
   z64_skeleton_t* skeleton;                                  /* 0x04 */
   union {
    z64_anim_header_t*            seg;
    z64_animation_entry_link_t*   link_animetion_seg;
    z64_anim_header_init_t*       common_seg;
  } anim_current;                                             /* 0x08 */
   float           start_frame; /* Initial Animation Frame */ /* 0x0C */
   float           anim_frame_count;                          /* 0x10 */
   float           anim_frame_total;                          /* 0x14 */
   float           anim_current_frame;                        /* 0x18 */
   float           anim_playback_speed;                       /* 0x1C */
   vec3s_t*        limb_draw_table; /* now_joint */           /* 0x20 */
   vec3s_t*        transition_draw_table; /* morf_joint */    /* 0x24 */
   float           trans_current_frame;                       /* 0x28 */
   float           transition_step;                           /* 0x2C */
   int32_t         (*anim_update)();                          /* 0x30 */
   int8_t          init_flags;                                /* 0x34 */
   uint8_t         flags;                                     /* 0x35 */
   int16_t         prev_frame_rot;                            /* 0x36 */
   vec3s_t         prev_frame_pos;                            /* 0x38 */
   vec3s_t         unk_0x3E;                                  /* 0x3E */
}; /* Size 0x44 */

typedef struct
{
  uint8_t          unk00[0x4C];
  z64_skelanime_t  skelanime;
} z64_skelanime_weighted_t;

typedef struct {
     char          unk_00[0x184];                            /* 0x000 */
     rgba8_t       p1StartColor;                             /* 0x184 */
     rgba8_t       p2StartColor;                             /* 0x188 */
     rgba8_t       p1EndColor;                               /* 0x18C */
     rgba8_t       p2EndColor;                               /* 0x190 */
     int32_t       elemDuration;                             /* 0x194 */
     int32_t       unkFlag;                                  /* 0x198 */
     int32_t       calcMode;                                 /* 0x19C */
} z_eff_blure_init_t; // size = 0x1A0

typedef struct {
     int32_t       state;                                    /* 0x00 */
     int32_t       timer;                                    /* 0x04 */
     vec3s_t       p1;                                       /* 0x08 */
     vec3s_t       p2;                                       /* 0x0E */
     uint16_t      flags;                                    /* 0x14 */
} z64_eff_blure_elem_t; // size = 0x18

typedef struct {
     z64_eff_blure_elem_t elements[16];                      /* 0x000 */
     int32_t       calcMode;                                 /* 0x180 */
     float         mode4Param;                               /* 0x184 */
     uint16_t      flags;                                    /* 0x188 */
     int16_t       addAngleChange;                           /* 0x18A */
     int16_t       addAngle;                                 /* 0x18C */
     rgba8_t       p1StartColor;                             /* 0x18E */
     rgba8_t       p2StartColor;                             /* 0x192 */
     rgba8_t       p1EndColor;                               /* 0x196 */
     rgba8_t       p2EndColor;                               /* 0x19A */
     uint8_t       numElements; // "now_edge_num"            /* 0x19E */
     uint8_t       elemDuration;                             /* 0x19F */
     uint8_t       unkFlag;                                  /* 0x1A0 */
     uint8_t       drawMode;                                 /* 0x1A1 */ // 0: simple; 1: simple with alt colors; 2+: smooth
     rgba8_t       altPrimColor; // used with drawMode 1     /* 0x1A2 */
     rgba8_t       altEnvColor; // used with drawMode 1      /* 0x1A6 */
} z64_eff_blure_t; // size = 0x1AC

typedef struct {
     uint8_t        buttonItems[4];                          /* 0x00 */
     uint8_t        cButtonSlots[3];                         /* 0x04 */
     uint16_t       equipment;                               /* 0x08 */
} ItemEquips; // size = 0x0A

typedef struct {
     uint32_t       chest;                                   /* 0x00 */
     uint32_t       swch;                                    /* 0x04 */
     uint32_t       clear;                                   /* 0x08 */
     uint32_t       collect;                                 /* 0x0C */
     uint32_t       unk;                                     /* 0x10 */
     uint32_t       rooms;                                   /* 0x14 */
     uint32_t       floors;                                  /* 0x18 */
} SaveSceneFlags; // size = 0x1C

typedef struct {
     int16_t        scene;                                   /* 0x00 */
     vec3s_t        pos;                                     /* 0x02 */
     int16_t        angle;                                   /* 0x08 */
} HorseData; // size = 0x0A

typedef struct {
     vec3f_t        pos;                                     /* 0x00 */
     int16_t        yaw;                                     /* 0x0C */
     int16_t        playerParams;                            /* 0x0E */
     int16_t        entranceIndex;                           /* 0x10 */
     uint8_t        roomIndex;                               /* 0x12 */
     int8_t         data;                                    /* 0x13 */
     uint32_t       tempSwchFlags;                           /* 0x14 */
     uint32_t       tempCollectFlags;                        /* 0x18 */
} RespawnData; // size = 0x1C

// Save Context
typedef struct {
     int32_t        entranceIndex;                           /* 0x0000 */
     int32_t        linkAge; // 0: Adult; 1: Child           /* 0x0004 */
     int32_t        cutsceneIndex;                           /* 0x0008 */
     uint16_t       dayTime; // "zelda_time"                 /* 0x000C */
     int32_t        nightFlag;                               /* 0x0010 */
     int32_t        unk_14;                                  /* 0x0014 */
     int32_t        unk_18;                                  /* 0x0018 */
     char           newf[6]; // string "ZELDAZ"              /* 0x001C */
     int16_t        deaths;                                  /* 0x0022 */
     char           playerName[8];                           /* 0x0024 */
     int16_t        n64ddFlag;                               /* 0x002C */
     int16_t        healthCapacity; // "max_life"            /* 0x002E */
     int16_t        health; // "now_life"                    /* 0x0030 */
     int8_t         magicLevel;                              /* 0x0032 */
     int8_t         magic;                                   /* 0x0033 */
     int16_t        rupees;                                  /* 0x0034 */
     uint16_t       bgsHitsLeft;                             /* 0x0036 */
     uint16_t       naviTimer;                               /* 0x0038 */
     uint8_t        magicAcquired;                           /* 0x003A */
     char           unk_3B[0x0001];                          /* 0x003B */
     uint8_t        doubleMagic;                             /* 0x003C */
     uint8_t        doubleDefense;                           /* 0x003D */
     int8_t         bgsFlag;                                 /* 0x003E */
     ItemEquips     childEquips;                             /* 0x0040 */
     ItemEquips     adultEquips;                             /* 0x004A */
     char           unk_54[0x0014];                          /* 0x0054 */
     ItemEquips     equips;                                  /* 0x0068 */
     char           unk_72[0x0002];                          /* 0x0072 */
     uint8_t        items[24];                               /* 0x0074 */
     int8_t         ammo[16];                                /* 0x008C */
     uint16_t       equipment;                               /* 0x009C */
     uint32_t       upgrades;                                /* 0x00A0 */
     uint32_t       questItems;                              /* 0x00A4 */
     uint8_t        dungeonItems[20];                        /* 0x00A8 */
     int8_t         dungeonKeys[19];                         /* 0x00BC */
     int8_t         defenseHearts;                           /* 0x00CF */
     int16_t        gsTokens;                                /* 0x00D0 */
     SaveSceneFlags sceneFlags[124];                         /* 0x00D4 */
     struct {
       int32_t      pos[3];                                  /* 0x0E64 */
       int32_t      yaw;                                     /* 0x0E70 */
       int32_t      playerParams;                            /* 0x0E74 */
       int32_t      entranceIndex;                           /* 0x0E78 */
       int32_t      roomIndex;                               /* 0x0E7C */
       int32_t      set;                                     /* 0x0E80 */
       int32_t      tempSwchFlags;                           /* 0x0E84 */
       int32_t      tempCollectFlags;                        /* 0x0E88 */
     }fw;
     char           unk_E8C[0x0010];                         /* 0x0E8C */
     uint8_t        gsFlags[24];                             /* 0x0E9C */
     char           unk_EB4[0x0010];                         /* 0x0EB4 */
     int32_t        unk_EC4;                                 /* 0x0EC4 */
     char           unk_EC8[0x000C];                         /* 0x0EC8 */
     uint16_t       eventChkInf[14]; // "event_chk_inf"      /* 0x0ED4 */
     uint16_t       itemGetInf[4]; // "item_get_inf"         /* 0x0EF0 */
     uint16_t       infTable[30]; // "inf_table"             /* 0x0EF8 */
     char           unk_F34[0x0004];                         /* 0x0F34 */
     uint32_t       worldMapAreaData; // "area_arrival"      /* 0x0F38 */
     char           unk_F3C[0x040C];                         /* 0x0F3C */
     HorseData      horseData;                               /* 0x1348 */
     uint16_t       checksum; // "check_sum"                 /* 0x1352 */
     int32_t        fileNum; // "file_no"                    /* 0x1354 */
     char           unk_1358[0x0004];                        /* 0x1358 */
     int32_t        gameMode;                                /* 0x135C */
     int32_t        sceneSetupIndex;                         /* 0x1360 */
     int32_t        respawnFlag; // "restart_flag"           /* 0x1364 */
     RespawnData    respawn[3]; // "restart_data"            /* 0x1368 */
     char           unk_13BC[0x0008];                        /* 0x13BC */
     int16_t        dogParams;                               /* 0x13C4 */
     uint8_t        unk_13C6;                                /* 0x13C6 */
     uint8_t        unk_13C7;                                /* 0x13C7 */
     int16_t        nayrusLoveTimer;                         /* 0x13C8 */
     char           unk_13CA[0x0002];                        /* 0x13CA */
     int16_t        rupeeAccumulator;                        /* 0x13CC */
     int16_t        timer1State;                             /* 0x13CE */
     int16_t        timer1Value;                             /* 0x13D0 */
     int16_t        timer2State;                             /* 0x13D2 */
     int16_t        timer2Value;                             /* 0x13D4 */
     int16_t        timerX[2];                               /* 0x13D6 */
     int16_t        timerY[2];                               /* 0x13DA */
     char           unk_13DE[0x0002];                        /* 0x13DE */
     uint8_t        seqIndex;                                /* 0x13E0 */
     uint8_t        nightSeqIndex;                           /* 0x13E1 */
     uint8_t        buttonStatus[5];                         /* 0x13E2 */
     uint8_t        unk_13E7;                                /* 0x13E7 */
     uint16_t       unk_13E8; // alpha type?                 /* 0x13E8 */
     uint16_t       unk_13EA; // also alpha type?            /* 0x13EA */
     uint16_t       unk_13EC; // alpha type counter?         /* 0x13EC */
     uint16_t       unk_13EE; // previous alpha type?        /* 0x13EE */
     int16_t        unk_13F0;                                /* 0x13F0 */
     int16_t        unk_13F2;                                /* 0x13F2 */
     int16_t        unk_13F4;                                /* 0x13F4 */
     int16_t        unk_13F6;                                /* 0x13F6 */
     int16_t        unk_13F8;                                /* 0x13F8 */
     uint16_t       eventInf[4]; // "event_inf"              /* 0x13FA */
     uint16_t       mapIndex; // intended for maps/minimaps  /* 0x1402 */
     uint16_t       minigameState;                           /* 0x1404 */
     uint16_t       minigameScore; // "yabusame_total"       /* 0x1406 */
     char           unk_1408[0x0001];                        /* 0x1408 */
     uint8_t        language;                                /* 0x1409 */
     uint8_t        audioSetting;                            /* 0x140A */
     char           unk_140B[0x0001];                        /* 0x140B */
     uint8_t        zTargetingSetting; // 0: Switch; 1: Hold /* 0x140C */
     uint16_t       unk_140D; // bgm related                 /* 0x140D */
     uint8_t        unk_1410;                                /* 0x1410 */
     uint8_t        unk_1411;                                /* 0x1411 */
     uint16_t       nextCutsceneIndex;                       /* 0x1412 */
     uint8_t        cutsceneTrigger;                         /* 0x1414 */
     uint8_t        chamberCutsceneNum;                      /* 0x1415 */
     uint16_t       nextDayTime; // "next_zelda_time"        /* 0x1416 */
     uint8_t        fadeDuration;                            /* 0x1418 */
     uint8_t        unk_1419; // transition related          /* 0x1419 */
     uint16_t       environmentTime;                         /* 0x141A */
     uint8_t        dogIsLost;                               /* 0x141C */
     uint8_t        nextTransition;                          /* 0x141D */
     char           unk_141E[0x0002];                        /* 0x141E */
     int16_t        worldMapArea;                            /* 0x1420 */
     int16_t        unk_1422; // day time related            /* 0x1422 */
     int16_t        healthAccumulator;                       /* 0x1424 */
} z64_save_context_t; // size = 0x1428
/* example of how to use save context in custom actor:

  z64_save_context_t *saveCtx = (void*)Z64GL_SAVE_CONTEXT;
  saveCtx->gsTokens = 100;
*/

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
