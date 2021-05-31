/*
 * File: coder_assumptions.h
 *
 * Abstract: Coder assumptions header file
 */

#ifndef CODER_ASSUMPTIONS_H
#define CODER_ASSUMPTIONS_H

/* include model specific checks */
#include "bms_f4_ca.h"

/* global results variable mapping for static code */
#define CA_Expected_HWImpl             CA_bms_f4_ExpHW
#define CA_Actual_HWImpl               CA_bms_f4_ActHW
#define CA_HWImpl_Results              CA_bms_f4_HWRes
#define CA_PortableWordSizes_Results   CA_bms_f4_PWSRes

/* entry point function mapping for static code */
#define CA_Run_Tests                   bms_f4_caRunTests
#endif                                 /* CODER_ASSUMPTIONS_H */
