#ifndef __ZELDA64_ACTOR_OOT_H__
#define __ZELDA64_ACTOR_OOT_H__

#include <stdint.h>
#include "oot_types.h"
#include <mips.h>

typedef enum {
  Switch = 0x00,
  Prop_1 = 0x01,
  Player = 0x02,
  Explosives = 0x03,
  NPC = 0x04,
  Enemy = 0x05,
  Prop = 0x06,
  Item_Action = 0x07,
  Misc = 0x08,
  Boss = 0x09,
  Door = 0x0A,
  Chest = 0x0B
} z64_actor_type_t;

typedef struct z64_actor_init_s{
  int16_t number; /* Actor Number */
  uint8_t type; /* Actor Type */
  uint8_t room; /* Room that the instance was spawned in*/
  int flags; /* Not completely documented */
  int16_t object; /* Object Number */
  int16_t padding;
  int instance_size; /* Size of the actor instance */
  void *init; /* Constructor */
  void *dest; /* Destructor */
  void *main; /* Main Update Function */
  void *draw; /* Draw Function */
} z64_actor_init_t;

/* Legacy Macros */
/* Get a value of arbitrary type from any address in the actor */
#define AVAL(base,type,offset)  (*(type*)((u8*)(base)+(offset)))

/* Get the address */
#define AADDR(a,o)  ((void*)((u8*)(a)+(o)))


/* ----------------------------------------------
   Data types & structures
   ---------------------------------------------- */

/* A function handler for an actor */
typedef void (*ZAFunc)( void *, void * );

/* A float triad (X/Y/Z) accessible also as u32 */
union z64_xyz_t
{
    /* Floating point */
    struct { f32 x,  y,  z;  };

    /* Unsigned 32-bit */
    struct { u32 rx, ry, rz; };
};

/* Rotation triad */
struct z64_rot_t
{
    s16 x;
    s16 y;
    s16 z;
};

/* Actor structure */
typedef struct z64_actor_s
{
    u16                     number;
    u8                      type;
    u8                      status;
    u8                      __pad0000[4];
    union z64_xyz_t         coords_1;
    struct z64_rot_t        rotation_1;
    u8                      __pad0001[2];
    u16                     variable;
    u8                      __pad0002[6];
    union z64_xyz_t         coords_2;
    struct z64_rot_t        rotation_2;
    u8                      __pad0003[2];
    union z64_xyz_t         coords_3;
    struct z64_rot_t        rotation_3;
    u8                      __pad0004[6];
    union z64_xyz_t         scale;
    union z64_xyz_t         acceleration;
    u8                      __pad0005[184];
    struct z64_actor_s *    previous;
    struct z64_actor_s *    next;
    ZAFunc                  f_init;
    ZAFunc                  f_routine1;
    ZAFunc                  f_routine2;
    ZAFunc                  f_routine3;
    ZAFunc                  f_code_entry;
    u8                      __pad0006[84];
    ZAFunc                  f_next;
} z64_actor_t;


#endif /* __ZELDA64_ACTOR_H__ */
