#ifndef PROCESSING_H
#define PROCESSING_H


#include "common.h"

#if __cplusplus
extern "C" {
#endif

enum OUTPUT_MODES
{
	OM_2_0_0 = 0,
	OM_2_2_1 = 1,
	OM_2_2_0 = 2,
	OM1_2_2_0 = 3

};


void processing(DSPfract input[][BLOCK_SIZE],DSPfract inpit[][BLOCK_SIZE], DSPfract inputGain, DSPint mode);

#if __cplusplus
}
#endif

#endif // !PROCESSING_H
