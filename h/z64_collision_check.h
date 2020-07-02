#ifndef Z64_COLLISION_CHECK_H_INCLUDED
#define Z64_COLLISION_CHECK_H_INCLUDED

#define HEARTS(HA0) ((uint8_t)(((float)HA0) * 16.0))

typedef enum z64_damage_fx_e {
    DMG_FX_KNOCKBACK
    , DMG_FX_FIRE
    , DMG_FX_ICE
    , DMG_FX_ELECTRIC
} z64_damage_fx_t;

typedef struct z64_collider_s {
    z64_actor_t * actor;
    z64_actor_t * at; /* Actor collided with in AT pool */
    z64_actor_t * ac; /* Actor collided with in AC pool */
    z64_actor_t * oc; /* Actor collided with in OC pool */
    uint8_t flags_at; /* Compared to flags_ac */
    uint8_t flags_ac; /* Compared to flags_at */
    uint8_t mask_a; /* Bitwise-AND compared to mask_b */
    uint8_t mask_b; /* Bitwise-AND compared to mask_a */
    uint8_t type; /* z64_collider_type_t */
    uint8_t shape; /* z64_collider_shape_t */
} z64_collider_t;

typedef struct z64_collider_touch_s {
    int32_t flags;
    uint8_t effect; /* Damage Special FX */
    uint8_t damage; /* Damage Amount / Stun Timer */
} z64_collider_touch_t;

typedef struct z64_collider_bump_init_s {
    int32_t flags; /* Collision Exclusion Mask */
    uint8_t effect; /* Damage Special FX */
    uint8_t defense; /* Damage Resistance */
} z64_collider_bump_init_t;

typedef struct z64_collider_body_init_s {
    uint8_t flags_body;
    z64_collider_touch_t toucher;
    z64_collider_bump_init_t bumper;
    uint8_t flags_toucher;
    uint8_t flags_bumper;
    uint8_t flags_body_2;
} z64_collider_body_init_t;

typedef struct z64_collider_bump_s {
    int32_t flags; /* Collision Exclusion Mask */
    uint8_t effect; /* Damage Special FX */
    uint8_t defense; /* Damage Resistance */
    vec3s_t unk_0x06;
} z64_collider_bump_t;

typedef struct z64_collider_body_s z64_collider_body_t;
struct z64_collider_body_s {
    z64_collider_touch_t toucher;
    z64_collider_bump_t bumper;
    uint8_t flags; /* Affects SFX? */
    uint8_t flags_toucher;
    uint8_t flags_bumper;
    uint8_t flags_oc;
    z64_collider_t * hit_at; /* Object touching this AT Collider */
    z64_collider_t * hit_ac; /* Object touching this AC Collider */
    z64_collider_body_t * hit_item_at; /* Element that hit the AT Collider */
    z64_collider_body_t * hit_item_ac; /* Element that hit the AC Collider */
};

typedef struct z64_collider_init_actor_s {
    z64_actor_t * actor;
    uint8_t flags_at;
    uint8_t flags_ac;
    uint8_t mask_a;
    uint8_t shape;
} z64_collider_init_actor_t;

typedef struct z64_cylinder16_s {
    int16_t radius;
    int16_t height;
    int16_t y_shift;
    vec3s_t pos;
} z64_cylinder16_t;

typedef struct z64_collider_cylinder_init_actor_s {
    z64_collider_init_actor_t base;
    z64_collider_body_init_t body;
    z64_cylinder16_t dim;
} z64_collider_cylinder_init_actor_t;

typedef struct z64_collider_init_set3_s {
    uint8_t type;
    uint8_t flags_at;
    uint8_t flags_ac;
    uint8_t mask_a;
    uint8_t shape;
} z64_collider_init_set3_t;

typedef struct z64_collider_cylinder_init_set3_s {
    z64_collider_init_set3_t base;
    z64_collider_body_init_t body;
    z64_cylinder16_t dim;
} z64_collider_cylinder_init_set3_t;

typedef struct z64_collider_init_s {
    uint8_t type;
    uint8_t flags_at;
    uint8_t flags_ac;
    uint8_t mask_a;
    uint8_t mask_b;
    uint8_t shape; /* z64_collider_shape_t */
} z64_collider_init_t;

typedef struct z64_collider_cylinder_init_s {
    z64_collider_init_t base;
    z64_collider_body_init_t body;
    z64_cylinder16_t dim;
} z64_collider_cylinder_init_t;

typedef struct z64_collider_cylinder_s {
    z64_collider_t base;
    z64_collider_body_t body;
    z64_cylinder16_t dim;
} z64_collider_cylinder_t;

typedef struct z64_sphere16_s {
    vec3s_t center;
    int16_t radius;
} z64_sphere16_t;

typedef struct z64_collider_jntsph_item_dim_s {
    z64_sphere16_t sphere_model;
    z64_sphere16_t sphere_world;
    float scale;
    uint8_t joint;
} z64_collider_jntsph_item_dim_t;

typedef struct z64_collider_jntsph_item_s {
    z64_collider_body_t body; /* Body */
    z64_collider_jntsph_item_dim_t dim; /* Dimensions */
} z64_collider_jntsph_item_t;

typedef struct z64_collider_jntsph_s {
    z64_collider_t base;
    int32_t count;
    z64_collider_jntsph_item_t * list;
} z64_collider_jntsph_t;

typedef struct z64_collider_jntsph_item_dim_init_s {
    uint8_t joint;
    z64_sphere16_t sphere_model;
    int16_t scale;
} z64_collider_jntsph_item_dim_init_t;

typedef struct z64_collider_jntsph_item_init_s {
    z64_collider_body_init_t body; /* Body */
    z64_collider_jntsph_item_dim_init_t dim; /* Dimensions */
} z64_collider_jntsph_item_init_t;

typedef struct z64_collider_jntsph_init_actor_s {
    z64_collider_init_actor_t base;
    int32_t count;
    z64_collider_jntsph_item_init_t * list;
} z64_collider_jntsph_init_actor_t;

typedef struct z64_collider_jntsph_init_set3_s {
    z64_collider_init_set3_t base;
    int32_t count;
    z64_collider_jntsph_item_init_t * list;
} z64_collider_jntsph_init_set3_t;

typedef struct z64_collider_jntsph_init_s {
    z64_collider_init_t base;
    int32_t count;
    z64_collider_jntsph_item_init_t * list;
} z64_collider_jntsph_init_t;

typedef struct z64_collider_quad_dim_init_s {
    vec3f_t quad[4];
} z64_collider_quad_dim_init_t;

typedef struct z64_collider_quad_dim_s {
    vec3f_t quad[4];
    vec3s_t dc_mid; /* Midpoint of D and C */
    vec3s_t ba_mid; /* Midpoint of B and A */
    float unk_0x3C;
} z64_collider_quad_dim_t;

typedef struct z64_collider_quad_init_set3_s {
    z64_collider_init_set3_t base;
    z64_collider_body_init_t body;
    z64_collider_quad_dim_init_t dim;
} z64_collider_quad_init_set3_t;

typedef struct z64_collider_quad_init_s {
    z64_collider_init_t base;
    z64_collider_body_init_t body;
    z64_collider_quad_dim_init_t dim;
} z64_collider_quad_init_t;

typedef struct z64_collider_quad_s {
    z64_collider_t base;
    z64_collider_body_t body;
    z64_collider_quad_dim_t dim;
} z64_collider_quad_t;

typedef enum z64_collider_shape_e {
    COL_SHAPE_CYLINDER=1,
    COL_SHAPE_INVALID=4,
    COL_SHAPE_JNTSPH=0,
    COL_SHAPE_QUAD=3,
    COL_SHAPE_TRIS=2
} z64_collider_shape_t;

typedef struct z64_collider_tris_item_dim_init_s {
    vec3f_t vtx[3];
} z64_collider_tris_item_dim_init_t;

typedef struct z64_collider_tris_item_init_s {
    z64_collider_body_init_t body;
    z64_collider_tris_item_dim_init_t dim;
} z64_collider_tris_item_init_t;

typedef struct z64_collider_tris_init_set3_s {
    z64_collider_init_set3_t base;
    int32_t count;
    z64_collider_tris_item_init_t * list;
} z64_collider_tris_init_set3_t;

typedef struct z64_collider_tris_init_s {
    z64_collider_init_t base;
    int32_t count;
    z64_collider_tris_item_init_t * list;
} z64_collider_tris_init_t;

typedef struct z64_plane_s {
    vec3f_t normal;
    float origin_dist;
} z64_plane_t;

typedef struct z64_tri_norm_s {
    vec3f_t vtx[3];
    z64_plane_t plane;
} z64_tri_norm_t;

typedef struct z64_collider_tris_item_s {
    z64_collider_body_t body;
    z64_tri_norm_t dim;
} z64_collider_tris_item_t;

typedef struct z64_collider_tris_s {
    z64_collider_t base;
    int32_t count;
    z64_collider_tris_item_t * list;
} z64_collider_tris_t;

typedef enum z64_collider_type_t {
    COL_TYPE_SHIELD_METAL=9,
    COL_TYPE_SHIELD_WOOD=11,
    COL_TYPE_UNK10=10,
    COL_TYPE_UNK0=0,
    COL_TYPE_UNK1=1,
    COL_TYPE_UNK12=12,
    COL_TYPE_UNK13=13,
    COL_TYPE_UNK2=2,
    COL_TYPE_UNK3=3,
    COL_TYPE_UNK4=4,
    COL_TYPE_UNK5=5,
    COL_TYPE_UNK6=6, // Gives a fleshy-sounding green-blooded hit effect.
    COL_TYPE_UNK7=7,
    COL_TYPE_UNK8=8
} z64_collider_type_t;

typedef struct z64_linef_s {
    vec3f_t a;
    vec3f_t b;
} z64_linef_t;

typedef struct z64_ocline_s {
    z64_linef_t line;
    uint16_t unk_0x18;
} z64_ocline_t;
#endif /* Z64_COLLISION_CHECK_H_INCLUDED */
