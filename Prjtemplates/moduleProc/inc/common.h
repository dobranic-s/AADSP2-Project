#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <dsplib\wavefile.h>
#include <stdfix.h>
#include <string.h>

/////////////////////////////////////////////////////////////////////////////////
// Constant definitions
/////////////////////////////////////////////////////////////////////////////////
#define BLOCK_SIZE 16
#define MAX_NUM_CHANNEL 8
/////////////////////////////////////////////////////////////////////////////////

/* DSP type definitions */
typedef short DSPshort;					/* DSP integer */
typedef unsigned short DSPushort;		/* DSP unsigned integer */
typedef int DSPint;						/* native integer */
typedef _Fract DSPfract;				/* DSP fixed-point fractional */
typedef long _Accum  DSPaccum;				/* DSP fixed-point fractional */

#endif
