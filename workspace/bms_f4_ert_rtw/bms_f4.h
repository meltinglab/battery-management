/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: bms_f4.h
 *
 * Code generated for Simulink model 'bms_f4'.
 *
 * Model version                  : 1.33
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Wed Jun  2 11:40:20 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_bms_f4_h_
#define RTW_HEADER_bms_f4_h_
#include <math.h>
#include <stddef.h>
#ifndef bms_f4_COMMON_INCLUDES_
#define bms_f4_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* bms_f4_COMMON_INCLUDES_ */

#include "bms_f4_types.h"
#include "MW_target_hardware_resources.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<S4>/Chart1' */
typedef struct {
  uint32_T temporalCounter_i1;         /* '<S4>/Chart1' */
  uint8_T is_active_c2_bms_f4;         /* '<S4>/Chart1' */
  uint8_T is_c2_bms_f4;                /* '<S4>/Chart1' */
  uint8_T is_ON;                       /* '<S4>/Chart1' */
  boolean_T flagBalancingDone;         /* '<S4>/Chart1' */
} DW_Chart1_bms_f4_T;

/* Block signals (default storage) */
typedef struct {
  real_T Selector[10];                 /* '<S4>/Selector' */
  real_T Selector1[10];                /* '<S4>/Selector1' */
  real_T Selector2[10];                /* '<S4>/Selector2' */
  real_T VectorConcatenate1[3];        /* '<S3>/Vector Concatenate1' */
  real_T VectorConcatenate[2];         /* '<S3>/Vector Concatenate' */
  real_T VectorConcatenate2[2];        /* '<S3>/Vector Concatenate2' */
  real_T VectorConcatenate3[2];        /* '<S3>/Vector Concatenate3' */
  real_T VectorConcatenate_k[3];       /* '<S4>/Vector Concatenate' */
  boolean_T MatrixConcatenate[30];     /* '<S4>/Matrix Concatenate' */
  real_T maxV;
  real_T maxV_m;
  real_T minV;
  real_T minV_c;
  real_T maxV_k;
  real_T maxV_c;
  real_T maxV_b;
  real_T Max3;                         /* '<S2>/Max3' */
  real_T Gain;                         /* '<S37>/Gain' */
  real_T Min3;                         /* '<S4>/Min3' */
  real_T Min4;                         /* '<S4>/Min4' */
  boolean_T VectorConcatenate1_a[3];   /* '<S4>/Vector Concatenate1' */
} B_bms_f4_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S17>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_a;/* '<S8>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTAT_au;/* '<S9>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_m;/* '<S10>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_b;/* '<S11>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_p;/* '<S12>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_c;/* '<S13>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTAT_mh;/* '<S14>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_g;/* '<S15>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTAT_g0;/* '<S16>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_d;/* '<S27>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTAT_b0;/* '<S18>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTAT_dc;/* '<S19>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_o;/* '<S20>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTAT_aw;/* '<S21>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_n;/* '<S22>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_e;/* '<S23>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_f;/* '<S24>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTAT_aj;/* '<S25>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTAT_bc;/* '<S26>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTAT_ps;/* '<S37>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTAT_ed;/* '<S28>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTAT_mg;/* '<S29>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTAT_fy;/* '<S30>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTAT_gd;/* '<S31>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_i;/* '<S32>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTAT_ce;/* '<S33>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTAT_p0;/* '<S34>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTAT_fb;/* '<S35>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTAT_d3;/* '<S36>/Discrete-Time Integrator' */
  uint32_T temporalCounter_i1;         /* '<S3>/Chart' */
  uint8_T is_c1_bms_f4;                /* '<S3>/Chart' */
  boolean_T isNotInit;                 /* '<S3>/Chart' */
  DW_Chart1_bms_f4_T sf_Chart3;        /* '<S4>/Chart3' */
  DW_Chart1_bms_f4_T sf_Chart2;        /* '<S4>/Chart2' */
  DW_Chart1_bms_f4_T sf_Chart1;        /* '<S4>/Chart1' */
} DW_bms_f4_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  BusInputBMS FromPlant;               /* '<Root>/FromPlant' */
  BusSimulationInput InputSimulationBus;/* '<Root>/InputSimulationBus' */
} ExtU_bms_f4_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  BusOutputBMS ToPlant;                /* '<Root>/ToPlant' */
} ExtY_bms_f4_T;

/* Parameters (default storage) */
struct P_bms_f4_T_ {
  real_T CellCurrentLimitThreshold_Fault;
                                    /* Variable: CellCurrentLimitThreshold_Fault
                                     * Referenced by: '<S39>/Constant'
                                     */
  real_T CellCurrentLimitThreshold_Warning;
                                  /* Variable: CellCurrentLimitThreshold_Warning
                                   * Referenced by: '<S38>/Constant'
                                   */
  real_T CellTemperatureLimitThreshold_Fault;
                                /* Variable: CellTemperatureLimitThreshold_Fault
                                 * Referenced by: '<S41>/Constant'
                                 */
  real_T CellTemperatureLimitThreshold_Warning;
                              /* Variable: CellTemperatureLimitThreshold_Warning
                               * Referenced by: '<S40>/Constant'
                               */
  real_T CellVoltageLimitHigh_Fault;   /* Variable: CellVoltageLimitHigh_Fault
                                        * Referenced by: '<S43>/Constant'
                                        */
  real_T CellVoltageLimitHigh_Warning; /* Variable: CellVoltageLimitHigh_Warning
                                        * Referenced by: '<S42>/Constant'
                                        */
  real_T CellVoltageLimitLow_Fault;    /* Variable: CellVoltageLimitLow_Fault
                                        * Referenced by: '<S45>/Constant'
                                        */
  real_T CellVoltageLimitLow_Warning;  /* Variable: CellVoltageLimitLow_Warning
                                        * Referenced by: '<S44>/Constant'
                                        */
  real_T DeltaVTargetMin;              /* Variable: DeltaVTargetMin
                                        * Referenced by:
                                        *   '<S4>/Chart1'
                                        *   '<S4>/Chart2'
                                        *   '<S4>/Chart3'
                                        */
  real_T DrivetrainEnDelay;            /* Variable: DrivetrainEnDelay
                                        * Referenced by: '<S3>/Chart'
                                        */
  real_T VbattMin;                     /* Variable: VbattMin
                                        * Referenced by: '<S3>/Chart'
                                        */
  real_T VbattThersholdChrg;           /* Variable: VbattThersholdChrg
                                        * Referenced by: '<S3>/Chart'
                                        */
  real_T VbattThresholdDis;            /* Variable: VbattThresholdDis
                                        * Referenced by: '<S3>/Chart'
                                        */
  real_T balancingRelaxationTime;      /* Variable: balancingRelaxationTime
                                        * Referenced by:
                                        *   '<S4>/Chart1'
                                        *   '<S4>/Chart2'
                                        *   '<S4>/Chart3'
                                        */
  real_T balancingTime;                /* Variable: balancingTime
                                        * Referenced by:
                                        *   '<S4>/Chart1'
                                        *   '<S4>/Chart2'
                                        *   '<S4>/Chart3'
                                        */
  real_T DiscreteTimeIntegrator_gainval;
                           /* Computed Parameter: DiscreteTimeIntegrator_gainval
                            * Referenced by: '<S17>/Discrete-Time Integrator'
                            */
  real_T DiscreteTimeIntegrator_IC;
                                /* Computed Parameter: DiscreteTimeIntegrator_IC
                                 * Referenced by: '<S17>/Discrete-Time Integrator'
                                 */
  real_T DiscreteTimeIntegrator_UpperSat;/* Expression: 1
                                          * Referenced by: '<S17>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_LowerSat;/* Expression: 0
                                          * Referenced by: '<S17>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_gainva_d;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainva_d
                           * Referenced by: '<S8>/Discrete-Time Integrator'
                           */
  real_T DiscreteTimeIntegrator_IC_h;
                              /* Computed Parameter: DiscreteTimeIntegrator_IC_h
                               * Referenced by: '<S8>/Discrete-Time Integrator'
                               */
  real_T DiscreteTimeIntegrator_UpperS_n;/* Expression: 1
                                          * Referenced by: '<S8>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_LowerS_e;/* Expression: 0
                                          * Referenced by: '<S8>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_gainva_o;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainva_o
                           * Referenced by: '<S9>/Discrete-Time Integrator'
                           */
  real_T DiscreteTimeIntegrator_IC_d;
                              /* Computed Parameter: DiscreteTimeIntegrator_IC_d
                               * Referenced by: '<S9>/Discrete-Time Integrator'
                               */
  real_T DiscreteTimeIntegrator_UpperS_m;/* Expression: 1
                                          * Referenced by: '<S9>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_LowerS_l;/* Expression: 0
                                          * Referenced by: '<S9>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_gainva_m;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainva_m
                           * Referenced by: '<S10>/Discrete-Time Integrator'
                           */
  real_T DiscreteTimeIntegrator_IC_m;
                              /* Computed Parameter: DiscreteTimeIntegrator_IC_m
                               * Referenced by: '<S10>/Discrete-Time Integrator'
                               */
  real_T DiscreteTimeIntegrator_Upper_mg;/* Expression: 1
                                          * Referenced by: '<S10>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_Lower_lh;/* Expression: 0
                                          * Referenced by: '<S10>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_gainv_do;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainv_do
                           * Referenced by: '<S11>/Discrete-Time Integrator'
                           */
  real_T DiscreteTimeIntegrator_IC_l;
                              /* Computed Parameter: DiscreteTimeIntegrator_IC_l
                               * Referenced by: '<S11>/Discrete-Time Integrator'
                               */
  real_T DiscreteTimeIntegrator_Upper_nt;/* Expression: 1
                                          * Referenced by: '<S11>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_LowerS_c;/* Expression: 0
                                          * Referenced by: '<S11>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_gainv_mu;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainv_mu
                           * Referenced by: '<S12>/Discrete-Time Integrator'
                           */
  real_T DiscreteTimeIntegrator_IC_p;
                              /* Computed Parameter: DiscreteTimeIntegrator_IC_p
                               * Referenced by: '<S12>/Discrete-Time Integrator'
                               */
  real_T DiscreteTimeIntegrator_UpperS_i;/* Expression: 1
                                          * Referenced by: '<S12>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_LowerS_p;/* Expression: 0
                                          * Referenced by: '<S12>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_gainva_i;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainva_i
                           * Referenced by: '<S13>/Discrete-Time Integrator'
                           */
  real_T DiscreteTimeIntegrator_IC_o;
                              /* Computed Parameter: DiscreteTimeIntegrator_IC_o
                               * Referenced by: '<S13>/Discrete-Time Integrator'
                               */
  real_T DiscreteTimeIntegrator_UpperS_e;/* Expression: 1
                                          * Referenced by: '<S13>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_LowerS_h;/* Expression: 0
                                          * Referenced by: '<S13>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_gainva_l;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainva_l
                           * Referenced by: '<S14>/Discrete-Time Integrator'
                           */
  real_T DiscreteTimeIntegrator_IC_m3;
                             /* Computed Parameter: DiscreteTimeIntegrator_IC_m3
                              * Referenced by: '<S14>/Discrete-Time Integrator'
                              */
  real_T DiscreteTimeIntegrator_UpperS_f;/* Expression: 1
                                          * Referenced by: '<S14>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_LowerS_f;/* Expression: 0
                                          * Referenced by: '<S14>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_gainv_oo;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainv_oo
                           * Referenced by: '<S15>/Discrete-Time Integrator'
                           */
  real_T DiscreteTimeIntegrator_IC_e;
                              /* Computed Parameter: DiscreteTimeIntegrator_IC_e
                               * Referenced by: '<S15>/Discrete-Time Integrator'
                               */
  real_T DiscreteTimeIntegrator_UpperS_g;/* Expression: 1
                                          * Referenced by: '<S15>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_LowerS_o;/* Expression: 0
                                          * Referenced by: '<S15>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_gainva_p;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainva_p
                           * Referenced by: '<S16>/Discrete-Time Integrator'
                           */
  real_T DiscreteTimeIntegrator_IC_ou;
                             /* Computed Parameter: DiscreteTimeIntegrator_IC_ou
                              * Referenced by: '<S16>/Discrete-Time Integrator'
                              */
  real_T DiscreteTimeIntegrator_UpperS_j;/* Expression: 1
                                          * Referenced by: '<S16>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_LowerS_g;/* Expression: 0
                                          * Referenced by: '<S16>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_gainva_k;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainva_k
                           * Referenced by: '<S27>/Discrete-Time Integrator'
                           */
  real_T DiscreteTimeIntegrator_IC_b;
                              /* Computed Parameter: DiscreteTimeIntegrator_IC_b
                               * Referenced by: '<S27>/Discrete-Time Integrator'
                               */
  real_T DiscreteTimeIntegrator_Upper_jp;/* Expression: 1
                                          * Referenced by: '<S27>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_Lower_ge;/* Expression: 0
                                          * Referenced by: '<S27>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_gainv_ks;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainv_ks
                           * Referenced by: '<S18>/Discrete-Time Integrator'
                           */
  real_T DiscreteTimeIntegrator_IC_dx;
                             /* Computed Parameter: DiscreteTimeIntegrator_IC_dx
                              * Referenced by: '<S18>/Discrete-Time Integrator'
                              */
  real_T DiscreteTimeIntegrator_Upper_g2;/* Expression: 1
                                          * Referenced by: '<S18>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_LowerS_k;/* Expression: 0
                                          * Referenced by: '<S18>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_gainva_c;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainva_c
                           * Referenced by: '<S19>/Discrete-Time Integrator'
                           */
  real_T DiscreteTimeIntegrator_IC_lq;
                             /* Computed Parameter: DiscreteTimeIntegrator_IC_lq
                              * Referenced by: '<S19>/Discrete-Time Integrator'
                              */
  real_T DiscreteTimeIntegrator_Upper_gd;/* Expression: 1
                                          * Referenced by: '<S19>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_Lower_c5;/* Expression: 0
                                          * Referenced by: '<S19>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_gainva_a;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainva_a
                           * Referenced by: '<S20>/Discrete-Time Integrator'
                           */
  real_T DiscreteTimeIntegrator_IC_oq;
                             /* Computed Parameter: DiscreteTimeIntegrator_IC_oq
                              * Referenced by: '<S20>/Discrete-Time Integrator'
                              */
  real_T DiscreteTimeIntegrator_UpperS_b;/* Expression: 1
                                          * Referenced by: '<S20>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_LowerS_b;/* Expression: 0
                                          * Referenced by: '<S20>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_gainva_n;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainva_n
                           * Referenced by: '<S21>/Discrete-Time Integrator'
                           */
  real_T DiscreteTimeIntegrator_IC_dk;
                             /* Computed Parameter: DiscreteTimeIntegrator_IC_dk
                              * Referenced by: '<S21>/Discrete-Time Integrator'
                              */
  real_T DiscreteTimeIntegrator_Upper_f5;/* Expression: 1
                                          * Referenced by: '<S21>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_Lower_pb;/* Expression: 0
                                          * Referenced by: '<S21>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_gainv_co;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainv_co
                           * Referenced by: '<S22>/Discrete-Time Integrator'
                           */
  real_T DiscreteTimeIntegrator_IC_on;
                             /* Computed Parameter: DiscreteTimeIntegrator_IC_on
                              * Referenced by: '<S22>/Discrete-Time Integrator'
                              */
  real_T DiscreteTimeIntegrator_Upper_i0;/* Expression: 1
                                          * Referenced by: '<S22>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_Lower_gd;/* Expression: 0
                                          * Referenced by: '<S22>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_gainva_f;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainva_f
                           * Referenced by: '<S23>/Discrete-Time Integrator'
                           */
  real_T DiscreteTimeIntegrator_IC_c;
                              /* Computed Parameter: DiscreteTimeIntegrator_IC_c
                               * Referenced by: '<S23>/Discrete-Time Integrator'
                               */
  real_T DiscreteTimeIntegrator_UpperS_h;/* Expression: 1
                                          * Referenced by: '<S23>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_Lower_hb;/* Expression: 0
                                          * Referenced by: '<S23>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_gainv_cu;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainv_cu
                           * Referenced by: '<S24>/Discrete-Time Integrator'
                           */
  real_T DiscreteTimeIntegrator_IC_lt;
                             /* Computed Parameter: DiscreteTimeIntegrator_IC_lt
                              * Referenced by: '<S24>/Discrete-Time Integrator'
                              */
  real_T DiscreteTimeIntegrator_Upper_e1;/* Expression: 1
                                          * Referenced by: '<S24>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_Lower_pz;/* Expression: 0
                                          * Referenced by: '<S24>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_gainva_e;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainva_e
                           * Referenced by: '<S25>/Discrete-Time Integrator'
                           */
  real_T DiscreteTimeIntegrator_IC_k;
                              /* Computed Parameter: DiscreteTimeIntegrator_IC_k
                               * Referenced by: '<S25>/Discrete-Time Integrator'
                               */
  real_T DiscreteTimeIntegrator_Upper_g4;/* Expression: 1
                                          * Referenced by: '<S25>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_LowerS_m;/* Expression: 0
                                          * Referenced by: '<S25>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_gainv_pk;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainv_pk
                           * Referenced by: '<S26>/Discrete-Time Integrator'
                           */
  real_T DiscreteTimeIntegrator_IC_dc;
                             /* Computed Parameter: DiscreteTimeIntegrator_IC_dc
                              * Referenced by: '<S26>/Discrete-Time Integrator'
                              */
  real_T DiscreteTimeIntegrator_UpperS_o;/* Expression: 1
                                          * Referenced by: '<S26>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_Lower_k0;/* Expression: 0
                                          * Referenced by: '<S26>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_gainv_nb;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainv_nb
                           * Referenced by: '<S37>/Discrete-Time Integrator'
                           */
  real_T DiscreteTimeIntegrator_IC_j;
                              /* Computed Parameter: DiscreteTimeIntegrator_IC_j
                               * Referenced by: '<S37>/Discrete-Time Integrator'
                               */
  real_T DiscreteTimeIntegrator_UpperS_p;/* Expression: 1
                                          * Referenced by: '<S37>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_LowerS_a;/* Expression: 0
                                          * Referenced by: '<S37>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_gainv_a5;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainv_a5
                           * Referenced by: '<S28>/Discrete-Time Integrator'
                           */
  real_T DiscreteTimeIntegrator_IC_hw;
                             /* Computed Parameter: DiscreteTimeIntegrator_IC_hw
                              * Referenced by: '<S28>/Discrete-Time Integrator'
                              */
  real_T DiscreteTimeIntegrator_UpperS_c;/* Expression: 1
                                          * Referenced by: '<S28>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_Lower_ae;/* Expression: 0
                                          * Referenced by: '<S28>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_gainv_md;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainv_md
                           * Referenced by: '<S29>/Discrete-Time Integrator'
                           */
  real_T DiscreteTimeIntegrator_IC_dv;
                             /* Computed Parameter: DiscreteTimeIntegrator_IC_dv
                              * Referenced by: '<S29>/Discrete-Time Integrator'
                              */
  real_T DiscreteTimeIntegrator_UpperS_d;/* Expression: 1
                                          * Referenced by: '<S29>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_LowerS_d;/* Expression: 0
                                          * Referenced by: '<S29>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_gainv_lm;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainv_lm
                           * Referenced by: '<S30>/Discrete-Time Integrator'
                           */
  real_T DiscreteTimeIntegrator_IC_l1;
                             /* Computed Parameter: DiscreteTimeIntegrator_IC_l1
                              * Referenced by: '<S30>/Discrete-Time Integrator'
                              */
  real_T DiscreteTimeIntegrator_Upper_eg;/* Expression: 1
                                          * Referenced by: '<S30>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_Lower_do;/* Expression: 0
                                          * Referenced by: '<S30>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_gainv_ae;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainv_ae
                           * Referenced by: '<S31>/Discrete-Time Integrator'
                           */
  real_T DiscreteTimeIntegrator_IC_i;
                              /* Computed Parameter: DiscreteTimeIntegrator_IC_i
                               * Referenced by: '<S31>/Discrete-Time Integrator'
                               */
  real_T DiscreteTimeIntegrator_Upper_hx;/* Expression: 1
                                          * Referenced by: '<S31>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_Lower_em;/* Expression: 0
                                          * Referenced by: '<S31>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_gainv_lx;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainv_lx
                           * Referenced by: '<S32>/Discrete-Time Integrator'
                           */
  real_T DiscreteTimeIntegrator_IC_f;
                              /* Computed Parameter: DiscreteTimeIntegrator_IC_f
                               * Referenced by: '<S32>/Discrete-Time Integrator'
                               */
  real_T DiscreteTimeIntegrator_Upper_ng;/* Expression: 1
                                          * Referenced by: '<S32>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_Lower_oi;/* Expression: 0
                                          * Referenced by: '<S32>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_gain_pkl;
                          /* Computed Parameter: DiscreteTimeIntegrator_gain_pkl
                           * Referenced by: '<S33>/Discrete-Time Integrator'
                           */
  real_T DiscreteTimeIntegrator_IC_ln;
                             /* Computed Parameter: DiscreteTimeIntegrator_IC_ln
                              * Referenced by: '<S33>/Discrete-Time Integrator'
                              */
  real_T DiscreteTimeIntegrator_Upper_ei;/* Expression: 1
                                          * Referenced by: '<S33>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_LowerS_i;/* Expression: 0
                                          * Referenced by: '<S33>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_gain_lxl;
                          /* Computed Parameter: DiscreteTimeIntegrator_gain_lxl
                           * Referenced by: '<S34>/Discrete-Time Integrator'
                           */
  real_T DiscreteTimeIntegrator_IC_mf;
                             /* Computed Parameter: DiscreteTimeIntegrator_IC_mf
                              * Referenced by: '<S34>/Discrete-Time Integrator'
                              */
  real_T DiscreteTimeIntegrator_Upper_cc;/* Expression: 1
                                          * Referenced by: '<S34>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_Lower_cp;/* Expression: 0
                                          * Referenced by: '<S34>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_gainv_ea;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainv_ea
                           * Referenced by: '<S35>/Discrete-Time Integrator'
                           */
  real_T DiscreteTimeIntegrator_IC_mz;
                             /* Computed Parameter: DiscreteTimeIntegrator_IC_mz
                              * Referenced by: '<S35>/Discrete-Time Integrator'
                              */
  real_T DiscreteTimeIntegrator_Upper_jh;/* Expression: 1
                                          * Referenced by: '<S35>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_Lower_ig;/* Expression: 0
                                          * Referenced by: '<S35>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_gainv_ol;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainv_ol
                           * Referenced by: '<S36>/Discrete-Time Integrator'
                           */
  real_T DiscreteTimeIntegrator_IC_m1;
                             /* Computed Parameter: DiscreteTimeIntegrator_IC_m1
                              * Referenced by: '<S36>/Discrete-Time Integrator'
                              */
  real_T DiscreteTimeIntegrator_Upper_m0;/* Expression: 1
                                          * Referenced by: '<S36>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_Lower_ou;/* Expression: 0
                                          * Referenced by: '<S36>/Discrete-Time Integrator'
                                          */
  real_T nDLookupTable_tableData[3];
                                  /* Computed Parameter: nDLookupTable_tableData
                                   * Referenced by: '<S8>/n-D Lookup Table'
                                   */
  real_T nDLookupTable_bp01Data[3];/* Computed Parameter: nDLookupTable_bp01Data
                                    * Referenced by: '<S8>/n-D Lookup Table'
                                    */
  real_T Gain_Gain;                    /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S8>/Gain'
                                        */
  real_T nDLookupTable_tableData_f[3];
                                /* Computed Parameter: nDLookupTable_tableData_f
                                 * Referenced by: '<S9>/n-D Lookup Table'
                                 */
  real_T nDLookupTable_bp01Data_o[3];
                                 /* Computed Parameter: nDLookupTable_bp01Data_o
                                  * Referenced by: '<S9>/n-D Lookup Table'
                                  */
  real_T Gain_Gain_f;                  /* Computed Parameter: Gain_Gain_f
                                        * Referenced by: '<S9>/Gain'
                                        */
  real_T nDLookupTable_tableData_e[3];
                                /* Computed Parameter: nDLookupTable_tableData_e
                                 * Referenced by: '<S10>/n-D Lookup Table'
                                 */
  real_T nDLookupTable_bp01Data_m[3];
                                 /* Computed Parameter: nDLookupTable_bp01Data_m
                                  * Referenced by: '<S10>/n-D Lookup Table'
                                  */
  real_T Gain_Gain_m;                  /* Computed Parameter: Gain_Gain_m
                                        * Referenced by: '<S10>/Gain'
                                        */
  real_T nDLookupTable_tableData_a[3];
                                /* Computed Parameter: nDLookupTable_tableData_a
                                 * Referenced by: '<S11>/n-D Lookup Table'
                                 */
  real_T nDLookupTable_bp01Data_c[3];
                                 /* Computed Parameter: nDLookupTable_bp01Data_c
                                  * Referenced by: '<S11>/n-D Lookup Table'
                                  */
  real_T Gain_Gain_fa;                 /* Computed Parameter: Gain_Gain_fa
                                        * Referenced by: '<S11>/Gain'
                                        */
  real_T nDLookupTable_tableData_h[3];
                                /* Computed Parameter: nDLookupTable_tableData_h
                                 * Referenced by: '<S12>/n-D Lookup Table'
                                 */
  real_T nDLookupTable_bp01Data_h[3];
                                 /* Computed Parameter: nDLookupTable_bp01Data_h
                                  * Referenced by: '<S12>/n-D Lookup Table'
                                  */
  real_T Gain_Gain_l;                  /* Computed Parameter: Gain_Gain_l
                                        * Referenced by: '<S12>/Gain'
                                        */
  real_T nDLookupTable_tableData_m[3];
                                /* Computed Parameter: nDLookupTable_tableData_m
                                 * Referenced by: '<S13>/n-D Lookup Table'
                                 */
  real_T nDLookupTable_bp01Data_g[3];
                                 /* Computed Parameter: nDLookupTable_bp01Data_g
                                  * Referenced by: '<S13>/n-D Lookup Table'
                                  */
  real_T Gain_Gain_c;                  /* Computed Parameter: Gain_Gain_c
                                        * Referenced by: '<S13>/Gain'
                                        */
  real_T nDLookupTable_tableData_j[3];
                                /* Computed Parameter: nDLookupTable_tableData_j
                                 * Referenced by: '<S14>/n-D Lookup Table'
                                 */
  real_T nDLookupTable_bp01Data_gg[3];
                                /* Computed Parameter: nDLookupTable_bp01Data_gg
                                 * Referenced by: '<S14>/n-D Lookup Table'
                                 */
  real_T Gain_Gain_n;                  /* Computed Parameter: Gain_Gain_n
                                        * Referenced by: '<S14>/Gain'
                                        */
  real_T nDLookupTable_tableData_i[3];
                                /* Computed Parameter: nDLookupTable_tableData_i
                                 * Referenced by: '<S15>/n-D Lookup Table'
                                 */
  real_T nDLookupTable_bp01Data_p[3];
                                 /* Computed Parameter: nDLookupTable_bp01Data_p
                                  * Referenced by: '<S15>/n-D Lookup Table'
                                  */
  real_T Gain_Gain_o;                  /* Computed Parameter: Gain_Gain_o
                                        * Referenced by: '<S15>/Gain'
                                        */
  real_T nDLookupTable_tableData_fr[3];
                               /* Computed Parameter: nDLookupTable_tableData_fr
                                * Referenced by: '<S16>/n-D Lookup Table'
                                */
  real_T nDLookupTable_bp01Data_j[3];
                                 /* Computed Parameter: nDLookupTable_bp01Data_j
                                  * Referenced by: '<S16>/n-D Lookup Table'
                                  */
  real_T Gain_Gain_la;                 /* Computed Parameter: Gain_Gain_la
                                        * Referenced by: '<S16>/Gain'
                                        */
  real_T nDLookupTable_tableData_g[3];
                                /* Computed Parameter: nDLookupTable_tableData_g
                                 * Referenced by: '<S17>/n-D Lookup Table'
                                 */
  real_T nDLookupTable_bp01Data_k[3];
                                 /* Computed Parameter: nDLookupTable_bp01Data_k
                                  * Referenced by: '<S17>/n-D Lookup Table'
                                  */
  real_T Gain_Gain_c4;                 /* Computed Parameter: Gain_Gain_c4
                                        * Referenced by: '<S17>/Gain'
                                        */
  real_T nDLookupTable_tableData_l[3];
                                /* Computed Parameter: nDLookupTable_tableData_l
                                 * Referenced by: '<S18>/n-D Lookup Table'
                                 */
  real_T nDLookupTable_bp01Data_i[3];
                                 /* Computed Parameter: nDLookupTable_bp01Data_i
                                  * Referenced by: '<S18>/n-D Lookup Table'
                                  */
  real_T Gain_Gain_p;                  /* Computed Parameter: Gain_Gain_p
                                        * Referenced by: '<S18>/Gain'
                                        */
  real_T nDLookupTable_tableData_md[3];
                               /* Computed Parameter: nDLookupTable_tableData_md
                                * Referenced by: '<S19>/n-D Lookup Table'
                                */
  real_T nDLookupTable_bp01Data_pr[3];
                                /* Computed Parameter: nDLookupTable_bp01Data_pr
                                 * Referenced by: '<S19>/n-D Lookup Table'
                                 */
  real_T Gain_Gain_d;                  /* Computed Parameter: Gain_Gain_d
                                        * Referenced by: '<S19>/Gain'
                                        */
  real_T nDLookupTable_tableData_aj[3];
                               /* Computed Parameter: nDLookupTable_tableData_aj
                                * Referenced by: '<S20>/n-D Lookup Table'
                                */
  real_T nDLookupTable_bp01Data_ch[3];
                                /* Computed Parameter: nDLookupTable_bp01Data_ch
                                 * Referenced by: '<S20>/n-D Lookup Table'
                                 */
  real_T Gain_Gain_e;                  /* Computed Parameter: Gain_Gain_e
                                        * Referenced by: '<S20>/Gain'
                                        */
  real_T nDLookupTable_tableData_p[3];
                                /* Computed Parameter: nDLookupTable_tableData_p
                                 * Referenced by: '<S21>/n-D Lookup Table'
                                 */
  real_T nDLookupTable_bp01Data_l[3];
                                 /* Computed Parameter: nDLookupTable_bp01Data_l
                                  * Referenced by: '<S21>/n-D Lookup Table'
                                  */
  real_T Gain_Gain_i;                  /* Computed Parameter: Gain_Gain_i
                                        * Referenced by: '<S21>/Gain'
                                        */
  real_T nDLookupTable_tableData_mk[3];
                               /* Computed Parameter: nDLookupTable_tableData_mk
                                * Referenced by: '<S22>/n-D Lookup Table'
                                */
  real_T nDLookupTable_bp01Data_gb[3];
                                /* Computed Parameter: nDLookupTable_bp01Data_gb
                                 * Referenced by: '<S22>/n-D Lookup Table'
                                 */
  real_T Gain_Gain_fu;                 /* Computed Parameter: Gain_Gain_fu
                                        * Referenced by: '<S22>/Gain'
                                        */
  real_T nDLookupTable_tableData_o[3];
                                /* Computed Parameter: nDLookupTable_tableData_o
                                 * Referenced by: '<S23>/n-D Lookup Table'
                                 */
  real_T nDLookupTable_bp01Data_ll[3];
                                /* Computed Parameter: nDLookupTable_bp01Data_ll
                                 * Referenced by: '<S23>/n-D Lookup Table'
                                 */
  real_T Gain_Gain_b;                  /* Computed Parameter: Gain_Gain_b
                                        * Referenced by: '<S23>/Gain'
                                        */
  real_T nDLookupTable_tableData_o3[3];
                               /* Computed Parameter: nDLookupTable_tableData_o3
                                * Referenced by: '<S24>/n-D Lookup Table'
                                */
  real_T nDLookupTable_bp01Data_b[3];
                                 /* Computed Parameter: nDLookupTable_bp01Data_b
                                  * Referenced by: '<S24>/n-D Lookup Table'
                                  */
  real_T Gain_Gain_k;                  /* Computed Parameter: Gain_Gain_k
                                        * Referenced by: '<S24>/Gain'
                                        */
  real_T nDLookupTable_tableData_pv[3];
                               /* Computed Parameter: nDLookupTable_tableData_pv
                                * Referenced by: '<S25>/n-D Lookup Table'
                                */
  real_T nDLookupTable_bp01Data_f[3];
                                 /* Computed Parameter: nDLookupTable_bp01Data_f
                                  * Referenced by: '<S25>/n-D Lookup Table'
                                  */
  real_T Gain_Gain_bj;                 /* Computed Parameter: Gain_Gain_bj
                                        * Referenced by: '<S25>/Gain'
                                        */
  real_T nDLookupTable_tableData_mx[3];
                               /* Computed Parameter: nDLookupTable_tableData_mx
                                * Referenced by: '<S26>/n-D Lookup Table'
                                */
  real_T nDLookupTable_bp01Data_hs[3];
                                /* Computed Parameter: nDLookupTable_bp01Data_hs
                                 * Referenced by: '<S26>/n-D Lookup Table'
                                 */
  real_T Gain_Gain_bi;                 /* Computed Parameter: Gain_Gain_bi
                                        * Referenced by: '<S26>/Gain'
                                        */
  real_T nDLookupTable_tableData_b[3];
                                /* Computed Parameter: nDLookupTable_tableData_b
                                 * Referenced by: '<S27>/n-D Lookup Table'
                                 */
  real_T nDLookupTable_bp01Data_f4[3];
                                /* Computed Parameter: nDLookupTable_bp01Data_f4
                                 * Referenced by: '<S27>/n-D Lookup Table'
                                 */
  real_T Gain_Gain_ix;                 /* Computed Parameter: Gain_Gain_ix
                                        * Referenced by: '<S27>/Gain'
                                        */
  real_T nDLookupTable_tableData_lf[3];
                               /* Computed Parameter: nDLookupTable_tableData_lf
                                * Referenced by: '<S28>/n-D Lookup Table'
                                */
  real_T nDLookupTable_bp01Data_ky[3];
                                /* Computed Parameter: nDLookupTable_bp01Data_ky
                                 * Referenced by: '<S28>/n-D Lookup Table'
                                 */
  real_T Gain_Gain_dp;                 /* Computed Parameter: Gain_Gain_dp
                                        * Referenced by: '<S28>/Gain'
                                        */
  real_T nDLookupTable_tableData_k[3];
                                /* Computed Parameter: nDLookupTable_tableData_k
                                 * Referenced by: '<S29>/n-D Lookup Table'
                                 */
  real_T nDLookupTable_bp01Data_ot[3];
                                /* Computed Parameter: nDLookupTable_bp01Data_ot
                                 * Referenced by: '<S29>/n-D Lookup Table'
                                 */
  real_T Gain_Gain_kc;                 /* Computed Parameter: Gain_Gain_kc
                                        * Referenced by: '<S29>/Gain'
                                        */
  real_T nDLookupTable_tableData_o2[3];
                               /* Computed Parameter: nDLookupTable_tableData_o2
                                * Referenced by: '<S30>/n-D Lookup Table'
                                */
  real_T nDLookupTable_bp01Data_bp[3];
                                /* Computed Parameter: nDLookupTable_bp01Data_bp
                                 * Referenced by: '<S30>/n-D Lookup Table'
                                 */
  real_T Gain_Gain_ek;                 /* Computed Parameter: Gain_Gain_ek
                                        * Referenced by: '<S30>/Gain'
                                        */
  real_T nDLookupTable_tableData_n[3];
                                /* Computed Parameter: nDLookupTable_tableData_n
                                 * Referenced by: '<S31>/n-D Lookup Table'
                                 */
  real_T nDLookupTable_bp01Data_d[3];
                                 /* Computed Parameter: nDLookupTable_bp01Data_d
                                  * Referenced by: '<S31>/n-D Lookup Table'
                                  */
  real_T Gain_Gain_pp;                 /* Computed Parameter: Gain_Gain_pp
                                        * Referenced by: '<S31>/Gain'
                                        */
  real_T nDLookupTable_tableData_bj[3];
                               /* Computed Parameter: nDLookupTable_tableData_bj
                                * Referenced by: '<S32>/n-D Lookup Table'
                                */
  real_T nDLookupTable_bp01Data_iz[3];
                                /* Computed Parameter: nDLookupTable_bp01Data_iz
                                 * Referenced by: '<S32>/n-D Lookup Table'
                                 */
  real_T Gain_Gain_oh;                 /* Computed Parameter: Gain_Gain_oh
                                        * Referenced by: '<S32>/Gain'
                                        */
  real_T nDLookupTable_tableData_oo[3];
                               /* Computed Parameter: nDLookupTable_tableData_oo
                                * Referenced by: '<S33>/n-D Lookup Table'
                                */
  real_T nDLookupTable_bp01Data_ow[3];
                                /* Computed Parameter: nDLookupTable_bp01Data_ow
                                 * Referenced by: '<S33>/n-D Lookup Table'
                                 */
  real_T Gain_Gain_pe;                 /* Computed Parameter: Gain_Gain_pe
                                        * Referenced by: '<S33>/Gain'
                                        */
  real_T nDLookupTable_tableData_aa[3];
                               /* Computed Parameter: nDLookupTable_tableData_aa
                                * Referenced by: '<S34>/n-D Lookup Table'
                                */
  real_T nDLookupTable_bp01Data_ko[3];
                                /* Computed Parameter: nDLookupTable_bp01Data_ko
                                 * Referenced by: '<S34>/n-D Lookup Table'
                                 */
  real_T Gain_Gain_g;                  /* Computed Parameter: Gain_Gain_g
                                        * Referenced by: '<S34>/Gain'
                                        */
  real_T nDLookupTable_tableData_d[3];
                                /* Computed Parameter: nDLookupTable_tableData_d
                                 * Referenced by: '<S35>/n-D Lookup Table'
                                 */
  real_T nDLookupTable_bp01Data_lc[3];
                                /* Computed Parameter: nDLookupTable_bp01Data_lc
                                 * Referenced by: '<S35>/n-D Lookup Table'
                                 */
  real_T Gain_Gain_cn;                 /* Computed Parameter: Gain_Gain_cn
                                        * Referenced by: '<S35>/Gain'
                                        */
  real_T nDLookupTable_tableData_f0[3];
                               /* Computed Parameter: nDLookupTable_tableData_f0
                                * Referenced by: '<S36>/n-D Lookup Table'
                                */
  real_T nDLookupTable_bp01Data_mh[3];
                                /* Computed Parameter: nDLookupTable_bp01Data_mh
                                 * Referenced by: '<S36>/n-D Lookup Table'
                                 */
  real_T Gain_Gain_j;                  /* Computed Parameter: Gain_Gain_j
                                        * Referenced by: '<S36>/Gain'
                                        */
  real_T nDLookupTable_tableData_hk[3];
                               /* Computed Parameter: nDLookupTable_tableData_hk
                                * Referenced by: '<S37>/n-D Lookup Table'
                                */
  real_T nDLookupTable_bp01Data_d4[3];
                                /* Computed Parameter: nDLookupTable_bp01Data_d4
                                 * Referenced by: '<S37>/n-D Lookup Table'
                                 */
  real_T Gain_Gain_oa;                 /* Computed Parameter: Gain_Gain_oa
                                        * Referenced by: '<S37>/Gain'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_bms_f4_T {
  const char_T *errorStatus;
};

/* Block parameters (default storage) */
extern P_bms_f4_T bms_f4_P;

/* Block signals (default storage) */
extern B_bms_f4_T bms_f4_B;

/* Block states (default storage) */
extern DW_bms_f4_T bms_f4_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_bms_f4_T bms_f4_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_bms_f4_T bms_f4_Y;

/* Model entry point functions */
extern void bms_f4_initialize(void);
extern void bms_f4_step(void);
extern void bms_f4_terminate(void);

/* Real-time Model object */
extern RT_MODEL_bms_f4_T *const bms_f4_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/Selector3' : Unused code path elimination
 * Block '<S1>/Selector6' : Unused code path elimination
 * Block '<S1>/Selector9' : Unused code path elimination
 * Block '<S3>/Data Type  Conversion' : Eliminate redundant data type conversion
 * Block '<S3>/Data Type  Conversion1' : Eliminate redundant data type conversion
 * Block '<S3>/Data Type  Conversion2' : Eliminate redundant data type conversion
 * Block '<S3>/Data Type  Conversion3' : Eliminate redundant data type conversion
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'bms_f4'
 * '<S1>'   : 'bms_f4/PackSOC'
 * '<S2>'   : 'bms_f4/Subsystem'
 * '<S3>'   : 'bms_f4/Subsystem Reference'
 * '<S4>'   : 'bms_f4/Subsystem Reference1'
 * '<S5>'   : 'bms_f4/PackSOC/Subsystem'
 * '<S6>'   : 'bms_f4/PackSOC/Subsystem1'
 * '<S7>'   : 'bms_f4/PackSOC/Subsystem2'
 * '<S8>'   : 'bms_f4/PackSOC/Subsystem/Subsystem Reference1'
 * '<S9>'   : 'bms_f4/PackSOC/Subsystem/Subsystem Reference2'
 * '<S10>'  : 'bms_f4/PackSOC/Subsystem/Subsystem Reference24'
 * '<S11>'  : 'bms_f4/PackSOC/Subsystem/Subsystem Reference25'
 * '<S12>'  : 'bms_f4/PackSOC/Subsystem/Subsystem Reference26'
 * '<S13>'  : 'bms_f4/PackSOC/Subsystem/Subsystem Reference27'
 * '<S14>'  : 'bms_f4/PackSOC/Subsystem/Subsystem Reference28'
 * '<S15>'  : 'bms_f4/PackSOC/Subsystem/Subsystem Reference29'
 * '<S16>'  : 'bms_f4/PackSOC/Subsystem/Subsystem Reference30'
 * '<S17>'  : 'bms_f4/PackSOC/Subsystem/Subsystem Reference43'
 * '<S18>'  : 'bms_f4/PackSOC/Subsystem1/Subsystem Reference1'
 * '<S19>'  : 'bms_f4/PackSOC/Subsystem1/Subsystem Reference2'
 * '<S20>'  : 'bms_f4/PackSOC/Subsystem1/Subsystem Reference24'
 * '<S21>'  : 'bms_f4/PackSOC/Subsystem1/Subsystem Reference25'
 * '<S22>'  : 'bms_f4/PackSOC/Subsystem1/Subsystem Reference26'
 * '<S23>'  : 'bms_f4/PackSOC/Subsystem1/Subsystem Reference27'
 * '<S24>'  : 'bms_f4/PackSOC/Subsystem1/Subsystem Reference28'
 * '<S25>'  : 'bms_f4/PackSOC/Subsystem1/Subsystem Reference29'
 * '<S26>'  : 'bms_f4/PackSOC/Subsystem1/Subsystem Reference30'
 * '<S27>'  : 'bms_f4/PackSOC/Subsystem1/Subsystem Reference43'
 * '<S28>'  : 'bms_f4/PackSOC/Subsystem2/Subsystem Reference1'
 * '<S29>'  : 'bms_f4/PackSOC/Subsystem2/Subsystem Reference2'
 * '<S30>'  : 'bms_f4/PackSOC/Subsystem2/Subsystem Reference24'
 * '<S31>'  : 'bms_f4/PackSOC/Subsystem2/Subsystem Reference25'
 * '<S32>'  : 'bms_f4/PackSOC/Subsystem2/Subsystem Reference26'
 * '<S33>'  : 'bms_f4/PackSOC/Subsystem2/Subsystem Reference27'
 * '<S34>'  : 'bms_f4/PackSOC/Subsystem2/Subsystem Reference28'
 * '<S35>'  : 'bms_f4/PackSOC/Subsystem2/Subsystem Reference29'
 * '<S36>'  : 'bms_f4/PackSOC/Subsystem2/Subsystem Reference30'
 * '<S37>'  : 'bms_f4/PackSOC/Subsystem2/Subsystem Reference43'
 * '<S38>'  : 'bms_f4/Subsystem/Compare To Constant'
 * '<S39>'  : 'bms_f4/Subsystem/Compare To Constant1'
 * '<S40>'  : 'bms_f4/Subsystem/Compare To Constant2'
 * '<S41>'  : 'bms_f4/Subsystem/Compare To Constant3'
 * '<S42>'  : 'bms_f4/Subsystem/Compare To Constant4'
 * '<S43>'  : 'bms_f4/Subsystem/Compare To Constant5'
 * '<S44>'  : 'bms_f4/Subsystem/Compare To Constant6'
 * '<S45>'  : 'bms_f4/Subsystem/Compare To Constant7'
 * '<S46>'  : 'bms_f4/Subsystem Reference/Chart'
 * '<S47>'  : 'bms_f4/Subsystem Reference1/Chart1'
 * '<S48>'  : 'bms_f4/Subsystem Reference1/Chart2'
 * '<S49>'  : 'bms_f4/Subsystem Reference1/Chart3'
 */
#endif                                 /* RTW_HEADER_bms_f4_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
