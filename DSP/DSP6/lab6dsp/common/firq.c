/* firq.c - FIR filter implemented with circular delay-line buffer */

float firq(int M, float *h, float *w, int *q, float x)
{                        
   int i, Q;
   float y;

   Q = M - (*q); 

   w[*q] = x;                            // read input sample x 

   for (y=0, i=0; i<=Q; i++) 
      y += h[i] * w[(*q)++];        

   (*q) = 0;

   for (i=Q+1; i<=M; i++) 
      y += h[i] * w[(*q)++];

   (*q)--;  if (*q == -1) *q = M; 

   return y;
}



