/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: bms.c
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

#include "bms.h"
#include "bms_private.h"

/* Named constants for Chart: '<S4>/Chart1' */
#define bms_IN_Balancing               ((uint8_T)1U)
#define bms_IN_BalancingFinished       ((uint8_T)2U)
#define bms_IN_MeasureVoltages         ((uint8_T)3U)
#define bms_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)
#define bms_IN_OFF                     ((uint8_T)1U)
#define bms_IN_ON                      ((uint8_T)2U)
#define bms_IN_WaitRelaxation          ((uint8_T)4U)

/* Named constants for Chart: '<S3>/Chart' */
#define bms_IN_charging                ((uint8_T)1U)
#define bms_IN_dis_charger             ((uint8_T)2U)
#define bms_IN_dis_inverter            ((uint8_T)3U)
#define bms_IN_driving                 ((uint8_T)4U)
#define bms_IN_en_charger              ((uint8_T)5U)
#define bms_IN_en_charger_prechrg      ((uint8_T)6U)
#define bms_IN_en_inverter             ((uint8_T)7U)
#define bms_IN_en_inverter_prechrg     ((uint8_T)8U)
#define bms_IN_init                    ((uint8_T)9U)

/* Block signals (default storage) */
B_bms_T bms_B;

/* Block states (default storage) */
DW_bms_T bms_DW;

/* External inputs (root inport signals with default storage) */
ExtU_bms_T bms_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_bms_T bms_Y;

/* Real-time model */
static RT_MODEL_bms_T bms_M_;
RT_MODEL_bms_T *const bms_M = &bms_M_;
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
void bms_Chart1_Init(boolean_T rty_balancingCmd[10], real_T *rty_DeltaVCell,
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
void bms_Chart1(SystemState_t rtu_SystemState, const real_T
                rtu_SegmentVoltageVector[10], real_T rtu_CellMaxV, real_T
                rtu_CellMinV, boolean_T rty_balancingCmd[10], real_T
                *rty_DeltaVCell, boolean_T *rty_balancingFlag, DW_Chart1_bms_T
                *localDW)
{
  int32_T i;
  boolean_T exitg1;
  if (localDW->temporalCounter_i1 < MAX_uint32_T) {
    localDW->temporalCounter_i1++;
  }

  /* Chart: '<S4>/Chart1' */
  if (localDW->is_active_c2_bms == 0U) {
    localDW->is_active_c2_bms = 1U;
    localDW->is_c2_bms = bms_IN_OFF;
    for (i = 0; i < 10; i++) {
      rty_balancingCmd[i] = false;
    }

    *rty_balancingFlag = false;
    *rty_DeltaVCell = rtu_CellMaxV - rtu_CellMinV;
  } else if (localDW->is_c2_bms == bms_IN_OFF) {
    if ((rtu_SystemState == SystemState_t_Balancing) && (*rty_DeltaVCell > 0.001))
    {
      localDW->is_c2_bms = bms_IN_ON;
      *rty_balancingFlag = true;
      localDW->is_ON = bms_IN_Balancing;
      localDW->temporalCounter_i1 = 0U;
      for (i = 0; i < 10; i++) {
        rty_balancingCmd[i] = (rtu_SegmentVoltageVector[i] - rtu_CellMinV >
          0.001);
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
    localDW->is_ON = bms_IN_NO_ACTIVE_CHILD;
    localDW->is_c2_bms = bms_IN_OFF;
    for (i = 0; i < 10; i++) {
      rty_balancingCmd[i] = false;
    }

    *rty_balancingFlag = false;
    *rty_DeltaVCell = rtu_CellMaxV - rtu_CellMinV;
  } else {
    switch (localDW->is_ON) {
     case bms_IN_Balancing:
      if (localDW->flagBalancingDone) {
        localDW->is_ON = bms_IN_BalancingFinished;
        *rty_DeltaVCell = rtu_CellMaxV - rtu_CellMinV;
        *rty_balancingFlag = false;
      } else if ((!localDW->flagBalancingDone) && ((uint32_T)((int32_T)
                   localDW->temporalCounter_i1 * 10) >= 2000U)) {
        localDW->is_ON = bms_IN_WaitRelaxation;
        localDW->temporalCounter_i1 = 0U;
        for (i = 0; i < 10; i++) {
          rty_balancingCmd[i] = false;
        }
      }
      break;

     case bms_IN_BalancingFinished:
      if (*rty_DeltaVCell > 0.001) {
        localDW->is_ON = bms_IN_Balancing;
        localDW->temporalCounter_i1 = 0U;
        for (i = 0; i < 10; i++) {
          rty_balancingCmd[i] = (rtu_SegmentVoltageVector[i] - rtu_CellMinV >
            0.001);
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

     case bms_IN_MeasureVoltages:
      localDW->is_ON = bms_IN_Balancing;
      localDW->temporalCounter_i1 = 0U;
      for (i = 0; i < 10; i++) {
        rty_balancingCmd[i] = (rtu_SegmentVoltageVector[i] - rtu_CellMinV >
          0.001);
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
      if ((uint32_T)((int32_T)localDW->temporalCounter_i1 * 10) >= 1000U) {
        localDW->is_ON = bms_IN_MeasureVoltages;
        *rty_DeltaVCell = rtu_CellMaxV - rtu_CellMinV;
      }
      break;
    }
  }

  /* End of Chart: '<S4>/Chart1' */
}

/* Model step function */
void bms_step(void)
{
  real_T rtb_Selector[10];
  real_T rtb_Selector1[10];
  real_T rtb_Selector2[10];
  real_T maxV;
  real_T maxV_0;
  real_T maxV_1;
  real_T maxV_2;
  real_T maxV_3;
  real_T maxV_4;
  real_T minV;
  real_T minV_0;
  real_T minV_tmp;
  real_T minV_tmp_0;
  real_T minV_tmp_1;
  real_T rtb_Gain;
  real_T rtb_Max3;
  real_T rtb_Min3;
  real_T rtb_Min4;
  int32_T i;
  int32_T maxV_tmp;
  SystemState_t tmp;

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
  bms_Y.ToPlant.BusSOCEstimation.CDCEstimation[0] =
    bms_DW.DiscreteTimeIntegrator_DSTATE;
  bms_Y.ToPlant.BusSOCEstimation.CDCEstimation[3] =
    bms_DW.DiscreteTimeIntegrator_DSTATE_a;
  bms_Y.ToPlant.BusSOCEstimation.CDCEstimation[6] =
    bms_DW.DiscreteTimeIntegrator_DSTAT_au;
  bms_Y.ToPlant.BusSOCEstimation.CDCEstimation[9] =
    bms_DW.DiscreteTimeIntegrator_DSTATE_m;
  bms_Y.ToPlant.BusSOCEstimation.CDCEstimation[12] =
    bms_DW.DiscreteTimeIntegrator_DSTATE_b;
  bms_Y.ToPlant.BusSOCEstimation.CDCEstimation[15] =
    bms_DW.DiscreteTimeIntegrator_DSTATE_p;
  bms_Y.ToPlant.BusSOCEstimation.CDCEstimation[18] =
    bms_DW.DiscreteTimeIntegrator_DSTATE_c;
  bms_Y.ToPlant.BusSOCEstimation.CDCEstimation[21] =
    bms_DW.DiscreteTimeIntegrator_DSTAT_mh;
  bms_Y.ToPlant.BusSOCEstimation.CDCEstimation[24] =
    bms_DW.DiscreteTimeIntegrator_DSTATE_g;
  bms_Y.ToPlant.BusSOCEstimation.CDCEstimation[27] =
    bms_DW.DiscreteTimeIntegrator_DSTAT_g0;
  bms_Y.ToPlant.BusSOCEstimation.CDCEstimation[1] =
    bms_DW.DiscreteTimeIntegrator_DSTATE_d;
  bms_Y.ToPlant.BusSOCEstimation.CDCEstimation[4] =
    bms_DW.DiscreteTimeIntegrator_DSTAT_b0;
  bms_Y.ToPlant.BusSOCEstimation.CDCEstimation[7] =
    bms_DW.DiscreteTimeIntegrator_DSTAT_dc;
  bms_Y.ToPlant.BusSOCEstimation.CDCEstimation[10] =
    bms_DW.DiscreteTimeIntegrator_DSTATE_o;
  bms_Y.ToPlant.BusSOCEstimation.CDCEstimation[13] =
    bms_DW.DiscreteTimeIntegrator_DSTAT_aw;
  bms_Y.ToPlant.BusSOCEstimation.CDCEstimation[16] =
    bms_DW.DiscreteTimeIntegrator_DSTATE_n;
  bms_Y.ToPlant.BusSOCEstimation.CDCEstimation[19] =
    bms_DW.DiscreteTimeIntegrator_DSTATE_e;
  bms_Y.ToPlant.BusSOCEstimation.CDCEstimation[22] =
    bms_DW.DiscreteTimeIntegrator_DSTATE_f;
  bms_Y.ToPlant.BusSOCEstimation.CDCEstimation[25] =
    bms_DW.DiscreteTimeIntegrator_DSTAT_aj;
  bms_Y.ToPlant.BusSOCEstimation.CDCEstimation[28] =
    bms_DW.DiscreteTimeIntegrator_DSTAT_bc;
  bms_Y.ToPlant.BusSOCEstimation.CDCEstimation[2] =
    bms_DW.DiscreteTimeIntegrator_DSTAT_ps;
  bms_Y.ToPlant.BusSOCEstimation.CDCEstimation[5] =
    bms_DW.DiscreteTimeIntegrator_DSTAT_ed;
  bms_Y.ToPlant.BusSOCEstimation.CDCEstimation[8] =
    bms_DW.DiscreteTimeIntegrator_DSTAT_mg;
  bms_Y.ToPlant.BusSOCEstimation.CDCEstimation[11] =
    bms_DW.DiscreteTimeIntegrator_DSTAT_fy;
  bms_Y.ToPlant.BusSOCEstimation.CDCEstimation[14] =
    bms_DW.DiscreteTimeIntegrator_DSTAT_gd;
  bms_Y.ToPlant.BusSOCEstimation.CDCEstimation[17] =
    bms_DW.DiscreteTimeIntegrator_DSTATE_i;
  bms_Y.ToPlant.BusSOCEstimation.CDCEstimation[20] =
    bms_DW.DiscreteTimeIntegrator_DSTAT_ce;
  bms_Y.ToPlant.BusSOCEstimation.CDCEstimation[23] =
    bms_DW.DiscreteTimeIntegrator_DSTAT_p0;
  bms_Y.ToPlant.BusSOCEstimation.CDCEstimation[26] =
    bms_DW.DiscreteTimeIntegrator_DSTAT_fb;
  bms_Y.ToPlant.BusSOCEstimation.CDCEstimation[29] =
    bms_DW.DiscreteTimeIntegrator_DSTAT_d3;

  /* Selector: '<S4>/Selector' incorporates:
   *  Inport: '<Root>/FromPlant'
   */
  for (i = 0; i < 10; i++) {
    rtb_Selector[i] = bms_U.FromPlant.BMSBatteryPackData.SegmentVoltageVector[3 *
      i];
  }

  /* MinMax: '<S4>/Max' incorporates:
   *  Inport: '<Root>/FromPlant'
   *  Selector: '<S4>/Selector'
   */
  rtb_Gain = bms_U.FromPlant.BMSBatteryPackData.SegmentVoltageVector[0];
  for (i = 0; i < 9; i++) {
    rtb_Gain = fmax(rtb_Gain,
                    bms_U.FromPlant.BMSBatteryPackData.SegmentVoltageVector[(i +
      1) * 3]);
  }

  /* Selector: '<S4>/Selector1' incorporates:
   *  Inport: '<Root>/FromPlant'
   */
  for (i = 0; i < 10; i++) {
    rtb_Selector1[i] = bms_U.FromPlant.BMSBatteryPackData.SegmentVoltageVector[3
      * i + 1];
  }

  /* MinMax: '<S4>/Max1' incorporates:
   *  Inport: '<Root>/FromPlant'
   *  Selector: '<S4>/Selector1'
   */
  maxV = bms_U.FromPlant.BMSBatteryPackData.SegmentVoltageVector[1];
  for (i = 0; i < 9; i++) {
    maxV = fmax(maxV, bms_U.FromPlant.BMSBatteryPackData.SegmentVoltageVector[(i
      + 1) * 3 + 1]);
  }

  /* Selector: '<S4>/Selector2' incorporates:
   *  Inport: '<Root>/FromPlant'
   */
  for (i = 0; i < 10; i++) {
    rtb_Selector2[i] = bms_U.FromPlant.BMSBatteryPackData.SegmentVoltageVector[3
      * i + 2];
  }

  /* MinMax: '<S4>/Max2' incorporates:
   *  Inport: '<Root>/FromPlant'
   *  Selector: '<S4>/Selector2'
   */
  maxV_0 = bms_U.FromPlant.BMSBatteryPackData.SegmentVoltageVector[2];

  /* MinMax: '<S4>/Min' incorporates:
   *  Inport: '<Root>/FromPlant'
   *  Selector: '<S4>/Selector'
   */
  rtb_Max3 = bms_U.FromPlant.BMSBatteryPackData.SegmentVoltageVector[0];

  /* MinMax: '<S4>/Min1' incorporates:
   *  Inport: '<Root>/FromPlant'
   *  Selector: '<S4>/Selector1'
   */
  minV = bms_U.FromPlant.BMSBatteryPackData.SegmentVoltageVector[1];

  /* MinMax: '<S4>/Min2' incorporates:
   *  Inport: '<Root>/FromPlant'
   *  Selector: '<S4>/Selector2'
   */
  minV_0 = bms_U.FromPlant.BMSBatteryPackData.SegmentVoltageVector[2];
  for (i = 0; i < 9; i++) {
    /* MinMax: '<S4>/Max2' incorporates:
     *  Inport: '<Root>/FromPlant'
     *  MinMax: '<S4>/Min'
     *  MinMax: '<S4>/Min1'
     *  MinMax: '<S4>/Min2'
     *  Selector: '<S4>/Selector'
     *  Selector: '<S4>/Selector1'
     *  Selector: '<S4>/Selector2'
     */
    maxV_tmp = (i + 1) * 3;
    rtb_Min3 = bms_U.FromPlant.BMSBatteryPackData.SegmentVoltageVector[maxV_tmp
      + 2];
    maxV_0 = fmax(maxV_0, rtb_Min3);

    /* MinMax: '<S4>/Min' incorporates:
     *  Inport: '<Root>/FromPlant'
     *  Selector: '<S4>/Selector'
     */
    rtb_Max3 = fmin(rtb_Max3,
                    bms_U.FromPlant.BMSBatteryPackData.SegmentVoltageVector[maxV_tmp]);

    /* MinMax: '<S4>/Min1' incorporates:
     *  Inport: '<Root>/FromPlant'
     *  Selector: '<S4>/Selector1'
     */
    minV = fmin(minV,
                bms_U.FromPlant.BMSBatteryPackData.SegmentVoltageVector[maxV_tmp
                + 1]);

    /* MinMax: '<S4>/Min2' */
    minV_0 = fmin(minV_0, rtb_Min3);
  }

  /* MinMax: '<S4>/Min3' incorporates:
   *  MinMax: '<S4>/Max'
   *  MinMax: '<S4>/Max1'
   *  MinMax: '<S4>/Max2'
   */
  rtb_Min3 = fmax(fmax(rtb_Gain, maxV), maxV_0);

  /* MinMax: '<S4>/Min4' incorporates:
   *  MinMax: '<S4>/Min'
   *  MinMax: '<S4>/Min1'
   *  MinMax: '<S4>/Min2'
   */
  rtb_Min4 = fmin(fmin(rtb_Max3, minV), minV_0);

  /* Chart: '<S3>/Chart' incorporates:
   *  Inport: '<Root>/FromPlant'
   *  Inport: '<Root>/InputSimulationBus'
   */
  switch (bms_DW.is_c1_bms) {
   case bms_IN_charging:
    bms_B.VectorConcatenate[0] = 0.0;
    bms_B.VectorConcatenate3[0] = 1.0;
    break;

   case bms_IN_dis_charger:
    bms_B.VectorConcatenate1[0] = 0.0;
    bms_B.VectorConcatenate2[0] = 1.0;
    bms_B.VectorConcatenate3[0] = 0.0;
    break;

   case bms_IN_dis_inverter:
    bms_B.VectorConcatenate1[1] = 0.0;
    bms_B.VectorConcatenate2[1] = 1.0;
    bms_B.VectorConcatenate3[1] = 0.0;
    break;

   case bms_IN_driving:
    bms_B.VectorConcatenate[1] = 0.0;
    bms_B.VectorConcatenate3[1] = 1.0;
    break;

   case bms_IN_en_charger:
    bms_B.VectorConcatenate1[0] = 1.0;
    break;

   case bms_IN_en_charger_prechrg:
    bms_B.VectorConcatenate[0] = 1.0;
    bms_B.VectorConcatenate1[2] = 1.0;
    break;

   case bms_IN_en_inverter:
    bms_B.VectorConcatenate1[1] = 1.0;
    break;

   case bms_IN_en_inverter_prechrg:
    bms_B.VectorConcatenate[1] = 1.0;
    bms_B.VectorConcatenate1[2] = 1.0;
    break;

   default:
    /* case IN_init: */
    bms_B.VectorConcatenate1[2] = 0.0;
    bms_B.VectorConcatenate[0] = 0.0;
    bms_B.VectorConcatenate[1] = 0.0;
    bms_B.VectorConcatenate1[0] = 0.0;
    bms_B.VectorConcatenate1[1] = 0.0;
    bms_B.VectorConcatenate2[0] = 0.0;
    bms_B.VectorConcatenate2[1] = 0.0;
    bms_B.VectorConcatenate3[0] = 0.0;
    bms_B.VectorConcatenate3[1] = 0.0;
    break;
  }

  if (bms_DW.isNotInit && (bms_DW.temporalCounter_i1 < MAX_uint32_T)) {
    bms_DW.temporalCounter_i1++;
  }

  bms_DW.isNotInit = true;
  switch (bms_DW.is_c1_bms) {
   case bms_IN_charging:
    tmp = bms_U.InputSimulationBus.SimulationSystemInput.SystemState;
    if (tmp != SystemState_t_Charging) {
      bms_DW.is_c1_bms = bms_IN_dis_charger;
    } else if (tmp == SystemState_t_Charging) {
      bms_DW.is_c1_bms = bms_IN_charging;
    }
    break;

   case bms_IN_dis_charger:
    if (bms_U.FromPlant.BMSContactorModuleData.VCharger < 0.2 *
        bms_U.FromPlant.BMSContactorModuleData.VBatt) {
      bms_DW.is_c1_bms = bms_IN_init;
    }
    break;

   case bms_IN_dis_inverter:
    if (bms_U.FromPlant.BMSContactorModuleData.VInverter < 0.2 *
        bms_U.FromPlant.BMSContactorModuleData.VBatt) {
      bms_DW.is_c1_bms = bms_IN_init;
    }
    break;

   case bms_IN_driving:
    tmp = bms_U.InputSimulationBus.SimulationSystemInput.SystemState;
    if (tmp != SystemState_t_Driving) {
      bms_DW.is_c1_bms = bms_IN_dis_inverter;
    } else if (tmp == SystemState_t_Driving) {
      bms_DW.is_c1_bms = bms_IN_driving;
    }
    break;

   case bms_IN_en_charger:
    if (bms_DW.temporalCounter_i1 >= 10U) {
      bms_DW.is_c1_bms = bms_IN_charging;
    }
    break;

   case bms_IN_en_charger_prechrg:
    maxV_4 = 0.8 * bms_U.FromPlant.BMSContactorModuleData.VBatt;
    if (bms_U.FromPlant.BMSContactorModuleData.VCharger >= maxV_4) {
      bms_DW.is_c1_bms = bms_IN_en_charger;
      bms_DW.temporalCounter_i1 = 0U;
    } else if (bms_U.FromPlant.BMSContactorModuleData.VCharger < maxV_4) {
      bms_DW.is_c1_bms = bms_IN_en_charger_prechrg;
    } else if (bms_U.InputSimulationBus.SimulationSystemInput.SystemState !=
               SystemState_t_Driving) {
      bms_DW.is_c1_bms = bms_IN_init;
    }
    break;

   case bms_IN_en_inverter:
    if (bms_DW.temporalCounter_i1 >= 10U) {
      bms_DW.is_c1_bms = bms_IN_driving;
    }
    break;

   case bms_IN_en_inverter_prechrg:
    maxV_4 = 0.8 * bms_U.FromPlant.BMSContactorModuleData.VBatt;
    if (bms_U.FromPlant.BMSContactorModuleData.VInverter >= maxV_4) {
      bms_DW.is_c1_bms = bms_IN_en_inverter;
      bms_DW.temporalCounter_i1 = 0U;
    } else if (bms_U.FromPlant.BMSContactorModuleData.VInverter < maxV_4) {
      bms_DW.is_c1_bms = bms_IN_en_inverter_prechrg;
    } else if (bms_U.InputSimulationBus.SimulationSystemInput.SystemState !=
               SystemState_t_Driving) {
      bms_DW.is_c1_bms = bms_IN_init;
    }
    break;

   default:
    /* case IN_init: */
    tmp = bms_U.InputSimulationBus.SimulationSystemInput.SystemState;
    if ((bms_U.FromPlant.BMSContactorModuleData.VBatt > 1.0) && (tmp ==
         SystemState_t_Charging)) {
      bms_DW.is_c1_bms = bms_IN_en_charger_prechrg;
    } else if ((bms_U.FromPlant.BMSContactorModuleData.VBatt > 1.0) && (tmp ==
                SystemState_t_Driving)) {
      bms_DW.is_c1_bms = bms_IN_en_inverter_prechrg;
    }
    break;
  }

  /* End of Chart: '<S3>/Chart' */

  /* Chart: '<S4>/Chart1' incorporates:
   *  Inport: '<Root>/InputSimulationBus'
   */
  bms_Chart1(bms_U.InputSimulationBus.SimulationSystemInput.SystemState,
             rtb_Selector, rtb_Min3, rtb_Min4, &bms_B.MatrixConcatenate[0],
             &bms_B.VectorConcatenate_k[0], &bms_B.VectorConcatenate1_a[0],
             &bms_DW.sf_Chart1);

  /* Chart: '<S4>/Chart2' incorporates:
   *  Inport: '<Root>/InputSimulationBus'
   */
  bms_Chart1(bms_U.InputSimulationBus.SimulationSystemInput.SystemState,
             rtb_Selector1, rtb_Min3, rtb_Min4, &bms_B.MatrixConcatenate[10],
             &bms_B.VectorConcatenate_k[1], &bms_B.VectorConcatenate1_a[1],
             &bms_DW.sf_Chart2);

  /* Chart: '<S4>/Chart3' incorporates:
   *  Inport: '<Root>/InputSimulationBus'
   */
  bms_Chart1(bms_U.InputSimulationBus.SimulationSystemInput.SystemState,
             rtb_Selector2, rtb_Min3, rtb_Min4, &bms_B.MatrixConcatenate[20],
             &bms_B.VectorConcatenate_k[2], &bms_B.VectorConcatenate1_a[2],
             &bms_DW.sf_Chart3);

  /* Math: '<S4>/Transpose' incorporates:
   *  Concatenate: '<S4>/Matrix Concatenate'
   */
  for (i = 0; i < 10; i++) {
    bms_Y.ToPlant.BMSBatteryPackInput.BalCmdVector[3 * i] =
      bms_B.MatrixConcatenate[i];
    bms_Y.ToPlant.BMSBatteryPackInput.BalCmdVector[3 * i + 1] =
      bms_B.MatrixConcatenate[i + 10];
    bms_Y.ToPlant.BMSBatteryPackInput.BalCmdVector[3 * i + 2] =
      bms_B.MatrixConcatenate[i + 20];
  }

  /* End of Math: '<S4>/Transpose' */

  /* MinMax: '<S2>/Max15' incorporates:
   *  Inport: '<Root>/FromPlant'
   *  Selector: '<S2>/Selector12'
   */
  rtb_Max3 = bms_U.FromPlant.BMSBatteryPackData.SegmentVoltageVector[2];

  /* MinMax: '<S2>/Max13' incorporates:
   *  Inport: '<Root>/FromPlant'
   *  Selector: '<S2>/Selector10'
   */
  minV = bms_U.FromPlant.BMSBatteryPackData.SegmentVoltageVector[0];

  /* MinMax: '<S2>/Max14' incorporates:
   *  Inport: '<Root>/FromPlant'
   *  Selector: '<S2>/Selector11'
   */
  minV_0 = bms_U.FromPlant.BMSBatteryPackData.SegmentVoltageVector[1];

  /* MinMax: '<S2>/Max4' incorporates:
   *  Inport: '<Root>/FromPlant'
   *  Selector: '<S2>/Selector1'
   */
  rtb_Gain = bms_U.FromPlant.BMSBatteryPackData.SegmentCurrentVector[0];

  /* MinMax: '<S2>/Max5' incorporates:
   *  Inport: '<Root>/FromPlant'
   *  Selector: '<S2>/Selector2'
   */
  maxV = bms_U.FromPlant.BMSBatteryPackData.SegmentCurrentVector[1];

  /* MinMax: '<S2>/Max6' incorporates:
   *  Inport: '<Root>/FromPlant'
   *  Selector: '<S2>/Selector3'
   */
  maxV_0 = bms_U.FromPlant.BMSBatteryPackData.SegmentCurrentVector[2];

  /* MinMax: '<S2>/Max7' incorporates:
   *  Inport: '<Root>/FromPlant'
   *  Selector: '<S2>/Selector4'
   */
  maxV_1 = bms_U.FromPlant.BMSBatteryPackData.SegmentTempVector[0];

  /* MinMax: '<S2>/Max8' incorporates:
   *  Inport: '<Root>/FromPlant'
   *  Selector: '<S2>/Selector5'
   */
  maxV_2 = bms_U.FromPlant.BMSBatteryPackData.SegmentTempVector[1];

  /* MinMax: '<S2>/Max9' incorporates:
   *  Inport: '<Root>/FromPlant'
   *  Selector: '<S2>/Selector6'
   */
  maxV_3 = bms_U.FromPlant.BMSBatteryPackData.SegmentTempVector[2];

  /* MinMax: '<S2>/Max10' incorporates:
   *  Inport: '<Root>/FromPlant'
   *  Selector: '<S2>/Selector7'
   */
  rtb_Min3 = bms_U.FromPlant.BMSBatteryPackData.SegmentVoltageVector[0];

  /* MinMax: '<S2>/Max11' incorporates:
   *  Inport: '<Root>/FromPlant'
   *  Selector: '<S2>/Selector8'
   */
  rtb_Min4 = bms_U.FromPlant.BMSBatteryPackData.SegmentVoltageVector[1];

  /* MinMax: '<S2>/Max12' incorporates:
   *  Inport: '<Root>/FromPlant'
   *  Selector: '<S2>/Selector9'
   */
  maxV_4 = bms_U.FromPlant.BMSBatteryPackData.SegmentVoltageVector[2];
  for (i = 0; i < 9; i++) {
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
    maxV_tmp = (i + 1) * 3;
    minV_tmp_1 =
      bms_U.FromPlant.BMSBatteryPackData.SegmentVoltageVector[maxV_tmp + 2];
    rtb_Max3 = fmin(rtb_Max3, minV_tmp_1);

    /* MinMax: '<S2>/Max13' incorporates:
     *  Inport: '<Root>/FromPlant'
     *  MinMax: '<S2>/Max10'
     *  Selector: '<S2>/Selector10'
     *  Selector: '<S2>/Selector7'
     */
    minV_tmp = bms_U.FromPlant.BMSBatteryPackData.SegmentVoltageVector[maxV_tmp];
    minV = fmin(minV, minV_tmp);

    /* MinMax: '<S2>/Max14' incorporates:
     *  Inport: '<Root>/FromPlant'
     *  MinMax: '<S2>/Max11'
     *  Selector: '<S2>/Selector11'
     *  Selector: '<S2>/Selector8'
     */
    minV_tmp_0 =
      bms_U.FromPlant.BMSBatteryPackData.SegmentVoltageVector[maxV_tmp + 1];
    minV_0 = fmin(minV_0, minV_tmp_0);

    /* MinMax: '<S2>/Max4' incorporates:
     *  Inport: '<Root>/FromPlant'
     *  Selector: '<S2>/Selector1'
     */
    rtb_Gain = fmax(rtb_Gain,
                    bms_U.FromPlant.BMSBatteryPackData.SegmentCurrentVector[maxV_tmp]);

    /* MinMax: '<S2>/Max5' incorporates:
     *  Inport: '<Root>/FromPlant'
     *  MinMax: '<S2>/Max14'
     *  Selector: '<S2>/Selector11'
     *  Selector: '<S2>/Selector2'
     */
    maxV = fmax(maxV,
                bms_U.FromPlant.BMSBatteryPackData.SegmentCurrentVector[maxV_tmp
                + 1]);

    /* MinMax: '<S2>/Max6' incorporates:
     *  Inport: '<Root>/FromPlant'
     *  MinMax: '<S2>/Max15'
     *  Selector: '<S2>/Selector12'
     *  Selector: '<S2>/Selector3'
     */
    maxV_0 = fmax(maxV_0,
                  bms_U.FromPlant.BMSBatteryPackData.SegmentCurrentVector[maxV_tmp
                  + 2]);

    /* MinMax: '<S2>/Max7' incorporates:
     *  Inport: '<Root>/FromPlant'
     *  Selector: '<S2>/Selector4'
     */
    maxV_1 = fmax(maxV_1,
                  bms_U.FromPlant.BMSBatteryPackData.SegmentTempVector[maxV_tmp]);

    /* MinMax: '<S2>/Max8' incorporates:
     *  Inport: '<Root>/FromPlant'
     *  MinMax: '<S2>/Max14'
     *  Selector: '<S2>/Selector11'
     *  Selector: '<S2>/Selector5'
     */
    maxV_2 = fmax(maxV_2,
                  bms_U.FromPlant.BMSBatteryPackData.SegmentTempVector[maxV_tmp
                  + 1]);

    /* MinMax: '<S2>/Max9' incorporates:
     *  Inport: '<Root>/FromPlant'
     *  MinMax: '<S2>/Max15'
     *  Selector: '<S2>/Selector12'
     *  Selector: '<S2>/Selector6'
     */
    maxV_3 = fmax(maxV_3,
                  bms_U.FromPlant.BMSBatteryPackData.SegmentTempVector[maxV_tmp
                  + 2]);

    /* MinMax: '<S2>/Max10' */
    rtb_Min3 = fmax(rtb_Min3, minV_tmp);

    /* MinMax: '<S2>/Max11' */
    rtb_Min4 = fmax(rtb_Min4, minV_tmp_0);

    /* MinMax: '<S2>/Max12' */
    maxV_4 = fmax(maxV_4, minV_tmp_1);
  }

  /* MinMax: '<S2>/Max3' incorporates:
   *  MinMax: '<S2>/Max13'
   *  MinMax: '<S2>/Max14'
   *  MinMax: '<S2>/Max15'
   */
  rtb_Max3 = fmin(fmin(minV, minV_0), rtb_Max3);

  /* RelationalOperator: '<S44>/Compare' incorporates:
   *  Constant: '<S44>/Constant'
   */
  bms_Y.ToPlant.BMSFaultOutput.UnderVoltageWarning = (rtb_Max3 <= 2.7);

  /* MinMax: '<S2>/Max' incorporates:
   *  MinMax: '<S2>/Max4'
   *  MinMax: '<S2>/Max5'
   *  MinMax: '<S2>/Max6'
   */
  rtb_Gain = fmax(fmax(rtb_Gain, maxV), maxV_0);

  /* RelationalOperator: '<S38>/Compare' incorporates:
   *  Constant: '<S38>/Constant'
   */
  bms_Y.ToPlant.BMSFaultOutput.OverCurrentWarning = (rtb_Gain >= 20.0);

  /* RelationalOperator: '<S39>/Compare' incorporates:
   *  Constant: '<S39>/Constant'
   */
  bms_Y.ToPlant.BMSFaultOutput.OverCurrentFault = (rtb_Gain >= 50.0);

  /* MinMax: '<S2>/Max1' incorporates:
   *  MinMax: '<S2>/Max7'
   *  MinMax: '<S2>/Max8'
   *  MinMax: '<S2>/Max9'
   */
  rtb_Gain = fmax(fmax(maxV_1, maxV_2), maxV_3);

  /* RelationalOperator: '<S40>/Compare' incorporates:
   *  Constant: '<S40>/Constant'
   */
  bms_Y.ToPlant.BMSFaultOutput.OverTemperatureWarning = (rtb_Gain >= 323.15);

  /* RelationalOperator: '<S41>/Compare' incorporates:
   *  Constant: '<S41>/Constant'
   */
  bms_Y.ToPlant.BMSFaultOutput.OverTemperatureFault = (rtb_Gain >= 338.15);

  /* MinMax: '<S2>/Max2' incorporates:
   *  MinMax: '<S2>/Max10'
   *  MinMax: '<S2>/Max11'
   *  MinMax: '<S2>/Max12'
   */
  rtb_Gain = fmax(fmax(rtb_Min3, rtb_Min4), maxV_4);

  /* RelationalOperator: '<S42>/Compare' incorporates:
   *  Constant: '<S42>/Constant'
   */
  bms_Y.ToPlant.BMSFaultOutput.OverVoltageWarning = (rtb_Gain >= 4.21);

  /* RelationalOperator: '<S43>/Compare' incorporates:
   *  Constant: '<S43>/Constant'
   */
  bms_Y.ToPlant.BMSFaultOutput.OverVoltageFault = (rtb_Gain >= 4.25);

  /* RelationalOperator: '<S45>/Compare' incorporates:
   *  Constant: '<S45>/Constant'
   */
  bms_Y.ToPlant.BMSFaultOutput.UnderVoltageFault = (rtb_Max3 <= 2.65);

  /* BusCreator generated from: '<Root>/ToPlant' */
  bms_Y.ToPlant.BMSContactorModuleCmd.ContactorCmd[0] =
    bms_B.VectorConcatenate1[0];
  bms_Y.ToPlant.BMSContactorModuleCmd.ContactorCmd[1] =
    bms_B.VectorConcatenate1[1];
  bms_Y.ToPlant.BMSContactorModuleCmd.ContactorCmd[2] =
    bms_B.VectorConcatenate1[2];
  bms_Y.ToPlant.BMSContactorModuleCmd.PreChrgCmd[0] = bms_B.VectorConcatenate[0];
  bms_Y.ToPlant.BMSContactorModuleCmd.DisChrgCmd[0] = bms_B.VectorConcatenate2[0];
  bms_Y.ToPlant.BMSContactorModuleCmd.DrivetrainEn[0] =
    bms_B.VectorConcatenate3[0];
  bms_Y.ToPlant.BMSContactorModuleCmd.PreChrgCmd[1] = bms_B.VectorConcatenate[1];
  bms_Y.ToPlant.BMSContactorModuleCmd.DisChrgCmd[1] = bms_B.VectorConcatenate2[1];
  bms_Y.ToPlant.BMSContactorModuleCmd.DrivetrainEn[1] =
    bms_B.VectorConcatenate3[1];

  /* BusCreator generated from: '<Root>/ToPlant' */
  bms_Y.ToPlant.BMSBatteryPackInput.balancingDeltaVCell[0] =
    bms_B.VectorConcatenate_k[0];
  bms_Y.ToPlant.BMSBatteryPackInput.balancingFlags[0] =
    bms_B.VectorConcatenate1_a[0];
  bms_Y.ToPlant.BMSBatteryPackInput.balancingDeltaVCell[1] =
    bms_B.VectorConcatenate_k[1];
  bms_Y.ToPlant.BMSBatteryPackInput.balancingFlags[1] =
    bms_B.VectorConcatenate1_a[1];
  bms_Y.ToPlant.BMSBatteryPackInput.balancingDeltaVCell[2] =
    bms_B.VectorConcatenate_k[2];
  bms_Y.ToPlant.BMSBatteryPackInput.balancingFlags[2] =
    bms_B.VectorConcatenate1_a[2];

  /* BusCreator generated from: '<Root>/ToPlant' incorporates:
   *  Concatenate: '<S1>/Matrix Concatenate'
   */
  memcpy(&bms_Y.ToPlant.BusSOCEstimation.EKFEstimation[0],
         &bms_ConstB.EKFEstimation[0], 30U * sizeof(real_T));

  /* Update for DiscreteIntegrator: '<S17>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S17>/Gain'
   *  Inport: '<Root>/FromPlant'
   *  Lookup_n-D: '<S17>/n-D Lookup Table'
   *  Product: '<S17>/Divide'
   *  Selector: '<S1>/Selector1'
   *  Selector: '<S1>/Selector2'
   */
  bms_DW.DiscreteTimeIntegrator_DSTATE += -0.00027777778450399637 *
    bms_U.FromPlant.BMSBatteryPackData.SegmentCurrentVector[0] / look1_binlxpw
    (bms_U.FromPlant.BMSBatteryPackData.SegmentTempVector[0], bms_ConstP.pooled8,
     bms_ConstP.pooled7, 2U) * 0.01;
  if (bms_DW.DiscreteTimeIntegrator_DSTATE >= 1.0) {
    bms_DW.DiscreteTimeIntegrator_DSTATE = 1.0;
  } else if (bms_DW.DiscreteTimeIntegrator_DSTATE <= 0.0) {
    bms_DW.DiscreteTimeIntegrator_DSTATE = 0.0;
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
  bms_DW.DiscreteTimeIntegrator_DSTATE_a += -0.00027777778450399637 *
    bms_U.FromPlant.BMSBatteryPackData.SegmentCurrentVector[3] / look1_binlxpw
    (bms_U.FromPlant.BMSBatteryPackData.SegmentTempVector[3], bms_ConstP.pooled8,
     bms_ConstP.pooled7, 2U) * 0.01;
  if (bms_DW.DiscreteTimeIntegrator_DSTATE_a >= 1.0) {
    bms_DW.DiscreteTimeIntegrator_DSTATE_a = 1.0;
  } else if (bms_DW.DiscreteTimeIntegrator_DSTATE_a <= 0.0) {
    bms_DW.DiscreteTimeIntegrator_DSTATE_a = 0.0;
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
  bms_DW.DiscreteTimeIntegrator_DSTAT_au += -0.00027777778450399637 *
    bms_U.FromPlant.BMSBatteryPackData.SegmentCurrentVector[6] / look1_binlxpw
    (bms_U.FromPlant.BMSBatteryPackData.SegmentTempVector[6], bms_ConstP.pooled8,
     bms_ConstP.pooled7, 2U) * 0.01;
  if (bms_DW.DiscreteTimeIntegrator_DSTAT_au >= 1.0) {
    bms_DW.DiscreteTimeIntegrator_DSTAT_au = 1.0;
  } else if (bms_DW.DiscreteTimeIntegrator_DSTAT_au <= 0.0) {
    bms_DW.DiscreteTimeIntegrator_DSTAT_au = 0.0;
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
  bms_DW.DiscreteTimeIntegrator_DSTATE_m += -0.00027777778450399637 *
    bms_U.FromPlant.BMSBatteryPackData.SegmentCurrentVector[9] / look1_binlxpw
    (bms_U.FromPlant.BMSBatteryPackData.SegmentTempVector[9], bms_ConstP.pooled8,
     bms_ConstP.pooled7, 2U) * 0.01;
  if (bms_DW.DiscreteTimeIntegrator_DSTATE_m >= 1.0) {
    bms_DW.DiscreteTimeIntegrator_DSTATE_m = 1.0;
  } else if (bms_DW.DiscreteTimeIntegrator_DSTATE_m <= 0.0) {
    bms_DW.DiscreteTimeIntegrator_DSTATE_m = 0.0;
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
  bms_DW.DiscreteTimeIntegrator_DSTATE_b += -0.00027777778450399637 *
    bms_U.FromPlant.BMSBatteryPackData.SegmentCurrentVector[12] / look1_binlxpw
    (bms_U.FromPlant.BMSBatteryPackData.SegmentTempVector[12],
     bms_ConstP.pooled8, bms_ConstP.pooled7, 2U) * 0.01;
  if (bms_DW.DiscreteTimeIntegrator_DSTATE_b >= 1.0) {
    bms_DW.DiscreteTimeIntegrator_DSTATE_b = 1.0;
  } else if (bms_DW.DiscreteTimeIntegrator_DSTATE_b <= 0.0) {
    bms_DW.DiscreteTimeIntegrator_DSTATE_b = 0.0;
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
  bms_DW.DiscreteTimeIntegrator_DSTATE_p += -0.00027777778450399637 *
    bms_U.FromPlant.BMSBatteryPackData.SegmentCurrentVector[15] / look1_binlxpw
    (bms_U.FromPlant.BMSBatteryPackData.SegmentTempVector[15],
     bms_ConstP.pooled8, bms_ConstP.pooled7, 2U) * 0.01;
  if (bms_DW.DiscreteTimeIntegrator_DSTATE_p >= 1.0) {
    bms_DW.DiscreteTimeIntegrator_DSTATE_p = 1.0;
  } else if (bms_DW.DiscreteTimeIntegrator_DSTATE_p <= 0.0) {
    bms_DW.DiscreteTimeIntegrator_DSTATE_p = 0.0;
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
  bms_DW.DiscreteTimeIntegrator_DSTATE_c += -0.00027777778450399637 *
    bms_U.FromPlant.BMSBatteryPackData.SegmentCurrentVector[18] / look1_binlxpw
    (bms_U.FromPlant.BMSBatteryPackData.SegmentTempVector[18],
     bms_ConstP.pooled8, bms_ConstP.pooled7, 2U) * 0.01;
  if (bms_DW.DiscreteTimeIntegrator_DSTATE_c >= 1.0) {
    bms_DW.DiscreteTimeIntegrator_DSTATE_c = 1.0;
  } else if (bms_DW.DiscreteTimeIntegrator_DSTATE_c <= 0.0) {
    bms_DW.DiscreteTimeIntegrator_DSTATE_c = 0.0;
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
  bms_DW.DiscreteTimeIntegrator_DSTAT_mh += -0.00027777778450399637 *
    bms_U.FromPlant.BMSBatteryPackData.SegmentCurrentVector[21] / look1_binlxpw
    (bms_U.FromPlant.BMSBatteryPackData.SegmentTempVector[21],
     bms_ConstP.pooled8, bms_ConstP.pooled7, 2U) * 0.01;
  if (bms_DW.DiscreteTimeIntegrator_DSTAT_mh >= 1.0) {
    bms_DW.DiscreteTimeIntegrator_DSTAT_mh = 1.0;
  } else if (bms_DW.DiscreteTimeIntegrator_DSTAT_mh <= 0.0) {
    bms_DW.DiscreteTimeIntegrator_DSTAT_mh = 0.0;
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
  bms_DW.DiscreteTimeIntegrator_DSTATE_g += -0.00027777778450399637 *
    bms_U.FromPlant.BMSBatteryPackData.SegmentCurrentVector[24] / look1_binlxpw
    (bms_U.FromPlant.BMSBatteryPackData.SegmentTempVector[24],
     bms_ConstP.pooled8, bms_ConstP.pooled7, 2U) * 0.01;
  if (bms_DW.DiscreteTimeIntegrator_DSTATE_g >= 1.0) {
    bms_DW.DiscreteTimeIntegrator_DSTATE_g = 1.0;
  } else if (bms_DW.DiscreteTimeIntegrator_DSTATE_g <= 0.0) {
    bms_DW.DiscreteTimeIntegrator_DSTATE_g = 0.0;
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
  bms_DW.DiscreteTimeIntegrator_DSTAT_g0 += -0.00027777778450399637 *
    bms_U.FromPlant.BMSBatteryPackData.SegmentCurrentVector[27] / look1_binlxpw
    (bms_U.FromPlant.BMSBatteryPackData.SegmentTempVector[27],
     bms_ConstP.pooled8, bms_ConstP.pooled7, 2U) * 0.01;
  if (bms_DW.DiscreteTimeIntegrator_DSTAT_g0 >= 1.0) {
    bms_DW.DiscreteTimeIntegrator_DSTAT_g0 = 1.0;
  } else if (bms_DW.DiscreteTimeIntegrator_DSTAT_g0 <= 0.0) {
    bms_DW.DiscreteTimeIntegrator_DSTAT_g0 = 0.0;
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
  bms_DW.DiscreteTimeIntegrator_DSTATE_d += -0.00027777778450399637 *
    bms_U.FromPlant.BMSBatteryPackData.SegmentCurrentVector[1] / look1_binlxpw
    (bms_U.FromPlant.BMSBatteryPackData.SegmentTempVector[1], bms_ConstP.pooled8,
     bms_ConstP.pooled7, 2U) * 0.01;
  if (bms_DW.DiscreteTimeIntegrator_DSTATE_d >= 1.0) {
    bms_DW.DiscreteTimeIntegrator_DSTATE_d = 1.0;
  } else if (bms_DW.DiscreteTimeIntegrator_DSTATE_d <= 0.0) {
    bms_DW.DiscreteTimeIntegrator_DSTATE_d = 0.0;
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
  bms_DW.DiscreteTimeIntegrator_DSTAT_b0 += -0.00027777778450399637 *
    bms_U.FromPlant.BMSBatteryPackData.SegmentCurrentVector[4] / look1_binlxpw
    (bms_U.FromPlant.BMSBatteryPackData.SegmentTempVector[4], bms_ConstP.pooled8,
     bms_ConstP.pooled7, 2U) * 0.01;
  if (bms_DW.DiscreteTimeIntegrator_DSTAT_b0 >= 1.0) {
    bms_DW.DiscreteTimeIntegrator_DSTAT_b0 = 1.0;
  } else if (bms_DW.DiscreteTimeIntegrator_DSTAT_b0 <= 0.0) {
    bms_DW.DiscreteTimeIntegrator_DSTAT_b0 = 0.0;
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
  bms_DW.DiscreteTimeIntegrator_DSTAT_dc += -0.00027777778450399637 *
    bms_U.FromPlant.BMSBatteryPackData.SegmentCurrentVector[7] / look1_binlxpw
    (bms_U.FromPlant.BMSBatteryPackData.SegmentTempVector[7], bms_ConstP.pooled8,
     bms_ConstP.pooled7, 2U) * 0.01;
  if (bms_DW.DiscreteTimeIntegrator_DSTAT_dc >= 1.0) {
    bms_DW.DiscreteTimeIntegrator_DSTAT_dc = 1.0;
  } else if (bms_DW.DiscreteTimeIntegrator_DSTAT_dc <= 0.0) {
    bms_DW.DiscreteTimeIntegrator_DSTAT_dc = 0.0;
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
  bms_DW.DiscreteTimeIntegrator_DSTATE_o += -0.00027777778450399637 *
    bms_U.FromPlant.BMSBatteryPackData.SegmentCurrentVector[10] / look1_binlxpw
    (bms_U.FromPlant.BMSBatteryPackData.SegmentTempVector[10],
     bms_ConstP.pooled8, bms_ConstP.pooled7, 2U) * 0.01;
  if (bms_DW.DiscreteTimeIntegrator_DSTATE_o >= 1.0) {
    bms_DW.DiscreteTimeIntegrator_DSTATE_o = 1.0;
  } else if (bms_DW.DiscreteTimeIntegrator_DSTATE_o <= 0.0) {
    bms_DW.DiscreteTimeIntegrator_DSTATE_o = 0.0;
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
  bms_DW.DiscreteTimeIntegrator_DSTAT_aw += -0.00027777778450399637 *
    bms_U.FromPlant.BMSBatteryPackData.SegmentCurrentVector[13] / look1_binlxpw
    (bms_U.FromPlant.BMSBatteryPackData.SegmentTempVector[13],
     bms_ConstP.pooled8, bms_ConstP.pooled7, 2U) * 0.01;
  if (bms_DW.DiscreteTimeIntegrator_DSTAT_aw >= 1.0) {
    bms_DW.DiscreteTimeIntegrator_DSTAT_aw = 1.0;
  } else if (bms_DW.DiscreteTimeIntegrator_DSTAT_aw <= 0.0) {
    bms_DW.DiscreteTimeIntegrator_DSTAT_aw = 0.0;
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
  bms_DW.DiscreteTimeIntegrator_DSTATE_n += -0.00027777778450399637 *
    bms_U.FromPlant.BMSBatteryPackData.SegmentCurrentVector[16] / look1_binlxpw
    (bms_U.FromPlant.BMSBatteryPackData.SegmentTempVector[16],
     bms_ConstP.pooled8, bms_ConstP.pooled7, 2U) * 0.01;
  if (bms_DW.DiscreteTimeIntegrator_DSTATE_n >= 1.0) {
    bms_DW.DiscreteTimeIntegrator_DSTATE_n = 1.0;
  } else if (bms_DW.DiscreteTimeIntegrator_DSTATE_n <= 0.0) {
    bms_DW.DiscreteTimeIntegrator_DSTATE_n = 0.0;
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
  bms_DW.DiscreteTimeIntegrator_DSTATE_e += -0.00027777778450399637 *
    bms_U.FromPlant.BMSBatteryPackData.SegmentCurrentVector[19] / look1_binlxpw
    (bms_U.FromPlant.BMSBatteryPackData.SegmentTempVector[19],
     bms_ConstP.pooled8, bms_ConstP.pooled7, 2U) * 0.01;
  if (bms_DW.DiscreteTimeIntegrator_DSTATE_e >= 1.0) {
    bms_DW.DiscreteTimeIntegrator_DSTATE_e = 1.0;
  } else if (bms_DW.DiscreteTimeIntegrator_DSTATE_e <= 0.0) {
    bms_DW.DiscreteTimeIntegrator_DSTATE_e = 0.0;
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
  bms_DW.DiscreteTimeIntegrator_DSTATE_f += -0.00027777778450399637 *
    bms_U.FromPlant.BMSBatteryPackData.SegmentCurrentVector[22] / look1_binlxpw
    (bms_U.FromPlant.BMSBatteryPackData.SegmentTempVector[22],
     bms_ConstP.pooled8, bms_ConstP.pooled7, 2U) * 0.01;
  if (bms_DW.DiscreteTimeIntegrator_DSTATE_f >= 1.0) {
    bms_DW.DiscreteTimeIntegrator_DSTATE_f = 1.0;
  } else if (bms_DW.DiscreteTimeIntegrator_DSTATE_f <= 0.0) {
    bms_DW.DiscreteTimeIntegrator_DSTATE_f = 0.0;
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
  bms_DW.DiscreteTimeIntegrator_DSTAT_aj += -0.00027777778450399637 *
    bms_U.FromPlant.BMSBatteryPackData.SegmentCurrentVector[25] / look1_binlxpw
    (bms_U.FromPlant.BMSBatteryPackData.SegmentTempVector[25],
     bms_ConstP.pooled8, bms_ConstP.pooled7, 2U) * 0.01;
  if (bms_DW.DiscreteTimeIntegrator_DSTAT_aj >= 1.0) {
    bms_DW.DiscreteTimeIntegrator_DSTAT_aj = 1.0;
  } else if (bms_DW.DiscreteTimeIntegrator_DSTAT_aj <= 0.0) {
    bms_DW.DiscreteTimeIntegrator_DSTAT_aj = 0.0;
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
  bms_DW.DiscreteTimeIntegrator_DSTAT_bc += -0.00027777778450399637 *
    bms_U.FromPlant.BMSBatteryPackData.SegmentCurrentVector[28] / look1_binlxpw
    (bms_U.FromPlant.BMSBatteryPackData.SegmentTempVector[28],
     bms_ConstP.pooled8, bms_ConstP.pooled7, 2U) * 0.01;
  if (bms_DW.DiscreteTimeIntegrator_DSTAT_bc >= 1.0) {
    bms_DW.DiscreteTimeIntegrator_DSTAT_bc = 1.0;
  } else if (bms_DW.DiscreteTimeIntegrator_DSTAT_bc <= 0.0) {
    bms_DW.DiscreteTimeIntegrator_DSTAT_bc = 0.0;
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
  bms_DW.DiscreteTimeIntegrator_DSTAT_ps += -0.00027777778450399637 *
    bms_U.FromPlant.BMSBatteryPackData.SegmentCurrentVector[2] / look1_binlxpw
    (bms_U.FromPlant.BMSBatteryPackData.SegmentTempVector[2], bms_ConstP.pooled8,
     bms_ConstP.pooled7, 2U) * 0.01;
  if (bms_DW.DiscreteTimeIntegrator_DSTAT_ps >= 1.0) {
    bms_DW.DiscreteTimeIntegrator_DSTAT_ps = 1.0;
  } else if (bms_DW.DiscreteTimeIntegrator_DSTAT_ps <= 0.0) {
    bms_DW.DiscreteTimeIntegrator_DSTAT_ps = 0.0;
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
  bms_DW.DiscreteTimeIntegrator_DSTAT_ed += -0.00027777778450399637 *
    bms_U.FromPlant.BMSBatteryPackData.SegmentCurrentVector[5] / look1_binlxpw
    (bms_U.FromPlant.BMSBatteryPackData.SegmentTempVector[5], bms_ConstP.pooled8,
     bms_ConstP.pooled7, 2U) * 0.01;
  if (bms_DW.DiscreteTimeIntegrator_DSTAT_ed >= 1.0) {
    bms_DW.DiscreteTimeIntegrator_DSTAT_ed = 1.0;
  } else if (bms_DW.DiscreteTimeIntegrator_DSTAT_ed <= 0.0) {
    bms_DW.DiscreteTimeIntegrator_DSTAT_ed = 0.0;
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
  bms_DW.DiscreteTimeIntegrator_DSTAT_mg += -0.00027777778450399637 *
    bms_U.FromPlant.BMSBatteryPackData.SegmentCurrentVector[8] / look1_binlxpw
    (bms_U.FromPlant.BMSBatteryPackData.SegmentTempVector[8], bms_ConstP.pooled8,
     bms_ConstP.pooled7, 2U) * 0.01;
  if (bms_DW.DiscreteTimeIntegrator_DSTAT_mg >= 1.0) {
    bms_DW.DiscreteTimeIntegrator_DSTAT_mg = 1.0;
  } else if (bms_DW.DiscreteTimeIntegrator_DSTAT_mg <= 0.0) {
    bms_DW.DiscreteTimeIntegrator_DSTAT_mg = 0.0;
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
  bms_DW.DiscreteTimeIntegrator_DSTAT_fy += -0.00027777778450399637 *
    bms_U.FromPlant.BMSBatteryPackData.SegmentCurrentVector[11] / look1_binlxpw
    (bms_U.FromPlant.BMSBatteryPackData.SegmentTempVector[11],
     bms_ConstP.pooled8, bms_ConstP.pooled7, 2U) * 0.01;
  if (bms_DW.DiscreteTimeIntegrator_DSTAT_fy >= 1.0) {
    bms_DW.DiscreteTimeIntegrator_DSTAT_fy = 1.0;
  } else if (bms_DW.DiscreteTimeIntegrator_DSTAT_fy <= 0.0) {
    bms_DW.DiscreteTimeIntegrator_DSTAT_fy = 0.0;
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
  bms_DW.DiscreteTimeIntegrator_DSTAT_gd += -0.00027777778450399637 *
    bms_U.FromPlant.BMSBatteryPackData.SegmentCurrentVector[14] / look1_binlxpw
    (bms_U.FromPlant.BMSBatteryPackData.SegmentTempVector[14],
     bms_ConstP.pooled8, bms_ConstP.pooled7, 2U) * 0.01;
  if (bms_DW.DiscreteTimeIntegrator_DSTAT_gd >= 1.0) {
    bms_DW.DiscreteTimeIntegrator_DSTAT_gd = 1.0;
  } else if (bms_DW.DiscreteTimeIntegrator_DSTAT_gd <= 0.0) {
    bms_DW.DiscreteTimeIntegrator_DSTAT_gd = 0.0;
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
  bms_DW.DiscreteTimeIntegrator_DSTATE_i += -0.00027777778450399637 *
    bms_U.FromPlant.BMSBatteryPackData.SegmentCurrentVector[17] / look1_binlxpw
    (bms_U.FromPlant.BMSBatteryPackData.SegmentTempVector[17],
     bms_ConstP.pooled8, bms_ConstP.pooled7, 2U) * 0.01;
  if (bms_DW.DiscreteTimeIntegrator_DSTATE_i >= 1.0) {
    bms_DW.DiscreteTimeIntegrator_DSTATE_i = 1.0;
  } else if (bms_DW.DiscreteTimeIntegrator_DSTATE_i <= 0.0) {
    bms_DW.DiscreteTimeIntegrator_DSTATE_i = 0.0;
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
  bms_DW.DiscreteTimeIntegrator_DSTAT_ce += -0.00027777778450399637 *
    bms_U.FromPlant.BMSBatteryPackData.SegmentCurrentVector[20] / look1_binlxpw
    (bms_U.FromPlant.BMSBatteryPackData.SegmentTempVector[20],
     bms_ConstP.pooled8, bms_ConstP.pooled7, 2U) * 0.01;
  if (bms_DW.DiscreteTimeIntegrator_DSTAT_ce >= 1.0) {
    bms_DW.DiscreteTimeIntegrator_DSTAT_ce = 1.0;
  } else if (bms_DW.DiscreteTimeIntegrator_DSTAT_ce <= 0.0) {
    bms_DW.DiscreteTimeIntegrator_DSTAT_ce = 0.0;
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
  bms_DW.DiscreteTimeIntegrator_DSTAT_p0 += -0.00027777778450399637 *
    bms_U.FromPlant.BMSBatteryPackData.SegmentCurrentVector[23] / look1_binlxpw
    (bms_U.FromPlant.BMSBatteryPackData.SegmentTempVector[23],
     bms_ConstP.pooled8, bms_ConstP.pooled7, 2U) * 0.01;
  if (bms_DW.DiscreteTimeIntegrator_DSTAT_p0 >= 1.0) {
    bms_DW.DiscreteTimeIntegrator_DSTAT_p0 = 1.0;
  } else if (bms_DW.DiscreteTimeIntegrator_DSTAT_p0 <= 0.0) {
    bms_DW.DiscreteTimeIntegrator_DSTAT_p0 = 0.0;
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
  bms_DW.DiscreteTimeIntegrator_DSTAT_fb += -0.00027777778450399637 *
    bms_U.FromPlant.BMSBatteryPackData.SegmentCurrentVector[26] / look1_binlxpw
    (bms_U.FromPlant.BMSBatteryPackData.SegmentTempVector[26],
     bms_ConstP.pooled8, bms_ConstP.pooled7, 2U) * 0.01;
  if (bms_DW.DiscreteTimeIntegrator_DSTAT_fb >= 1.0) {
    bms_DW.DiscreteTimeIntegrator_DSTAT_fb = 1.0;
  } else if (bms_DW.DiscreteTimeIntegrator_DSTAT_fb <= 0.0) {
    bms_DW.DiscreteTimeIntegrator_DSTAT_fb = 0.0;
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
  bms_DW.DiscreteTimeIntegrator_DSTAT_d3 += -0.00027777778450399637 *
    bms_U.FromPlant.BMSBatteryPackData.SegmentCurrentVector[29] / look1_binlxpw
    (bms_U.FromPlant.BMSBatteryPackData.SegmentTempVector[29],
     bms_ConstP.pooled8, bms_ConstP.pooled7, 2U) * 0.01;
  if (bms_DW.DiscreteTimeIntegrator_DSTAT_d3 >= 1.0) {
    bms_DW.DiscreteTimeIntegrator_DSTAT_d3 = 1.0;
  } else if (bms_DW.DiscreteTimeIntegrator_DSTAT_d3 <= 0.0) {
    bms_DW.DiscreteTimeIntegrator_DSTAT_d3 = 0.0;
  }

  /* End of Update for DiscreteIntegrator: '<S36>/Discrete-Time Integrator' */
}

/* Model initialize function */
void bms_initialize(void)
{
  /* InitializeConditions for DiscreteIntegrator: '<S17>/Discrete-Time Integrator' */
  bms_DW.DiscreteTimeIntegrator_DSTATE = 1.0;

  /* InitializeConditions for DiscreteIntegrator: '<S8>/Discrete-Time Integrator' */
  bms_DW.DiscreteTimeIntegrator_DSTATE_a = 1.0;

  /* InitializeConditions for DiscreteIntegrator: '<S9>/Discrete-Time Integrator' */
  bms_DW.DiscreteTimeIntegrator_DSTAT_au = 1.0;

  /* InitializeConditions for DiscreteIntegrator: '<S10>/Discrete-Time Integrator' */
  bms_DW.DiscreteTimeIntegrator_DSTATE_m = 1.0;

  /* InitializeConditions for DiscreteIntegrator: '<S11>/Discrete-Time Integrator' */
  bms_DW.DiscreteTimeIntegrator_DSTATE_b = 1.0;

  /* InitializeConditions for DiscreteIntegrator: '<S12>/Discrete-Time Integrator' */
  bms_DW.DiscreteTimeIntegrator_DSTATE_p = 1.0;

  /* InitializeConditions for DiscreteIntegrator: '<S13>/Discrete-Time Integrator' */
  bms_DW.DiscreteTimeIntegrator_DSTATE_c = 1.0;

  /* InitializeConditions for DiscreteIntegrator: '<S14>/Discrete-Time Integrator' */
  bms_DW.DiscreteTimeIntegrator_DSTAT_mh = 1.0;

  /* InitializeConditions for DiscreteIntegrator: '<S15>/Discrete-Time Integrator' */
  bms_DW.DiscreteTimeIntegrator_DSTATE_g = 1.0;

  /* InitializeConditions for DiscreteIntegrator: '<S16>/Discrete-Time Integrator' */
  bms_DW.DiscreteTimeIntegrator_DSTAT_g0 = 1.0;

  /* InitializeConditions for DiscreteIntegrator: '<S27>/Discrete-Time Integrator' */
  bms_DW.DiscreteTimeIntegrator_DSTATE_d = 1.0;

  /* InitializeConditions for DiscreteIntegrator: '<S18>/Discrete-Time Integrator' */
  bms_DW.DiscreteTimeIntegrator_DSTAT_b0 = 1.0;

  /* InitializeConditions for DiscreteIntegrator: '<S19>/Discrete-Time Integrator' */
  bms_DW.DiscreteTimeIntegrator_DSTAT_dc = 1.0;

  /* InitializeConditions for DiscreteIntegrator: '<S20>/Discrete-Time Integrator' */
  bms_DW.DiscreteTimeIntegrator_DSTATE_o = 1.0;

  /* InitializeConditions for DiscreteIntegrator: '<S21>/Discrete-Time Integrator' */
  bms_DW.DiscreteTimeIntegrator_DSTAT_aw = 1.0;

  /* InitializeConditions for DiscreteIntegrator: '<S22>/Discrete-Time Integrator' */
  bms_DW.DiscreteTimeIntegrator_DSTATE_n = 1.0;

  /* InitializeConditions for DiscreteIntegrator: '<S23>/Discrete-Time Integrator' */
  bms_DW.DiscreteTimeIntegrator_DSTATE_e = 1.0;

  /* InitializeConditions for DiscreteIntegrator: '<S24>/Discrete-Time Integrator' */
  bms_DW.DiscreteTimeIntegrator_DSTATE_f = 1.0;

  /* InitializeConditions for DiscreteIntegrator: '<S25>/Discrete-Time Integrator' */
  bms_DW.DiscreteTimeIntegrator_DSTAT_aj = 1.0;

  /* InitializeConditions for DiscreteIntegrator: '<S26>/Discrete-Time Integrator' */
  bms_DW.DiscreteTimeIntegrator_DSTAT_bc = 1.0;

  /* InitializeConditions for DiscreteIntegrator: '<S37>/Discrete-Time Integrator' */
  bms_DW.DiscreteTimeIntegrator_DSTAT_ps = 1.0;

  /* InitializeConditions for DiscreteIntegrator: '<S28>/Discrete-Time Integrator' */
  bms_DW.DiscreteTimeIntegrator_DSTAT_ed = 1.0;

  /* InitializeConditions for DiscreteIntegrator: '<S29>/Discrete-Time Integrator' */
  bms_DW.DiscreteTimeIntegrator_DSTAT_mg = 1.0;

  /* InitializeConditions for DiscreteIntegrator: '<S30>/Discrete-Time Integrator' */
  bms_DW.DiscreteTimeIntegrator_DSTAT_fy = 1.0;

  /* InitializeConditions for DiscreteIntegrator: '<S31>/Discrete-Time Integrator' */
  bms_DW.DiscreteTimeIntegrator_DSTAT_gd = 1.0;

  /* InitializeConditions for DiscreteIntegrator: '<S32>/Discrete-Time Integrator' */
  bms_DW.DiscreteTimeIntegrator_DSTATE_i = 1.0;

  /* InitializeConditions for DiscreteIntegrator: '<S33>/Discrete-Time Integrator' */
  bms_DW.DiscreteTimeIntegrator_DSTAT_ce = 1.0;

  /* InitializeConditions for DiscreteIntegrator: '<S34>/Discrete-Time Integrator' */
  bms_DW.DiscreteTimeIntegrator_DSTAT_p0 = 1.0;

  /* InitializeConditions for DiscreteIntegrator: '<S35>/Discrete-Time Integrator' */
  bms_DW.DiscreteTimeIntegrator_DSTAT_fb = 1.0;

  /* InitializeConditions for DiscreteIntegrator: '<S36>/Discrete-Time Integrator' */
  bms_DW.DiscreteTimeIntegrator_DSTAT_d3 = 1.0;

  /* Chart: '<S3>/Chart' */
  bms_DW.is_c1_bms = bms_IN_init;

  /* SystemInitialize for Chart: '<S4>/Chart1' */
  bms_Chart1_Init(&bms_B.MatrixConcatenate[0], &bms_B.VectorConcatenate_k[0],
                  &bms_B.VectorConcatenate1_a[0]);

  /* SystemInitialize for Chart: '<S4>/Chart2' */
  bms_Chart1_Init(&bms_B.MatrixConcatenate[10], &bms_B.VectorConcatenate_k[1],
                  &bms_B.VectorConcatenate1_a[1]);

  /* SystemInitialize for Chart: '<S4>/Chart3' */
  bms_Chart1_Init(&bms_B.MatrixConcatenate[20], &bms_B.VectorConcatenate_k[2],
                  &bms_B.VectorConcatenate1_a[2]);
}

/* Model terminate function */
void bms_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
