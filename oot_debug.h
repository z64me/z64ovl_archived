#ifndef __Z64OVL_OOT_DEBUG_H__
#define __Z64OVL_OOT_DEBUG_H__

#define OOT_DEBUG 1

#include "mips.h"
#include "actor_oot.h"
#include "z64_functions.h"

// RAM Stuff
#define RAM_SEGMENT_TABLE 0x80166FA8
#define GLOBAL_CONTEXT    0x80212020
#define VIEW_CONTEXT      0x802140F8
#define AS_A0             0x80213C44 // spawn_actor argument 0
#define OS_A0             0x802237C4 // spawn_object argument 0
#define LINK              0x802245B0
#define NAVI              0x8022CBE0
#define ZTARGETPOINTER    0x80213CEC

#endif
