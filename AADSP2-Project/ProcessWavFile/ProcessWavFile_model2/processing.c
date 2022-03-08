
#include "processing.h"
#include "common.h"
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


DSPfract IIR_low_pass_1000Hz_2nd_order[6] = { FRACT_NUM(0.00392209866199085940/2), FRACT_NUM(0.00784419732398171890/2), FRACT_NUM(0.00392209866199085940/2),
													 FRACT_NUM(1.00000000000000000000/2), FRACT_NUM((-1.81534108270456800000) / 2), FRACT_NUM(0.83100558934675750000/2) };


DSPfract IIR_high_pass_500Hz_2nd_order[6] = { FRACT_NUM(0.95466161616884615000/2), FRACT_NUM(-1.90932323233769230000 / 2), FRACT_NUM(0.95466161616884615000/2),
													 FRACT_NUM(1.00000000000000000000 / 2), FRACT_NUM(-1.90750162605361280000 / 2), FRACT_NUM(0.91159449660707459000/2) };


static DSPfract l_x_history[2] = { FRACT_NUM(0.0), FRACT_NUM(0.0) };
static DSPfract l_y_history[2] = { FRACT_NUM(0.0), FRACT_NUM(0.0) };
static DSPfract r_x_history[2] = { FRACT_NUM(0.0), FRACT_NUM(0.0) };
static DSPfract r_y_history[2] = { FRACT_NUM(0.0), FRACT_NUM(0.0) };




void processing(DSPfract input[][BLOCK_SIZE], DSPfract output[][BLOCK_SIZE], DSPfract inputGain, DSPint mode)
{	
	DSPfract* leftChannelIn = *input;
	input++;
	DSPfract* rightChannelIn = *input;
	
	DSPfract* leftChannelOut = *output;
	output++;
	DSPfract* rightChannelOut = *output;
	output++;
	DSPfract* leftSurroundChannelOut = *output;
	output++;
	DSPfract* rightSurroundChannelOut = *output;
	output++;
	DSPfract* lowFreqEffChannelOut = *output;
	

	if (mode == OM_2_2_1) // mode1 = 1
	{
		for (DSPint i = 0; i < BLOCK_SIZE; i++)
		{


			*leftSurroundChannelOut = inputGain * *leftChannelIn;	//Ls
			*rightSurroundChannelOut = inputGain * *rightChannelIn;	//Rs

			*leftChannelOut = second_order_IIR((*leftSurroundChannelOut), IIR_low_pass_1000Hz_2nd_order, l_x_history, l_y_history);	// L
			*lowFreqEffChannelOut = *leftChannelOut;																							// LFE
			*rightChannelOut = second_order_IIR((inputGain * *rightChannelIn), IIR_low_pass_1000Hz_2nd_order, r_x_history, r_y_history);	// R


			leftChannelIn++;
			rightChannelIn++;

			leftSurroundChannelOut++;
			rightSurroundChannelOut++;
			leftChannelOut++;
			lowFreqEffChannelOut++;
			rightChannelOut++;
		}

	}

	if (mode == OM_2_2_0)	// mode1 = 0 i mode2 = 0
	{
		for (DSPint i = 0; i < BLOCK_SIZE; i++)
		{
			*leftSurroundChannelOut = inputGain * *leftChannelIn;	//Ls
			*rightSurroundChannelOut = inputGain * *rightChannelIn;	//Rs

			*leftChannelOut = second_order_IIR((inputGain * *leftChannelIn), IIR_high_pass_500Hz_2nd_order, l_x_history, l_y_history);	// L
			
			*rightChannelOut = second_order_IIR((inputGain * *rightChannelIn), IIR_high_pass_500Hz_2nd_order, r_x_history, r_y_history);	// R
			leftChannelIn++;
			rightChannelIn++;

			leftSurroundChannelOut++;
			rightSurroundChannelOut++;
			leftChannelOut++;
			rightChannelOut++;
		}
	}

	if (mode == OM1_2_2_0)	// mode1 = 0 i mode2 = 1
	{
		for (DSPint i = 0; i < BLOCK_SIZE; i++)
		{
			*leftSurroundChannelOut = inputGain * *leftChannelIn;	//Ls
			*rightSurroundChannelOut = inputGain * *rightChannelIn;	//Rs

			*leftChannelOut = inputGain * *leftChannelIn;		//L

			*rightChannelOut = inputGain * *rightChannelIn;		//R
			
			leftChannelIn++;
			rightChannelIn++;

			leftSurroundChannelOut++;
			rightSurroundChannelOut++;

			leftChannelOut++;
			rightChannelOut++;
		}
	}
	
	if (mode == OM_2_0_0) // enable = 0
	{
		
		//Mix left and right channels and output result to center channel
		for (DSPint i = 0; i < BLOCK_SIZE; i++)
		{	
			*leftChannelOut = *leftChannelIn;	//L

			*rightChannelOut = *rightChannelIn;	//R
			
			leftChannelIn++;
			rightChannelIn++;

			leftChannelOut++;
			rightChannelOut++;
		}
	}
	

}
