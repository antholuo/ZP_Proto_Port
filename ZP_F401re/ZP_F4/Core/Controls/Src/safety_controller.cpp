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
	 pwm->set(0, 75);
	 pwm->set(1, 25);
	 pwm->set(2, 75);
	 pwm->set(3, 25);
	 pwm->set(4, 75);
	 pwm->set(5, 25);
	 pwm->set(6, 75);
	 pwm->set(7, 25);

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
