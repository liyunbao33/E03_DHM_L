/*
 * File: DHM.h
 *
 * Code generated for Simulink model 'DHM'.
 *
 * Model version                  : 1.306
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Sat Oct  7 08:45:57 2023
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

/* Block states (default storage) for system '<S8>/CtrlLogic' */
typedef struct {
  uint8 is_active_c1_DoorHndDriver;    /* '<S8>/CtrlLogic' */
  uint8 is_Ctrl;                       /* '<S8>/CtrlLogic' */
  uint8 is_Unfold;                     /* '<S8>/CtrlLogic' */
  uint8 is_Icebreak;                   /* '<S8>/CtrlLogic' */
  uint8 is_Fold;                       /* '<S8>/CtrlLogic' */
  uint8 temporalCounter_i1;            /* '<S8>/CtrlLogic' */
  boolean SI_b_DoorHndUnfoldReq_prev;  /* '<S8>/CtrlLogic' */
  boolean SI_b_DoorHndUnfoldReq_start; /* '<S8>/CtrlLogic' */
  boolean SI_b_DoorHndFoldReq_prev;    /* '<S8>/CtrlLogic' */
  boolean SI_b_DoorHndFoldReq_start;   /* '<S8>/CtrlLogic' */
} DW_CtrlLogic_DHM_T;

/* Block states (default storage) for system '<S8>/DoorHndPos' */
typedef struct {
  uint8 is_active_c5_DoorHndDriver;    /* '<S8>/DoorHndPos' */
} DW_DoorHndPos_DHM_T;

/* Block states (default storage) for system '<S8>/LearnLogic' */
typedef struct {
  uint8 is_active_c3_DoorHndDriver;    /* '<S8>/LearnLogic' */
  uint8 is_c3_DoorHndDriver;           /* '<S8>/LearnLogic' */
  uint8 is_LearnLogic;                 /* '<S8>/LearnLogic' */
  uint8 SI_e_AutoLearnCount;           /* '<S8>/LearnLogic' */
  uint8 temporalCounter_i1;            /* '<S8>/LearnLogic' */
  boolean SI_b_LearnReq_prev;          /* '<S8>/LearnLogic' */
  boolean SI_b_LearnReq_start;         /* '<S8>/LearnLogic' */
} DW_LearnLogic_DHM_T;

/* Block states (default storage) for system '<S8>/MotorLogic' */
typedef struct {
  uint8 is_active_c4_DoorHndDriver;    /* '<S8>/MotorLogic' */
} DW_MotorLogic_DHM_T;

/* Block states (default storage) for system '<S8>/Stall' */
typedef struct {
  sint16 SL_s_CurrentPos_Old;          /* '<S8>/Stall' */
  uint8 is_active_c2_DoorHndDriver;    /* '<S8>/Stall' */
  uint8 is_Stall_Handler;              /* '<S8>/Stall' */
  uint8 temporalCounter_i1;            /* '<S8>/Stall' */
} DW_Stall_DHM_T;

/* Block states (default storage) for system '<S3>/FLDoorHndReq' */
typedef struct {
  uint8 is_active_c4_DoorHndReq;       /* '<S3>/FLDoorHndReq' */
  uint8 is_Unfold;                     /* '<S3>/FLDoorHndReq' */
  uint8 is_Fold;                       /* '<S3>/FLDoorHndReq' */
  uint8 temporalCounter_i1;            /* '<S3>/FLDoorHndReq' */
  uint8 temporalCounter_i2;            /* '<S3>/FLDoorHndReq' */
  boolean SI_b_CrashOutpSts_prev;      /* '<S3>/FLDoorHndReq' */
  boolean SI_b_CrashOutpSts_start;     /* '<S3>/FLDoorHndReq' */
} DW_FLDoorHndReq_DHM_T;

/* Block signals (default storage) */
typedef struct tag_B_DHM_T {
  SInt16 TmpSignalConversionAtVsINP_HWA_;
  SInt16 TmpSignalConversionAtVsINP_HW_a;
  sint16 SO_s_MaxPos;                  /* '<S11>/LearnLogic' */
  sint16 SO_s_MaxSoftPos;              /* '<S11>/DoorHndPos' */
  sint16 SO_s_MinSoftPos;              /* '<S11>/DoorHndPos' */
  sint16 SO_s_IceBrkPos;               /* '<S11>/DoorHndPos' */
  sint16 SO_s_MaxPos_n;                /* '<S8>/LearnLogic' */
  sint16 SO_s_MaxSoftPos_k;            /* '<S8>/DoorHndPos' */
  sint16 SO_s_MinSoftPos_n;            /* '<S8>/DoorHndPos' */
  sint16 SO_s_IceBrkPos_k;             /* '<S8>/DoorHndPos' */
  uint8 SO_e_MotorCmd;                 /* '<S11>/MotorLogic' */
  uint8 SO_e_MotorCmd_a;               /* '<S11>/LearnLogic' */
  uint8 SO_e_MotorPwm_e;               /* '<S11>/LearnLogic' */
  uint8 SO_e_MotorCmd_f;               /* '<S11>/CtrlLogic' */
  uint8 SO_e_MotorPwm_g;               /* '<S11>/CtrlLogic' */
  uint8 SO_e_MotorCmd_c;               /* '<S8>/MotorLogic' */
  uint8 SO_e_MotorCmd_j;               /* '<S8>/LearnLogic' */
  uint8 SO_e_MotorPwm_m;               /* '<S8>/LearnLogic' */
  uint8 SO_e_MotorCmd_g;               /* '<S8>/CtrlLogic' */
  uint8 SO_e_MotorPwm_ew;              /* '<S8>/CtrlLogic' */
  Boolean VbINP_HWA_DoorHandleLrnReq_flg_;
  /* '<S2>/VbINP_HWA_DoorHandleLrnReq_flg_VbINP_HWA_DoorHandleLrnReq_flg_read' */
  boolean SO_b_HndUnfoldReq;           /* '<S3>/RRDoorHndReq' */
  boolean SO_b_HndFoldReq;             /* '<S3>/RRDoorHndReq' */
  boolean SO_b_HndUnfoldReq_a;         /* '<S3>/RLDoorHndReq' */
  boolean SO_b_HndFoldReq_a;           /* '<S3>/RLDoorHndReq' */
  boolean SO_b_HallStall;              /* '<S11>/Stall' */
  boolean SO_b_MotorA;                 /* '<S11>/MotorLogic' */
  boolean SO_b_MotorB;                 /* '<S11>/MotorLogic' */
  boolean SO_b_HndUnfoldReq_k;         /* '<S3>/FRDoorHndReq' */
  boolean SO_b_HndFoldReq_d;           /* '<S3>/FRDoorHndReq' */
  boolean SO_b_HndUnfoldReq_j;         /* '<S3>/FLDoorHndReq' */
  boolean SO_b_HndFoldReq_dm;          /* '<S3>/FLDoorHndReq' */
  boolean SO_b_HallStall_m;            /* '<S8>/Stall' */
  boolean SO_b_MotorA_k;               /* '<S8>/MotorLogic' */
  boolean SO_b_MotorB_e;               /* '<S8>/MotorLogic' */
  Learn_Sts_E SO_m_LearnSts;           /* '<S11>/LearnLogic' */
  Learn_Sts_E SO_m_LearnSts_b;         /* '<S8>/LearnLogic' */
} B_DHM_T;

/* Block states (default storage) for system '<Root>' */
typedef struct tag_DW_DHM_T {
  sint16 UnitDelay5_DSTATE;            /* '<S8>/Unit Delay5' */
  sint16 UnitDelay5_DSTATE_h;          /* '<S11>/Unit Delay5' */
  uint8 UnitDelay1_DSTATE;             /* '<S8>/Unit Delay1' */
  uint8 UnitDelay1_DSTATE_f;           /* '<S11>/Unit Delay1' */
  boolean UnitDelay4_DSTATE;           /* '<S8>/Unit Delay4' */
  boolean UnitDelay4_DSTATE_n;         /* '<S11>/Unit Delay4' */
  uint8 E03_DHM_L;                     /* '<S3>/Data Store Memory' */
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
