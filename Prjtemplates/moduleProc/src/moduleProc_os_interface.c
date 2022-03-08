/*
 * moduleProc.c
 *
 * This file defines the data structures necessary for a module that fits into
 * the Cirrus Logic OS Framework.
 */
#include <moduleProc_impl.h>
 
/*
 * Define the MCT for moduleProc
 */
static __memY mct_t moduleProc_mct = {
	&moduleProc_preKickstart,			// prekick function
	&moduleProc_postKickstart,			// postkick function
	&moduleProc_timer,					// timer function
	&moduleProc_frame,					// frame function
	&moduleProc_brick,					// block function
	0,										// reserved
	&moduleProc_background,			// background function
	&moduleProc_postMallocInit,		// post-malloc function
	&moduleProc_preMallocInit			// pre-malloc function
};

/* 
 * Define the MIF for moduleProc
 */
__memY mif_t moduleProc_mif = {
	&moduleProc_mcv_HOST,
	&moduleProc_mct
};
