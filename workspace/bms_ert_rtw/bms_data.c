/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: bms_data.c
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

/* Invariant block signals (default storage) */
const ConstB_bms_T bms_ConstB = {
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },/* synthesized block */

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },/* '<S5>/Transpose' */

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },/* synthesized block */

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },/* '<S6>/Transpose' */

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },/* synthesized block */

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },/* '<S7>/Transpose' */

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 }/* '<S1>/Matrix Concatenate' */
};

/* Constant parameters (default storage) */
const ConstP_bms_T bms_ConstP = {
  /* Pooled Parameter (Expression: single(LUTBattery_Charge);)
   * Referenced by:
   *   '<S8>/n-D Lookup Table'
   *   '<S9>/n-D Lookup Table'
   *   '<S10>/n-D Lookup Table'
   *   '<S11>/n-D Lookup Table'
   *   '<S12>/n-D Lookup Table'
   *   '<S13>/n-D Lookup Table'
   *   '<S14>/n-D Lookup Table'
   *   '<S15>/n-D Lookup Table'
   *   '<S16>/n-D Lookup Table'
   *   '<S17>/n-D Lookup Table'
   *   '<S18>/n-D Lookup Table'
   *   '<S19>/n-D Lookup Table'
   *   '<S20>/n-D Lookup Table'
   *   '<S21>/n-D Lookup Table'
   *   '<S22>/n-D Lookup Table'
   *   '<S23>/n-D Lookup Table'
   *   '<S24>/n-D Lookup Table'
   *   '<S25>/n-D Lookup Table'
   *   '<S26>/n-D Lookup Table'
   *   '<S27>/n-D Lookup Table'
   *   '<S28>/n-D Lookup Table'
   *   '<S29>/n-D Lookup Table'
   *   '<S30>/n-D Lookup Table'
   *   '<S31>/n-D Lookup Table'
   *   '<S32>/n-D Lookup Table'
   *   '<S33>/n-D Lookup Table'
   *   '<S34>/n-D Lookup Table'
   *   '<S35>/n-D Lookup Table'
   *   '<S36>/n-D Lookup Table'
   *   '<S37>/n-D Lookup Table'
   */
  { 2.4100000858306885, 2.3900001049041748, 2.2999999523162842 },

  /* Pooled Parameter (Expression: single(LUTBattery_Charge_Temp);)
   * Referenced by:
   *   '<S8>/n-D Lookup Table'
   *   '<S9>/n-D Lookup Table'
   *   '<S10>/n-D Lookup Table'
   *   '<S11>/n-D Lookup Table'
   *   '<S12>/n-D Lookup Table'
   *   '<S13>/n-D Lookup Table'
   *   '<S14>/n-D Lookup Table'
   *   '<S15>/n-D Lookup Table'
   *   '<S16>/n-D Lookup Table'
   *   '<S17>/n-D Lookup Table'
   *   '<S18>/n-D Lookup Table'
   *   '<S19>/n-D Lookup Table'
   *   '<S20>/n-D Lookup Table'
   *   '<S21>/n-D Lookup Table'
   *   '<S22>/n-D Lookup Table'
   *   '<S23>/n-D Lookup Table'
   *   '<S24>/n-D Lookup Table'
   *   '<S25>/n-D Lookup Table'
   *   '<S26>/n-D Lookup Table'
   *   '<S27>/n-D Lookup Table'
   *   '<S28>/n-D Lookup Table'
   *   '<S29>/n-D Lookup Table'
   *   '<S30>/n-D Lookup Table'
   *   '<S31>/n-D Lookup Table'
   *   '<S32>/n-D Lookup Table'
   *   '<S33>/n-D Lookup Table'
   *   '<S34>/n-D Lookup Table'
   *   '<S35>/n-D Lookup Table'
   *   '<S36>/n-D Lookup Table'
   *   '<S37>/n-D Lookup Table'
   */
  { 278.14999389648438, 293.14999389648438, 323.14999389648438 }
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
