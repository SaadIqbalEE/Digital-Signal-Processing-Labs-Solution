// template.c - to be used as starting point for interrupt-based programs
//
// 332:348 DSP Lab - Spring 2011 - S. J. Orfanidis
//
// ----------------------------------------------------------------------------------

#include "dsplab.h" // init parameters and function prototypes
short xL, xR, yL, yR; // input and output samples from/to codec
#define D 8000 // max delay in samples (TD = D/fs = 8000/8000 = 1 sec)
short fs = 8; // sampling rate in kHz
float w[D+1], *p, x, y; // circular delay-line buffer, circular pointer, input, output
int d = 4000; // must be d <= D
// ----------------------------------------------------------------------------------
void main() // main program executed first
{
int n;
for (n=0; n<=D; n++) // initialize circular buffer to zero
w[n] = 0;
p = w; // initialize pointer
initialize(); // initialize DSK board and codec, define interrupts
sampling_rate(fs); // possible sampling rates: 8, 16, 24, 32, 44, 48, 96 kHz
audio_source(MIC); // use LINE or MIC for line or microphone input
while(1); // keep waiting for interrupt, then jump to isr()
}
// ----------------------------------------------------------------------------------
interrupt void isr() // sample processing algorithm - interrupt service routine
{
read_inputs(&xL, &xR); // read left and right input samples from codec
x = (float) xL; // work with left input only
y = *pwrap(D,w,p+d); // delayed output - pwrap defined in dsplab.c
*p = x; // delay-line input
p = pwrap(D,w,--p); // backshift pointer
yL = yR = (short) y;
write_outputs(yL,yR); // write left and right output samples to codec
return;
}
