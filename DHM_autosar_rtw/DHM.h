/*
 * File: DHM.h
 *
 * Code generated for Simulink model 'DHM'.
 *
 * Model version                  : 1.362
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Thu Oct 12 20:04:30 2023
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

/* Block states (default storage) for system '<S12>/CtrlLogic' */
typedef struct {
  uint8 is_active_c1_DoorHndDriver;    /* '<S12>/CtrlLogic' */
  uint8 is_Ctrl;                       /* '<S12>/CtrlLogic' */
  uint8 is_Unfold;                     /* '<S12>/CtrlLogic' */
  uint8 is_Icebreak;                   /* '<S12>/CtrlLogic' */
  uint8 is_Fold;                       /* '<S12>/CtrlLogic' */
  uint8 SL_e_CycleCount;               /* '<S12>/CtrlLogic' */
  uint8 SL_e_IceBrkCount;              /* '<S12>/CtrlLogic' */
  uint8 temporalCounter_i1;            /* '<S12>/CtrlLogic' */
  boolean SI_b_DoorHndUnfoldReq_prev;  /* '<S12>/CtrlLogic' */
  boolean SI_b_DoorHndUnfoldReq_start; /* '<S12>/CtrlLogic' */
  boolean SI_b_DoorHndFoldReq_prev;    /* '<S12>/CtrlLogic' */
  boolean SI_b_DoorHndFoldReq_start;   /* '<S12>/CtrlLogic' */
} DW_CtrlLogic_DHM_T;

/* Block states (default storage) for system '<S12>/DoorHndPos' */
typedef struct {
  uint8 is_active_c5_DoorHndDriver;    /* '<S12>/DoorHndPos' */
} DW_DoorHndPos_DHM_T;

/* Block states (default storage) for system '<S12>/LearnLogic' */
typedef struct {
  uint16 temporalCounter_i1;           /* '<S12>/LearnLogic' */
  uint8 is_active_c3_DoorHndDriver;    /* '<S12>/LearnLogic' */
  uint8 is_c3_DoorHndDriver;           /* '<S12>/LearnLogic' */
  uint8 is_LearnLogic;                 /* '<S12>/LearnLogic' */
  uint8 SL_e_AutoLearnCount;           /* '<S12>/LearnLogic' */
  uint8 SL_e_tempPos;                  /* '<S12>/LearnLogic' */
  boolean SI_b_LearnReq_prev;          /* '<S12>/LearnLogic' */
  boolean SI_b_LearnReq_start;         /* '<S12>/LearnLogic' */
} DW_LearnLogic_DHM_T;

/* Block states (default storage) for system '<S12>/MotorLogic' */
typedef struct {
  uint8 is_active_c4_DoorHndDriver;    /* '<S12>/MotorLogic' */
} DW_MotorLogic_DHM_T;

/* Block states (default storage) for system '<S12>/Stall' */
typedef struct {
  sint16 SL_s_CurrentPos_Old;          /* '<S12>/Stall' */
  uint8 is_active_c2_DoorHndDriver;    /* '<S12>/Stall' */
  uint8 is_Stall_Handler;              /* '<S12>/Stall' */
  uint8 temporalCounter_i1;            /* '<S12>/Stall' */
} DW_Stall_DHM_T;

/* Block states (default storage) for system '<S3>/FLDoorHndReq' */
typedef struct {
  uint8 is_active_c4_DoorHndReq;       /* '<S3>/FLDoorHndReq' */
  uint8 is_Fold;                       /* '<S3>/FLDoorHndReq' */
  uint8 is_Unfold;                     /* '<S3>/FLDoorHndReq' */
  uint8 temporalCounter_i1;            /* '<S3>/FLDoorHndReq' */
  uint8 temporalCounter_i2;            /* '<S3>/FLDoorHndReq' */
  boolean SL_b_UnfoldReqTrig;          /* '<S3>/FLDoorHndReq' */
  boolean SI_b_CrashOutpSts_prev;      /* '<S3>/FLDoorHndReq' */
  boolean SI_b_CrashOutpSts_start;     /* '<S3>/FLDoorHndReq' */
} DW_FLDoorHndReq_DHM_T;

/* Block signals (default storage) */
typedef struct tag_B_DHM_T {
  SInt16 TmpSignalConversionAtVsINP_HWA_;
  SInt16 TmpSignalConversionAtVsINP_HW_a;
  sint16 SO_s_MaxPos;                  /* '<S17>/LearnLogic' */
  sint16 SO_s_MaxSoftPos;              /* '<S17>/DoorHndPos' */
  sint16 SO_s_MinSoftPos;              /* '<S17>/DoorHndPos' */
  sint16 SO_s_IceBrkPos;               /* '<S17>/DoorHndPos' */
  sint16 SO_s_MaxPos_i;                /* '<S12>/LearnLogic' */
  sint16 SO_s_MaxSoftPos_k;            /* '<S12>/DoorHndPos' */
  sint16 SO_s_MinSoftPos_n;            /* '<S12>/DoorHndPos' */
  sint16 SO_s_IceBrkPos_k;             /* '<S12>/DoorHndPos' */
  uint8 SO_e_MotorCmd;                 /* '<S17>/MotorLogic' */
  uint8 SO_e_LearnMotorCmd;            /* '<S17>/LearnLogic' */
  uint8 SO_e_LearnMotorPwm;            /* '<S17>/LearnLogic' */
  uint8 SO_e_MotorCmd_f;               /* '<S17>/CtrlLogic' */
  uint8 SO_e_MotorPwm_g;               /* '<S17>/CtrlLogic' */
  uint8 SO_e_LearnSts;                 /* '<S3>/LearnSts' */
  uint8 SO_e_FRHndReq;                 /* '<S3>/HndReq' */
  uint8 SO_e_RRHndReq;                 /* '<S3>/HndReq' */
  uint8 SO_e_MotorCmd_c;               /* '<S12>/MotorLogic' */
  uint8 SO_e_LearnMotorCmd_f;          /* '<S12>/LearnLogic' */
  uint8 SO_e_LearnMotorPwm_p;          /* '<S12>/LearnLogic' */
  uint8 SO_e_MotorCmd_g;               /* '<S12>/CtrlLogic' */
  uint8 SO_e_MotorPwm_e;               /* '<S12>/CtrlLogic' */
  Boolean VbINP_HWA_DoorHandleLrnReq_flg_;
  /* '<S2>/VbINP_HWA_DoorHandleLrnReq_flg_VbINP_HWA_DoorHandleLrnReq_flg_read' */
  boolean SO_b_HndUnfoldReq;           /* '<S3>/RRDoorHndReq' */
  boolean SO_b_HndFoldReq;             /* '<S3>/RRDoorHndReq' */
  boolean SO_b_HndUnfoldReq_a;         /* '<S3>/RLDoorHndReq' */
  boolean SO_b_HndFoldReq_a;           /* '<S3>/RLDoorHndReq' */
  boolean SO_b_HallStall;              /* '<S17>/Stall' */
  boolean SO_b_MotorA;                 /* '<S17>/MotorLogic' */
  boolean SO_b_MotorB;                 /* '<S17>/MotorLogic' */
  boolean SO_b_Learning;               /* '<S17>/LearnLogic' */
  boolean SO_b_HndUnfoldReq_k;         /* '<S3>/FRDoorHndReq' */
  boolean SO_b_HndFoldReq_d;           /* '<S3>/FRDoorHndReq' */
  boolean SO_b_HndUnfoldReq_j;         /* '<S3>/FLDoorHndReq' */
  boolean SO_b_HndFoldReq_dm;          /* '<S3>/FLDoorHndReq' */
  boolean SO_b_HallStall_m;            /* '<S12>/Stall' */
  boolean SO_b_MotorA_k;               /* '<S12>/MotorLogic' */
  boolean SO_b_MotorB_e;               /* '<S12>/MotorLogic' */
  boolean SO_b_Learning_j;             /* '<S12>/LearnLogic' */
  Learn_Sts_E SO_m_LearnSts;           /* '<S17>/LearnLogic' */
  Learn_Sts_E SO_m_LearnSts_e;         /* '<S12>/LearnLogic' */
} B_DHM_T;

/* Block states (default storage) for system '<Root>' */
typedef struct tag_DW_DHM_T {
  sint16 UnitDelay5_DSTATE;            /* '<S12>/Unit Delay5' */
  sint16 UnitDelay5_DSTATE_h;          /* '<S17>/Unit Delay5' */
  uint8 UnitDelay1_DSTATE;             /* '<S12>/Unit Delay1' */
  uint8 UnitDelay1_DSTATE_f;           /* '<S17>/Unit Delay1' */
  uint8 E03_DHM_L;                     /* '<S3>/Data Store Memory' */
  uint8 is_active_c2_DHM;              /* '<S3>/LearnSts' */
  uint8 is_active_c1_DHM;              /* '<S3>/HndReq' */
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
  DW_Stall_DHM_T sf_Stall_m;           /* '<S17>/Stall' */
  DW_MotorLogic_DHM_T sf_MotorLogic_l; /* '<S17>/MotorLogic' */
  DW_LearnLogic_DHM_T sf_LearnLogic_d; /* '<S17>/LearnLogic' */
  DW_DoorHndPos_DHM_T sf_DoorHndPos_m; /* '<S17>/DoorHndPos' */
  DW_CtrlLogic_DHM_T sf_CtrlLogic_g;   /* '<S17>/CtrlLogic' */
  DW_FLDoorHndReq_DHM_T sf_FRDoorHndReq;/* '<S3>/FRDoorHndReq' */
  DW_FLDoorHndReq_DHM_T sf_FLDoorHndReq;/* '<S3>/FLDoorHndReq' */
  DW_Stall_DHM_T sf_Stall;             /* '<S12>/Stall' */
  DW_MotorLogic_DHM_T sf_MotorLogic;   /* '<S12>/MotorLogic' */
  DW_LearnLogic_DHM_T sf_LearnLogic;   /* '<S12>/LearnLogic' */
  DW_DoorHndPos_DHM_T sf_DoorHndPos;   /* '<S12>/DoorHndPos' */
  DW_CtrlLogic_DHM_T sf_CtrlLogic;     /* '<S12>/CtrlLogic' */
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
 * '<S4>'   : 'DHM/DHM_Step_sys/DHM/Compare To Constant1'
 * '<S5>'   : 'DHM/DHM_Step_sys/DHM/Compare To Constant2'
 * '<S6>'   : 'DHM/DHM_Step_sys/DHM/Compare To Constant3'
 * '<S7>'   : 'DHM/DHM_Step_sys/DHM/Compare To Constant4'
 * '<S8>'   : 'DHM/DHM_Step_sys/DHM/Compare To Constant5'
 * '<S9>'   : 'DHM/DHM_Step_sys/DHM/Compare To Constant6'
 * '<S10>'  : 'DHM/DHM_Step_sys/DHM/Compare To Constant7'
 * '<S11>'  : 'DHM/DHM_Step_sys/DHM/Compare To Constant8'
 * '<S12>'  : 'DHM/DHM_Step_sys/DHM/FLDoorHndDriver'
 * '<S13>'  : 'DHM/DHM_Step_sys/DHM/FLDoorHndReq'
 * '<S14>'  : 'DHM/DHM_Step_sys/DHM/FRDoorHndReq'
 * '<S15>'  : 'DHM/DHM_Step_sys/DHM/HndReq'
 * '<S16>'  : 'DHM/DHM_Step_sys/DHM/LearnSts'
 * '<S17>'  : 'DHM/DHM_Step_sys/DHM/RLDoorHndDriver'
 * '<S18>'  : 'DHM/DHM_Step_sys/DHM/RLDoorHndReq'
 * '<S19>'  : 'DHM/DHM_Step_sys/DHM/RRDoorHndReq'
 * '<S20>'  : 'DHM/DHM_Step_sys/DHM/Recycle Bin'
 * '<S21>'  : 'DHM/DHM_Step_sys/DHM/FLDoorHndDriver/CtrlLogic'
 * '<S22>'  : 'DHM/DHM_Step_sys/DHM/FLDoorHndDriver/DoorHndPos'
 * '<S23>'  : 'DHM/DHM_Step_sys/DHM/FLDoorHndDriver/LearnLogic'
 * '<S24>'  : 'DHM/DHM_Step_sys/DHM/FLDoorHndDriver/MotorLogic'
 * '<S25>'  : 'DHM/DHM_Step_sys/DHM/FLDoorHndDriver/Stall'
 * '<S26>'  : 'DHM/DHM_Step_sys/DHM/RLDoorHndDriver/CtrlLogic'
 * '<S27>'  : 'DHM/DHM_Step_sys/DHM/RLDoorHndDriver/DoorHndPos'
 * '<S28>'  : 'DHM/DHM_Step_sys/DHM/RLDoorHndDriver/LearnLogic'
 * '<S29>'  : 'DHM/DHM_Step_sys/DHM/RLDoorHndDriver/MotorLogic'
 * '<S30>'  : 'DHM/DHM_Step_sys/DHM/RLDoorHndDriver/Stall'
 */
#endif                                 /* RTW_HEADER_DHM_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
