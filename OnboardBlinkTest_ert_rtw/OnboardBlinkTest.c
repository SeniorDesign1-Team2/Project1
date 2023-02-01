/*
 * OnboardBlinkTest.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "OnboardBlinkTest".
 *
 * Model version              : 1.5
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C source code generated on : Wed Feb  1 18:27:15 2023
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "OnboardBlinkTest.h"
#include "OnboardBlinkTest_private.h"

/* Block signals (default storage) */
B_OnboardBlinkTest_T OnboardBlinkTest_B;

/* Block states (default storage) */
DW_OnboardBlinkTest_T OnboardBlinkTest_DW;

/* Real-time model */
static RT_MODEL_OnboardBlinkTest_T OnboardBlinkTest_M_;
RT_MODEL_OnboardBlinkTest_T *const OnboardBlinkTest_M = &OnboardBlinkTest_M_;
real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/* Model step function */
void OnboardBlinkTest_step(void)
{
  codertarget_arduinobase_inter_T *obj;
  real_T tmp;
  uint8_T tmp_0;

  /* MATLABSystem: '<Root>/Analog Input2' */
  if (OnboardBlinkTest_DW.obj.SampleTime !=
      OnboardBlinkTest_P.AnalogInput2_SampleTime) {
    OnboardBlinkTest_DW.obj.SampleTime =
      OnboardBlinkTest_P.AnalogInput2_SampleTime;
  }

  obj = &OnboardBlinkTest_DW.obj;
  obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(62UL);

  /* MATLABSystem: '<Root>/Analog Input2' */
  MW_AnalogInSingle_ReadResult
    (OnboardBlinkTest_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE,
     &OnboardBlinkTest_B.AnalogInput2, 3);

  /* MATLABSystem: '<Root>/Digital Output3' incorporates:
   *  Constant: '<S1>/Constant'
   *  RelationalOperator: '<S1>/Compare'
   */
  writeDigitalPin(4, (uint8_T)(OnboardBlinkTest_B.AnalogInput2 >=
    OnboardBlinkTest_P.CompareToConstant_const));

  /* ManualSwitch: '<Root>/Manual Switch' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant1'
   */
  if (OnboardBlinkTest_P.ManualSwitch_CurrentSetting == 1) {
    tmp = OnboardBlinkTest_P.Constant1_Value;
  } else {
    tmp = OnboardBlinkTest_P.Constant_Value;
  }

  /* End of ManualSwitch: '<Root>/Manual Switch' */

  /* MATLABSystem: '<Root>/Digital Output' */
  tmp = rt_roundd_snf(tmp);
  if (tmp < 256.0) {
    if (tmp >= 0.0) {
      tmp_0 = (uint8_T)tmp;
    } else {
      tmp_0 = 0U;
    }
  } else {
    tmp_0 = MAX_uint8_T;
  }

  writeDigitalPin(13, tmp_0);

  /* End of MATLABSystem: '<Root>/Digital Output' */

  /* MATLABSystem: '<Root>/Digital Output2' incorporates:
   *  Constant: '<Root>/Constant2'
   */
  tmp = rt_roundd_snf(OnboardBlinkTest_P.Constant2_Value);
  if (tmp < 256.0) {
    if (tmp >= 0.0) {
      tmp_0 = (uint8_T)tmp;
    } else {
      tmp_0 = 0U;
    }
  } else {
    tmp_0 = MAX_uint8_T;
  }

  writeDigitalPin(5, tmp_0);

  /* End of MATLABSystem: '<Root>/Digital Output2' */
  {                                    /* Sample time: [0.2s, 0.0s] */
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++OnboardBlinkTest_M->Timing.clockTick0)) {
    ++OnboardBlinkTest_M->Timing.clockTickH0;
  }

  OnboardBlinkTest_M->Timing.taskTime0 = OnboardBlinkTest_M->Timing.clockTick0 *
    OnboardBlinkTest_M->Timing.stepSize0 +
    OnboardBlinkTest_M->Timing.clockTickH0 *
    OnboardBlinkTest_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void OnboardBlinkTest_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)OnboardBlinkTest_M, 0,
                sizeof(RT_MODEL_OnboardBlinkTest_T));
  rtmSetTFinal(OnboardBlinkTest_M, -1);
  OnboardBlinkTest_M->Timing.stepSize0 = 0.2;

  /* External mode info */
  OnboardBlinkTest_M->Sizes.checksums[0] = (3728881407U);
  OnboardBlinkTest_M->Sizes.checksums[1] = (2602268688U);
  OnboardBlinkTest_M->Sizes.checksums[2] = (1414377679U);
  OnboardBlinkTest_M->Sizes.checksums[3] = (3858354187U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[7];
    OnboardBlinkTest_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(OnboardBlinkTest_M->extModeInfo,
      &OnboardBlinkTest_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(OnboardBlinkTest_M->extModeInfo,
                        OnboardBlinkTest_M->Sizes.checksums);
    rteiSetTPtr(OnboardBlinkTest_M->extModeInfo, rtmGetTPtr(OnboardBlinkTest_M));
  }

  /* block I/O */
  (void) memset(((void *) &OnboardBlinkTest_B), 0,
                sizeof(B_OnboardBlinkTest_T));

  /* states (dwork) */
  (void) memset((void *)&OnboardBlinkTest_DW, 0,
                sizeof(DW_OnboardBlinkTest_T));

  {
    codertarget_arduinobase_inter_T *obj;

    /* Start for MATLABSystem: '<Root>/Analog Input2' */
    OnboardBlinkTest_DW.obj.matlabCodegenIsDeleted = true;
    OnboardBlinkTest_DW.obj.isInitialized = 0L;
    OnboardBlinkTest_DW.obj.SampleTime = -1.0;
    OnboardBlinkTest_DW.obj.matlabCodegenIsDeleted = false;
    OnboardBlinkTest_DW.objisempty_b = true;
    OnboardBlinkTest_DW.obj.SampleTime =
      OnboardBlinkTest_P.AnalogInput2_SampleTime;
    obj = &OnboardBlinkTest_DW.obj;
    OnboardBlinkTest_DW.obj.isSetupComplete = false;
    OnboardBlinkTest_DW.obj.isInitialized = 1L;
    obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(62UL);
    OnboardBlinkTest_DW.obj.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Output3' */
    OnboardBlinkTest_DW.obj_o.matlabCodegenIsDeleted = false;
    OnboardBlinkTest_DW.objisempty = true;
    OnboardBlinkTest_DW.obj_o.isInitialized = 1L;
    digitalIOSetup(4, 1);
    OnboardBlinkTest_DW.obj_o.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Output' */
    OnboardBlinkTest_DW.obj_g.matlabCodegenIsDeleted = false;
    OnboardBlinkTest_DW.objisempty_n = true;
    OnboardBlinkTest_DW.obj_g.isInitialized = 1L;
    digitalIOSetup(13, 1);
    OnboardBlinkTest_DW.obj_g.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Output2' */
    OnboardBlinkTest_DW.obj_b.matlabCodegenIsDeleted = false;
    OnboardBlinkTest_DW.objisempty_c = true;
    OnboardBlinkTest_DW.obj_b.isInitialized = 1L;
    digitalIOSetup(5, 1);
    OnboardBlinkTest_DW.obj_b.isSetupComplete = true;
  }
}

/* Model terminate function */
void OnboardBlinkTest_terminate(void)
{
  codertarget_arduinobase_inter_T *obj;

  /* Terminate for MATLABSystem: '<Root>/Analog Input2' */
  obj = &OnboardBlinkTest_DW.obj;
  if (!OnboardBlinkTest_DW.obj.matlabCodegenIsDeleted) {
    OnboardBlinkTest_DW.obj.matlabCodegenIsDeleted = true;
    if ((OnboardBlinkTest_DW.obj.isInitialized == 1L) &&
        OnboardBlinkTest_DW.obj.isSetupComplete) {
      obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(62UL);
      MW_AnalogIn_Close
        (OnboardBlinkTest_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Analog Input2' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output3' */
  if (!OnboardBlinkTest_DW.obj_o.matlabCodegenIsDeleted) {
    OnboardBlinkTest_DW.obj_o.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output3' */
  /* Terminate for MATLABSystem: '<Root>/Digital Output' */
  if (!OnboardBlinkTest_DW.obj_g.matlabCodegenIsDeleted) {
    OnboardBlinkTest_DW.obj_g.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output2' */
  if (!OnboardBlinkTest_DW.obj_b.matlabCodegenIsDeleted) {
    OnboardBlinkTest_DW.obj_b.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output2' */
}
