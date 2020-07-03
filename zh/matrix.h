#ifndef MATRIX_H
#define MATRIX_H

#include <z64ovl/zh/vec3f.h>
#include <z64ovl/zh/vec3s.h>

#define	FTOFIX32(x)	(long)((x) * (float)0x00010000)
#define cosf z_cosf
#define sinf z_sinf
static const float    dtor = (float)(3.1415926 / 180.0);

#define MULTIPLY 0
#define DIVIDE 1
#define ADD 2
#define SUBTRACT 3

static inline void libultra_guMtxIdentF(float mf[4][4]);
static inline void libultra_guTranslateF(float mf[4][4], float x, float y, float z);
static inline void libultra_guScaleF(float mf[4][4], float x, float y, float z);
static inline void libultra_guNormalize(float* x, float* y, float* z);
static inline void libultra_guRotateF(float mf[4][4], float a, float x, float y, float z);
static inline void libultra_guPositionF(float mf[4][4], float r, float p, float h, float s, float x, float y, float z);
static inline void guMtxArithmeticF(float mf[4][4], float mult[4][4], int32_t op);
static inline void libultra_guMtxF2L(float mf[4][4], Mtx* m);
static inline void libulutra_guMtxCatF(float mf[4][4], float nf[4][4], float res[4][4]);
static inline void libultra_guRotateRPYF(float mf[4][4], float r, float p, float h);

static inline void libultra_guMtxIdentF(float mf[4][4])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (i == j)
				mf[i][j] = 1.0f;
			else
				mf[i][j] = 0.0f;
		}
	}
}

static inline void libultra_guTranslateF(float mf[4][4], float x, float y, float z)
{
	libultra_guMtxIdentF(mf);

	mf[3][0] = x;
	mf[3][1] = y;
	mf[3][2] = z;
}

static inline void libultra_guScaleF(float mf[4][4], float x, float y, float z)
{
	libultra_guMtxIdentF(mf);

	mf[0][0] = x;
	mf[1][1] = y;
	mf[2][2] = z;
	mf[3][3] = 1.0f;
}

static inline void libultra_guNormalize(float* x, float* y, float* z)
{
	float m;

	m = 1 / SQRT(
		(*x) * (*x)
		+ (*y) * (*y)
		+ (*z) * (*z)
	);
	*x *= m;
	*y *= m;
	*z *= m;
}

static inline void libultra_guRotateF(float mf[4][4], float a, float x, float y, float z)
{
	float	sine;
	float	cosine;
	float	ab, bc, ca, t;

	libultra_guNormalize(&x, &y, &z);
	a *= dtor;
	sine = sinf(a);
	cosine = cosf(a);
	t = (1 - cosine);
	ab = x * y * t;
	bc = y * z * t;
	ca = z * x * t;

	libultra_guMtxIdentF(mf);

	t = x * x;
	mf[0][0] = t + cosine * (1 - t);
	mf[2][1] = bc - x * sine;
	mf[1][2] = bc + x * sine;

	t = y * y;
	mf[1][1] = t + cosine * (1 - t);
	mf[2][0] = ca + y * sine;
	mf[0][2] = ca - y * sine;

	t = z * z;
	mf[2][2] = t + cosine * (1 - t);
	mf[1][0] = ab - z * sine;
	mf[0][1] = ab + z * sine;
}

/*
 *  Return position matrix given roll, pitch, and yaw in degrees
 *  plus scale and position.
 *   
 * r = roll  (degrees)
 * p = pitch (degrees)
 * h = yaw   (degrees)
 * s = scale
 * x,y,z = position (world coordinates)
 *   
 */

static inline void libultra_guPositionF(float mf[4][4], float r, float p, float h, float s, float x, float y, float z)
{
    float   sinr, sinp, sinh;
    float   cosr, cosp, cosh;

    sinr = sinf(r);
    cosr = cosf(r);
    sinp = sinf(p);
    cosp = cosf(p);
    sinh = sinf(h);
    cosh = cosf(h);

    mf[0][0] = (cosp * cosh) * s;
    mf[0][1] = (cosp * sinh) * s;
    mf[0][2] = (-sinp) * s;
    mf[0][3] = 0.0;

    mf[1][0] = (sinr * sinp * cosh - cosr * sinh) * s;
    mf[1][1] = (sinr * sinp * sinh + cosr * cosh) * s;
    mf[1][2] = (sinr * cosp) * s;
    mf[1][3] = 0.0;

    mf[2][0] = (cosr * sinp * cosh + sinr * sinh) * s;
    mf[2][1] = (cosr * sinp * sinh - sinr * cosh) * s;
    mf[2][2] = (cosr * cosp) * s;
    mf[2][3] = 0.0;

    mf[3][0] = x;
    mf[3][1] = y;
    mf[3][2] = z;
    mf[3][3] = 1.0;
}

static inline void guMtxArithmeticF(float mf[4][4], float mult[4][4], int32_t op)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			switch (op)
			{
				case 0: // Multiply
					mf[i][j] *= mult[i][j];
					break;
				case 1: // Divide
					mf[i][j] /= mult[i][j];
					break;
				case 2: // Add
					mf[i][j] += mult[i][j];
					break;
				case 3: // Subtract
					mf[i][j] *= mult[i][j];
					break;
			}
		}
	}
}

static inline void libultra_guMtxF2L(float mf[4][4], Mtx* m)
{
	int32_t e1, e2;
	int32_t* ai;
	int32_t* af;

	ai = (int32_t*)&m->m[0][0]; // Integer
	af = (int32_t*)&m->m[2][0]; // Fraction

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			e1 = FTOFIX32(mf[i][j * 2]);
			e2 = FTOFIX32(mf[i][j * 2 + 1]);
			*(ai++) = (e1 & 0xFFFF0000) | ((e2 >> 16) & 0xFFFF);
			*(af++) = ((e1 << 16) & 0xFFFF0000) | (e2 & 0xFFFF);
		}
	}
}

static inline void libulutra_guMtxCatF(float mf[4][4], float nf[4][4], float res[4][4])
{
	int	i, j, k;
	float	temp[4][4];

	for (i=0; i<4; i++) {
	    for (j=0; j<4; j++) {
		temp[i][j] = 0.0;
		for (k=0; k<4; k++) {
		    temp[i][j] += mf[i][k] * nf[k][j];
		}
	    }
	}

	/* make sure we handle case where result is an input */
	for (i=0; i<4; i++) {
	    for (j=0; j<4; j++) {
		res[i][j] = temp[i][j];
	    }
	}
}

static inline void libultra_guRotateRPYF(float mf[4][4], float r, float p, float h)
{
	static float	dtor = 3.1415926 / 180.0;
	float	sinr, sinp, sinh;
	float	cosr, cosp, cosh;

	r *= dtor;
	p *= dtor;
	h *= dtor;
	sinr = sinf(r);
	cosr = cosf(r);
	sinp = sinf(p);
	cosp = cosf(p);
	sinh = sinf(h);
	cosh = cosf(h);

	guMtxIdentF(mf);

	mf[0][0] = cosp*cosh;
	mf[0][1] = cosp*sinh;
	mf[0][2] = -sinp;

	mf[1][0] = sinr*sinp*cosh - cosr*sinh;
	mf[1][1] = sinr*sinp*sinh + cosr*cosh;
	mf[1][2] = sinr*cosp;

	mf[2][0] = cosr*sinp*cosh + sinr*sinh;
	mf[2][1] = cosr*sinp*sinh - sinr*cosh;
	mf[2][2] = cosr*cosp;
}

#endif
