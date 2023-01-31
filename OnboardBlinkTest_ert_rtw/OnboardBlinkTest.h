/*
 * OnboardBlinkTest.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "OnboardBlinkTest".
 *
 * Model version              : 1.3
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C source code generated on : Tue Jan 31 18:34:02 2023
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_OnboardBlinkTest_h_
#define RTW_HEADER_OnboardBlinkTest_h_
#include <math.h>
#include <stddef.h>
#include <string.h>
#ifndef OnboardBlinkTest_COMMON_INCLUDES_
#define OnboardBlinkTest_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_AnalogIn.h"
#include "MW_arduino_digitalio.h"
#endif                                 /* OnboardBlinkTest_COMMON_INCLUDES_ */

#include "OnboardBlinkTest_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<Root>/Analog Input1' */
  codertarget_arduinobase_inter_T obj_n;/* '<Root>/Analog Input' */
  codertarget_arduinobase_block_T obj_nv;/* '<Root>/Digital Output2' */
  codertarget_arduinobase_block_T obj_i;/* '<Root>/Digital Output1' */
  codertarget_arduinobase_block_T obj_g;/* '<Root>/Digital Output' */
  boolean_T objisempty;                /* '<Root>/Digital Output2' */
  boolean_T objisempty_g;              /* '<Root>/Digital Output1' */
  boolean_T objisempty_n;              /* '<Root>/Digital Output' */
  boolean_T objisempty_f;              /* '<Root>/Analog Input1' */
  boolean_T objisempty_j;              /* '<Root>/Analog Input' */
} DW_OnboardBlinkTest_T;

/* Parameters (default storage) */
struct P_OnboardBlinkTest_T_ {
  real_T AnalogInput_SampleTime;       /* Expression: 1
                                        * Referenced by: '<Root>/Analog Input'
                                        */
  real_T AnalogInput1_SampleTime;      /* Expression: 1
                                        * Referenced by: '<Root>/Analog Input1'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T Constant3_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant3'
                                        */
  uint8_T ManualSwitch_CurrentSetting;
                              /* Computed Parameter: ManualSwitch_CurrentSetting
                               * Referenced by: '<Root>/Manual Switch'
                               */
};

/* Real-time Model Data Structure */
struct tag_RTM_OnboardBlinkTest_T {
  const char_T *errorStatus;
};

/* Block parameters (default storage) */
extern P_OnboardBlinkTest_T OnboardBlinkTest_P;

/* Block states (default storage) */
extern DW_OnboardBlinkTest_T OnboardBlinkTest_DW;

/* Model entry point functions */
extern void OnboardBlinkTest_initialize(void);
extern void OnboardBlinkTest_step(void);
extern void OnboardBlinkTest_terminate(void);

/* Real-time Model object */
extern RT_MODEL_OnboardBlinkTest_T *const OnboardBlinkTest_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

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
 * '<Root>' : 'OnboardBlinkTest'
 */
#endif                                 /* RTW_HEADER_OnboardBlinkTest_h_ */
