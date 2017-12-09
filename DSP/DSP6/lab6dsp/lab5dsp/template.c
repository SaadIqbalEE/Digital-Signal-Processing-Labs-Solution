// template.c - to be used as starting point for interrupt-based programs
//
// 332:348 DSP Lab - Spring 2011 - S. J. Orfanidis
//
// ----------------------------------------------------------------------------------

#include "dsplab.h"          // DSK initialization declarations and function prototypes
// #include <math.h>, if necessary, or <stdio.h>, or <stdlib.h>

short xL, xR, yL, yR;        // left and right input and output samples from/to codec 
float g=1;                   // gain to demonstrate watch windows and GEL files (see template.gel)

// ----------------------------------------------------------------------------------
// here, add more global variable declarations, #define's, #include's, etc.
// ----------------------------------------------------------------------------------

void main()                  // main program executed first
{
  initialize();              // initialize DSK board and codec, define interrupts             

  sampling_rate(8);          // possible sampling rates: 8, 16, 24, 32, 44, 48, 96 kHz 
  audio_source(LINE);        // LINE or MIC for line or microphone input

  while(1);                  // keep waiting for interrupt, then jump to isr()
}
 
// ----------------------------------------------------------------------------------

interrupt void isr()         // sample processing algorithm - interrupt service routine
{
   read_inputs(&xL, &xR);    // read left and right input samples from codec
 
   yL = g * xL;              // replace these with your sample processing algorithm 
   yR = g * xR;

   write_outputs(yL,yR);     // write left and right output samples to codec        

   return;
}

// ----------------------------------------------------------------------------------
// here, add more functions to be called within isr() or main()
// ----------------------------------------------------------------------------------
