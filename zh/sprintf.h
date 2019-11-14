/**
 * sprintf.h  <z64.me>
 * a basic implementation of sprintf using va_arr.h;
 * for use with z64ovl, but potentially useful on other
 * platforms where stdarg.h is not present
 *
 * the only format specifiers currently supported are:
 *   %s - string
 *   %c - character
 *   %d - decimal integer
 *   %x - hexadecimal integer
 *   %X - hexadecimal integer, uppercase
 *   %f - floating point
 **/

#if 0
	/* usage example */
	char buf[128];
	int x = 0xABC;
	zh_sprintf(
		buf
		, "%s-%c, under the sea... 0x%X, %d, %f"
		, VA_ARR(
			"tunafish"
			, VA_ARR_c('Z')
			, &x
			, VA_ARR_d(256)
			, VA_ARR_f(1024.56789f)
		)
	);
#endif

#ifndef ZH_SPRINTF_H_INCLUDED
#define ZH_SPRINTF_H_INCLUDED

#include "va_arr.h"

static
void
zh_sprintf(char *dst, char *fmt, struct va_arr *va_arr)
{
	/* temporary pointers for storing arguments */
	char  *val_char;
	int   *val_int;
	float *val_float;
	
	/* temporary buffer for storing int/float conversions */
	char buffer[32];
	char ch;
	
	/* a rare case where nested functions are acceptable */
	int
	powi(int x, int y)
	{
		int z = x;
		while (--y)
			x *= z;
		return x;
	}
	
	void
	reverse(char *str, int len)
	{
		char *end = str + len;
		while (str < end)
		{
			do { *str ^= *end; *end ^= *str; *str ^= *end; } while (0);
			++str;
			--end;
		}
	}

	void
	itoa(int v, char *dst, int base)
	{
#define ITOA_CAPS 0x80
#define ITOA_BASE 0x7F
		int digits = 0;
		if (base == 10)
		{
			while (v)
			{
				*(dst++) = '0' + (v % 10);
				v /= 10;
				++digits;
			}
		}
		else if (base == 16 || base == (16 | ITOA_CAPS))
		{
			while (v)
			{
				int x = (v & 0xF);
				if (x <= 9)
					x = '0' + x;
				else
					x = ((base & ITOA_CAPS) ? 'A' : 'a') + (x - 0xA);
				v >>= 4;
				*(dst++) = x;
				++digits;
			}
		}
		
		/* we constructed the string backwards, so reverse it */
		reverse(dst - digits, digits - 1);
		
		/* zero terminator */
		*dst = '\0';
	}

	void
	ftoa(float v, char *dst, int places)
	{
		int    ipart = v;
		float  fpart = v - ipart;
		itoa(ipart, dst, 10);
		while (*dst)
			++dst;
		if (places > 0)
		{
			*(dst++) = '.';
			fpart *= powi(10, places);
			itoa(fpart, dst, 10);
		}
	}
	
	void
	append(char *buf)
	{
		do {
			*(dst++) = *(buf++);
		} while(*buf);
	}
	
	/* all the formatting work takes place here */
	while ((ch = *fmt++))
	{
		/* '%' indicates a format specifier */
		if (ch == '%')
		{
			switch (ch = *fmt++)
			{
				/* %% - print a '%' character    */
				case '%':
					*(dst++) = '%';
					break;

				/* %c - print a character        */
				case 'c':
					val_char = (va_arr++)->v;
					*(dst++) = *val_char;
					break;

				/* %s - print a string           */
				case 's':
					val_char = (va_arr++)->v;
					append(val_char);
					break;

				/* %d - print an int             */
				case 'd':
					val_int = (va_arr++)->v;
					itoa(*val_int, buffer, 10);
					append(buffer);
					break;

				/* %x - print an int (hex)       */
				case 'x':
					val_int = (va_arr++)->v;
					itoa(*val_int, buffer, 16);
					append(buffer);
					break;

				/* %X - print an int (hex, caps) */
				case 'X':
					val_int = (va_arr++)->v;
					itoa(*val_int, buffer, 16 | ITOA_CAPS);
					append(buffer);
					break;

				/* %f - print a float            */
				case 'f':
					val_float = (va_arr++)->v;
					ftoa(*val_float, buffer, 5);
					append(buffer);
					break;

				/* display as-is if unsupported  */
				default:
					*(dst++) = '%';
					*(dst++) = ch;
					break;
			}
		}
		else
			*(dst++) = ch;
	}
	
	/* zero terminator */
	*dst = '\0';
}

#endif /* ZH_SPRINTF_H_INCLUDED */
