// delay.c - update linear delay-line buffer
//
// Usage: delay(D,w)
//
// w = (D+1)-dimensional circular buffer
// updates delay contents by: for (i=D; i>=1; i--) w[i] = w[i-1];
//
//  332:348 DSP Lab - Spring 2011 - S. J. Orfanidis

void delay(D,w)
int D;
double *w;
{
   int i;

   for (i=D; i>=1; i--)       
      w[i] = w[i-1];
}




