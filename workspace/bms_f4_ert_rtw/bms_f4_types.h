/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: bms_f4_types.h
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

#ifndef RTW_HEADER_bms_f4_types_h_
#define RTW_HEADER_bms_f4_types_h_
#include "rtwtypes.h"
#include "SystemState_t.h"

/* Model Code Variants */
#ifndef DEFINED_TYPEDEF_FOR_BMSBatteryPackData_
#define DEFINED_TYPEDEF_FOR_BMSBatteryPackData_

typedef struct {
  real_T SegmentTempVector[30];
  real_T SegmentVoltageVector[30];
  real_T SegmentCurrentVector[30];
  real_T SegmentRealSOCVector[30];
} BMSBatteryPackData;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BMSContactorModuleData_
#define DEFINED_TYPEDEF_FOR_BMSContactorModuleData_

typedef struct {
  real_T VCharger;
  real_T VInverter;
  real_T ICharger;
  real_T IInverter;
  real_T IBatt;
  real_T VBatt;
} BMSContactorModuleData;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BusInputBMS_
#define DEFINED_TYPEDEF_FOR_BusInputBMS_

typedef struct {
  BMSBatteryPackData BMSBatteryPackData;
  BMSContactorModuleData BMSContactorModuleData;
} BusInputBMS;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SimulationSystemInput_
#define DEFINED_TYPEDEF_FOR_SimulationSystemInput_

typedef struct {
  SystemState_t SystemState;
  real_T DrivingCurrentRqst;
  real_T ChargingCurrentRequest;
} SimulationSystemInput;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SimulationBatteryPackInput_
#define DEFINED_TYPEDEF_FOR_SimulationBatteryPackInput_

typedef struct {
  boolean_T ShortCircuitInjection[30];
  boolean_T OpenCircuitInjection[30];
} SimulationBatteryPackInput;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BusSimulationInput_
#define DEFINED_TYPEDEF_FOR_BusSimulationInput_

typedef struct {
  SimulationSystemInput SimulationSystemInput;
  SimulationBatteryPackInput SimulationBatteryPackInput;
} BusSimulationInput;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BMSContactorModuleCmd_
#define DEFINED_TYPEDEF_FOR_BMSContactorModuleCmd_

typedef struct {
  real_T ContactorCmd[3];
  real_T PreChrgCmd[2];
  real_T DisChrgCmd[2];
  real_T DrivetrainEn[2];
} BMSContactorModuleCmd;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BMSBatteryPackInput_
#define DEFINED_TYPEDEF_FOR_BMSBatteryPackInput_

typedef struct {
  boolean_T BalCmdVector[30];
  real_T balancingDeltaVCell[3];
  boolean_T balancingFlags[3];
} BMSBatteryPackInput;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BusSOCEstimation_
#define DEFINED_TYPEDEF_FOR_BusSOCEstimation_

typedef struct {
  real_T EKFEstimation[30];
  real_T CDCEstimation[30];
} BusSOCEstimation;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BMSFaultOutput_
#define DEFINED_TYPEDEF_FOR_BMSFaultOutput_

typedef struct {
  boolean_T OverCurrentWarning;
  boolean_T OverCurrentFault;
  boolean_T OverTemperatureWarning;
  boolean_T OverTemperatureFault;
  boolean_T OverVoltageWarning;
  boolean_T OverVoltageFault;
  boolean_T UnderVoltageWarning;
  boolean_T UnderVoltageFault;
} BMSFaultOutput;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BusOutputBMS_
#define DEFINED_TYPEDEF_FOR_BusOutputBMS_

typedef struct {
  BMSContactorModuleCmd BMSContactorModuleCmd;
  BMSBatteryPackInput BMSBatteryPackInput;
  BusSOCEstimation BusSOCEstimation;
  BMSFaultOutput BMSFaultOutput;
} BusOutputBMS;

#endif

/* Parameters (default storage) */
typedef struct P_bms_f4_T_ P_bms_f4_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_bms_f4_T RT_MODEL_bms_f4_T;

#endif                                 /* RTW_HEADER_bms_f4_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
