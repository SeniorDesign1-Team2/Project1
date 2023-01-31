/*
 * OnboardBlinkTest.c
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

#include "OnboardBlinkTest.h"
#include "OnboardBlinkTest_private.h"

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
  uint16_T rtb_AnalogInput;
  uint16_T rtb_AnalogInput1;
  uint8_T tmp_0;

  /* MATLABSystem: '<Root>/Analog Input' */
  if (OnboardBlinkTest_DW.obj_n.SampleTime !=
      OnboardBlinkTest_P.AnalogInput_SampleTime) {
    OnboardBlinkTest_DW.obj_n.SampleTime =
      OnboardBlinkTest_P.AnalogInput_SampleTime;
  }

  obj = &OnboardBlinkTest_DW.obj_n;
  obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(62UL);
  MW_AnalogInSingle_ReadResult
    (OnboardBlinkTest_DW.obj_n.AnalogInDriverObj.MW_ANALOGIN_HANDLE,
     &rtb_AnalogInput, 3);

  /* End of MATLABSystem: '<Root>/Analog Input' */
  /* MATLABSystem: '<Root>/Analog Input1' */
  if (OnboardBlinkTest_DW.obj.SampleTime !=
      OnboardBlinkTest_P.AnalogInput1_SampleTime) {
    OnboardBlinkTest_DW.obj.SampleTime =
      OnboardBlinkTest_P.AnalogInput1_SampleTime;
  }

  obj = &OnboardBlinkTest_DW.obj;
  obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(63UL);
  MW_AnalogInSingle_ReadResult
    (OnboardBlinkTest_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE,
     &rtb_AnalogInput1, 3);

  /* End of MATLABSystem: '<Root>/Analog Input1' */
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

  /* MATLABSystem: '<Root>/Digital Output1' incorporates:
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

  writeDigitalPin(4, tmp_0);

  /* End of MATLABSystem: '<Root>/Digital Output1' */

  /* MATLABSystem: '<Root>/Digital Output2' incorporates:
   *  Constant: '<Root>/Constant3'
   */
  tmp = rt_roundd_snf(OnboardBlinkTest_P.Constant3_Value);
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
}

/* Model initialize function */
void OnboardBlinkTest_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(OnboardBlinkTest_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&OnboardBlinkTest_DW, 0,
                sizeof(DW_OnboardBlinkTest_T));

  {
    codertarget_arduinobase_inter_T *obj;

    /* Start for MATLABSystem: '<Root>/Analog Input' */
    OnboardBlinkTest_DW.obj_n.matlabCodegenIsDeleted = true;
    OnboardBlinkTest_DW.obj_n.isInitialized = 0L;
    OnboardBlinkTest_DW.obj_n.SampleTime = -1.0;
    OnboardBlinkTest_DW.obj_n.matlabCodegenIsDeleted = false;
    OnboardBlinkTest_DW.objisempty_j = true;
    OnboardBlinkTest_DW.obj_n.SampleTime =
      OnboardBlinkTest_P.AnalogInput_SampleTime;
    obj = &OnboardBlinkTest_DW.obj_n;
    OnboardBlinkTest_DW.obj_n.isSetupComplete = false;
    OnboardBlinkTest_DW.obj_n.isInitialized = 1L;
    obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(62UL);
    OnboardBlinkTest_DW.obj_n.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Analog Input1' */
    OnboardBlinkTest_DW.obj.matlabCodegenIsDeleted = true;
    OnboardBlinkTest_DW.obj.isInitialized = 0L;
    OnboardBlinkTest_DW.obj.SampleTime = -1.0;
    OnboardBlinkTest_DW.obj.matlabCodegenIsDeleted = false;
    OnboardBlinkTest_DW.objisempty_f = true;
    OnboardBlinkTest_DW.obj.SampleTime =
      OnboardBlinkTest_P.AnalogInput1_SampleTime;
    obj = &OnboardBlinkTest_DW.obj;
    OnboardBlinkTest_DW.obj.isSetupComplete = false;
    OnboardBlinkTest_DW.obj.isInitialized = 1L;
    obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(63UL);
    OnboardBlinkTest_DW.obj.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Output' */
    OnboardBlinkTest_DW.obj_g.matlabCodegenIsDeleted = false;
    OnboardBlinkTest_DW.objisempty_n = true;
    OnboardBlinkTest_DW.obj_g.isInitialized = 1L;
    digitalIOSetup(13, 1);
    OnboardBlinkTest_DW.obj_g.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Output1' */
    OnboardBlinkTest_DW.obj_i.matlabCodegenIsDeleted = false;
    OnboardBlinkTest_DW.objisempty_g = true;
    OnboardBlinkTest_DW.obj_i.isInitialized = 1L;
    digitalIOSetup(4, 1);
    OnboardBlinkTest_DW.obj_i.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Output2' */
    OnboardBlinkTest_DW.obj_nv.matlabCodegenIsDeleted = false;
    OnboardBlinkTest_DW.objisempty = true;
    OnboardBlinkTest_DW.obj_nv.isInitialized = 1L;
    digitalIOSetup(5, 1);
    OnboardBlinkTest_DW.obj_nv.isSetupComplete = true;
  }
}

/* Model terminate function */
void OnboardBlinkTest_terminate(void)
{
  codertarget_arduinobase_inter_T *obj;

  /* Terminate for MATLABSystem: '<Root>/Analog Input' */
  obj = &OnboardBlinkTest_DW.obj_n;
  if (!OnboardBlinkTest_DW.obj_n.matlabCodegenIsDeleted) {
    OnboardBlinkTest_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((OnboardBlinkTest_DW.obj_n.isInitialized == 1L) &&
        OnboardBlinkTest_DW.obj_n.isSetupComplete) {
      obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(62UL);
      MW_AnalogIn_Close
        (OnboardBlinkTest_DW.obj_n.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Analog Input' */

  /* Terminate for MATLABSystem: '<Root>/Analog Input1' */
  obj = &OnboardBlinkTest_DW.obj;
  if (!OnboardBlinkTest_DW.obj.matlabCodegenIsDeleted) {
    OnboardBlinkTest_DW.obj.matlabCodegenIsDeleted = true;
    if ((OnboardBlinkTest_DW.obj.isInitialized == 1L) &&
        OnboardBlinkTest_DW.obj.isSetupComplete) {
      obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(63UL);
      MW_AnalogIn_Close
        (OnboardBlinkTest_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Analog Input1' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output' */
  if (!OnboardBlinkTest_DW.obj_g.matlabCodegenIsDeleted) {
    OnboardBlinkTest_DW.obj_g.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output1' */
  if (!OnboardBlinkTest_DW.obj_i.matlabCodegenIsDeleted) {
    OnboardBlinkTest_DW.obj_i.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output1' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output2' */
  if (!OnboardBlinkTest_DW.obj_nv.matlabCodegenIsDeleted) {
    OnboardBlinkTest_DW.obj_nv.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output2' */
}
