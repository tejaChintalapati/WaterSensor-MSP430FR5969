/*
 * mainApp.h
 *
 * Created on: Feb 05, 2016
 * Author: Teja Chintalapati
 * Contact: teja.chintalapati@gmail.com
 * Phone: +91-8792-355-512
 *
 */

#ifndef WATERSENSOR_SOURCE_MAINAPP_H_
#define WATERSENSOR_SOURCE_MAINAPP_H_

/******************************************************************************
 * INCLUDES
 */

#include <stdio.h>
#include <driverlib.h>
#include "clockInitialisation.h"
#include "pinInitialisation.h"
#include "portInitialisation.h"
#include "Water.h"

/******************************************************************************
 * DEFINITIONS
 */

//If you want to see clock frequencies, then make this true.
#define DEBUG																   false


//Used in pinInitialisation.c
#define WATERSENSORPORT														   GPIO_PORT_P2
#define WATERSENSORPIN														   GPIO_PIN4

//TODO: If you change these pins, please make appropriate changes in ISRs (pinInitialisation.c)

#define REDLEDPORT															   GPIO_PORT_P4
#define REDLEDPIN															   GPIO_PIN6
#define GREENLEDPORT														   GPIO_PORT_P1
#define GREENLEDPIN															   GPIO_PIN0

//Used in clockInitiaisation.c
#define LF_CRYSTAL_FREQUENCY_IN_HZ     										   32768
#define HF_CRYSTAL_FREQUENCY_IN_HZ											   0            // FR5969 Launchpad does not have 16MHz crystal

//Used in portInitialisation.c
#define allPins																   GPIO_PIN0 + GPIO_PIN1 + GPIO_PIN2 + GPIO_PIN3 + GPIO_PIN4 + GPIO_PIN5 + GPIO_PIN6 + GPIO_PIN7

/******************************************************************************
 * FUNCTION DECLARATION
 */

void boardInitialisation(void);

#endif /* WATERSENSOR_SOURCE_MAINAPP_H_ */
