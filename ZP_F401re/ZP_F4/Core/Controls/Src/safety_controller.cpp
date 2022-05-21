/*
 * safety_controller.cpp
 *
 *  Created on: May 15, 2022
 *      Author: antho
 */

#include "../Inc/PWM.hpp"
#include "main.h"
// #include "../../Peripherals/Inc/PPM.hpp"

void safetyRun(){
	// Runs safety!
	 PWMChannel *pwm = new PWMChannel();
	 uint8_t max_channels = 2;
	 for(int i =0; i< max_channels; ++i) {
		 pwm->set(i, 75);
	 }

	 while (1) {
		 // toggle LED pin?
		 HAL_GPIO_TogglePin (LD2_GPIO_Port, LD2_Pin);
		 HAL_Delay (100);   /* Insert delay 100 ms */
	 }

	// PPM
//	PPMChannel *ppm = new PPMChannel(MAX_PPM_CHANNELS); // 8 currently max PPM channels
//	float PPM_values[MAX_PPM_CHANNELS-1];
//	while (1) {
//		for(int i = 0; i < MAX_PPM_CHANNELS; i++)
//		    {
//		        PPM_values[i] = ppm->get(i);
//		    }
//	}
}
