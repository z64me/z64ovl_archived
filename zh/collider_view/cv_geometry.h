#ifndef ZH_COLLIDER_VIEW_GEOMETRY
#define ZH_COLLIDER_VIEW_GEOMETRY

/* translucent material */
static Gfx xlu_material[] = {
	gsSPTexture(qu016(0.999985), qu016(0.999985), 0, G_TX_RENDERTILE, G_OFF),
	gsDPPipeSync(),
	gsDPSetRenderMode(AA_EN | Z_CMP | Z_UPD | IM_RD | FORCE_BL | CVG_DST_CLAMP | ZMODE_XLU | CVG_X_ALPHA | ALPHA_CVG_SEL | GBL_c1(G_BL_CLR_FOG, G_BL_A_SHADE, G_BL_CLR_IN, G_BL_1MA), G_RM_AA_ZB_TEX_EDGE2),
	gsDPSetCombineLERP(
		0, 0, 0, ENVIRONMENT
		, 0, 0, 0, ENVIRONMENT
		, 0, 0, 0, COMBINED
		, 0, 0, 0, COMBINED
	),
	gsSPEndDisplayList()
};

/* Scale Factor is * 128 */
static Vtx v_cylinder[32] = {
	gdSPDefVtxN(0, 200, -100, 0, 0, 0, 190, 169, 255),
	gdSPDefVtxN(38, 0, -92, 0, 0, 71, 175, -170, 255),
	gdSPDefVtxN(0, 0, -100, 0, 0, 0, 190, -169, 255),
	gdSPDefVtxN(38, 200, -92, 0, 0, 71, 175, 170, 255),
	gdSPDefVtxN(71, 0, -71, 0, 0, 135, 135, -168, 255),
	gdSPDefVtxN(71, 200, -71, 0, 0, 135, 135, 168, 255),
	gdSPDefVtxN(92, 0, -38, 0, 0, 175, 71, -170, 255),
	gdSPDefVtxN(92, 200, -38, 0, 0, 175, 71, 170, 255),
	gdSPDefVtxN(100, 0, 0, 0, 0, 190, 0, -169, 255),
	gdSPDefVtxN(100, 200, 0, 0, 0, 190, 0, 169, 255),
	gdSPDefVtxN(92, 0, 38, 0, 0, 175, -71, -170, 255),
	gdSPDefVtxN(92, 200, 38, 0, 0, 175, -71, 170, 255),
	gdSPDefVtxN(71, 0, 71, 0, 0, 135, -135, -168, 255),
	gdSPDefVtxN(71, 200, 71, 0, 0, 135, -135, 168, 255),
	gdSPDefVtxN(38, 0, 92, 0, 0, 71, -175, -170, 255),
	gdSPDefVtxN(38, 200, 92, 0, 0, 71, -175, 170, 255),
	gdSPDefVtxN(0, 0, 100, 0, 0, 0, -190, -169, 255),
	gdSPDefVtxN(0, 200, 100, 0, 0, 0, -190, 169, 255),
	gdSPDefVtxN(-38, 0, 92, 0, 0, -71, -175, -170, 255),
	gdSPDefVtxN(-38, 200, 92, 0, 0, -71, -175, 170, 255),
	gdSPDefVtxN(-71, 0, 71, 0, 0, -135, -135, -168, 255),
	gdSPDefVtxN(-71, 200, 71, 0, 0, -135, -135, 168, 255),
	gdSPDefVtxN(-92, 0, 38, 0, 0, -175, -71, -170, 255),
	gdSPDefVtxN(-92, 200, 38, 0, 0, -175, -71, 170, 255),
	gdSPDefVtxN(-100, 0, 0, 0, 0, -190, 0, -169, 255),
	gdSPDefVtxN(-100, 200, 0, 0, 0, -190, 0, 169, 255),
	gdSPDefVtxN(-92, 0, -38, 0, 0, -175, 71, -170, 255),
	gdSPDefVtxN(-92, 200, -38, 0, 0, -175, 71, 170, 255),
	gdSPDefVtxN(-71, 0, -71, 0, 0, -135, 135, -168, 255),
	gdSPDefVtxN(-71, 200, -71, 0, 0, -135, 135, 168, 255),
	gdSPDefVtxN(-38, 0, -92, 0, 0, -71, 175, -170, 255),
	gdSPDefVtxN(-38, 200, -92, 0, 0, -71, 175, 170, 255)
};

static Gfx dl_cylinder[] = {
	gsDPPipeSync(),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
	gsSPVertex(&v_cylinder, 32, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 4, 1, 0),
	gsSP2Triangles(5, 6, 4, 0, 7, 8, 6, 0),
	gsSP2Triangles(9, 10, 8, 0, 11, 12, 10, 0),
	gsSP2Triangles(13, 14, 12, 0, 15, 16, 14, 0),
	gsSP2Triangles(17, 18, 16, 0, 19, 20, 18, 0),
	gsSP2Triangles(21, 22, 20, 0, 23, 24, 22, 0),
	gsSP2Triangles(25, 26, 24, 0, 27, 28, 26, 0),
	gsSP2Triangles(5, 29, 21, 0, 29, 30, 28, 0),
	gsSP2Triangles(31, 2, 30, 0, 6, 14, 22, 0),
	gsSP2Triangles(0, 3, 1, 0, 3, 5, 4, 0),
	gsSP2Triangles(5, 7, 6, 0, 7, 9, 8, 0),
	gsSP2Triangles(9, 11, 10, 0, 11, 13, 12, 0),
	gsSP2Triangles(13, 15, 14, 0, 15, 17, 16, 0),
	gsSP2Triangles(17, 19, 18, 0, 19, 21, 20, 0),
	gsSP2Triangles(21, 23, 22, 0, 23, 25, 24, 0),
	gsSP2Triangles(25, 27, 26, 0, 27, 29, 28, 0),
	gsSP2Triangles(5, 3, 0, 0, 0, 31, 29, 0),
	gsSP2Triangles(29, 27, 25, 0, 25, 23, 21, 0),
	gsSP2Triangles(21, 19, 17, 0, 17, 15, 13, 0),
	gsSP2Triangles(13, 11, 9, 0, 9, 7, 13, 0),
	gsSP2Triangles(7, 5, 13, 0, 5, 0, 29, 0),
	gsSP2Triangles(29, 25, 21, 0, 21, 17, 5, 0),
	gsSP2Triangles(17, 13, 5, 0, 29, 31, 30, 0),
	gsSP2Triangles(31, 0, 2, 0, 30, 2, 1, 0),
	gsSP2Triangles(1, 4, 30, 0, 4, 6, 30, 0),
	gsSP2Triangles(6, 8, 10, 0, 10, 12, 6, 0),
	gsSP2Triangles(12, 14, 6, 0, 14, 16, 22, 0),
	gsSP2Triangles(16, 18, 22, 0, 18, 20, 22, 0),
	gsSP2Triangles(22, 24, 26, 0, 26, 28, 30, 0),
	gsSP2Triangles(22, 26, 30, 0, 30, 6, 22, 0),
    gsSPClearGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
	gsSPEndDisplayList()
};

/* Scale Factor is * 128 */
static Vtx v_sphere[30] = {
	gdSPDefVtxN(0, -40, -122, 0, 0, 0, 244, -73, 255),
	gdSPDefVtxN(59, -104, -47, 0, 0, 127, 100, -196, 255),
	gdSPDefVtxN(0, -104, -75, 0, 0, 0, 162, -196, 255),
	gdSPDefVtxN(0, 104, -75, 0, 0, 0, 162, 196, 255),
	gdSPDefVtxN(95, 40, -76, 0, 0, 190, 152, 72, 255),
	gdSPDefVtxN(0, 40, -122, 0, 0, 0, 244, 73, 255),
	gdSPDefVtxN(0, -128, 0, 0, 0, 0, 0, -254, 255),
	gdSPDefVtxN(95, -40, -76, 0, 0, 190, 152, -73, 255),
	gdSPDefVtxN(0, 128, 0, 0, 0, 0, 0, 254, 255),
	gdSPDefVtxN(59, 104, -47, 0, 0, 127, 101, 196, 255),
	gdSPDefVtxN(119, -40, 27, 0, 0, 238, -53, -73, 255),
	gdSPDefVtxN(73, 104, 17, 0, 0, 157, -36, 196, 255),
	gdSPDefVtxN(73, -104, 17, 0, 0, 158, -35, -196, 255),
	gdSPDefVtxN(119, 40, 27, 0, 0, 238, -53, 73, 255),
	gdSPDefVtxN(53, -40, 110, 0, 0, 106, -220, -73, 255),
	gdSPDefVtxN(33, 104, 68, 0, 0, 71, -146, 196, 255),
	gdSPDefVtxN(33, -104, 68, 0, 0, 70, -146, -196, 255),
	gdSPDefVtxN(53, 40, 110, 0, 0, 106, -219, 73, 255),
	gdSPDefVtxN(-53, -40, 110, 0, 0, -106, -219, -73, 255),
	gdSPDefVtxN(-33, 104, 68, 0, 0, -70, -146, 196, 255),
	gdSPDefVtxN(-33, -104, 68, 0, 0, -71, -146, -196, 255),
	gdSPDefVtxN(-53, 40, 110, 0, 0, -106, -220, 73, 255),
	gdSPDefVtxN(-119, -40, 27, 0, 0, -238, -53, -73, 255),
	gdSPDefVtxN(-73, 104, 17, 0, 0, -158, -35, 196, 255),
	gdSPDefVtxN(-73, -104, 17, 0, 0, -157, -36, -196, 255),
	gdSPDefVtxN(-119, 40, 27, 0, 0, -238, -53, 73, 255),
	gdSPDefVtxN(-95, 40, -76, 0, 0, -190, 152, 73, 255),
	gdSPDefVtxN(-95, -40, -76, 0, 0, -190, 152, -72, 255),
	gdSPDefVtxN(-59, 104, -47, 0, 0, -127, 100, 196, 255),
	gdSPDefVtxN(-59, -104, -47, 0, 0, -127, 101, -196, 255)
};

static Gfx dl_sphere[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
	gsSPVertex(&v_sphere, 30, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
	gsSP2Triangles(6, 2, 1, 0, 5, 7, 0, 0),
	gsSP2Triangles(3, 8, 9, 0, 4, 10, 7, 0),
	gsSP2Triangles(9, 8, 11, 0, 7, 12, 1, 0),
	gsSP2Triangles(9, 13, 4, 0, 6, 1, 12, 0),
	gsSP2Triangles(13, 14, 10, 0, 11, 8, 15, 0),
	gsSP2Triangles(10, 16, 12, 0, 11, 17, 13, 0),
	gsSP2Triangles(6, 12, 16, 0, 17, 18, 14, 0),
	gsSP2Triangles(15, 8, 19, 0, 14, 20, 16, 0),
	gsSP2Triangles(15, 21, 17, 0, 6, 16, 20, 0),
	gsSP2Triangles(21, 22, 18, 0, 19, 8, 23, 0),
	gsSP2Triangles(18, 24, 20, 0, 19, 25, 21, 0),
	gsSP2Triangles(6, 20, 24, 0, 22, 26, 27, 0),
	gsSP2Triangles(23, 8, 28, 0, 22, 29, 24, 0),
	gsSP2Triangles(23, 26, 25, 0, 6, 24, 29, 0),
	gsSP2Triangles(27, 5, 0, 0, 28, 8, 3, 0),
	gsSP2Triangles(27, 2, 29, 0, 28, 5, 26, 0),
	gsSP2Triangles(6, 29, 2, 0, 0, 7, 1, 0),
	gsSP2Triangles(3, 9, 4, 0, 5, 4, 7, 0),
	gsSP2Triangles(4, 13, 10, 0, 7, 10, 12, 0),
	gsSP2Triangles(9, 11, 13, 0, 13, 17, 14, 0),
	gsSP2Triangles(10, 14, 16, 0, 11, 15, 17, 0),
	gsSP2Triangles(17, 21, 18, 0, 14, 18, 20, 0),
	gsSP2Triangles(15, 19, 21, 0, 21, 25, 22, 0),
	gsSP2Triangles(18, 22, 24, 0, 19, 23, 25, 0),
	gsSP2Triangles(22, 25, 26, 0, 22, 27, 29, 0),
	gsSP2Triangles(23, 28, 26, 0, 27, 26, 5, 0),
	gsSP2Triangles(27, 0, 2, 0, 28, 3, 5, 0),
	gsSPClearGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
	gsSPEndDisplayList()
};

#endif