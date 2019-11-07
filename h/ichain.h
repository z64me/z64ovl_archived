/****
 * ichain.h
 * contains everything needed to generate
 * compact actor instance initialization chains
 * for use in custom OoT/MM overlays
 ***/

#include <stdint.h> /* integer types */
#include <stddef.h> /* offsetof */

/* TODO u/s may need to be swapped */
/* TODO float/vec operations, do those support signedness? */
/* TODO are s8/s16/s32 values all represented as s16? */
/* TODO `type` is 7 bits but spans 0 - A inclusive */
enum ichain_types
{
	ICHAIN_U8 = 0            /* sets byte  */
	, ICHAIN_S8
	, ICHAIN_U16             /* sets short */
	, ICHAIN_S16
	, ICHAIN_U32             /* sets word  */
	, ICHAIN_S32
	, ICHAIN_F               /* sets float to int                  */
	, ICHAIN_Fdiv1000        /* sets float to int, divides by 1000 */
	, ICHAIN_VEC3F           /* sets vec3f members to int          */
	, ICHAIN_VEC3Fdiv1000    /* sets vec3f members to int / 1000   */
	, ICHAIN_VEC3S16         /* sets vec3s members to int          */
};

/****
 * ICHAIN_EX macro is for using a user-specified structure, such
 * as an `entity_t`; identical to ICHAIN otherwise, which assumes
 * a `z64_actor_t` structure, so look there for the actual notes
 ***/
#define ICHAIN_EX(is_last, type, member, value, structure)  \
	(uint32_t) (                                             \
		(((!is_last) & 1) << 31)    |                         \
		((type      & 15) << 27)    |                         \
		((offsetof(structure, member) & 0x7FF) << 16) |       \
		(value & 0xFFFF)                                      \
	)

/****
 * ICHAIN macro generates a uint32_t of the following form:
 * * (v >> 31) & 0x0001 == Continue Parsing
 * * (v >> 27) & 0x000F == Type
 * * (v >> 16) & 0x07FF == Offset from start of instance to write initial value
 * *  v        & 0xFFFF == Value
 * arguments:
 * * is_last -- use 1 if it's the last in the list; 0 otherwise
 * * type ----- see `enum ichain_types`
 * * member --- name of member inside `z64_actor_t` structure
 * * value ---- use only int values that can be represented in 16 bits
 ***/
#define ICHAIN(is_last, type, member, value)                \
	ICHAIN_EX(is_last, type, member, value, z64_actor_t)

