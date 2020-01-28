/**
 * gfx.h <CrookedPoe>
 * A collection of useful graphics-handling structs, converters, and macros.
 **/

/*** Structs ***/
typedef struct {
  uint32_t timg;
  float width;
  float height;
  uint8_t  fmt;
  uint8_t  bitsiz;
} gfx_texture_t;

typedef struct {
  float x;
  float y;
  uint8_t  origin_anchor;
  float width;
  float height;
} gfx_screen_tile_t;

#define G_TX_ANCHOR_C  0b0000
#define G_TX_ANCHOR_U  0b0001
#define G_TX_ANCHOR_R  0b0010
#define G_TX_ANCHOR_D  0b0100
#define G_TX_ANCHOR_L  0b1000
#define G_TX_ANCHOR_UR G_TX_ANCHOR_U + G_TX_ANCHOR_R
#define G_TX_ANCHOR_DR G_TX_ANCHOR_D + G_TX_ANCHOR_R
#define G_TX_ANCHOR_DL G_TX_ANCHOR_D + G_TX_ANCHOR_L
#define G_TX_ANCHOR_UL G_TX_ANCHOR_U + G_TX_ANCHOR_L
#define G_TX_ANCHOR_UD G_TX_ANCHOR_U + G_TX_ANCHOR_D
#define G_TX_ANCHOR_RL G_TX_ANCHOR_R + G_TX_ANCHOR_L
#define TIMG_A(TA0) G_TX_ANCHOR_##TA0
#define TEXT_DIR_LTR 0b00
#define TEXT_DIR_RTL 0b01
#define TEXT_DIR_CEN 0b10
#define TEXT_IGNORE_COLOR 1
#define TEXT_SKIP_RENDER 2

/* draw debug text (supports format specifiers);         *
 * this example displays the string "hello z64ovl"       *
 * at the upper left corner of the screen:               *
 *   zh_draw_debug_text(                                 *
 *      gl                                               *
 *      , 0xFFFFFFFF                                     *
 *      , 1, 1                                           *
 *      , "hello z%dovl"                                 *
 *      , 64                                             *
 *   );                                                  */
#define zh_draw_debug_text(                              \
   /*z64_global_tP*/  gl     /* Global Context    */     \
   , /*uint32_t*/     rgba   /* RGBA 32-Bit Color */     \
   , /*uint8_t*/      x      /* X Coordinate      */     \
   , /*uint8_t*/      y      /* Y Coordinate      */     \
   , /*const charP*/  fmt    /* Format String     */     \
   , ...                     /* Extra Arguments   */     \
)                                                        \
{                                                        \
   z64_debug_text_t dbtx = {0};                          \
   z64_disp_buf_t *ovl = &gl->common.gfx_ctxt->overlay;  \
   debug_init_text_struct(&dbtx);                        \
   debug_do_text_struct(&dbtx, ovl->p);                  \
   debug_set_text_rgba(                                  \
      &dbtx                                              \
      , RED32(rgba)                                      \
      , GREEN32(rgba)                                    \
      , BLUE32(rgba)                                     \
      , ALPHA32(rgba)                                    \
   );                                                    \
   debug_set_text_xy(&dbtx, x, y);                       \
   debug_set_text_string(&dbtx, fmt, __VA_ARGS__);       \
   ovl->p = (Gfx *)debug_update_text_struct(&dbtx);      \
}

static void zh_set_palette(z64_disp_buf_t *buf, int32_t addr)
{
  gDPPipeSync(buf->p++);
  gSPSetOtherMode(buf->p++, G_SETOTHERMODE_H, G_MDSFT_TEXTFILT, 2, 0x00000000);
  gDPSetTextureImage(buf->p++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, addr);
  gDPTileSync(buf->p++);
  gDPSetTile(buf->p++, G_IM_FMT_RGBA, 0, 0, 0x100, G_TX_LOADTILE, 0, 0, 0, 0, 0, 0, 0);
  gDPLoadSync(buf->p++);
  gDPLoadTLUTCmd(buf->p++, G_TX_LOADTILE, 255);
  gSPSetOtherMode(buf->p++, G_SETOTHERMODE_H, G_MDSFT_TEXTLUT, 2, 0x00008000);
}

static
void
zh_draw_ui_sprite(
	z64_disp_buf_t *buf
	, gfx_texture_t *img
	, gfx_screen_tile_t *tile
)
{
	gfx_screen_tile_t tile_copy = *tile;
	tile = &tile_copy;
	if (tile->origin_anchor == 0x0000)
	{
		tile->x -= (tile->width/2); tile->y -= (tile->height/2);
	}
	else
	{
		if (tile->origin_anchor & TIMG_A(U))
			tile->height /= 2;
		if (tile->origin_anchor & TIMG_A(R))
			tile->x -= tile->width;
		if (tile->origin_anchor & TIMG_A(D))
			tile->y -= tile->height;
		if (tile->origin_anchor & TIMG_A(L))
			tile->width /= 2;
	}

	#if OOT_DEBUG
		gSPDisplayList(buf->p++, 0x801269D0);
	#elif	OOT_U_1_0
		gSPDisplayList(buf->p++, 0x800F84A0);
	#endif

	gDPSetCombineLERP(
		buf->p++
		, PRIMITIVE
		, ENVIRONMENT
		, TEXEL0
		, ENVIRONMENT
		, TEXEL0
		, 0
		, PRIMITIVE
		, 0
		, PRIMITIVE
		, ENVIRONMENT
		, TEXEL0
		, ENVIRONMENT
		, TEXEL0
		, 0
		, PRIMITIVE
		, 0
	);
	gDPSetPrimColor(buf->p++, 0, 0, 255, 255, 255, 255);
	gDPSetEnvColor(buf->p++, 0, 0, 0, 255);
	//gDPPipeSync(buf->p++);
  gDPLoadTextureBlock(
    buf->p++
    , img->timg, img->fmt, img->bitsiz
    , img->width, img->height
    , 0
    , G_TX_WRAP, G_TX_WRAP
    , G_TX_NOMASK, G_TX_NOMASK
    , G_TX_NOLOD, G_TX_NOLOD
  );
	if (tile->width == 0) tile->width++;
	if (tile->height == 0) tile->height++;
	gSPTextureRectangle(
		buf->p++
		, qs102(tile->x) & ~3
		, qs102(tile->y) & ~3
		, qs102(tile->x + tile->width) & ~3
		, qs102(tile->y + tile->height) & ~3
		, G_TX_RENDERTILE
		, qu105(0), qu105(0)
		, qu510(img->width / tile->width)
		, qu510(img->height / tile->height)
	);
}
