/** @file moduleProc_impl.h
 *
 *  This file declares implementation data types for 
 *  moduleProc.
 */
 
#ifndef moduleProc_IMPL_H_
#define moduleProc_IMPL_H_ 

#include <stdfix.h>
#include <dsplib/cl_os.h>
#include <moduleProc_mcv.h>
#include <moduleProc_module.h>

extern __memY mcv_t moduleProc_mcv_HOST;
extern __memY mcv_t moduleProc_mcv;

extern void __fg_call moduleProc_preKickstart(__memY void * mif_ptr);
extern void __fg_call moduleProc_postKickstart(void);
extern void __fg_call moduleProc_timer(void);
extern void __fg_call moduleProc_frame(void);
extern void __fg_call moduleProc_brick(void);
extern void __bg_call moduleProc_background(void);
extern void __fg_call moduleProc_postMallocInit(void);
extern void __fg_call moduleProc_preMallocInit(void);

#endif
