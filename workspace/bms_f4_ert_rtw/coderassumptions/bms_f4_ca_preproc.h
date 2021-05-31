/*
 * File: bms_f4_ca_preproc.h
 *
 * Abstract: Preprocessor checks for hardware implementation settings.
 *
 * Hardware Implementation Specification:
 *
 * HWDeviceType: ARM Compatible->ARM Cortex
 * PortableWordSizes: off
 * PreprocMaxBitsUint: 32
 * PreprocMaxBitsSint: 32
 * BitPerChar: 8
 * BitPerShort: 16
 * BitPerInt: 32
 * BitPerLong: 32
 * LongLongMode: off
 * BitPerLongLong: 64
 */

#ifndef BMS_F4_CA_PREPROC_H
#define BMS_F4_CA_PREPROC_H

/* make sure limits are available */
#ifndef UCHAR_MAX
#include <limits.h>
#endif

#if (UCHAR_MAX != (0xFFU)) || (SCHAR_MAX != (0x7F))
#error Code was generated for compiler with different sized uchar/char. \
Consider adjusting Hardware Implementation data type sizes to \
match your compiler (defined in limits.h).
#endif

#if (USHRT_MAX != (0xFFFFU)) || (SHRT_MAX != (0x7FFF))
#error Code was generated for compiler with different sized ushort/short. \
Consider adjusting Hardware Implementation data type sizes to \
match your compiler (defined in limits.h).
#endif

#if (UINT_MAX != (0xFFFFFFFFU)) || (INT_MAX != (0x7FFFFFFF))
#error Code was generated for compiler with different sized uint/int. \
Consider adjusting Hardware Implementation data type sizes to \
match your compiler (defined in limits.h).
#endif

#if (ULONG_MAX != (0xFFFFFFFFU)) || (LONG_MAX != (0x7FFFFFFF))
#error Code was generated for compiler with different sized ulong/long. \
Consider adjusting Hardware Implementation data type sizes to \
match your compiler (defined in limits.h).
#endif
#endif                                 /* BMS_F4_CA_PREPROC_H */
