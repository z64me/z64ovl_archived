#ifndef __VARIOUS_TYPES_H__
#define __VARIOUS_TYPES_H__

#include "mips.h"
#include "n64.h"

typedef enum{
	false,
	true
} bool;

#define DAMAGE_HEARTS(HA0) (int32_t)((HA0) * 16)
#define COMBINE1(COMBINE1A0, COMBINE1A1) COMBINE1A0##COMBINE1A1
#define COMBINE(COMBINEA0, COMBINEA1) COMBINE1(COMBINEA0, COMBINEA1)
#define PADDING(PADDINGBYTES) COMBINE(char padding,__LINE__)[PADDINGBYTES]
#define ROT16(R16A0) (182.044444 * (R16A0))
#define SGN(SGNA0) (((SGNA0)<0)?-1:((SGNA0)==0)?0:1)
#define MIN(MINA0, MINA1) (((MINA0)<(MINA1))?(MINA0):(MINA1))
#define MAX(MAXA0, MAXA1) (((MAXA0)>(MAXA1))?(MAXA0):(MAXA1))
#define ABS(ABSA0) (((ABSA0)<0)?(-(ABSA0)):ABSA0)
#define TWEEN_LINEAR(TWL_FROM, TWL_TO, TWL_SPEED) (SGN((TWL_TO)-(TWL_FROM))*MIN(ABS((TWL_TO)-(TWL_FROM)),(TWL_SPEED)))
#define SEXT24(SEXTA0) (((SEXTA0) & 0x800000) ? ((uint32_t)(SEXTA0) | 0xff000000):(uint32_t)(SEXTA0))
#define FLOOR(FLA0)	((uint32_t)(FLA0))
#define CEIL(CLA0) (CLA0-(uint32_t)(CLA0)>0?(uint32_t)(CLA0+1):(uint32_t)(CLA0))
#define SQRARE(x) ((x) * (x))
#define enum8(x) uint8_t

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
    union {
        struct {
            uint16_t    a   : 1;
            uint16_t    b   : 1;
            uint16_t    z   : 1;
            uint16_t    s   : 1;
            uint16_t    du  : 1;
            uint16_t    dd  : 1;
            uint16_t    dl  : 1;
            uint16_t    dr  : 1;
            uint16_t        : 2;
            uint16_t    l   : 1;
            uint16_t    r   : 1;
            uint16_t    cu  : 1;
            uint16_t    cd  : 1;
            uint16_t    cl  : 1;
            uint16_t    cr  : 1;
        };
        uint16_t        pad;                /* 0x0000 */
    };
    int8_t              x;                  /* 0x0002 */
    int8_t              y;                  /* 0x0003 */
} z64_controller_t;                         /* 0x0004 */

/* Legacy Macros */
/* Get a value of arbitrary type from any address in the actor */
#define AVAL(base,type,offset)  (*(type*)((uint8_t*)(base)+(offset)))

/* Get the address */
#define AADDR(a,o)  ((void*)((uint8_t*)(a)+(o)))

/* rgb888 color */
typedef struct
{
  uint8_t r;
  uint8_t g;
  uint8_t b;
} rgb8_t;

/* rgba8888 color */
typedef struct
{
  uint8_t r;
  uint8_t g;
  uint8_t b;
  uint8_t a;
} rgba8_t;

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
	int16_t x;
	int16_t y;
} vec2s_t;

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

typedef struct PosRot
{
	vec3f_t pos;
	z64_rot_t rot;
} PosRot_t;

float fminf(float a, float b)
{
	return a < b ? a : b;
}

float fmaxf(float a, float b)
{
	return a > b ? a : b;
}

float zh_pow(float in, int32_t power)
{
  float out = in;

  for (int i = 1; i < power; i++)
    out *= in;
  
  return out;
}

#define min_f(a, b, c) (fminf(a, fminf(b, c)))
#define max_f(a, b, c)  (fmaxf(a, fmaxf(b, c)))

#endif
