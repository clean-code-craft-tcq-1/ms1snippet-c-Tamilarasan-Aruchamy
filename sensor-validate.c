#include "sensor-validate.h"


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
    int Isvalidinput=1;
	for(int Itr_Signal=0; Itr_Signal<Max_InputSignal; Itr_Signal++){
	    if(InputSignal[Itr_Signal].values!=NULL){
		    if(IsNoisySensorInputs(InputSignal[Itr_Signal].values,InputSignal[Itr_Signal].numOfValues,NoiseLimit[Itr_Signal])) {
			    InputSignal[Itr_Signal].NoiseDetected = true;
			    Isvalidinput=0;
		    }
	    }
			printf("\tNoiseDetected - %d\n",InputSignal[Itr_Signal].NoiseDetected);
	}
	return Isvalidinput;
}

int main()
{
    
#define TEST_CASE(a) printf("\nTest_Case_%d\n",a);


TEST_CASE(1);
        double tc1_Currentvalues[]={1,1,1,1.5,2};
        double tc1_SOCvalues[]={1,2,3,4,5,6};

        InputSignalConfig tc1_InputSignal[Max_InputSignal]={{tc1_Currentvalues,	sizeof(tc1_Currentvalues)/sizeof(double)},\
															{tc1_SOCvalues,		sizeof(tc1_SOCvalues)/sizeof(double)}};

        assert(validateReadings(tc1_InputSignal));

TEST_CASE(2);
        double tc2_Currentvalues[]={1,2,2,3,3};
        double tc2_SOCvalues[]={1,2,3,46,5,6};

        InputSignalConfig tc2_InputSignal[Max_InputSignal]={{tc2_Currentvalues,	sizeof(tc2_Currentvalues)/sizeof(double)},\
															{tc2_SOCvalues,		sizeof(tc2_SOCvalues)/sizeof(double)}};
        assert(!validateReadings(tc2_InputSignal));
		
TEST_CASE(3);
        double tc3_Currentvalues[]={1,2,2,3,3};
        double tc3_SOCvalues[]={1,2,3,46,5,6};

        InputSignalConfig tc3_InputSignal[Max_InputSignal]={{NULL,	sizeof(tc3_Currentvalues)/sizeof(double)},\
															{NULL,		sizeof(tc3_SOCvalues)/sizeof(double)}};

        assert(validateReadings(tc3_InputSignal));
		
		
 return 1;
	
}
