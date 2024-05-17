/*
 * encoder.c
 *
 *  Created on: May 1, 2024
 *      Author: wang
 */
#include "chassis/encoder.h"

encoder_t* encoder_hw_init(TIM_HandleTypeDef *timer)
{
    encoder_t* encoder = NULL;

    encoder = (encoder_t*)malloc(sizeof(encoder_t));
    encoder->timer = timer;
    encoder->timer->Instance->CNT = ENCODER_INIT_CNT;
    return encoder;
}

int encoder_get_cnt_diff(encoder_t* encoder)
{
    return encoder->timer->Instance->CNT - ENCODER_INIT_CNT;
}

void encoder_start_cnt(encoder_t* encoder)
{
	encoder->timer->Instance->CNT = ENCODER_INIT_CNT;
	HAL_TIM_Base_Start(encoder->timer);
}
