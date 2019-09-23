#ifndef __Z64OVL_OOT_U_10_H__
#define __Z64OVL_OOT_U_10_H__

#define OOT_U_1_0 1
#define RETAIL_NUANCES 1

#include "../h/mips.h"
#include "types.h"
#include "../z64_functions.h"

// RAM Stuff
#define Z64GL_INTERFACE_ON  0x8011B92F
#define SAVE_CONTEXT        0x8011A5D0
#define GLOBAL_IS_NIGHT     0x8011A5E0 // u32, 0 if day, 1 if night
#define STATIC_CONTEXT      0x8011BA00
#define RAM_SEGMENT_TABLE   0x80120C38
#define GLOBAL_CONTEXT      0x801C84A0
#define AS_A0               (GLOBAL_CONTEXT + 0x001C24) // spawn_actor argument 0
#define OS_A0               (GLOBAL_CONTEXT + 0x0117A4) // spawn_object argument 0

#endif
