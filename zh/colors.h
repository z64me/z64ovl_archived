/**
 * colors.h <CrookedPoe>
 * A collection of useful color-handling structs, converters, and macros.
 **/

/*** Structs ***/
#if 0 /* moved to various_types.h */
typedef struct
{
  uint8_t r;
  uint8_t g;
  uint8_t b;
} rgb8_t;

typedef struct
{
  uint8_t r;
  uint8_t g;
  uint8_t b;
  uint8_t a;
} rgba8_t;
#endif

typedef struct
{
  float h;
  float s;
  float v;
} hsvf_t;

/*** Macros ***/
/* Create a 24-bit integer, representing a red, green, blue value. */
#define COLOR24(r, g, b) (uint32_t)((r << 16) | (g << 8) | b)

/* Create a 32-bit integer, representing a red, green, blue and alpha value. */
#define COLOR32(r, g, b, a) (uint32_t)(((r) << 24) | ((g) << 16) | ((b) << 8) | (a))

/* Isolate a red value from a COLOR32. */
#define RED32(RGBA0) (uint8_t)(((RGBA0) >> 24) & 0xFF)

/* Isolate a green value from a COLOR32. */
#define GREEN32(RGBA0) (uint8_t)(((RGBA0) >> 16) & 0xFF)

/* Isolate a blue value from a COLOR32. */
#define BLUE32(RGBA0) (uint8_t)(((RGBA0) >> 8) & 0xFF)

/* Isolate an alpha value from a COLOR32. */
#define ALPHA32(RGBA0) (uint8_t)(((RGBA0)) & 0xFF)

/* Isolate a red value from a COLOR24. */
#define RED24(RGBA0) (uint8_t)(((RGBA0) >> 16) & 0xFF)

/* Isolate a green value from a COLOR24. */
#define GREEN24(RGBA0) (uint8_t)(((RGBA0) >> 8) & 0xFF)

/* Isolate a blue value from a COLOR24. */
#define BLUE24(RGBA0) (uint8_t)(((RGBA0)) & 0xFF)

/* Convert a pecentage to a radian value. */
#define PRAD(PERA0) (float)((PERA0) * 0.06283f)

/* Convert a radian value to a percentage. */
#define RPER(RADA0) (float)((RADA0) * 15.91549f)

#define COLOR16_TO_COLOR32(CARG0) (                 \
      COLOR32((((CARG0) & 0xF800) >> 11) /* red */  \
    , (((CARG0) & 0x07C0) >> 6) /* green */         \
    , (((CARG0) & 0x003E) >> 1) /* blue  */         \
    , ((((CARG0) & 0x1) > 0) ? 255 : 0) /* alpha */ \
))

#define COLOR32_TO_COLOR16(CARG0) (              \
      (((CARG0) & 0xF8000000) >> 16) /* red   */  \
    | (((CARG0) & 0x00F80000) >> 13) /* green */  \
    | (((CARG0) & 0x0000F800) >> 10) /* blue  */  \
    | (((CARG0) & 0x00000080) >>  7) /* alpha */  \
) /* Thanks, z64.me! */

#define COLOR16(r, g, b, a) COLOR32_TO_COLOR16(COLOR32((r), (g), (b), (a)))

static inline void zh_color_hsv2rgb(float h, float s, float v, rgba8_t *out, uint32_t init)
{
	float red = RED32(init);
	float green = GREEN32(init);
	float blue = BLUE32(init);

	float c = (v * s);
	float x = c * (1 - math_fabsf(math_fmodf((h / 60.0f), 2) - 1));
	float m = (v - c);

	if (h >= 0.0f && h < 60.0f)
	{
		red = c;
		green = x;
		blue = 0.0f;
	}
	else if (h >= 60.0f && h < 120.0f)
	{
		red = x;
		green = c;
		blue = 0.0f;
	}
	else if (h >= 120.0f && h < 180.0f)
	{
		red = 0.0f;
		green = c;
		blue = x;
	}
	else if (h >= 180.0f && h < 240.0f)
	{
		red = 0.0f;
		green = x;
		blue = c;
	}
	else if (h >= 240.0f && h < 300.0f)
	{
		red = x;
		green = 0.0f;
		blue = c;
	}
	else/* if (h >= 300.0f && h <= 360.0f)*/
	{
		red = c;
		green = 0.0f;
		blue = x;
	}

	out->r = (uint8_t)(CEIL((red + m) * 255));
	out->g = (uint8_t)(CEIL((green + m) * 255));
	out->b = (uint8_t)(CEIL((blue + m) * 255));
	out->a = 0xFF;
}

static inline void zh_color_rgb2hsv(uint32_t rgba, hsvf_t *out)
{
	float red = (RED32(rgba) / 255.0f);
	float green = (GREEN32(rgba) / 255.0f);
	float blue = (BLUE32(rgba) / 255.0f);

	float cmax = zh_math_fmaxf(red, zh_math_fmaxf(green, blue));
	float cmin = zh_math_fminf(red, zh_math_fminf(green, blue));

	float delta = (cmax - cmin);

	/* Hue and Saturation*/
	if (cmax == 0.0f)
	{
		out->s = 0.0f;
		out->h = 0.0f;
	}
	else if (delta == 0.0f)
	{
		out->s = 0.0f;
		out->h = 0.0f;
	}
	else
	{
		out->s = (delta / cmax);

		/* Hue */
		if (cmax == red)
			out->h = (60 * math_fmodf(((green - blue) / delta), 6));
		else if (cmax == green)
			out->h = (60 * (((blue - red) / delta) + 2));
		else
			out->h = (60 * (((red) / delta) + 4));
	}

	if (out->h < 0)
		out->h += 360.0f;

	/* Value */
	out->v = cmax;
}

static inline uint32_t zh_rgba8_to_color32(rgba8_t *rgba)
{
  uint32_t out = COLOR32(
    rgba->r
    , rgba->g
    , rgba->b
    , rgba->a
  );
  return out;
}

static inline uint32_t zh_rgb8_to_color24(rgba8_t *rgb)
{
  uint32_t out = COLOR24(
    rgb->r
    , rgb->g
    , rgb->b
  );
  return out;
}

static inline rgba8_t *zh_color32_to_rgba8(uint32_t color)
{
  rgba8_t *out;
  out->r = RED32(color);
  out->g = GREEN32(color);
  out->b = BLUE32(color);
  out->a = ALPHA32(color);
  return out;
}

static inline rgb8_t *zh_color24_to_rgb8(uint32_t color)
{
  rgb8_t *out;
  out->r = RED24(color);
  out->g = GREEN24(color);
  out->b = BLUE24(color);
  return out;
}

static inline hsvf_t *zh_color32_to_hsvf(uint32_t color)
{
  hsvf_t *out;
  zh_color_rgb2hsv(color, out);
  return out;
}

static inline void zh_color_rainbow_cycle(float *hue, float speed, rgba8_t *out)
{
  if (*hue >= 0.0f && *hue < 360.0f)
    *hue += speed;
  else if (*hue >= 360.0f)
    *hue = 0.0f;

  zh_color_hsv2rgb(*hue, 1.0f, 1.0f, out, 0xFF0000FF);
}

static inline void zh_color_flash(uint32_t init, float min_val, float timer, hsvf_t *in, rgba8_t *out)
{
  if (timer > 10) /* Cap Maximum Timer Value at 10 */
    timer -= 10;

  zh_color_rgb2hsv(init, in);
  float val = ((math_cosf(timer) + 1.0f) / 2) * (1.0f - min_val) + min_val;
  zh_color_hsv2rgb(in->h, in->s, val, out, init);
}
