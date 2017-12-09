// wavgen.c - wavetable generator
//
// Usage: y = wavgen(D,w,A,F,&q);
//
// D = wavetable period in samples
// w = wavetable buffer holding one period of the waveform
// A = amplitude
// F = frequency in units of cycles/sample, i.e., F = f/fs, f=c*fs/D
// q = circular index, passed by address, gets shifted by q=q+c, c=D*F 
//
// y = current output sample
//
//
// 332:348 - DSP Lab - Spring 2011 - S. J. Orfanidis
// -------------------------------------------------

int qwrap(int, int);                                          // defined in dsplab.c

float wavgen(int D, float *w, float A, float F, int *q)       
{                        
   float y, c=D*F;

   y = A * w[*q];

   *q = qwrap(D-1, (int) (*q+c));

   return y;
}



