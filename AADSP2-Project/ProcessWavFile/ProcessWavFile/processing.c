
#include "processing.h"
#include "IIR_low_pass_filter.h"

#define MAX_NUM_OUT_CH		5
#define MAX_NUM_IN_CH		2
#define MAX_NUM_OUT_MODE	3 

// Index of channels
#define L		0
#define R		1
#define Ls		2
#define Rs		3
#define LFE		4  
 

static const int outputChMask[MAX_NUM_OUT_MODE][MAX_NUM_OUT_CH] =
{
	//L  R Ls Rs LFE
	{ 1, 1, 0, 0, 0 },		//2.0.0 (stereo) enable = 0 
	{ 1, 1, 1, 1, 1 },		//2.2.1 mode1 = 1
	{ 1, 1, 1, 1, 0 }		//2.2.0 mode1 = 0 
};

int get_out_num_ch(int mode)
{
	int ret = 0;

	for (int i = 0; i < MAX_NUM_OUT_CH; i++)
	{
		ret += outputChMask[mode][i];
	}

	return ret;
}

int is_channel_active(int mode, int channel)
{
	return outputChMask[mode][channel];
}


/////////////////////////////////////////////////////////////////////////////////
// @Author	<student name>
// @Date		<date>  
//
// Function:
// multitap_echo
//
// @param - input - Buffer with input samples
//		  - output - Buffer with output samples
//		  - echo_state - Control state structure
//		  - mode - selected output mode
//
// @return - nothing
// Comment: Apply multichannel processing to input samples
//
// E-mail:	<email>
//
/////////////////////////////////////////////////////////////////////////////////


static double l_x_history[2];
static double l_y_history[2];
static double r_x_history[2];
static double r_y_history[2];

void processing(double input[][BLOCK_SIZE], double output[][BLOCK_SIZE], double inputGain, int mode)
{	
	
	if (mode == OM_2_2_1)	// mode1 = 1
	{
		for (int i = 0; i < BLOCK_SIZE; i++)
		{
			

			output[Ls][i] = inputGain * input[L][i];	//Ls

			output[Rs][i] = inputGain * input[R][i];

			output[L][i] = second_order_IIR((inputGain * input[L][i]), IIR_low_pass_1000Hz_2nd_order, l_x_history, l_y_history);

			output[LFE][i] = output[L][i];

			output[R][i] = second_order_IIR(inputGain * input[R][i], IIR_low_pass_1000Hz_2nd_order, r_x_history, r_y_history);


		}

	}

	if (mode == OM_2_2_0)	// mode1 = 0 i mode2 = 0
	{
		for (int i = 0; i < BLOCK_SIZE; i++)
		{
			output[Ls][i] = inputGain * input[L][i];	//Ls

			output[Rs][i] = inputGain * input[R][i];	//Rs

			output[L][i] = second_order_IIR((inputGain * input[L][i]), IIR_high_pass_500Hz_2nd_order, l_x_history, l_y_history);
			
			output[R][i] = second_order_IIR((inputGain * input[R][i]), IIR_high_pass_500Hz_2nd_order, r_x_history, r_y_history);

		}
	}

	if (mode == OM1_2_2_0)	// mode1 = 0 i mode2 = 1
	{
		for (int i = 0; i < BLOCK_SIZE; i++)
		{
			output[Ls][i] = inputGain * input[L][i];	//Ls

			output[L][i] = inputGain * input[L][i];		//L

			output[Rs][i] = inputGain * input[R][i];	//Rs

			output[R][i] = inputGain * input[R][i];		//R


		}
	}
	
	if (mode == OM_2_0_0)	// enable = 0
	{
		
		//Mix left and right channels and output result to center channel
		for (int i = 0; i < BLOCK_SIZE; i++)
		{	
			output[L][i] = input[L][i];	//L

			output[R][i] = input[R][i];	//R

		}
	}
	

}
