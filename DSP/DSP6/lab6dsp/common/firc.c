// firc.c - FIR filter implemented with circular delay-line buffer 
//
// 332:348 DSP Lab - Spring 2011 - S. J. Orfanidis
//
// ---------------------------------------------------------------------------- 

float *pwrap(int, float *, float *);

float firc(int M, float *h, float *w, float **p, float x)
{                        
   int i;
   float y;

   **p = x;                                // read input sample x 

   for (y=0, i=0; i<=M; i++) {
      y += (*h++) * (**p);                 // i-th state s[i] = *pwrap(M,w,*p+i)
      *p = pwrap(M,w,++*p);                // pointer to state s[i+1] = *pwrap(M,w,*p+i+1)
      }

   *p = pwrap(M,w,--*p);                   // update circular delay line 

   return y;
}
