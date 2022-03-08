
#include <stdlib.h>
#include <string.h>
#include "WAVheader.h"
#include <math.h>
#include "processing.h"
#include "fixed_point_math.h"
#include "stdfix_emu.h"

DSPfract sampleBuffer[MAX_NUM_CHANNEL][BLOCK_SIZE];


DSPint mode = OM_2_2_1;
DSPint mode1 = 1;
DSPint mode2 = 0;
DSPfract inputGain = 0.501;
DSPint enable = 1;
DSPint numOfChanel = 5;

DSPint main(DSPint argc, char* argv[])
{	
	if (argc == 2)
	{
		printf("DEFAULT VALUE!!");
	}
	else if (argc != 7 && argc != 2)
	{
		printf("Nedovoljan broj argumenata");
		exit(1);
	}
	else
	{
		DSPfract g = pow(10.0, atof(argv[4]) / 20.0);
		enable = atoi(argv[3]);
		inputGain = FRACT_NUM(g);
		mode1 = atoi(argv[5]);
		mode2 = atoi(argv[6]);
		if (enable == 0)
		{
			mode = (OM_2_0_0);
			numOfChanel = 2;
		}
		else if (mode1 == 1) 
		{
			mode = OM_2_2_1;
			numOfChanel = 5;
		}
		else if(mode2 == 0)
		{
			mode = (OM_2_2_0);
			numOfChanel = 4;
		}
		else
		{
			mode = OM1_2_2_0;
			numOfChanel = 4;
		}
	}



	FILE *wav_in=NULL;
	FILE *wav_out=NULL;
	char WavInputName[256];
	char WavOutputName[256];
	WAV_HEADER inputWAVhdr,outputWAVhdr;	

	// Init channel buffers
	for(DSPint i=0; i<MAX_NUM_CHANNEL; i++)
		for(DSPint j=0; j<BLOCK_SIZE; j++)
			sampleBuffer[i][j] = FRACT_NUM(0.0);

	// Open input and output wav files
	//-------------------------------------------------
	strcpy(WavInputName,argv[1]);
	wav_in = OpenWavFileForRead (WavInputName,"rb");
	strcpy(WavOutputName,argv[2]);
	wav_out = OpenWavFileForRead (WavOutputName,"wb");
	//-------------------------------------------------

	// Read input wav header
	//-------------------------------------------------
	ReadWavHeader(wav_in,inputWAVhdr);
	//-------------------------------------------------
	
	// Set up output WAV header
	//-------------------------------------------------	
	outputWAVhdr = inputWAVhdr;
	outputWAVhdr.fmt.NumChannels = numOfChanel; //inputWAVhdr.fmt.NumChannels = 6; // change number of channels

	DSPint oneChannelSubChunk2Size = inputWAVhdr.data.SubChunk2Size/inputWAVhdr.fmt.NumChannels;
	DSPint oneChannelByteRate = inputWAVhdr.fmt.ByteRate/inputWAVhdr.fmt.NumChannels;
	DSPint oneChannelBlockAlign = inputWAVhdr.fmt.BlockAlign/inputWAVhdr.fmt.NumChannels;
	
	outputWAVhdr.data.SubChunk2Size = oneChannelSubChunk2Size*outputWAVhdr.fmt.NumChannels;
	outputWAVhdr.fmt.ByteRate = oneChannelByteRate*outputWAVhdr.fmt.NumChannels;
	outputWAVhdr.fmt.BlockAlign = oneChannelBlockAlign*outputWAVhdr.fmt.NumChannels;


	// Write output WAV header to file
	//-------------------------------------------------
	WriteWavHeader(wav_out,outputWAVhdr);


	// Processing loop
	//-------------------------------------------------	
	{
		DSPint sample;
		DSPint BytesPerSample = inputWAVhdr.fmt.BitsPerSample/8;
		const double SAMPLE_SCALE = -(double)(1 << 31);		//2^31
		DSPint iNumSamples = inputWAVhdr.data.SubChunk2Size/(inputWAVhdr.fmt.NumChannels*inputWAVhdr.fmt.BitsPerSample/8);
		
		// exact file length should be handled correctly...
		for(DSPint i=0; i<iNumSamples/BLOCK_SIZE; i++)
		{	
			for(DSPint j=0; j<BLOCK_SIZE; j++)
			{
				for(DSPint k=0; k<inputWAVhdr.fmt.NumChannels; k++)
				{	
					sample = 0; //debug
					fread(&sample, BytesPerSample, 1, wav_in);
					sample = sample << (32 - inputWAVhdr.fmt.BitsPerSample); // force signextend
					sampleBuffer[k][j] = sample / SAMPLE_SCALE;				// scale sample to 1.0/-1.0 range		
				}
			}

			//processing();
			processing(sampleBuffer, sampleBuffer, inputGain, mode);

			for(DSPint j=0; j<BLOCK_SIZE; j++)
			{
				for(DSPint k=0; k<outputWAVhdr.fmt.NumChannels; k++)
				{	
					sample = sampleBuffer[k][j].toLong();		// *SAMPLE_SCALE;	// crude, non-rounding 			
					sample = sample >> (32 - inputWAVhdr.fmt.BitsPerSample);
					fwrite(&sample, outputWAVhdr.fmt.BitsPerSample/8, 1, wav_out);		
				}
			}		
		}
	}
	
	// Close files
	//-------------------------------------------------	
	fclose(wav_in);
	fclose(wav_out);
	//-------------------------------------------------	

	return 0;
}