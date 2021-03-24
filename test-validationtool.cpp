#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "sensor-validate.h"

extern int validateReadings(InputSignalConfig InputSignal[Max_InputSignal]);

TEST_CASE("reports error when soc jumps abruptly") {
   double tc1_Currentvalues[]={1,1,1,1.5,2};
   double tc1_SOCvalues[]={1,2,3,4,5,15};
  InputSignalConfig tc1_InputSignal[Max_InputSignal]={	{tc1_Currentvalues,	sizeof(tc1_Currentvalues)/sizeof(double)},\
							{tc1_SOCvalues,		sizeof(tc1_SOCvalues)/sizeof(double)}};

  REQUIRE(validateReadings(tc1_InputSignal) == 0);
}

TEST_CASE("reports error when current jumps abruptly") {
        double tc2_Currentvalues[]={1,2,7,3,3};
        double tc2_SOCvalues[]={1,2,3,4,5,6};

        InputSignalConfig tc2_InputSignal[Max_InputSignal]={	{tc2_Currentvalues,	sizeof(tc2_Currentvalues)/sizeof(double)},\
								{tc2_SOCvalues,		sizeof(tc2_SOCvalues)/sizeof(double)}};
 
  REQUIRE(validateReadings(tc2_InputSignal) == 0);
  
}
  
TEST_CASE("Not report error when NULL parameter passed") {
        double tc3_Currentvalues[]={1,2,7,3,3};
        double tc3_SOCvalues[]={1,2,3,4,5,6};

        InputSignalConfig tc3_InputSignal[Max_InputSignal]={	{NULL,	sizeof(tc3_Currentvalues)/sizeof(double)},\
								{NULL,		sizeof(tc3_SOCvalues)/sizeof(double)}};
 
  REQUIRE(validateReadings(tc3_InputSignal) == 1);
  
  
}
