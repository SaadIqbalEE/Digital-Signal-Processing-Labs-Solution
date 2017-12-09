// firc2.c - FIR filter implemented with circular delay-line buffer 
//
// 332:348 DSP Lab - Spring 2011 - S. J. Orfanidis
//
// ---------------------------------------------------------------------------- 

int qwrap(int, int);

float firc2(int M, float *h, float *w, int *q, float x)
{                        
   int i;
   float y;

   w[*q] = x;                            // read input sample x 

   for (y=0, i=0; i<=M; i++) {
      y += *h++ * w[*q];                 // i-th state s[i] = w[*q]
      *q = qwrap(M,++*q);                // pointer to state s[i+1] = w[*q+1]
      }

   *q = qwrap(M,--*q);                   // update circular delay line 

   return y;
}



