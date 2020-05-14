#ifndef VEC3S_H

#ifndef __Z64OVL_H__
#error "you cannot #include <z64ovl/zh/vec3s.h> before z64ovl itself"
#endif

#define VEC3S_H

#define PI 3.141592653589f
#define TAU (PI * 2.f)
#define HPI (PI * 0.5f)

#define DEG2RAD 0.017453292f
#define RAD2DEG 57.29578049f
#define S2RAD (PI / 32768.f)
#define S2DEG (180.f / 32768.f)
#define RAD2S (32768.f / PI)
#define DEG2S (32768.f / 180.f)

#define STOR(RHS) (S2RAD * RHS)
#define STOD(RHS) (S2DEG * RHS)
#define RTOS(RHS) (RAD2S * RHS)
#define DTOS(RHS) (DEG2S * RHS)
#define DTOR(RHS) (DEG2RAD * RHS)
#define RTOD(RHS) (RAD2DEG * RHS)

/*typedef struct {
    int16_t x;
    int16_t y;
    int16_t z;
} vec3s_t, z64_rot_t, z64_point_t, z64_xyz_t;*/

/*TODO: How to safely add to the generic?*/
static inline vec3s_t vec3s_new_v(void) {
    return (vec3s_t){0, 0, 0};
}

static inline vec3s_t vec3s_new_s(int16_t x, int16_t y, int16_t z) {
    return (vec3s_t){x, y, z};
}

static inline vec3s_t vec3s_new_v3(const vec3s_t rhs) {
    return rhs;
}

const vec3s_t vec3s_zero        = (vec3s_t) {0, 0, 0};
const vec3s_t vec3s_right       = (vec3s_t) {1, 0, 0};
const vec3s_t vec3s_up          = (vec3s_t) {0, 1, 0};
const vec3s_t vec3s_forward     = (vec3s_t) {0, 0, 1};
const vec3s_t vec3s_left        = (vec3s_t){-1, 0, 0};
const vec3s_t vec3s_down        = (vec3s_t){0, -1, 0};
const vec3s_t vec3s_backward    = (vec3s_t){0, 0, -1};

#define vec3s_new(_a0, ...) \
_Generic((_a0),             \
    int16_t: vec3s_new_s,     \
    vec3s_t: vec3s_new_v3   \
)(_a0 __VA_OPT__(,) __VA_ARGS__)

static inline vec3s_t vec3s_add(vec3s_t lhs, vec3s_t rhs) {
    lhs.x += rhs.x;
    lhs.y += rhs.y;
    lhs.z += rhs.z;
    return lhs;
}

static inline vec3s_t vec3s_sub(vec3s_t lhs, vec3s_t rhs) {
    lhs.x -= rhs.x;
    lhs.y -= rhs.y;
    lhs.z -= rhs.z;
    return lhs;
}

static inline vec3s_t vec3s_mul_f(vec3s_t lhs, float rhs) {
    lhs.x *= rhs;
    lhs.y *= rhs;
    lhs.z *= rhs;
    return lhs;
}

static inline vec3s_t vec3s_mul_s(vec3s_t lhs, int16_t rhs) {
    lhs.x *= rhs;
    lhs.y *= rhs;
    lhs.z *= rhs;
    return lhs;
}

static inline vec3s_t vec3s_mul_v3(vec3s_t lhs, vec3s_t rhs) {
    lhs.x *= rhs.x;
    lhs.y *= rhs.y;
    lhs.z *= rhs.z;
    return lhs;
}

#define vec3s_mul(_a0, _a1) \
_Generic((_a1),             \
    vec3s_t: vec3s_mul_v3,  \
    int16_t: vec3s_mul_s,     \
    default: vec3s_mul_f    \
)(_a0, _a1)

/* TODO benchmark me */
static inline vec3s_t vec3s_div_f(vec3s_t lhs, float rhs)
{
    if (rhs == 0) return vec3s_zero;
    float recip = 1.0f / rhs;

    lhs.x *= recip;
    lhs.y *= recip;
    lhs.z *= recip;

    return lhs;
}

static inline vec3s_t vec3s_div_s(vec3s_t lhs, int16_t rhs)
{
    if (rhs == 0) return vec3s_zero;

    lhs.x /= rhs;
    lhs.y /= rhs;
    lhs.z /= rhs;

    return lhs;
}

/* TODO benchmark me */
static inline vec3s_t vec3s_div_v3(vec3s_t lhs, vec3s_t rhs) {
    if (lhs.x == 0 || rhs.x == 0) lhs.x = 0;
    else lhs.x /= rhs.x;
    
    if (lhs.y == 0 || rhs.y == 0) lhs.y = 0;
    else lhs.y /= rhs.y;
    
    if (lhs.z == 0 || rhs.z == 0) lhs.z = 0;
    else lhs.z /= rhs.z;

    return lhs;
}

#define vec3s_div(_a0, _a1) \
_Generic((_a1),             \
    vec3s_t: vec3s_div_v3,  \
    int16_t: vec3_div_s,      \
    default: vec3s_div_f    \
)(_a0, _a1)

static inline float vec3s_magnitude(vec3s_t lhs) {
    return z_sqrt(lhs.x * lhs.x + lhs.y * lhs.y + lhs.z * lhs.z);
}

static inline vec3s_t vec3s_normalize(vec3s_t lhs) {
    float l = vec3s_magnitude(lhs);
    if (l == 0) return vec3s_zero;
    return vec3s_div_f(lhs, l);
}

static inline vec3s_t vec3s_inverse(vec3s_t lhs) {
    return vec3s_new_s(-lhs.x, -lhs.y, -lhs.z);
}

static inline vec3s_t vec3s_cross(vec3s_t lhs, vec3s_t rhs) {
    return vec3s_new_s(
        lhs.y * rhs.z - rhs.y * lhs.z,
        lhs.z * rhs.x - rhs.z * lhs.x,
        lhs.x * rhs.y - rhs.x * lhs.y
    );
}

static inline float vec3s_dot(vec3s_t lhs, vec3s_t rhs) {
    return (lhs.x * rhs.x) + (lhs.y * rhs.y) + (lhs.z * rhs.z);
}

/* TODO benchmark me */
static inline uint32_t vec3s_is_empty(vec3s_t lhs) {
    return *(uint32_t*)(&lhs.x) | *(uint32_t*)(&lhs.y) | *(uint32_t*)(&lhs.z);
}

vec3s_t vec3s_toDeg(vec3s_t lhs) {
    return vec3s_mul_f(lhs, S2DEG);
}

/*
Perhaps we should include vec3s and return that for this?
vec3s_t vec3s_toRad(vec3s_t lhs) {
    return vec3s_mul(lhs, S2RAD);
}*/

#endif

