/*
 * File: xil_instrumentation.c
 *
 * Code generated for instrumentation.
 *
 */

#include "xil_instrumentation.h"

/* Code instrumentation offset(s) for model bms_f4 */
#define taskTimeStart_bms_f4_offset    0
#define taskTimeEnd_bms_f4_offset      0

/* Code instrumentation offset(s) for model bms_f4 */
#define captureMode_bms_f4_offset      3

/* A function parameter may be intentionally unused */
#ifndef UNUSED_PARAMETER
# if defined(__LCC__)
#   define UNUSED_PARAMETER(x)
# else
#   define UNUSED_PARAMETER(x)         (void) (x)
# endif
#endif

#define SIZEOF_TIMER_TYPE              sizeof(uint32_T)

static uint32_T xsd_xil_timer_corrected = 0;
static uint32_T xsd_xil_timer_unfreeze = 0;
static uint32_T xsd_xil_freezing_busy = 0;
void xilUploadProfilingData(uint32_T sectionId)
{
  xilUploadCodeInstrData((void *)(&xsd_xil_timer_corrected), (uint32_T)
    (SIZEOF_TIMER_TYPE), sectionId);
}

/* The internal freeze and unfreeze methods cannot be nested. The customer-visible implementation avoids nesting problems */
void xilProfilingTimerFreezeInternal(void)
{
  /* Update the value of the corrected timer to exclude time spent in the
   * instrumentation code.
   *
   * Using a timer that increments on each tick.
   */
  xsd_xil_timer_corrected = xsd_xil_timer_corrected + (((uint32_T)
    (profileTimerRead())) - xsd_xil_timer_unfreeze);
}

void xilProfilingTimerUnFreezeInternal(void)
{
  xsd_xil_timer_unfreeze = ( uint32_T ) (profileTimerRead());
}

void xilProfilingTimerFreeze(void)
{
  if (xsd_xil_freezing_busy == 0) {
    xilProfilingTimerFreezeInternal();
  }                                    /* if */
}

void xilProfilingTimerUnFreeze(void)
{
  if (xsd_xil_freezing_busy == 0) {
    xilProfilingTimerUnFreezeInternal();
  }                                    /* if */
}

void taskTimeStart(uint32_T sectionId)
{
  captureModeStart(sectionId);
  xilProfilingTimerUnFreezeInternal();
}

void taskTimeEnd(uint32_T sectionId)
{
  xilProfilingTimerFreezeInternal();
  captureModeEnd(sectionId);
}

#define MAX_EXECUTION_SECTION_ID       3
#define MAP_CAPTURE_IDS(X)             (((X) > 0 && (X) <= 3) ? (X) : 0)

static uint32_T xsd_xil_last_start_time[MAX_EXECUTION_SECTION_ID] = { 0 };

static uint32_T xsd_xil_capture_mode_max[MAX_EXECUTION_SECTION_ID] = { 0 };

static uint32_T xsd_xil_capture_mode_avg[MAX_EXECUTION_SECTION_ID] = { 0 };

static uint32_T xsd_xil_capture_mode_calls[MAX_EXECUTION_SECTION_ID] = { 0 };

void captureMode(uint32_T sectionId)
{
  xilUploadCodeInstrData((void *)(&xsd_xil_capture_mode_max), (uint32_T)
    (MAX_EXECUTION_SECTION_ID * sizeof(uint32_T)), sectionId);
  xilUploadCodeInstrData((void *)(&xsd_xil_capture_mode_avg), (uint32_T)
    (MAX_EXECUTION_SECTION_ID * sizeof(uint32_T)), sectionId + 1);
  xilUploadCodeInstrData((void *)(&xsd_xil_capture_mode_calls), (uint32_T)
    (MAX_EXECUTION_SECTION_ID * sizeof(uint32_T)), sectionId + 2);
}

void captureModeStart(uint32_T sectionId)
{
  uint32_T mappedId = MAP_CAPTURE_IDS(sectionId);
  if (mappedId > 0) {
    xsd_xil_last_start_time[mappedId - 1] = xsd_xil_timer_corrected;
  }                                    /* if */
}

void captureModeEnd(uint32_T sectionId)
{
  uint32_T mappedId = MAP_CAPTURE_IDS(sectionId);
  uint32_T* pCaptureValue;
  uint32_T turnaroundTime;
  if (mappedId > 0) {
    mappedId = mappedId - 1;

    /* Update maximum execution */
    pCaptureValue = &(xsd_xil_capture_mode_max[mappedId]);
    turnaroundTime = xsd_xil_timer_corrected - xsd_xil_last_start_time[mappedId];
    if (turnaroundTime > *pCaptureValue) {
      *pCaptureValue = turnaroundTime;
    }                                  /* if */

    /* Try to update to total execution counter */
    pCaptureValue = &(xsd_xil_capture_mode_avg[mappedId]);
    if ((*pCaptureValue + turnaroundTime) > *pCaptureValue) {
      *pCaptureValue = *pCaptureValue + turnaroundTime;

      /* Update total number of calls */
      pCaptureValue = &(xsd_xil_capture_mode_calls[mappedId]);
      *pCaptureValue = *pCaptureValue + 1;
    }                                  /* if */
  }                                    /* if */
}

/* Code instrumentation method(s) for model bms_f4 */
void taskTimeStart_bms_f4(uint32_T sectionId)
{
  taskTimeStart(taskTimeStart_bms_f4_offset + sectionId);
}

void taskTimeEnd_bms_f4(uint32_T sectionId)
{
  taskTimeEnd(taskTimeEnd_bms_f4_offset + sectionId);
}

/* Code instrumentation method(s) for model bms_f4 */
void captureMode_bms_f4(uint32_T sectionId)
{
  captureMode(captureMode_bms_f4_offset + sectionId);
}

void PauseEvent (void)
{
  /* callbacks executed when the sim is paused */
}

void TerminateEvent (void)
{
  /* callbacks executed when the sim ends */
  captureMode_bms_f4(1);
}

void StepCompletedEvent (void)
{
  /* callbacks executed when a step ends */
}
