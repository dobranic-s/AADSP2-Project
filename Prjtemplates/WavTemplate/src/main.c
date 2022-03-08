#include "common.h"
#include "processing.h"
#include "stdfix_emu.h"
#include <stdlib.h>
#define BLOCK_SIZE 16
#define MAX_NUM_CHANNEL 8

fract sampleBuffer[MAX_NUM_CHANNEL][BLOCK_SIZE];
__memX DSPfract inputGain = FRACT_NUM(0.50118723362727224);
 
int main(int argc, char *argv[])
 {


    WAVREAD_HANDLE *wav_in;
    WAVWRITE_HANDLE *wav_out;
	
	char WavInputName[256];
	char WavOutputName[256];
	
    int nChannels;
	int bitsPerSample;
    int sampleRate;
    int iNumSamples;
    int i;
    int mode;
    int numOfChanel;
    mode = OM_2_2_1;
	if (mode == OM_2_0_0)
	{
		numOfChanel = 2;
	}
	else if (mode == OM_2_2_1)
	{
		numOfChanel = 5;
	}
	else if(mode == OM_2_2_0)
	{
		numOfChanel = 4;
	}
	else if(mode == OM1_2_2_0)
	{
		numOfChanel = 4;
	}



	for(i=0; i<MAX_NUM_CHANNEL; i++)
		memset(&sampleBuffer[i],0,BLOCK_SIZE);


	// Open input wav file
	//-------------------------------------------------
	strcpy(WavInputName,argv[0]);//"C:\\Users\\stevo\\Downloads\\Vezba3\\postavka\\TestStreams\\WhiteNoise.wav" );
	wav_in = cl_wavread_open(WavInputName);
	 if(wav_in == NULL)
    {
        printf("Error: Could not open wavefile.\n");
        return -1;
    }
	//-------------------------------------------------
	
	// Read input wav header
	//-------------------------------------------------
	nChannels = cl_wavread_getnchannels(wav_in);
    bitsPerSample = cl_wavread_bits_per_sample(wav_in);
    sampleRate = cl_wavread_frame_rate(wav_in);
    iNumSamples =  cl_wavread_number_of_frames(wav_in);
	//-------------------------------------------------
	
	// Open output wav file
	//-------------------------------------------------
	strcpy(WavOutputName,argv[1]);//"C:\\Users\\stevo\\Downloads\\Vezba3\\postavka\\TestStreams\\outmodel3.wav");
	wav_out = cl_wavwrite_open(WavOutputName, bitsPerSample, numOfChanel, sampleRate);
	if(!wav_out)
    {
        printf("Error: Could not open wavefile.\n");
        return -1;
    }
	//---------------- ---------------------------------
	
	// Processing loop
	//-------------------------------------------------	
    {
		int i;
		int j;
		int k;
		int sample;
		
		// exact file length should be handled correctly...
		for(i=0; i<iNumSamples/BLOCK_SIZE; i++)
		{	
			for(j=0; j<BLOCK_SIZE; j++)
			{
				for(k=0; k<nChannels; k++)
				{	
					sample = cl_wavread_recvsample(wav_in);
        			sampleBuffer[k][j] = rbits(sample);
				}
			}

			processing(sampleBuffer, sampleBuffer, inputGain , mode);

			for(j=0; j<BLOCK_SIZE; j++)
			{
				for(k=0; k<numOfChanel; k++)
				{	
					sample = bitsr(sampleBuffer[k][j]);
					cl_wavwrite_sendsample(wav_out, sample);
				}
			}		
		}
	}
	
	// Close files
	//-------------------------------------------------	
    cl_wavread_close(wav_in);
    cl_wavwrite_close(wav_out);
	//-------------------------------------------------	

    return 0;
 }
