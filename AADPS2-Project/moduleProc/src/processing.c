
#include "processing.h"
#include "common.h"
#include "stdfix_emu.h"
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




__memX DSPfract IIR_low_pass_1000Hz_2nd_order[6] = { FRACT_NUM(0.0019610493309954297), FRACT_NUM(0.0039220986619908594), FRACT_NUM(0.0019610493309954297),
													 FRACT_NUM(0.50000000000000000000), FRACT_NUM(-0.90767054135228398), FRACT_NUM(0.41550279467337875) };


__memX DSPfract IIR_high_pass_500Hz_2nd_order[6] = { FRACT_NUM(0.47733080808442307), FRACT_NUM(-0.95466161616884615), FRACT_NUM(0.47733080808442307),
													 FRACT_NUM(0.50000000000000000000 ), FRACT_NUM(-0.95375081302680642), FRACT_NUM(0.45579724830353729) };


__memY static DSPfract l_x_history[2] = { FRACT_NUM(0.0), FRACT_NUM(0.0) };
__memY static DSPfract l_y_history[2] = { FRACT_NUM(0.0), FRACT_NUM(0.0) };
__memY static DSPfract r_x_history[2] = { FRACT_NUM(0.0), FRACT_NUM(0.0) };
__memY static DSPfract r_y_history[2] = { FRACT_NUM(0.0), FRACT_NUM(0.0) };


__memY DSPfract* leftChannelIn;
__memY DSPfract* rightChannelIn;
__memY DSPfract* leftChannelOut;
__memY DSPfract* rightChannelOut;
__memY DSPfract* leftSurroundChannelOut;
__memY DSPfract* rightSurroundChannelOut;
__memY DSPfract* lowFreqEffChannelOut;

DSPint mode;

void processing( __memY DSPfract* __memY* input, __memY DSPfract* __memY* output, DSPfract inputGain, DSPint mode1, DSPint mode2)
{	
	DSPint i;

	leftChannelIn = *input;
	input++;
	rightChannelIn = *input;
	
	leftChannelOut = *output;
	output++;
	rightChannelOut = *output;
	output++;
	leftSurroundChannelOut = *output;
	output++;
	rightSurroundChannelOut = *output;
	output++;
	lowFreqEffChannelOut = *output;
	if (mode1 == 1)
	{
		mode = OM_2_2_1;
	}
	else if (mode2 == 1)
	{
		mode = OM1_2_2_0;

	}
	else if(mode2 == 0)
	{
		mode = OM_2_2_0;

	}else
	{
		mode = OM_2_0_0;
	}

	if (mode == OM_2_2_1) // mode1 = 1
	{
		for (i = 0; i < BLOCK_SIZE; i++)
		{


			*leftSurroundChannelOut = inputGain * *leftChannelIn;	//Ls
			*rightSurroundChannelOut = inputGain * *rightChannelIn;	//Rs

			*leftChannelOut = second_order_IIR_asm((*leftSurroundChannelOut), IIR_low_pass_1000Hz_2nd_order, l_x_history, l_y_history);	// L
			*lowFreqEffChannelOut = *leftChannelOut;																							// LFE
			*rightChannelOut = second_order_IIR_asm((inputGain * *rightChannelIn), IIR_low_pass_1000Hz_2nd_order, r_x_history, r_y_history);	// R


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
		for (i = 0; i < BLOCK_SIZE; i++)
		{
			*leftSurroundChannelOut = inputGain * *leftChannelIn;	//Ls
			*rightSurroundChannelOut = inputGain * *rightChannelIn;	//Rs

			*leftChannelOut = second_order_IIR_asm((inputGain * *leftChannelIn), IIR_high_pass_500Hz_2nd_order, l_x_history, l_y_history);	// L
			
			*rightChannelOut = second_order_IIR_asm((inputGain * *rightChannelIn), IIR_high_pass_500Hz_2nd_order, r_x_history, r_y_history);	// R
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
		for (i = 0; i < BLOCK_SIZE; i++)
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
		for (i = 0; i < BLOCK_SIZE; i++)
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
