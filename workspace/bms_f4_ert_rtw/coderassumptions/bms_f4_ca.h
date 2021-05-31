/*
 * File: bms_f4_ca.h
 *
 * Abstract: Tests assumptions in the generated code.
 */

#ifndef BMS_F4_CA_H
#define BMS_F4_CA_H

/* preprocessor validation checks */
#include "bms_f4_ca_preproc.h"
#include "coder_assumptions_hwimpl.h"

/* variables holding test results */
extern CA_HWImpl_TestResults CA_bms_f4_HWRes;
extern CA_PWS_TestResults CA_bms_f4_PWSRes;

/* variables holding "expected" and "actual" hardware implementation */
extern const CA_HWImpl CA_bms_f4_ExpHW;
extern CA_HWImpl CA_bms_f4_ActHW;

/* entry point function to run tests */
void bms_f4_caRunTests(void);

#endif                                 /* BMS_F4_CA_H */
