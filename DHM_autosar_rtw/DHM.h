/*
 * File: DHM.h
 *
 * Code generated for Simulink model 'DHM'.
 *
 * Model version                  : 1.426
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Thu Oct 19 15:51:49 2023
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_DHM_h_
#define RTW_HEADER_DHM_h_
#ifndef DHM_COMMON_INCLUDES_
#define DHM_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Rte_DHM.h"
#endif                                 /* DHM_COMMON_INCLUDES_ */

#include "DHM_types.h"
#include "Rte_Type.h"

/* Block states (default storage) for system '<S16>/CtrlLogic' */
typedef struct {
  uint8 is_active_c1_DoorHndDriver;    /* '<S16>/CtrlLogic' */
  uint8 is_Ctrl;                       /* '<S16>/CtrlLogic' */
  uint8 is_Unfold;                     /* '<S16>/CtrlLogic' */
  uint8 is_Icebreak;                   /* '<S16>/CtrlLogic' */
  uint8 is_Fold;                       /* '<S16>/CtrlLogic' */
  uint8 SL_e_CycleCount;               /* '<S16>/CtrlLogic' */
  uint8 SL_e_IceBrkCount;              /* '<S16>/CtrlLogic' */
  uint8 temporalCounter_i1;            /* '<S16>/CtrlLogic' */
  boolean SI_b_DoorHndUnfoldReq_prev;  /* '<S16>/CtrlLogic' */
  boolean SI_b_DoorHndUnfoldReq_start; /* '<S16>/CtrlLogic' */
  boolean SI_b_DoorHndFoldReq_prev;    /* '<S16>/CtrlLogic' */
  boolean SI_b_DoorHndFoldReq_start;   /* '<S16>/CtrlLogic' */
} DW_CtrlLogic_DHM_T;

/* Block states (default storage) for system '<S16>/DoorHndPos' */
typedef struct {
  uint8 is_active_c5_DoorHndDriver;    /* '<S16>/DoorHndPos' */
} DW_DoorHndPos_DHM_T;

/* Block states (default storage) for system '<S16>/LearnLogic' */
typedef struct {
  uint16 temporalCounter_i1;           /* '<S16>/LearnLogic' */
  uint8 is_active_c3_DoorHndDriver;    /* '<S16>/LearnLogic' */
  uint8 is_c3_DoorHndDriver;           /* '<S16>/LearnLogic' */
  uint8 is_LearnLogic;                 /* '<S16>/LearnLogic' */
  uint8 SL_e_AutoLearnCount;           /* '<S16>/LearnLogic' */
  uint8 SL_e_tempPos;                  /* '<S16>/LearnLogic' */
  boolean SI_b_LearnReq_prev;          /* '<S16>/LearnLogic' */
  boolean SI_b_LearnReq_start;         /* '<S16>/LearnLogic' */
} DW_LearnLogic_DHM_T;

/* Block states (default storage) for system '<S16>/MotorLogic' */
typedef struct {
  uint8 is_active_c4_DoorHndDriver;    /* '<S16>/MotorLogic' */
} DW_MotorLogic_DHM_T;

/* Block states (default storage) for system '<S16>/Stall' */
typedef struct {
  sint16 SL_s_CurrentPos_Old;          /* '<S16>/Stall' */
  uint8 is_active_c2_DoorHndDriver;    /* '<S16>/Stall' */
  uint8 is_Stall_Handler;              /* '<S16>/Stall' */
  uint8 temporalCounter_i1;            /* '<S16>/Stall' */
} DW_Stall_DHM_T;

/* Block states (default storage) for system '<S3>/FLDoorHndReq' */
typedef struct {
  uint8 is_active_c4_DoorHndReq;       /* '<S3>/FLDoorHndReq' */
  uint8 is_c4_DoorHndReq;              /* '<S3>/FLDoorHndReq' */
  uint8 is_Fold;                       /* '<S3>/FLDoorHndReq' */
  uint8 is_Unfold;                     /* '<S3>/FLDoorHndReq' */
  uint8 temporalCounter_i1;            /* '<S3>/FLDoorHndReq' */
  uint8 temporalCounter_i2;            /* '<S3>/FLDoorHndReq' */
  boolean SL_b_UnfoldReqTrig;          /* '<S3>/FLDoorHndReq' */
  boolean SL_b_FoldReqTrig;            /* '<S3>/FLDoorHndReq' */
  boolean SI_b_CrashOutpSts_prev;      /* '<S3>/FLDoorHndReq' */
  boolean SI_b_CrashOutpSts_start;     /* '<S3>/FLDoorHndReq' */
} DW_FLDoorHndReq_DHM_T;

/* Block signals (default storage) */
typedef struct tag_B_DHM_T {
  SInt16 TmpSignalConversionAtVsINP_HWA_;
  SInt16 TmpSignalConversionAtVsINP_HW_a;
  sint16 SO_s_MaxPos;                  /* '<S21>/LearnLogic' */
  sint16 SO_s_MaxSoftPos;              /* '<S21>/DoorHndPos' */
  sint16 SO_s_MinSoftPos;              /* '<S21>/DoorHndPos' */
  sint16 SO_s_IceBrkPos;               /* '<S21>/DoorHndPos' */
  sint16 SO_s_MaxPos_i;                /* '<S16>/LearnLogic' */
  sint16 SO_s_MaxSoftPos_p;            /* '<S16>/DoorHndPos' */
  sint16 SO_s_MinSoftPos_f;            /* '<S16>/DoorHndPos' */
  sint16 SO_s_IceBrkPos_e;             /* '<S16>/DoorHndPos' */
  uint8 SO_e_LearnMotorCmd;            /* '<S21>/LearnLogic' */
  uint8 SO_e_LearnMotorPwm;            /* '<S21>/LearnLogic' */
  uint8 SO_e_MotorCmd;                 /* '<S21>/CtrlLogic' */
  uint8 SO_e_MotorPwm;                 /* '<S21>/CtrlLogic' */
  uint8 SO_e_LearnMotorCmd_j;          /* '<S16>/LearnLogic' */
  uint8 SO_e_LearnMotorPwm_i;          /* '<S16>/LearnLogic' */
  uint8 SO_e_MotorCmd_e;               /* '<S16>/CtrlLogic' */
  uint8 SO_e_MotorPwm_d;               /* '<S16>/CtrlLogic' */
  Boolean VbINP_HWA_DoorHandleLrnReq_flg_;
  /* '<S2>/VbINP_HWA_DoorHandleLrnReq_flg_VbINP_HWA_DoorHandleLrnReq_flg_read' */
  boolean SO_b_HndUnfoldReq;           /* '<S3>/RRDoorHndReq' */
  boolean SO_b_HndFoldReq;             /* '<S3>/RRDoorHndReq' */
  boolean SO_b_HndUnfoldReq_a;         /* '<S3>/RLDoorHndReq' */
  boolean SO_b_HndFoldReq_a;           /* '<S3>/RLDoorHndReq' */
  boolean SO_b_HallStall;              /* '<S21>/Stall' */
  boolean SO_b_Learning;               /* '<S21>/LearnLogic' */
  boolean SO_b_HndUnfoldReq_k;         /* '<S3>/FRDoorHndReq' */
  boolean SO_b_HndFoldReq_d;           /* '<S3>/FRDoorHndReq' */
  boolean SO_b_HndUnfoldReq_j;         /* '<S3>/FLDoorHndReq' */
  boolean SO_b_HndFoldReq_dm;          /* '<S3>/FLDoorHndReq' */
  boolean SO_b_HallStall_d;            /* '<S16>/Stall' */
  boolean SO_b_Learning_e;             /* '<S16>/LearnLogic' */
  Learn_Sts_E SO_m_LearnSts;           /* '<S21>/LearnLogic' */
  Learn_Sts_E SO_m_LearnSts_g;         /* '<S16>/LearnLogic' */
} B_DHM_T;

/* Block states (default storage) for system '<Root>' */
typedef struct tag_DW_DHM_T {
  sint16 UnitDelay5_DSTATE;            /* '<S16>/Unit Delay5' */
  sint16 UnitDelay5_DSTATE_g;          /* '<S21>/Unit Delay5' */
  uint8 UnitDelay1_DSTATE;             /* '<S16>/Unit Delay1' */
  uint8 UnitDelay1_DSTATE_a;           /* '<S21>/Unit Delay1' */
  uint8 E03_DHM_L;                     /* '<S3>/Data Store Memory' */
  uint8 is_active_c2_DHM;              /* '<S3>/LearnSts' */
  uint8 is_active_c1_DHM;              /* '<S3>/HndReq' */
  uint8 is_FRHndReq;                   /* '<S3>/HndReq' */
  uint8 is_RRHndReq;                   /* '<S3>/HndReq' */
  boolean SI_b_FRHndFoldReq_prev;      /* '<S3>/HndReq' */
  boolean SI_b_FRHndFoldReq_start;     /* '<S3>/HndReq' */
  boolean SI_b_FRHndUnfoldReq_prev;    /* '<S3>/HndReq' */
  boolean SI_b_FRHndUnfoldReq_start;   /* '<S3>/HndReq' */
  boolean SI_b_RRHndFoldReq_prev;      /* '<S3>/HndReq' */
  boolean SI_b_RRHndFoldReq_start;     /* '<S3>/HndReq' */
  boolean SI_b_RRHndUnfoldReq_prev;    /* '<S3>/HndReq' */
  boolean SI_b_RRHndUnfoldReq_start;   /* '<S3>/HndReq' */
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

/* Block signals (default storage) */
extern B_DHM_T DHM_B;

/* Block states (default storage) */
extern DW_DHM_T DHM_DW;

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
