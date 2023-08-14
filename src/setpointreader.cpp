//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: setpointreader.cpp
//
// Code generated for Simulink model 'setpointreader'.
//
// Model version                  : 4.2
// Simulink Coder version         : 9.8 (R2022b) 13-May-2022
// C/C++ source code generated on : Mon Aug 14 11:33:06 2023
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "setpointreader.h"
#include "rtwtypes.h"
#include "setpointreader_types.h"

// Block signals (default storage)
B_setpointreader_T setpointreader_B;

// Block states (default storage)
DW_setpointreader_T setpointreader_DW;

// Real-time model
RT_MODEL_setpointreader_T setpointreader_M_ = RT_MODEL_setpointreader_T();
RT_MODEL_setpointreader_T *const setpointreader_M = &setpointreader_M_;

// Model step function
void setpointreader_step(void)
{
  SL_Bus_setpointreader_geometry_msgs_Point b_varargout_2;
  boolean_T b_varargout_1;

  // Outputs for Atomic SubSystem: '<Root>/Subscribe1'
  // MATLABSystem: '<S3>/SourceBlock'
  b_varargout_1 = Sub_setpointreader_31.getLatestMessage(&b_varargout_2);

  // Outputs for Enabled SubSystem: '<S3>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S4>/Enable'

  if (b_varargout_1) {
    // SignalConversion generated from: '<S4>/In1'
    setpointreader_B.In1 = b_varargout_2;
  }

  // End of MATLABSystem: '<S3>/SourceBlock'
  // End of Outputs for SubSystem: '<S3>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<Root>/Subscribe1'

  // BusAssignment: '<Root>/Bus Assignment' incorporates:
  //   Constant: '<S1>/Constant'
  //   Gain: '<Root>/Gain'

  setpointreader_B.BusAssignment = setpointreader_P.Constant_Value;
  setpointreader_B.BusAssignment.Linear.X = setpointreader_P.Gain_Gain *
    setpointreader_B.In1.Y;

  // Outputs for Atomic SubSystem: '<Root>/Publish'
  // MATLABSystem: '<S2>/SinkBlock'
  Pub_setpointreader_3.publish(&setpointreader_B.BusAssignment);

  // End of Outputs for SubSystem: '<Root>/Publish'
}

// Model initialize function
void setpointreader_initialize(void)
{
  {
    char_T b_zeroDelimTopic[8];
    char_T b_zeroDelimTopic_0[6];
    static const char_T tmp[7] = { 'm', 's', 'g', '_', '4', '6', '7' };

    static const char_T tmp_0[5] = { 'v', '_', 'r', 'e', 'f' };

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe1'
    // SystemInitialize for Enabled SubSystem: '<S3>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S4>/In1' incorporates:
    //   Outport: '<S4>/Out1'

    setpointreader_B.In1 = setpointreader_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S3>/Enabled Subsystem'

    // Start for MATLABSystem: '<S3>/SourceBlock'
    setpointreader_DW.obj_g.matlabCodegenIsDeleted = false;
    setpointreader_DW.obj_g.isInitialized = 1;
    for (int32_T i = 0; i < 7; i++) {
      b_zeroDelimTopic[i] = tmp[i];
    }

    b_zeroDelimTopic[7] = '\x00';
    Sub_setpointreader_31.createSubscriber(&b_zeroDelimTopic[0], 1);
    setpointreader_DW.obj_g.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S3>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe1'

    // SystemInitialize for Atomic SubSystem: '<Root>/Publish'
    // Start for MATLABSystem: '<S2>/SinkBlock'
    setpointreader_DW.obj.matlabCodegenIsDeleted = false;
    setpointreader_DW.obj.isInitialized = 1;
    for (int32_T i = 0; i < 5; i++) {
      b_zeroDelimTopic_0[i] = tmp_0[i];
    }

    b_zeroDelimTopic_0[5] = '\x00';
    Pub_setpointreader_3.createPublisher(&b_zeroDelimTopic_0[0], 1);
    setpointreader_DW.obj.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S2>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Publish'
  }
}

// Model terminate function
void setpointreader_terminate(void)
{
  // Terminate for Atomic SubSystem: '<Root>/Subscribe1'
  // Terminate for MATLABSystem: '<S3>/SourceBlock'
  if (!setpointreader_DW.obj_g.matlabCodegenIsDeleted) {
    setpointreader_DW.obj_g.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S3>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe1'

  // Terminate for Atomic SubSystem: '<Root>/Publish'
  // Terminate for MATLABSystem: '<S2>/SinkBlock'
  if (!setpointreader_DW.obj.matlabCodegenIsDeleted) {
    setpointreader_DW.obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S2>/SinkBlock'
  // End of Terminate for SubSystem: '<Root>/Publish'
}

//
// File trailer for generated code.
//
// [EOF]
//
