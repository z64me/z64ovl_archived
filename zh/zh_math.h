#ifndef _ZH_MATH_
#define _ZH_MATH_

#define sins z_sins
#define sinf z_sinf
#define asinf z_asinf
#define coss z_coss
#define cosf z_cosf
#define acosf z_acosf
#define tanf z_tanf
#define atanf z_atanf
#define atan2f z_atan2f
#define absf z_fabs
#define modf z_fmod
#define floorf z_floorf
#define ceilf z_ceilf
#define roundf z_roundf
#define truncf z_truncf
#define randf z_math_frand

/* Generate a random floating point number between a lower bound and an upper bound. */
#define RAND_LOWER_UPPER(LOWER_BOUND, UPPER_BOUND) (float)(randf((UPPER_BOUND)-(LOWER_BOUND))+(LOWER_BOUND))

/* Generate a random floating point number between a lower bound and an upper bound. */
#define RANDF(L, U) RAND_LOWER_UPPER((L), (U))

/* Generate a random integer between a lower bound and an upper bound. */
#define RAND(L, U) roundf(RAND_LOWER_UPPER((L), (U)))

/* Macros for creating 3D vectors given a radius and pitch or yaw */
#define VECTOR3D_X(radius, yaw, pitch) (float)(radius)*sinf(DTOR((yaw)))*cosf(DTOR((pitch)))
#define VECTOR3D_Y(radius, pitch) (float)(radius)*sinf(DTOR((pitch)))
#define VECTOR3D_Z(radius, yaw, pitch) (float)(radius)*cosf(DTOR((yaw)))*cosf(DTOR((pitch)))

/*
* A function for creating or returning a vec3f_t given
* radius `r`, X Rotation `pitch`, and Y Rotation `yaw`.
* Evan20000
*/
static inline vec3f_t vec3f_point(float radius, float yaw, float pitch)
{
    vec3f_t _p = {
        .x = VECTOR3D_X(radius, yaw, pitch)
        , .y = VECTOR3D_Y(radius, pitch)
        , .z = VECTOR3D_Z(radius, yaw, pitch)
    };
    return _p;
}

#endif