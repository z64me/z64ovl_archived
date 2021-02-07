#ifndef __Z64OVL_OOT_U_10_H__
#define __Z64OVL_OOT_U_10_H__

#define OOT_U_1_0 1
#define CZLE 1
#define RETAIL_NUANCES 1

#include "../h/mips.h"
#include "types.h"


// RAM Stuff
#define Z64GL_SAVE_CONTEXT          0x8011A5D0
#define Z64GL_NES_FONT_WIDTH_TABLE  0x80112F40
#define STATIC_CONTEXT              0x8011BA00
#define RAM_SEGMENT_TABLE           0x80120C38
#define GLOBAL_CONTEXT              0x801C84A0
#define LINK                        0x801DAA30
#define AS_A0                       (GLOBAL_CONTEXT + 0x001C24) // spawn_actor argument 0
#define OS_A0                       (GLOBAL_CONTEXT + 0x0117A4) // spawn_object argument 0
#define G_IM_TEX_DIGIT_TIMG         0x3040 /* Counter Digits */
#define G_IM_TEX_DIGIT_AMMO_TIMG    0x35C0 /* Ammo Digits */
#define G_IM_TEX_CLOCK_TIMG         0x2000 /* Clock Icon */
#define G_IM_TEX_LETTER             0x0000 /* Char 0 Space */
#define Z64GL_VROM_ICON_ITEM_STATIC 0x007BD000
#define Z64GL_CODE                  0x800110A0 /* where code lives in ram */
#define Z64GL_CODE_PAUSEPLAYER      0xED3E0 /* relative to start of code */

#include "shared.h"
#include "../z64_functions.h"

#endif
