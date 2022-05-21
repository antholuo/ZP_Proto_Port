#include "stm32f4xx_hal.h"
#include "../Inc/PWM.hpp"

#include <main.h>


#define MAX_CHANNELS 10
#define NUM_AVAILABLE_CHANNELS 2

extern TIM_HandleTypeDef htim3;

static const PWMPinConfig PWM_CONFIG[MAX_CHANNELS]
{
    {PWM1_Pin, PWM1_GPIO_Port, &htim3, TIM_CHANNEL_1, false, {0}, 0, 0},
    {PWM2_Pin, PWM2_GPIO_Port, &htim3, TIM_CHANNEL_2, false, {0}, 0, 0}
};

PWMChannel::PWMChannel()
{
    for(int i = 0; i < NUM_AVAILABLE_CHANNELS; i++)
    {
        const PWMPinConfig *currentChannel = &PWM_CONFIG[i];
        HAL_TIM_PWM_Start(currentChannel->timer,currentChannel->timer_channel);
    }
}

void PWMChannel::set(uint8_t channel, float percent)
{
    if(channel > MAX_CHANNELS || channel < 0)
    {
        channel = 0;
    }

    const PWMPinConfig * currentChannel = &PWM_CONFIG[channel];


    uint32_t prescaler = (static_cast<TIM_HandleTypeDef *>(currentChannel->timer))->Init.Prescaler;
	uint32_t us = (((uint8_t)percent * (PWMChannel::max_signal - PWMChannel::min_signal)) / 100 + PWMChannel::min_signal);
    uint32_t periodTicks = (static_cast<TIM_HandleTypeDef *>(currentChannel->timer))->Init.Period;
	uint32_t ticks = static_cast<uint32_t>((static_cast<float>(us) / static_cast<float>(pwmPeriod)) * static_cast<float>(periodTicks));
    __HAL_TIM_SET_COMPARE((TIM_HandleTypeDef *) currentChannel->timer, currentChannel->timer_channel, (uint32_t) ticks);

}
