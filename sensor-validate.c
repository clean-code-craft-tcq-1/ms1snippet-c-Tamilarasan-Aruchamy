#include "sensor-validate.h"


int suddenJumpDetected(double value, double nextValue, double maxDelta);

int IsNoisySensorInputs(double* values, int numOfValues, double maxDelta);

int validateReadings(InputSignalConfig InputSignal[Max_InputSignal]);

extern int mainController(InputSignalConfig InputSignal[Max_InputSignal]);




int suddenJumpDetected(double value, double nextValue, double maxDelta) {
  if(abs(nextValue - value) > maxDelta) {
    return 1;
  }
  return 0;
}

int IsNoisySensorInputs(double* values, int numOfValues,double maxDelta) {
  int lastButOneIndex = numOfValues - 1;
  for(int i = 0; i < lastButOneIndex; i++) {
    if(suddenJumpDetected(values[i], values[i + 1], maxDelta)) {
      return 1;
    }
  }
  return 0;
}

int validateReadings(InputSignalConfig InputSignal[Max_InputSignal])
{	
	for(int Itr_Signal=0; Itr_Signal<Max_InputSignal; Itr_Signal++){
	    if(InputSignal[Itr_Signal].values!=NULL){
		   InputSignal[Itr_Signal].NoiseDetected = IsNoisySensorInputs(InputSignal[Itr_Signal].values,InputSignal[Itr_Signal].numOfValues,NoiseLimit[Itr_Signal]);
		    
			}
		    
	    }
			
	return mainController(InputSignal);
}
