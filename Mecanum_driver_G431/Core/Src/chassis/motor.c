#include "chassis/motor.h"

extern TIM_HandleTypeDef MOTOR_PWM_TIMER;
extern TIM_HandleTypeDef ENCODER_A_TIMER;
extern TIM_HandleTypeDef ENCODER_B_TIMER;
extern TIM_HandleTypeDef ENCODER_C_TIMER;
extern TIM_HandleTypeDef ENCODER_D_TIMER;


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
	motor->hw.encoder = encoder_hw_init(&ENCODER_A_TIMER);

	motor = get_motor(MotorB);
	motor->hw.dir1_Port = MotorB_DIR1_GPIO_Port;
	motor->hw.dir1_Pin = MotorB_DIR1_Pin;
	motor->hw.dir2_Port = MotorB_DIR2_GPIO_Port;
	motor->hw.dir2_Pin = MotorB_DIR2_Pin;
	motor->hw.pin_mask_fwd = PIN_MASK_REVERSE;
	motor->hw.timer = &MOTOR_PWM_TIMER;
	motor->hw.pwm_channel = TIM_CHANNEL_2;
	motor->hw.encoder = encoder_hw_init(&ENCODER_B_TIMER);

	motor = get_motor(MotorC);
	motor->hw.dir1_Port = MotorC_DIR1_GPIO_Port;
	motor->hw.dir1_Pin = MotorC_DIR1_Pin;
	motor->hw.dir2_Port = MotorC_DIR2_GPIO_Port;
	motor->hw.dir2_Pin = MotorC_DIR2_Pin;
	motor->hw.pin_mask_fwd = PIN_MASK_FORWARD;
	motor->hw.timer = &MOTOR_PWM_TIMER;
	motor->hw.pwm_channel = TIM_CHANNEL_3;
	motor->hw.encoder = encoder_hw_init(&ENCODER_C_TIMER);

	motor = get_motor(MotorD);
	motor->hw.dir1_Port = MotorD_DIR1_GPIO_Port;
	motor->hw.dir1_Pin = MotorD_DIR1_Pin;
	motor->hw.dir2_Port = MotorD_DIR2_GPIO_Port;
	motor->hw.dir2_Pin = MotorD_DIR2_Pin;
	motor->hw.pin_mask_fwd = PIN_MASK_FORWARD;
	motor->hw.timer = &MOTOR_PWM_TIMER;
	motor->hw.pwm_channel = TIM_CHANNEL_4;
	motor->hw.encoder = encoder_hw_init(&ENCODER_D_TIMER);


}

void motor_run( motor_id_t idx, motor_ctl_t act)
{
	motor_t *motor = get_motor(idx);
	uint32_t dir1_pin_state = 0;
	uint32_t dir2_pin_state = 0;
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
	HAL_GPIO_WritePin(motor->hw.dir1_Port, motor->hw.dir1_Pin, dir1_pin_state);
	HAL_GPIO_WritePin(motor->hw.dir2_Port, motor->hw.dir2_Pin, dir2_pin_state);
	__HAL_TIM_SET_COMPARE(motor->hw.timer, motor->hw.pwm_channel, ccr);
	HAL_TIM_PWM_Start(motor->hw.timer, motor->hw.pwm_channel);
}

motor_state_t* motor_refresh_state(motor_id_t idx)
{
	float enc_cnt = 0;
	motor_t *motor = get_motor(idx);

	enc_cnt = (float)encoder_get_cnt_diff(motor->hw.encoder);
	motor->state.ang_vel = MOTOR_STATE_FRESH_HZ * (enc_cnt / MOTOR_RESOLUTION) * 360;
	motor->state.line_vel = motor->state.ang_vel * WHEEL_DIAMETER * 3.1415926;
	encoder_start_cnt(motor->hw.encoder);
	return &motor->state;
}

void motor_run_all(void)
{

}
