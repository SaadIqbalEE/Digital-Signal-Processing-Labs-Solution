// fft.h - fft function declarations
//
// struct complex is defined in cmplx.h, which also includes math.h
//
// struct complex{float x, y;};      
// typedef struct complex complex;
//
// S. J. Orfanidis, "Introduction to Signal Processing", online book, 2010,
// available from: http://www.ece.rutgers.edu/~orfanidi/intro2sp/

#include "cmplx.h"                          // includes <math.h>     

int bitrev(int, int);                       // bit reversal
void swap(complex *, complex *);            // swap two complex numbers 
void shuffle(int, complex *);               // shuffling
void dftmerge(int, complex *);              // dft merge
void fft(int, complex *);                   // fft consisting of shuffling + dftmerge
void ifft(int, complex *);                  // inverse fft by fft

complex dtft(int, float *, float);          // dtft by Horner's rule at single frequency

void dtftr(int, float *, int, complex *, float, float);   // dtft over frequency range

void dft(int, float *, int, complex *);     // dft by evaluation of dtft at dft frequencies
