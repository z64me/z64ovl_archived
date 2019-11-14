/**
 * va_arr.h  <z64.me>
 * a hackish solution for creating variadic functions
 * on platforms where stdarg.h is not present;
 * see sprintf.h for a usage example
 **/

#ifndef VA_ARR_H_INCLUDED
#define VA_ARR_H_INCLUDED

struct va_arr {
	void *v;
};

#define VA_NUM_ARGS_IMPL(  \
      _1,  _2,  _3,  _4    \
   ,  _5,  _6,  _7,  _8    \
   ,  _9, _10, _11, _12    \
   , _13, _14, _15, _16    \
   , N                     \
   , ...                   \
) N

#define VA_NUM_ARGS(...)                         \
   VA_NUM_ARGS_IMPL(__VA_ARGS__, 16, 15, 14, 13  \
                               , 12, 11, 10, 9   \
                               ,  8,  7,  6, 5   \
                               ,  4,  3,  2, 1   \
   )

/* like VA_ARR, but stores count as first item */
#define VA_ARR_COUNT(...)                       \
   (struct va_arr[])                            \
   {(VA_NUM_ARGS(__VA_ARGS__)), __VA_ARGS__}

/* constructs an va_arr array (max 16 values)  */
#define VA_ARR(...)                             \
   (struct va_arr[])                            \
   {__VA_ARGS__}

#define VA_ARR_CONST_TYPE(t, v) &(t){v}

/* use these to provide inline constants instead of variables */
#define VA_ARR_s(x) x
#define VA_ARR_d(x) VA_ARR_CONST_TYPE(int  , x)
#define VA_ARR_f(x) VA_ARR_CONST_TYPE(float, x)
#define VA_ARR_c(x) VA_ARR_CONST_TYPE(char , x)

#endif /* VA_ARR_H_INCLUDED */
