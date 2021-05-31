/*
 * File: xil_instrumentation.h
 *
 * Code generated for instrumentation.
 *
 */

/* Functions with a C call interface */
#ifdef __cplusplus

extern "C" {

#endif

#include "profiler_timer.h"
#ifdef __cplusplus

}
#endif

#include "rtwtypes.h"

/* Upload code instrumentation data point */
void xilUploadCodeInstrData(
  void* pData, uint32_T numMemUnits, uint32_T sectionId);

/* Called before starting a profiled section of code */
void taskTimeStart(uint32_T);

/* Called on finishing a profiled section of code */
void taskTimeEnd(uint32_T);

/* Uploads data */
void xilUploadProfilingData(uint32_T sectionId);

/* Pause the timer while running code associated with storing and uploading the data. */
void xilProfilingTimerFreeze(void);

/* Restart the timer after a pause */
void xilProfilingTimerUnFreeze(void);

/* Request upload of metrics evaluated on target */
void captureMode(uint32_T sectionId);

/* Update methods */
void captureModeStart(uint32_T sectionId);
void captureModeEnd(uint32_T sectionId);

/* Code instrumentation method(s) for model bms_f4 */
void taskTimeStart_bms_f4(uint32_T sectionId);
void taskTimeEnd_bms_f4(uint32_T sectionId);

/* Code instrumentation method(s) for model bms_f4 */
void captureMode_bms_f4(uint32_T sectionId);

/* Callback called when the simulation is paused */
void PauseEvent (void);

/* Callback called when the simulation ends */
void TerminateEvent (void);

/* Callback called when a step ends */
void StepCompletedEvent (void);
