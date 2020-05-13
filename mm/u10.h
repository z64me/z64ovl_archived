#ifndef __Z64OVL_MM_U_10_H__
#define __Z64OVL_MM_U_10_H__

#define GAME_MM 1
#define MM_U_1_0 1
#define NZSE 1
#define RETAIL_NUANCES 1

// RAM Stuff
#define Z64GL_SAVE_CONTEXT                  0x801EF670
#define Z64GL_IS_NIGHT                      0x801EF680 // u32, 0 if day, 1 if night
#define Z64GL_CUTSCENE_PLAY_SCRIPT          0x801F35BC /* byte */
#define Z64GL_NES_FONT_WIDTH_TABLE          0x801D0468
#define RAM_SEGMENT_TABLE                   0x801F8180 // 0x80100504 is like rel2abs
#define GLOBAL_CONTEXT                      0x803E6B20
#define AS_A0                               (GLOBAL_CONTEXT + 0x001CA0) // spawn_actor argument 0
#define OS_A0                               (GLOBAL_CONTEXT + 0x017D88) // spawn_object argument 0
#define G_IM_TEX_DIGIT_TIMG                 0x3040 /* Counter Digits */ // TODO: Find this
#define G_IM_TEX_DIGIT_AMMO_TIMG            0x35C0 /* Ammo Digits */ // TODO: Find this
#define G_IM_TEX_CLOCK_TIMG                 0x2000 /* Clock Icon */ // TODO: Find this
#define G_IM_TEX_LETTER                     0x0000 /* Char 0 Space */ // TODO: Find this

#include "../h/mips.h"
#include "types.h"
#include "../z64_functions.h"

#endif
