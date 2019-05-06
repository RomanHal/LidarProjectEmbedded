#include <stdint.h>
#include "main.h"

typedef enum
{
	horizontal,
	vertical
} Steppers;


void MakeStep(Steppers stepper, uint8_t direction);
