/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: bms_f4_data.c
 *
 * Code generated for Simulink model 'bms_f4'.
 *
 * Model version                  : 1.33
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Mon May 31 18:37:05 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "bms_f4.h"
#include "bms_f4_private.h"

/* Block parameters (default storage) */
P_bms_f4_T bms_f4_P = {
  /* Variable: CellCurrentLimitThreshold_Fault
   * Referenced by: '<S39>/Constant'
   */
  50.0,

  /* Variable: CellCurrentLimitThreshold_Warning
   * Referenced by: '<S38>/Constant'
   */
  20.0,

  /* Variable: CellTemperatureLimitThreshold_Fault
   * Referenced by: '<S41>/Constant'
   */
  338.15,

  /* Variable: CellTemperatureLimitThreshold_Warning
   * Referenced by: '<S40>/Constant'
   */
  323.15,

  /* Variable: CellVoltageLimitHigh_Fault
   * Referenced by: '<S43>/Constant'
   */
  4.25,

  /* Variable: CellVoltageLimitHigh_Warning
   * Referenced by: '<S42>/Constant'
   */
  4.21,

  /* Variable: CellVoltageLimitLow_Fault
   * Referenced by: '<S45>/Constant'
   */
  2.65,

  /* Variable: CellVoltageLimitLow_Warning
   * Referenced by: '<S44>/Constant'
   */
  2.7,

  /* Variable: DeltaVTargetMin
   * Referenced by:
   *   '<S4>/Chart1'
   *   '<S4>/Chart2'
   *   '<S4>/Chart3'
   */
  0.001,

  /* Variable: DrivetrainEnDelay
   * Referenced by: '<S3>/Chart'
   */
  0.1,

  /* Variable: VbattMin
   * Referenced by: '<S3>/Chart'
   */
  1.0,

  /* Variable: VbattThersholdChrg
   * Referenced by: '<S3>/Chart'
   */
  0.8,

  /* Variable: VbattThresholdDis
   * Referenced by: '<S3>/Chart'
   */
  0.2,

  /* Variable: balancingRelaxationTime
   * Referenced by:
   *   '<S4>/Chart1'
   *   '<S4>/Chart2'
   *   '<S4>/Chart3'
   */
  1000.0,

  /* Variable: balancingTime
   * Referenced by:
   *   '<S4>/Chart1'
   *   '<S4>/Chart2'
   *   '<S4>/Chart3'
   */
  2000.0,

  /* Computed Parameter: DiscreteTimeIntegrator_gainval
   * Referenced by: '<S17>/Discrete-Time Integrator'
   */
  0.01,

  /* Computed Parameter: DiscreteTimeIntegrator_IC
   * Referenced by: '<S17>/Discrete-Time Integrator'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S17>/Discrete-Time Integrator'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S17>/Discrete-Time Integrator'
   */
  0.0,

  /* Computed Parameter: DiscreteTimeIntegrator_gainva_d
   * Referenced by: '<S8>/Discrete-Time Integrator'
   */
  0.01,

  /* Computed Parameter: DiscreteTimeIntegrator_IC_h
   * Referenced by: '<S8>/Discrete-Time Integrator'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S8>/Discrete-Time Integrator'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S8>/Discrete-Time Integrator'
   */
  0.0,

  /* Computed Parameter: DiscreteTimeIntegrator_gainva_o
   * Referenced by: '<S9>/Discrete-Time Integrator'
   */
  0.01,

  /* Computed Parameter: DiscreteTimeIntegrator_IC_d
   * Referenced by: '<S9>/Discrete-Time Integrator'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S9>/Discrete-Time Integrator'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S9>/Discrete-Time Integrator'
   */
  0.0,

  /* Computed Parameter: DiscreteTimeIntegrator_gainva_m
   * Referenced by: '<S10>/Discrete-Time Integrator'
   */
  0.01,

  /* Computed Parameter: DiscreteTimeIntegrator_IC_m
   * Referenced by: '<S10>/Discrete-Time Integrator'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S10>/Discrete-Time Integrator'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S10>/Discrete-Time Integrator'
   */
  0.0,

  /* Computed Parameter: DiscreteTimeIntegrator_gainv_do
   * Referenced by: '<S11>/Discrete-Time Integrator'
   */
  0.01,

  /* Computed Parameter: DiscreteTimeIntegrator_IC_l
   * Referenced by: '<S11>/Discrete-Time Integrator'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S11>/Discrete-Time Integrator'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S11>/Discrete-Time Integrator'
   */
  0.0,

  /* Computed Parameter: DiscreteTimeIntegrator_gainv_mu
   * Referenced by: '<S12>/Discrete-Time Integrator'
   */
  0.01,

  /* Computed Parameter: DiscreteTimeIntegrator_IC_p
   * Referenced by: '<S12>/Discrete-Time Integrator'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S12>/Discrete-Time Integrator'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S12>/Discrete-Time Integrator'
   */
  0.0,

  /* Computed Parameter: DiscreteTimeIntegrator_gainva_i
   * Referenced by: '<S13>/Discrete-Time Integrator'
   */
  0.01,

  /* Computed Parameter: DiscreteTimeIntegrator_IC_o
   * Referenced by: '<S13>/Discrete-Time Integrator'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S13>/Discrete-Time Integrator'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S13>/Discrete-Time Integrator'
   */
  0.0,

  /* Computed Parameter: DiscreteTimeIntegrator_gainva_l
   * Referenced by: '<S14>/Discrete-Time Integrator'
   */
  0.01,

  /* Computed Parameter: DiscreteTimeIntegrator_IC_m3
   * Referenced by: '<S14>/Discrete-Time Integrator'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S14>/Discrete-Time Integrator'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S14>/Discrete-Time Integrator'
   */
  0.0,

  /* Computed Parameter: DiscreteTimeIntegrator_gainv_oo
   * Referenced by: '<S15>/Discrete-Time Integrator'
   */
  0.01,

  /* Computed Parameter: DiscreteTimeIntegrator_IC_e
   * Referenced by: '<S15>/Discrete-Time Integrator'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S15>/Discrete-Time Integrator'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S15>/Discrete-Time Integrator'
   */
  0.0,

  /* Computed Parameter: DiscreteTimeIntegrator_gainva_p
   * Referenced by: '<S16>/Discrete-Time Integrator'
   */
  0.01,

  /* Computed Parameter: DiscreteTimeIntegrator_IC_ou
   * Referenced by: '<S16>/Discrete-Time Integrator'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S16>/Discrete-Time Integrator'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S16>/Discrete-Time Integrator'
   */
  0.0,

  /* Computed Parameter: DiscreteTimeIntegrator_gainva_k
   * Referenced by: '<S27>/Discrete-Time Integrator'
   */
  0.01,

  /* Computed Parameter: DiscreteTimeIntegrator_IC_b
   * Referenced by: '<S27>/Discrete-Time Integrator'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S27>/Discrete-Time Integrator'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S27>/Discrete-Time Integrator'
   */
  0.0,

  /* Computed Parameter: DiscreteTimeIntegrator_gainv_ks
   * Referenced by: '<S18>/Discrete-Time Integrator'
   */
  0.01,

  /* Computed Parameter: DiscreteTimeIntegrator_IC_dx
   * Referenced by: '<S18>/Discrete-Time Integrator'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S18>/Discrete-Time Integrator'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S18>/Discrete-Time Integrator'
   */
  0.0,

  /* Computed Parameter: DiscreteTimeIntegrator_gainva_c
   * Referenced by: '<S19>/Discrete-Time Integrator'
   */
  0.01,

  /* Computed Parameter: DiscreteTimeIntegrator_IC_lq
   * Referenced by: '<S19>/Discrete-Time Integrator'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S19>/Discrete-Time Integrator'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S19>/Discrete-Time Integrator'
   */
  0.0,

  /* Computed Parameter: DiscreteTimeIntegrator_gainva_a
   * Referenced by: '<S20>/Discrete-Time Integrator'
   */
  0.01,

  /* Computed Parameter: DiscreteTimeIntegrator_IC_oq
   * Referenced by: '<S20>/Discrete-Time Integrator'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S20>/Discrete-Time Integrator'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S20>/Discrete-Time Integrator'
   */
  0.0,

  /* Computed Parameter: DiscreteTimeIntegrator_gainva_n
   * Referenced by: '<S21>/Discrete-Time Integrator'
   */
  0.01,

  /* Computed Parameter: DiscreteTimeIntegrator_IC_dk
   * Referenced by: '<S21>/Discrete-Time Integrator'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S21>/Discrete-Time Integrator'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S21>/Discrete-Time Integrator'
   */
  0.0,

  /* Computed Parameter: DiscreteTimeIntegrator_gainv_co
   * Referenced by: '<S22>/Discrete-Time Integrator'
   */
  0.01,

  /* Computed Parameter: DiscreteTimeIntegrator_IC_on
   * Referenced by: '<S22>/Discrete-Time Integrator'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S22>/Discrete-Time Integrator'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S22>/Discrete-Time Integrator'
   */
  0.0,

  /* Computed Parameter: DiscreteTimeIntegrator_gainva_f
   * Referenced by: '<S23>/Discrete-Time Integrator'
   */
  0.01,

  /* Computed Parameter: DiscreteTimeIntegrator_IC_c
   * Referenced by: '<S23>/Discrete-Time Integrator'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S23>/Discrete-Time Integrator'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S23>/Discrete-Time Integrator'
   */
  0.0,

  /* Computed Parameter: DiscreteTimeIntegrator_gainv_cu
   * Referenced by: '<S24>/Discrete-Time Integrator'
   */
  0.01,

  /* Computed Parameter: DiscreteTimeIntegrator_IC_lt
   * Referenced by: '<S24>/Discrete-Time Integrator'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S24>/Discrete-Time Integrator'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S24>/Discrete-Time Integrator'
   */
  0.0,

  /* Computed Parameter: DiscreteTimeIntegrator_gainva_e
   * Referenced by: '<S25>/Discrete-Time Integrator'
   */
  0.01,

  /* Computed Parameter: DiscreteTimeIntegrator_IC_k
   * Referenced by: '<S25>/Discrete-Time Integrator'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S25>/Discrete-Time Integrator'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S25>/Discrete-Time Integrator'
   */
  0.0,

  /* Computed Parameter: DiscreteTimeIntegrator_gainv_pk
   * Referenced by: '<S26>/Discrete-Time Integrator'
   */
  0.01,

  /* Computed Parameter: DiscreteTimeIntegrator_IC_dc
   * Referenced by: '<S26>/Discrete-Time Integrator'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S26>/Discrete-Time Integrator'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S26>/Discrete-Time Integrator'
   */
  0.0,

  /* Computed Parameter: DiscreteTimeIntegrator_gainv_nb
   * Referenced by: '<S37>/Discrete-Time Integrator'
   */
  0.01,

  /* Computed Parameter: DiscreteTimeIntegrator_IC_j
   * Referenced by: '<S37>/Discrete-Time Integrator'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S37>/Discrete-Time Integrator'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S37>/Discrete-Time Integrator'
   */
  0.0,

  /* Computed Parameter: DiscreteTimeIntegrator_gainv_a5
   * Referenced by: '<S28>/Discrete-Time Integrator'
   */
  0.01,

  /* Computed Parameter: DiscreteTimeIntegrator_IC_hw
   * Referenced by: '<S28>/Discrete-Time Integrator'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S28>/Discrete-Time Integrator'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S28>/Discrete-Time Integrator'
   */
  0.0,

  /* Computed Parameter: DiscreteTimeIntegrator_gainv_md
   * Referenced by: '<S29>/Discrete-Time Integrator'
   */
  0.01,

  /* Computed Parameter: DiscreteTimeIntegrator_IC_dv
   * Referenced by: '<S29>/Discrete-Time Integrator'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S29>/Discrete-Time Integrator'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S29>/Discrete-Time Integrator'
   */
  0.0,

  /* Computed Parameter: DiscreteTimeIntegrator_gainv_lm
   * Referenced by: '<S30>/Discrete-Time Integrator'
   */
  0.01,

  /* Computed Parameter: DiscreteTimeIntegrator_IC_l1
   * Referenced by: '<S30>/Discrete-Time Integrator'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S30>/Discrete-Time Integrator'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S30>/Discrete-Time Integrator'
   */
  0.0,

  /* Computed Parameter: DiscreteTimeIntegrator_gainv_ae
   * Referenced by: '<S31>/Discrete-Time Integrator'
   */
  0.01,

  /* Computed Parameter: DiscreteTimeIntegrator_IC_i
   * Referenced by: '<S31>/Discrete-Time Integrator'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S31>/Discrete-Time Integrator'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S31>/Discrete-Time Integrator'
   */
  0.0,

  /* Computed Parameter: DiscreteTimeIntegrator_gainv_lx
   * Referenced by: '<S32>/Discrete-Time Integrator'
   */
  0.01,

  /* Computed Parameter: DiscreteTimeIntegrator_IC_f
   * Referenced by: '<S32>/Discrete-Time Integrator'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S32>/Discrete-Time Integrator'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S32>/Discrete-Time Integrator'
   */
  0.0,

  /* Computed Parameter: DiscreteTimeIntegrator_gain_pkl
   * Referenced by: '<S33>/Discrete-Time Integrator'
   */
  0.01,

  /* Computed Parameter: DiscreteTimeIntegrator_IC_ln
   * Referenced by: '<S33>/Discrete-Time Integrator'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S33>/Discrete-Time Integrator'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S33>/Discrete-Time Integrator'
   */
  0.0,

  /* Computed Parameter: DiscreteTimeIntegrator_gain_lxl
   * Referenced by: '<S34>/Discrete-Time Integrator'
   */
  0.01,

  /* Computed Parameter: DiscreteTimeIntegrator_IC_mf
   * Referenced by: '<S34>/Discrete-Time Integrator'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S34>/Discrete-Time Integrator'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S34>/Discrete-Time Integrator'
   */
  0.0,

  /* Computed Parameter: DiscreteTimeIntegrator_gainv_ea
   * Referenced by: '<S35>/Discrete-Time Integrator'
   */
  0.01,

  /* Computed Parameter: DiscreteTimeIntegrator_IC_mz
   * Referenced by: '<S35>/Discrete-Time Integrator'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S35>/Discrete-Time Integrator'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S35>/Discrete-Time Integrator'
   */
  0.0,

  /* Computed Parameter: DiscreteTimeIntegrator_gainv_ol
   * Referenced by: '<S36>/Discrete-Time Integrator'
   */
  0.01,

  /* Computed Parameter: DiscreteTimeIntegrator_IC_m1
   * Referenced by: '<S36>/Discrete-Time Integrator'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S36>/Discrete-Time Integrator'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S36>/Discrete-Time Integrator'
   */
  0.0,

  /* Computed Parameter: nDLookupTable_tableData
   * Referenced by: '<S8>/n-D Lookup Table'
   */
  { 2.4100000858306885, 2.3900001049041748, 2.2999999523162842 },

  /* Computed Parameter: nDLookupTable_bp01Data
   * Referenced by: '<S8>/n-D Lookup Table'
   */
  { 278.14999389648438, 293.14999389648438, 323.14999389648438 },

  /* Computed Parameter: Gain_Gain
   * Referenced by: '<S8>/Gain'
   */
  -0.00027777778450399637,

  /* Computed Parameter: nDLookupTable_tableData_f
   * Referenced by: '<S9>/n-D Lookup Table'
   */
  { 2.4100000858306885, 2.3900001049041748, 2.2999999523162842 },

  /* Computed Parameter: nDLookupTable_bp01Data_o
   * Referenced by: '<S9>/n-D Lookup Table'
   */
  { 278.14999389648438, 293.14999389648438, 323.14999389648438 },

  /* Computed Parameter: Gain_Gain_f
   * Referenced by: '<S9>/Gain'
   */
  -0.00027777778450399637,

  /* Computed Parameter: nDLookupTable_tableData_e
   * Referenced by: '<S10>/n-D Lookup Table'
   */
  { 2.4100000858306885, 2.3900001049041748, 2.2999999523162842 },

  /* Computed Parameter: nDLookupTable_bp01Data_m
   * Referenced by: '<S10>/n-D Lookup Table'
   */
  { 278.14999389648438, 293.14999389648438, 323.14999389648438 },

  /* Computed Parameter: Gain_Gain_m
   * Referenced by: '<S10>/Gain'
   */
  -0.00027777778450399637,

  /* Computed Parameter: nDLookupTable_tableData_a
   * Referenced by: '<S11>/n-D Lookup Table'
   */
  { 2.4100000858306885, 2.3900001049041748, 2.2999999523162842 },

  /* Computed Parameter: nDLookupTable_bp01Data_c
   * Referenced by: '<S11>/n-D Lookup Table'
   */
  { 278.14999389648438, 293.14999389648438, 323.14999389648438 },

  /* Computed Parameter: Gain_Gain_fa
   * Referenced by: '<S11>/Gain'
   */
  -0.00027777778450399637,

  /* Computed Parameter: nDLookupTable_tableData_h
   * Referenced by: '<S12>/n-D Lookup Table'
   */
  { 2.4100000858306885, 2.3900001049041748, 2.2999999523162842 },

  /* Computed Parameter: nDLookupTable_bp01Data_h
   * Referenced by: '<S12>/n-D Lookup Table'
   */
  { 278.14999389648438, 293.14999389648438, 323.14999389648438 },

  /* Computed Parameter: Gain_Gain_l
   * Referenced by: '<S12>/Gain'
   */
  -0.00027777778450399637,

  /* Computed Parameter: nDLookupTable_tableData_m
   * Referenced by: '<S13>/n-D Lookup Table'
   */
  { 2.4100000858306885, 2.3900001049041748, 2.2999999523162842 },

  /* Computed Parameter: nDLookupTable_bp01Data_g
   * Referenced by: '<S13>/n-D Lookup Table'
   */
  { 278.14999389648438, 293.14999389648438, 323.14999389648438 },

  /* Computed Parameter: Gain_Gain_c
   * Referenced by: '<S13>/Gain'
   */
  -0.00027777778450399637,

  /* Computed Parameter: nDLookupTable_tableData_j
   * Referenced by: '<S14>/n-D Lookup Table'
   */
  { 2.4100000858306885, 2.3900001049041748, 2.2999999523162842 },

  /* Computed Parameter: nDLookupTable_bp01Data_gg
   * Referenced by: '<S14>/n-D Lookup Table'
   */
  { 278.14999389648438, 293.14999389648438, 323.14999389648438 },

  /* Computed Parameter: Gain_Gain_n
   * Referenced by: '<S14>/Gain'
   */
  -0.00027777778450399637,

  /* Computed Parameter: nDLookupTable_tableData_i
   * Referenced by: '<S15>/n-D Lookup Table'
   */
  { 2.4100000858306885, 2.3900001049041748, 2.2999999523162842 },

  /* Computed Parameter: nDLookupTable_bp01Data_p
   * Referenced by: '<S15>/n-D Lookup Table'
   */
  { 278.14999389648438, 293.14999389648438, 323.14999389648438 },

  /* Computed Parameter: Gain_Gain_o
   * Referenced by: '<S15>/Gain'
   */
  -0.00027777778450399637,

  /* Computed Parameter: nDLookupTable_tableData_fr
   * Referenced by: '<S16>/n-D Lookup Table'
   */
  { 2.4100000858306885, 2.3900001049041748, 2.2999999523162842 },

  /* Computed Parameter: nDLookupTable_bp01Data_j
   * Referenced by: '<S16>/n-D Lookup Table'
   */
  { 278.14999389648438, 293.14999389648438, 323.14999389648438 },

  /* Computed Parameter: Gain_Gain_la
   * Referenced by: '<S16>/Gain'
   */
  -0.00027777778450399637,

  /* Computed Parameter: nDLookupTable_tableData_g
   * Referenced by: '<S17>/n-D Lookup Table'
   */
  { 2.4100000858306885, 2.3900001049041748, 2.2999999523162842 },

  /* Computed Parameter: nDLookupTable_bp01Data_k
   * Referenced by: '<S17>/n-D Lookup Table'
   */
  { 278.14999389648438, 293.14999389648438, 323.14999389648438 },

  /* Computed Parameter: Gain_Gain_c4
   * Referenced by: '<S17>/Gain'
   */
  -0.00027777778450399637,

  /* Computed Parameter: nDLookupTable_tableData_l
   * Referenced by: '<S18>/n-D Lookup Table'
   */
  { 2.4100000858306885, 2.3900001049041748, 2.2999999523162842 },

  /* Computed Parameter: nDLookupTable_bp01Data_i
   * Referenced by: '<S18>/n-D Lookup Table'
   */
  { 278.14999389648438, 293.14999389648438, 323.14999389648438 },

  /* Computed Parameter: Gain_Gain_p
   * Referenced by: '<S18>/Gain'
   */
  -0.00027777778450399637,

  /* Computed Parameter: nDLookupTable_tableData_md
   * Referenced by: '<S19>/n-D Lookup Table'
   */
  { 2.4100000858306885, 2.3900001049041748, 2.2999999523162842 },

  /* Computed Parameter: nDLookupTable_bp01Data_pr
   * Referenced by: '<S19>/n-D Lookup Table'
   */
  { 278.14999389648438, 293.14999389648438, 323.14999389648438 },

  /* Computed Parameter: Gain_Gain_d
   * Referenced by: '<S19>/Gain'
   */
  -0.00027777778450399637,

  /* Computed Parameter: nDLookupTable_tableData_aj
   * Referenced by: '<S20>/n-D Lookup Table'
   */
  { 2.4100000858306885, 2.3900001049041748, 2.2999999523162842 },

  /* Computed Parameter: nDLookupTable_bp01Data_ch
   * Referenced by: '<S20>/n-D Lookup Table'
   */
  { 278.14999389648438, 293.14999389648438, 323.14999389648438 },

  /* Computed Parameter: Gain_Gain_e
   * Referenced by: '<S20>/Gain'
   */
  -0.00027777778450399637,

  /* Computed Parameter: nDLookupTable_tableData_p
   * Referenced by: '<S21>/n-D Lookup Table'
   */
  { 2.4100000858306885, 2.3900001049041748, 2.2999999523162842 },

  /* Computed Parameter: nDLookupTable_bp01Data_l
   * Referenced by: '<S21>/n-D Lookup Table'
   */
  { 278.14999389648438, 293.14999389648438, 323.14999389648438 },

  /* Computed Parameter: Gain_Gain_i
   * Referenced by: '<S21>/Gain'
   */
  -0.00027777778450399637,

  /* Computed Parameter: nDLookupTable_tableData_mk
   * Referenced by: '<S22>/n-D Lookup Table'
   */
  { 2.4100000858306885, 2.3900001049041748, 2.2999999523162842 },

  /* Computed Parameter: nDLookupTable_bp01Data_gb
   * Referenced by: '<S22>/n-D Lookup Table'
   */
  { 278.14999389648438, 293.14999389648438, 323.14999389648438 },

  /* Computed Parameter: Gain_Gain_fu
   * Referenced by: '<S22>/Gain'
   */
  -0.00027777778450399637,

  /* Computed Parameter: nDLookupTable_tableData_o
   * Referenced by: '<S23>/n-D Lookup Table'
   */
  { 2.4100000858306885, 2.3900001049041748, 2.2999999523162842 },

  /* Computed Parameter: nDLookupTable_bp01Data_ll
   * Referenced by: '<S23>/n-D Lookup Table'
   */
  { 278.14999389648438, 293.14999389648438, 323.14999389648438 },

  /* Computed Parameter: Gain_Gain_b
   * Referenced by: '<S23>/Gain'
   */
  -0.00027777778450399637,

  /* Computed Parameter: nDLookupTable_tableData_o3
   * Referenced by: '<S24>/n-D Lookup Table'
   */
  { 2.4100000858306885, 2.3900001049041748, 2.2999999523162842 },

  /* Computed Parameter: nDLookupTable_bp01Data_b
   * Referenced by: '<S24>/n-D Lookup Table'
   */
  { 278.14999389648438, 293.14999389648438, 323.14999389648438 },

  /* Computed Parameter: Gain_Gain_k
   * Referenced by: '<S24>/Gain'
   */
  -0.00027777778450399637,

  /* Computed Parameter: nDLookupTable_tableData_pv
   * Referenced by: '<S25>/n-D Lookup Table'
   */
  { 2.4100000858306885, 2.3900001049041748, 2.2999999523162842 },

  /* Computed Parameter: nDLookupTable_bp01Data_f
   * Referenced by: '<S25>/n-D Lookup Table'
   */
  { 278.14999389648438, 293.14999389648438, 323.14999389648438 },

  /* Computed Parameter: Gain_Gain_bj
   * Referenced by: '<S25>/Gain'
   */
  -0.00027777778450399637,

  /* Computed Parameter: nDLookupTable_tableData_mx
   * Referenced by: '<S26>/n-D Lookup Table'
   */
  { 2.4100000858306885, 2.3900001049041748, 2.2999999523162842 },

  /* Computed Parameter: nDLookupTable_bp01Data_hs
   * Referenced by: '<S26>/n-D Lookup Table'
   */
  { 278.14999389648438, 293.14999389648438, 323.14999389648438 },

  /* Computed Parameter: Gain_Gain_bi
   * Referenced by: '<S26>/Gain'
   */
  -0.00027777778450399637,

  /* Computed Parameter: nDLookupTable_tableData_b
   * Referenced by: '<S27>/n-D Lookup Table'
   */
  { 2.4100000858306885, 2.3900001049041748, 2.2999999523162842 },

  /* Computed Parameter: nDLookupTable_bp01Data_f4
   * Referenced by: '<S27>/n-D Lookup Table'
   */
  { 278.14999389648438, 293.14999389648438, 323.14999389648438 },

  /* Computed Parameter: Gain_Gain_ix
   * Referenced by: '<S27>/Gain'
   */
  -0.00027777778450399637,

  /* Computed Parameter: nDLookupTable_tableData_lf
   * Referenced by: '<S28>/n-D Lookup Table'
   */
  { 2.4100000858306885, 2.3900001049041748, 2.2999999523162842 },

  /* Computed Parameter: nDLookupTable_bp01Data_ky
   * Referenced by: '<S28>/n-D Lookup Table'
   */
  { 278.14999389648438, 293.14999389648438, 323.14999389648438 },

  /* Computed Parameter: Gain_Gain_dp
   * Referenced by: '<S28>/Gain'
   */
  -0.00027777778450399637,

  /* Computed Parameter: nDLookupTable_tableData_k
   * Referenced by: '<S29>/n-D Lookup Table'
   */
  { 2.4100000858306885, 2.3900001049041748, 2.2999999523162842 },

  /* Computed Parameter: nDLookupTable_bp01Data_ot
   * Referenced by: '<S29>/n-D Lookup Table'
   */
  { 278.14999389648438, 293.14999389648438, 323.14999389648438 },

  /* Computed Parameter: Gain_Gain_kc
   * Referenced by: '<S29>/Gain'
   */
  -0.00027777778450399637,

  /* Computed Parameter: nDLookupTable_tableData_o2
   * Referenced by: '<S30>/n-D Lookup Table'
   */
  { 2.4100000858306885, 2.3900001049041748, 2.2999999523162842 },

  /* Computed Parameter: nDLookupTable_bp01Data_bp
   * Referenced by: '<S30>/n-D Lookup Table'
   */
  { 278.14999389648438, 293.14999389648438, 323.14999389648438 },

  /* Computed Parameter: Gain_Gain_ek
   * Referenced by: '<S30>/Gain'
   */
  -0.00027777778450399637,

  /* Computed Parameter: nDLookupTable_tableData_n
   * Referenced by: '<S31>/n-D Lookup Table'
   */
  { 2.4100000858306885, 2.3900001049041748, 2.2999999523162842 },

  /* Computed Parameter: nDLookupTable_bp01Data_d
   * Referenced by: '<S31>/n-D Lookup Table'
   */
  { 278.14999389648438, 293.14999389648438, 323.14999389648438 },

  /* Computed Parameter: Gain_Gain_pp
   * Referenced by: '<S31>/Gain'
   */
  -0.00027777778450399637,

  /* Computed Parameter: nDLookupTable_tableData_bj
   * Referenced by: '<S32>/n-D Lookup Table'
   */
  { 2.4100000858306885, 2.3900001049041748, 2.2999999523162842 },

  /* Computed Parameter: nDLookupTable_bp01Data_iz
   * Referenced by: '<S32>/n-D Lookup Table'
   */
  { 278.14999389648438, 293.14999389648438, 323.14999389648438 },

  /* Computed Parameter: Gain_Gain_oh
   * Referenced by: '<S32>/Gain'
   */
  -0.00027777778450399637,

  /* Computed Parameter: nDLookupTable_tableData_oo
   * Referenced by: '<S33>/n-D Lookup Table'
   */
  { 2.4100000858306885, 2.3900001049041748, 2.2999999523162842 },

  /* Computed Parameter: nDLookupTable_bp01Data_ow
   * Referenced by: '<S33>/n-D Lookup Table'
   */
  { 278.14999389648438, 293.14999389648438, 323.14999389648438 },

  /* Computed Parameter: Gain_Gain_pe
   * Referenced by: '<S33>/Gain'
   */
  -0.00027777778450399637,

  /* Computed Parameter: nDLookupTable_tableData_aa
   * Referenced by: '<S34>/n-D Lookup Table'
   */
  { 2.4100000858306885, 2.3900001049041748, 2.2999999523162842 },

  /* Computed Parameter: nDLookupTable_bp01Data_ko
   * Referenced by: '<S34>/n-D Lookup Table'
   */
  { 278.14999389648438, 293.14999389648438, 323.14999389648438 },

  /* Computed Parameter: Gain_Gain_g
   * Referenced by: '<S34>/Gain'
   */
  -0.00027777778450399637,

  /* Computed Parameter: nDLookupTable_tableData_d
   * Referenced by: '<S35>/n-D Lookup Table'
   */
  { 2.4100000858306885, 2.3900001049041748, 2.2999999523162842 },

  /* Computed Parameter: nDLookupTable_bp01Data_lc
   * Referenced by: '<S35>/n-D Lookup Table'
   */
  { 278.14999389648438, 293.14999389648438, 323.14999389648438 },

  /* Computed Parameter: Gain_Gain_cn
   * Referenced by: '<S35>/Gain'
   */
  -0.00027777778450399637,

  /* Computed Parameter: nDLookupTable_tableData_f0
   * Referenced by: '<S36>/n-D Lookup Table'
   */
  { 2.4100000858306885, 2.3900001049041748, 2.2999999523162842 },

  /* Computed Parameter: nDLookupTable_bp01Data_mh
   * Referenced by: '<S36>/n-D Lookup Table'
   */
  { 278.14999389648438, 293.14999389648438, 323.14999389648438 },

  /* Computed Parameter: Gain_Gain_j
   * Referenced by: '<S36>/Gain'
   */
  -0.00027777778450399637,

  /* Computed Parameter: nDLookupTable_tableData_hk
   * Referenced by: '<S37>/n-D Lookup Table'
   */
  { 2.4100000858306885, 2.3900001049041748, 2.2999999523162842 },

  /* Computed Parameter: nDLookupTable_bp01Data_d4
   * Referenced by: '<S37>/n-D Lookup Table'
   */
  { 278.14999389648438, 293.14999389648438, 323.14999389648438 },

  /* Computed Parameter: Gain_Gain_oa
   * Referenced by: '<S37>/Gain'
   */
  -0.00027777778450399637
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
