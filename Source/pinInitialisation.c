/*
 * 	pinInitialisation.c
 *
 *  Created on: Feb 05, 2016
 *  Author: Teja Chintalapati
 *	Contact: teja.chintalapati@gmail.com
 *	Phone: +91-8792-355-512
 *	Description: This file will initialise all pins required in this program
 *
 */

/******************************************************************************
 * INCLUDES
 */

#include "mainApp.h"

/******************************************************************************
 * FUNCTION DEFINITIONS
 */

void pinConfiguration(void)
{
    /*
     * Set LFXT clock pins to crystal input. By default, they're configured as GPIO.
     * If you don't configure these pins, your code will be stuck in CS_turnOnLFXT function
     */
    GPIO_setAsPeripheralModuleFunctionInputPin( GPIO_PORT_PJ, GPIO_PIN4 + GPIO_PIN5, GPIO_PRIMARY_MODULE_FUNCTION );

    //Configure Red and Green LEDs
    GPIO_setAsOutputPin(GREENLEDPORT, GREENLEDPIN);
    GPIO_setOutputLowOnPin(GREENLEDPORT, GREENLEDPIN);

    GPIO_setAsOutputPin(REDLEDPORT, REDLEDPIN);
    GPIO_setOutputLowOnPin(REDLEDPORT, REDLEDPIN);

    //Configuring Flame Sensor Pin
    GPIO_setAsInputPinWithPullUpResistor(WATERSENSORPORT, WATERSENSORPIN);
    if(GPIO_getInputPinValue(WATERSENSORPORT, WATERSENSORPIN))
    {
    	//If water is not present initially
    	GPIO_selectInterruptEdge(WATERSENSORPORT, WATERSENSORPIN, GPIO_HIGH_TO_LOW_TRANSITION);
    	GPIO_setOutputHighOnPin(REDLEDPORT, REDLEDPIN);
    	GPIO_setOutputLowOnPin(GREENLEDPORT, GREENLEDPIN);
    }
    else
    {
    	//If water is present around the sensor initially
    	GPIO_selectInterruptEdge(WATERSENSORPORT, WATERSENSORPIN, GPIO_LOW_TO_HIGH_TRANSITION);
    	GPIO_setOutputLowOnPin(REDLEDPORT, REDLEDPIN);
    	GPIO_setOutputHighOnPin(GREENLEDPORT, GREENLEDPIN);
    }
    GPIO_clearInterrupt(WATERSENSORPORT, allPins);
    GPIO_enableInterrupt(WATERSENSORPORT, WATERSENSORPIN);
}

/*
 * Port ISRs
 */
//#pragma vector = PORT1_VECTOR;
//__interrupt void Port1_ISR(void)
//{
//	switch(__even_in_range(P1IV, P1IV_P1IFG7))
//	{
//	case P1IV_NONE : break;							//No Interrupt pending
//	case P1IV_P1IFG0 : break;						//(0x02) P1.0 interrupt
//	case P1IV_P1IFG1 : break;						//(0x04) P1.1 interrupt
//	case P1IV_P1IFG2 : break;						//(0x06) P1.2 interrupt
//	case P1IV_P1IFG3 : break;						//(0x08) P1.3 interrupt
//	case P1IV_P1IFG4 : break;						//(0x0A) P1.4 interrupt
//	case P1IV_P1IFG5 : break;						//(0x0C) P1.5 interrupt
//	case P1IV_P1IFG6 : break;						//(0x0E) P1.6 interrupt
//	case P1IV_P1IFG7 : break;						//(0x10) P1.7 interrupt
//	default :
//		__never_executed();
//		break;
//	}
//}

#pragma vector = PORT2_VECTOR;
__interrupt void Port2_ISR(void)
{
	switch(__even_in_range(P2IV, P2IV_P2IFG7))
	{
	case P2IV_NONE : break;							//No Interrupt pending
	case P2IV_P2IFG0 : break;						//(0x02) P2.0 interrupt
	case P2IV_P2IFG1 : break;						//(0x04) P2.1 interrupt
	case P2IV_P2IFG2 : break;						//(0x06) P2.2 interrupt
	case P2IV_P2IFG3 : break;						//(0x08) P2.3 interrupt
	case P2IV_P2IFG4 :								//(0x0A) P2.4 interrupt
		__low_power_mode_off_on_exit();
		break;
	case P2IV_P2IFG5 : break;						//(0x0C) P2.5 interrupt
	case P2IV_P2IFG6 : break;						//(0x0E) P2.6 interrupt
	case P2IV_P2IFG7 : break;						//(0x10) P2.7 interrupt
	default :
		__never_executed();
		break;
	}
}

//#pragma vector = PORT3_VECTOR;
//__interrupt void Port3_ISR(void)
//{
//	switch(__even_in_range(P3IV, P3IV_P3IFG7))
//	{
//	case P3IV_NONE : break;							//No Interrupt pending
//	case P3IV_P3IFG0 : break;						//(0x02) P3.0 interrupt
//	case P3IV_P3IFG1 : break;						//(0x04) P3.1 interrupt
//	case P3IV_P3IFG2 : break;						//(0x06) P3.2 interrupt
//	case P3IV_P3IFG3 : break;						//(0x08) P3.3 interrupt
//	case P3IV_P3IFG4 : break;						//(0x0A) P3.4 interrupt
//	case P3IV_P3IFG5 : break;						//(0x0C) P3.5 interrupt
//	case P3IV_P3IFG6 : break;						//(0x0E) P3.6 interrupt
//	case P3IV_P3IFG7 : break;						//(0x10) P3.7 interrupt
//	default :
//		__never_executed();
//		break;
//	}
//}

//#pragma vector = PORT4_VECTOR;
//__interrupt void Port4_ISR(void)
//{
//	switch(__even_in_range(P4IV, P4IV_P4IFG7))
//	{
//	case P4IV_NONE : break;							//No Interrupt pending
//	case P4IV_P4IFG0 : break;						//(0x02) P4.0 interrupt
//	case P4IV_P4IFG1 : break;						//(0x04) P4.1 interrupt
//	case P4IV_P4IFG2 : break;						//(0x06) P4.2 interrupt
//	case P4IV_P4IFG3 : break;						//(0x08) P4.3 interrupt
//	case P4IV_P4IFG4 : break;						//(0x0A) P4.4 interrupt
//	case P4IV_P4IFG5 : break;						//(0x0C) P4.5 interrupt
//	case P4IV_P4IFG6 : break;						//(0x0E) P4.6 interrupt
//	case P4IV_P4IFG7 : break;						//(0x10) P4.7 interrupt
//	default :
//		__never_executed();
//		break;
//	}
//}
