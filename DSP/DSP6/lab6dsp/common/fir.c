// fir.c - FIR filter in direct form 
//
// 332:348 DSP Lab - Spring 2011 - S. J. Orfanidis
//
// ---------------------------------------------------------------------------- 

float fir(int M, float *h, float *w, float x)                       /* Usage: y=fir(M, h, w, x); */
{                        
       int i;
       float y;                             /* y=output sample */

       w[0] = x;                             /* read current input sample x */

       for (y=0, i=0; i<=M; i++)
              y += h[i] * w[i];              /* process current output sample */

       for (i=M; i>=1; i--)                  /* update states for next call */
              w[i] = w[i-1];                 /* done in reverse order */

       return y;
}
