#ifndef __Z64OVL_H__
#define __Z64OVL_H__

#include "h/ichain.h"
#include "common.h"
#include "oldnames.h"
#include "real.h"

/****
 * z64ovl.h
 * Either `#define OOT_DEBUG 1` or `#define OOT_U_1_0 1` before `#include`ing.
 * Please leave your camel parked outside.
 ***/

/****
 * Due to differences in the actor instance structure between OoT and MM,
 * wrapper functions exist to keep your custom overlays compatible with
 * both games.
 * Code written using these wrapper functions produces the same number
 * of opcodes as code that does not. The abstraction that they provide
 * also keeps code more readable.
 * Search this document for actor_init_shadow to see an example.
 ***/

/****
 * M A C R O S
 ***/

/* compile-time assertion; example usage:

	typedef struct entity {
		float a;
		float b;
		float c;
	} entity_t;

	Z64OVL_STATIC_ASSERT(offsetof(entity_t, a) == 0);
	Z64OVL_STATIC_ASSERT(offsetof(entity_t, b) == 4);
	Z64OVL_STATIC_ASSERT(offsetof(entity_t, c) == 8);
*/
#define Z64OVL_STATIC_ASSERT(e)          \
   extern                                \
   char                                  \
   (*__z64ovl_static_assertion__(void))  \
   [sizeof(char[1 - 2*!(e)])]

#define VEC3_ADD( V3A0, V3A1 ) \
{                              \
	V3A0.x += V3A1.x;          \
	V3A0.y += V3A1.y;          \
	V3A0.z += V3A1.z;          \
}

#define VEC3_SUB( V3DST, V3A0, V3A1 ) \
{                                     \
    V3DST.x = V3A0.x - V3A1.x;        \
    V3DST.y = V3A0.y - V3A1.y;        \
    V3DST.z = V3A0.z - V3A1.z;        \
}

#define SQRT(ARG0) z_sqrt((ARG0))

#define DmaMgr_ProcessMsg z_file_load
/* DmaRequest Type */
extern void z_file_load(void *req);
#if OOT_DEBUG
	asm("z_file_load = 0x800013FC");
#elif OOT_U_1_0
	asm("z_file_load = 0x80000B0C");
#elif MM_U_1_0
	asm("z_file_load = 0x80080A08");
#endif


/****
 * Copy data from the ROM into VRAM, using Direct Memory Access (DMA)
 ***/
#define DmaMgr_SendRequest1 load_data_from_rom
extern uint32_t load_data_from_rom(
	void* vram_addr
	, void* vrom_addr
	, uint32_t size
#ifndef RETAIL_NUANCES /* debug roms require these arguments, retail roms don't */
	, const char *string
	, int32_t line
#endif
);
#ifdef RETAIL_NUANCES
#define load_data_from_rom(VRAM, VROM, SIZE, STR) load_data_from_rom(VRAM, VROM, SIZE)
#else
#define load_data_from_rom(VRAM, VROM, SIZE, STR) load_data_from_rom(VRAM, VROM, SIZE, STR, __LINE__)
#endif
    #if OOT_DEBUG
        asm("load_data_from_rom = 0x80001AA0");
	#elif OOT_U_1_0
		asm("load_data_from_rom = 0x80000DF0");
	#elif MM_U_1_0
		asm("load_data_from_rom = 0x80080C90");
    #endif

#define sprintf z_sprintf
extern int32_t z_sprintf(volatile char* dst, const char* fmt, ...);
	#if OOT_DEBUG
		asm("z_sprintf = 0x80002F44");
	#elif OOT_U_1_0
		asm("z_sprintf = 0x800CE7B4");
	#elif MM_U_1_0
		asm("z_sprintf = 0x800878A4");
	#endif

/****
 * Send OS Message. This function is not used inside any existing overlay.
 * A0 = 0x80013990 for file reads on Debug, A1 = destination buffer, A2 = OS_MESG_NOBLOCK = 0 / OS_MESG_BLOCK = 1
 ***/
extern void osSendMesg(OSMesgQueue* queue, void* dest, int32_t flag);
	#if OOT_DEBUG
		asm("osSendMesg = 0x80003060");
	#elif OOT_U_1_0
		asm("osSendMesg = 0x80001E20");
	#endif

/****
 * zero `num` bytes starting at `dst`
 * This function is not used inside any existing overlay
 ***/
#define bzero z_bzero
extern void z_bzero(void *dst, const int num);
	#if OOT_DEBUG
		asm("z_bzero = 0x80004450");
	#elif OOT_U_1_0
		asm("z_bzero = 0x80002E80");
	#elif MM_U_1_0
		// TODO
	#endif

extern int _Printf(
	void *pfn(void *, const char *, size_t), void *arg, const char *fmt, ...);
	#if OOT_DEBUG
		asm("_Printf = 0x800052E0");
	#elif OOT_U_1_0
		asm("_Printf = 0x800D1D00");
	#endif

extern int _Putfld(
	/* _Pft*/void *px, /* va_list*/void *pap, char code, char *ac);
	#if OOT_DEBUG
		asm("_Putfld = 0x80005928");
	#elif OOT_U_1_0
		asm("_Putfld = 0x800D1690");
	#endif

#define strchr z_strchr
// TODO Find 1.0 Equivalent
extern const uint8_t* z_strchr(const char* str, int32_t ch);
	#if OOT_DEBUG
		asm("z_strchr = 0x800060B0");
	#elif OOT_U_1_0
		//asm("z_strchr = 0x800D1690");
	#endif

#define strlen z_strlen
// TODO Find 1.0 Equivalent
extern size_t z_strlen(const char* str);
	#if OOT_DEBUG
		asm("z_strlen = 0x800060F0");
	#elif OOT_U_1_0
		//asm("z_strlen = 0x800D1690");
	#endif

/****
 * Create a queue. This function is not used inside any existing overlay.
 ***/
extern void osCreateMesgQueue(OSMesgQueue* queue, OSMesg* mesg, int32_t flag);
	#if OOT_DEBUG
		asm("osCreateMesgQueue = 0x800061D0");
	#elif OOT_U_1_0
		asm("osCreateMesgQueue = 0x80004220");
	#endif

/****
 * Receive message from a queue. This function is not used inside any existing overlay.
 ***/
extern void osRecvMesg(OSMesgQueue* queue, OSMesg* mesq, int32_t flag);
	#if OOT_DEBUG
		asm("osRecvMesg = 0x800062E0");
	#elif OOT_U_1_0
		asm("osRecvMesg = 0x80002030");
	#endif

/****
 * compare byte sequences `s1` and `s2` of length `n`
 * if they are equal, or `n == 0`, z_bcmp returns 0; non-zero otherwise
 ***/
#define bcmp z_bcmp
extern int z_bcmp(const void *s1, const void *s2, int n);
	#if OOT_DEBUG
		asm("z_bcmp = 0x800068C0");
	#elif OOT_U_1_0
		asm("z_bcmp = 0x800D4390");
	#elif MM_U_1_0
		// TODO
	#endif

/****
 * copy `num` bytes from `src` to `dst`
 * This function is not used inside any existing overlay
 * formerly memory_copy
 ***/
#define bcopy z_bcopy
extern void z_bcopy(const void *src, void *dst, const uint32_t num);
	#if OOT_DEBUG
		asm("z_bcopy = 0x80006F10");
	#elif OOT_U_1_0
		asm("z_bcopy = 0x80004DC0");
	#elif MM_U_1_0
		asm("z_bcopy = 0x800912C0");
	#endif

/*
 * z_assert(condition)
 *    writes info to the console if a condition is not true;
 *    you use this for conditions that should always be true
 *
 * NOTE
 *    all assertions are ignored and stripped from the
 *    binary when the compilation flag -DNDEBUG is used
 *
 * USAGE
 *    if (z_assert(x != 0)) {
 *       // this block is executed when x == 0
 *    }
 *
 *    or simply:
 *       z_assert(x != 0);
 */
#undef z_assert
#ifdef NDEBUG
   #define z_assert(CONDITION) ((void*)0)
#else
   #define z_assert(CONDITION)                                   \
      (                                                          \
         (CONDITION)                                             \
         ? 0                                                     \
         : (z_assert_message(#CONDITION, __FILE__, __LINE__), 1) \
      )
#endif

/**
 * called on assertion failure
 * [!] don't use this directly; use z_assert instead
 */
#define __assert z_assert_message
#define z_assert_message(x) (z_assert_message)(x, __FILE__, __LINE__)
extern void (z_assert_message)(char *mesg, char *fn, int line);
	#if OOT_DEBUG
		asm("z_assert_message = 0x80001FF0");
	#elif OOT_U_1_0
		asm("z_assert_message = 0x800A01B8");
	#endif

/**
 * print a debug message to the console
 * use DEBUG_LOG(), which will disable z_console_log() calls unless compiling with DEBUG defined
 */
#define osSyncPrintf z_console_log
extern void z_console_log(const char *msg, ...);
#ifdef DEBUG
	#define DEBUG_LOG z_console_log
#else
	#define DEBUG_LOG
#endif
	#if OOT_DEBUG
		asm("z_console_log = 0x80002130");
	#elif OOT_U_1_0
		asm("z_console_log = 0x800ADBF8"); /* 15BC */
	#endif

/**
 * This prints a debug string that doesn't exist in 1.0
 * Perhaps this function doesn't, either.
 */
#define LogUtils_LogThreadId z_thread_log_id
#define z_thread_log_id(x) (z_thread_log_id)(__FILE__, __LINE__)
extern void (z_thread_log_id)(const char* name, int32_t line);
	#if OOT_DEBUG
		asm("z_thread_log_id = 0x80002E10");
	#elif OOT_U_1_0
		#define external_func_80002E10(...) do { /* nothing */ } while (0)
	#endif

/**
 * Returns where a thread is hung up.
 */
#define LogUtils_HungupThread z_thread_hungup
#define z_thread_hungup(x) (z_thread_hungup)(__FILE__, __LINE__)
extern void (z_thread_hungup)(const char* name, int32_t line);
	#if OOT_DEBUG
		asm("z_thread_hungup = 0x80002E50");
	#elif OOT_U_1_0
		asm("z_thread_hungup = 0x80001B38");
	#endif

/* Spawn Collectible Item
* Source Code Reference File: "z_en_item00.c"
* Formerly `item_drop_collectible`
*/
#define Item_DropCollectible z_item_drop
extern void z_item_drop(
z64_global_t* gl /* Global Context */
, vec3f_t* position /* X, Y, and Z Position */
, uint16_t id /* Drop Table Item ID */
);
#if OOT_DEBUG
  asm("z_item_drop = 0x8001F548");
#elif OOT_U_1_0
  asm("z_item_drop = 0x80013678");
#elif MM_U_1_0
  /*asm("z_item_drop = 0xDEADBEEF");*/
#endif

/* Alternate Spawn Collectible Item
* Source Code Reference File: "z_en_item00.c"
*/
#define Item_DropCollectible2 z_item_drop_2
extern void z_item_drop_2(
z64_global_t* gl /* Global Context */
, vec3f_t* position /* X, Y, and Z Position */
, uint16_t id /* Drop Table Item ID */
);
#if OOT_DEBUG
	asm("z_item_drop_2 = 0x8001F77C");
#elif OOT_U_1_0
	asm("z_item_drop_2 = 0x800138B0");
#endif

/* Spawn Random Collectible Item
* Source Code Reference File: "z_en_item00.c"
*/
#define Item_DropCollectibleRandom z_item_drop_random
extern void z_item_drop_random(
z64_global_t* gl /* Global Context */
, z64_actor_t* a /* Actor Instance */
, vec3f_t* position /* X, Y, and Z Position */
, uint32_t id /* Drop Table Item ID */
);
#if OOT_DEBUG
  asm("z_item_drop_random = 0x8001F940");
#elif OOT_U_1_0
  asm("z_item_drop_random = 0x80013A84");
#elif MM_U_1_0
  asm("z_item_drop_random = 0x800A7D28");
#endif

/**
 * Used for drawing z_eff_blure
 */
#define EffectBlure_AddVertex z_eff_blure_vertex_add
extern void z_eff_blure_vertex_add(z64_eff_blure_t* blureInstance, vec3f_t* p1, vec3f_t* p2);
	#if OOT_DEBUG
		asm("z_eff_blure_vertex_add = 0x8001FDF0");
	#elif OOT_U_1_0
		asm("z_eff_blure_vertex_add = 0x80013F30");
	#endif

/**
 * Used for drawing z_eff_blure
 */
#define EffectBlure_AddSpace z_eff_blure_space_add
extern void z_eff_blure_space_add(z64_eff_blure_t* blureInstance);
	#if OOT_DEBUG
		asm("z_eff_blure_space_add = 0x80020120");
	#elif OOT_U_1_0
		asm("z_eff_blure_space_add = 0x80014254");
	#endif

/**
 * z_eff_ss_dead
 */
#define func_80026230 external_func_80026230
extern void external_func_80026230(z64_global_t* gl, rgba8_t* color, int16_t a2, int16_t a3);
	#if OOT_DEBUG
		asm("external_func_80026230 = 0x80026230");
	#elif OOT_U_1_0
		asm("external_func_80026230 = 0x8001A0E0");
	#endif

/**
 * z_eff_ss_dead
 */
#define func_80026608 external_func_80026608
extern void external_func_80026608(z64_global_t* gl);
	#if OOT_DEBUG
		asm("external_func_80026608 = 0x80026608");
	#elif OOT_U_1_0
		asm("external_func_80026608 = 0x8001A468");
	#endif

/**
 * z_eff_ss_dead
 */
#define func_80026690 external_func_80026690
extern void external_func_80026690(z64_global_t* gl, rgba8_t* color, int16_t a2, int16_t a3);
	#if OOT_DEBUG
		asm("external_func_80026690 = 0x80026690");
	#elif OOT_U_1_0
		asm("external_func_80026690 = 0x8001A4AC");
	#endif

/**
 * z_eff_ss_dead
 */
#define func_80026860 external_func_80026860
extern void external_func_80026860(z64_global_t* gl, rgba8_t* color, int16_t a2, int16_t a3);
	#if OOT_DEBUG
		asm("external_func_80026860 = 0x80026860");
	#elif OOT_U_1_0
		asm("external_func_80026860 = 0x8001A654");
	#endif

/**
 * z_eff_ss_dead
 */
#define func_80026A6C external_func_80026A6C
extern void external_func_80026A6C(z64_global_t* gl);
	#if OOT_DEBUG
		asm("external_func_80026A6C = 0x80026A6C");
	#elif OOT_U_1_0
		asm("external_func_80026A6C = 0x8001A83C");
	#endif

/**
 * Return pointer to an effect via index.
 */
#define Effect_GetByIndex z_eff_index_get
extern void* z_eff_index_get(uint32_t idx);
	#if OOT_DEBUG
		asm("z_eff_index_get = 0x80026B0C");
	#elif OOT_U_1_0
		asm("z_eff_index_get = 0x8001A890");
	#endif

/**
 * Add an effect.
 */
#define Effect_Add z_effect_add
extern void z_effect_add(z64_global_t* gl, int32_t* idx, int32_t type, uint8_t arg3, uint8_t arg4, void* initParams);
	#if OOT_DEBUG
		asm("z_effect_add = 0x80026CD4");
	#elif OOT_U_1_0
		asm("z_effect_add = 0x8001AA5C");
	#endif

/**
 * Delete an effect.
 */
#define Effect_Delete z_effect_remove
extern void z_effect_remove(z64_global_t *gl, uint32_t index);
	#if OOT_DEBUG
		asm("z_effect_remove = 0x8002709C");
	#elif OOT_U_1_0
		asm("z_effect_remove = 0x8001AE04");
	#endif

/**
 * Kill Particle
 * A0 = Particle Instance Ptr
 * Delete an effect (Soft Sprite)
 */
#define EffectSs_Delete z_particle_kill
extern void z_particle_kill(void* particle_instance);
	#if OOT_DEBUG
		asm("z_particle_kill = 0x800274E0");
	#elif OOT_U_1_0
		asm("z_particle_kill = 0x8001B1A4");
	#endif

/**
 * Keyword: Particle
 * Insert an effect. (Soft Sprite)
 * This function is not used inside any existing overlay
 */
#define EffectSs_Insert z_particle_insert
extern void z_particle_insert(z64_global_t* gl, void* particle_instance);
	#if OOT_DEBUG
		asm("z_particle_insert = 0x80027704");
	#elif OOT_U_1_0
		asm("z_particle_insert = 0x8001B3D0");
	#endif

/**
 * if (a2) return (a0 + (a1 - a0) / a2)
 * This function is not used inside any existing overlay
 */
#define func_80027DD4 external_func_80027DD4
extern void external_func_80027DD4(int16_t a0, int16_t a1, int32_t a2);
	#if OOT_DEBUG
		asm("external_func_80027DD4 = 0x80027DD4");
	#elif OOT_U_1_0
		asm("external_func_80027DD4 = 0x8001B8FC");
	#endif

/**
 * Draw Splash? (Particle 0x0A)
 * TODO These notes need converted into a C function prototype
 * This function is not used inside any existing overlay
 */
extern void external_func_80027F80(void);
	#if OOT_DEBUG
		asm("external_func_80027F80 = 0x80027F80");
	#elif OOT_U_1_0
		asm("external_func_80027F80 = 0x8001BAA0");
	#endif

/**
 * Spawn Particle 0x00 Type 0 (Wrapper for 8001BCE0)
 * TODO These notes need converted into a C function prototype
 */
extern void z_effect_spawn_dust_a(z64_global_t* gl, vec3f_t* pos, vec3f_t* u0, vec3f_t* u1, uint32_t* u2, uint32_t* u3, int16_t u4, int16_t u5);
	#if OOT_DEBUG
		asm("z_effect_spawn_dust_a = 0x8002829C");
	#elif OOT_U_1_0
		asm("z_effect_spawn_dust_a = 0x8001BD94");
	#endif

/**
 * Spawn Particle 0x00 Type 0 (Wrapper for 8001BCE0)
 * TODO These notes need converted into a C function prototype
 */
extern void external_func_8002836C(void);
	#if OOT_DEBUG
		asm("external_func_8002836C = 0x8002836C");
	#elif OOT_U_1_0
		asm("external_func_8002836C = 0x8001BE64");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800283D4(void);
	#if OOT_DEBUG
		asm("external_func_800283D4 = 0x800283D4");
	#elif OOT_U_1_0
		asm("external_func_800283D4 = 0x8001BECC");
	#endif

/**
 * Spawn Particle 0x00 Type 2 (Wrapper for 8001BCE0)
 * TODO These notes need converted into a C function prototype
 */
extern void external_func_8002843C(void);
	#if OOT_DEBUG
		asm("external_func_8002843C = 0x8002843C");
	#elif OOT_U_1_0
		asm("external_func_8002843C = 0x8001BF34");
	#endif

/**
 * Spawn Particle 0x00 Type 4 (Wrapper for 8001BCE0)
 * TODO These notes need converted into a C function prototype
 */
extern void external_func_8002865C(void);
	#if OOT_DEBUG
		asm("external_func_8002865C = 0x8002865C");
	#elif OOT_U_1_0
		asm("external_func_8002865C = 0x8001C154");
	#endif

/* Spawn ovl_Effect_Ss_Dust (Dust)
* Type 5
* Source Code Reference File: "z_effect_soft_sprite_old_init.c"
*/
extern void z_effect_spawn_dust_5(
z64_global_t* gl /* Global Context */
, vec3f_t* position /* X, Y, and Z Position */
, vec3f_t* velocity /* Velocity along the X, Y, and Z axes */
, vec3f_t* acceleration /* Acceleration along the X, Y, and Z axes */
, int16_t sp10
, int16_t sp14
);
#if OOT_DEBUG
  asm("z_effect_spawn_dust_5 = 0x800286CC");
#elif OOT_U_1_0
  asm("z_effect_spawn_dust_5 = 0x8001C1C4");
#elif MM_U_1_0
  /*asm("z_effect_spawn_dust_5 = 0xDEADBEEF");*/
#endif

/**
 * Spawn Particle 0x00 Type 4 (Wrapper for 8001BCE0)
 * TODO These notes need converted into a C function prototype
 */
extern void external_func_8002873C(void);
	#if OOT_DEBUG
		asm("external_func_8002873C = 0x8002873C");
	#elif OOT_U_1_0
		asm("external_func_8002873C = 0x8001C234");
	#endif

/**
 * Spawn Particle 0x00 Type 5 (Wrapper for 8001BCE0)
 * TODO These notes need converted into a C function prototype
 */
extern void external_func_800287AC(void);
	#if OOT_DEBUG
		asm("external_func_800287AC = 0x800287AC");
	#elif OOT_U_1_0
		asm("external_func_800287AC = 0x8001C2A4");
	#endif

/**
 * Spawn 20 Particle 0x00 (Calls 8001C234)
 * TODO These notes need converted into a C function prototype
 */
extern void external_func_80028990(void);
	#if OOT_DEBUG
		asm("external_func_80028990 = 0x80028990");
	#elif OOT_U_1_0
		asm("external_func_80028990 = 0x8001C488");
	#endif

/**
 * Spawn 20 Particle 0x00 (Calls 8001C2A4)
 * TODO These notes need converted into a C function prototype
 */
extern void external_func_80028A54(void);
	#if OOT_DEBUG
		asm("external_func_80028A54 = 0x80028A54");
	#elif OOT_U_1_0
		asm("external_func_80028A54 = 0x8001C54C");
	#endif

/**
 * Spawn Particle 0x01 (Wrapper for 8001C6A8)
 * TODO These notes need converted into a C function prototype
 */
extern void external_func_80028B18(void);
	#if OOT_DEBUG
		asm("external_func_80028B18 = 0x80028B18");
	#elif OOT_U_1_0
		asm("external_func_80028B18 = 0x8001C610");
	#endif

/**
 * Spawn ovl_Effect_Ss_KiraKira (Sparkle Motes - Spawned by Navi)
 */
#define func_80028B74 z_effect_spawn_sparkle
extern void z_effect_spawn_sparkle(z64_global_t* gl, vec3f_t* a1, void* a2, void* a3, rgba8_t a, rgba8_t b);
	#if OOT_DEBUG
		asm("z_effect_spawn_sparkle = 0x80028B74");
	#elif OOT_U_1_0
		asm("z_effect_spawn_sparkle = 0x8001C66C");
	#endif

/**
 * Spawn Particle 0x01 (Fairy Sparkle)
 * TODO These notes need converted into a C function prototype
 */
extern void external_func_80028BB0(void);
	#if OOT_DEBUG
		asm("external_func_80028BB0 = 0x80028BB0");
	#elif OOT_U_1_0
		asm("external_func_80028BB0 = 0x8001C6A8");
	#endif

/**
 * Spawn Particle 0x01 (?, First Visit ToT as Adult)
 * TODO These notes need converted into a C function prototype
 */
extern void external_func_80028CEC(void);
	#if OOT_DEBUG
		asm("external_func_80028CEC = 0x80028CEC");
	#elif OOT_U_1_0
		asm("external_func_80028CEC = 0x8001C7E4");
	#endif

/* Spawn ovl_Effect_Ss_Bomb2 (Bomb Explosion)
* Source Code Reference File: "z_effect_soft_sprite_old_init.c"
*/
extern void z_effect_spawn_bomb2(
z64_global_t* gl /* Global Context */
, vec3f_t* position /* X, Y, and Z Position */
, vec3f_t* burst_gravity /* Gravity along the X, Y, and Z axes */
, vec3f_t* burst_velocity /* Velocity along the X, Y, and Z axes */
, uint16_t scale /* Explosion Scale */
, int16_t growth_velocty /* How fast the explosion cloud increases its size */
);
#if OOT_DEBUG
  asm("z_effect_spawn_bomb2 = 0x80028E84");
#elif OOT_U_1_0
  asm("z_effect_spawn_bomb2 = 0x8001C97C");
#elif MM_U_1_0
  /*asm("z_effect_spawn_bomb2 = 0xDEADBEEF");*/
#endif

/**
 * Spawn Particle 0x04 (Wrapper for 8001C9EC)
 * TODO These notes need converted into a C function prototype
 */
extern void external_func_80028F84(void);
	#if OOT_DEBUG
		asm("external_func_80028F84 = 0x80028F84");
	#elif OOT_U_1_0
		asm("external_func_80028F84 = 0x8001CA7C");
	#endif

/**
 * Spawn Particle 0x04 (Wrapper for 8001CAD0)
 * TODO These notes need converted into a C function prototype
 */
extern void z_effect_spawn_blast_ring(z64_global_t* gl, vec3f_t* position, vec3f_t* grav, vec3f_t* u0);
	#if OOT_DEBUG
		asm("z_effect_spawn_blast_ring = 0x80029024");
	#elif OOT_U_1_0
		asm("z_effect_spawn_blast_ring = 0x8001CB1C");
	#endif

/**
 * Spawn Particle 0x05 (Wrapper for 8001CDD4)
 * TODO These notes need converted into a C function prototype
 * Bomb Spark
 */
extern void z_effect_spawn_spark(z64_global_t* gl, z64_actor_t* a, vec3f_t* pos, vec3f_t* grav, vec3f_t* u0);
	#if OOT_DEBUG
		asm("z_effect_spawn_spark = 0x80029184");
	#elif OOT_U_1_0
		asm("z_effect_spawn_spark = 0x8001CC7C");
	#endif

/**
 * Spawn Particle 0x06 (Wrapper for 8001CE18)
 * TODO These notes need converted into a C function prototype
 */
extern void z_effect_spawn_fire_breath(void);
	#if OOT_DEBUG
		asm("z_effect_spawn_fire_breath = 0x800293A0");
	#elif OOT_U_1_0
		asm("z_effect_spawn_fire_breath = 0x8001CE98");
	#elif MM_U_1_0
		asm("z_effect_spawn_fire_breath = 0x800B1DC8");
	#endif

/**
 * Spawn ovl_Effect_Ss_Bubble (A water bubble)
 */
#define func_800293E4 z_effect_spawn_bubble
extern void z_effect_spawn_bubble(z64_global_t* gl, vec3f_t* pos, float a, float b, float c, float d);
	#if OOT_DEBUG
		asm("z_effect_spawn_bubble = 0x800293E4");
	#elif OOT_U_1_0
		asm("z_effect_spawn_bubble = 0x8001CEDC");
	#elif MM_U_1_0
		asm("z_effect_spawn_bubble = 0x800B1E94");
	#endif

/**
 * Spawn Particle 0x09
 * TODO These notes need converted into a C function prototype
 */
extern void z_effect_spawn_water_ripple(z64_global_t* global, vec3f_t* pos, int32_t unk0, int32_t unk1, int32_t unk2);
	#if OOT_DEBUG
		asm("z_effect_spawn_water_ripple = 0x80029444");
	#elif OOT_U_1_0
		asm("z_effect_spawn_water_ripple = 0x8001CF3C");
	#elif MM_U_1_0
		asm("z_effect_spawn_water_ripple = 0x800B1EF4");
	#endif

/**
 * Spawn Particle 0x0A
 * TODO These notes need converted into a C function prototype
 */
extern void z_effect_spawn_water_splash(
	z64_global_t *global, vec3f_t *pos,
	int32_t unk0, int32_t unk1, int32_t unk2, int32_t unk3
);
	#if OOT_DEBUG
		asm("z_effect_spawn_water_splash = 0x8002949C");
	#elif OOT_U_1_0
		asm("z_effect_spawn_water_splash = 0x8001CF94");
	#elif MM_U_1_0
		asm("z_effect_spawn_water_splash = 0x800B1F4C");
	#endif

/**
 * Spawn Particle 0x0B
 * TODO These notes need converted into a C function prototype
 */
extern void z_effect_spawn_magma(void);
	#if OOT_DEBUG
		asm("z_effect_spawn_magma = 0x80029530");
	#elif OOT_U_1_0
		asm("z_effect_spawn_magma = 0x8001D028");
	#endif

/**
 * Spawn Particle 0x0D
 * TODO These notes need converted into a C function prototype
 */
extern void z_effect_spawn_lightning(z64_global_t *global, vec3f_t *position, uint32_t *opacity, uint32_t *color, uint16_t size);
    #if OOT_DEBUG
        asm("z_effect_spawn_lightning= 0x800295A0");
    #elif OOT_U_1_0
        asm("z_effect_spawn_lightning= 0x8001D098");
    #endif

/* Spawn ovl_Effect_Ss_Dt_Bubble (Big Octo Bubble)
* Source Code Reference File: "z_effect_soft_sprite.c"
*/
extern void z_effect_spawn_dt_bubble_0(
z64_global_t* gl /* Global Context */
, vec3f_t* position /* X, Y, and Z Position */
, vec3f_t* velocity /* Velocity along the X, Y, and Z axes */
, vec3f_t* acceleration /* Acceleration along the X, Y, and Z axes */
, int16_t drop_scale /* Affects visible scale. */
, int16_t sp14
, int16_t color /* Some kind of color index. */
, int16_t sp1C
);
#if OOT_DEBUG
	asm("z_effect_spawn_dt_bubble_0 = 0x80029618");
#elif OOT_U_1_0
	asm("z_effect_spawn_dt_bubble_0 = 0x8001D110");
#elif MM_U_1_0
	asm("z_effect_spawn_dt_bubble_0 = 0x800B2090");
#endif

/**
 * Spawn Particle 0x0E
 * TODO These notes need converted into a C function prototype
 */
extern void external_func_80029694(void);
	#if OOT_DEBUG
		asm("external_func_80029694 = 0x80029694");
	#elif OOT_U_1_0
		asm("external_func_80029694 = 0x8001D18C");
	#elif MM_U_1_0
		asm("external_func_80029694 = 0x800B210C");
	#endif

/* Spawn ovl_Effect_Ss_Hahen (Fragment)
* Source Code Reference File: "z_effect_soft_sprite.c"
*/
extern void z_effect_spawn_hahen(
z64_global_t* gl /* Global Context */
, vec3f_t* position /* X, Y, and Z Position */
, vec3f_t* velocity /* Velocity along the X, Y, and Z axes */
, vec3f_t* acceleration /* Acceleration along the X, Y, and Z axes */
, int16_t xr, int16_t yr, int16_t zr /* X, Y, and Z Rotation (Unconfirmed) */
, int16_t sp20
, int32_t sp24
);
#if OOT_DEBUG
  asm("z_effect_spawn_hahen = 0x80029724");
#elif OOT_U_1_0
  asm("z_effect_spawn_hahen = 0x8001D21C");
#elif MM_U_1_0
  /*asm("z_effect_spawn_hahen = 0xDEADBEEF");*/
#endif

/* Spawn ovl_Effect_Ss_Hahen
* Wrapper to modify the amount of particles spawned.
* Source Code Reference File: "z_effect_soft_sprite.c"
*/
extern void z_effect_spawn_hahen_n(
z64_global_t* gl /* Global Context */
, vec3f_t* position /* X, Y, and Z Position */
, float y_speed /* Acceleration along the Y axis */
, int16_t a3
, int16_t srand_offset /* `offset` for z_lib_math_rand_s16_offset */
, int16_t srand_range /* `range` for z_lib_math_rand_s16_offset */
, int16_t count /* Particle Count */
, int16_t sp20
, int16_t sp24
, int32_t sp28
);
#if OOT_DEBUG
  asm("z_effect_spawn_hahen_n = 0x800297A4");
#elif OOT_U_1_0
  asm("z_effect_spawn_hahen_n = 0x8001D29C");
#elif MM_U_1_0
  /*asm("z_effect_spawn_hahen_n = 0xDEADBEEF");*/
#endif

/**
 * Spawn Particle 0x11 (Wrapper for 8001D438)
 * TODO These notes need converted into a C function prototype
 */
extern void z_effect_spawn_splash(z64_global_t* gl, vec3f_t* pos);
	#if OOT_DEBUG
		asm("z_effect_spawn_splash = 0x800299AC");
	#elif OOT_U_1_0
		asm("z_effect_spawn_splash = 0x8001D4A8");
	#endif

/**
 * Spawn Particle 0x13
 * TODO These notes need converted into a C function prototype
 */
extern void z_effect_spawn_magma2(void);
	#if OOT_DEBUG
		asm("z_effect_spawn_magma2 = 0x80029B90");
	#elif OOT_U_1_0
		asm("z_effect_spawn_magma2 = 0x8001D68C");
	#endif

/**
 * Spawn Particle 0x14
 * TODO These notes need converted into a C function prototype
 */
extern void z_effect_spawn_stone1(void);
	#if OOT_DEBUG
		asm("z_effect_spawn_stone1 = 0x80029C00");
	#elif OOT_U_1_0
		asm("z_effect_spawn_stone1 = 0x8001D6FC");
	#endif

/**
 * Spawn ovl_Effect_Ss_HitMark (Impact Effect)
 */
extern void z_effect_spawn_hitmark(z64_global_t* gl, int32_t a, vec3f_t* pos);
	#if OOT_DEBUG
		asm("z_effect_spawn_hitmark = 0x80029CA4");
	#elif OOT_U_1_0
		asm("z_effect_spawn_hitmark = 0x8001D7A8");
	#endif

/**
 * Spawn Particle 0x15 (Wrapper for 8001D750)
 * TODO These notes need converted into a C function prototype
 */
extern void external_func_80029CC8(void);
	#if OOT_DEBUG
		asm("external_func_80029CC8 = 0x80029CC8");
	#elif OOT_U_1_0
		asm("external_func_80029CC8 = 0x8001D7CC");
	#endif

/**
 * Spawn Particle 0x16
 * TODO These notes need converted into a C function prototype
 */
extern void external_func_80029CF0(void);
	#if OOT_DEBUG
		asm("external_func_80029CF0 = 0x80029CF0");
	#elif OOT_U_1_0
		asm("external_func_80029CF0 = 0x8001D7F8");
	#endif

/**
 * Spawn Particle 0x16
 * TODO These notes need converted into a C function prototype
 */
extern void external_func_80029D5C(void);
	#if OOT_DEBUG
		asm("external_func_80029D5C = 0x80029D5C");
	#elif OOT_U_1_0
		asm("external_func_80029D5C = 0x8001D864");
	#endif

/**
 * Spawn Particle 0x17
 * TODO These notes need converted into a C function prototype
 */
extern void z_effect_spawn_k_fire(void);
	#if OOT_DEBUG
		asm("z_effect_spawn_k_fire = 0x80029DBC");
	#elif OOT_U_1_0
		asm("z_effect_spawn_k_fire = 0x8001D8C8");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_80029E24(void);
	#if OOT_DEBUG
		asm("external_func_80029E24 = 0x80029E24");
	#elif OOT_U_1_0
		asm("external_func_80029E24 = 0x8001D930");
	#endif

/**
 * Spawn Particle 0x19 (ovl_Effect_Ss_Kakera)
*************
Argument Notes
* gl = Global Context
* burst_depth_y = The range of the particle fragments along the explosion's y axis (up and down)
* burst_depth_x = The range of the particle fragments along the explosion's x axis (left and right)
* gravity_influence = The influence of gravity on the explosion's particle fragments
* ? - Set to 0x20, 0x40 or 0x60
* rotation_speed = The number of frames for a particle fragment to complete a full rotation
* burst_velocity = The outward force of the explosion
* ? - Set to 0
* scale = The scale of each particle fragment
* ? - Set to 0
* jitter = The aggression that which particle fragments shake with
* duration = The number of frames for a particle fragment to be drawn.
* ? - Set to -1
* object_number = The number of the object containing the particle fragment display list
* display_list = The display list of the particle fragment
**************
 */
extern void z_effect_spawn_fragment(
	z64_global_t *global,
	vec3f_t *burst_depth_y, vec3f_t *burst_depth_x, vec3f_t *burst_origin,
	int16_t gravity_influence,
	int16_t u0,
	int16_t rotation_speed,
	int16_t burst_velocity,
	int16_t u1,
	int16_t scale,
	int16_t u2,
	int16_t jitter,
	int32_t duration,
	int16_t u3,
	int16_t objno,
	uint32_t dlist
	);
	#if OOT_DEBUG
		asm("z_effect_spawn_fragment = 0x80029E8C");
	#elif OOT_U_1_0
		asm("z_effect_spawn_fragment = 0x8001D998");
	#elif MM_U_1_0
		asm("z_effect_spawn_fragment = 0x800B2810");
	#endif

/**
 * Spawn Particle 0x1B
 * TODO These notes need converted into a C function prototype
 */
extern void external_func_8002A140(void);
	#if OOT_DEBUG
		asm("external_func_8002A140 = 0x8002A140");
	#elif OOT_U_1_0
		asm("external_func_8002A140 = 0x8001DC4C");
	#endif

/**
 * Spawn Particle 0x1B (ovl_Effect_Ss_En_Ice)
 * TODO These notes need converted into a C function prototype
 */
extern void external_func_8002A1DC(z64_global_t *gl, void *en, int16_t *unk, uint8_t a3, uint8_t a4, uint8_t a5, uint8_t a6, uint8_t a7, uint8_t a8, uint8_t a9, uint32_t a10);
	#if OOT_DEBUG
		asm("external_func_8002A1DC = 0x8002A1DC");
	#elif OOT_U_1_0
		asm("external_func_8002A1DC = 0x8001DCEC");
	#endif

/**
 * Spawn Particle 0x1B
 * TODO These notes need converted into a C function prototype
 */
extern void external_func_8002A2A4(void);
	#if OOT_DEBUG
		asm("external_func_8002A2A4 = 0x8002A2A4");
	#elif OOT_U_1_0
		asm("external_func_8002A2A4 = 0x8001DDB8");
	#endif

/**
 * Spawn Particle 0x1C (Wrapper for 8001DE40)
 * TODO These notes need converted into a C function prototype
 */
extern void z_effect_spawn_fire_tail(void);
	#if OOT_DEBUG
		asm("z_effect_spawn_fire_tail = 0x8002A3C4");
	#elif OOT_U_1_0
		asm("z_effect_spawn_fire_tail = 0x8001DED8");
	#endif

/* Spawn ovl_Effect_Ss_En_Fire (Fire)
* Source Code Reference File: "z_effect_soft_sprite_old_init.c"
* Formerly `z_effect_spawn_en_fire`
*/
extern void z_effect_spawn_fire(
z64_global_t* gl /* Global Context */
, z64_actor_t* a /* Actor to Reference */
, vec3f_t* position /* X, Y, and Z Position */
, int16_t a3
, int16_t sp10
, int16_t sp14
, int16_t count /* Particle Count */
);
#if OOT_DEBUG
  asm("z_effect_spawn_fire = 0x8002A4D4");
#elif OOT_U_1_0
  asm("z_effect_spawn_fire = 0x8001DFEC");
#elif MM_U_1_0
  /*asm("z_effect_spawn_fire = 0xDEADBEEF");*/
#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8002A54C(void);
	#if OOT_DEBUG
		asm("external_func_8002A54C = 0x8002A54C");
	#elif OOT_U_1_0
		asm("external_func_8002A54C = 0x8001E064");
	#endif

/**
 * Spawn Particle 0x1E
 * TODO These notes need converted into a C function prototype
 */
extern void z_effect_spawn_extra(void);
	#if OOT_DEBUG
		asm("z_effect_spawn_extra = 0x8002A5F4");
	#elif OOT_U_1_0
		asm("z_effect_spawn_extra = 0x8001E110");
	#endif

/* Spawn Flame Circle
* Source Code Reference File: "z_effect_soft_sprite.c"
*/
extern void z_effect_spawn_flame_circle(
z64_global_t* gl /* Global Context */
, z64_actor_t* a /* Actor Instance */
, vec3f_t* position /* X, Y, and Z Position */
, uint16_t radius /* Flame Cylinder Radius */
, uint16_t height /* Flame Cylinder Height */
);
#if OOT_DEBUG
  asm("z_effect_spawn_flame_circle = 0x8002A65C");
#elif OOT_U_1_0
  asm("z_effect_spawn_flame_circle = 0x8001E178");
#elif MM_U_1_0
	/* ovl_Effect_Ss_Fcircle does not exist in MM */
  /*asm("z_effect_spawn_flame_circle = 0xDEADBEEF");*/
#endif

/* Spawn ovl_Effect_Ss_Dead_Db (Dead Deku Baba)
* Particles on Deku Baba Death
* Source Code Reference File: "z_effect_soft_sprite.c"
*/
extern void z_effect_spawn_dead_db(
z64_global_t* gl /* Global Context */
, vec3f_t* position /* X, Y, and Z Position */
, vec3f_t* a2
, vec3f_t* a3
, uint16_t scale /* Scale * 100 */
, uint16_t sp14
, uint8_t smoke_ir, uint8_t smoke_ig, uint8_t smoke_ib /* RGB of Inner Smoke Cloud */
, uint8_t smoke_a /* Smoke Cloud Alpha */
, uint8_t smoke_or, uint8_t smoke_og, uint8_t smoke_ob /* RGB of Outer Smoke Cloud */
, uint16_t sp34
, uint32_t duration /* Duration of Effect in Frames */
, uint16_t sp3C
);
#if OOT_DEBUG
  asm("z_effect_spawn_dead_db = 0x8002A6B8");
#elif OOT_U_1_0
  asm("z_effect_spawn_dead_db = 0x8001E1D4");
#elif MM_U_1_0
  asm("z_effect_spawn_dead_db = 0x800B2F80");
#endif

/**
 * Spawn Particle 0x21
 * TODO These notes need converted into a C function prototype
 */
extern void z_effect_spawn_dead_dodongo(void);
	#if OOT_DEBUG
		asm("z_effect_spawn_dead_dodongo = 0x8002A770");
	#elif OOT_U_1_0
		asm("z_effect_spawn_dead_dodongo = 0x8001E28C");
	#endif

/**
 * Spawn Particle 0x22 (Wrapper for 8001E3B0)
 * TODO These notes need converted into a C function prototype
 */
extern void z_effect_spawn_dead_deku_scrub(void);
	#if OOT_DEBUG
		asm("z_effect_spawn_dead_deku_scrub = 0x8002A90C");
	#elif OOT_U_1_0
		asm("z_effect_spawn_dead_deku_scrub = 0x8001E428");
	#endif

/**
 * Spawn Particle 0x23 (Wrapper for 8001E478)
 * TODO These notes need converted into a C function prototype
 */
extern void z_effect_spawn_dead_sound(z64_global_t* gl, vec3f_t* pos, uint16_t sfx, int16_t u0, int16_t u1, uint32_t u2);
	#if OOT_DEBUG
		asm("z_effect_spawn_dead_sound = 0x8002A9F4");
	#elif OOT_U_1_0
		asm("z_effect_spawn_dead_sound = 0x8001E510");
	#endif

/**
 * Spawn Particle 0x24
 * TODO These notes need converted into a C function prototype
 */
extern void z_effect_spawn_ice_smoke(void);
	#if OOT_DEBUG
		asm("z_effect_spawn_ice_smoke = 0x8002AA44");
	#elif OOT_U_1_0
		asm("z_effect_spawn_ice_smoke = 0x8001E560");
	#endif

/* Initialize the process to draw a drop shadow.
* Source Code Reference File: "z_actor.c"
* Formerly `actor_init_shadow`
*/
#define ActorShape_Init z_actor_shadow_init
extern void z_actor_shadow_init(
void* a /* Sub Structure at `actor->0x00B4`, formerly `rot_2` */
, float f0
, void* fdraw /* Shadow Draw Function */
, float radius /* Radius of Shadow */
);
#if OOT_DEBUG
  asm("z_actor_shadow_init = 0x8002B1E0");
  asm("Z_SHADOW_CIRCLE = 0x8002B5EC");
  asm("Z_SHADOW_TEARDROP = 0x8002B8C4");
  //asm("Z_SHADOW_CIRCLE_WHITE = 0x8002B614");
  //asm("Z_SHADOW_SQUIGGLE = 0x8002B644");
#elif OOT_U_1_0
  asm("z_actor_shadow_init = 0x8001EC20");
  asm("Z_SHADOW_CIRCLE = 0x8001EFF4");
  asm("Z_SHADOW_TEARDROP = 0x8001F280");
#elif MM_U_1_0
  asm("z_actor_shadow_init = 0x800B3BA4");
  asm("Z_SHADOW_CIRCLE = 0x800B3FC0");
  asm("Z_SHADOW_TEARDROP = 0x800B42F8");
#elif MM_J_1_0
  asm("z_actor_shadow_init = 0x800B5784");
  asm("Z_SHADOW_CIRCLE = 0x800B5BA0");
  asm("Z_SHADOW_TEARDROP = 0x800B5ED8");
#elif MM_DEBUG
  asm("z_actor_shadow_init = 0x800C61DC");
  asm("Z_SHADOW_CIRCLE = 0x800C6634");
  asm("Z_SHADOW_TEARDROP = 0x800C6A4C");
#endif
extern void *Z_SHADOW_CIRCLE, *Z_SHADOW_TEARDROP;

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8002BDB0(void);
	#if OOT_DEBUG
		asm("external_func_8002BDB0 = 0x8002BDB0");
	#elif OOT_U_1_0
		asm("external_func_8002BDB0 = 0x8001F74C");
	#endif

/**
 * Tests if Switch Flag is Set
 */
#define Flags_GetSwitch z_flags_switch_get
#define flag_get_switch z_flags_switch_get
extern int32_t z_flags_switch_get(z64_global_t *global, int32_t flag);
	#if OOT_DEBUG
		asm("z_flags_switch_get = 0x8002CB40");
	#elif OOT_U_1_0
		asm("z_flags_switch_get = 0x8002049C");
	#elif MM_U_1_0
		asm("z_flags_switch_get = 0x800B5BB0");
	#endif

/**
 * Sets Switch Flag to 1
 */
#define Flags_SetSwitch z_flags_switch_set
#define flag_set_switch z_flags_switch_set
extern void z_flags_switch_set(z64_global_t *global, int32_t flag);
	#if OOT_DEBUG
		asm("z_flags_switch_set = 0x8002CB74");
	#elif OOT_U_1_0
		asm("z_flags_switch_set = 0x800204D0");
	#elif MM_U_1_0
		asm("z_flags_switch_set = 0x800B5BF4");
	#endif

/**
 * Sets Switch Flag to 0
 */
#define Flags_UnsetSwitch z_flags_switch_unset
#define flag_unset_switch z_flags_switch_unset
extern void z_flags_switch_unset(z64_global_t *global, int32_t flag);
	#if OOT_DEBUG
		asm("z_flags_switch_unset = 0x8002CBB4");
	#elif OOT_U_1_0
		asm("z_flags_switch_unset = 0x80020510");
	#elif MM_U_1_0
		asm("z_flags_switch_unset = 0x800B5C34");
	#endif

/**
 * Tests if Unused Scene Flag is Set
 * This function is not used inside any existing overlay
 */
#define Flags_GetUnknown z_flags_switch_unk_get
#define flag_get_uscene z_flags_switch_unk_get
extern int32_t z_flags_switch_unk_get(z64_global_t *global, int32_t flag);
	#if OOT_DEBUG
		asm("z_flags_switch_unk_get = 0x8002CBF8");
	#elif OOT_U_1_0
		asm("z_flags_switch_unk_get = 0x80020554");
	#endif

/**
 * Sets Unused Scene Flag to 1
 * This function is not used inside any existing overlay
 */
#define Flags_SetUnknown z_flags_switch_unk_set
#define flag_set_uscene z_flags_switch_unk_set
extern void z_flags_switch_unk_set(z64_global_t *global, int32_t flag);
	#if OOT_DEBUG
		asm("z_flags_switch_unk_set = 0x8002CC2C");
	#elif OOT_U_1_0
		asm("z_flags_switch_unk_set = 0x80020588");
	#endif

/**
 * Sets Unused Scene Flag to 0
 * This function is not used inside any existing overlay
 */
#define Flags_UnsetUnknown z_flags_switch_unk_unset
#define flag_unset_uscene z_flags_switch_unk_unset
extern void z_flags_switch_unk_unset(z64_global_t *global, int32_t flag);
	#if OOT_DEBUG
		asm("z_flags_switch_unk_unset = 0x8002CC6C");
	#elif OOT_U_1_0
		asm("z_flags_switch_unk_unset = 0x800205C8");
	#endif

/**
 * Tests if a Chest Flag is set
 */
#define Flags_GetTreasure z_flags_chest_get
#define flag_get_treasure z_flags_chest_get
extern int32_t z_flags_chest_get(z64_global_t *global, int32_t flag);
	#if OOT_DEBUG
		asm("z_flags_chest_get = 0x8002CCB0");
	#elif OOT_U_1_0
		asm("z_flags_chest_get = 0x8002060C");
	#endif

/**
 * Sets Chest Flag to 1
 */
#define Flags_SetTreasure z_flags_chest_set
#define flag_set_treasure z_flags_chest_set
extern void z_flags_chest_set(z64_global_t *global, int32_t flag);
	#if OOT_DEBUG
		asm("z_flags_chest_set = 0x8002CCC4");
	#elif OOT_U_1_0
		asm("z_flags_chest_set = 0x80020624");
	#endif

/**
 * Test if a Room Clear Flag is set
 */
#define Flags_GetClear z_flags_clear_get
#define flag_get_roomclear z_flags_clear_get
extern int32_t z_flags_clear_get(z64_global_t *global, int32_t flag);
	#if OOT_DEBUG
		asm("z_flags_clear_get = 0x8002CCDC");
	#elif OOT_U_1_0
		asm("z_flags_clear_get = 0x80020640");
	#endif

/**
 * Sets Room Clear Flag to 1
 */
#define Flags_SetClear z_flags_clear_set
#define flag_set_roomclear z_flags_clear_set
extern void z_flags_clear_set(z64_global_t *global, int32_t flag);
	#if OOT_DEBUG
		asm("z_flags_clear_set = 0x8002CCF0");
	#elif OOT_U_1_0
		asm("z_flags_clear_set = 0x80020658");
	#endif

/**
 * Unset Room Clear Flags
 */
#define Flags_UnsetClear z_flags_clear_unset
extern void z_flags_clear_unset(z64_global_t *global, int32_t flag);
	#if OOT_DEBUG
		asm("z_flags_clear_unset = 0x8002CD08");
	#elif OOT_U_1_0
		asm("z_flags_clear_unset = 0x80020674");
	#endif

/**
 * Tests if Global Context + 0x1D40 Flag is set
 */
#define Flags_GetTempClear z_flags_clear_temp_get
#define temp_clear_flag_get z_flags_clear_temp_get
extern int32_t z_flags_clear_temp_get(z64_global_t *global, int32_t flag);
	#if OOT_DEBUG
		asm("z_flags_clear_temp_get = 0x8002CD24");
	#elif OOT_U_1_0
		asm("z_flags_clear_temp_get = 0x80020694");
	#elif MM_U_1_0
		asm("z_flags_clear_temp_get = 0x800B5D18");
	#endif

/**
 * Sets Global Context + 0x1D40 Flag to 1
 */
#define Flags_SetTempClear z_flags_clear_temp_set
#define temp_clear_flag_set z_flags_clear_temp_set
extern void z_flags_clear_temp_set(z64_global_t *global, int32_t flag);
	#if OOT_DEBUG
		asm("z_flags_clear_temp_set = 0x8002CD38");
	#elif OOT_U_1_0
		asm("z_flags_clear_temp_set = 0x800206AC");
	#elif MM_U_1_0
		asm("z_flags_clear_temp_set = 0x800B5D30");
	#endif

/**
 * Tests if Scene Collectible Flag is set
 */
#define Flags_GetCollectible z_flags_collect_get
#define flag_get_scenecollect z_flags_collect_get
extern int32_t z_flags_collect_get(z64_global_t *global, int32_t flag);
	#if OOT_DEBUG
		asm("z_flags_collect_get = 0x8002CD6C");
	#elif OOT_U_1_0
		asm("z_flags_collect_get = 0x800206E8");
	#elif MM_U_1_0
		asm("z_flags_collect_get = 0x800B5D6C");
	#endif

/**
 * Sets Scene Collectible Flag to 1
 */
#define Flags_SetCollectible z_flags_collect_set
#define flag_set_scenecollect z_flags_collect_set
extern void z_flags_collect_set(z64_global_t *global, int32_t flag);
	#if OOT_DEBUG
		asm("z_flags_collect_set = 0x8002CDA0");
	#elif OOT_U_1_0
		asm("z_flags_collect_set = 0x8002071C");
	#elif MM_U_1_0
		asm("z_flags_collect_set = 0x800B5DB0");
	#endif

/**
 * Boss Title
 * A0 - global context | A1 - A0 + 0x1D4C (Title Card Context) | A2 - (object pointer + texture offset inside the object)
 */
#define TitleCard_InitBossName z_actor_titlecard_boss
#define actor_boss_title z_actor_titlecard_boss
extern void z_actor_titlecard_boss(z64_global_t *global, z64_global_t *global_plus_0x1D4C, uint32_t texture, int16_t arg3, int16_t arg4, uint8_t arg5, uint8_t arg6);
	#if OOT_DEBUG
		asm("z_actor_titlecard_boss = 0x8002CE00");
	#elif OOT_U_1_0
		asm("z_actor_titlecard_boss = 0x80020780");
	#elif MM_U_1_0
		asm("z_actor_titlecard_boss = 0x800B5E0C");
	#endif

/* This kills an actor process.
* Does not de-allocate an actor.
* Sets `main_proc` and `draw_proc` to 0x0.
* Set `flags` to -1.
* Source Code Reference File: "z_actor.c"
* Formerly `actor_kill`
*/
#define Actor_Kill z_actor_kill
extern void z_actor_kill(
z64_actor_t* a /* Actor to Kill */
);
#if OOT_DEBUG
  asm("z_actor_kill = 0x8002D570");
#elif OOT_U_1_0
  asm("z_actor_kill = 0x80020EB4");
#elif MM_U_1_0
  asm("z_actor_kill = 0x800B670C");
#endif

/* Set Actor Height
* Refreshes Z-Target Position
* Source Code Reference File: "z_actor.c"
* Formerly `actor_set_height`
*/
#define Actor_SetHeight z_actor_set_height
extern void z_actor_set_height(
z64_actor_t* a /* Actor to Reference */
, float height /* Y position relative to Actor Origin */
);
#if OOT_DEBUG
  asm("z_actor_set_height = 0x8002D5B8");
#elif OOT_U_1_0
  asm("z_actor_set_height = 0x80020F04");
#elif MM_U_1_0
  asm("z_actor_set_height = 0x800B675C");
#endif

/* Set Actor Scale
* Source Code Reference File: "z_actor.c"
* Formerly `actor_set_scale`
*/
#define Actor_SetScale z_actor_set_scale
extern void z_actor_set_scale(
z64_actor_t* a /* Actor to Reference */
, float scale /* X, Y, and Z scale of actor */
);
#if OOT_DEBUG
  asm("z_actor_set_scale = 0x8002D62C");
#elif OOT_U_1_0
  asm("z_actor_set_scale = 0x80020F88");
#elif MM_U_1_0
  asm("z_actor_set_scale = 0x800B67E0");
#endif

/**
 * Update CPU Segment 0x06 to point32_t to actor's defined object dependency
 */
#define Actor_SetObjectDependency z_actor_set_object
#define actor_set_object z_actor_set_object
extern void z_actor_set_object(z64_global_t *global, z64_actor_t *actor);
	#if OOT_DEBUG
		asm("z_actor_set_object = 0x8002D644");
	#elif OOT_U_1_0
		asm("z_actor_set_object = 0x80020FA4");
	#elif MM_U_1_0
		asm("z_actor_set_object = 0x800B67FC");
	#endif

/**
 * Physics, updates XYZ coordinates of actor
 */
#define actor_update_pos z_actor_update_pos
extern void z_actor_update_pos(z64_actor_t *actor);
	#if OOT_DEBUG
		asm("z_actor_update_pos = 0x8002D7EC");
	#elif OOT_U_1_0
		asm("z_actor_update_pos = 0x80021124");
	#elif MM_U_1_0
		asm("z_actor_update_pos = 0x800B69AC");
	#endif

/**
 * Physics, updates XYZ velocity vectors (+0x5C) of an actor
 * Only factors y component of speed rotation xyz (+0x30)
 */
#define actor_update_vel z_actor_update_vel
extern void z_actor_update_vel(z64_actor_t *actor);
	#if OOT_DEBUG
		asm("z_actor_update_vel = 0x8002D868");
	#elif OOT_U_1_0
		asm("z_actor_update_vel = 0x800211A4");
	#endif

/* Move actor towards direction.
* Direction is set at `actor->0x0032`
* Speed/Velocity is set at `actor->0x0068`
* Source Code Reference File: "z_actor.c"
* Formerly `actor_move_towards_direction`
*/
#define Actor_MoveForward z_actor_move_dir_vel
extern void z_actor_move_dir_vel(
z64_actor_t* a /* Actor Instance to Modify */
);
#if OOT_DEBUG
  asm("z_actor_move_dir_vel = 0x8002D8E0");
#elif OOT_U_1_0
  asm("z_actor_move_dir_vel = 0x8002121C");
#elif MM_U_1_0
  asm("z_actor_move_dir_vel = 0x800B6A88");
#endif

/**
 * Physics, updates XYZ velocity vectors (+0x5C) of an actor
 * Factors x and y component of speed rotation xyz (+0x30)
 * TODO These notes need converted into a C function prototype
 */
extern void external_func_8002D908(z64_actor_t *actor);
	#if OOT_DEBUG
		asm("external_func_8002D908 = 0x8002D908");
	#elif OOT_U_1_0
		asm("external_func_8002D908 = 0x80021248");
	#endif

/**
 * Physics, updates XYZ velocity and XYZ coordinates of actor | (Wrapper for 80021248 and 80021124)
 * TODO These notes need converted into a C function prototype
 * A0 = Actor Instance ptr
 */
extern void external_func_8002D97C(z64_actor_t* a);
	#if OOT_DEBUG
		asm("external_func_8002D97C = 0x8002D97C");
	#elif OOT_U_1_0
		asm("external_func_8002D97C = 0x800212B8");
	#elif MM_U_1_0
		asm("external_func_8002D97C = 0x800B6B24");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8002D9A4(z64_actor_t* a, float a1);
	#if OOT_DEBUG
		asm("external_func_8002D9A4 = 0x8002D9A4");
	#elif OOT_U_1_0
		asm("external_func_8002D9A4 = 0x800212E4");
	#endif

/* Return angle of rotation to face another actor.
* Source Code Reference File: "z_actor.c"
*/
extern int16_t z_actor_math_yaw_actor(
z64_actor_t* a /* Actor to Derive Angle */
, z64_actor_t* target /* Actor to Target */
);
#if OOT_DEBUG
  asm("z_actor_math_yaw_actor = 0x8002DAC0");
#elif OOT_U_1_0
  asm("z_actor_math_yaw_actor = 0x8002140C");
#elif MM_U_1_0
  asm("z_actor_math_yaw_actor = 0x800B6CD4");
#endif

/* Return angle of rotation to reach target (provided a vec3f_t)
* Source Code Reference File: "z_actor.c"
*/
extern int16_t z_actor_math_yaw_vec3f(
z64_actor_t* a /* Actor to Derive Angle */
, vec3f_t* target /* Target Vector */
);
#if OOT_DEBUG
  asm("z_actor_math_yaw_vec3f = 0x8002DAC0");
#elif OOT_U_1_0
  asm("z_actor_math_yaw_vec3f = 0x8002140C");
#elif MM_U_1_0
  /*asm("z_actor_math_yaw_vec3f = 0xDEADBEEF");*/
#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8002DAE0(z64_actor_t* a, z64_actor_t* b);
	#if OOT_DEBUG
		asm("external_func_8002DAE0 = 0x8002DAE0");
	#elif OOT_U_1_0
		asm("external_func_8002DAE0 = 0x80021430");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8002DB28(z64_actor_t* a, vec3f_t* b);
	#if OOT_DEBUG
		asm("external_func_8002DB28 = 0x8002DB28");
	#elif OOT_U_1_0
		asm("external_func_8002DB28 = 0x80021488");
	#endif

/**
 * Calculates XYZ distance between two actors (+0x24)
 * Wrapper for 80063E18
 * TODO These notes need converted into a C function prototype
 * A0 = Actor A | A1 = Actor B | F0 = Result
 */
extern float math_distance_xyz_actor_actor(z64_actor_t *a, z64_actor_t *b);
	#if OOT_DEBUG
		asm("math_distance_xyz_actor_actor = 0x8002DB48");
	#elif OOT_U_1_0
		asm("math_distance_xyz_actor_actor = 0x800214AC");
	#endif

/**
 * Calculates XYZ distance between actor (+0x24) and a point_t  | Wrapper fo 80063E18
 * TODO These notes need converted into a C function prototype
 * A0 = Actor | A1 = Coordinate ptr | F0 = Result
 */
extern float math_distance_xyz_actor_point(z64_actor_t *a, z64_point_t *b);
	#if OOT_DEBUG
		asm("math_distance_xyz_actor_point32_t = 0x8002DB6C");
	#elif OOT_U_1_0
		asm("math_distance_xyz_actor_point32_t = 0x800214D8");
	#endif

/**
 * Calculates XZ distance between two actors (+0x24)
 * Wrapper for 80063EB8
 */
extern float math_distance_xz_actor_actor(z64_actor_t *a, z64_actor_t *b);
	#if OOT_DEBUG
		asm("math_distance_xz_actor_actor = 0x8002DB8C");
	#elif OOT_U_1_0
		asm("math_distance_xz_actor_actor = 0x800214FC");
	#endif

/* Calculate the XZ distance between an actor and an arbitrary vec3f (point)
* Source Code Reference File: "z_actor.c"
*/
extern float z_actor_math_dist_xz_vec3f(
z64_actor_t* a /* Actor to Derive Position */
, vec3f_t* target /* Target Vector */
);
#if OOT_DEBUG
  asm("z_actor_math_dist_xz_vec3f = 0x8002DBB0");
#elif OOT_U_1_0
  asm("z_actor_math_dist_xz_vec3f = 0x80021528");
#elif MM_U_1_0
  /*asm("z_actor_math_dist_xz_vec3f = 0xDEADBEEF");*/
#endif

/**
 * Returns vertical, horizontal and front distance between 2 points taking rotation of instance into account
 * TODO These notes need converted into a C function prototype
 * a0 - actor instance | a1 - $sp + offset to store an array of 3 floats | a2 - array position of Link (and other stuff?)
 */
extern void external_func_8002DBD0(void);
	#if OOT_DEBUG
		asm("external_func_8002DBD0 = 0x8002DBD0");
	#elif OOT_U_1_0
		asm("external_func_8002DBD0 = 0x8002154C");
	#endif

/**
 * Calculates Y distance between two actors (+0x28)
 * Height Difference
 */
#define Actor_HeightDiff z_actor_y_distance
#define math_distance_y_actor_actor z_actor_y_distance
extern float z_actor_y_distance(z64_actor_t *a, z64_actor_t *b);
	#if OOT_DEBUG
		asm("z_actor_y_distance = 0x8002DC74");
	#elif OOT_U_1_0
		// TODO Find 1.0 Equivalent!
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8002DD78(z64_player_t* player);
	#if OOT_DEBUG
		asm("external_func_8002DD78 = 0x8002DD78");
	#elif OOT_U_1_0
		asm("external_func_8002DD78 = 0x800216F8");
	#endif

/**
 * Regarding Link's Y Scale
 * return Link->actor.scale.y & 8
 */
extern void external_func_8002DDE4(z64_global_t* gl);
	#if OOT_DEBUG
		asm("external_func_8002DDE4 = 0x8002DDE4");
	#elif OOT_U_1_0
		asm("external_func_8002DDE4 = 0x80021768");
	#endif

/**
 * Regarding Link's Y Scale
 * return Link->actor.scale.y & 0x1000
 */
extern void external_func_8002DDF4(z64_global_t* gl);
	#if OOT_DEBUG
		asm("external_func_8002DDF4 = 0x8002DDF4");
	#elif OOT_U_1_0
		asm("external_func_8002DDF4 = 0x8002177C");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8002DE04(z64_global_t* gl, z64_actor_t* a, z64_actor_t* b);
	#if OOT_DEBUG
		asm("external_func_8002DE04 = 0x8002DE04");
	#elif OOT_U_1_0
		asm("external_func_8002DE04 = 0x80021790");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8002DEEC(z64_global_t* gl, z64_player_t* Link, z64_actor_t* a);
	#if OOT_DEBUG
		asm("external_func_8002DEEC = 0x8002DEEC");
	#elif OOT_U_1_0
		asm("external_func_8002DEEC = 0x8002187C");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8002DF38(z64_global_t* gl, z64_actor_t* a, uint8_t action);
	#if OOT_DEBUG
		asm("external_func_8002DF38 = 0x8002DF38");
	#elif OOT_U_1_0
		asm("external_func_8002DF38 = 0x800218C8");
	#endif

/**
 * make Link perform an action during an actor-controlled cutscene
 * `actor`   can be `0` or `NULL`; a copy of this pointer gets
             stored at 0x448 in Link's instance structure
 * `action`  the action `var_80854B18[action]` in Link's overlay
             will be executed; note that this is a different table
             than what is used during scene cutscenes; also, a copy of
             this value is stored as a `uint8_t` at 0x444 in Link's instance.
             If you end the cutscene you will not have control over Link
             until you use action 0x7.

 * TODO:     further investigate `actor`; does Link call a callback
             function that is stored in it, for stringing multiple
             actions together?
 */
#define link_set_cutscene_action z_cutscene_link_action
extern void link_set_cutscene_action(
	z64_global_t    *global
	, z64_actor_t   *actor
	, uint8_t        action
);
	#if OOT_DEBUG
		asm("z_cutscene_link_action = 0x8002DF54");
	#elif OOT_U_1_0
		asm("z_cutscene_link_action = 0x800218EC");
	#endif

/**
 * Regarding DynaPoly Actor
 */
extern void external_func_8002DF90(z64_actor_t* dynapoly_actor);
	#if OOT_DEBUG
		asm("external_func_8002DF90 = 0x8002DF90");
	#elif OOT_U_1_0
		asm("external_func_8002DF90 = 0x80021928");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8002DFC8(z64_actor_t* actor, int16_t a1, z64_global_t* gl);
	#if OOT_DEBUG
		asm("external_func_8002DFC8 = 0x8002DFC8");
	#elif OOT_U_1_0
		asm("external_func_8002DFC8 = 0x80021968");
	#endif

/* Tests if the angle to face Link is within range (rot)
* Source Code Reference File: "z_actor.c"
* Formerly `actor_angle_link_in_range`
*/
extern float z_actor_player_in_range(
z64_actor_t* a /* Actor Instance to Reference */
, int16_t rot /* 16-bit Angle (range) */
);
#if OOT_DEBUG
  asm("z_actor_player_in_range = 0x8002E084");
#elif OOT_U_1_0
  asm("z_actor_player_in_range = 0x80021A28");
#elif MM_U_1_0
  /*asm("z_actor_player_in_range = 0xDEADBEEF");*/
#endif

/**
 * TODO This function is completely undocumented
 */
extern int32_t external_func_8002E12C(z64_actor_t* a, float a1, int16_t a2);
	#if OOT_DEBUG
		asm("external_func_8002E12C = 0x8002E12C");
	#elif OOT_U_1_0
		asm("external_func_8002E12C = 0x80021AD4");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8002E1A8(z64_actor_t* a, z64_actor_t* b, float a2, int16_t a3);
	#if OOT_DEBUG
		asm("external_func_8002E1A8 = 0x8002E1A8");
	#elif OOT_U_1_0
		asm("external_func_8002E1A8 = 0x80021B54");
	#endif

/* Primary Actor Collision Call (?)
* Required for a shadow to draw.
* Source Code Reference File: "z_actor.c"
* Formerly `actor_collision_routine`
*/
extern void z_actor_find_bounds(
z64_global_t* gl /* Global Context */
, z64_actor_t* a /* Actor to Reference */
, float below /* space below actor coordinates to test if ground is below actor */
, float radius /* radius for moving actor out of wall in case it is placed inside wall */
, float above /* space above actor coordinates to test if ceiling is above actor */
, uint32_t flags /* Type? */
);
#if OOT_DEBUG
  asm("z_actor_find_bounds = 0x8002E4B4");
#elif OOT_U_1_0
  asm("z_actor_find_bounds = 0x80021E6C");
#elif MM_U_1_0
  asm("z_actor_find_bounds = 0x800B78B8");
#endif

/**
 * Return Hilite*
 */
extern void * external_func_8002EABC(vec3f_t* object, vec3f_t* eye, vec3f_t* lightDir, z64_gfx_t* gfx_ctxt);
	#if OOT_DEBUG
		asm("external_func_8002EABC = 0x8002EABC");
	#elif OOT_U_1_0
		asm("external_func_8002EABC = 0x800223C8");
	#endif

/**
 * Return Hilite*
 */
extern void external_func_8002EB44(vec3f_t* object, vec3f_t* eye, vec3f_t* lightDir, z64_gfx_t* gfx_ctxt);
	#if OOT_DEBUG
		asm("external_func_8002EB44 = 0x8002EB44");
	#elif OOT_U_1_0
		asm("external_func_8002EB44 = 0x80022400");
	#endif

/**
 * Sets lighting angles for shiny things or something.
 * TODO These notes need converted into a C function prototype
 */
extern void z_actor_texgen_init(z64_actor_t *a0, z64_global_t *gl, int32_t flag);
	#if OOT_DEBUG
		asm("z_actor_texgen_init = 0x8002EBCC");
	#elif OOT_U_1_0
		asm("z_actor_texgen_init = 0x80022438");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8002ED80(z64_actor_t *a0, z64_global_t *gl, int32_t flag);
	#if OOT_DEBUG
		asm("external_func_8002ED80 = 0x8002ED80");
	#elif OOT_U_1_0
		asm("external_func_8002ED80 = 0x80022554");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void* external_func_8002EF14(void* PosRot, z64_actor_t* actor);
	#if OOT_DEBUG
		asm("external_func_8002EF14 = 0x8002EF14");
	#elif OOT_U_1_0
		asm("external_func_8002EF14 = 0x800226A4");
	#endif

/*
int32_t func_8002F194(z64_actor_t *a, z64_global_t *g)
{
	if ((a->flags & 0x0100) != 0)
	{
	 a->flags &= 0xFFFFFEFF;
	 return 1;
	}
	return 0;
}
 */
extern uint32_t external_func_8002F194(z64_actor_t *actor, z64_global_t *global);
	#if OOT_DEBUG
		asm("external_func_8002F194 = 0x8002F194");
	#elif OOT_U_1_0
		asm("external_func_8002F194 = 0x80022930");
	#endif

/**
 * Makes a cylinder-shaped region around the actor in which Link is able to speak to and trade with the actor.
 * A0 = Actor Instance | A1 = Global Context | A2 = float, xy distance | A3 = float, y distance | SP+0x10 = Trade Item Index
 */
#define actor_poll_trade_cylinder z_actor_poll_trade_cylinder
extern int32_t z_actor_poll_trade_cylinder(z64_actor_t *actor, z64_global_t *, float dist_xz, float dist_y, uint32_t item_index);
	#if OOT_DEBUG
		asm("z_actor_poll_trade_cylinder = 0x8002F1C4");
	#elif OOT_U_1_0
		asm("z_actor_poll_trade_cylinder = 0x80022960");
	#endif

/**
 * Makes a cube-shaped (or, more specifically, a regular-cylinder-shaped) region around the actor in which Link is able to speak to and trade with the actor (Wrapper for 8002F1C4)
 * Passes A2 into A2 and A3 of inner function
 * A0 = Actor Instance | A1 = Global Context | A2 = float, xyz distance | A3 = Trade Item Index
 */
#define actor_poll_trade_cube z_actor_poll_trade_cube
extern int32_t z_actor_poll_trade_cube(z64_actor_t *actor, z64_global_t *global, float distance, uint32_t item_index);
	#if OOT_DEBUG
		asm("z_actor_poll_trade_cube = 0x8002F298");
	#elif OOT_U_1_0
		asm("z_actor_poll_trade_cube = 0x80022A34");
	#endif

/**
 * Makes a cube-shaped (or, more specifically, a regular-cylinder-shaped) region around the actor in which Link is able to speak with the actor (Wrapper for 80022A34)
 * Calls wrapped function with A3 = 0
 * TODO These notes need converted into a C function prototype
 * A0 = Actor Instance | A1 = Global Context | A2 = float distance?
 */
#define actor_poll_speak_cube z_actor_poll_speak_cube
extern void z_actor_poll_speak_cube(z64_actor_t *actor, z64_global_t *gl, float distance);
	#if OOT_DEBUG
		asm("z_actor_poll_speak_cube = 0x8002F2CC");
	#elif OOT_U_1_0
		asm("z_actor_poll_speak_cube = 0x80022A68");
	#endif

/**
 * NPC Request Trade Item? | (Wrapper for 80022A68)
 * Calls wrapped function with A2 =(float) int16_t Inst. + 0x98 + 50.0f
 * TODO These notes need converted into a C function prototype
 * A0 = Actor Instance | A1 = Global Context
 */
extern void external_func_8002F2F4(z64_actor_t *actor, z64_global_t *global);
	#if OOT_DEBUG
		asm("external_func_8002F2F4 = 0x8002F2F4");
	#elif OOT_U_1_0
		asm("external_func_8002F2F4 = 0x80022A90");
	#elif MM_U_1_0
		asm("external_func_8002F2F4 = 0x800B863C");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8002F334(z64_actor_t* actor, z64_global_t* gl);
	#if OOT_DEBUG
		asm("external_func_8002F334 = 0x8002F334");
	#elif OOT_U_1_0
		asm("external_func_8002F334 = 0x80022AD0");
	#endif

/**
 * Get Trade Item Link is holding
 * TODO Look into this a bit more, return type
 * Returns Link Instance + 0x0683
 */
#define actor_npc_trade_get z_actor_player_trade_item_get
extern int32_t z_actor_player_trade_item_get(z64_global_t *global);
	#if OOT_DEBUG
		asm("z_actor_player_trade_item_get = 0x8002F368");
	#elif OOT_U_1_0
		asm("z_actor_player_trade_item_get = 0x80022B04");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8002F374(z64_global_t *global, z64_actor_t *actor, int16_t *unk0, int16_t *unk1);
	#if OOT_DEBUG
		asm("external_func_8002F374 = 0x8002F374");
	#elif OOT_U_1_0
		asm("external_func_8002F374 = 0x80022B14");
	#elif MM_U_1_0
		asm("external_func_8002F374 = 0x800B8898");
	#endif

/* Test if an actor->attached_a is present.
* Commonly used to test if an actor is held or has been picked up by the player.
* Source Code Reference File: "z_actor.c"
* Formerly `actor_is_held`
*/
extern int32_t z_actor_is_attached(
z64_actor_t* a /* Actor to Reference */
);
#if OOT_DEBUG
  asm("z_actor_is_attached = 0x8002F410");
#elif OOT_U_1_0
  asm("z_actor_is_attached = 0x80022BB0");
#elif MM_U_1_0
  asm("z_actor_is_attached = 0x800B89F8");
#endif

/**
 * Give Item
 * A0 = Actor instance //Actor giving item
 * A1 = Global Context
 * A2 = Get Item ID
 * A3 = float, max xz distance from actor to Link that item will be given
 * SP+10 = float, max y distance from actor to Link that item will be given
 */
extern void z_actor_give_item(
	z64_actor_t *actor,
	z64_global_t *global,
	uint32_t get_item_id,
	float range_xz, float range_y
);
	#if OOT_DEBUG
		asm("z_actor_give_item = 0x8002F434");
	#elif OOT_U_1_0
		asm("z_actor_give_item = 0x80022BD4");
	#elif MM_U_1_0
		asm("z_actor_give_item = 0x800B8A1C");
	#endif
#define actor_give_item z_actor_give_item

/* Give Item
* Wrapper for 8002F434
* XZ Range set to 50.0f
* Y Range set to 10.0f
* Source Code Reference File: "z_actor.c"
* Formerly `actor_give_item_50xz_10y`
*/
extern void z_actor_give_item_50_10(
z64_actor_t* a /* Actor to Reference */
, z64_global_t* gl /* Global Context */
, uint32_t id /* Get Item ID (See: https://wiki.cloudmodding.com/oot/Ovl_player_actor/Get_Items#Get_Item_Table)*/
);
#if OOT_DEBUG
  asm("z_actor_give_item_50_10 = 0x8002F554");
#elif OOT_U_1_0
  asm("z_actor_give_item_50_10 = 0x80022CF4");
#elif MM_U_1_0
  asm("z_actor_give_item_50_10 = 0x800B8B84");
#endif

/**
 * Give Item Wrapper (80022CF4) | Sets A2 to 0
 * TODO These notes need converted into a C function prototype
 * A0 = Actor Instance | A1 = Global Context
 */
/*wrapper for actor_give_item_50xz_10y, provides get_item_id*/
/*void z_actor_give_id_0(z64_actor_t *actor, z64_global_t *global)
{
   actor_give_item_50xz_10y(actor, global, 0);
}*/
extern void z_actor_give_id_0(z64_actor_t *actor, z64_global_t *global);
	#if OOT_DEBUG
		asm("z_actor_give_id_0 = 0x8002F580");
	#elif OOT_U_1_0
		asm("z_actor_give_id_0 = 0x80022D20");
	#endif

/**
 * Same function as 8002F410?
 */
extern int32_t z_actor_is_attached2(z64_actor_t* a);
	#if OOT_DEBUG
		asm("z_actor_is_attached2 = 0x8002F5A0");
	#elif OOT_U_1_0
		asm("z_actor_is_attached2 = 0x80022D40");
	#endif

/**
 * Confirm Usage
 */
extern void external_func_8002F5C4(z64_player_t* Link, z64_actor_t* a);
	#if OOT_DEBUG
		asm("external_func_8002F5C4 = 0x8002F5C4");
	#elif OOT_U_1_0
		asm("external_func_8002F5C4 = 0x80022D64");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8002F5F0(z64_actor_t* actor, z64_global_t* gl);
	#if OOT_DEBUG
		asm("external_func_8002F5F0 = 0x8002F5F0");
	#elif OOT_U_1_0
		asm("external_func_8002F5F0 = 0x80022D94");
	#endif

/**
 * return (a->attached_b != 0x0)
 */
extern int32_t external_func_8002F618(z64_global_t* gl, z64_actor_t* a);
	#if OOT_DEBUG
		asm("external_func_8002F618 = 0x8002F618");
	#elif OOT_U_1_0
		asm("external_func_8002F618 = 0x80022DBC");
	#endif

/**
 * Check if Link is Riding Epona?
 */
extern int32_t external_func_8002F63C(z64_global_t* gl, z64_actor_t* a, int32_t a2);
	#if OOT_DEBUG
		asm("external_func_8002F63C = 0x8002F63C");
	#elif OOT_U_1_0
		asm("external_func_8002F63C = 0x80022DE0");
	#endif

/**
 * return (a->attached_b == 0x0)
 */
extern int32_t external_func_8002F674(z64_global_t* gl, z64_actor_t* a);
	#if OOT_DEBUG
		asm("external_func_8002F674 = 0x8002F674");
	#elif OOT_U_1_0
		asm("external_func_8002F674 = 0x80022E18");
	#endif

/**
 * z_player_
 * TODO Find usage context.
 */
extern void external_func_8002F698(z64_global_t* gl, uint32_t a1, float a2, int16_t a3, float a4, uint32_t a5, uint32_t a6);
	#if OOT_DEBUG
		asm("external_func_8002F698 = 0x8002F698");
	#elif OOT_U_1_0
		asm("external_func_8002F698 = 0x80022E3C");
	#endif

/**
 * Wrapper for 8002F698 (Above)
 */
extern void external_func_8002F6D4(z64_global_t* gl, uint32_t a1, float a2, int16_t a3, float a4, uint32_t a5);
	#if OOT_DEBUG
		asm("external_func_8002F6D4 = 0x8002F6D4");
	#elif OOT_U_1_0
		asm("external_func_8002F6D4 = 0x80022E7C");
	#elif MM_U_1_0
		asm("external_func_8002F6D4 = 0x800B8D50");
	#endif

/* Knocks the player back a certain distance and height in the specified direction.
 * Used in the original game by the moblin pounds.
 * Wrapper for 8002F6D4 (Above)
*/
extern void z_player_knockback(z64_global_t *gl, z64_actor_t* a, float distance, int16_t direction, float height);
	#if OOT_DEBUG
		asm("z_player_knockback = 0x8002F71C");
	#elif OOT_U_1_0
		asm("z_player_knockback = 0x80022EC4");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8002F758(z64_global_t *gl, void *gl830, float a, float b, float *c, void *unk);
	#if OOT_DEBUG
		asm("external_func_8002F758 = 0x8002F758");
	#elif OOT_U_1_0
		asm("external_func_8002F758 = 0x80022F00");
	#elif MM_U_1_0
		asm("external_func_8002F6D4 = 0x800CA1E8");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8002F7A0(z64_global_t* gl, uint32_t a1, float a2, int16_t a3, float a4);
	#if OOT_DEBUG
		asm("external_func_8002F7A0 = 0x8002F7A0");
	#elif OOT_U_1_0
		asm("external_func_8002F7A0 = 0x80022F48");
	#elif MM_U_1_0
		asm("external_func_8002F7A0 = 0x800B8E1C");
	#endif

/**
 * Play Sound Effect (Actor)
 */
#define Audio_PlayActorSound2 z_actor_play_sfx
#define sound_play_actor z_actor_play_sfx
extern void z_actor_play_sfx(z64_actor_t *actor, uint16_t sound_id);
	#if OOT_DEBUG
		asm("z_actor_play_sfx = 0x8002F7DC");
	#elif OOT_U_1_0
		asm("z_actor_play_sfx = 0x80022F84");
	#endif

/* Play a sound effect.
* Wrapper for 80078914 (a wrapper for sound_play_system)
* References `actor->unk_0xE4`; Likely a position vector to place the sound origin.
* Source Code Reference File: "z_actor.c"
*/
extern void z_actor_play_sfx2(
z64_actor_t* a /* Actor to derive position */
, uint16_t sfx /* Sound Effect ID (See: https://wiki.cloudmodding.com/oot/Sound_Effect_Ids)*/
);
#if OOT_DEBUG
  asm("z_actor_play_sfx2 = 0x8002F828");
#elif OOT_U_1_0
  asm("z_actor_play_sfx2 = 0x80022FD0");
#elif MM_U_1_0
  asm("z_actor_play_sfx2 = 0x800B8EC8");
#endif

/**
 * Plays a sound effect based on `actor->bgcheck_flags`
 * TODO: Document Stuff
 */
extern void external_func_8002F850(z64_global_t* gl, z64_actor_t* a);
	#if OOT_DEBUG
		asm("external_func_8002F850 = 0x8002F850");
	#elif OOT_U_1_0
		asm("external_func_8002F850 = 0x80022FFC");
	#endif

	/**
	 * Play Sound Effect (Actor)
	 * TODO There are three identical functions... distinguish the difference and fix names
	 */
extern void sound_play_actor3(z64_actor_t *actor, uint16_t sound_id);
	#if OOT_DEBUG
		asm("sound_play_actor3 = 0x8002F8F0");
	#elif OOT_U_1_0
		asm("sound_play_actor3 = 0x800230A0");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8002F948(z64_actor_t *actor, uint16_t sound_id);
	#if OOT_DEBUG
		asm("external_func_8002F948 = 0x8002F948");
	#elif OOT_U_1_0
		asm("external_func_8002F948 = 0x80023108");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void z_actor_play_sfx_flag(z64_actor_t *actor, uint16_t sound_id);
	#if OOT_DEBUG
		asm("z_actor_play_sfx_flag = 0x8002F974");
	#elif OOT_U_1_0
		asm("z_actor_play_sfx_flag = 0x8002313C");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8002F994(z64_actor_t *actor, uint16_t sound_id);
	#if OOT_DEBUG
		asm("external_func_8002F994 = 0x8002F994");
	#elif OOT_U_1_0
		asm("external_func_8002F994 = 0x80023164");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8002F9EC(z64_global_t* gl, z64_actor_t* a, void* a2, void* a3, void* a4);
	#if OOT_DEBUG
		asm("external_func_8002F9EC = 0x8002F9EC");
	#elif OOT_U_1_0
		asm("external_func_8002F9EC = 0x800231BC");
	#endif

/**
 * Possibly tests if actor should be drawn
 * TODO Confirm whether this is a draw distance thing
 * TODO Also do something with a2 and a3, how does this translate to C?
 * A0 = Global Context | A1 = actor instance | A2 = actor instance + 0xE4 | A3 = float at actor instance + 0xF0
 */
#define actor_set_draw_distance z_actor_set_draw_distance
extern void z_actor_set_draw_distance(z64_global_t *global, z64_actor_t *actor, void *a2 /*actor+0xE4*/, float *a3 /*actor+0xF0*/);
	#if OOT_DEBUG
		asm("z_actor_set_draw_distance = 0x800314D4");
	#elif OOT_U_1_0
		asm("z_actor_set_draw_distance = 0x800249DC");
	#endif

/* Spawn an actor. Returns a pointer to the spawned actor, or NULL if it fails.
* Source Code Reference File: "z_actor.c"
* Formerly `actor_spawn`
*/
#define Actor_Spawn z_actor_spawn
extern z64_actor_t* z_actor_spawn(
z64_actor_context_t* actor_ctxt /* Actor Context within Global Context */
, z64_global_t *gl /* Global Context */
, int16_t id /* Actor ID */
, float x, float y, float z /* X, Y, and Z Position */
, int16_t xr, int16_t yr, int16_t zr /* X, Y, and Z Rotation */
, uint16_t variable /* Actor Variable */
);
#if OOT_DEBUG
  asm("z_actor_spawn = 0x80031F50");
#elif OOT_U_1_0
  asm("z_actor_spawn = 0x80025110");
#elif MM_U_1_0
  asm("z_actor_spawn = 0x800BAE14");
#endif

#define Actor_SpawnAttached z_actor_spawn_attached
/* Spawn an actor and attach it to `host`. Returns a pointer to the spawned actor, or NULL if it fails.
* return->attached_a will be set to `id`.
* host->attached_b will be set to the return value.
* The spawned actor will be bound to the host actor's room unless the room is -1. (0xFF)
* Source Code Reference File: "z_actor.c"
* Formerly `actor_spawn_attached`
*/
extern z64_actor_t* z_actor_spawn_attached(
z64_actor_context_t* actor_ctxt /* Actor Context within Global Context */
, z64_actor_t* host /* Actor to Attach To */
, z64_global_t *gl /* Global Context */
, int16_t id /* Actor ID */
, float x, float y, float z /* X, Y, and Z Position */
, int16_t xr, int16_t yr, int16_t zr /* X, Y, and Z Rotation */
, uint16_t variable /* Actor Variable */
);
#if OOT_DEBUG
  asm("z_actor_spawn_attached = 0x80032458");
#elif OOT_U_1_0
  asm("z_actor_spawn_attached = 0x800253F0");
#elif MM_U_1_0
  /*asm("z_actor_spawn_attached = 0xDEADBEEF");*/
#endif

/**
 * TODO This function is completely undocumented
 */
#define Actor_Find z_actor_find
extern void z_actor_find(z64_actor_context_t* ctxt, int32_t id, int32_t type);
	#if OOT_DEBUG
		asm("z_actor_find = 0x80032C3C");
	#elif OOT_U_1_0
		asm("z_actor_find = 0x80025B0C");
	#endif

/* Plays `NA_SE_EN_LAST_DAMAGE` at actor position.
* Source Code Reference File: "z_actor.c"
*/
extern void z_actor_play_sound_defeated(
z64_global_t* gl /* Global Context */
, z64_actor_t *a /* Actor to derive position */
);
#if OOT_DEBUG
  asm("z_actor_play_sound_defeated = 0x80032C7C");
#elif OOT_U_1_0
  asm("z_actor_play_sound_defeated = 0x80025B4C");
#elif MM_U_1_0
  asm("z_actor_play_sound_defeated = 0x800BBA88");
#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_80032E24(void* a0, int32_t a1, z64_global_t* gl);
	#if OOT_DEBUG
		asm("external_func_80032E24 = 0x80032E24");
	#elif OOT_U_1_0
		asm("external_func_80032E24 = 0x80025D04");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_80032F54(int32_t *a0, uint8_t limb, int32_t a2, int32_t a3, int32_t a4, uint32_t dlist, int32_t a6);
	#if OOT_DEBUG
		asm("external_func_80032F54 = 0x80032F54");
	#elif OOT_U_1_0
		asm("external_func_80032F54 = 0x80025DFC");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8003305C(void);
	#if OOT_DEBUG
		asm("external_func_8003305C = 0x8003305C");
	#elif OOT_U_1_0
		asm("external_func_8003305C = 0x80025F04");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_80033260(void);
	#if OOT_DEBUG
		asm("external_func_80033260 = 0x80033260");
	#elif OOT_U_1_0
		asm("external_func_80033260 = 0x800260E8");
	#endif

/**
 * TODO Document arguments more thoroughly. Current arguments are Nokaubure's findings.
 * Spawns various dust particles.
 */
extern void external_func_80033480(
	z64_global_t *global,
	vec3f_t *pos,
	float radius,
	int32_t particle_count,
	int16_t scale_a,
	int16_t scale_b,
	int8_t type
	);
	#if OOT_DEBUG
		asm("external_func_80033480 = 0x80033480");
	#elif OOT_U_1_0
		asm("external_func_80033480 = 0x80026308");
	#endif

/**
 * Collision, Test if entity is being bombed
 * TODO confirm whether "actor collision struct" means the capsule structure, or something else
 * A0 = Global Context | A1 = Actor Collision Struct | V0 = Null or Pointer to Explosive-type actor that collided
 */
#define actor_is_bombed z_actor_test_explosive
extern z64_actor_t* z_actor_test_explosive(z64_global_t *global, z64_collider_t* col);
	#if OOT_DEBUG
		asm("z_actor_test_explosive = 0x80033640");
	#elif OOT_U_1_0
		asm("z_actor_test_explosive = 0x800264C8");
	#endif

/**
 * Unknown, collision detection related
 * TODO These notes need converted into a C function prototype
 * a0 = global context | a1 = actor instance | v0 = unknown
 */
extern int32_t z_find_explosive(z64_global_t *global, void *explosive);
	#if OOT_DEBUG
		asm("z_find_explosive = 0x80033684");
	#elif OOT_U_1_0
		asm("z_find_explosive = 0x8002650C");
	#endif

/* Change Actor Type
* Source Code Reference File: "z_actor.c"
*/
#define Actor_ChangeType z_actor_type_change
extern void z_actor_type_change(
z64_global_t* gl /* Global Context */
, void* actor_ctxt /* Actor Context within Global Context */
, z64_actor_t* a /* Actor To Modify */
, uint8_t type /* Type to Change To */
);
#if OOT_DEBUG
  asm("z_actor_type_change = 0x80033748");
#elif OOT_U_1_0
  asm("z_actor_type_change = 0x800265D4");
#elif MM_U_1_0
  /*asm("z_actor_type_change = 0xDEADBEEF");*/
#endif

/**
 * Checking for hookshot or arrow.
 */
extern z64_actor_t* external_func_80033780(z64_global_t* gl, z64_actor_t* a, float a2);
	#if OOT_DEBUG
		asm("external_func_80033780 = 0x80033780");
	#elif OOT_U_1_0
		asm("external_func_80033780 = 0x80026614");
	#endif

/**
 * Set an actor's text prefix based on the current scene index.
 */
#define Actor_SetTextWithPrefix z_actor_set_text_scene
extern void z_actor_set_text_scene(z64_global_t* gl, z64_actor_t* actor, int16_t text_id);
	#if OOT_DEBUG
		asm("z_actor_set_text_scene = 0x80033940");
	#elif OOT_U_1_0
		asm("z_actor_set_text_scene = 0x800267D4");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern int16_t external_func_800339B8(z64_actor_t* actor, z64_global_t* gl, float a2, int16_t a3);
	#if OOT_DEBUG
		asm("external_func_800339B8 = 0x800339B8");
	#elif OOT_U_1_0
		asm("external_func_800339B8 = 0x80026850");
	#endif

/**
 * ? Same code as 80026950
 * TODO These notes need converted into a C function prototype
 * A0 = Global Context | A1 = ?
 */
extern int32_t external_func_80033A84(z64_global_t* gl, z64_actor_t* a);
	#if OOT_DEBUG
		asm("external_func_80033A84 = 0x80033A84");
	#elif OOT_U_1_0
		asm("external_func_80033A84 = 0x8002691C");
	#endif

/**
 * ? Same code as 8002691C
 * TODO These notes need converted into a C function prototype
 * A0 = Global Context | A1 = ?
 */
extern int32_t external_func_80033AB8(z64_global_t* gl, z64_actor_t* a);
	#if OOT_DEBUG
		asm("external_func_80033AB8 = 0x80033AB8");
	#elif OOT_U_1_0
		asm("external_func_80033AB8 = 0x80026950");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern float external_func_80033AEC(vec3f_t* a0, vec3f_t* a1, float a2, float a3, float a4, float a5);
	#if OOT_DEBUG
		asm("external_func_80033AEC = 0x80033AEC");
	#elif OOT_U_1_0
		asm("external_func_80033AEC = 0x80026984");
	#endif

/* Draw a circular shadow provided vec3f_t types.
* Source Code Reference File: "z_actor.c"
* Formerly `actor_shadow_circle`
*/
extern void z_actor_shadow_draw_vec3f(
vec3f_t* pos /* X, Y, and Z Position */
, vec3f_t* scale /* X, Y, and Z Scale */
, uint32_t opacity /* Shadow Opacity */
, z64_global_t* gl /* Global Context */
);
#if OOT_DEBUG
  asm("z_actor_shadow_draw_vec3f = 0x80033C30");
#elif OOT_U_1_0
  asm("z_actor_shadow_draw_vec3f = 0x80026AD0");
#elif MM_U_1_0
  /*asm("z_actor_shadow_draw_vec3f = 0xDEADBEEF");*/
#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_80033DB8(z64_global_t* gl, int16_t a1, int16_t a2);
	#if OOT_DEBUG
		asm("external_func_80033DB8 = 0x80033DB8");
	#elif OOT_U_1_0
		asm("external_func_80033DB8 = 0x80026C1C");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_80033E1C(z64_global_t* gl, int16_t a1, int16_t a2, int16_t a3);
	#if OOT_DEBUG
		asm("external_func_80033E1C = 0x80033E1C");
	#elif OOT_U_1_0
		asm("external_func_80033E1C = 0x80026C84");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_80033E88(z64_actor_t* actor, z64_global_t* gl, int16_t a2, int16_t a3);
	#if OOT_DEBUG
		asm("external_func_80033E88 = 0x80033E88");
	#elif OOT_U_1_0
		asm("external_func_80033E88 = 0x80026CF4");
	#endif

/**
 * Generates a random floating point in the range [0, n) (0 to n exclusive)
 */
#define Math_Rand_ZeroFloat z_math_frand
extern float z_math_frand(float n);
	#if OOT_DEBUG
		asm("z_math_frand = 0x80033EF8");
	#elif OOT_U_1_0
		asm("z_math_frand= 0x80026D64");
	#elif MM_U_1_0
		asm("z_math_frand = 0x80179594");
	#endif

/**
 * Multiplies a random floating point by a number in the range [-0.5, 0.5)
 */
#define Math_Rand_CenteredFloat z_math_frand_center
extern float z_math_frand_center(float n);
	#if OOT_DEBUG
		asm("z_math_frand_center = 0x80033F20");
	#elif OOT_U_1_0
		asm("z_math_frand_center = 0x80026D90");
	#elif MM_U_1_0
		asm("z_math_frand_center = 0x801795C0");
	#endif

/**
 * TODO This function is completely undocumented
 * Refernce Source File: "z_actor.c"
 */
extern void external_func_80033F54(z64_global_t* gl, int32_t a1, int32_t a2);
	#if OOT_DEBUG
		asm("external_func_80033F54 = 0x80033F54");
	#elif OOT_U_1_0
		asm("external_func_80033F54 = 0x80026DC8");
	#endif

/**
 * Wrapper for 80062D60
 * TODO These notes need converted into a C function prototype
 */
extern void external_func_8003424C(z64_global_t* gl, vec3f_t* arg1);
	#if OOT_DEBUG
		asm("external_func_8003424C = 0x8003424C");
	#elif OOT_U_1_0
		asm("external_func_8003424C = 0x80027070");
	#endif

/* Modify Actor Damage Color
* Commonly used to turn an actor blue when stunned.
* Plays `NA_SE_EN_LIGHT_ARROW_HIT` if a2 is within a certain range. (180 degrees?)
* Source Code Reference File: "z_actor.c"
*/
extern void z_actor_damage_color(
z64_actor_t* a /* Actor to Modify */
, int16_t a1
, int16_t a2
, int16_t a3
, int16_t timer /* Timer in Frames; How long the actor is a particular color */
);
#if OOT_DEBUG
  asm("z_actor_damage_color = 0x8003426C");
#elif OOT_U_1_0
  asm("z_actor_damage_color = 0x80027090");
#elif MM_U_1_0
  asm("z_actor_damage_color = 0x800BCB70");
#elif MM_J_1_0
  asm("z_actor_damage_color = 0x800BE6E8");
#elif MM_DEBUG
  asm("z_actor_damage_color = 0x800D1508");
#endif

/**
 * TODO This function is completely undocumented
 * Return a Hilite*
 */
extern void external_func_8003435C(vec3f_t* object, z64_global_t* gl);
	#if OOT_DEBUG
		asm("external_func_8003435C = 0x8003435C");
	#elif OOT_U_1_0
		asm("external_func_8003435C = 0x80027188");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern int32_t external_func_800343CC(z64_global_t* gl, z64_actor_t* a, int16_t* a2, uint16_t (*unkFunc1)(z64_global_t*, z64_actor_t*), int16_t (*unk_Func2)(z64_global_t*, z64_actor_t*));
#if OOT_DEBUG
	asm("external_func_800343CC = 0x800343CC");
#elif OOT_U_1_0
	asm("external_func_800343CC = 0x800271FC");
#endif

/**
 * TODO These notes need converted into a C function prototype
 */
extern int16_t external_func_800347E8(int16_t a0);
	#if OOT_DEBUG
		asm("external_func_800347E8 = 0x800347E8");
	#elif OOT_U_1_0
		asm("external_func_800347E8 = 0x80027620");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_80034A14(z64_actor_t* actor, void* a1, int16_t a2, int16_t a3);
	#if OOT_DEBUG
		asm("external_func_80034A14 = 0x80034A14");
	#elif OOT_U_1_0
		asm("external_func_80034A14 = 0x80027854");
	#endif

/**
	* Draw Matrix-Enabled Object with an alpha attribute.
	* Source code reference: "z_actor.c"
	* Wrapper for SkelAnime_DrawSV2
	* Draws to poly_opa
 */
#define z_skl_mtx_opa_alpha z_skelanime_draw_mtx_alpha_opa
extern void z_skelanime_draw_mtx_alpha_opa(z64_global_t *global, z64_skelanime_t *skelanime, void *internal0, void *internal1, z64_actor_t *actor, int16_t opacity);
	#if OOT_DEBUG
		asm("z_skelanime_draw_mtx_alpha_opa = 0x80034BA0");
	#elif OOT_U_1_0
		asm("z_skelanime_draw_mtx_alpha_opa = 0x800279CC");
	#endif

/**
	* Draw Matrix-Enabled Object with an alpha attribute.
	* Source code reference: "z_actor.c"
	* Wrapper for SkelAnime_DrawSV2
	* Draws to poly_xlu
 */
#define z_skl_mtx_xlu_alpha z_skelanime_draw_mtx_alpha_opa
extern void z_skelanime_draw_mtx_alpha_xlu(z64_global_t *global, z64_skelanime_t *skelanime, void *internal0, void *internal1, z64_actor_t *actor, int16_t opacity);
	#if OOT_DEBUG
		asm("z_skelanime_draw_mtx_alpha_xlu = 0x80034CC4");
	#elif OOT_U_1_0
		asm("z_skelanime_draw_mtx_alpha_xlu = 0x80027AC4");
	#endif

/**
 * TODO This function is completely undocumented
 * Cutscene Related
 */
extern float external_func_80034DD4(z64_actor_t* actor, z64_global_t* gl, float a2, float a3);
	#if OOT_DEBUG
		asm("external_func_80034DD4 = 0x80034DD4");
	#elif OOT_U_1_0
		asm("external_func_80034DD4 = 0x80027BA8");
	#endif

/**
 * TODO This function is completely undocumented
 * An animation changing wrapper.
 */
extern void external_func_80034EC0(z64_skelanime_t* skl, void* a1, int32_t a2);
	#if OOT_DEBUG
		asm("external_func_80034EC0 = 0x80034EC0");
	#elif OOT_U_1_0
		asm("external_func_80034EC0 = 0x80027C98");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_80034F54(z64_global_t* gl, int16_t* a1, int16_t* a2, int32_t a3);
	#if OOT_DEBUG
		asm("external_func_80034F54 = 0x80034F54");
	#elif OOT_U_1_0
		asm("external_func_80034F54 = 0x80027D30");
	#endif

/* Draws a display list to "poly_opa".
* Source Code Reference File: "z_cheap_proc.c"
* Formerly `draw_dlist_opa`
*/
#define z_draw_dlist_opa z_cheap_proc_draw_opa //#SHORTNAME
#define Gfx_DrawDListOpa z_cheap_proc_draw_opa
extern void z_cheap_proc_draw_opa(
z64_global_t* gl /* Global Context */
, uint32_t dl /* A segment-relative display list address. (i.e. 0x06021F78)*/
);
#if OOT_DEBUG
	asm("z_cheap_proc_draw_opa = 0x80035260");
#elif OOT_U_1_0
	asm("z_cheap_proc_draw_opa = 0x80028048");
#elif MM_U_1_0
	asm("z_cheap_proc_draw_opa = 0x800BDFC0");
#endif

/* Draws a display list to "poly_xlu".
* Source Code Reference File: "z_cheap_proc.c"
* Formerly `draw_dlist_xlu`
*/
#define z_draw_dlist_xlu z_cheap_proc_draw_xlu //#SHORTNAME
#define Gfx_DrawDListXlu z_cheap_proc_draw_xlu
extern void z_cheap_proc_draw_xlu(
z64_global_t* gl /* Global Context */
, uint32_t dl /* A segment-relative display list address. (i.e. 0x06021F78)*/
);
#if OOT_DEBUG
	asm("z_cheap_proc_draw_xlu = 0x80035324");
#elif OOT_U_1_0
	asm("z_cheap_proc_draw_xlu = 0x800280C8");
#elif MM_U_1_0
	asm("z_cheap_proc_draw_xlu = 0x800BE03C");
#endif

/**
 * Finds the closest actor instance of a specified id and type within specified range.
 * a0 - global context | a1 - actor instance | a2 - actor id (-1 = any) | a3 - category | 0x10($sp) distance from actor"
 */
#define find_closest_actor_instance_within_range z_actor_detect_nearest
#define Actor_FindNearby z_actor_detect_nearest
extern z64_actor_t* z_actor_detect_nearest(z64_global_t *global, z64_actor_t *actor, int16_t actor_id, z64_actor_type_t type, float range);
	#if OOT_DEBUG
		asm("z_actor_detect_nearest = 0x800353F4");
	#elif OOT_U_1_0
		asm("z_actor_detect_nearest = 0x80028158");
	#endif

/**
 * Checks if link is at certain distance, and if link is attacking, doesn't check jumpslashes
 * TODO These notes need converted into a C function prototype
 * a0 - global context | a1 - actor instance | a2 - float value | a3 - ???? | 0x10($sp) - rotation value? | 0x14($sp) - rotation value 0xB6(s0)? | v0 - returns true/false
 */
extern int32_t external_func_800354B4(z64_global_t* gl, z64_actor_t *actor, float range, int16_t a3, int16_t a4, int16_t a5);
	#if OOT_DEBUG
		asm("external_func_800354B4 = 0x800354B4");
	#elif OOT_U_1_0
		asm("external_func_800354B4 = 0x8002821C");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8003555C(z64_global_t* gl, vec3f_t* a1, vec3f_t* a2, vec3f_t* a3);
	#if OOT_DEBUG
		asm("external_func_8003555C = 0x8003555C");
	#elif OOT_U_1_0
		asm("external_func_8003555C = 0x800282C4");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800355B8(z64_global_t* gl, vec3f_t* a1);
	#if OOT_DEBUG
		asm("external_func_800355B8 = 0x800355B8");
	#elif OOT_U_1_0
		asm("external_func_800355B8 = 0x80028320");
	#endif

/**
 * TODO This function is completely undocumented
 * Change Link->sword_anim_index to 0x16
 */
extern uint8_t external_func_800355E4(z64_global_t* gl, z64_collider_t* collider);
	#if OOT_DEBUG
		asm("external_func_800355E4 = 0x800355E4");
	#elif OOT_U_1_0
		asm("external_func_800355E4 = 0x8002834C");
	#endif

/* Apply damage to an actor's health.
* Source Code Reference File: "z_actor.c"
*/
#define Actor_ApplyDamage z_actor_update_health
extern uint8_t z_actor_update_health(
z64_actor_t* a /* Actor to be damaged. */
);
#if OOT_DEBUG
  asm("z_actor_update_health = 0x80035628");
#elif OOT_U_1_0
  asm("z_actor_update_health = 0x80028390");
#elif MM_U_1_0
  asm("z_actor_update_health = 0x800BE22C");
#endif

/* Collision Related
* Source Code Reference File: "z_actor.c"
*/
extern void z_actor_is_frozen(
z64_actor_t* a
, z64_collider_body_t* collider
, int32_t is_frozen
);
#if OOT_DEBUG
  asm("z_actor_is_frozen = 0x80035650");
#elif OOT_U_1_0
  asm("z_actor_is_frozen = 0x800283BC");
#elif MM_U_1_0
  /*asm("z_actor_is_frozen = 0xDEADBEEF");*/
#endif

/* Collision Collection Related
* Source Code Reference File: "z_actor.c"
*/
extern void z_actor_is_frozen_jntsphs(
z64_actor_t* a
, void*  jntsphs
, int32_t is_frozen
);
#if OOT_DEBUG
  asm("z_actor_is_frozen_jntsphs = 0x8003573C");
#elif OOT_U_1_0
  asm("z_actor_is_frozen_jntsphs = 0x800284A8");
#elif MM_U_1_0
  /*asm("z_actor_is_frozen_jntsphs = 0xDEADBEEF");*/
#endif

/**
 * TODO
 * Used in `En_Dha` to rotate the hand to be flat on Link's head.
 */
extern void z_actor_func_80035844(vec3f_t* a0, vec3f_t* a1, int16_t* a2, int32_t a3);
	#if OOT_DEBUG
		asm("z_actor_func_80035844 = 0x80035844");
	#elif OOT_U_1_0
		asm("z_actor_func_80035844 = 0x800285B0");
	#endif

/**
 * Spawn En_Part (Dissipating Flames).
 */
extern void external_func_800358DC(z64_actor_t* host, vec3f_t* pos, vec3s_t* rot, float* physics, int16_t a, int32_t b, z64_global_t* gl, int16_t variable, int32_t c);
	#if OOT_DEBUG
		asm("external_func_800358DC = 0x800358DC");
	#elif OOT_U_1_0
		asm("external_func_800358DC = 0x80028644");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800359B8(z64_actor_t* actor, int16_t a1, vec3s_t* a2);
	#if OOT_DEBUG
		asm("external_func_800359B8 = 0x800359B8");
	#elif OOT_U_1_0
		asm("external_func_800359B8 = 0x80028720");
	#endif

/**
 * Tests if event_chk_inf flag is set
 */
#define Flags_GetEventChkInf z_flags_event_get
#define flag_get_event_chk_inf z_flags_event_get
extern int32_t z_flags_event_get(int32_t flag);
	#if OOT_DEBUG
		asm("z_flags_event_get = 0x80035B4C");
	#elif OOT_U_1_0
		asm("z_flags_event_get = 0x800288B4");
	#endif

/**
 * Sets event_chk_inf flag to 1
 */
#define Flags_SetEventChkInf z_flags_event_set
#define flag_set_event_chk_inf z_flags_event_set
extern void z_flags_event_set(int32_t flag);
	#if OOT_DEBUG
		asm("z_flags_event_set = 0x80035B74");
	#elif OOT_U_1_0
		asm("z_flags_event_set = 0x800288E0");
	#endif

/**
 * Tests if inf_table flag is set
 */
#define Flags_GetInfTable z_flags_inf_table_get
#define flag_get_inf_table z_flags_inf_table_get
extern int32_t z_flags_inf_table_get(int32_t flag);
	#if OOT_DEBUG
		asm("z_flags_inf_table_get= 0x80035BA4");
	#elif OOT_U_1_0
		asm("z_flags_inf_table_get = 0x80028914");
	#endif

/**
 * Sets inf_table flag to 1
 */
#define Flags_SetInfTable z_flags_inf_table_set
#define flag_set_inf_table z_flags_inf_table_set
extern void z_flags_inf_table_set(int32_t flag);
	#if OOT_DEBUG
		asm("z_flags_inf_table_set = 0x80035BCC");
	#elif OOT_U_1_0
		asm("z_flags_inf_table_set = 0x80028940");
	#endif

/**
 * Generic NPC Text Handler 7
 * TODO These notes need converted into a C function prototype
 * a0 - global context | a1 - 0xF (?) | v0 - (?)
 */
extern void external_func_80037C30(z64_global_t* gl, int16_t a1);
	#if OOT_DEBUG
		asm("external_func_80037C30 = 0x80037C30");
	#elif OOT_U_1_0
		asm("external_func_80037C30 = 0x8002A9AC");
	#endif

/**
 * Enables speak command, use in update
 * TODO These notes need converted into a C function prototype
 * a0 - global context  |  a1 - actor instance  | a2 - 0xF (??? related to what message to display)  | a3 - actor instance + 0x01A0 (not sure what this points to...)
 */
extern void external_func_80037D98(z64_global_t* gl, z64_actor_t* a, int16_t a2, int32_t* a3);
	#if OOT_DEBUG
		asm("external_func_80037D98 = 0x80037D98");
	#elif OOT_U_1_0
		asm("external_func_80037D98 = 0x8002AB20");
	#endif

/**
 * Return rotation vectors towards a specific focus point.
 * Cutscene and camera focus related.
 */
extern void z_actor_vector_focus(z64_global_t* gl, z64_actor_t* a, vec3s_t* a2, vec3s_t* a3, vec3f_t a4);
	#if OOT_DEBUG
		asm("z_actor_vector_focus = 0x80038290");
	#elif OOT_U_1_0
		asm("z_actor_vector_focus = 0x8002B024");
	#endif

/* Initialize a matrix for a collision polytype (?)
* Source Code Reference File: "z_bgcheck.c"
*/
extern void z_bg_poly_mtxf_init(
z64_col_poly_t* poly /* Collision Poly */
, vec3f_t* x, vec3f_t* y, vec3f_t* z /* X, Y, and Z Translation */
, float* mf /* Float Matrix */
);
#if OOT_DEBUG
  asm("z_bg_poly_mtxf_init = 0x80038A28");
#elif OOT_U_1_0
  asm("z_bg_poly_mtxf_init = 0x8002B668");
#elif MM_U_1_0
  /*asm("z_bg_poly_mtxf_init = 0xDEADBEEF");*/
#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8003C890(void);
	#if OOT_DEBUG
		asm("external_func_8003C890 = 0x8003C890");
	#elif OOT_U_1_0
		asm("external_func_8003C890 = 0x8002F3A4");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern float external_func_8003C940(void *col_ctxt, void *floorpoly, void *unk_sp2C, z64_actor_t *actor, vec3f_t *pos);
	#if OOT_DEBUG
		asm("external_func_8003C940 = 0x8003C940");
	#elif OOT_U_1_0
		asm("external_func_8003C940 = 0x8002F454");
	#elif MM_U_1_0
		asm("external_func_8003C940 = 0x800C411C");
	#endif

/**
 * raycast
 * returns a Y location of where to place actor on success, otherwise RAYCAST_FAIL (-32000.0f)
 * use RAYCAST_SUCCESS(result) to validate whether successful
 * Not inherently a mathematical raycast, but is used for something similar.
 */
#define math_raycast z_bgcheck_raycast
extern float z_bgcheck_raycast(z64_col_ctxt_t* col_ctxt, void *unk0, void *unk1, z64_actor_t *actor, vec3f_t *pos);
	#if OOT_DEBUG
		#define RAYCAST_FAIL -32000.0f
		asm("z_bgcheck_raycast = 0x8003C9A4");
	#elif OOT_U_1_0
		#define RAYCAST_FAIL -32000.0f
		asm("z_bgcheck_raycast = 0x8002F4B8");
	#endif
	#define RAYCAST_SUCCESS(RAYCAST_RESULT) ( RAYCAST_RESULT > RAYCAST_FAIL )

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8003CA0C(z64_global_t* gl, z64_col_ctxt_t* col_ctxt, void** poly, uint32_t* a, z64_actor_t* actor, vec3f_t* b);
	#if OOT_DEBUG
		asm("external_func_8003CA0C = 0x8003CA0C");
	#elif OOT_U_1_0
		asm("external_func_8003CA0C = 0x8002F520");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8003CA64(void);
	#if OOT_DEBUG
		asm("external_func_8003CA64 = 0x8003CA64");
	#elif OOT_U_1_0
		asm("external_func_8003CA64 = 0x8002F578");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8003D464(void);
	#if OOT_DEBUG
		asm("external_func_8003D464 = 0x8003D464");
	#elif OOT_U_1_0
		asm("external_func_8003D464 = 0x8002FF1C");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8003DE84(void);
	#if OOT_DEBUG
		asm("external_func_8003DE84 = 0x8003DE84");
	#elif OOT_U_1_0
		asm("external_func_8003DE84 = 0x800308B4");
	#elif MM_U_1_0
		asm("external_func_8003DE84 = 0x800C55C4");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8003DF10(void);
	#if OOT_DEBUG
		asm("external_func_8003DF10 = 0x8003DF10");
	#elif OOT_U_1_0
		asm("external_func_8003DF10 = 0x80030940");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8003DFA0(void);
	#if OOT_DEBUG
		asm("external_func_8003DFA0 = 0x8003DFA0");
	#elif OOT_U_1_0
		asm("external_func_8003DFA0 = 0x800309D0");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8003E02C(void);
	#if OOT_DEBUG
		asm("external_func_8003E02C = 0x8003E02C");
	#elif OOT_U_1_0
		asm("external_func_8003E02C = 0x80030A5C");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8003E0B8(void);
	#if OOT_DEBUG
		asm("external_func_8003E0B8 = 0x8003E0B8");
	#elif OOT_U_1_0
		asm("external_func_8003E0B8 = 0x80030AE8");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8003E0FC(void);
	#if OOT_DEBUG
		asm("external_func_8003E0FC = 0x8003E0FC");
	#elif OOT_U_1_0
		asm("external_func_8003E0FC = 0x80030B2C");
	#endif

/**
 * test if a sphere touches geometry in a collision context
 * TODO Confirm Usage
 */
extern int32_t z_collision_sphere_test(z64_col_ctxt_t *gcollision, vec3f_t *point, float radius);
	#if OOT_DEBUG
		asm("z_collision_sphere_test = 0x8003E30C");
	#elif OOT_U_1_0
		asm("z_collision_sphere_test = 0x80030D08");
	#endif

/**
 * description
 * DynaPolyInfo_setActor()
 */
#define DynaPolyInfo_RegisterActor z_dynapoly_actor_set
#define actor_register_dynapoly z_dynapoly_actor_set
extern uint32_t z_dynapoly_actor_set(z64_global_t *global, void *global_plus_0x810, z64_actor_t *actor, uint32_t dynacollision);
	#if OOT_DEBUG
		asm("z_dynapoly_actor_set = 0x8003EA74");
	#elif OOT_U_1_0
		asm("z_dynapoly_actor_set = 0x800313A4");
	#elif MM_U_1_0
		asm("z_dynapoly_actor_set = 0x800C6188");
	#endif

/**
 * description
 * TODO These notes need converted into a C function prototype
 * A0 = Global Context | A1 = Mesh Collision Id | V0 = Actor Instance or null
 */
#define DynaPolyInfo_GetActor z_dynapoly_actor_get
#define dynapolyinfo_get_actor z_dynapoly_actor_get
extern void z_dynapoly_actor_get(z64_global_t *gl, uint32_t dynapolyid);
	#if OOT_DEBUG
		asm("z_dynapoly_actor_get = 0x8003EB84");
	#elif OOT_U_1_0
		asm("z_dynapoly_actor_get = 0x80031464");
	#elif MM_U_1_0
		asm("z_dynapoly_actor_get = 0x800C6248");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8003EBF8(z64_global_t *global, void *global_plus_0x810, uint32_t dynapoly_id);
	#if OOT_DEBUG
		asm("external_func_8003EBF8 = 0x8003EBF8");
	#elif OOT_U_1_0
		asm("external_func_8003EBF8 = 0x800314D8");
	#elif MM_U_1_0
		asm("external_func_8003EBF8 = 0x800C62BC");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8003EC50(z64_global_t *gl, void *gl880, uint32_t *collision);;
	#if OOT_DEBUG
		asm("external_func_8003EC50 = 0x8003EC50");
	#elif OOT_U_1_0
		asm("external_func_8003EC50 = 0x80031530");
	#elif MM_U_1_0
		asm("external_func_8003EC50 = 0x800C6314");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8003ECA8(void);
	#if OOT_DEBUG
		asm("external_func_8003ECA8 = 0x8003ECA8");
	#elif OOT_U_1_0
		asm("external_func_8003ECA8 = 0x80031588");
	#endif

/**
 * description
 * TODO These notes need converted into a C function prototype
 * A0 = Global Context | A1 = Global Context + 0x810 | A2 = Mesh Collision Id
 */
#define DynaPolyInfo_Free z_dynapoly_free
extern void z_dynapoly_free(z64_global_t *global, void *global_plus_0x810, uint32_t dynacollision_id);
	#if OOT_DEBUG
		asm("z_dynapoly_free = 0x8003ED58");
	#elif OOT_U_1_0
		asm("z_dynapoly_free = 0x80031638");
	#elif MM_U_1_0
		asm("z_dynapoly_free = 0x800C64CC");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8003EE6C(void);
	#if OOT_DEBUG
		asm("external_func_8003EE6C = 0x8003EE6C");
	#elif OOT_U_1_0
		asm("external_func_8003EE6C = 0x800316C0");
	#endif

/**
 * TODO These notes need converted into a C function prototype
 * TODO We need to figure out what this does
 * Theory: Given a standard collision mesh, a dynamic collision mesh is allocated and a pointer to it is returned
 * dynacollision_init()?
 * A0 = Segment Offset to Collision Data | A1 = ptr to store result?
 */
extern void z_dynapoly_alloc(const uint32_t collision, void *collision_pointer);
	#if OOT_DEBUG
		asm("z_dynapoly_alloc = 0x80041880");
	#elif OOT_U_1_0
		asm("z_dynapoly_alloc = 0x80033EF4");
	#elif MM_U_1_0
		asm("z_dynapoly_alloc = 0x800C9564");
	#endif

/**
* Gets the collision polytype
* A0 = Global Context + 0x7C0
* A1 = Polygon*
* A2 = Mesh Collision Id 0x32 = Scene
* A3 = 0 returns high word, 1 turns low word
* V0 = High (0x00) or Low (0x04) word
 */
extern uint32_t get_collision_polytype(z64_col_ctxt_t *collision_cotext, void *Polygon, uint16_t mesh, bool word);
	#if OOT_DEBUG
		asm("get_collision_polytype = 0x800419B0");
	#elif OOT_U_1_0
		asm("get_collision_polytype = 0x80034028");
	#endif

/**
 * Get PolyType High Word &amp;&gt;&gt; 0x0003 E000
 * TODO These notes need converted into a C function prototype
 * A0 = Global Context + 0x7C0 | A1 = Polygon* | A2 = Mesh Collision Id | V0 = Result
 */
extern void external_func_80041D4C(void);
	#if OOT_DEBUG
		asm("external_func_80041D4C = 0x80041D4C");
	#elif OOT_U_1_0
		asm("external_func_80041D4C = 0x800343D4");
	#endif

/**
 * TODO These notes need converted into a C function prototype
 * A0 = Global Context + 0x7C0 | A1 = Polygon* | A2 = Mesh Collision Id | V0 = Result
 */
extern void external_func_80041DB8(void);
	#if OOT_DEBUG
		asm("external_func_80041DB8 = 0x80041DB8");
	#elif OOT_U_1_0
		asm("external_func_80041DB8 = 0x8003444C");
	#endif

/**
 * TODO These notes need converted into a C function prototype
 * A0 = Global Context + 0x7C0 | A1 = Polygon* | A2 = Mesh Collision Id | V0 = Result
 */
extern void external_func_80041EA4(void);
	#if OOT_DEBUG
		asm("external_func_80041EA4 = 0x80041EA4");
	#elif OOT_U_1_0
		asm("external_func_80041EA4 = 0x80034540");
	#endif

/**
 * TODO These notes need converted into a C function prototype
 * A0 = Global Context + 0x7C0 | A1 = Polygon* | A2 = Mesh Collision Id | V0 = Result
 */
extern void external_func_80041EEC(void);
	#if OOT_DEBUG
		asm("external_func_80041EEC = 0x80041EEC");
	#elif OOT_U_1_0
		asm("external_func_80041EEC = 0x80034590");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_80041F34(void);
	#if OOT_DEBUG
		asm("external_func_80041F34 = 0x80041F34");
	#elif OOT_U_1_0
		asm("external_func_80041F34 = 0x800345DC");
	#endif

/**
 * TODO These notes need converted into a C function prototype
 * A0 = Global Context + 0x7C0 | A1 = Polygon* | A2 = Mesh Collision Id | V0 = Result
 */
extern void external_func_80041FE8(void);
	#if OOT_DEBUG
		asm("external_func_80041FE8 = 0x80041FE8");
	#elif OOT_U_1_0
		asm("external_func_80041FE8 = 0x8003469C");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_80042048(void);
	#if OOT_DEBUG
		asm("external_func_80042048 = 0x80042048");
	#elif OOT_U_1_0
		asm("external_func_80042048 = 0x80034700");
	#endif

/**
 * Collision, poly surface, return Conveyor Surface Speed
 * A0 = Global Context + 0x7C0 | A1 = Polygon* | A2 = Mesh Collision Id | V0 = Result
 */
extern uint32_t get_collision_conveyor_speed(z64_col_ctxt_t *collision_cotext, void *Polygon, uint16_t mesh);
	#if OOT_DEBUG
		asm("get_collision_conveyor_speed = 0x800420C0");
	#elif OOT_U_1_0
		asm("get_collision_conveyor_speed = 0x80034778");
	#endif

/**
 * Collision, poly surface, return Conveyor Surface Direction
 * A0 = Global Context + 0x7C0 | A1 = Polygon* | A2 = Mesh Collision Id | V0 = Result
 */
extern uint32_t get_collision_conveyor_direction(z64_col_ctxt_t *collision_cotext, void *Polygon, uint16_t mesh);
	#if OOT_DEBUG
		asm("get_collision_conveyor_direction = 0x800420E4");
	#elif OOT_U_1_0
		asm("get_collision_conveyor_direction = 0x800347A0");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8004213C(void);
	#if OOT_DEBUG
		asm("external_func_8004213C = 0x8004213C");
	#elif OOT_U_1_0
		asm("external_func_8004213C = 0x800347FC");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_80042244(void);
	#if OOT_DEBUG
		asm("external_func_80042244 = 0x80042244");
	#elif OOT_U_1_0
		asm("external_func_80042244 = 0x80034908");
	#endif

/**
 * TODO This function is completely undocumented
 * This function is not used inside any existing overlay
 */
extern void external_func_8004239C(void);
	#if OOT_DEBUG
		asm("external_func_8004239C = 0x8004239C");
	#elif OOT_U_1_0
		asm("external_func_8004239C = 0x80034A60");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800433A4(void);
	#if OOT_DEBUG
		asm("external_func_800433A4 = 0x800433A4");
	#elif OOT_U_1_0
		asm("external_func_800433A4 = 0x80035180");
	#endif

/**
 * flags: | 1 updates position of actors on top, | 2 updates rotation of actors on top
 */
extern void actor_dynapoly_set_move(z64_actor_t *actor, enum dynapoly_move_flag flags);
	#if OOT_DEBUG
		asm("actor_dynapoly_set_move = 0x80043480");
	#elif OOT_U_1_0
		asm("actor_dynapoly_set_move = 0x80035260");
	#elif MM_U_1_0
		asm("actor_dynapoly_set_move = 0x800CAE10");
	#endif

/**
 * Wrapper for dynapoly_alloc() and actor_register_dynapoly(), so
 * MM-style dynapoly can work in OoT.
 * NOTE: This function appears to only exist in MM. A functionally
 *       identical rewrite for use in OoT has been provided, however.
 * NOTE: in the entity structure, a dynapoly_t must immediately
 *       follow the actor_t whose pointer you provide
 * TODO: Test rewrite in OoT and confirm it works.
 */
/* TODO: Does OoT have an equivalent of this function? */
#if OOT_DEBUG || OOT_U_1_0
	static inline void
	actor_dynapoly_new(
		z64_global_t *global
		, z64_actor_t *actor
		, uint32_t dynacollision  /* ex. 0x06000B70 (Obj_Kibako2) */
	)
	{
		/* the actor_t is followed by a dynapoly_t */
		z64_dynapoly_t *dynapoly = (z64_dynapoly_t*)(actor + 1);
		uint32_t result = 0;
		dynapoly_alloc(dynacollision, &result);
		dynapoly->poly_id =
		actor_register_dynapoly(
			global
			, &global->col_ctxt.unk_00_
			, actor
			, result
		);
	}
#elif MM_U_1_0
	extern void
	actor_dynapoly_new(
		z64_global_t *global
		, z64_actor_t *actor
		, uint32_t dynacollision
	);
	asm("actor_dynapoly_new = 0x800CAE34");
#endif

/**
 * Sets dynapoly flag 1
 */
extern void dynapoly_set_flag_1(z64_actor_t *actor);
	#if OOT_DEBUG
		asm("dynapoly_set_flag_1 = 0x800434A8");
	#elif OOT_U_1_0
		asm("dynapoly_set_flag_1 = 0x80035290");
	#endif

/**
 * Sets dynapoly flag 8
 */
extern void dynapoly_set_flag_8(z64_actor_t *actor);
	#if OOT_DEBUG
		asm("dynapoly_set_flag_8 = 0x80043538");
	#elif OOT_U_1_0
		asm("dynapoly_set_flag_8 = 0x8003532C");
	#endif

/**
 * Returns 0 or 1 depending on dynapoly flag & 1
 */
extern uint16_t dynapoly_check_flag_1(void);
	#if OOT_DEBUG
		asm("dynapoly_check_flag_1 = 0x80043548");
	#elif OOT_U_1_0
		asm("dynapoly_check_flag_1 = 0x80035340");
	#endif

/**
 * Returns 0 or 1 depending on dynapoly flag & 2
 */
extern uint16_t dynapoly_check_flag_2(z64_actor_t *actor);
	#if OOT_DEBUG
		asm("dynapoly_check_flag_2 = 0x8004356C");
	#elif OOT_U_1_0
		asm("dynapoly_check_flag_2 = 0x80035364");
	#elif MM_U_1_0
		asm("dynapoly_check_flag_2 = 0x800CAF70");
	#endif

/**
 * Returns 0 or 1 depending on dynapoly flag & 4
 */
extern uint16_t dynapoly_check_flag_4(z64_actor_t *actor);
	#if OOT_DEBUG
		asm("dynapoly_check_flag_4 = 0x80043590");
	#elif OOT_U_1_0
		asm("dynapoly_check_flag_4 = 0x80035388");
	#endif

/**
 * Returns 0 or 1 depending on dynapoly flag & 8
 */
extern uint16_t dynapoly_check_flag_8(z64_actor_t *actor);
	#if OOT_DEBUG
		asm("dynapoly_check_flag_8 = 0x800435B4");
	#elif OOT_U_1_0
		asm("dynapoly_check_flag_8 = 0x800353AC");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern int32_t actor_dynapoly_get_link_floorcast(z64_actor_t *actor);
	#if OOT_DEBUG
		asm("actor_dynapoly_get_link_floorcast = 0x80043590");
	#elif OOT_U_1_0
		asm("actor_dynapoly_get_link_floorcast = 0x80035388");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800435B4(void);
	#if OOT_DEBUG
		asm("external_func_800435B4 = 0x800435B4");
	#elif OOT_U_1_0
		asm("external_func_800435B4 = 0x800353AC");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800435D8(void);
	#if OOT_DEBUG
		asm("external_func_800435D8 = 0x800435D8");
	#elif OOT_U_1_0
		asm("external_func_800435D8 = 0x800353D0");
	#endif

/**
 * Camera related (Wrapper for 800493C8)
 * Function sets A2 = 0, calls inner function
 * TODO These notes need converted into a C function prototype
 * A0 = Camera struct ptr (ref in Global Context + 0x0790) | A1 = ?
 */
extern void external_func_8005A77C(void);
	#if OOT_DEBUG
		asm("external_func_8005A77C = 0x8005A77C");
	#elif OOT_U_1_0
		asm("external_func_8005A77C = 0x800495BC");
	#endif

/**
 * Sets the current camera type to the one specified by the parameter.
 * A0 = Camera context (Global Context + 0x01E0) | A1 = Camera type
 */
extern void set_camera_type(void *camera_context, uint16_t camera_type);
	#if OOT_DEBUG
		asm("set_camera_type = 0x8005A548");
	#elif OOT_U_1_0
		asm("set_camera_type = 0x800495E8");
	#endif

/**
 * Sets the current camera id to the one specified by the parameter. Needs to be called every frame to work.
 * This function is not used inside any existing overlay
 * A0 = Camera context (Global Context + 0x01E0) | A1 = Camera ID
 */
extern void set_camera_id(void *camera_context, uint16_t camera_id);
	#if OOT_DEBUG
		asm("set_camera_id = 0x8005A7A8");
	#elif OOT_U_1_0
		asm("set_camera_id = 0x800495E8");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8005A948(void);
	#if OOT_DEBUG
		asm("external_func_8005A948 = 0x8005A948");
	#elif OOT_U_1_0
		asm("external_func_8005A948 = 0x80049708");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8005A970(void);
	#if OOT_DEBUG
		asm("external_func_8005A970 = 0x8005A970");
	#elif OOT_U_1_0
		asm("external_func_8005A970 = 0x80049730");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8005A9CC(void);
	#if OOT_DEBUG
		asm("external_func_8005A9CC = 0x8005A9CC");
	#elif OOT_U_1_0
		asm("external_func_8005A9CC = 0x80049754");
	#endif

/**
 * Camera related.
 */
extern int16_t external_func_8005A9F4(void* gl790);
	#if OOT_DEBUG
		asm("external_func_8005A9F4 = 0x8005A9F4");
	#elif OOT_U_1_0
		asm("external_func_8005A9F4 = 0x8004977C");
	#endif

/**
 * Shakes the camera with specified strength and duration
 * a0 - global context + 0x1E0
 * a1 - u16 unknown, set to 2
 * a2 - u16 earthquake strength
 * a3 - u16 earthquake duration
 */
extern void z_camera_earthquake(void* global1E0, uint16_t unk, uint16_t strength, uint16_t duration);
	#if OOT_DEBUG
		asm("z_camera_earthquake = 0x8005AA1C");
	#elif OOT_U_1_0
		asm("z_camera_earthquake = 0x800497A4");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8005AA90(void);
	#if OOT_DEBUG
		asm("external_func_8005AA90 = 0x8005AA90");
	#elif OOT_U_1_0
		asm("external_func_8005AA90 = 0x80049818");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8005AC60(void);
	#if OOT_DEBUG
		asm("external_func_8005AC60 = 0x8005AC60");
	#elif OOT_U_1_0
		asm("external_func_8005AC60 = 0x800499F0");
	#endif

/**
 * Acts like a relative cammera command in scene cutscenes
 * A0 = Cutscene Camera struct ptr | A1 = Focus Point32_t Tween List | A2 = Camera Position Tween List | A3 = Actor Instance (tracked actor)
 */
extern void cutscene_set_relative_camera_command(void* global1E0, void*focus_tween_list, void*focus_point_list,z64_actor_t *actor);
	#if OOT_DEBUG
		asm("external_func_8005AC6C = 0x8005AC6C");
	#elif OOT_U_1_0
		asm("external_func_8005AC6C = 0x80049A00");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8005ACFC(void);
	#if OOT_DEBUG
		asm("external_func_8005ACFC = 0x8005ACFC");
	#elif OOT_U_1_0
		asm("external_func_8005ACFC = 0x80049A94");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8005AD1C(void);
	#if OOT_DEBUG
		asm("external_func_8005AD1C = 0x8005AD1C");
	#elif OOT_U_1_0
		asm("external_func_8005AD1C = 0x80049AB8");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8005AD40(void);
	#if OOT_DEBUG
		asm("external_func_8005AD40 = 0x8005AD40");
	#elif OOT_U_1_0
		asm("external_func_8005AD40 = 0x80049AE0");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8005AFB4(void);
	#if OOT_DEBUG
		asm("external_func_8005AFB4 = 0x8005AFB4");
	#elif OOT_U_1_0
		asm("external_func_8005AFB4 = 0x80049D34");
	#elif MM_U_1_0
		asm("external_func_8005AFB4 = 0x800E01B8");
	#endif

/**
 * TODO This function is completely undocumented; name may be misleading
 */
extern void camera_set_data(void);
	#if OOT_DEBUG
		asm("camera_set_data = 0x8005AFD4");
	#elif OOT_U_1_0
		asm("camera_set_data = 0x80049D58");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8005B198(void);
	#if OOT_DEBUG
		asm("external_func_8005B198 = 0x8005B198");
	#elif OOT_U_1_0
		asm("external_func_8005B198 = 0x80049DA4");
	#endif

/**
 * padding at end of function
 * TODO These notes need converted into a C function prototype
 */
extern void external_func_8005B1A4(void);
	#if OOT_DEBUG
		asm("external_func_8005B1A4 = 0x8005B1A4");
	#elif OOT_U_1_0
		asm("external_func_8005B1A4 = 0x80049DB4");
	#endif

/**
 * retrieves damage chart table pointer, called by all actors that don't have their damage chart inside overlay
 * TODO These notes need converted into a C function prototype
 * a0 - entry ID of some table? varies between actors | v0 - returns pointer that's used in a1 of damage chart initializer (80061EFC)
 */
extern void* z_actor_damage_chart_get(int32_t id);
	#if OOT_DEBUG
		asm("actor_damage_chart_get = 0x8005B200");
	#elif OOT_U_1_0
		asm("actor_damage_chart_get = 0x80049E10");
	#elif MM_U_1_0
		asm("actor_damage_chart_get = 0x800E03A0");
	#endif

/* Allocate a z64_collider_cylinder_collection_t structure.
* Source Code Reference File: "z_collision_check.c"
* Formerly `actor_collider_cylinder_array_alloc`
*/
extern void z_collider_jntsph_alloc(
z64_global_t* gl /* Global Context */
, void*  c /* Collider List to Allocate */
);
#if OOT_DEBUG
  asm("z_collider_jntsph_alloc = 0x8005BBF8");
#elif OOT_U_1_0
  asm("z_collider_jntsph_alloc = 0x8004A484");
#elif MM_U_1_0
  asm("z_collider_jntsph_alloc = 0x800E0B4C");
#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8005BC28(void);
	#if OOT_DEBUG
		asm("external_func_8005BC28 = 0x8005BC28");
	#elif OOT_U_1_0
		asm("external_func_8005BC28 = 0x8004A4B0");
	#endif

/* Dellocate a z64_collider_cylinder_collection_t structure.
* Source Code Reference File: "z_collision_check.c"
*/
extern void z_collider_jntsph_free(
z64_global_t* gl /* Global Context */
, void*  c /* Collider List to Deallocate */
);
#if OOT_DEBUG
  asm("z_collider_jntsph_free = 0x8005BCC8");
#elif OOT_U_1_0
  asm("z_collider_jntsph_free = 0x8004A550");
#elif MM_U_1_0
  asm("z_collider_jntsph_free = 0x800E0C18");
#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8005BE50(void);
	#if OOT_DEBUG
		asm("external_func_8005BE50 = 0x8005BE50");
	#elif OOT_U_1_0
		asm("external_func_8005BE50 = 0x8004A6BC");
	#endif

/* Initiailize a z64_collider_cylinder_collection_t structure.
* Source Code Reference File: "z_collision_check.c"
* Debug Message: "pclobj_jntsph->elem_tbl != NULL"
* Formerly `actor_collider_cylinder_array_init`
*/
extern int32_t z_collider_jntsph_init(
z64_global_t* gl /* Global Context */
, void*  c /* Collider List to Initiailize */
, z64_actor_t* a /* Actor instance */
, void* init /* Collider List Header */
, void* list /* Individual Collider Structures in Instance */
);
#if OOT_DEBUG
  asm("z_collider_jntsph_init = 0x8005C050");
#elif OOT_U_1_0
  asm("z_collider_jntsph_init = 0x8004A874");
#elif MM_U_1_0
  asm("z_collider_jntsph_init = 0x800E0E60");
#endif

/* Allocate a z64_collider_cylinder_main_t structure.
* Source Code Reference File: "z_collision_check.c"
* Formerly `actor_collider_cylinder_alloc`
*/
extern void z_collider_cylinder_alloc(
z64_global_t* gl /* Global Context */
, void*  c /* Collider to Allocate */
);
#if OOT_DEBUG
  asm("z_collider_cylinder_alloc = 0x8005C364");
#elif OOT_U_1_0
  asm("z_collider_cylinder_alloc = 0x8004AB7C");
#elif MM_U_1_0
  asm("z_collider_cylinder_alloc = 0x800E119C");
#endif

/* Deallocate a z64_collider_cylinder_main_t structure.
* Source Code Reference File: "z_collision_check.c"
* Formerly `actor_collider_cylinder_free`
*/
extern void z_collider_cylinder_free(
z64_global_t* gl /* Global Context */
, void*  c /* Collider to Deallocate */
);
#if OOT_DEBUG
  asm("z_collider_cylinder_free = 0x8005C3AC");
#elif OOT_U_1_0
  asm("z_collider_cylinder_free = 0x8004ABCC");
#elif MM_U_1_0
  asm("z_collider_cylinder_free = 0x800E11EC");
#endif

/**
 * Loads hitbox variable array to hitbox structure  (different purpose than 8005C4AC?)
 * TODO These notes need converted into a C function prototype
 * a0 - global context | a1 - actor instance + 0x014C (offset of hitbox struct in the instance) | a2 - hitbox variable array
 */
extern void external_func_8005C3F4(void);
	#if OOT_DEBUG
		asm("external_func_8005C3F4 = 0x8005C3F4");
	#elif OOT_U_1_0
		asm("external_func_8005C3F4 = 0x8004AC1C");
	#elif MM_U_1_0
		asm("external_func_8005C3F4 = 0x800E123C");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8005C450(void);
	#if OOT_DEBUG
		asm("external_func_8005C450 = 0x8005C450");
	#elif OOT_U_1_0
		asm("external_func_8005C450 = 0x8004AC84");
	#elif MM_U_1_0
		asm("external_func_8005C450 = 0x800E12A4");
	#endif

/* Initialize a z64_collider_cylinder_main_t structure.
* Source Code Reference File: "z_collision_check.c"
* Formerly `actor_collider_cylinder_init`
*/
extern void z_collider_cylinder_init(
z64_global_t* gl /* Global Context */
, void*  c /* Collider to Initialize */
, z64_actor_t* a /* Actor Instance to Reference */
, const z64_collider_cylinder_init_t* source /* Initialization Variables */
);
#if OOT_DEBUG
  asm("z_collider_cylinder_init = 0x8005C4AC");
#elif OOT_U_1_0
  asm("z_collider_cylinder_init = 0x8004ACEC");
#elif MM_U_1_0
  asm("z_collider_cylinder_init = 0x800E130C");
#endif

/**
 * TODO This function is completely undocumented
 */
extern int32_t z_collider_tri_list_alloc(z64_global_t* gl, z64_collider_tris_t* t);
	#if OOT_DEBUG
		asm("z_collider_tri_list_alloc = 0x8005C7E0");
	#elif OOT_U_1_0
		asm("z_collider_tri_list_alloc = 0x8004B064");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void z_collider_tri_list_free(z64_global_t* gl, z64_collider_tris_t* t);
	#if OOT_DEBUG
		asm("z_collider_tri_list_free = 0x8005C8C8");
	#elif OOT_U_1_0
		asm("z_collider_tri_list_free = 0x8004B148");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern int32_t z_collider_tri_list_init(z64_global_t* gl, z64_collider_tris_t* dest, z64_actor_t* actor, void* src, void* list);
	#if OOT_DEBUG
		asm("z_collider_tri_list_init = 0x8005CBAC");
	#elif OOT_U_1_0
		asm("z_collider_tri_list_init = 0x8004B3EC");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern int32_t z_collider_quad_alloc(z64_global_t *gl, z64_collider_quad_t* col);
	#if OOT_DEBUG
		asm("z_collider_quad_alloc = 0x8005D018");
	#elif OOT_U_1_0
		asm("z_collider_quad_alloc = 0x8004B858");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void z_collider_quad_free(z64_global_t *gl, z64_collider_quad_t* col);
	#if OOT_DEBUG
		asm("z_collider_quad_free = 0x8005D060");
	#elif OOT_U_1_0
		asm("z_collider_quad_free = 0x8004B8A8");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern int32_t z_collider_quad_init(z64_global_t *gl, z64_collider_t *collider, z64_actor_t *a, z64_collider_quad_init_t* col_init);
	#if OOT_DEBUG
		asm("z_collider_quad_init = 0x8005D104");
	#elif OOT_U_1_0
		asm("z_collider_quad_init = 0x8004B960");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8005D160(void);
	#if OOT_DEBUG
		asm("external_func_8005D160 = 0x8005D160");
	#elif OOT_U_1_0
		asm("external_func_8005D160 = 0x8004B9C8");
	#endif

/* Subscribe to Collision Pool 1
* (AT; Attack Toucher)
* Deal Damage
* Source Code Reference File: "z_collision_check.c"
* Formerly `actor_collision_check_set_at`
*/
extern void z_collider_hitbox(
z64_global_t* gl /* Global Context */
, z64_hit_ctxt_t* hit_ctxt /* Hitbox Context within Global Context */
, void*  c /* Collider Structure */
);
#if OOT_DEBUG
  asm("z_collider_hitbox = 0x8005D79C");
#elif OOT_U_1_0
  asm("z_collider_hitbox = 0x8004BD50");
#elif MM_U_1_0
  asm("z_collider_hitbox = 0x800E2634");
#endif

/* Subscribe to Collision Pool 2
* (AC; Attack Checker)
* Take Damage
* Source Code Reference File: "z_collision_check.c"
* Formerly `actor_collision_check_set_ac`
*/
extern void z_collider_hurtbox(
z64_global_t* gl /* Global Context */
, z64_hit_ctxt_t* hit_ctxt /* Hitbox Context within Global Context */
, void*  c /* Collider Structure */
);
#if OOT_DEBUG
  asm("z_collider_hurtbox = 0x8005D9F4");
#elif OOT_U_1_0
  asm("z_collider_hurtbox = 0x8004BF40");
#elif MM_U_1_0
  asm("z_collider_hurtbox = 0x800E2740");
#endif

/* Subscribe to Collision Pool 3
* (OT; (Object?) Toucher)
* Solid Collision - No Damage
* Source Code Reference File: "z_collision_check.c"
* Formerly `actor_collision_check_set_ot`
*/
extern void z_collider_bumpbox(
z64_global_t* gl /* Global Context */
, z64_hit_ctxt_t* hit_ctxt /* Hitbox Context within Global Context */
, void*  c /* Collider Structure */
);
#if OOT_DEBUG
  asm("z_collider_bumpbox = 0x8005DC4C");
#elif OOT_U_1_0
  asm("z_collider_bumpbox = 0x8004C130");
#elif MM_U_1_0
  asm("z_collider_bumpbox = 0x800E2928");
#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8005DFAC(void);
	#if OOT_DEBUG
		asm("external_func_8005DFAC = 0x8005DFAC");
	#elif OOT_U_1_0
		asm("external_func_8005DFAC = 0x8004C430");
	#endif

/* Initializes an actor's damage chart. (Perhaps allocation is more accurate?)
* `damage_chart` can be NULL.
* `init_data` should not be NULL.
* Source Code Reference File: "z_actor.c"
* Formerly `external_func_80061ED4`
*/
extern void z_actor_damage_table_init(
void* out /* Destination for initialized table. */
, z64_damagechart_init_t* damage_chart /* Initialization Variables for Damage Table */
, void* init_data
);
#if OOT_DEBUG
  asm("z_actor_damage_table_init = 0x80061ED4");
#elif OOT_U_1_0
  asm("z_actor_damage_table_init = 0x80050344");
#elif MM_U_1_0
  asm("z_actor_damage_table_init = 0x800E7530");
#elif MM_J_1_0
  asm("z_actor_damage_table_init = 0x800E90CC");
#elif MM_DEBUG
  asm("z_actor_damage_table_init = 0x8010174C");
#endif

/**
 * initializes damage chart part of actor
 * //Actor 0095
 * TODO These notes need converted into a C function prototype
 */
extern void z_actor_damage_table_init_80061EFC(
void* out /* Destination for initialized table. */
, z64_damagechart_init_t* damage_chart /* Initialization Variables for Damage Table */
, const uint32_t* init_data
);
	#if OOT_DEBUG
		asm("z_actor_damage_table_init_80061EFC = 0x80061EFC");
	#elif OOT_U_1_0
		asm("z_actor_damage_table_init_80061EFC = 0x80050370");
	#elif MM_U_1_0
		asm("z_actor_damage_table_init_80061EFC = 0x800E755C");
	#endif

/* Dynamically Update Collider Structure
* Source Code Reference File: "z_collision_check.c"
* Formerly `actor_collider_cylinder_update`
*/
extern void z_collider_cylinder_update(
z64_actor_t* a /* Actor to Reference */
, void*  c /* Collider Structure */
);
#if OOT_DEBUG
  asm("z_collider_cylinder_update = 0x800626DC");
#elif OOT_U_1_0
  asm("z_collider_cylinder_update = 0x80050B00");
#elif MM_U_1_0
  asm("z_collider_cylinder_update = 0x800E7DF8");
#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_80062718(void);
	#if OOT_DEBUG
		asm("external_func_80062718 = 0x80062718");
	#elif OOT_U_1_0
		asm("external_func_80062718 = 0x80050B44");
	#endif

/**
 * Translate a quad collider.
 */
extern void z_collider_quad_translate(z64_collider_quad_t* col, vec3f_t* a, vec3f_t* b, vec3f_t* c, vec3f_t* d);
	#if OOT_DEBUG
		asm("z_collider_quad_translate = 0x80062734");
	#elif OOT_U_1_0
		asm("z_collider_quad_translate = 0x80050B64");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800627A0(void);
	#if OOT_DEBUG
		asm("external_func_800627A0 = 0x800627A0");
	#elif OOT_U_1_0
		asm("external_func_800627A0 = 0x80050BD4");
	#endif

/* Translate a collider given an index and list.
* Commonly used to assign collision to a particular limb.
* Source Code Reference File: "z_collision_check.c"
*/
extern void z_collider_translate_index(
int32_t c_index /* Cylinder Index */
, void*  clist /* Cylinder List */
);
#if OOT_DEBUG
  asm("z_collider_translate_index = 0x800628A4");
#elif OOT_U_1_0
  asm("z_collider_translate_index = 0x80050CE4");
#elif MM_U_1_0
  /*asm("z_collider_translate_index = 0xDEADBEEF");*/
#endif

/**
 */
extern void z_effect_spawn_metalspark(z64_global_t* global, vec3f_t position);
	#if OOT_DEBUG
		asm("z_effect_spawn_metalspark = 0x80062CD4");
	#elif OOT_U_1_0
		asm("z_effect_spawn_metalspark = 0x80051124");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_80062D60(void);
	#if OOT_DEBUG
		asm("external_func_80062D60 = 0x80062D60");
	#elif OOT_U_1_0
		asm("external_func_80062D60 = 0x800511B8");
	#endif

/**
 * Also spawn metalspark
 */
extern void external_func_80062DF4(z64_global_t* gl, vec3f_t* pos);
	#if OOT_DEBUG
		asm("external_func_80062DF4 = 0x80062DF4");
	#elif OOT_U_1_0
		asm("external_func_80062DF4 = 0x80051250");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800635D0(void);
	#if OOT_DEBUG
		asm("external_func_800635D0 = 0x800635D0");
	#elif OOT_U_1_0
		asm("external_func_800635D0 = 0x80051A34");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_80063E9C(void);
	#if OOT_DEBUG
		asm("external_func_80063E9C = 0x80063E9C");
	#elif OOT_U_1_0
		asm("external_func_80063E9C = 0x80051E70");
	#endif

/**
 * enable actor-controlled cutscene
 * disables Z-Targeting, interface, and adds horizontal black bars
 * `global_cutscene` refers to `&global->cutscene`
 */
extern void actor_cutscene_enable(z64_global_t *, void *global_cutscene);
	#if OOT_DEBUG
		asm("actor_cutscene_enable = 0x80064520");
	#elif OOT_U_1_0
		asm("actor_cutscene_enable = 0x80052328");
	#endif

/**
 * disable actor-controlled cutscene
 * NOTE: will not work if (global->cutscene.state == 4)
 * `global_cutscene` refers to `&global->cutscene`
 */
extern void actor_cutscene_disable(z64_global_t *, void *global_cutscene);
	#if OOT_DEBUG
		asm("actor_cutscene_disable = 0x80064534");
	#elif OOT_U_1_0
		asm("actor_cutscene_disable = 0x80052340");
	#endif

/**
 * initialize cutscene from a script stored in a ram segment
 * NOTE: use wrapper `cutscene_play_script` instead (same arguments)
         if you want  the cutscene to play immediately; otherwise,
         heed the following note(s)
 * NOTE: To enable the cutscene, you must set
         Z64GL_CUTSCENE_PLAY_SCRIPT (byte) to 1
         after calling this function.
 * TODO: this is confirmed working with cutscenes stored in scenes
         by using ram segment 0x02, but what about cutscenes
         embedded directly into objects (ram segment 0x06)?
 * TODO: explain what "Contains Disk Drive Hook" means
 * `segptr` is a segment pointer to cutscene data,
            typically within a scene file (zscene)
 */
extern void cutscene_init_script(z64_global_t *, uint32_t segptr);
	#if OOT_DEBUG
		asm("cutscene_init_script = 0x800693D8");
	#elif OOT_U_1_0
		asm("cutscene_init_script = 0x80056F98");
	#endif
static inline void cutscene_play_script(z64_global_t *gl, uint32_t segptr)
{
	cutscene_init_script(gl, segptr);
	AVAL(Z64GL_CUTSCENE_PLAY_SCRIPT, uint8_t, 0) = 1;
}

/* Draws "Get Item" Model with defined draw function from a table at:
* 0x8011E320 (NZLE RAM)
* 0x801BB170 (NZSE RAM)
* Source Code Reference File: "z_draw.c"
* Formerly `draw_get_item`
*/
extern void z_draw_gi_model(
z64_global_t* gl /* Global Context */
, int16_t id /* Get Item Model ID (See: https://wiki.cloudmodding.com/oot/Code_(File)/Debug/Get_Item_Models)*/
);
#if OOT_DEBUG
  asm("z_draw_gi_model = 0x800694A0");
#elif OOT_U_1_0
  asm("z_draw_gi_model = 0x800570C0");
#elif MM_U_1_0
  asm("z_draw_gi_model = 0x800EE320");
#endif

/* Play a sound within a given radius at a given set of coordinates.
* Source Code Reference File: "code.c"
* Formerly `sound_play_position`
*/
extern void z_sfx_play_position(
z64_global_t* gl /* Global Context */
, vec3f_t* pos /* Global Coordiantes to act as the origin of the sound effect. */
, int32_t radius /* The radius in which you can hear the sound. */
, uint16_t id /* The sound effect ID */
);
#if OOT_DEBUG
  asm("z_sfx_play_position = 0x8006BAD8");
#elif OOT_U_1_0
  asm("z_sfx_play_position = 0x80058FF8");
#elif MM_U_1_0
  asm("z_sfx_play_position = 0x800F0568");
#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8006C2B0(void);
	#if OOT_DEBUG
		asm("external_func_8006C2B0 = 0x8006C2B0");
	#elif OOT_U_1_0
		asm("external_func_8006C2B0 = 0x80059714");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8006C318(void);
	#if OOT_DEBUG
		asm("external_func_8006C318 = 0x8006C318");
	#elif OOT_U_1_0
		asm("external_func_8006C318 = 0x8005977C");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern uint16_t external_func_8006C360(z64_global_t *global, int32_t unk1);
	#if OOT_DEBUG
		asm("external_func_8006C360 = 0x8006C360");
	#elif OOT_U_1_0
		asm("external_func_8006C360 = 0x800597C0");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8006C3D0(void);
	#if OOT_DEBUG
		asm("external_func_8006C3D0 = 0x8006C3D0");
	#elif OOT_U_1_0
		asm("external_func_8006C3D0 = 0x80059840");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8006C438(void);
	#if OOT_DEBUG
		asm("external_func_8006C438 = 0x8006C438");
	#elif OOT_U_1_0
		asm("external_func_8006C438 = 0x800598AC");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8006C4A4(void);
	#if OOT_DEBUG
		asm("external_func_8006C4A4 = 0x8006C4A4");
	#elif OOT_U_1_0
		asm("external_func_8006C4A4 = 0x8005991C");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8006C750(void);
	#if OOT_DEBUG
		asm("external_func_8006C750 = 0x8006C750");
	#elif OOT_U_1_0
		asm("external_func_8006C750 = 0x80059BD0");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8006C778(void);
	#if OOT_DEBUG
		asm("external_func_8006C778 = 0x8006C778");
	#elif OOT_U_1_0
		asm("external_func_8006C778 = 0x80059C00");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8006C85C(void);
	#if OOT_DEBUG
		asm("external_func_8006C85C = 0x8006C85C");
	#elif OOT_U_1_0
		asm("external_func_8006C85C = 0x80059CB0");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8006C894(void);
	#if OOT_DEBUG
		asm("external_func_8006C894 = 0x8006C894");
	#elif OOT_U_1_0
		asm("external_func_8006C894 = 0x80059CE0");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8006C8C4(void);
	#if OOT_DEBUG
		asm("external_func_8006C8C4 = 0x8006C8C4");
	#elif OOT_U_1_0
		asm("external_func_8006C8C4 = 0x80059D18");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8006CF6C(void);
	#if OOT_DEBUG
		asm("external_func_8006CF6C = 0x8006CF6C");
	#elif OOT_U_1_0
		asm("external_func_8006CF6C = 0x8005A36C");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8006D074(void);
	#if OOT_DEBUG
		asm("external_func_8006D074 = 0x8006D074");
	#elif OOT_U_1_0
		asm("external_func_8006D074 = 0x8005A474");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8006DD9C(void);
	#if OOT_DEBUG
		asm("external_func_8006DD9C = 0x8006DD9C");
	#elif OOT_U_1_0
		asm("external_func_8006DD9C = 0x8005B00C");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8006EF10(void);
	#if OOT_DEBUG
		asm("external_func_8006EF10 = 0x8006EF10");
	#elif OOT_U_1_0
		asm("external_func_8006EF10 = 0x8005BD78");
	#endif

/**
 * A0 = s16 end frame | A1 = s16 start frame? | A2 = s16 current frame? | F2 = Value between 0.0 (current frame smaller than start frame) and 1.0 (current frame >= end frame)
 */
extern float math_linear_tween(uint16_t endframe, uint16_t startframe, uint16_t currentframe);
	#if OOT_DEBUG
		asm("math_linear_tween = 0x8006F93C");
	#elif OOT_U_1_0
		asm("math_linear_tween = 0x8005C690");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8006F9BC(void);
	#if OOT_DEBUG
		asm("external_func_8006F9BC = 0x8006F9BC");
	#elif OOT_U_1_0
		asm("external_func_8006F9BC = 0x8005C714");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_80070600(void);
	#if OOT_DEBUG
		asm("external_func_80070600 = 0x80070600");
	#elif OOT_U_1_0
		asm("external_func_80070600 = 0x8005D2B4");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_80074CE8(void);
	#if OOT_DEBUG
		asm("external_func_80074CE8 = 0x80074CE8");
	#elif OOT_U_1_0
		asm("external_func_80074CE8 = 0x80060CE8");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800773A8(z64_global_t* gl, float a, float b, float c, float d);
	#if OOT_DEBUG
		asm("external_func_800773A8 = 0x800773A8");
	#elif OOT_U_1_0
		asm("external_func_800773A8 = 0x800631D8");
	#endif

/**
 * Return int32_t at 8011A5E8 (Event Days)
 * TODO These notes need converted into a C function prototype
 * V0 = int32_t at 8011A5E8
 */
extern void external_func_800775CC(void);
	#if OOT_DEBUG
		asm("external_func_800775CC = 0x800775CC");
	#elif OOT_U_1_0
		asm("external_func_800775CC = 0x80063404");
	#endif

/**
 * Zero int32_t at 8011A5E8 (Event Days)
 * TODO These notes need converted into a C function prototype
 */
extern void external_func_800775D8(void);
	#if OOT_DEBUG
		asm("external_func_800775D8 = 0x800775D8");
	#elif OOT_U_1_0
		asm("external_func_800775D8 = 0x80063414");
	#endif

/**
 * Update Background Music
 * TODO These notes need converted into a C function prototype
 * A0 = int32_t? value to write to 8011B9DE
 */
extern void external_func_800775F0(void);
	#if OOT_DEBUG
		asm("external_func_800775F0 = 0x800775F0");
	#elif OOT_U_1_0
		asm("external_func_800775F0 = 0x80063434");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_80077624(void);
	#if OOT_DEBUG
		asm("external_func_80077624 = 0x80077624");
	#elif OOT_U_1_0
		asm("external_func_80077624 = 0x80063474");
	#endif

/**
 * TODO This function is completely undocumented
 * mem_copy
 */
extern void external_func_80077684(void);
	#if OOT_DEBUG
		asm("external_func_80077684 = 0x80077684");
	#elif OOT_U_1_0
		asm("external_func_80077684 = 0x800634D4");
	#endif

/**
 * TODO This function is completely undocumented
 * mem_clear
 */
extern void external_func_800776E4(void);
	#if OOT_DEBUG
		asm("external_func_800776E4 = 0x800776E4");
	#elif OOT_U_1_0
		asm("external_func_800776E4 = 0x80063534");
	#endif

/**
 * memset byte
 * A0 = Address | A1 = length (in bytes) | A2 = uint8_t value
 * mem_cmp
 * formerly memory_set
 */
extern void z_memset(void *dst, const uint32_t len, const uint8_t value);
	#if OOT_DEBUG
		asm("z_memset = 0x800777E0");
	#elif OOT_U_1_0
		asm("z_memset = 0x80063630");
	#endif

/**
/* Return Cosine of Rotation Angle
* Source Code Reference File: "z_lib.c"
* Formerly `math_coss`
*/
#define Math_Coss z_coss
extern float z_coss(
int16_t angle /* 16-bit Angle */
);
#if OOT_DEBUG
  asm("z_coss = 0x80077834"); /* Alternatively 0x80104780 */
#elif OOT_U_1_0
  asm("z_coss = 0x80063684");
#elif MM_U_1_0
  asm("z_coss = 0x800FED44");
#endif

/**
/* Return Sine of Rotation Angle
* Source Code Reference File: "z_lib.c"
* Formerly `math_sins`
*/
#define Math_Sins z_sins
extern float z_sins(
int16_t angle /* 16-bit Angle */
);
#if OOT_DEBUG
  asm("z_sins = 0x80077870"); /* Alternatively 0x80100450 */
#elif OOT_U_1_0
  asm("z_sins = 0x800636C4");
#elif MM_U_1_0
  asm("z_sins = 0x800FED84");
#endif

/* Approximate to an angle.
* In animal crossing, this is called `chase_angle`
* Source Code Reference File: "z_lib.c"
*/
#define Math_ApproxUpdateScaledS z_lib_approx_angle_s
extern int32_t z_lib_approx_angle_s(
int16_t* angle /* Angle to Change */
, int16_t target /* Angle to Approximate To */
, int16_t change /* Value to Change By */
);
#if OOT_DEBUG
  asm("z_lib_approx_angle_s = 0x800778AC");
#elif OOT_U_1_0
  asm("z_lib_approx_angle_s = 0x80063704");
#elif MM_U_1_0
  asm("z_lib_approx_angle_s = 0x800FEE70");
#endif

/* Approximate to an int16_t
* In animal crossing, this is called `chase_s`
* Source Code Reference File: "z_lib.c"
*/
#define Math_ApproxS z_lib_approx_s
extern int16_t z_lib_approx_s(
int16_t* out /* Integer to Change */
, int16_t target /* Integer to Approximate To */
, int16_t change /* Value to Change By */
);
#if OOT_DEBUG
  asm("z_lib_approx_s = 0x8007797C");
#elif OOT_U_1_0
  asm("z_lib_approx_s = 0x80063704");
#elif MM_U_1_0
  asm("z_lib_approx_s = 0x800FEF2C");
#endif

/* Approximate to a float
* In animal crossing, this is called `chase_f`
* Source Code Reference File: "z_lib.c"
*/
#define Math_ApproxF z_lib_approx_f
extern int32_t z_lib_approx_f(
float* out /* Integer to Change */
, float target /* Float to Approximate To */
, float change /* Value to Change By */
);
#if OOT_DEBUG
  asm("z_lib_approx_f = 0x80077A00");
#elif OOT_U_1_0
  asm("z_lib_approx_f = 0x8006385C");
#elif MM_U_1_0
  asm("z_lib_approx_f = 0x800FF03C");
#endif

/**
 * i
 * TODO These notes need converted into a C function prototype
 * chase_xyz_t
 * vec3f_t approximator?
 */
extern void external_func_80077AF8(void);
	#if OOT_DEBUG
		asm("external_func_80077AF8 = 0x80077AF8");
	#elif OOT_U_1_0
		asm("external_func_80077AF8 = 0x80063958");
	#endif

/**
 * TODO This function is completely undocumented
 * inter_float
 * Interpolate Floating Point?
 */
extern void external_func_80077B58(void);
	#if OOT_DEBUG
		asm("external_func_80077B58 = 0x80077B58");
	#elif OOT_U_1_0
		asm("external_func_80077B58 = 0x800639B8");
	#endif

/* Generate a random int16_t.
* Range is [0, range) (Exclusive)
* Adds `offset` to the generated integer.
* Source Code Reference File: "z_lib.c"
*/
#define Math_Rand_S16Offset z_lib_math_rand_s16_offset
extern int16_t z_lib_math_rand_s16_offset(
int16_t offset /* Offset to Add */
, int16_t range /* Range Limit */
);
#if OOT_DEBUG
  asm("z_lib_math_rand_s16_offset = 0x80077D90");
#elif OOT_U_1_0
  asm("z_lib_math_rand_s16_offset = 0x80063BF0");
#elif MM_U_1_0
  asm("z_lib_math_rand_s16_offset = 0x800FF450");
#endif

/* Copy a vec3f_t to a destination.
* In animal crossing, this is called `xyz_t_move`
* Source Code Reference File: "z_lib.c"
*/
extern void z_lib_vec3f_copy(
vec3f_t *out /* Destination Pointer */
, vec3f_t *in /* Input Vector */
);
#if OOT_DEBUG
  asm("z_lib_vec3f_copy = 0x80077E40");
#elif OOT_U_1_0
  asm("z_lib_vec3f_copy = 0x80063CAC");
#elif MM_U_1_0
  asm("z_lib_vec3f_copy = 0x800FF50C");
#endif

/* Convert vec3s_t to vec3f_t
* Source Code Reference File: "z_lib.c"
* Formerly `math_vec3f_from_vec3s`
*/
extern void z_lib_vec3s_to_vec3f(
vec3f_t* out
, vec3s_t* in
);
#if OOT_DEBUG
    asm("z_lib_vec3s_to_vec3f = 0x80077E5C");
#elif OOT_U_1_0
    asm("z_lib_vec3s_to_vec3f = 0x80063CCC");
#elif MM_U_1_0
    asm("z_lib_vec3s_to_vec3f = 0x800FF54C");
#endif

/* Sum of two vec3f_t structures.
* out = a + b;
* Source Code Reference File: "z_lib.c"
* Formerly `math_vec3f_add`
*/
extern void z_lib_vec3f_sum(
vec3f_t* a
, vec3f_t* b
, vec3f_t* out
);
#if OOT_DEBUG
    asm("z_lib_vec3f_sum = 0x80077E9C");
#elif OOT_U_1_0
    asm("z_lib_vec3f_sum = 0x80063D10");
#elif MM_U_1_0
    asm("z_lib_vec3f_sum = 0x800FF5BC");
#endif

/* Difference of two vec3f_t structures.
* out = a - b;
* Source Code Reference File: "z_lib.c"
* Formerly `math_vec3f_sub`
*/
extern void z_lib_vec3f_diff(
vec3f_t* a
, vec3f_t* b
, vec3f_t* out
);
#if OOT_DEBUG
    asm("z_lib_vec3f_diff = 0x80077ED0");
#elif OOT_U_1_0
    asm("z_lib_vec3f_diff = 0x80063D48");
#elif MM_U_1_0
    asm("z_lib_vec3f_diff = 0x800FF5F4");
#endif

/* Difference of two vec3s_t structures.
* Store the result as a vec3f_t.
* out = a - b;
* Source Code Reference File: "z_lib.c"
* Formerly `math_vec3s_sub`
*/
extern void z_lib_vec3s_diff_to_vec3f(
vec3f_t* out
, vec3s_t* a
, vec3s_t* b
);
#if OOT_DEBUG
    asm("z_lib_vec3s_diff = 0x80077F04");
#elif OOT_U_1_0
    asm("z_lib_vec3s_diff = 0x80063D80");
#elif MM_U_1_0
    asm("z_lib_vec3s_diff = 0x800FF62C");
#endif

/* Multiply a vec3f_t by a scalar value.
* out *= scale;
* Source Code Reference File: "z_lib.c"
* Formerly `math_vec3f_mul_scalar`
*/
extern void z_lib_vec3f_scale(
vec3f_t* out
, float scale
);
#if OOT_DEBUG
    asm("z_lib_vec3f_scale = 0x80077F5C");
#elif OOT_U_1_0
    asm("z_lib_vec3f_scale = 0x80063DDC");
#elif MM_U_1_0
    asm("z_lib_vec3f_scale = 0x800FF688");
#endif

/* Calculate the xyz distance between two vec3f structures.
return √(((b->x) - (a->x))^2 + ((b->y) - (a->y))^2 + ((b->z) - (a->z))^2);
* Source Code Reference File: "z_lib.c"
* Formerly `math_vec3f_distance`
*/
extern float z_lib_vec3f_dist_xyz(
vec3f_t* a
, vec3f_t* b
);
#if OOT_DEBUG
    asm("z_lib_vec3f_dist_xyz = 0x80077F90");
#elif OOT_U_1_0
    asm("z_lib_vec3f_dist_xyz = 0x80063E18");
#elif MM_U_1_0
    asm("z_lib_vec3f_dist_xyz = 0x800FF884");
#endif

/* Calculate the distance between two vec3f structures.
* Store the difference as a vec3f_t.
* return √((out->x)^2 + (out->y)^2 + (out->z)^2);
* out = {(b->x - a->x), (b->y - a->y), (b->z - a->z)};
* Source Code Reference File: "z_lib.c"
* Formerly `math_vec3f_distance_sub`
*/
extern float z_lib_vec3f_dist_diff(
vec3f_t* a
, vec3f_t* b
, vec3f_t* out
);
#if OOT_DEBUG
    asm("z_lib_vec3f_dist_diff = 0x80077FD0");
#elif OOT_U_1_0
    asm("z_lib_vec3f_dist_diff = 0x80063E5C");
#elif MM_U_1_0
    asm("z_lib_vec3f_dist_diff = 0x800FF8D4");
#endif

/* Utilizes the pythagorean theorem to calculate the distance between two vec3f_t vectors (a, b)
* c = √(a^2 + b^2)
* Source Code Reference File: "z_lib.c"
* Formerly `math_vec3f_distance_xz`
*/
extern float z_lib_vec3f_dist_xz(
vec3f_t* a /* Vector A */
, vec3f_t* b /* Vector B */
);
#if OOT_DEBUG
  asm("z_lib_vec3f_dist_xz = 0x80078028");
#elif OOT_U_1_0
  asm("z_lib_vec3f_dist_xz = 0x80063EB8");
#elif MM_U_1_0
  asm("z_lib_vec3f_dist_xz = 0x800FF92C");
#endif

/* Calculate arctan2 (x, z) of two vec3f_t vectors (a, b)
* Source Code Reference File: "z_lib.c"
* Formerly `math_vec3f_atan2_xz`
*/
extern int16_t z_lib_vec3f_yaw(
vec3f_t* a /* Vector A */
, vec3f_t* b /* Vector B */
);
#if OOT_DEBUG
  asm("z_lib_vec3f_yaw = 0x80078068");
#elif OOT_U_1_0
  asm("z_lib_vec3f_yaw = 0x80063F00");
#elif MM_U_1_0
  asm("z_lib_vec3f_yaw = 0x800FFA60");
#endif

/* Calculates atan2(z_lib_vec3f_yaw(a, b), (a->y - b->y))
* Source Code Reference File: "z_lib.c"
* Formerly `math_vec3f_atan2_xz_y`
*/
extern int16_t z_lib_vec3f_pitch(
vec3f_t* a /* Vector A */
, vec3f_t* b /* Vector B */
);
#if OOT_DEBUG
  asm("z_lib_vec3f_pitch = 0x8007809C");
#elif OOT_U_1_0
  asm("z_lib_vec3f_pitch = 0x80063F34");
#elif MM_U_1_0
  asm("z_lib_vec3f_pitch = 0x800FFA94");
#endif

/* Process a chain of variables for the "compact initialization format".
* Source Code Reference File: "z_lib.c"
* Formerly `actor_init_ichain`
*/
extern void z_lib_ichain_init(
z64_actor_t* a /* Actor to Reference */
, const uint32_t* data /* "Initiailization Chain Data" */
);
#if OOT_DEBUG
  asm("z_lib_ichain_init = 0x800780DC");
#elif OOT_U_1_0
  asm("z_lib_ichain_init = 0x80063F7C");
#elif MM_U_1_0
  asm("z_lib_ichain_init = 0x800FFADC");
#endif

/* Smoothly Transition (Scale) float to Target
* Keywords: Tweening
* Source Code Reference File: "z_lib.c"
*/
extern float z_lib_smooth_scale_max_min_f(
float* src /* Source Float */
, float target /* Target Float */
, float scale /* Scale */
, float max /* Maximum Value to Change By */
, float min /* Minimum Value to Change By */
);
#if OOT_DEBUG
  asm("z_lib_smooth_scale_max_min_f = 0x80078310");
#elif OOT_U_1_0
  asm("z_lib_smooth_scale_max_min_f = 0x80064178");
#elif MM_U_1_0
  asm("z_lib_smooth_scale_max_min_f = 0x800FFCD8");
#endif

/* Smoothly Transition (Scale) float to Target
* Keywords: Tweening
* Source Code Reference File: "z_lib.c"
*/
extern void z_lib_smooth_scale_max_f(
float* src /* Source Float */
, float target /* Target Float */
, float scale /* Scale */
, float max /* Maximum Value to Change By */
);
#if OOT_DEBUG
  asm("z_lib_smooth_scale_max_f = 0x8007841C");
#elif OOT_U_1_0
  asm("z_lib_smooth_scale_max_f = 0x80064280");
#elif MM_U_1_0
  asm("z_lib_smooth_scale_max_f = 0x800FFDF8");
#endif

/* Smoothly Transition (Scale) float
* Keywords: Tweening
* Source Code Reference File: "z_lib.c"
*/
extern void z_lib_smooth_downscale_max_f(
float* src /* Source Float */
, float scale /* Scale */
, float max /* Maximum Value to Change By */
);
#if OOT_DEBUG
  asm("z_lib_smooth_downscale_max_f = 0x8007848C");
#elif OOT_U_1_0
  asm("z_lib_smooth_downscale_max_f = 0x800642F0");
#elif MM_U_1_0
  asm("z_lib_smooth_downscale_max_f = 0x800FFE68");
#endif

/* Smoothly Transition (Scale) int16_t to Target
* Source Code Reference File: "z_lib.c"
*/
extern int16_t z_lib_smooth_scale_max_min_s(
int16_t* src /* Source Short */
, int16_t target /* Target Short*/
, int16_t invScale /* Derived from Decomp */
, int16_t max /* Maximum Value to Scale By */
, int16_t min /* Minimum Value to Scale By */
);
#if OOT_DEBUG
  asm("z_lib_smooth_scale_max_min_s = 0x8007869C");
#elif OOT_U_1_0
  asm("z_lib_smooth_scale_max_min_s = 0x80064508");
#elif MM_U_1_0
  asm("z_lib_smooth_scale_max_min_s = 0x800FFEBC");
#endif

/* Smoothly Transition (Scale) int16_t to Target
* Source Code Reference File: "z_lib.c"
*/
extern int16_t z_lib_smooth_scale_max_s(
int16_t* src /* Source Short */
, int16_t target /* Target Short*/
, int16_t invScale /* Derived from Decomp */
, int16_t max /* Maximum Value to Scale By */
);
#if OOT_DEBUG
  asm("z_lib_smooth_scale_max_s = 0x800787BC");
#elif OOT_U_1_0
  asm("z_lib_smooth_scale_max_s = 0x80064624");
#elif MM_U_1_0
  asm("z_lib_smooth_scale_max_s = 0x800FFFD8");
#endif

/* Copy 4 bytes from src to dest
* The decomp calls this `Color_RGBA8_Copy`
* Source Code Reference File: "z_lib.c"
* Formerly `mem_copy_uint8_t_4`
*/
extern void z_lib_word_copy(
void* dest
, void* src
);
#if OOT_DEBUG
  asm("z_lib_word_copy = 0x80078860");
#elif OOT_U_1_0
  asm("z_lib_word_copy = 0x800646C8");
#elif MM_U_1_0
  asm("z_lib_word_copy = 0x8010007C");
#endif

/**
 * Play SFX (limited set, identical to 80064738)
 * TODO These notes need converted into a C function prototype
 * A0 = SFX
 */
extern void external_func_80078884(void);
	#if OOT_DEBUG
		asm("external_func_80078884 = 0x80078884");
	#elif OOT_U_1_0
		asm("external_func_80078884 = 0x800646F0");
	#endif

/**
 * Play SFX once. Stops playing the SFX if the same SFX is played again.
 * A0 = SFX
 */
extern void play_sound_global_once(uint16_t sfx_id);
	#if OOT_DEBUG
		asm("play_sound_global_once = 0x800788CC");
	#elif OOT_U_1_0
		asm("play_sound_global_once = 0x80064738");
	#endif

/**
 * Play SFX (limited set)
 * TODO These notes need converted into a C function prototype
 * A0 = SFX
 */
extern void external_func_80078914(uint16_t sfx_id);
	#if OOT_DEBUG
		asm("external_func_80078914 = 0x80078914");
	#elif OOT_U_1_0
		asm("external_func_80078914 = 0x80064780");
	#endif

/**
 * Initiailize a positional point light. (Type 0)
 * Wrapper for 80079D30
 * Source Code Reference File: "z_lights.c"
 */
extern void z_lights_init_pos_0(
void* info
, int16_t x, int16_t y, int16_t z
, uint8_t r, uint8_t g, uint8_t b
, int16_t radius
);
#if OOT_DEBUG
	asm("z_lights_init_pos_0 = 0x80079D8C");
#elif OOT_U_1_0
	asm("z_lights_init_pos_0 = 0x80065BCC");
#endif

/**
 * Initiailize a positional point light. (Type 2)
 * Wrapper for 80079D30
 * Source Code Reference File: "z_lights.c"
 */
extern void z_lights_init_pos_2(
void* info
, int16_t x, int16_t y, int16_t z
, uint8_t r, uint8_t g, uint8_t b
, int16_t radius
);
#if OOT_DEBUG
	asm("z_lights_init_pos_2 = 0x80079DF0");
#elif OOT_U_1_0
	asm("z_lights_init_pos_2 = 0x80065C30");
#endif

/**
 * Set a light color.
 * Source Code Reference File: "z_lights.c"
 */
extern void z_lights_set_rgb_radius(
z64_lightinfo_t* info
, uint8_t r, uint8_t g, uint8_t b
, int16_t radius
);
#if OOT_DEBUG
	asm("z_lights_set_rgb_radius = 0x80079E58");
#elif OOT_U_1_0
	asm("z_lights_set_rgb_radius = 0x80065C98");
#endif

/**
 * Initializing and allocating a [point?] light strucutre in memory.
 * Source Code Reference File: "z_lights.c"
 */
extern z64_light_node_t* z_lights_insert(
z64_global_t* gl /* Global Context */
, z64_lighting_t* lighting /* Lighting Struct */
, z64_lightinfo_t* info /* Initialization Info */
);
#if OOT_DEBUG
	asm("z_lights_insert = 0x8007A764");
#elif OOT_U_1_0
	asm("z_lights_insert = 0x800665B0");
#endif

/**
 * Freeing the memory used for a light structure.
 * Source Code Reference File: "z_lights.c"
 */
extern void z_lights_kill(
z64_global_t* gl /* Global Context */
, z64_lighting_t* lighting /* Lighting Struct */
, z64_light_node_t* light /* Light Node */
);
#if OOT_DEBUG
	asm("z_lights_kill = 0x8007A7C4");
#elif OOT_U_1_0
	asm("z_lights_kill = 0x80066610");
#endif

/**
 * z_malloc_r, possibly?
 */
extern void external_func_8007AE10(void);
	#if OOT_DEBUG
		asm("external_func_8007AE10 = 0x8007AE10");
	#elif OOT_U_1_0
		asm("external_func_8007AE10 = 0x80066C10");
	#endif

/**
 * Allocates bytes in the arena, rounded up to nearest 16.
 * a0 = size, v0 = alloced address
 * 0x8007AE90 seems to do the same thing?
 */
extern void *z_malloc(
	uint32_t size
#ifndef RETAIL_NUANCES /* debug roms require these arguments, retail roms don't */
	, const char *string
	, int32_t line
#endif
);
#ifdef RETAIL_NUANCES
#define z_malloc(SIZE, STR) z_malloc(SIZE)
#else
#define z_malloc(SIZE, STR) z_malloc(SIZE, STR, __LINE__)
#endif
    #if OOT_DEBUG
        asm("z_malloc = 0x8007AEE0");
	#elif OOT_U_1_0
		asm("z_malloc = 0x80066C60");
    #endif

/**
 * Allocates bytes in the arena, rounded up to nearest 16, starting from the highest free address.
 * a0 = size, v0 = alloced address
 * 0x8007AF3C seems to do the same thing?
 */
extern void *z_malloc_reverse(
	uint32_t size
#ifndef RETAIL_NUANCES /* debug roms require these arguments, retail roms don't */
	, const char *string
	, int32_t line
#endif
);
#ifdef RETAIL_NUANCES
#define z_malloc_reverse(SIZE, STR) z_malloc_reverse(SIZE)
#else
#define z_malloc_reverse(SIZE, STR) z_malloc_reverse(SIZE, STR, __LINE__)
#endif
    #if OOT_DEBUG
        asm("z_malloc_reverse = 0x8007AF8C");
	#elif OOT_U_1_0
		// TODO Needs 1.0 equivalent!
    #endif

/**
 * Frees bytes from the arena.
 * a0 = allocated address
 */
extern void z_free(void *address);
	#if OOT_DEBUG
		asm("z_free = 0x8007B0D4");
	#elif OOT_U_1_0
		asm("z_free = 0x80066C90");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8007C25C(void);
	#if OOT_DEBUG
		asm("external_func_8007C25C = 0x8007C25C");
	#elif OOT_U_1_0
		asm("external_func_8007C25C = 0x80067850");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8007C3F4(void);
	#if OOT_DEBUG
		asm("external_func_8007C3F4 = 0x8007C3F4");
	#elif OOT_U_1_0
		asm("external_func_8007C3F4 = 0x800679E8");
	#endif

/**
 * Enters cutscene mode and focuses the actor for a short time
 * TODO Finish tehse notes, convert to a C function prototype...
 * a0 - global context | a1 = ??? | a2 = frame duration | a3 = ??? | 0x10(sp) = ???
 */
extern void actor_closeup(void);
	#if OOT_DEBUG
		asm("actor_closeup = 0x800800F8");
	#elif OOT_U_1_0
		asm("actor_closeup = 0x8006B6FC");
	#endif

/**
 * Camera related
 * TODO These notes need converted into a C function prototype
 * a0 - global context | a1 - int16_t unknown
 */
extern void external_func_800803F0(void);
	#if OOT_DEBUG
		asm("external_func_800803F0 = 0x800803F0");
	#elif OOT_U_1_0
		asm("external_func_800803F0 = 0x8006B9B4");
	#endif

/**
 * Enters cutscene mode and focuses the actor for a short time
 * a0 - global context | a1 - actor instance
 */
extern void actor_one_point_cutscene(z64_global_t *, z64_actor_t *actor);
	#if OOT_DEBUG
		asm("actor_one_point_cutscene = 0x80080480");
	#elif OOT_U_1_0
		asm("actor_one_point_cutscene = 0x8006BA10");
	#endif

/**
 * Enters cutscene mode and focuses the actor for a short time, playing a sound?
 * a0 - global context | a1 - actor instance | a2 - sound ID?
 */
extern void actor_one_point_cutscene_sound(z64_global_t *, z64_actor_t *actor, uint16_t sound);
	#if OOT_DEBUG
		asm("actor_one_point_cutscene_sound = 0x800806BC");
	#elif OOT_U_1_0
		asm("actor_one_point_cutscene_sound = 0x8006BB7C");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_80080728(void);
	#if OOT_DEBUG
		asm("external_func_80080728 = 0x80080728");
	#elif OOT_U_1_0
		asm("external_func_80080728 = 0x8006BBF4");
	#endif

/**
 * Draw Compass Arrows
 */
extern void interface_draw_compass(z64_global_t *gl);
	#if OOT_DEBUG
		asm("interface_draw_compass = 0x80081240");
	#elif OOT_U_1_0
		asm("interface_draw_compass = 0x8008921C"); /* TODO: Confirm */
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800825E0(void);
	#if OOT_DEBUG
		asm("external_func_800825E0 = 0x800825E0");
	#elif OOT_U_1_0
		asm("external_func_800825E0 = 0x8006D8E0");
	#endif

/**
 * Swaps Link's equipment to the adult/child version depending on the current age.
 * It updates boots, tunic, shield, B-Button and C-Button items.
 * NOTE: Only use this function when the button icons are not on-screen. They
         may get corrupted otherwise.
 * NOTE: This function is not used in any existing actor overlay in OoT.
 */
extern void player_swap_age_equipment(void);
    #if OOT_DEBUG
        asm("player_swap_age_equipment = 0x800846E0");
    #elif OOT_U_1_0
        asm("player_swap_age_equipment = 0x8006F804");
    #endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800849A8(void);
	#if OOT_DEBUG
		asm("external_func_800849A8 = 0x800849A8");
	#elif OOT_U_1_0
		asm("external_func_800849A8 = 0x8006FA88");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800849EC(void);
	#if OOT_DEBUG
		asm("external_func_800849EC = 0x800849EC");
	#elif OOT_U_1_0
		asm("external_func_800849EC = 0x8006FAD0");
	#endif

/**
 * Update Item Icon for Interface
 */
extern void gfx_update_item_icon(z64_global_t *gl, uint8_t button_id);
	#if OOT_DEBUG
		asm("gfx_update_item_icon = 0x80084A6C");
	#elif OOT_U_1_0
		asm("gfx_update_item_icon = 0x8006FB50");
	#endif

/**
 * TODO This function is completely undocumented
 * This function is not used inside any existing overlay
 */
extern void external_func_80084BF4(void);
	#if OOT_DEBUG
		asm("external_func_80084BF4 = 0x80084BF4");
	#elif OOT_U_1_0
		asm("external_func_80084BF4 = 0x8006FCB0");
	#endif

/**
 * Item Giving Routine
 * one of them at least
 */
extern void inventory_item_set(z64_global_t *global, uint8_t item);
	#if OOT_DEBUG
		asm("inventory_item_set = 0x80084D10");
	#elif OOT_U_1_0
		asm("inventory_item_set = 0x8006FDCC");
	#endif

/**
 * ? Check if player has item?
 * TODO These notes need converted into a C function prototype
 * A0 = Item Index | V0 = 0xFF if no Item?
 */
extern uint8_t inventory_item_get(uint8_t item);
	#if OOT_DEBUG
		asm("inventory_item_get = 0x80086388");
	#elif OOT_U_1_0
		asm("inventory_item_get = 0x80071420");
	#endif

/**
 * Try Update Trade Quest Item, returns 1 on success 0 otherwise
 * Egg -> Chicken; Ruto's Letter -> Bottle, etc
 */
extern int32_t inventory_item_update(uint8_t item_old, uint8_t item_new);
	#if OOT_DEBUG
		asm("inventory_item_update = 0x800869E4");
	#elif OOT_U_1_0
		asm("inventory_item_update = 0x800719E0");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_80086ABC(void);
	#if OOT_DEBUG
		asm("external_func_80086ABC = 0x80086ABC");
	#elif OOT_U_1_0
		asm("external_func_80086ABC = 0x80071A94");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_80086B2C(void);
	#if OOT_DEBUG
		asm("external_func_80086B2C = 0x80086B2C");
	#elif OOT_U_1_0
		asm("external_func_80086B2C = 0x80071B04");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_80086F00(void);
	#if OOT_DEBUG
		asm("external_func_80086F00 = 0x80086F00");
	#elif OOT_U_1_0
		asm("external_func_80086F00 = 0x80071E6C");
	#endif

/**
 * ROM st: do_action_static
 * TODO These notes need converted into a C function prototype
 * This function is not used inside any existing overlay
 */
extern void external_func_8008708C(void);
	#if OOT_DEBUG
		asm("external_func_8008708C = 0x8008708C");
	#elif OOT_U_1_0
		asm("external_func_8008708C = 0x80071FF8");
	#endif

/**
 * Update Link's Health
 * Negative Value Subtracts Health
 * Positive Value Adds Health
 */
#define Health_ChangeBy z_player_update_health
extern void z_player_update_health(z64_global_t* gl, int16_t health);
	#if OOT_DEBUG
		asm("z_player_update_health = 0x80087174");
	#elif OOT_U_1_0
		asm("z_player_update_health = 0x800720BC");
	#endif

/**
 * Adds or removes rupees from the counter (Negative values subtract, positive add)
 * a0 - Rupee amount.
 */
#define Rupees_ChangeBy z_player_update_rupees
#define change_rupee_count_by z_player_update_rupees
extern void z_player_update_rupees(int32_t num_rupees);
	#if OOT_DEBUG
		asm("z_player_update_rupees = 0x8008730C");
	#elif OOT_U_1_0
		asm("z_player_update_rupees = 0x800721CC");
	#endif

/**
 * Update ammo amount given an item and change.
 */
#define Inventory_ChangeAmmo z_inventory_update_ammo
extern void z_inventory_update_ammo(int16_t item, int16_t ammo_change);
	#if OOT_DEBUG
		asm("z_inventory_update_ammo = 0x80087330");
	#elif OOT_U_1_0
		asm("z_inventory_update_ammo = 0x800721F4");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_80087680(void);
	#if OOT_DEBUG
		asm("external_func_80087680 = 0x80087680");
	#elif OOT_U_1_0
		asm("external_func_80087680 = 0x80072500");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800876C8(z64_global_t *gl);
	#if OOT_DEBUG
		asm("external_func_800876C8 = 0x800876C8");
	#elif OOT_U_1_0
		asm("external_func_800876C8 = 0x80072548");
	#elif MM_U_1_0
		asm("external_func_800876C8 = 0x80115D5C");
	#endif

/**
 * Subtract Magic Routine
 * Global Context, Magic Amount to Subtract
 */
extern int32_t z_parameter_subtract_magic(z64_global_t* gl, int16_t amount, int16_t a2);
	#if OOT_DEBUG
		asm("z_parameter_subtract_magic = 0x80087708");
	#elif OOT_U_1_0
		asm("z_parameter_subtract_magic = 0x80072588");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_80088AA0(int16_t seconds);
	#if OOT_DEBUG
		asm("external_func_80088AA0 = 0x80088AA0");
	#elif OOT_U_1_0
		asm("external_func_80088AA0 = 0x800738E8");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_80088AF0(void);
	#if OOT_DEBUG
		asm("external_func_80088AF0 = 0x80088AF0");
	#elif OOT_U_1_0
		asm("external_func_80088AF0 = 0x80073938");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_80088B34(int16_t a);
	#if OOT_DEBUG
		asm("external_func_80088B34 = 0x80088B34");
	#elif OOT_U_1_0
		asm("external_func_80088B34 = 0x8007397C");
	#endif

/**
 * z_parameter
 */
#define Interface_DrawActionLabel z_parameter_draw_action_label
extern void z_parameter_draw_action_label(z64_gfx_t* gfx, uint32_t a1);
	#if OOT_DEBUG
		asm("z_parameter_draw_action_label = 0x80088B84");
	#elif OOT_U_1_0
		asm("z_parameter_draw_action_label = 0x800739CC");
	#endif

/**
 * z_parameter
 */
#define Interface_DrawItemButtons z_parameter_draw_item_button
extern void z_parameter_draw_item_button(z64_gfx_t* gfx, uint32_t a1);
	#if OOT_DEBUG
		asm("z_parameter_draw_item_button = 0x80088CBC");
	#elif OOT_U_1_0
		asm("z_parameter_draw_item_button = 0x80073AB4");
	#endif

/**
 * z_parameter
 */
#define Interface_DrawItemIconTexture z_parameter_draw_item_icon
extern void z_parameter_draw_item_icon(z64_global_t* gl, uint32_t icon_texture, uint32_t button);
	#if OOT_DEBUG
		asm("z_parameter_draw_item_icon = 0x80089B00");
	#elif OOT_U_1_0
		asm("z_parameter_draw_item_icon = 0x800748DC");
	#endif

/**
 * z_parameter
 */
#define Interface_DrawAmmoCount z_parameter_draw_ammo
extern void z_parameter_draw_ammo(z64_global_t* gl, uint32_t icon_texture, uint32_t button);
	#if OOT_DEBUG
		asm("z_parameter_draw_ammo = 0x80089CF8");
	#elif OOT_U_1_0
		asm("z_parameter_draw_ammo = 0x80074A84");
	#endif

/**
 * Draw an A button to the HUD overlay.
 */
#define Interface_DrawActionButton z_parameter_draw_action_button
extern void z_parameter_draw_action_button(z64_global_t* gl);
	#if OOT_DEBUG
		asm("z_parameter_draw_action_button = 0x8008A1BC");
	#elif OOT_U_1_0
		asm("z_parameter_draw_action_button = 0x80074F24");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8008A3E0(z64_global_t* gl);
	#if OOT_DEBUG
		asm("external_func_8008A3E0 = 0x8008A3E0");
	#elif OOT_U_1_0
		/*asm("external_func_8008A3E0 = 0xDEADBEEF");*/
	#endif

/**
 * TODO This function is completely undocumented
 */
//Interface_InitVertices
extern void external_func_8008A8B8(z64_global_t* gl, int32_t a1, int32_t a2, int32_t a3, int32_t sp10);
	#if OOT_DEBUG
		asm("external_func_8008A8B8 = 0x8008A8B8");
	#elif OOT_U_1_0
		asm("external_func_8008A8B8 = 0x80075108");
	#endif

/**
 * Initializes a 320 x 240 viewport for the game's HUD and writes a projection matrix to RAM.
 */
extern void z_if_viewport_init(z64_if_ctxt_t* if_ctxt);
	#if OOT_DEBUG
		asm("z_if_viewport_init = 0x8008A994");
	#elif OOT_U_1_0
		asm("z_if_viewport_init = 0x800756A8");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8008E4E0(void);
	#if OOT_DEBUG
		asm("external_func_8008E4E0 = 0x8008E4E0");
	#elif OOT_U_1_0
		asm("external_func_8008E4E0 = 0x80078F80");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8008E520(void);
	#if OOT_DEBUG
		asm("external_func_8008E520 = 0x8008E520");
	#elif OOT_U_1_0
		asm("external_func_8008E520 = 0x80078FC4");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8008E60C(void);
	#if OOT_DEBUG
		asm("external_func_8008E60C = 0x8008E60C");
	#elif OOT_U_1_0
		asm("external_func_8008E60C = 0x800790B0");
	#endif

/**
 * Tests if Link is busy?
 * TODO How do we reference Link's instance? void should be fine, but test confirm in-game. Also, return value type.
 * A0 = Global Context | A1 = Link Instance | V0 = 1 if true, 0 if false
 */
extern int32_t player_is_busy(z64_global_t *global, void *link_instance);
	#if OOT_DEBUG
		asm("player_is_busy = 0x8008E8DC");
	#elif OOT_U_1_0
		asm("player_is_busy = 0x8007938C");
	#endif

/**
 * Tests if Link is busy (Calls 8007938C, but also checks if talking?)
 * TODO Confirm return type, test in-game
 */
extern int32_t player_is_busy_talking(z64_global_t *global);
	#if OOT_DEBUG
		asm("player_is_busy_talking = 0x8008E988");
	#elif OOT_U_1_0
		asm("player_is_busy_talking = 0x8007943C");
	#endif

/**
 * ? Related to updating Child Link's state if Hylian Shield is equipped
 * TODO These notes need converted into a C function prototype
 * A0 = Link Instance | A1 = 1 if 800794B0 returns 1, else 0
 */
extern void external_func_8008EC04(void);
	#if OOT_DEBUG
		asm("external_func_8008EC04 = 0x8008EC04");
	#elif OOT_U_1_0
		asm("external_func_8008EC04 = 0x800796C0");
	#endif

/**
 * Update Bottle Contents, Link's Action State | //Calls 80071B7C
 * TODO These notes need converted into a C function prototype
 * A0 = Global Context | A1 = Link Instance | A2 = Item Index (C-Item) | A3 = Action Parameter
 */
extern void external_func_8008ED9C(void);
	#if OOT_DEBUG
		asm("external_func_8008ED9C = 0x8008ED9C");
	#elif OOT_U_1_0
		asm("external_func_8008ED9C = 0x80079854");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8008EEAC(void);
	#if OOT_DEBUG
		asm("external_func_8008EEAC = 0x8008EEAC");
	#elif OOT_U_1_0
		asm("external_func_8008EEAC = 0x80079968");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8008EF44(void);
	#if OOT_DEBUG
		asm("external_func_8008EF44 = 0x8008EF44");
	#elif OOT_U_1_0
		asm("external_func_8008EF44 = 0x80079A04");
	#endif

/**
 * z_player_lib.c
 */
extern int32_t external_func_8008EF5C(z64_global_t* gl, vec3f_t* pos, float radius, float u0);
	#if OOT_DEBUG
		asm("external_func_8008EF5C = 0x8008EF5C");
	#elif OOT_U_1_0
		asm("external_func_8008EF5C = 0x80079A20");
	#endif

/**
 * Get Strength Upgrade Power Level
 * TODO These notes need converted into a C function prototype
 * V0 = 0 if no upgrades, Highest Upgrade if Adult, or 1 if Child and Upgrade &gt; 0
 */
extern void external_func_8008F034(void);
	#if OOT_DEBUG
		asm("external_func_8008F034 = 0x8008F034");
	#elif OOT_U_1_0
		asm("external_func_8008F034 = 0x80079AF8");
	#endif

/**
 * Get Link's Mask (Instance + 0x14F)
 * TODO Confirm return type, test in-game
 * TODO This function needs more explanation, what exactly does it do?
 * A0 = Global Context | V0 = Id
 */
extern uint8_t player_get_mask(z64_global_t *global);
	#if OOT_DEBUG
		asm("player_get_mask = 0x8008F080");
	#elif OOT_U_1_0
		asm("player_get_mask = 0x80079B44");
	#endif

/**
 * Set Link's Mask (Instance + 0x14F)
 * TODO This function needs more explanation, what exactly does it do?
 * A0 = Global Context
 */
extern void player_set_mask(z64_global_t *global);
	#if OOT_DEBUG
		asm("player_set_mask = 0x8008F08C");
	#elif OOT_U_1_0
		asm("player_set_mask = 0x80079B54");
	#endif

/**
 * Test if Link is wearing the Mirror Shield (Instance + 0x13E)
 * returns 0 on false, 1 on true
 */
extern int32_t player_is_mirrorshield(z64_global_t *global);
	#if OOT_DEBUG
		asm("player_is_mirrorshield = 0x8008F098");
	#elif OOT_U_1_0
		asm("player_is_mirrorshield = 0x80079B64");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8008F0AC(void);
	#if OOT_DEBUG
		asm("external_func_8008F0AC = 0x8008F0AC");
	#elif OOT_U_1_0
		asm("external_func_8008F0AC = 0x80079B7C");
	#endif

/**
 * Test if Link Item Action (Instance + 0x141) is Hookshot/Longshot
 * TODO How do we reference Link's instance? void should be fine, but test confirm in-game. Also, return value type.
 * returns false (0) true (1)
 */
extern int32_t player_is_hookshotting(void *link_instance);
	#if OOT_DEBUG
		asm("player_is_hookshotting = 0x8008F104");
	#elif OOT_U_1_0
		asm("player_is_hookshotting = 0x80079BD4");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8008FCC8(void);
	#if OOT_DEBUG
		asm("external_func_8008FCC8 = 0x8008FCC8");
	#elif OOT_U_1_0
		asm("external_func_8008FCC8 = 0x8007A740");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_80090480(void);
	#if OOT_DEBUG
		asm("external_func_80090480 = 0x80090480");
	#elif OOT_U_1_0
		asm("external_func_80090480 = 0x8007AF14");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_80090D20(void);
	#if OOT_DEBUG
		asm("external_func_80090D20 = 0x80090D20");
	#elif OOT_U_1_0
		asm("external_func_80090D20 = 0x8007B734");
	#endif

/**
 * TODO This function is completely undocumented
 * This function is not used inside any existing overlay
 */
extern void external_func_8009214C(void);
	#if OOT_DEBUG
		asm("external_func_8009214C = 0x8009214C");
	#elif OOT_U_1_0
		asm("external_func_8009214C = 0x8007CA54");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_80092DAC(void);
	#if OOT_DEBUG
		asm("external_func_80092DAC = 0x80092DAC");
	#elif OOT_U_1_0
		asm("external_func_80092DAC = 0x8007D668");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_80092DF0(void);
	#if OOT_DEBUG
		asm("external_func_80092DF0 = 0x80092DF0");
	#elif OOT_U_1_0
		asm("external_func_80092DF0 = 0x8007D6B0");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_80092E70(void);
	#if OOT_DEBUG
		asm("external_func_80092E70 = 0x80092E70");
	#elif OOT_U_1_0
		asm("external_func_80092E70 = 0x8007D738");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_80092F88(void);
	#if OOT_DEBUG
		asm("external_func_80092F88 = 0x80092F88");
	#elif OOT_U_1_0
		asm("external_func_80092F88 = 0x8007D85C");
	#endif

/**
 * TODO This function is completely undocumented
 */
#define Gfx_SetFog z_rcp_fog_set
extern Gfx* z_rcp_fog_set(Gfx* gfx, int32_t r, int32_t g, int32_t b, int32_t a, int32_t n, int32_t f);
	#if OOT_DEBUG
		asm("z_rcp_fog_set = 0x80093370");
	#elif OOT_U_1_0
		asm("z_rcp_fog_set = 0x8007DC40");
	#endif

/**
 * Used when setting Link's damage color.
 */
#define Gfx_SetFog2 z_rcp_fog_set_2
extern Gfx* z_rcp_fog_set_2(Gfx* gfx, int32_t r, int32_t g, int32_t b, int32_t a, int32_t n, int32_t f);
	#if OOT_DEBUG
		asm("z_rcp_fog_set_2 = 0x80093708");
	#elif OOT_U_1_0
		asm("z_rcp_fog_set_2 = 0x8007DF4C");
	#endif

/**
 * Wrapper for 8009373C; Set up a display list.
 */
#define Gfx_CallSetupDL z_rcp_set_dlist
extern Gfx* z_rcp_set_dlist(Gfx* gfx, uint32_t i);
	#if OOT_DEBUG
		asm("z_rcp_set_dlist = 0x80093774");
	#elif OOT_U_1_0
		asm("z_rcp_set_dlist = 0x8007DFBC");
	#endif

/**
 * Write DE000000 80126D30 to Display List
 */
extern Gfx* external_func_800937C0(Gfx *p);
	#if OOT_DEBUG
		asm("external_func_800937C0 = 0x800937C0");
	#elif OOT_U_1_0
		asm("external_func_800937C0 = 0x8007E008");
	#endif

/**
 * Jump To Display List
 */
extern void external_func_80094140(z64_gfx_t *g);
	#if OOT_DEBUG
		asm("external_func_80094140 = 0x80094140");
	#elif OOT_U_1_0
		/*asm("external_func_80094140 = 0xDEADBEEF");*/
	#endif

/**
 * Jump To Display List
 */
extern void external_func_80094520(z64_gfx_t *g);
	#if OOT_DEBUG
		asm("external_func_80094520 = 0x80094520");
	#elif OOT_U_1_0
		/*asm("external_func_80094520 = 0xDEADBEEF");*/
	#endif

/**
 * Write DE000000 80126A60 to Overlay
 */
extern void external_func_80094A14(z64_gfx_t *g);
	#if OOT_DEBUG
		asm("external_func_80094A14 = 0x80094A14");
	#elif OOT_U_1_0
		asm("external_func_80094A14 = 0x8007E09C");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_80093C14(void);
	#if OOT_DEBUG
		asm("external_func_80093C14 = 0x80093C14");
	#elif OOT_U_1_0
		asm("external_func_80093C14 = 0x8007E204");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_80093C80(void);
	#if OOT_DEBUG
		asm("external_func_80093C80 = 0x80093C80");
	#elif OOT_U_1_0
		asm("external_func_80093C80 = 0x8007E22C");
	#endif

/* This appends `DE000000 80126730 (NZLE)` to the POLY_OPA Display List Buffer
* This display list seems to contain a preset combiner and geometry mode.
* Source Code Reference File: "z_rcp.c"
*/
extern void z_rcp_append_preset_opa(
z64_gfx_t* gfx_ctxt /* Graphics Context, within Global Context */
);
#if OOT_DEBUG
  asm("z_rcp_append_preset_opa = 0x80093D18");
#elif OOT_U_1_0
  asm("z_rcp_append_preset_opa = 0x8007E298");
#elif MM_U_1_0
  asm("z_rcp_append_preset_opa = 0x8012C28C");
#endif

/* This appends `DE000000 80126730 (NZLE)` to the POLY_XLU Display List Buffer
* This display list seems to contain a preset combiner and geometry mode.
* Source Code Reference File: "z_rcp.c"
*/
extern void z_rcp_append_preset_xlu_80093D84(
z64_gfx_t* gfx_ctxt /* Graphics Context, within Global Context */
);
#if OOT_DEBUG
  asm("z_rcp_append_preset_xlu_80093D84 = 0x80093D84");
#elif OOT_U_1_0
  asm("z_rcp_append_preset_xlu_80093D84 = 0x80093D84");
#elif MM_U_1_0
  asm("z_rcp_append_preset_xlu_80093D84 = 0x8012C3DC");
#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_80093F34(void);
	#if OOT_DEBUG
		asm("external_func_80093F34 = 0x80093F34");
	#elif OOT_U_1_0
		asm("external_func_80093F34 = 0x8007E388");
	#endif

/* This appends `DE000000 80126AC0 (NZLE)` to the POLY_XLU Display List Buffer
* This display list seems to contain a preset combiner and geometry mode.
* Source Code Reference File: "z_rcp.c"
*/
extern void z_rcp_append_preset_xlu_80094044(
z64_gfx_t* gfx_ctxt /* Graphics Context, within Global Context */
);
#if OOT_DEBUG
  asm("z_rcp_append_preset_xlu_80094044 = 0x80094044");
#elif OOT_U_1_0
  asm("z_rcp_append_preset_xlu_80094044 = 0x8007E544");
#elif MM_U_1_0
  /*asm("z_rcp_append_preset_xlu_80094044 = 0xDEADBEEF");*/
#endif

/**
 * Write Jump to Display List 800F8440 on POLY_OPA_DISP
 * TODO These notes need converted into a C function prototype
 * A0 = Global Context
 */
extern void external_func_800943C8(void);
	#if OOT_DEBUG
		asm("external_func_800943C8 = 0x800943C8");
	#elif OOT_U_1_0
		asm("external_func_800943C8 = 0x8007E56C");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void interface_jump_to_main_dlist(z64_gfx_t *gfx_ctxt);
	#if OOT_DEBUG
		asm("external_func_80094520 = 0x80094520");
	#elif OOT_U_1_0
		asm("external_func_80094520 = 0x8007E5BC");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8009457C(void);
	#if OOT_DEBUG
		asm("external_func_8009457C = 0x8009457C");
	#elif OOT_U_1_0
		asm("external_func_8009457C = 0x8007E63C");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8009460C(void);
	#if OOT_DEBUG
		asm("external_func_8009460C = 0x8009460C");
	#elif OOT_U_1_0
		asm("external_func_8009460C = 0x8007E690");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_80094968(void);
	#if OOT_DEBUG
		asm("external_func_80094968 = 0x80094968");
	#elif OOT_U_1_0
		asm("external_func_80094968 = 0x8007E824");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_80094B58(z64_gfx_t* gfx_ctxt);
	#if OOT_DEBUG
		asm("external_func_80094B58 = 0x80094B58");
	#elif OOT_U_1_0
		asm("external_func_80094B58 = 0x8007E908");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_80094BC4(void);
	#if OOT_DEBUG
		asm("external_func_80094BC4 = 0x80094BC4");
	#elif OOT_U_1_0
		asm("external_func_80094BC4 = 0x8007E930");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_80094C50(void);
	#if OOT_DEBUG
		asm("external_func_80094C50 = 0x80094C50");
	#elif OOT_U_1_0
		asm("external_func_80094C50 = 0x8007E978");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_80094D28(void);
	#if OOT_DEBUG
		asm("external_func_80094D28 = 0x80094D28");
	#elif OOT_U_1_0
		asm("external_func_80094D28 = 0x8007E9C8");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_80094E78(void);
	#if OOT_DEBUG
		asm("external_func_80094E78 = 0x80094E78");
	#elif OOT_U_1_0
		asm("external_func_80094E78 = 0x8007EADC");
	#endif

/* This alocates an 0x18 byte `settilesize` structure.
* 0xE8, 0xF2, 0xDF
* Source Code Reference File: "z_rcp.c"
*/
#define Gfx_TexScroll z_rcp_gen_1_settilesize
extern Gfx* z_rcp_gen_1_settilesize(
z64_gfx_t* gfx_ctxt /* Graphics Context, within Global Context */
, int32_t tile0 /* Tile Descriptor 0; Layer 1 */
, int32_t s0_ul /* Upper-left S(X) Coordinate for Tile 0 */
, int32_t t0_ul /* Upper-left T(Y) Coordinate for Tile 0 */
, int32_t t0_w /* Tile 0 Width */
, int32_t t0_h /* Tile 0 Height */
);
#if OOT_DEBUG
  asm("z_rcp_gen_1_settilesize = 0x80094E9C");
#elif OOT_U_1_0
  asm("z_rcp_gen_1_settilesize = 0x8007EB00");
#elif MM_U_1_0
  asm("z_rcp_gen_1_settilesize = 0x8012CB4C");
#endif

/* This alocates a 0x28 byte `settilesize` structure.
* 0xE8, 0xF2, 0xE8, 0xF2, 0xDF
* Commonly used for animating two multitextured tiles.
* Source Code Reference File: "z_rcp.c"
* Formerly `f3dzex_gen_settilesize`
*/
#define Gfx_TwoTexScroll z_rcp_gen_2_settilesize
extern Gfx* z_rcp_gen_2_settilesize(
z64_gfx_t* gfx_ctxt /* Graphics Context, within Global Context */
, int32_t tile0 /* Tile Descriptor 0; Layer 1 */
, int32_t s0_ul /* Upper-left S(X) Coordinate for Tile 0 */
, int32_t t0_ul /* Upper-left T(Y) Coordinate for Tile 0 */
, int32_t t0_w /* Tile 0 Width */
, int32_t t0_h /* Tile 0 Height */
, int32_t tile1 /* Tile Descriptor 1; Layer 2 */
, int32_t s1_ul /* Upper-left S(X) Coordinate for Tile 1 */
, int32_t t1_ul /* Upper-left T(Y) Coordinate for Tile 1 */
, int32_t t1_w /* Tile 1 Width */
, int32_t t1_h /* Tile 1 Height */
);
#if OOT_DEBUG
  asm("z_rcp_gen_2_settilesize = 0x80094F40");
#elif OOT_U_1_0
  asm("z_rcp_gen_2_settilesize = 0x8007EB84");
#elif MM_U_1_0
  asm("z_rcp_gen_2_settilesize = 0x8012CBD0");
#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_80095068(void);
	#if OOT_DEBUG
		asm("external_func_80095068 = 0x80095068");
	#elif OOT_U_1_0
		asm("external_func_80095068 = 0x8007ECA4");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800951D0(void);
	#if OOT_DEBUG
		asm("external_func_800951D0 = 0x800951D0");
	#elif OOT_U_1_0
		asm("external_func_800951D0 = 0x8007EE04");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_80095248(z64_gfx_t* gfx, uint8_t a1, uint8_t a2, uint8_t a3);
	#if OOT_DEBUG
		asm("external_func_80095248 = 0x80095248");
	#elif OOT_U_1_0
		/*asm("external_func_800951D0 = 0xDEADBEEF");*/
	#endif

/**
 * Load Room
 * TODO These notes need converted into a C function prototype
 * A0 = Global Context | A1 = Global Context + 0x11CBC (Room Context) | A2 = Room ID
 */
extern void external_func_8009728C(void);
	#if OOT_DEBUG
		asm("external_func_8009728C = 0x8009728C");
	#elif OOT_U_1_0
		asm("external_func_8009728C = 0x80080A3C");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_80097534(void);
	#if OOT_DEBUG
		asm("external_func_80097534 = 0x80097534");
	#elif OOT_U_1_0
		asm("external_func_80097534 = 0x80080C98");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_80097A54(void);
	#if OOT_DEBUG
		asm("external_func_80097A54 = 0x80097A54");
	#elif OOT_U_1_0
		asm("external_func_80097A54 = 0x80081188");
	#endif


/* Load an object from ROM into RAM and allocates it in the scene.
* This loads an object into memory even if it is already loaded.
* Source Code Reference File: "z_scene.c"
* Formerly `object_load`
*/
#define Object_Spawn z_scene_object_load
extern int32_t z_scene_object_load(
z64_obj_ctxt_t* obj_ctxt /* The Object Context, within the Global Context */
, int32_t id /* The object file ID */
);
#if OOT_DEBUG
  asm("z_scene_object_load = 0x80097C00");
#elif OOT_U_1_0
  asm("z_scene_object_load = 0x800812F0");
#elif MM_U_1_0
  asm("z_scene_object_load = 0x8012F2E0");
#elif MM_J_1_0
  asm("z_scene_object_load = 0x80130D50");
#elif MM_DEBUG
  asm("z_scene_object_load = 0x80155220");
#endif

/* Return the index of a loaded object index.
* Source Code Reference File: "z_scene.c"
* Formerly `object_get_index`
*/
#define Object_GetIndex z_scene_object_get_index
extern int32_t z_scene_object_get_index(
z64_obj_ctxt_t* obj_ctxt /* The Object Context, within the Global Context */
, int32_t id /* The object file ID */
);
#if OOT_DEBUG
  asm("z_scene_object_get_index = 0x8009812C");
#elif OOT_U_1_0
  asm("z_scene_object_get_index = 0x80081628");
#elif MM_U_1_0
  asm("z_scene_object_get_index = 0x8012F608");
#elif MM_J_1_0
  asm("z_scene_object_get_index = 0x80131078");
#elif MM_J_1_0
  asm("z_scene_object_get_index = 0x80155650");
#endif

/* Check if an object is loaded in the scene.
* Returns 0 on false, 1 on true
* Source Code Reference File: "z_scene.c"
* Formerly `object_is_loaded`
*/
#define Object_IsLoaded z_scene_object_is_loaded
extern int32_t z_scene_object_is_loaded(
z64_obj_ctxt_t* obj_ctxt /* The Object Context, within the Global Context */
, int32_t id /* The object file ID */
);
#if OOT_DEBUG
  asm("z_scene_object_is_loaded = 0x80098188");
#elif OOT_U_1_0
  asm("z_scene_object_is_loaded = 0x80081688");
#elif MM_U_1_0
  asm("z_scene_object_is_loaded = 0x8012F668");
#elif MM_J_1_0
  asm("z_scene_object_is_loaded = 0x801310D8");
#elif MM_DEBUG
  asm("z_scene_object_is_loaded = 0x801556B0");
#endif

/**
 * TODO This function is completely undocumented
 */
#define SkelAnime_LodDraw z_skelanime_draw_lod
extern void z_skelanime_draw_lod(z64_global_t* gl, z64_skeleton_t* skel, vec3s_t* limb_draw_table, void* override, void* postdraw, z64_actor_t* actor, int32_t dlist_idx);
	#if OOT_DEBUG
		asm("z_skelanime_draw_lod = 0x800A0B40");
	#elif OOT_U_1_0
		asm("z_skelanime_draw_lod = 0x8008902C");
	#endif

/* Draw a `skelanime` structure.
* This supports matrices and a `Level Of Detail` hierarchy.
* This function is used to draw Link.
* Source Code Reference File: "z_skelanime.c"
*/
#define SkelAnime_DrawSV2 z_skelanime_draw_mtx_lod
extern Gfx* z_skelanime_draw_mtx_lod(
z64_global_t* gl /* Global Context */
, uint32_t skeleton
, uint32_t animation
, uint32_t limb_dlists_count
, int32_t callback0(            /* callback0 must return 0 */
	  z64_global_t *global
	, uint8_t limb           /* limb index in skeleton */
	, uint32_t *dlist        /* *dlist = 0x06xxxxxx changes limb model */
	, vec3f_t *translation
	, vec3s_t *rotation
	, void *entity
  )
, void callback1(
	  z64_global_t *global
	, uint8_t limb
	, uint32_t dlist         /* different from callback0, needs more research */
	, vec3s_t *rotation
	, void *entity
  )
, void* instance
, Gfx* dest
);
#if OOT_DEBUG
  asm("z_skelanime_draw_mtx_lod = 0x800A273C"); /* 0x800A106C */
#elif OOT_U_1_0
  asm("z_skelanime_draw_mtx_lod = 0x800894A4");
#elif MM_U_1_0
  asm("z_skelanime_draw_mtx_lod = 0x80134DBC");
#endif

/* Draw a `skelanime` structure.
* This function supports both matrix and non-matrix formats; specify
* the number of limbs using matrices for a matrix format, 0 otherwise.
* Debug strings dub this function `Si2_draw()` (Skeleton Info 2; Draw)?
* Source Code Reference File: "z_skelanime.c"
* Formerly `skelanime_draw`
*/
static inline void z_skelanime_draw(
z64_global_t* gl       /* Global Context */
, int matrix_limbs     /* Number of matrix limbs, or 0 if non-matrix */
, void* instance       /* A pointer to the actor instance */
, z64_skelanime_t *sk  /* Skelanime */
, int32_t callback0(      /* This must return 0 */
	z64_global_t* gl       /* Global Context */
	, int32_t limb         /* Current Limb */
	, uint32_t* dlist      /* Display List Pointer */
	, vec3f_t* translation /* Limb Translation */
	, vec3s_t* rotation    /* Limb Rotation */
	, void* instance       /* Current instance pointer (entity_t) */
	)
, void callback1(         /* An internal callback function. */
	z64_global_t* gl       /* Global Context */
	, int32_t limb         /* Current Limb */
	, uint32_t dlist       /* Display List */
	, vec3s_t* rotation    /* Limb Rotation */
	, void* instance       /* Current instance pointer (entity_t) */
	)
) {
	if (matrix_limbs)
		_z_skelanime_draw_mtx(
			gl
			, sk->skeleton
			, sk->limb_draw_table
			, matrix_limbs
			, callback0
			, callback1
			, instance
		);
	else
		_z_skelanime_draw(
			gl
			, sk->skeleton
			, sk->limb_draw_table
			, callback0
			, callback1
			, instance
		);
}

/* Return Animation Frame Count
* Source Code Reference File: "z_skelanime.c"
* Formerly `anime_get_framecount`
*/
#define SkelAnime_GetFrameCount z_skelanime_anim_nframes
extern int32_t z_skelanime_anim_nframes(
uint32_t anim /* Segment-relative Animation Offset */
);
#if OOT_DEBUG
  asm("z_skelanime_anim_nframes = 0x800A2000");
#elif OOT_U_1_0
  asm("z_skelanime_anim_nframes = 0x8008A194");
#elif MM_U_1_0
  asm("z_skelanime_anim_nframes = 0x80134748");
#endif

/**
 * Draw an object skeleton on a specific destination buffer
 * TODO Variable name cleanup, better notes
 * A0 = Global Context | A1 = Hierarchy Limb Index (in Object File, in RAM) | A2 = Pointer to Actor Drawing Table | A3 = 0 | 0x0010(SP) = 0 | 0x0014(SP) = Actor Instance Address | 0x0018(SP) = Buffer
 */
#define SkelAnime_Draw2 z_skelanime_draw_dest
extern Gfx* z_skelanime_draw_dest(z64_global_t *global, uint32_t limb_index, uint32_t adt, void* subr0, void* subr1, z64_actor_t *actor, Gfx *gfx_buffer);
	#if OOT_DEBUG
		asm("z_skelanime_draw_dest = 0x800A2288");
	#elif OOT_U_1_0
		asm("z_skelanime_draw_dest = 0x8008A1DC");
	#endif

/**
 * TODO Draw a matrix-enabled object skeleton on a specific destination buffer
 */
extern Gfx* z_skelanime_draw_mtx_destination(z64_global_t *global, uint32_t limb_index, void* adt, uint8_t limb_dlists_count, void* subr0, void* subr1, z64_actor_t *actor, void *gfx_buffer);
	#if OOT_DEBUG
		asm("z_skelanime_draw_mtx_destination = 0x800A273C");
	#elif OOT_U_1_0
		asm("z_skelanime_draw_mtx_destination = 0x8008A608");
	#endif

/**
 * TODO This function is completely undocumented
 */
#define SkelAnime_InterpolateVec3s z_skelanime_interpolate_vec3s
extern void z_skelanime_interpolate_vec3s(int32_t a, vec3s_t* b, vec3s_t* c, vec3s_t* d, float e);
	#if OOT_DEBUG
		asm("z_skelanime_interpolate_vec3s = 0x800A2E70");
	#elif OOT_U_1_0
		asm("z_skelanime_interpolate_vec3s = 0x8008AFB8");
	#endif

/**
 * TODO This function is completely undocumented
 */
#define SkelAnime_LoadAnimationType3 z_skelanime_load_anim_3
extern void z_skelanime_load_anim_3(z64_global_t* gl, int32_t nvec, vec3s_t* dst, vec3s_t* src, uint8_t* idx);
	#if OOT_DEBUG
		asm("z_skelanime_load_anim_3 = 0x800A3548");
	#elif OOT_U_1_0
		asm("z_skelanime_load_anim_3 = 0x8008B698");
	#endif

/**
 * TODO This function is completely undocumented
 */
#define SkelAnime_LoadAnimationType5 z_skelanime_load_anim_5
extern void z_skelanime_load_anim_5(z64_global_t* gl, z64_actor_t* actor, z64_skelanime_t* skl, float a3);
	#if OOT_DEBUG
		asm("z_skelanime_load_anim_5 = 0x800A3620");
	#elif OOT_U_1_0
		asm("z_skelanime_load_anim_5 = 0x8008B778");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800A3BC0(void);
	#if OOT_DEBUG
		asm("external_func_800A3BC0 = 0x800A3BC0");
	#elif OOT_U_1_0
		asm("external_func_800A3BC0 = 0x8008BCA4");
	#endif

/* Initialize a "Skelanime Structure"
* This function will use the matrix-specific function if you provide
* a non-zero value for is_matrix.
* Source Code Reference File: "z_skelanime.c"
* Formerly `skelanime_init`
*/
static inline void z_skelanime_init(
z64_global_t* gl /* Global Context */
, int is_matrix
, z64_skelanime_t* sk /* Skelanime Structure */
, uint32_t skeleton /* Segment-relative offset of Skeleton */
, uint32_t anim /* Segment-relative offset of animation to initialize with */
)
{
	if (is_matrix)
		_z_skelanime_mtx_init(gl, sk, skeleton, anim, 0, 0, 0);

	else
		_z_skelanime_init(gl, sk, skeleton, anim, 0, 0, 0);
}

/* Initialize a "Skelanime Structure"
* Same as above, but with extended functionality; you can manually specify
* pre-allocated draw table blocks, usually from the instance structure.
*/
static inline void z_skelanime_init_ext(
z64_global_t* gl /* Global Context */
, int is_matrix
, z64_skelanime_t* sk /* Skelanime Structure */
, uint32_t skeleton /* Segment-relative offset of Skeleton */
, uint32_t anim /* Segment-relative offset of animation to initialize with */
, vec3s_t* dt_rot /* Limb-based variable size structure (Draw Table Rotations) If 0, the game automatically allocates memory for this. */
, vec3s_t* dt_pos /* Limb-based variable size structure (Draw Table Positions) If 0, the game automatically allocates memory for this. */
, uint32_t nlimb /* Total Limb Count + 1 */
)
{
	if (is_matrix)
		_z_skelanime_mtx_init(gl, sk, skeleton, anim, dt_rot, dt_pos, nlimb);

	else
		_z_skelanime_init(gl, sk, skeleton, anim, dt_rot, dt_pos, nlimb);
}

/* This executes an actor's `skelanime draw table function`
* Source Code Reference File: "z_skelanime.c"
* Formerly `actor_anime_frame_update_mtx`
*/
#define SkelAnime_FrameUpdateMatrix z_skelanime_update_anim
#define z_skelanime_draw_table z_skelanime_update_anim
extern int32_t z_skelanime_update_anim(
z64_skelanime_t* s /* Skelanime Structure */
);
#if OOT_DEBUG
  asm("z_skelanime_update_anim = 0x800A49FC");
#elif OOT_U_1_0
  asm("z_skelanime_update_anim = 0x8008C9C0");
#elif MM_U_1_0
  asm("z_skelanime_update_anim = 0x80136CD0");
#endif

/**
 * Change an actor's current animation.
 * Source Code Reference File: "z_skelanime.c"
 */
#define SkelAnime_ChangeAnimImpl z_skelanime_change_anim_impl
extern void z_skelanime_change_anim_impl(z64_skelanime_t* sk, z64_anim_header_t* anim, float playback_speed, float frame, float nframes, uint8_t unk, float transition_rate, int8_t unk2);
	#if OOT_DEBUG
		asm("z_skelanime_change_anim_impl = 0x800A4FE4");
	#elif OOT_U_1_0
		asm("z_skelanime_change_anim_impl = 0x8008CFC0");
	#elif MM_U_1_0
		asm("z_skelanime_change_anim_impl = 0x8013722C");
	#endif

/* Change an actor's current animation.
* Wrapper for 800A4FE4
* Source Code Reference File: "z_skelanime.c"
* Formerly `actor_anime_change`
*/
#define SkelAnime_ChangeAnim z_skelanime_change_anim
extern void z_skelanime_change_anim(
z64_skelanime_t* sk /* Skelanime Structure */
, uint32_t anim /* Segment-relative Animation Offset */
, float speed /* Speed at which to play back the animation */
, float frame_begin /* Starting Animation Frame */
, int frame_count /* The amount of frames to play from this animation, 0 to play them all. */
, uint32_t unk_1 /* Unidentified */
, float xrate /* Transition Rate (Automatic Interpolation Between Frames) */
);
#if OOT_DEBUG
  asm("z_skelanime_change_anim = 0x800A51A0");
#elif OOT_U_1_0
  asm("z_skelanime_change_anim = 0x8008D17C");
#elif MM_U_1_0
  asm("z_skelanime_change_anim = 0x801373E8");
#endif

/* Change Animation
* Source Code Reference File: "z_skelanime.c"
*/
#define SkelAnime_ChangeAnimDefaultStop z_skelanime_change_anim_default_stop
extern void z_skelanime_change_anim_default_stop(
z64_skelanime_t* s /* Skelanime Structure */
, uint32_t anim /* Segment-relative Animation Address */
);
#if OOT_DEBUG
  asm("z_skelanime_change_anim_default_stop = 0x800A51E8");
#elif OOT_U_1_0
  asm("z_skelanime_change_anim_default_stop = 0x8008D1C4");
#elif MM_U_1_0
  /*asm("z_skelanime_change_anim_default_stop = 0xDEADBEEF");*/
#endif

/* Change Animation and Transition Rate
* Source Code Reference File: "z_skelanime.c"
*/
#define SkelAnime_ChangeAnimTransitionStop z_skelanime_change_anim_trate
extern void z_skelanime_change_anim_trate(
z64_skelanime_t* s /* Skelanime Structure */
, uint32_t anim /* Segment-relative Animation Address */
, float trate /* Transition Rate */
);
#if OOT_DEBUG
  asm("z_skelanime_change_anim_trate = 0x800A5240");
#elif OOT_U_1_0
  asm("z_skelanime_change_anim_trate = 0x8008D21C");
#elif MM_U_1_0
  /*asm("z_skelanime_change_anim_trate = 0xDEADBEEF");*/
#endif

/* Change Animation
* Modify Start Frame
* Source Code Reference File: "z_skelanime.c"
*/
#define SkelAnime_ChangeAnimPlaybackStop z_skelanime_change_anim_playback
extern void z_skelanime_change_anim_playback(
z64_skelanime_t* s /* Skelanime Structure */
, uint32_t anim /* Segment-relative Animation Address */
, float playback_speed
);
#if OOT_DEBUG
  asm("z_skelanime_change_anim_playback = 0x800A529C");
#elif OOT_U_1_0
  asm("z_skelanime_change_anim_playback = 0x8008D278");
#elif MM_U_1_0
  /*asm("z_skelanime_change_anim_playback = 0xDEADBEEF");*/
#endif

/* Set Animation
* Wrapper for `z_skelanime_change_anim`
* Wrapper for `z_skelanime_get_frame_count`
* Source Code Reference File: "z_skelanime.c"
*/
#define SkelAnime_ChangeAnimDefaultRepeat z_skelanime_anim_set
extern void z_skelanime_anim_set(
z64_skelanime_t* s /* Skelanime Structure */
, uint32_t anim /* Segment-relative Animation Address */
);
#if OOT_DEBUG
  asm("z_skelanime_anim_set = 0x800A52F8");
#elif OOT_U_1_0
  asm("z_skelanime_anim_set = 0x8008D2D4");
#elif MM_U_1_0
  /*asm("z_skelanime_anim_set = 0xDEADBEEF");*/
#endif

/* Change Animation
* Playback speed defaulted to 1.0f
* Start frame defaulted to 0
* Source Code Reference File: "z_skelanime.c"
*/
#define SkelAnime_ChangeAnimTransitionRepeat z_skelanime_change_frame_count
extern void z_skelanime_change_frame_count(
z64_skelanime_t* s /* Skelanime Structure */
, uint32_t anim /* Segment-relative Animation Address */
, float frame_count /* New Frame Count */
);
#if OOT_DEBUG
  asm("z_skelanime_change_frame_count = 0x800A534C");
#elif OOT_U_1_0
  asm("z_skelanime_change_frame_count = 0x8008D328");
#elif MM_U_1_0
  /*asm("z_skelanime_change_frame_count = 0xDEADBEEF");*/
#endif

/**
 * TODO This function is completely undocumented
 */
#define SkelAnime_ChangeAnimPlaybackRepeat z_skelanime_change_anim_playback_repeat
extern void z_skelanime_change_anim_playback_repeat(
z64_skelanime_t* s /* Skelanime Structure */
, uint32_t anim /* Segment-relative Animation Address */
, float playback_speed
);
#if OOT_DEBUG
	asm("z_skelanime_change_anim_playback_repeat = 0x800A5384");
#elif OOT_U_1_0
	asm("z_skelanime_change_anim_playback_repeat = 0x8008D360");
#endif

/**
 * TODO This function is completely undocumented
 */
#define SkelAnime_AnimReverse z_skelanime_anim_reverse
extern void z_skelanime_anim_reverse(z64_skelanime_t* sk);
	#if OOT_DEBUG
		asm("z_skelanime_anim_reverse = 0x800A5408");
	#elif OOT_U_1_0
		asm("z_skelanime_anim_reverse = 0x8008D3E4");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800A5428(void);
	#if OOT_DEBUG
		asm("external_func_800A5428 = 0x800A5428");
	#elif OOT_U_1_0
		asm("external_func_800A5428 = 0x8008D408");
	#endif

/* Test if an animation is at a specific frame.
* Source Code Reference File: "z_skelanime.c"
*/
extern int32_t z_skelanime_frame_index_test(
z64_skelanime_t* s /* Skelanime Struct */
, float frame /* Frame Index */
);
#if OOT_DEBUG
  asm("z_skelanime_frame_index_test = 0x800A56C8");
#elif OOT_U_1_0
  asm("z_skelanime_frame_index_test = 0x8008D6A8");
#elif MM_U_1_0
  /*asm("z_skelanime_frame_index_test = 0x80137594");*/
#endif

/**
 * TODO This function is completely undocumented
 */
#define SkelAnime_Free z_skelanime_free
extern void z_skelanime_free(z64_skelanime_t* skl, z64_global_t* gl);
	#if OOT_DEBUG
		asm("z_skelanime_free = 0x800A56F0");
	#elif OOT_U_1_0
		asm("z_skelanime_free = 0x8008D6D0");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800A5F60(void);
	#if OOT_DEBUG
		asm("external_func_800A5F60 = 0x800A5F60");
	#elif OOT_U_1_0
		asm("external_func_800A5F60 = 0x8008DE88");
	#endif

/**
 * Draw object that uses a weighted skeleton structure
 * A0 = Entity | A1 = Global Context | A2 = Skeleton | A3 = Callback | 0x0010(SP) = 1, something to do with Y translation?
 */
extern void skelanime_draw_weighted(z64_actor_t* actor, z64_global_t* global, z64_skelanime_weighted_t* weighted_skelanime, void* callback1, uint32_t unk0);
	#if OOT_DEBUG
		asm("skelanime_draw_weighted = 0x800A6330");
	#elif OOT_U_1_0
		asm("skelanime_draw_weighted = 0x8008E1D4");
	#endif

/**
 * Draw object that uses a weighted skeleton structure. Callback2 lets you set textures. Used by Epona.
 * A0 = Entity | A1 = Global Context | A2 = Skeleton | A3 = Callback | 0x0014(SP) = Texture setting callback | 0x0014(SP) = 1, something to do with Y translation?
 */
extern void skelanime_draw_weighted_unk(z64_actor_t* actor, z64_global_t* global, z64_skelanime_weighted_t* weighted_skelanime, void* callback1, void* callback2, uint32_t unk0);
    #if OOT_DEBUG
        asm("skelanime_draw_weighted_unk = 0x800A6360");
    #elif OOT_U_1_0
        asm("skelanime_draw_weighted_unk = 0x8008E204");
    #endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800A63CC(void);
	#if OOT_DEBUG
		asm("external_func_800A63CC = 0x800A63CC");
	#elif OOT_U_1_0
		asm("external_func_800A63CC = 0x8008E270");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800A6408(void);
	#if OOT_DEBUG
		asm("external_func_800A6408 = 0x800A6408");
	#elif OOT_U_1_0
		asm("external_func_800A6408 = 0x8008E2AC");
	#endif

/**
 * Initialize weighted skeleton object with animation
 * TODO Unknown variables, do something about that
 * a0 = Global Context | a1 = Skeleton) | a2 = Hierarchy Pointer (In Object) | a3 = Animation Pointer (In Object)
 */
extern void skelanime_init_weighted(z64_global_t *global, z64_skelanime_weighted_t *weighted_skelanime, uint32_t skeleton, uint32_t animation, uint8_t unk0, uint8_t unk1, uint8_t unk2);
	#if OOT_DEBUG
		asm("skelanime_init_weighted = 0x800A663C");
	#elif OOT_U_1_0
		asm("skelanime_init_weighted = 0x8008E4EC");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800A6888(void);
	#if OOT_DEBUG
		asm("external_func_800A6888 = 0x800A6888");
	#elif OOT_U_1_0
		asm("external_func_800A6888 = 0x8008E6BC");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800A6E10(void);
	#if OOT_DEBUG
		asm("external_func_800A6E10 = 0x800A6E10");
	#elif OOT_U_1_0
		asm("external_func_800A6E10 = 0x8008EC20");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800A6EF4(void);
	#if OOT_DEBUG
		asm("external_func_800A6EF4 = 0x800A6EF4");
	#elif OOT_U_1_0
		asm("external_func_800A6EF4 = 0x8008ED08");
	#endif

/**
 * Multiply Matrix
 */
extern void z_skin_mtx_multiply(float* in, float* mult, float* out);
	#if OOT_DEBUG
		asm("external_func_800A6FA0 = 0x800A6FA0");
	#elif OOT_U_1_0
		asm("external_func_800A6EF4 = 0x8008EDB8");
	#endif


/**
 * TODO This function is completely undocumented
 */
extern void external_func_800A7B04(void);
	#if OOT_DEBUG
		asm("external_func_800A7B04 = 0x800A7B04");
	#elif OOT_U_1_0
		asm("external_func_800A7B04 = 0x8008F890");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800A7E70(void);
	#if OOT_DEBUG
		asm("external_func_800A7E70 = 0x800A7E70");
	#elif OOT_U_1_0
		asm("external_func_800A7E70 = 0x8008FC98");
	#endif

/**
 * TODO This function is completely undocumented
 * This function is not used inside any existing overlay
 */
extern void external_func_800A9CD4(void);
	#if OOT_DEBUG
		asm("external_func_800A9CD4 = 0x800A9CD4");
	#elif OOT_U_1_0
		asm("external_func_800A9CD4 = 0x800912C4");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800A9F6C(float a, uint8_t b, uint8_t c, uint8_t d);
	#if OOT_DEBUG
		asm("external_func_800A9F6C = 0x800A9F6C");
	#elif OOT_U_1_0
		asm("external_func_800A9F6C = 0x8009151C");
	#endif

/**
 * Something to do with initializing the rumble pak.
 * This contains a loop. What's really happening?
 */
extern void external_func_800AA000(float a, uint8_t b, uint8_t duration, uint8_t step);
	#if OOT_DEBUG
		asm("external_func_800AA000 = 0x800AA000");
	#elif OOT_U_1_0
		asm("external_func_800AA000 = 0x800915CC");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800AA148(void);
	#if OOT_DEBUG
		asm("external_func_800AA148 = 0x800AA148");
	#elif OOT_U_1_0
		asm("external_func_800AA148 = 0x80091730");
	#endif

/**
 * Initializes the VIEW variables
 * TODO These notes need converted into a C function prototype
 * A0 = VIEW struct ptr | A1 = Graphics Context ptr
 * This function is not used inside any existing overlay
 */
extern void external_func_800AA278(void* view, z64_gfx_t* gfx);
	#if OOT_DEBUG
		asm("external_func_800AA278 = 0x800AA278");
	#elif OOT_U_1_0
		asm("external_func_800AA278 = 0x80091858");
	#endif

/**
 * TODO This function is completely undocumented
 * This function is not used inside any existing overlay
 */
extern void external_func_800AA358(void* view, vec3f_t* eye, vec3f_t* vec2, vec3f_t* vec3);
	#if OOT_DEBUG
		asm("external_func_800AA358 = 0x800AA358");
	#elif OOT_U_1_0
		asm("external_func_800AA358 = 0x80091918");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800AA4FC(void* view, void* viewport);
	#if OOT_DEBUG
		asm("external_func_800AA4FC = 0x800AA4FC");
	#elif OOT_U_1_0
		/*asm("external_func_800AA4FC = 0xDEADBEEF");*/
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800AAA50(void* view, int32_t a1);
	#if OOT_DEBUG
		asm("external_func_800AAA50 = 0x800AAA50");
	#elif OOT_U_1_0
		asm("external_func_800AAA50 = 0x80091F94");
	#endif

/**
 * sw A0, 800FE474($zero)
 * TODO These notes need converted into a C function prototype
 */
extern void external_func_800B3840(void);
	#if OOT_DEBUG
		asm("external_func_800B3840 = 0x800B3840");
	#elif OOT_U_1_0
		asm("external_func_800B3840 = 0x80099620");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800BB2B4(void);
	#if OOT_DEBUG
		asm("external_func_800BB2B4 = 0x800BB2B4");
	#elif OOT_U_1_0
		asm("external_func_800BB2B4 = 0x800999A4");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800BC490(void);
	#if OOT_DEBUG
		asm("external_func_800BC490 = 0x800BC490");
	#elif OOT_U_1_0
		asm("external_func_800BC490 = 0x8009A1B0");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800BC56C(void);
	#if OOT_DEBUG
		asm("external_func_800BC56C = 0x800BC56C");
	#elif OOT_U_1_0
		asm("external_func_800BC56C = 0x8009A25C");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800BC590(void);
	#if OOT_DEBUG
		asm("external_func_800BC590 = 0x800BC590");
	#elif OOT_U_1_0
		asm("external_func_800BC590 = 0x8009A284");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800BC8A0(void);
	#if OOT_DEBUG
		asm("external_func_800BC8A0 = 0x800BC8A0");
	#elif OOT_U_1_0
		asm("external_func_800BC8A0 = 0x8009A574");
	#endif

/**
 * Call 8007943C if Global Context + 0x1D6C (cutscene play state) is 0
 * TODO These notes need converted into a C function prototype
 * A0 = Global Context | V0 = 1 if ?, else 0
 */
extern int32_t external_func_800BFC84(z64_global_t* gl);
	#if OOT_DEBUG
		asm("external_func_800BFC84 = 0x800BFC84");
	#elif OOT_U_1_0
		asm("external_func_800BFC84 = 0x8009CB08");
	#endif

/**
 * Starts actor cutscene camera
 * returns camera ID
 * A0 - global context
 */
extern uint16_t start_cutscene_camera(z64_global_t *global);
	#if OOT_DEBUG
		asm("start_cutscene_camera = 0x800C0230");
	#elif OOT_U_1_0
		asm("start_cutscene_camera = 0x8009D0F0");
	#endif

/**
 * Camera related, use after 800C0230
 * TODO These notes need converted into a C function prototype
 * A0 - global context | A1 - unknown, set to 0 | A2 - unknown, set to 1
 */
extern void external_func_800C0314(z64_global_t *global, int32_t unk0, int32_t flags);
	#if OOT_DEBUG
		asm("external_func_800C0314 = 0x800C0314");
	#elif OOT_U_1_0
		asm("external_func_800C0314 = 0x8009D1AC");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800C0384(void);
	#if OOT_DEBUG
		asm("external_func_800C0384 = 0x800C0384");
	#elif OOT_U_1_0
		asm("external_func_800C0384 = 0x8009D21C");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800C0438(void);
	#if OOT_DEBUG
		asm("external_func_800C0438 = 0x800C0438");
	#elif OOT_U_1_0
		asm("external_func_800C0438 = 0x8009D284");
	#endif

/**
 * Cutscenes? Related to Cutscene Command 0x07
 * TODO These notes need converted into a C function prototype
 * A0 = Global Context | A1 = Cutscene Struct + 0x16
 */
extern void external_func_800C04A4(void);
	#if OOT_DEBUG
		asm("external_func_800C04A4 = 0x800C04A4");
	#elif OOT_U_1_0
		asm("external_func_800C04A4 = 0x8009D2F0");
	#endif

/**
 * Updates actor camera
 * TODO These notes need converted into a C function prototype
 * a0 - global context, a1 - set to 1 to update the camera , a2 - float array, camera focus point, a3 - float array, camera origin
 */
extern void update_cutscene_camera(z64_global_t *global, int16_t a1, vec3f_t *camera_focus_point, vec3f_t *camera_origin);
	#if OOT_DEBUG
		asm("update_cutscene_camera = 0x800C04D8");
	#elif OOT_U_1_0
		asm("update_cutscene_camera = 0x8009D328");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800C05E4(void);
	#if OOT_DEBUG
		asm("external_func_800C05E4 = 0x800C05E4");
	#elif OOT_U_1_0
		asm("external_func_800C05E4 = 0x8009D438");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800C0704(void);
	#if OOT_DEBUG
		asm("external_func_800C0704 = 0x800C0704");
	#elif OOT_U_1_0
		asm("external_func_800C0704 = 0x8009D55C");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800C078C(void);
	#if OOT_DEBUG
		asm("external_func_800C078C = 0x800C078C");
	#elif OOT_U_1_0
		asm("external_func_800C078C = 0x8009D5F0");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800C0808(void);
	#if OOT_DEBUG
		asm("external_func_800C0808 = 0x800C0808");
	#elif OOT_U_1_0
		asm("external_func_800C0808 = 0x8009D66C");
	#endif

/**
 * Ends actor cutscene camera
 * TODO unk0's size must be either 8 or 16 because of alignment found in the Arwing
 * A0 - global context | A1 - unknown, set to 1, A2 - End movement speed. If the value is not 0, it calls actor_closeup with arguments: global, 0x3F0, and this value.
 */
extern void end_cutscene_camera(z64_global_t *global, int16_t unk0, int32_t end_movement_speed);
	#if OOT_DEBUG
		asm("end_cutscene_camera = 0x800C08AC");
	#elif OOT_U_1_0
		asm("end_cutscene_camera = 0x8009D718");
	#endif

/**
 * Set Void, Grotto, Farore's Wind Checkpoint
 * TODO These notes need converted into a C function prototype
 * A0 = Global Context | A1 = Zoneout Type (0-2) | A2 = Link Spawn Variable
 */
extern void external_func_800C0AF4(void);
	#if OOT_DEBUG
		asm("external_func_800C0AF4 = 0x800C0AF4");
	#elif OOT_U_1_0
		asm("external_func_800C0AF4 = 0x8009D94C");
	#endif

/**
 * Triggers a "void out" (where you get reset to the last safe position, i.e when you take too long in the
 * Dampe Race, fall into a pit, etc.
 */
extern void z_void_out(z64_global_t *global);
	#if OOT_DEBUG
		asm("z_void_out = 0x800C0B60");
	#elif OOT_U_1_0
		asm("z_void_out = 0x8009D9B8");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800C0C88(void);
	#if OOT_DEBUG
		asm("external_func_800C0C88 = 0x800C0C88");
	#elif OOT_U_1_0
		asm("external_func_800C0C88 = 0x8009DAB0");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800C0CB8(void);
	#if OOT_DEBUG
		asm("external_func_800C0CB8 = 0x800C0CB8");
	#elif OOT_U_1_0
		asm("external_func_800C0CB8 = 0x8009DAE4");
	#endif

/**
 * Check if Game Updates are Disabled
 * returns 1 (V0 = 1) if Global Context + 0x7B8 > 0
 */
extern void game_updates_off(z64_global_t *global);
	#if OOT_DEBUG
		asm("game_updates_off = 0x800C0D28");
	#elif OOT_U_1_0
		asm("game_updates_off = 0x8009DB54");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800C0DB4(void);
	#if OOT_DEBUG
		asm("external_func_800C0DB4 = 0x800C0DB4");
	#elif OOT_U_1_0
		asm("external_func_800C0DB4 = 0x8009DBE4");
	#endif

/**
 * TODO This function is completely undocumented
 * This function is not used inside any existing overlay
 */
extern void external_func_800C0F08(void);
	#if OOT_DEBUG
		asm("external_func_800C0F08 = 0x800C0F08");
	#elif OOT_U_1_0
		asm("external_func_800C0F08 = 0x8009DD44");
	#endif

/**
 * TODO This function is completely undocumented
 * This function is not used inside any existing overlay
 */
extern void external_func_800C3770(void);
	#if OOT_DEBUG
		asm("external_func_800C3770 = 0x800C3770");
	#elif OOT_U_1_0
		asm("external_func_800C3770 = 0x8009FDEC");
	#endif

/**
 * TODO This function is completely undocumented
 * This function is not used inside any existing overlay
 */
extern uint32_t z_game_alloc(z64_global_t* gl, int32_t size, char* file, int32_t line);
	#if OOT_DEBUG
		asm("z_game_alloc = 0x800C5484");
	#elif OOT_U_1_0
		/*asm("z_game_alloc = 0xDEADBEEF");*/
	#endif

/**
 * Allocates graphics memory
 * returns a pointer to allocated graphics memory, which you
 * can cast to uint8_t or uint32_t, whatever is convenient
 * z_gp is 0x80212020
 * size is the size of the block to be allocated
 */
	#if OOT_DEBUG
		extern void *
		graph_alloc(z64_gfx_t *gfx_ctxt, int32_t size);
		asm("graph_alloc = 0x800C69CC");
	#else
		// This function seems to only exist in the Debug ROM.
		// Therefore, we implement it directly in other roms.
		static void *
		graph_alloc(z64_gfx_t *gfx_ctxt, int32_t size)
		{
			/* TODO confirm this works in 1.0 */
			/* TODO compile-time error checking: #error if (size & 7) */
			gfx_ctxt->poly_opa.d -= size / 8;
			return gfx_ctxt->poly_opa.d;
		}
	#endif

/* Allocates graphics debugging information to memory.
* This function seems to only exist in the Debug ROM.
* Source Code Reference File: "code.c"
*/
extern void z_debug_graph_alloc(
Gfx* buffer /* Display List Graphics Buffer */
, z64_gfx_t* gfx_ctxt /* Graphics Context, within Global Context */
, char* filename /* The Source String, Usually a filename */
, int32_t line /* Source Line Number */
);
#if OOT_DEBUG
  asm("z_debug_graph_alloc = 0x800C6AC4");
#elif OOT_U_1_0
  /*asm("z_debug_graph_alloc = 0xDEADBEEF");*/
#elif MM_U_1_0
  /*asm("z_debug_graph_alloc = 0xDEADBEEF")*/
#endif

/* Writes graphics debugging information to memory. (?)
* This function seems to only exist in the Debug ROM.
* Source Code Reference File: "code.c"
*/
extern void z_debug_graph_write(
Gfx* buffer /* Display List Graphics Buffer */
, z64_gfx_t* gfx_ctxt /* Graphics Context, within Global Context */
, char* filename /* The Source String, Usually a filename */
, int32_t line /* Source Line Number */
);
#if OOT_DEBUG
  asm("z_debug_graph_write = 0x800C6B54");
#elif OOT_U_1_0
  /*asm("z_debug_graph_write = 0xDEADBEEF");*/
#elif MM_U_1_0
  /*asm("z_debug_graph_write = 0xDEADBEEF")*/
#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800C6C20(void);
	#if OOT_DEBUG
		asm("external_func_800C6C20 = 0x800C6C20");
	#elif OOT_U_1_0
		asm("external_func_800C6C20 = 0x800A1AA0");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800C6C28(void);
	#if OOT_DEBUG
		asm("external_func_800C6C28 = 0x800C6C28");
	#elif OOT_U_1_0
		asm("external_func_800C6C28 = 0x800A1AAC");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern float external_func_800CA720(float a0);
	#if OOT_DEBUG
		asm("external_func_800CA720 = 0x800CA720");
	#elif OOT_U_1_0
		asm("external_func_800CA720 = 0x800A45FC");
	#elif MM_U_1_0
		asm("external_func_800CA720 = 0x801794EC");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800CA774(void);
	#if OOT_DEBUG
		asm("external_func_800CA774 = 0x800CA774");
	#elif OOT_U_1_0
		asm("external_func_800CA774 = 0x800A4650");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800CAFEC(void);
	#if OOT_DEBUG
		asm("external_func_800CAFEC = 0x800CAFEC");
	#elif OOT_U_1_0
		asm("external_func_800CAFEC = 0x800A4EBC");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800CB010(void);
	#if OOT_DEBUG
		asm("external_func_800CB010 = 0x800CB010");
	#elif OOT_U_1_0
		asm("external_func_800CB010 = 0x800A4EE0");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800CB0C0(void);
	#if OOT_DEBUG
		asm("external_func_800CB0C0 = 0x800CB0C0");
	#elif OOT_U_1_0
		asm("external_func_800CB0C0 = 0x800A4F98");
	#elif MM_U_1_0
		asm("external_func_800CB0C0 = 0x80179F64");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800CB198(void);
	#if OOT_DEBUG
		asm("external_func_800CB198 = 0x800CB198");
	#elif OOT_U_1_0
		asm("external_func_800CB198 = 0x800A506C");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800CB55C(void);
	#if OOT_DEBUG
		asm("external_func_800CB55C = 0x800CB55C");
	#elif OOT_U_1_0
		asm("external_func_800CB55C = 0x800A5434");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800CB594(void);
	#if OOT_DEBUG
		asm("external_func_800CB594 = 0x800CB594");
	#elif OOT_U_1_0
		asm("external_func_800CB594 = 0x800A5470");
	#endif

/**
 * Return a^2 + b^2 + c^2" Args="A0 = pointer to float array | F0 = a^2 + b^2 + c^2"
 */
extern float math_vec3f_sum_squares(vec3f_t *in);
	#if OOT_DEBUG
		asm("math_vec3f_sum_squares = 0x800CB600");
	#elif OOT_U_1_0
		asm("math_vec3f_sum_squares = 0x800A54E4");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800CB628(void);
	#if OOT_DEBUG
		asm("external_func_800CB628 = 0x800CB628");
	#elif OOT_U_1_0
		asm("external_func_800CB628 = 0x800A5510");
	#endif

/**
 * Compute Distance Squared" Args="A0 = pointer to float array (xyz) | A1 = pointer to float array | F0 = define A2 = (A0 - A1), return (A2.a)^2 + (A2.b)^2 + (A2.c)^2"
 */
extern float math_distance_squared(vec3f_t *in, vec3f_t *in_2);
	#if OOT_DEBUG
		asm("math_distance_squared = 0x800CB650");
	#elif OOT_U_1_0
		asm("math_distance_squared = 0x800A5538");
	#endif

/**
 * Unknown
 * TODO These notes need converted into a C function prototype
 * a0 - actor instance + 0x24 (position array) | a1 - actor instance + 0x100 (pos4?)
 */
extern void external_func_800CB678(void);
	#if OOT_DEBUG
		asm("external_func_800CB678 = 0x800CB678");
	#elif OOT_U_1_0
		asm("external_func_800CB678 = 0x800A5560");
	#endif

/**
 * Unknown (something related to update rotation by velocity)
 * TODO These notes need converted into a C function prototype
 * a0 - 12 byte float array | a1 - actor instance + 0x5C (velocity) | a2 - $sp offset to store the results
 */
extern void external_func_800CB7B4(void);
	#if OOT_DEBUG
		asm("external_func_800CB7B4 = 0x800CB7B4");
	#elif OOT_U_1_0
		asm("external_func_800CB7B4 = 0x800A56B8");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800CC824(void);
	#if OOT_DEBUG
		asm("external_func_800CC824 = 0x800CC824");
	#elif OOT_U_1_0
		asm("external_func_800CC824 = 0x800A6750");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800CCB0C(void);
	#if OOT_DEBUG
		asm("external_func_800CCB0C = 0x800CCB0C");
	#elif OOT_U_1_0
		asm("external_func_800CCB0C = 0x800A69A4");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800CCF48(void);
	#if OOT_DEBUG
		asm("external_func_800CCF48 = 0x800CCF48");
	#elif OOT_U_1_0
		asm("external_func_800CCF48 = 0x800A6D8C");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800CE15C(void);
	#if OOT_DEBUG
		asm("external_func_800CE15C = 0x800CE15C");
	#elif OOT_U_1_0
		asm("external_func_800CE15C = 0x800A7FC8");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800CE4B8(void);
	#if OOT_DEBUG
		asm("external_func_800CE4B8 = 0x800CE4B8");
	#elif OOT_U_1_0
		asm("external_func_800CE4B8 = 0x800A8334");
	#endif

/**
 * atan2
 * returns rotation in int16_t format
 * formerly math_atan2s
 */
extern int16_t z_atan2s(float x, float y);
	#if OOT_DEBUG
		asm("z_atan2_s = 0x800D0664");
	#elif OOT_U_1_0
		asm("z_atan2_s = 0x800AA4F8");
	#elif MM_U_1_0
		/* TODO */
	#endif

/**
 * atan2
 * returns rotation in float format
 */
extern void z_atan2f(float x, float y);
	#if OOT_DEBUG
		asm("z_atan2f = 0x800D07D4");
	#elif OOT_U_1_0
		asm("z_atan2f = 0x800AA670");
	#elif MM_U_1_0
		/* TODO */
	#endif

/**
 * Allocates a 0x500 byte Float Matrix Stack | 80121200 stores start address, 80121204 stores top matrix
 * TODO These notes need converted into a C function prototype
 * A0 = Global Context
 * This function is not used inside any existing overlay
 * new_Matrix
 */
#define Matrix_Init z_matrix_new
extern void z_matrix_new(void *gameState);
	#if OOT_DEBUG
		asm("z_matrix_new = 0x800D0810");
	#elif OOT_U_1_0
		asm("z_matrix_new = 0x800AA6B0");
	#elif MM_U_1_0
		/* TODO */
	#endif

/**
 * Clones the top level matrix in the Float Matrix Stack | (Increments Append Start by 0x40)
 * TODO These notes need converted into a C function prototype
 * Matrix_push
 */
#define Matrix_Push z_matrix_push
#define matrix_push z_matrix_push
extern void z_matrix_push(void);
	#if OOT_DEBUG
		asm("z_matrix_push = 0x800D084C");
	#elif OOT_U_1_0
		asm("z_matrix_push = 0x800AA6EC");
	#elif MM_U_1_0
		asm("z_matrix_push = 0x8018019C");
	#endif

/**
 * Pops top level matrix in the Float Matrix Stack
 * TODO These notes need converted into a C function prototype
 * Matrix_pull
 * aka glPopMatrix
 *
 */
#define Matrix_Pull z_matrix_pop
#define matrix_pop z_matrix_pop
extern void z_matrix_pop(void);
	#if OOT_DEBUG
		asm("z_matrix_pop = 0x800D0884");
	#elif OOT_U_1_0
		asm("z_matrix_pop = 0x800AA724");
	#elif MM_U_1_0
		asm("z_matrix_pop = 0x801801CC");
	#endif

/* Copy the floating point matrix from the top of the stack to mf.
* Source Code Reference File: "sys_matrix.c"
* Formerly `matrix_get`
*/
#define Matrix_Get z_matrix_get
#define z_mtxf_get_top z_matrix_get
extern void z_matrix_get(
float* mf
);
#if OOT_DEBUG
  asm("z_matrix_get = 0x800D08D8");
#elif OOT_U_1_0
  asm("z_matrix_get = 0x800AA740");
#elif MM_U_1_0
  /*asm("z_matrix_get = 0xDEADBEEF");*/
#endif

/* Copy mf to the matrix at the top of the matrix stack.
* Source Code Reference File: "sys_matrix.c"
* Formerly `matrix_load`
*/
#define Matrix_Put z_matrix_put
#define z_mtxf_put_top z_matrix_put
extern void z_matrix_put(
float* mf
);
#if OOT_DEBUG
  asm("z_matrix_put = 0x800D08FC");
#elif OOT_U_1_0
  asm("z_matrix_put = 0x800AA764");
#elif MM_U_1_0
  /*asm("z_matrix_put = 0xDEADBEEF");*/
#endif

/*
* Source Code Reference File: "sys_matrix.c"
*/
#define Matrix_GetCurrent z_matrix_get_now
extern float* z_matrix_get_now(void)
#if OOT_DEBUG
  asm("z_matrix_get_now = 0x800D0924");
#elif OOT_U_1_0
  /*asm("z_matrix_get_now = 0xDEADBEEF");*/
#elif MM_U_1_0
  /*asm("z_matrix_get_now = 0xDEADBEEF");*/
#endif

/* Multiply the top float matrix in the stack by a given float matrix. (?)
* Source Code Reference File: "sys_matrix.c"
*/
#define Matrix_Mult z_matrix_multiply
extern void z_matrix_multiply(
float* in /* Float Matrix to Multiply By */
, int32_t apply /* 0 copies the new matrix to the top one in the stack; 1 modifies the current matrix on the stack. */
);
#if OOT_DEBUG
  asm("z_matrix_multiply = 0x800D0930");
#elif OOT_U_1_0
  asm("z_matrix_multiply = 0x800AA79C");
#elif MM_U_1_0
  /*asm("z_matrix_multiply = 0xDEADBEEF");*/
#endif

/* Translate a matrix along the X, Y, and Z axes.
* Source Code Reference File: "sys_matrix.c"
* Formerly `matrix_translate`
*/
#define Matrix_Translate z_matrix_translate_3f
extern void z_matrix_translate_3f(
float x, float y, float z /* X, Y, and Z Position */
, int32_t apply /* 0 initializes a new matrix and translates it; 1 modifies the current matrix on the stack. */
);
#if OOT_DEBUG
  asm("z_matrix_translate_3f = 0x800D0984");
#elif OOT_U_1_0
  asm("z_matrix_translate_3f = 0x800AA7F4");
#elif MM_U_1_0
  asm("z_matrix_translate_3f = 0x8018029C");
#endif

/* Scale a matrix along the X, Y, and Z axes.
* Source Code Reference File: "sys_matrix.c"
* Formerly `matrix_scale`
*/
#define Matrix_Scale z_matrix_scale_3f
extern void z_matrix_scale_3f(
float x, float y, float z /* X, Y, and Z Scale */
, int32_t apply /* 0 initializes a new matrix and scales it; 1 modifies the current matrix on the stack. */
);
#if OOT_DEBUG
  asm("z_matrix_scale_3f = 0x800D0A8C");
#elif OOT_U_1_0
  asm("z_matrix_scale_3f = 0x800AA8FC");
#elif MM_U_1_0
  asm("z_matrix_scale_3f = 0x8018039C");
#endif

/* Rotate a matrix along the X axis (Pitch a matrix).
* Source Code Reference File: "sys_matrix.c"
* Formerly `matrix_rotate_x`
*/
#define Matrix_RotateX z_matrix_pitch
extern void z_matrix_pitch(
int16_t x /* The angle in degrees to pitch the matrix by. */
, int32_t apply /* 0 initializes a new matrix and pitches it; 1 modifies the current matrix on the stack. */
);
#if OOT_DEBUG
  asm("z_matrix_pitch = 0x800D0B70");
#elif OOT_U_1_0
  asm("z_matrix_pitch = 0x800AA9E0");
#elif MM_U_1_0
  asm("z_matrix_pitch = 0x80180478");
#endif

/* Rotate a matrix along the Y axis (Yaw a matrix).
* Source Code Reference File: "sys_matrix.c"
* Formerly `matrix_rotate_y`
*/
#define Matrix_RotateY z_matrix_yaw
extern void z_matrix_yaw(
int16_t y /* The angle in degrees to yaw the matrix by. */
, int32_t apply /* 0 initializes a new matrix and yaws it; 1 modifies the current matrix on the stack. */
);
#if OOT_DEBUG
  asm("z_matrix_yaw = 0x800D0D20");
#elif OOT_U_1_0
  asm("z_matrix_yaw = 0x800AAB94");
#elif MM_U_1_0
  asm("z_matrix_yaw = 0x80180CF8");
#endif

/* Rotate a matrix along the Z axis (Roll a matrix).
* Source Code Reference File: "sys_matrix.c"
* Formerly `matrix_rotate_z`
*/
#define Matrix_RotateZ z_matrix_roll
extern void z_matrix_roll(
float z /* The angle in degrees to roll the matrix by. */
, int32_t apply /* 0 initializes a new matrix and rolls it; 1 modifies the current matrix on the stack. */
);
#if OOT_DEBUG
  asm("z_matrix_roll = 0x800D0ED4");
#elif OOT_U_1_0
  asm("z_matrix_roll = 0x800AAD4C");
#elif MM_U_1_0
  asm("z_matrix_roll = 0x801809AC");
#endif

/* Rotate a matrix along the Z, Y, and X axes.
* Source Code Reference File: "sys_matrix.c"
* Formerly `matrix_rotate`
*/
#define Matrix_RotateRPY z_matrix_rotate_3s
extern void z_matrix_rotate_3s(
int16_t x, int16_t y, int16_t z /* X, Y, and Z Rotation */
, int32_t apply /* 0 initializes a new matrix and rotates it; 1 modifies the current matrix on the stack. */
);
#if OOT_DEBUG
  asm("z_matrix_rotate_3s = 0x800D1084");
#elif OOT_U_1_0
  asm("z_matrix_rotate_3s = 0x800AAF00");
#elif MM_U_1_0
  asm("z_matrix_rotate_3s = 0x8018103C");
#endif

/* Translate a matrix and then rotate it.
* Source Code Reference File: "sys_matrix.c"
*/
#define Matrix_JointPosition z_matrix_translate_rotate
extern void z_matrix_translate_rotate(
vec3f_t* translation
, vec3s_t* rotation
);
#if OOT_DEBUG
  asm("z_matrix_translate_rotate = 0x800D1340");
#elif OOT_U_1_0
  asm("z_matrix_translate_rotate = 0x800AB1BC");
#elif MM_U_1_0
  /*asm("z_matrix_translate_rotate = 0xDEADBEEF");*/
#endif

/* Translate the top matrix on the stack along the X, Y, and Z axes.
* Used in drawing the Bunny Hood Ears
* Source Code Reference File: "sys_matrix.c"
*/
extern void z_matrix_translate_3f_800D1694(
float x, float y, float z
, vec3s_t* r
);
#if OOT_DEBUG
	asm("z_matrix_translate_3f_800D1694 = 0x800D1694");
#elif OOT_U_1_0
	asm("z_matrix_translate_3f_800D1694 = 0x800AB510");
#elif MM_U_1_0
	asm("z_matrix_translate_3f_800D1694 = 0x80181650");
#endif

/* Convert a floating-point matrix to a s15.16 fixed-point matrix.
* Source Code Reference File: "sys_matrix.c"
* Formerly `_guMtxF2L`
*/
#define Matrix_MtxFToMtx z_matrix_float_to_fixed
extern Mtx* z_matrix_float_to_fixed(
float* src
, Mtx* dest
);
#if OOT_DEBUG
  asm("z_matrix_float_to_fixed = 0x800D1840");
#elif OOT_U_1_0
  asm("z_matrix_float_to_fixed = 0x800AB6BC");
#elif MM_U_1_0
  asm("z_matrix_float_to_fixed = 0x801817FC");
#endif

/* Convert the top floating-point matrix to a s15.16 fixed-point matrix.
* Source Code Reference File: "sys_matrix.c"
* Formerly `external_func_800D1A54`
*/
#define Matrix_ToMtx z_matrix_top_to_fixed
extern Mtx* z_matrix_top_to_fixed(
Mtx* dest
, char* file
, int32_t line
);
#if OOT_DEBUG
  asm("z_matrix_top_to_fixed = 0x800D1A54");
#elif OOT_U_1_0
  asm("z_matrix_top_to_fixed = 0x800AB8D8");
#elif MM_U_1_0
  asm("z_matrix_top_to_fixed = 0x80181A18");
#endif

/**
 * Converts and Appends the Float Matrix Stack's top matrix to POLY_OPA_DISP end
 * please provide only the first two arguments when using this function
 */
#define Matrix_NewMtx z_matrix_alloc
extern Mtx* z_matrix_alloc(
	  z64_gfx_t *gfx_ctx
#ifndef RETAIL_NUANCES /* debug roms require these arguments, retail roms don't */
	, const char *string
	, int32_t line
#endif
);
#ifdef RETAIL_NUANCES
#define z_matrix_alloc(MTXALLOC_GFX, MTXALLOC_STR) z_matrix_alloc(MTXALLOC_GFX)
#else
#define z_matrix_alloc(MTXALLOC_GFX, MTXALLOC_STR) z_matrix_alloc(MTXALLOC_GFX, MTXALLOC_STR, __LINE__)
#endif
	#if OOT_DEBUG
		asm("z_matrix_alloc = 0x800D1A88");
	#elif OOT_U_1_0
		asm("z_matrix_alloc = 0x800AB900");
	#elif MM_U_1_0
		asm("z_matrix_alloc = 0x80181A40");
	#endif

/**
 * Allocate a new fixed matrix from a floating point matrix.
 */
#define Matrix_MtxFToNewMtx z_matrix_new_f2l
extern void z_matrix_new_f2l(MtxF* src, z64_gfx_t* gfx);
	#if OOT_DEBUG
		asm("z_matrix_new_f2l = 0x800D1AC0");
	#elif OOT_U_1_0
		//asm("z_matrix_new_f2l = 0xDEADBEEF");
	#elif MM_U_1_0
		//asm("z_matrix_new_f2l = 0xDEADBEEF");
	#endif

/**
 * Multiply the top floating point matrix by vec3f_t `src`.
 * Store the result as a vec3f_t `dest`.
 */
#define Matrix_MultVec3f z_matrix_mult_vec3f
extern void z_matrix_mult_vec3f(vec3f_t* src, vec3f_t* dest);
	#if OOT_DEBUG
		asm("z_matrix_mult_vec3f = 0x800D1AF4");
	#elif OOT_U_1_0
		asm("z_matrix_mult_vec3f = 0x800AB958");
	#elif MM_U_1_0
		asm("z_matrix_mult_vec3f = 0x80181A98");
	#endif

/**
 * Float Matrix Copy
 * copy src over dst
 * poorly optimized?
 * A0 = Destination | A1 = Source
 */
#define Matrix_MtxFCopt z_matrix_float_copy
extern void z_matrix_float_copy(void *dst, void *src);
	#if OOT_DEBUG
		asm("z_matrix_float_copy = 0x800D1BA8");
	#elif OOT_U_1_0
		asm("z_matrix_float_copy = 0x800ABA10");
	#elif MM_U_1_0
		/* TODO */
	#endif

/* Convert a s15.16 fixed-point matrix to a floating-point matrix.
* Source Code Reference File: "sys_matrix.c"
*/
#define Matrix_MtxToMtxF z_matrix_fixed_to_float
extern void z_matrix_fixed_to_float(Mtx* src, float dest[4][4]);
#if OOT_DEBUG
  asm("z_matrix_fixed_to_float= 0x800D1CAC");
#elif OOT_U_1_0
  //asm("z_matrix_fixed_to_float = 0xDEADBEEF");
#elif MM_U_1_0
  //asm("z_matrix_fixed_to_float = 0xDEADBEEF");
#endif

/**
 * TODO This function is completely undocumented
 */
#define Matrix_MultVec3fExt z_matrix_mult_vec3f_ext
extern void z_matrix_mult_vec3f_ext(vec3f_t* src, vec3f_t* dest, float mf[4][4]);
	#if OOT_DEBUG
		asm("z_matrix_mult_vec3f_ext = 0x800D1EF4");
	#elif OOT_U_1_0
		asm("z_matrix_mult_vec3f_ext = 0x800ABD6C");
	#endif

/**
 * TODO This function is completely undocumented
 */
#define Matrix_Reverse z_matrix_reverse
extern void z_matrix_reverse(float mf[4][4]);
	#if OOT_DEBUG
		asm("z_matrix_reverse = 0x800D1FA0");
	#elif OOT_U_1_0
		//asm("z_matrix_reverse = 0xDEADBEEF");
	#endif

/**
 * TODO what does this do?
 * unk0 is consistently either the graphics or global context, + 0x11DA0
 */
extern void z_matrix_rotate_vec3f(vec3f_t* rot);
	#if OOT_DEBUG
		asm("z_matrix_rotate_vec3f = 0x800D1FD4");
	#elif OOT_U_1_0
		asm("z_matrix_rotate_vec3f = 0x800ABE54");
	#elif MM_U_1_0
		asm("z_matrix_rotate_vec3f = 0x801820A0");
	#endif

/* Extract rotations from a 3x3 matrix within a 4x4 transformation matrix.
* Used to deflect projectiles.
* Source Code Reference File: "code.c"
* Formerly `external_func_800D20CC`
*/
extern void z_matrix_float_to_vec3s(
float* mf /* Float Matrix for angles to be derived from. */
, vec3s_t* /* Where the derived vector is stored. */
, int32_t flag /* Likely, "matrix_has_scale" */
);
#if OOT_DEBUG
  asm("z_matrix_float_to_vec3s = 0x800D20CC");
#elif OOT_U_1_0
  asm("z_matrix_float_to_vec3s = 0x800ABF50");
#elif MM_U_1_0
  /*asm("z_matrix_float_to_vec3s = 0xDEADBEEF");*/
#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800D2264(void);
	#if OOT_DEBUG
		asm("external_func_800D2264 = 0x800D2264");
	#elif OOT_U_1_0
		asm("external_func_800D2264 = 0x800AC0E8");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800D23FC(void);
	#if OOT_DEBUG
		asm("external_func_800D23FC = 0x800D23FC");
	#elif OOT_U_1_0
		asm("external_func_800D23FC = 0x800AC280");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800D285C(void);
	#if OOT_DEBUG
		asm("external_func_800D285C = 0x800D285C");
	#elif OOT_U_1_0
		// TODO Needs 1.0 equivalent!
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800ED858(void);
	#if OOT_DEBUG
		asm("external_func_800ED858 = 0x800ED858");
	#elif OOT_U_1_0
		asm("external_func_800ED858 = 0x800C2C90");
	#endif

/**
 * Song playback related.
 * TODO These notes need converted into a C function prototype
 */
extern void external_func_800ED93C(void);
	#if OOT_DEBUG
		asm("external_func_800ED93C = 0x800ED93C");
	#elif OOT_U_1_0
		asm("external_func_800ED93C = 0x800C2D74");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800F3F3C(void);
	#if OOT_DEBUG
		asm("external_func_800F3F3C = 0x800F3F3C");
	#elif OOT_U_1_0
		asm("external_func_800F3F3C = 0x800C4C84");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800F4190(void);
	#if OOT_DEBUG
		asm("external_func_800F4190 = 0x800F4190");
	#elif OOT_U_1_0
		asm("external_func_800F4190 = 0x800C4ED0");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800F41E0(void);
	#if OOT_DEBUG
		asm("external_func_800F41E0 = 0x800F41E0");
	#elif OOT_U_1_0
		asm("external_func_800F41E0 = 0x800C4F20");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800F4254(vec3f_t* a0, uint32_t a1);
	#if OOT_DEBUG
		asm("external_func_800F4254 = 0x800F4254");
	#elif OOT_U_1_0
		asm("external_func_800F4254 = 0x800C4F94");
	#endif

/**
 * TODO a0 = actor instance + E4 | a1 = sfx id | a2 = float pitch
 */
extern void sound_play_pitch(void *actor_plus_0xE4, uint16_t sfx, float pitch);
	#if OOT_DEBUG
		asm("sound_play_pitch = 0x800F436C");
	#elif OOT_U_1_0
		asm("sound_play_pitch = 0x800C50AC");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800F4414(void);
	#if OOT_DEBUG
		asm("external_func_800F4414 = 0x800F4414");
	#elif OOT_U_1_0
		asm("external_func_800F4414 = 0x800C5154");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800F44EC(void);
	#if OOT_DEBUG
		asm("external_func_800F44EC = 0x800F44EC");
	#elif OOT_U_1_0
		asm("external_func_800F44EC = 0x800C522C");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800F4524(void);
	#if OOT_DEBUG
		asm("external_func_800F4524 = 0x800F4524");
	#elif OOT_U_1_0
		asm("external_func_800F4524 = 0x800C5264");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800F4634(void);
	#if OOT_DEBUG
		asm("external_func_800F4634 = 0x800F4634");
	#elif OOT_U_1_0
		asm("external_func_800F4634 = 0x800C5374");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800F46E0(void);
	#if OOT_DEBUG
		asm("external_func_800F46E0 = 0x800F46E0");
	#elif OOT_U_1_0
		asm("external_func_800F46E0 = 0x800C5420");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800F483C(void);
	#if OOT_DEBUG
		asm("external_func_800F483C = 0x800F483C");
	#elif OOT_U_1_0
		asm("external_func_800F483C = 0x800C557C");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800F4870(void);
	#if OOT_DEBUG
		asm("external_func_800F4870 = 0x800F4870");
	#elif OOT_U_1_0
		asm("external_func_800F4870 = 0x800C55B0");
	#endif

/**
 * Sound? Set uint8_t 80121DFC to A0, uint8_t 80121DFE to 1
 * TODO These notes need converted into a C function prototype
 * A0 = ?
 */
extern void external_func_800F4A54(void);
	#if OOT_DEBUG
		asm("external_func_800F4A54 = 0x800F4A54");
	#elif OOT_U_1_0
		asm("external_func_800F4A54 = 0x800C5794");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800F4B58(void);
	#if OOT_DEBUG
		asm("external_func_800F4B58 = 0x800F4B58");
	#elif OOT_U_1_0
		asm("external_func_800F4B58 = 0x800C5898");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800F4BE8(void);
	#if OOT_DEBUG
		asm("external_func_800F4BE8 = 0x800F4BE8");
	#elif OOT_U_1_0
		asm("external_func_800F4BE8 = 0x800C5928");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800F4BF4(void);
	#if OOT_DEBUG
		asm("external_func_800F4BF4 = 0x800F4BF4");
	#elif OOT_U_1_0
		asm("external_func_800F4BF4 = 0x800C5934");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800F4E30(void);
	#if OOT_DEBUG
		asm("external_func_800F4E30 = 0x800F4E30");
	#elif OOT_U_1_0
		asm("external_func_800F4E30 = 0x800C5B70");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800F50EC(void);
	#if OOT_DEBUG
		asm("external_func_800F50EC = 0x800F50EC");
	#elif OOT_U_1_0
		asm("external_func_800F50EC = 0x800C5E2C");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800F52A0(void);
	#if OOT_DEBUG
		asm("external_func_800F52A0 = 0x800F52A0");
	#elif OOT_U_1_0
		asm("external_func_800F52A0 = 0x800C5FE0");
	#endif

/**
 * Zero uint32_t? 8010195C
 * TODO These notes need converted into a C function prototype
 */
extern void external_func_800F5504(void);
	#if OOT_DEBUG
		asm("external_func_800F5504 = 0x800F5504");
	#elif OOT_U_1_0
		asm("external_func_800F5504 = 0x800C6258");
	#endif

/**
 * no args
 */
extern void play_windmill_music(void);
	#if OOT_DEBUG
		asm("external_func_800F5718 = 0x800F5718");
	#elif OOT_U_1_0
		asm("external_func_800F5718 = 0x800C646C");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800F574C(void);
	#if OOT_DEBUG
		asm("external_func_800F574C = 0x800F574C");
	#elif OOT_U_1_0
		asm("external_func_800F574C = 0x800C64A0");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800F5918(void);
	#if OOT_DEBUG
		asm("external_func_800F5918 = 0x800F5918");
	#elif OOT_U_1_0
		asm("external_func_800F5918 = 0x800C666C");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800F5A58(void);
	#if OOT_DEBUG
		asm("external_func_800F5A58 = 0x800F5A58");
	#elif OOT_U_1_0
		asm("external_func_800F5A58 = 0x800C67AC");
	#endif

/**
 * Change background music until enemies are defeated
 * a0 - music ID
 */
#define play_midboss_music z_bgm_play_midboss
extern void z_bgm_play_midboss(uint32_t musicID);
	#if OOT_DEBUG
		asm("z_bgm_play_midboss = 0x800F5ACC");
	#elif OOT_U_1_0
		asm("z_bgm_play_midboss = 0x800C6820");
	#endif

/**
 * TODO Confirm Usage
 */
extern void z_bgm_stop_midboss(void);
	#if OOT_DEBUG
		asm("z_bgm_stop_midboss = 0x800F5B58");
	#elif OOT_U_1_0
		asm("z_bgm_stop_midboss = 0x800C6894");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800F5BF0(void);
	#if OOT_DEBUG
		asm("external_func_800F5BF0 = 0x800F5BF0");
	#elif OOT_U_1_0
		asm("external_func_800F5BF0 = 0x800C692C");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800F5C2C(void);
	#if OOT_DEBUG
		asm("external_func_800F5C2C = 0x800F5C2C");
	#elif OOT_U_1_0
		asm("external_func_800F5C2C = 0x800C6968");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800F5C64(void);
	#if OOT_DEBUG
		asm("external_func_800F5C64 = 0x800F5C64");
	#elif OOT_U_1_0
		asm("external_func_800F5C64 = 0x800C69A0");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800F6268(void);
	#if OOT_DEBUG
		asm("external_func_800F6268 = 0x800F6268");
	#elif OOT_U_1_0
		asm("external_func_800F6268 = 0x800C6F9C");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800F6584(void);
	#if OOT_DEBUG
		asm("external_func_800F6584 = 0x800F6584");
	#elif OOT_U_1_0
		asm("external_func_800F6584 = 0x800C72A4");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800F67A0(void);
	#if OOT_DEBUG
		asm("external_func_800F67A0 = 0x800F67A0");
	#elif OOT_U_1_0
		asm("external_func_800F67A0 = 0x800C74C0");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800F6828(void);
	#if OOT_DEBUG
		asm("external_func_800F6828 = 0x800F6828");
	#elif OOT_U_1_0
		asm("external_func_800F6828 = 0x800C7548");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800F68BC(void);
	#if OOT_DEBUG
		asm("external_func_800F68BC = 0x800F68BC");
	#elif OOT_U_1_0
		asm("external_func_800F68BC = 0x800C75DC");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800F6D58(void);
	#if OOT_DEBUG
		asm("external_func_800F6D58 = 0x800F6D58");
	#elif OOT_U_1_0
		asm("external_func_800F6D58 = 0x800C7A78");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800F6FB4(void);
	#if OOT_DEBUG
		asm("external_func_800F6FB4 = 0x800F6FB4");
	#elif OOT_U_1_0
		asm("external_func_800F6FB4 = 0x800C7C90");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800F7260(void);
	#if OOT_DEBUG
		asm("external_func_800F7260 = 0x800F7260");
	#elif OOT_U_1_0
		asm("external_func_800F7260 = 0x800C7F40");
	#endif

/**
 * Play a sound effect (at a system level)
 * Source Code Reference File: `code.c`
 */
extern void z_sfx_play_system(
uint16_t sfx_id
, vec3f_t* pos
, uint32_t a2
, float* a3
, float* a4
, float* a5
);
#if OOT_DEBUG
	asm("z_sfx_play_system = 0x800F738C");
#elif OOT_U_1_0
	asm("z_sfx_play_system = 0x800C806C");
#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800F89E8(void);
	#if OOT_DEBUG
		asm("external_func_800F89E8 = 0x800F89E8");
	#elif OOT_U_1_0
		asm("external_func_800F89E8 = 0x800C9568");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800F8A44(void);
	#if OOT_DEBUG
		asm("external_func_800F8A44 = 0x800F8A44");
	#elif OOT_U_1_0
		asm("external_func_800F8A44 = 0x800C95C4");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800F8D04(void);
	#if OOT_DEBUG
		asm("external_func_800F8D04 = 0x800F8D04");
	#elif OOT_U_1_0
		asm("external_func_800F8D04 = 0x800C9884");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800F8FF4(void);
	#if OOT_DEBUG
		asm("external_func_800F8FF4 = 0x800F8FF4");
	#elif OOT_U_1_0
		asm("external_func_800F8FF4 = 0x800C9B74");
	#endif

/**
 * Change background music
 * TODO Confirm music_id type
 */
extern void sound_set_bgm(uint32_t music_id);
	#if OOT_DEBUG
		asm("sound_set_bgm = 0x800FA00C");
	#elif OOT_U_1_0
		asm("sound_set_bgm = 0x800CAA70");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800FA0B4(void);
	#if OOT_DEBUG
		asm("external_func_800FA0B4 = 0x800FA0B4");
	#elif OOT_U_1_0
		asm("external_func_800FA0B4 = 0x800CAB18");
	#endif

/**
 * Set RGBA color for a string of Debug Text.
 */
extern void debug_set_text_rgba(z64_debug_text_t *text_struct, uint8_t r, uint8_t g, uint8_t b, uint8_t a);
	#if OOT_DEBUG
		asm("debug_set_text_rgba = 0x800FB3AC");
	#elif OOT_U_1_0
		asm("debug_set_text_rgba = 0x800CBE58");
	#elif MM_U_1_0
		asm("debug_set_text_rgba = 0x800859BC");
	#endif

/**
 * Set X / Y coordinates for a string of Debug Text.
 */
extern void debug_set_text_xy(z64_debug_text_t *text_struct, int32_t x, int32_t y);
	#if OOT_DEBUG
		asm("debug_set_text_xy = 0x800FB41C");
	#elif OOT_U_1_0
		asm("debug_set_text_xy = 0x800CBEC8");
	#elif MM_U_1_0
		asm("debug_set_text_xy = 0x80085A2C");
	#endif

/**
 * Initailize a variable structure for Debug Text.
 */
extern void debug_init_text_struct(z64_debug_text_t *text_struct);
	#if OOT_DEBUG
		asm("debug_init_text_struct = 0x800FBB8C");
	#elif OOT_U_1_0
		asm("debug_init_text_struct = 0x800CC4AC");
	#elif MM_U_1_0
		asm("debug_init_text_struct = 0x80086010");
	#endif

/**
 * Store A0 on stack
 * TODO These notes need converted into a C function prototype
 * This function is not used inside any existing overlay
 */
extern void external_func_800FBC14(z64_debug_text_t* t);
	#if OOT_DEBUG
		asm("external_func_800FBC14 = 0x800FBC14");
	#elif OOT_U_1_0
		asm("external_func_800FBC14 = 0x800CC500");
	#elif MM_U_1_0
		asm("external_func_800FBC14 = 0x80086064");
	#endif

/**
 * gfxprint_open:２重オープンです related.
 * Write Debug Text display list to main display list buffer.
 */
extern void debug_do_text_struct(z64_debug_text_t *text_struct, void *gfx_buffer);
	#if OOT_DEBUG
		asm("debug_do_text_struct = 0x800FBC1C");
	#elif OOT_U_1_0
		asm("debug_do_text_struct = 0x800CC508");
	#elif MM_U_1_0
		asm("debug_do_text_struct = 0x8008606C");
	#endif

/**
 * Return a pointer to the main display list buffer after adding debug text structure.
 */
extern
void *
debug_update_text_struct(z64_debug_text_t *text_struct);
	#if OOT_DEBUG
		asm("debug_update_text_struct = 0x800FBC64");
	#elif OOT_U_1_0
		asm("debug_update_text_struct = 0x800CC550");
	#elif MM_U_1_0
		asm("debug_update_text_struct = 0x800860A0");
	#endif

/**
 * Set character string for Debug Text.
 */
extern void debug_set_text_string(z64_debug_text_t *text_struct, const char *format, ...);
	#if OOT_DEBUG
		asm("debug_set_text_string = 0x800FBCB4");
	#elif OOT_U_1_0
		asm("debug_set_text_string = 0x800CC588");
	#elif MM_U_1_0
		asm("debug_set_text_string = 0x800860D8");
	#endif

/**
 * Relocates an overlay from virtual RAM to real RAM.
 */
extern void z_overlay_do_relocation(void* overlay_file, void* overlay_header, void* vram_start);
	#if OOT_DEBUG
		asm("z_overlay_do_relocation = 0x800FC2C0");
	#elif OOT_U_1_0
		asm("z_overlay_do_relocation = 0x800CC8F0");
	#elif MM_U_1_0
 		asm("z_overlay_do_relocation = 0x800849A0");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800FCC6C(void);
	#if OOT_DEBUG
		asm("external_func_800FCC6C = 0x800FCC6C");
	#elif OOT_U_1_0
		asm("external_func_800FCC6C = 0x800CCED4");
	#endif

/* Return tangent of `x`. */
extern float z_tanf(float x);
#if OOT_DEBUG
  asm("z_tanf = 0x800FCE80");
#elif OOT_U_1_0
  /*asm("z_tanf = 0xDEADBEEF");*/
#elif MM_U_1_0
  /*asm("z_tanf = 0xDEADBEEF");*/
#endif

/* Return floor of `x`. */
extern float z_floorf(float x);
#if OOT_DEBUG
  asm("z_floorf = 0x800FCEB4");
#elif OOT_U_1_0
  /*asm("z_floorf = 0xDEADBEEF");*/
#elif MM_U_1_0
  /*asm("z_floorf = 0xDEADBEEF");*/
#endif

/* Return ceil of `x`. */
extern float z_ceilf(float x);
#if OOT_DEBUG
  asm("z_ceilf = 0x800FCED4");
#elif OOT_U_1_0
  /*asm("z_ceilf = 0xDEADBEEF");*/
#elif MM_U_1_0
  /*asm("z_ceilf = 0xDEADBEEF");*/
#endif

/* Round `x`. */
extern float z_roundf(float x);
#if OOT_DEBUG
  asm("z_roundf = 0x800FCEF4");
#elif OOT_U_1_0
  /*asm("z_roundf = 0xDEADBEEF");*/
#elif MM_U_1_0
  /*asm("z_roundf = 0xDEADBEEF");*/
#endif

/* Truncate `x`. */
extern float z_truncf(float x);
#if OOT_DEBUG
  asm("z_truncf = 0x800FCF14");
#elif OOT_U_1_0
  /*asm("z_truncf = 0xDEADBEEF");*/
#elif MM_U_1_0
  /*asm("z_truncf = 0xDEADBEEF");*/
#endif

/**
 * Atan
 */
extern float z_atanf_cfrac(float x);
	#if OOT_DEBUG
		asm("z_atanf = 0x800FD0C4");
	#elif OOT_U_1_0
		asm("z_atanf = 0x800CD648");
	#endif

/**
 * Atan2
 */
extern float z_atan2f2(float y, float x);
	#if OOT_DEBUG
		asm("z_atan2f2 = 0x800FD250");
	#elif OOT_U_1_0
		asm("z_atan2f2 = 0x800CD76C");
	#endif

/**
 * asinf
 */
extern void z_asinf(float x);
	#if OOT_DEBUG
		asm("z_asinf = 0x800FD338");
	#elif OOT_U_1_0
		//asm("z_asinf = 0xDEADBEEF");
	#endif

/**
 * acosf
 */
extern void z_acosf(float x);
	#if OOT_DEBUG
		asm("z_acosf = 0x800FD368");
	#elif OOT_U_1_0
		asm("z_acosf = 0x800CD890");
	#endif

/**
 * Deallocates memory on main heap
 * TODO These notes need converted into a C function prototype
 * A0 = ptr to block to free (not the node)
 */
extern void external_func_800FD7B4(void);
	#if OOT_DEBUG
		asm("external_func_800FD7B4 = 0x800FD7B4");
	#elif OOT_U_1_0
		asm("external_func_800FD7B4 = 0x800CDB00");
	#endif

/* Generate a random float that is smaller than 1.
* Range is [0, 1) (Exclusive)
* Adds `offset` to the generated integer.
* Source Code Reference File: "code_800FD970.s"
*/
extern float z_math_rand_zero_one(void);
#if OOT_DEBUG
  asm("z_math_rand_zero_one = 0x800FD9AC");
#elif OOT_U_1_0
  asm("z_math_rand_zero_one = 0x800CDCCC");
#elif MM_U_1_0
  asm("z_math_rand_zero_one = 0x80086FDC");
#endif

/**
 * TODO This function is completely undocumented
 */
extern int32_t external_func_800FD970(void);
	#if OOT_DEBUG
		asm("external_func_800FD970 = 0x800FD970");
	#elif OOT_U_1_0
		asm("external_func_800FD970 = 0x800CDC90");
	#elif MM_U_1_0
		asm("external_func_800FD970 = 0x80086FA0");
	#endif

/**
 * Seeds the RNG with the given seed. This function is not used inside any existing overlay.
 * formerly srand
 * TODO in the C standard library, srand does not return anything...
 *      please confirm whether this returns anything, and if so, what
 */
extern int32_t z_srand(uint32_t seed);
	#if OOT_DEBUG
		asm("z_srand = 0x800FD9A0");
	#elif OOT_U_1_0
		asm("z_srand = 0x800CDCC0");
	#endif

/**
/* Return Sine (in radians) of Rotation Angle
* Source Code Reference File: "code.c"
* Formerly `z_sin`
*/
extern float z_sinf(
float angle /* Floating Point Angle */
);
#if OOT_DEBUG
  asm("z_sinf = 0x80100290");
#elif OOT_U_1_0
  asm("z_sinf = 0x800CF470");
#elif MM_U_1_0
  /*asm("z_sinf = 0xDEADBEEF");*/
#endif

/**
 * Returns the square root of a floating point number.
 * formerly math_sqrtf
 */
extern float z_sqrt(float value);
	#if OOT_DEBUG
		asm("z_sqrt = 0x801031E0");
	#elif OOT_U_1_0
		asm("z_sqrt = 0x800D0DC0");
	#elif MM_U_1_0
		asm(
			"z_sqrt:		 	 \n"
			"jr			$ra		 \n"
			"sqrt.S 	$f0, $f12\n"
		);
	#endif

/**
 * Returns cosine (in radians) of a floating point value.
 * formerly math_cosf
 */
extern float z_cosf(float angle);
	#if OOT_DEBUG
		asm("z_cosf = 0x80104610");
	#elif OOT_U_1_0
		asm("z_cosf = 0x800D2CD0");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern int16_t coss(int16_t angle);
	#if OOT_DEBUG
		asm("coss = 0x80104780");
	#elif OOT_U_1_0
		asm("coss = 0x800D2FA0");
	#endif

/**
 * Returns the absolute value of a floating point number.
 * formerly math_fabsf
 */
extern float z_fabs(float value);
	#if OOT_DEBUG
		asm("z_fabs = 0x801067E0");
	#elif OOT_U_1_0
		// TODO does a 1.0 equivalent really not exist? compare a
		//      debug actor that uses it to its retail counterpart
		inline float z_fabs(float value) {
			if (value < 0)
				return -value;
			return value;
		}
	#endif

/**
 * floating-point remainder function
 * Returns the modulous of two floating point numbers.
 * formerly math_fmodf
 */
extern float z_fmod(float a, float b);
	#if OOT_DEBUG
		asm("z_fmod = 0x801067F0");
	#elif OOT_U_1_0
		// TODO does a 1.0 equivalent really not exist? compare a
		//      debug actor that uses it to its retail counterpart
		inline float z_fmod(float a, float b) {
			if (b == 0.00000000)
				a = 0.00000000;
			else
				a = a - (a / b) * b;
			return a;
		}
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_80106AA8(void);
	#if OOT_DEBUG
		asm("external_func_80106AA8 = 0x80106AA8");
	#elif OOT_U_1_0
		asm("external_func_80106AA8 = 0x800D5FEC");
	#endif

/**
 * Checks whether the player has selected a text-box option
 * returns 1 once player has selected yes/no/maybe from a text-box, 0 otherwise
 * NOTE: If you want to fetch the option selected, look no
         further than helper_player_textbox_selection() in helpers.h
 * NOTE: This function's value is cleared to 0 once per frame, so you
         should test it once per frame if you're in a textbox selection.
 */
extern int32_t player_responded_to_textbox(z64_global_t *global);
    #if OOT_DEBUG
        asm("player_responded_to_textbox = 0x80106BC8");
    #elif OOT_U_1_0
        asm("player_responded_to_textbox = 0x800D6110");
    #endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_80106CCC(void);
	#if OOT_DEBUG
		asm("external_func_80106CCC = 0x80106CCC");
	#elif OOT_U_1_0
		asm("external_func_80106CCC = 0x800D6218");
	#endif

/**
 * Initialize a textbox with message `text_id`
 * `actor` should either be a pointer to the actor structure
 *         within the entity, or 0 (NULL)
 * TODO: Find out what happens when `actor` is non-zero.
 *       Current theories include:
 *         * some kind of camera magic
 *         * a value inside the actor structure is set
 *           when the textbox advances, closes, or both
 */
extern void textbox_begin(z64_global_t *, uint16_t text_id, z64_actor_t *actor);
	#if OOT_DEBUG
		asm("textbox_begin = 0x8010B680");
	#elif OOT_U_1_0
		asm("textbox_begin = 0x800DCE14");
 	#elif MM_U_1_0
		asm("textbox_begin = 0x801518B0");
	#endif

/**
 * Continue conversation
 * NOTE: Should NOT be used unless a textbox is already onscreen!
 */
extern void textbox_continue(z64_global_t *global, uint16_t text_id);
	#if OOT_DEBUG
		asm("textbox_continue = 0x8010B720");
	#elif OOT_U_1_0
		asm("textbox_continue = 0x800DCE80");
	#endif

/**
 * Something related to song playback?
 * Jumps to 800DCF50
 * TODO These notes need converted into a C function prototype
 */
extern void external_func_8010BD58(void);
	#if OOT_DEBUG
		asm("external_func_8010BD58 = 0x8010BD58");
	#elif OOT_U_1_0
		asm("external_func_8010BD58 = 0x800DD400");
	#endif

/**
 * Something related to song playback?
 * Jumps to 800DCF50
 * TODO These notes need converted into a C function prototype
 */
extern void external_func_8010BD88(void);
	#if OOT_DEBUG
		asm("external_func_8010BD88 = 0x8010BD88");
	#elif OOT_U_1_0
		asm("external_func_8010BD88 = 0x800DD430");
	#endif

/**
 * Check if Link is talking
 * TODO These notes need converted into a C function prototype
 * A0 = global context + 0x20D8 (VIEW struct ptr)
 */
extern uint32_t player_talk_state(z64_global_t *gl_20D8);
	#if OOT_DEBUG
		asm("player_talk_state = 0x8010BDBC");
	#elif OOT_U_1_0
		asm("player_talk_state = 0x800DD464");
	#endif

/**
 * Game sound on/off (except global sounds), if off, music volume -50%
 */
extern void external_func_800F64E0(uint32_t onoff);
	#if OOT_DEBUG
		asm("external_func_800F64E0 = 0x800F64E0");
	#endif


/**
 * Unknown (used on unpause) first arg is global+0x7C0
 */
extern void external_func_800418D0(uint32_t global7C0,z64_global_t *global);
	#if OOT_DEBUG
		asm("external_func_800418D0 = 0x800418D0");
	#endif

/**
 * Stores permanent flags in the save context (use it before saving the game)
 */
extern void save_flags(z64_global_t *global);
	#if OOT_DEBUG
		asm("save_flags = 0x800C0A44");
	#endif

/**
 * Saves the game (save context) in the current file slot
 */
extern void save_game(uint32_t global1F74,z64_global_t *global);
	#if OOT_DEBUG
		asm("save_game = 0x800A88D4");
	#endif


/**
 Refresh Link's instance equipment, a0 = global context, a1 = link instance
 */
extern uint32_t player_refresh_equipment(z64_global_t *global, z64_actor_t *actor);
	#if OOT_DEBUG
		asm("player_refresh_equipment = 0x8008ECAC");
	#elif OOT_U_1_0
		asm("player_refresh_equipment = 0x80079764");
	#endif

/*
 * Determines if the line formed by `lineStart` and `lineEnd` intersect with Triangle formed from
 * vertices `v0`, `v1`, and `v2` with normal vector `nx`, `ny`, and `nz` with plane distance from origin
 * `originDist` Outputs the intersection point at to `intersect`
 * Returns 1 if the line intersects with the triangle, 0 otherwise
 */
extern int z_tri_line_intersect(vec3f_t* v0, vec3f_t* v1, vec3f_t* v2, float nx, float ny, float nz, float originDist, vec3f_t* lineStart, vec3f_t* lineEnd, vec3f_t* intersectionPoint, int arg);
	#ifdef OOT_U_1_0
		 asm("z_tri_line_intersect = 0x800A80D0");
	#else
		 asm("z_tri_line_intersect = 0x800CE258");
	#endif

/**
 * libultra guScale
 * Keywords: Matrix, Scale
 */
extern void guScale(Mtx* m, float x, float y, float z);
	#if OOT_DEBUG
		asm("guScale = 0x801001E0");
	#elif OOT_U_1_0
		//asm("guScale = 0xDEADBEEF");
	#endif

/**
 * libultra guPerspectiveF
 * Keywords: Matrix, Perspective, Float
 */
extern void guPerspectiveF(
	float mf[4][4]
	, uint16_t* perspNorm, float fovy, float aspect
	, float near, float far, float scale
);
	#if OOT_DEBUG
		asm("guPerspectiveF = 0x801010D0");
	#elif OOT_U_1_0
		//asm("guPerspectiveF = 0xDEADBEEF");
	#endif

/**
 * libultra guPerspective
 * Keywords: Matrix, Perspective
 */
extern void guPerspective(
	Mtx* m
	uint16_t* perspNorm, float fovy, float aspect
	, float near, float far, float scale
);
	#if OOT_DEBUG
		asm("guPerspective = 0x80101300");
	#elif OOT_U_1_0
		//asm("guPerspective = 0xDEADBEEF");
	#endif

/**
 * libultra guMtxIdentF
 * Keywords: Matrix, Identity, Float
 */
extern void guMtxIdentF(float mf[4][4]);
	#if OOT_DEBUG
		asm("guMtxIdentF = 0x80101B40");
	#elif OOT_U_1_0
		//asm("guMtxIdentF = 0xDEADBEEF");
	#endif

/**
 * libultra guLookAtF
 * Keywords: Matrix, LookAt, Float
 */
extern void guLookAtF(
	float mf[4][4],
	float xEye, float yEye, float zEye
	, float xAt, float yAt, float zAt
	, float xUp, float yUp, float zUp
);
	#if OOT_DEBUG
		asm("guLookAtF = 0x80101B90");
	#elif OOT_U_1_0
		//asm("guLookAtF = 0xDEADBEEF");
	#endif

/**
 * libultra guLookAt
 * Keywords: Matrix, LookAt
 */
extern void guLookAt(
	Mtx* m,
	float xEye, float yEye, float zEye
	, float xAt, float yAt, float zAt
	, float xUp, float yUp, float zUp
);
	#if OOT_DEBUG
		asm("guLookAt = 0x80101E34");
	#elif OOT_U_1_0
		//asm("guLookAt = 0xDEADBEEF");
	#endif

/**
 * libultra guLookAtHiliteF
 * Keywords: Matrix, LookAt, Hilite, Float
 */
extern void guLookAtHiliteF(
	float mf[4][4], LookAt* l, Hilite* h
	, float xEye, float yEye, float zEye,
	, float xAt, float yAt, float zAt
	, float xUp, float yUp, float zUp
	, float xl1, float yl1, float zl1
	, float xl2, float yl2, float zl2
	, int32_t hiliteWidth, int32_t hiliteHeight
);
	#if OOT_DEBUG
		asm("guLookAtHiliteF = 0x801032B0");
	#elif OOT_U_1_0
		//asm("guLookAtHiliteF = 0xDEADBEEF");
	#endif

/**
 * libultra guLookAtHilite
 * Keywords: Matrix, LookAt, Hilite
 */
extern void guLookAtHilite(
	Mtx* m, LookAt* l, Hilite* h
	, float xEye, float yEye, float zEye,
	, float xAt, float yAt, float zAt
	, float xUp, float yUp, float zUp
	, float xl1, float yl1, float zl1
	, float xl2, float yl2, float zl2
	, int32_t hiliteWidth, int32_t hiliteHeight
);
	#if OOT_DEBUG
		asm("guLookAtHilite = 0x80103A70");
	#elif OOT_U_1_0
		//asm("guLookAtHilite = 0xDEADBEEF");
	#endif

/**
 * libultra guMtxIdent
 * Keywords: Matrix, Identity
 */
extern void guMtxIdent(Mtx* m);
	#if OOT_DEBUG
		asm("guMtxIdent = 0x80103B60");
	#elif OOT_U_1_0
		//asm("guMtxIdent = 0xDEADBEEF");
	#endif

/**
 * libultra guPositionF
 * Keywords: Matrix, Position, Float
 */
extern void guPositionF(float mf[4][4], float rot, float pitch, float yaw, float scale, float x, float y, float z);
	#if OOT_DEBUG
		asm("guPositionF = 0x80103BB0");
	#elif OOT_U_1_0
		//asm("guPositionF = 0xDEADBEEF");
	#endif

/**
 * libultra guPosition
 * Keywords: Matrix, Position
 */
extern void guPosition(Mtx* m, float rot, float pitch, float yaw, float scale, float x, float y, float z);
	#if OOT_DEBUG
		asm("guPosition = 0x80103D58");
	#elif OOT_U_1_0
		//asm("guPosition = 0xDEADBEEF");
	#endif

/**
 * libultra guRotateF
 * Keywords: Matrix, Rotate, Float
 */
extern void guRotateF(float mf[4][4], float a, float x, float y, float z);
	#if OOT_DEBUG
		asm("guRotateF = 0x80103E20");
	#elif OOT_U_1_0
		//asm("guRotateF = 0xDEADBEEF");
	#endif

/**
 * libultra guRotate
 * Keywords: Matrix, Rotate
 */
extern void guRotate(Mtx* m, float a, float x, float y, float z);
	#if OOT_DEBUG
		asm("guRotate = 0x80103FA4");
	#elif OOT_U_1_0
		//asm("guRotate = 0xDEADBEEF");
	#endif

/**
 * libultra guNormalize
 * Keywords: Matrix, Rotate
 */
extern void guNormalize(float x, float y, float z);
	#if OOT_DEBUG
		asm("guNormalize = 0x80104160");
	#elif OOT_U_1_0
		//asm("guNormalize = 0xDEADBEEF");
	#endif

/**
 * libultra guOrthoF
 * Keywords: Matrix, Orthographic, Float
 */
extern void guOrthoF(float mf[4][4], float left, float right, float bottom, float top, float near, float far, float scale);
	#if OOT_DEBUG
		asm("guOrthoF = 0x80104450");
	#elif OOT_U_1_0
		//asm("guOrthoF = 0xDEADBEEF");
	#endif

/**
 * libultra guOrtho
 * Keywords: Matrix, Orthographic
 */
extern void guOrtho(Mtx* m, float left, float right, float bottom, float top, float near, float far, float scale);
	#if OOT_DEBUG
		asm("guOrtho = 0x801045A4");
	#elif OOT_U_1_0
		//asm("guOrtho = 0xDEADBEEF");
	#endif

/**
 * libultra guTranslate
 * Keywords: Matrix, Translate
 */
extern void guTranslate(Mtx* m, float x, float y, float z);
	#if OOT_DEBUG
		asm("guTranslate = 0x80105C20");
	#elif OOT_U_1_0
		//asm("guTranslate = 0xDEADBEEF");
	#endif

/**
 * libultra guMtxF2L (Floating Point to Fixed Point)
 * Keywords: Matrix, Float, Fixed
 */
extern void guMtxF2L(float mf[4][4], Mtx* m);
	#if OOT_DEBUG
		asm("guMtxF2L = 0x801064E0");
	#elif OOT_U_1_0
		//asm("guMtxF2L = 0xDEADBEEF");
	#endif

#endif // __Z64OVL_H__
