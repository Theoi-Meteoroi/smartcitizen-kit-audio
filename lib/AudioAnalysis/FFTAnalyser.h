#ifndef _FFT_ANALYSER_H_INCLUDED
#define _FFT_ANALYSER_H_INCLUDED

#include <Arduino.h>

#define ARM_MATH_CM0PLUS
#include <arm_math.h>

#include "AudioAnalyser.h"
#include "ConstantsSound.h"

//CLASS
class FFTAnalyser : public AudioAnalyser
{
public:

  FFTAnalyser();
  ~FFTAnalyser();

  bool allocateBuffer(int bufferSize, int fftSize, WeightingType weightingType);
  bool initI2S(int sampleRate, int bitsPerSample);
  bool initFFT(int fftSize);
  bool terminateBuffer();
  float getReading(int spectrum[]);
  float getReading();
  bool bufferFilled();

private:

  void weighting(void *inputBuffer, int inputSize);
  void convert2DB(void *inputVector, void *outputVector, int vectorSize, int factor);
  double rms(void *inputBuffer, int inputSize, int typeRMS, int factor);
  void fft(void *inputBuffer, void* outputBuffer, int fftBufferSize);  
  
  //BUFFER Sizes
  int _fftSize;
  int _bufferSize; //Already usable bufferSize
  int _bufferIndex;
  WeightingType _weightingType;
  int _sampleRate;
  int _bitsPerSample;
  float _rmsSpecB;
  //BUFFERS
  void* _sampleBuffer;
  void* _fftBuffer;
  void* _spectrumBuffer;
  void* _spectrumBufferDB;
  //FFT
  arm_rfft_instance_q31 _S31;

};

#endif