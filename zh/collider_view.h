#ifndef ZH_COLLIDER_VIEW
#define ZH_COLLIDER_VIEW

#include "matrix.h"
#include "collider_view/cv_geometry.h"
#define sin z_sins
#define cos z_coss
#define sinf z_sinf
#define cosf z_cosf
#define sqrtf z_sqrt
#define floorf z_floorf
#define memcpy(A,B,C) z_bcopy(B,A,C)
#define guTranslateF libultra_guTranslateF
#define guScaleF libultra_guScaleF
#define guMtxCatF libulutra_guMtxCatF
#define guRotateRPYF libultra_guRotateRPYF
#define M_PI 3.14159265358979323846

/* Adapted from gz */
/*static void gz_tri_norm(vec3f_t* v1, vec3f_t* v2, vec3f_t* v3, vec3f_t* norm)
{
    norm->x = (v2->y - v1->y) * (v3->z - v1->z) - (v2->z - v1->z) * (v3->y - v1->y);
    norm->y = (v2->z - v1->z) * (v3->x - v1->x) - (v2->x - v1->x) * (v3->z - v1->z);
    norm->z = (v2->x - v1->x) * (v3->y - v1->y) - (v2->y - v1->y) * (v3->x - v1->x);
    float norm_d = sqrtf(norm->x * norm->x + norm->y * norm->y + norm->z * norm->z);

    if (norm_d != 0.0f)
    {
        norm->x *= 127.0f / norm_d;
        norm->y *= 127.0f / norm_d;
        norm->z *= 127.0f / norm_d;
    }
}

static void gz_draw_tri(Gfx** p_gfx_p, Gfx** p_gfx_d, vec3f_t* v1, vec3f_t* v2, vec3f_t* v3)
{
    vec3f_t norm;
    gz_tri_norm(v1, v2, v3, &norm);

    Vtx v[3] = {
        gdSPDefVtxN(v1->x, v1->y, v1->z, 0, 0, norm.x, norm.y, norm.z, 255)
        , gdSPDefVtxN(v1->x, v1->y, v1->z, 0, 0, norm.x, norm.y, norm.z, 255)
        , gdSPDefVtxN(v1->x, v1->y, v1->z, 0, 0, norm.x, norm.y, norm.z, 255)
    };

    gSPVertex((*p_gfx_p)++, gDisplayListData(p_gfx_d, v), 3, 0);
    gSP1Triangle((*p_gfx_p)++, 0, 1, 2, 0);
}

static void gz_draw_quad(Gfx **p_gfx_p, Gfx **p_gfx_d, z64_xyzf_t *v1, z64_xyzf_t *v2, z64_xyzf_t *v3, z64_xyzf_t *v4)
{
  z64_xyzf_t norm;
  tri_norm(v1, v2, v4, &norm);

  Vtx v[4] = {
    gdSPDefVtxN(v1->x, v1->y, v1->z, 0, 0, norm.x, norm.y, norm.z, 255),
    gdSPDefVtxN(v2->x, v2->y, v2->z, 0, 0, norm.x, norm.y, norm.z, 255),
    gdSPDefVtxN(v3->x, v3->y, v3->z, 0, 0, norm.x, norm.y, norm.z, 255),
    gdSPDefVtxN(v4->x, v4->y, v4->z, 0, 0, norm.x, norm.y, norm.z, 255)
  };

  gSPVertex((*p_gfx_p)++, gDisplayListData(p_gfx_d, v), 4, 0);
  gSP2Triangles((*p_gfx_p)++, 0, 1, 2, 0, 0, 2, 3, 0);
}*/

static void zh_draw_sphere(z64_global_t* gl, Gfx** p_gfx_p, Gfx** p_gfx_d, float x, float y, float z, int radius, uint32_t env_color)
{
    Mtx m;
    {
        float mf[4][4];
        float ms[4][4];
        guTranslateF(mf, x, y, z);
        guScaleF(ms, radius / 128.0f, radius / 128.0f, radius / 128.0f);
        guMtxCatF(ms, mf, mf);
        guMtxF2L(mf, &m);
    }
    Mtx* mtx = z_matrix_alloc((gl->common).gfx_ctxt, "");
    z_bcopy(&m, (void*)mtx, 0x40);
    gSPMatrix((*p_gfx_p)++, mtx, G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_PUSH);
    gSPDisplayList((*p_gfx_p)++, xlu_material);
    gDPSetEnvColor((*p_gfx_p)++, RED32(env_color), GREEN32(env_color), BLUE32(env_color), ALPHA32(env_color));
    gSPDisplayList((*p_gfx_p)++, dl_sphere);
    gSPPopMatrix((*p_gfx_p)++, G_MTX_MODELVIEW);
}

static void zh_draw_cylinder(z64_global_t* gl, Gfx** p_gfx_p, Gfx** p_gfx_d, float x, float y, float z, int radius, int height, uint32_t env_color)
{
    Mtx m;
    {
        float mf[4][4];
        float ms[4][4];
        guTranslateF(mf, x, y, z);
        guScaleF(ms, radius / 128.0f, height / 204.0f, radius / 128.0f);
        guMtxCatF(ms, mf, mf);
        guMtxF2L(mf, &m);
    }
    Mtx* mtx = z_matrix_alloc((gl->common).gfx_ctxt, "");
    z_bcopy(&m, (void*)mtx, 0x40);
    gSPMatrix((*p_gfx_p)++, mtx, G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_PUSH);
    gSPDisplayList((*p_gfx_p)++, xlu_material);
    gDPSetEnvColor((*p_gfx_p)++, RED32(env_color), GREEN32(env_color), BLUE32(env_color), ALPHA32(env_color));
    gSPDisplayList((*p_gfx_p)++, dl_cylinder);
    gSPPopMatrix((*p_gfx_p)++, G_MTX_MODELVIEW);
}

static void zh_collider_draw(z64_global_t* gl, z64_collider_t* col, uint32_t env_color)
{
    z64_disp_buf_t* xlu = &ZQDL(gl, poly_xlu);
    Gfx** p_gfx_p = &xlu->p;
    Gfx** p_gfx_d = &xlu->d;

    switch(col->shape)
    {
        case COL_SHAPE_JNTSPH: {// Spheres
            z64_collider_jntsph_t* sph = (z64_collider_jntsph_t*)col;
            
            for (int i = 0; i < sph->count; ++i)
            {
                z64_collider_jntsph_item_t* item = &sph->list[i];

                // Make spheres with 0 radius appear very small.
                int radius = (item->dim).sphere_world.radius;
                if (radius == 0) radius = 1;

                zh_draw_sphere(
                    gl, p_gfx_p, p_gfx_d
                    , (item->dim).sphere_world.center.x
                    , (item->dim).sphere_world.center.y
                    , (item->dim).sphere_world.center.z
                    , radius, env_color
                );
            }
            break;
        }
        case COL_SHAPE_CYLINDER: {
            z64_collider_cylinder_t* cyl = (z64_collider_cylinder_t*)col;
            // Make cylinders with 0 radius appear very small.
            int radius = (cyl->dim).radius;
            if (radius == 0) radius = 1;

            zh_draw_cylinder(
                gl, p_gfx_p, p_gfx_d
                , cyl->dim.pos.x, cyl->dim.pos.y + cyl->dim.y_shift, cyl->dim.pos.z
                , radius, cyl->dim.height, env_color
            );
            break;
        }
        case COL_SHAPE_TRIS: /*{
            z64_collider_tris_t* tris = (z64_collider_tris_t*)col;

            for (int j = 0; j < tris->count; ++j)
            {
                z64_collider_tris_item_t* item = &tris->list[j];
                gz_draw_tri(p_gfx_p, p_gfx_d, &item->dim.vtx[0], &item->dim.vtx[1], &item->dim.vtx[2]);
            }
            break;
        }*/
        break;
        case COL_SHAPE_QUAD: /*{
            z64_collider_quad_t* quad = (z64_collider_quad_t*)col;
            gz_draw_quad(p_gfx_p, p_gfx_d, &quad->dim.quad[0], &quad->dim.quad[2], &quad->dim.quad[3], &quad->dim.quad[1]);
            break;
        }*/
        break;
    }
}
#endif /* !ZH_COLLIDER_VIEW */
