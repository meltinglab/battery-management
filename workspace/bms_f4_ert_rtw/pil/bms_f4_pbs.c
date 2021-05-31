/*
 * bms_f4_pbs.c
 *
 * Automatically generated s-function with I/O interface for:
 * Component: bms_f4
 * Component Simulink Path: bms_f4
 * Simulation Mode: PIL
 *
 */

#define S_FUNCTION_NAME                bms_f4_pbs
#define S_FUNCTION_LEVEL               2
#if !defined(RTW_GENERATED_S_FUNCTION)
#define RTW_GENERATED_S_FUNCTION
#endif

#include <stdio.h>
#include <string.h>
#include "simstruc.h"
#include "simtarget/slMdlrefSimTargetCoreHeaders.h"
#include "simtarget/slMdlrefSimTargetInstrumentationHeaders.h"
#include "fixedpoint.h"
#include "coder/connectivity_core/xilutils/xilutils.h"
#include "coder/simulinkcoder/xilutils_sl/xilutils_sl.h"
#include "rtiostream_utils.h"
#include "coder/connectivity/xilcomms_rtiostream/xilcomms_rtiostream.h"
#include "coder/connectivity/XILHostAppSvc/XILHostAppSvc_CInterface.h"
#include "messages/slMessagesSfcnBridge.h"
#include "strings/slStringSfcnAPI.h"
#include "mwstringutil.h"
#include "coder/connectivity/CoderAssumpHostAppSvc/CoderAssumpHostAppSvc_CInterface.h"

static real_T rtInf;
static real_T rtMinusInf;

/* Response case labels */
enum ResponseIDs {
  RESPONSE_ERROR = 0,
  RESPONSE_OUTPUT_PRE_DATA = 1,
  RESPONSE_OUTPUT_DATA = 2,
  RESPONSE_PRINTF = 3,
  RESPONSE_FOPEN = 4,
  RESPONSE_FPRINTF = 5,
  RESPONSE_SIGNAL_RAISED = 6
};

typedef struct {
  FILE ** Fd;
  mwSize size;
  int32_T fidOffset;
} targetIOFd_T;

typedef enum {
  XIL_INIT_COMMAND = 0,
  XIL_INITIALIZE_COMMAND,
  XIL_SYSTEM_INITIALIZE_COMMAND,
  XIL_OUTPUT_COMMAND,
  XIL_TERMINATE_COMMAND,
  XIL_ENABLE_COMMAND,
  XIL_DISABLE_COMMAND,
  XIL_CONST_OUTPUT_COMMAND,
  XIL_PROCESS_PARAMS_COMMAND,
  XIL_CLIENT_SERVER_COMMAND,
  XIL_SHUTDOWN_COMMAND,
  XIL_UPDATE_COMMAND,
  XIL_SYSTEM_RESET_COMMAND,
  XIL_PAUSE_COMMAND
}
  XIL_COMMAND_TYPE_ENUM;

typedef struct {
  uint16_T bitPattern;
} real16_T;

static RegMdlInfo rtMdlInfo_bms_f4[1] = { "", MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT,
  0, 0, NULL };

static char * getSimulinkBlockPath(SimStruct *S)
{
  char * simulinkBlockPath = NULL;
  const char * origBlockPath = ssGetPath(S);
  const char * searchString = "TmpSFcnForModelReference_";
  char * searchPtr;
  size_t origLength, searchAndNameLength, copyAmount;
  char * secondPart;
  size_t nameLength;
  origLength = strlen(origBlockPath);
  searchPtr = strstr(origBlockPath, searchString);
  if (searchPtr == NULL) {
    return simulinkBlockPath;
  }

  searchAndNameLength = strlen(searchPtr);
  copyAmount = origLength - searchAndNameLength;
  simulinkBlockPath = (char *) mxCalloc((mwSize) (origLength + 1), sizeof(char));
  simulinkBlockPath = strncpy(simulinkBlockPath, origBlockPath, copyAmount);
  simulinkBlockPath[copyAmount] = '\0';
  nameLength = searchAndNameLength - strlen(searchString);
  secondPart = &simulinkBlockPath[copyAmount];
  secondPart = strncpy(secondPart, &origBlockPath[origLength - nameLength],
                       nameLength);
  secondPart[nameLength] = '\0';
  return simulinkBlockPath;
}

static void callStopHookAndFreeSFcnMemory(SimStruct *S);
static void mdlTerminate(SimStruct *S);

/* grow the buffer for target I/O Fd array
 * targetIOFd->Fd is NULL on failure */
static void growTargetIOFd(SimStruct *S, targetIOFd_T * IOFd, mwSize
  requiredSize)
{
  if (IOFd->size < requiredSize) {
    IOFd->Fd = (FILE**)mxRealloc(IOFd->Fd, requiredSize * sizeof(FILE*));
    if (IOFd->Fd == NULL) {
      ssSetErrorStatus( S,"growTargetIOFd: mxRealloc failed.");
    } else {
      mexMakeMemoryPersistent(IOFd->Fd);
      IOFd->size = requiredSize;
    }                                  /* if */
  }                                    /* if */
}

static void closeAndFreeTargetIOFd(SimStruct *S)
{
  int i;
  if (ssGetPWork(S) != NULL) {
    targetIOFd_T * targetIOFdPtr = (targetIOFd_T *) ssGetPWorkValue(S, 3);
    if (targetIOFdPtr != NULL) {
      if (targetIOFdPtr->Fd != NULL) {
        for (i=0; i<targetIOFdPtr->size; i++) {
          if (targetIOFdPtr->Fd[i] != NULL) {
            fclose(targetIOFdPtr->Fd[i]);
          }                            /* if */
        }                              /* for */

        mxFree(targetIOFdPtr->Fd);
      }                                /* if */

      mxFree(targetIOFdPtr);
    }                                  /* if */

    ssSetPWorkValue(S, 3, NULL);
  }                                    /* if */
}

/* receive one packet of data and dispatch to owning application */
static boolean_T recvData(SimStruct *S, void* pComms)
{
  int * pCommErrorOccurred = (int *) ssGetPWorkValue(S, 4);
  void * pXILUtils = (void *) ssGetPWorkValue(S, 6);
  if (pCommErrorOccurred == NULL) {
    ssSetErrorStatus( S,"pCommErrorOccurred is NULL.");
    return XILHOSTAPPSVC_ERROR;
  }                                    /* if */

  if (pXILUtils == NULL) {
    ssSetErrorStatus( S,"pXILUtils is NULL.");
    return XILHOSTAPPSVC_ERROR;
  }                                    /* if */

  *pCommErrorOccurred = (xilCommsRun(pComms, pXILUtils) !=
    XILCOMMS_RTIOSTREAM_SUCCESS);
  return (*pCommErrorOccurred?XILHOSTAPPSVC_ERROR:XILHOSTAPPSVC_SUCCESS);
}

/* send data via xil comms */
static boolean_T sendData(SimStruct *S, void* pXILService, XIL_IOBuffer_T
  * IOBuffer, mwSize sendSize)
{
  int * pCommErrorOccurred = (int *) ssGetPWorkValue(S, 4);
  if (pCommErrorOccurred == NULL) {
    ssSetErrorStatus( S,"pCommErrorOccurred is NULL.");
    return XILHOSTAPPSVC_ERROR;
  }                                    /* if */

  *pCommErrorOccurred = (xilHostAppSvcSend(pXILService, IOBuffer->data, sendSize)
    != XILHOSTAPPSVC_SUCCESS);
  return (*pCommErrorOccurred?XILHOSTAPPSVC_ERROR:XILHOSTAPPSVC_SUCCESS);
}

/* implements command dispatch */
static boolean_T commandDispatch(SimStruct *S, XIL_IOBuffer_T* IOBuffer, mwSize
  dataOutSize)
{
  void * pXILService = (void *) ssGetPWorkValue(S, 9);
  if (pXILService == NULL) {
    ssSetErrorStatus( S,"pXILService is NULL!");
    return XILHOSTAPPSVC_ERROR;
  }                                    /* if */

  /* send the data */
  if (sendData(S, pXILService, IOBuffer, dataOutSize) != XILHOSTAPPSVC_SUCCESS)
  {
    return XILHOSTAPPSVC_ERROR;
  }                                    /* if */

  return XILHOSTAPPSVC_SUCCESS;
}

/* implements command response */
static boolean_T commandResponse(SimStruct *S, mwSize* dataInSize,
  XILCommandResponseType* commandType)
{
  void * pXILService = (void *) ssGetPWorkValue(S, 9);
  if (pXILService == NULL) {
    ssSetErrorStatus( S,"pXILService is NULL!");
    return XILHOSTAPPSVC_ERROR;
  }                                    /* if */

  {
    /* receive the response data */
    uint8_T COMMAND_COMPLETE = 0;
    void * pComms = (void *) ssGetPWorkValue(S, 7);
    if (pComms == NULL) {
      ssSetErrorStatus( S,"pComms is NULL!");
      return XILHOSTAPPSVC_ERROR;
    }                                  /* if */

    while (!COMMAND_COMPLETE) {
      xilHostAppSvcSetIsResponseComplete(pXILService, 0);
      if (recvData(S, pComms) != XILHOSTAPPSVC_SUCCESS) {
        return XILHOSTAPPSVC_ERROR;
      }                                /* if */

      COMMAND_COMPLETE = xilHostAppSvcGetIsResponseComplete(pXILService);
    }                                  /* while */

    /* determine command response type */
    *commandType = (XILCommandResponseType) COMMAND_COMPLETE;
    *dataInSize = xilHostAppSvcGetPayloadSizeForOneStep(pXILService);
    return XILHOSTAPPSVC_SUCCESS;
  }
}

static void copyIOData(void * const dstPtr, void * const srcPtr, uint8_T **
  const tgtPtrPtr, size_t numElements, size_t cTypeSize)
{
  size_t maxBytesConsumed = numElements * cTypeSize;
  memcpy(dstPtr, srcPtr, maxBytesConsumed);
  (*tgtPtrPtr)+=(maxBytesConsumed/sizeof(**tgtPtrPtr));
}

static void copyStringIOData(void * const dstPtr, void * const srcPtr, uint8_T **
  const tgtPtrPtr, size_t numElements, size_t cTypeSize, uint8_T isInput)
{
  size_t maxBytesConsumed = numElements * cTypeSize;
  if (isInput) {
    suWriteSILStringInput(dstPtr, (int32_T)numElements, srcPtr);
  } else {
    suWriteSILStringOutput(dstPtr, srcPtr, (int32_T)numElements);
  }                                    /* if */

  (*tgtPtrPtr)+=(maxBytesConsumed/sizeof(**tgtPtrPtr));
}

static void callStopHookAndFreeSFcnMemory(SimStruct *S)
{
  closeAndFreeTargetIOFd(S);
  if (ssGetPWork(S) != NULL) {
    int * pCommErrorOccurred = (int *) ssGetPWorkValue(S, 4);
    int * pIsXILApplicationStarted = (int *) ssGetPWorkValue(S, 5);
    if ((pIsXILApplicationStarted != NULL) && (*pIsXILApplicationStarted == 1))
    {
      {
        void * pXILUtils = (void *) ssGetPWorkValue(S, 6);
        if (pXILUtils) {
          mxArray *rhs[3];
          char * simulinkBlockPath = getSimulinkBlockPath(S);
          if (simulinkBlockPath == NULL) {
            ssSetErrorStatus(S,
                             "ModelBlock SIL/PIL unexpected error: getSimulinkBlockPath returned NULL pointer. Check search string was found in ssGetPath.\n");
            return;
          }

          rhs[ 0 ] = mxCreateString(
            "@coder.connectivity.SimulinkInterface.getSILPILInterface");
          rhs[ 1 ] = mxCreateDoubleScalar( 4 );
          rhs[ 2 ] = mxCreateString(simulinkBlockPath);
          xilUtilsCallMATLAB(pXILUtils, 0, NULL, 3, rhs,
                             "rtw.pil.SILPILInterface.sfunctionPILStopHook");
          mxFree((void *) simulinkBlockPath);
        }                              /* if */
      }
    }                                  /* if */

    if (pIsXILApplicationStarted != NULL) {
      *pIsXILApplicationStarted = 0;
    }                                  /* if */
  }                                    /* if */

  if (ssGetPWork(S) != NULL) {
    XIL_IOBuffer_T* IOBufferPtr;
    XIL_RtIOStreamData_T * rtIOStreamDataPtr = (XIL_RtIOStreamData_T *)
      ssGetPWorkValue(S, 0);
    SIL_DEBUGGING_DATA_T * silDebuggingDataPtr = (SIL_DEBUGGING_DATA_T *)
      ssGetPWorkValue(S, 2);
    if (rtIOStreamDataPtr != NULL) {
      {
        int errorStatus = rtIOStreamUnloadLib(&rtIOStreamDataPtr->libH);
        if (errorStatus) {
          ssSetErrorStatus( S,"rtIOStreamUnloadLib failed.");
        }                              /* if */
      }

      mxFree(rtIOStreamDataPtr->lib);
      mxDestroyArray(rtIOStreamDataPtr->MATLABObject);
      mxFree(rtIOStreamDataPtr);
      ssSetPWorkValue(S, 0, NULL);
    }                                  /* if */

    if (silDebuggingDataPtr != NULL) {
      mxFree(silDebuggingDataPtr->componentBlockPath);
      mxFree(silDebuggingDataPtr->SILPILInterfaceFcnStr);
      mxFree(silDebuggingDataPtr);
      ssSetPWorkValue(S, 2, NULL);
    }                                  /* if */

    IOBufferPtr = (XIL_IOBuffer_T *) ssGetPWorkValue(S, 1);
    if (IOBufferPtr != NULL) {
      mxFree(IOBufferPtr->data);
      mxFree(IOBufferPtr);
      ssSetPWorkValue(S, 1, NULL);
    }                                  /* if */

    closeAndFreeTargetIOFd(S);
    if (ssGetPWork(S) != NULL) {
      void * pXILUtils = (void *) ssGetPWorkValue(S, 6);
      void * pComms = (void *) ssGetPWorkValue(S, 7);
      void * pXILService = (void *) ssGetPWorkValue(S, 9);
      void * pCoderAssumptionsApp = (void *) ssGetPWorkValue(S, 10);
      if (pCoderAssumptionsApp != NULL) {
        coderAssumpHostAppSvcDestroy(pCoderAssumptionsApp);
        ssSetPWorkValue(S, 10, NULL);
      }                                /* if */

      if (pXILService != NULL) {
        xilHostAppSvcDestroy(pXILService);
        ssSetPWorkValue(S, 9, NULL);
      }                                /* if */

      if (pComms != NULL) {
        xilCommsDestroy(pComms);
        ssSetPWorkValue(S, 7, NULL);
      }                                /* if */
    }                                  /* if */
  }                                    /* if */
}

static boolean_T processResponseError(SimStruct * S, uint8_T ** mxMemUnitPtrPtr)
{
  uint8_T errorId = **mxMemUnitPtrPtr;
  (*mxMemUnitPtrPtr)++;
  if (errorId) {
    {
      void * pXILUtils = (void *) ssGetPWorkValue(S, 6);
      mxArray * rhs[ 2 ];
      rhs[0] = mxCreateString("PIL:pilverification:PILError");
      rhs[1] = mxCreateDoubleScalar(errorId);
      xilUtilsHandleError(pXILUtils, 2 , rhs );
      return XILHOSTAPPSVC_ERROR;
    }
  }                                    /* if */

  return XILHOSTAPPSVC_SUCCESS;
}

static boolean_T processResponsePrintf(SimStruct * S, uint8_T ** mxMemUnitPtrPtr)
{
  const int TARGET_IO_SUCCESS = 0;
  uint8_T PRINTF_ERROR;
  uint16_T PRINTF_SIZE;

  {
    {
      uint8_T * simDataMemUnitPtr;
      simDataMemUnitPtr = (uint8_T *) &PRINTF_ERROR;

      {
        size_t num_elements = 1;

        {
          copyIOData(simDataMemUnitPtr, *mxMemUnitPtrPtr, &*mxMemUnitPtrPtr,
                     num_elements, sizeof(uint8_T));
        }
      }
    }
  }

  {
    {
      uint8_T * simDataMemUnitPtr;
      simDataMemUnitPtr = (uint8_T *) &PRINTF_SIZE;

      {
        size_t num_elements = 1;

        {
          copyIOData(simDataMemUnitPtr, *mxMemUnitPtrPtr, &*mxMemUnitPtrPtr,
                     num_elements, sizeof(uint16_T));
        }
      }
    }
  }

  if (PRINTF_ERROR != TARGET_IO_SUCCESS) {
    {
      void * pXILUtils = (void *) ssGetPWorkValue(S, 6);
      mxArray * rhs[ 2 ];
      rhs[0] = mxCreateString("PIL:pil:TargetIOError");
      rhs[1] = mxCreateDoubleScalar(PRINTF_ERROR);
      xilUtilsHandleError(pXILUtils, 2 , rhs );
      return XILHOSTAPPSVC_ERROR;
    }
  } else {
    uint8_T *pPrintBuff;
    pPrintBuff = *mxMemUnitPtrPtr;
    if (pPrintBuff[PRINTF_SIZE-1] == '\0') {
      mexPrintf("%s", pPrintBuff);
    }                                  /* if */
  }                                    /* if */

  (*mxMemUnitPtrPtr) = (*mxMemUnitPtrPtr) + PRINTF_SIZE;
  return XILHOSTAPPSVC_SUCCESS;
}

static boolean_T processResponseFopen(SimStruct * S, uint8_T ** mxMemUnitPtrPtr)
{
  uint16_T FOPEN_FID;
  uint16_T FOPEN_NAME_SIZE;
  targetIOFd_T *targetIOFdPtr;

  {
    {
      uint8_T * simDataMemUnitPtr;
      simDataMemUnitPtr = (uint8_T *) &FOPEN_FID;

      {
        size_t num_elements = 1;

        {
          copyIOData(simDataMemUnitPtr, *mxMemUnitPtrPtr, &*mxMemUnitPtrPtr,
                     num_elements, sizeof(uint16_T));
        }
      }
    }
  }

  {
    {
      uint8_T * simDataMemUnitPtr;
      simDataMemUnitPtr = (uint8_T *) &FOPEN_NAME_SIZE;

      {
        size_t num_elements = 1;

        {
          copyIOData(simDataMemUnitPtr, *mxMemUnitPtrPtr, &*mxMemUnitPtrPtr,
                     num_elements, sizeof(uint16_T));
        }
      }
    }
  }

  targetIOFdPtr = (targetIOFd_T *) ssGetPWorkValue(S, 3);
  if (targetIOFdPtr != NULL) {
    /* check fid increments by 1 */
    if (targetIOFdPtr->fidOffset + 1 == FOPEN_FID) {
      targetIOFdPtr->fidOffset = FOPEN_FID;
      growTargetIOFd(S, targetIOFdPtr, targetIOFdPtr->fidOffset + 1);
      if (targetIOFdPtr->Fd != NULL) {
        uint8_T *pFopenBuff;
        targetIOFdPtr->Fd[targetIOFdPtr->fidOffset] = NULL;
        pFopenBuff = (*mxMemUnitPtrPtr);
        if (pFopenBuff[FOPEN_NAME_SIZE-1] == '\0') {
          FILE * tmpFd = NULL;
          tmpFd = fopen((char *) pFopenBuff,"w");
          if (tmpFd != NULL) {
            /* save the file descriptor */
            targetIOFdPtr->Fd[targetIOFdPtr->fidOffset] = tmpFd;
          } else {
            {
              void * pXILUtils = (void *) ssGetPWorkValue(S, 6);
              mxArray * rhs[ 2 ];
              rhs[0] = mxCreateString("PIL:pil:TargetIOFopenError");
              rhs[1] = mxCreateString((char *) pFopenBuff);
              xilUtilsHandleError(pXILUtils, 2 , rhs );
              return XILHOSTAPPSVC_ERROR;
            }
          }                            /* if */
        }                              /* if */
      }                                /* if */
    } else {
      {
        void * pXILUtils = (void *) ssGetPWorkValue(S, 6);
        mxArray * rhs[ 2 ];
        rhs[0] = mxCreateString("PIL:pil:TargetIOFopenFidError");
        rhs[1] = mxCreateDoubleScalar(FOPEN_FID);
        xilUtilsHandleError(pXILUtils, 2 , rhs );
        return XILHOSTAPPSVC_ERROR;
      }
    }                                  /* if */
  }                                    /* if */

  (*mxMemUnitPtrPtr) = (*mxMemUnitPtrPtr) + FOPEN_NAME_SIZE;
  return XILHOSTAPPSVC_SUCCESS;
}

static boolean_T processResponseFprintf(SimStruct * S, uint8_T
  ** mxMemUnitPtrPtr)
{
  const int TARGET_IO_SUCCESS = 0;
  uint8_T FPRINTF_ERROR;
  uint16_T FPRINTF_FID;
  uint16_T FPRINTF_SIZE;

  {
    {
      uint8_T * simDataMemUnitPtr;
      simDataMemUnitPtr = (uint8_T *) &FPRINTF_ERROR;

      {
        size_t num_elements = 1;

        {
          copyIOData(simDataMemUnitPtr, *mxMemUnitPtrPtr, &*mxMemUnitPtrPtr,
                     num_elements, sizeof(uint8_T));
        }
      }
    }
  }

  {
    {
      uint8_T * simDataMemUnitPtr;
      simDataMemUnitPtr = (uint8_T *) &FPRINTF_FID;

      {
        size_t num_elements = 1;

        {
          copyIOData(simDataMemUnitPtr, *mxMemUnitPtrPtr, &*mxMemUnitPtrPtr,
                     num_elements, sizeof(uint16_T));
        }
      }
    }
  }

  {
    {
      uint8_T * simDataMemUnitPtr;
      simDataMemUnitPtr = (uint8_T *) &FPRINTF_SIZE;

      {
        size_t num_elements = 1;

        {
          copyIOData(simDataMemUnitPtr, *mxMemUnitPtrPtr, &*mxMemUnitPtrPtr,
                     num_elements, sizeof(uint16_T));
        }
      }
    }
  }

  if (FPRINTF_ERROR != TARGET_IO_SUCCESS) {
    {
      void * pXILUtils = (void *) ssGetPWorkValue(S, 6);
      mxArray * rhs[ 2 ];
      rhs[0] = mxCreateString("PIL:pil:TargetIOError");
      rhs[1] = mxCreateDoubleScalar(FPRINTF_ERROR);
      xilUtilsHandleError(pXILUtils, 2 , rhs );
      return XILHOSTAPPSVC_ERROR;
    }
  } else {
    targetIOFd_T * targetIOFdPtr = (targetIOFd_T *) ssGetPWorkValue(S, 3);
    if (targetIOFdPtr != NULL) {
      if (targetIOFdPtr->size > FPRINTF_FID) {
        if (targetIOFdPtr->Fd[FPRINTF_FID] != NULL) {
          uint8_T *pFprintfBuff;
          pFprintfBuff = (*mxMemUnitPtrPtr);
          if (pFprintfBuff[FPRINTF_SIZE-1] == '\0') {
            fprintf(targetIOFdPtr->Fd[FPRINTF_FID], "%s", pFprintfBuff);
          }                            /* if */
        }                              /* if */
      }                                /* if */
    }                                  /* if */
  }                                    /* if */

  (*mxMemUnitPtrPtr) = (*mxMemUnitPtrPtr) + FPRINTF_SIZE ;
  return XILHOSTAPPSVC_SUCCESS;
}

static boolean_T processResponseSignalRaised(SimStruct * S, uint8_T
  ** mxMemUnitPtrPtr)
{
  const char *signalStr[5] = { "SIGFPE", "SIGILL", "SIGABRT", "SIGSEGV",
    "Unknown Signal" };

  uint8_T errorId = **mxMemUnitPtrPtr;
  (*mxMemUnitPtrPtr)++;

  {
    void * pXILUtils = (void *) ssGetPWorkValue(S, 6);
    mxArray * rhs[ 3 ];
    rhs[0] = mxCreateString("Connectivity:target:CaughtTargetSignal");
    rhs[1] = mxCreateString(signalStr[errorId]);
    rhs[2] = mxCreateDoubleScalar(ssGetT(S));
    xilUtilsHandleError(pXILUtils, 3 , rhs );
    return XILHOSTAPPSVC_ERROR;
  }
}

static boolean_T processErrorAndTargetIOResponseCases(SimStruct * S, const int
  responseId, uint8_T ** mxMemUnitPtrPtr)
{
  switch (responseId) {
   case RESPONSE_ERROR:
    {
      return processResponseError(S, mxMemUnitPtrPtr);
    }

   case RESPONSE_PRINTF:
    {
      return processResponsePrintf(S, mxMemUnitPtrPtr);
    }

   case RESPONSE_FOPEN:
    {
      return processResponseFopen(S, mxMemUnitPtrPtr);
    }

   case RESPONSE_FPRINTF:
    {
      return processResponseFprintf(S, mxMemUnitPtrPtr);
    }

   case RESPONSE_SIGNAL_RAISED:
    {
      return processResponseSignalRaised(S, mxMemUnitPtrPtr);
    }

   default:
    {
      {
        void * pXILUtils = (void *) ssGetPWorkValue(S, 6);
        mxArray * rhs[ 2 ];
        rhs[0] = mxCreateString("PIL:pilverification:UnknownResponseId");
        rhs[1] = mxCreateDoubleScalar(responseId);
        xilUtilsHandleError(pXILUtils, 2 , rhs );
        return XILHOSTAPPSVC_ERROR;
      }
    }
  }                                    /* switch */
}

static size_t getBusElementDimension(SimStruct * S, DTypeId dType, int_T
  offsetIdx, const int_T ** dimsOut, int_T * numDims)
{
  int_T numDimensions = ssGetBusElementNumDimensions(S, dType, offsetIdx);
  const int_T *dims = ssGetBusElementDimensions(S, dType, offsetIdx);
  size_t numElements = 1;
  int j = 0;
  for (j = 0; j< numDimensions; j++) {
    numElements *= dims[j];
  }                                    /* for */

  *dimsOut = dims;
  *numDims = numDimensions;
  return numElements;
}

/* Process params function shared between mdlStart and mdlProcessParams */
static void processParams(SimStruct * S)
{
  if (ssGetPWork(S) != NULL) {
    int * pIsXILApplicationStarted = (int *) ssGetPWorkValue(S, 5);
    if ((pIsXILApplicationStarted!=NULL) && (*pIsXILApplicationStarted==1)) {
      /* update run time params */
      ssUpdateAllTunableParamsAsRunTimeParams(S);

      {
        uint8_T * mxMemUnitPtr;
        mwSize dataInSize = 0;
        XIL_IOBuffer_T * IOBufferPtr = (XIL_IOBuffer_T *) ssGetPWorkValue(S, 1);
        if (IOBufferPtr != NULL) {
          void * pXILService = (void *) ssGetPWorkValue(S, 9);
          if (pXILService != NULL) {
            if (xilHostAppSvcGrowIOBuffer(pXILService, IOBufferPtr, 125, 0)!=
                XILHOSTAPPSVC_SUCCESS) {
              return;
            }                          /* if */

            if (IOBufferPtr->data != NULL) {
              mxMemUnitPtr = (uint8_T *) IOBufferPtr->data;

              /* write command id */
              *mxMemUnitPtr = (uint8_T) XIL_PROCESS_PARAMS_COMMAND;
              mxMemUnitPtr++;

              {
                {
                  uint8_T * simDataMemUnitPtr;
                  uint32_T commandDataFcnid = 0;
                  simDataMemUnitPtr = (uint8_T *) &commandDataFcnid;

                  {
                    size_t num_elements = 1;

                    {
                      copyIOData(mxMemUnitPtr, simDataMemUnitPtr, &mxMemUnitPtr,
                                 num_elements, sizeof(uint32_T));
                    }
                  }
                }
              }

              {
                /* DataInterface: parameter, 1 */
                void * dataInterfacePtr;
                if (!ssGetModelRefGlobalParamData(S, 0, (void **)
                     (&dataInterfacePtr)))
                  return;

                {
                  uint8_T * simDataMemUnitPtr;
                  simDataMemUnitPtr = (uint8_T *) dataInterfacePtr;

                  {
                    size_t num_elements = 1;

                    {
                      copyIOData(mxMemUnitPtr, simDataMemUnitPtr, &mxMemUnitPtr,
                                 num_elements, sizeof(real64_T));
                    }
                  }
                }
              }

              {
                /* DataInterface: parameter, 2 */
                void * dataInterfacePtr;
                if (!ssGetModelRefGlobalParamData(S, 1, (void **)
                     (&dataInterfacePtr)))
                  return;

                {
                  uint8_T * simDataMemUnitPtr;
                  simDataMemUnitPtr = (uint8_T *) dataInterfacePtr;

                  {
                    size_t num_elements = 1;

                    {
                      copyIOData(mxMemUnitPtr, simDataMemUnitPtr, &mxMemUnitPtr,
                                 num_elements, sizeof(real64_T));
                    }
                  }
                }
              }

              {
                /* DataInterface: parameter, 3 */
                void * dataInterfacePtr;
                if (!ssGetModelRefGlobalParamData(S, 2, (void **)
                     (&dataInterfacePtr)))
                  return;

                {
                  uint8_T * simDataMemUnitPtr;
                  simDataMemUnitPtr = (uint8_T *) dataInterfacePtr;

                  {
                    size_t num_elements = 1;

                    {
                      copyIOData(mxMemUnitPtr, simDataMemUnitPtr, &mxMemUnitPtr,
                                 num_elements, sizeof(real64_T));
                    }
                  }
                }
              }

              {
                /* DataInterface: parameter, 4 */
                void * dataInterfacePtr;
                if (!ssGetModelRefGlobalParamData(S, 3, (void **)
                     (&dataInterfacePtr)))
                  return;

                {
                  uint8_T * simDataMemUnitPtr;
                  simDataMemUnitPtr = (uint8_T *) dataInterfacePtr;

                  {
                    size_t num_elements = 1;

                    {
                      copyIOData(mxMemUnitPtr, simDataMemUnitPtr, &mxMemUnitPtr,
                                 num_elements, sizeof(real64_T));
                    }
                  }
                }
              }

              {
                /* DataInterface: parameter, 5 */
                void * dataInterfacePtr;
                if (!ssGetModelRefGlobalParamData(S, 4, (void **)
                     (&dataInterfacePtr)))
                  return;

                {
                  uint8_T * simDataMemUnitPtr;
                  simDataMemUnitPtr = (uint8_T *) dataInterfacePtr;

                  {
                    size_t num_elements = 1;

                    {
                      copyIOData(mxMemUnitPtr, simDataMemUnitPtr, &mxMemUnitPtr,
                                 num_elements, sizeof(real64_T));
                    }
                  }
                }
              }

              {
                /* DataInterface: parameter, 6 */
                void * dataInterfacePtr;
                if (!ssGetModelRefGlobalParamData(S, 5, (void **)
                     (&dataInterfacePtr)))
                  return;

                {
                  uint8_T * simDataMemUnitPtr;
                  simDataMemUnitPtr = (uint8_T *) dataInterfacePtr;

                  {
                    size_t num_elements = 1;

                    {
                      copyIOData(mxMemUnitPtr, simDataMemUnitPtr, &mxMemUnitPtr,
                                 num_elements, sizeof(real64_T));
                    }
                  }
                }
              }

              {
                /* DataInterface: parameter, 7 */
                void * dataInterfacePtr;
                if (!ssGetModelRefGlobalParamData(S, 6, (void **)
                     (&dataInterfacePtr)))
                  return;

                {
                  uint8_T * simDataMemUnitPtr;
                  simDataMemUnitPtr = (uint8_T *) dataInterfacePtr;

                  {
                    size_t num_elements = 1;

                    {
                      copyIOData(mxMemUnitPtr, simDataMemUnitPtr, &mxMemUnitPtr,
                                 num_elements, sizeof(real64_T));
                    }
                  }
                }
              }

              {
                /* DataInterface: parameter, 8 */
                void * dataInterfacePtr;
                if (!ssGetModelRefGlobalParamData(S, 7, (void **)
                     (&dataInterfacePtr)))
                  return;

                {
                  uint8_T * simDataMemUnitPtr;
                  simDataMemUnitPtr = (uint8_T *) dataInterfacePtr;

                  {
                    size_t num_elements = 1;

                    {
                      copyIOData(mxMemUnitPtr, simDataMemUnitPtr, &mxMemUnitPtr,
                                 num_elements, sizeof(real64_T));
                    }
                  }
                }
              }

              {
                /* DataInterface: parameter, 9 */
                void * dataInterfacePtr;
                if (!ssGetModelRefGlobalParamData(S, 8, (void **)
                     (&dataInterfacePtr)))
                  return;

                {
                  uint8_T * simDataMemUnitPtr;
                  simDataMemUnitPtr = (uint8_T *) dataInterfacePtr;

                  {
                    size_t num_elements = 1;

                    {
                      copyIOData(mxMemUnitPtr, simDataMemUnitPtr, &mxMemUnitPtr,
                                 num_elements, sizeof(real64_T));
                    }
                  }
                }
              }

              {
                /* DataInterface: parameter, 10 */
                void * dataInterfacePtr;
                if (!ssGetModelRefGlobalParamData(S, 9, (void **)
                     (&dataInterfacePtr)))
                  return;

                {
                  uint8_T * simDataMemUnitPtr;
                  simDataMemUnitPtr = (uint8_T *) dataInterfacePtr;

                  {
                    size_t num_elements = 1;

                    {
                      copyIOData(mxMemUnitPtr, simDataMemUnitPtr, &mxMemUnitPtr,
                                 num_elements, sizeof(real64_T));
                    }
                  }
                }
              }

              {
                /* DataInterface: parameter, 11 */
                void * dataInterfacePtr;
                if (!ssGetModelRefGlobalParamData(S, 10, (void **)
                     (&dataInterfacePtr)))
                  return;

                {
                  uint8_T * simDataMemUnitPtr;
                  simDataMemUnitPtr = (uint8_T *) dataInterfacePtr;

                  {
                    size_t num_elements = 1;

                    {
                      copyIOData(mxMemUnitPtr, simDataMemUnitPtr, &mxMemUnitPtr,
                                 num_elements, sizeof(real64_T));
                    }
                  }
                }
              }

              {
                /* DataInterface: parameter, 12 */
                void * dataInterfacePtr;
                if (!ssGetModelRefGlobalParamData(S, 11, (void **)
                     (&dataInterfacePtr)))
                  return;

                {
                  uint8_T * simDataMemUnitPtr;
                  simDataMemUnitPtr = (uint8_T *) dataInterfacePtr;

                  {
                    size_t num_elements = 1;

                    {
                      copyIOData(mxMemUnitPtr, simDataMemUnitPtr, &mxMemUnitPtr,
                                 num_elements, sizeof(real64_T));
                    }
                  }
                }
              }

              {
                /* DataInterface: parameter, 13 */
                void * dataInterfacePtr;
                if (!ssGetModelRefGlobalParamData(S, 12, (void **)
                     (&dataInterfacePtr)))
                  return;

                {
                  uint8_T * simDataMemUnitPtr;
                  simDataMemUnitPtr = (uint8_T *) dataInterfacePtr;

                  {
                    size_t num_elements = 1;

                    {
                      copyIOData(mxMemUnitPtr, simDataMemUnitPtr, &mxMemUnitPtr,
                                 num_elements, sizeof(real64_T));
                    }
                  }
                }
              }

              {
                /* DataInterface: parameter, 14 */
                void * dataInterfacePtr;
                if (!ssGetModelRefGlobalParamData(S, 13, (void **)
                     (&dataInterfacePtr)))
                  return;

                {
                  uint8_T * simDataMemUnitPtr;
                  simDataMemUnitPtr = (uint8_T *) dataInterfacePtr;

                  {
                    size_t num_elements = 1;

                    {
                      copyIOData(mxMemUnitPtr, simDataMemUnitPtr, &mxMemUnitPtr,
                                 num_elements, sizeof(real64_T));
                    }
                  }
                }
              }

              {
                /* DataInterface: parameter, 15 */
                void * dataInterfacePtr;
                if (!ssGetModelRefGlobalParamData(S, 14, (void **)
                     (&dataInterfacePtr)))
                  return;

                {
                  uint8_T * simDataMemUnitPtr;
                  simDataMemUnitPtr = (uint8_T *) dataInterfacePtr;

                  {
                    size_t num_elements = 1;

                    {
                      copyIOData(mxMemUnitPtr, simDataMemUnitPtr, &mxMemUnitPtr,
                                 num_elements, sizeof(real64_T));
                    }
                  }
                }
              }
            }                          /* if */
          }                            /* if */
        }                              /* if */
      }

      {
        {
          uint8_T * mxMemUnitPtr;
          mwSize dataInSize = 0;
          XIL_IOBuffer_T * IOBufferPtr = (XIL_IOBuffer_T *) ssGetPWorkValue(S, 1);

          /* dispatch command to the target */
          if (commandDispatch(S, IOBufferPtr, 125)!=XILHOSTAPPSVC_SUCCESS) {
            return;
          }                            /* if */

          {
            XILCommandResponseType commandResponseType =
              XIL_COMMAND_NOT_COMPLETE;
            while (commandResponseType != XIL_STEP_COMPLETE) {
              /* receive command from the target */
              mwSize dataInSize = 0;
              if (commandResponse(S, &dataInSize, &commandResponseType) !=
                  XILHOSTAPPSVC_SUCCESS) {
                return;
              }                        /* if */

              if (dataInSize>0) {
                size_t dataInMemUnitSize = dataInSize;
                uint8_T responseId = 0;
                uint8_T * mxMemUnitPtrEnd;
                mxMemUnitPtr = (uint8_T *) IOBufferPtr->data;
                mxMemUnitPtrEnd = mxMemUnitPtr + dataInMemUnitSize - 1;
                while (mxMemUnitPtr <= mxMemUnitPtrEnd) {
                  /* read response id */
                  responseId = *mxMemUnitPtr;
                  mxMemUnitPtr++;
                  switch (responseId) {
                   case RESPONSE_ERROR:
                   case RESPONSE_PRINTF:
                   case RESPONSE_FOPEN:
                   case RESPONSE_FPRINTF:
                   case RESPONSE_SIGNAL_RAISED:
                    {
                      if (processErrorAndTargetIOResponseCases(S, responseId,
                           &mxMemUnitPtr)== XILHOSTAPPSVC_ERROR) {
                        return;
                      }                /* if */
                      break;
                    }

                   default:
                    {
                      {
                        void * pXILUtils = (void *) ssGetPWorkValue(S, 6);
                        mxArray * rhs[ 2 ];
                        rhs[0] = mxCreateString(
                          "PIL:pilverification:UnknownResponseId");
                        rhs[1] = mxCreateDoubleScalar(responseId);
                        xilUtilsHandleError(pXILUtils, 2 , rhs );
                        return;
                      }
                      break;
                    }
                  }                    /* switch */
                }                      /* while */
              }                        /* if */
            }                          /* while */
          }
        }
      }
    }                                  /* if */
  }                                    /* if */
}

static boolean_T startAndSetupApplication(SimStruct *S)
{
  {
    {
      mxArray *rhs[4];
      char * simulinkBlockPath = getSimulinkBlockPath(S);
      if (simulinkBlockPath == NULL) {
        ssSetErrorStatus(S,
                         "ModelBlock SIL/PIL unexpected error: getSimulinkBlockPath returned NULL pointer. Check search string was found in ssGetPath.\n");
        return false;
      }

      rhs[ 0 ] = mxCreateString(
        "@coder.connectivity.SimulinkInterface.getSILPILInterface");
      rhs[ 1 ] = mxCreateDoubleScalar( 4 );
      rhs[ 2 ] = mxCreateString(simulinkBlockPath);
      rhs[3] = mxCreateString("uint8");

      {
        void * pXILUtils = (void *) ssGetPWorkValue(S, 6);
        if (xilUtilsCallMATLAB(pXILUtils, 0, 0, 4, rhs,
                               "rtw.pil.SILPILInterface.sfunctionPILStartHook")
            !=XIL_UTILS_SUCCESS) {
          return false;
        }                              /* if */
      }

      mxFree((void *) simulinkBlockPath);
    }

    {                                  /* record that the XIL application has started */
      int * pIsXILApplicationStarted = (int *) ssGetPWorkValue(S, 5);
      *pIsXILApplicationStarted = 1;
      ssSetPWorkValue(S, 5, pIsXILApplicationStarted);
    }
  }

  {
    mxArray *rhs[3];
    mxArray *lhs[5];
    char * simulinkBlockPath = getSimulinkBlockPath(S);
    if (simulinkBlockPath == NULL) {
      ssSetErrorStatus(S,
                       "ModelBlock SIL/PIL unexpected error: getSimulinkBlockPath returned NULL pointer. Check search string was found in ssGetPath.\n");
      return false;
    }

    rhs[ 0 ] = mxCreateString(
      "@coder.connectivity.SimulinkInterface.getSILPILInterface");
    rhs[ 1 ] = mxCreateDoubleScalar( 4 );
    rhs[ 2 ] = mxCreateString(simulinkBlockPath);

    {
      void * pXILUtils = (void *) ssGetPWorkValue(S, 6);
      if (xilUtilsCallMATLAB(pXILUtils, 5, lhs, 3, rhs,
                             "rtw.pil.SILPILInterface.sfunctionGetRtIOStreamInfoHook")
          !=XIL_UTILS_SUCCESS) {
        return false;
      }                                /* if */
    }

    mxFree((void *) simulinkBlockPath);

    {
      XIL_RtIOStreamData_T* rtIOStreamDataPtr = (XIL_RtIOStreamData_T*) mxCalloc
        (1, sizeof(XIL_RtIOStreamData_T));
      if (rtIOStreamDataPtr == NULL) {
        ssSetErrorStatus( S,"Error in allocating memory through mxCalloc.");
        return false;
      }                                /* if */

      rtIOStreamDataPtr->lib = mxArrayToString(lhs[0]);
      rtIOStreamDataPtr->MATLABObject = mxDuplicateArray(lhs[1]);
      mexMakeMemoryPersistent(rtIOStreamDataPtr);
      mexMakeMemoryPersistent(rtIOStreamDataPtr->lib);
      mexMakeArrayPersistent(rtIOStreamDataPtr->MATLABObject);
      rtIOStreamDataPtr->streamID = *mxGetPr(lhs[2]);
      rtIOStreamDataPtr->recvTimeout = *mxGetPr(lhs[3]);
      rtIOStreamDataPtr->sendTimeout = *mxGetPr(lhs[4]);
      rtIOStreamDataPtr->isRtIOStreamCCall = 1;
      rtIOStreamDataPtr->ioMxClassID = mxUINT8_CLASS;
      rtIOStreamDataPtr->ioDataSize = sizeof(uint8_T);
      rtIOStreamDataPtr->targetRecvBufferSizeBytes = 128;
      rtIOStreamDataPtr->targetSendBufferSizeBytes = 128;

      {
        int errorStatus = rtIOStreamLoadLib(&rtIOStreamDataPtr->libH,
          rtIOStreamDataPtr->lib);
        if (errorStatus) {
          ssSetErrorStatus( S,"rtIOStreamLoadLib failed.");
          return false;
        }                              /* if */
      }

      ssSetPWorkValue(S, 0, rtIOStreamDataPtr);
    }

    {
      int i;
      for (i=0; i<5; i++) {
        mxDestroyArray(lhs[i]);
      }                                /* for */
    }
  }

  {
    XIL_IOBuffer_T* IOBufferPtr = (XIL_IOBuffer_T *) mxCalloc(1, sizeof
      (XIL_IOBuffer_T));
    if (IOBufferPtr == NULL) {
      ssSetErrorStatus( S,"Error in allocating memory through mxCalloc.");
      return false;
    }                                  /* if */

    mexMakeMemoryPersistent(IOBufferPtr);
    ssSetPWorkValue(S, 1, IOBufferPtr);
  }

  {
    SIL_DEBUGGING_DATA_T* silDebuggingDataPtr = (SIL_DEBUGGING_DATA_T*) mxCalloc
      (1, sizeof(SIL_DEBUGGING_DATA_T));
    char * simulinkBlockPath = getSimulinkBlockPath(S);
    if (simulinkBlockPath == NULL) {
      ssSetErrorStatus(S,
                       "ModelBlock SIL/PIL unexpected error: getSimulinkBlockPath returned NULL pointer. Check search string was found in ssGetPath.\n");
      return false;
    }

    if (silDebuggingDataPtr == NULL) {
      ssSetErrorStatus( S,
                       "Error in allocating memory through mxCalloc for SIL_DEBUGGING_DATA_T.");
      return false;
    }                                  /* if */

    silDebuggingDataPtr->componentBlockPath = strcpy((char *) mxCalloc(strlen
      (simulinkBlockPath)+1, sizeof(char)), simulinkBlockPath);
    silDebuggingDataPtr->SILPILInterfaceFcnStr = strcpy((char*) mxCalloc(57,
      sizeof(char)), "@coder.connectivity.SimulinkInterface.getSILPILInterface");
    silDebuggingDataPtr->inTheLoopType = 4;
    mexMakeMemoryPersistent(silDebuggingDataPtr);
    mexMakeMemoryPersistent(silDebuggingDataPtr->componentBlockPath);
    mexMakeMemoryPersistent(silDebuggingDataPtr->SILPILInterfaceFcnStr);
    ssSetPWorkValue(S, 2, silDebuggingDataPtr);
    mxFree((void *) simulinkBlockPath);
  }

  {
    targetIOFd_T * targetIOFdPtr = (targetIOFd_T *) mxCalloc(1, sizeof
      (targetIOFd_T));
    if (targetIOFdPtr == NULL) {
      return false;
    }                                  /* if */

    mexMakeMemoryPersistent(targetIOFdPtr);
    targetIOFdPtr->size = 0;
    targetIOFdPtr->Fd = NULL;
    targetIOFdPtr->fidOffset = -1;
    ssSetPWorkValue(S, 3, targetIOFdPtr);
  }

  {
    void* pConnectionOptions = NULL;
    void* pComms = NULL;
    void* pXILService = NULL;
    void* pMemUnitTransformer = NULL;
    void * pXILUtils = (void *) ssGetPWorkValue(S, 6);
    uint8_T memUnitSizeBytes = 1;
    uint8_T ioDataTypeSizeBytes = sizeof(uint8_T);
    XIL_RtIOStreamData_T * rtIOStreamDataPtr = (XIL_RtIOStreamData_T *)
      ssGetPWorkValue(S, 0);
    SIL_DEBUGGING_DATA_T * silDebuggingDataPtr = (SIL_DEBUGGING_DATA_T *)
      ssGetPWorkValue(S, 2);
    XIL_IOBuffer_T * IOBufferPtr = (XIL_IOBuffer_T *) ssGetPWorkValue(S, 1);
    void * pCoderAssumptionsApp = NULL;
    if (xilCommsCreate(&pComms, rtIOStreamDataPtr, silDebuggingDataPtr,
                       memUnitSizeBytes, pMemUnitTransformer, pXILUtils, 0) !=
        XILCOMMS_RTIOSTREAM_SUCCESS) {
      return false;
    }                                  /* if */

    if (xilHostAppSvcCreate(&pXILService, pComms, pXILUtils, IOBufferPtr,
                            memUnitSizeBytes, ioDataTypeSizeBytes, 0) !=
        XILHOSTAPPSVC_SUCCESS) {
      return false;
    }                                  /* if */

    {
      mxArray * codeGenComponent = mxCreateString("bms_f4");
      mxArray *rhs[3];
      char * simulinkBlockPath = getSimulinkBlockPath(S);
      if (simulinkBlockPath == NULL) {
        ssSetErrorStatus(S,
                         "ModelBlock SIL/PIL unexpected error: getSimulinkBlockPath returned NULL pointer. Check search string was found in ssGetPath.\n");
        return false;
      }

      rhs[ 0 ] = mxCreateString(
        "@coder.connectivity.SimulinkInterface.getSILPILInterface");
      rhs[ 1 ] = mxCreateDoubleScalar( 4 );
      rhs[ 2 ] = mxCreateString(simulinkBlockPath);
      if (coderAssumpHostAppSvcCreate(&pCoderAssumptionsApp, pComms, pXILUtils,
           0, 1, codeGenComponent, rhs[0], rhs[1], rhs[2], 1, 0, 0) !=
          CODERASSUMPHOSTAPPSVC_SUCCESS) {
        return false;
      }                                /* if */

      mxFree((void *) simulinkBlockPath);
    }

    xilCommsRegisterApplication(pComms, pXILService);
    xilCommsRegisterApplication(pComms, pCoderAssumptionsApp);
    ssSetPWorkValue(S, 9, pXILService);
    ssSetPWorkValue(S, 7, pComms);
    ssSetPWorkValue(S, 6, pXILUtils);
    ssSetPWorkValue(S, 10, pCoderAssumptionsApp);
  }

  {
    uint8_T * mxMemUnitPtr;
    mwSize dataInSize = 0;
    XIL_IOBuffer_T * IOBufferPtr = (XIL_IOBuffer_T *) ssGetPWorkValue(S, 1);
    if (IOBufferPtr != NULL) {
      void * pXILService = (void *) ssGetPWorkValue(S, 9);
      if (pXILService != NULL) {
        if (xilHostAppSvcGrowIOBuffer(pXILService, IOBufferPtr, 5, 0)!=
            XILHOSTAPPSVC_SUCCESS) {
          return false;
        }                              /* if */

        if (IOBufferPtr->data != NULL) {
          mxMemUnitPtr = (uint8_T *) IOBufferPtr->data;

          /* write command id */
          *mxMemUnitPtr = (uint8_T) XIL_INIT_COMMAND;
          mxMemUnitPtr++;

          {
            {
              uint8_T * simDataMemUnitPtr;
              uint32_T commandDataFcnid = 0;
              simDataMemUnitPtr = (uint8_T *) &commandDataFcnid;

              {
                size_t num_elements = 1;

                {
                  copyIOData(mxMemUnitPtr, simDataMemUnitPtr, &mxMemUnitPtr,
                             num_elements, sizeof(uint32_T));
                }
              }
            }
          }
        }                              /* if */
      }                                /* if */
    }                                  /* if */
  }

  {
    {
      uint8_T * mxMemUnitPtr;
      mwSize dataInSize = 0;
      XIL_IOBuffer_T * IOBufferPtr = (XIL_IOBuffer_T *) ssGetPWorkValue(S, 1);

      /* dispatch command to the target */
      if (commandDispatch(S, IOBufferPtr, 5)!=XILHOSTAPPSVC_SUCCESS) {
        return false;
      }                                /* if */

      {
        XILCommandResponseType commandResponseType = XIL_COMMAND_NOT_COMPLETE;
        while (commandResponseType != XIL_STEP_COMPLETE) {
          /* receive command from the target */
          mwSize dataInSize = 0;
          if (commandResponse(S, &dataInSize, &commandResponseType) !=
              XILHOSTAPPSVC_SUCCESS) {
            return false;
          }                            /* if */

          if (dataInSize>0) {
            size_t dataInMemUnitSize = dataInSize;
            uint8_T responseId = 0;
            uint8_T * mxMemUnitPtrEnd;

#define RESPONSE_TYPE_SIZE             7

            mxMemUnitPtr = (uint8_T *) IOBufferPtr->data;
            mxMemUnitPtrEnd = mxMemUnitPtr + dataInMemUnitSize - 1;
            while (mxMemUnitPtr <= mxMemUnitPtrEnd) {
              /* read response id */
              responseId = *mxMemUnitPtr;
              mxMemUnitPtr++;
              switch (responseId) {
               case RESPONSE_ERROR:
               case RESPONSE_PRINTF:
               case RESPONSE_FOPEN:
               case RESPONSE_FPRINTF:
               case RESPONSE_SIGNAL_RAISED:
                {
                  if (processErrorAndTargetIOResponseCases(S, responseId,
                       &mxMemUnitPtr)== XILHOSTAPPSVC_ERROR) {
                    return false;
                  }                    /* if */
                  break;
                }

               case RESPONSE_TYPE_SIZE:
                {
                  uint8_T typeBytes;
                  uint8_T typeId = *mxMemUnitPtr;
                  mxMemUnitPtr++;
                  typeBytes = *mxMemUnitPtr;
                  mxMemUnitPtr++;
                  switch (typeId) {
                   case SS_SINGLE:
                    {
                      if (typeBytes != 4) {
                        {
                          void * pXILUtils = (void *) ssGetPWorkValue(S, 6);
                          mxArray * rhs[ 3 ];
                          rhs[0] = mxCreateString(
                            "PIL:pilverification:SingleUnsupported");
                          rhs[1] = mxCreateDoubleScalar(4);
                          rhs[2] = mxCreateDoubleScalar(typeBytes);
                          xilUtilsHandleError(pXILUtils, 3 , rhs );
                          return false;
                        }
                      }                /* if */
                      break;
                    }

                   case SS_DOUBLE:
                    {
                      if (typeBytes != 8) {
                        {
                          void * pXILUtils = (void *) ssGetPWorkValue(S, 6);
                          mxArray * rhs[ 3 ];
                          rhs[0] = mxCreateString(
                            "PIL:pilverification:DoubleUnsupported");
                          rhs[1] = mxCreateDoubleScalar(8);
                          rhs[2] = mxCreateDoubleScalar(typeBytes);
                          xilUtilsHandleError(pXILUtils, 3 , rhs );
                          return false;
                        }
                      }                /* if */
                      break;
                    }

                   default:
                    {
                      {
                        void * pXILUtils = (void *) ssGetPWorkValue(S, 6);
                        mxArray * rhs[ 2 ];
                        rhs[0] = mxCreateString(
                          "PIL:pilverification:UnknownTypeId");
                        rhs[1] = mxCreateDoubleScalar(typeId);
                        xilUtilsHandleError(pXILUtils, 2 , rhs );
                        return false;
                      }
                      break;
                    }
                  }                    /* switch */
                  break;
                }

               default:
                {
                  {
                    void * pXILUtils = (void *) ssGetPWorkValue(S, 6);
                    mxArray * rhs[ 2 ];
                    rhs[0] = mxCreateString(
                      "PIL:pilverification:UnknownResponseId");
                    rhs[1] = mxCreateDoubleScalar(responseId);
                    xilUtilsHandleError(pXILUtils, 2 , rhs );
                    return false;
                  }
                  break;
                }
              }                        /* switch */
            }                          /* while */
          }                            /* if */
        }                              /* while */
      }
    }
  }

  /* initialize parameters */
  processParams(S);

  {
    /* DataInterface: output, 1 */
    void * dataInterfacePtr = (void *) ssGetOutputPortSignal(S, 0);
  }

  return true;
}

static void sendInitializeCommand(SimStruct *S)
{
  {
    uint8_T * mxMemUnitPtr;
    mwSize dataInSize = 0;
    XIL_IOBuffer_T * IOBufferPtr = (XIL_IOBuffer_T *) ssGetPWorkValue(S, 1);
    if (IOBufferPtr != NULL) {
      void * pXILService = (void *) ssGetPWorkValue(S, 9);
      if (pXILService != NULL) {
        if (xilHostAppSvcGrowIOBuffer(pXILService, IOBufferPtr, 5, 0)!=
            XILHOSTAPPSVC_SUCCESS) {
          return;
        }                              /* if */

        if (IOBufferPtr->data != NULL) {
          mxMemUnitPtr = (uint8_T *) IOBufferPtr->data;

          /* write command id */
          *mxMemUnitPtr = (uint8_T) XIL_INITIALIZE_COMMAND;
          mxMemUnitPtr++;

          {
            {
              uint8_T * simDataMemUnitPtr;
              uint32_T commandDataFcnid = 0;
              simDataMemUnitPtr = (uint8_T *) &commandDataFcnid;

              {
                size_t num_elements = 1;

                {
                  copyIOData(mxMemUnitPtr, simDataMemUnitPtr, &mxMemUnitPtr,
                             num_elements, sizeof(uint32_T));
                }
              }
            }
          }
        }                              /* if */
      }                                /* if */
    }                                  /* if */
  }

  {
    {
      uint8_T * mxMemUnitPtr;
      mwSize dataInSize = 0;
      XIL_IOBuffer_T * IOBufferPtr = (XIL_IOBuffer_T *) ssGetPWorkValue(S, 1);

      /* dispatch command to the target */
      if (commandDispatch(S, IOBufferPtr, 5)!=XILHOSTAPPSVC_SUCCESS) {
        return;
      }                                /* if */

      {
        XILCommandResponseType commandResponseType = XIL_COMMAND_NOT_COMPLETE;
        while (commandResponseType != XIL_STEP_COMPLETE) {
          /* receive command from the target */
          mwSize dataInSize = 0;
          if (commandResponse(S, &dataInSize, &commandResponseType) !=
              XILHOSTAPPSVC_SUCCESS) {
            return;
          }                            /* if */

          if (dataInSize>0) {
            size_t dataInMemUnitSize = dataInSize;
            uint8_T responseId = 0;
            uint8_T * mxMemUnitPtrEnd;
            mxMemUnitPtr = (uint8_T *) IOBufferPtr->data;
            mxMemUnitPtrEnd = mxMemUnitPtr + dataInMemUnitSize - 1;
            while (mxMemUnitPtr <= mxMemUnitPtrEnd) {
              /* read response id */
              responseId = *mxMemUnitPtr;
              mxMemUnitPtr++;
              switch (responseId) {
               case RESPONSE_ERROR:
               case RESPONSE_PRINTF:
               case RESPONSE_FOPEN:
               case RESPONSE_FPRINTF:
               case RESPONSE_SIGNAL_RAISED:
                {
                  if (processErrorAndTargetIOResponseCases(S, responseId,
                       &mxMemUnitPtr)== XILHOSTAPPSVC_ERROR) {
                    return;
                  }                    /* if */
                  break;
                }

               case RESPONSE_OUTPUT_PRE_DATA:
                {
                  break;
                }

               case RESPONSE_OUTPUT_DATA:
                {
                  {
                    /* DataInterface: output, 1 */
                    void * dataInterfacePtr = (void *) ssGetOutputPortSignal(S,
                      0);

                    {
                      uint8_T * simDataMemUnitPtr;
                      uint32_T offsetIdx;
                      for (offsetIdx=0; offsetIdx< 4; offsetIdx++) {
                        slDataTypeAccess * dta = ssGetDataTypeAccess(S);
                        const char * bpath = ssGetPath(S);

                        {
                          /* DataInterface: output, 1 */
                          simDataMemUnitPtr = ( uint8_T *) dataInterfacePtr;
                          simDataMemUnitPtr = (uint8_T*) (((char *)
                            simDataMemUnitPtr) +
                            dtaGetDataTypeElementOffset(dta, bpath,
                            ssGetDataTypeId(S, "BusOutputBMS"), 0) +
                            dtaGetDataTypeElementOffset(dta, bpath,
                            ssGetDataTypeId(S, "BMSContactorModuleCmd"),
                            offsetIdx));

                          {
                            DTypeId dType = ssGetDataTypeId(S,
                              "BMSContactorModuleCmd");
                            size_t num_elements;
                            const int_T * busElementsDims;
                            int_T busElementNumDims;
                            DTypeId elemTypeId = ssGetBusElementDataType(S,
                              dType, offsetIdx);
                            if (ssIsStringDataType(S, elemTypeId)) {
                              num_elements = ssGetStringDataTypeBufferSize(S,
                                elemTypeId);
                            } else {
                              num_elements = getBusElementDimension(S, dType,
                                offsetIdx, &busElementsDims, &busElementNumDims);
                            }          /* if */

                            {
                              if (ssIsStringDataType(S, elemTypeId)) {
                                copyStringIOData(simDataMemUnitPtr, mxMemUnitPtr,
                                                 &mxMemUnitPtr, num_elements,
                                                 sizeof(char_T), 0);
                              } else {
                                copyIOData(simDataMemUnitPtr, mxMemUnitPtr,
                                           &mxMemUnitPtr, num_elements,
                                           ssGetDataTypeSize(S, elemTypeId));
                              }        /* if */
                            }
                          }
                        }
                      }                /* for */
                    }

                    {
                      uint8_T * simDataMemUnitPtr;
                      uint32_T offsetIdx;
                      for (offsetIdx=0; offsetIdx< 3; offsetIdx++) {
                        slDataTypeAccess * dta = ssGetDataTypeAccess(S);
                        const char * bpath = ssGetPath(S);

                        {
                          /* DataInterface: output, 1 */
                          simDataMemUnitPtr = ( uint8_T *) dataInterfacePtr;
                          simDataMemUnitPtr = (uint8_T*) (((char *)
                            simDataMemUnitPtr) +
                            dtaGetDataTypeElementOffset(dta, bpath,
                            ssGetDataTypeId(S, "BusOutputBMS"), 1) +
                            dtaGetDataTypeElementOffset(dta, bpath,
                            ssGetDataTypeId(S, "BMSBatteryPackInput"), offsetIdx));

                          {
                            DTypeId dType = ssGetDataTypeId(S,
                              "BMSBatteryPackInput");
                            size_t num_elements;
                            const int_T * busElementsDims;
                            int_T busElementNumDims;
                            DTypeId elemTypeId = ssGetBusElementDataType(S,
                              dType, offsetIdx);
                            if (ssIsStringDataType(S, elemTypeId)) {
                              num_elements = ssGetStringDataTypeBufferSize(S,
                                elemTypeId);
                            } else {
                              num_elements = getBusElementDimension(S, dType,
                                offsetIdx, &busElementsDims, &busElementNumDims);
                            }          /* if */

                            {
                              if (ssIsStringDataType(S, elemTypeId)) {
                                copyStringIOData(simDataMemUnitPtr, mxMemUnitPtr,
                                                 &mxMemUnitPtr, num_elements,
                                                 sizeof(char_T), 0);
                              } else {
                                copyIOData(simDataMemUnitPtr, mxMemUnitPtr,
                                           &mxMemUnitPtr, num_elements,
                                           ssGetDataTypeSize(S, elemTypeId));
                              }        /* if */
                            }
                          }
                        }
                      }                /* for */
                    }

                    {
                      uint8_T * simDataMemUnitPtr;
                      uint32_T offsetIdx;
                      for (offsetIdx=0; offsetIdx< 2; offsetIdx++) {
                        slDataTypeAccess * dta = ssGetDataTypeAccess(S);
                        const char * bpath = ssGetPath(S);

                        {
                          /* DataInterface: output, 1 */
                          simDataMemUnitPtr = ( uint8_T *) dataInterfacePtr;
                          simDataMemUnitPtr = (uint8_T*) (((char *)
                            simDataMemUnitPtr) +
                            dtaGetDataTypeElementOffset(dta, bpath,
                            ssGetDataTypeId(S, "BusOutputBMS"), 2) +
                            dtaGetDataTypeElementOffset(dta, bpath,
                            ssGetDataTypeId(S, "BusSOCEstimation"), offsetIdx));

                          {
                            DTypeId dType = ssGetDataTypeId(S,
                              "BusSOCEstimation");
                            size_t num_elements;
                            const int_T * busElementsDims;
                            int_T busElementNumDims;
                            DTypeId elemTypeId = ssGetBusElementDataType(S,
                              dType, offsetIdx);
                            if (ssIsStringDataType(S, elemTypeId)) {
                              num_elements = ssGetStringDataTypeBufferSize(S,
                                elemTypeId);
                            } else {
                              num_elements = getBusElementDimension(S, dType,
                                offsetIdx, &busElementsDims, &busElementNumDims);
                            }          /* if */

                            {
                              if (ssIsStringDataType(S, elemTypeId)) {
                                copyStringIOData(simDataMemUnitPtr, mxMemUnitPtr,
                                                 &mxMemUnitPtr, num_elements,
                                                 sizeof(char_T), 0);
                              } else {
                                copyIOData(simDataMemUnitPtr, mxMemUnitPtr,
                                           &mxMemUnitPtr, num_elements,
                                           ssGetDataTypeSize(S, elemTypeId));
                              }        /* if */
                            }
                          }
                        }
                      }                /* for */
                    }

                    {
                      uint8_T * simDataMemUnitPtr;
                      uint32_T offsetIdx;
                      for (offsetIdx=0; offsetIdx< 8; offsetIdx++) {
                        slDataTypeAccess * dta = ssGetDataTypeAccess(S);
                        const char * bpath = ssGetPath(S);

                        {
                          /* DataInterface: output, 1 */
                          simDataMemUnitPtr = ( uint8_T *) dataInterfacePtr;
                          simDataMemUnitPtr = (uint8_T*) (((char *)
                            simDataMemUnitPtr) +
                            dtaGetDataTypeElementOffset(dta, bpath,
                            ssGetDataTypeId(S, "BusOutputBMS"), 3) +
                            dtaGetDataTypeElementOffset(dta, bpath,
                            ssGetDataTypeId(S, "BMSFaultOutput"), offsetIdx));

                          {
                            DTypeId dType = ssGetDataTypeId(S, "BMSFaultOutput");
                            size_t num_elements;
                            const int_T * busElementsDims;
                            int_T busElementNumDims;
                            DTypeId elemTypeId = ssGetBusElementDataType(S,
                              dType, offsetIdx);
                            if (ssIsStringDataType(S, elemTypeId)) {
                              num_elements = ssGetStringDataTypeBufferSize(S,
                                elemTypeId);
                            } else {
                              num_elements = getBusElementDimension(S, dType,
                                offsetIdx, &busElementsDims, &busElementNumDims);
                            }          /* if */

                            {
                              if (ssIsStringDataType(S, elemTypeId)) {
                                copyStringIOData(simDataMemUnitPtr, mxMemUnitPtr,
                                                 &mxMemUnitPtr, num_elements,
                                                 sizeof(char_T), 0);
                              } else {
                                copyIOData(simDataMemUnitPtr, mxMemUnitPtr,
                                           &mxMemUnitPtr, num_elements,
                                           ssGetDataTypeSize(S, elemTypeId));
                              }        /* if */
                            }
                          }
                        }
                      }                /* for */
                    }
                  }
                  break;
                }

               default:
                {
                  {
                    void * pXILUtils = (void *) ssGetPWorkValue(S, 6);
                    mxArray * rhs[ 2 ];
                    rhs[0] = mxCreateString(
                      "PIL:pilverification:UnknownResponseId");
                    rhs[1] = mxCreateDoubleScalar(responseId);
                    xilUtilsHandleError(pXILUtils, 2 , rhs );
                    return;
                  }
                  break;
                }
              }                        /* switch */
            }                          /* while */
          }                            /* if */
        }                              /* while */
      }
    }
  }
}

static void initializeInfAndMinusInf(void)
{
  typedef struct {
    struct {
      uint32_T wordL;
      uint32_T wordH;
    } words;
  } LittleEndianIEEEDouble;

  rtInf = 0.0;
  rtMinusInf = 0.0;

  {
    union {
      LittleEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal1;

    tmpVal1.bitVal.words.wordH = 0x7FF00000U;
    tmpVal1.bitVal.words.wordL = 0x00000000U;
    rtInf = tmpVal1.fltVal;
  }

  {
    union {
      LittleEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal2;

    tmpVal2.bitVal.words.wordH = 0xFFF00000U;
    tmpVal2.bitVal.words.wordL = 0x00000000U;
    rtMinusInf = tmpVal2.fltVal;
  }
}

static void mdlSystemInitialize(SimStruct *S)
{
  if (ssRTWGenIsCodeGen(S) || ssIsExternalSim(S)) {
    return;
  }                                    /* if */

  {
    int * pIsXILApplicationStartedLocal = (int *) ssGetPWorkValue(S, 5);
    if (pIsXILApplicationStartedLocal == NULL || (*pIsXILApplicationStartedLocal)
        == 0) {
      boolean_T applicationStarted = startAndSetupApplication(S);
      if (!applicationStarted) {
        return;
      }                                /* if */
    }                                  /* if */

    sendInitializeCommand(S);
  }
}

static void mdlPeriodicOutputUpdate(SimStruct *S, int_T tid);

/* This function checks the attributes of tunable parameters. */
#define MDL_CHECK_PARAMETERS
#if defined(MDL_CHECK_PARAMETERS) && defined(MATLAB_MEX_FILE)

static void mdlCheckParameters(SimStruct *S)
{
}

#endif                                 /* MDL_CHECK_PARAMETERS */

static void mdlInitializeSizes(SimStruct *S)
{
  ssSetNumSFcnParams(S, 0);            /* Number of expected parameters */
  if (ssGetNumSFcnParams(S) == ssGetSFcnParamsCount(S)) {

#if defined(MDL_CHECK_PARAMETERS)

    mdlCheckParameters(S);

#endif

    if (ssGetErrorStatus(S) != (NULL))
      return;
  } else {
    /* Parameter mismatch will be reported by Simulink */
    return;
  }

  ssSetNumContStates(S, 0);
  ssSetNumDiscStates(S, 0);

  /* no support for SimState */
  ssSetSimStateCompliance(S, DISALLOW_SIM_STATE);

  /* Allow signal dimensions greater than 2 */
  ssAllowSignalsWithMoreThan2D(S);

  /* Allow fixed-point data types with 33 or more bits */
  ssFxpSetU32BitRegionCompliant(S,1);
  initializeInfAndMinusInf();
  ssSetRTWGeneratedSFcn(S, 2);
  if ((S->mdlInfo->genericFcn != (NULL)) && (!(S->mdlInfo->genericFcn)(S,
        GEN_FCN_CHK_MODELREF_SFUN_HAS_MODEL_BLOCK, -1, (NULL)))) {
    return;
  }

  slmrInitializeIOPortDataVectors(S, 2, 1);
  if (!ssSetNumInputPorts(S, 2))
    return;
  if (!ssSetInputPortVectorDimension(S, 0, 1))
    return;
  ssSetInputPortDimensionsMode(S, 0, FIXED_DIMS_MODE);
  ssSetInputPortFrameData(S, 0, FRAME_NO);
  if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {

#if defined (MATLAB_MEX_FILE)

    {
      DTypeId dataTypeIdReg;
      ssRegisterTypeFromNamedObject(
        S,
        "BusInputBMS",
        &dataTypeIdReg);
      if (dataTypeIdReg == INVALID_DTYPE_ID)
        return;
      ssSetInputPortDataType(S, 0, dataTypeIdReg);
    }

#endif

  }

  if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {

#if defined (MATLAB_MEX_FILE)

    UnitId unitIdReg;
    ssRegisterUnitFromExpr(
      S,
      "",
      &unitIdReg);
    if (unitIdReg == INVALID_UNIT_ID)
      return;
    ssSetInputPortUnit(S, 0, unitIdReg);

#endif

  }

  ssSetInputPortDirectFeedThrough(S, 0, 1);
  ssSetInputPortRequiredContiguous(S, 0, 1);
  ssSetInputPortOverWritable(S, 0, false);
  ssSetInputPortSampleTime(S, 0, 0.01);
  ssSetInputPortOffsetTime(S, 0, 0.0);
  if (!ssSetInputPortVectorDimension(S, 1, 1))
    return;
  ssSetInputPortDimensionsMode(S, 1, FIXED_DIMS_MODE);
  ssSetInputPortFrameData(S, 1, FRAME_NO);
  if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {

#if defined (MATLAB_MEX_FILE)

    {
      DTypeId dataTypeIdReg;
      ssRegisterTypeFromNamedObject(
        S,
        "BusSimulationInput",
        &dataTypeIdReg);
      if (dataTypeIdReg == INVALID_DTYPE_ID)
        return;
      ssSetInputPortDataType(S, 1, dataTypeIdReg);
    }

#endif

  }

  if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {

#if defined (MATLAB_MEX_FILE)

    UnitId unitIdReg;
    ssRegisterUnitFromExpr(
      S,
      "",
      &unitIdReg);
    if (unitIdReg == INVALID_UNIT_ID)
      return;
    ssSetInputPortUnit(S, 1, unitIdReg);

#endif

  }

  ssSetInputPortDirectFeedThrough(S, 1, 1);
  ssSetInputPortRequiredContiguous(S, 1, 1);
  ssSetInputPortOverWritable(S, 1, false);
  ssSetInputPortSampleTime(S, 1, 0.01);
  ssSetInputPortOffsetTime(S, 1, 0.0);
  if (!ssSetNumOutputPorts(S, 1))
    return;
  if (!ssSetOutputPortVectorDimension(S, 0, 1))
    return;
  ssSetOutputPortDimensionsMode(S, 0, FIXED_DIMS_MODE);
  ssSetOutputPortFrameData(S, 0, FRAME_NO);
  if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {

#if defined (MATLAB_MEX_FILE)

    {
      DTypeId dataTypeIdReg;
      ssRegisterTypeFromNamedObject(
        S,
        "BusOutputBMS",
        &dataTypeIdReg);
      if (dataTypeIdReg == INVALID_DTYPE_ID)
        return;
      ssSetOutputPortDataType(S, 0, dataTypeIdReg);
    }

#endif

  }

  if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {

#if defined (MATLAB_MEX_FILE)

    UnitId unitIdReg;
    ssRegisterUnitFromExpr(
      S,
      "",
      &unitIdReg);
    if (unitIdReg == INVALID_UNIT_ID)
      return;
    ssSetOutputPortUnit(S, 0, unitIdReg);

#endif

  }

  ssSetOutputPortSampleTime(S, 0, 0.01);
  ssSetOutputPortOffsetTime(S, 0, 0.0);
  if (ssRTWGenIsCodeGen(S) || ssIsExternalSim(S) ) {
    ssSetOutputPortOkToMerge(S, 0, SS_NOT_OK_TO_MERGE);
  }                                    /* if */

  ssSetAcceptsFcnCallInputs(S);        /* All sample times are available through ports. Use port based sample times. */
  ssSetNumSampleTimes(S, PORT_BASED_SAMPLE_TIMES);
  ssSetParameterTuningCompliance(S, true);
  ssSetModelReferenceSampleTimeInheritanceRule(S,
    DISALLOW_SAMPLE_TIME_INHERITANCE);
  ssSetOptions(S, SS_OPTION_ALLOW_CONSTANT_PORT_SAMPLE_TIME |
               SS_OPTION_SUPPORTS_ALIAS_DATA_TYPES |
               SS_OPTION_DISALLOW_CONSTANT_SAMPLE_TIME |
               SS_OPTION_CALL_TERMINATE_ON_EXIT);
  slmrRegisterSystemInitializeMethod(S, mdlSystemInitialize);
  slmrRegisterPeriodicOutputUpdateMethod(S, mdlPeriodicOutputUpdate);
  if (ssRTWGenIsCodeGen(S) || ssIsExternalSim(S) ) {
    ssSetNumPWork(S, 0);
  } else {
    ssSetNumPWork(S, 11);
  }                                    /* if */

  ssSetNumRWork(S, 0);
  ssSetNumIWork(S, 0);
  ssSetNumModes(S, 0);
  ssSetNumNonsampledZCs(S, 0);
  ssSetModelReferenceNormalModeSupport(S, MDL_START_AND_MDL_PROCESS_PARAMS_OK);

#if SS_SFCN_FOR_SIM

  if (S->mdlInfo->genericFcn != (NULL) &&
      ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
    ssRegModelRefMdlInfo(S, "bms_f4", rtMdlInfo_bms_f4, 0);
  }

#endif

  /* DWork */
  if (!ssRTWGenIsAccelerator(S)) {
    ssSetNumDWork(S, 0);
  }                                    /* if */
}

#define MDL_SET_INPUT_PORT_SAMPLE_TIME                           /* Change to #undef to remove function */
#if defined(MDL_SET_INPUT_PORT_SAMPLE_TIME) && defined(MATLAB_MEX_FILE)

static void mdlSetInputPortSampleTime(SimStruct *S, int_T portIdx, real_T
  sampleTime, real_T offsetTime)
{
  /* sample times are fully specified, not inherited */
}

#endif                                 /* MDL_SET_INPUT_PORT_SAMPLE_TIME */

#define MDL_SET_OUTPUT_PORT_SAMPLE_TIME                          /* Change to #undef to remove function */
#if defined(MDL_SET_OUTPUT_PORT_SAMPLE_TIME) && defined(MATLAB_MEX_FILE)

static void mdlSetOutputPortSampleTime(SimStruct *S, int_T portIdx, real_T
  sampleTime, real_T offsetTime)
{
  /* sample times are fully specified, not inherited */
}

#endif                                 /* MDL_SET_OUTPUT_PORT_SAMPLE_TIME */

static void mdlInitializeSampleTimes(SimStruct *S)
{
  /* This block has port based sample time. */
  return;
}

#define MDL_SETUP_RUNTIME_RESOURCES                              /* Change to #undef to remove function */
#if defined(MDL_SETUP_RUNTIME_RESOURCES)

static void mdlSetupRuntimeResources(SimStruct *S)
{
  if (ssRTWGenIsCodeGen(S) || ssIsExternalSim(S)) {
    return;
  }                                    /* if */

  {
    mxArray * error = NULL;
    error = mexCallMATLABWithTrap( 0, NULL, 0, NULL,
      "rtw.pil.checkEmbeddedCoderInstalled");
    if (error != NULL) {
      mexCallMATLAB( 0, NULL, 1, &error, "throw");
    }                                  /* if */
  }

  {
    mxArray * lhs[1];
    mxArray * error = NULL;
    char * installVersion;
    error = mexCallMATLABWithTrap(1, lhs, 0, NULL, "rtw.pil.getPILVersion");
    if (error != NULL) {
      mxDestroyArray(error);
      ssSetErrorStatus( S,
                       "Failed to determine the installed In-the-Loop version for comparison against the In-the-Loop s-function version (release 9.10 (R2021a)_15). To avoid this error, remove the In-the-Loop s-function from your MATLAB path (e.g. delete it or move to a clean working directory).");
      return;
    }                                  /* if */

    if (mxIsEmpty(lhs[0])) {
      ssSetErrorStatus( S,"rtw.pil.getPILVersion returned empty!");
      return;
    }                                  /* if */

    installVersion = mxArrayToString(lhs[0]);
    mxDestroyArray(lhs[0]);
    if (installVersion == NULL) {
      ssSetErrorStatus( S,"Failed to determine installed In-the-Loop version.");
      return;
    }                                  /* if */

    if (strcmp(installVersion, "9.10 (R2021a)_15") != 0) {
      ssSetErrorStatus( S,
                       "The In-the-Loop s-function is incompatible with the installed In-the-Loop version (see ver('matlab')); it was generated for release 9.10 (R2021a)_15. To avoid this error, remove the In-the-Loop s-function from your MATLAB path (e.g. delete it or move to a clean working directory)");
      return;
    }                                  /* if */

    mxFree(installVersion);
  }

  {
    int retValXILUtils = XIL_UTILS_SUCCESS;
    void* pXILUtils = NULL;
    retValXILUtils = xilSimulinkUtilsCreate(&pXILUtils, S);
    if (retValXILUtils!=XIL_UTILS_SUCCESS) {
      ssSetErrorStatus( S,"Error instantiating XIL Utils!");
      return;
    }                                  /* if */

    ssSetPWorkValue(S, 6, pXILUtils);
  }

  if (ssGetSimMode(S) != SS_SIMMODE_NORMAL) {
    void * pXILUtils = (void *) ssGetPWorkValue(S, 6);
    if (pXILUtils) {
      mxArray *rhs[3];
      char * simulinkBlockPath = getSimulinkBlockPath(S);
      if (simulinkBlockPath == NULL) {
        ssSetErrorStatus(S,
                         "ModelBlock SIL/PIL unexpected error: getSimulinkBlockPath returned NULL pointer. Check search string was found in ssGetPath.\n");
        return;
      }

      rhs[ 0 ] = mxCreateString(
        "@coder.connectivity.SimulinkInterface.getSILPILInterface");
      rhs[ 1 ] = mxCreateDoubleScalar( 4 );
      rhs[ 2 ] = mxCreateString(simulinkBlockPath);
      xilUtilsCallMATLAB(pXILUtils, 0, NULL, 3, rhs,
                         "rtw.pil.acceleratedModeNotSupported");
      mxFree((void *) simulinkBlockPath);
    }                                  /* if */
  }                                    /* if */

  {
    int * pCommErrorOccurred = (int *) mxCalloc(1, sizeof(int));
    if (pCommErrorOccurred == NULL) {
      ssSetErrorStatus( S,
                       "Error in allocating memory for pCommErrorOccurred through mxCalloc.");
      return;
    }                                  /* if */

    *pCommErrorOccurred = 0;
    mexMakeMemoryPersistent(pCommErrorOccurred);
    ssSetPWorkValue(S, 4, pCommErrorOccurred);
  }

  {
    int * pIsXILApplicationStarted = (int *) mxCalloc(1, sizeof(int));
    if (pIsXILApplicationStarted == NULL) {
      ssSetErrorStatus( S,
                       "Error in allocating memory for pIsXILApplicationStarted through mxCalloc.");
      return;
    }                                  /* if */

    *pIsXILApplicationStarted = 0;
    mexMakeMemoryPersistent(pIsXILApplicationStarted);
    ssSetPWorkValue(S, 5, pIsXILApplicationStarted);
  }

  {
    mxArray *rhs[4];
    mxArray *lhs[1];
    char * rootLoggingPath;
    char * simulinkBlockPath = getSimulinkBlockPath(S);
    if (simulinkBlockPath == NULL) {
      ssSetErrorStatus(S,
                       "ModelBlock SIL/PIL unexpected error: getSimulinkBlockPath returned NULL pointer. Check search string was found in ssGetPath.\n");
      return;
    }

    rhs[ 0 ] = mxCreateString(
      "@coder.connectivity.SimulinkInterface.getSILPILInterface");
    rhs[ 1 ] = mxCreateDoubleScalar( 4 );
    rhs[ 2 ] = mxCreateString(simulinkBlockPath);
    rhs[3] = mxCreateString(ssGetPath(ssGetRootSS(S)));

    {
      void * pXILUtils = (void *) ssGetPWorkValue(S, 6);
      if (xilUtilsCallMATLAB(pXILUtils, 1, lhs, 4, rhs,
                             "rtw.pil.SILPILInterface.sfunctionInitializeHook")
          !=XIL_UTILS_SUCCESS) {
        return;
      }                                /* if */
    }

    rootLoggingPath = mxArrayToString(lhs[0]);
    mxDestroyArray(lhs[0]);
    mxFree((void *) simulinkBlockPath);
    mxFree(rootLoggingPath);
  }
}

#endif                                 /* MDL_SETUP_RUNTIME_RESOURCES */

#define MDL_SIM_STATUS_CHANGE                                    /* Change to #undef to remove function */
#if defined(MDL_SIM_STATUS_CHANGE)

static void mdlSimStatusChange(SimStruct *S, ssSimStatusChangeType simStatus)
{
  if (ssRTWGenIsCodeGen(S) || ssIsExternalSim(S)) {
    return;
  }                                    /* if */

  if (simStatus == SIM_PAUSE) {
    {
      uint8_T * mxMemUnitPtr;
      mwSize dataInSize = 0;
      XIL_IOBuffer_T * IOBufferPtr = (XIL_IOBuffer_T *) ssGetPWorkValue(S, 1);
      if (IOBufferPtr != NULL) {
        void * pXILService = (void *) ssGetPWorkValue(S, 9);
        if (pXILService != NULL) {
          if (xilHostAppSvcGrowIOBuffer(pXILService, IOBufferPtr, 5, 0)!=
              XILHOSTAPPSVC_SUCCESS) {
            return ;
          }                            /* if */

          if (IOBufferPtr->data != NULL) {
            mxMemUnitPtr = (uint8_T *) IOBufferPtr->data;

            /* write command id */
            *mxMemUnitPtr = (uint8_T) XIL_PAUSE_COMMAND;
            mxMemUnitPtr++;

            {
              {
                uint8_T * simDataMemUnitPtr;
                uint32_T commandDataFcnid = 0;
                simDataMemUnitPtr = (uint8_T *) &commandDataFcnid;

                {
                  size_t num_elements = 1;

                  {
                    copyIOData(mxMemUnitPtr, simDataMemUnitPtr, &mxMemUnitPtr,
                               num_elements, sizeof(uint32_T));
                  }
                }
              }
            }
          }                            /* if */
        }                              /* if */
      }                                /* if */
    }

    {
      {
        uint8_T * mxMemUnitPtr;
        mwSize dataInSize = 0;
        XIL_IOBuffer_T * IOBufferPtr = (XIL_IOBuffer_T *) ssGetPWorkValue(S, 1);

        /* dispatch command to the target */
        if (commandDispatch(S, IOBufferPtr, 5)!=XILHOSTAPPSVC_SUCCESS) {
          return ;
        }                              /* if */

        {
          XILCommandResponseType commandResponseType = XIL_COMMAND_NOT_COMPLETE;
          while (commandResponseType != XIL_STEP_COMPLETE) {
            /* receive command from the target */
            mwSize dataInSize = 0;
            if (commandResponse(S, &dataInSize, &commandResponseType) !=
                XILHOSTAPPSVC_SUCCESS) {
              return ;
            }                          /* if */

            if (dataInSize>0) {
              size_t dataInMemUnitSize = dataInSize;
              uint8_T responseId = 0;
              uint8_T * mxMemUnitPtrEnd;
              mxMemUnitPtr = (uint8_T *) IOBufferPtr->data;
              mxMemUnitPtrEnd = mxMemUnitPtr + dataInMemUnitSize - 1;
              while (mxMemUnitPtr <= mxMemUnitPtrEnd) {
                /* read response id */
                responseId = *mxMemUnitPtr;
                mxMemUnitPtr++;
                switch (responseId) {
                 case RESPONSE_ERROR:
                 case RESPONSE_PRINTF:
                 case RESPONSE_FOPEN:
                 case RESPONSE_FPRINTF:
                 case RESPONSE_SIGNAL_RAISED:
                  {
                    if (processErrorAndTargetIOResponseCases(S, responseId,
                         &mxMemUnitPtr)== XILHOSTAPPSVC_ERROR) {
                      return ;
                    }                  /* if */
                    break;
                  }

                 default:
                  {
                    {
                      void * pXILUtils = (void *) ssGetPWorkValue(S, 6);
                      mxArray * rhs[ 2 ];
                      rhs[0] = mxCreateString(
                        "PIL:pilverification:UnknownResponseId");
                      rhs[1] = mxCreateDoubleScalar(responseId);
                      xilUtilsHandleError(pXILUtils, 2 , rhs );
                      return ;
                    }
                    break;
                  }
                }                      /* switch */
              }                        /* while */
            }                          /* if */
          }                            /* while */
        }
      }
    }

    {
      void * pXILUtils = (void *) ssGetPWorkValue(S, 6);
      if (pXILUtils) {
        mxArray *rhs[3];
        char * simulinkBlockPath = getSimulinkBlockPath(S);
        if (simulinkBlockPath == NULL) {
          ssSetErrorStatus(S,
                           "ModelBlock SIL/PIL unexpected error: getSimulinkBlockPath returned NULL pointer. Check search string was found in ssGetPath.\n");
          return;
        }

        rhs[ 0 ] = mxCreateString(
          "@coder.connectivity.SimulinkInterface.getSILPILInterface");
        rhs[ 1 ] = mxCreateDoubleScalar( 4 );
        rhs[ 2 ] = mxCreateString(simulinkBlockPath);
        if (xilUtilsCallMATLAB(pXILUtils, 0, NULL, 3, rhs,
                               "rtw.pil.SILPILInterface.sfunctionPILPauseHook")
            != XIL_UTILS_SUCCESS) {
          return ;
        }                              /* if */

        mxFree((void *) simulinkBlockPath);
      }                                /* if */
    }
  }                                    /* if */
}

#endif                                 /* MDL_SIM_STATUS_CHANGE */

static void XILoutputTID01(SimStruct *S, int tid)
{
  {
    uint8_T * mxMemUnitPtr;
    mwSize dataInSize = 0;
    XIL_IOBuffer_T * IOBufferPtr = (XIL_IOBuffer_T *) ssGetPWorkValue(S, 1);
    if (IOBufferPtr != NULL) {
      void * pXILService = (void *) ssGetPWorkValue(S, 9);
      if (pXILService != NULL) {
        if (xilHostAppSvcGrowIOBuffer(pXILService, IOBufferPtr, 1095, 0)!=
            XILHOSTAPPSVC_SUCCESS) {
          return;
        }                              /* if */

        if (IOBufferPtr->data != NULL) {
          mxMemUnitPtr = (uint8_T *) IOBufferPtr->data;

          /* write command id */
          *mxMemUnitPtr = (uint8_T) XIL_OUTPUT_COMMAND;
          mxMemUnitPtr++;

          {
            {
              uint8_T * simDataMemUnitPtr;
              uint32_T commandDataFcnidTID[2] = { 0, 1 };

              simDataMemUnitPtr = (uint8_T *) &commandDataFcnidTID[0];

              {
                size_t num_elements = 2;

                {
                  copyIOData(mxMemUnitPtr, simDataMemUnitPtr, &mxMemUnitPtr,
                             num_elements, sizeof(uint32_T));
                }
              }
            }
          }

          {
            /* DataInterface: input, 1 */
            void * dataInterfacePtr = (void *) ssGetInputPortSignal(S, 0);

            {
              uint8_T * simDataMemUnitPtr;
              uint32_T offsetIdx;
              for (offsetIdx=0; offsetIdx< 4; offsetIdx++) {
                slDataTypeAccess * dta = ssGetDataTypeAccess(S);
                const char * bpath = ssGetPath(S);

                {
                  /* DataInterface: input, 1 */
                  simDataMemUnitPtr = ( uint8_T *) dataInterfacePtr;
                  simDataMemUnitPtr = (uint8_T*) (((char *) simDataMemUnitPtr) +
                    dtaGetDataTypeElementOffset(dta, bpath, ssGetDataTypeId(S,
                    "BusInputBMS"), 0) +
                    dtaGetDataTypeElementOffset(dta, bpath, ssGetDataTypeId(S,
                    "BMSBatteryPackData"), offsetIdx));

                  {
                    DTypeId dType = ssGetDataTypeId(S, "BMSBatteryPackData");
                    size_t num_elements;
                    const int_T * busElementsDims;
                    int_T busElementNumDims;
                    DTypeId elemTypeId = ssGetBusElementDataType(S, dType,
                      offsetIdx);
                    if (ssIsStringDataType(S, elemTypeId)) {
                      num_elements = ssGetStringDataTypeBufferSize(S, elemTypeId);
                    } else {
                      num_elements = getBusElementDimension(S, dType, offsetIdx,
                        &busElementsDims, &busElementNumDims);
                    }                  /* if */

                    {
                      if (ssIsStringDataType(S, elemTypeId)) {
                        copyStringIOData(mxMemUnitPtr, simDataMemUnitPtr,
                                         &mxMemUnitPtr, num_elements, sizeof
                                         (char_T), 1);
                      } else {
                        copyIOData(mxMemUnitPtr, simDataMemUnitPtr,
                                   &mxMemUnitPtr, num_elements,
                                   ssGetDataTypeSize(S, elemTypeId));
                      }                /* if */
                    }
                  }
                }
              }                        /* for */
            }

            {
              uint8_T * simDataMemUnitPtr;
              uint32_T offsetIdx;
              for (offsetIdx=0; offsetIdx< 6; offsetIdx++) {
                slDataTypeAccess * dta = ssGetDataTypeAccess(S);
                const char * bpath = ssGetPath(S);

                {
                  /* DataInterface: input, 1 */
                  simDataMemUnitPtr = ( uint8_T *) dataInterfacePtr;
                  simDataMemUnitPtr = (uint8_T*) (((char *) simDataMemUnitPtr) +
                    dtaGetDataTypeElementOffset(dta, bpath, ssGetDataTypeId(S,
                    "BusInputBMS"), 1) +
                    dtaGetDataTypeElementOffset(dta, bpath, ssGetDataTypeId(S,
                    "BMSContactorModuleData"), offsetIdx));

                  {
                    DTypeId dType = ssGetDataTypeId(S, "BMSContactorModuleData");
                    size_t num_elements;
                    const int_T * busElementsDims;
                    int_T busElementNumDims;
                    DTypeId elemTypeId = ssGetBusElementDataType(S, dType,
                      offsetIdx);
                    if (ssIsStringDataType(S, elemTypeId)) {
                      num_elements = ssGetStringDataTypeBufferSize(S, elemTypeId);
                    } else {
                      num_elements = getBusElementDimension(S, dType, offsetIdx,
                        &busElementsDims, &busElementNumDims);
                    }                  /* if */

                    {
                      if (ssIsStringDataType(S, elemTypeId)) {
                        copyStringIOData(mxMemUnitPtr, simDataMemUnitPtr,
                                         &mxMemUnitPtr, num_elements, sizeof
                                         (char_T), 1);
                      } else {
                        copyIOData(mxMemUnitPtr, simDataMemUnitPtr,
                                   &mxMemUnitPtr, num_elements,
                                   ssGetDataTypeSize(S, elemTypeId));
                      }                /* if */
                    }
                  }
                }
              }                        /* for */
            }
          }

          {
            /* DataInterface: input, 2 */
            void * dataInterfacePtr = (void *) ssGetInputPortSignal(S, 1);

            {
              uint8_T * simDataMemUnitPtr;
              uint32_T offsetIdx;
              for (offsetIdx=0; offsetIdx< 3; offsetIdx++) {
                slDataTypeAccess * dta = ssGetDataTypeAccess(S);
                const char * bpath = ssGetPath(S);

                {
                  /* DataInterface: input, 2 */
                  simDataMemUnitPtr = ( uint8_T *) dataInterfacePtr;
                  simDataMemUnitPtr = (uint8_T*) (((char *) simDataMemUnitPtr) +
                    dtaGetDataTypeElementOffset(dta, bpath, ssGetDataTypeId(S,
                    "BusSimulationInput"), 0) +
                    dtaGetDataTypeElementOffset(dta, bpath, ssGetDataTypeId(S,
                    "SimulationSystemInput"), offsetIdx));

                  {
                    DTypeId dType = ssGetDataTypeId(S, "SimulationSystemInput");
                    size_t num_elements;
                    const int_T * busElementsDims;
                    int_T busElementNumDims;
                    DTypeId elemTypeId = ssGetBusElementDataType(S, dType,
                      offsetIdx);
                    if (ssIsStringDataType(S, elemTypeId)) {
                      num_elements = ssGetStringDataTypeBufferSize(S, elemTypeId);
                    } else {
                      num_elements = getBusElementDimension(S, dType, offsetIdx,
                        &busElementsDims, &busElementNumDims);
                    }                  /* if */

                    {
                      if (ssIsStringDataType(S, elemTypeId)) {
                        copyStringIOData(mxMemUnitPtr, simDataMemUnitPtr,
                                         &mxMemUnitPtr, num_elements, sizeof
                                         (char_T), 1);
                      } else {
                        copyIOData(mxMemUnitPtr, simDataMemUnitPtr,
                                   &mxMemUnitPtr, num_elements,
                                   ssGetDataTypeSize(S, elemTypeId));
                      }                /* if */
                    }
                  }
                }
              }                        /* for */
            }

            {
              uint8_T * simDataMemUnitPtr;
              uint32_T offsetIdx;
              for (offsetIdx=0; offsetIdx< 2; offsetIdx++) {
                slDataTypeAccess * dta = ssGetDataTypeAccess(S);
                const char * bpath = ssGetPath(S);

                {
                  /* DataInterface: input, 2 */
                  simDataMemUnitPtr = ( uint8_T *) dataInterfacePtr;
                  simDataMemUnitPtr = (uint8_T*) (((char *) simDataMemUnitPtr) +
                    dtaGetDataTypeElementOffset(dta, bpath, ssGetDataTypeId(S,
                    "BusSimulationInput"), 1) +
                    dtaGetDataTypeElementOffset(dta, bpath, ssGetDataTypeId(S,
                    "SimulationBatteryPackInput"), offsetIdx));

                  {
                    DTypeId dType = ssGetDataTypeId(S,
                      "SimulationBatteryPackInput");
                    size_t num_elements;
                    const int_T * busElementsDims;
                    int_T busElementNumDims;
                    DTypeId elemTypeId = ssGetBusElementDataType(S, dType,
                      offsetIdx);
                    if (ssIsStringDataType(S, elemTypeId)) {
                      num_elements = ssGetStringDataTypeBufferSize(S, elemTypeId);
                    } else {
                      num_elements = getBusElementDimension(S, dType, offsetIdx,
                        &busElementsDims, &busElementNumDims);
                    }                  /* if */

                    {
                      if (ssIsStringDataType(S, elemTypeId)) {
                        copyStringIOData(mxMemUnitPtr, simDataMemUnitPtr,
                                         &mxMemUnitPtr, num_elements, sizeof
                                         (char_T), 1);
                      } else {
                        copyIOData(mxMemUnitPtr, simDataMemUnitPtr,
                                   &mxMemUnitPtr, num_elements,
                                   ssGetDataTypeSize(S, elemTypeId));
                      }                /* if */
                    }
                  }
                }
              }                        /* for */
            }
          }
        }                              /* if */
      }                                /* if */
    }                                  /* if */
  }

  {
    {
      uint8_T * mxMemUnitPtr;
      mwSize dataInSize = 0;
      XIL_IOBuffer_T * IOBufferPtr = (XIL_IOBuffer_T *) ssGetPWorkValue(S, 1);

      /* dispatch command to the target */
      if (commandDispatch(S, IOBufferPtr, 1095)!=XILHOSTAPPSVC_SUCCESS) {
        return;
      }                                /* if */

      {
        XILCommandResponseType commandResponseType = XIL_COMMAND_NOT_COMPLETE;
        while (commandResponseType != XIL_STEP_COMPLETE) {
          /* receive command from the target */
          mwSize dataInSize = 0;
          if (commandResponse(S, &dataInSize, &commandResponseType) !=
              XILHOSTAPPSVC_SUCCESS) {
            return;
          }                            /* if */

          if (dataInSize>0) {
            size_t dataInMemUnitSize = dataInSize;
            uint8_T responseId = 0;
            uint8_T * mxMemUnitPtrEnd;
            mxMemUnitPtr = (uint8_T *) IOBufferPtr->data;
            mxMemUnitPtrEnd = mxMemUnitPtr + dataInMemUnitSize - 1;
            while (mxMemUnitPtr <= mxMemUnitPtrEnd) {
              /* read response id */
              responseId = *mxMemUnitPtr;
              mxMemUnitPtr++;
              switch (responseId) {
               case RESPONSE_ERROR:
               case RESPONSE_PRINTF:
               case RESPONSE_FOPEN:
               case RESPONSE_FPRINTF:
               case RESPONSE_SIGNAL_RAISED:
                {
                  if (processErrorAndTargetIOResponseCases(S, responseId,
                       &mxMemUnitPtr)== XILHOSTAPPSVC_ERROR) {
                    return;
                  }                    /* if */
                  break;
                }

               case RESPONSE_OUTPUT_PRE_DATA:
                {
                  break;
                }

               case RESPONSE_OUTPUT_DATA:
                {
                  {
                    /* DataInterface: output, 1 */
                    void * dataInterfacePtr = (void *) ssGetOutputPortSignal(S,
                      0);

                    {
                      uint8_T * simDataMemUnitPtr;
                      uint32_T offsetIdx;
                      for (offsetIdx=0; offsetIdx< 4; offsetIdx++) {
                        slDataTypeAccess * dta = ssGetDataTypeAccess(S);
                        const char * bpath = ssGetPath(S);

                        {
                          /* DataInterface: output, 1 */
                          simDataMemUnitPtr = ( uint8_T *) dataInterfacePtr;
                          simDataMemUnitPtr = (uint8_T*) (((char *)
                            simDataMemUnitPtr) +
                            dtaGetDataTypeElementOffset(dta, bpath,
                            ssGetDataTypeId(S, "BusOutputBMS"), 0) +
                            dtaGetDataTypeElementOffset(dta, bpath,
                            ssGetDataTypeId(S, "BMSContactorModuleCmd"),
                            offsetIdx));

                          {
                            DTypeId dType = ssGetDataTypeId(S,
                              "BMSContactorModuleCmd");
                            size_t num_elements;
                            const int_T * busElementsDims;
                            int_T busElementNumDims;
                            DTypeId elemTypeId = ssGetBusElementDataType(S,
                              dType, offsetIdx);
                            if (ssIsStringDataType(S, elemTypeId)) {
                              num_elements = ssGetStringDataTypeBufferSize(S,
                                elemTypeId);
                            } else {
                              num_elements = getBusElementDimension(S, dType,
                                offsetIdx, &busElementsDims, &busElementNumDims);
                            }          /* if */

                            {
                              if (ssIsStringDataType(S, elemTypeId)) {
                                copyStringIOData(simDataMemUnitPtr, mxMemUnitPtr,
                                                 &mxMemUnitPtr, num_elements,
                                                 sizeof(char_T), 0);
                              } else {
                                copyIOData(simDataMemUnitPtr, mxMemUnitPtr,
                                           &mxMemUnitPtr, num_elements,
                                           ssGetDataTypeSize(S, elemTypeId));
                              }        /* if */
                            }
                          }
                        }
                      }                /* for */
                    }

                    {
                      uint8_T * simDataMemUnitPtr;
                      uint32_T offsetIdx;
                      for (offsetIdx=0; offsetIdx< 3; offsetIdx++) {
                        slDataTypeAccess * dta = ssGetDataTypeAccess(S);
                        const char * bpath = ssGetPath(S);

                        {
                          /* DataInterface: output, 1 */
                          simDataMemUnitPtr = ( uint8_T *) dataInterfacePtr;
                          simDataMemUnitPtr = (uint8_T*) (((char *)
                            simDataMemUnitPtr) +
                            dtaGetDataTypeElementOffset(dta, bpath,
                            ssGetDataTypeId(S, "BusOutputBMS"), 1) +
                            dtaGetDataTypeElementOffset(dta, bpath,
                            ssGetDataTypeId(S, "BMSBatteryPackInput"), offsetIdx));

                          {
                            DTypeId dType = ssGetDataTypeId(S,
                              "BMSBatteryPackInput");
                            size_t num_elements;
                            const int_T * busElementsDims;
                            int_T busElementNumDims;
                            DTypeId elemTypeId = ssGetBusElementDataType(S,
                              dType, offsetIdx);
                            if (ssIsStringDataType(S, elemTypeId)) {
                              num_elements = ssGetStringDataTypeBufferSize(S,
                                elemTypeId);
                            } else {
                              num_elements = getBusElementDimension(S, dType,
                                offsetIdx, &busElementsDims, &busElementNumDims);
                            }          /* if */

                            {
                              if (ssIsStringDataType(S, elemTypeId)) {
                                copyStringIOData(simDataMemUnitPtr, mxMemUnitPtr,
                                                 &mxMemUnitPtr, num_elements,
                                                 sizeof(char_T), 0);
                              } else {
                                copyIOData(simDataMemUnitPtr, mxMemUnitPtr,
                                           &mxMemUnitPtr, num_elements,
                                           ssGetDataTypeSize(S, elemTypeId));
                              }        /* if */
                            }
                          }
                        }
                      }                /* for */
                    }

                    {
                      uint8_T * simDataMemUnitPtr;
                      uint32_T offsetIdx;
                      for (offsetIdx=0; offsetIdx< 2; offsetIdx++) {
                        slDataTypeAccess * dta = ssGetDataTypeAccess(S);
                        const char * bpath = ssGetPath(S);

                        {
                          /* DataInterface: output, 1 */
                          simDataMemUnitPtr = ( uint8_T *) dataInterfacePtr;
                          simDataMemUnitPtr = (uint8_T*) (((char *)
                            simDataMemUnitPtr) +
                            dtaGetDataTypeElementOffset(dta, bpath,
                            ssGetDataTypeId(S, "BusOutputBMS"), 2) +
                            dtaGetDataTypeElementOffset(dta, bpath,
                            ssGetDataTypeId(S, "BusSOCEstimation"), offsetIdx));

                          {
                            DTypeId dType = ssGetDataTypeId(S,
                              "BusSOCEstimation");
                            size_t num_elements;
                            const int_T * busElementsDims;
                            int_T busElementNumDims;
                            DTypeId elemTypeId = ssGetBusElementDataType(S,
                              dType, offsetIdx);
                            if (ssIsStringDataType(S, elemTypeId)) {
                              num_elements = ssGetStringDataTypeBufferSize(S,
                                elemTypeId);
                            } else {
                              num_elements = getBusElementDimension(S, dType,
                                offsetIdx, &busElementsDims, &busElementNumDims);
                            }          /* if */

                            {
                              if (ssIsStringDataType(S, elemTypeId)) {
                                copyStringIOData(simDataMemUnitPtr, mxMemUnitPtr,
                                                 &mxMemUnitPtr, num_elements,
                                                 sizeof(char_T), 0);
                              } else {
                                copyIOData(simDataMemUnitPtr, mxMemUnitPtr,
                                           &mxMemUnitPtr, num_elements,
                                           ssGetDataTypeSize(S, elemTypeId));
                              }        /* if */
                            }
                          }
                        }
                      }                /* for */
                    }

                    {
                      uint8_T * simDataMemUnitPtr;
                      uint32_T offsetIdx;
                      for (offsetIdx=0; offsetIdx< 8; offsetIdx++) {
                        slDataTypeAccess * dta = ssGetDataTypeAccess(S);
                        const char * bpath = ssGetPath(S);

                        {
                          /* DataInterface: output, 1 */
                          simDataMemUnitPtr = ( uint8_T *) dataInterfacePtr;
                          simDataMemUnitPtr = (uint8_T*) (((char *)
                            simDataMemUnitPtr) +
                            dtaGetDataTypeElementOffset(dta, bpath,
                            ssGetDataTypeId(S, "BusOutputBMS"), 3) +
                            dtaGetDataTypeElementOffset(dta, bpath,
                            ssGetDataTypeId(S, "BMSFaultOutput"), offsetIdx));

                          {
                            DTypeId dType = ssGetDataTypeId(S, "BMSFaultOutput");
                            size_t num_elements;
                            const int_T * busElementsDims;
                            int_T busElementNumDims;
                            DTypeId elemTypeId = ssGetBusElementDataType(S,
                              dType, offsetIdx);
                            if (ssIsStringDataType(S, elemTypeId)) {
                              num_elements = ssGetStringDataTypeBufferSize(S,
                                elemTypeId);
                            } else {
                              num_elements = getBusElementDimension(S, dType,
                                offsetIdx, &busElementsDims, &busElementNumDims);
                            }          /* if */

                            {
                              if (ssIsStringDataType(S, elemTypeId)) {
                                copyStringIOData(simDataMemUnitPtr, mxMemUnitPtr,
                                                 &mxMemUnitPtr, num_elements,
                                                 sizeof(char_T), 0);
                              } else {
                                copyIOData(simDataMemUnitPtr, mxMemUnitPtr,
                                           &mxMemUnitPtr, num_elements,
                                           ssGetDataTypeSize(S, elemTypeId));
                              }        /* if */
                            }
                          }
                        }
                      }                /* for */
                    }
                  }
                  break;
                }

               default:
                {
                  {
                    void * pXILUtils = (void *) ssGetPWorkValue(S, 6);
                    mxArray * rhs[ 2 ];
                    rhs[0] = mxCreateString(
                      "PIL:pilverification:UnknownResponseId");
                    rhs[1] = mxCreateDoubleScalar(responseId);
                    xilUtilsHandleError(pXILUtils, 2 , rhs );
                    return;
                  }
                  break;
                }
              }                        /* switch */
            }                          /* while */
          }                            /* if */
        }                              /* while */
      }
    }
  }

  {
    uint8_T * mxMemUnitPtr;
    mwSize dataInSize = 0;
    XIL_IOBuffer_T * IOBufferPtr = (XIL_IOBuffer_T *) ssGetPWorkValue(S, 1);
    mxMemUnitPtr = (uint8_T *) IOBufferPtr->data;
    if (dataInSize>0) {
      size_t dataInMemUnitSize = dataInSize;
      uint8_T responseId = 0;
      uint8_T * mxMemUnitPtrEnd;
      mxMemUnitPtr = (uint8_T *) IOBufferPtr->data;
      mxMemUnitPtrEnd = mxMemUnitPtr + dataInMemUnitSize - 1;
      while (mxMemUnitPtr <= mxMemUnitPtrEnd) {
        /* read response id */
        responseId = *mxMemUnitPtr;
        mxMemUnitPtr++;
        switch (responseId) {
         case RESPONSE_ERROR:
         case RESPONSE_PRINTF:
         case RESPONSE_FOPEN:
         case RESPONSE_FPRINTF:
         case RESPONSE_SIGNAL_RAISED:
          {
            if (processErrorAndTargetIOResponseCases(S, responseId,
                 &mxMemUnitPtr)== XILHOSTAPPSVC_ERROR) {
              return;
            }                          /* if */
            break;
          }

         default:
          {
            {
              void * pXILUtils = (void *) ssGetPWorkValue(S, 6);
              mxArray * rhs[ 2 ];
              rhs[0] = mxCreateString("PIL:pilverification:UnknownResponseId");
              rhs[1] = mxCreateDoubleScalar(responseId);
              xilUtilsHandleError(pXILUtils, 2 , rhs );
              return;
            }
            break;
          }
        }                              /* switch */
      }                                /* while */
    }                                  /* if */
  }
}

#define MDL_PROCESS_PARAMETERS
#if defined(MDL_PROCESS_PARAMETERS)

static void mdlProcessParameters(SimStruct *S)
{
  if (ssRTWGenIsCodeGen(S) || ssIsExternalSim(S)) {
    return;
  }                                    /* if */

  processParams(S);
}

#endif                                 /* MDL_PROCESS_PARAMETERS */

#define MDL_SET_WORK_WIDTHS                                      /* Change to #undef to remove function */
#if defined(MDL_SET_WORK_WIDTHS)

static void mdlSetWorkWidths(SimStruct *S)
{
  if (ssRTWGenIsCodeGen(S) || ssIsExternalSim(S)) {
    if (S->mdlInfo->genericFcn != (NULL)) {
      _GenericFcn fcn = S->mdlInfo->genericFcn;
      ssSetSignalSizesComputeType(S, SS_VARIABLE_SIZE_FROM_INPUT_VALUE_AND_SIZE);
    }
  }                                    /* if */
}

#endif                                 /* MDL_SET_WORK_WIDTHS */

static void mdlPeriodicOutputUpdate(SimStruct *S, int_T tid)
{
  /* Periodic Output Update sample time matching */
  /* check for sample time hit associated with task 1 */
  if (tid == 0) {
    XILoutputTID01(S, tid);
  }                                    /* if */
}

static void mdlOutputs(SimStruct *S, int_T tid)
{
  if (ssRTWGenIsCodeGen(S) || ssIsExternalSim(S)) {
    return;
  }                                    /* if */

  /* Singlerate scheduling */
  /* check for sample time hit associated with task 1 */
  if (ssIsSampleHit(S, 0, tid)) {
    XILoutputTID01(S, tid);
  }                                    /* if */
}

#define MDL_UPDATE
#if defined(MDL_UPDATE)

static void mdlUpdate(SimStruct *S, int_T tid)
{
}

#endif

static void mdlTerminate(SimStruct *S)
{
  int commErrorOccurred = 0;
  int isXILApplicationStarted = 0;

  {
    if (ssRTWGenIsCodeGen(S) || ssIsExternalSim(S)) {
      return;
    }                                  /* if */

    if (ssGetPWork(S) != NULL) {
      int * pCommErrorOccurred = (int *) ssGetPWorkValue(S, 4);
      int * pIsXILApplicationStarted = (int *) ssGetPWorkValue(S, 5);
      if (pCommErrorOccurred != NULL) {
        commErrorOccurred = *pCommErrorOccurred;
      }                                /* if */

      if (pIsXILApplicationStarted != NULL) {
        isXILApplicationStarted = *pIsXILApplicationStarted;
      }                                /* if */
    }                                  /* if */
  }

  if (isXILApplicationStarted) {
    if (!commErrorOccurred) {
      {
        uint8_T * mxMemUnitPtr;
        mwSize dataInSize = 0;
        XIL_IOBuffer_T * IOBufferPtr = (XIL_IOBuffer_T *) ssGetPWorkValue(S, 1);
        if (IOBufferPtr != NULL) {
          void * pXILService = (void *) ssGetPWorkValue(S, 9);
          if (pXILService != NULL) {
            if (xilHostAppSvcGrowIOBuffer(pXILService, IOBufferPtr, 5, 0)!=
                XILHOSTAPPSVC_SUCCESS) {
              callStopHookAndFreeSFcnMemory(S);
              return;
            }                          /* if */

            if (IOBufferPtr->data != NULL) {
              mxMemUnitPtr = (uint8_T *) IOBufferPtr->data;

              /* write command id */
              *mxMemUnitPtr = (uint8_T) XIL_TERMINATE_COMMAND;
              mxMemUnitPtr++;

              {
                {
                  uint8_T * simDataMemUnitPtr;
                  uint32_T commandDataFcnid = 0;
                  simDataMemUnitPtr = (uint8_T *) &commandDataFcnid;

                  {
                    size_t num_elements = 1;

                    {
                      copyIOData(mxMemUnitPtr, simDataMemUnitPtr, &mxMemUnitPtr,
                                 num_elements, sizeof(uint32_T));
                    }
                  }
                }
              }
            }                          /* if */
          }                            /* if */
        }                              /* if */
      }

      {
        {
          uint8_T * mxMemUnitPtr;
          mwSize dataInSize = 0;
          XIL_IOBuffer_T * IOBufferPtr = (XIL_IOBuffer_T *) ssGetPWorkValue(S, 1);

          /* dispatch command to the target */
          if (commandDispatch(S, IOBufferPtr, 5)!=XILHOSTAPPSVC_SUCCESS) {
            callStopHookAndFreeSFcnMemory(S);
            return;
          }                            /* if */

          {
            XILCommandResponseType commandResponseType =
              XIL_COMMAND_NOT_COMPLETE;
            while (commandResponseType != XIL_STEP_COMPLETE) {
              /* receive command from the target */
              mwSize dataInSize = 0;
              if (commandResponse(S, &dataInSize, &commandResponseType) !=
                  XILHOSTAPPSVC_SUCCESS) {
                callStopHookAndFreeSFcnMemory(S);
                return;
              }                        /* if */

              if (dataInSize>0) {
                size_t dataInMemUnitSize = dataInSize;
                uint8_T responseId = 0;
                uint8_T * mxMemUnitPtrEnd;
                mxMemUnitPtr = (uint8_T *) IOBufferPtr->data;
                mxMemUnitPtrEnd = mxMemUnitPtr + dataInMemUnitSize - 1;
                while (mxMemUnitPtr <= mxMemUnitPtrEnd) {
                  /* read response id */
                  responseId = *mxMemUnitPtr;
                  mxMemUnitPtr++;
                  switch (responseId) {
                   case RESPONSE_ERROR:
                   case RESPONSE_PRINTF:
                   case RESPONSE_FOPEN:
                   case RESPONSE_FPRINTF:
                   case RESPONSE_SIGNAL_RAISED:
                    {
                      if (processErrorAndTargetIOResponseCases(S, responseId,
                           &mxMemUnitPtr)== XILHOSTAPPSVC_ERROR) {
                        callStopHookAndFreeSFcnMemory(S);
                        return;
                      }                /* if */
                      break;
                    }

                   default:
                    {
                      {
                        void * pXILUtils = (void *) ssGetPWorkValue(S, 6);
                        mxArray * rhs[ 2 ];
                        rhs[0] = mxCreateString(
                          "PIL:pilverification:UnknownResponseId");
                        rhs[1] = mxCreateDoubleScalar(responseId);
                        xilUtilsHandleError(pXILUtils, 2 , rhs );
                        callStopHookAndFreeSFcnMemory(S);
                        return;
                      }
                      break;
                    }
                  }                    /* switch */
                }                      /* while */
              }                        /* if */
            }                          /* while */
          }
        }
      }

      {
        uint8_T * mxMemUnitPtr;
        mwSize dataInSize = 0;
        XIL_IOBuffer_T * IOBufferPtr = (XIL_IOBuffer_T *) ssGetPWorkValue(S, 1);
        if (IOBufferPtr != NULL) {
          void * pXILService = (void *) ssGetPWorkValue(S, 9);
          if (pXILService != NULL) {
            if (xilHostAppSvcGrowIOBuffer(pXILService, IOBufferPtr, 1, 0)!=
                XILHOSTAPPSVC_SUCCESS) {
              callStopHookAndFreeSFcnMemory(S);
              return;
            }                          /* if */

            if (IOBufferPtr->data != NULL) {
              mxMemUnitPtr = (uint8_T *) IOBufferPtr->data;

              /* write command id */
              *mxMemUnitPtr = (uint8_T) XIL_SHUTDOWN_COMMAND;
              mxMemUnitPtr++;
            }                          /* if */
          }                            /* if */
        }                              /* if */
      }

      {
        {
          uint8_T * mxMemUnitPtr;
          mwSize dataInSize = 0;
          XIL_IOBuffer_T * IOBufferPtr = (XIL_IOBuffer_T *) ssGetPWorkValue(S, 1);

          /* dispatch command to the target */
          if (commandDispatch(S, IOBufferPtr, 1)!=XILHOSTAPPSVC_SUCCESS) {
            callStopHookAndFreeSFcnMemory(S);
            return;
          }                            /* if */
        }
      }
    }                                  /* if */
  }                                    /* if */

  callStopHookAndFreeSFcnMemory(S);
}

#define MDL_CLEANUP_RUNTIME_RESOURCES                            /* Change to #undef to remove function */
#if defined(MDL_CLEANUP_RUNTIME_RESOURCES)

static void mdlCleanupRuntimeResources(SimStruct *S)
{
  mdlTerminate(S);
  if (ssRTWGenIsCodeGen(S) || ssIsExternalSim(S)) {
    return;
  }                                    /* if */

  if (ssGetPWork(S) != NULL) {
    int * pIsXILApplicationStarted = (int *) ssGetPWorkValue(S, 5);
    int * pCommErrorOccurred = (int *) ssGetPWorkValue(S, 4);
    if (pIsXILApplicationStarted != NULL) {
      mxFree(pIsXILApplicationStarted);
      ssSetPWorkValue(S, 5, NULL);
    }                                  /* if */

    if (pCommErrorOccurred != NULL) {
      mxFree(pCommErrorOccurred);
      ssSetPWorkValue(S, 4, NULL);
    }                                  /* if */
  }                                    /* if */

  if (ssGetPWork(S) != NULL) {
    void * pXILUtils = (void *) ssGetPWorkValue(S, 6);
    if (pXILUtils != NULL) {
      xilUtilsDestroy(pXILUtils);
      ssSetPWorkValue(S, 6, NULL);
    }                                  /* if */
  }                                    /* if */
}

#endif                                 /* MDL_CLEANUP_RUNTIME_RESOURCES */

#define MDL_ENABLE
#if defined(MDL_ENABLE)

static void mdlEnable(SimStruct *S)
{
  if (ssGetT(S) != ssGetTStart(S)) {
    {
      void * pXILUtils = (void *) ssGetPWorkValue(S, 6);
      mxArray * rhs[ 3 ];
      rhs[0] = mxCreateString("PIL:pil:EnableDisableCallbackError");
      rhs[1] = mxCreateString("enable");
      rhs[2] = mxCreateString("enable");
      xilUtilsHandleError(pXILUtils, 3 , rhs );
      return;
    }
  }                                    /* if */
}

#endif                                 /* MDL_ENABLE */

#define MDL_DISABLE
#if defined(MDL_DISABLE)

static void mdlDisable(SimStruct *S)
{
  {
    void * pXILUtils = (void *) ssGetPWorkValue(S, 6);
    mxArray * rhs[ 3 ];
    rhs[0] = mxCreateString("PIL:pil:EnableDisableCallbackError");
    rhs[1] = mxCreateString("disable");
    rhs[2] = mxCreateString("disable");
    xilUtilsHandleError(pXILUtils, 3 , rhs );
    return;
  }
}

#endif                                 /* MDL_DISABLE */

/* Required S-function trailer */
#ifdef MATLAB_MEX_FILE                 /* Is this file being compiled as a MEX-file? */
#include "simulink.c"                  /* MEX-file interface mechanism */
#include "fixedpoint.c"
#else
#error Assertion failed: file must be compiled as a MEX-file
#endif
