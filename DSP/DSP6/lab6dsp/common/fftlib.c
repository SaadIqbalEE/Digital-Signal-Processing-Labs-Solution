// fftlib.c - FFT function definitions
//
// S. J. Orfanidis, "Introduction to Signal Processing", online book, 2010,
// available from: http://www.ece.rutgers.edu/~orfanidi/intro2sp/

#include "fft.h"

#define two(x)       (1 << (x))                  /* 2^x by left-shifting */

//--------------------------------------------------------
/* complex.c - complex arithmetic functions */
//--------------------------------------------------------

float cabs(complex z)
{
      return sqrt(z.x * z.x + z.y * z.y);
}

complex cmplx(float x, float y)                        /* z = cmplx(x,y) = x+jy */
{
       complex z;

       z.x = x;  z.y = y;

       return z;
}

complex conjg(complex z)                               /* complex conjugate of z=x+jy */
{
       return cmplx(z.x, -z.y);                        /* returns z* = x-jy */
}

complex cadd(complex a, complex b)                     /* complex addition */
{
       return cmplx(a.x + b.x, a.y + b.y);
}

complex csub(complex a, complex b)                     /* complex subtraction */
{
       return cmplx(a.x - b.x, a.y - b.y);
}

complex cmul(complex a, complex b)                     /* complex multiplication */
{
       return cmplx(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x);
}

complex rmul(float a, complex z)                       /* multiplication by real */
{
       return cmplx(a * z.x, a * z.y);
}

complex cdiv(complex a, complex b)                     /* complex division */
{
   float D = b.x * b.x + b.y * b.y;

   return cmplx((a.x * b.x + a.y * b.y) / D, (a.y * b.x - a.x * b.y) / D);
}

complex rdiv(complex z, float a)                       /* division by real */
{
       return cmplx(z.x / a, z.y / a);
}

float real(complex z)                                  /* real part Re(z) */
{
       return z.x;
}

float aimag(complex z)                                 /* imaginary part Im(z) */
{
       return z.y;
}

complex cexp(complex z)                                /* complex exponential */
{
       float R = exp(z.x);

       return cmplx(R * cos(z.y), R * sin(z.y));
}

//--------------------------------------------------------
/* bitrev.c - bit reverse of a B-bit integer n */
//--------------------------------------------------------

int bitrev(int n, int B)
{
       int m, r;

       for (r=0, m=B-1; m>=0; m--)
          if ((n >> m) == 1) {                   /* if \(2\sp{m}\) term is present, then */
             r += two(B-1-m);                    /* add \(2\sp{B-1-m}\) to \(r\), and */
             n -= two(m);                        /* subtract \(2\sp{m}\) from \(n\) */
             }

       return(r);
}

//--------------------------------------------------------
/*  swap.c  --  swap two complex numbers (by their addresses)  */
//--------------------------------------------------------

void swap(complex *a, complex *b)
{
       complex t;

        t = *a;
       *a = *b;
       *b =  t;
}

//--------------------------------------------------------
/* shuffle.c - in-place shuffling (bit-reversal) of a complex array */
//--------------------------------------------------------

void shuffle(int N, complex *X)
{
       int n, r, B=1;

       while ( (N >> B) > 0 )             /* \(B\) = number of bits */
              B++;

       B--;                               /* \(N = 2\sp{B}\) */

       for (n = 0; n < N; n++) {
           r = bitrev(n, B);              /* bit-reversed version of \(n\) */
           if (r < n) continue;           /* swap only half of the \(n\)s */
           swap(X+n, X+r);                /* swap by addresses */
           }
}

//--------------------------------------------------------
/* dftmerge.c - DFT merging for radix 2 decimation-in-time FFT */
//--------------------------------------------------------

void dftmerge(int N, complex *XF)
{
       float pi = 4. * atan(1.0);
       int k, i, p, q, M;
       complex  A, B, V, W;

       M = 2;
       while (M <= N) {                          /* two \((M/2)\)-DFTs into one \(M\)-DFT  */
            W = cexp(cmplx(0.0, -2 * pi / M));   /* order-\(M\) twiddle factor */
            V = cmplx(1., 0.);                   /* successive powers of \(W\) */
            for (k = 0; k < M/2; k++) {          /* index for an \((M/2)\)-DFT */
                 for (i = 0; i < N; i += M) {    /* \(i\)th butterfly; increment by \(M\) */
                      p = k + i;                 /* absolute indices for */
                      q = p + M / 2;             /* \(i\)th butterfly */
                      A = XF[p];
                      B = cmul(XF[q], V);        /* \(V = W\sp{k}\) */
                      XF[p] = cadd(A, B);        /* butterfly operations */
                      XF[q] = csub(A, B);
                      }
                 V = cmul(V, W);                 /* \(V = VW = W\sp{k+1}\) */
                 }
            M = 2 * M;                           /* next stage */
            }
}

//--------------------------------------------------------
/* fft.c  --  in-place decimation-in-time FFT */
//--------------------------------------------------------

void fft(int N, complex *X)
{
       shuffle(N, X);
       dftmerge(N, X);
}

//--------------------------------------------------------
/* ifft.c - inverse FFT */
//--------------------------------------------------------

void ifft(int N, complex *X)
{
    int k;

    for (k=0; k<N; k++)
         X[k] = conjg(X[k]);                     /* conjugate input */

    fft(N, X);                                   /* compute FFT of conjugate */

    for (k=0; k<N; k++)
         X[k] = rdiv(conjg(X[k]), (float)N);     /* conjugate and divide by \(N\) */
}

//--------------------------------------------------------
/* dtft.c - DTFT of length-L signal at a single frequency w */
//--------------------------------------------------------

complex dtft(int L, float *x, float w)               /* usage: X=dtft(L, x, w); */
{
       complex z, X;
       int n;

       z = cexp(cmplx(0, -w));                       /* set \(z=e\sp{-j\om}\) */

       X = cmplx(0,0);                               /* initialize \(X=0\) */

       for (n=L-1; n>=0; n--)
              X = cadd(cmplx(x[n], 0), cmul(z, X));

       return X;
}

//--------------------------------------------------------
/* dtftr.c - N DTFT values over frequency range [wa, wb) */
//--------------------------------------------------------

void dtftr(int L, float *x, int N, complex *X, float wa, float wb)                     /* usage: dtftr(L, x, N, X, wa, wb); */
{
       int k;
       float dw = (wb-wa)/N;                      /* frequency bin width */

       for (k=0; k<N; k++)
              X[k] = dtft(L, x, wa + k*dw);        /* \(k\)th DTFT value \(X(\om\sb{k})\) */
}


//--------------------------------------------------------
/* dft.c - N-point DFT of length-L real-valued signal */
//--------------------------------------------------------

void dft(int L, float *x, int N, complex *X)                             /* usage: dft(L, x, N, X); */
{
       float pi = 4 * atan(1.0);

       dtftr(L, x, N, X, 0.0, 2*pi);             /* \(N\) frequencies over \([0,2\pi)\) */
}
