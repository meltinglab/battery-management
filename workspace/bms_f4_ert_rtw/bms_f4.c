/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: bms_f4.c
 *
 * Code generated for Simulink model 'bms_f4'.
 *
 * Model version                  : 1.33
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Mon May 31 17:07:59 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "bms_f4.h"
#include "bms_f4_private.h"

/* Named constants for Chart: '<S4>/Chart1' */
#define bms_f4_IN_Balancing            ((uint8_T)1U)
#define bms_f4_IN_BalancingFinished    ((uint8_T)2U)
#define bms_f4_IN_MeasureVoltages      ((uint8_T)3U)
#define bms_f4_IN_NO_ACTIVE_CHILD      ((uint8_T)0U)
#define bms_f4_IN_OFF                  ((uint8_T)1U)
#define bms_f4_IN_ON                   ((uint8_T)2U)
#define bms_f4_IN_WaitRelaxation       ((uint8_T)4U)

/* Named constants for Chart: '<S3>/Chart' */
#define bms_f4_IN_charging             ((uint8_T)1U)
#define bms_f4_IN_dis_charger          ((uint8_T)2U)
#define bms_f4_IN_dis_inverter         ((uint8_T)3U)
#define bms_f4_IN_driving              ((uint8_T)4U)
#define bms_f4_IN_en_charger           ((uint8_T)5U)
#define bms_f4_IN_en_charger_prechrg   ((uint8_T)6U)
#define bms_f4_IN_en_inverter          ((uint8_T)7U)
#define bms_f4_IN_en_inverter_prechrg  ((uint8_T)8U)
#define bms_f4_IN_init                 ((uint8_T)9U)

/* Block signals (default storage) */
B_bms_f4_T bms_f4_B;

/* Block states (default storage) */
DW_bms_f4_T bms_f4_DW;

/* External inputs (root inport signals with default storage) */
ExtU_bms_f4_T bms_f4_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_bms_f4_T bms_f4_Y;

/* Real-time model */
static RT_MODEL_bms_f4_T bms_f4_M_;
RT_MODEL_bms_f4_T *const bms_f4_M = &bms_f4_M_;
real_T look1_binlxpw(real_T u0, const real_T bp0[], const real_T table[],
                     uint32_T maxIndex)
{
  real_T frac;
  real_T yL_0d0;
  uint32_T bpIdx;
  uint32_T iLeft;
  uint32_T iRght;

  /* Column-major Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Linear'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = (u0 - bp0[0U]) / (bp0[1U] - bp0[0U]);
  } else if (u0 < bp0[maxIndex]) {
    /* Binary Search */
    bpIdx = maxIndex >> 1U;
    iLeft = 0U;
    iRght = maxIndex;
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex - 1U;
    frac = (u0 - bp0[maxIndex - 1U]) / (bp0[maxIndex] - bp0[maxIndex - 1U]);
  }

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  yL_0d0 = table[iLeft];
  return (table[iLeft + 1U] - yL_0d0) * frac + yL_0d0;
}

/*
 * System initialize for atomic system:
 *    '<S4>/Chart1'
 *    '<S4>/Chart2'
 *    '<S4>/Chart3'
 */
void bms_f4_Chart1_Init(boolean_T rty_balancingCmd[10], real_T *rty_DeltaVCell,
  boolean_T *rty_balancingFlag)
{
  int32_T i;
  for (i = 0; i < 10; i++) {
    rty_balancingCmd[i] = false;
  }

  *rty_DeltaVCell = 0.0;
  *rty_balancingFlag = false;
}

/*
 * Output and update for atomic system:
 *    '<S4>/Chart1'
 *    '<S4>/Chart2'
 *    '<S4>/Chart3'
 */
void bms_f4_Chart1(SystemState_t rtu_SystemState, const real_T
                   rtu_SegmentVoltageVector[10], real_T rtu_CellMaxV, real_T
                   rtu_CellMinV, boolean_T rty_balancingCmd[10], real_T
                   *rty_DeltaVCell, boolean_T *rty_balancingFlag,
                   DW_Chart1_bms_f4_T *localDW)
{
  int32_T i;
  boolean_T exitg1;
  if (localDW->temporalCounter_i1 < MAX_uint32_T) {
    localDW->temporalCounter_i1++;
  }

  /* Chart: '<S4>/Chart1' */
  if (localDW->is_active_c2_bms_f4 == 0U) {
    localDW->is_active_c2_bms_f4 = 1U;
    localDW->is_c2_bms_f4 = bms_f4_IN_OFF;
    for (i = 0; i < 10; i++) {
      rty_balancingCmd[i] = false;
    }

    *rty_balancingFlag = false;
    *rty_DeltaVCell = rtu_CellMaxV - rtu_CellMinV;
  } else if (localDW->is_c2_bms_f4 == bms_f4_IN_OFF) {
    if ((rtu_SystemState == SystemState_t_Balancing) && (*rty_DeltaVCell >
         bms_f4_P.DeltaVTargetMin)) {
      localDW->is_c2_bms_f4 = bms_f4_IN_ON;
      *rty_balancingFlag = true;
      localDW->is_ON = bms_f4_IN_Balancing;
      localDW->temporalCounter_i1 = 0U;
      for (i = 0; i < 10; i++) {
        rty_balancingCmd[i] = (rtu_SegmentVoltageVector[i] - rtu_CellMinV >
          bms_f4_P.DeltaVTargetMin);
      }

      localDW->flagBalancingDone = true;
      i = 0;
      exitg1 = false;
      while ((!exitg1) && (i < 10)) {
        if (rty_balancingCmd[i]) {
          localDW->flagBalancingDone = false;
          exitg1 = true;
        } else {
          i++;
        }
      }

      *rty_balancingFlag = true;
    } else {
      *rty_DeltaVCell = rtu_CellMaxV - rtu_CellMinV;
    }

    /* case IN_ON: */
  } else if (rtu_SystemState != SystemState_t_Balancing) {
    localDW->is_ON = bms_f4_IN_NO_ACTIVE_CHILD;
    localDW->is_c2_bms_f4 = bms_f4_IN_OFF;
    for (i = 0; i < 10; i++) {
      rty_balancingCmd[i] = false;
    }

    *rty_balancingFlag = false;
    *rty_DeltaVCell = rtu_CellMaxV - rtu_CellMinV;
  } else {
    switch (localDW->is_ON) {
     case bms_f4_IN_Balancing:
      if (localDW->flagBalancingDone) {
        localDW->is_ON = bms_f4_IN_BalancingFinished;
        *rty_DeltaVCell = rtu_CellMaxV - rtu_CellMinV;
        *rty_balancingFlag = false;
      } else if ((!localDW->flagBalancingDone) && ((uint32_T)((int32_T)
                   localDW->temporalCounter_i1 * 10) >= (uint32_T)ceil
                  (bms_f4_P.balancingTime))) {
        localDW->is_ON = bms_f4_IN_WaitRelaxation;
        localDW->temporalCounter_i1 = 0U;
        for (i = 0; i < 10; i++) {
          rty_balancingCmd[i] = false;
        }
      }
      break;

     case bms_f4_IN_BalancingFinished:
      if (*rty_DeltaVCell > bms_f4_P.DeltaVTargetMin) {
        localDW->is_ON = bms_f4_IN_Balancing;
        localDW->temporalCounter_i1 = 0U;
        for (i = 0; i < 10; i++) {
          rty_balancingCmd[i] = (rtu_SegmentVoltageVector[i] - rtu_CellMinV >
            bms_f4_P.DeltaVTargetMin);
        }

        localDW->flagBalancingDone = true;
        i = 0;
        exitg1 = false;
        while ((!exitg1) && (i < 10)) {
          if (rty_balancingCmd[i]) {
            localDW->flagBalancingDone = false;
            exitg1 = true;
          } else {
            i++;
          }
        }

        *rty_balancingFlag = true;
      } else {
        *rty_DeltaVCell = rtu_CellMaxV - rtu_CellMinV;
        *rty_balancingFlag = false;
      }
      break;

     case bms_f4_IN_MeasureVoltages:
      localDW->is_ON = bms_f4_IN_Balancing;
      localDW->temporalCounter_i1 = 0U;
      for (i = 0; i < 10; i++) {
        rty_balancingCmd[i] = (rtu_SegmentVoltageVector[i] - rtu_CellMinV >
          bms_f4_P.DeltaVTargetMin);
      }

      localDW->flagBalancingDone = true;
      i = 0;
      exitg1 = false;
      while ((!exitg1) && (i < 10)) {
        if (rty_balancingCmd[i]) {
          localDW->flagBalancingDone = false;
          exitg1 = true;
        } else {
          i++;
        }
      }

      *rty_balancingFlag = true;
      break;

     default:
      /* case IN_WaitRelaxation: */
      if ((uint32_T)((int32_T)localDW->temporalCounter_i1 * 10) >= (uint32_T)
          ceil(bms_f4_P.balancingRelaxationTime)) {
        localDW->is_ON = bms_f4_IN_MeasureVoltages;
        *rty_DeltaVCell = rtu_CellMaxV - rtu_CellMinV;
      }
      break;
    }
  }

  /* End of Chart: '<S4>/Chart1' */
}

/* Model step function */
void bms_f4_step(void)
{
  real_T rtb_nDLookupTable;
  real_T u1;
  real_T u1_tmp_0;
  real_T u1_tmp_1;
  real_T u1_tmp_2;
  int32_T sigIdx;
  int32_T u1_tmp;
  SystemState_t tmp;
  boolean_T tmp_0;
  boolean_T tmp_1;
  boolean_T tmp_2;

  /* Concatenate: '<S1>/Matrix Concatenate' incorporates:
   *  SignalConversion generated from: '<S5>/Transpose'
   *  SignalConversion generated from: '<S6>/Transpose'
   *  SignalConversion generated from: '<S7>/Transpose'
   */
  bms_f4_Y.ToPlant.BusSOCEstimation.EKFEstimation[0] = 0.0;
  bms_f4_Y.ToPlant.BusSOCEstimation.EKFEstimation[3] = 0.0;
  bms_f4_Y.ToPlant.BusSOCEstimation.EKFEstimation[6] = 0.0;
  bms_f4_Y.ToPlant.BusSOCEstimation.EKFEstimation[9] = 0.0;
  bms_f4_Y.ToPlant.BusSOCEstimation.EKFEstimation[12] = 0.0;
  bms_f4_Y.ToPlant.BusSOCEstimation.EKFEstimation[15] = 0.0;
  bms_f4_Y.ToPlant.BusSOCEstimation.EKFEstimation[18] = 0.0;
  bms_f4_Y.ToPlant.BusSOCEstimation.EKFEstimation[21] = 0.0;
  bms_f4_Y.ToPlant.BusSOCEstimation.EKFEstimation[24] = 0.0;
  bms_f4_Y.ToPlant.BusSOCEstimation.EKFEstimation[27] = 0.0;
  bms_f4_Y.ToPlant.BusSOCEstimation.EKFEstimation[1] = 0.0;
  bms_f4_Y.ToPlant.BusSOCEstimation.EKFEstimation[4] = 0.0;
  bms_f4_Y.ToPlant.BusSOCEstimation.EKFEstimation[7] = 0.0;
  bms_f4_Y.ToPlant.BusSOCEstimation.EKFEstimation[10] = 0.0;
  bms_f4_Y.ToPlant.BusSOCEstimation.EKFEstimation[13] = 0.0;
  bms_f4_Y.ToPlant.BusSOCEstimation.EKFEstimation[16] = 0.0;
  bms_f4_Y.ToPlant.BusSOCEstimation.EKFEstimation[19] = 0.0;
  bms_f4_Y.ToPlant.BusSOCEstimation.EKFEstimation[22] = 0.0;
  bms_f4_Y.ToPlant.BusSOCEstimation.EKFEstimation[25] = 0.0;
  bms_f4_Y.ToPlant.BusSOCEstimation.EKFEstimation[28] = 0.0;
  bms_f4_Y.ToPlant.BusSOCEstimation.EKFEstimation[2] = 0.0;
  bms_f4_Y.ToPlant.BusSOCEstimation.EKFEstimation[5] = 0.0;
  bms_f4_Y.ToPlant.BusSOCEstimation.EKFEstimation[8] = 0.0;
  bms_f4_Y.ToPlant.BusSOCEstimation.EKFEstimation[11] = 0.0;
  bms_f4_Y.ToPlant.BusSOCEstimation.EKFEstimation[14] = 0.0;
  bms_f4_Y.ToPlant.BusSOCEstimation.EKFEstimation[17] = 0.0;
  bms_f4_Y.ToPlant.BusSOCEstimation.EKFEstimation[20] = 0.0;
  bms_f4_Y.ToPlant.BusSOCEstimation.EKFEstimation[23] = 0.0;
  bms_f4_Y.ToPlant.BusSOCEstimation.EKFEstimation[26] = 0.0;
  bms_f4_Y.ToPlant.BusSOCEstimation.EKFEstimation[29] = 0.0;

  /* Concatenate: '<S1>/Matrix Concatenate1' incorporates:
   *  DiscreteIntegrator: '<S10>/Discrete-Time Integrator'
   *  DiscreteIntegrator: '<S11>/Discrete-Time Integrator'
   *  DiscreteIntegrator: '<S12>/Discrete-Time Integrator'
   *  DiscreteIntegrator: '<S13>/Discrete-Time Integrator'
   *  DiscreteIntegrator: '<S14>/Discrete-Time Integrator'
   *  DiscreteIntegrator: '<S15>/Discrete-Time Integrator'
   *  DiscreteIntegrator: '<S16>/Discrete-Time Integrator'
   *  DiscreteIntegrator: '<S17>/Discrete-Time Integrator'
   *  DiscreteIntegrator: '<S18>/Discrete-Time Integrator'
   *  DiscreteIntegrator: '<S19>/Discrete-Time Integrator'
   *  DiscreteIntegrator: '<S20>/Discrete-Time Integrator'
   *  DiscreteIntegrator: '<S21>/Discrete-Time Integrator'
   *  DiscreteIntegrator: '<S22>/Discrete-Time Integrator'
   *  DiscreteIntegrator: '<S23>/Discrete-Time Integrator'
   *  DiscreteIntegrator: '<S24>/Discrete-Time Integrator'
   *  DiscreteIntegrator: '<S25>/Discrete-Time Integrator'
   *  DiscreteIntegrator: '<S26>/Discrete-Time Integrator'
   *  DiscreteIntegrator: '<S27>/Discrete-Time Integrator'
   *  DiscreteIntegrator: '<S28>/Discrete-Time Integrator'
   *  DiscreteIntegrator: '<S29>/Discrete-Time Integrator'
   *  DiscreteIntegrator: '<S30>/Discrete-Time Integrator'
   *  DiscreteIntegrator: '<S31>/Discrete-Time Integrator'
   *  DiscreteIntegrator: '<S32>/Discrete-Time Integrator'
   *  DiscreteIntegrator: '<S33>/Discrete-Time Integrator'
   *  DiscreteIntegrator: '<S34>/Discrete-Time Integrator'
   *  DiscreteIntegrator: '<S35>/Discrete-Time Integrator'
   *  DiscreteIntegrator: '<S36>/Discrete-Time Integrator'
   *  DiscreteIntegrator: '<S37>/Discrete-Time Integrator'
   *  DiscreteIntegrator: '<S8>/Discrete-Time Integrator'
   *  DiscreteIntegrator: '<S9>/Discrete-Time Integrator'
   */
  bms_f4_Y.ToPlant.BusSOCEstimation.CDCEstimation[0] =
    bms_f4_DW.DiscreteTimeIntegrator_DSTATE;
  bms_f4_Y.ToPlant.BusSOCEstimation.CDCEstimation[3] =
    bms_f4_DW.DiscreteTimeIntegrator_DSTATE_a;
  bms_f4_Y.ToPlant.BusSOCEstimation.CDCEstimation[6] =
    bms_f4_DW.DiscreteTimeIntegrator_DSTAT_au;
  bms_f4_Y.ToPlant.BusSOCEstimation.CDCEstimation[9] =
    bms_f4_DW.DiscreteTimeIntegrator_DSTATE_m;
  bms_f4_Y.ToPlant.BusSOCEstimation.CDCEstimation[12] =
    bms_f4_DW.DiscreteTimeIntegrator_DSTATE_b;
  bms_f4_Y.ToPlant.BusSOCEstimation.CDCEstimation[15] =
    bms_f4_DW.DiscreteTimeIntegrator_DSTATE_p;
  bms_f4_Y.ToPlant.BusSOCEstimation.CDCEstimation[18] =
    bms_f4_DW.DiscreteTimeIntegrator_DSTATE_c;
  bms_f4_Y.ToPlant.BusSOCEstimation.CDCEstimation[21] =
    bms_f4_DW.DiscreteTimeIntegrator_DSTAT_mh;
  bms_f4_Y.ToPlant.BusSOCEstimation.CDCEstimation[24] =
    bms_f4_DW.DiscreteTimeIntegrator_DSTATE_g;
  bms_f4_Y.ToPlant.BusSOCEstimation.CDCEstimation[27] =
    bms_f4_DW.DiscreteTimeIntegrator_DSTAT_g0;
  bms_f4_Y.ToPlant.BusSOCEstimation.CDCEstimation[1] =
    bms_f4_DW.DiscreteTimeIntegrator_DSTATE_d;
  bms_f4_Y.ToPlant.BusSOCEstimation.CDCEstimation[4] =
    bms_f4_DW.DiscreteTimeIntegrator_DSTAT_b0;
  bms_f4_Y.ToPlant.BusSOCEstimation.CDCEstimation[7] =
    bms_f4_DW.DiscreteTimeIntegrator_DSTAT_dc;
  bms_f4_Y.ToPlant.BusSOCEstimation.CDCEstimation[10] =
    bms_f4_DW.DiscreteTimeIntegrator_DSTATE_o;
  bms_f4_Y.ToPlant.BusSOCEstimation.CDCEstimation[13] =
    bms_f4_DW.DiscreteTimeIntegrator_DSTAT_aw;
  bms_f4_Y.ToPlant.BusSOCEstimation.CDCEstimation[16] =
    bms_f4_DW.DiscreteTimeIntegrator_DSTATE_n;
  bms_f4_Y.ToPlant.BusSOCEstimation.CDCEstimation[19] =
    bms_f4_DW.DiscreteTimeIntegrator_DSTATE_e;
  bms_f4_Y.ToPlant.BusSOCEstimation.CDCEstimation[22] =
    bms_f4_DW.DiscreteTimeIntegrator_DSTATE_f;
  bms_f4_Y.ToPlant.BusSOCEstimation.CDCEstimation[25] =
    bms_f4_DW.DiscreteTimeIntegrator_DSTAT_aj;
  bms_f4_Y.ToPlant.BusSOCEstimation.CDCEstimation[28] =
    bms_f4_DW.DiscreteTimeIntegrator_DSTAT_bc;
  bms_f4_Y.ToPlant.BusSOCEstimation.CDCEstimation[2] =
    bms_f4_DW.DiscreteTimeIntegrator_DSTAT_ps;
  bms_f4_Y.ToPlant.BusSOCEstimation.CDCEstimation[5] =
    bms_f4_DW.DiscreteTimeIntegrator_DSTAT_ed;
  bms_f4_Y.ToPlant.BusSOCEstimation.CDCEstimation[8] =
    bms_f4_DW.DiscreteTimeIntegrator_DSTAT_mg;
  bms_f4_Y.ToPlant.BusSOCEstimation.CDCEstimation[11] =
    bms_f4_DW.DiscreteTimeIntegrator_DSTAT_fy;
  bms_f4_Y.ToPlant.BusSOCEstimation.CDCEstimation[14] =
    bms_f4_DW.DiscreteTimeIntegrator_DSTAT_gd;
  bms_f4_Y.ToPlant.BusSOCEstimation.CDCEstimation[17] =
    bms_f4_DW.DiscreteTimeIntegrator_DSTATE_i;
  bms_f4_Y.ToPlant.BusSOCEstimation.CDCEstimation[20] =
    bms_f4_DW.DiscreteTimeIntegrator_DSTAT_ce;
  bms_f4_Y.ToPlant.BusSOCEstimation.CDCEstimation[23] =
    bms_f4_DW.DiscreteTimeIntegrator_DSTAT_p0;
  bms_f4_Y.ToPlant.BusSOCEstimation.CDCEstimation[26] =
    bms_f4_DW.DiscreteTimeIntegrator_DSTAT_fb;
  bms_f4_Y.ToPlant.BusSOCEstimation.CDCEstimation[29] =
    bms_f4_DW.DiscreteTimeIntegrator_DSTAT_d3;

  /* Selector: '<S4>/Selector' incorporates:
   *  Inport: '<Root>/FromPlant'
   */
  for (sigIdx = 0; sigIdx < 10; sigIdx++) {
    bms_f4_B.Selector[sigIdx] =
      bms_f4_U.FromPlant.BMSBatteryPackData.SegmentVoltageVector[3 * sigIdx];
  }

  /* MinMax: '<S4>/Max' incorporates:
   *  Inport: '<Root>/FromPlant'
   *  Selector: '<S4>/Selector'
   */
  bms_f4_B.maxV = bms_f4_U.FromPlant.BMSBatteryPackData.SegmentVoltageVector[0];
  for (sigIdx = 0; sigIdx < 9; sigIdx++) {
    u1 = bms_f4_U.FromPlant.BMSBatteryPackData.SegmentVoltageVector[(sigIdx + 1)
      * 3];
    if ((!(bms_f4_B.maxV > u1)) && (!rtIsNaN(u1))) {
      bms_f4_B.maxV = u1;
    }
  }

  /* Selector: '<S4>/Selector1' incorporates:
   *  Inport: '<Root>/FromPlant'
   */
  for (sigIdx = 0; sigIdx < 10; sigIdx++) {
    bms_f4_B.Selector1[sigIdx] =
      bms_f4_U.FromPlant.BMSBatteryPackData.SegmentVoltageVector[3 * sigIdx + 1];
  }

  /* MinMax: '<S4>/Max1' incorporates:
   *  Inport: '<Root>/FromPlant'
   *  Selector: '<S4>/Selector1'
   */
  bms_f4_B.maxV_m = bms_f4_U.FromPlant.BMSBatteryPackData.SegmentVoltageVector[1];
  for (sigIdx = 0; sigIdx < 9; sigIdx++) {
    u1 = bms_f4_U.FromPlant.BMSBatteryPackData.SegmentVoltageVector[(sigIdx + 1)
      * 3 + 1];
    if ((!(bms_f4_B.maxV_m > u1)) && (!rtIsNaN(u1))) {
      bms_f4_B.maxV_m = u1;
    }
  }

  /* Selector: '<S4>/Selector2' incorporates:
   *  Inport: '<Root>/FromPlant'
   */
  for (sigIdx = 0; sigIdx < 10; sigIdx++) {
    bms_f4_B.Selector2[sigIdx] =
      bms_f4_U.FromPlant.BMSBatteryPackData.SegmentVoltageVector[3 * sigIdx + 2];
  }

  /* MinMax: '<S4>/Max2' incorporates:
   *  Inport: '<Root>/FromPlant'
   *  Selector: '<S4>/Selector2'
   */
  bms_f4_B.Min3 = bms_f4_U.FromPlant.BMSBatteryPackData.SegmentVoltageVector[2];

  /* MinMax: '<S4>/Min' incorporates:
   *  Inport: '<Root>/FromPlant'
   *  Selector: '<S4>/Selector'
   */
  bms_f4_B.minV = bms_f4_U.FromPlant.BMSBatteryPackData.SegmentVoltageVector[0];

  /* MinMax: '<S4>/Min1' incorporates:
   *  Inport: '<Root>/FromPlant'
   *  Selector: '<S4>/Selector1'
   */
  bms_f4_B.minV_c = bms_f4_U.FromPlant.BMSBatteryPackData.SegmentVoltageVector[1];

  /* MinMax: '<S4>/Min2' incorporates:
   *  Inport: '<Root>/FromPlant'
   *  Selector: '<S4>/Selector2'
   */
  bms_f4_B.Min4 = bms_f4_U.FromPlant.BMSBatteryPackData.SegmentVoltageVector[2];
  for (sigIdx = 0; sigIdx < 9; sigIdx++) {
    /* MinMax: '<S4>/Max2' incorporates:
     *  Inport: '<Root>/FromPlant'
     *  MinMax: '<S4>/Min'
     *  MinMax: '<S4>/Min1'
     *  MinMax: '<S4>/Min2'
     *  Selector: '<S4>/Selector'
     *  Selector: '<S4>/Selector1'
     *  Selector: '<S4>/Selector2'
     */
    u1_tmp = (sigIdx + 1) * 3;
    u1_tmp_0 = bms_f4_U.FromPlant.BMSBatteryPackData.SegmentVoltageVector[u1_tmp
      + 2];
    tmp_0 = !rtIsNaN(u1_tmp_0);
    if ((!(bms_f4_B.Min3 > u1_tmp_0)) && tmp_0) {
      bms_f4_B.Min3 = u1_tmp_0;
    }

    /* MinMax: '<S4>/Min' incorporates:
     *  Inport: '<Root>/FromPlant'
     *  Selector: '<S4>/Selector'
     */
    u1 = bms_f4_U.FromPlant.BMSBatteryPackData.SegmentVoltageVector[u1_tmp];
    if ((!(bms_f4_B.minV < u1)) && (!rtIsNaN(u1))) {
      bms_f4_B.minV = u1;
    }

    /* MinMax: '<S4>/Min1' incorporates:
     *  Inport: '<Root>/FromPlant'
     *  Selector: '<S4>/Selector1'
     */
    u1 = bms_f4_U.FromPlant.BMSBatteryPackData.SegmentVoltageVector[u1_tmp + 1];
    if ((!(bms_f4_B.minV_c < u1)) && (!rtIsNaN(u1))) {
      bms_f4_B.minV_c = u1;
    }

    /* MinMax: '<S4>/Min2' */
    if ((!(bms_f4_B.Min4 < u1_tmp_0)) && tmp_0) {
      bms_f4_B.Min4 = u1_tmp_0;
    }
  }

  /* MinMax: '<S4>/Min3' incorporates:
   *  MinMax: '<S4>/Max'
   *  MinMax: '<S4>/Max1'
   *  MinMax: '<S4>/Max2'
   */
  if ((bms_f4_B.maxV > bms_f4_B.maxV_m) || rtIsNaN(bms_f4_B.maxV_m)) {
    bms_f4_B.maxV_m = bms_f4_B.maxV;
  }

  if ((bms_f4_B.maxV_m > bms_f4_B.Min3) || rtIsNaN(bms_f4_B.Min3)) {
    bms_f4_B.Min3 = bms_f4_B.maxV_m;
  }

  /* End of MinMax: '<S4>/Min3' */

  /* MinMax: '<S4>/Min4' incorporates:
   *  MinMax: '<S4>/Min'
   *  MinMax: '<S4>/Min1'
   *  MinMax: '<S4>/Min2'
   */
  if ((bms_f4_B.minV < bms_f4_B.minV_c) || rtIsNaN(bms_f4_B.minV_c)) {
    bms_f4_B.minV_c = bms_f4_B.minV;
  }

  if ((bms_f4_B.minV_c < bms_f4_B.Min4) || rtIsNaN(bms_f4_B.Min4)) {
    bms_f4_B.Min4 = bms_f4_B.minV_c;
  }

  /* End of MinMax: '<S4>/Min4' */

  /* Chart: '<S3>/Chart' incorporates:
   *  Inport: '<Root>/FromPlant'
   *  Inport: '<Root>/InputSimulationBus'
   */
  switch (bms_f4_DW.is_c1_bms_f4) {
   case bms_f4_IN_charging:
    bms_f4_B.VectorConcatenate[0] = 0.0;
    bms_f4_B.VectorConcatenate3[0] = 1.0;
    break;

   case bms_f4_IN_dis_charger:
    bms_f4_B.VectorConcatenate1[0] = 0.0;
    bms_f4_B.VectorConcatenate2[0] = 1.0;
    bms_f4_B.VectorConcatenate3[0] = 0.0;
    break;

   case bms_f4_IN_dis_inverter:
    bms_f4_B.VectorConcatenate1[1] = 0.0;
    bms_f4_B.VectorConcatenate2[1] = 1.0;
    bms_f4_B.VectorConcatenate3[1] = 0.0;
    break;

   case bms_f4_IN_driving:
    bms_f4_B.VectorConcatenate[1] = 0.0;
    bms_f4_B.VectorConcatenate3[1] = 1.0;
    break;

   case bms_f4_IN_en_charger:
    bms_f4_B.VectorConcatenate1[0] = 1.0;
    break;

   case bms_f4_IN_en_charger_prechrg:
    bms_f4_B.VectorConcatenate[0] = 1.0;
    bms_f4_B.VectorConcatenate1[2] = 1.0;
    break;

   case bms_f4_IN_en_inverter:
    bms_f4_B.VectorConcatenate1[1] = 1.0;
    break;

   case bms_f4_IN_en_inverter_prechrg:
    bms_f4_B.VectorConcatenate[1] = 1.0;
    bms_f4_B.VectorConcatenate1[2] = 1.0;
    break;

   default:
    /* case IN_init: */
    bms_f4_B.VectorConcatenate1[2] = 0.0;
    bms_f4_B.VectorConcatenate[0] = 0.0;
    bms_f4_B.VectorConcatenate[1] = 0.0;
    bms_f4_B.VectorConcatenate1[0] = 0.0;
    bms_f4_B.VectorConcatenate1[1] = 0.0;
    bms_f4_B.VectorConcatenate2[0] = 0.0;
    bms_f4_B.VectorConcatenate2[1] = 0.0;
    bms_f4_B.VectorConcatenate3[0] = 0.0;
    bms_f4_B.VectorConcatenate3[1] = 0.0;
    break;
  }

  if (bms_f4_DW.isNotInit && (bms_f4_DW.temporalCounter_i1 < MAX_uint32_T)) {
    bms_f4_DW.temporalCounter_i1++;
  }

  bms_f4_DW.isNotInit = true;
  switch (bms_f4_DW.is_c1_bms_f4) {
   case bms_f4_IN_charging:
    tmp = bms_f4_U.InputSimulationBus.SimulationSystemInput.SystemState;
    if (tmp != SystemState_t_Charging) {
      bms_f4_DW.is_c1_bms_f4 = bms_f4_IN_dis_charger;
    } else if (tmp == SystemState_t_Charging) {
      bms_f4_DW.is_c1_bms_f4 = bms_f4_IN_charging;
    }
    break;

   case bms_f4_IN_dis_charger:
    if (bms_f4_U.FromPlant.BMSContactorModuleData.VCharger <
        bms_f4_P.VbattThresholdDis *
        bms_f4_U.FromPlant.BMSContactorModuleData.VBatt) {
      bms_f4_DW.is_c1_bms_f4 = bms_f4_IN_init;
    }
    break;

   case bms_f4_IN_dis_inverter:
    if (bms_f4_U.FromPlant.BMSContactorModuleData.VInverter <
        bms_f4_P.VbattThresholdDis *
        bms_f4_U.FromPlant.BMSContactorModuleData.VBatt) {
      bms_f4_DW.is_c1_bms_f4 = bms_f4_IN_init;
    }
    break;

   case bms_f4_IN_driving:
    tmp = bms_f4_U.InputSimulationBus.SimulationSystemInput.SystemState;
    if (tmp != SystemState_t_Driving) {
      bms_f4_DW.is_c1_bms_f4 = bms_f4_IN_dis_inverter;
    } else if (tmp == SystemState_t_Driving) {
      bms_f4_DW.is_c1_bms_f4 = bms_f4_IN_driving;
    }
    break;

   case bms_f4_IN_en_charger:
    if (bms_f4_DW.temporalCounter_i1 >= (uint32_T)ceil
        (bms_f4_P.DrivetrainEnDelay * 100.0)) {
      bms_f4_DW.is_c1_bms_f4 = bms_f4_IN_charging;
    }
    break;

   case bms_f4_IN_en_charger_prechrg:
    bms_f4_B.maxV = bms_f4_P.VbattThersholdChrg *
      bms_f4_U.FromPlant.BMSContactorModuleData.VBatt;
    if (bms_f4_U.FromPlant.BMSContactorModuleData.VCharger >= bms_f4_B.maxV) {
      bms_f4_DW.is_c1_bms_f4 = bms_f4_IN_en_charger;
      bms_f4_DW.temporalCounter_i1 = 0U;
    } else if (bms_f4_U.FromPlant.BMSContactorModuleData.VCharger <
               bms_f4_B.maxV) {
      bms_f4_DW.is_c1_bms_f4 = bms_f4_IN_en_charger_prechrg;
    } else if (bms_f4_U.InputSimulationBus.SimulationSystemInput.SystemState !=
               SystemState_t_Driving) {
      bms_f4_DW.is_c1_bms_f4 = bms_f4_IN_init;
    }
    break;

   case bms_f4_IN_en_inverter:
    if (bms_f4_DW.temporalCounter_i1 >= (uint32_T)ceil
        (bms_f4_P.DrivetrainEnDelay * 100.0)) {
      bms_f4_DW.is_c1_bms_f4 = bms_f4_IN_driving;
    }
    break;

   case bms_f4_IN_en_inverter_prechrg:
    bms_f4_B.maxV = bms_f4_P.VbattThersholdChrg *
      bms_f4_U.FromPlant.BMSContactorModuleData.VBatt;
    if (bms_f4_U.FromPlant.BMSContactorModuleData.VInverter >= bms_f4_B.maxV) {
      bms_f4_DW.is_c1_bms_f4 = bms_f4_IN_en_inverter;
      bms_f4_DW.temporalCounter_i1 = 0U;
    } else if (bms_f4_U.FromPlant.BMSContactorModuleData.VInverter <
               bms_f4_B.maxV) {
      bms_f4_DW.is_c1_bms_f4 = bms_f4_IN_en_inverter_prechrg;
    } else if (bms_f4_U.InputSimulationBus.SimulationSystemInput.SystemState !=
               SystemState_t_Driving) {
      bms_f4_DW.is_c1_bms_f4 = bms_f4_IN_init;
    }
    break;

   default:
    /* case IN_init: */
    tmp = bms_f4_U.InputSimulationBus.SimulationSystemInput.SystemState;
    if ((bms_f4_U.FromPlant.BMSContactorModuleData.VBatt > bms_f4_P.VbattMin) &&
        (tmp == SystemState_t_Charging)) {
      bms_f4_DW.is_c1_bms_f4 = bms_f4_IN_en_charger_prechrg;
    } else if ((bms_f4_U.FromPlant.BMSContactorModuleData.VBatt >
                bms_f4_P.VbattMin) && (tmp == SystemState_t_Driving)) {
      bms_f4_DW.is_c1_bms_f4 = bms_f4_IN_en_inverter_prechrg;
    }
    break;
  }

  /* End of Chart: '<S3>/Chart' */

  /* Chart: '<S4>/Chart1' incorporates:
   *  Inport: '<Root>/InputSimulationBus'
   */
  bms_f4_Chart1(bms_f4_U.InputSimulationBus.SimulationSystemInput.SystemState,
                bms_f4_B.Selector, bms_f4_B.Min3, bms_f4_B.Min4,
                &bms_f4_B.MatrixConcatenate[0], &bms_f4_B.VectorConcatenate_k[0],
                &bms_f4_B.VectorConcatenate1_a[0], &bms_f4_DW.sf_Chart1);

  /* Chart: '<S4>/Chart2' incorporates:
   *  Inport: '<Root>/InputSimulationBus'
   */
  bms_f4_Chart1(bms_f4_U.InputSimulationBus.SimulationSystemInput.SystemState,
                bms_f4_B.Selector1, bms_f4_B.Min3, bms_f4_B.Min4,
                &bms_f4_B.MatrixConcatenate[10], &bms_f4_B.VectorConcatenate_k[1],
                &bms_f4_B.VectorConcatenate1_a[1], &bms_f4_DW.sf_Chart2);

  /* Chart: '<S4>/Chart3' incorporates:
   *  Inport: '<Root>/InputSimulationBus'
   */
  bms_f4_Chart1(bms_f4_U.InputSimulationBus.SimulationSystemInput.SystemState,
                bms_f4_B.Selector2, bms_f4_B.Min3, bms_f4_B.Min4,
                &bms_f4_B.MatrixConcatenate[20], &bms_f4_B.VectorConcatenate_k[2],
                &bms_f4_B.VectorConcatenate1_a[2], &bms_f4_DW.sf_Chart3);

  /* Math: '<S4>/Transpose' incorporates:
   *  Concatenate: '<S4>/Matrix Concatenate'
   */
  for (sigIdx = 0; sigIdx < 10; sigIdx++) {
    bms_f4_Y.ToPlant.BMSBatteryPackInput.BalCmdVector[3 * sigIdx] =
      bms_f4_B.MatrixConcatenate[sigIdx];
    bms_f4_Y.ToPlant.BMSBatteryPackInput.BalCmdVector[3 * sigIdx + 1] =
      bms_f4_B.MatrixConcatenate[sigIdx + 10];
    bms_f4_Y.ToPlant.BMSBatteryPackInput.BalCmdVector[3 * sigIdx + 2] =
      bms_f4_B.MatrixConcatenate[sigIdx + 20];
  }

  /* End of Math: '<S4>/Transpose' */

  /* MinMax: '<S2>/Max15' incorporates:
   *  Inport: '<Root>/FromPlant'
   *  Selector: '<S2>/Selector12'
   */
  bms_f4_B.Max3 = bms_f4_U.FromPlant.BMSBatteryPackData.SegmentVoltageVector[2];

  /* MinMax: '<S2>/Max13' incorporates:
   *  Inport: '<Root>/FromPlant'
   *  Selector: '<S2>/Selector10'
   */
  bms_f4_B.minV = bms_f4_U.FromPlant.BMSBatteryPackData.SegmentVoltageVector[0];

  /* MinMax: '<S2>/Max14' incorporates:
   *  Inport: '<Root>/FromPlant'
   *  Selector: '<S2>/Selector11'
   */
  bms_f4_B.minV_c = bms_f4_U.FromPlant.BMSBatteryPackData.SegmentVoltageVector[1];

  /* MinMax: '<S2>/Max4' incorporates:
   *  Inport: '<Root>/FromPlant'
   *  Selector: '<S2>/Selector1'
   */
  bms_f4_B.maxV = bms_f4_U.FromPlant.BMSBatteryPackData.SegmentCurrentVector[0];

  /* MinMax: '<S2>/Max5' incorporates:
   *  Inport: '<Root>/FromPlant'
   *  Selector: '<S2>/Selector2'
   */
  bms_f4_B.maxV_m = bms_f4_U.FromPlant.BMSBatteryPackData.SegmentCurrentVector[1];

  /* MinMax: '<S2>/Max6' incorporates:
   *  Inport: '<Root>/FromPlant'
   *  Selector: '<S2>/Selector3'
   */
  bms_f4_B.Gain = bms_f4_U.FromPlant.BMSBatteryPackData.SegmentCurrentVector[2];

  /* MinMax: '<S2>/Max7' incorporates:
   *  Inport: '<Root>/FromPlant'
   *  Selector: '<S2>/Selector4'
   */
  bms_f4_B.Min3 = bms_f4_U.FromPlant.BMSBatteryPackData.SegmentTempVector[0];

  /* MinMax: '<S2>/Max8' incorporates:
   *  Inport: '<Root>/FromPlant'
   *  Selector: '<S2>/Selector5'
   */
  bms_f4_B.Min4 = bms_f4_U.FromPlant.BMSBatteryPackData.SegmentTempVector[1];

  /* MinMax: '<S2>/Max9' incorporates:
   *  Inport: '<Root>/FromPlant'
   *  Selector: '<S2>/Selector6'
   */
  rtb_nDLookupTable = bms_f4_U.FromPlant.BMSBatteryPackData.SegmentTempVector[2];

  /* MinMax: '<S2>/Max10' incorporates:
   *  Inport: '<Root>/FromPlant'
   *  Selector: '<S2>/Selector7'
   */
  bms_f4_B.maxV_k = bms_f4_U.FromPlant.BMSBatteryPackData.SegmentVoltageVector[0];

  /* MinMax: '<S2>/Max11' incorporates:
   *  Inport: '<Root>/FromPlant'
   *  Selector: '<S2>/Selector8'
   */
  bms_f4_B.maxV_c = bms_f4_U.FromPlant.BMSBatteryPackData.SegmentVoltageVector[1];

  /* MinMax: '<S2>/Max12' incorporates:
   *  Inport: '<Root>/FromPlant'
   *  Selector: '<S2>/Selector9'
   */
  bms_f4_B.maxV_b = bms_f4_U.FromPlant.BMSBatteryPackData.SegmentVoltageVector[2];
  for (sigIdx = 0; sigIdx < 9; sigIdx++) {
    /* MinMax: '<S2>/Max15' incorporates:
     *  Inport: '<Root>/FromPlant'
     *  MinMax: '<S2>/Max10'
     *  MinMax: '<S2>/Max12'
     *  MinMax: '<S2>/Max13'
     *  MinMax: '<S2>/Max14'
     *  MinMax: '<S2>/Max4'
     *  MinMax: '<S2>/Max7'
     *  Selector: '<S2>/Selector1'
     *  Selector: '<S2>/Selector10'
     *  Selector: '<S2>/Selector11'
     *  Selector: '<S2>/Selector12'
     *  Selector: '<S2>/Selector4'
     *  Selector: '<S2>/Selector7'
     *  Selector: '<S2>/Selector9'
     */
    u1_tmp = (sigIdx + 1) * 3;
    u1_tmp_0 = bms_f4_U.FromPlant.BMSBatteryPackData.SegmentVoltageVector[u1_tmp
      + 2];
    tmp_0 = !rtIsNaN(u1_tmp_0);
    if ((!(bms_f4_B.Max3 < u1_tmp_0)) && tmp_0) {
      bms_f4_B.Max3 = u1_tmp_0;
    }

    /* MinMax: '<S2>/Max13' incorporates:
     *  Inport: '<Root>/FromPlant'
     *  MinMax: '<S2>/Max10'
     *  Selector: '<S2>/Selector10'
     *  Selector: '<S2>/Selector7'
     */
    u1_tmp_1 = bms_f4_U.FromPlant.BMSBatteryPackData.SegmentVoltageVector[u1_tmp];
    tmp_1 = !rtIsNaN(u1_tmp_1);
    if ((!(bms_f4_B.minV < u1_tmp_1)) && tmp_1) {
      bms_f4_B.minV = u1_tmp_1;
    }

    /* MinMax: '<S2>/Max14' incorporates:
     *  Inport: '<Root>/FromPlant'
     *  MinMax: '<S2>/Max11'
     *  Selector: '<S2>/Selector11'
     *  Selector: '<S2>/Selector8'
     */
    u1_tmp_2 = bms_f4_U.FromPlant.BMSBatteryPackData.SegmentVoltageVector[u1_tmp
      + 1];
    tmp_2 = !rtIsNaN(u1_tmp_2);
    if ((!(bms_f4_B.minV_c < u1_tmp_2)) && tmp_2) {
      bms_f4_B.minV_c = u1_tmp_2;
    }

    /* MinMax: '<S2>/Max4' incorporates:
     *  Inport: '<Root>/FromPlant'
     *  Selector: '<S2>/Selector1'
     */
    u1 = bms_f4_U.FromPlant.BMSBatteryPackData.SegmentCurrentVector[u1_tmp];
    if ((!(bms_f4_B.maxV > u1)) && (!rtIsNaN(u1))) {
      bms_f4_B.maxV = u1;
    }

    /* MinMax: '<S2>/Max5' incorporates:
     *  Inport: '<Root>/FromPlant'
     *  MinMax: '<S2>/Max14'
     *  Selector: '<S2>/Selector11'
     *  Selector: '<S2>/Selector2'
     */
    u1 = bms_f4_U.FromPlant.BMSBatteryPackData.SegmentCurrentVector[u1_tmp + 1];
    if ((!(bms_f4_B.maxV_m > u1)) && (!rtIsNaN(u1))) {
      bms_f4_B.maxV_m = u1;
    }

    /* MinMax: '<S2>/Max6' incorporates:
     *  Inport: '<Root>/FromPlant'
     *  MinMax: '<S2>/Max15'
     *  Selector: '<S2>/Selector12'
     *  Selector: '<S2>/Selector3'
     */
    u1 = bms_f4_U.FromPlant.BMSBatteryPackData.SegmentCurrentVector[u1_tmp + 2];
    if ((!(bms_f4_B.Gain > u1)) && (!rtIsNaN(u1))) {
      bms_f4_B.Gain = u1;
    }

    /* MinMax: '<S2>/Max7' incorporates:
     *  Inport: '<Root>/FromPlant'
     *  Selector: '<S2>/Selector4'
     */
    u1 = bms_f4_U.FromPlant.BMSBatteryPackData.SegmentTempVector[u1_tmp];
    if ((!(bms_f4_B.Min3 > u1)) && (!rtIsNaN(u1))) {
      bms_f4_B.Min3 = u1;
    }

    /* MinMax: '<S2>/Max8' incorporates:
     *  Inport: '<Root>/FromPlant'
     *  MinMax: '<S2>/Max14'
     *  Selector: '<S2>/Selector11'
     *  Selector: '<S2>/Selector5'
     */
    u1 = bms_f4_U.FromPlant.BMSBatteryPackData.SegmentTempVector[u1_tmp + 1];
    if ((!(bms_f4_B.Min4 > u1)) && (!rtIsNaN(u1))) {
      bms_f4_B.Min4 = u1;
    }

    /* MinMax: '<S2>/Max9' incorporates:
     *  Inport: '<Root>/FromPlant'
     *  MinMax: '<S2>/Max15'
     *  Selector: '<S2>/Selector12'
     *  Selector: '<S2>/Selector6'
     */
    u1 = bms_f4_U.FromPlant.BMSBatteryPackData.SegmentTempVector[u1_tmp + 2];
    if ((!(rtb_nDLookupTable > u1)) && (!rtIsNaN(u1))) {
      rtb_nDLookupTable = u1;
    }

    /* MinMax: '<S2>/Max10' */
    if ((!(bms_f4_B.maxV_k > u1_tmp_1)) && tmp_1) {
      bms_f4_B.maxV_k = u1_tmp_1;
    }

    /* MinMax: '<S2>/Max11' */
    if ((!(bms_f4_B.maxV_c > u1_tmp_2)) && tmp_2) {
      bms_f4_B.maxV_c = u1_tmp_2;
    }

    /* MinMax: '<S2>/Max12' */
    if ((!(bms_f4_B.maxV_b > u1_tmp_0)) && tmp_0) {
      bms_f4_B.maxV_b = u1_tmp_0;
    }
  }

  /* MinMax: '<S2>/Max3' incorporates:
   *  MinMax: '<S2>/Max13'
   *  MinMax: '<S2>/Max14'
   *  MinMax: '<S2>/Max15'
   */
  if ((bms_f4_B.minV < bms_f4_B.minV_c) || rtIsNaN(bms_f4_B.minV_c)) {
    bms_f4_B.minV_c = bms_f4_B.minV;
  }

  if ((bms_f4_B.minV_c < bms_f4_B.Max3) || rtIsNaN(bms_f4_B.Max3)) {
    bms_f4_B.Max3 = bms_f4_B.minV_c;
  }

  /* End of MinMax: '<S2>/Max3' */

  /* RelationalOperator: '<S44>/Compare' incorporates:
   *  Constant: '<S44>/Constant'
   */
  bms_f4_Y.ToPlant.BMSFaultOutput.UnderVoltageWarning = (bms_f4_B.Max3 <=
    bms_f4_P.CellVoltageLimitLow_Warning);

  /* MinMax: '<S2>/Max' incorporates:
   *  MinMax: '<S2>/Max4'
   *  MinMax: '<S2>/Max5'
   *  MinMax: '<S2>/Max6'
   */
  if ((bms_f4_B.maxV > bms_f4_B.maxV_m) || rtIsNaN(bms_f4_B.maxV_m)) {
    bms_f4_B.maxV_m = bms_f4_B.maxV;
  }

  if ((bms_f4_B.maxV_m > bms_f4_B.Gain) || rtIsNaN(bms_f4_B.Gain)) {
    bms_f4_B.Gain = bms_f4_B.maxV_m;
  }

  /* End of MinMax: '<S2>/Max' */

  /* RelationalOperator: '<S38>/Compare' incorporates:
   *  Constant: '<S38>/Constant'
   */
  bms_f4_Y.ToPlant.BMSFaultOutput.OverCurrentWarning = (bms_f4_B.Gain >=
    bms_f4_P.CellCurrentLimitThreshold_Warning);

  /* RelationalOperator: '<S39>/Compare' incorporates:
   *  Constant: '<S39>/Constant'
   */
  bms_f4_Y.ToPlant.BMSFaultOutput.OverCurrentFault = (bms_f4_B.Gain >=
    bms_f4_P.CellCurrentLimitThreshold_Fault);

  /* MinMax: '<S2>/Max1' incorporates:
   *  MinMax: '<S2>/Max7'
   *  MinMax: '<S2>/Max8'
   *  MinMax: '<S2>/Max9'
   */
  if ((bms_f4_B.Min3 > bms_f4_B.Min4) || rtIsNaN(bms_f4_B.Min4)) {
    bms_f4_B.Min4 = bms_f4_B.Min3;
  }

  if ((bms_f4_B.Min4 > rtb_nDLookupTable) || rtIsNaN(rtb_nDLookupTable)) {
    rtb_nDLookupTable = bms_f4_B.Min4;
  }

  /* End of MinMax: '<S2>/Max1' */

  /* RelationalOperator: '<S40>/Compare' incorporates:
   *  Constant: '<S40>/Constant'
   */
  bms_f4_Y.ToPlant.BMSFaultOutput.OverTemperatureWarning = (rtb_nDLookupTable >=
    bms_f4_P.CellTemperatureLimitThreshold_Warning);

  /* RelationalOperator: '<S41>/Compare' incorporates:
   *  Constant: '<S41>/Constant'
   */
  bms_f4_Y.ToPlant.BMSFaultOutput.OverTemperatureFault = (rtb_nDLookupTable >=
    bms_f4_P.CellTemperatureLimitThreshold_Fault);

  /* MinMax: '<S2>/Max2' incorporates:
   *  MinMax: '<S2>/Max10'
   *  MinMax: '<S2>/Max11'
   *  MinMax: '<S2>/Max12'
   */
  if ((bms_f4_B.maxV_k > bms_f4_B.maxV_c) || rtIsNaN(bms_f4_B.maxV_c)) {
    bms_f4_B.maxV_c = bms_f4_B.maxV_k;
  }

  if ((bms_f4_B.maxV_c > bms_f4_B.maxV_b) || rtIsNaN(bms_f4_B.maxV_b)) {
    rtb_nDLookupTable = bms_f4_B.maxV_c;
  } else {
    rtb_nDLookupTable = bms_f4_B.maxV_b;
  }

  /* End of MinMax: '<S2>/Max2' */

  /* RelationalOperator: '<S42>/Compare' incorporates:
   *  Constant: '<S42>/Constant'
   */
  bms_f4_Y.ToPlant.BMSFaultOutput.OverVoltageWarning = (rtb_nDLookupTable >=
    bms_f4_P.CellVoltageLimitHigh_Warning);

  /* RelationalOperator: '<S43>/Compare' incorporates:
   *  Constant: '<S43>/Constant'
   */
  bms_f4_Y.ToPlant.BMSFaultOutput.OverVoltageFault = (rtb_nDLookupTable >=
    bms_f4_P.CellVoltageLimitHigh_Fault);

  /* RelationalOperator: '<S45>/Compare' incorporates:
   *  Constant: '<S45>/Constant'
   */
  bms_f4_Y.ToPlant.BMSFaultOutput.UnderVoltageFault = (bms_f4_B.Max3 <=
    bms_f4_P.CellVoltageLimitLow_Fault);

  /* BusCreator generated from: '<Root>/ToPlant' */
  bms_f4_Y.ToPlant.BMSContactorModuleCmd.ContactorCmd[0] =
    bms_f4_B.VectorConcatenate1[0];
  bms_f4_Y.ToPlant.BMSContactorModuleCmd.ContactorCmd[1] =
    bms_f4_B.VectorConcatenate1[1];
  bms_f4_Y.ToPlant.BMSContactorModuleCmd.ContactorCmd[2] =
    bms_f4_B.VectorConcatenate1[2];
  bms_f4_Y.ToPlant.BMSContactorModuleCmd.PreChrgCmd[0] =
    bms_f4_B.VectorConcatenate[0];
  bms_f4_Y.ToPlant.BMSContactorModuleCmd.DisChrgCmd[0] =
    bms_f4_B.VectorConcatenate2[0];
  bms_f4_Y.ToPlant.BMSContactorModuleCmd.DrivetrainEn[0] =
    bms_f4_B.VectorConcatenate3[0];
  bms_f4_Y.ToPlant.BMSContactorModuleCmd.PreChrgCmd[1] =
    bms_f4_B.VectorConcatenate[1];
  bms_f4_Y.ToPlant.BMSContactorModuleCmd.DisChrgCmd[1] =
    bms_f4_B.VectorConcatenate2[1];
  bms_f4_Y.ToPlant.BMSContactorModuleCmd.DrivetrainEn[1] =
    bms_f4_B.VectorConcatenate3[1];

  /* BusCreator generated from: '<Root>/ToPlant' */
  bms_f4_Y.ToPlant.BMSBatteryPackInput.balancingDeltaVCell[0] =
    bms_f4_B.VectorConcatenate_k[0];
  bms_f4_Y.ToPlant.BMSBatteryPackInput.balancingFlags[0] =
    bms_f4_B.VectorConcatenate1_a[0];
  bms_f4_Y.ToPlant.BMSBatteryPackInput.balancingDeltaVCell[1] =
    bms_f4_B.VectorConcatenate_k[1];
  bms_f4_Y.ToPlant.BMSBatteryPackInput.balancingFlags[1] =
    bms_f4_B.VectorConcatenate1_a[1];
  bms_f4_Y.ToPlant.BMSBatteryPackInput.balancingDeltaVCell[2] =
    bms_f4_B.VectorConcatenate_k[2];
  bms_f4_Y.ToPlant.BMSBatteryPackInput.balancingFlags[2] =
    bms_f4_B.VectorConcatenate1_a[2];

  /* Update for DiscreteIntegrator: '<S17>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S17>/Gain'
   *  Inport: '<Root>/FromPlant'
   *  Lookup_n-D: '<S17>/n-D Lookup Table'
   *  Product: '<S17>/Divide'
   *  Selector: '<S1>/Selector1'
   *  Selector: '<S1>/Selector2'
   */
  bms_f4_DW.DiscreteTimeIntegrator_DSTATE += bms_f4_P.Gain_Gain_c4 *
    bms_f4_U.FromPlant.BMSBatteryPackData.SegmentCurrentVector[0] /
    look1_binlxpw(bms_f4_U.FromPlant.BMSBatteryPackData.SegmentTempVector[0],
                  bms_f4_P.nDLookupTable_bp01Data_k,
                  bms_f4_P.nDLookupTable_tableData_g, 2U) *
    bms_f4_P.DiscreteTimeIntegrator_gainval;
  if (bms_f4_DW.DiscreteTimeIntegrator_DSTATE >=
      bms_f4_P.DiscreteTimeIntegrator_UpperSat) {
    bms_f4_DW.DiscreteTimeIntegrator_DSTATE =
      bms_f4_P.DiscreteTimeIntegrator_UpperSat;
  } else if (bms_f4_DW.DiscreteTimeIntegrator_DSTATE <=
             bms_f4_P.DiscreteTimeIntegrator_LowerSat) {
    bms_f4_DW.DiscreteTimeIntegrator_DSTATE =
      bms_f4_P.DiscreteTimeIntegrator_LowerSat;
  }

  /* End of Update for DiscreteIntegrator: '<S17>/Discrete-Time Integrator' */

  /* Update for DiscreteIntegrator: '<S8>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S8>/Gain'
   *  Inport: '<Root>/FromPlant'
   *  Lookup_n-D: '<S8>/n-D Lookup Table'
   *  Product: '<S8>/Divide'
   *  Selector: '<S1>/Selector1'
   *  Selector: '<S1>/Selector2'
   */
  bms_f4_DW.DiscreteTimeIntegrator_DSTATE_a += bms_f4_P.Gain_Gain *
    bms_f4_U.FromPlant.BMSBatteryPackData.SegmentCurrentVector[3] /
    look1_binlxpw(bms_f4_U.FromPlant.BMSBatteryPackData.SegmentTempVector[3],
                  bms_f4_P.nDLookupTable_bp01Data,
                  bms_f4_P.nDLookupTable_tableData, 2U) *
    bms_f4_P.DiscreteTimeIntegrator_gainva_d;
  if (bms_f4_DW.DiscreteTimeIntegrator_DSTATE_a >=
      bms_f4_P.DiscreteTimeIntegrator_UpperS_n) {
    bms_f4_DW.DiscreteTimeIntegrator_DSTATE_a =
      bms_f4_P.DiscreteTimeIntegrator_UpperS_n;
  } else if (bms_f4_DW.DiscreteTimeIntegrator_DSTATE_a <=
             bms_f4_P.DiscreteTimeIntegrator_LowerS_e) {
    bms_f4_DW.DiscreteTimeIntegrator_DSTATE_a =
      bms_f4_P.DiscreteTimeIntegrator_LowerS_e;
  }

  /* End of Update for DiscreteIntegrator: '<S8>/Discrete-Time Integrator' */

  /* Update for DiscreteIntegrator: '<S9>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S9>/Gain'
   *  Inport: '<Root>/FromPlant'
   *  Lookup_n-D: '<S9>/n-D Lookup Table'
   *  Product: '<S9>/Divide'
   *  Selector: '<S1>/Selector1'
   *  Selector: '<S1>/Selector2'
   */
  bms_f4_DW.DiscreteTimeIntegrator_DSTAT_au += bms_f4_P.Gain_Gain_f *
    bms_f4_U.FromPlant.BMSBatteryPackData.SegmentCurrentVector[6] /
    look1_binlxpw(bms_f4_U.FromPlant.BMSBatteryPackData.SegmentTempVector[6],
                  bms_f4_P.nDLookupTable_bp01Data_o,
                  bms_f4_P.nDLookupTable_tableData_f, 2U) *
    bms_f4_P.DiscreteTimeIntegrator_gainva_o;
  if (bms_f4_DW.DiscreteTimeIntegrator_DSTAT_au >=
      bms_f4_P.DiscreteTimeIntegrator_UpperS_m) {
    bms_f4_DW.DiscreteTimeIntegrator_DSTAT_au =
      bms_f4_P.DiscreteTimeIntegrator_UpperS_m;
  } else if (bms_f4_DW.DiscreteTimeIntegrator_DSTAT_au <=
             bms_f4_P.DiscreteTimeIntegrator_LowerS_l) {
    bms_f4_DW.DiscreteTimeIntegrator_DSTAT_au =
      bms_f4_P.DiscreteTimeIntegrator_LowerS_l;
  }

  /* End of Update for DiscreteIntegrator: '<S9>/Discrete-Time Integrator' */

  /* Update for DiscreteIntegrator: '<S10>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S10>/Gain'
   *  Inport: '<Root>/FromPlant'
   *  Lookup_n-D: '<S10>/n-D Lookup Table'
   *  Product: '<S10>/Divide'
   *  Selector: '<S1>/Selector1'
   *  Selector: '<S1>/Selector2'
   */
  bms_f4_DW.DiscreteTimeIntegrator_DSTATE_m += bms_f4_P.Gain_Gain_m *
    bms_f4_U.FromPlant.BMSBatteryPackData.SegmentCurrentVector[9] /
    look1_binlxpw(bms_f4_U.FromPlant.BMSBatteryPackData.SegmentTempVector[9],
                  bms_f4_P.nDLookupTable_bp01Data_m,
                  bms_f4_P.nDLookupTable_tableData_e, 2U) *
    bms_f4_P.DiscreteTimeIntegrator_gainva_m;
  if (bms_f4_DW.DiscreteTimeIntegrator_DSTATE_m >=
      bms_f4_P.DiscreteTimeIntegrator_Upper_mg) {
    bms_f4_DW.DiscreteTimeIntegrator_DSTATE_m =
      bms_f4_P.DiscreteTimeIntegrator_Upper_mg;
  } else if (bms_f4_DW.DiscreteTimeIntegrator_DSTATE_m <=
             bms_f4_P.DiscreteTimeIntegrator_Lower_lh) {
    bms_f4_DW.DiscreteTimeIntegrator_DSTATE_m =
      bms_f4_P.DiscreteTimeIntegrator_Lower_lh;
  }

  /* End of Update for DiscreteIntegrator: '<S10>/Discrete-Time Integrator' */

  /* Update for DiscreteIntegrator: '<S11>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S11>/Gain'
   *  Inport: '<Root>/FromPlant'
   *  Lookup_n-D: '<S11>/n-D Lookup Table'
   *  Product: '<S11>/Divide'
   *  Selector: '<S1>/Selector1'
   *  Selector: '<S1>/Selector2'
   */
  bms_f4_DW.DiscreteTimeIntegrator_DSTATE_b += bms_f4_P.Gain_Gain_fa *
    bms_f4_U.FromPlant.BMSBatteryPackData.SegmentCurrentVector[12] /
    look1_binlxpw(bms_f4_U.FromPlant.BMSBatteryPackData.SegmentTempVector[12],
                  bms_f4_P.nDLookupTable_bp01Data_c,
                  bms_f4_P.nDLookupTable_tableData_a, 2U) *
    bms_f4_P.DiscreteTimeIntegrator_gainv_do;
  if (bms_f4_DW.DiscreteTimeIntegrator_DSTATE_b >=
      bms_f4_P.DiscreteTimeIntegrator_Upper_nt) {
    bms_f4_DW.DiscreteTimeIntegrator_DSTATE_b =
      bms_f4_P.DiscreteTimeIntegrator_Upper_nt;
  } else if (bms_f4_DW.DiscreteTimeIntegrator_DSTATE_b <=
             bms_f4_P.DiscreteTimeIntegrator_LowerS_c) {
    bms_f4_DW.DiscreteTimeIntegrator_DSTATE_b =
      bms_f4_P.DiscreteTimeIntegrator_LowerS_c;
  }

  /* End of Update for DiscreteIntegrator: '<S11>/Discrete-Time Integrator' */

  /* Update for DiscreteIntegrator: '<S12>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S12>/Gain'
   *  Inport: '<Root>/FromPlant'
   *  Lookup_n-D: '<S12>/n-D Lookup Table'
   *  Product: '<S12>/Divide'
   *  Selector: '<S1>/Selector1'
   *  Selector: '<S1>/Selector2'
   */
  bms_f4_DW.DiscreteTimeIntegrator_DSTATE_p += bms_f4_P.Gain_Gain_l *
    bms_f4_U.FromPlant.BMSBatteryPackData.SegmentCurrentVector[15] /
    look1_binlxpw(bms_f4_U.FromPlant.BMSBatteryPackData.SegmentTempVector[15],
                  bms_f4_P.nDLookupTable_bp01Data_h,
                  bms_f4_P.nDLookupTable_tableData_h, 2U) *
    bms_f4_P.DiscreteTimeIntegrator_gainv_mu;
  if (bms_f4_DW.DiscreteTimeIntegrator_DSTATE_p >=
      bms_f4_P.DiscreteTimeIntegrator_UpperS_i) {
    bms_f4_DW.DiscreteTimeIntegrator_DSTATE_p =
      bms_f4_P.DiscreteTimeIntegrator_UpperS_i;
  } else if (bms_f4_DW.DiscreteTimeIntegrator_DSTATE_p <=
             bms_f4_P.DiscreteTimeIntegrator_LowerS_p) {
    bms_f4_DW.DiscreteTimeIntegrator_DSTATE_p =
      bms_f4_P.DiscreteTimeIntegrator_LowerS_p;
  }

  /* End of Update for DiscreteIntegrator: '<S12>/Discrete-Time Integrator' */

  /* Update for DiscreteIntegrator: '<S13>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S13>/Gain'
   *  Inport: '<Root>/FromPlant'
   *  Lookup_n-D: '<S13>/n-D Lookup Table'
   *  Product: '<S13>/Divide'
   *  Selector: '<S1>/Selector1'
   *  Selector: '<S1>/Selector2'
   */
  bms_f4_DW.DiscreteTimeIntegrator_DSTATE_c += bms_f4_P.Gain_Gain_c *
    bms_f4_U.FromPlant.BMSBatteryPackData.SegmentCurrentVector[18] /
    look1_binlxpw(bms_f4_U.FromPlant.BMSBatteryPackData.SegmentTempVector[18],
                  bms_f4_P.nDLookupTable_bp01Data_g,
                  bms_f4_P.nDLookupTable_tableData_m, 2U) *
    bms_f4_P.DiscreteTimeIntegrator_gainva_i;
  if (bms_f4_DW.DiscreteTimeIntegrator_DSTATE_c >=
      bms_f4_P.DiscreteTimeIntegrator_UpperS_e) {
    bms_f4_DW.DiscreteTimeIntegrator_DSTATE_c =
      bms_f4_P.DiscreteTimeIntegrator_UpperS_e;
  } else if (bms_f4_DW.DiscreteTimeIntegrator_DSTATE_c <=
             bms_f4_P.DiscreteTimeIntegrator_LowerS_h) {
    bms_f4_DW.DiscreteTimeIntegrator_DSTATE_c =
      bms_f4_P.DiscreteTimeIntegrator_LowerS_h;
  }

  /* End of Update for DiscreteIntegrator: '<S13>/Discrete-Time Integrator' */

  /* Update for DiscreteIntegrator: '<S14>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S14>/Gain'
   *  Inport: '<Root>/FromPlant'
   *  Lookup_n-D: '<S14>/n-D Lookup Table'
   *  Product: '<S14>/Divide'
   *  Selector: '<S1>/Selector1'
   *  Selector: '<S1>/Selector2'
   */
  bms_f4_DW.DiscreteTimeIntegrator_DSTAT_mh += bms_f4_P.Gain_Gain_n *
    bms_f4_U.FromPlant.BMSBatteryPackData.SegmentCurrentVector[21] /
    look1_binlxpw(bms_f4_U.FromPlant.BMSBatteryPackData.SegmentTempVector[21],
                  bms_f4_P.nDLookupTable_bp01Data_gg,
                  bms_f4_P.nDLookupTable_tableData_j, 2U) *
    bms_f4_P.DiscreteTimeIntegrator_gainva_l;
  if (bms_f4_DW.DiscreteTimeIntegrator_DSTAT_mh >=
      bms_f4_P.DiscreteTimeIntegrator_UpperS_f) {
    bms_f4_DW.DiscreteTimeIntegrator_DSTAT_mh =
      bms_f4_P.DiscreteTimeIntegrator_UpperS_f;
  } else if (bms_f4_DW.DiscreteTimeIntegrator_DSTAT_mh <=
             bms_f4_P.DiscreteTimeIntegrator_LowerS_f) {
    bms_f4_DW.DiscreteTimeIntegrator_DSTAT_mh =
      bms_f4_P.DiscreteTimeIntegrator_LowerS_f;
  }

  /* End of Update for DiscreteIntegrator: '<S14>/Discrete-Time Integrator' */

  /* Update for DiscreteIntegrator: '<S15>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S15>/Gain'
   *  Inport: '<Root>/FromPlant'
   *  Lookup_n-D: '<S15>/n-D Lookup Table'
   *  Product: '<S15>/Divide'
   *  Selector: '<S1>/Selector1'
   *  Selector: '<S1>/Selector2'
   */
  bms_f4_DW.DiscreteTimeIntegrator_DSTATE_g += bms_f4_P.Gain_Gain_o *
    bms_f4_U.FromPlant.BMSBatteryPackData.SegmentCurrentVector[24] /
    look1_binlxpw(bms_f4_U.FromPlant.BMSBatteryPackData.SegmentTempVector[24],
                  bms_f4_P.nDLookupTable_bp01Data_p,
                  bms_f4_P.nDLookupTable_tableData_i, 2U) *
    bms_f4_P.DiscreteTimeIntegrator_gainv_oo;
  if (bms_f4_DW.DiscreteTimeIntegrator_DSTATE_g >=
      bms_f4_P.DiscreteTimeIntegrator_UpperS_g) {
    bms_f4_DW.DiscreteTimeIntegrator_DSTATE_g =
      bms_f4_P.DiscreteTimeIntegrator_UpperS_g;
  } else if (bms_f4_DW.DiscreteTimeIntegrator_DSTATE_g <=
             bms_f4_P.DiscreteTimeIntegrator_LowerS_o) {
    bms_f4_DW.DiscreteTimeIntegrator_DSTATE_g =
      bms_f4_P.DiscreteTimeIntegrator_LowerS_o;
  }

  /* End of Update for DiscreteIntegrator: '<S15>/Discrete-Time Integrator' */

  /* Update for DiscreteIntegrator: '<S16>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S16>/Gain'
   *  Inport: '<Root>/FromPlant'
   *  Lookup_n-D: '<S16>/n-D Lookup Table'
   *  Product: '<S16>/Divide'
   *  Selector: '<S1>/Selector1'
   *  Selector: '<S1>/Selector2'
   */
  bms_f4_DW.DiscreteTimeIntegrator_DSTAT_g0 += bms_f4_P.Gain_Gain_la *
    bms_f4_U.FromPlant.BMSBatteryPackData.SegmentCurrentVector[27] /
    look1_binlxpw(bms_f4_U.FromPlant.BMSBatteryPackData.SegmentTempVector[27],
                  bms_f4_P.nDLookupTable_bp01Data_j,
                  bms_f4_P.nDLookupTable_tableData_fr, 2U) *
    bms_f4_P.DiscreteTimeIntegrator_gainva_p;
  if (bms_f4_DW.DiscreteTimeIntegrator_DSTAT_g0 >=
      bms_f4_P.DiscreteTimeIntegrator_UpperS_j) {
    bms_f4_DW.DiscreteTimeIntegrator_DSTAT_g0 =
      bms_f4_P.DiscreteTimeIntegrator_UpperS_j;
  } else if (bms_f4_DW.DiscreteTimeIntegrator_DSTAT_g0 <=
             bms_f4_P.DiscreteTimeIntegrator_LowerS_g) {
    bms_f4_DW.DiscreteTimeIntegrator_DSTAT_g0 =
      bms_f4_P.DiscreteTimeIntegrator_LowerS_g;
  }

  /* End of Update for DiscreteIntegrator: '<S16>/Discrete-Time Integrator' */

  /* Update for DiscreteIntegrator: '<S27>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S27>/Gain'
   *  Inport: '<Root>/FromPlant'
   *  Lookup_n-D: '<S27>/n-D Lookup Table'
   *  Product: '<S27>/Divide'
   *  Selector: '<S1>/Selector4'
   *  Selector: '<S1>/Selector5'
   */
  bms_f4_DW.DiscreteTimeIntegrator_DSTATE_d += bms_f4_P.Gain_Gain_ix *
    bms_f4_U.FromPlant.BMSBatteryPackData.SegmentCurrentVector[1] /
    look1_binlxpw(bms_f4_U.FromPlant.BMSBatteryPackData.SegmentTempVector[1],
                  bms_f4_P.nDLookupTable_bp01Data_f4,
                  bms_f4_P.nDLookupTable_tableData_b, 2U) *
    bms_f4_P.DiscreteTimeIntegrator_gainva_k;
  if (bms_f4_DW.DiscreteTimeIntegrator_DSTATE_d >=
      bms_f4_P.DiscreteTimeIntegrator_Upper_jp) {
    bms_f4_DW.DiscreteTimeIntegrator_DSTATE_d =
      bms_f4_P.DiscreteTimeIntegrator_Upper_jp;
  } else if (bms_f4_DW.DiscreteTimeIntegrator_DSTATE_d <=
             bms_f4_P.DiscreteTimeIntegrator_Lower_ge) {
    bms_f4_DW.DiscreteTimeIntegrator_DSTATE_d =
      bms_f4_P.DiscreteTimeIntegrator_Lower_ge;
  }

  /* End of Update for DiscreteIntegrator: '<S27>/Discrete-Time Integrator' */

  /* Update for DiscreteIntegrator: '<S18>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S18>/Gain'
   *  Inport: '<Root>/FromPlant'
   *  Lookup_n-D: '<S18>/n-D Lookup Table'
   *  Product: '<S18>/Divide'
   *  Selector: '<S1>/Selector4'
   *  Selector: '<S1>/Selector5'
   */
  bms_f4_DW.DiscreteTimeIntegrator_DSTAT_b0 += bms_f4_P.Gain_Gain_p *
    bms_f4_U.FromPlant.BMSBatteryPackData.SegmentCurrentVector[4] /
    look1_binlxpw(bms_f4_U.FromPlant.BMSBatteryPackData.SegmentTempVector[4],
                  bms_f4_P.nDLookupTable_bp01Data_i,
                  bms_f4_P.nDLookupTable_tableData_l, 2U) *
    bms_f4_P.DiscreteTimeIntegrator_gainv_ks;
  if (bms_f4_DW.DiscreteTimeIntegrator_DSTAT_b0 >=
      bms_f4_P.DiscreteTimeIntegrator_Upper_g2) {
    bms_f4_DW.DiscreteTimeIntegrator_DSTAT_b0 =
      bms_f4_P.DiscreteTimeIntegrator_Upper_g2;
  } else if (bms_f4_DW.DiscreteTimeIntegrator_DSTAT_b0 <=
             bms_f4_P.DiscreteTimeIntegrator_LowerS_k) {
    bms_f4_DW.DiscreteTimeIntegrator_DSTAT_b0 =
      bms_f4_P.DiscreteTimeIntegrator_LowerS_k;
  }

  /* End of Update for DiscreteIntegrator: '<S18>/Discrete-Time Integrator' */

  /* Update for DiscreteIntegrator: '<S19>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S19>/Gain'
   *  Inport: '<Root>/FromPlant'
   *  Lookup_n-D: '<S19>/n-D Lookup Table'
   *  Product: '<S19>/Divide'
   *  Selector: '<S1>/Selector4'
   *  Selector: '<S1>/Selector5'
   */
  bms_f4_DW.DiscreteTimeIntegrator_DSTAT_dc += bms_f4_P.Gain_Gain_d *
    bms_f4_U.FromPlant.BMSBatteryPackData.SegmentCurrentVector[7] /
    look1_binlxpw(bms_f4_U.FromPlant.BMSBatteryPackData.SegmentTempVector[7],
                  bms_f4_P.nDLookupTable_bp01Data_pr,
                  bms_f4_P.nDLookupTable_tableData_md, 2U) *
    bms_f4_P.DiscreteTimeIntegrator_gainva_c;
  if (bms_f4_DW.DiscreteTimeIntegrator_DSTAT_dc >=
      bms_f4_P.DiscreteTimeIntegrator_Upper_gd) {
    bms_f4_DW.DiscreteTimeIntegrator_DSTAT_dc =
      bms_f4_P.DiscreteTimeIntegrator_Upper_gd;
  } else if (bms_f4_DW.DiscreteTimeIntegrator_DSTAT_dc <=
             bms_f4_P.DiscreteTimeIntegrator_Lower_c5) {
    bms_f4_DW.DiscreteTimeIntegrator_DSTAT_dc =
      bms_f4_P.DiscreteTimeIntegrator_Lower_c5;
  }

  /* End of Update for DiscreteIntegrator: '<S19>/Discrete-Time Integrator' */

  /* Update for DiscreteIntegrator: '<S20>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S20>/Gain'
   *  Inport: '<Root>/FromPlant'
   *  Lookup_n-D: '<S20>/n-D Lookup Table'
   *  Product: '<S20>/Divide'
   *  Selector: '<S1>/Selector4'
   *  Selector: '<S1>/Selector5'
   */
  bms_f4_DW.DiscreteTimeIntegrator_DSTATE_o += bms_f4_P.Gain_Gain_e *
    bms_f4_U.FromPlant.BMSBatteryPackData.SegmentCurrentVector[10] /
    look1_binlxpw(bms_f4_U.FromPlant.BMSBatteryPackData.SegmentTempVector[10],
                  bms_f4_P.nDLookupTable_bp01Data_ch,
                  bms_f4_P.nDLookupTable_tableData_aj, 2U) *
    bms_f4_P.DiscreteTimeIntegrator_gainva_a;
  if (bms_f4_DW.DiscreteTimeIntegrator_DSTATE_o >=
      bms_f4_P.DiscreteTimeIntegrator_UpperS_b) {
    bms_f4_DW.DiscreteTimeIntegrator_DSTATE_o =
      bms_f4_P.DiscreteTimeIntegrator_UpperS_b;
  } else if (bms_f4_DW.DiscreteTimeIntegrator_DSTATE_o <=
             bms_f4_P.DiscreteTimeIntegrator_LowerS_b) {
    bms_f4_DW.DiscreteTimeIntegrator_DSTATE_o =
      bms_f4_P.DiscreteTimeIntegrator_LowerS_b;
  }

  /* End of Update for DiscreteIntegrator: '<S20>/Discrete-Time Integrator' */

  /* Update for DiscreteIntegrator: '<S21>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S21>/Gain'
   *  Inport: '<Root>/FromPlant'
   *  Lookup_n-D: '<S21>/n-D Lookup Table'
   *  Product: '<S21>/Divide'
   *  Selector: '<S1>/Selector4'
   *  Selector: '<S1>/Selector5'
   */
  bms_f4_DW.DiscreteTimeIntegrator_DSTAT_aw += bms_f4_P.Gain_Gain_i *
    bms_f4_U.FromPlant.BMSBatteryPackData.SegmentCurrentVector[13] /
    look1_binlxpw(bms_f4_U.FromPlant.BMSBatteryPackData.SegmentTempVector[13],
                  bms_f4_P.nDLookupTable_bp01Data_l,
                  bms_f4_P.nDLookupTable_tableData_p, 2U) *
    bms_f4_P.DiscreteTimeIntegrator_gainva_n;
  if (bms_f4_DW.DiscreteTimeIntegrator_DSTAT_aw >=
      bms_f4_P.DiscreteTimeIntegrator_Upper_f5) {
    bms_f4_DW.DiscreteTimeIntegrator_DSTAT_aw =
      bms_f4_P.DiscreteTimeIntegrator_Upper_f5;
  } else if (bms_f4_DW.DiscreteTimeIntegrator_DSTAT_aw <=
             bms_f4_P.DiscreteTimeIntegrator_Lower_pb) {
    bms_f4_DW.DiscreteTimeIntegrator_DSTAT_aw =
      bms_f4_P.DiscreteTimeIntegrator_Lower_pb;
  }

  /* End of Update for DiscreteIntegrator: '<S21>/Discrete-Time Integrator' */

  /* Update for DiscreteIntegrator: '<S22>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S22>/Gain'
   *  Inport: '<Root>/FromPlant'
   *  Lookup_n-D: '<S22>/n-D Lookup Table'
   *  Product: '<S22>/Divide'
   *  Selector: '<S1>/Selector4'
   *  Selector: '<S1>/Selector5'
   */
  bms_f4_DW.DiscreteTimeIntegrator_DSTATE_n += bms_f4_P.Gain_Gain_fu *
    bms_f4_U.FromPlant.BMSBatteryPackData.SegmentCurrentVector[16] /
    look1_binlxpw(bms_f4_U.FromPlant.BMSBatteryPackData.SegmentTempVector[16],
                  bms_f4_P.nDLookupTable_bp01Data_gb,
                  bms_f4_P.nDLookupTable_tableData_mk, 2U) *
    bms_f4_P.DiscreteTimeIntegrator_gainv_co;
  if (bms_f4_DW.DiscreteTimeIntegrator_DSTATE_n >=
      bms_f4_P.DiscreteTimeIntegrator_Upper_i0) {
    bms_f4_DW.DiscreteTimeIntegrator_DSTATE_n =
      bms_f4_P.DiscreteTimeIntegrator_Upper_i0;
  } else if (bms_f4_DW.DiscreteTimeIntegrator_DSTATE_n <=
             bms_f4_P.DiscreteTimeIntegrator_Lower_gd) {
    bms_f4_DW.DiscreteTimeIntegrator_DSTATE_n =
      bms_f4_P.DiscreteTimeIntegrator_Lower_gd;
  }

  /* End of Update for DiscreteIntegrator: '<S22>/Discrete-Time Integrator' */

  /* Update for DiscreteIntegrator: '<S23>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S23>/Gain'
   *  Inport: '<Root>/FromPlant'
   *  Lookup_n-D: '<S23>/n-D Lookup Table'
   *  Product: '<S23>/Divide'
   *  Selector: '<S1>/Selector4'
   *  Selector: '<S1>/Selector5'
   */
  bms_f4_DW.DiscreteTimeIntegrator_DSTATE_e += bms_f4_P.Gain_Gain_b *
    bms_f4_U.FromPlant.BMSBatteryPackData.SegmentCurrentVector[19] /
    look1_binlxpw(bms_f4_U.FromPlant.BMSBatteryPackData.SegmentTempVector[19],
                  bms_f4_P.nDLookupTable_bp01Data_ll,
                  bms_f4_P.nDLookupTable_tableData_o, 2U) *
    bms_f4_P.DiscreteTimeIntegrator_gainva_f;
  if (bms_f4_DW.DiscreteTimeIntegrator_DSTATE_e >=
      bms_f4_P.DiscreteTimeIntegrator_UpperS_h) {
    bms_f4_DW.DiscreteTimeIntegrator_DSTATE_e =
      bms_f4_P.DiscreteTimeIntegrator_UpperS_h;
  } else if (bms_f4_DW.DiscreteTimeIntegrator_DSTATE_e <=
             bms_f4_P.DiscreteTimeIntegrator_Lower_hb) {
    bms_f4_DW.DiscreteTimeIntegrator_DSTATE_e =
      bms_f4_P.DiscreteTimeIntegrator_Lower_hb;
  }

  /* End of Update for DiscreteIntegrator: '<S23>/Discrete-Time Integrator' */

  /* Update for DiscreteIntegrator: '<S24>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S24>/Gain'
   *  Inport: '<Root>/FromPlant'
   *  Lookup_n-D: '<S24>/n-D Lookup Table'
   *  Product: '<S24>/Divide'
   *  Selector: '<S1>/Selector4'
   *  Selector: '<S1>/Selector5'
   */
  bms_f4_DW.DiscreteTimeIntegrator_DSTATE_f += bms_f4_P.Gain_Gain_k *
    bms_f4_U.FromPlant.BMSBatteryPackData.SegmentCurrentVector[22] /
    look1_binlxpw(bms_f4_U.FromPlant.BMSBatteryPackData.SegmentTempVector[22],
                  bms_f4_P.nDLookupTable_bp01Data_b,
                  bms_f4_P.nDLookupTable_tableData_o3, 2U) *
    bms_f4_P.DiscreteTimeIntegrator_gainv_cu;
  if (bms_f4_DW.DiscreteTimeIntegrator_DSTATE_f >=
      bms_f4_P.DiscreteTimeIntegrator_Upper_e1) {
    bms_f4_DW.DiscreteTimeIntegrator_DSTATE_f =
      bms_f4_P.DiscreteTimeIntegrator_Upper_e1;
  } else if (bms_f4_DW.DiscreteTimeIntegrator_DSTATE_f <=
             bms_f4_P.DiscreteTimeIntegrator_Lower_pz) {
    bms_f4_DW.DiscreteTimeIntegrator_DSTATE_f =
      bms_f4_P.DiscreteTimeIntegrator_Lower_pz;
  }

  /* End of Update for DiscreteIntegrator: '<S24>/Discrete-Time Integrator' */

  /* Update for DiscreteIntegrator: '<S25>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S25>/Gain'
   *  Inport: '<Root>/FromPlant'
   *  Lookup_n-D: '<S25>/n-D Lookup Table'
   *  Product: '<S25>/Divide'
   *  Selector: '<S1>/Selector4'
   *  Selector: '<S1>/Selector5'
   */
  bms_f4_DW.DiscreteTimeIntegrator_DSTAT_aj += bms_f4_P.Gain_Gain_bj *
    bms_f4_U.FromPlant.BMSBatteryPackData.SegmentCurrentVector[25] /
    look1_binlxpw(bms_f4_U.FromPlant.BMSBatteryPackData.SegmentTempVector[25],
                  bms_f4_P.nDLookupTable_bp01Data_f,
                  bms_f4_P.nDLookupTable_tableData_pv, 2U) *
    bms_f4_P.DiscreteTimeIntegrator_gainva_e;
  if (bms_f4_DW.DiscreteTimeIntegrator_DSTAT_aj >=
      bms_f4_P.DiscreteTimeIntegrator_Upper_g4) {
    bms_f4_DW.DiscreteTimeIntegrator_DSTAT_aj =
      bms_f4_P.DiscreteTimeIntegrator_Upper_g4;
  } else if (bms_f4_DW.DiscreteTimeIntegrator_DSTAT_aj <=
             bms_f4_P.DiscreteTimeIntegrator_LowerS_m) {
    bms_f4_DW.DiscreteTimeIntegrator_DSTAT_aj =
      bms_f4_P.DiscreteTimeIntegrator_LowerS_m;
  }

  /* End of Update for DiscreteIntegrator: '<S25>/Discrete-Time Integrator' */

  /* Update for DiscreteIntegrator: '<S26>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S26>/Gain'
   *  Inport: '<Root>/FromPlant'
   *  Lookup_n-D: '<S26>/n-D Lookup Table'
   *  Product: '<S26>/Divide'
   *  Selector: '<S1>/Selector4'
   *  Selector: '<S1>/Selector5'
   */
  bms_f4_DW.DiscreteTimeIntegrator_DSTAT_bc += bms_f4_P.Gain_Gain_bi *
    bms_f4_U.FromPlant.BMSBatteryPackData.SegmentCurrentVector[28] /
    look1_binlxpw(bms_f4_U.FromPlant.BMSBatteryPackData.SegmentTempVector[28],
                  bms_f4_P.nDLookupTable_bp01Data_hs,
                  bms_f4_P.nDLookupTable_tableData_mx, 2U) *
    bms_f4_P.DiscreteTimeIntegrator_gainv_pk;
  if (bms_f4_DW.DiscreteTimeIntegrator_DSTAT_bc >=
      bms_f4_P.DiscreteTimeIntegrator_UpperS_o) {
    bms_f4_DW.DiscreteTimeIntegrator_DSTAT_bc =
      bms_f4_P.DiscreteTimeIntegrator_UpperS_o;
  } else if (bms_f4_DW.DiscreteTimeIntegrator_DSTAT_bc <=
             bms_f4_P.DiscreteTimeIntegrator_Lower_k0) {
    bms_f4_DW.DiscreteTimeIntegrator_DSTAT_bc =
      bms_f4_P.DiscreteTimeIntegrator_Lower_k0;
  }

  /* End of Update for DiscreteIntegrator: '<S26>/Discrete-Time Integrator' */

  /* Update for DiscreteIntegrator: '<S37>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S37>/Gain'
   *  Inport: '<Root>/FromPlant'
   *  Lookup_n-D: '<S37>/n-D Lookup Table'
   *  Product: '<S37>/Divide'
   *  Selector: '<S1>/Selector7'
   *  Selector: '<S1>/Selector8'
   */
  bms_f4_DW.DiscreteTimeIntegrator_DSTAT_ps += bms_f4_P.Gain_Gain_oa *
    bms_f4_U.FromPlant.BMSBatteryPackData.SegmentCurrentVector[2] /
    look1_binlxpw(bms_f4_U.FromPlant.BMSBatteryPackData.SegmentTempVector[2],
                  bms_f4_P.nDLookupTable_bp01Data_d4,
                  bms_f4_P.nDLookupTable_tableData_hk, 2U) *
    bms_f4_P.DiscreteTimeIntegrator_gainv_nb;
  if (bms_f4_DW.DiscreteTimeIntegrator_DSTAT_ps >=
      bms_f4_P.DiscreteTimeIntegrator_UpperS_p) {
    bms_f4_DW.DiscreteTimeIntegrator_DSTAT_ps =
      bms_f4_P.DiscreteTimeIntegrator_UpperS_p;
  } else if (bms_f4_DW.DiscreteTimeIntegrator_DSTAT_ps <=
             bms_f4_P.DiscreteTimeIntegrator_LowerS_a) {
    bms_f4_DW.DiscreteTimeIntegrator_DSTAT_ps =
      bms_f4_P.DiscreteTimeIntegrator_LowerS_a;
  }

  /* End of Update for DiscreteIntegrator: '<S37>/Discrete-Time Integrator' */

  /* Update for DiscreteIntegrator: '<S28>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S28>/Gain'
   *  Inport: '<Root>/FromPlant'
   *  Lookup_n-D: '<S28>/n-D Lookup Table'
   *  Product: '<S28>/Divide'
   *  Selector: '<S1>/Selector7'
   *  Selector: '<S1>/Selector8'
   */
  bms_f4_DW.DiscreteTimeIntegrator_DSTAT_ed += bms_f4_P.Gain_Gain_dp *
    bms_f4_U.FromPlant.BMSBatteryPackData.SegmentCurrentVector[5] /
    look1_binlxpw(bms_f4_U.FromPlant.BMSBatteryPackData.SegmentTempVector[5],
                  bms_f4_P.nDLookupTable_bp01Data_ky,
                  bms_f4_P.nDLookupTable_tableData_lf, 2U) *
    bms_f4_P.DiscreteTimeIntegrator_gainv_a5;
  if (bms_f4_DW.DiscreteTimeIntegrator_DSTAT_ed >=
      bms_f4_P.DiscreteTimeIntegrator_UpperS_c) {
    bms_f4_DW.DiscreteTimeIntegrator_DSTAT_ed =
      bms_f4_P.DiscreteTimeIntegrator_UpperS_c;
  } else if (bms_f4_DW.DiscreteTimeIntegrator_DSTAT_ed <=
             bms_f4_P.DiscreteTimeIntegrator_Lower_ae) {
    bms_f4_DW.DiscreteTimeIntegrator_DSTAT_ed =
      bms_f4_P.DiscreteTimeIntegrator_Lower_ae;
  }

  /* End of Update for DiscreteIntegrator: '<S28>/Discrete-Time Integrator' */

  /* Update for DiscreteIntegrator: '<S29>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S29>/Gain'
   *  Inport: '<Root>/FromPlant'
   *  Lookup_n-D: '<S29>/n-D Lookup Table'
   *  Product: '<S29>/Divide'
   *  Selector: '<S1>/Selector7'
   *  Selector: '<S1>/Selector8'
   */
  bms_f4_DW.DiscreteTimeIntegrator_DSTAT_mg += bms_f4_P.Gain_Gain_kc *
    bms_f4_U.FromPlant.BMSBatteryPackData.SegmentCurrentVector[8] /
    look1_binlxpw(bms_f4_U.FromPlant.BMSBatteryPackData.SegmentTempVector[8],
                  bms_f4_P.nDLookupTable_bp01Data_ot,
                  bms_f4_P.nDLookupTable_tableData_k, 2U) *
    bms_f4_P.DiscreteTimeIntegrator_gainv_md;
  if (bms_f4_DW.DiscreteTimeIntegrator_DSTAT_mg >=
      bms_f4_P.DiscreteTimeIntegrator_UpperS_d) {
    bms_f4_DW.DiscreteTimeIntegrator_DSTAT_mg =
      bms_f4_P.DiscreteTimeIntegrator_UpperS_d;
  } else if (bms_f4_DW.DiscreteTimeIntegrator_DSTAT_mg <=
             bms_f4_P.DiscreteTimeIntegrator_LowerS_d) {
    bms_f4_DW.DiscreteTimeIntegrator_DSTAT_mg =
      bms_f4_P.DiscreteTimeIntegrator_LowerS_d;
  }

  /* End of Update for DiscreteIntegrator: '<S29>/Discrete-Time Integrator' */

  /* Update for DiscreteIntegrator: '<S30>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S30>/Gain'
   *  Inport: '<Root>/FromPlant'
   *  Lookup_n-D: '<S30>/n-D Lookup Table'
   *  Product: '<S30>/Divide'
   *  Selector: '<S1>/Selector7'
   *  Selector: '<S1>/Selector8'
   */
  bms_f4_DW.DiscreteTimeIntegrator_DSTAT_fy += bms_f4_P.Gain_Gain_ek *
    bms_f4_U.FromPlant.BMSBatteryPackData.SegmentCurrentVector[11] /
    look1_binlxpw(bms_f4_U.FromPlant.BMSBatteryPackData.SegmentTempVector[11],
                  bms_f4_P.nDLookupTable_bp01Data_bp,
                  bms_f4_P.nDLookupTable_tableData_o2, 2U) *
    bms_f4_P.DiscreteTimeIntegrator_gainv_lm;
  if (bms_f4_DW.DiscreteTimeIntegrator_DSTAT_fy >=
      bms_f4_P.DiscreteTimeIntegrator_Upper_eg) {
    bms_f4_DW.DiscreteTimeIntegrator_DSTAT_fy =
      bms_f4_P.DiscreteTimeIntegrator_Upper_eg;
  } else if (bms_f4_DW.DiscreteTimeIntegrator_DSTAT_fy <=
             bms_f4_P.DiscreteTimeIntegrator_Lower_do) {
    bms_f4_DW.DiscreteTimeIntegrator_DSTAT_fy =
      bms_f4_P.DiscreteTimeIntegrator_Lower_do;
  }

  /* End of Update for DiscreteIntegrator: '<S30>/Discrete-Time Integrator' */

  /* Update for DiscreteIntegrator: '<S31>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S31>/Gain'
   *  Inport: '<Root>/FromPlant'
   *  Lookup_n-D: '<S31>/n-D Lookup Table'
   *  Product: '<S31>/Divide'
   *  Selector: '<S1>/Selector7'
   *  Selector: '<S1>/Selector8'
   */
  bms_f4_DW.DiscreteTimeIntegrator_DSTAT_gd += bms_f4_P.Gain_Gain_pp *
    bms_f4_U.FromPlant.BMSBatteryPackData.SegmentCurrentVector[14] /
    look1_binlxpw(bms_f4_U.FromPlant.BMSBatteryPackData.SegmentTempVector[14],
                  bms_f4_P.nDLookupTable_bp01Data_d,
                  bms_f4_P.nDLookupTable_tableData_n, 2U) *
    bms_f4_P.DiscreteTimeIntegrator_gainv_ae;
  if (bms_f4_DW.DiscreteTimeIntegrator_DSTAT_gd >=
      bms_f4_P.DiscreteTimeIntegrator_Upper_hx) {
    bms_f4_DW.DiscreteTimeIntegrator_DSTAT_gd =
      bms_f4_P.DiscreteTimeIntegrator_Upper_hx;
  } else if (bms_f4_DW.DiscreteTimeIntegrator_DSTAT_gd <=
             bms_f4_P.DiscreteTimeIntegrator_Lower_em) {
    bms_f4_DW.DiscreteTimeIntegrator_DSTAT_gd =
      bms_f4_P.DiscreteTimeIntegrator_Lower_em;
  }

  /* End of Update for DiscreteIntegrator: '<S31>/Discrete-Time Integrator' */

  /* Update for DiscreteIntegrator: '<S32>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S32>/Gain'
   *  Inport: '<Root>/FromPlant'
   *  Lookup_n-D: '<S32>/n-D Lookup Table'
   *  Product: '<S32>/Divide'
   *  Selector: '<S1>/Selector7'
   *  Selector: '<S1>/Selector8'
   */
  bms_f4_DW.DiscreteTimeIntegrator_DSTATE_i += bms_f4_P.Gain_Gain_oh *
    bms_f4_U.FromPlant.BMSBatteryPackData.SegmentCurrentVector[17] /
    look1_binlxpw(bms_f4_U.FromPlant.BMSBatteryPackData.SegmentTempVector[17],
                  bms_f4_P.nDLookupTable_bp01Data_iz,
                  bms_f4_P.nDLookupTable_tableData_bj, 2U) *
    bms_f4_P.DiscreteTimeIntegrator_gainv_lx;
  if (bms_f4_DW.DiscreteTimeIntegrator_DSTATE_i >=
      bms_f4_P.DiscreteTimeIntegrator_Upper_ng) {
    bms_f4_DW.DiscreteTimeIntegrator_DSTATE_i =
      bms_f4_P.DiscreteTimeIntegrator_Upper_ng;
  } else if (bms_f4_DW.DiscreteTimeIntegrator_DSTATE_i <=
             bms_f4_P.DiscreteTimeIntegrator_Lower_oi) {
    bms_f4_DW.DiscreteTimeIntegrator_DSTATE_i =
      bms_f4_P.DiscreteTimeIntegrator_Lower_oi;
  }

  /* End of Update for DiscreteIntegrator: '<S32>/Discrete-Time Integrator' */

  /* Update for DiscreteIntegrator: '<S33>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S33>/Gain'
   *  Inport: '<Root>/FromPlant'
   *  Lookup_n-D: '<S33>/n-D Lookup Table'
   *  Product: '<S33>/Divide'
   *  Selector: '<S1>/Selector7'
   *  Selector: '<S1>/Selector8'
   */
  bms_f4_DW.DiscreteTimeIntegrator_DSTAT_ce += bms_f4_P.Gain_Gain_pe *
    bms_f4_U.FromPlant.BMSBatteryPackData.SegmentCurrentVector[20] /
    look1_binlxpw(bms_f4_U.FromPlant.BMSBatteryPackData.SegmentTempVector[20],
                  bms_f4_P.nDLookupTable_bp01Data_ow,
                  bms_f4_P.nDLookupTable_tableData_oo, 2U) *
    bms_f4_P.DiscreteTimeIntegrator_gain_pkl;
  if (bms_f4_DW.DiscreteTimeIntegrator_DSTAT_ce >=
      bms_f4_P.DiscreteTimeIntegrator_Upper_ei) {
    bms_f4_DW.DiscreteTimeIntegrator_DSTAT_ce =
      bms_f4_P.DiscreteTimeIntegrator_Upper_ei;
  } else if (bms_f4_DW.DiscreteTimeIntegrator_DSTAT_ce <=
             bms_f4_P.DiscreteTimeIntegrator_LowerS_i) {
    bms_f4_DW.DiscreteTimeIntegrator_DSTAT_ce =
      bms_f4_P.DiscreteTimeIntegrator_LowerS_i;
  }

  /* End of Update for DiscreteIntegrator: '<S33>/Discrete-Time Integrator' */

  /* Update for DiscreteIntegrator: '<S34>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S34>/Gain'
   *  Inport: '<Root>/FromPlant'
   *  Lookup_n-D: '<S34>/n-D Lookup Table'
   *  Product: '<S34>/Divide'
   *  Selector: '<S1>/Selector7'
   *  Selector: '<S1>/Selector8'
   */
  bms_f4_DW.DiscreteTimeIntegrator_DSTAT_p0 += bms_f4_P.Gain_Gain_g *
    bms_f4_U.FromPlant.BMSBatteryPackData.SegmentCurrentVector[23] /
    look1_binlxpw(bms_f4_U.FromPlant.BMSBatteryPackData.SegmentTempVector[23],
                  bms_f4_P.nDLookupTable_bp01Data_ko,
                  bms_f4_P.nDLookupTable_tableData_aa, 2U) *
    bms_f4_P.DiscreteTimeIntegrator_gain_lxl;
  if (bms_f4_DW.DiscreteTimeIntegrator_DSTAT_p0 >=
      bms_f4_P.DiscreteTimeIntegrator_Upper_cc) {
    bms_f4_DW.DiscreteTimeIntegrator_DSTAT_p0 =
      bms_f4_P.DiscreteTimeIntegrator_Upper_cc;
  } else if (bms_f4_DW.DiscreteTimeIntegrator_DSTAT_p0 <=
             bms_f4_P.DiscreteTimeIntegrator_Lower_cp) {
    bms_f4_DW.DiscreteTimeIntegrator_DSTAT_p0 =
      bms_f4_P.DiscreteTimeIntegrator_Lower_cp;
  }

  /* End of Update for DiscreteIntegrator: '<S34>/Discrete-Time Integrator' */

  /* Update for DiscreteIntegrator: '<S35>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S35>/Gain'
   *  Inport: '<Root>/FromPlant'
   *  Lookup_n-D: '<S35>/n-D Lookup Table'
   *  Product: '<S35>/Divide'
   *  Selector: '<S1>/Selector7'
   *  Selector: '<S1>/Selector8'
   */
  bms_f4_DW.DiscreteTimeIntegrator_DSTAT_fb += bms_f4_P.Gain_Gain_cn *
    bms_f4_U.FromPlant.BMSBatteryPackData.SegmentCurrentVector[26] /
    look1_binlxpw(bms_f4_U.FromPlant.BMSBatteryPackData.SegmentTempVector[26],
                  bms_f4_P.nDLookupTable_bp01Data_lc,
                  bms_f4_P.nDLookupTable_tableData_d, 2U) *
    bms_f4_P.DiscreteTimeIntegrator_gainv_ea;
  if (bms_f4_DW.DiscreteTimeIntegrator_DSTAT_fb >=
      bms_f4_P.DiscreteTimeIntegrator_Upper_jh) {
    bms_f4_DW.DiscreteTimeIntegrator_DSTAT_fb =
      bms_f4_P.DiscreteTimeIntegrator_Upper_jh;
  } else if (bms_f4_DW.DiscreteTimeIntegrator_DSTAT_fb <=
             bms_f4_P.DiscreteTimeIntegrator_Lower_ig) {
    bms_f4_DW.DiscreteTimeIntegrator_DSTAT_fb =
      bms_f4_P.DiscreteTimeIntegrator_Lower_ig;
  }

  /* End of Update for DiscreteIntegrator: '<S35>/Discrete-Time Integrator' */

  /* Update for DiscreteIntegrator: '<S36>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S36>/Gain'
   *  Inport: '<Root>/FromPlant'
   *  Lookup_n-D: '<S36>/n-D Lookup Table'
   *  Product: '<S36>/Divide'
   *  Selector: '<S1>/Selector7'
   *  Selector: '<S1>/Selector8'
   */
  bms_f4_DW.DiscreteTimeIntegrator_DSTAT_d3 += bms_f4_P.Gain_Gain_j *
    bms_f4_U.FromPlant.BMSBatteryPackData.SegmentCurrentVector[29] /
    look1_binlxpw(bms_f4_U.FromPlant.BMSBatteryPackData.SegmentTempVector[29],
                  bms_f4_P.nDLookupTable_bp01Data_mh,
                  bms_f4_P.nDLookupTable_tableData_f0, 2U) *
    bms_f4_P.DiscreteTimeIntegrator_gainv_ol;
  if (bms_f4_DW.DiscreteTimeIntegrator_DSTAT_d3 >=
      bms_f4_P.DiscreteTimeIntegrator_Upper_m0) {
    bms_f4_DW.DiscreteTimeIntegrator_DSTAT_d3 =
      bms_f4_P.DiscreteTimeIntegrator_Upper_m0;
  } else if (bms_f4_DW.DiscreteTimeIntegrator_DSTAT_d3 <=
             bms_f4_P.DiscreteTimeIntegrator_Lower_ou) {
    bms_f4_DW.DiscreteTimeIntegrator_DSTAT_d3 =
      bms_f4_P.DiscreteTimeIntegrator_Lower_ou;
  }

  /* End of Update for DiscreteIntegrator: '<S36>/Discrete-Time Integrator' */
}

/* Model initialize function */
void bms_f4_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* InitializeConditions for DiscreteIntegrator: '<S17>/Discrete-Time Integrator' */
  bms_f4_DW.DiscreteTimeIntegrator_DSTATE = bms_f4_P.DiscreteTimeIntegrator_IC;

  /* InitializeConditions for DiscreteIntegrator: '<S8>/Discrete-Time Integrator' */
  bms_f4_DW.DiscreteTimeIntegrator_DSTATE_a =
    bms_f4_P.DiscreteTimeIntegrator_IC_h;

  /* InitializeConditions for DiscreteIntegrator: '<S9>/Discrete-Time Integrator' */
  bms_f4_DW.DiscreteTimeIntegrator_DSTAT_au =
    bms_f4_P.DiscreteTimeIntegrator_IC_d;

  /* InitializeConditions for DiscreteIntegrator: '<S10>/Discrete-Time Integrator' */
  bms_f4_DW.DiscreteTimeIntegrator_DSTATE_m =
    bms_f4_P.DiscreteTimeIntegrator_IC_m;

  /* InitializeConditions for DiscreteIntegrator: '<S11>/Discrete-Time Integrator' */
  bms_f4_DW.DiscreteTimeIntegrator_DSTATE_b =
    bms_f4_P.DiscreteTimeIntegrator_IC_l;

  /* InitializeConditions for DiscreteIntegrator: '<S12>/Discrete-Time Integrator' */
  bms_f4_DW.DiscreteTimeIntegrator_DSTATE_p =
    bms_f4_P.DiscreteTimeIntegrator_IC_p;

  /* InitializeConditions for DiscreteIntegrator: '<S13>/Discrete-Time Integrator' */
  bms_f4_DW.DiscreteTimeIntegrator_DSTATE_c =
    bms_f4_P.DiscreteTimeIntegrator_IC_o;

  /* InitializeConditions for DiscreteIntegrator: '<S14>/Discrete-Time Integrator' */
  bms_f4_DW.DiscreteTimeIntegrator_DSTAT_mh =
    bms_f4_P.DiscreteTimeIntegrator_IC_m3;

  /* InitializeConditions for DiscreteIntegrator: '<S15>/Discrete-Time Integrator' */
  bms_f4_DW.DiscreteTimeIntegrator_DSTATE_g =
    bms_f4_P.DiscreteTimeIntegrator_IC_e;

  /* InitializeConditions for DiscreteIntegrator: '<S16>/Discrete-Time Integrator' */
  bms_f4_DW.DiscreteTimeIntegrator_DSTAT_g0 =
    bms_f4_P.DiscreteTimeIntegrator_IC_ou;

  /* InitializeConditions for DiscreteIntegrator: '<S27>/Discrete-Time Integrator' */
  bms_f4_DW.DiscreteTimeIntegrator_DSTATE_d =
    bms_f4_P.DiscreteTimeIntegrator_IC_b;

  /* InitializeConditions for DiscreteIntegrator: '<S18>/Discrete-Time Integrator' */
  bms_f4_DW.DiscreteTimeIntegrator_DSTAT_b0 =
    bms_f4_P.DiscreteTimeIntegrator_IC_dx;

  /* InitializeConditions for DiscreteIntegrator: '<S19>/Discrete-Time Integrator' */
  bms_f4_DW.DiscreteTimeIntegrator_DSTAT_dc =
    bms_f4_P.DiscreteTimeIntegrator_IC_lq;

  /* InitializeConditions for DiscreteIntegrator: '<S20>/Discrete-Time Integrator' */
  bms_f4_DW.DiscreteTimeIntegrator_DSTATE_o =
    bms_f4_P.DiscreteTimeIntegrator_IC_oq;

  /* InitializeConditions for DiscreteIntegrator: '<S21>/Discrete-Time Integrator' */
  bms_f4_DW.DiscreteTimeIntegrator_DSTAT_aw =
    bms_f4_P.DiscreteTimeIntegrator_IC_dk;

  /* InitializeConditions for DiscreteIntegrator: '<S22>/Discrete-Time Integrator' */
  bms_f4_DW.DiscreteTimeIntegrator_DSTATE_n =
    bms_f4_P.DiscreteTimeIntegrator_IC_on;

  /* InitializeConditions for DiscreteIntegrator: '<S23>/Discrete-Time Integrator' */
  bms_f4_DW.DiscreteTimeIntegrator_DSTATE_e =
    bms_f4_P.DiscreteTimeIntegrator_IC_c;

  /* InitializeConditions for DiscreteIntegrator: '<S24>/Discrete-Time Integrator' */
  bms_f4_DW.DiscreteTimeIntegrator_DSTATE_f =
    bms_f4_P.DiscreteTimeIntegrator_IC_lt;

  /* InitializeConditions for DiscreteIntegrator: '<S25>/Discrete-Time Integrator' */
  bms_f4_DW.DiscreteTimeIntegrator_DSTAT_aj =
    bms_f4_P.DiscreteTimeIntegrator_IC_k;

  /* InitializeConditions for DiscreteIntegrator: '<S26>/Discrete-Time Integrator' */
  bms_f4_DW.DiscreteTimeIntegrator_DSTAT_bc =
    bms_f4_P.DiscreteTimeIntegrator_IC_dc;

  /* InitializeConditions for DiscreteIntegrator: '<S37>/Discrete-Time Integrator' */
  bms_f4_DW.DiscreteTimeIntegrator_DSTAT_ps =
    bms_f4_P.DiscreteTimeIntegrator_IC_j;

  /* InitializeConditions for DiscreteIntegrator: '<S28>/Discrete-Time Integrator' */
  bms_f4_DW.DiscreteTimeIntegrator_DSTAT_ed =
    bms_f4_P.DiscreteTimeIntegrator_IC_hw;

  /* InitializeConditions for DiscreteIntegrator: '<S29>/Discrete-Time Integrator' */
  bms_f4_DW.DiscreteTimeIntegrator_DSTAT_mg =
    bms_f4_P.DiscreteTimeIntegrator_IC_dv;

  /* InitializeConditions for DiscreteIntegrator: '<S30>/Discrete-Time Integrator' */
  bms_f4_DW.DiscreteTimeIntegrator_DSTAT_fy =
    bms_f4_P.DiscreteTimeIntegrator_IC_l1;

  /* InitializeConditions for DiscreteIntegrator: '<S31>/Discrete-Time Integrator' */
  bms_f4_DW.DiscreteTimeIntegrator_DSTAT_gd =
    bms_f4_P.DiscreteTimeIntegrator_IC_i;

  /* InitializeConditions for DiscreteIntegrator: '<S32>/Discrete-Time Integrator' */
  bms_f4_DW.DiscreteTimeIntegrator_DSTATE_i =
    bms_f4_P.DiscreteTimeIntegrator_IC_f;

  /* InitializeConditions for DiscreteIntegrator: '<S33>/Discrete-Time Integrator' */
  bms_f4_DW.DiscreteTimeIntegrator_DSTAT_ce =
    bms_f4_P.DiscreteTimeIntegrator_IC_ln;

  /* InitializeConditions for DiscreteIntegrator: '<S34>/Discrete-Time Integrator' */
  bms_f4_DW.DiscreteTimeIntegrator_DSTAT_p0 =
    bms_f4_P.DiscreteTimeIntegrator_IC_mf;

  /* InitializeConditions for DiscreteIntegrator: '<S35>/Discrete-Time Integrator' */
  bms_f4_DW.DiscreteTimeIntegrator_DSTAT_fb =
    bms_f4_P.DiscreteTimeIntegrator_IC_mz;

  /* InitializeConditions for DiscreteIntegrator: '<S36>/Discrete-Time Integrator' */
  bms_f4_DW.DiscreteTimeIntegrator_DSTAT_d3 =
    bms_f4_P.DiscreteTimeIntegrator_IC_m1;

  /* Chart: '<S3>/Chart' */
  bms_f4_DW.is_c1_bms_f4 = bms_f4_IN_init;

  /* SystemInitialize for Chart: '<S4>/Chart1' */
  bms_f4_Chart1_Init(&bms_f4_B.MatrixConcatenate[0],
                     &bms_f4_B.VectorConcatenate_k[0],
                     &bms_f4_B.VectorConcatenate1_a[0]);

  /* SystemInitialize for Chart: '<S4>/Chart2' */
  bms_f4_Chart1_Init(&bms_f4_B.MatrixConcatenate[10],
                     &bms_f4_B.VectorConcatenate_k[1],
                     &bms_f4_B.VectorConcatenate1_a[1]);

  /* SystemInitialize for Chart: '<S4>/Chart3' */
  bms_f4_Chart1_Init(&bms_f4_B.MatrixConcatenate[20],
                     &bms_f4_B.VectorConcatenate_k[2],
                     &bms_f4_B.VectorConcatenate1_a[2]);
}

/* Model terminate function */
void bms_f4_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
