/*
 * This file is automatically generated by CLIDE
 *
 * MCV (Module Control Vector)
 */

#include <dsplib/platform_support.h>
#include <dsplib/cl_os.h> 
#include <dsplib/meter.h>
#include <dsplib/response.h>

typedef union {
	void __memY * y_ptr;
	void __memX * x_ptr;
	void __memXY * xy_ptr;
} unspecified_zone_ptr;

#define	isDefined 	 true


typedef __memY struct {
	bool enable;	 // bool	non-zero to enable this function
	int Mode1;	 //int
	int Mode2;	 //int
	fract inputGain;	 //fract(1.31)
} mcv_t;


#define MCV_INITIAL_VALUES { false, 1, 0, FRACT_NUM_SCALE_R(0.5, 31) }

