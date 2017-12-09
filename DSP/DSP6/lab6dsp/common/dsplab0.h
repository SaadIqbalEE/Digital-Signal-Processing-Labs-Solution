// dsplab0.h - common header file
//
// 332:348 DSP Lab - Spring 2011 - S. J. Orfanidis
// ------------------------------------------------- 

#include "dsk6713.h"
#include "dsk6713_aic23.h"

// ------------------------------------------------

#define LINE   0x0012
#define MIC    0x0014    
#define MICB   0x0015  
// MICB boosted by 20 dB  
// LINE was 0x0011

extern far void vectors();

void initialize();

void sampling_rate(short);
void audio_source(short);

void tx_ready();
void rx_ready();

short left_input();
short right_input();

void read_inputs(short *, short *);
void write_outputs(short, short);

float *pwrap(int, float *, float *);
int qwrap(int, int);
void delay(int, float *);













