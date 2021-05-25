/*
 *  @file 	main.c
 *  @brief	Application entry point
 *  @author Félix Armenta A - IECA PADTS 3
 *  @date	May 25th 2021
 */

#include <stdio.h> 	/**Standard input/output to debug console*/
#include <stdint.h> /**Standard integer definition provided by the compiler*/
#include "MK64F12.h"

#define DELAY 1500000
void delay(uint32_t delay);

int main(void){
	SIM->SCGC5 = 0x2400;	// Habilita el reloj para el periferico PORTB y PORTE

	PORTB->PCR[22] = 0x00000100;	// Pone la funcion de GPIO para el pin 22 con
									// su MUX por default - Ver tabla de pinout
	PORTE->PCR[26] = 0x00000100;	// MUX en GPIO para el PORTE_26
	PORTB->PCR[21] = 0x00000100;	// MUX en GPIO para el PORTB_21

	// Con un 1 se apagan los LED por el RGB de anado comun
	GPIOB->PDOR = 0x00600000;		// Manda un 1 logico al pin PORTB_22 y PORTB_21
	GPIOE->PDOR = 0x04000000;		// Manda un 1 logico al pin PORTE_26


	GPIOB->PDDR = 0x00600000;		// Se configura como salida el pin PORTB_22 y
									// PORTB_21
	GPIOE->PDDR = 0x04000000;		// Se configura como salida el pin PORTE_26

	while(1){
		GPIOE->PDOR = 0x04000000;
		GPIOB->PDOR = 0x00400000;
		printf("BLUE LED ON\n");
		delay(DELAY);

		GPIOB->PDOR = 0x00200000;
		printf("RED LED ON\n");
		delay(DELAY);

		GPIOB->PDOR = 0x00600000;
		GPIOE->PDOR = 0;
		printf("GREEN LED ON\n");
		delay(DELAY);
	}
	return 0;
}

void delay(uint32_t delay){
	volatile uint32_t i;
	for (i = 0; i < delay; i++) {
	}
}

