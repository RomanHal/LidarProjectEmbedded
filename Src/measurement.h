#include <stdint.h>

//360 degree 400 steps => 1 step 0.9 degree
#define horizontalSteps 400
//90 degree deviation (-45 to 45) 100 steps => 1 step 0.9 degree
#define deviationSteps 100

uint8_t makeMeasurement(void);
int sendData(void);



typedef struct 
{
	uint16_t Angle;
	int Distance;
} HorizontalMeasurement;

typedef struct
{
	uint8_t Angle;
	HorizontalMeasurement horizontal[horizontalSteps];
} Measurement;


