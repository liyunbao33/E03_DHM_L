/*
 * File: DHM.h
 *
 * Code generated for Simulink model 'DHM'.
 *
 * Model version                  : 1.386
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Tue Oct 17 20:34:25 2023
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

/* Block states (default storage) for system '<S16>/CtrlLogic' */
typedef struct {
  uint8_T is_active_c1_DoorHndDriver;  /* '<S16>/CtrlLogic' */
  uint8_T is_Ctrl;                     /* '<S16>/CtrlLogic' */
  uint8_T is_Unfold;                   /* '<S16>/CtrlLogic' */
  uint8_T is_Icebreak;                 /* '<S16>/CtrlLogic' */
  uint8_T is_Fold;                     /* '<S16>/CtrlLogic' */
  uint8_T SL_e_CycleCount;             /* '<S16>/CtrlLogic' */
  uint8_T SL_e_IceBrkCount;            /* '<S16>/CtrlLogic' */
  uint8_T temporalCounter_i1;          /* '<S16>/CtrlLogic' */
  boolean_T SI_b_DoorHndUnfoldReq_prev;/* '<S16>/CtrlLogic' */
  boolean_T SI_b_DoorHndUnfoldReq_start;/* '<S16>/CtrlLogic' */
  boolean_T SI_b_DoorHndFoldReq_prev;  /* '<S16>/CtrlLogic' */
  boolean_T SI_b_DoorHndFoldReq_start; /* '<S16>/CtrlLogic' */
} DW_CtrlLogic_DHM_T;

/* Block states (default storage) for system '<S16>/DoorHndPos' */
typedef struct {
  uint8_T is_active_c5_DoorHndDriver;  /* '<S16>/DoorHndPos' */
} DW_DoorHndPos_DHM_T;

/* Block states (default storage) for system '<S16>/LearnLogic' */
typedef struct {
  uint16_T temporalCounter_i1;         /* '<S16>/LearnLogic' */
  uint8_T is_active_c3_DoorHndDriver;  /* '<S16>/LearnLogic' */
  uint8_T is_c3_DoorHndDriver;         /* '<S16>/LearnLogic' */
  uint8_T is_LearnLogic;               /* '<S16>/LearnLogic' */
  uint8_T SL_e_AutoLearnCount;         /* '<S16>/LearnLogic' */
  uint8_T SL_e_tempPos;                /* '<S16>/LearnLogic' */
  boolean_T SI_b_LearnReq_prev;        /* '<S16>/LearnLogic' */
  boolean_T SI_b_LearnReq_start;       /* '<S16>/LearnLogic' */
} DW_LearnLogic_DHM_T;

/* Block states (default storage) for system '<S16>/MotorLogic' */
typedef struct {
  uint8_T is_active_c4_DoorHndDriver;  /* '<S16>/MotorLogic' */
} DW_MotorLogic_DHM_T;

/* Block states (default storage) for system '<S16>/Stall' */
typedef struct {
  int16_T SL_s_CurrentPos_Old;         /* '<S16>/Stall' */
  uint8_T is_active_c2_DoorHndDriver;  /* '<S16>/Stall' */
  uint8_T is_Stall_Handler;            /* '<S16>/Stall' */
  uint8_T temporalCounter_i1;          /* '<S16>/Stall' */
} DW_Stall_DHM_T;

/* Block states (default storage) for system '<S3>/FLDoorHndReq' */
typedef struct {
  uint8_T is_active_c4_DoorHndReq;     /* '<S3>/FLDoorHndReq' */
  uint8_T is_Fold;                     /* '<S3>/FLDoorHndReq' */
  uint8_T is_Unfold;                   /* '<S3>/FLDoorHndReq' */
  uint8_T temporalCounter_i1;          /* '<S3>/FLDoorHndReq' */
  uint8_T temporalCounter_i2;          /* '<S3>/FLDoorHndReq' */
  boolean_T SL_b_UnfoldReqTrig;        /* '<S3>/FLDoorHndReq' */
  boolean_T SL_b_FoldReqTrig;          /* '<S3>/FLDoorHndReq' */
  boolean_T SI_b_CrashOutpSts_prev;    /* '<S3>/FLDoorHndReq' */
  boolean_T SI_b_CrashOutpSts_start;   /* '<S3>/FLDoorHndReq' */
} DW_FLDoorHndReq_DHM_T;

/* Block signals (default storage) */
typedef struct {
  int16_T SO_s_MaxSoftPos;             /* '<S21>/DoorHndPos' */
  int16_T SO_s_MinSoftPos;             /* '<S21>/DoorHndPos' */
  int16_T SO_s_IceBrkPos;              /* '<S21>/DoorHndPos' */
  int16_T SO_s_MaxSoftPos_p;           /* '<S16>/DoorHndPos' */
  int16_T SO_s_MinSoftPos_f;           /* '<S16>/DoorHndPos' */
  int16_T SO_s_IceBrkPos_e;            /* '<S16>/DoorHndPos' */
  uint8_T SO_e_MotorCmd;               /* '<S21>/MotorLogic' */
  uint8_T SO_e_LearnMotorCmd;          /* '<S21>/LearnLogic' */
  uint8_T SO_e_LearnMotorPwm;          /* '<S21>/LearnLogic' */
  uint8_T SO_e_MotorCmd_a;             /* '<S16>/MotorLogic' */
  uint8_T SO_e_LearnMotorCmd_j;        /* '<S16>/LearnLogic' */
  uint8_T SO_e_LearnMotorPwm_i;        /* '<S16>/LearnLogic' */
  boolean_T SO_b_HndUnfoldReq;         /* '<S3>/RRDoorHndReq' */
  boolean_T SO_b_HndFoldReq;           /* '<S3>/RRDoorHndReq' */
  boolean_T SO_b_HndUnfoldReq_a;       /* '<S3>/RLDoorHndReq' */
  boolean_T SO_b_HndFoldReq_a;         /* '<S3>/RLDoorHndReq' */
  boolean_T SO_b_HallStall;            /* '<S21>/Stall' */
  boolean_T SO_b_Learning;             /* '<S21>/LearnLogic' */
  boolean_T SO_b_HndUnfoldReq_k;       /* '<S3>/FRDoorHndReq' */
  boolean_T SO_b_HndFoldReq_d;         /* '<S3>/FRDoorHndReq' */
  boolean_T SO_b_HndUnfoldReq_j;       /* '<S3>/FLDoorHndReq' */
  boolean_T SO_b_HndFoldReq_dm;        /* '<S3>/FLDoorHndReq' */
  boolean_T SO_b_HallStall_d;          /* '<S16>/Stall' */
  boolean_T SO_b_Learning_e;           /* '<S16>/LearnLogic' */
  Learn_Sts_E SO_m_LearnSts;           /* '<S21>/LearnLogic' */
  Learn_Sts_E SO_m_LearnSts_g;         /* '<S16>/LearnLogic' */
} B_DHM_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  int16_T UnitDelay5_DSTATE;           /* '<S16>/Unit Delay5' */
  int16_T UnitDelay5_DSTATE_g;         /* '<S21>/Unit Delay5' */
  uint8_T UnitDelay1_DSTATE;           /* '<S16>/Unit Delay1' */
  uint8_T UnitDelay1_DSTATE_a;         /* '<S21>/Unit Delay1' */
  uint8_T is_active_c2_DHM;            /* '<S3>/LearnSts' */
  uint8_T is_active_c1_DHM;            /* '<S3>/HndReq' */
  DW_FLDoorHndReq_DHM_T sf_RRDoorHndReq;/* '<S3>/RRDoorHndReq' */
  DW_FLDoorHndReq_DHM_T sf_RLDoorHndReq;/* '<S3>/RLDoorHndReq' */
  DW_Stall_DHM_T sf_Stall_i;           /* '<S21>/Stall' */
  DW_MotorLogic_DHM_T sf_MotorLogic_o; /* '<S21>/MotorLogic' */
  DW_LearnLogic_DHM_T sf_LearnLogic_p; /* '<S21>/LearnLogic' */
  DW_DoorHndPos_DHM_T sf_DoorHndPos_a; /* '<S21>/DoorHndPos' */
  DW_CtrlLogic_DHM_T sf_CtrlLogic_e;   /* '<S21>/CtrlLogic' */
  DW_FLDoorHndReq_DHM_T sf_FRDoorHndReq;/* '<S3>/FRDoorHndReq' */
  DW_FLDoorHndReq_DHM_T sf_FLDoorHndReq;/* '<S3>/FLDoorHndReq' */
  DW_Stall_DHM_T sf_Stall;             /* '<S16>/Stall' */
  DW_MotorLogic_DHM_T sf_MotorLogic;   /* '<S16>/MotorLogic' */
  DW_LearnLogic_DHM_T sf_LearnLogic;   /* '<S16>/LearnLogic' */
  DW_DoorHndPos_DHM_T sf_DoorHndPos;   /* '<S16>/DoorHndPos' */
  DW_CtrlLogic_DHM_T sf_CtrlLogic;     /* '<S16>/CtrlLogic' */
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
 * '<S6>'   : 'DHM/DHM_Step_sys/DHM/Compare To Constant10'
 * '<S7>'   : 'DHM/DHM_Step_sys/DHM/Compare To Constant11'
 * '<S8>'   : 'DHM/DHM_Step_sys/DHM/Compare To Constant2'
 * '<S9>'   : 'DHM/DHM_Step_sys/DHM/Compare To Constant3'
 * '<S10>'  : 'DHM/DHM_Step_sys/DHM/Compare To Constant4'
 * '<S11>'  : 'DHM/DHM_Step_sys/DHM/Compare To Constant5'
 * '<S12>'  : 'DHM/DHM_Step_sys/DHM/Compare To Constant6'
 * '<S13>'  : 'DHM/DHM_Step_sys/DHM/Compare To Constant7'
 * '<S14>'  : 'DHM/DHM_Step_sys/DHM/Compare To Constant8'
 * '<S15>'  : 'DHM/DHM_Step_sys/DHM/Compare To Constant9'
 * '<S16>'  : 'DHM/DHM_Step_sys/DHM/FLDoorHndDriver'
 * '<S17>'  : 'DHM/DHM_Step_sys/DHM/FLDoorHndReq'
 * '<S18>'  : 'DHM/DHM_Step_sys/DHM/FRDoorHndReq'
 * '<S19>'  : 'DHM/DHM_Step_sys/DHM/HndReq'
 * '<S20>'  : 'DHM/DHM_Step_sys/DHM/LearnSts'
 * '<S21>'  : 'DHM/DHM_Step_sys/DHM/RLDoorHndDriver'
 * '<S22>'  : 'DHM/DHM_Step_sys/DHM/RLDoorHndReq'
 * '<S23>'  : 'DHM/DHM_Step_sys/DHM/RRDoorHndReq'
 * '<S24>'  : 'DHM/DHM_Step_sys/DHM/Recycle Bin'
 * '<S25>'  : 'DHM/DHM_Step_sys/DHM/FLDoorHndDriver/CtrlLogic'
 * '<S26>'  : 'DHM/DHM_Step_sys/DHM/FLDoorHndDriver/DoorHndPos'
 * '<S27>'  : 'DHM/DHM_Step_sys/DHM/FLDoorHndDriver/LearnLogic'
 * '<S28>'  : 'DHM/DHM_Step_sys/DHM/FLDoorHndDriver/MotorLogic'
 * '<S29>'  : 'DHM/DHM_Step_sys/DHM/FLDoorHndDriver/Stall'
 * '<S30>'  : 'DHM/DHM_Step_sys/DHM/RLDoorHndDriver/CtrlLogic'
 * '<S31>'  : 'DHM/DHM_Step_sys/DHM/RLDoorHndDriver/DoorHndPos'
 * '<S32>'  : 'DHM/DHM_Step_sys/DHM/RLDoorHndDriver/LearnLogic'
 * '<S33>'  : 'DHM/DHM_Step_sys/DHM/RLDoorHndDriver/MotorLogic'
 * '<S34>'  : 'DHM/DHM_Step_sys/DHM/RLDoorHndDriver/Stall'
 */
#endif                                 /* RTW_HEADER_DHM_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
