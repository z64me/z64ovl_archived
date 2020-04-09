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

typedef struct {
   gfx_texture_t texture;
   gfx_screen_tile_t tile;
} zh_ui_sprite_t;

#define G_TX_ANCHOR_C  0b0000
#define G_TX_ANCHOR_U  0b0001
#define G_TX_ANCHOR_R  0b0010
#define G_TX_ANCHOR_D  0b0100
#define G_TX_ANCHOR_L  0b1000
#define G_TX_ANCHOR_UR (G_TX_ANCHOR_U + G_TX_ANCHOR_R)
#define G_TX_ANCHOR_DR (G_TX_ANCHOR_D + G_TX_ANCHOR_R)
#define G_TX_ANCHOR_DL (G_TX_ANCHOR_D + G_TX_ANCHOR_L)
#define G_TX_ANCHOR_UL (G_TX_ANCHOR_U + G_TX_ANCHOR_L)
#define G_TX_ANCHOR_UD (G_TX_ANCHOR_U + G_TX_ANCHOR_D)
#define G_TX_ANCHOR_RL (G_TX_ANCHOR_R + G_TX_ANCHOR_L)
#define TIMG_A(TA0) G_TX_ANCHOR_##TA0
#define TEXT_DIR_LTR 0b00
#define TEXT_DIR_RTL 0b01
#define TEXT_DIR_CEN 0b10
#define TEXT_IGNORE_COLOR 1
#define TEXT_SKIP_RENDER 2

/* for drawing multiple debug text strings optimally,     *
 * use the following macros like so:                      *
 *   zh_text_init(global, 0xFFFFFFFF, 1, 1);              *
 *     zh_text_draw("hello z%dovl", 64);                  *
 *     zh_text_draw("another line...");                   *
 *   zh_text_done();                                      *
 * [@] any variables declared between init() and done()   *
 *     have scope only in that region                     *
 * [@] you can draw with custom position and color using  *
 *     zh_text_draw_ex                                    *
 * if you don't understand this, use the simpler macro    *
 * zh_draw_debug_text() for your text rendering needs     */
#define zh_text_init_ex(/*z64_global_tP*/ gl)             \
{                                                         \
   z64_global_t *__LGL = gl; /* local copy */             \
   int __X = 0;                                           \
   int __Y = 0;                                           \
   z64_debug_text_t dbtx = {0};                           \
   z64_disp_buf_t *ovl = &__LGL->common.gfx_ctxt->overlay;\
   debug_init_text_struct(&dbtx);                         \
   debug_do_text_struct(&dbtx, ovl->p);   
#define zh_text_init(                                     \
	/*z64_global_tP*/  gl                                  \
   , /*uint32_t*/     rgba   /* RGBA 32-Bit Color */      \
   , /*uint8_t*/      x      /* X Coordinate      */      \
   , /*uint8_t*/      y      /* Y Coordinate      */      \
)                                                         \
{                                                         \
   z64_global_t *__LGL = gl; /* local copy */             \
   int __X = x;                                           \
   int __Y = y;                                           \
   z64_debug_text_t dbtx = {0};                           \
   z64_disp_buf_t *ovl = &__LGL->common.gfx_ctxt->overlay;\
   debug_init_text_struct(&dbtx);                         \
   debug_do_text_struct(&dbtx, ovl->p);                   \
   debug_set_text_rgba(                                   \
      &dbtx                                               \
      , RED32(rgba)                                       \
      , GREEN32(rgba)                                     \
      , BLUE32(rgba)                                      \
      , ALPHA32(rgba)                                     \
   );
#define zh_text_draw_ex(                                  \
   /*uint32_t*/       rgba   /* RGBA 32-Bit Color */      \
   , /*uint8_t*/      x      /* X Coordinate      */      \
   , /*uint8_t*/      y      /* Y Coordinate      */      \
   , /*const charP*/  fmt    /* Format String     */      \
   , ...                     /* Extra Arguments   */      \
)                                                         \
{                                                         \
   debug_set_text_rgba(                                   \
      &dbtx                                               \
      , RED32(rgba)                                       \
      , GREEN32(rgba)                                     \
      , BLUE32(rgba)                                      \
      , ALPHA32(rgba)                                     \
   );                                                     \
   debug_set_text_xy(&dbtx, x, y);                        \
   __X = x;                                               \
   __Y = y + 1;                                           \
   debug_set_text_string(&dbtx, fmt, __VA_ARGS__);        \
}
#define zh_text_draw(                                     \
   /*const charP*/  fmt      /* Format String     */      \
   , ...                     /* Extra Arguments   */      \
)                                                         \
{                                                         \
   debug_set_text_xy(&dbtx, __X, __Y);                    \
   ++__Y; /* advance to next line */                      \
   debug_set_text_string(&dbtx, fmt, __VA_ARGS__);        \
}
#define zh_text_done(x)                                   \
   ovl->p = (Gfx *)debug_update_text_struct(&dbtx);       \
}

/* this version allows you to draw with one call: */
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
   , uint32_t rgba
)
{
	gfx_screen_tile_t tile_copy = *tile;
	tile = &tile_copy;

   /* Anchor Coordinates */
   if (tile->origin_anchor == G_TX_ANCHOR_C) /* Center */
   {
      tile->x -= (tile->width/2);
      tile->y -= (tile->height/2);
   }
   else
   {
      if (tile->origin_anchor & TIMG_A(U))
         tile->y += 0; /* Default */
      if (tile->origin_anchor & TIMG_A(R))
         tile->x = tile->width;
      if (tile->origin_anchor & TIMG_A(D))
         tile->y = tile->height;
      if (tile->origin_anchor & TIMG_A(L))
         tile->x += 0; /* Default */ 
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
	gDPSetPrimColor(buf->p++, 0, 0, RED32(rgba), GREEN32(rgba), BLUE32(rgba), ALPHA32(rgba));
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

static void zh_draw_numeric_text(
    z64_global_t* gl
    , int32_t is_ammo
    , int32_t n, int32_t length
    , float x, float y
    , uint32_t rgba
)
{
    z64_disp_buf_t* ovl = &ZQDL(gl, overlay);
    float lw = is_ammo ? 6 : 8; 				/* Character Width */
    int digits = 1;
	for (int x = n / 10; x; x /= 10) ++digits;
	digits = zh_max_int(digits, length);         /* Total Integer Digits */
    x += lw * digits; 
	zh_ui_sprite_t digit = {
		.texture = {
			.timg = is_ammo ? G_IM_TEX_DIGIT_AMMO_TIMG : G_IM_TEX_DIGIT_TIMG
			, .width = 8
			, .height = is_ammo ? 8 : 16
			, .fmt = is_ammo ? G_IM_FMT_IA : G_IM_FMT_I
			, .bitsiz = G_IM_SIZ_8b
		},
		.tile = {
			.x = x
			, .y = y
			, .origin_anchor = G_TX_ANCHOR_UL
			, .width = 8
			, .height = is_ammo ? 8 : 16
		}
	};
    uint32_t sz = is_ammo ? 0x40 : 0x80;

    while(digits--)
    {
        int32_t i = n % 10;
        n /= 10;

		uint32_t tex = (is_ammo ? G_IM_TEX_DIGIT_AMMO_TIMG : G_IM_TEX_DIGIT_TIMG) + i * sz;
		digit.texture.timg = (uint32_t)gl->if_ctxt.parameter + tex;

		digit.tile.x -= lw;
        zh_draw_ui_sprite(ovl, &digit.texture, &digit.tile, rgba); /* Draw digit. */
    }
}

static void zh_draw_numeric_timer(
	z64_global_t* gl
	, int32_t minutes
	, int32_t seconds
	, float x
	, float y
	, uint32_t rgba
)
{
    float lw = 8; /* letter width */
    char buf[16];
    z64_disp_buf_t* ovl = &ZQDL(gl, overlay);
    
	/* Clock */
	gfx_texture_t clock = { /* Grab our digit texture. */
		(uint32_t)gl->if_ctxt.parameter + G_IM_TEX_CLOCK_TIMG
		, 16
		, 16
		, G_IM_FMT_IA
		, G_IM_SIZ_8b
	};

	gfx_screen_tile_t clock_tile = { /* Create a tile for our digit texture. */
		x
		, y
		, G_TX_ANCHOR_UL
		, 16
		, 16
	};

	zh_draw_ui_sprite(ovl, &clock, &clock_tile, 0xFFFFFFFF); /* Draw Clock. */

	/* Timer Digits */
    z_sprintf(buf, "%02d:%02d", minutes, seconds);
    
    for (char *str = buf; *str; ++str)
    {
        int i = *str - '0';

        gfx_texture_t digit = { /* Grab our digit texture. */
            (uint32_t)gl->if_ctxt.parameter + (G_IM_TEX_DIGIT_TIMG + (i * 0x80))
            , 8
            , 16
            , G_IM_FMT_I
            , G_IM_SIZ_8b
        };

        gfx_screen_tile_t digit_tile = { /* Create a tile for our digit texture. */
            (x += lw) + 8
            , y
            , G_TX_ANCHOR_UL
            , 8
            , 16
        };

        zh_draw_ui_sprite(ovl, &digit, &digit_tile, rgba); /* Draw digit. */
    }
}

static void zh_draw_nes_font(
	z64_global_t* gl
	, uint32_t nes_font_static
	, char* format
	, float x, float y
	, float scale
	, uint32_t rgba
)
{
    float *width = (float*)Z64GL_NES_FONT_WIDTH_TABLE;
    char buf[64];
    z64_disp_buf_t* ovl = &ZQDL(gl, overlay);

	z_sprintf(buf, format);
    
    for (char *str = buf; *str; ++str)
    {
        int i = *str - ' ';

        gfx_texture_t letter = { /* Grab our character texture. */
            nes_font_static + (i * 0x80)
            , 16
            , 16
            , G_IM_FMT_I
            , G_IM_SIZ_4b
        };

        gfx_screen_tile_t letter_tile = { /* Create a tile for our character texture. */
            x
            , y
            , G_TX_ANCHOR_UL
            , 16 * scale
            , 16 * scale
        };
		x += width[i] * scale;

        zh_draw_ui_sprite(ovl, &letter, &letter_tile, rgba); /* Draw character. */
    }
}
