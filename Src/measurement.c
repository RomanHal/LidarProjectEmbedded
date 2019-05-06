#include <stdio.h>

#include "stepper.h"
#include "lidarCommunication.h"
#include "measurement.h"



int8_t angle=-50;
// Measurement measure[deviationSteps];
HorizontalMeasurement mesurement[horizontalSteps];
void MeasurementStructInit(void)
{
	
	// for(int i=0;i<deviationSteps;i++)
		{
			// measure[i].Angle=i-50;
			for(int j=0;j<horizontalSteps;j++)
			{
				mesurement[j].Angle=j;				
			}
		}
}

uint8_t makeMeasurement(void)
{
	MeasurementStructInit();
	static char direction=0x1;
	
			direction^=1;
			if(direction==0)
			{
				for(int j=0;j<horizontalSteps;j++)
				{
					mesurement[j].Distance= GetDistance();
					MakeStep(horizontal,1);
				}
			}
			else	
			{
				for(int j=horizontalSteps-1;j>-1;j--)
				{
					mesurement[j].Distance= GetDistance();
					MakeStep(horizontal,0);
				}
			}
		MakeStep(vertical,1);
		angle++;
		
	
	// for(int i=0;i<deviationSteps;i++)
	// 	{
	// 		direction^=1;
	// 		if(direction==0)
	// 		{
	// 			for(int j=0;j<horizontalSteps;i++)
	// 			{
	// 				measure[i].horizontal[j].Distance= GetDistance();
	// 				MakeStep(horizontal,1);
	// 			}
	// 		}
	// 		else	
	// 		{
	// 			for(int j=horizontalSteps-1;j>-1;i--)
	// 			{
	// 				measure[i].horizontal[j].Distance= GetDistance();
	// 				MakeStep(horizontal,0);
	// 			}
	// 		}
	// 	MakeStep(vertical,1);
	// 	}
	
	return 0;
}
