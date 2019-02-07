#ifndef __Z64OVL_H__
#define __Z64OVL_H__

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

/**
 * Allocates to the tail end of the given heap (0x10 aligned)
 * TODO These notes need converted into a C function prototype
 * A0 = Allocation Handle ptr | A1 = Size | V0 = ptr to free space
 */
extern void external_func_80001FF0(void);
	#if OOT_DEBUG
		asm("external_func_80001FF0 = 0x80001FF0");
	#elif OOT_U_1_0
		asm("external_func_80001FF0 = 0x800A01B8");
	#endif

/**
 * padding at func end
 * TODO These notes need converted into a C function prototype
 */
extern void external_func_80002130(void);
	#if OOT_DEBUG
		asm("external_func_80002130 = 0x80002130");
	#elif OOT_U_1_0
		asm("external_func_80002130 = 0x800ACE60");
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
 * TODO These notes need converted into a C function prototype
 * a0 = global context | a1 = actor instance + 0x24 | a2 = drop ID
 */
extern void external_func_8001F548(void);
	#if OOT_DEBUG
		asm("external_func_8001F548 = 0x8001F548");
	#elif OOT_U_1_0
		asm("external_func_8001F548 = 0x80013678");
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
 * TODO These notes need converted into a C function prototype
 * a0 = global context | a1 = actor instance | a2 = position array | a3 = drop table ID
 */
extern void external_func_8001F940(void);
	#if OOT_DEBUG
		asm("external_func_8001F940 = 0x8001F940");
	#elif OOT_U_1_0
		asm("external_func_8001F940 = 0x80013A84");
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
extern void external_func_80026CD4(void);
	#if OOT_DEBUG
		asm("external_func_80026CD4 = 0x80026CD4");
	#elif OOT_U_1_0
		asm("external_func_80026CD4 = 0x8001AA5C");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8002709C(void);
	#if OOT_DEBUG
		asm("external_func_8002709C = 0x8002709C");
	#elif OOT_U_1_0
		asm("external_func_8002709C = 0x8001AE04");
	#endif

/**
 * Kill Particle
 * TODO These notes need converted into a C function prototype
 * A0 = Particle Instance Ptr
 * This function is not used inside any existing overlay
 */
extern void external_func_800274E0(void);
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
extern void external_func_80028E84(void);
	#if OOT_DEBUG
		asm("external_func_80028E84 = 0x80028E84");
	#elif OOT_U_1_0
		asm("external_func_80028E84 = 0x8001C97C");
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
extern void external_func_80029184(void);
	#if OOT_DEBUG
		asm("external_func_80029184 = 0x80029184");
	#elif OOT_U_1_0
		asm("external_func_80029184 = 0x8001CC7C");
	#endif

/**
 * Spawn Particle 0x06 (Wrapper for 8001CE18)
 * TODO These notes need converted into a C function prototype
 */
extern void external_func_800293A0(void);
	#if OOT_DEBUG
		asm("external_func_800293A0 = 0x800293A0");
	#elif OOT_U_1_0
		asm("external_func_800293A0 = 0x8001CE98");
	#endif

/**
 * Spawn Particle 0x07
 * TODO These notes need converted into a C function prototype
 */
extern void external_func_800293E4(void);
	#if OOT_DEBUG
		asm("external_func_800293E4 = 0x800293E4");
	#elif OOT_U_1_0
		asm("external_func_800293E4 = 0x8001CEDC");
	#endif

/**
 * Spawn Particle 0x09
 * TODO These notes need converted into a C function prototype
 */
extern void external_func_80029444(void);
	#if OOT_DEBUG
		asm("external_func_80029444 = 0x80029444");
	#elif OOT_U_1_0
		asm("external_func_80029444 = 0x8001CF3C");
	#endif

/**
 * Spawn Particle 0x0A
 * TODO These notes need converted into a C function prototype
 */
extern void external_func_8002949C(void);
	#if OOT_DEBUG
		asm("external_func_8002949C = 0x8002949C");
	#elif OOT_U_1_0
		asm("external_func_8002949C = 0x8001CF94");
	#endif

/**
 * Spawn Particle 0x0B
 * TODO These notes need converted into a C function prototype
 */
extern void external_func_80029530(void);
	#if OOT_DEBUG
		asm("external_func_80029530 = 0x80029530");
	#elif OOT_U_1_0
		asm("external_func_80029530 = 0x8001D028");
	#endif

/**
 * Spawn Particle 0x0D
 * TODO These notes need converted into a C function prototype
 */
extern void external_func_800295A0(void);
	#if OOT_DEBUG
		asm("external_func_800295A0 = 0x800295A0");
	#elif OOT_U_1_0
		asm("external_func_800295A0 = 0x8001D098");
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
 * SP+0x18 = s16 Particles to Spawn
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
extern void external_func_800299AC(void);
	#if OOT_DEBUG
		asm("external_func_800299AC = 0x800299AC");
	#elif OOT_U_1_0
		asm("external_func_800299AC = 0x8001D4A8");
	#endif

/**
 * Spawn Particle 0x13
 * TODO These notes need converted into a C function prototype
 */
extern void external_func_80029B90(void);
	#if OOT_DEBUG
		asm("external_func_80029B90 = 0x80029B90");
	#elif OOT_U_1_0
		asm("external_func_80029B90 = 0x8001D68C");
	#endif

/**
 * Spawn Particle 0x14
 * TODO These notes need converted into a C function prototype
 */
extern void external_func_80029C00(void);
	#if OOT_DEBUG
		asm("external_func_80029C00 = 0x80029C00");
	#elif OOT_U_1_0
		asm("external_func_80029C00 = 0x8001D6FC");
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
extern void external_func_80029DBC(void);
	#if OOT_DEBUG
		asm("external_func_80029DBC = 0x80029DBC");
	#elif OOT_U_1_0
		asm("external_func_80029DBC = 0x8001D8C8");
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
 * Spawn Particle 0x19
 * TODO These notes need converted into a C function prototype
 */
extern void external_func_80029E8C(void);
	#if OOT_DEBUG
		asm("external_func_80029E8C = 0x80029E8C");
	#elif OOT_U_1_0
		asm("external_func_80029E8C = 0x8001D998");
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
 * Spawn Particle 0x1B
 * TODO These notes need converted into a C function prototype
 */
extern void external_func_8002A1DC(void);
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
extern void external_func_8002A3C4(void);
	#if OOT_DEBUG
		asm("external_func_8002A3C4 = 0x8002A3C4");
	#elif OOT_U_1_0
		asm("external_func_8002A3C4 = 0x8001DED8");
	#endif

/**
 * Spawn Particle 0x1D
 * TODO These notes need converted into a C function prototype
 */
extern void external_func_8002A4D4(void);
	#if OOT_DEBUG
		asm("external_func_8002A4D4 = 0x8002A4D4");
	#elif OOT_U_1_0
		asm("external_func_8002A4D4 = 0x8001DFEC");
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
extern void external_func_8002A5F4(void);
	#if OOT_DEBUG
		asm("external_func_8002A5F4 = 0x8002A5F4");
	#elif OOT_U_1_0
		asm("external_func_8002A5F4 = 0x8001E110");
	#endif

/**
 * Spawn Particle 0x1F
 * TODO These notes need converted into a C function prototype
 */
extern void external_func_8002A65C(void);
	#if OOT_DEBUG
		asm("external_func_8002A65C = 0x8002A65C");
	#elif OOT_U_1_0
		asm("external_func_8002A65C = 0x8001E178");
	#endif

/**
 * Spawn Particle 0x20
 * TODO These notes need converted into a C function prototype
 */
extern void external_func_8002A6B8(void);
	#if OOT_DEBUG
		asm("external_func_8002A6B8 = 0x8002A6B8");
	#elif OOT_U_1_0
		asm("external_func_8002A6B8 = 0x8001E1D4");
	#endif

/**
 * Spawn Particle 0x21
 * TODO These notes need converted into a C function prototype
 */
extern void external_func_8002A770(void);
	#if OOT_DEBUG
		asm("external_func_8002A770 = 0x8002A770");
	#elif OOT_U_1_0
		asm("external_func_8002A770 = 0x8001E28C");
	#endif

/**
 * Spawn Particle 0x22 (Wrapper for 8001E3B0)
 * TODO These notes need converted into a C function prototype
 */
extern void external_func_8002A90C(void);
	#if OOT_DEBUG
		asm("external_func_8002A90C = 0x8002A90C");
	#elif OOT_U_1_0
		asm("external_func_8002A90C = 0x8001E428");
	#endif

/**
 * Spawn Particle 0x23 (Wrapper for 8001E478)
 * TODO These notes need converted into a C function prototype
 */
extern void external_func_8002A9F4(void);
	#if OOT_DEBUG
		asm("external_func_8002A9F4 = 0x8002A9F4");
	#elif OOT_U_1_0
		asm("external_func_8002A9F4 = 0x8001E510");
	#endif

/**
 * Spawn Particle 0x24
 * TODO These notes need converted into a C function prototype
 */
extern void external_func_8002AA44(void);
	#if OOT_DEBUG
		asm("external_func_8002AA44 = 0x8002AA44");
	#elif OOT_U_1_0
		asm("external_func_8002AA44 = 0x8001E560");
	#endif

/**
 * Draws shadow until instance is destroyed (use in constructor)
 * actor = actor instance
 * unk0 = unknown float, gets stored at dest + 0x08
 * drawfunc = ACTOR_SHADOW_DRAWFUNC_CIRCLE for circular shadows, ACTOR_SHADOW_DRAWFUNC_TEARDROP for teardrop shadows attached to feet, gets stored at dest + 0x0C
 * radius = size of shadow(s), gets stored at dest + 0x10
 * INTERNAL dest = actor instance + 0xB4
 */
/*wrapper*/static inline void actor_init_shadow(z64_actor_t *actor, f32 unk0, void *drawfunc, f32 radius);
/*internal-use-only*/extern void _actor_init_shadow(void *dest, f32 unk0, void *drawfunc, f32 radius);
	#if OOT_DEBUG
		asm("_actor_init_shadow = 0x8002B1E0");
		asm("ACTOR_SHADOW_DRAWFUNC_CIRCLE = 0x8002B5EC");
		asm("ACTOR_SHADOW_DRAWFUNC_TEARDROP = 0x8002B8C4");
	#elif OOT_U_1_0
		asm("_actor_init_shadow = 0x8001EC20");
		// TODO Needs 1.0 equivalents!
	#endif
	extern char // drawfunc must be the address of one of the following:
		ACTOR_SHADOW_DRAWFUNC_CIRCLE,
		ACTOR_SHADOW_DRAWFUNC_TEARDROP;
	#if OOT_DEBUG || OOT_U_1_0
		static inline void actor_init_shadow(z64_actor_t *actor, f32 unk0, void *drawfunc, f32 radius) {
			_actor_init_shadow( AADDR(actor, 0xB4), unk0, drawfunc, radius );
		}
	#endif

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
extern int flag_get_switch(u32 glbl_ctxt, int flag);
	#if OOT_DEBUG
		asm("flag_get_switch = 0x8002CB40");
	#elif OOT_U_1_0
		asm("flag_get_switch = 0x8002049C");
	#endif

/**
 * Sets Switch Flag to 1
 */
extern void flag_set_switch(u32 glbl_ctxt, int flag);
	#if OOT_DEBUG
		asm("flag_set_switch = 0x8002CB74");
	#elif OOT_U_1_0
		asm("flag_set_switch = 0x800204D0");
	#endif

/**
 * Sets Switch Flag to 0
 */
extern void flag_unset_switch(u32 glbl_ctxt, int flag);
	#if OOT_DEBUG
		asm("flag_unset_switch = 0x8002CBB4");
	#elif OOT_U_1_0
		asm("flag_unset_switch = 0x80020510");
	#endif

/**
 * Tests if Unused Scene Flag is Set
 * This function is not used inside any existing overlay
 */
extern int flag_get_uscene(u32 glbl_ctxt, int flag);
	#if OOT_DEBUG
		asm("flag_get_uscene = 0x8002CBF8");
	#elif OOT_U_1_0
		asm("flag_get_uscene = 0x80020554");
	#endif

/**
 * Sets Unused Scene Flag to 1
 * This function is not used inside any existing overlay
 */
extern void flag_set_uscene(u32 glbl_ctxt, int flag);
	#if OOT_DEBUG
		asm("flag_set_uscene = 0x8002CC2C");
	#elif OOT_U_1_0
		asm("flag_set_uscene = 0x80020588");
	#endif

/**
 * Sets Unused Scene Flag to 0
 * This function is not used inside any existing overlay
 */
extern void flag_unset_uscene(u32 glbl_ctxt, int flag);
	#if OOT_DEBUG
		asm("flag_unset_uscene = 0x8002CC6C");
	#elif OOT_U_1_0
		asm("flag_unset_uscene = 0x800205C8");
	#endif

/**
 * Tests if a Chest Flag is set
 */
extern int flag_get_treasure(u32 glbl_ctxt, int flag);
	#if OOT_DEBUG
		asm("flag_get_treasure = 0x8002CCB0");
	#elif OOT_U_1_0
		asm("flag_get_treasure = 0x8002060C");
	#endif

/**
 * Sets Chest Flag to 1
 */
extern void flag_set_treasure(u32 glbl_ctxt, int flag);
	#if OOT_DEBUG
		asm("flag_set_treasure = 0x8002CCC4");
	#elif OOT_U_1_0
		asm("flag_set_treasure = 0x80020624");
	#endif

/**
 * Test if a Room Clear Flag is set
 */
extern int flag_get_roomclear(u32 glbl_ctxt, int flag);
	#if OOT_DEBUG
		asm("flag_get_roomclear = 0x8002CCDC");
	#elif OOT_U_1_0
		asm("flag_get_roomclear = 0x80020640");
	#endif

/**
 * Sets Room Clear Flag to 1
 */
extern void flag_set_roomclear(u32 glbl_ctxt, int flag);
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
extern int flag_get_0x1D40(u32 glbl_ctxt, int flag);
	#if OOT_DEBUG
		asm("flag_get_0x1D40 = 0x8002CD24");
	#elif OOT_U_1_0
		asm("flag_get_0x1D40 = 0x80020694");
	#endif

/**
 * Sets Global Context + 0x1D40 Flag to 1
 */
extern void flag_set_0x1D40(u32 glbl_ctxt, int flag);
	#if OOT_DEBUG
		asm("flag_set_0x1D40 = 0x8002CD38");
	#elif OOT_U_1_0
		asm("flag_set_0x1D40 = 0x800206AC");
	#endif

/**
 * Tests if Scene Collectible Flag is set
 */
extern int flag_get_scenecollect(u32 glbl_ctxt, int flag);
	#if OOT_DEBUG
		asm("flag_get_scenecollect = 0x8002CD6C");
	#elif OOT_U_1_0
		asm("flag_get_scenecollect = 0x800206E8");
	#endif

/**
 * Sets Scene Collectible Flag to 1
 */
extern void flag_set_scenecollect(u32 glbl_ctxt, int flag);
	#if OOT_DEBUG
		asm("flag_set_scenecollect = 0x8002CDA0");
	#elif OOT_U_1_0
		asm("flag_set_scenecollect = 0x8002071C");
	#endif

/**
 * Boss Title
 * A0 - global context | A1 - A0 + 0x1D4C | A2 - (object pointer + texture offset inside the object)
 */
extern void actor_boss_title(u32 glbl_ctxt, u32 glbl_ctxt_plus_0x1D4C, u32 texture);
	#if OOT_DEBUG
		asm("actor_boss_title = 0x8002CE00");
	#elif OOT_U_1_0
		asm("actor_boss_title = 0x80020780");
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
	#elif MM_U
		asm("actor_set_scale = 0x800B67E0");
	#endif

/**
 * Update CPU Segment 0x06 to point to actor's defined object dependency
 */
extern void actor_set_object(u32 glbl_ctxt, z64_actor_t *actor);
	#if OOT_DEBUG
		asm("actor_set_object = 0x8002D644");
	#elif OOT_U_1_0
		asm("actor_set_object = 0x80020FA4");
	#endif

/**
 * Physics, updates XYZ coordinates of actor
 */
extern void actor_update_pos(z64_actor_t *actor);
	#if OOT_DEBUG
		asm("actor_update_pos = 0x8002D7EC");
	#elif OOT_U_1_0
		asm("actor_update_pos = 0x80021124");
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
extern void external_func_8002D8E0(void);
	#if OOT_DEBUG
		asm("external_func_8002D8E0 = 0x8002D8E0");
	#elif OOT_U_1_0
		asm("external_func_8002D8E0 = 0x8002121C");
	#endif

/**
 * Physics, updates XYZ velocity vectors (+0x5C) of an actor
 * Factors x and y component of speed rotation xyz (+0x30)
 * TODO These notes need converted into a C function prototype
 */
extern void external_func_8002D908(void);
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
 * Calculates XYZ distance between actor (+0x24) and a point  | Wrapper fo 80063E18
 * TODO These notes need converted into a C function prototype
 * A0 = Actor | A1 = Coordinate ptr | F0 = Result
 */
extern float math_distance_xyz_actor_point(z64_actor_t *a, z64_point_t *b);
	#if OOT_DEBUG
		asm("math_distance_xyz_actor_point = 0x8002DB6C");
	#elif OOT_U_1_0
		asm("math_distance_xyz_actor_point = 0x800214D8");
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
		asm("math_distance_xz_actor_point = 0x8002DBB0");
	#elif OOT_U_1_0
		asm("math_distance_xz_actor_point = 0x80021528");
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
 * TODO This function is completely undocumented
 */
extern void external_func_8002DF54(void);
	#if OOT_DEBUG
		asm("external_func_8002DF54 = 0x8002DF54");
	#elif OOT_U_1_0
		asm("external_func_8002DF54 = 0x800218EC");
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
extern int actor_angle_link_in_range(z64_actor_t *actor, int16_t angle);
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
 * TODO These notes need converted into a C function prototype
 * A0 = Global Context | A1 = Actor Instance | A2 = float wallCheckHeight? (26f for Link) | A3 = float wallPushback? (18f/14f for Adult/Child Link) | SP+0x10 float ? (56f/40f for Adult/Child Link) | SP+0x14 int (type?)
 */
extern void external_func_8002E4B4(void);
	#if OOT_DEBUG
		asm("external_func_8002E4B4 = 0x8002E4B4");
	#elif OOT_U_1_0
		asm("external_func_8002E4B4 = 0x80021E6C");
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
extern void external_func_8002EBCC(void);
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

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8002F194(void);
	#if OOT_DEBUG
		asm("external_func_8002F194 = 0x8002F194");
	#elif OOT_U_1_0
		asm("external_func_8002F194 = 0x80022930");
	#endif

/**
 * NPC Request Trade Item
 * TODO These notes need converted into a C function prototype
 * A0 = Actor Instance | A1 = Global Context | A2 = float (distance 1?) | A3 = float (disstance 2?) | SP+0x10 = Trade Item Index
 */
extern void actor_npc_trade_request(void);
	#if OOT_DEBUG
		asm("actor_npc_trade_request = 0x8002F1C4");
	#elif OOT_U_1_0
		asm("actor_npc_trade_request = 0x80022960");
	#endif

/**
 * NPC Request Trade Item | (Wrapper for 80022960)
 * Passes A2 into A2 and A3 of inner function
 * TODO These notes need converted into a C function prototype
 * A0 = Actor Instance | A1 = Global Context | A2 = float distance? | A3 = Trade Item Index
 */
extern void external_func_8002F298(void);
	#if OOT_DEBUG
		asm("external_func_8002F298 = 0x8002F298");
	#elif OOT_U_1_0
		asm("external_func_8002F298 = 0x80022A34");
	#endif

/**
 * NPC Request Trade Item? | (Wrapper for 80022A34)
 * Calls wrapped function with A3 = 0
 * TODO These notes need converted into a C function prototype
 * A0 = Actor Instance | A1 = Global Context | A2 = float distance?
 */
extern void external_func_8002F2CC(void);
	#if OOT_DEBUG
		asm("external_func_8002F2CC = 0x8002F2CC");
	#elif OOT_U_1_0
		asm("external_func_8002F2CC = 0x80022A68");
	#endif

/**
 * NPC Request Trade Item? | (Wrapper for 80022A68)
 * Calls wrapped function with A2 =(float) s16 Inst. + 0x98 + 50.0f
 * TODO These notes need converted into a C function prototype
 * A0 = Actor Instance | A1 = Global Context
 */
extern void external_func_8002F2F4(z64_actor_t *actor, u32 global_context);
	#if OOT_DEBUG
		asm("external_func_8002F2F4 = 0x8002F2F4");
	#elif OOT_U_1_0
		asm("external_func_8002F2F4 = 0x80022A90");
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
extern int actor_npc_trade_get(void);
	#if OOT_DEBUG
		asm("actor_npc_trade_get = 0x8002F368");
	#elif OOT_U_1_0
		asm("actor_npc_trade_get = 0x80022B04");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8002F374(void);
	#if OOT_DEBUG
		asm("external_func_8002F374 = 0x8002F374");
	#elif OOT_U_1_0
		asm("external_func_8002F374 = 0x80022B14");
	#endif

/**
 * Is Actor Held? Or Interacting?
 * TODO Question marks: let's get to the bottom of this. Also, return type.
 * A0 = Actor Instance | V0 = 0 if Instance + 0x118 is null, else 1
 */
extern int actor_is_held(z64_actor_t *actor);
	#if OOT_DEBUG
		asm("actor_is_held = 0x8002F410");
	#elif OOT_U_1_0
		asm("actor_is_held = 0x80022BB0");
	#endif

/**
 * Give Item
 * TODO These notes need converted into a C function prototype
 * A0 = Actor instance //Actor giving item | A1 = Global Context | A2 = Get Item ID | A3 = float, max xz distance from actor to Link that item will be given | SP+10 = float, max y distance from actor to Link that item will be given
 */
extern void external_func_8002F434(void);
	#if OOT_DEBUG
		asm("external_func_8002F434 = 0x8002F434");
	#elif OOT_U_1_0
		asm("external_func_8002F434 = 0x80022BD4");
	#endif

/**
 * Give Item Wrapper (80022BD4) | Sets A3 to 50.0f, SP+0x10 to 10.0f
 * TODO These notes need converted into a C function prototype
 * A0 = Actor Instance | A1 = Global Context | A2 = Get Item Id
 */
extern void external_func_8002F554(void);
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
extern void external_func_8002F580(void);
	#if OOT_DEBUG
		asm("external_func_8002F580 = 0x8002F580");
	#elif OOT_U_1_0
		asm("external_func_8002F580 = 0x80022D20");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8002F5A0(void);
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
extern void external_func_8002F758(void);
	#if OOT_DEBUG
		asm("external_func_8002F758 = 0x8002F758");
	#elif OOT_U_1_0
		// TODO Needs 1.0 equivalent!
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8002F7A0(void);
	#if OOT_DEBUG
		asm("external_func_8002F7A0 = 0x8002F7A0");
	#elif OOT_U_1_0
		asm("external_func_8002F7A0 = 0x80022F48");
	#endif

/**
 * Play Sound Effect (Actor)
 */
extern void sound_play_actor(z64_actor_t *actor, u16 sound_id);
	#if OOT_DEBUG
		asm("sound_play_actor = 0x8002F7DC");
	#elif OOT_U_1_0
		asm("sound_play_actor = 0x80022F84");
	#endif

/**
 * Play Sound Effect (Actor)
 * TODO There are two identical functions... distinguish the difference and fix names
 */
extern void sound_play_actor2(z64_actor_t *actor, u16 sound_id);
	#if OOT_DEBUG
		asm("sound_play_actor2 = 0x8002F828");
	#elif OOT_U_1_0
		asm("sound_play_actor2 = 0x80022FD0");
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
 * TODO This function is completely undocumented
 */
extern void external_func_8002F8F0(void);
	#if OOT_DEBUG
		asm("external_func_8002F8F0 = 0x8002F8F0");
	#elif OOT_U_1_0
		asm("external_func_8002F8F0 = 0x800230A0");
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
extern void external_func_8002F974(void);
	#if OOT_DEBUG
		asm("external_func_8002F974 = 0x8002F974");
	#elif OOT_U_1_0
		asm("external_func_8002F974 = 0x8002313C");
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
extern void actor_set_draw_distance(u32 glbl_ctxt, z64_actor_t *actor, void *a2 /*actor+0xE4*/, float *a3 /*actor+0xF0*/);
	#if OOT_DEBUG
		asm("actor_set_draw_distance = 0x800314D4");
	#elif OOT_U_1_0
		asm("actor_set_draw_distance = 0x800249DC");
	#endif

/**
 * Spawn Actor
 * TODO a0 = global context + 0x1C24, do we really pass it in this way?
 * A0 = Global Context + 0x1C24 | A1 = Global Context | A2 = s16 Actor Id | A3 = float x | SP+0x10 = float y | SP+0x14 = float z | SP+0x18 = rotx | SP+0x1C = roty | SP+0x20 = rotz | SP+0x24 = s16 var | V0 = Pointer to new actor, or null
 */
extern void actor_spawn(u32 a0/*gl_ctx+0x1C24*/, u32 glbl_ctxt, s16 actor_id, f32 x, f32 y, f32 z, s16 rot_x, s16 rot_y, s16 rot_z, u16 variable);
	#if OOT_DEBUG
		asm("actor_spawn = 0x80031F50");
	#elif OOT_U_1_0
		asm("actor_spawn = 0x80025110");
	#elif MM_U
		asm("actor_spawn = 0x800BAC60");
	#endif

/**
 * Spawn actor attached to `dest`, returns pointer to new actor `newactor` or NULL on failure
 * `newactor` + 0x118 will be set to `actor_id`
 * `dest` + 0x11C will point to `newactor`
 * `newactor` will be bound to `dest`'s room unless spawned actor is global (room=-1)
 * TODO do something with a0?
 * A0 = Global Context + 0x1C24 | A1 = Actor* attachToInstance | A2 = Global Context | A3 = s16 Actor Id | SP + 0x10 = float x | SP + 0x14 = float y | SP + 0x18 = float z | SP + 0x1C = s16 rotx | SP + 0x20 = s16 roty | SP + 0x24 = s16 rotz | SP + 0x28 = s16 var | V0 = Pointer to new actor, or null if allocation failed
 */
extern z64_actor_t *actor_spawn_attached(u32 a0/*gl_ctx+0x1C24*/, z64_actor_t *dest, s16 actor_id, f32 x, f32 y, f32 z, s16 rot_x, s16 rot_y, s16 rot_z, u16 variable);
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
extern void external_func_80032F54(void);
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
 * TODO This function is completely undocumented
 */
extern void external_func_80033480(void);
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
extern z64_actor_t *actor_is_bombed(u32 glbl_ctxt, z64_capsule_t *capsule);
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
extern void external_func_80033684(void);
	#if OOT_DEBUG
		asm("external_func_80033684 = 0x80033684");
	#elif OOT_U_1_0
		asm("external_func_80033684 = 0x8002650C");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_80033748(void);
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
 * xyz = pointer to an actor's internal position array (actor + 0x24)
 * scale[3] = scale along three axes
 * alpha = opacity of the shadow
 * a0 actor pointer + 0x24 (position array) | a1  scale, 12 byte array | a2 0x00FF | a3 global context
 */
extern void actor_shadow_circle(void *xyz, f32 scale[3], u8 alpha, u32 glbl_ctxt);
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
 * Generates a random floating point between 0 and N exclusive
 * TODO These notes need converted into a C function prototype
 * F12 = N, exclusive upper bound | F0 = result
 */
extern f32 math_rand_f32(void);
	#if OOT_DEBUG
		asm("math_rand_f32 = 0x80033EF8");
	#elif OOT_U_1_0
		asm("math_rand_f32 = 0x80026D64");
	#endif

/**
 * Multiplies value by a random scalar between -0.5 and 0.5 exclusive
 * TODO These notes need converted into a C function prototype
 * F12 = N | F0 = result
 */
extern void external_func_80033F20(void);
	#if OOT_DEBUG
		asm("external_func_80033F20 = 0x80033F20");
	#elif OOT_U_1_0
		asm("external_func_80033F20 = 0x80026D90");
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
 * TODO This function is completely undocumented
 */
extern void external_func_8003426C(void);
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
 * A0 = s16
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
 * TODO This function is completely undocumented
 */
extern void external_func_80034BA0(void);
	#if OOT_DEBUG
		asm("external_func_80034BA0 = 0x80034BA0");
	#elif OOT_U_1_0
		// TODO Needs 1.0 equivalent!
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
extern void draw_static_dlist(u32 glbl_ctxt, u32 dlist);
	#if OOT_DEBUG
		asm("draw_static_dlist = 0x80035260");
	#elif OOT_U_1_0
		asm("draw_static_dlist = 0x80028048");
	#endif

/**
 * Draw a single display list, affected by Lens of Truth?
 * TODO There's a question mark, we need to confirm whether Lens of Truth has anything to do with it
 * a0 - global context | a1 - DList segment offset | a2 - Unknown, set to 0
 */
extern void draw_static_dlist_lens(u32 glbl_ctxt, u32 dlist);
	#if OOT_DEBUG
		asm("draw_static_dlist_lens = 0x80035324");
	#elif OOT_U_1_0
		asm("draw_static_dlist_lens = 0x800280C8");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800353F4(void);
	#if OOT_DEBUG
		asm("external_func_800353F4 = 0x800353F4");
	#elif OOT_U_1_0
		asm("external_func_800353F4 = 0x80028158");
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
 * TODO This function is completely undocumented
 */
extern void external_func_80035628(void);
	#if OOT_DEBUG
		asm("external_func_80035628 = 0x80035628");
	#elif OOT_U_1_0
		asm("external_func_80035628 = 0x80028390");
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
extern int flag_get_event_chk_inf(int flag);
	#if OOT_DEBUG
		asm("flag_get_event_chk_inf = 0x80035B4C");
	#elif OOT_U_1_0
		asm("flag_get_event_chk_inf = 0x800288B4");
	#endif

/**
 * Sets event_chk_inf flag to 1
 */
extern void flag_set_event_chk_inf(int flag);
	#if OOT_DEBUG
		asm("flag_set_event_chk_inf = 0x80035B74");
	#elif OOT_U_1_0
		asm("flag_set_event_chk_inf = 0x800288E0");
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
 * TODO This function is completely undocumented
 */
extern void external_func_80038290(void);
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
extern void external_func_8003C940(void);
	#if OOT_DEBUG
		asm("external_func_8003C940 = 0x8003C940");
	#elif OOT_U_1_0
		asm("external_func_8003C940 = 0x8002F454");
	#endif

/**
 * Raycast
 * TODO No notes available
 */
extern void math_raycast(void);
	#if OOT_DEBUG
		asm("math_raycast = 0x8003C9A4");
	#elif OOT_U_1_0
		asm("math_raycast = 0x8002F4B8");
	#endif

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
 * TODO This function is completely undocumented
 */
extern void external_func_8003E30C(void);
	#if OOT_DEBUG
		asm("external_func_8003E30C = 0x8003E30C");
	#elif OOT_U_1_0
		asm("external_func_8003E30C = 0x80030D08");
	#endif

/**
 * description
 * TODO These notes need converted into a C function prototype
 * A0 = Global Context | A1 = Global Context + 0x810 | A2 = Actor Index | A3 = result of func 80041880 | V0 = Mesh Collision Id
 */
extern void dynapolyinfo_set_actor(void);
	#if OOT_DEBUG
		asm("dynapolyinfo_set_actor = 0x8003EA74");
	#elif OOT_U_1_0
		asm("dynapolyinfo_set_actor = 0x800313A4");
	#endif

/**
 * description
 * TODO These notes need converted into a C function prototype
 * A0 = Global Context | A1 = Mesh Collision Id | V0 = Actor Instance or null
 */
extern void dynapolyinfo_get_actor(void);
	#if OOT_DEBUG
		asm("dynapolyinfo_get_actor = 0x8003EB84");
	#elif OOT_U_1_0
		asm("dynapolyinfo_get_actor = 0x80031464");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8003EBF8(void);
	#if OOT_DEBUG
		asm("external_func_8003EBF8 = 0x8003EBF8");
	#elif OOT_U_1_0
		asm("external_func_8003EBF8 = 0x800314D8");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8003EC50(void);
	#if OOT_DEBUG
		asm("external_func_8003EC50 = 0x8003EC50");
	#elif OOT_U_1_0
		asm("external_func_8003EC50 = 0x80031530");
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
extern void dynapolyinfo_delete_reserve(void);
	#if OOT_DEBUG
		asm("dynapolyinfo_delete_reserve = 0x8003ED58");
	#elif OOT_U_1_0
		asm("dynapolyinfo_delete_reserve = 0x80031638");
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
 * A0 = Segment Offset to Collision Data | A1 = ptr to store result?
 */
extern void external_func_80041880(void);
	#if OOT_DEBUG
		asm("external_func_80041880 = 0x80041880");
	#elif OOT_U_1_0
		asm("external_func_80041880 = 0x80033EF4");
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
extern void external_func_80043480(void);
	#if OOT_DEBUG
		asm("external_func_80043480 = 0x80043480");
	#elif OOT_U_1_0
		asm("external_func_80043480 = 0x80035260");
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
extern void external_func_8004356C(void);
	#if OOT_DEBUG
		asm("external_func_8004356C = 0x8004356C");
	#elif OOT_U_1_0
		asm("external_func_8004356C = 0x80035364");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_80043590(void);
	#if OOT_DEBUG
		asm("external_func_80043590 = 0x80043590");
	#elif OOT_U_1_0
		asm("external_func_80043590 = 0x80035388");
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
extern void external_func_8005A9F4(void);
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
 * A0 = Cutscene Camera struct ptr | A1 = Focus Point Tween List | A2 = Camera Position Tween List | A3 = Actor Instance (tracked actor)
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
		// TODO Needs 1.0 equivalent!
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
	#endif

/**
 * Initializes hitbox structure
 * TODO These notes need converted into a C function prototype
 * a0 - global context | a1 - actor instance + 0x014C (offset of hitbox struct in the instance)
 */
extern void external_func_8005C364(u32 gl_ctxt, z64_capsule_t *collision);
	#if OOT_DEBUG
		asm("external_func_8005C364 = 0x8005C364");
	#elif OOT_U_1_0
		asm("external_func_8005C364 = 0x8004AB7C");
	#endif

/**
 * Unloads hitbox structure
 * TODO These notes need converted into a C function prototype
 * a0 - global context | a1 - actor instance + 0x014C (offset where you stored the hitbox struct)
 */
extern void external_func_8005C3AC(void);
	#if OOT_DEBUG
		asm("external_func_8005C3AC = 0x8005C3AC");
	#elif OOT_U_1_0
		asm("external_func_8005C3AC = 0x8004ABCC");
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
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8005C450(void);
	#if OOT_DEBUG
		asm("external_func_8005C450 = 0x8005C450");
	#elif OOT_U_1_0
		asm("external_func_8005C450 = 0x8004AC84");
	#endif

/**
 * Loads hitbox variable array to hitbox structure
 * TODO These notes need converted into a C function prototype
 * a0 - global context | a1 - actor instance + 0x014C (offset of hitbox struct in the instance) | a2 - actor instance | a3 - hitbox variable array
 */
extern void external_func_8005C4AC(u32 gl_ctxt, z64_capsule_t *dest, z64_actor_t *actor, z64_capsule_init_t *source);
	#if OOT_DEBUG
		asm("external_func_8005C4AC = 0x8005C4AC");
	#elif OOT_U_1_0
		asm("external_func_8005C4AC = 0x8004ACEC");
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
extern void external_func_8005D018(void);
	#if OOT_DEBUG
		asm("external_func_8005D018 = 0x8005D018");
	#elif OOT_U_1_0
		asm("external_func_8005D018 = 0x8004B858");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8005D060(void);
	#if OOT_DEBUG
		asm("external_func_8005D060 = 0x8005D060");
	#elif OOT_U_1_0
		asm("external_func_8005D060 = 0x8004B8A8");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8005D104(void);
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
extern void actor_collision_check_set_at(u32 glbl_ctxt, u32 a1 /*glbl_ctxt+0x11E60*/, z64_capsule_t *collision);
	#if OOT_DEBUG
		asm("actor_collision_check_set_at = 0x8005D79C");
	#elif OOT_U_1_0
		asm("actor_collision_check_set_at = 0x8004BD50");
	#endif

/**
 * //Subscribe to collision pool 2, non-complex poly types | //Called directly by actors
 * TODO Look into actors that use this function, there are conflicts between these notes and the function prototype, define a type for collision and figure out the return type
 * A0 = Global Context | A1 = 801DA300 //collision body groups | A2 = Collision Body Ptr | V0 = 0 or -1 based on 801DA302 lowest bit?
 */
extern void actor_collision_check_set_ac(void);
	#if OOT_DEBUG
		asm("actor_collision_check_set_ac = 0x8005D9F4");
	#elif OOT_U_1_0
		asm("actor_collision_check_set_ac = 0x8004BF40");
	#endif

/**
 * Subscribe to collision pool 3, non-complex poly types
 * TODO Look into actors that use this function, there are conflicts between these notes and the function prototype, define a type for collision and figure out the return type
 * A0 = Global Context | A1 = 801DA300 //collision body groups | A2 = Collision Body Ptr | V0 = 0 or -1 based on 801DA302 lowest bit? | Called directly by actors
 */
extern void actor_collision_check_set_ot(u32 gl_ctxt, u32 col_body_groups, z64_capsule_t *collision);
	#if OOT_DEBUG
		asm("actor_collision_check_set_ot = 0x8005DC4C");
	#elif OOT_U_1_0
		asm("actor_collision_check_set_ot = 0x8004C130");
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
 * //Actor 0095
 * TODO These notes need converted into a C function prototype
 */
extern void external_func_80061ED4(void);
	#if OOT_DEBUG
		asm("external_func_80061ED4 = 0x80061ED4");
	#elif OOT_U_1_0
		asm("external_func_80061ED4 = 0x80050344");
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
	#endif

/**
 * Enables hitbox, only needs to be used one time?
 * TODO These notes need converted into a C function prototype
 * a0 - actor instance | a1 - actor instance + 0x014C (offset of hitbox struct in the instance)
 */
extern void external_func_800626DC(z64_actor_t *actor, void* collision);
	#if OOT_DEBUG
		asm("external_func_800626DC = 0x800626DC");
	#elif OOT_U_1_0
		asm("external_func_800626DC = 0x80050B00");
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
 * Starts cutscene for link
 * TODO These notes need converted into a C function prototype
 * A0 - global context | A1 - global context + 0x1D64
 */
extern void external_func_80064520(void);
	#if OOT_DEBUG
		asm("external_func_80064520 = 0x80064520");
	#elif OOT_U_1_0
		asm("external_func_80064520 = 0x80052328");
	#endif

/**
 * Ends cutscene for link
 * TODO These notes need converted into a C function prototype
 * A0 - global context | A1 - global context + 0x1D64
 */
extern void external_func_80064534(void);
	#if OOT_DEBUG
		asm("external_func_80064534 = 0x80064534");
	#elif OOT_U_1_0
		asm("external_func_80064534 = 0x80052340");
	#endif

/**
 * Set Cutscene Pointer (Area Intro Cutscenes Only?)
 * Contains Disk Drive Hook
 * TODO These notes need converted into a C function prototype
 * A0 = Global Context | A1 = Segment Offset
 */
extern void external_func_800693D8(void);
	#if OOT_DEBUG
		asm("external_func_800693D8 = 0x800693D8");
	#elif OOT_U_1_0
		asm("external_func_800693D8 = 0x80056F98");
	#endif

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
extern void sound_play_position(void);
	#if OOT_DEBUG
		asm("sound_play_position = 0x8006BAD8");
	#elif OOT_U_1_0
		asm("sound_play_position = 0x80058FF8");
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
extern void external_func_8006C360(void);
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
 * Return s32 at 8011A5E8 (Event Days)
 * TODO These notes need converted into a C function prototype
 * V0 = s32 at 8011A5E8
 */
extern void external_func_800775CC(void);
	#if OOT_DEBUG
		asm("external_func_800775CC = 0x800775CC");
	#elif OOT_U_1_0
		asm("external_func_800775CC = 0x80063404");
	#endif

/**
 * Zero s32 at 8011A5E8 (Event Days)
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
 * A0 = s32? value to write to 8011B9DE
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
 * TODO These notes need converted into a C function prototype
 * A0 = Address | A1 = Size | A2 = u8 value
 */
extern void external_func_800777E0(void);
	#if OOT_DEBUG
		asm("external_func_800777E0 = 0x800777E0");
	#elif OOT_U_1_0
		asm("external_func_800777E0 = 0x80063630");
	#endif

/**
 * Math, Get cosine of short rotation angle
 * TODO Test in-game
 * A0 = s16 rotation | F0 = cosine of A0
 */
extern float math_coss(s16 angle);
	#if OOT_DEBUG
		asm("math_coss = 0x80077834");
	#elif OOT_U_1_0
		asm("math_coss = 0x80063684");
	#endif

/**
 * Math, Get sine of short rotation angle
 * TODO Test in-game
 * A0 = s16 rotation | F0 = sine of A0
 */
extern float math_sins(s16 angle);
	#if OOT_DEBUG
		asm("math_sins = 0x80077870");
	#elif OOT_U_1_0
		asm("math_sins = 0x800636C4");
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
 */
extern void external_func_8007797C(void);
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
extern void math_approxf(void);
	#if OOT_DEBUG
		asm("math_approxf = 0x80077A00");
	#elif OOT_U_1_0
		asm("math_approxf = 0x8006385C");
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
 * Generates random s16 between 0 and `range` (exlusive), and adds `offset`
 */
extern s16 math_rand_s16_offset(s16 offset, s16 range);
	#if OOT_DEBUG
		asm("math_rand_s16_offset = 0x80077D90");
	#elif OOT_U_1_0
		asm("math_rand_s16_offset = 0x80063BF0");
	#endif

/**
 * Copy vec3f_t
 */
extern void math_vec3f_copy(vec3f_t *out, vec3f_t *in);
	#if OOT_DEBUG
		asm("math_vec3f_copy = 0x80077E40");
	#elif OOT_U_1_0
		asm("math_vec3f_copy = 0x80063CAC");
	#endif

/**
 * convert vec3s_t to vec3f_t
 * Convert s16 Coordinates to Float Coordinates
 */
extern void math_vec3f_from_vec3s(vec3f_t *out, vec3s_t *in);
	#if OOT_DEBUG
		asm("math_vec3f_from_vec3s = 0x80077E5C");
	#elif OOT_U_1_0
		asm("math_vec3f_from_vec3s = 0x80063CCC");
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
	#endif

/**
 * get the difference of two vec3s_t types, stored as a vec3f_t
 * out = a - b
 * TODO Note that out, a, and b are ordered differently than the math_vec3f_sub version of this function; confirm whether this is actually correct
 * TODO confirm that it's actually a - b
 * A0 = Result Float Coord ptr (A - B) | A1 = s16 coord A ptr | A2 = s16 coord B ptr
 */
extern void math_vec3s_sub(vec3f_t *out, vec3s_t *a, vec3s_t *b);
	#if OOT_DEBUG
		asm("math_vec3s_sub = 0x80077F04");
	#elif OOT_U_1_0
		asm("math_vec3s_sub = 0x80063D80");
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
	#endif

/**
 * calculates distance between two vec3f_t types
 */
extern float math_vec3f_distance(vec3f_t *a, vec3f_t *b);
	#if OOT_DEBUG
		asm("math_vec3f_distance = 0x80077F90");
	#elif OOT_U_1_0
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
 * A0 = Coord A ptr | A1 = Coord B ptr | V0 = s16 rotation
 */
extern void external_func_80078068(void);
	#if OOT_DEBUG
		asm("external_func_80078068 = 0x80078068");
	#elif OOT_U_1_0
		asm("external_func_80078068 = 0x80063F00");
	#endif

/**
 * Calculates Arctan2 (distance(XZ), Y) of two coordinates | (A-B for Y coordinate)
 * TODO These notes need converted into a C function prototype
 * A0 = Coord A ptr | A1 = Coord B ptr | V0 = s16 rotation
 */
extern void external_func_8007809C(void);
	#if OOT_DEBUG
		asm("external_func_8007809C = 0x8007809C");
	#elif OOT_U_1_0
		asm("external_func_8007809C = 0x80063F34");
	#endif

/**
 * Instance Init, Initialize Variable Chain
 * TODO These notes need converted into a C function prototype
 * A0 = Actor Instance | A1 = Variable Initializer List ptr
 */
extern void external_func_800780DC(void);
	#if OOT_DEBUG
		asm("external_func_800780DC = 0x800780DC");
	#elif OOT_U_1_0
		asm("external_func_800780DC = 0x80063F7C");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_80078310(void);
	#if OOT_DEBUG
		asm("external_func_80078310 = 0x80078310");
	#elif OOT_U_1_0
		asm("external_func_80078310 = 0x80064178");
	#endif

/**
 * smoothly aproximates a0 to a1, commonly used for smooth movement
 * TODO These notes need converted into a C function prototype
 * a0 - actor instance + xxxx (offset of the float that will change) | a1 - float where you want a0 to be aproximated to | a2 - float (amount?)a3 - float (smaller than a2)
 */
extern void external_func_8007841C(void);
	#if OOT_DEBUG
		asm("external_func_8007841C = 0x8007841C");
	#elif OOT_U_1_0
		asm("external_func_8007841C = 0x80064280");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8007848C(void);
	#if OOT_DEBUG
		asm("external_func_8007848C = 0x8007848C");
	#elif OOT_U_1_0
		asm("external_func_8007848C = 0x800642F0");
	#endif

/**
 * TODO These notes need converted into a C function prototype
 * A0 = s16 Rotation Pointer (Y this pass) | A1 = s16 ? | A2 = ? | A3 = ?
 */
extern void external_func_8007869C(void);
	#if OOT_DEBUG
		asm("external_func_8007869C = 0x8007869C");
	#elif OOT_U_1_0
		asm("external_func_8007869C = 0x80064508");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800787BC(void);
	#if OOT_DEBUG
		asm("external_func_800787BC = 0x800787BC");
	#elif OOT_U_1_0
		asm("external_func_800787BC = 0x80064624");
	#endif

/**
 * Copy u8[4] array
 * A0 = Destination ptr | A1 = Source ptr
 */
extern void mem_copy_u8_4(u8 *dest, u8 *src);
	#if OOT_DEBUG
		asm("mem_copy_u8_4 = 0x80078860");
	#elif OOT_U_1_0
		asm("mem_copy_u8_4 = 0x800646C8");
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
 * Play SFX (limited set, Identical to 800646F0)
 * TODO These notes need converted into a C function prototype
 * A0 = SFX
 */
extern void external_func_800788CC(void);
	#if OOT_DEBUG
		asm("external_func_800788CC = 0x800788CC");
	#elif OOT_U_1_0
		asm("external_func_800788CC = 0x80064738");
	#endif

/**
 * Play SFX (limited set)
 * TODO These notes need converted into a C function prototype
 * A0 = SFX
 */
extern void external_func_80078914(void);
	#if OOT_DEBUG
		asm("external_func_80078914 = 0x80078914");
	#elif OOT_U_1_0
		asm("external_func_80078914 = 0x80064780");
	#endif

/**
 * Initialize Flame Light (Wrapper for 80065B70)
 * TODO These notes need converted into a C function prototype
 */
extern void external_func_80079D8C(void);
	#if OOT_DEBUG
		asm("external_func_80079D8C = 0x80079D8C");
	#elif OOT_U_1_0
		asm("external_func_80079D8C = 0x80065BCC");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_80079DF0(void);
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
extern void external_func_80079E58(void);
	#if OOT_DEBUG
		asm("external_func_80079E58 = 0x80079E58");
	#elif OOT_U_1_0
		asm("external_func_80079E58 = 0x80065C98");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8007A764(void);
	#if OOT_DEBUG
		asm("external_func_8007A764 = 0x8007A764");
	#elif OOT_U_1_0
		asm("external_func_8007A764 = 0x800665B0");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_8007A7C4(void);
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
 * a0 - global context | a1 - s16 unknown
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
extern void inventory_item_set(u32 glbl_ctxt, u8 item);
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
extern u8 inventory_item_get(u8 item);
	#if OOT_DEBUG
		asm("inventory_item_get = 0x80086388");
	#elif OOT_U_1_0
		asm("inventory_item_get = 0x80071420");
	#endif

/**
 * Try Update Trade Quest Item, returns 1 on success 0 otherwise
 * Egg -> Chicken; Ruto's Letter -> Bottle, etc
 */
extern int inventory_item_update(u8 item_old, u8 item_new);
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
 * TODO These notes need converted into a C function prototype
 * a0 rupees to substract
 */
extern void external_func_8008730C(void);
	#if OOT_DEBUG
		asm("external_func_8008730C = 0x8008730C");
	#elif OOT_U_1_0
		asm("external_func_8008730C = 0x800721CC");
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
extern int player_is_busy(u32 glbl_ctxt, void *link_instance);
	#if OOT_DEBUG
		asm("player_is_busy = 0x8008E8DC");
	#elif OOT_U_1_0
		asm("player_is_busy = 0x8007938C");
	#endif

/**
 * Tests if Link is busy (Calls 8007938C, but also checks if talking?)
 * TODO Confirm return type, test in-game
 */
extern int player_is_busy_talking(u32 glbl_ctxt);
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
extern u8 player_get_mask(u32 glbl_ctxt);
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
extern void player_set_mask(u32 glbl_ctxt);
	#if OOT_DEBUG
		asm("player_set_mask = 0x8008F08C");
	#elif OOT_U_1_0
		asm("player_set_mask = 0x80079B54");
	#endif

/**
 * Test if Link is wearing the Mirror Shield (Instance + 0x13E)
 * returns 0 on false, 1 on true
 */
extern int player_is_mirrorshield(u32 global_context);
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
extern int player_is_hookshotting(void *link_instance);
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
 * A0 = Global Context
 */
extern void external_func_80093D18(void);
	#if OOT_DEBUG
		asm("external_func_80093D18 = 0x80093D18");
	#elif OOT_U_1_0
		asm("external_func_80093D18 = 0x8007E298");
	#endif

/**
 * Write Jump to Display List 800F8200 on POLY_XLU_DISP
 * Get Item Models
 * TODO These notes need converted into a C function prototype
 * A0 = Global Context
 */
extern void external_func_80093D84(void);
	#if OOT_DEBUG
		asm("external_func_80093D84 = 0x80093D84");
	#elif OOT_U_1_0
		asm("external_func_80093D84 = 0x8007E2C0");
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
extern void f3dzex_gen_settilesize(void);
	#if OOT_DEBUG
		asm("f3dzex_gen_settilesize = 0x80094F40");
	#elif OOT_U_1_0
		asm("f3dzex_gen_settilesize = 0x8007EB84");
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
 * TODO Need argument mappigns...
 */
extern int object_get_index(void);
	#if OOT_DEBUG
		asm("object_get_index = 0x8009812C");
	#elif OOT_U_1_0
		asm("object_get_index = 0x80081628");
	#endif

/**
 * Test if object file dependency is loaded (returns 1 on true 0 on false)
 * TODO Need argument mappings...
 */
extern int object_is_loaded(void);
	#if OOT_DEBUG
		asm("object_is_loaded = 0x80098188");
	#elif OOT_U_1_0
		asm("object_is_loaded = 0x80081688");
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
extern void actor_skelanime_draw(u32 gl_ctxt, u32 limb_index, u32 skelanime, u8 limb_dlists_count, void *func_unk0, void *func_unk1, z64_actor_t *actor);
	#if OOT_DEBUG
		asm("actor_skelanime_draw = 0x800A15C8");
	#elif OOT_U_1_0
		asm("actor_skelanime_draw = 0x8008993C");
	#endif

/**
 * Draw Matrix-Enabled Object
 * TODO Variable name cleanup, better notes
 * A0 = Global Context | A1 = Hierarchy Limb Index (in Object File, in RAM) | A2 = Pointer to Actor Drawing Table | A3 = Number of Limbs that use display lists. | 0x0010(SP) = 0 | 0x0014(SP) = 0 | 0x0018(SP) = Actor Instance Address
 */
extern void actor_skelanime_draw_mtx(u32 gl_ctxt, u32 limb_index, u32 skelanime, u8 limb_dlists_count, void *func_unk0, void *func_unk1, z64_actor_t *actor);
	#if OOT_DEBUG
		asm("actor_skelanime_draw_mtx = 0x800A1AC8");
	#elif OOT_U_1_0
		asm("actor_skelanime_draw_mtx = 0x80089D8C");
	#endif

/**
 * Count Animation Frames
 */
extern int anime_get_framecount(u32 animation);
	#if OOT_DEBUG
		asm("anime_get_framecount = 0x800A2000");
	#elif OOT_U_1_0
		asm("anime_get_framecount = 0x8008A194");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800A2288(void);
	#if OOT_DEBUG
		asm("external_func_800A2288 = 0x800A2288");
	#elif OOT_U_1_0
		// TODO Needs 1.0 equivalent!
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800A273C(void);
	#if OOT_DEBUG
		asm("external_func_800A273C = 0x800A273C");
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
extern void actor_skelanime_init(u32 gl_ctxt, z64_skelanime_t *skelanime, u32 skeleton, u32 animation, u8 unk0, u8 unk1, u8 unk2);
	#if OOT_DEBUG
		asm("actor_skelanime_init = 0x800A457C");
	#elif OOT_U_1_0
		asm("actor_skelanime_init = 0x8008C684");
	#endif

/**
 * Initialize Matrix-Enabled Object with Animation
 * TODO Unknown variables, do something about that
 * a0 = Global Context | a1 = Actor Instance Address + 0x014C (Drawing Table) | a2 = Hierarchy Pointer (In Object) | a3 = Animation Pointer (In Object)
 */
extern void actor_skelanime_init_mtx(u32 global_context, z64_skelanime_t *skelanime, u32 skeleton, u32 animation, u8 unk0, u8 unk1, u8 unk2);
	#if OOT_DEBUG
		asm("actor_skelanime_init_mtx = 0x800A46F8");
	#elif OOT_U_1_0
		asm("actor_skelanime_init_mtx = 0x8008C788");
	#endif

/**
 * Update Animation for Matrix-Enabled Object
 * TODO Conflict, notes below say actor+0x014C, but taking actor+0x0 is fine?
 * A0 = actor instance + 0x014C (Drawing Table) V0 = 1 if ?, else 0
 */
extern int actor_anime_frame_update_mtx(z64_skelanime_t *skelanime);
	#if OOT_DEBUG
		asm("actor_anime_frame_update_mtx = 0x800A49FC");
	#elif OOT_U_1_0
		asm("actor_anime_frame_update_mtx = 0x8008C9C0");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800A4FE4(void);
	#if OOT_DEBUG
		asm("external_func_800A4FE4 = 0x800A4FE4");
	#elif OOT_U_1_0
		asm("external_func_800A4FE4 = 0x8008CFC0");
	#endif

/**
 * Change Animation
 * transition rate is between 0.0 and 1.0
 * TODO These notes need converted into a C function prototype
 * A0 = actor instance + 0x014C (Drawing Table) | A1 = New Animation Pointer (in Object File) | A2 = Animation Speed (Floating Point) | A3 = ? | 0x0010(SP) = Number of Frames in Floating Point | 0x0014(SP) = some counter related to how long the animation should be played? | 0x0018(SP) = float transition rate, less than 1
 */
extern void actor_anime_change(z64_skelanime_t *skelanime, u32 animation, f32 playback_speed, f32 unk0, f32 frame_count, u8 unk_1, f32 transition_rate);
	#if OOT_DEBUG
		asm("actor_anime_change = 0x800A51A0");
	#elif OOT_U_1_0
		asm("actor_anime_change = 0x8008D17C");
	#endif

/**
 * TODO These notes need converted into a C function prototype
 * A0 = ? struct (Anju + 0x13C/ Archery Gerudo + 0x188) | A1 = Segment Offset
 */
extern void external_func_800A51E8(void);
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
 */
extern void external_func_800A52F8(void);
	#if OOT_DEBUG
		asm("external_func_800A52F8 = 0x800A52F8");
	#elif OOT_U_1_0
		asm("external_func_800A52F8 = 0x8008D2D4");
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
 * TODO This function is completely undocumented
 */
extern void external_func_800A6330(void);
	#if OOT_DEBUG
		asm("external_func_800A6330 = 0x800A6330");
	#elif OOT_U_1_0
		asm("external_func_800A6330 = 0x8008E1D4");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800A6360(void);
	#if OOT_DEBUG
		asm("external_func_800A6360 = 0x800A6360");
	#elif OOT_U_1_0
		asm("external_func_800A6360 = 0x8008E204");
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
 * TODO This function is completely undocumented
 */
extern void external_func_800A663C(void);
	#if OOT_DEBUG
		asm("external_func_800A663C = 0x800A663C");
	#elif OOT_U_1_0
		asm("external_func_800A663C = 0x8008E4EC");
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
 * TODO These notes need converted into a C function prototype
 * A0 - global context
 */
extern void external_func_800C0230(void);
	#if OOT_DEBUG
		asm("external_func_800C0230 = 0x800C0230");
	#elif OOT_U_1_0
		asm("external_func_800C0230 = 0x8009D0F0");
	#endif

/**
 * Camera related, use after 800C0230
 * TODO These notes need converted into a C function prototype
 * A0 - global context | A1 - unknown, set to 0 | A2 - unknown, set to 1
 */
extern void external_func_800C0314(void);
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
 * a0 - global context, a1 - set to 1 to update the camera , a2 - float array, origin?, a3 - float array, focus point?
 */
extern void external_func_800C04D8(void);
	#if OOT_DEBUG
		asm("external_func_800C04D8 = 0x800C04D8");
	#elif OOT_U_1_0
		asm("external_func_800C04D8 = 0x8009D328");
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
 * TODO These notes need converted into a C function prototype
 * A0 - global context | A1 - unknown, set to 1
 */
extern void external_func_800C08AC(void);
	#if OOT_DEBUG
		asm("external_func_800C08AC = 0x800C08AC");
	#elif OOT_U_1_0
		asm("external_func_800C08AC = 0x8009D718");
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
 * TODO This function is completely undocumented
 */
extern void external_func_800C0B60(void);
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
 * TODO This function is completely undocumented
 */
extern void external_func_800C69CC(void);
	#if OOT_DEBUG
		asm("external_func_800C69CC = 0x800C69CC");
	#elif OOT_U_1_0
		// TODO Needs 1.0 equivalent!
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800C6AC4(void);
	#if OOT_DEBUG
		asm("external_func_800C6AC4 = 0x800C6AC4");
	#elif OOT_U_1_0
		// TODO Needs 1.0 equivalent!
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800C6B54(void);
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
extern void external_func_800CA720(void);
	#if OOT_DEBUG
		asm("external_func_800CA720 = 0x800CA720");
	#elif OOT_U_1_0
		asm("external_func_800CA720 = 0x800A45FC");
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
 * returns rotation in s16 format
 * TODO These notes need converted into a C function prototype
 * F12 = x | F14 = y | V0 = s16 Rotation
 */
extern s16 math_atan2s(void);
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
extern void external_func_800D0984(void);
	#if OOT_DEBUG
		asm("external_func_800D0984 = 0x800D0984");
	#elif OOT_U_1_0
		asm("external_func_800D0984 = 0x800AA7F4");
	#endif

/**
 * Create/Apply x,y,z scalar transformation on Float Matrix Stack
 * TODO These notes need converted into a C function prototype
 * F12 = x | F14 = y | A2 = float z | A3 = 0 initializes new matrix, 1 transforms stored matrix
 */
extern void external_func_800D0A8C(void);
	#if OOT_DEBUG
		asm("external_func_800D0A8C = 0x800D0A8C");
	#elif OOT_U_1_0
		asm("external_func_800D0A8C = 0x800AA8FC");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800D0B70(void);
	#if OOT_DEBUG
		asm("external_func_800D0B70 = 0x800D0B70");
	#elif OOT_U_1_0
		asm("external_func_800D0B70 = 0x800AA9E0");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800D0D20(void);
	#if OOT_DEBUG
		asm("external_func_800D0D20 = 0x800D0D20");
	#elif OOT_U_1_0
		asm("external_func_800D0D20 = 0x800AAB94");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800D0ED4(void);
	#if OOT_DEBUG
		asm("external_func_800D0ED4 = 0x800D0ED4");
	#elif OOT_U_1_0
		asm("external_func_800D0ED4 = 0x800AAD4C");
	#endif

/**
 * Create/Apply x,y,z rotation transformation on Float Matrix Stack
 * TODO These notes need converted into a C function prototype
 * A0 = u16 x rotation | A1 = u16 y rotation | A2 = u16 z rotation | A3 = 0 initializes new matrix, 1 transforms stored matrix
 */
extern void external_func_800D1084(void);
	#if OOT_DEBUG
		asm("external_func_800D1084 = 0x800D1084");
	#elif OOT_U_1_0
		asm("external_func_800D1084 = 0x800AAF00");
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
 * F12 = float x | F14 = float y | A2 = float z | A3 = ptr to u16 rotation
 */
extern void external_func_800D1694(void);
	#if OOT_DEBUG
		asm("external_func_800D1694 = 0x800D1694");
	#elif OOT_U_1_0
		asm("external_func_800D1694 = 0x800AB510");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800D1840(void);
	#if OOT_DEBUG
		asm("external_func_800D1840 = 0x800D1840");
	#elif OOT_U_1_0
		// TODO Needs 1.0 equivalent!
	#endif

/**
 * Converts the Top in the Float Matrix Stack to a fixed point matrix
 * TODO These notes need converted into a C function prototype
 * A0 = Destination for the Fixed Point Matrix
 */
extern void external_func_800D1A54(void);
	#if OOT_DEBUG
		asm("external_func_800D1A54 = 0x800D1A54");
	#elif OOT_U_1_0
		asm("external_func_800D1A54 = 0x800AB8D8");
	#endif

/**
 * Converts and Appends the Float Matrix Stack's top matrix to POLY_OPA_DISP end
 * TODO additional arguments `u8 source, u8 line` are debug rom only; does it work fine on 1.0 if we leave them enabled?
 */
extern void matrix_alloc(u32 gfx_ctx, u8 source, u8 line);
	#if OOT_DEBUG
		asm("matrix_alloc = 0x800D1A88");
	#elif OOT_U_1_0
		asm("matrix_alloc = 0x800AB900");
	#endif

/**
 * Multiply Float Matrix Stack's top matrix by float Vector3
 * TODO These notes need converted into a C function prototype
 * A0 = ptr to Vector3 | A1 = ptr to result
 */
extern void external_func_800D1AF4(void);
	#if OOT_DEBUG
		asm("external_func_800D1AF4 = 0x800D1AF4");
	#elif OOT_U_1_0
		asm("external_func_800D1AF4 = 0x800AB958");
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
 * TODO This function is completely undocumented
 */
extern void external_func_800D1FD4(void);
	#if OOT_DEBUG
		asm("external_func_800D1FD4 = 0x800D1FD4");
	#elif OOT_U_1_0
		// TODO Needs 1.0 equivalent!
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_800D20CC(void);
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
 * Sound? Set u8 80121DFC to A0, u8 80121DFE to 1
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
 * Zero u32? 8010195C
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
extern void sound_play_general(u16 sound_id);
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
extern void sound_set_bgm(u8 music_id);
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
 * set debug text color
 * TODO We need argument mapping
 * This function is not used inside any existing overlay
 */
extern void debug_set_text_rgba(void);
	#if OOT_DEBUG
		asm("debug_set_text_rgba = 0x800FB3AC");
	#elif OOT_U_1_0
		asm("debug_set_text_rgba = 0x800CBE58");
	#endif

/**
 * set debug text coordinates
 * TODO We need argument mapping
 * This function is not used inside any existing overlay
 */
extern void debug_set_text_xy(void);
	#if OOT_DEBUG
		asm("debug_set_text_xy = 0x800FB41C");
	#elif OOT_U_1_0
		asm("debug_set_text_xy = 0x800CBEC8");
	#endif

/**
 * TODO This function is completely undocumented
 * This function is not used inside any existing overlay
 */
extern void external_func_800FBB8C(void);
	#if OOT_DEBUG
		asm("external_func_800FBB8C = 0x800FBB8C");
	#elif OOT_U_1_0
		asm("external_func_800FBB8C = 0x800CC4AC");
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
 * TODO These notes need converted into a C function prototype
 * This function is not used inside any existing overlay
 */
extern void external_func_800FBC1C(void);
	#if OOT_DEBUG
		asm("external_func_800FBC1C = 0x800FBC1C");
	#elif OOT_U_1_0
		asm("external_func_800FBC1C = 0x800CC508");
	#endif

/**
 * TODO This function is completely undocumented
 * This function is not used inside any existing overlay
 */
extern void external_func_800FBC64(void);
	#if OOT_DEBUG
		asm("external_func_800FBC64 = 0x800FBC64");
	#elif OOT_U_1_0
		asm("external_func_800FBC64 = 0x800CC550");
	#endif

/**
 * set debug text string
 * TODO We need argument mapping
 * This function is not used inside any existing overlay
 */
extern void debug_set_text_string(void);
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
 * TODO This function is completely undocumented
 */
extern void external_func_800FD250(void);
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
extern f32 math_rand_zero_one(void);
	#if OOT_DEBUG
		asm("math_rand_zero_one = 0x800FD9AC");
	#elif OOT_U_1_0
		asm("math_rand_zero_one = 0x800CDCCC");
	#endif

/**
 * padding between this and prev func
 * TODO These notes need converted into a C function prototype
 */
extern void external_func_80100290(void);
	#if OOT_DEBUG
		asm("external_func_80100290 = 0x80100290");
	#elif OOT_U_1_0
		asm("external_func_80100290 = 0x800CF470");
	#endif

/**
 * TODO This function is completely undocumented
 */
extern void external_func_80104610(void);
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
 * ? Dialog Related, potentially confirm yes/no
 * TODO These notes need converted into a C function prototype
 * V0 = result?
 */
extern void external_func_80106BC8(void);
	#if OOT_DEBUG
		asm("external_func_80106BC8 = 0x80106BC8");
	#elif OOT_U_1_0
		asm("external_func_80106BC8 = 0x800D6110");
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
 * Message display-related
 * TODO These notes need converted into a C function prototype
 * a1 = Text ID
 */
extern void external_func_8010B680(void);
	#if OOT_DEBUG
		asm("external_func_8010B680 = 0x8010B680");
	#elif OOT_U_1_0
		asm("external_func_8010B680 = 0x800DCE14");
	#endif

/**
 * Dialog yes/no response?
 * TODO These notes need converted into a C function prototype
 * a1 = Response Text ID
 */
extern void external_func_8010B720(void);
	#if OOT_DEBUG
		asm("external_func_8010B720 = 0x8010B720");
	#elif OOT_U_1_0
		asm("external_func_8010B720 = 0x800DCE80");
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
extern u32 player_talk_state(u32 global_context);
	#if OOT_DEBUG
		asm("player_talk_state = 0x8010BDBC");
	#elif OOT_U_1_0
		asm("player_talk_state = 0x800DD464");
	#endif

#endif // __Z64OVL_H__
