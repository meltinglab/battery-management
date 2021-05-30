/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: bms_private.h
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

#ifndef RTW_HEADER_bms_private_h_
#define RTW_HEADER_bms_private_h_
#include "rtwtypes.h"
#include "bms.h"

extern real_T look1_binlxpw(real_T u0, const real_T bp0[], const real_T table[],
  uint32_T maxIndex);
extern void bms_Chart1_Init(boolean_T rty_balancingCmd[10], real_T
  *rty_DeltaVCell, boolean_T *rty_balancingFlag);
extern void bms_Chart1(SystemState_t rtu_SystemState, const real_T
  rtu_SegmentVoltageVector[10], real_T rtu_CellMaxV, real_T rtu_CellMinV,
  boolean_T rty_balancingCmd[10], real_T *rty_DeltaVCell, boolean_T
  *rty_balancingFlag, DW_Chart1_bms_T *localDW);

#endif                                 /* RTW_HEADER_bms_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
