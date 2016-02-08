/*
 *  Water.c
 *
 *  Created on: Feb 05, 2016
 *  Author: Teja Chintalapati
 *	Contact: teja.chintalapati@gmail.com
 *	Phone: +91-8792-355-512
 *	Description: Contains code to handle Water Sensor Interrupt
 *
 */

/******************************************************************************
 * INCLUDES
 */

#include "mainApp.h"

/******************************************************************************
 * FUNCTION DEFINITIONS
 */

void processWaterSensorInterrupt(void)
{
	//TODO: If you change port to which sensor is connected, please change PxIES below accordingly
	if(P2IES & WATERSENSORPIN)					//High to low
	{
		GPIO_selectInterruptEdge(WATERSENSORPORT, WATERSENSORPIN, GPIO_LOW_TO_HIGH_TRANSITION);
		GPIO_setOutputHighOnPin(GREENLEDPORT, GREENLEDPIN);
		GPIO_setOutputLowOnPin(REDLEDPORT, REDLEDPIN);
	}
	else
	{
		GPIO_selectInterruptEdge(WATERSENSORPORT, WATERSENSORPIN, GPIO_HIGH_TO_LOW_TRANSITION);
		GPIO_setOutputLowOnPin(GREENLEDPORT, GREENLEDPIN);
		GPIO_setOutputHighOnPin(REDLEDPORT, REDLEDPIN);
	}
}
