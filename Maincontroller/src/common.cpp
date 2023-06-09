/*
 * common.cpp
 *
 *  Created on: 2020.07.16
 *      Author: JackyPan
 */
#include "maincontroller.h"

static bool _soft_armed=false;//心跳包中表示是否解锁的标志位
static bool _thr_force_decrease=false;//强制油门下降
ROBOT_STATE robot_state=STATE_NONE;
ROBOT_STATE robot_state_desired=STATE_NONE;
ROBOT_MAIN_MODE robot_main_mode=MODE_AIR;
ROBOT_SUB_MODE robot_sub_mode=MODE_AUTONAV;

bool get_soft_armed(void){
	return _soft_armed;
}

void set_soft_armed(bool soft_armed){
	_soft_armed=soft_armed;
}

bool get_thr_force_decrease(void){
	return _thr_force_decrease;
}

void set_thr_force_decrease(bool force_decrease){
	_thr_force_decrease=force_decrease;
}

bool mode_init(void){
	return mode_autonav_init();
}

//should be run at 400hz
void mode_update(void){
	mode_autonav();
}
