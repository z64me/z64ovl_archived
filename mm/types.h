#ifndef __Z64OVL_MM_TYPES_H__
#define __Z64OVL_MM_TYPES_H__

#include "../stdint.h"
#include "../h/mips.h"
#include "../h/n64.h"
#include "../h/various_types.h"

// Graphics Context
typedef struct {
    uint32_t    size;   /* 0x00 */
    Gfx         *buf;   /* 0x04 */
    Gfx         *p;     /* 0x08 */
    Gfx         *d;     /* 0x0C */
} z64_disp_buf_t;

typedef struct {
    Gfx             *poly_opa_d_start;      /* 0x0000 */
    Gfx             *poly_xlu_d_start;      /* 0x0004 */
    char            unk_0x08_[0x08];        /* 0x0008 */
    Gfx             *overlay_d_start;       /* 0x0010 */
    char            unk_0x18_[0x24];        /* 0x0014 */
    OSMesg          task_mesg[8];           /* 0x0038 */
    char            unk_0x58_[0x04];        /* 0x0058 */
    OSMesgQueue     task_queue;             /* 0x005C */
    char            pad_0x74_[0x04];        /* 0x0074 */
    OSScTask        task;                   /* 0x0078 */
    char            unk_0xD0_[0xD0];        /* 0x00D0 */
    Gfx             *work_d_start;          /* 0x01A0 */
    z64_disp_buf_t   work;                   /* 0x01A4 */
    char            unk_0x1C4_[0xE4];       /* 0x01B4 */
    z64_disp_buf_t   overlay;                /* 0x0298 */
    z64_disp_buf_t   poly_opa;               /* 0x02A8 */
    z64_disp_buf_t   poly_xlu;               /* 0x02B8 */
    uint32_t        frame_cnt_1;            /* 0x02C8 */
    void            *frame_buffer;          /* 0x02CC */
    char            unk_0x2E0_[0x08];       /* 0x02D0 */
    uint32_t        frame_cnt_2;            /* 0x02D8 */
} z64_gfx_t;

// Global Context
typedef struct {
    z64_gfx_t        *gfx;                   /* 0x0000 */
    void            *gamestate_update;      /* 0x0004 */
    void            *gamestate_dtor;        /* 0x0008 */
    void            *gamestate_ctor;        /* 0x000C */
    uint32_t         ctxt_size;             /* 0x0010 */
    z64_controller_t      input[4];               /* 0x0014 */
    uint32_t        gamestate_heap_size;    /* 0x0074 */
    void            *gamestate_heap_ptr;    /* 0x0078 */
    void            *heap_append_start;     /* 0x007C */
    void            *heap_append_end;       /* 0x0080 */
    void            *gamestate_heap_node;   /* 0x0084 */
    char            unk_0x88_[0x10];        /* 0x0088 */
    int32_t         execute_state;          /* 0x0098 */
    int32_t         gamestate_frames;       /* 0x009C */
    int32_t         unk_0xA0;               /* 0x00A0 */
} z64_game_state_t;

typedef struct
{
  uint32_t          vrom_start;               /* 0x0000 */
  uint32_t          vrom_end;                 /* 0x0004 */
                                              /* 0x0008 */
} z64_vrom_file_t;

typedef struct
{
    /* index of z2_col_type in scene file */
    uint16_t    type;
    /* vertex indices, a and b are bitmasked for some reason */
    struct
    {
        uint16_t  unk_00_ : 3;
        uint16_t  va : 13;
    };
    struct
    {
        uint16_t  unk_01_ : 3;
        uint16_t  vb : 13;
    };
    uint16_t    vc;
    /* normal vector */
    z64_xyz_t    norm;
    /* plane distance from origin */
    int16_t     dist;
} z64_col_poly_t;

#include "actor.h"
