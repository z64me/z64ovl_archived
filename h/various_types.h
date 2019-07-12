#ifndef __VARIOUS_TYPES_H__
#define __VARIOUS_TYPES_H__

#include "mips.h"
#include "n64.h"

typedef enum{
	false,
	true
} bool;

#define COMBINE1(COMBINE1A0, COMBINE1A1) COMBINE1A0##COMBINE1A1
#define COMBINE(COMBINEA0, COMBINEA1) COMBINE1(COMBINEA0, COMBINEA1)
#define PADDING(PADDINGBYTES) COMBINE(char padding,__LINE__)[PADDINGBYTES]
#define ROT16(R16A0) (182.044444 * (R16A0))
#define SGN(SGNA0) (((SGNA0)<0)?-1:((SGNA0)==0)?0:1)
#define MIN(MINA0, MINA1) (((MINA0)<(MINA1))?(MINA0):(MINA1))
#define ABS(ABSA0) (((ABSA0)<0)?(-(ABSA0)):ABSA0)
#define TWEEN_LINEAR(TWL_FROM, TWL_TO, TWL_SPEED) (SGN((TWL_TO)-(TWL_FROM))*MIN(ABS((TWL_TO)-(TWL_FROM)),(TWL_SPEED)))

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

typedef struct
{
	float r, g, b, a;
} rgbaf_t;

typedef int16_t z64_angle_t;
typedef struct
{
  z64_angle_t       x;                        /* 0x0000 */
  z64_angle_t       y;                        /* 0x0002 */
  z64_angle_t       z;                        /* 0x0004 */
                                              /* 0x0006 */
} z64_rot_t;

#endif
