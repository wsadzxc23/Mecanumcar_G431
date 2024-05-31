/*
 * rosserial.cpp
 *
 *  Created on: May 21, 2024
 *      Author: wang
 */
#include "stdio.h"
#include "string.h"
#include "rosserial/rosserial.h"
#include <ros.h>
#include <std_msgs/String.h>
#include<geometry_msgs/Twist.h>

ros::NodeHandle nh;

std_msgs::String str_msg;
ros::Publisher chatter("chatter", &str_msg);

void chassis_ctl_callback(const geometry_msgs::Twist& cmd_vel)
{
//  char buf[128] = {0};
//  snprintf(buf, sizeof(buf),"twist msg:vx:%f, vy:%f, vw:%f\r\n", cmd_vel.linear.x, cmd_vel.linear.x, cmd_vel.angular.z);
//  str_msg.data = buf;
//  chatter.publish(&str_msg);
  printf("twist msg:vx:%f, vy:%f, vw:%f\r\n", cmd_vel.linear.x, cmd_vel.linear.x, cmd_vel.angular.z);
}

ros::Subscriber<geometry_msgs::Twist> sub_cmdvel("turtle1/cmd_vel", &chassis_ctl_callback );
char hello[] = "i have changed source location!!!\r\n";

void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart){
  nh.getHardware()->flush();
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){
  nh.getHardware()->reset_rbuf();
}

void setup(void)
{
  nh.initNode();
  nh.advertise(chatter);
  nh.subscribe(sub_cmdvel);
}

void loop(void)
{

  nh.spinOnce();
}



