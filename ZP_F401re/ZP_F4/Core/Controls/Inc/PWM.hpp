/**
 * Implementation by Anthony Luo, 2022.
 * Test file to create PWM Outputs.
 *
 */

// iteration May 2022
// Tim3 Ch1&2 are pwm outs on pa6/pa7


#include <stdint.h>
#include "stm32f4xx_hal.h"
#include <stdbool.h>

#pragma once

typedef uint8_t PWMChannelNum;

typedef struct PWMPinConfig {
	uint16_t num;
	GPIO_TypeDef* port;
	TIM_HandleTypeDef *timer;     //handle to the timer
	uint16_t timer_channel;       //channel of the timer
  bool isUsingDshot;            //flag indicating if this configuration is for DSHOT
  uint32_t *dshotDMABuffer;     //pointer to DSHOT buffer, if applicable
  uint16_t timDMAHandleIndex;   //TIM DMA handle index , if applicable
  uint16_t timDMASource;        //TIM DMA source, if applicable

} PWMPinConfig;

/**
 * Represents a group of PWM outputs that map to a single timer
 * Settings can be changed on a per-group basis
 */
typedef enum PWMGroup {
	PWM_GROUP_1,
	PWM_GROUP_2,
	PWM_GROUP_3_4,
	PWM_GROUP_5_8,
	PWM_GROUP_9_12
} PWMGroup;

typedef struct PWMGroupSetting {
	uint32_t period; //period of pulse in us
	uint32_t min_length; //min pulse length in us
	uint32_t max_length; //max pulse length in us
	bool inverted;
} PWMGroupSetting;


class PWMChannel {
public:
	PWMChannel();
	void set(uint8_t channel, float percent);
private:
	//values in us
	uint32_t pwmPeriod = 20000;
	uint32_t min_signal = 950; //standard for 50hz pwm signal, with a 100 Hz margin added to ensure we can reach the extreme values.
	uint32_t max_signal = 2050;

/**
  * @brief Starts PWM generation of channels 1-4 on TIM1
  * @param dmaBuffer Pointer to the DMA buffer
  * @param None
  * @retval None
  */
    void dshotStartPWM();
};
