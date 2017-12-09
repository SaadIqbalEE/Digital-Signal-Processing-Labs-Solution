/* dsplab1.c - common definitions and functions (use with the FFT examples)
  
   332:348 DSP Lab - Spring 2012 - S. J. Orfanidis
   
----------------------------------------------------------------------------- 
  
  References:

  dsk6713_aic23_openCodec.c - Spectrum Digital, 2002
   
  D. R. Brown III, 2009 Workshop on Digital Signal Processing and
  Applications with the TMS320C6713 DSK, Parts 1 & 2, available online from:
  http://spinlab.wpi.edu/courses/dspworkshop/dspworkshop_part1_2009.pdf,
  http://spinlab.wpi.edu/courses/dspworkshop/dspworkshop_part2_2009.pdf
   
  N. Kehtarnavaz, "Real-Time Digital Signal Processing Based on the
  TMS320C6000", Newnes/Elsevier, Oxford, UK, 2005.
   
  R. Chassaing and D. Reay, "Digital Signal Processing and Applications with 
  the TMS320C6713 and TMS320C6416 DSK", 2nd ed., Wiley, Hoboken, NJ, 2008.
   
  S. J. Orfanidis, "Introduction to Signal Processing", online book, 2010,
  available from: http://www.ece.rutgers.edu/~orfanidi/intro2sp/
   
----------------------------------------------------------------------------- */

#include "dsplab.h"                       // function prototypes
#include "MCBSP.h"                         // MCBSP configuration

// --------- AIC conguration parameters and codec handle ---------------------

DSK6713_AIC23_Config config = DSK6713_AIC23_DEFAULTCONFIG;     // defined in dsk6713_aic23.h
DSK6713_AIC23_CodecHandle hcodec;

// --------- union to facilitate 32-bit data transfers -----------------------

union {
   Uint32 u;          // both channels packed as codec.u = 32-bits = | 16-bits left | 16-bits right |
   short c[2];        // left-channel = codec.c[1], right-channel = codec.c[0] 
} codec;

// --------- initialize DSK, McBSP, set up interrupts ------------------------

void initialize()						 	
{
  IRQ_globalDisable();           

  DSK6713_init();                   	                     // BSL initialization function

  hcodec=DSK6713_AIC23_openCodec(0, &config);                // codec handle

  MCBSP_config(DSK6713_AIC23_DATAHANDLE,&cfgdata32);         // reconfigure for 32-bit word transfers, defined in MCBSP.h

  MCBSP_start(DSK6713_AIC23_DATAHANDLE, MCBSP_XMIT_START | MCBSP_RCV_START | MCBSP_SRGR_START | MCBSP_SRGR_FRAMESYNC, 220);  

  eventID = MCBSP_getXmtEventId(DSK6713_AIC23_codecdatahandle);  

  IRQ_map(eventID, 11);		
  IRQ_reset(eventID);    	
  IRQ_globalEnable();       	
  IRQ_nmiEnable();          	
  IRQ_enable(eventID);		

  write_outputs(0,0) ;       	                             // write an output sample

  // change headphone volume - default was 0x00d8
  //DSK6713_AIC23_rset(hcodec, 0x0002, 0x01f9);  
  //DSK6713_AIC23_rset(hcodec, 0x0003, 0x01f9);

}

// --------- set sampling rate (in kHz) -----------------------------------------------
void sampling_rate(short fs) 
{
   switch (fs) {
       case  8: DSK6713_AIC23_setFreq(hcodec, 1); break;  
       case 16: DSK6713_AIC23_setFreq(hcodec, 2); break;
       case 24: DSK6713_AIC23_setFreq(hcodec, 3); break;
       case 32: DSK6713_AIC23_setFreq(hcodec, 4); break;
       case 44: DSK6713_AIC23_setFreq(hcodec, 5); break;
       case 48: DSK6713_AIC23_setFreq(hcodec, 6); break;
       case 96: DSK6713_AIC23_setFreq(hcodec, 7);
       }
}
// ------------------------------------------------------------------------------------


// --------- select stereo line-in or mic input ---------------------------------------
void audio_source(short source)
{
   if (source==LINE) 
        DSK6713_AIC23_rset(hcodec, 0x0004, LINE);
   else
        DSK6713_AIC23_rset(hcodec, 0x0004, MIC);
}// ------------------------------------------------------------------------------------


// --------- polling the MCBSP with functions tx_ready() and rx_ready() ----------------
// --------- to be used with vectors_poll.asm instead of vectors.asm -------------------
// --------- is MCBSP ready to transmit? -----------------------------------------------
void tx_ready()                  		
{
     while(!MCBSP_xrdy(DSK6713_AIC23_DATAHANDLE));       // wait till MCBSP is ready to transmit		
}
   
// --------- is MCBSP ready to receive? -----------------------------------------------
void rx_ready()                  		
{
     while(!MCBSP_rrdy(DSK6713_AIC23_DATAHANDLE));       // wait till MCBSP is ready to receive		
}
// ------------------------------------------------------------------------------------


// --------- read left channel --------------------------------------------------------
short left_input()                   		//input to left channel
{
	codec.u = MCBSP_read(DSK6713_AIC23_DATAHANDLE);        // read into left channel
	return(codec.c[1]);				       // return left channel data
}
// ------------------------------------------------------------------------------------
         
                                                      // DSK6713_AIC23_DATAHANDLE is defined in dsk6713_aic23.h
// --------- read right channel -------------------------------------------------------
short right_input()                   		//input to right channel
{
   codec.u = MCBSP_read(DSK6713_AIC23_DATAHANDLE);     // read into left channel
   return(codec.c[0]);				       // return left channel data
}
// ------------------------------------------------------------------------------------


// --------- read both left/right channels --------------------------------------------
void read_inputs(short *xL, short *xR)
{
   codec.u = MCBSP_read(DSK6713_AIC23_DATAHANDLE);       // read input data

   *xL = codec.c[1];  
   *xR = codec.c[0];
}
// ------------------------------------------------------------------------------------


// --------- write both left/right channels -------------------------------------------
void write_outputs(short yL, short yR)
{
   codec.c[1] = yL;
   codec.c[0] = yR;

   MCBSP_write(DSK6713_AIC23_DATAHANDLE,codec.u);      // write output data
}
// ------------------------------------------------------------------------------------


// --------- circular pointer wrapping relative to circular buffer --------------------
float *pwrap(int D,float *w, float *p)
{
   if (p > w+D) p -= D+1;          
   if (p < w)   p += D+1;    
      
   return p;
}
// ------------------------------------------------------------------------------------


// --------- circular pointer index wrapping ------------------------------------------
int qwrap(int D, int q)
{
       if (q > D)                  /* assumes q is in the bounds 0 <= q <= D */
              q -= D + 1;          /* when *q=D+1, it wraps around to *q=0 */

       if (q < 0)  
              q += D + 1;          /* when *q=-1, it wraps around to *q=D */

       return q;
}
// ------------------------------------------------------------------------------------


// --------- linear delay-line buffer updating ----------------------------------------
void delay(D,w)
int D;
float *w;
{
   int i;

   for (i=D; i>=1; i--)       
      w[i] = w[i-1];
}
// ------------------------------------------------------------------------------------
