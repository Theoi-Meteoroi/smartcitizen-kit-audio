#ifndef _AUDIO_ANALYZER_H_INCLUDED
#define _AUDIO_ANALYZER_H_INCLUDED

#include <I2S_SCK.h>
#include <Arduino.h>

#define ARM_MATH_CM0PLUS
#include <arm_math.h>
#include <stddef.h>

#include "ConstantsSound.h"

enum WeightingType{
	A_WEIGHTING,
   	C_WEIGHTING,
   	Z_WEIGHTING
};

//CLASS
class AudioAnalyser
{
public:

  	bool begin(long sampleRate, int bitsPerSample);
  	void end();
	void scalingandwindow(void *vector, int vectorSize);
  	void equalising(void *inputBuffer, int inputSize, int sampleRate);	

};

#endif