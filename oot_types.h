#ifndef __Z64OVL_OOT_TYPES_H__
#define __Z64OVL_OOT_TYPES_H__

#include <stdint.h>
#include "n64.h"
#include "mips.h"
#include "actor_oot.h"

// Controller Input
typedef enum {
	INPUT_NONE = 0b0000000000000000,
	INPUT_C_RIGHT = 0b0000000000000001,
	INPUT_C_LEFT = 0b0000000000000010,
	INPUT_C_DOWN = 0b0000000000000100,
	INPUT_C_UP = 0b0000000000001000,
	INPUT_R_TRIGGER = 0b0000000000010000,
	INPUT_L_TRIGGER = 0b0000000000100000,
	INPUT_D_RIGHT = 0b0000000100000000,
	INPUT_D_LEFT = 0b0000001000000000,
	INPUT_D_DOWN = 0b0000010000000000,
	INPUT_D_UP = 0b0000100000000000,
	INPUT_START = 0b0001000000000000,
	INPUT_Z = 0b0010000000000000,
	INPUT_B = 0b0100000000000000,
	INPUT_A = 0b1000000000000000
} z64_button_t;

typedef struct {
	z64_button_t	button;
	char	stick_x;
	char	stick_y;
	char	errno;
} OSContPad;

typedef struct {
	OSContPad current;
	OSContPad last;
	OSContPad pressEdge;
	OSContPad releaseEdge;
} z64_controller_t;

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
typedef struct{
	z64_gfx_t *gfx_ctxt;
	int *update;
	int *destuctor;
	int *init_next;
	int size;
	z64_controller_t controller[4];
	uint32_t heap_size;
	int *heap;
	int *heap_free_start;
	int *heap_free_end;
	int *unk1;
	int *unk2;
	int *unk3;
	int *unk4;
	int *unk5;
	int execute;
	int update_count;
	int unk6;
} z64_game_state_t;

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
  int8_t            numlights;                /* 0x0000 */
  char              pad_00_[0x0007];          /* 0x0001 */
  Lightsn           lites;                    /* 0x0008 */
                                              /* 0x0080 */
} z64_gbi_lights_t;

typedef void (*z64_light_handler_t)(z64_gbi_lights_t*, z64_lightn_t*,
                                    z64_actor_t*);

/* game context */
typedef struct
{
  z64_ctxt_t        common;                   /* 0x00000 */
  uint16_t          scene_index;              /* 0x000A4 */
  char              unk_00_[0x000A];          /* 0x000A6 */
  void             *scene_file;               /* 0x000B0 */
  char              unk_01_[0x000C];          /* 0x000B4 */
  uint32_t          screen_top;               /* 0x000C0 */
  uint32_t          screen_bottom;            /* 0x000C4 */
  uint32_t          screen_left;              /* 0x000C8 */
  uint32_t          screen_right;             /* 0x000CC */
  float             camera_distance;          /* 0x000D0 */
  float             fog_distance;             /* 0x000D4 */
  float             z_distance;               /* 0x000D8 */
  float             unk_02_;                  /* 0x000DC */
  char              unk_03_[0x0190];          /* 0x000E0 */
  z64_actor_t      *camera_focus;             /* 0x00270 */
  char              unk_04_[0x00AE];          /* 0x00274 */
  uint16_t          camera_mode;              /* 0x00322 */
  char              unk_05_[0x001A];          /* 0x00324 */
  uint16_t          camera_flag_1;            /* 0x0033E */
  char              unk_06_[0x016C];          /* 0x00340 */
  int16_t           event_flag;               /* 0x004AC */
  char              unk_07_[0x02F6];          /* 0x004AE */
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
  char              unk_0E_[0x0010];          /* 0x01D58 */
  void             *cutscene_ptr;             /* 0x01D68 */
  int8_t            cutscene_state;           /* 0x01D6C */
  char              unk_0F_[0x020B];          /* 0x01D6D */
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
  char              unk_15_[0x0030];          /* 0x104C0 */
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
  char              unk_1C_[0x00A8];          /* 0x11D3C */
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
  char              unk_22_[0x0004];          /* 0x11E10 */
  uint8_t           skybox_type;              /* 0x11E14 */
  int8_t            scene_load_flag;          /* 0x11E15 */
  char              unk_23_[0x0004];          /* 0x11E16 */
  int16_t           entrance_index;           /* 0x11E1A */
  char              unk_24_[0x0042];          /* 0x11E1C */
  uint8_t           fadeout_transition;       /* 0x11E5E */
  char              unk_25_[0x06B9];          /* 0x11E5F */
                                              /* 0x12518 */
} z64_global_t;

typedef struct {
	/* 0x00 */ uint32_t printer; /* 0x800FBB60 */
	/* 0x04 */ uint32_t dlist_end;
	/* 0x08 */ uint16_t x;
	/* 0x0A */ uint16_t y;
	/* 0x0C */ uint16_t unk1;
	/* 0x0E */ uint8_t unk2;
	/* 0x0F */ uint8_t unk3;
	/* 0x10 */ uint32_t unk4;
} z64_debug_text_t;

/*enum DISP{
	WORK = 0x01BC,
	OVERLAY = 0x02B0,
	POLY_OPA = 0x02C0,
	POLY_XLU = 0x02D0
};*/

/* Actor Specific? */
typedef struct {
  /* 0x00 */ uint8_t limb_count;
  /* 0x01 */ uint8_t unk1; /* Probably Padding*/
  /* 0x02 */ uint8_t dlist_count;
  /* 0x03 */ uint8_t unk2; /* Probably Padding */
  /* 0x04 */ uint32_t limb_index;
  /* 0x08 */ uint32_t anim_current;
  /* 0x0C */ int unk3; /* 0x00000000 */
  /* 0x10 */ float anim_frame_count;
  /* 0x14 */ float unk4;
  /* 0x18 */ float anim_current_frame;
  /* 0x1C */ float anim_playback_speed;
  /* 0x20 */ uint32_t unk5; /* Actor Drawing Table? */
  /* 0x24 */ uint32_t unk6;
  /* 0x28 */ uint32_t unk7;
  /* 0x2C */ uint32_t unk8;
  /* 0x30 */ uint32_t func_unk9; /* Some function pointer */
  /* 0x34 */ int pad1; /* 0x00000000 */
  /* 0x38 */ int pad2; /* 0x00000000 */
  /* 0x3C */ uint16_t unk10;
  /* 0x3E */ uint16_t unk11; /* Probably Padding */
  /* 0x40 */
} z64_skelanime_t;

// Actor Collision
typedef struct z64_capsule_init_s {
  /* 0x00 */ uint32_t unk1;
  /* 0x04 */ uint32_t unk2;
  /* 0x08 */ uint32_t unk3;
  /* 0x0C */ uint32_t unk4;
  /* 0x10 */ uint8_t damage_type;
  /* 0x11 */ uint8_t damage_amount;
  /* 0x12 */ uint16_t unk5;
  /* 0x14 */ uint32_t unk6;
  /* 0x18 */ uint32_t unk7;
  /* 0x1C */ uint32_t unk8;
  /* 0x20 */ uint16_t radius;
  /* 0x22 */ uint16_t height;
  /* 0x24 */ uint32_t unk9;
  /* 0x28 */ uint32_t unk10;
  /* 0x2C */
} z64_capsule_init_t;

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
} z64_damagechart_init_t;

typedef struct z64_capsule_s {
/*00*/	z64_actor_t *actor; // actor instance; TODO Is this a z64_actor_t or a typeless instance?
/*04*/	u32 unk_0x4;
/*08*/	z64_actor_t *colliding_actor; // colliding actor instance?; TODO Is this a z64_actor_t or a typeless instance?
/*0C*/	u32 unk_0xC;
	// TODO Needs better naming. Also, why are these values out of order?

/* 0010 :
 *** old notes say 'if & 0x0002, is detecting a Deku Nut hit?'. I can't verify this.
 *** However, our Kibako rewrite suggests that & 0x0002 is for detecting any attack from
 *** Link. Sword swing, Deku Stick swing, ammo, etc.
*/
/*10*/	u16 cso_0x01; //if & 0x0002, is detecting a Deku Nut hit?


/*12*/	u16 unk_0x12; //bitwise-and compared to opposing collision's 0x13 and 0x12 bytes
/*14*/	u8
		cso_0x00,
		cso_0x05, //used to reference function pointer, start location at 800EFB4C.
				  //Basically, on left compare to right, left's value * 0x10 + right's value * 0x04 = pointer look up
		unk_0x16, // curious that two unknowns somehow lie here; likely cso_0x06
		unk_0x17 // and cso_0x07; types also unknown
	;
/*18*/	u32 cso_0x0C;
/*1C*/	u8
		cso_0x10,
		cso_0x11, // damage dealt when touched
		unk_0x1E, // unknown, likely cso_0x12
		unk_0x1F // and cso_0x13; types also unknown
	;
/*20*/	u32 cso_0x14; // (FFCF FFFF)
/*24*/	u8
		cso_0x18,
		cso_0x19,
		unk_0x26, // unknown, likely also "cso" stuff
		unk_0x27, // types also unknown
		unk_0x28,
		unk_0x29,
		unk_0x2A,
		unk_0x2B,
		cso_0x08,
		cso_0x1C,
		cso_0x1D,
		cso_0x1E
	;
/*30*/	u8 unk[12];
/*3C*/  u32 unk_0x3C;
/*40*/	s16
		radius, // or diameter? CSO 0x20
		height, // CSO 0x22
		unk_0x44, // CSO 0x24
		x, // coordinates
		y,
		z
	;
} z64_capsule_t; // length 0x5C bytes

typedef struct z64_dynapoly {
    u8 unk_0[16];
    u32 id;
    u8 unk_1[16];
		u8 collided_flag;
		u8 unk_2[3]; /* for alignment right now */
} z64_dynapoly_t;

typedef struct z64_dynapoly_init {
    u8 unk_0[2];
    u16 scale;
    u32 unk_1;
		u32 unk_2;
		u32 unk_3;
		u32 unk_4;
} z64_dynapoly_init_t;

enum dynapoly_move_flag {
	DPM_PLAYER = 0b01,
 	DPM_ENEMY = 0b10
};

#endif
