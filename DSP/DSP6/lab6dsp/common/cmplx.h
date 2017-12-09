// cmplx.h - complex arithmetic declarations 
//
// S. J. Orfanidis, "Introduction to Signal Processing", online book, 2010,
// available from: http://www.ece.rutgers.edu/~orfanidi/intro2sp/


#include <math.h>                     

struct complex{float x, y;};   
typedef struct complex complex;
   
float cabs(struct complex);       

complex cmplx(float, float);            /* define complex number */
complex conjg(complex);                 /* complex conjugate */

complex cadd(complex, complex);         /* complex addition */
complex csub(complex, complex);         /* complex subtraction */
complex cmul(complex, complex);         /* complex multiplication */
complex cdiv(complex, complex);         /* complex division */

complex rmul(float, complex);           /* multiplication by real */
complex rdiv(complex, float);           /* division by real */

float real(complex);                    /* real part */
float aimag(complex);                   /* imaginary part */

complex cexp(complex);                  /* complex exponential */
