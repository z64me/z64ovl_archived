#ifndef __Z64OVL_H__
#define __Z64OVL_H__
#endif /* Unterminated ifndef error? */

#include "h/ichain.h"

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

#define SQRT(ARG0) sqrtf((ARG0))

/****
 * Copy data from the ROM into VRAM, using Direct Memory Access (DMA)
 ***/
extern void load_data_from_rom(uint32_t* vram_addr, uint32_t* vrom_addr, uint32_t size, uint32_t unk);
    #if OOT_DEBUG
        asm("load_data_from_rom = 0x80001AA0");
	#elif OOT_U_1_0
		asm("load_data_from_rom = 0x80000DF0");
	#elif MM_U_1_0
		asm("load_data_from_rom = 0x80080C90");
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
 * copy `num` bytes from `src` to `dst`
 * This function is not used inside any existing overlay
 ***/
extern void memory_copy(const void *src, void *dst, const uint32_t num);
	#if OOT_DEBUG
		asm("memory_copy = 0x80006F10");
	#elif OOT_U_1_0
		// TODO Needs 1.0 equivalent!
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
 * Allocates to the tail end of the given heap (0x10 aligned)
 * A0 = Allocation Handle ptr | A1 = Size | V0 = ptr to free space
 */
extern void* allocate_from_top(void* heap_ptr, int32_t alloc_size);
	#if OOT_DEBUG
		asm("external_func_80001FF0 = 0x80001FF0");
	#elif OOT_U_1_0
		asm("external_func_80001FF0 = 0x800A01B8");
	#endif

/**
 * print32_t a debug message to the console
 * use DEBUG_MESSAGE(), which will disable debug_message() calls unless compiling with DEBUG defined
 */
extern void debug_message(const char *msg, ...);
#ifdef DEBUG
	#define DEBUG_MESSAGE debug_message
#else
	#define DEBUG_MESSAGE
#endif
	#if OOT_DEBUG
		asm("debug_message = 0x80002130");
	#elif OOT_U_1_0
		asm("debug_message = 0x800ACE60");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_80002E10(void);
	#if OOT_DEBUG
		asm("external_func_80002E10 = 0x80002E10");
	#elif OOT_U_1_0
		// TODO Needs 1.0 equivalent!
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_80002E50(void);
	#if OOT_DEBUG
		asm("external_func_80002E50 = 0x80002E50");
	#elif OOT_U_1_0
		// TODO Needs 1.0 equivalent!
	#endif

/**
 * Drops a collectible
 * a0 = global context | a1 = actor instance + 0x24 | a2 = drop ID
 */
extern void item_drop_collectible(z64_global_t *global, vec3f_t *pos2, uint16_t drop_id);
	#if OOT_DEBUG
		asm("item_drop_collectible = 0x8001F548");
	#elif OOT_U_1_0
		asm("item_drop_collectible = 0x80013678");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8001F77C(void);
	#if OOT_DEBUG
		asm("external_func_8001F77C = 0x8001F77C");
	#elif OOT_U_1_0
		asm("external_func_8001F77C = 0x800138B0");
	#endif

/**
 * Randomized item spawn
 * a0 = global context | a1 = actor instance | a2 = position array | a3 = drop table ID
 */
extern void item_drop_random_collectible(z64_actor_t* global, z64_actor_t* actor, vec3f_t* position, uint16_t drop_id);
	#if OOT_DEBUG
		asm("external_func_8001F940 = 0x8001F940");
	#elif OOT_U_1_0
		asm("external_func_8001F940 = 0x80013A84");
	#elif MM_U_1_0
		asm("external_func_8001F940 = 0x800A7D28");
		asm("external_func_800A7D28 = 0x800A7D28");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8001FDF0(void);
	#if OOT_DEBUG
		asm("external_func_8001FDF0 = 0x8001FDF0");
	#elif OOT_U_1_0
		asm("external_func_8001FDF0 = 0x80013F30");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_80020120(void);
	#if OOT_DEBUG
		asm("external_func_80020120 = 0x80020120");
	#elif OOT_U_1_0
		asm("external_func_80020120 = 0x80014254");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_80026230(void);
	#if OOT_DEBUG
		asm("external_func_80026230 = 0x80026230");
	#elif OOT_U_1_0
		asm("external_func_80026230 = 0x8001A0E0");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_80026608(void);
	#if OOT_DEBUG
		asm("external_func_80026608 = 0x80026608");
	#elif OOT_U_1_0
		asm("external_func_80026608 = 0x8001A468");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_80026690(void);
	#if OOT_DEBUG
		asm("external_func_80026690 = 0x80026690");
	#elif OOT_U_1_0
		// TODO Needs 1.0 equivalent!
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_80026860(void);
	#if OOT_DEBUG
		asm("external_func_80026860 = 0x80026860");
	#elif OOT_U_1_0
		// TODO Needs 1.0 equivalent!
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_80026A6C(void);
	#if OOT_DEBUG
		asm("external_func_80026A6C = 0x80026A6C");
	#elif OOT_U_1_0
		// TODO Needs 1.0 equivalent!
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_80026B0C(void);
	#if OOT_DEBUG
		asm("external_func_80026B0C = 0x80026B0C");
	#elif OOT_U_1_0
		asm("external_func_80026B0C = 0x8001A890");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void effect_add(void);
	#if OOT_DEBUG
		asm("effect_add = 0x80026CD4");
	#elif OOT_U_1_0
		asm("effect_add = 0x8001AA5C");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8002709C(z64_global_t *gl, uint32_t a1);
	#if OOT_DEBUG
		asm("external_func_8002709C = 0x8002709C");
	#elif OOT_U_1_0
		asm("external_func_8002709C = 0x8001AE04");
	#endif

/**
 * Kill Particle
 * A0 = Particle Instance Ptr
 * This function is not used inside any existing overlay
 */
extern void particle_kill(void* particle_instance);
	#if OOT_DEBUG
		asm("external_func_800274E0 = 0x800274E0");
	#elif OOT_U_1_0
		asm("external_func_800274E0 = 0x8001B1A4");
	#endif

/**
 * TODO This function is completely undocumented
 * This function is not used inside any existing overlay
 */
extern void external_func_80027704(void);
	#if OOT_DEBUG
		asm("external_func_80027704 = 0x80027704");
	#elif OOT_U_1_0
		asm("external_func_80027704 = 0x8001B3D0");
	#endif

/**
 * TODO This function is completely undocumented
 * This function is not used inside any existing overlay
 */
extern void external_func_80027DD4(void);
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
extern void external_func_8002829C(void);
	#if OOT_DEBUG
		asm("external_func_8002829C = 0x8002829C");
	#elif OOT_U_1_0
		asm("external_func_8002829C = 0x8001BD94");
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
		// TODO Needs 1.0 equivalent!
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

/**
 * Spawn Particle 0x00 Type 5 (Wrapper for 8001BCE0)
 * TODO These notes need converted into a C function prototype
 */
extern void external_func_800286CC(void);
	#if OOT_DEBUG
		asm("external_func_800286CC = 0x800286CC");
	#elif OOT_U_1_0
		asm("external_func_800286CC = 0x8001C1C4");
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
 * Spawn Particle 0x01 (Wrapper for 8001C6A8)
 * TODO These notes need converted into a C function prototype
 */
extern void external_func_80028B74(void);
	#if OOT_DEBUG
		asm("external_func_80028B74 = 0x80028B74");
	#elif OOT_U_1_0
		asm("external_func_80028B74 = 0x8001C66C");
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

/**
 * Spawn Particle 0x03
 * TODO These notes need converted into a C function prototype
 */
extern void effect_spawn_bomb2(void);
	#if OOT_DEBUG
		asm("effect_spawn_bomb2 = 0x80028E84");
	#elif OOT_U_1_0
		asm("effect_spawn_bomb2 = 0x8001C97C");
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
extern void external_func_80029024(void);
	#if OOT_DEBUG
		asm("external_func_80029024 = 0x80029024");
	#elif OOT_U_1_0
		asm("external_func_80029024 = 0x8001CB1C");
	#endif

/**
 * Spawn Particle 0x05 (Wrapper for 8001CDD4)
 * TODO These notes need converted into a C function prototype
 * Bomb Spark
 */
extern void effect_spawn_spark(void);
	#if OOT_DEBUG
		asm("effect_spawn_spark = 0x80029184");
	#elif OOT_U_1_0
		asm("effect_spawn_spark = 0x8001CC7C");
	#endif

/**
 * Spawn Particle 0x06 (Wrapper for 8001CE18)
 * TODO These notes need converted into a C function prototype
 */
extern void effect_spawn_fire_breath(void);
	#if OOT_DEBUG
		asm("effect_spawn_fire_breath = 0x800293A0");
	#elif OOT_U_1_0
		asm("effect_spawn_fire_breath = 0x8001CE98");
	#elif MM_U_1_0
		asm("effect_spawn_fire_breath = 0x800B1DC8");
	#endif

/**
 * Spawn Particle 0x07
 * TODO These notes need converted into a C function prototype
 */
extern void effect_spawn_water_bubble(void);
	#if OOT_DEBUG
		asm("effect_spawn_water_bubble = 0x800293E4");
	#elif OOT_U_1_0
		asm("effect_spawn_water_bubble = 0x8001CEDC");
	#elif MM_U_1_0
		asm("effect_spawn_water_bubble = 0x800B1E94");
	#endif

/**
 * Spawn Particle 0x09
 * TODO These notes need converted into a C function prototype
 */
extern void effect_spawn_water_ripple(z64_global_t *global, vec3f_t *pos, int32_t unk0, int32_t unk1, int32_t unk2);
	#if OOT_DEBUG
		asm("effect_spawn_water_ripple = 0x80029444");
	#elif OOT_U_1_0
		asm("effect_spawn_water_ripple = 0x8001CF3C");
	#elif MM_U_1_0
		asm("effect_spawn_water_ripple = 0x800B1EF4");
	#endif

/**
 * Spawn Particle 0x0A
 * TODO These notes need converted into a C function prototype
 */
extern void effect_spawn_water_splash(
	z64_global_t *global, vec3f_t *pos,
	int32_t unk0, int32_t unk1, int32_t unk2, int32_t unk3
);
	#if OOT_DEBUG
		asm("effect_spawn_water_splash = 0x8002949C");
	#elif OOT_U_1_0
		asm("effect_spawn_water_splash = 0x8001CF94");
	#elif MM_U_1_0
		asm("effect_spawn_water_splash = 0x800B1F4C");
	#endif

/**
 * Spawn Particle 0x0B
 * TODO These notes need converted into a C function prototype
 */
extern void effect_spawn_magma(void);
	#if OOT_DEBUG
		asm("effect_spawn_magma = 0x80029530");
	#elif OOT_U_1_0
		asm("effect_spawn_magma = 0x8001D028");
	#endif

/**
 * Spawn Particle 0x0D
 * TODO These notes need converted into a C function prototype
 */
extern void effect_spawn_lightning(z64_global_t *global, vec3f_t *position, uint32_t *opacity, uint32_t *color, uint16_t size);
    #if OOT_DEBUG
        asm("effect_spawn_lightning= 0x800295A0");
    #elif OOT_U_1_0
        asm("effect_spawn_lightning= 0x8001D098");
    #endif

/**
 * Spawn Particle 0x0E
 * TODO These notes need converted into a C function prototype
 */
extern void external_func_80029618(void);
	#if OOT_DEBUG
		asm("external_func_80029618 = 0x80029618");
	#elif OOT_U_1_0
		asm("external_func_80029618 = 0x8001D110");
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
		asm("external_func_800B210C = 0x800B210C");
	#endif

/**
 * Spawn Particle 0x0F
 * TODO These notes need converted into a C function prototype
 */
extern void external_func_80029724(void);
	#if OOT_DEBUG
		asm("external_func_80029724 = 0x80029724");
	#elif OOT_U_1_0
		asm("external_func_80029724 = 0x8001D21C");
	#endif

/**
 * Spawn N Particle 0x0F (Wrapper for 8001D21C)
 * TODO These notes need converted into a C function prototype
 * SP+0x18 = int16_t Particles to Spawn
 */
extern void external_func_800297A4(void);
	#if OOT_DEBUG
		asm("external_func_800297A4 = 0x800297A4");
	#elif OOT_U_1_0
		asm("external_func_800297A4 = 0x8001D29C");
	#endif

/**
 * Spawn Particle 0x11 (Wrapper for 8001D438)
 * TODO These notes need converted into a C function prototype
 */
extern void effect_spawn_splash(void);
	#if OOT_DEBUG
		asm("effect_spawn_splash = 0x800299AC");
	#elif OOT_U_1_0
		asm("effect_spawn_splash = 0x8001D4A8");
	#endif

/**
 * Spawn Particle 0x13
 * TODO These notes need converted into a C function prototype
 */
extern void effect_spawn_magma2(void);
	#if OOT_DEBUG
		asm("effect_spawn_magma2 = 0x80029B90");
	#elif OOT_U_1_0
		asm("effect_spawn_magma2 = 0x8001D68C");
	#endif

/**
 * Spawn Particle 0x14
 * TODO These notes need converted into a C function prototype
 */
extern void effect_spawn_stone1(void);
	#if OOT_DEBUG
		asm("effect_spawn_stone1 = 0x80029C00");
	#elif OOT_U_1_0
		asm("effect_spawn_stone1 = 0x8001D6FC");
	#endif

/**
 * Spawn Particle 0x15 (Wrapper for 8001D750)
 * TODO These notes need converted into a C function prototype
 */
extern void external_func_80029CA4(void);
	#if OOT_DEBUG
		asm("external_func_80029CA4 = 0x80029CA4");
	#elif OOT_U_1_0
		asm("external_func_80029CA4 = 0x8001D7A8");
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
extern void effect_spawn_k_fire(void);
	#if OOT_DEBUG
		asm("effect_spawn_k_fire = 0x80029DBC");
	#elif OOT_U_1_0
		asm("effect_spawn_k_fire = 0x8001D8C8");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_80029E24(void);
	#if OOT_DEBUG
		asm("external_func_80029E24 = 0x80029E24");
	#elif OOT_U_1_0
		// TODO Needs 1.0 equivalent!
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
extern void effect_spawn_fragment(
	z64_global_t *global,
	vec3f_t *burst_depth_y, vec3f_t *burst_depth_x, vec3f_t *burst_origin,
	int16_t gravity_influence,
	int16_t u0,
	int16_t rotation_speed,
	int16_t burst_velocity,
	uint8_t u1,
	int16_t scale,
	uint8_t u2,
	int16_t jitter,
	int32_t duration,
	int16_t u3,
	int16_t objno,
	uint32_t dlist
	);
	#if OOT_DEBUG
		asm("effect_spawn_fragment = 0x80029E8C");
	#elif OOT_U_1_0
		asm("effect_spawn_fragment = 0x8001D998");
	#elif MM_U_1_0
		asm("effect_spawn_fragment = 0x800B2810");
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
extern void effect_spawn_fire_tail(void);
	#if OOT_DEBUG
		asm("effect_spawn_fire_tail = 0x8002A3C4");
	#elif OOT_U_1_0
		asm("effect_spawn_fire_tail = 0x8001DED8");
	#endif

/**
 * Spawn Particle 0x1D
 * TODO These notes need converted into a C function prototype
 */
extern void effect_spawn_en_fire(void);
	#if OOT_DEBUG
		asm("effect_spawn_en_fire = 0x8002A4D4");
	#elif OOT_U_1_0
		asm("effect_spawn_en_fire = 0x8001DFEC");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8002A54C(void);
	#if OOT_DEBUG
		asm("external_func_8002A54C = 0x8002A54C");
	#elif OOT_U_1_0
		// TODO Needs 1.0 equivalent!
	#endif

/**
 * Spawn Particle 0x1E
 * TODO These notes need converted into a C function prototype
 */
extern void effect_spawn_extra(void);
	#if OOT_DEBUG
		asm("effect_spawn_extra = 0x8002A5F4");
	#elif OOT_U_1_0
		asm("effect_spawn_extra = 0x8001E110");
	#endif

/**
 * Spawn Particle 0x1F
 * TODO These notes need converted into a C function prototype
 */
extern void effect_spawn_fcircle(void);
	#if OOT_DEBUG
		asm("effect_spawn_fcircle = 0x8002A65C");
	#elif OOT_U_1_0
		asm("effect_spawn_fcircle = 0x8001E178");
	#endif

/**
 * Spawn Particle 0x20
 * TODO These notes need converted into a C function prototype
 */
extern void effect_spawn_dead_dekubaba(void);
	#if OOT_DEBUG
		asm("effect_spawn_dead_dekubaba = 0x8002A6B8");
	#elif OOT_U_1_0
		asm("effect_spawn_dead_dekubaba = 0x8001E1D4");
	#endif

/**
 * Spawn Particle 0x21
 * TODO These notes need converted into a C function prototype
 */
extern void effect_spawn_dead_dodongo(void);
	#if OOT_DEBUG
		asm("effect_spawn_dead_dodongo = 0x8002A770");
	#elif OOT_U_1_0
		asm("effect_spawn_dead_dodongo = 0x8001E28C");
	#endif

/**
 * Spawn Particle 0x22 (Wrapper for 8001E3B0)
 * TODO These notes need converted into a C function prototype
 */
extern void effect_spawn_dead_deku_scrub(void);
	#if OOT_DEBUG
		asm("effect_spawn_dead_deku_scrub = 0x8002A90C");
	#elif OOT_U_1_0
		asm("effect_spawn_dead_deku_scrub = 0x8001E428");
	#endif

/**
 * Spawn Particle 0x23 (Wrapper for 8001E478)
 * TODO These notes need converted into a C function prototype
 */
extern void effect_spawn_dead_sound(void);
	#if OOT_DEBUG
		asm("effect_spawn_dead_sound = 0x8002A9F4");
	#elif OOT_U_1_0
		asm("effect_spawn_dead_sound = 0x8001E510");
	#endif

/**
 * Spawn Particle 0x24
 * TODO These notes need converted into a C function prototype
 */
extern void effect_spawn_ice_smoke(void);
	#if OOT_DEBUG
		asm("effect_spawn_ice_smoke = 0x8002AA44");
	#elif OOT_U_1_0
		asm("effect_spawn_ice_smoke = 0x8001E560");
	#endif

/**
 * Draws shadow until instance is destroyed (use in constructor)
 * rot2 = pointer to rotation vector, generally rot_2 in the actor (ex: &en->actor.rot_2)
 * unk0 = unknown float, gets stored at dest + 0x08
 * drawfunc = ACTOR_SHADOW_DRAWFUNC_CIRCLE for circular shadows, ACTOR_SHADOW_DRAWFUNC_TEARDROP for teardrop shadows attached to feet, gets stored at dest + 0x0C
 * radius = size of shadow(s), gets stored at dest + 0x10
 */
extern void actor_init_shadow(z64_rot_t *rot2, f32 unk0, void *drawfunc, f32 radius);
	#if OOT_DEBUG
		asm("actor_init_shadow = 0x8002B1E0");
		asm("ACTOR_SHADOW_DRAWFUNC_CIRCLE = 0x8002B5EC");
		asm("ACTOR_SHADOW_DRAWFUNC_TEARDROP = 0x8002B8C4");
	#elif OOT_U_1_0
		asm("actor_init_shadow = 0x8001EC20");
		asm("ACTOR_SHADOW_DRAWFUNC_CIRCLE = 0x8001EFF4");
		asm("ACTOR_SHADOW_DRAWFUNC_TEARDROP = 0x8001F280");
	#elif MM_U_1_0
		asm("actor_init_shadow = 0x800B3BA4");
		asm("ACTOR_SHADOW_DRAWFUNC_CIRCLE = 0x800B3FC0");
		asm("ACTOR_SHADOW_DRAWFUNC_TEARDROP = 0x800B42F8");
	#endif
	extern char // drawfunc must be the address of one of the following:
		ACTOR_SHADOW_DRAWFUNC_CIRCLE,
		ACTOR_SHADOW_DRAWFUNC_TEARDROP;

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
extern int32_t flag_get_switch(z64_global_t *global, int32_t flag);
	#if OOT_DEBUG
		asm("flag_get_switch = 0x8002CB40");
	#elif OOT_U_1_0
		asm("flag_get_switch = 0x8002049C");
	#elif MM_U_1_0
		asm("flag_get_switch = 0x800B5BB0");
	#endif

/**
 * Sets Switch Flag to 1
 */
extern void flag_set_switch(z64_global_t *global, int32_t flag);
	#if OOT_DEBUG
		asm("flag_set_switch = 0x8002CB74");
	#elif OOT_U_1_0
		asm("flag_set_switch = 0x800204D0");
	#elif MM_U_1_0
		asm("flag_set_switch = 0x800B5BF4");
	#endif

/**
 * Sets Switch Flag to 0
 */
extern void flag_unset_switch(z64_global_t *global, int32_t flag);
	#if OOT_DEBUG
		asm("flag_unset_switch = 0x8002CBB4");
	#elif OOT_U_1_0
		asm("flag_unset_switch = 0x80020510");
	#elif MM_U_1_0
		asm("flag_unset_switch = 0x800B5C34");
	#endif

/**
 * Tests if Unused Scene Flag is Set
 * This function is not used inside any existing overlay
 */
extern int32_t flag_get_uscene(z64_global_t *global, int32_t flag);
	#if OOT_DEBUG
		asm("flag_get_uscene = 0x8002CBF8");
	#elif OOT_U_1_0
		asm("flag_get_uscene = 0x80020554");
	#endif

/**
 * Sets Unused Scene Flag to 1
 * This function is not used inside any existing overlay
 */
extern void flag_set_uscene(z64_global_t *global, int32_t flag);
	#if OOT_DEBUG
		asm("flag_set_uscene = 0x8002CC2C");
	#elif OOT_U_1_0
		asm("flag_set_uscene = 0x80020588");
	#endif

/**
 * Sets Unused Scene Flag to 0
 * This function is not used inside any existing overlay
 */
extern void flag_unset_uscene(z64_global_t *global, int32_t flag);
	#if OOT_DEBUG
		asm("flag_unset_uscene = 0x8002CC6C");
	#elif OOT_U_1_0
		asm("flag_unset_uscene = 0x800205C8");
	#endif

/**
 * Tests if a Chest Flag is set
 */
extern int32_t flag_get_treasure(z64_global_t *global, int32_t flag);
	#if OOT_DEBUG
		asm("flag_get_treasure = 0x8002CCB0");
	#elif OOT_U_1_0
		asm("flag_get_treasure = 0x8002060C");
	#endif

/**
 * Sets Chest Flag to 1
 */
extern void flag_set_treasure(z64_global_t *global, int32_t flag);
	#if OOT_DEBUG
		asm("flag_set_treasure = 0x8002CCC4");
	#elif OOT_U_1_0
		asm("flag_set_treasure = 0x80020624");
	#endif

/**
 * Test if a Room Clear Flag is set
 */
extern int32_t flag_get_roomclear(z64_global_t *global, int32_t flag);
	#if OOT_DEBUG
		asm("flag_get_roomclear = 0x8002CCDC");
	#elif OOT_U_1_0
		asm("flag_get_roomclear = 0x80020640");
	#endif

/**
 * Sets Room Clear Flag to 1
 */
extern void flag_set_roomclear(z64_global_t *global, int32_t flag);
	#if OOT_DEBUG
		asm("flag_set_roomclear = 0x8002CCF0");
	#elif OOT_U_1_0
		asm("flag_set_roomclear = 0x80020658");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8002CD08(void);
	#if OOT_DEBUG
		asm("external_func_8002CD08 = 0x8002CD08");
	#elif OOT_U_1_0
		// TODO Needs 1.0 equivalent!
	#endif

/**
 * Tests if Global Context + 0x1D40 Flag is set
 */
extern int32_t temp_clear_flag_get(z64_global_t *global, int32_t flag);
	#if OOT_DEBUG
		asm("temp_clear_flag_get = 0x8002CD24");
	#elif OOT_U_1_0
		asm("temp_clear_flag_get = 0x80020694");
	#elif MM_U_1_0
		asm("temp_clear_flag_get = 0x800B5D18");
	#endif

/**
 * Sets Global Context + 0x1D40 Flag to 1
 */
extern void temp_clear_flag_set(z64_global_t *global, int32_t flag);
	#if OOT_DEBUG
		asm("temp_clear_flag_set = 0x8002CD38");
	#elif OOT_U_1_0
		asm("temp_clear_flag_set = 0x800206AC");
	#elif MM_U_1_0
		asm("temp_clear_flag_set = 0x800B5D30");
	#endif

/**
 * Tests if Scene Collectible Flag is set
 */
extern int32_t flag_get_scenecollect(z64_global_t *global, int32_t flag);
	#if OOT_DEBUG
		asm("flag_get_scenecollect = 0x8002CD6C");
	#elif OOT_U_1_0
		asm("flag_get_scenecollect = 0x800206E8");
	#elif MM_U_1_0
		asm("flag_get_scenecollect = 0x800B5D6C");
	#endif

/**
 * Sets Scene Collectible Flag to 1
 */
extern void flag_set_scenecollect(z64_global_t *global, int32_t flag);
	#if OOT_DEBUG
		asm("flag_set_scenecollect = 0x8002CDA0");
	#elif OOT_U_1_0
		asm("flag_set_scenecollect = 0x8002071C");
	#elif MM_U_1_0
		asm("flag_set_scenecollect = 0x800B5DB0");
	#endif

/**
 * Boss Title
 * A0 - global context | A1 - A0 + 0x1D4C | A2 - (object pointer + texture offset inside the object)
 */
extern void actor_boss_title(z64_global_t *global, z64_global_t *global_plus_0x1D4C, uint32_t texture);
	#if OOT_DEBUG
		asm("actor_boss_title = 0x8002CE00");
	#elif OOT_U_1_0
		asm("actor_boss_title = 0x80020780");
	#elif MM_U_1_0
		asm("actor_boss_title = 0x800B5E0C");
	#endif

/**
 * Kill Actor (nulls draw/update, but does not deallocate)
 * actor - actor instance
 */
extern void actor_kill(z64_actor_t *actor);
	#if OOT_DEBUG
		asm("actor_kill = 0x8002D570");
	#elif OOT_U_1_0
		asm("actor_kill = 0x80020EB4");
	#elif MM_U_1_0
		asm("actor_kill = 0x800B670C");
	#endif

/**
 * Sets the actor height (used by navi, target arrows, camera face when an npc is talking, etc)
 * actor - actor instance
 * height - float Y position from actor origin
 */
extern void actor_set_height(z64_actor_t *actor, f32 height);
	#if OOT_DEBUG
		asm("actor_set_height = 0x8002D5B8");
	#elif OOT_U_1_0
		asm("actor_set_height = 0x80020F04");
	#elif MM_U_1_0
		asm("actor_set_height = 0x800B675C");
	#endif

/**
 * Scale Actor
 * actor - actor instance
 * scale - float value
 */
extern void actor_set_scale(z64_actor_t *actor, f32 scale);
	#if OOT_DEBUG
		asm("actor_set_scale = 0x8002D62C");
	#elif OOT_U_1_0
		asm("actor_set_scale = 0x80020F88");
	#elif MM_U_1_0
		asm("actor_set_scale = 0x800B67E0");
	#endif

/**
 * Update CPU Segment 0x06 to point32_t to actor's defined object dependency
 */
extern void actor_set_object(z64_global_t *global, z64_actor_t *actor);
	#if OOT_DEBUG
		asm("actor_set_object = 0x8002D644");
	#elif OOT_U_1_0
		asm("actor_set_object = 0x80020FA4");
	#elif MM_U_1_0
		asm("actor_set_object = 0x800B67FC");
	#endif

/**
 * Physics, updates XYZ coordinates of actor
 */
extern void actor_update_pos(z64_actor_t *actor);
	#if OOT_DEBUG
		asm("actor_update_pos = 0x8002D7EC");
	#elif OOT_U_1_0
		asm("actor_update_pos = 0x80021124");
	#elif MM_U_1_0
		asm("actor_update_pos = 0x800B69AC");
	#endif

/**
 * Physics, updates XYZ velocity vectors (+0x5C) of an actor
 * Only factors y component of speed rotation xyz (+0x30)
 */
extern void actor_update_vel(z64_actor_t *actor);
	#if OOT_DEBUG
		asm("actor_update_vel = 0x8002D868");
	#elif OOT_U_1_0
		asm("actor_update_vel = 0x800211A4");
	#endif

/**
 * Function to move in direction (0x32) at set velocity (0x68)
 * TODO These notes need converted into a C function prototype
 * a0 = pointer to start address of actor instance
 */
extern void external_func_8002D8E0(z64_actor_t *actor);
	#if OOT_DEBUG
		asm("external_func_8002D8E0 = 0x8002D8E0");
	#elif OOT_U_1_0
		asm("external_func_8002D8E0 = 0x8002121C");
	#elif MM_U_1_0
		asm("external_func_8002D8E0 = 0x800B6A88");
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
extern void external_func_8002D97C(void);
	#if OOT_DEBUG
		asm("external_func_8002D97C = 0x8002D97C");
	#elif OOT_U_1_0
		asm("external_func_8002D97C = 0x800212B8");
	#elif MM_U_1_0
		asm("external_func_8002D97C = 0x800B6B24");
		asm("external_func_800B6B24 = 0x800B6B24");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8002D9A4(void);
	#if OOT_DEBUG
		asm("external_func_8002D9A4 = 0x8002D9A4");
	#elif OOT_U_1_0
		asm("external_func_8002D9A4 = 0x800212E4");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8002DA78(void);
	#if OOT_DEBUG
		asm("external_func_8002DA78 = 0x8002DA78");
	#elif OOT_U_1_0
		asm("external_func_8002DA78 = 0x800213B4");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8002DAC0(void);
	#if OOT_DEBUG
		asm("external_func_8002DAC0 = 0x8002DAC0");
	#elif OOT_U_1_0
		asm("external_func_8002DAC0 = 0x8002140C");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8002DAE0(void);
	#if OOT_DEBUG
		asm("external_func_8002DAE0 = 0x8002DAE0");
	#elif OOT_U_1_0
		asm("external_func_8002DAE0 = 0x80021430");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8002DB28(void);
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
 * Calculates XYZ distance between actor (+0x24) and a point32_t  | Wrapper fo 80063E18
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

/**
 * Calculates XZ distance between actor (+0x24) and a Point
 * Wrapper for 80063EB8
 */
extern float math_distance_xz_actor_point(z64_actor_t *a, z64_point_t *b);
	#if OOT_DEBUG
		asm("math_distance_xz_actor_point32_t = 0x8002DBB0");
	#elif OOT_U_1_0
		asm("math_distance_xz_actor_point32_t = 0x80021528");
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
 * TODO This function is completely undocumented
 */
extern void external_func_8002DD78(void);
	#if OOT_DEBUG
		asm("external_func_8002DD78 = 0x8002DD78");
	#elif OOT_U_1_0
		asm("external_func_8002DD78 = 0x800216F8");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8002DDE4(void);
	#if OOT_DEBUG
		asm("external_func_8002DDE4 = 0x8002DDE4");
	#elif OOT_U_1_0
		asm("external_func_8002DDE4 = 0x80021768");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8002DDF4(void);
	#if OOT_DEBUG
		asm("external_func_8002DDF4 = 0x8002DDF4");
	#elif OOT_U_1_0
		asm("external_func_8002DDF4 = 0x8002177C");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8002DE04(void);
	#if OOT_DEBUG
		asm("external_func_8002DE04 = 0x8002DE04");
	#elif OOT_U_1_0
		asm("external_func_8002DE04 = 0x80021790");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8002DEEC(void);
	#if OOT_DEBUG
		asm("external_func_8002DEEC = 0x8002DEEC");
	#elif OOT_U_1_0
		asm("external_func_8002DEEC = 0x8002187C");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8002DF38(void);
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
extern void link_set_cutscene_action(
	z64_global_t    *global
	, z64_actor_t   *actor
	, uint8_t        action
);
	#if OOT_DEBUG
		asm("link_set_cutscene_action = 0x8002DF54");
	#elif OOT_U_1_0
		asm("link_set_cutscene_action = 0x800218EC");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8002DF90(void);
	#if OOT_DEBUG
		asm("external_func_8002DF90 = 0x8002DF90");
	#elif OOT_U_1_0
		asm("external_func_8002DF90 = 0x80021928");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8002DFC8(void);
	#if OOT_DEBUG
		asm("external_func_8002DFC8 = 0x8002DFC8");
	#elif OOT_U_1_0
		asm("external_func_8002DFC8 = 0x80021968");
	#endif

/**
 * Detects if the angle to face Link is inside a1 range
 */
extern int32_t actor_angle_link_in_range(z64_actor_t *actor, int16_t angle);
	#if OOT_DEBUG
		asm("actor_angle_link_in_range = 0x8002E084");
	#elif OOT_U_1_0
		asm("actor_angle_link_in_range = 0x80021A28");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8002E12C(void);
	#if OOT_DEBUG
		asm("external_func_8002E12C = 0x8002E12C");
	#elif OOT_U_1_0
		asm("external_func_8002E12C = 0x80021AD4");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8002E1A8(void);
	#if OOT_DEBUG
		asm("external_func_8002E1A8 = 0x8002E1A8");
	#elif OOT_U_1_0
		asm("external_func_8002E1A8 = 0x80021B54");
	#endif

/**
 * possibly primary actor collision call
 * required in order for shadow initialized in actor_init_shadow to work
 * TODO Test this stuff more thoroughly in-game
 * TODO arguments below/radius may actually be swapped, test these more carefully
 * below = space below actor coordinates to test if ground is below actor
 * radius = radius for moving actor out of wall in case it is placed inside wall
 * above = space above actor coordinates to test if ceiling is above actor
 * En_Niw_Lady uses the arguments (gctx, &en->actor, 20.0f, 20.0f, 60.0f, 0x0000001D)
 * old notes for reference:
 * A0 = Global Context | A1 = Actor Instance | A2 = float wallCheckHeight? (26f for Link) | A3 = float wallPushback? (18f/14f for Adult/Child Link) | SP+0x10 float ? (56f/40f for Adult/Child Link) | SP+0x14 int32_t (type?)
 */
extern void external_func_8002E4B4(z64_global_t *global, z64_actor_t *actor, f32 below, f32 radius, f32 above, uint32_t flags);
	#if OOT_DEBUG
		asm("external_func_8002E4B4 = 0x8002E4B4");
	#elif OOT_U_1_0
		asm("external_func_8002E4B4 = 0x80021E6C");
	#elif MM_U_1_0
		asm("external_func_8002E4B4 = 0x800B78B8");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8002EABC(void);
	#if OOT_DEBUG
		asm("external_func_8002EABC = 0x8002EABC");
	#elif OOT_U_1_0
		// TODO Needs 1.0 equivalent!
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8002EB44(void);
	#if OOT_DEBUG
		asm("external_func_8002EB44 = 0x8002EB44");
	#elif OOT_U_1_0
		// TODO Needs 1.0 equivalent!
	#endif

/**
 * Sets lighting angles for shiny things or something.
 * TODO These notes need converted into a C function prototype
 */
extern void external_func_8002EBCC(z64_actor_t *a0, z64_global_t *gl, int32_t a2);
	#if OOT_DEBUG
		asm("external_func_8002EBCC = 0x8002EBCC");
	#elif OOT_U_1_0
		asm("external_func_8002EBCC = 0x80022438");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8002ED80(void);
	#if OOT_DEBUG
		asm("external_func_8002ED80 = 0x8002ED80");
	#elif OOT_U_1_0
		asm("external_func_8002ED80 = 0x80022554");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8002EF14(void);
	#if OOT_DEBUG
		asm("external_func_8002EF14 = 0x8002EF14");
	#elif OOT_U_1_0
		// TODO Needs 1.0 equivalent!
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
extern int32_t external_func_8002F194(z64_actor_t *actor, z64_global_t *global);
	#if OOT_DEBUG
		asm("external_func_8002F194 = 0x8002F194");
	#elif OOT_U_1_0
		asm("external_func_8002F194 = 0x80022930");
	#endif

/**
 * Makes a cylinder-shaped region around the actor in which Link is able to speak to and trade with the actor.
 * A0 = Actor Instance | A1 = Global Context | A2 = float, xy distance | A3 = float, y distance | SP+0x10 = Trade Item Index
 */
extern void actor_poll_trade_cylinder(z64_actor_t *actor, z64_global_t *, float dist_xz, float dist_y, uint8_t item_index
);
	#if OOT_DEBUG
		asm("actor_npc_trade_request = 0x8002F1C4");
	#elif OOT_U_1_0
		asm("actor_npc_trade_request = 0x80022960");
	#endif

/**
 * Makes a cube-shaped (or, more specifically, a regular-cylinder-shaped) region around the actor in which Link is able to speak to and trade with the actor (Wrapper for 8002F1C4)
 * Passes A2 into A2 and A3 of inner function
 * A0 = Actor Instance | A1 = Global Context | A2 = float, xyz distance | A3 = Trade Item Index
 */
extern void actor_poll_trade_cube(z64_actor_t *actor, z64_global_t *global, float distance, uint8_t item_index);
	#if OOT_DEBUG
		asm("external_func_8002F298 = 0x8002F298");
	#elif OOT_U_1_0
		asm("external_func_8002F298 = 0x80022A34");
	#endif

/**
 * Makes a cube-shaped (or, more specifically, a regular-cylinder-shaped) region around the actor in which Link is able to speak with the actor (Wrapper for 80022A34)
 * Calls wrapped function with A3 = 0
 * TODO These notes need converted into a C function prototype
 * A0 = Actor Instance | A1 = Global Context | A2 = float distance?
 */
extern void actor_poll_speak_cube(z64_actor_t *actor, z64_global_t *gl, float distance);
	#if OOT_DEBUG
		asm("external_func_8002F2CC = 0x8002F2CC");
	#elif OOT_U_1_0
		asm("external_func_8002F2CC = 0x80022A68");
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
		asm("external_func_800B863C = 0x800B863C");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8002F334(void);
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
extern int32_t actor_npc_trade_get(z64_global_t *global);
	#if OOT_DEBUG
		asm("actor_npc_trade_get = 0x8002F368");
	#elif OOT_U_1_0
		asm("actor_npc_trade_get = 0x80022B04");
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
		asm("external_func_800B8898 = 0x800B8898");
	#endif

/**
 * Is Actor Held? Or Interacting?
 * TODO Question marks: let's get to the bottom of this. Also, return type.
 * A0 = Actor Instance | V0 = 0 if Instance + 0x118 is null, else 1
 */
extern int32_t actor_is_held(z64_actor_t *actor, z64_global_t *global);
	#if OOT_DEBUG
		asm("actor_is_held = 0x8002F410");
	#elif OOT_U_1_0
		asm("actor_is_held = 0x80022BB0");
	#endif

/**
 * Give Item
 * TODO get_item_id, is it uint8_t, uint16_t, or uint32_t?
 * TODO: a different name may be more fitting
 * A0 = Actor instance //Actor giving item
 * A1 = Global Context
 * A2 = Get Item ID
 * A3 = float, max xz distance from actor to Link that item will be given
 * SP+10 = float, max y distance from actor to Link that item will be given
 */
extern void actor_give_item(
	z64_actor_t *actor,
	z64_global_t *global,
	uint8_t get_item_id,
	float range_xz, float range_y
);
	#if OOT_DEBUG
		asm("actor_give_item = 0x8002F434");
	#elif OOT_U_1_0
		asm("actor_give_item = 0x80022BD4");
	#endif

/**
 * Give Item Wrapper (80022BD4) | Sets A3 to 50.0f, SP+0x10 to 10.0f
 * TODO These notes need converted into a C function prototype
 * A0 = Actor Instance | A1 = Global Context | A2 = Get Item Id
 */
/*wrapper for actor_give_item, provides range_xz and range_y*/
/*void actor_give_item_50xz_10y(z64_actor_t *actor, z64_global_t *global, char get_item_id)
{
   actor_give_item(actor, global, get_item_id, 50.0f, 10.0f);
}*/
extern void actor_give_item_50xz_10y(z64_actor_t *actor, z64_global_t *global, int8_t get_item_id);
	#if OOT_DEBUG
		asm("external_func_8002F554 = 0x8002F554");
	#elif OOT_U_1_0
		asm("external_func_8002F554 = 0x80022CF4");
	#endif

/**
 * Give Item Wrapper (80022CF4) | Sets A2 to 0
 * TODO These notes need converted into a C function prototype
 * A0 = Actor Instance | A1 = Global Context
 */
/*wrapper for actor_give_item_50xz_10y, provides get_item_id*/
/*void actor_give_item_gid0(z64_actor_t *actor, z64_global_t *global)
{
   actor_give_item_50xz_10y(actor, global, 0);
}*/
extern void actor_give_item_gid0(z64_actor_t *actor, z64_global_t *global);
	#if OOT_DEBUG
		asm("actor_give_item_gid0 = 0x8002F580");
	#elif OOT_U_1_0
		asm("actor_give_item_gid0 = 0x80022D20");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern int32_t external_func_8002F5A0(void);
	#if OOT_DEBUG
		asm("external_func_8002F5A0 = 0x8002F5A0");
	#elif OOT_U_1_0
		asm("external_func_8002F5A0 = 0x80022D40");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8002F5C4(void);
	#if OOT_DEBUG
		asm("external_func_8002F5C4 = 0x8002F5C4");
	#elif OOT_U_1_0
		asm("external_func_8002F5C4 = 0x80022D64");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8002F5F0(void);
	#if OOT_DEBUG
		asm("external_func_8002F5F0 = 0x8002F5F0");
	#elif OOT_U_1_0
		asm("external_func_8002F5F0 = 0x80022D94");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8002F618(void);
	#if OOT_DEBUG
		asm("external_func_8002F618 = 0x8002F618");
	#elif OOT_U_1_0
		asm("external_func_8002F618 = 0x80022DBC");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8002F63C(void);
	#if OOT_DEBUG
		asm("external_func_8002F63C = 0x8002F63C");
	#elif OOT_U_1_0
		asm("external_func_8002F63C = 0x80022DE0");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8002F674(void);
	#if OOT_DEBUG
		asm("external_func_8002F674 = 0x8002F674");
	#elif OOT_U_1_0
		asm("external_func_8002F674 = 0x80022E18");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8002F698(void);
	#if OOT_DEBUG
		asm("external_func_8002F698 = 0x8002F698");
	#elif OOT_U_1_0
		// TODO Needs 1.0 equivalent!
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8002F6D4(void);
	#if OOT_DEBUG
		asm("external_func_8002F6D4 = 0x8002F6D4");
	#elif OOT_U_1_0
		asm("external_func_8002F6D4 = 0x80022E7C");
	#elif MM_U_1_0
		asm("external_func_8002F6D4 = 0x800B8D50");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8002F71C(void);
	#if OOT_DEBUG
		asm("external_func_8002F71C = 0x8002F71C");
	#elif OOT_U_1_0
		asm("external_func_8002F71C = 0x80022EC4");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8002F758(z64_global_t *gl, void *gl830, float a, float b, float *c, void *unk);
	#if OOT_DEBUG
		asm("external_func_8002F758 = 0x8002F758");
	#elif OOT_U_1_0
		// TODO Needs 1.0 equivalent!
	#elif MM_U_1_0
		asm("external_func_8002F6D4 = 0x800CA1E8");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8002F7A0(void);
	#if OOT_DEBUG
		asm("external_func_8002F7A0 = 0x8002F7A0");
	#elif OOT_U_1_0
		asm("external_func_8002F7A0 = 0x80022F48");
	#elif MM_U_1_0
		asm("external_func_8002F7A0 = 0x800B8E1C");
		asm("external_func_800B8E1C = 0x800B8E1C");
	#endif

/**
 * Play Sound Effect (Actor)
 */
extern void sound_play_actor(z64_actor_t *actor, uint16_t sound_id);
	#if OOT_DEBUG
		asm("sound_play_actor = 0x8002F7DC");
	#elif OOT_U_1_0
		asm("sound_play_actor = 0x80022F84");
	#endif

/**
 * Play Sound Effect (Actor)
 * TODO There are three identical functions... distinguish the difference and fix names
 */
extern void sound_play_actor2(z64_actor_t *actor, uint16_t sound_id);
	#if OOT_DEBUG
		asm("sound_play_actor2 = 0x8002F828");
	#elif OOT_U_1_0
		asm("sound_play_actor2 = 0x80022FD0");
	#elif MM_U_1_0
		asm("sound_play_actor2 = 0x800B8EC8");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8002F850(void);
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
extern void external_func_8002F948(void);
	#if OOT_DEBUG
		asm("external_func_8002F948 = 0x8002F948");
	#elif OOT_U_1_0
		asm("external_func_8002F948 = 0x80023108");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void actor_flag_play_sound(z64_actor_t *actor, uint16_t sfx_id);
	#if OOT_DEBUG
		asm("actor_flag_play_sound = 0x8002F974");
	#elif OOT_U_1_0
		asm("actor_flag_play_sound = 0x8002313C");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8002F994(void);
	#if OOT_DEBUG
		asm("external_func_8002F994 = 0x8002F994");
	#elif OOT_U_1_0
		asm("external_func_8002F994 = 0x80023164");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8002F9EC(void);
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
extern void actor_set_draw_distance(z64_global_t *global, z64_actor_t *actor, void *a2 /*actor+0xE4*/, float *a3 /*actor+0xF0*/);
	#if OOT_DEBUG
		asm("actor_set_draw_distance = 0x800314D4");
	#elif OOT_U_1_0
		asm("actor_set_draw_distance = 0x800249DC");
	#endif

/**
 * Spawn Actor
 * TODO a0 = global context + 0x1C24, do we really pass it in this way?
 * A0 = Global Context + 0x1C24 | A1 = Global Context | A2 = int16_t Actor Id | A3 = float x | SP+0x10 = float y | SP+0x14 = float z | SP+0x18 = rotx | SP+0x1C = roty | SP+0x20 = rotz | SP+0x24 = int16_t var | V0 = Pointer to new actor, or null
 */
extern void *actor_spawn(void *actor_context/*gl_ctx+0x1C24*/, z64_global_t *global, int16_t actor_id, f32 x, f32 y, f32 z, int16_t rot_x, int16_t rot_y, int16_t rot_z, uint16_t variable);
	#if OOT_DEBUG
		asm("actor_spawn = 0x80031F50");
	#elif OOT_U_1_0
		asm("actor_spawn = 0x80025110");
	#elif MM_U_1_0
		asm("actor_spawn = 0x800BAC60");
	#endif

/**
 * Spawn actor attached to `dest`, returns pointer to new actor `newactor` or NULL on failure
 * `newactor` + 0x118 will be set to `actor_id`
 * `dest` + 0x11C will point32_t to `newactor`
 * `newactor` will be bound to `dest`'s room unless spawned actor is global (room=-1)
 * TODO do something with a0?
 * A0 = Global Context + 0x1C24 | A1 = Actor* attachToInstance | A2 = Global Context | A3 = int16_t Actor Id | SP + 0x10 = float x | SP + 0x14 = float y | SP + 0x18 = float z | SP + 0x1C = int16_t rotx | SP + 0x20 = int16_t roty | SP + 0x24 = int16_t rotz | SP + 0x28 = int16_t var | V0 = Pointer to new actor, or null if allocation failed
 */
extern z64_actor_t *actor_spawn_attached(uint32_t a0/*gl_ctx+0x1C24*/, z64_actor_t *dest, int16_t actor_id, f32 x, f32 y, f32 z, int16_t rot_x, int16_t rot_y, int16_t rot_z, uint16_t variable);
	#if OOT_DEBUG
		asm("actor_spawn_attached = 0x80032458");
	#elif OOT_U_1_0
		asm("actor_spawn_attached = 0x800253F0");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_80032C3C(void);
	#if OOT_DEBUG
		asm("external_func_80032C3C = 0x80032C3C");
	#elif OOT_U_1_0
		asm("external_func_80032C3C = 0x80025B0C");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_80032C7C(void);
	#if OOT_DEBUG
		asm("external_func_80032C7C = 0x80032C7C");
	#elif OOT_U_1_0
		asm("external_func_80032C7C = 0x80025B4C");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_80032E24(void);
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
extern z64_actor_t *actor_is_bombed(z64_global_t *global, z64_collider_cylinder_main_t *capsule);
	#if OOT_DEBUG
		asm("actor_is_bombed = 0x80033640");
	#elif OOT_U_1_0
		asm("actor_is_bombed = 0x800264C8");
	#endif

/**
 * Unknown, collision detection related
 * TODO These notes need converted into a C function prototype
 * a0 = global context | a1 = actor instance | v0 = unknown
 */
extern int32_t external_func_80033684(z64_global_t *global, void *actor);
	#if OOT_DEBUG
		asm("external_func_80033684 = 0x80033684");
	#elif OOT_U_1_0
		asm("external_func_80033684 = 0x8002650C");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_80033748(z64_global_t *gl, char *actor_ctxt, z64_actor_t *a, uint32_t arg_unalignedF);
	#if OOT_DEBUG
		asm("external_func_80033748 = 0x80033748");
	#elif OOT_U_1_0
		asm("external_func_80033748 = 0x800265D4");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_80033780(void);
	#if OOT_DEBUG
		asm("external_func_80033780 = 0x80033780");
	#elif OOT_U_1_0
		asm("external_func_80033780 = 0x80026614");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_80033940(void);
	#if OOT_DEBUG
		asm("external_func_80033940 = 0x80033940");
	#elif OOT_U_1_0
		asm("external_func_80033940 = 0x800267D4");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800339B8(void);
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
extern void external_func_80033A84(void);
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
extern void external_func_80033AB8(void);
	#if OOT_DEBUG
		asm("external_func_80033AB8 = 0x80033AB8");
	#elif OOT_U_1_0
		asm("external_func_80033AB8 = 0x80026950");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_80033AEC(void);
	#if OOT_DEBUG
		asm("external_func_80033AEC = 0x80033AEC");
	#elif OOT_U_1_0
		asm("external_func_80033AEC = 0x80026984");
	#endif

/**
 * Draw circular shadow at actor coordinates
 * pos = pointer to an actor's internal position (actor + 0x24) (ex. &en->actor.pos_2)
 * scale = pointer to scale vector (ex. vec3f_t s={1,1,1}; pass &s in as this argument)
 * alpha = opacity of the shadow
 * a0 actor pointer + 0x24 (position array) | a1  scale, 12 byte array | a2 0x00FF | a3 global context
 */
extern void actor_shadow_circle(vec3f_t *pos, vec3f_t *scale, uint8_t alpha, z64_global_t *global);
	#if OOT_DEBUG
		asm("actor_shadow_circle = 0x80033C30");
	#elif OOT_U_1_0
		asm("actor_shadow_circle = 0x80026AD0");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_80033DB8(void);
	#if OOT_DEBUG
		asm("external_func_80033DB8 = 0x80033DB8");
	#elif OOT_U_1_0
		// TODO Needs 1.0 equivalent!
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_80033E1C(void);
	#if OOT_DEBUG
		asm("external_func_80033E1C = 0x80033E1C");
	#elif OOT_U_1_0
		// TODO Needs 1.0 equivalent!
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_80033E88(void);
	#if OOT_DEBUG
		asm("external_func_80033E88 = 0x80033E88");
	#elif OOT_U_1_0
		asm("external_func_80033E88 = 0x80026CF4");
	#endif

/**
 * Generates a random floating point32_t between 0 and N exclusive
 * TODO These notes need converted into a C function prototype
 * F12 = N, exclusive upper bound | F0 = result
 */
extern f32 math_rand_f32(float n);
	#if OOT_DEBUG
		asm("math_rand_f32 = 0x80033EF8");
	#elif OOT_U_1_0
		asm("math_rand_f32 = 0x80026D64");
	#elif MM_U_1_0
		asm("math_rand_f32 = 0x80179594");
	#endif

/**
 * Multiplies value by a random scalar between -0.5 and 0.5 exclusive
 * TODO These notes need converted into a C function prototype
 * F12 = N | F0 = result
 */
extern float external_func_80033F20(float n);
	#if OOT_DEBUG
		asm("external_func_80033F20 = 0x80033F20");
	#elif OOT_U_1_0
		asm("external_func_80033F20 = 0x80026D90");
	#elif MM_U_1_0
		asm("external_func_80033F20 = 0x801795C0");
		asm("external_func_801795C0 = 0x801795C0");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_80033F54(void);
	#if OOT_DEBUG
		asm("external_func_80033F54 = 0x80033F54");
	#elif OOT_U_1_0
		// TODO Needs 1.0 equivalent!
	#endif

/**
 * Wrapper for 800511B8
 * TODO These notes need converted into a C function prototype
 */
extern void external_func_8003424C(void);
	#if OOT_DEBUG
		asm("external_func_8003424C = 0x8003424C");
	#elif OOT_U_1_0
		asm("external_func_8003424C = 0x80027070");
	#endif

/**
 * TODO what does this one do?
 */
extern void external_func_8003426C(z64_actor_t *actor, int32_t unk0, int32_t unk1, int32_t unk2, int32_t unk3);
	#if OOT_DEBUG
		asm("external_func_8003426C = 0x8003426C");
	#elif OOT_U_1_0
		asm("external_func_8003426C = 0x80027090");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8003435C(void);
	#if OOT_DEBUG
		asm("external_func_8003435C = 0x8003435C");
	#elif OOT_U_1_0
		// TODO Needs 1.0 equivalent!
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800343CC(void);
	#if OOT_DEBUG
		asm("external_func_800343CC = 0x800343CC");
	#elif OOT_U_1_0
		asm("external_func_800343CC = 0x800271FC");
	#endif

/**
 * TODO These notes need converted into a C function prototype
 * A0 = int16_t
 */
extern void external_func_800347E8(void);
	#if OOT_DEBUG
		asm("external_func_800347E8 = 0x800347E8");
	#elif OOT_U_1_0
		asm("external_func_800347E8 = 0x80027620");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_80034A14(void);
	#if OOT_DEBUG
		asm("external_func_80034A14 = 0x80034A14");
	#elif OOT_U_1_0
		asm("external_func_80034A14 = 0x80027854");
	#endif

/**
	* Draw Matrix-Enabled Object with an opacity attribute
	* Wrapper for 800A273C
	* TODO Variable name cleanup, better notes
 */
extern void skelanime_draw_mtx_xlu(z64_global_t *global, z64_skelanime_t *skelanime, void *internal0, void *internal1, z64_actor_t *actor, uint8_t opacity);
	#if OOT_DEBUG
		asm("skelanime_draw_mtx_xlu = 0x80034BA0");
	#elif OOT_U_1_0
		asm("skelanime_draw_mtx_xlu = 0x800279CC");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_80034CC4(void);
	#if OOT_DEBUG
		asm("external_func_80034CC4 = 0x80034CC4");
	#elif OOT_U_1_0
		// TODO Needs 1.0 equivalent!
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_80034DD4(void);
	#if OOT_DEBUG
		asm("external_func_80034DD4 = 0x80034DD4");
	#elif OOT_U_1_0
		asm("external_func_80034DD4 = 0x80027BA8");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_80034EC0(void);
	#if OOT_DEBUG
		asm("external_func_80034EC0 = 0x80034EC0");
	#elif OOT_U_1_0
		asm("external_func_80034EC0 = 0x80027C98");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_80034F54(void);
	#if OOT_DEBUG
		asm("external_func_80034F54 = 0x80034F54");
	#elif OOT_U_1_0
		asm("external_func_80034F54 = 0x80027D30");
	#endif

/**
 * Draw a single display list to POLY_OPA_DISP
 */
extern void draw_dlist_opa(z64_global_t *global, uint32_t dlist);
	#if OOT_DEBUG
		asm("draw_dlist_opa = 0x80035260");
	#elif OOT_U_1_0
		asm("draw_dlist_opa = 0x80028048");
	#elif MM_U_1_0
		asm("draw_dlist_opa = 0x800BDFC0");
	#endif

/**
 * Draw a single display list, affected by Lens of Truth?
 * TODO There's a question mark, we need to confirm whether Lens of Truth has anything to do with it
 * a0 - global context | a1 - DList segment offset | a2 - Unknown, set to 0
 */
extern void draw_dlist_xlu(z64_global_t *global, uint32_t dlist);
	#if OOT_DEBUG
		asm("draw_dlist_xlu = 0x80035324");
	#elif OOT_U_1_0
		asm("draw_dlist_xlu = 0x800280C8");
	#elif MM_U_1_0
		asm("draw_dlist_xlu = 0x800BE03C");
	#endif

/**
 * Finds the closest actor instance of a specified id and type within specified range.
 * a0 - global context | a1 - actor instance | a2 - actor id (-1 = any) | a3 - category | 0x10($sp) distance from actor"
 */
extern z64_actor_t* find_closest_actor_instance_within_range(z64_global_t *global, z64_actor_t *actor, int16_t actor_id, z64_actor_type_t type, float range);
	#if OOT_DEBUG
		asm("find_closest_actor_instance_within_range = 0x800353F4");
	#elif OOT_U_1_0
		asm("find_closest_actor_instance_within_range = 0x80028158");
	#endif

/**
 * Checks if link is at certain distance, and if link is attacking, doesn't check jumpslashes
 * TODO These notes need converted into a C function prototype
 * a0 - global context | a1 - actor instance | a2 - float value | a3 - ???? | 0x10($sp) - rotation value? | 0x14($sp) - rotation value 0xB6(s0)? | v0 - returns true/false
 */
extern void external_func_800354B4(void);
	#if OOT_DEBUG
		asm("external_func_800354B4 = 0x800354B4");
	#elif OOT_U_1_0
		asm("external_func_800354B4 = 0x8002821C");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8003555C(void);
	#if OOT_DEBUG
		asm("external_func_8003555C = 0x8003555C");
	#elif OOT_U_1_0
		asm("external_func_8003555C = 0x800282C4");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800355B8(void);
	#if OOT_DEBUG
		asm("external_func_800355B8 = 0x800355B8");
	#elif OOT_U_1_0
		asm("external_func_800355B8 = 0x80028320");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800355E4(void);
	#if OOT_DEBUG
		asm("external_func_800355E4 = 0x800355E4");
	#elif OOT_U_1_0
		asm("external_func_800355E4 = 0x8002834C");
	#endif

/**
 * Subtracts damage amount (colliding damage source) from *actor's health
 */
extern void actor_update_health(z64_actor_t *actor);
	#if OOT_DEBUG
		asm("actor_update_health = 0x80035628");
	#elif OOT_U_1_0
		asm("actor_update_health = 0x80028390");
	#elif MM_U_1_0
		asm("actor_update_health = 0x800BE22C");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_80035650(void);
	#if OOT_DEBUG
		asm("external_func_80035650 = 0x80035650");
	#elif OOT_U_1_0
		asm("external_func_80035650 = 0x800283BC");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8003573C(void);
	#if OOT_DEBUG
		asm("external_func_8003573C = 0x8003573C");
	#elif OOT_U_1_0
		asm("external_func_8003573C = 0x800284A8");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_80035844(void);
	#if OOT_DEBUG
		asm("external_func_80035844 = 0x80035844");
	#elif OOT_U_1_0
		asm("external_func_80035844 = 0x800285B0");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800358DC(void);
	#if OOT_DEBUG
		asm("external_func_800358DC = 0x800358DC");
	#elif OOT_U_1_0
		// TODO Needs 1.0 equivalent!
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800359B8(void);
	#if OOT_DEBUG
		asm("external_func_800359B8 = 0x800359B8");
	#elif OOT_U_1_0
		asm("external_func_800359B8 = 0x80028720");
	#endif

/**
 * Tests if event_chk_inf flag is set
 */
extern int32_t flag_get_event_chk_inf(int32_t flag);
	#if OOT_DEBUG
		asm("flag_get_event_chk_inf = 0x80035B4C");
	#elif OOT_U_1_0
		asm("flag_get_event_chk_inf = 0x800288B4");
	#endif

/**
 * Sets event_chk_inf flag to 1
 */
extern void flag_set_event_chk_inf(int32_t flag);
	#if OOT_DEBUG
		asm("flag_set_event_chk_inf = 0x80035B74");
	#elif OOT_U_1_0
		asm("flag_set_event_chk_inf = 0x800288E0");
	#endif

/**
 * Tests if inf_table flag is set
 */
extern int32_t flag_get_inf_table(int32_t flag);
	#if OOT_DEBUG
		asm("flag_get_inf_table = 0x80035BA4");
	#elif OOT_U_1_0
		asm("flag_get_inf_table = 0x80028914");
	#endif

/**
 * Sets inf_table flag to 1
 */
extern void flag_set_inf_table(int32_t flag);
	#if OOT_DEBUG
		asm("flag_set_inf_table = 0x80035BCC");
	#elif OOT_U_1_0
		asm("flag_set_inf_table = 0x80028940");
	#endif

/**
 * Generic NPC Text Handler 7
 * TODO These notes need converted into a C function prototype
 * a0 - global context | a1 - 0xF (?) | v0 - (?)
 */
extern void external_func_80037C30(void);
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
extern void external_func_80037D98(void);
	#if OOT_DEBUG
		asm("external_func_80037D98 = 0x80037D98");
	#elif OOT_U_1_0
		asm("external_func_80037D98 = 0x8002AB20");
	#endif

/**
 * TODO This function has yet to have a name put to it.
 */
extern void external_func_80038290(z64_global_t *global, z64_actor_t *actor, void *rot_zx, void *rot_y, float pos_3_x, float pos_3_y, float pos_3_z);
	#if OOT_DEBUG
		asm("external_func_80038290 = 0x80038290");
	#elif OOT_U_1_0
		asm("external_func_80038290 = 0x8002B024");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_80038A28(void);
	#if OOT_DEBUG
		asm("external_func_80038A28 = 0x80038A28");
	#elif OOT_U_1_0
		// TODO Needs 1.0 equivalent!
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
extern float external_func_8003C940(void *gl830, void *floorpoly, void *unk_sp2C, z64_actor_t *actor, vec3f_t *pos);
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
 * TODO confirm return type, do something about global_plus_0x7C0, figure out unk[0,1]
 */
extern float math_raycast(uint32_t global_plus_0x7C0, void *unk0, void *unk1, z64_actor_t *actor, vec3f_t *pos);
	#if OOT_DEBUG
		#define RAYCAST_FAIL -32000.0f
		asm("math_raycast = 0x8003C9A4");
	#elif OOT_U_1_0
		#define RAYCAST_FAIL -32000.0f
		asm("math_raycast = 0x8002F4B8");
	#endif
	#define RAYCAST_SUCCESS(RAYCAST_RESULT) ( RAYCAST_RESULT > RAYCAST_FAIL )

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8003CA0C(void);
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
		asm("external_func_800C55C4 = 0x800C55C4");
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
 */
extern int32_t collision_sphere_test(z64_col_ctxt_t *gcollision, vec3f_t *point, float radius);
	#if OOT_DEBUG
		asm("collision_sphere_test = 0x8003E30C");
	#elif OOT_U_1_0
		asm("collision_sphere_test = 0x80030D08");
	#endif

/**
 * description
 * TODO These notes need converted into a C function prototype
 * TODO + 0x810 = bad, it needs a name
 * TODO Actor Index and entity have different meanings; this documentation is conflicting
 * A0 = Global Context | A1 = Global Context + 0x810 | A2 = Actor Index | A3 = result of func 80041880 | V0 = Mesh Collision Id
 */
extern uint32_t actor_register_dynapoly(z64_global_t *global, void *global_plus_0x810, z64_actor_t *actor, uint32_t dynacollision);
	#if OOT_DEBUG
		asm("actor_register_dynapoly = 0x8003EA74");
	#elif OOT_U_1_0
		asm("actor_register_dynapoly = 0x800313A4");
	#elif MM_U_1_0
		asm("actor_register_dynapoly = 0x800C6188");
	#endif

/**
 * description
 * TODO These notes need converted into a C function prototype
 * A0 = Global Context | A1 = Mesh Collision Id | V0 = Actor Instance or null
 */
extern void dynapolyinfo_get_actor(z64_global_t *gl, uint32_t dynapolyid);
	#if OOT_DEBUG
		asm("dynapolyinfo_get_actor = 0x8003EB84");
	#elif OOT_U_1_0
		asm("dynapolyinfo_get_actor = 0x80031464");
	#elif MM_U_1_0
		asm("dynapolyinfo_get_actor = 0x800C6248");
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
extern void dynapoly_free(z64_global_t *global, void *global_plus_0x810, uint32_t dynacollision_id);
	#if OOT_DEBUG
		asm("dynapoly_free = 0x8003ED58");
	#elif OOT_U_1_0
		asm("dynapoly_free = 0x80031638");
	#elif MM_U_1_0
		asm("dynapoly_free = 0x800C64CC");
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
extern void dynapoly_alloc(const uint32_t collision, void *collision_pointer);
	#if OOT_DEBUG
		asm("dynapoly_alloc = 0x80041880");
	#elif OOT_U_1_0
		asm("dynapoly_alloc = 0x80033EF4");
	#elif MM_U_1_0
		asm("dynapoly_alloc = 0x800C9564");
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
 * TODO These notes need converted into a C function prototype
 * A0 = Global Context + 0x7C0 | A1 = Polygon* | A2 = Mesh Collision Id | V0 = Result
 */
extern void external_func_800420C0(void);
	#if OOT_DEBUG
		asm("external_func_800420C0 = 0x800420C0");
	#elif OOT_U_1_0
		asm("external_func_800420C0 = 0x80034778");
	#endif

/**
 * TODO These notes need converted into a C function prototype
 * A0 = Global Context + 0x7C0 | A1 = Polygon* | A2 = Mesh Collision Id | V0 = Result
 */
extern void external_func_800420E4(void);
	#if OOT_DEBUG
		asm("external_func_800420E4 = 0x800420E4");
	#elif OOT_U_1_0
		asm("external_func_800420E4 = 0x800347A0");
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
 * TODO This function is completely undocumented
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
 * TODO This function is completely undocumented
 */
extern void external_func_800434A8(void);
	#if OOT_DEBUG
		asm("external_func_800434A8 = 0x800434A8");
	#elif OOT_U_1_0
		asm("external_func_800434A8 = 0x80035290");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_80043538(void);
	#if OOT_DEBUG
		asm("external_func_80043538 = 0x80043538");
	#elif OOT_U_1_0
		asm("external_func_80043538 = 0x8003532C");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_80043548(void);
	#if OOT_DEBUG
		asm("external_func_80043548 = 0x80043548");
	#elif OOT_U_1_0
		asm("external_func_80043548 = 0x80035340");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern int32_t external_func_8004356C(z64_actor_t *actor);
	#if OOT_DEBUG
		asm("external_func_8004356C = 0x8004356C");
	#elif OOT_U_1_0
		asm("external_func_8004356C = 0x80035364");
	#elif MM_U_1_0
		asm("external_func_8004356C = 0x800CAF70");
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
		// TODO Needs 1.0 equivalent!
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8005A9CC(void);
	#if OOT_DEBUG
		asm("external_func_8005A9CC = 0x8005A9CC");
	#elif OOT_U_1_0
		// TODO Needs 1.0 equivalent!
	#endif

/**
 * TODO This function is completely undocumented
 */
extern int16_t external_func_8005A9F4(uint32_t gl790);
	#if OOT_DEBUG
		asm("external_func_8005A9F4 = 0x8005A9F4");
	#elif OOT_U_1_0
		asm("external_func_8005A9F4 = 0x8004977C");
	#endif

/**
 * Camera earthquake?
 * TODO These notes need converted into a C function prototype
 */
extern void external_func_8005AA1C(void);
	#if OOT_DEBUG
		asm("external_func_8005AA1C = 0x8005AA1C");
	#elif OOT_U_1_0
		asm("external_func_8005AA1C = 0x800497A4");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8005AA90(void);
	#if OOT_DEBUG
		asm("external_func_8005AA90 = 0x8005AA90");
	#elif OOT_U_1_0
		// TODO Needs 1.0 equivalent!
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
 * Cutscene Camera?
 * TODO These notes need converted into a C function prototype
 * A0 = Cutscene Camera struct ptr | A1 = Focus Point32_t Tween List | A2 = Camera Position Tween List | A3 = Actor Instance (tracked actor)
 */
extern void external_func_8005AC6C(void);
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
		asm("external_func_800E01B8 = 0x800E01B8");
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
extern void actor_damage_chart_get(void);
	#if OOT_DEBUG
		asm("actor_damage_chart_get = 0x8005B200");
	#elif OOT_U_1_0
		asm("actor_damage_chart_get = 0x80049E10");
	#elif MM_U_1_0
		asm("actor_damage_chart_get = 0x800E03A0");
	#endif

/**
 * Initializes hitbox structure (different purpose than 8005C364?)
 * TODO These notes need converted into a C function prototype
 * a0 - global context | a1 - actor instance + 0x0150 (offset of hitbox struct in the instance)
 */
extern void external_func_8005BBF8(void);
	#if OOT_DEBUG
		asm("external_func_8005BBF8 = 0x8005BBF8");
	#elif OOT_U_1_0
		asm("external_func_8005BBF8 = 0x8004A484");
	#elif MM_U_1_0
		asm("external_func_8005BBF8 = 0x800E0B4C");
		asm("external_func_800E0B4C = 0x800E0B4C");
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

/**
 * Unloads hitbox structure  (different purpose than 8005C3AC?)
 * TODO These notes need converted into a C function prototype
 * a0 - global context | a1 - actor instance + 0x0150 (offset where you stored the hitbox struct)
 */
extern void external_func_8005BCC8(void);
	#if OOT_DEBUG
		asm("external_func_8005BCC8 = 0x8005BCC8");
	#elif OOT_U_1_0
		asm("external_func_8005BCC8 = 0x8004A550");
	#elif MM_U_1_0
		asm("external_func_8005BCC8 = 0x800E0C18");
		asm("external_func_800E0C18 = 0x800E0C18");
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

/**
 * Loads hitbox variable array to hitbox structure  (different purpose than 8005C4AC?)
 * TODO These notes need converted into a C function prototype
 * a0 - global context | a1 - actor instance + 0x0150 (offset of hitbox struct in the instance) | a2 - actor instance | a3 - hitbox variable array
 */
extern void external_func_8005C050(void);
	#if OOT_DEBUG
		asm("external_func_8005C050 = 0x8005C050");
	#elif OOT_U_1_0
		asm("external_func_8005C050 = 0x8004A874");
	#elif MM_U_1_0
		asm("external_func_8005C050 = 0x800E0E60");
		asm("external_func_800E0E60 = 0x800E0E60");
	#endif

/**
 * allocates memory for capsule
 * TODO These notes need converted into a C function prototype
 * a0 - global context | a1 - actor instance + 0x014C (offset of hitbox struct in the instance)
 */
extern void actor_collider_cylinder_alloc(z64_global_t *global, z64_collider_cylinder_main_t *collision);
	#if OOT_DEBUG
		asm("actor_collider_cylinder_alloc = 0x8005C364");
	#elif OOT_U_1_0
		asm("actor_collider_cylinder_alloc = 0x8004AB7C");
	#elif MM_U_1_0
		asm("actor_collider_cylinder_alloc = 0x800E119C");
	#endif

/**
 * frees memory associated with capsule
 * TODO These notes need converted into a C function prototype
 * a0 - global context | a1 - actor instance + 0x014C (offset where you stored the hitbox struct)
 */
extern void actor_collider_cylinder_free(z64_global_t *global, z64_collider_cylinder_main_t *collision);
	#if OOT_DEBUG
		asm("actor_collider_cylinder_free = 0x8005C3AC");
	#elif OOT_U_1_0
		asm("actor_collider_cylinder_free = 0x8004ABCC");
	#elif MM_U_1_0
		asm("actor_collider_cylinder_free = 0x800E11EC");
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
		asm("external_func_800E123C = 0x800E123C");
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
		asm("external_func_800E12A4 = 0x800E12A4");
	#endif

/**
 * Loads hitbox variable array to hitbox structure
 * dest = destination capsule structure within actor instance
 * actor = actor
 * source = capsule initialization data
 * a0 - global context | a1 - actor instance + 0x014C (offset of hitbox struct in the instance) | a2 - actor instance | a3 - hitbox variable array
 */
extern void actor_collider_cylinder_init(z64_global_t *global, z64_collider_cylinder_main_t *dest, z64_actor_t *actor, const z64_collider_cylinder_init_t *src);
	#if OOT_DEBUG
		asm("actor_collider_cylinder_init = 0x8005C4AC");
	#elif OOT_U_1_0
		asm("actor_collider_cylinder_init = 0x8004ACEC");
	#elif MM_U_1_0
		asm("actor_collider_cylinder_init = 0x800E1374");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8005C7E0(void);
	#if OOT_DEBUG
		asm("external_func_8005C7E0 = 0x8005C7E0");
	#elif OOT_U_1_0
		asm("external_func_8005C7E0 = 0x8004B064");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8005C8C8(void);
	#if OOT_DEBUG
		asm("external_func_8005C8C8 = 0x8005C8C8");
	#elif OOT_U_1_0
		asm("external_func_8005C8C8 = 0x8004B148");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8005CBAC(void);
	#if OOT_DEBUG
		asm("external_func_8005CBAC = 0x8005CBAC");
	#elif OOT_U_1_0
		asm("external_func_8005CBAC = 0x8004B3EC");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern int32_t external_func_8005D018(z64_global_t *gl, int32_t unk0);
	#if OOT_DEBUG
		asm("external_func_8005D018 = 0x8005D018");
	#elif OOT_U_1_0
		asm("external_func_8005D018 = 0x8004B858");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8005D060(z64_global_t *gl, void *a1);
	#if OOT_DEBUG
		asm("external_func_8005D060 = 0x8005D060");
	#elif OOT_U_1_0
		asm("external_func_8005D060 = 0x8004B8A8");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern int32_t external_func_8005D104(z64_global_t *gl, z64_collider_t *collider, z64_actor_t *a, z64_collider_cylinder_init_t *col_init);
	#if OOT_DEBUG
		asm("external_func_8005D104 = 0x8005D104");
	#elif OOT_U_1_0
		asm("external_func_8005D104 = 0x8004B960");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8005D160(void);
	#if OOT_DEBUG
		asm("external_func_8005D160 = 0x8005D160");
	#elif OOT_U_1_0
		// TODO Needs 1.0 equivalent!
	#endif

/**
 * Subscribe to collision pool 1, non-complex poly types | Called directly by actors
 * TODO Look into actors that use this function, there are conflicts between these notes and the function prototype, define a type for collision and figure out the return type
 * A0 = Global Context | A1 = 801DA300 //collision body groups | A2 = Collision Body Ptr | V0 = 0 or -1 based on 801DA302 lowest bit?
 */
extern void actor_collision_check_set_at(z64_global_t *global, void* simple_body_groups, z64_collider_cylinder_main_t *collision);
	#if OOT_DEBUG
		asm("actor_collision_check_set_at = 0x8005D79C");
	#elif OOT_U_1_0
		asm("actor_collision_check_set_at = 0x8004BD50");
	#elif MM_U_1_0
		asm("actor_collision_check_set_at = 0x800E2634");
	#endif

/**
 * //Subscribe to collision pool 2, non-complex poly types | //Called directly by actors
 * TODO Look into actors that use this function, there are conflicts between these notes and the function prototype, define a type for collision and figure out the return type
 * A0 = Global Context | A1 = 801DA300 //collision body groups | A2 = Collision Body Ptr | V0 = 0 or -1 based on 801DA302 lowest bit?
 */
extern void actor_collision_check_set_ac(z64_global_t *global, void* simple_body_groups, z64_collider_cylinder_main_t *collision);
	#if OOT_DEBUG
		asm("actor_collision_check_set_ac = 0x8005D9F4");
	#elif OOT_U_1_0
		asm("actor_collision_check_set_ac = 0x8004BF40");
	#elif MM_U_1_0
		asm("actor_collision_check_set_ac = 0x800E2740");
	#endif

/**
 * Subscribe to collision pool 3, non-complex poly types
 * TODO Look into actors that use this function, there are conflicts between these notes and the function prototype, define a type for collision and figure out the return type
 * A0 = Global Context | A1 = 801DA300 //collision body groups | A2 = Collision Body Ptr | V0 = 0 or -1 based on 801DA302 lowest bit? | Called directly by actors
 */
extern void actor_collision_check_set_ot(z64_global_t *global, void *simple_body_groups, z64_collider_cylinder_main_t *collision);
	#if OOT_DEBUG
		asm("actor_collision_check_set_ot = 0x8005DC4C");
	#elif OOT_U_1_0
		asm("actor_collision_check_set_ot = 0x8004C130");
	#elif MM_U_1_0
		asm("actor_collision_check_set_ot = 0x800E2928");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8005DFAC(void);
	#if OOT_DEBUG
		asm("external_func_8005DFAC = 0x8005DFAC");
	#elif OOT_U_1_0
		// TODO Needs 1.0 equivalent!
	#endif

/**
 * initializes damage chart part of actor
 * given a destination table, a pointer to a z64_damagechart_init_t, and a pointer to the initialization data
 * itemchart can be null, but damage_init should not be
 * //Actor 0095
 * TODO Types
 */
extern void external_func_80061ED4(void *table_dst, z64_damagechart_init_t *itemchart, uint32_t *damage_init);
	#if OOT_DEBUG
		asm("external_func_80061ED4 = 0x80061ED4");
	#elif OOT_U_1_0
		asm("external_func_80061ED4 = 0x80050344");
	#elif MM_U_1_0
		asm("external_func_80061ED4 = 0x800E7530");
		asm("external_func_800E7530 = 0x800E7530");
	#endif

/**
 * initializes damage chart part of actor
 * //Actor 0095
 * TODO These notes need converted into a C function prototype
 */
extern void external_func_80061EFC(void);
	#if OOT_DEBUG
		asm("external_func_80061EFC = 0x80061EFC");
	#elif OOT_U_1_0
		asm("external_func_80061EFC = 0x80050370");
	#elif MM_U_1_0
		asm("external_func_80061EFC = 0x800E755C");
		asm("external_func_800E755C = 0x800E755C");
	#endif

/**
 * Enables hitbox, only needs to be used one time?
 * TODO These notes need converted into a C function prototype
 * a0 - actor instance | a1 - actor instance + 0x014C (offset of hitbox struct in the instance)
 */
extern void actor_collider_cylinder_update(z64_actor_t *actor, z64_collider_cylinder_main_t *collision);
	#if OOT_DEBUG
		asm("actor_collider_cylinder_update = 0x800626DC");
	#elif OOT_U_1_0
		asm("actor_collider_cylinder_update = 0x80050B00");
	#elif MM_U_1_0
		asm("actor_collider_cylinder_update = 0x800E7DF8");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_80062718(void);
	#if OOT_DEBUG
		asm("external_func_80062718 = 0x80062718");
	#elif OOT_U_1_0
		// TODO Needs 1.0 equivalent!
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_80062734(void);
	#if OOT_DEBUG
		asm("external_func_80062734 = 0x80062734");
	#elif OOT_U_1_0
		asm("external_func_80062734 = 0x80050B64");
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

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800628A4(void);
	#if OOT_DEBUG
		asm("external_func_800628A4 = 0x800628A4");
	#elif OOT_U_1_0
		asm("external_func_800628A4 = 0x80050CE4");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_80062CD4(void);
	#if OOT_DEBUG
		asm("external_func_80062CD4 = 0x80062CD4");
	#elif OOT_U_1_0
		asm("external_func_80062CD4 = 0x80051124");
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
 * TODO This function is completely undocumented
 */
extern void external_func_80062DF4(void);
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
		// TODO Needs 1.0 equivalent!
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
	//AVAL(Z64GL_CUTSCENE_PLAY_SCRIPT, uint8_t, 0) = 1; /* Undefined? */
}

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800694A0(void);
	#if OOT_DEBUG
		asm("external_func_800694A0 = 0x800694A0");
	#elif OOT_U_1_0
		asm("external_func_800694A0 = 0x800570C0");
	#endif

/**
 * plays sound at position
 * TODO These notes need converted into a C function prototype
 * TODO Considering this uses an actor instance, is it any different from sound_play_actor?
 * a0 - global context | a1 - actor instance + 0x24 (position array of the sound) | a2 - 0x3C (radius?) | a3 - sound ID
 */
extern void sound_play_position(z64_global_t *global, vec3f_t *pos2, int32_t radius, uint16_t sfx_id);
	#if OOT_DEBUG
		asm("sound_play_position = 0x8006BAD8");
	#elif OOT_U_1_0
		asm("sound_play_position = 0x80058FF8");
	#elif MM_U_1_0
		asm("sound_play_position = 0x800F0568");
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
		// TODO Needs 1.0 equivalent!
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8006C438(void);
	#if OOT_DEBUG
		asm("external_func_8006C438 = 0x8006C438");
	#elif OOT_U_1_0
		// TODO Needs 1.0 equivalent!
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
		// TODO Needs 1.0 equivalent!
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8006C778(void);
	#if OOT_DEBUG
		asm("external_func_8006C778 = 0x8006C778");
	#elif OOT_U_1_0
		// TODO Needs 1.0 equivalent!
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
		// TODO Needs 1.0 equivalent!
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
		// TODO Needs 1.0 equivalent!
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8006F93C(void);
	#if OOT_DEBUG
		asm("external_func_8006F93C = 0x8006F93C");
	#elif OOT_U_1_0
		asm("external_func_8006F93C = 0x8005C690");
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
		// TODO Needs 1.0 equivalent!
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
extern void external_func_800773A8(void);
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
 */
extern void external_func_80077684(void);
	#if OOT_DEBUG
		asm("external_func_80077684 = 0x80077684");
	#elif OOT_U_1_0
		asm("external_func_80077684 = 0x800634D4");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800776E4(void);
	#if OOT_DEBUG
		asm("external_func_800776E4 = 0x800776E4");
	#elif OOT_U_1_0
		// TODO Needs 1.0 equivalent!
	#endif

/**
 * memset byte
 * A0 = Address | A1 = length (in bytes) | A2 = uint8_t value
 */
extern void memory_set(void *dst, const uint32_t len, const uint8_t value);
	#if OOT_DEBUG
		asm("memory_set = 0x800777E0");
	#elif OOT_U_1_0
		asm("memory_set = 0x80063630");
	#endif

/**
 * Math, Get cosine of short rotation angle
 * TODO Test in-game
 * A0 = int16_t rotation | F0 = cosine of A0
 */
extern float math_coss(int16_t angle);
	#if OOT_DEBUG
		asm("math_coss = 0x80077834");
	#elif OOT_U_1_0
		asm("math_coss = 0x80063684");
	#elif MM_U_1_0
		asm("math_coss = 0x800FED44");
	#endif

/**
 * Math, Get sine of short rotation angle
 * TODO Test in-game
 * A0 = int16_t rotation | F0 = sine of A0
 */
extern float math_sins(int16_t angle);
	#if OOT_DEBUG
		asm("math_sins = 0x80077870");
	#elif OOT_U_1_0
		asm("math_sins = 0x800636C4");
	#elif MM_U_1_0
		asm("math_sins = 0x800FED84");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800778AC(void);
	#if OOT_DEBUG
		asm("external_func_800778AC = 0x800778AC");
	#elif OOT_U_1_0
		asm("external_func_800778AC = 0x80063704");
	#endif

/**
 * TODO This function is completely undocumented
 * TODO possibly some kind of random number function...
 */
extern void external_func_8007797C(int16_t *unk0, const int32_t unk1, const int32_t unk2);
	#if OOT_DEBUG
		asm("external_func_8007797C = 0x8007797C");
	#elif OOT_U_1_0
		asm("external_func_8007797C = 0x800637D4");
	#endif

/**
 * Float approximator
 * TODO These notes need converted into a C function prototype
 * a0 - actor instance + 0x0198 (offset of stored float) | a1 - float value (target float) | a2 - float value (increments or decrements result by this until it reaches the target float) | v0 - returns 0 if it hasn't reached it, 1 if it does
 */
extern int32_t math_approxf(float *in_actor, int32_t target, float change);
	#if OOT_DEBUG
		asm("math_approxf = 0x80077A00");
	#elif OOT_U_1_0
		asm("math_approxf = 0x8006385C");
	#elif MM_U_1_0
		asm("math_approxf = 0x800FF03C");
	#endif

/**
 * i
 * TODO These notes need converted into a C function prototype
 */
extern void external_func_80077AF8(void);
	#if OOT_DEBUG
		asm("external_func_80077AF8 = 0x80077AF8");
	#elif OOT_U_1_0
		asm("external_func_80077AF8 = 0x80063958");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_80077B58(void);
	#if OOT_DEBUG
		asm("external_func_80077B58 = 0x80077B58");
	#elif OOT_U_1_0
		asm("external_func_80077B58 = 0x800639B8");
	#endif

/**
 * Generates random int16_t between 0 and `range` (exlusive), and adds `offset`
 */
extern int16_t math_rand_int16_t_offset(int16_t offset, int16_t range);
	#if OOT_DEBUG
		asm("math_rand_int16_t_offset = 0x80077D90");
	#elif OOT_U_1_0
		asm("math_rand_int16_t_offset = 0x80063BF0");
	#elif MM_U_1_0
		asm("math_rand_int16_t_offset = 0x800FF450");
	#endif

/**
 * Copy vec3f_t
 */
extern void math_vec3f_copy(vec3f_t *out, vec3f_t *in);
	#if OOT_DEBUG
		asm("math_vec3f_copy = 0x80077E40");
	#elif OOT_U_1_0
		asm("math_vec3f_copy = 0x80063CAC");
	#elif MM_U_1_0
		asm("math_vec3f_copy = 0x800FF50C");
	#endif

/**
 * convert vec3s_t to vec3f_t
 * Convert int16_t Coordinates to Float Coordinates
 */
extern void math_vec3f_from_vec3s(vec3f_t *out, vec3s_t *in);
	#if OOT_DEBUG
		asm("math_vec3f_from_vec3s = 0x80077E5C");
	#elif OOT_U_1_0
		asm("math_vec3f_from_vec3s = 0x80063CCC");
	#elif MM_U_1_0
		asm("math_vec3f_from_vec3s = 0x800FF54C");
	#endif

/**
 * get the sum of two vec3f_t types
 * out = a + b
 */
extern void math_vec3f_add(vec3f_t *a, vec3f_t *b, vec3f_t *out);
	#if OOT_DEBUG
		asm("math_vec3f_add = 0x80077E9C");
	#elif OOT_U_1_0
		asm("math_vec3f_add = 0x80063D10");
	#elif MM_U_1_0
		asm("math_vec3f_add = 0x800FF5BC");
	#endif

/**
 * get the difference of two vec3f_t types
 * out = a - b
 */
extern void math_vec3f_sub(vec3f_t *a, vec3f_t *b, vec3f_t *out);
	#if OOT_DEBUG
		asm("math_vec3f_sub = 0x80077ED0");
	#elif OOT_U_1_0
		asm("math_vec3f_sub = 0x80063D48");
	#elif MM_U_1_0
		asm("math_vec3f_sub = 0x800FF5F4");
	#endif

/**
 * get the difference of two vec3s_t types, stored as a vec3f_t
 * out = a - b
 * TODO Note that out, a, and b are ordered differently than the math_vec3f_sub version of this function; confirm whether this is actually correct
 * TODO confirm that it's actually a - b
 * A0 = Result Float Coord ptr (A - B) | A1 = int16_t coord A ptr | A2 = int16_t coord B ptr
 */
extern void math_vec3s_sub(vec3f_t *out, vec3s_t *a, vec3s_t *b);
	#if OOT_DEBUG
		asm("math_vec3s_sub = 0x80077F04");
	#elif OOT_U_1_0
		asm("math_vec3s_sub = 0x80063D80");
	#elif MM_U_1_0
		asm("math_vec3s_sub = 0x800FF62C");
	#endif

/**
 * multiply vec3f_t by scalar value
 * x *= scale
 * TODO is the scalar a float or an integer? Confirm in-game
 * A0 = Coord ptr | A1 = Scalar Value
 */
extern void math_vec3f_mul_scalar(vec3f_t *x, f32 scale);
	#if OOT_DEBUG
		asm("math_vec3f_mul_scalar = 0x80077F5C");
	#elif OOT_U_1_0
		asm("math_vec3f_mul_scalar = 0x80063DDC");
	#elif MM_U_1_0
		asm("math_vec3f_mul_scalar = 0x800FF688");
	#endif

/**
 * calculates distance between two vec3f_t types
 */
extern float math_vec3f_distance(vec3f_t *a, vec3f_t *b);
	#if OOT_DEBUG
		asm("math_vec3f_distance = 0x80077F90");
	#elif OOT_U_1_0
		asm("math_vec3f_distance = 0x80063E18");
	#elif MM_U_1_0
		asm("math_vec3f_distance = 0x80063E18");
	#endif

/**
 * calculates distance between two vec3f_t types and also does subtraction out = b - a
 * TODO math_vec3s_sub does out = a - b, this does b - a, confirm whether this is true...
 * A0 = Coord A ptr | A1 = Coord B ptr | A2 = Result B - A ptr | F0 = Distance
 */
extern float math_vec3f_distance_sub(vec3f_t *a, vec3f_t *b, vec3f_t *out);
	#if OOT_DEBUG
		asm("math_vec3f_distance_sub = 0x80077FD0");
	#elif OOT_U_1_0
		asm("math_vec3f_distance_sub = 0x80063E5C");
	#endif

/**
 * calculates XZ distance between two vec3f_t types
 * TODO These notes need converted into a C function prototype
 */
extern float math_vec3f_distance_xz(vec3f_t *a, vec3f_t *b);
	#if OOT_DEBUG
		asm("math_vec3f_distance_xz = 0x80078028");
	#elif OOT_U_1_0
		asm("math_vec3f_distance_xz = 0x80063EB8");
	#endif

/**
 * Calculates Arctan2 (X,Z) of two coordinates (A-B) | Wrapper for 800AA4F8
 * TODO These notes need converted into a C function prototype
 * A0 = Coord A ptr | A1 = Coord B ptr | V0 = int16_t rotation
 */
extern int16_t math_vec3f_atan2_xz(vec3f_t* coord1, vec3f_t* coord2);
	#if OOT_DEBUG
		asm("external_func_80078068 = 0x80078068");
	#elif OOT_U_1_0
		asm("external_func_80078068 = 0x80063F00");
	#elif MM_U_1_0
		asm("external_func_80078068 = 0x800FFA60");
		asm("external_func_800FFA60 = 0x800FFA60");
	#endif

/**
 * Calculates Arctan2 (distance(XZ), Y) of two coordinates | (A-B for Y coordinate)
 * TODO These notes need converted into a C function prototype
 * A0 = Coord A ptr | A1 = Coord B ptr | V0 = int16_t rotation
 */
extern int16_t math_vec3f_atan2_xz_y(vec3f_t* coord1, vec3f_t* coord2);
	#if OOT_DEBUG
		asm("external_func_8007809C = 0x8007809C");
	#elif OOT_U_1_0
		asm("external_func_8007809C = 0x80063F34");
	#elif MM_U_1_0
		asm("external_func_8007809C = 0x800FFA94");
		asm("external_func_800FFA94 = 0x800FFA94");
	#endif

/**
 * Instance Init, Initialize Variable Chain
 * TODO These notes need converted into a C function prototype
 * A0 = Actor Instance | A1 = Variable Initializer List ptr
 */
extern void actor_init_ichain(z64_actor_t *actor, uint32_t const *ichain);
	#if OOT_DEBUG
		asm("actor_init_ichain = 0x800780DC");
	#elif OOT_U_1_0
		asm("actor_init_ichain = 0x80063F7C");
	#elif MM_U_1_0
		asm("actor_init_ichain = 0x800FFADC");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_80078310(void);
	#if OOT_DEBUG
		asm("external_func_80078310 = 0x80078310");
	#elif OOT_U_1_0
		asm("external_func_80078310 = 0x80064178");
	#elif MM_U_1_0
		asm("external_func_80078310 = 0x800FFCD8");
	#endif

/**
 * smoothly aproximates a0 to a1, commonly used for smooth movement
 * keyword: tweening
 * TODO These notes need converted into a C function prototype
 * a0 - actor instance + xxxx (offset of the float that will change) | a1 - float where you want a0 to be aproximated to | a2 - float (amount?)a3 - float (smaller than a2)
 */
extern void external_func_8007841C(float *arg0, f32 arg1, f32 arg2, f32 arg3);
	#if OOT_DEBUG
		asm("external_func_8007841C = 0x8007841C");
	#elif OOT_U_1_0
		asm("external_func_8007841C = 0x80064280");
	#elif MM_U_1_0
		asm("external_func_8007841C = 0x800FFDF8");
	#endif

/**
 * TODO probably some kind of tweening function
 */
extern void external_func_8007848C(float *value, float a, float b);
	#if OOT_DEBUG
		asm("external_func_8007848C = 0x8007848C");
	#elif OOT_U_1_0
		asm("external_func_8007848C = 0x800642F0");
	#endif

/**
 * TODO figure out what this function does...
 * A0 = int16_t Rotation Pointer (Y this pass) | A1 = int16_t ? | A2 = ? | A3 = ?
 */
extern int32_t external_func_8007869C(int16_t *rot, int32_t unk0, int16_t unk1, int32_t unk2, int32_t unk3, uint32_t unk4);
	#if OOT_DEBUG
		asm("external_func_8007869C = 0x8007869C");
	#elif OOT_U_1_0
		asm("external_func_8007869C = 0x80064508");
	#elif MM_U_1_0
		asm("external_func_8007869C = 0x800FFEBC");
	#endif

/**
 * TODO figure out what this function does
 */
extern void external_func_800787BC(int16_t *rot, int32_t unk0, int16_t unk1, int32_t unk2);
	#if OOT_DEBUG
		asm("external_func_800787BC = 0x800787BC");
	#elif OOT_U_1_0
		asm("external_func_800787BC = 0x80064624");
	#endif

/**
 * Copy uint8_t[4] array
 * A0 = Destination ptr | A1 = Source ptr
 */
extern void mem_copy_uint8_t_4(void *dest, void *src);
	#if OOT_DEBUG
		asm("mem_copy_uint8_t_4 = 0x80078860");
	#elif OOT_U_1_0
		asm("mem_copy_uint8_t_4 = 0x800646C8");
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
 * Initialize Flame Light (Wrapper for 80065B70)
 * TODO These notes need converted into a C function prototype
 */
extern void external_func_80079D8C(uint32_t *a0, int32_t a1_x, int32_t a2_y, int32_t a3_z, uint8_t unk_00, uint32_t unk_01);
	#if OOT_DEBUG
		asm("external_func_80079D8C = 0x80079D8C");
	#elif OOT_U_1_0
		asm("external_func_80079D8C = 0x80065BCC");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_80079DF0(uint32_t *a0, int32_t a1_x, int32_t a2_y, int32_t a3_z, uint8_t unk_00, uint32_t unk_01);
	#if OOT_DEBUG
		asm("external_func_80079DF0 = 0x80079DF0");
	#elif OOT_U_1_0
		asm("external_func_80079DF0 = 0x80065C30");
	#endif

/**
 * Initialize Flame Color
 * writes RGBA to A0 + 0x08 (note alpha is short) | Called by 80065B70
 * TODO These notes need converted into a C function prototype
 * A0 = Blue Fire Instance + 0x19C | A1 = byte Red (0x9B this pass) | A2 = byte Green (0xD2 this pass) | A3 = byte Blue | SP + 0x10 = short Alpha?
 */
extern void external_func_80079E58(void *a0, uint8_t r, uint8_t g, uint8_t b, uint32_t a1);
	#if OOT_DEBUG
		asm("external_func_80079E58 = 0x80079E58");
	#elif OOT_U_1_0
		asm("external_func_80079E58 = 0x80065C98");
	#endif

/**
 * TODO This function is completely undocumented
 * Possible for initializing a light structure.
 */
extern void *external_func_8007A764(z64_global_t *gl, z64_lighting_t *lighting, uint32_t a3);
	#if OOT_DEBUG
		asm("external_func_8007A764 = 0x8007A764");
	#elif OOT_U_1_0
		asm("external_func_8007A764 = 0x800665B0");
	#endif

/**
 * TODO This function is completely undocumented
 * Possibly for "Freeing" a light structure.
 */
extern void external_func_8007A7C4(z64_global_t *gl, z64_lighting_t *lighting, void *a3);
	#if OOT_DEBUG
		asm("external_func_8007A7C4 = 0x8007A7C4");
	#elif OOT_U_1_0
		asm("external_func_8007A7C4 = 0x80066610");
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
 * TODO These notes need converted into a C function prototype
 * a0 - global context | a1 - actor instance
 */
extern void external_func_80080480(void);
	#if OOT_DEBUG
		asm("external_func_80080480 = 0x80080480");
	#elif OOT_U_1_0
		asm("external_func_80080480 = 0x8006BA10");
	#endif

/**
 * Enters cutscene mode and focuses the actor for a short time, playing a sound?
 * TODO These notes need converted into a C function prototype
 * a0 - global context | a1 - actor instance | a2 - sound ID?
 */
extern void external_func_800806BC(void);
	#if OOT_DEBUG
		asm("external_func_800806BC = 0x800806BC");
	#elif OOT_U_1_0
		asm("external_func_800806BC = 0x8006BB7C");
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
 * TODO This function is completely undocumented
 */
extern void external_func_800825E0(void);
	#if OOT_DEBUG
		asm("external_func_800825E0 = 0x800825E0");
	#elif OOT_U_1_0
		asm("external_func_800825E0 = 0x8006D8E0");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800849A8(void);
	#if OOT_DEBUG
		asm("external_func_800849A8 = 0x800849A8");
	#elif OOT_U_1_0
		// TODO Needs 1.0 equivalent!
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
 * TODO This function is completely undocumented
 */
extern void external_func_80087174(void);
	#if OOT_DEBUG
		asm("external_func_80087174 = 0x80087174");
	#elif OOT_U_1_0
		asm("external_func_80087174 = 0x800720BC");
	#endif

/**
 * Adds or removes rupees from the counter (Negative values subtract, positive add)
 * a0 - Rupee amount.
 */
extern void change_rupee_count_by(int32_t num_rupees);
	#if OOT_DEBUG
		asm("change_rupee_count_by = 0x8008730C");
	#elif OOT_U_1_0
		asm("change_rupee_count_by = 0x800721CC");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_80087330(void);
	#if OOT_DEBUG
		asm("external_func_80087330 = 0x80087330");
	#elif OOT_U_1_0
		asm("external_func_80087330 = 0x800721F4");
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
extern void external_func_800876C8(void);
	#if OOT_DEBUG
		asm("external_func_800876C8 = 0x800876C8");
	#elif OOT_U_1_0
		asm("external_func_800876C8 = 0x80072548");
	#elif MM_U_1_0
		asm("external_func_800876C8 = 0x80115D5C");
		asm("external_func_80115D5C = 0x80115D5C");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_80087708(void);
	#if OOT_DEBUG
		asm("external_func_80087708 = 0x80087708");
	#elif OOT_U_1_0
		asm("external_func_80087708 = 0x80072588");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_80088AA0(void);
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
		// TODO Needs 1.0 equivalent!
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_80088B34(void);
	#if OOT_DEBUG
		asm("external_func_80088B34 = 0x80088B34");
	#elif OOT_U_1_0
		asm("external_func_80088B34 = 0x8007397C");
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
 * TODO This function is completely undocumented
 */
extern void external_func_8008EF5C(void);
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
		// TODO Needs 1.0 equivalent!
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
extern void external_func_80093370(void);
	#if OOT_DEBUG
		asm("external_func_80093370 = 0x80093370");
	#elif OOT_U_1_0
		// TODO Needs 1.0 equivalent!
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_80093708(void);
	#if OOT_DEBUG
		asm("external_func_80093708 = 0x80093708");
	#elif OOT_U_1_0
		// TODO Needs 1.0 equivalent!
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_80093774(void);
	#if OOT_DEBUG
		asm("external_func_80093774 = 0x80093774");
	#elif OOT_U_1_0
		// TODO Needs 1.0 equivalent!
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800937C0(void);
	#if OOT_DEBUG
		asm("external_func_800937C0 = 0x800937C0");
	#elif OOT_U_1_0
		// TODO Needs 1.0 equivalent!
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_80093C14(void);
	#if OOT_DEBUG
		asm("external_func_80093C14 = 0x80093C14");
	#elif OOT_U_1_0
		// TODO Needs 1.0 equivalent!
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_80093C80(void);
	#if OOT_DEBUG
		asm("external_func_80093C80 = 0x80093C80");
	#elif OOT_U_1_0
		// TODO Needs 1.0 equivalent!
	#endif

/**
 * Write Jump to Display List 800F8200 on POLY_OPA_DISP
 * Get Item Models
 * TODO These notes need converted into a C function prototype
 * A0 = Graphics Context
 */
extern void external_func_80093D18(z64_gfx_t *gfx);
	#if OOT_DEBUG
		asm("external_func_80093D18 = 0x80093D18");
	#elif OOT_U_1_0
		asm("external_func_80093D18 = 0x8007E298");
	#elif MM_U_1_0
		asm("external_func_80093D18 = 0x8012C28C");
	#endif

/**
 * Write Jump to Display List 800F8200 on POLY_XLU_DISP
 * Get Item Models
 * TODO These notes need converted into a C function prototype
 * A0 = Graphics Context
 */
extern void external_func_80093D84(z64_gfx_t *gfx);
	#if OOT_DEBUG
		asm("external_func_80093D84 = 0x80093D84");
	#elif OOT_U_1_0
		asm("external_func_80093D84 = 0x8007E2C0");
	#elif MM_U_1_0
		asm("external_func_80093D84 = 0x8012C2DC");
		asm("external_func_8012C2DC = 0x8012C2DC");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_80093F34(void);
	#if OOT_DEBUG
		asm("external_func_80093F34 = 0x80093F34");
	#elif OOT_U_1_0
		// TODO Needs 1.0 equivalent!
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_80094044(void);
	#if OOT_DEBUG
		asm("external_func_80094044 = 0x80094044");
	#elif OOT_U_1_0
		// TODO Needs 1.0 equivalent!
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
extern void external_func_80094520(void);
	#if OOT_DEBUG
		asm("external_func_80094520 = 0x80094520");
	#elif OOT_U_1_0
		// TODO Needs 1.0 equivalent!
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8009457C(void);
	#if OOT_DEBUG
		asm("external_func_8009457C = 0x8009457C");
	#elif OOT_U_1_0
		// TODO Needs 1.0 equivalent!
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8009460C(void);
	#if OOT_DEBUG
		asm("external_func_8009460C = 0x8009460C");
	#elif OOT_U_1_0
		// TODO Needs 1.0 equivalent!
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_80094968(void);
	#if OOT_DEBUG
		asm("external_func_80094968 = 0x80094968");
	#elif OOT_U_1_0
		// TODO Needs 1.0 equivalent!
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_80094B58(void);
	#if OOT_DEBUG
		asm("external_func_80094B58 = 0x80094B58");
	#elif OOT_U_1_0
		// TODO Needs 1.0 equivalent!
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_80094BC4(void);
	#if OOT_DEBUG
		asm("external_func_80094BC4 = 0x80094BC4");
	#elif OOT_U_1_0
		// TODO Needs 1.0 equivalent!
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_80094C50(void);
	#if OOT_DEBUG
		asm("external_func_80094C50 = 0x80094C50");
	#elif OOT_U_1_0
		// TODO Needs 1.0 equivalent!
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_80094D28(void);
	#if OOT_DEBUG
		asm("external_func_80094D28 = 0x80094D28");
	#elif OOT_U_1_0
		// TODO Needs 1.0 equivalent!
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_80094E78(void);
	#if OOT_DEBUG
		asm("external_func_80094E78 = 0x80094E78");
	#elif OOT_U_1_0
		// TODO Needs 1.0 equivalent!
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_80094E9C(void);
	#if OOT_DEBUG
		asm("external_func_80094E9C = 0x80094E9C");
	#elif OOT_U_1_0
		// TODO Needs 1.0 equivalent!
	#endif

/**
 * Animate Tile |  | Generates G_SETTILESIZE commands at the tail end of the POLY_OPA dlist | //E8, F2, E8, F2, DF command sequence
 * TODO These notes need converted into a C function prototype
 * A0 = Graphics Context | A1 = ? (tile descriptor one?) | A2 = upper left S-axis | A3 = upper left T-axis | SP+0x10 = width (whole units) | SP+0x14 = height (whole units) | SP+0x18 = Tile Descriptor Two | SP+0x1C = upper left S-axis 2 | SP+0x20 = Upper left T-axis 2 | SP+0x24 = width (whole units) | SP+0x28 = height (whole units)
 */
 extern uint32_t f3dzex_gen_settilesize(
     z64_gfx_t *gfx, int32_t t0, int32_t s0_ul, int32_t t0_ul, int32_t t0_w, int32_t t0_h, int32_t t1, int32_t s1_ul, int32_t t1_ul, int32_t t1_w, int32_t t1_h);
	#if OOT_DEBUG
		asm("f3dzex_gen_settilesize = 0x80094F40");
	#elif OOT_U_1_0
		asm("f3dzex_gen_settilesize = 0x8007EB84");
	#elif MM_U_1_0
		asm("f3dzex_gen_settilesize = 0x8012CBD0");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_80095068(void);
	#if OOT_DEBUG
		asm("external_func_80095068 = 0x80095068");
	#elif OOT_U_1_0
		// TODO Needs 1.0 equivalent!
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800951D0(void);
	#if OOT_DEBUG
		asm("external_func_800951D0 = 0x800951D0");
	#elif OOT_U_1_0
		// TODO Needs 1.0 equivalent!
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
		// TODO Needs 1.0 equivalent!
	#endif

/**
 * Given its number, returns the object's index in the object table, or -1 if it isn't loaded.
 * A0 = object context (OoT: global + 117A4, MM: global + 17D88), A1 = Object ID, V0 = Object index / -1 if not loaded.
 */
extern int32_t object_get_index(z64_obj_ctxt_t* object_context, uint16_t object_id);
	#if OOT_DEBUG
		asm("object_get_index = 0x8009812C");
	#elif OOT_U_1_0
		asm("object_get_index = 0x80081628");
 	#elif MM_U_1_0
		asm("object_get_index = 0x8012F608");
	#endif

/**
 * Test if object file dependency is loaded (returns 1 on true 0 on false)
 * A0 = object context (OoT: global + 117A4, MM: global + 17D88), A1 = Object ID, V0 = 1 if loaded, 0 if not.
 */
extern int32_t object_is_loaded(z64_obj_ctxt_t* object_context, uint16_t object_id);
	#if OOT_DEBUG
		asm("object_is_loaded = 0x80098188");
	#elif OOT_U_1_0
		asm("object_is_loaded = 0x80081688");
	#endif

 /**
 * Load an object into memory. Object is loaded even if
 * it has already been loaded.
 * A0 = object context (OoT: global + 117A4, MM: global + 17D88), A1 = Object ID,
 * NOTE: This function is not used in any existing actor overlay in OoT.
 */
extern void object_load(z64_obj_ctxt_t* object_context, uint16_t object_id);
    #if OOT_DEBUG
        asm("object_load = 0x80097C00");
    #elif OOT_U_1_0
        asm("object_load = 0x800812F0");
    /* Maybe - args could be different. Would need testing.
    #elif MM_U_1_0
        asm("object_load = 0x8012F2E0");
    */
    #endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800A0B40(void);
	#if OOT_DEBUG
		asm("external_func_800A0B40 = 0x800A0B40");
	#elif OOT_U_1_0
		// TODO Needs 1.0 equivalent!
	#endif

/**
 * Must be in draw even after initializing hirearchy without matrices
 * TODO Variable name cleanup, better notes
 */
extern void skelanime_draw(z64_global_t *global, uint32_t limb_index, uint32_t adt, uint8_t limb_dlists_count, void *internal0, void *internal1, z64_actor_t *actor);
	#if OOT_DEBUG
		asm("skelanime_draw = 0x800A15C8");
	#elif OOT_U_1_0
		asm("skelanime_draw = 0x8008993C");
	#endif

/**
 * Draw Matrix-Enabled Object
 * callback0 and callback1 should be NULL, or pointers
   to functions of their respective descriptions
 * TODO Variable name cleanup, better notes
 * A0 = Global Context | A1 = Hierarchy Limb Index (in Object File, in RAM) | A2 = Pointer to Actor Drawing Table | A3 = Number of Limbs that use display lists. | 0x0010(SP) = 0 | 0x0014(SP) = 0 | 0x0018(SP) = Actor Instance Address
 * TODO confirm dlist argument of callback0
 */
extern
void
skelanime_draw_mtx(
	  z64_global_t *global
	, uint32_t limb_index
	, uint32_t adt
	, uint8_t limb_dlists_count
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
	, void *entity
);
	#if OOT_DEBUG
		asm("skelanime_draw_mtx = 0x800A1AC8");
	#elif OOT_U_1_0
		asm("skelanime_draw_mtx = 0x80089D8C");
	#elif MM_U_1_0
		asm("skelanime_draw_mtx = 0x80133F28");
	#endif

/**
 * Count Animation Frames
 */
extern int32_t anime_get_framecount(uint32_t animation);
	#if OOT_DEBUG
		asm("anime_get_framecount = 0x800A2000");
	#elif OOT_U_1_0
		asm("anime_get_framecount = 0x8008A194");
	#elif MM_U_1_0
		asm("anime_get_framecount = 0x80134748");
	#endif

/**
 * Draw an object skeleton on a specific destination buffer
 * TODO Variable name cleanup, better notes
 * A0 = Global Context | A1 = Hierarchy Limb Index (in Object File, in RAM) | A2 = Pointer to Actor Drawing Table | A3 = 0 | 0x0010(SP) = 0 | 0x0014(SP) = Actor Instance Address | 0x0018(SP) = Buffer
 */
extern uint32_t skelanime_draw_destination(z64_global_t *global, uint32_t limb_index, uint32_t adt, void* subr0, void* subr1, z64_actor_t *actor, Gfx *gfx_buffer);
	#if OOT_DEBUG
		asm("skelanime_draw_destination = 0x800A2288");
	#elif OOT_U_1_0
		// TODO Needs 1.0 equivalent!
	#endif

/**
 * TODO Draw a matrix-enabled object skeleton on a specific destination buffer
 */
extern uint32_t skelanime_draw_mtx_destination(z64_global_t *global, uint32_t limb_index, uint32_t adt, uint8_t limb_dlists_count, void* subr0, void* subr1, z64_actor_t *actor, void *gfx_buffer);
	#if OOT_DEBUG
		asm("skelanime_draw_mtx_destination = 0x800A273C");
	#elif OOT_U_1_0
		// TODO Needs 1.0 equivalent!
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800A2E70(void);
	#if OOT_DEBUG
		asm("external_func_800A2E70 = 0x800A2E70");
	#elif OOT_U_1_0
		asm("external_func_800A2E70 = 0x8008AFB8");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800A3548(void);
	#if OOT_DEBUG
		asm("external_func_800A3548 = 0x800A3548");
	#elif OOT_U_1_0
		asm("external_func_800A3548 = 0x8008B698");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800A3620(void);
	#if OOT_DEBUG
		asm("external_func_800A3620 = 0x800A3620");
	#elif OOT_U_1_0
		asm("external_func_800A3620 = 0x8008B778");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800A3BC0(void);
	#if OOT_DEBUG
		asm("external_func_800A3BC0 = 0x800A3BC0");
	#elif OOT_U_1_0
		// TODO Needs 1.0 equivalent!
	#endif

/**
 * Initializes hierarchy without matrices
 * TODO Unknown variables, do something about that
 * a0 = Global Context | a1 = Actor Instance + 0x014C (offset to store data) | a2 = Hierarchy Pointer (In Object) | a3 = Animation Pointer (In Object)  0x10($sp) 0x14($sp) 0x18($sp)
 */
extern void skelanime_init(z64_global_t *global, z64_skelanime_t *skelanime, uint32_t skeleton, uint32_t animation, uint8_t unk0, uint8_t unk1, uint8_t unk2);
	#if OOT_DEBUG
		asm("skelanime_init = 0x800A457C");
	#elif OOT_U_1_0
		asm("skelanime_init = 0x8008C684");
	#endif

/**
 * Initialize Matrix-Enabled Object with Animation
 * TODO Unknown variables, do something about that
 * a0 = Global Context | a1 = Actor Instance Address + 0x014C (Drawing Table) | a2 = Hierarchy Pointer (In Object) | a3 = Animation Pointer (In Object)
 */
extern void skelanime_init_mtx(z64_global_t *global, z64_skelanime_t *skelanime, uint32_t skeleton, uint32_t animation, uint8_t unk0, uint8_t unk1, uint8_t unk2);
	#if OOT_DEBUG
		asm("skelanime_init_mtx = 0x800A46F8");
	#elif OOT_U_1_0
		asm("skelanime_init_mtx = 0x8008C788");
	#elif MM_U_1_0
		asm("skelanime_init_mtx = 0x80136B30");
	#endif

/**
 * Update Animation for Matrix-Enabled Object
 * TODO Conflict, notes below say actor+0x014C, but taking actor+0x0 is fine?
 * A0 = actor instance + 0x014C (Drawing Table) V0 = 1 if ?, else 0
 */
extern int32_t actor_anime_frame_update_mtx(z64_skelanime_t *skelanime);
	#if OOT_DEBUG
		asm("actor_anime_frame_update_mtx = 0x800A49FC");
	#elif OOT_U_1_0
		asm("actor_anime_frame_update_mtx = 0x8008C9C0");
	#elif MM_U_1_0
		asm("actor_anime_frame_update_mtx = 0x80136CD0");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800A4FE4(void);
	#if OOT_DEBUG
		asm("external_func_800A4FE4 = 0x800A4FE4");
	#elif OOT_U_1_0
		asm("external_func_800A4FE4 = 0x8008CFC0");
	#elif MM_U_1_0
		asm("external_func_800A4FE4 = 0x8013722C");
		asm("external_func_8013722C = 0x8013722C");
	#endif

/**
 * Change Animation
 * transition rate is between 0.0 and 1.0
 * TODO These notes need converted into a C function prototype
 * A0 = actor instance + 0x014C (Drawing Table) | A1 = New Animation Pointer (in Object File) | A2 = Animation Speed (Floating Point) | A3 = ? | 0x0010(SP) = Number of Frames in Floating Point32_t | 0x0014(SP) = some counter related to how long the animation should be played? | 0x0018(SP) = float transition rate, less than 1
 */
extern void actor_anime_change(z64_skelanime_t *skelanime, uint32_t animation, f32 playback_speed, f32 unk0, f32 frame_count, uint8_t unk_1, f32 transition_rate);
	#if OOT_DEBUG
		asm("actor_anime_change = 0x800A51A0");
	#elif OOT_U_1_0
		asm("actor_anime_change = 0x8008D17C");
	#elif MM_U_1_0
		asm("actor_anime_change = 0x801373E8");
	#endif

/**
 * TODO These notes need converted into a C function prototype
 * A0 = ? struct (Anju + 0x13C/ Archery Gerudo + 0x188) | A1 = Segment Offset
 */
extern void external_func_800A51E8(z64_skelanime_t *skelanime, uint32_t animation);
	#if OOT_DEBUG
		asm("external_func_800A51E8 = 0x800A51E8");
	#elif OOT_U_1_0
		asm("external_func_800A51E8 = 0x8008D1C4");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800A5240(void);
	#if OOT_DEBUG
		asm("external_func_800A5240 = 0x800A5240");
	#elif OOT_U_1_0
		asm("external_func_800A5240 = 0x8008D21C");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800A529C(void);
	#if OOT_DEBUG
		asm("external_func_800A529C = 0x800A529C");
	#elif OOT_U_1_0
		asm("external_func_800A529C = 0x8008D278");
	#endif

/**
 * Change Animation
 * TODO These notes need converted into a C function prototype
 * A0 = actor instance + 0x014C (Drawing Table) | A1 = Animation Pointer (in Object File)
 * Wrapper for actor_anime_change and anime_get_framecount */
extern void actor_anime_set(z64_skelanime_t *skelanime, uint32_t animation);
	#if OOT_DEBUG
		asm("actor_anime_set = 0x800A52F8");
	#elif OOT_U_1_0
		asm("actor_anime_set = 0x8008D2D4");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800A534C(void);
	#if OOT_DEBUG
		asm("external_func_800A534C = 0x800A534C");
	#elif OOT_U_1_0
		asm("external_func_800A534C = 0x8008D328");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800A5384(void);
	#if OOT_DEBUG
		asm("external_func_800A5384 = 0x800A5384");
	#elif OOT_U_1_0
		asm("external_func_800A5384 = 0x8008D360");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800A5408(void);
	#if OOT_DEBUG
		asm("external_func_800A5408 = 0x800A5408");
	#elif OOT_U_1_0
		asm("external_func_800A5408 = 0x8008D3E4");
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

/**
 * Checks if the animation is at specific frame
 * TODO These notes need converted into a C function prototype
 * a0 = animation struct | a1 = frame (float) | v0 = true/false
 */
extern void external_func_800A56C8(void);
	#if OOT_DEBUG
		asm("external_func_800A56C8 = 0x800A56C8");
	#elif OOT_U_1_0
		asm("external_func_800A56C8 = 0x8008D6A8");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800A56F0(void);
	#if OOT_DEBUG
		asm("external_func_800A56F0 = 0x800A56F0");
	#elif OOT_U_1_0
		asm("external_func_800A56F0 = 0x8008D6D0");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800A5F60(void);
	#if OOT_DEBUG
		asm("external_func_800A5F60 = 0x800A5F60");
	#elif OOT_U_1_0
		// TODO Needs 1.0 equivalent!
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
		// TODO Needs 1.0 equivalent!
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
 * TODO This function is completely undocumented
 */
extern void external_func_800A7B04(void);
	#if OOT_DEBUG
		asm("external_func_800A7B04 = 0x800A7B04");
	#elif OOT_U_1_0
		// TODO Needs 1.0 equivalent!
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800A7E70(void);
	#if OOT_DEBUG
		asm("external_func_800A7E70 = 0x800A7E70");
	#elif OOT_U_1_0
		// TODO Needs 1.0 equivalent!
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
extern void external_func_800A9F6C(void);
	#if OOT_DEBUG
		asm("external_func_800A9F6C = 0x800A9F6C");
	#elif OOT_U_1_0
		asm("external_func_800A9F6C = 0x8009151C");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800AA000(void);
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
extern void external_func_800AA278(void);
	#if OOT_DEBUG
		asm("external_func_800AA278 = 0x800AA278");
	#elif OOT_U_1_0
		asm("external_func_800AA278 = 0x80091858");
	#endif

/**
 * TODO This function is completely undocumented
 * This function is not used inside any existing overlay
 */
extern void external_func_800AA358(void);
	#if OOT_DEBUG
		asm("external_func_800AA358 = 0x800AA358");
	#elif OOT_U_1_0
		asm("external_func_800AA358 = 0x80091918");
	#endif

/**
 * TODO This function is completely undocumented
 * This function is not used inside any existing overlay
 */
extern void external_func_800AAA50(void);
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
		// TODO Needs 1.0 equivalent!
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800BC490(void);
	#if OOT_DEBUG
		asm("external_func_800BC490 = 0x800BC490");
	#elif OOT_U_1_0
		// TODO Needs 1.0 equivalent!
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
		// TODO Needs 1.0 equivalent!
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800BC8A0(void);
	#if OOT_DEBUG
		asm("external_func_800BC8A0 = 0x800BC8A0");
	#elif OOT_U_1_0
		// TODO Needs 1.0 equivalent!
	#endif

/**
 * Call 8007943C if Global Context + 0x1D6C (cutscene play state) is 0
 * TODO These notes need converted into a C function prototype
 * A0 = Global Context | V0 = 1 if ?, else 0
 */
extern void external_func_800BFC84(void);
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
extern void void_out(z64_global_t *global);
	#if OOT_DEBUG
		asm("external_func_800C0B60 = 0x800C0B60");
	#elif OOT_U_1_0
		asm("external_func_800C0B60 = 0x8009D9B8");
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
 * TODO These notes need converted into a C function prototype
 * V0 = 1 if Global Context + 0x7B8 &gt; 0
 */
extern void external_func_800C0D28(void);
	#if OOT_DEBUG
		asm("external_func_800C0D28 = 0x800C0D28");
	#elif OOT_U_1_0
		asm("external_func_800C0D28 = 0x8009DB54");
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
 * Allocates graphics memory
 * returns a pointer to allocated graphics memory, which you
 * can cast to uint8_t or uint32_t, whatever is convenient
 * z_gp is 0x80212020
 * size is the size of the block to be allocated
 */
extern void *
graph_alloc(z64_global_t *global, int32_t size);
	#if OOT_DEBUG
		asm("graph_alloc = 0x800C69CC");
	#elif OOT_U_1_0
		// TODO Needs 1.0 equivalent!
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800C6AC4(void *unk0, z64_gfx_t *gfx, const char *string, int32_t line);
	#if OOT_DEBUG
		asm("external_func_800C6AC4 = 0x800C6AC4");
	#elif OOT_U_1_0
		// TODO Needs 1.0 equivalent!
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800C6B54(void *unk0, z64_gfx_t *gfx, const char *string, int32_t line);
	#if OOT_DEBUG
		asm("external_func_800C6B54 = 0x800C6B54");
	#elif OOT_U_1_0
		// TODO Needs 1.0 equivalent!
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800C6C20(void);
	#if OOT_DEBUG
		asm("external_func_800C6C20 = 0x800C6C20");
	#elif OOT_U_1_0
		// TODO Needs 1.0 equivalent!
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800C6C28(void);
	#if OOT_DEBUG
		asm("external_func_800C6C28 = 0x800C6C28");
	#elif OOT_U_1_0
		// TODO Needs 1.0 equivalent!
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
		asm("external_func_80179F64 = 0x80179F64");
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
 * TODO This function is completely undocumented
 */
extern void external_func_800CB600(void);
	#if OOT_DEBUG
		asm("external_func_800CB600 = 0x800CB600");
	#elif OOT_U_1_0
		asm("external_func_800CB600 = 0x800A54E4");
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
 * TODO This function is completely undocumented
 */
extern void external_func_800CB650(void);
	#if OOT_DEBUG
		asm("external_func_800CB650 = 0x800CB650");
	#elif OOT_U_1_0
		asm("external_func_800CB650 = 0x800A5538");
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
 * TODO These notes need converted into a C function prototype
 * F12 = x | F14 = y | V0 = int16_t Rotation
 */
extern int16_t math_atan2s(float x, float y);
	#if OOT_DEBUG
		asm("math_atan2s = 0x800D0664");
	#elif OOT_U_1_0
		asm("math_atan2s = 0x800AA4F8");
	#endif

/**
 * padding at func end
 * TODO These notes need converted into a C function prototype
 */
extern void external_func_800D07D4(void);
	#if OOT_DEBUG
		asm("external_func_800D07D4 = 0x800D07D4");
	#elif OOT_U_1_0
		asm("external_func_800D07D4 = 0x800AA670");
	#endif

/**
 * Allocates a 0x500 byte Float Matrix Stack | 80121200 stores start address, 80121204 stores top matrix
 * TODO These notes need converted into a C function prototype
 * A0 = Global Context
 * This function is not used inside any existing overlay
 */
extern void external_func_800D0810(void);
	#if OOT_DEBUG
		asm("external_func_800D0810 = 0x800D0810");
	#elif OOT_U_1_0
		asm("external_func_800D0810 = 0x800AA6B0");
	#endif

/**
 * Clones the top level matrix in the Float Matrix Stack | (Increments Append Start by 0x40)
 * TODO These notes need converted into a C function prototype
 */
extern void external_func_800D084C(void);
	#if OOT_DEBUG
		asm("external_func_800D084C = 0x800D084C");
	#elif OOT_U_1_0
		asm("external_func_800D084C = 0x800AA6EC");
	#endif

/**
 * Pops top level matrix in the Float Matrix Stack
 * TODO These notes need converted into a C function prototype
 */
extern void external_func_800D0884(void);
	#if OOT_DEBUG
		asm("external_func_800D0884 = 0x800D0884");
	#elif OOT_U_1_0
		asm("external_func_800D0884 = 0x800AA724");
	#endif

/**
 * Copies the top level matrix in the Float Matrix Stack
 * TODO These notes need converted into a C function prototype
 * A0 = Destination
 */
extern void external_func_800D08D8(void);
	#if OOT_DEBUG
		asm("external_func_800D08D8 = 0x800D08D8");
	#elif OOT_U_1_0
		asm("external_func_800D08D8 = 0x800AA740");
	#endif

/**
 * Overwrites top level matrix in the Float Matrix Stack
 * TODO These notes need converted into a C function prototype
 * A0 = Source Matrix
 */
extern void external_func_800D08FC(void);
	#if OOT_DEBUG
		asm("external_func_800D08FC = 0x800D08FC");
	#elif OOT_U_1_0
		asm("external_func_800D08FC = 0x800AA764");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800D0930(void);
	#if OOT_DEBUG
		asm("external_func_800D0930 = 0x800D0930");
	#elif OOT_U_1_0
		// TODO Needs 1.0 equivalent!
	#endif

/**
 * Create/Apply x,y,z transformation on Float Matrix Stack
 * TODO These notes need converted into a C function prototype
 * F12 = x | F14 = y | A2 = float z | A3 = 0 initializes new matrix, 1 transforms stored matrix
 */
extern void matrix_translate3f(float x, float y, float z, int32_t transform_current);
	#if OOT_DEBUG
		asm("matrix_translate3f = 0x800D0984");
	#elif OOT_U_1_0
		asm("matrix_translate3f = 0x800AA7F4");
	#elif MM_U_1_0
		asm("matrix_translate3f = 0x8018029C");
	#endif

/**
 * Create/Apply x,y,z scalar transformation on Float Matrix Stack
 * TODO These notes need converted into a C function prototype
 * F12 = x | F14 = y | A2 = float z | A3 = 0 initializes new matrix, 1 transforms stored matrix
 */
extern void matrix_scale3f(float x, float y, float z, int32_t transform_current);
	#if OOT_DEBUG
		asm("matrix_scale3f = 0x800D0A8C");
	#elif OOT_U_1_0
		asm("matrix_scale3f = 0x800AA8FC");
	#elif MM_U_1_0
		asm("matrix_scale3f = 0x8018039C");
	#endif

/**
 * TODO probably some kind of matrix function
 */
extern void external_func_800D0B70(float unk0, int32_t transform_current);
	#if OOT_DEBUG
		asm("external_func_800D0B70 = 0x800D0B70");
	#elif OOT_U_1_0
		asm("external_func_800D0B70 = 0x800AA9E0");
	#endif

/**
 * TODO probably some kind of matrix function
 */
extern void external_func_800D0D20(float unk0, int32_t transform_current);
	#if OOT_DEBUG
		asm("external_func_800D0D20 = 0x800D0D20");
	#elif OOT_U_1_0
		asm("external_func_800D0D20 = 0x800AAB94");
	#endif

/**
 * TODO some kind of matrix function?
 */
extern void external_func_800D0ED4(float unk0, int32_t current_transform);
	#if OOT_DEBUG
		asm("external_func_800D0ED4 = 0x800D0ED4");
	#elif OOT_U_1_0
		asm("external_func_800D0ED4 = 0x800AAD4C");
	#elif MM_U_1_0
		asm("external_func_800D0ED4 = 0x80180E90");
		asm("external_func_80180E90 = 0x80180E90");
	#endif

/**
 * Create/Apply x,y,z rotation transformation on Float Matrix Stack
 * TODO These notes need converted into a C function prototype
 * A0 = uint16_t x rotation | A1 = uint16_t y rotation | A2 = uint16_t z rotation | A3 = 0 initializes new matrix, 1 transforms stored matrix
 */
extern void matrix_rotate3s(int16_t x, int16_t y, int16_t z, int32_t transform_current);
	#if OOT_DEBUG
		asm("matrix_rotate3s = 0x800D1084");
	#elif OOT_U_1_0
		asm("matrix_rotate3s = 0x800AAF00");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800D1340(void);
	#if OOT_DEBUG
		asm("external_func_800D1340 = 0x800D1340");
	#elif OOT_U_1_0
		// TODO Needs 1.0 equivalent!
	#endif

/**
 * Create x,y,z transformation and apply rotation on Float Matrix Stack
 * TODO These notes need converted into a C function prototype
 * F12 = float x | F14 = float y | A2 = float z | A3 = ptr to uint16_t rotation
 */
extern void external_func_800D1694(void);
	#if OOT_DEBUG
		asm("external_func_800D1694 = 0x800D1694");
	#elif OOT_U_1_0
		asm("external_func_800D1694 = 0x800AB510");
	#endif

/**
 * guMtxF2L -- mtxutil.c from libultra SDK
 */
extern void _guMtxF2L(float mf[4][4], Mtx *m);
	#if OOT_DEBUG
		asm("_guMtxF2L = 0x800D1840");
	#elif OOT_U_1_0
		asm("_guMtxF2L = 0x800AB6BC");
	#elif MM_U_1_0
		asm("_guMtxF2L = 0x801817FC");
	#endif

/**
 * Converts the Top in the Float Matrix Stack to a fixed point32_t matrix
 * TODO These notes need converted into a C function prototype
 * A0 = Destination for the Fixed Point32_t Matrix
 */
extern void external_func_800D1A54(void);
	#if OOT_DEBUG
		asm("external_func_800D1A54 = 0x800D1A54");
	#elif OOT_U_1_0
		asm("external_func_800D1A54 = 0x800AB8D8");
	#endif

/**
 * Converts and Appends the Float Matrix Stack's top matrix to POLY_OPA_DISP end
 * please provide only the first two arguments when using this function
 */
extern uint32_t matrix_alloc(
	  z64_gfx_t *gfx_ctx
#ifndef RETAIL_NUANCES /* debug roms require these arguments, retail roms don't */
	, const char *string
	, int32_t line
#endif
);
#ifdef RETAIL_NUANCES
#define matrix_alloc(MTXALLOC_GFX, MTXALLOC_STR) matrix_alloc(MTXALLOC_GFX)
#else
#define matrix_alloc(MTXALLOC_GFX, MTXALLOC_STR) matrix_alloc(MTXALLOC_GFX, MTXALLOC_STR, __LINE__)
#endif
	#if OOT_DEBUG
		asm("matrix_alloc = 0x800D1A88");
	#elif OOT_U_1_0
		asm("matrix_alloc = 0x800AB900");
	#elif MM_U_1_0
		asm("matrix_alloc = 0x80181A40");
	#endif

/**
 * transform `in` somehow, store result in `out`
 * Old notes, for reference:
 * Multiply Float Matrix Stack's top matrix by float Vector3
 * A0 = ptr to Vector3 | A1 = ptr to result
 */
extern void external_func_800D1AF4(vec3f_t *in, vec3f_t *out);
	#if OOT_DEBUG
		asm("external_func_800D1AF4 = 0x800D1AF4");
	#elif OOT_U_1_0
		asm("external_func_800D1AF4 = 0x800AB958");
	#elif MM_U_1_0
		asm("external_func_800D1AF4 = 0x80181A98");
	#endif

/**
 * Float Matrix Copy
 * poorly optimized?
 * TODO These notes need converted into a C function prototype
 * A0 = Destination | A1 = Source
 */
extern void external_func_800D1BA8(void);
	#if OOT_DEBUG
		asm("external_func_800D1BA8 = 0x800D1BA8");
	#elif OOT_U_1_0
		asm("external_func_800D1BA8 = 0x800ABA10");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800D1EF4(void);
	#if OOT_DEBUG
		asm("external_func_800D1EF4 = 0x800D1EF4");
	#elif OOT_U_1_0
		// TODO Needs 1.0 equivalent!
	#endif

/**
 * TODO what does this do?
 * unk0 is consistently either the graphics or global context, + 0x11DA0
 */
extern void external_func_800D1FD4(void *unk0);
	#if OOT_DEBUG
		asm("external_func_800D1FD4 = 0x800D1FD4");
	#elif OOT_U_1_0
		asm("external_func_800D1FD4 = 0x800ABE54");
	#elif MM_U_1_0
		asm("external_func_800D1FD4 = 0x801820A0");
		asm("external_func_801820A0 = 0x801820A0");
	#endif

/**
 * Used to reflect projectiles
 * A0 = Link instance + 0x0A20 | A1 = place in stack to store result | a2 = 0? | Stores an array of 3 halfs containing the reflected direction into the address in A1
 */
extern void external_func_800D20CC(float* link_0A20, int16_t* store, int32_t condition);
	#if OOT_DEBUG
		asm("external_func_800D20CC = 0x800D20CC");
	#elif OOT_U_1_0
		asm("external_func_800D20CC = 0x800ABF50");
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
		// TODO Needs 1.0 equivalent!
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
extern void external_func_800F4254(void);
	#if OOT_DEBUG
		asm("external_func_800F4254 = 0x800F4254");
	#elif OOT_U_1_0
		asm("external_func_800F4254 = 0x800C4F94");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800F436C(void);
	#if OOT_DEBUG
		asm("external_func_800F436C = 0x800F436C");
	#elif OOT_U_1_0
		asm("external_func_800F436C = 0x800C50AC");
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
		// TODO Needs 1.0 equivalent!
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
		// TODO Needs 1.0 equivalent!
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
		// TODO Needs 1.0 equivalent!
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800F4BE8(void);
	#if OOT_DEBUG
		asm("external_func_800F4BE8 = 0x800F4BE8");
	#elif OOT_U_1_0
		// TODO Needs 1.0 equivalent!
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
 * TODO This function is completely undocumented
 */
extern void external_func_800F5718(void);
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
 * Change background music until enemies are defeated?
 * TODO These notes need converted into a C function prototype
 * a0 - music ID
 */
extern void external_func_800F5ACC(void);
	#if OOT_DEBUG
		asm("external_func_800F5ACC = 0x800F5ACC");
	#elif OOT_U_1_0
		asm("external_func_800F5ACC = 0x800C6820");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800F5B58(void);
	#if OOT_DEBUG
		asm("external_func_800F5B58 = 0x800F5B58");
	#elif OOT_U_1_0
		asm("external_func_800F5B58 = 0x800C6894");
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
		// TODO Needs 1.0 equivalent!
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
		// TODO Needs 1.0 equivalent!
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800F6D58(void);
	#if OOT_DEBUG
		asm("external_func_800F6D58 = 0x800F6D58");
	#elif OOT_U_1_0
		// TODO Needs 1.0 equivalent!
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
 * Global Play Sfx?
 * TODO There's a conflict between these notes and the function prototype
 * A0 = SFX ID | A1 = ? | A2 = ? | A3 = 80104394 this pass
 */
extern void sound_play_general(uint16_t sound_id);
	#if OOT_DEBUG
		asm("sound_play_general = 0x800F738C");
	#elif OOT_U_1_0
		asm("sound_play_general = 0x800C806C");
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
extern void sound_set_bgm(uint8_t music_id);
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
		// TODO Needs 1.0 equivalent!
	#endif

/**
 * Set RGBA color for a string of Debug Text.
 */
extern void debug_set_text_rgba(z64_debug_text_t *text_struct, uint8_t r, uint8_t g, uint8_t b, uint8_t a);
	#if OOT_DEBUG
		asm("debug_set_text_rgba = 0x800FB3AC");
	#elif OOT_U_1_0
		asm("debug_set_text_rgba = 0x800CBE58");
	#endif

/**
 * Set X / Y coordinates for a string of Debug Text.
 */
extern void debug_set_text_xy(z64_debug_text_t *text_struct, uint16_t x, uint16_t y);
	#if OOT_DEBUG
		asm("debug_set_text_xy = 0x800FB41C");
	#elif OOT_U_1_0
		asm("debug_set_text_xy = 0x800CBEC8");
	#endif

/**
 * Initailize a variable structure for Debug Text.
 */
extern void debug_init_text_struct(z64_debug_text_t *text_struct);
	#if OOT_DEBUG
		asm("debug_init_text_struct = 0x800FBB8C");
	#elif OOT_U_1_0
		asm("debug_init_text_struct = 0x800CC4AC");
	#endif

/**
 * Store A0 on stack
 * TODO These notes need converted into a C function prototype
 * This function is not used inside any existing overlay
 */
extern void external_func_800FBC14(void);
	#if OOT_DEBUG
		asm("external_func_800FBC14 = 0x800FBC14");
	#elif OOT_U_1_0
		asm("external_func_800FBC14 = 0x800CC500");
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
	#endif

/**
 * Set character string for Debug Text.
 */
extern void debug_set_text_string(z64_debug_text_t *text_struct, const char *format, ...);
	#if OOT_DEBUG
		asm("debug_set_text_string = 0x800FBCB4");
	#elif OOT_U_1_0
		asm("debug_set_text_string = 0x800CC588");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800FCC6C(void);
	#if OOT_DEBUG
		asm("external_func_800FCC6C = 0x800FCC6C");
	#elif OOT_U_1_0
		// TODO Needs 1.0 equivalent!
	#endif

/**
 * TODO What does this function do?
 */
extern float external_func_800FD250(float unk0, float unk1);
	#if OOT_DEBUG
		asm("external_func_800FD250 = 0x800FD250");
	#elif OOT_U_1_0
		asm("external_func_800FD250 = 0x800CD76C");
	#endif

/**
 * Wrapper for 800CD860 (subtracts result by 90 degrees)
 * TODO These notes need converted into a C function prototype
 * F12 = ? | F0 = radians
 */
extern void external_func_800FD368(void);
	#if OOT_DEBUG
		asm("external_func_800FD368 = 0x800FD368");
	#elif OOT_U_1_0
		asm("external_func_800FD368 = 0x800CD890");
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

/**
 * generates a random number between 0 inclusive and 1 exclusive
 */
extern float math_rand_zero_one(void);
	#if OOT_DEBUG
		asm("math_rand_zero_one = 0x800FD9AC");
	#elif OOT_U_1_0
		asm("math_rand_zero_one = 0x800CDCCC");
	#elif MM_U_1_0
		asm("math_rand_zero_one = 0x80086FDC");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern int32_t external_func_800FD970(void);
	#if OOT_DEBUG
		asm("external_func_800FD970 = 0x800FD970");
	#elif OOT_U_1_0
		// TODO Needs 1.0 equivalent!
	#elif MM_U_1_0
		asm("external_func_800FD970 = 0x80086FA0");
	#endif

/**
 * Seeds the RNG with the given seed. This function is not used inside any existing overlay.
 */
extern int32_t srand(uint32_t seed);
	#if OOT_DEBUG
		asm("srand = 0x800FD9A0");
	#elif OOT_U_1_0
		asm("srand = 0x800CDCC0");

/**
 * TODO math, does something to a floating point32_t value
 * padding between this and prev func
 * TODO These notes need converted into a C function prototype
 */
extern float external_func_80100290(float n);
	#if OOT_DEBUG
		asm("external_func_80100290 = 0x80100290");
	#elif OOT_U_1_0
		asm("external_func_80100290 = 0x800CF470");
	#endif

/**
 * TODO math, does something to a floating point32_t value
 */
extern float external_func_80104610(float n);
	#if OOT_DEBUG
		asm("external_func_80104610 = 0x80104610");
	#elif OOT_U_1_0
		asm("external_func_80104610 = 0x800D2CD0");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_80104780(void);
	#if OOT_DEBUG
		asm("external_func_80104780 = 0x80104780");
	#elif OOT_U_1_0
		// TODO Needs 1.0 equivalent!
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

extern void z64_bzero(void *dest, int32_t length);
asm("bzero = 0x80004450");
extern int32_t z64_bcmp(const void *s1, const void *s2, int32_t length);
asm("bcmp = 0x800068C0");
extern void bcpy(const void *src, void *dst, int32_t length);
asm("bcpy = 0x80006F10");

// /ultra/user/src/pr/libsrc/libultra/gu

extern float sinf(float angle);
asm("sinf = 0x80100290");
extern float sins(unsigned short angle);
asm("sins = 0x80100450");
extern void guPerspectiveF(float mf[4][4], uint16_t *perspNorm, float fovy, float aspect, float near, float far, float scale);
asm("guPerspectiveF = 0x801010D0");
extern void guPerspective(Mtx *m, uint16_t *perspNorm, float fovy, float aspect, float near, float far, float scale);
asm("guPerspective = 0x80101300");
/*
* 80101B40 guMtxIdentF?
* 80101B90
* 80101E34
*/
extern float sqrtf (float value);
asm("sqrtf = 0x801031E0");
/*
* 801032B0
* 80103A70
* 80103BB0
* 80103D58
* 80103E20
* 80103FA4
* 80104450
* 801045A4
*/
extern float cosf(float angle);
asm("cosf = 0x80104610"); // OOTDBG
extern float coss(unsigned short angle);
asm("coss = 0x80104780"); // OOTDBG
extern void guMtxF2L(float mf[4][4], Mtx *m);
asm("guMtxF2L = 0x801064E0"); // OOTDBG
extern float absf(float value);
asm("absf = 0x801067E0"); // OOTDBG

#endif // __Z64OVL_H__
