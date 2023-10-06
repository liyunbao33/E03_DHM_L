/*
 * File: DHM.h
 *
 * Code generated for Simulink model 'DHM'.
 *
 * Model version                  : 1.305
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Fri Oct  6 23:30:33 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_DHM_h_
#define RTW_HEADER_DHM_h_
#ifndef DHM_COMMON_INCLUDES_
#define DHM_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* DHM_COMMON_INCLUDES_ */

#include "DHM_types.h"
#include "Rte_Type.h"
#include <stddef.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<S8>/CtrlLogic' */
typedef struct {
  uint8_T is_active_c1_DoorHndDriver;  /* '<S8>/CtrlLogic' */
  uint8_T is_Ctrl;                     /* '<S8>/CtrlLogic' */
  uint8_T is_Unfold;                   /* '<S8>/CtrlLogic' */
  uint8_T is_Icebreak;                 /* '<S8>/CtrlLogic' */
  uint8_T is_Fold;                     /* '<S8>/CtrlLogic' */
  uint8_T temporalCounter_i1;          /* '<S8>/CtrlLogic' */
  boolean_T SI_b_DoorHndUnfoldReq_prev;/* '<S8>/CtrlLogic' */
  boolean_T SI_b_DoorHndUnfoldReq_start;/* '<S8>/CtrlLogic' */
  boolean_T SI_b_DoorHndFoldReq_prev;  /* '<S8>/CtrlLogic' */
  boolean_T SI_b_DoorHndFoldReq_start; /* '<S8>/CtrlLogic' */
} DW_CtrlLogic_DHM_T;

/* Block states (default storage) for system '<S8>/DoorHndPos' */
typedef struct {
  uint8_T is_active_c5_DoorHndDriver;  /* '<S8>/DoorHndPos' */
} DW_DoorHndPos_DHM_T;

/* Block states (default storage) for system '<S8>/LearnLogic' */
typedef struct {
  uint8_T is_active_c3_DoorHndDriver;  /* '<S8>/LearnLogic' */
  uint8_T is_c3_DoorHndDriver;         /* '<S8>/LearnLogic' */
  uint8_T is_LearnLogic;               /* '<S8>/LearnLogic' */
  uint8_T SI_e_AutoLearnCount;         /* '<S8>/LearnLogic' */
  uint8_T temporalCounter_i1;          /* '<S8>/LearnLogic' */
  boolean_T SI_b_LearnReq_prev;        /* '<S8>/LearnLogic' */
  boolean_T SI_b_LearnReq_start;       /* '<S8>/LearnLogic' */
} DW_LearnLogic_DHM_T;

/* Block states (default storage) for system '<S8>/MotorLogic' */
typedef struct {
  uint8_T is_active_c4_DoorHndDriver;  /* '<S8>/MotorLogic' */
} DW_MotorLogic_DHM_T;

/* Block states (default storage) for system '<S8>/Stall' */
typedef struct {
  int16_T SL_s_CurrentPos_Old;         /* '<S8>/Stall' */
  uint8_T is_active_c2_DoorHndDriver;  /* '<S8>/Stall' */
  uint8_T is_Stall_Handler;            /* '<S8>/Stall' */
  uint8_T temporalCounter_i1;          /* '<S8>/Stall' */
} DW_Stall_DHM_T;

/* Block states (default storage) for system '<S3>/FLDoorHndReq' */
typedef struct {
  uint8_T is_active_c4_DoorHndReq;     /* '<S3>/FLDoorHndReq' */
  uint8_T is_Unfold;                   /* '<S3>/FLDoorHndReq' */
  uint8_T is_Fold;                     /* '<S3>/FLDoorHndReq' */
  uint8_T temporalCounter_i1;          /* '<S3>/FLDoorHndReq' */
  uint8_T temporalCounter_i2;          /* '<S3>/FLDoorHndReq' */
  boolean_T SI_b_CrashOutpSts_prev;    /* '<S3>/FLDoorHndReq' */
  boolean_T SI_b_CrashOutpSts_start;   /* '<S3>/FLDoorHndReq' */
} DW_FLDoorHndReq_DHM_T;

/* Block signals (default storage) */
typedef struct {
  int16_T SO_s_MaxSoftPos;             /* '<S11>/DoorHndPos' */
  int16_T SO_s_MinSoftPos;             /* '<S11>/DoorHndPos' */
  int16_T SO_s_IceBrkPos;              /* '<S11>/DoorHndPos' */
  int16_T SO_s_MaxSoftPos_k;           /* '<S8>/DoorHndPos' */
  int16_T SO_s_MinSoftPos_n;           /* '<S8>/DoorHndPos' */
  int16_T SO_s_IceBrkPos_k;            /* '<S8>/DoorHndPos' */
  uint8_T SO_e_MotorCmd;               /* '<S11>/MotorLogic' */
  uint8_T SO_e_MotorCmd_a;             /* '<S11>/LearnLogic' */
  uint8_T SO_e_MotorPwm_e;             /* '<S11>/LearnLogic' */
  uint8_T SO_e_MotorCmd_c;             /* '<S8>/MotorLogic' */
  uint8_T SO_e_MotorCmd_j;             /* '<S8>/LearnLogic' */
  uint8_T SO_e_MotorPwm_m;             /* '<S8>/LearnLogic' */
  boolean_T SO_b_HndUnfoldReq;         /* '<S3>/RRDoorHndReq' */
  boolean_T SO_b_HndFoldReq;           /* '<S3>/RRDoorHndReq' */
  boolean_T SO_b_HndUnfoldReq_a;       /* '<S3>/RLDoorHndReq' */
  boolean_T SO_b_HndFoldReq_a;         /* '<S3>/RLDoorHndReq' */
  boolean_T SO_b_HallStall;            /* '<S11>/Stall' */
  boolean_T SO_b_HndUnfoldReq_k;       /* '<S3>/FRDoorHndReq' */
  boolean_T SO_b_HndFoldReq_d;         /* '<S3>/FRDoorHndReq' */
  boolean_T SO_b_HndUnfoldReq_j;       /* '<S3>/FLDoorHndReq' */
  boolean_T SO_b_HndFoldReq_dm;        /* '<S3>/FLDoorHndReq' */
  boolean_T SO_b_HallStall_m;          /* '<S8>/Stall' */
  Learn_Sts_E SO_m_LearnSts;           /* '<S11>/LearnLogic' */
  Learn_Sts_E SO_m_LearnSts_b;         /* '<S8>/LearnLogic' */
} B_DHM_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  int16_T UnitDelay5_DSTATE;           /* '<S8>/Unit Delay5' */
  int16_T UnitDelay5_DSTATE_h;         /* '<S11>/Unit Delay5' */
  uint8_T UnitDelay1_DSTATE;           /* '<S8>/Unit Delay1' */
  uint8_T UnitDelay1_DSTATE_f;         /* '<S11>/Unit Delay1' */
  boolean_T UnitDelay4_DSTATE;         /* '<S8>/Unit Delay4' */
  boolean_T UnitDelay4_DSTATE_n;       /* '<S11>/Unit Delay4' */
  DW_FLDoorHndReq_DHM_T sf_RRDoorHndReq;/* '<S3>/RRDoorHndReq' */
  DW_FLDoorHndReq_DHM_T sf_RLDoorHndReq;/* '<S3>/RLDoorHndReq' */
  DW_Stall_DHM_T sf_Stall_m;           /* '<S11>/Stall' */
  DW_MotorLogic_DHM_T sf_MotorLogic_l; /* '<S11>/MotorLogic' */
  DW_LearnLogic_DHM_T sf_LearnLogic_d; /* '<S11>/LearnLogic' */
  DW_DoorHndPos_DHM_T sf_DoorHndPos_m; /* '<S11>/DoorHndPos' */
  DW_CtrlLogic_DHM_T sf_CtrlLogic_g;   /* '<S11>/CtrlLogic' */
  DW_FLDoorHndReq_DHM_T sf_FRDoorHndReq;/* '<S3>/FRDoorHndReq' */
  DW_FLDoorHndReq_DHM_T sf_FLDoorHndReq;/* '<S3>/FLDoorHndReq' */
  DW_Stall_DHM_T sf_Stall;             /* '<S8>/Stall' */
  DW_MotorLogic_DHM_T sf_MotorLogic;   /* '<S8>/MotorLogic' */
  DW_LearnLogic_DHM_T sf_LearnLogic;   /* '<S8>/LearnLogic' */
  DW_DoorHndPos_DHM_T sf_DoorHndPos;   /* '<S8>/DoorHndPos' */
  DW_CtrlLogic_DHM_T sf_CtrlLogic;     /* '<S8>/CtrlLogic' */
} DW_DHM_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  UInt8 VeINP_CAN_PowerMode_sig_VeINP_C;
                  /* '<Root>/VeINP_CAN_PowerMode_sig_VeINP_CAN_PowerMode_sig' */
  UInt8 VeOUT_DLK_LHFDoorLockSts_sig_Ve;
        /* '<Root>/VeOUT_DLK_LHFDoorLockSts_sig_VeOUT_DLK_LHFDoorLockSts_sig' */
  UInt8 VeOUT_SP_EspVehSpd_kmh_VeOUT_SP;
                    /* '<Root>/VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh' */
  SInt16 VsINP_HWA_DriverHandleHall_sig_;
    /* '<Root>/VsINP_HWA_DriverHandleHall_sig_VsINP_HWA_DriverHandleHall_sig' */
  SInt16 VsINP_HWA_RLHandleHall_sig_VsIN;
            /* '<Root>/VsINP_HWA_RLHandleHall_sig_VsINP_HWA_RLHandleHall_sig' */
  UInt8 VeINP_CAN_FRDoorHandleSts_sig_V;
      /* '<Root>/VeINP_CAN_FRDoorHandleSts_sig_VeINP_CAN_FRDoorHandleSts_sig' */
  UInt8 VeINP_CAN_RRDoorHandleSts_sig_V;
      /* '<Root>/VeINP_CAN_RRDoorHandleSts_sig_VeINP_CAN_RRDoorHandleSts_sig' */
  UInt8 VeOUT_SP_LHFdoorSts_sig_VeOUT_S;
                  /* '<Root>/VeOUT_SP_LHFdoorSts_sig_VeOUT_SP_LHFdoorSts_sig' */
  UInt8 VeOUT_SP_LHRdoorSts_sig_VeOUT_S;
                  /* '<Root>/VeOUT_SP_LHRdoorSts_sig_VeOUT_SP_LHRdoorSts_sig' */
  UInt8 VeINP_CAN_RHFDoorSts_sig_VeINP_;
                /* '<Root>/VeINP_CAN_RHFDoorSts_sig_VeINP_CAN_RHFDoorSts_sig' */
  UInt8 VeINP_CAN_RHRDoorSts_sig_VeINP_;
                /* '<Root>/VeINP_CAN_RHRDoorSts_sig_VeINP_CAN_RHRDoorSts_sig' */
  Boolean VbOUT_SP_CrashOutpSts_flg_VbOUT;
              /* '<Root>/VbOUT_SP_CrashOutpSts_flg_VbOUT_SP_CrashOutpSts_flg' */
  SInt16 VsINP_EPRM_FLDoorHandleFromEE_s;
  /* '<Root>/VsINP_EPRM_FLDoorHandleFromEE_sig_VsINP_EPRM_FLDoorHandleFromEE_sig' */
  SInt16 VsINP_EPRM_RLDoorHandleFromEE_s;
  /* '<Root>/VsINP_EPRM_RLDoorHandleFromEE_sig_VsINP_EPRM_RLDoorHandleFromEE_sig' */
  UInt8 VeINP_EPRM_FLDoorHandleLrnStsEE;
  /* '<Root>/VeINP_EPRM_FLDoorHandleLrnStsEE_sig_VeINP_EPRM_FLDoorHandleLrnStsEE_sig' */
  UInt8 VeINP_EPRM_RLDoorHandleLrnStsEE;
  /* '<Root>/VeINP_EPRM_RLDoorHandleLrnStsEE_sig_VeINP_EPRM_RLDoorHandleLrnStsEE_sig' */
  UInt8 VeINP_CAN_FRDoorHandleLrnSts_si;
  /* '<Root>/VeINP_CAN_FRDoorHandleLrnSts_sig_VeINP_CAN_FRDoorHandleLrnSts_sig' */
  UInt8 VeINP_CAN_RRDoorHandleLrnSts_si;
  /* '<Root>/VeINP_CAN_RRDoorHandleLrnSts_sig_VeINP_CAN_RRDoorHandleLrnSts_sig' */
  Boolean VbINP_HWA_DoorHandleLrnReq_flg_;
    /* '<Root>/VbINP_HWA_DoorHandleLrnReq_flg_VbINP_HWA_DoorHandleLrnReq_flg' */
} ExtU_DHM_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  UInt8 VeOUT_DHM_FLHandleFoldedStatus_;
  /* '<Root>/VeOUT_DHM_FLHandleFoldedStatus_sig_VeOUT_DHM_FLHandleFoldedStatus_sig' */
  UInt8 VeOUT_DHM_RLHandleFoldedStatus_;
  /* '<Root>/VeOUT_DHM_RLHandleFoldedStatus_sig_VeOUT_DHM_RLHandleFoldedStatus_sig' */
  UInt8 VeOUT_DHM_FRHandleFoldedStatus_;
  /* '<Root>/VeOUT_DHM_FRHandleFoldedStatus_sig_VeOUT_DHM_FRHandleFoldedStatus_sig' */
  UInt8 VeOUT_DHM_RRHandleFoldedStatus_;
  /* '<Root>/VeOUT_DHM_RRHandleFoldedStatus_sig_VeOUT_DHM_RRHandleFoldedStatus_sig' */
  UInt8 VeOUT_DHM_FRDoorHandleReq_sig_V;
      /* '<Root>/VeOUT_DHM_FRDoorHandleReq_sig_VeOUT_DHM_FRDoorHandleReq_sig' */
  UInt8 VeOUT_DHM_RRDoorHandleReq_sig_V;
      /* '<Root>/VeOUT_DHM_RRDoorHandleReq_sig_VeOUT_DHM_RRDoorHandleReq_sig' */
  Boolean VbOUT_DHM_FLHadUnfold_flg_VbOUT;
              /* '<Root>/VbOUT_DHM_FLHadUnfold_flg_VbOUT_DHM_FLHadUnfold_flg' */
  Boolean VbOUT_DHM_FLHadFold_flg_VbOUT_D;
                  /* '<Root>/VbOUT_DHM_FLHadFold_flg_VbOUT_DHM_FLHadFold_flg' */
  Boolean VbOUT_DHM_RLHandleUnfold_flg_Vb;
        /* '<Root>/VbOUT_DHM_RLHandleUnfold_flg_VbOUT_DHM_RLHandleUnfold_flg' */
  Boolean VbOUT_DHM_RLHandleFold_flg_VbOU;
            /* '<Root>/VbOUT_DHM_RLHandleFold_flg_VbOUT_DHM_RLHandleFold_flg' */
  SInt16 VsINP_DHM_FLDoorHandleEE_sig_Vs;
        /* '<Root>/VsINP_DHM_FLDoorHandleEE_sig_VsINP_DHM_FLDoorHandleEE_sig' */
  SInt16 VsINP_DHM_RLDoorHandleEE_sig_Vs;
        /* '<Root>/VsINP_DHM_RLDoorHandleEE_sig_VsINP_DHM_RLDoorHandleEE_sig' */
  UInt8 VeOUT_DHM_DoorHandleLrnSts_sig_;
    /* '<Root>/VeOUT_DHM_DoorHandleLrnSts_sig_VeOUT_DHM_DoorHandleLrnSts_sig' */
  UInt8 VeOUT_DHM_FLDoorHandleLrnStsEE_;
  /* '<Root>/VeOUT_DHM_FLDoorHandleLrnStsEE_sig_VeOUT_DHM_FLDoorHandleLrnStsEE_sig' */
  UInt8 VeOUT_DHM_RLDoorHandleLrnStsEE_;
  /* '<Root>/VeOUT_DHM_RLDoorHandleLrnStsEE_sig_VeOUT_DHM_RLDoorHandleLrnStsEE_sig' */
  Boolean VbOUT_DHM_DoorHandleLrnReq_flg_;
    /* '<Root>/VbOUT_DHM_DoorHandleLrnReq_flg_VbOUT_DHM_DoorHandleLrnReq_flg' */
} ExtY_DHM_T;

/* Real-time Model Data Structure */
struct tag_RTM_DHM_T {
  const char_T * volatile errorStatus;
};

/* Block signals (default storage) */
extern B_DHM_T DHM_B;

/* Block states (default storage) */
extern DW_DHM_T DHM_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_DHM_T DHM_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_DHM_T DHM_Y;

/* Model entry point functions */
extern void DHM_initialize(void);
extern void DHM_terminate(void);

/* Exported entry point function */
extern void DHM_Step(void);

/* Real-time Model object */
extern RT_MODEL_DHM_T *const DHM_M;

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
 * '<Root>' : 'DHM'
 * '<S1>'   : 'DHM/DHM_Init'
 * '<S2>'   : 'DHM/DHM_Step_sys'
 * '<S3>'   : 'DHM/DHM_Step_sys/DHM'
 * '<S4>'   : 'DHM/DHM_Step_sys/DHM/Compare To Constant'
 * '<S5>'   : 'DHM/DHM_Step_sys/DHM/Compare To Constant1'
 * '<S6>'   : 'DHM/DHM_Step_sys/DHM/Compare To Constant2'
 * '<S7>'   : 'DHM/DHM_Step_sys/DHM/Compare To Constant3'
 * '<S8>'   : 'DHM/DHM_Step_sys/DHM/FLDoorHndDriver'
 * '<S9>'   : 'DHM/DHM_Step_sys/DHM/FLDoorHndReq'
 * '<S10>'  : 'DHM/DHM_Step_sys/DHM/FRDoorHndReq'
 * '<S11>'  : 'DHM/DHM_Step_sys/DHM/RLDoorHndDriver'
 * '<S12>'  : 'DHM/DHM_Step_sys/DHM/RLDoorHndReq'
 * '<S13>'  : 'DHM/DHM_Step_sys/DHM/RRDoorHndReq'
 * '<S14>'  : 'DHM/DHM_Step_sys/DHM/Recycle Bin'
 * '<S15>'  : 'DHM/DHM_Step_sys/DHM/FLDoorHndDriver/CtrlLogic'
 * '<S16>'  : 'DHM/DHM_Step_sys/DHM/FLDoorHndDriver/DoorHndPos'
 * '<S17>'  : 'DHM/DHM_Step_sys/DHM/FLDoorHndDriver/LearnLogic'
 * '<S18>'  : 'DHM/DHM_Step_sys/DHM/FLDoorHndDriver/MotorLogic'
 * '<S19>'  : 'DHM/DHM_Step_sys/DHM/FLDoorHndDriver/Stall'
 * '<S20>'  : 'DHM/DHM_Step_sys/DHM/RLDoorHndDriver/CtrlLogic'
 * '<S21>'  : 'DHM/DHM_Step_sys/DHM/RLDoorHndDriver/DoorHndPos'
 * '<S22>'  : 'DHM/DHM_Step_sys/DHM/RLDoorHndDriver/LearnLogic'
 * '<S23>'  : 'DHM/DHM_Step_sys/DHM/RLDoorHndDriver/MotorLogic'
 * '<S24>'  : 'DHM/DHM_Step_sys/DHM/RLDoorHndDriver/Stall'
 */
#endif                                 /* RTW_HEADER_DHM_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
