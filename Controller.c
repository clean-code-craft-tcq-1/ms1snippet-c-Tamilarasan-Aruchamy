#include "sensor-validate.h"


int mainController(InputSignalConfig InputSignal[Max_InputSignal])
{
int IsValidSignals=1;



for(int Itr_Signal=0; Itr_Signal<Max_InputSignal; Itr_Signal++){
		   if(InputSignal[Itr_Signal].NoiseDetected){
			   IsValidSignals=0;
		   }
		   printf("\tNoiseDetected - %d\n",InputSignal[Itr_Signal].NoiseDetected);
		}
return IsValidSignals;

}
