#include "chassis/motor.h"

extern TIM_HandleTypeDef MOTOR_PWM_TIMER;

motor_t *g_motors = NULL;

motor_t* get_motor(motor_id_t idx)
{
	return (g_motors + (sizeof(motor_t) * idx) );
}

void motors_hw_init(void)
{
	motor_t *motor = NULL;

	g_motors = malloc(sizeof(motor_t) * MotorMax);

	motor = get_motor(MotorA);
	motor->hw.dir1_Port = MotorA_DIR1_GPIO_Port;
	motor->hw.dir1_Pin = MotorA_DIR1_Pin;
	motor->hw.dir2_Port = MotorA_DIR2_GPIO_Port;
	motor->hw.dir2_Pin = MotorA_DIR2_Pin;
	motor->hw.pin_mask_fwd = PIN_MASK_REVERSE;
	motor->hw.timer = &MOTOR_PWM_TIMER;
	motor->hw.pwm_channel = TIM_CHANNEL_1;

	motor = get_motor(MotorB);
	motor->hw.dir1_Port = MotorB_DIR1_GPIO_Port;
	motor->hw.dir1_Pin = MotorB_DIR1_Pin;
	motor->hw.dir2_Port = MotorB_DIR2_GPIO_Port;
	motor->hw.dir2_Pin = MotorB_DIR2_Pin;
	motor->hw.pin_mask_fwd = PIN_MASK_REVERSE;
	motor->hw.timer = &MOTOR_PWM_TIMER;
	motor->hw.pwm_channel = TIM_CHANNEL_2;

	motor = get_motor(MotorC);
	motor->hw.dir1_Port = MotorC_DIR1_GPIO_Port;
	motor->hw.dir1_Pin = MotorC_DIR1_Pin;
	motor->hw.dir2_Port = MotorC_DIR2_GPIO_Port;
	motor->hw.dir2_Pin = MotorC_DIR2_Pin;
	motor->hw.pin_mask_fwd = PIN_MASK_FORWARD;
	motor->hw.timer = &MOTOR_PWM_TIMER;
	motor->hw.pwm_channel = TIM_CHANNEL_3;

	motor = get_motor(MotorD);
	motor->hw.dir1_Port = MotorD_DIR1_GPIO_Port;
	motor->hw.dir1_Pin = MotorD_DIR1_Pin;
	motor->hw.dir2_Port = MotorD_DIR2_GPIO_Port;
	motor->hw.dir2_Pin = MotorD_DIR2_Pin;
	motor->hw.pin_mask_fwd = PIN_MASK_FORWARD;
	motor->hw.timer = &MOTOR_PWM_TIMER;
	motor->hw.pwm_channel = TIM_CHANNEL_4;


}

void motor_run( motor_id_t idx, motor_ctl_t act)
{
	motor_t *motor = get_motor(idx);
	int dir1_pin_state = 0;
	int dir2_pin_state = 0;
	uint32_t ccr = 0;

	act.speed = act.speed >= 100 ? 100:act.speed;
	ccr = (motor->hw.timer->Init.Period * act.speed ) / 100;

	switch (act.dir) {
		case MT_FORWARD:
			dir1_pin_state = motor->hw.pin_mask_fwd & (1<<0);
			dir2_pin_state = motor->hw.pin_mask_fwd & (1<<1);
			break;
		case MT_REVERSE:
			dir1_pin_state = ~(motor->hw.pin_mask_fwd) & (1<<0);
			dir2_pin_state = ~(motor->hw.pin_mask_fwd) & (1<<1);
			break;
		default:
			HAL_TIM_PWM_Stop(motor->hw.timer, motor->hw.pwm_channel);
			break;
	}
	HAL_TIM_Base_Start(motor->hw.timer);
	HAL_GPIO_WritePin(motor->hw.dir1_Port, motor->hw.dir1_Pin, 0);
	HAL_GPIO_WritePin(motor->hw.dir2_Port, motor->hw.dir2_Pin, 1);
	__HAL_TIM_SET_COMPARE(motor->hw.timer, motor->hw.pwm_channel, ccr);
	HAL_TIM_PWM_Start(motor->hw.timer, motor->hw.pwm_channel);
}

void motor_run_all(void)
{

}
