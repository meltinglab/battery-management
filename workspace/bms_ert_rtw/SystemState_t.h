/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: SystemState_t.h
 *
 * Code generated for Simulink model 'bms'.
 *
 * Model version                  : 1.27
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Sat May 29 15:36:42 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_SystemState_t_h_
#define RTW_HEADER_SystemState_t_h_
#include "rtwtypes.h"

/* General System State enum typedef */
typedef int16_T SystemState_t;

/* enum SystemState_t */
#define SystemState_t_Parking          ((SystemState_t)0)        /* Default value */
#define SystemState_t_Driving          ((SystemState_t)1)
#define SystemState_t_Charging         ((SystemState_t)2)
#define SystemState_t_Balancing        ((SystemState_t)3)
#endif                                 /* RTW_HEADER_SystemState_t_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
