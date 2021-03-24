#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#include <assert.h>


typedef enum
{
	CurrentSignal,
	SOC_Signal,
	Max_InputSignal
	
}InputSignalList;


typedef  struct
{
	double* values;
	int numOfValues;
	bool  NoiseDetected;
}InputSignalConfig;


enum Language
{
	English,
	German,
	Language_Max  // Add the new languages above this variable only.
};

typedef struct
{
	char FailureMessage [Language_Max][200];
}FailureMessageConfig;


int DisplayLanguage = English; // Default Language is English


static const double NoiseLimit[Max_InputSignal]={2,5}; // Index 0 - MaxDelta_CurrentSignal,1 - MaxDelta_SOCSignal

static const FailureMessageConfig FailureMessage[Max_InputSignal]= { \
		/* Index 0-In English , 1- In German */ \
	 {"Noise Detected in Current Input Signal","Rauschen im Stromeingangssignal erkannt"}, /* FailureMessage when Noise in Current Input */ \
	 {"Noise Detected in SOC Input Signal","Rauschen im SOC-Eingangssignal erkannt"}};	/* FailureMessage when Noise in SOC Input */

