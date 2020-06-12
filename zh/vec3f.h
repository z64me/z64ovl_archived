#ifndef VEC3_H

#ifndef __Z64OVL_H__
#error "you cannot #include <z64ovl/zh/vec3f.h> before z64ovl itself"
#endif

#define VEC3_H

/*typedef struct {
    float x;
    float y;
    float z;
} vec3f_t, z64_xyzf_t;*/

/*TODO: How to safely add to the generic?*/
static inline vec3f_t vec3f_new_v(void) {
    return (vec3f_t){0, 0, 0};
}

static inline vec3f_t vec3f_new_f(float x, float y, float z) {
    return (vec3f_t){x, y, z};
}

static inline vec3f_t vec3f_new_v3(const vec3f_t rhs) {
    return rhs;
}

static const vec3f_t vec3f_zero        = (vec3f_t) {0, 0, 0};
static const vec3f_t vec3f_right       = (vec3f_t) {1, 0, 0};
static const vec3f_t vec3f_up          = (vec3f_t) {0, 1, 0};
static const vec3f_t vec3f_forward     = (vec3f_t) {0, 0, 1};
static const vec3f_t vec3f_left        = (vec3f_t){-1, 0, 0};
static const vec3f_t vec3f_down        = (vec3f_t){0, -1, 0};
static const vec3f_t vec3f_backward    = (vec3f_t){0, 0, -1};

#define vec3f_new(_a0, ...)  \
_Generic((_a0),             \
    int: vec3f_new_f,        \
    uint32_t: vec3f_new_f,   \
    float: vec3f_new_f,      \
    double: vec3f_new_f,     \
    vec3f_t: vec3f_new_v3    \
)(_a0 __VA_OPT__(,) __VA_ARGS__)

static inline vec3f_t vec3f_add(vec3f_t lhs, vec3f_t rhs) {
    lhs.x += rhs.x;
    lhs.y += rhs.y;
    lhs.z += rhs.z;
    return lhs;
}

static inline vec3f_t vec3f_sub(vec3f_t lhs, vec3f_t rhs) {
    lhs.x -= rhs.x;
    lhs.y -= rhs.y;
    lhs.z -= rhs.z;
    return lhs;
}

static inline vec3f_t vec3f_mul_f(vec3f_t lhs, float rhs) {
    lhs.x *= rhs;
    lhs.y *= rhs;
    lhs.z *= rhs;
    return lhs;
}

static inline vec3f_t vec3f_mul_v3(vec3f_t lhs, vec3f_t rhs) {
    lhs.x *= rhs.x;
    lhs.y *= rhs.y;
    lhs.z *= rhs.z;
    return lhs;
}

#define vec3f_mul(_a0, _a1) \
_Generic((_a1),             \
    vec3f_t: vec3f_mul_v3,  \
    default: vec3f_mul_f    \
)(_a0, _a1)

/* TODO benchmark me */
static inline vec3f_t vec3f_div_f(vec3f_t lhs, float rhs)
{
    if (rhs == 0) return vec3f_zero;
    float recip = 1.0f / rhs;

    lhs.x *= recip;
    lhs.y *= recip;
    lhs.z *= recip;

    return lhs;
}

/* TODO benchmark me */
static inline vec3f_t vec3f_div_v3(vec3f_t lhs, vec3f_t rhs) {
    if (lhs.x == 0 || rhs.x == 0) lhs.x = 0;
    else lhs.x /= rhs.x;
    
    if (lhs.y == 0 || rhs.y == 0) lhs.y = 0;
    else lhs.y /= rhs.y;
    
    if (lhs.z == 0 || rhs.z == 0) lhs.z = 0;
    else lhs.z /= rhs.z;

    return lhs;
}

#define vec3f_div(_a0, _a1)  \
_Generic((_a1),             \
    vec3f_t: vec3f_div_v3,   \
    default: vec3f_div_f     \
)(_a0, _a1)

static inline float vec3f_magnitude(vec3f_t lhs) {
    return z_sqrt(lhs.x * lhs.x + lhs.y * lhs.y + lhs.z * lhs.z);
}

static inline vec3f_t vec3f_normalize(vec3f_t lhs) {
    float l = vec3f_magnitude(lhs);
    if (l == 0) return vec3f_zero;
    return vec3f_div(lhs, l);
}

static inline vec3f_t vec3f_inverse(vec3f_t lhs) {
    return vec3f_new_f(-lhs.x, -lhs.y, -lhs.z);
}

static inline vec3f_t vec3f_cross(vec3f_t lhs, vec3f_t rhs) {
    return vec3f_new_f(
        lhs.y * rhs.z - rhs.y * lhs.z,
        lhs.z * rhs.x - rhs.z * lhs.x,
        lhs.x * rhs.y - rhs.x * lhs.y
    );
}

static inline float vec3f_dot(vec3f_t lhs, vec3f_t rhs) {
    return (lhs.x * rhs.x) + (lhs.y * rhs.y) + (lhs.z * rhs.z);
}

/* TODO benchmark me */
static inline uint32_t vec3f_is_empty(vec3f_t lhs) {
    return !(*(uint32_t*)(&lhs.x) || *(uint32_t*)(&lhs.y) || *(uint32_t*)(&lhs.z));
}

#define vec3f_is_zero vec3f_is_empty

#endif


