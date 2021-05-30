/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: bms.h
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

#ifndef RTW_HEADER_bms_h_
#define RTW_HEADER_bms_h_
#include <math.h>
#include <string.h>
#ifndef bms_COMMON_INCLUDES_
#define bms_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* bms_COMMON_INCLUDES_ */

#include "bms_types.h"

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
  uint8_T is_active_c2_bms;            /* '<S4>/Chart1' */
  uint8_T is_c2_bms;                   /* '<S4>/Chart1' */
  uint8_T is_ON;                       /* '<S4>/Chart1' */
  boolean_T flagBalancingDone;         /* '<S4>/Chart1' */
} DW_Chart1_bms_T;

/* Block signals (default storage) */
typedef struct {
  real_T VectorConcatenate1[3];        /* '<S3>/Vector Concatenate1' */
  real_T VectorConcatenate[2];         /* '<S3>/Vector Concatenate' */
  real_T VectorConcatenate2[2];        /* '<S3>/Vector Concatenate2' */
  real_T VectorConcatenate3[2];        /* '<S3>/Vector Concatenate3' */
  real_T VectorConcatenate_k[3];       /* '<S4>/Vector Concatenate' */
  boolean_T MatrixConcatenate[30];     /* '<S4>/Matrix Concatenate' */
  boolean_T VectorConcatenate1_a[3];   /* '<S4>/Vector Concatenate1' */
} B_bms_T;

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
  uint8_T is_c1_bms;                   /* '<S3>/Chart' */
  boolean_T isNotInit;                 /* '<S3>/Chart' */
  DW_Chart1_bms_T sf_Chart3;           /* '<S4>/Chart3' */
  DW_Chart1_bms_T sf_Chart2;           /* '<S4>/Chart2' */
  DW_Chart1_bms_T sf_Chart1;           /* '<S4>/Chart1' */
} DW_bms_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real_T TmpSignalConversionAtTransp[10];
  const real_T Transpose[10];          /* '<S5>/Transpose' */
  const real_T TmpSignalConversionAtTran_n[10];
  const real_T Transpose_p[10];        /* '<S6>/Transpose' */
  const real_T TmpSignalConversionAtTran_j[10];
  const real_T Transpose_f[10];        /* '<S7>/Transpose' */
  const real_T EKFEstimation[30];      /* '<S1>/Matrix Concatenate' */
} ConstB_bms_T;

/* Constant parameters (default storage) */
typedef struct {
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
  real_T pooled7[3];

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
  real_T pooled8[3];
} ConstP_bms_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  BusInputBMS FromPlant;               /* '<Root>/FromPlant' */
  BusSimulationInput InputSimulationBus;/* '<Root>/InputSimulationBus' */
} ExtU_bms_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  BusOutputBMS ToPlant;                /* '<Root>/ToPlant' */
} ExtY_bms_T;

/* Real-time Model Data Structure */
struct tag_RTM_bms_T {
  const char_T * volatile errorStatus;
};

/* Block signals (default storage) */
extern B_bms_T bms_B;

/* Block states (default storage) */
extern DW_bms_T bms_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_bms_T bms_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_bms_T bms_Y;
extern const ConstB_bms_T bms_ConstB;  /* constant block i/o */

/* Constant parameters (default storage) */
extern const ConstP_bms_T bms_ConstP;

/* Model entry point functions */
extern void bms_initialize(void);
extern void bms_step(void);
extern void bms_terminate(void);

/* Real-time Model object */
extern RT_MODEL_bms_T *const bms_M;

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
 * '<Root>' : 'bms'
 * '<S1>'   : 'bms/PackSOC'
 * '<S2>'   : 'bms/Subsystem'
 * '<S3>'   : 'bms/Subsystem Reference'
 * '<S4>'   : 'bms/Subsystem Reference1'
 * '<S5>'   : 'bms/PackSOC/Subsystem'
 * '<S6>'   : 'bms/PackSOC/Subsystem1'
 * '<S7>'   : 'bms/PackSOC/Subsystem2'
 * '<S8>'   : 'bms/PackSOC/Subsystem/Subsystem Reference1'
 * '<S9>'   : 'bms/PackSOC/Subsystem/Subsystem Reference2'
 * '<S10>'  : 'bms/PackSOC/Subsystem/Subsystem Reference24'
 * '<S11>'  : 'bms/PackSOC/Subsystem/Subsystem Reference25'
 * '<S12>'  : 'bms/PackSOC/Subsystem/Subsystem Reference26'
 * '<S13>'  : 'bms/PackSOC/Subsystem/Subsystem Reference27'
 * '<S14>'  : 'bms/PackSOC/Subsystem/Subsystem Reference28'
 * '<S15>'  : 'bms/PackSOC/Subsystem/Subsystem Reference29'
 * '<S16>'  : 'bms/PackSOC/Subsystem/Subsystem Reference30'
 * '<S17>'  : 'bms/PackSOC/Subsystem/Subsystem Reference43'
 * '<S18>'  : 'bms/PackSOC/Subsystem1/Subsystem Reference1'
 * '<S19>'  : 'bms/PackSOC/Subsystem1/Subsystem Reference2'
 * '<S20>'  : 'bms/PackSOC/Subsystem1/Subsystem Reference24'
 * '<S21>'  : 'bms/PackSOC/Subsystem1/Subsystem Reference25'
 * '<S22>'  : 'bms/PackSOC/Subsystem1/Subsystem Reference26'
 * '<S23>'  : 'bms/PackSOC/Subsystem1/Subsystem Reference27'
 * '<S24>'  : 'bms/PackSOC/Subsystem1/Subsystem Reference28'
 * '<S25>'  : 'bms/PackSOC/Subsystem1/Subsystem Reference29'
 * '<S26>'  : 'bms/PackSOC/Subsystem1/Subsystem Reference30'
 * '<S27>'  : 'bms/PackSOC/Subsystem1/Subsystem Reference43'
 * '<S28>'  : 'bms/PackSOC/Subsystem2/Subsystem Reference1'
 * '<S29>'  : 'bms/PackSOC/Subsystem2/Subsystem Reference2'
 * '<S30>'  : 'bms/PackSOC/Subsystem2/Subsystem Reference24'
 * '<S31>'  : 'bms/PackSOC/Subsystem2/Subsystem Reference25'
 * '<S32>'  : 'bms/PackSOC/Subsystem2/Subsystem Reference26'
 * '<S33>'  : 'bms/PackSOC/Subsystem2/Subsystem Reference27'
 * '<S34>'  : 'bms/PackSOC/Subsystem2/Subsystem Reference28'
 * '<S35>'  : 'bms/PackSOC/Subsystem2/Subsystem Reference29'
 * '<S36>'  : 'bms/PackSOC/Subsystem2/Subsystem Reference30'
 * '<S37>'  : 'bms/PackSOC/Subsystem2/Subsystem Reference43'
 * '<S38>'  : 'bms/Subsystem/Compare To Constant'
 * '<S39>'  : 'bms/Subsystem/Compare To Constant1'
 * '<S40>'  : 'bms/Subsystem/Compare To Constant2'
 * '<S41>'  : 'bms/Subsystem/Compare To Constant3'
 * '<S42>'  : 'bms/Subsystem/Compare To Constant4'
 * '<S43>'  : 'bms/Subsystem/Compare To Constant5'
 * '<S44>'  : 'bms/Subsystem/Compare To Constant6'
 * '<S45>'  : 'bms/Subsystem/Compare To Constant7'
 * '<S46>'  : 'bms/Subsystem Reference/Chart'
 * '<S47>'  : 'bms/Subsystem Reference1/Chart1'
 * '<S48>'  : 'bms/Subsystem Reference1/Chart2'
 * '<S49>'  : 'bms/Subsystem Reference1/Chart3'
 */
#endif                                 /* RTW_HEADER_bms_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
