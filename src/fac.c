/*							fac.c
 *
 *	Factorial function
 *
 *
 *
 * SYNOPSIS:
 *
 * double y, fac();
 * int i;
 *
 * y = fac( i );
 *
 *
 *
 * DESCRIPTION:
 *
 * Returns factorial of i  =  1 * 2 * 3 * ... * i.
 * fac(0) = 1.0.
 *
 * Due to machine arithmetic bounds the largest value of
 * i accepted is 33 in DEC arithmetic or 170 in IEEE
 * arithmetic.  Greater values, or negative ones,
 * produce an error message and return MAXNUM.
 *
 *
 *
 * ACCURACY:
 *
 * For i < 34 the values are simply tabulated, and have
 * full machine accuracy.  If i > 55, fac(i) = true_gamma(i+1);
 * see gamma.c.
 *
 *                      Relative error:
 * arithmetic   domain      peak
 *    IEEE      0, 170    1.4e-15
 *    DEC       0, 33      1.4e-17
 *
 */

/*
Cephes Math Library Release 2.0:  April, 1987
Copyright 1984, 1987 by Stephen L. Moshier
Direct inquiries to 30 Frost Street, Cambridge, MA 02140
*/

#include "mconf.h"
#include "cephes.h"

/* Factorials of integers from 0 through 33 */
#ifdef UNK
static double factbl[] = {
  1.00000000000000000000E0,
  1.00000000000000000000E0,
  2.00000000000000000000E0,
  6.00000000000000000000E0,
  2.40000000000000000000E1,
  1.20000000000000000000E2,
  7.20000000000000000000E2,
  5.04000000000000000000E3,
  4.03200000000000000000E4,
  3.62880000000000000000E5,
  3.62880000000000000000E6,
  3.99168000000000000000E7,
  4.79001600000000000000E8,
  6.22702080000000000000E9,
  8.71782912000000000000E10,
  1.30767436800000000000E12,
  2.09227898880000000000E13,
  3.55687428096000000000E14,
  6.40237370572800000000E15,
  1.21645100408832000000E17,
  2.43290200817664000000E18,
  5.10909421717094400000E19,
  1.12400072777760768000E21,
  2.58520167388849766400E22,
  6.20448401733239439360E23,
  1.55112100433309859840E25,
  4.03291461126605635584E26,
  1.0888869450418352160768E28,
  3.04888344611713860501504E29,
  8.841761993739701954543616E30,
  2.6525285981219105863630848E32,
  8.22283865417792281772556288E33,
  2.6313083693369353016721801216E35,
  8.68331761881188649551819440128E36
};
#define MAXFAC 33
#endif

#ifdef DEC
static unsigned short factbl[] = {
0040200,0000000,0000000,0000000,
0040200,0000000,0000000,0000000,
0040400,0000000,0000000,0000000,
0040700,0000000,0000000,0000000,
0041300,0000000,0000000,0000000,
0041760,0000000,0000000,0000000,
0042464,0000000,0000000,0000000,
0043235,0100000,0000000,0000000,
0044035,0100000,0000000,0000000,
0044661,0030000,0000000,0000000,
0045535,0076000,0000000,0000000,
0046430,0042500,0000000,0000000,
0047344,0063740,0000000,0000000,
0050271,0112146,0000000,0000000,
0051242,0060731,0040000,0000000,
0052230,0035673,0126000,0000000,
0053230,0035673,0126000,0000000,
0054241,0137567,0063300,0000000,
0055265,0173546,0051630,0000000,
0056330,0012711,0101504,0100000,
0057407,0006635,0171012,0150000,
0060461,0040737,0046656,0030400,
0061563,0135223,0005317,0101540,
0062657,0027031,0127705,0023155,
0064003,0061223,0041723,0156322,
0065115,0045006,0014773,0004410,
0066246,0146044,0172433,0173526,
0067414,0136077,0027317,0114261,
0070566,0044556,0110753,0045465,
0071737,0031214,0032075,0036050,
0073121,0037543,0070371,0064146,
0074312,0132550,0052561,0116443,
0075512,0132550,0052561,0116443,
0076721,0005423,0114035,0025014
};
#define MAXFAC 33
#endif

#ifdef IBMPC
static unsigned short factbl[] = {
0x0000,0x0000,0x0000,0x3ff0,
0x0000,0x0000,0x0000,0x3ff0,
0x0000,0x0000,0x0000,0x4000,
0x0000,0x0000,0x0000,0x4018,
0x0000,0x0000,0x0000,0x4038,
0x0000,0x0000,0x0000,0x405e,
0x0000,0x0000,0x8000,0x4086,
0x0000,0x0000,0xb000,0x40b3,
0x0000,0x0000,0xb000,0x40e3,
0x0000,0x0000,0x2600,0x4116,
0x0000,0x0000,0xaf80,0x414b,
0x0000,0x0000,0x08a8,0x4183,
0x0000,0x0000,0x8cfc,0x41bc,
0x0000,0xc000,0x328c,0x41f7,
0x0000,0x2800,0x4c3b,0x4234,
0x0000,0x7580,0x0777,0x4273,
0x0000,0x7580,0x0777,0x42b3,
0x0000,0xecd8,0x37ee,0x42f4,
0x0000,0xca73,0xbeec,0x4336,
0x9000,0x3068,0x02b9,0x437b,
0x5a00,0xbe41,0xe1b3,0x43c0,
0xc620,0xe9b5,0x283b,0x4406,
0xf06c,0x6159,0x7752,0x444e,
0xa4ce,0x35f8,0xe5c3,0x4495,
0x7b9a,0x687a,0x6c52,0x44e0,
0x6121,0xc33f,0xa940,0x4529,
0x7eeb,0x9ea3,0xd984,0x4574,
0xf316,0xe5d9,0x9787,0x45c1,
0x6967,0xd23d,0xc92d,0x460e,
0xa785,0x8687,0xe651,0x465b,
0x2d0d,0x6e1f,0x27ec,0x46aa,
0x33a4,0x0aae,0x56ad,0x46f9,
0x33a4,0x0aae,0x56ad,0x4749,
0xa541,0x7303,0x2162,0x479a
};
#define MAXFAC 170
#endif

#ifdef MIEEE
static unsigned short factbl[] = {
0x3ff0,0x0000,0x0000,0x0000,
0x3ff0,0x0000,0x0000,0x0000,
0x4000,0x0000,0x0000,0x0000,
0x4018,0x0000,0x0000,0x0000,
0x4038,0x0000,0x0000,0x0000,
0x405e,0x0000,0x0000,0x0000,
0x4086,0x8000,0x0000,0x0000,
0x40b3,0xb000,0x0000,0x0000,
0x40e3,0xb000,0x0000,0x0000,
0x4116,0x2600,0x0000,0x0000,
0x414b,0xaf80,0x0000,0x0000,
0x4183,0x08a8,0x0000,0x0000,
0x41bc,0x8cfc,0x0000,0x0000,
0x41f7,0x328c,0xc000,0x0000,
0x4234,0x4c3b,0x2800,0x0000,
0x4273,0x0777,0x7580,0x0000,
0x42b3,0x0777,0x7580,0x0000,
0x42f4,0x37ee,0xecd8,0x0000,
0x4336,0xbeec,0xca73,0x0000,
0x437b,0x02b9,0x3068,0x9000,
0x43c0,0xe1b3,0xbe41,0x5a00,
0x4406,0x283b,0xe9b5,0xc620,
0x444e,0x7752,0x6159,0xf06c,
0x4495,0xe5c3,0x35f8,0xa4ce,
0x44e0,0x6c52,0x687a,0x7b9a,
0x4529,0xa940,0xc33f,0x6121,
0x4574,0xd984,0x9ea3,0x7eeb,
0x45c1,0x9787,0xe5d9,0xf316,
0x460e,0xc92d,0xd23d,0x6967,
0x465b,0xe651,0x8687,0xa785,
0x46aa,0x27ec,0x6e1f,0x2d0d,
0x46f9,0x56ad,0x0aae,0x33a4,
0x4749,0x56ad,0x0aae,0x33a4,
0x479a,0x2162,0x7303,0xa541
};
#define MAXFAC 170
#endif

extern double MAXNUM;

double fac(i)
int i;
{
double x, f, n;
int j;

if( i < 0 )
	{
	mtherr( "fac", SING );
	return( MAXNUM );
	}

if( i > MAXFAC )
	{
	mtherr( "fac", OVERFLOW );
	return( MAXNUM );
	}

/* Get answer from table for small i. */
if( i < 34 )
	{
#ifdef UNK
	return( factbl[i] );
#else
	return( *(double *)(&factbl[4*i]) );
#endif
	}
/* Use gamma function for large i. */
if( i > 55 )
	{
	x = i + 1;
	return( true_gamma(x) );
	}
/* Compute directly for intermediate i. */
n = 34.0;
f = 34.0;
for( j=35; j<=i; j++ )
	{
	n += 1.0;
	f *= n;
	}
#ifdef UNK
	f *= factbl[33];
#else
	f *= *(double *)(&factbl[4*33]);
#endif
return( f );
}
