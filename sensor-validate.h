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


static const double NoiseLimit[Max_InputSignal]={2,5};


