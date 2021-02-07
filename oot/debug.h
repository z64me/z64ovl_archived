#ifndef __Z64OVL_OOT_DEBUG_H__
#define __Z64OVL_OOT_DEBUG_H__

#define OOT_DEBUG 1
#define NZLE 1

#include "../h/mips.h"
#include "types.h"


// RAM Stuff
#define Z64GL_SAVE_CONTEXT          0x8015E660
#define Z64GL_NES_FONT_WIDTH_TABLE  0x80153A00
/*
float font_width[145] = {
  00.0f, 08.0f, 08.0f, 06.0f, 09.0f, 09.0f, 14.0f, 02.0f, 03.0f, 07.0f
, 07.0f, 07.0f, 09.0f, 04.0f, 06.0f, 04.0f, 09.0f, 10.0f, 05.0f, 09.0f 
, 09.0f, 10.0f, 09.0f, 09.0f, 09.0f, 09.0f, 09.0f, 06.0f, 06.0f, 09.0f 
, 11.0f, 09.0f, 11.0f, 13.0f, 12.0f, 09.0f, 11.0f, 11.0f, 08.0f, 08.0f 
, 12.0f, 10.0f, 04.0f, 08.0f, 10.0f, 08.0f, 13.0f, 11.0f, 13.0f, 09.0f 
, 13.0f, 10.0f, 10.0f, 09.0f, 10.0f, 11.0f, 15.0f, 11.0f, 10.0f, 10.0f 
, 07.0f, 10.0f, 07.0f, 10.0f, 09.0f, 05.0f, 08.0f, 09.0f, 08.0f, 09.0f
, 09.0f, 06.0f, 09.0f, 08.0f, 04.0f, 06.0f, 08.0f, 04.0f, 12.0f, 09.0f
, 09.0f, 09.0f, 09.0f, 07.0f, 08.0f, 07.0f, 08.0f, 09.0f, 12.0f, 08.0f
, 09.0f, 08.0f, 07.0f, 05.0f, 07.0f, 10.0f, 10.0f, 12.0f, 06.0f, 12.0f
, 12.0f, 11.0f, 08.0f, 08.0f, 08.0f, 06.0f, 06.0f, 13.0f, 13.0f, 10.0f
, 10.0f, 10.0f, 09.0f, 08.0f, 08.0f, 08.0f, 08.0f, 08.0f, 09.0f, 09.0f
, 09.0f, 09.0f, 06.0f, 09.0f, 09.0f, 09.0f, 09.0f, 09.0f, 14.0f, 14.0f
, 14.0f, 14.0f, 14.0f, 14.0f, 14.0f, 14.0f, 14.0f, 14.0f, 14.0f, 14.0f
, 14.0f, 14.0f, 14.0f, 14.0f, 14.0f
};
*/
#define STATIC_CONTEXT              0x8015FA90
#define RAM_SEGMENT_TABLE           0x80166FA8
#define GLOBAL_CONTEXT              0x80212020
#define AS_A0                       (GLOBAL_CONTEXT + 0x001C24) // spawn_actor argument 0
#define OS_A0                       (GLOBAL_CONTEXT + 0x0117A4) // spawn_object argument 0
#define LINK                        0x802245B0
#define NAVI                        0x8022CBE0
#define G_IM_TEX_DIGIT_TIMG         0x3040 /* Counter Digits */
#define G_IM_TEX_DIGIT_AMMO_TIMG    0x35C0 /* Ammo Digits */
#define G_IM_TEX_CLOCK_TIMG         0x2000 /* Clock Icon */
#define G_IM_TEX_LETTER             0x0000 /* Char 0 Space */
#define Z64GL_VROM_ICON_ITEM_STATIC 0x0074C000
#define Z64GL_CODE                  0x8001CE60 /* where code lives in ram */
#define Z64GL_CODE_PAUSEPLAYER      0x110340 /* relative to start of code */

#include "shared.h"
#include "../z64_functions.h"

#endif
