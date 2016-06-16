/*
 * diagnostic.c
 *
 *  Created on: 3 cze 2016
 *      Author: Łukasz
 */

#include "diagnostic.h"


 int showTempChange(const uint8_t tempPrev, const uint8_t temp)
{
	int value;
	if(tempPrev==temp)
	{
		Board_LED_Set(1, true); //green led
		Board_LED_Set(0, false);
		Board_LED_Set(2, false);
		value=1;
	}
	if(tempPrev>temp)
	{
		Board_LED_Set(2, true); //blue led
		Board_LED_Set(1, false);
		Board_LED_Set(0, false);
		value=2;
	}
	if(tempPrev<temp)
	{
		Board_LED_Set(0, true); //red led
		Board_LED_Set(2, false);
		Board_LED_Set(1, false);
		value=0;
	}

	return value;

}
