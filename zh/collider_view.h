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

static void zh_collider_draw_cylinder(z64_global_t* gl, Gfx** p_gfx_p, Gfx** p_gfx_d, float x, float y, float z, int radius, int height)
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
    gSPDisplayList((*p_gfx_p)++, dl_cylinder);
    gSPPopMatrix((*p_gfx_p)++, G_MTX_MODELVIEW);
}

static void zh_collider_draw(z64_global_t* gl, z64_collider_t* col)
{
    z64_disp_buf_t* xlu = &ZQDL(gl, poly_xlu);
    Gfx** p_gfx_p = &xlu->p;
    Gfx** p_gfx_d = &xlu->d;

    switch(col->shape)
    {
        case COL_SHAPE_JNTSPH: // Spheres
            //TODO
            break;
        case COL_SHAPE_CYLINDER: {
            z64_collider_cylinder_t* cyl = (z64_collider_cylinder_t*)col;
            // Make cylinders with 0 radius appear very small.
            int radius = cyl->dim.radius;
            if (radius == 0) radius = 1;

            zh_collider_draw_cylinder(
                gl, p_gfx_p, p_gfx_d
                , cyl->dim.pos.x, cyl->dim.pos.y + cyl->dim.y_shift, cyl->dim.pos.z
                , radius, cyl->dim.height
            );
            break;
        }
        case COL_SHAPE_TRIS:
            //TODO
            break;
        case COL_SHAPE_QUAD:
            //TODO
            break;
    }
}
#endif /* !ZH_COLLIDER_VIEW */
