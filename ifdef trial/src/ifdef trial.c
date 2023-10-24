/*
 ============================================================================
 Name        : ifdef.c
 Author      : Ahmed Wael
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>

#define WITH_ENGINE_TEMPERATURE_CONTROLLER

int main(void) {

#ifdef WITH_ENGINE_TEMPERATURE_CONTROLLER
	printf("Engine Temperature Controller Enabled!\n");
#else
	printf("Engine Temperature Controller Disabled!\n");
#endif

}
