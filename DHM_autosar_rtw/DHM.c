/*
 * File: DHM.c
 *
 * Code generated for Simulink model 'DHM'.
 *
 * Model version                  : 1.428
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Tue Oct 24 17:21:21 2023
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "DHM.h"
#include "rtwtypes.h"
#include "DHM_types.h"
#include "Rte_Type.h"
#include "DHM_private.h"

/* Named constants for Chart: '<S16>/CtrlLogic' */
#define DHM_IN_Fold                    ((uint8)1U)
#define DHM_IN_Idle                    ((uint8)2U)
#define DHM_IN_Interrupt1              ((uint8)3U)
#define DHM_IN_Interrupt2              ((uint8)4U)
#define DHM_IN_NO_ACTIVE_CHILD         ((uint8)0U)
#define DHM_IN_Start                   ((uint8)1U)
#define DHM_IN_Stop                    ((uint8)2U)
#define DHM_IN_Unfold                  ((uint8)5U)

/* Named constants for Chart: '<S3>/FLDoorHndReq' */
#define DHM_IN_CrashUnfoldReq          ((uint8)1U)
#define DHM_IN_FoldReq                 ((uint8)1U)
#define DHM_IN_Func                    ((uint8)1U)
#define DHM_IN_Idle_a                  ((uint8)2U)
#define DHM_IN_NormalUnfoldReq         ((uint8)3U)
#define DHM_IN_PowerOnDelay            ((uint8)2U)

/* Named constants for Chart: '<S3>/HndReq' */
#define DHM_IN_FoldReq_e               ((uint8)1U)
#define DHM_IN_Idle_p                  ((uint8)2U)
#define DHM_IN_UnfoldReq               ((uint8)3U)

/* Block signals (default storage) */
B_DHM_T DHM_B;

/* Block states (default storage) */
DW_DHM_T DHM_DW;

/*
 * System initialize for atomic system:
 *    '<S16>/CtrlLogic'
 *    '<S21>/CtrlLogic'
 */
void DHM_CtrlLogic_Init(uint8 *rty_SO_e_MotorCmd, uint8 *rty_SO_e_MotorPwm,
  boolean *rty_SO_b_Error)
{
  *rty_SO_e_MotorCmd = 0U;
  *rty_SO_e_MotorPwm = 0U;
  *rty_SO_b_Error = false;
}

/*
 * Output and update for atomic system:
 *    '<S16>/CtrlLogic'
 *    '<S21>/CtrlLogic'
 */
void DHM_CtrlLogic(boolean rtu_SI_b_DoorHndFoldReq, boolean
                   rtu_SI_b_DoorHndUnfoldReq, uint8 *rty_SO_e_MotorCmd, uint8
                   *rty_SO_e_MotorPwm, boolean *rty_SO_b_Error,
                   DW_CtrlLogic_DHM_T *localDW)
{
  if (localDW->temporalCounter_i1 < 255U) {
    localDW->temporalCounter_i1++;
  }

  localDW->SI_b_DoorHndUnfoldReq_prev = localDW->SI_b_DoorHndUnfoldReq_start;
  localDW->SI_b_DoorHndUnfoldReq_start = rtu_SI_b_DoorHndUnfoldReq;
  localDW->SI_b_DoorHndFoldReq_prev = localDW->SI_b_DoorHndFoldReq_start;
  localDW->SI_b_DoorHndFoldReq_start = rtu_SI_b_DoorHndFoldReq;

  /* Chart: '<S16>/CtrlLogic' */
  if (localDW->is_active_c1_DoorHndDriver == 0U) {
    localDW->SI_b_DoorHndUnfoldReq_prev = rtu_SI_b_DoorHndUnfoldReq;
    localDW->SI_b_DoorHndFoldReq_prev = rtu_SI_b_DoorHndFoldReq;
    localDW->is_active_c1_DoorHndDriver = 1U;
    localDW->is_Ctrl = DHM_IN_Idle;
    *rty_SO_e_MotorCmd = 0U;
    *rty_SO_e_MotorPwm = 0U;
  } else {
    switch (localDW->is_Ctrl) {
     case DHM_IN_Fold:
      if ((localDW->SI_b_DoorHndUnfoldReq_prev !=
           localDW->SI_b_DoorHndUnfoldReq_start) &&
          localDW->SI_b_DoorHndUnfoldReq_start) {
        localDW->is_Fold = DHM_IN_NO_ACTIVE_CHILD;
        localDW->is_Ctrl = DHM_IN_Interrupt2;
        localDW->temporalCounter_i1 = 0U;

        /*  展开打断折叠  */
        *rty_SO_e_MotorCmd = 0U;
        *rty_SO_e_MotorPwm = 0U;
      } else if (localDW->is_Fold == DHM_IN_Start) {
        *rty_SO_e_MotorCmd = 2U;
        *rty_SO_e_MotorPwm = 100U;
        if (localDW->temporalCounter_i1 >= 240) {
          localDW->is_Fold = DHM_IN_Stop;
          *rty_SO_e_MotorCmd = 0U;
          *rty_SO_e_MotorPwm = 0U;
          *rty_SO_b_Error = false;
        }
      } else {
        /* case IN_Stop: */
        localDW->is_Fold = DHM_IN_NO_ACTIVE_CHILD;
        localDW->is_Ctrl = DHM_IN_Idle;
        *rty_SO_e_MotorCmd = 0U;
        *rty_SO_e_MotorPwm = 0U;
      }
      break;

     case DHM_IN_Idle:
      *rty_SO_e_MotorCmd = 0U;
      *rty_SO_e_MotorPwm = 0U;
      if ((localDW->SI_b_DoorHndFoldReq_prev !=
           localDW->SI_b_DoorHndFoldReq_start) &&
          localDW->SI_b_DoorHndFoldReq_start) {
        localDW->is_Ctrl = DHM_IN_Fold;

        /*  未学习  */
        localDW->is_Fold = DHM_IN_Start;
        localDW->temporalCounter_i1 = 0U;
        *rty_SO_e_MotorCmd = 2U;
        *rty_SO_e_MotorPwm = 100U;
      } else if ((localDW->SI_b_DoorHndUnfoldReq_prev !=
                  localDW->SI_b_DoorHndUnfoldReq_start) &&
                 localDW->SI_b_DoorHndUnfoldReq_start) {
        localDW->is_Ctrl = DHM_IN_Unfold;

        /*  未学习  */
        localDW->is_Unfold = DHM_IN_Start;
        localDW->temporalCounter_i1 = 0U;
        *rty_SO_e_MotorCmd = 1U;
        *rty_SO_e_MotorPwm = 100U;
      }
      break;

     case DHM_IN_Interrupt1:
      *rty_SO_e_MotorCmd = 0U;
      *rty_SO_e_MotorPwm = 0U;
      if (localDW->temporalCounter_i1 >= 20) {
        /*  delay   */
        localDW->is_Ctrl = DHM_IN_Fold;

        /*  未学习  */
        localDW->is_Fold = DHM_IN_Start;
        localDW->temporalCounter_i1 = 0U;
        *rty_SO_e_MotorCmd = 2U;
        *rty_SO_e_MotorPwm = 100U;
      }
      break;

     case DHM_IN_Interrupt2:
      *rty_SO_e_MotorCmd = 0U;
      *rty_SO_e_MotorPwm = 0U;
      if (localDW->temporalCounter_i1 >= 20) {
        /*  delay   */
        localDW->is_Ctrl = DHM_IN_Unfold;

        /*  未学习  */
        localDW->is_Unfold = DHM_IN_Start;
        localDW->temporalCounter_i1 = 0U;
        *rty_SO_e_MotorCmd = 1U;
        *rty_SO_e_MotorPwm = 100U;
      }
      break;

     default:
      /* case IN_Unfold: */
      if ((localDW->SI_b_DoorHndFoldReq_prev !=
           localDW->SI_b_DoorHndFoldReq_start) &&
          localDW->SI_b_DoorHndFoldReq_start) {
        localDW->is_Unfold = DHM_IN_NO_ACTIVE_CHILD;
        localDW->is_Ctrl = DHM_IN_Interrupt1;
        localDW->temporalCounter_i1 = 0U;

        /*  折叠打断展开  */
        *rty_SO_e_MotorCmd = 0U;
        *rty_SO_e_MotorPwm = 0U;
      } else if (localDW->is_Unfold == DHM_IN_Start) {
        *rty_SO_e_MotorCmd = 1U;
        *rty_SO_e_MotorPwm = 100U;
        if (localDW->temporalCounter_i1 >= 240) {
          localDW->is_Unfold = DHM_IN_Stop;
          *rty_SO_e_MotorCmd = 0U;
          *rty_SO_e_MotorPwm = 0U;
          *rty_SO_b_Error = false;
        }
      } else {
        /* case IN_Stop: */
        localDW->is_Unfold = DHM_IN_NO_ACTIVE_CHILD;
        localDW->is_Ctrl = DHM_IN_Idle;
        *rty_SO_e_MotorCmd = 0U;
        *rty_SO_e_MotorPwm = 0U;
      }
      break;
    }
  }

  /* End of Chart: '<S16>/CtrlLogic' */
}

/*
 * System initialize for atomic system:
 *    '<S16>/DoorHndPos'
 *    '<S21>/DoorHndPos'
 */
void DHM_DoorHndPos_Init(HndPos_Sts_E *rty_SO_m_DoorHndPosSts, sint16
  *rty_SO_s_MaxSoftPos, sint16 *rty_SO_s_MinSoftPos, sint16 *rty_SO_s_IceBrkPos)
{
  *rty_SO_m_DoorHndPosSts = Hnd_Fold;
  *rty_SO_s_MaxSoftPos = 0;
  *rty_SO_s_MinSoftPos = 0;
  *rty_SO_s_IceBrkPos = 0;
}

/*
 * Output and update for atomic system:
 *    '<S16>/DoorHndPos'
 *    '<S21>/DoorHndPos'
 */
void DHM_DoorHndPos(HndPos_Sts_E *rty_SO_m_DoorHndPosSts, DW_DoorHndPos_DHM_T
                    *localDW)
{
  /* Chart: '<S16>/DoorHndPos' */
  if (localDW->is_active_c5_DoorHndDriver == 0U) {
    localDW->is_active_c5_DoorHndDriver = 1U;
    *rty_SO_m_DoorHndPosSts = Hnd_Unknown;
  } else {
    *rty_SO_m_DoorHndPosSts = Hnd_Unknown;
  }

  /* End of Chart: '<S16>/DoorHndPos' */
}

/*
 * System initialize for atomic system:
 *    '<S16>/LearnLogic'
 *    '<S21>/LearnLogic'
 */
void DHM_LearnLogic_Init(uint8 *rty_SO_e_LearnMotorCmd, uint8
  *rty_SO_e_LearnMotorPwm, boolean *rty_SO_b_CorrectPosToZero, Learn_Sts_E
  *rty_SO_m_LearnSts, sint16 *rty_SO_s_MaxPos, boolean *rty_SO_b_Learning)
{
  *rty_SO_e_LearnMotorCmd = 0U;
  *rty_SO_e_LearnMotorPwm = 0U;
  *rty_SO_b_CorrectPosToZero = false;
  *rty_SO_m_LearnSts = Learn_Invalid;
  *rty_SO_s_MaxPos = 0;
  *rty_SO_b_Learning = false;
}

/*
 * System initialize for atomic system:
 *    '<S16>/MotorLogic'
 *    '<S21>/MotorLogic'
 */
void DHM_MotorLogic_Init(uint8 *rty_SO_e_MotorCmd, uint8 *rty_SO_e_MotorPwm)
{
  *rty_SO_e_MotorCmd = 0U;
  *rty_SO_e_MotorPwm = 0U;
}

/*
 * Output and update for atomic system:
 *    '<S16>/MotorLogic'
 *    '<S21>/MotorLogic'
 */
void DHM_MotorLogic(uint8 rtu_SI_e_LearnMotorCmd, uint8 rtu_SI_e_LearnMotorPwm,
                    uint8 rtu_SI_e_CtrlMotorCmd, uint8 rtu_SI_e_CtrlMotorPwm,
                    uint8 *rty_SO_e_MotorCmd, uint8 *rty_SO_e_MotorPwm,
                    DW_MotorLogic_DHM_T *localDW)
{
  /* Chart: '<S16>/MotorLogic' */
  if (localDW->is_active_c4_DoorHndDriver == 0U) {
    localDW->is_active_c4_DoorHndDriver = 1U;
    if (rtu_SI_e_LearnMotorCmd != 0) {
      *rty_SO_e_MotorCmd = rtu_SI_e_LearnMotorCmd;
      *rty_SO_e_MotorPwm = rtu_SI_e_LearnMotorPwm;
    } else if (rtu_SI_e_CtrlMotorCmd != 0) {
      *rty_SO_e_MotorCmd = rtu_SI_e_CtrlMotorCmd;
      *rty_SO_e_MotorPwm = rtu_SI_e_CtrlMotorPwm;
    } else {
      *rty_SO_e_MotorCmd = 0U;
      *rty_SO_e_MotorPwm = 0U;
    }
  } else if (rtu_SI_e_LearnMotorCmd != 0) {
    *rty_SO_e_MotorCmd = rtu_SI_e_LearnMotorCmd;
    *rty_SO_e_MotorPwm = rtu_SI_e_LearnMotorPwm;
  } else if (rtu_SI_e_CtrlMotorCmd != 0) {
    *rty_SO_e_MotorCmd = rtu_SI_e_CtrlMotorCmd;
    *rty_SO_e_MotorPwm = rtu_SI_e_CtrlMotorPwm;
  } else {
    *rty_SO_e_MotorCmd = 0U;
    *rty_SO_e_MotorPwm = 0U;
  }

  /* End of Chart: '<S16>/MotorLogic' */
}

/*
 * System initialize for atomic system:
 *    '<S16>/Stall'
 *    '<S21>/Stall'
 */
void DHM_Stall_Init(boolean *rty_SO_b_HallStall)
{
  *rty_SO_b_HallStall = false;
}

/*
 * System initialize for atomic system:
 *    '<S3>/FLDoorHndReq'
 *    '<S3>/FRDoorHndReq'
 *    '<S3>/RLDoorHndReq'
 *    '<S3>/RRDoorHndReq'
 */
void DHM_FLDoorHndReq_Init(boolean *rty_SO_b_HndUnfoldReq, boolean
  *rty_SO_b_HndFoldReq)
{
  *rty_SO_b_HndUnfoldReq = false;
  *rty_SO_b_HndFoldReq = false;
}

/*
 * Output and update for atomic system:
 *    '<S3>/FLDoorHndReq'
 *    '<S3>/FRDoorHndReq'
 *    '<S3>/RLDoorHndReq'
 *    '<S3>/RRDoorHndReq'
 */
void DHM_FLDoorHndReq(Boolean rtu_SI_b_CrashOutpSts, UInt8 rtu_SI_e_EspVehSpd,
                      boolean rtu_SI_b_DoorOpen, Door_Sts_E rtu_SI_m_DoorLockSts,
                      HndPos_Sts_E rtu_SI_m_HndPosSts, boolean
                      *rty_SO_b_HndUnfoldReq, boolean *rty_SO_b_HndFoldReq,
                      DW_FLDoorHndReq_DHM_T *localDW)
{
  if (localDW->temporalCounter_i1 < 127U) {
    localDW->temporalCounter_i1++;
  }

  if (localDW->temporalCounter_i2 < 7U) {
    localDW->temporalCounter_i2++;
  }

  localDW->SI_b_CrashOutpSts_prev = localDW->SI_b_CrashOutpSts_start;
  localDW->SI_b_CrashOutpSts_start = rtu_SI_b_CrashOutpSts;

  /* Chart: '<S3>/FLDoorHndReq' */
  if (localDW->is_active_c4_DoorHndReq == 0U) {
    localDW->SI_b_CrashOutpSts_prev = rtu_SI_b_CrashOutpSts;
    localDW->is_active_c4_DoorHndReq = 1U;
    localDW->is_c4_DoorHndReq = DHM_IN_PowerOnDelay;
    localDW->temporalCounter_i1 = 0U;
  } else if (localDW->is_c4_DoorHndReq == DHM_IN_Func) {
    if (localDW->is_Fold == DHM_IN_FoldReq) {
      if (localDW->temporalCounter_i1 >= 5) {
        localDW->is_Fold = DHM_IN_Idle_a;
        *rty_SO_b_HndFoldReq = false;
        localDW->SL_b_FoldReqTrig = (((rtu_SI_m_DoorLockSts == Door_Lock) ||
          (rtu_SI_e_EspVehSpd >= 15)) && localDW->SL_b_FoldReqTrig);
      }

      /* case IN_Idle: */
    } else if (((rtu_SI_m_DoorLockSts == Door_Lock) || (rtu_SI_e_EspVehSpd >= 15))
               && (!localDW->SL_b_FoldReqTrig) && (!rtu_SI_b_CrashOutpSts) &&
               (rtu_SI_m_HndPosSts != Hnd_Fold)) {
      localDW->is_Fold = DHM_IN_FoldReq;
      localDW->temporalCounter_i1 = 0U;
      *rty_SO_b_HndFoldReq = true;
      localDW->SL_b_FoldReqTrig = true;
    } else {
      localDW->SL_b_FoldReqTrig = (((rtu_SI_m_DoorLockSts == Door_Lock) ||
        (rtu_SI_e_EspVehSpd >= 15)) && localDW->SL_b_FoldReqTrig);
    }

    switch (localDW->is_Unfold) {
     case DHM_IN_CrashUnfoldReq:
      if (localDW->temporalCounter_i2 >= 5) {
        localDW->is_Unfold = DHM_IN_Idle_a;
        *rty_SO_b_HndUnfoldReq = false;
        localDW->SL_b_UnfoldReqTrig = ((rtu_SI_b_DoorOpen ||
          (rtu_SI_m_DoorLockSts == Door_Unlock)) && localDW->SL_b_UnfoldReqTrig);
      }
      break;

     case DHM_IN_Idle_a:
      if ((rtu_SI_e_EspVehSpd < 15) && (rtu_SI_b_DoorOpen ||
           (rtu_SI_m_DoorLockSts == Door_Unlock)) &&
          (!localDW->SL_b_UnfoldReqTrig) && (rtu_SI_m_HndPosSts != Hnd_Unfold))
      {
        localDW->is_Unfold = DHM_IN_NormalUnfoldReq;
        localDW->temporalCounter_i2 = 0U;
        *rty_SO_b_HndUnfoldReq = true;
        localDW->SL_b_UnfoldReqTrig = true;
      } else if ((localDW->SI_b_CrashOutpSts_prev !=
                  localDW->SI_b_CrashOutpSts_start) &&
                 localDW->SI_b_CrashOutpSts_start && (rtu_SI_m_HndPosSts !=
                  Hnd_Unfold)) {
        localDW->is_Unfold = DHM_IN_CrashUnfoldReq;
        localDW->temporalCounter_i2 = 0U;
        *rty_SO_b_HndUnfoldReq = true;
      } else {
        localDW->SL_b_UnfoldReqTrig = ((rtu_SI_b_DoorOpen ||
          (rtu_SI_m_DoorLockSts == Door_Unlock)) && localDW->SL_b_UnfoldReqTrig);
      }
      break;

     default:
      /* case IN_NormalUnfoldReq: */
      if (localDW->temporalCounter_i2 >= 5) {
        localDW->is_Unfold = DHM_IN_Idle_a;
        *rty_SO_b_HndUnfoldReq = false;
        localDW->SL_b_UnfoldReqTrig = ((rtu_SI_b_DoorOpen ||
          (rtu_SI_m_DoorLockSts == Door_Unlock)) && localDW->SL_b_UnfoldReqTrig);
      }
      break;
    }

    /* case IN_PowerOnDelay: */
  } else if (localDW->temporalCounter_i1 >= 100) {
    /*  上电延迟1s，防止底层信号量未及时传递导致请求误触发  */
    localDW->is_c4_DoorHndReq = DHM_IN_Func;
    localDW->is_Fold = DHM_IN_Idle_a;
    *rty_SO_b_HndFoldReq = false;
    localDW->SL_b_FoldReqTrig = (((rtu_SI_m_DoorLockSts == Door_Lock) ||
      (rtu_SI_e_EspVehSpd >= 15)) && localDW->SL_b_FoldReqTrig);
    localDW->is_Unfold = DHM_IN_Idle_a;
    *rty_SO_b_HndUnfoldReq = false;
    localDW->SL_b_UnfoldReqTrig = ((rtu_SI_b_DoorOpen || (rtu_SI_m_DoorLockSts ==
      Door_Unlock)) && localDW->SL_b_UnfoldReqTrig);
  }

  /* End of Chart: '<S3>/FLDoorHndReq' */
}

/* Model step function for TID1 */
void DHM_Step(void)                    /* Explicit Task: DHM_Step */
{
  /* local block i/o variables */
  SInt16 rtb_TmpSignalConversionAtVsINP_;
  SInt16 rtb_TmpSignalConversionAtVsIN_a;
  UInt8 rtb_TmpSignalConversionAtVeOUT_;
  uint8 rtb_SO_e_MotorCmd;
  uint8 rtb_SO_e_MotorPwm;
  uint8 rtb_SO_e_MotorCmd_c;
  uint8 rtb_SO_e_MotorPwm_m;
  uint8 rtb_SO_e_MotorCmd_a;
  uint8 rtb_SO_e_MotorPwm_b;
  uint8 rtb_SO_e_MotorCmd_e;
  uint8 rtb_SO_e_MotorPwm_d;
  Boolean rtb_TmpSignalConversionAtVbOUT_;
  HndPos_Sts_E rtb_SO_m_DoorHndPosSts;
  HndPos_Sts_E rtb_SO_m_DoorHndPosSts_h;
  UInt8 rtb_TmpSignalConversionAtVeINP_;
  UInt8 rtb_TmpSignalConversionAtVeIN_i;
  UInt8 rtb_TmpSignalConversionAtVeOU_a;
  UInt8 rtb_TmpSignalConversionAtVeOU_f;
  UInt8 tmpRead;
  UInt8 tmpRead_0;
  UInt8 tmpRead_1;
  UInt8 tmpRead_2;
  UInt8 tmpRead_3;
  uint8 SO_e_FRHndReq;
  uint8 SO_e_RRHndReq;
  boolean SO_b_Error_f;
  boolean rtb_LogicalOperator1;

  /* SignalConversion generated from: '<S2>/VbINP_HWA_DoorHandleLrnReq_flg_VbINP_HWA_DoorHandleLrnReq_flg_read' incorporates:
   *  Inport: '<Root>/VbINP_HWA_DoorHandleLrnReq_flg_VbINP_HWA_DoorHandleLrnReq_flg'
   */
  (void)Rte_Read_VbINP_HWA_DoorHandleLrnReq_flg_VbINP_HWA_DoorHandleLrnReq_flg
    (&DHM_B.VbINP_HWA_DoorHandleLrnReq_flg_);

  /* Inport: '<Root>/VeINP_CAN_RRDoorHandleLrnSts_sig_VeINP_CAN_RRDoorHandleLrnSts_sig' */
  (void)
    Rte_Read_VeINP_CAN_RRDoorHandleLrnSts_sig_VeINP_CAN_RRDoorHandleLrnSts_sig
    (&tmpRead_3);

  /* Inport: '<Root>/VeINP_CAN_FRDoorHandleLrnSts_sig_VeINP_CAN_FRDoorHandleLrnSts_sig' */
  (void)
    Rte_Read_VeINP_CAN_FRDoorHandleLrnSts_sig_VeINP_CAN_FRDoorHandleLrnSts_sig
    (&tmpRead_2);

  /* Inport: '<Root>/VeINP_EPRM_RLDoorHandleLrnStsEE_sig_VeINP_EPRM_RLDoorHandleLrnStsEE_sig' */
  (void)
    Rte_Read_VeINP_EPRM_RLDoorHandleLrnStsEE_sig_VeINP_EPRM_RLDoorHandleLrnStsEE_sig
    (&tmpRead_1);

  /* Inport: '<Root>/VeINP_EPRM_FLDoorHandleLrnStsEE_sig_VeINP_EPRM_FLDoorHandleLrnStsEE_sig' */
  (void)
    Rte_Read_VeINP_EPRM_FLDoorHandleLrnStsEE_sig_VeINP_EPRM_FLDoorHandleLrnStsEE_sig
    (&tmpRead_0);

  /* Inport: '<Root>/VeINP_CAN_RRDoorHandleSts_sig_VeINP_CAN_RRDoorHandleSts_sig' */
  (void)Rte_Read_VeINP_CAN_RRDoorHandleSts_sig_VeINP_CAN_RRDoorHandleSts_sig
    (&SO_e_FRHndReq);

  /* Inport: '<Root>/VeINP_CAN_FRDoorHandleSts_sig_VeINP_CAN_FRDoorHandleSts_sig' */
  (void)Rte_Read_VeINP_CAN_FRDoorHandleSts_sig_VeINP_CAN_FRDoorHandleSts_sig
    (&SO_e_RRHndReq);

  /* Inport: '<Root>/VeOUT_DLK_LHFDoorLockSts_sig_VeOUT_DLK_LHFDoorLockSts_sig' */
  (void)Rte_Read_VeOUT_DLK_LHFDoorLockSts_sig_VeOUT_DLK_LHFDoorLockSts_sig
    (&tmpRead);

  /* RootInportFunctionCallGenerator generated from: '<Root>/DHM_Step' incorporates:
   *  SubSystem: '<Root>/DHM_Step_sys'
   */
  /* DataStoreWrite: '<S3>/Data Store Write' incorporates:
   *  Constant: '<S3>/Constant'
   */
  DHM_DW.E03_DHM_L = 4U;

  /* SignalConversion generated from: '<S2>/VsINP_HWA_DriverHandleHall_sig_VsINP_HWA_DriverHandleHall_sig_read' incorporates:
   *  Inport: '<Root>/VsINP_HWA_DriverHandleHall_sig_VsINP_HWA_DriverHandleHall_sig'
   */
  (void)Rte_Read_VsINP_HWA_DriverHandleHall_sig_VsINP_HWA_DriverHandleHall_sig
    (&rtb_TmpSignalConversionAtVsINP_);

  /* Chart: '<S16>/DoorHndPos' */
  DHM_DoorHndPos(&rtb_SO_m_DoorHndPosSts_h, &DHM_DW.sf_DoorHndPos);

  /* SignalConversion generated from: '<S2>/VbOUT_SP_CrashOutpSts_flg_VbOUT_SP_CrashOutpSts_flg_read' incorporates:
   *  Inport: '<Root>/VbOUT_SP_CrashOutpSts_flg_VbOUT_SP_CrashOutpSts_flg'
   */
  (void)Rte_Read_VbOUT_SP_CrashOutpSts_flg_VbOUT_SP_CrashOutpSts_flg
    (&rtb_TmpSignalConversionAtVbOUT_);

  /* SignalConversion generated from: '<S2>/VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh_read' incorporates:
   *  Inport: '<Root>/VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh'
   */
  (void)Rte_Read_VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh
    (&rtb_TmpSignalConversionAtVeOUT_);

  /* SignalConversion generated from: '<S2>/VeOUT_SP_LHFdoorSts_sig_VeOUT_SP_LHFdoorSts_sig_read' incorporates:
   *  Inport: '<Root>/VeOUT_SP_LHFdoorSts_sig_VeOUT_SP_LHFdoorSts_sig'
   */
  (void)Rte_Read_VeOUT_SP_LHFdoorSts_sig_VeOUT_SP_LHFdoorSts_sig
    (&rtb_TmpSignalConversionAtVeOU_a);

  /* SignalConversion generated from: '<S2>/VeOUT_SP_LHRdoorSts_sig_VeOUT_SP_LHRdoorSts_sig_read' incorporates:
   *  Inport: '<Root>/VeOUT_SP_LHRdoorSts_sig_VeOUT_SP_LHRdoorSts_sig'
   */
  (void)Rte_Read_VeOUT_SP_LHRdoorSts_sig_VeOUT_SP_LHRdoorSts_sig
    (&rtb_TmpSignalConversionAtVeOU_f);

  /* SignalConversion generated from: '<S2>/VeINP_CAN_RHFDoorSts_sig_VeINP_CAN_RHFDoorSts_sig_read' incorporates:
   *  Inport: '<Root>/VeINP_CAN_RHFDoorSts_sig_VeINP_CAN_RHFDoorSts_sig'
   */
  (void)Rte_Read_VeINP_CAN_RHFDoorSts_sig_VeINP_CAN_RHFDoorSts_sig
    (&rtb_TmpSignalConversionAtVeINP_);

  /* SignalConversion generated from: '<S2>/VeINP_CAN_RHRDoorSts_sig_VeINP_CAN_RHRDoorSts_sig_read' incorporates:
   *  Inport: '<Root>/VeINP_CAN_RHRDoorSts_sig_VeINP_CAN_RHRDoorSts_sig'
   */
  (void)Rte_Read_VeINP_CAN_RHRDoorSts_sig_VeINP_CAN_RHRDoorSts_sig
    (&rtb_TmpSignalConversionAtVeIN_i);

  /* Logic: '<S3>/Logical Operator1' incorporates:
   *  Constant: '<S10>/Constant'
   *  Constant: '<S11>/Constant'
   *  Constant: '<S12>/Constant'
   *  Constant: '<S13>/Constant'
   *  Constant: '<S14>/Constant'
   *  Constant: '<S5>/Constant'
   *  Constant: '<S8>/Constant'
   *  Constant: '<S9>/Constant'
   *  Logic: '<S3>/Logical Operator'
   *  Logic: '<S3>/Logical Operator2'
   *  Logic: '<S3>/Logical Operator3'
   *  Logic: '<S3>/Logical Operator4'
   *  RelationalOperator: '<S10>/Compare'
   *  RelationalOperator: '<S11>/Compare'
   *  RelationalOperator: '<S12>/Compare'
   *  RelationalOperator: '<S13>/Compare'
   *  RelationalOperator: '<S14>/Compare'
   *  RelationalOperator: '<S5>/Compare'
   *  RelationalOperator: '<S8>/Compare'
   *  RelationalOperator: '<S9>/Compare'
   */
  rtb_LogicalOperator1 = ((rtb_TmpSignalConversionAtVeOU_a == 1) ||
    (rtb_TmpSignalConversionAtVeOU_a == 2) || ((rtb_TmpSignalConversionAtVeOU_f ==
    1) || (rtb_TmpSignalConversionAtVeOU_f == 2)) ||
    ((rtb_TmpSignalConversionAtVeINP_ == 1) || (rtb_TmpSignalConversionAtVeINP_ ==
    2)) || ((rtb_TmpSignalConversionAtVeIN_i == 1) ||
            (rtb_TmpSignalConversionAtVeIN_i == 2)));

  /* Chart: '<S3>/FLDoorHndReq' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion7'
   */
  DHM_FLDoorHndReq(rtb_TmpSignalConversionAtVbOUT_,
                   rtb_TmpSignalConversionAtVeOUT_, rtb_LogicalOperator1,
                   tmpRead, rtb_SO_m_DoorHndPosSts_h, &DHM_B.SO_b_HndUnfoldReq_j,
                   &DHM_B.SO_b_HndFoldReq_dm, &DHM_DW.sf_FLDoorHndReq);

  /* Chart: '<S16>/CtrlLogic' */
  DHM_CtrlLogic(DHM_B.SO_b_HndFoldReq_dm, DHM_B.SO_b_HndUnfoldReq_j,
                &rtb_SO_e_MotorCmd_e, &rtb_SO_e_MotorPwm_d, &SO_b_Error_f,
                &DHM_DW.sf_CtrlLogic);

  /* Chart: '<S16>/MotorLogic' */
  DHM_MotorLogic(DHM_B.SO_e_LearnMotorCmd_j, DHM_B.SO_e_LearnMotorPwm_i,
                 rtb_SO_e_MotorCmd_e, rtb_SO_e_MotorPwm_d, &rtb_SO_e_MotorCmd_a,
                 &rtb_SO_e_MotorPwm_b, &DHM_DW.sf_MotorLogic);

  /* SignalConversion generated from: '<S2>/VsINP_HWA_RLHandleHall_sig_VsINP_HWA_RLHandleHall_sig_read' incorporates:
   *  Inport: '<Root>/VsINP_HWA_RLHandleHall_sig_VsINP_HWA_RLHandleHall_sig'
   */
  (void)Rte_Read_VsINP_HWA_RLHandleHall_sig_VsINP_HWA_RLHandleHall_sig
    (&rtb_TmpSignalConversionAtVsIN_a);

  /* Chart: '<S21>/DoorHndPos' */
  DHM_DoorHndPos(&rtb_SO_m_DoorHndPosSts, &DHM_DW.sf_DoorHndPos_a);

  /* Chart: '<S3>/RLDoorHndReq' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion7'
   */
  DHM_FLDoorHndReq(rtb_TmpSignalConversionAtVbOUT_,
                   rtb_TmpSignalConversionAtVeOUT_, rtb_LogicalOperator1,
                   tmpRead, rtb_SO_m_DoorHndPosSts, &DHM_B.SO_b_HndUnfoldReq_a,
                   &DHM_B.SO_b_HndFoldReq_a, &DHM_DW.sf_RLDoorHndReq);

  /* Chart: '<S21>/CtrlLogic' */
  DHM_CtrlLogic(DHM_B.SO_b_HndFoldReq_a, DHM_B.SO_b_HndUnfoldReq_a,
                &rtb_SO_e_MotorCmd_c, &rtb_SO_e_MotorPwm_m, &SO_b_Error_f,
                &DHM_DW.sf_CtrlLogic_e);

  /* Chart: '<S21>/MotorLogic' */
  DHM_MotorLogic(DHM_B.SO_e_LearnMotorCmd, DHM_B.SO_e_LearnMotorPwm,
                 rtb_SO_e_MotorCmd_c, rtb_SO_e_MotorPwm_m, &rtb_SO_e_MotorCmd,
                 &rtb_SO_e_MotorPwm, &DHM_DW.sf_MotorLogic_o);

  /* Outport: '<Root>/VeOUT_DHM_FRHandleFoldedStatus_sig_VeOUT_DHM_FRHandleFoldedStatus_sig' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion1'
   *  DataTypeConversion: '<S3>/Data Type Conversion4'
   */
  (void)
    Rte_Write_VeOUT_DHM_FRHandleFoldedStatus_sig_VeOUT_DHM_FRHandleFoldedStatus_sig
    (SO_e_RRHndReq);

  /* Outport: '<Root>/VeOUT_DHM_RRHandleFoldedStatus_sig_VeOUT_DHM_RRHandleFoldedStatus_sig' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion2'
   *  DataTypeConversion: '<S3>/Data Type Conversion6'
   */
  (void)
    Rte_Write_VeOUT_DHM_RRHandleFoldedStatus_sig_VeOUT_DHM_RRHandleFoldedStatus_sig
    (SO_e_FRHndReq);

  /* Chart: '<S3>/FRDoorHndReq' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion4'
   *  DataTypeConversion: '<S3>/Data Type Conversion7'
   */
  DHM_FLDoorHndReq(rtb_TmpSignalConversionAtVbOUT_,
                   rtb_TmpSignalConversionAtVeOUT_, rtb_LogicalOperator1,
                   tmpRead, SO_e_RRHndReq, &DHM_B.SO_b_HndUnfoldReq_k,
                   &DHM_B.SO_b_HndFoldReq_d, &DHM_DW.sf_FRDoorHndReq);

  /* Chart: '<S3>/RRDoorHndReq' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion6'
   *  DataTypeConversion: '<S3>/Data Type Conversion7'
   */
  DHM_FLDoorHndReq(rtb_TmpSignalConversionAtVbOUT_,
                   rtb_TmpSignalConversionAtVeOUT_, rtb_LogicalOperator1,
                   tmpRead, SO_e_FRHndReq, &DHM_B.SO_b_HndUnfoldReq,
                   &DHM_B.SO_b_HndFoldReq, &DHM_DW.sf_RRDoorHndReq);

  /* Chart: '<S3>/HndReq' */
  DHM_DW.SI_b_FRHndFoldReq_prev = DHM_DW.SI_b_FRHndFoldReq_start;
  DHM_DW.SI_b_FRHndFoldReq_start = DHM_B.SO_b_HndFoldReq_d;
  DHM_DW.SI_b_FRHndUnfoldReq_prev = DHM_DW.SI_b_FRHndUnfoldReq_start;
  DHM_DW.SI_b_FRHndUnfoldReq_start = DHM_B.SO_b_HndUnfoldReq_k;
  DHM_DW.SI_b_RRHndFoldReq_prev = DHM_DW.SI_b_RRHndFoldReq_start;
  DHM_DW.SI_b_RRHndFoldReq_start = DHM_B.SO_b_HndFoldReq;
  DHM_DW.SI_b_RRHndUnfoldReq_prev = DHM_DW.SI_b_RRHndUnfoldReq_start;
  DHM_DW.SI_b_RRHndUnfoldReq_start = DHM_B.SO_b_HndUnfoldReq;
  if (DHM_DW.is_active_c1_DHM == 0U) {
    DHM_DW.SI_b_FRHndFoldReq_prev = DHM_B.SO_b_HndFoldReq_d;
    DHM_DW.SI_b_FRHndUnfoldReq_prev = DHM_B.SO_b_HndUnfoldReq_k;
    DHM_DW.SI_b_RRHndFoldReq_prev = DHM_B.SO_b_HndFoldReq;
    DHM_DW.SI_b_RRHndUnfoldReq_prev = DHM_B.SO_b_HndUnfoldReq;
    DHM_DW.is_active_c1_DHM = 1U;
    DHM_DW.is_FRHndReq = DHM_IN_Idle_p;
    SO_e_FRHndReq = 0U;
    DHM_DW.is_RRHndReq = DHM_IN_Idle_p;
    SO_e_RRHndReq = 0U;
  } else {
    switch (DHM_DW.is_FRHndReq) {
     case DHM_IN_FoldReq_e:
      SO_e_FRHndReq = 1U;
      if ((DHM_DW.SI_b_FRHndUnfoldReq_prev != DHM_DW.SI_b_FRHndUnfoldReq_start) &&
          DHM_DW.SI_b_FRHndUnfoldReq_start) {
        DHM_DW.is_FRHndReq = DHM_IN_UnfoldReq;
        SO_e_FRHndReq = 2U;
      } else if (!DHM_B.SO_b_HndFoldReq_d) {
        DHM_DW.is_FRHndReq = DHM_IN_Idle_p;
        SO_e_FRHndReq = 0U;
      }
      break;

     case DHM_IN_Idle_p:
      SO_e_FRHndReq = 0U;
      if ((DHM_DW.SI_b_FRHndFoldReq_prev != DHM_DW.SI_b_FRHndFoldReq_start) &&
          DHM_DW.SI_b_FRHndFoldReq_start) {
        DHM_DW.is_FRHndReq = DHM_IN_FoldReq_e;
        SO_e_FRHndReq = 1U;
      } else if ((DHM_DW.SI_b_FRHndUnfoldReq_prev !=
                  DHM_DW.SI_b_FRHndUnfoldReq_start) &&
                 DHM_DW.SI_b_FRHndUnfoldReq_start) {
        DHM_DW.is_FRHndReq = DHM_IN_UnfoldReq;
        SO_e_FRHndReq = 2U;
      }
      break;

     default:
      /* case IN_UnfoldReq: */
      SO_e_FRHndReq = 2U;
      if ((DHM_DW.SI_b_FRHndFoldReq_prev != DHM_DW.SI_b_FRHndFoldReq_start) &&
          DHM_DW.SI_b_FRHndFoldReq_start) {
        DHM_DW.is_FRHndReq = DHM_IN_FoldReq_e;
        SO_e_FRHndReq = 1U;
      } else if (!DHM_B.SO_b_HndUnfoldReq_k) {
        DHM_DW.is_FRHndReq = DHM_IN_Idle_p;
        SO_e_FRHndReq = 0U;
      }
      break;
    }

    switch (DHM_DW.is_RRHndReq) {
     case DHM_IN_FoldReq_e:
      SO_e_RRHndReq = 1U;
      if ((DHM_DW.SI_b_RRHndUnfoldReq_prev != DHM_DW.SI_b_RRHndUnfoldReq_start) &&
          DHM_DW.SI_b_RRHndUnfoldReq_start) {
        DHM_DW.is_RRHndReq = DHM_IN_UnfoldReq;
        SO_e_RRHndReq = 2U;
      } else if (!DHM_B.SO_b_HndFoldReq) {
        DHM_DW.is_RRHndReq = DHM_IN_Idle_p;
        SO_e_RRHndReq = 0U;
      }
      break;

     case DHM_IN_Idle_p:
      SO_e_RRHndReq = 0U;
      if ((DHM_DW.SI_b_RRHndFoldReq_prev != DHM_DW.SI_b_RRHndFoldReq_start) &&
          DHM_DW.SI_b_RRHndFoldReq_start) {
        DHM_DW.is_RRHndReq = DHM_IN_FoldReq_e;
        SO_e_RRHndReq = 1U;
      } else if ((DHM_DW.SI_b_RRHndUnfoldReq_prev !=
                  DHM_DW.SI_b_RRHndUnfoldReq_start) &&
                 DHM_DW.SI_b_RRHndUnfoldReq_start) {
        DHM_DW.is_RRHndReq = DHM_IN_UnfoldReq;
        SO_e_RRHndReq = 2U;
      }
      break;

     default:
      /* case IN_UnfoldReq: */
      SO_e_RRHndReq = 2U;
      if ((DHM_DW.SI_b_RRHndFoldReq_prev != DHM_DW.SI_b_RRHndFoldReq_start) &&
          DHM_DW.SI_b_RRHndFoldReq_start) {
        DHM_DW.is_RRHndReq = DHM_IN_FoldReq_e;
        SO_e_RRHndReq = 1U;
      } else if (!DHM_B.SO_b_HndUnfoldReq) {
        DHM_DW.is_RRHndReq = DHM_IN_Idle_p;
        SO_e_RRHndReq = 0U;
      }
      break;
    }
  }

  /* End of Chart: '<S3>/HndReq' */
  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/DHM_Step' */

  /* RootInportFunctionCallGenerator generated from: '<Root>/DHM_Step' incorporates:
   *  SubSystem: '<Root>/DHM_Step_sys'
   */
  /* Outport: '<Root>/VeOUT_DHM_FLHandleFoldedStatus_sig_VeOUT_DHM_FLHandleFoldedStatus_sig' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion3'
   */
  (void)
    Rte_Write_VeOUT_DHM_FLHandleFoldedStatus_sig_VeOUT_DHM_FLHandleFoldedStatus_sig
    (rtb_SO_m_DoorHndPosSts_h);

  /* Outport: '<Root>/VeOUT_DHM_RLHandleFoldedStatus_sig_VeOUT_DHM_RLHandleFoldedStatus_sig' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion5'
   */
  (void)
    Rte_Write_VeOUT_DHM_RLHandleFoldedStatus_sig_VeOUT_DHM_RLHandleFoldedStatus_sig
    (rtb_SO_m_DoorHndPosSts);

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/DHM_Step' */

  /* Outport: '<Root>/VeOUT_DHM_FRDoorHandleReq_sig_VeOUT_DHM_FRDoorHandleReq_sig' */
  (void)Rte_Write_VeOUT_DHM_FRDoorHandleReq_sig_VeOUT_DHM_FRDoorHandleReq_sig
    (SO_e_FRHndReq);

  /* Outport: '<Root>/VeOUT_DHM_RRDoorHandleReq_sig_VeOUT_DHM_RRDoorHandleReq_sig' */
  (void)Rte_Write_VeOUT_DHM_RRDoorHandleReq_sig_VeOUT_DHM_RRDoorHandleReq_sig
    (SO_e_RRHndReq);

  /* RootInportFunctionCallGenerator generated from: '<Root>/DHM_Step' incorporates:
   *  SubSystem: '<Root>/DHM_Step_sys'
   */
  /* Outport: '<Root>/VbOUT_DHM_FLHadUnfold_flg_VbOUT_DHM_FLHadUnfold_flg' incorporates:
   *  Constant: '<S4>/Constant'
   *  RelationalOperator: '<S4>/Compare'
   */
  (void)Rte_Write_VbOUT_DHM_FLHadUnfold_flg_VbOUT_DHM_FLHadUnfold_flg
    (rtb_SO_e_MotorCmd_a == 1);

  /* Outport: '<Root>/VbOUT_DHM_FLHadFold_flg_VbOUT_DHM_FLHadFold_flg' incorporates:
   *  Constant: '<S15>/Constant'
   *  RelationalOperator: '<S15>/Compare'
   */
  (void)Rte_Write_VbOUT_DHM_FLHadFold_flg_VbOUT_DHM_FLHadFold_flg
    (rtb_SO_e_MotorCmd_a == 2);

  /* Outport: '<Root>/VbOUT_DHM_RLHandleUnfold_flg_VbOUT_DHM_RLHandleUnfold_flg' incorporates:
   *  Constant: '<S6>/Constant'
   *  RelationalOperator: '<S6>/Compare'
   */
  (void)Rte_Write_VbOUT_DHM_RLHandleUnfold_flg_VbOUT_DHM_RLHandleUnfold_flg
    (rtb_SO_e_MotorCmd == 1);

  /* Outport: '<Root>/VbOUT_DHM_RLHandleFold_flg_VbOUT_DHM_RLHandleFold_flg' incorporates:
   *  Constant: '<S7>/Constant'
   *  RelationalOperator: '<S7>/Compare'
   */
  (void)Rte_Write_VbOUT_DHM_RLHandleFold_flg_VbOUT_DHM_RLHandleFold_flg
    (rtb_SO_e_MotorCmd == 2);

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/DHM_Step' */

  /* Outport: '<Root>/VsINP_DHM_FLDoorHandleEE_sig_VsINP_DHM_FLDoorHandleEE_sig' */
  (void)Rte_Write_VsINP_DHM_FLDoorHandleEE_sig_VsINP_DHM_FLDoorHandleEE_sig
    (DHM_B.SO_s_MaxPos_i);

  /* Outport: '<Root>/VsINP_DHM_RLDoorHandleEE_sig_VsINP_DHM_RLDoorHandleEE_sig' */
  (void)Rte_Write_VsINP_DHM_RLDoorHandleEE_sig_VsINP_DHM_RLDoorHandleEE_sig
    (DHM_B.SO_s_MaxPos);

  /* Outport: '<Root>/VeOUT_DHM_DoorHandleLrnSts_sig_VeOUT_DHM_DoorHandleLrnSts_sig' */
  (void)Rte_Write_VeOUT_DHM_DoorHandleLrnSts_sig_VeOUT_DHM_DoorHandleLrnSts_sig
    (DHM_B.SO_e_LearnSts);

  /* RootInportFunctionCallGenerator generated from: '<Root>/DHM_Step' incorporates:
   *  SubSystem: '<Root>/DHM_Step_sys'
   */
  /* Outport: '<Root>/VeOUT_DHM_FLDoorHandleLrnStsEE_sig_VeOUT_DHM_FLDoorHandleLrnStsEE_sig' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion10'
   */
  (void)
    Rte_Write_VeOUT_DHM_FLDoorHandleLrnStsEE_sig_VeOUT_DHM_FLDoorHandleLrnStsEE_sig
    (DHM_B.SO_m_LearnSts_g);

  /* Outport: '<Root>/VeOUT_DHM_RLDoorHandleLrnStsEE_sig_VeOUT_DHM_RLDoorHandleLrnStsEE_sig' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion11'
   */
  (void)
    Rte_Write_VeOUT_DHM_RLDoorHandleLrnStsEE_sig_VeOUT_DHM_RLDoorHandleLrnStsEE_sig
    (DHM_B.SO_m_LearnSts);

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/DHM_Step' */

  /* Outport: '<Root>/VbOUT_DHM_DoorHandleLrnReq_flg_VbOUT_DHM_DoorHandleLrnReq_flg' */
  (void)Rte_Write_VbOUT_DHM_DoorHandleLrnReq_flg_VbOUT_DHM_DoorHandleLrnReq_flg
    (DHM_B.VbINP_HWA_DoorHandleLrnReq_flg_);
}

/* Model initialize function */
void DHM_Init(void)
{
  {
    /* local block i/o variables */
    uint8 rtb_SO_e_MotorCmd;
    uint8 rtb_SO_e_MotorPwm;
    uint8 rtb_SO_e_MotorCmd_c;
    uint8 rtb_SO_e_MotorPwm_m;
    uint8 rtb_SO_e_MotorCmd_a;
    uint8 rtb_SO_e_MotorPwm_b;
    uint8 rtb_SO_e_MotorCmd_e;
    uint8 rtb_SO_e_MotorPwm_d;
    HndPos_Sts_E rtb_SO_m_DoorHndPosSts;
    HndPos_Sts_E rtb_SO_m_DoorHndPosSts_h;
    boolean SO_b_Error_f;

    /* SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/DHM_Step' incorporates:
     *  SubSystem: '<Root>/DHM_Step_sys'
     */

    /* SystemInitialize for Chart: '<S16>/CtrlLogic' */
    DHM_CtrlLogic_Init(&rtb_SO_e_MotorCmd_e, &rtb_SO_e_MotorPwm_d, &SO_b_Error_f);

    /* SystemInitialize for Chart: '<S16>/DoorHndPos' */
    DHM_DoorHndPos_Init(&rtb_SO_m_DoorHndPosSts_h, &DHM_B.SO_s_MaxSoftPos_p,
                        &DHM_B.SO_s_MinSoftPos_f, &DHM_B.SO_s_IceBrkPos_e);

    /* SystemInitialize for Chart: '<S16>/LearnLogic' */
    DHM_LearnLogic_Init(&DHM_B.SO_e_LearnMotorCmd_j, &DHM_B.SO_e_LearnMotorPwm_i,
                        &SO_b_Error_f, &DHM_B.SO_m_LearnSts_g,
                        &DHM_B.SO_s_MaxPos_i, &DHM_B.SO_b_Learning_e);

    /* SystemInitialize for Chart: '<S16>/MotorLogic' */
    DHM_MotorLogic_Init(&rtb_SO_e_MotorCmd_a, &rtb_SO_e_MotorPwm_b);

    /* SystemInitialize for Chart: '<S16>/Stall' */
    DHM_Stall_Init(&DHM_B.SO_b_HallStall_d);

    /* SystemInitialize for Chart: '<S3>/FLDoorHndReq' */
    DHM_FLDoorHndReq_Init(&DHM_B.SO_b_HndUnfoldReq_j, &DHM_B.SO_b_HndFoldReq_dm);

    /* SystemInitialize for Chart: '<S3>/FRDoorHndReq' */
    DHM_FLDoorHndReq_Init(&DHM_B.SO_b_HndUnfoldReq_k, &DHM_B.SO_b_HndFoldReq_d);

    /* SystemInitialize for Chart: '<S21>/CtrlLogic' */
    DHM_CtrlLogic_Init(&rtb_SO_e_MotorCmd_c, &rtb_SO_e_MotorPwm_m, &SO_b_Error_f);

    /* SystemInitialize for Chart: '<S21>/DoorHndPos' */
    DHM_DoorHndPos_Init(&rtb_SO_m_DoorHndPosSts, &DHM_B.SO_s_MaxSoftPos,
                        &DHM_B.SO_s_MinSoftPos, &DHM_B.SO_s_IceBrkPos);

    /* SystemInitialize for Chart: '<S21>/LearnLogic' */
    DHM_LearnLogic_Init(&DHM_B.SO_e_LearnMotorCmd, &DHM_B.SO_e_LearnMotorPwm,
                        &SO_b_Error_f, &DHM_B.SO_m_LearnSts, &DHM_B.SO_s_MaxPos,
                        &DHM_B.SO_b_Learning);

    /* SystemInitialize for Chart: '<S21>/MotorLogic' */
    DHM_MotorLogic_Init(&rtb_SO_e_MotorCmd, &rtb_SO_e_MotorPwm);

    /* SystemInitialize for Chart: '<S21>/Stall' */
    DHM_Stall_Init(&DHM_B.SO_b_HallStall);

    /* SystemInitialize for Chart: '<S3>/RLDoorHndReq' */
    DHM_FLDoorHndReq_Init(&DHM_B.SO_b_HndUnfoldReq_a, &DHM_B.SO_b_HndFoldReq_a);

    /* SystemInitialize for Chart: '<S3>/RRDoorHndReq' */
    DHM_FLDoorHndReq_Init(&DHM_B.SO_b_HndUnfoldReq, &DHM_B.SO_b_HndFoldReq);

    /* End of SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/DHM_Step' */

    /* SystemInitialize for Outport: '<Root>/VsINP_DHM_FLDoorHandleEE_sig_VsINP_DHM_FLDoorHandleEE_sig' */
    (void)Rte_Write_VsINP_DHM_FLDoorHandleEE_sig_VsINP_DHM_FLDoorHandleEE_sig
      (DHM_B.SO_s_MaxPos_i);

    /* SystemInitialize for Outport: '<Root>/VsINP_DHM_RLDoorHandleEE_sig_VsINP_DHM_RLDoorHandleEE_sig' */
    (void)Rte_Write_VsINP_DHM_RLDoorHandleEE_sig_VsINP_DHM_RLDoorHandleEE_sig
      (DHM_B.SO_s_MaxPos);
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
