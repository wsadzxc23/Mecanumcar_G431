/*
 * encoder.h
 *
 *  Created on: May 1, 2024
 *      Author: wang
 */

#ifndef INC_CHASSIS_ENCODER_H_
#define INC_CHASSIS_ENCODER_H_
#include "main.h"

#define ENCODER_A_TIMER     htim2
#define ENCODER_B_TIMER     htim3
#define ENCODER_C_TIMER     htim4
#define ENCODER_D_TIMER     htim8

#define ENCODER_RESOLUTION  11
#define ENCODER_INIT_CNT    32767
/* 电机转动一圈编码器的脉冲数 */
#define MOTOR_RESOLUTION  (MOTOR_REDUCTION_RATIO*ENCODER_RESOLUTION*4)

typedef struct encoder
{
	TIM_HandleTypeDef *timer;

}encoder_t;


encoder_t* encoder_hw_init(TIM_HandleTypeDef *timer);
int encoder_get_cnt_diff(encoder_t* encoder);
void encoder_start_cnt(encoder_t* encoder);

#endif /* INC_CHASSIS_ENCODER_H_ */
