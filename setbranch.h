#ifndef _Z64OVL_SETBRANCH_H_INCLUDED_
#define _Z64OVL_SETBRANCH_H_INCLUDED_

/****
 * setbranch.h
 * not to be confused with setjmp.h from
 * the standard C library
 ***/

// defines a label
#define setbranch(SBLABELNAME) \
	asm(                       \
		"."SBLABELNAME": \n"   \
	)

// branches to a label, even across functions
#define longbranch(SBLABELNAME) \
	asm(                        \
		"b  ."SBLABELNAME" \n"  \
		"nop               \n"  \
	)

#endif /* _Z64OVL_SETBRANCH_H_INCLUDED_ */
