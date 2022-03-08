/*
 * moduleProc_impl.c
 *
 * This file defines the actual implementation of the functions for 
 * moduleProc.
 */
#include <moduleProc_impl.h>
#include "processing.h"
/*
 * It is a good practice to make MCV shadow. That way host changes
 * are less likely to produce inconsistent state
 */
__memY mcv_t moduleProc_mcv_HOST = MCV_INITIAL_VALUES;
__memY mcv_t moduleProc_mcv = MCV_INITIAL_VALUES;

void __fg_call moduleProc_preKickstart(__memY void * mif_ptr)
{
	// <your code here>
}

void __fg_call moduleProc_postKickstart(void)
{
	// <your code here>
}

void __fg_call moduleProc_timer(void)
{
	// <your code here>
}

void __fg_call moduleProc_frame(void)
{
	// <your code here>
}

void __fg_call moduleProc_brick(void)
{
	// <your code here>
	if(moduleProc_mcv.enable)
	{
		processing(__X_BY_IOBUFFER_PTRS, __X_BY_IOBUFFER_PTRS, moduleProc_mcv.inputGain, moduleProc_mcv.Mode1, moduleProc_mcv.Mode2);
	}
}

void __bg_call moduleProc_background(void)
{
	// make a shadow copy of the MCV so that changes won't affect this function
	moduleProc_mcv = moduleProc_mcv_HOST;

	// <your code here>
}

void __fg_call moduleProc_preMallocInit(void)
{
	// <your code here>
}

void __fg_call moduleProc_postMallocInit(void)
{
	// <your code here>
}
