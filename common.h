#ifndef __Z64OVL_H__
#error "common.h" must not be #included before z64_functions.h!
#endif

#ifndef __Z64OVL_COMMON_H__
#define __Z64OVL_COMMON_H__

enum mtxmod
{
	MTXMOD_NEW = 0      /* creates new matrix */
	, MTXMOD_APPLY = 1  /* applies transformation to active matrix */
};

#endif /* __Z64OVL_COMMON_H__ */
