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

int get_out_num_ch(int mode);

int is_channel_active(int mode, int channel);

void processing(double input[][BLOCK_SIZE], double inpit[][BLOCK_SIZE], double inputGain, int mode);

#if __cplusplus
}
#endif

#endif // !PROCESSING_H
