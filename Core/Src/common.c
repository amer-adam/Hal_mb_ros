
/*********************************************/
/*          Include Header                   */
/*********************************************/
#include "common.h"
#include "math.h"

void set() {
	Initialize();
//	PSxInit(&ps4,&hi2c1);
	TIMxInit(&htim6, 20000, 84, 1, 0);
//		TIMxInit(&htim2, 5000, 84, 1, 0);
//	HAL_Delay(700);
//	RNS_config(&hcan1);
//	led3=!led3;
//	speed = 4;
//	Reset();
}


//void RNS_config(CAN_HandleTypeDef* hcanx) {
//	RNSInit(hcanx, &rns);
//	HAL_Delay(500);
//	RNSSet(&rns, RNS_DEVICE_CONFIG, (float) 0b10100100, (float) fwd_omni,
//			(float) roboconPID);
//
//	RNSSet(&rns, RNS_X_Y_ENC_CONFIG, 0.05 / 2000.0 * 3.142, 1.0,
//			0.05 / 2000.0 * 3.142, 1.0); //1.0 for nonswap , 2.0 for swap
//	RNSSet(&rns, RNS_F_KCD_PTD, 2442.748 / 2444.161,
//			0.150 * 3.142 / 244.2748);
//	RNSSet(&rns, RNS_B_KCD_PTD, 2438.506 / 2443.219,
//			0.150 * 3.142 / 243.8506);
//
//	RNSSet(&rns, RNS_F_LEFT_VEL_SATEU, 1.0, 1.0 / 13.247, 19999.0);
//
//	RNSSet(&rns, RNS_F_RIGHT_VEL_SATEU, 1.0, 1.0 / 14.5880 , 19999.0);
//
//	RNSSet(&rns, RNS_B_LEFT_VEL_SATEU, 1.0, 1.0 / 13.732, 19999.0);
//
//	RNSSet(&rns, RNS_B_RIGHT_VEL_SATEU, 1.0, 1.0 / 12.131, 19999.0);
//
//	RNSSet(&rns, RNS_F_LEFT_VEL_PID, 1.7, 7.0, 0.0);   // 1.7 2.0 0.0
//	RNSSet(&rns, RNS_F_RIGHT_VEL_PID, 2.5, 7.0, 0.0);  // 2.5 2.0 0.0
//	RNSSet(&rns, RNS_B_LEFT_VEL_PID, 2.0, 7.0, 0.0);   // 2.0 2.0 0.0
//	RNSSet(&rns, RNS_B_RIGHT_VEL_PID, 2.4, 7.0, 0.0);  // 2.4 2.0 0.0
//
//	RNSSet(&rns, RNS_PPInit); //Path Planning
//	RNSSet(&rns, RNS_PPPathPID, 1.0, 0.1, 0.5);
//	RNSSet(&rns, RNS_PPEndPID, 0.5, 0.1, 0.7);
//	RNSSet(&rns, RNS_PPZPID, 2.0, 1.0, 0.5, 1.0);
//	RNSSet(&rns, RNS_PPSetCRV_PTS, 10.0);         // Change No. of Points in the Curved Path
//
//	//	RNSSet(&rns,RNS_LF_LSA_POS,(float)AT_FRONT,(float)AT_BACK,(float)AT_LEFT,(float)AT_RIGHT);
//}
//

