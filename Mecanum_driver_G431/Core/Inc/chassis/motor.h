#ifndef __Motor_H__
#define __Motor_H__
#include "main.h"

#define MOTOR_NUM		4
/* 使底盘向前运动的电机方向控制引脚掩码   BIT0: DIR1, BIT1:DIR2 */
#define	PIN_MASK_REVERSE	(0<<1 || 1<<0)
#define	PIN_MASK_FORWARD	(1<<1 || 0<<0)

#define MOTOR_PWM_TIMER		htim1


typedef enum {
	MT_FORWARD = 0,
	MT_STOP,
	MT_REVERSE
} motor_direction_t;

typedef enum {
	MotorA = 0,
	MotorB,
	MotorC,
	MotorD,
	MotorMax
} motor_id_t;

typedef struct{
	GPIO_TypeDef *dir1_Port;
	uint16_t dir1_Pin;
	GPIO_TypeDef *dir2_Port;
	uint16_t dir2_Pin;
	int pin_mask_fwd;
	TIM_HandleTypeDef *timer;
	uint32_t pwm_channel;
}motor_hw_t;

typedef struct {
	motor_direction_t dir;
	int speed;
}motor_ctl_t;

typedef struct{
	motor_hw_t hw;
	motor_ctl_t ctl;
}motor_t;


void motors_hw_init(void);
void motor_run( motor_id_t idx, motor_ctl_t act);

#endif
