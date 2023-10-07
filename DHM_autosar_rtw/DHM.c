/*
 * File: DHM.c
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

#include "DHM.h"
#include "rtwtypes.h"
#include "Rte_Type.h"
#include "DHM_types.h"
#include "DHM_private.h"

/* Named constants for Chart: '<S8>/CtrlLogic' */
#define DHM_IN_Check                   ((uint8)1U)
#define DHM_IN_Fold                    ((uint8)1U)
#define DHM_IN_IceBrk1                 ((uint8)2U)
#define DHM_IN_IceBrk2                 ((uint8)3U)
#define DHM_IN_IceBrk3                 ((uint8)4U)
#define DHM_IN_IceBrkWait              ((uint8)5U)
#define DHM_IN_Icebreak                ((uint8)1U)
#define DHM_IN_Idle                    ((uint8)2U)
#define DHM_IN_Interrupt1              ((uint8)3U)
#define DHM_IN_Interrupt2              ((uint8)4U)
#define DHM_IN_NO_ACTIVE_CHILD         ((uint8)0U)
#define DHM_IN_Start                   ((uint8)2U)
#define DHM_IN_Start_i                 ((uint8)1U)
#define DHM_IN_Step1                   ((uint8)3U)
#define DHM_IN_Step1_o                 ((uint8)2U)
#define DHM_IN_Step2                   ((uint8)4U)
#define DHM_IN_Step2_l                 ((uint8)3U)
#define DHM_IN_Step3                   ((uint8)5U)
#define DHM_IN_Step3_o                 ((uint8)4U)
#define DHM_IN_Stop                    ((uint8)6U)
#define DHM_IN_Stop_e                  ((uint8)5U)
#define DHM_IN_Unfold                  ((uint8)5U)

/* Named constants for Chart: '<S8>/LearnLogic' */
#define DHM_IN_CorrectMaxPos           ((uint8)1U)
#define DHM_IN_CorrectZeroPos          ((uint8)2U)
#define DHM_IN_Failed                  ((uint8)3U)
#define DHM_IN_Finished                ((uint8)4U)
#define DHM_IN_GotoMaxPos              ((uint8)5U)
#define DHM_IN_GotoZeroPos             ((uint8)6U)
#define DHM_IN_Idle_j                  ((uint8)7U)
#define DHM_IN_LearnLogic              ((uint8)1U)
#define DHM_IN_PowerOn                 ((uint8)2U)

/* Named constants for Chart: '<S8>/Stall' */
#define DHM_IN_Checking                ((uint8)1U)
#define DHM_IN_Idle_a                  ((uint8)2U)
#define DHM_IN_Stall                   ((uint8)3U)

/* Named constants for Chart: '<S3>/FLDoorHndReq' */
#define DHM_IN_CrashUnfoldReq          ((uint8)1U)
#define DHM_IN_FoldReq                 ((uint8)1U)
#define DHM_IN_Idle_ai                 ((uint8)2U)
#define DHM_IN_NormalUnfoldReq         ((uint8)3U)

/* Block signals (default storage) */
B_DHM_T DHM_B;

/* Block states (default storage) */
DW_DHM_T DHM_DW;

/* Forward declaration for local functions */
static void DHM_Unfold(boolean rtu_SI_b_HallStall, SInt16 rtu_SI_s_CurrentPos,
  sint16 rtu_SI_s_MaxSoftPos, sint16 rtu_SI_s_IceBrkPos, uint8
  *rty_SO_e_MotorCmd, uint8 *rty_SO_e_MotorPwm, boolean *rty_SO_b_Error,
  DW_CtrlLogic_DHM_T *localDW);

/* Forward declaration for local functions */
static float64 DHM_GetPosSts(float64 CurrentPos, float64 MinSoftPos, float64
  MaxSoftPos);
static uint8 DHM_safe_cast_to_HndPos_Sts_E(uint8 input);

/* Function for Chart: '<S8>/CtrlLogic' */
static void DHM_Unfold(boolean rtu_SI_b_HallStall, SInt16 rtu_SI_s_CurrentPos,
  sint16 rtu_SI_s_MaxSoftPos, sint16 rtu_SI_s_IceBrkPos, uint8
  *rty_SO_e_MotorCmd, uint8 *rty_SO_e_MotorPwm, boolean *rty_SO_b_Error,
  DW_CtrlLogic_DHM_T *localDW)
{
  if ((localDW->SI_b_DoorHndFoldReq_prev != localDW->SI_b_DoorHndFoldReq_start) &&
      localDW->SI_b_DoorHndFoldReq_start) {
    localDW->is_Icebreak = DHM_IN_NO_ACTIVE_CHILD;
    localDW->is_Unfold = DHM_IN_NO_ACTIVE_CHILD;
    localDW->is_Ctrl = DHM_IN_Interrupt1;
    localDW->temporalCounter_i1 = 0U;

    /*  折叠打断展开  */
    *rty_SO_e_MotorCmd = 0U;
    *rty_SO_e_MotorPwm = 0U;
  } else {
    switch (localDW->is_Unfold) {
     case DHM_IN_Icebreak:
      switch (localDW->is_Icebreak) {
       case DHM_IN_Check:
        *rty_SO_e_MotorCmd = 0U;
        *rty_SO_e_MotorPwm = 0U;
        if (rtu_SI_s_CurrentPos >= rtu_SI_s_IceBrkPos) {
          /*  破冰完成  */
          localDW->is_Icebreak = DHM_IN_NO_ACTIVE_CHILD;
          localDW->is_Unfold = DHM_IN_Step3;
          localDW->temporalCounter_i1 = 0U;

          /*  缓停  */
          *rty_SO_e_MotorCmd = 1U;
          *rty_SO_e_MotorPwm = 60U;
        } else {
          *rty_SO_b_Error = true;

          /*  破冰失败，报错  */
          localDW->is_Icebreak = DHM_IN_NO_ACTIVE_CHILD;
          localDW->is_Unfold = DHM_IN_NO_ACTIVE_CHILD;
          localDW->is_Ctrl = DHM_IN_Idle;
          *rty_SO_e_MotorCmd = 0U;
          *rty_SO_e_MotorPwm = 0U;
        }
        break;

       case DHM_IN_IceBrk1:
        *rty_SO_e_MotorCmd = 1U;
        *rty_SO_e_MotorPwm = 100U;
        if (localDW->temporalCounter_i1 >= 50) {
          localDW->is_Icebreak = DHM_IN_IceBrk2;
          localDW->temporalCounter_i1 = 0U;
          *rty_SO_e_MotorCmd = 0U;
          *rty_SO_e_MotorPwm = 0U;
        }
        break;

       case DHM_IN_IceBrk2:
        *rty_SO_e_MotorCmd = 0U;
        *rty_SO_e_MotorPwm = 0U;
        if (localDW->temporalCounter_i1 >= 50) {
          localDW->is_Icebreak = DHM_IN_IceBrk3;
          *rty_SO_e_MotorCmd = 1U;
          *rty_SO_e_MotorPwm = 100U;
        }
        break;

       case DHM_IN_IceBrk3:
        localDW->is_Icebreak = DHM_IN_Check;
        *rty_SO_e_MotorCmd = 0U;
        *rty_SO_e_MotorPwm = 0U;
        break;

       default:
        /* case IN_IceBrkWait: */
        *rty_SO_e_MotorCmd = 0U;
        *rty_SO_e_MotorPwm = 0U;
        if (localDW->temporalCounter_i1 >= 130) {
          localDW->is_Icebreak = DHM_IN_IceBrk1;
          localDW->temporalCounter_i1 = 0U;
          *rty_SO_e_MotorCmd = 1U;
          *rty_SO_e_MotorPwm = 100U;
        }
        break;
      }
      break;

     case DHM_IN_Start:
      *rty_SO_e_MotorCmd = 1U;
      *rty_SO_e_MotorPwm = 100U;
      if ((localDW->temporalCounter_i1 >= 200) || rtu_SI_b_HallStall) {
        localDW->is_Unfold = DHM_IN_Stop;
        *rty_SO_e_MotorCmd = 0U;
        *rty_SO_e_MotorPwm = 0U;
        *rty_SO_b_Error = false;
      }
      break;

     case DHM_IN_Step1:
      *rty_SO_e_MotorCmd = 1U;
      *rty_SO_e_MotorPwm = 60U;
      if (localDW->temporalCounter_i1 >= 20) {
        localDW->is_Unfold = DHM_IN_Step2;
        localDW->temporalCounter_i1 = 0U;
        *rty_SO_e_MotorCmd = 1U;
        *rty_SO_e_MotorPwm = 85U;
      }
      break;

     case DHM_IN_Step2:
      *rty_SO_e_MotorCmd = 1U;
      *rty_SO_e_MotorPwm = 85U;
      if (rtu_SI_s_CurrentPos >= rtu_SI_s_MaxSoftPos) {
        localDW->is_Unfold = DHM_IN_Step3;
        localDW->temporalCounter_i1 = 0U;

        /*  缓停  */
        *rty_SO_e_MotorCmd = 1U;
        *rty_SO_e_MotorPwm = 60U;
      } else if (localDW->temporalCounter_i1 >= 200) {
        localDW->is_Unfold = DHM_IN_Icebreak;
        localDW->is_Icebreak = DHM_IN_IceBrkWait;
        localDW->temporalCounter_i1 = 0U;

        /*  破冰延时  */
        *rty_SO_e_MotorCmd = 0U;
        *rty_SO_e_MotorPwm = 0U;
      }
      break;

     case DHM_IN_Step3:
      *rty_SO_e_MotorCmd = 1U;
      *rty_SO_e_MotorPwm = 60U;
      if (localDW->temporalCounter_i1 >= 20) {
        localDW->is_Unfold = DHM_IN_Stop;
        *rty_SO_e_MotorCmd = 0U;
        *rty_SO_e_MotorPwm = 0U;
        *rty_SO_b_Error = false;
      }
      break;

     default:
      /* case IN_Stop: */
      localDW->is_Unfold = DHM_IN_NO_ACTIVE_CHILD;
      localDW->is_Ctrl = DHM_IN_Idle;
      *rty_SO_e_MotorCmd = 0U;
      *rty_SO_e_MotorPwm = 0U;
      break;
    }
  }
}

/*
 * System initialize for atomic system:
 *    '<S8>/CtrlLogic'
 *    '<S11>/CtrlLogic'
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
 *    '<S8>/CtrlLogic'
 *    '<S11>/CtrlLogic'
 */
void DHM_CtrlLogic(boolean rtu_SI_b_HallStall, SInt16 rtu_SI_s_CurrentPos,
                   sint16 rtu_SI_s_MaxSoftPos, sint16 rtu_SI_s_MinSoftPos,
                   sint16 rtu_SI_s_IceBrkPos, boolean rtu_SI_b_DoorHndFoldReq,
                   boolean rtu_SI_b_DoorHndUnfoldReq, Learn_Sts_E
                   rtu_SI_m_LearnSts, uint8 *rty_SO_e_MotorCmd, uint8
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

  /* Chart: '<S8>/CtrlLogic' */
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
      } else {
        switch (localDW->is_Fold) {
         case DHM_IN_Start_i:
          *rty_SO_e_MotorCmd = 2U;
          *rty_SO_e_MotorPwm = 100U;
          if ((localDW->temporalCounter_i1 >= 200) || rtu_SI_b_HallStall) {
            localDW->is_Fold = DHM_IN_Stop_e;
            *rty_SO_e_MotorCmd = 0U;
            *rty_SO_e_MotorPwm = 0U;
            *rty_SO_b_Error = false;
          }
          break;

         case DHM_IN_Step1_o:
          *rty_SO_e_MotorCmd = 2U;
          *rty_SO_e_MotorPwm = 60U;
          if (localDW->temporalCounter_i1 >= 20) {
            localDW->is_Fold = DHM_IN_Step2_l;
            localDW->temporalCounter_i1 = 0U;
            *rty_SO_e_MotorCmd = 2U;
            *rty_SO_e_MotorPwm = 85U;
          }
          break;

         case DHM_IN_Step2_l:
          *rty_SO_e_MotorCmd = 2U;
          *rty_SO_e_MotorPwm = 85U;
          if (rtu_SI_s_CurrentPos <= rtu_SI_s_MinSoftPos) {
            localDW->is_Fold = DHM_IN_Step3_o;
            localDW->temporalCounter_i1 = 0U;

            /*  缓停  */
            *rty_SO_e_MotorCmd = 2U;
            *rty_SO_e_MotorPwm = 60U;
          } else if (localDW->temporalCounter_i1 >= 200) {
            /*  超时报错  */
            localDW->is_Fold = DHM_IN_NO_ACTIVE_CHILD;
            localDW->is_Ctrl = DHM_IN_Idle;
            *rty_SO_e_MotorCmd = 0U;
            *rty_SO_e_MotorPwm = 0U;
          }
          break;

         case DHM_IN_Step3_o:
          *rty_SO_e_MotorCmd = 2U;
          *rty_SO_e_MotorPwm = 60U;
          if (localDW->temporalCounter_i1 >= 20) {
            localDW->is_Fold = DHM_IN_Stop_e;
            *rty_SO_e_MotorCmd = 0U;
            *rty_SO_e_MotorPwm = 0U;
            *rty_SO_b_Error = false;
          }
          break;

         default:
          /* case IN_Stop: */
          localDW->is_Fold = DHM_IN_NO_ACTIVE_CHILD;
          localDW->is_Ctrl = DHM_IN_Idle;
          *rty_SO_e_MotorCmd = 0U;
          *rty_SO_e_MotorPwm = 0U;
          break;
        }
      }
      break;

     case DHM_IN_Idle:
      *rty_SO_e_MotorCmd = 0U;
      *rty_SO_e_MotorPwm = 0U;
      if ((localDW->SI_b_DoorHndFoldReq_prev !=
           localDW->SI_b_DoorHndFoldReq_start) &&
          localDW->SI_b_DoorHndFoldReq_start) {
        localDW->is_Ctrl = DHM_IN_Fold;
        if (rtu_SI_m_LearnSts == Learn_Success) {
          /*  已学习  */
          localDW->is_Fold = DHM_IN_Step1_o;
          localDW->temporalCounter_i1 = 0U;

          /*  缓启  */
          *rty_SO_e_MotorCmd = 2U;
          *rty_SO_e_MotorPwm = 60U;
        } else {
          /*  未学习  */
          localDW->is_Fold = DHM_IN_Start_i;
          localDW->temporalCounter_i1 = 0U;
          *rty_SO_e_MotorCmd = 2U;
          *rty_SO_e_MotorPwm = 100U;
        }
      } else if ((localDW->SI_b_DoorHndUnfoldReq_prev !=
                  localDW->SI_b_DoorHndUnfoldReq_start) &&
                 localDW->SI_b_DoorHndUnfoldReq_start) {
        localDW->is_Ctrl = DHM_IN_Unfold;
        if (rtu_SI_m_LearnSts == Learn_Success) {
          /*  已学习  */
          localDW->is_Unfold = DHM_IN_Step1;
          localDW->temporalCounter_i1 = 0U;

          /*  缓启  */
          *rty_SO_e_MotorCmd = 1U;
          *rty_SO_e_MotorPwm = 60U;
        } else {
          /*  未学习  */
          localDW->is_Unfold = DHM_IN_Start;
          localDW->temporalCounter_i1 = 0U;
          *rty_SO_e_MotorCmd = 1U;
          *rty_SO_e_MotorPwm = 100U;
        }
      }
      break;

     case DHM_IN_Interrupt1:
      *rty_SO_e_MotorCmd = 0U;
      *rty_SO_e_MotorPwm = 0U;
      if (localDW->temporalCounter_i1 >= 20) {
        /*  delay   */
        localDW->is_Ctrl = DHM_IN_Fold;
        if (rtu_SI_m_LearnSts == Learn_Success) {
          /*  已学习  */
          localDW->is_Fold = DHM_IN_Step1_o;
          localDW->temporalCounter_i1 = 0U;

          /*  缓启  */
          *rty_SO_e_MotorCmd = 2U;
          *rty_SO_e_MotorPwm = 60U;
        } else {
          /*  未学习  */
          localDW->is_Fold = DHM_IN_Start_i;
          localDW->temporalCounter_i1 = 0U;
          *rty_SO_e_MotorCmd = 2U;
          *rty_SO_e_MotorPwm = 100U;
        }
      }
      break;

     case DHM_IN_Interrupt2:
      *rty_SO_e_MotorCmd = 0U;
      *rty_SO_e_MotorPwm = 0U;
      if (localDW->temporalCounter_i1 >= 20) {
        /*  delay   */
        localDW->is_Ctrl = DHM_IN_Unfold;
        if (rtu_SI_m_LearnSts == Learn_Success) {
          /*  已学习  */
          localDW->is_Unfold = DHM_IN_Step1;
          localDW->temporalCounter_i1 = 0U;

          /*  缓启  */
          *rty_SO_e_MotorCmd = 1U;
          *rty_SO_e_MotorPwm = 60U;
        } else {
          /*  未学习  */
          localDW->is_Unfold = DHM_IN_Start;
          localDW->temporalCounter_i1 = 0U;
          *rty_SO_e_MotorCmd = 1U;
          *rty_SO_e_MotorPwm = 100U;
        }
      }
      break;

     default:
      /* case IN_Unfold: */
      DHM_Unfold(rtu_SI_b_HallStall, rtu_SI_s_CurrentPos, rtu_SI_s_MaxSoftPos,
                 rtu_SI_s_IceBrkPos, rty_SO_e_MotorCmd, rty_SO_e_MotorPwm,
                 rty_SO_b_Error, localDW);
      break;
    }
  }

  /* End of Chart: '<S8>/CtrlLogic' */
}

/* Function for Chart: '<S8>/DoorHndPos' */
static float64 DHM_GetPosSts(float64 CurrentPos, float64 MinSoftPos, float64
  MaxSoftPos)
{
  float64 y;
  if (CurrentPos <= MinSoftPos) {
    y = 1.0;
  } else if (CurrentPos >= MaxSoftPos) {
    y = 0.0;
  } else {
    y = 2.0;
  }

  return y;
}

static uint8 DHM_safe_cast_to_HndPos_Sts_E(uint8 input)
{
  uint8 output;

  /* Initialize output value to default value for HndPos_Sts_E (Hnd_Fold) */
  output = 0U;
  if (input <= 3) {
    /* Set output value to input value if it is a member of HndPos_Sts_E */
    output = input;
  }

  return output;
}

/*
 * System initialize for atomic system:
 *    '<S8>/DoorHndPos'
 *    '<S11>/DoorHndPos'
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
 *    '<S8>/DoorHndPos'
 *    '<S11>/DoorHndPos'
 */
void DHM_DoorHndPos(SInt16 rtu_SI_s_CurrentPos, sint16 rtu_SI_s_MaxPos,
                    Learn_Sts_E rtu_SI_m_LearnSts, HndPos_Sts_E
                    *rty_SO_m_DoorHndPosSts, sint16 *rty_SO_s_MaxSoftPos, sint16
                    *rty_SO_s_MinSoftPos, sint16 *rty_SO_s_IceBrkPos,
                    DW_DoorHndPos_DHM_T *localDW)
{
  /* Chart: '<S8>/DoorHndPos' */
  if (localDW->is_active_c5_DoorHndDriver == 0U) {
    localDW->is_active_c5_DoorHndDriver = 1U;
    if (rtu_SI_m_LearnSts == Learn_Success) {
      float64 tmp;
      *rty_SO_s_MaxSoftPos = (sint16)(rtu_SI_s_MaxPos * 95 / 100);
      *rty_SO_s_MinSoftPos = (sint16)(rtu_SI_s_MaxPos * 5 / 100);
      *rty_SO_s_IceBrkPos = (sint16)(rtu_SI_s_MaxPos * 20 / 100);
      tmp = DHM_GetPosSts((float64)rtu_SI_s_CurrentPos, (float64)*
                          rty_SO_s_MinSoftPos, (float64)*rty_SO_s_MaxSoftPos);
      if (tmp < 2.147483648E+9) {
        if (tmp >= -2.147483648E+9) {
          *rty_SO_m_DoorHndPosSts = DHM_safe_cast_to_HndPos_Sts_E((uint8)(sint32)
            tmp);
        } else {
          *rty_SO_m_DoorHndPosSts = DHM_safe_cast_to_HndPos_Sts_E(0);
        }
      } else {
        *rty_SO_m_DoorHndPosSts = DHM_safe_cast_to_HndPos_Sts_E(MAX_uint8_T);
      }
    } else {
      *rty_SO_m_DoorHndPosSts = Hnd_Unknown;
    }
  } else if (rtu_SI_m_LearnSts == Learn_Success) {
    float64 tmp;
    *rty_SO_s_MaxSoftPos = (sint16)(rtu_SI_s_MaxPos * 95 / 100);
    *rty_SO_s_MinSoftPos = (sint16)(rtu_SI_s_MaxPos * 5 / 100);
    *rty_SO_s_IceBrkPos = (sint16)(rtu_SI_s_MaxPos * 20 / 100);
    tmp = DHM_GetPosSts((float64)rtu_SI_s_CurrentPos, (float64)*
                        rty_SO_s_MinSoftPos, (float64)*rty_SO_s_MaxSoftPos);
    if (tmp < 2.147483648E+9) {
      if (tmp >= -2.147483648E+9) {
        *rty_SO_m_DoorHndPosSts = DHM_safe_cast_to_HndPos_Sts_E((uint8)(sint32)
          tmp);
      } else {
        *rty_SO_m_DoorHndPosSts = DHM_safe_cast_to_HndPos_Sts_E(0);
      }
    } else {
      *rty_SO_m_DoorHndPosSts = DHM_safe_cast_to_HndPos_Sts_E(MAX_uint8_T);
    }
  } else {
    *rty_SO_m_DoorHndPosSts = Hnd_Unknown;
  }

  /* End of Chart: '<S8>/DoorHndPos' */
}

/*
 * System initialize for atomic system:
 *    '<S8>/LearnLogic'
 *    '<S11>/LearnLogic'
 */
void DHM_LearnLogic_Init(uint8 *rty_SO_e_MotorCmd, uint8 *rty_SO_e_MotorPwm,
  boolean *rty_SO_b_CorrectPosToZero, boolean *rty_SO_b_CorrectPosToMax,
  Learn_Sts_E *rty_SO_m_LearnSts, sint16 *rty_SO_s_MaxPos)
{
  *rty_SO_e_MotorCmd = 0U;
  *rty_SO_e_MotorPwm = 0U;
  *rty_SO_b_CorrectPosToZero = false;
  *rty_SO_b_CorrectPosToMax = false;
  *rty_SO_m_LearnSts = Learn_Invalid;
  *rty_SO_s_MaxPos = 0;
}

/*
 * Output and update for atomic system:
 *    '<S8>/LearnLogic'
 *    '<S11>/LearnLogic'
 */
void DHM_LearnLogic(boolean rtu_SI_b_HallStall, Boolean rtu_SI_b_LearnReq,
                    Learn_Sts_E rtu_SI_m_LearnStsFromEE, sint16
                    rtu_SI_s_MaxPosFromEE, SInt16 rtu_SI_s_CurrentPos, uint8
                    *rty_SO_e_MotorCmd, uint8 *rty_SO_e_MotorPwm, boolean
                    *rty_SO_b_CorrectPosToZero, boolean
                    *rty_SO_b_CorrectPosToMax, Learn_Sts_E *rty_SO_m_LearnSts,
                    sint16 *rty_SO_s_MaxPos, DW_LearnLogic_DHM_T *localDW)
{
  if (localDW->temporalCounter_i1 < 255U) {
    localDW->temporalCounter_i1++;
  }

  localDW->SI_b_LearnReq_prev = localDW->SI_b_LearnReq_start;
  localDW->SI_b_LearnReq_start = rtu_SI_b_LearnReq;

  /* Chart: '<S8>/LearnLogic' */
  if (localDW->is_active_c3_DoorHndDriver == 0U) {
    localDW->SI_b_LearnReq_prev = rtu_SI_b_LearnReq;
    localDW->is_active_c3_DoorHndDriver = 1U;
    localDW->is_c3_DoorHndDriver = DHM_IN_PowerOn;
    localDW->temporalCounter_i1 = 0U;
    *rty_SO_m_LearnSts = rtu_SI_m_LearnStsFromEE;
    localDW->SI_e_AutoLearnCount = 0U;
    *rty_SO_s_MaxPos = rtu_SI_s_MaxPosFromEE;
  } else if (localDW->is_c3_DoorHndDriver == DHM_IN_LearnLogic) {
    boolean guard1 = false;
    guard1 = false;
    switch (localDW->is_LearnLogic) {
     case DHM_IN_CorrectMaxPos:
      localDW->is_LearnLogic = DHM_IN_Finished;
      localDW->temporalCounter_i1 = 0U;

      /*  学习成功  */
      *rty_SO_m_LearnSts = Learn_Success;
      break;

     case DHM_IN_CorrectZeroPos:
      if (localDW->temporalCounter_i1 >= 20) {
        localDW->is_LearnLogic = DHM_IN_GotoMaxPos;
        localDW->temporalCounter_i1 = 0U;

        /*  折叠  */
        *rty_SO_e_MotorCmd = 2U;
        *rty_SO_e_MotorPwm = 100U;
      }
      break;

     case DHM_IN_Failed:
      if (localDW->temporalCounter_i1 >= 3) {
        localDW->is_LearnLogic = DHM_IN_Idle_j;
        *rty_SO_b_CorrectPosToZero = false;
        *rty_SO_b_CorrectPosToMax = false;
        *rty_SO_e_MotorCmd = 0U;
        *rty_SO_e_MotorPwm = 0U;
      }
      break;

     case DHM_IN_Finished:
      if (localDW->temporalCounter_i1 >= 3) {
        localDW->is_LearnLogic = DHM_IN_Idle_j;
        *rty_SO_b_CorrectPosToZero = false;
        *rty_SO_b_CorrectPosToMax = false;
        *rty_SO_e_MotorCmd = 0U;
        *rty_SO_e_MotorPwm = 0U;
      }
      break;

     case DHM_IN_GotoMaxPos:
      if (localDW->temporalCounter_i1 >= 200) {
        localDW->is_LearnLogic = DHM_IN_Failed;
        localDW->temporalCounter_i1 = 0U;

        /*  学习失败  */
        *rty_SO_e_MotorCmd = 0U;
        *rty_SO_e_MotorPwm = 0U;
        *rty_SO_m_LearnSts = Learn_Fail;
      } else if (rtu_SI_b_HallStall) {
        localDW->is_LearnLogic = DHM_IN_CorrectMaxPos;

        /*  最大位置点校准  */
        *rty_SO_e_MotorCmd = 0U;
        *rty_SO_e_MotorPwm = 0U;
        *rty_SO_b_CorrectPosToMax = true;
        *rty_SO_s_MaxPos = rtu_SI_s_CurrentPos;
      } else {
        /*  折叠  */
        *rty_SO_e_MotorCmd = 2U;
        *rty_SO_e_MotorPwm = 100U;
      }
      break;

     case DHM_IN_GotoZeroPos:
      if (rtu_SI_b_HallStall) {
        localDW->is_LearnLogic = DHM_IN_CorrectZeroPos;
        localDW->temporalCounter_i1 = 0U;

        /*  零点校准  */
        *rty_SO_e_MotorCmd = 0U;
        *rty_SO_e_MotorPwm = 0U;
        *rty_SO_b_CorrectPosToZero = true;
      } else if (localDW->temporalCounter_i1 >= 200) {
        localDW->is_LearnLogic = DHM_IN_Failed;
        localDW->temporalCounter_i1 = 0U;

        /*  学习失败  */
        *rty_SO_e_MotorCmd = 0U;
        *rty_SO_e_MotorPwm = 0U;
        *rty_SO_m_LearnSts = Learn_Fail;
      } else {
        /*  展开  */
        *rty_SO_e_MotorCmd = 1U;
        *rty_SO_e_MotorPwm = 100U;
      }
      break;

     default:
      /* case IN_Idle: */
      if ((*rty_SO_m_LearnSts != Learn_Success) && (localDW->SI_e_AutoLearnCount
           > 0)) {
        localDW->SI_e_AutoLearnCount--;
        guard1 = true;
      } else if ((localDW->SI_b_LearnReq_prev != localDW->SI_b_LearnReq_start) &&
                 localDW->SI_b_LearnReq_start) {
        guard1 = true;
      }
      break;
    }

    if (guard1) {
      localDW->is_LearnLogic = DHM_IN_GotoZeroPos;
      localDW->temporalCounter_i1 = 0U;

      /*  展开  */
      *rty_SO_e_MotorCmd = 1U;
      *rty_SO_e_MotorPwm = 100U;
    }

    /* case IN_PowerOn: */
  } else if (localDW->temporalCounter_i1 >= 50) {
    /*  500ms内读取E2学习状态和最大hall位置  */
    localDW->is_c3_DoorHndDriver = DHM_IN_LearnLogic;
    localDW->is_LearnLogic = DHM_IN_Idle_j;
    *rty_SO_b_CorrectPosToZero = false;
    *rty_SO_b_CorrectPosToMax = false;
    *rty_SO_e_MotorCmd = 0U;
    *rty_SO_e_MotorPwm = 0U;
  } else {
    *rty_SO_m_LearnSts = rtu_SI_m_LearnStsFromEE;
    localDW->SI_e_AutoLearnCount = 0U;
    *rty_SO_s_MaxPos = rtu_SI_s_MaxPosFromEE;
  }

  /* End of Chart: '<S8>/LearnLogic' */
}

/*
 * System initialize for atomic system:
 *    '<S8>/MotorLogic'
 *    '<S11>/MotorLogic'
 */
void DHM_MotorLogic_Init(uint8 *rty_SO_e_MotorCmd, boolean *rty_SO_b_MotorA,
  boolean *rty_SO_b_MotorB, uint8 *rty_SO_e_MotorPwm)
{
  *rty_SO_e_MotorCmd = 0U;
  *rty_SO_b_MotorA = false;
  *rty_SO_b_MotorB = false;
  *rty_SO_e_MotorPwm = 0U;
}

/*
 * Output and update for atomic system:
 *    '<S8>/MotorLogic'
 *    '<S11>/MotorLogic'
 */
void DHM_MotorLogic(uint8 rtu_SI_e_LearnMotorCmd, uint8 rtu_SI_e_LearnMotorPwm,
                    uint8 rtu_SI_e_CtrlMotorCmd, uint8 rtu_SI_e_CtrlMotorPwm,
                    uint8 *rty_SO_e_MotorCmd, boolean *rty_SO_b_MotorA, uint8
                    *rty_SO_e_MotorPwm, DW_MotorLogic_DHM_T *localDW)
{
  /* Chart: '<S8>/MotorLogic' */
  if (localDW->is_active_c4_DoorHndDriver == 0U) {
    localDW->is_active_c4_DoorHndDriver = 1U;
    switch (rtu_SI_e_LearnMotorCmd) {
     case 1:
      *rty_SO_b_MotorA = false;
      *rty_SO_e_MotorCmd = 1U;
      *rty_SO_e_MotorPwm = rtu_SI_e_LearnMotorPwm;
      break;

     case 2:
      *rty_SO_b_MotorA = true;
      *rty_SO_e_MotorCmd = 2U;
      *rty_SO_e_MotorPwm = rtu_SI_e_LearnMotorPwm;
      break;

     default:
      switch (rtu_SI_e_CtrlMotorCmd) {
       case 1:
        *rty_SO_b_MotorA = false;
        *rty_SO_e_MotorCmd = 1U;
        *rty_SO_e_MotorPwm = rtu_SI_e_CtrlMotorPwm;
        break;

       case 2:
        *rty_SO_b_MotorA = true;
        *rty_SO_e_MotorCmd = 2U;
        *rty_SO_e_MotorPwm = rtu_SI_e_CtrlMotorPwm;
        break;

       default:
        *rty_SO_b_MotorA = false;
        *rty_SO_e_MotorCmd = 0U;
        *rty_SO_e_MotorPwm = 0U;
        break;
      }
      break;
    }
  }

  /* End of Chart: '<S8>/MotorLogic' */
}

/*
 * System initialize for atomic system:
 *    '<S8>/Stall'
 *    '<S11>/Stall'
 */
void DHM_Stall_Init(boolean *rty_SO_b_HallStall)
{
  *rty_SO_b_HallStall = false;
}

/*
 * Output and update for atomic system:
 *    '<S8>/Stall'
 *    '<S11>/Stall'
 */
void DHM_Stall(SInt16 rtu_SI_s_CurrentPos, uint8 rtu_SI_e_MotorCmd, boolean
               *rty_SO_b_HallStall, DW_Stall_DHM_T *localDW)
{
  if (localDW->temporalCounter_i1 < 63U) {
    localDW->temporalCounter_i1++;
  }

  /* Chart: '<S8>/Stall' */
  if (localDW->is_active_c2_DoorHndDriver == 0U) {
    localDW->is_active_c2_DoorHndDriver = 1U;
    localDW->is_Stall_Handler = DHM_IN_Idle_a;
    *rty_SO_b_HallStall = false;
  } else {
    switch (localDW->is_Stall_Handler) {
     case DHM_IN_Checking:
      if (rtu_SI_e_MotorCmd == 0) {
        localDW->is_Stall_Handler = DHM_IN_Idle_a;
        *rty_SO_b_HallStall = false;
      } else if ((rtu_SI_s_CurrentPos - localDW->SL_s_CurrentPos_Old > 5) ||
                 (localDW->SL_s_CurrentPos_Old - rtu_SI_s_CurrentPos > 5)) {
        localDW->is_Stall_Handler = DHM_IN_Checking;
        localDW->temporalCounter_i1 = 0U;
        localDW->SL_s_CurrentPos_Old = rtu_SI_s_CurrentPos;
      } else if (localDW->temporalCounter_i1 >= 40) {
        localDW->is_Stall_Handler = DHM_IN_Stall;
        localDW->temporalCounter_i1 = 0U;
        *rty_SO_b_HallStall = true;
      }
      break;

     case DHM_IN_Idle_a:
      if (rtu_SI_e_MotorCmd != 0) {
        localDW->is_Stall_Handler = DHM_IN_Checking;
        localDW->temporalCounter_i1 = 0U;
        localDW->SL_s_CurrentPos_Old = rtu_SI_s_CurrentPos;
      }
      break;

     default:
      /* case IN_Stall: */
      if (localDW->temporalCounter_i1 >= 3) {
        localDW->is_Stall_Handler = DHM_IN_Idle_a;
        *rty_SO_b_HallStall = false;
      }
      break;
    }
  }

  /* End of Chart: '<S8>/Stall' */
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
  if (localDW->temporalCounter_i1 < 7U) {
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
    localDW->is_Unfold = DHM_IN_Idle_ai;
    *rty_SO_b_HndUnfoldReq = false;
    localDW->is_Fold = DHM_IN_Idle_ai;
    *rty_SO_b_HndFoldReq = false;
  } else {
    switch (localDW->is_Unfold) {
     case DHM_IN_CrashUnfoldReq:
      if (localDW->temporalCounter_i1 >= 5) {
        localDW->is_Unfold = DHM_IN_Idle_ai;
        *rty_SO_b_HndUnfoldReq = false;
      }
      break;

     case DHM_IN_Idle_ai:
      if ((rtu_SI_e_EspVehSpd < 15) && (rtu_SI_b_DoorOpen ||
           (rtu_SI_m_DoorLockSts == Door_Unlock)) && (rtu_SI_m_HndPosSts !=
           Hnd_Unfold)) {
        localDW->is_Unfold = DHM_IN_NormalUnfoldReq;
        localDW->temporalCounter_i1 = 0U;
        *rty_SO_b_HndUnfoldReq = true;
      } else if ((localDW->SI_b_CrashOutpSts_prev !=
                  localDW->SI_b_CrashOutpSts_start) &&
                 localDW->SI_b_CrashOutpSts_start && (rtu_SI_m_HndPosSts !=
                  Hnd_Unfold)) {
        localDW->is_Unfold = DHM_IN_CrashUnfoldReq;
        localDW->temporalCounter_i1 = 0U;
        *rty_SO_b_HndUnfoldReq = true;
      } else {
        *rty_SO_b_HndUnfoldReq = false;
      }
      break;

     default:
      /* case IN_NormalUnfoldReq: */
      if ((rtu_SI_e_EspVehSpd >= 15) || ((!rtu_SI_b_DoorOpen) &&
           (rtu_SI_m_DoorLockSts != Door_Unlock)) || (rtu_SI_m_HndPosSts ==
           Hnd_Unfold)) {
        localDW->is_Unfold = DHM_IN_Idle_ai;
        *rty_SO_b_HndUnfoldReq = false;
      } else {
        *rty_SO_b_HndUnfoldReq = ((localDW->temporalCounter_i1 != 5) &&
          (*rty_SO_b_HndUnfoldReq));
      }
      break;
    }

    if (localDW->is_Fold == DHM_IN_FoldReq) {
      if ((rtu_SI_m_DoorLockSts != Door_Lock) || (rtu_SI_m_HndPosSts == Hnd_Fold))
      {
        localDW->is_Fold = DHM_IN_Idle_ai;
        *rty_SO_b_HndFoldReq = false;
      } else {
        *rty_SO_b_HndFoldReq = ((localDW->temporalCounter_i2 != 5) &&
          (*rty_SO_b_HndFoldReq));
      }

      /* case IN_Idle: */
    } else if ((rtu_SI_m_DoorLockSts == Door_Lock) && (rtu_SI_m_HndPosSts !=
                Hnd_Fold)) {
      localDW->is_Fold = DHM_IN_FoldReq;
      localDW->temporalCounter_i2 = 0U;
      *rty_SO_b_HndFoldReq = true;
    } else {
      *rty_SO_b_HndFoldReq = false;
    }
  }

  /* End of Chart: '<S3>/FLDoorHndReq' */
}

/* Model step function for TID1 */
void DHM_Step(void)                    /* Explicit Task: DHM_Step */
{
  /* local block i/o variables */
  UInt8 rtb_TmpSignalConversionAtVeOUT_;
  Boolean rtb_TmpSignalConversionAtVbOUT_;
  HndPos_Sts_E rtb_SO_m_DoorHndPosSts;
  HndPos_Sts_E rtb_SO_m_DoorHndPosSts_i;
  UInt8 tmpRead;
  UInt8 tmpRead_0;
  UInt8 tmpRead_1;
  UInt8 tmpRead_2;
  UInt8 tmpRead_3;
  UInt8 tmpRead_4;
  UInt8 tmpRead_5;
  UInt8 tmpRead_6;
  uint8 SO_e_MotorPwm_k;
  boolean SO_b_CorrectPosToMax_b;
  boolean SO_b_CorrectPosToZero_j;

  /* SignalConversion generated from: '<S2>/VbINP_HWA_DoorHandleLrnReq_flg_VbINP_HWA_DoorHandleLrnReq_flg_read' incorporates:
   *  Inport: '<Root>/VbINP_HWA_DoorHandleLrnReq_flg_VbINP_HWA_DoorHandleLrnReq_flg'
   */
  (void)Rte_Read_VbINP_HWA_DoorHandleLrnReq_flg_VbINP_HWA_DoorHandleLrnReq_flg
    (&DHM_B.VbINP_HWA_DoorHandleLrnReq_flg_);

  /* Inport: '<Root>/VeINP_EPRM_RLDoorHandleLrnStsEE_sig_VeINP_EPRM_RLDoorHandleLrnStsEE_sig' */
  (void)
    Rte_Read_VeINP_EPRM_RLDoorHandleLrnStsEE_sig_VeINP_EPRM_RLDoorHandleLrnStsEE_sig
    (&SO_e_MotorPwm_k);

  /* Inport: '<Root>/VeINP_EPRM_FLDoorHandleLrnStsEE_sig_VeINP_EPRM_FLDoorHandleLrnStsEE_sig' */
  (void)
    Rte_Read_VeINP_EPRM_FLDoorHandleLrnStsEE_sig_VeINP_EPRM_FLDoorHandleLrnStsEE_sig
    (&tmpRead_6);

  /* Inport: '<Root>/VeINP_CAN_RHRDoorSts_sig_VeINP_CAN_RHRDoorSts_sig' */
  (void)Rte_Read_VeINP_CAN_RHRDoorSts_sig_VeINP_CAN_RHRDoorSts_sig(&tmpRead_5);

  /* Inport: '<Root>/VeINP_CAN_RHFDoorSts_sig_VeINP_CAN_RHFDoorSts_sig' */
  (void)Rte_Read_VeINP_CAN_RHFDoorSts_sig_VeINP_CAN_RHFDoorSts_sig(&tmpRead_4);

  /* Inport: '<Root>/VeOUT_SP_LHRdoorSts_sig_VeOUT_SP_LHRdoorSts_sig' */
  (void)Rte_Read_VeOUT_SP_LHRdoorSts_sig_VeOUT_SP_LHRdoorSts_sig(&tmpRead_3);

  /* Inport: '<Root>/VeOUT_SP_LHFdoorSts_sig_VeOUT_SP_LHFdoorSts_sig' */
  (void)Rte_Read_VeOUT_SP_LHFdoorSts_sig_VeOUT_SP_LHFdoorSts_sig(&tmpRead_2);

  /* Inport: '<Root>/VeINP_CAN_RRDoorHandleSts_sig_VeINP_CAN_RRDoorHandleSts_sig' */
  (void)Rte_Read_VeINP_CAN_RRDoorHandleSts_sig_VeINP_CAN_RRDoorHandleSts_sig
    (&tmpRead_1);

  /* Inport: '<Root>/VeINP_CAN_FRDoorHandleSts_sig_VeINP_CAN_FRDoorHandleSts_sig' */
  (void)Rte_Read_VeINP_CAN_FRDoorHandleSts_sig_VeINP_CAN_FRDoorHandleSts_sig
    (&tmpRead_0);

  /* Inport: '<Root>/VeOUT_DLK_LHFDoorLockSts_sig_VeOUT_DLK_LHFDoorLockSts_sig' */
  (void)Rte_Read_VeOUT_DLK_LHFDoorLockSts_sig_VeOUT_DLK_LHFDoorLockSts_sig
    (&tmpRead);

  /* RootInportFunctionCallGenerator generated from: '<Root>/DHM_Step' incorporates:
   *  SubSystem: '<Root>/DHM_Step_sys'
   */
  /* DataStoreWrite: '<S3>/Data Store Write' incorporates:
   *  Constant: '<S3>/Constant'
   */
  DHM_DW.E03_DHM_L = 0U;

  /* Outport: '<Root>/VeOUT_DHM_FRHandleFoldedStatus_sig_VeOUT_DHM_FRHandleFoldedStatus_sig' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion1'
   *  DataTypeConversion: '<S3>/Data Type Conversion4'
   */
  (void)
    Rte_Write_VeOUT_DHM_FRHandleFoldedStatus_sig_VeOUT_DHM_FRHandleFoldedStatus_sig
    (tmpRead_0);

  /* SignalConversion generated from: '<S2>/VsINP_HWA_DriverHandleHall_sig_VsINP_HWA_DriverHandleHall_sig_read' incorporates:
   *  Inport: '<Root>/VsINP_HWA_DriverHandleHall_sig_VsINP_HWA_DriverHandleHall_sig'
   */
  (void)Rte_Read_VsINP_HWA_DriverHandleHall_sig_VsINP_HWA_DriverHandleHall_sig
    (&DHM_B.TmpSignalConversionAtVsINP_HWA_);

  /* Chart: '<S8>/LearnLogic' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion8'
   *  UnitDelay: '<S8>/Unit Delay'
   */
  DHM_LearnLogic(DHM_B.SO_b_HallStall_m, DHM_B.VbINP_HWA_DoorHandleLrnReq_flg_,
                 tmpRead_6, 0, DHM_B.TmpSignalConversionAtVsINP_HWA_,
                 &DHM_B.SO_e_MotorCmd_j, &DHM_B.SO_e_MotorPwm_m,
                 &SO_b_CorrectPosToZero_j, &SO_b_CorrectPosToMax_b,
                 &DHM_B.SO_m_LearnSts_b, &DHM_B.SO_s_MaxPos_n,
                 &DHM_DW.sf_LearnLogic);

  /* SignalConversion generated from: '<S2>/VsINP_HWA_RLHandleHall_sig_VsINP_HWA_RLHandleHall_sig_read' incorporates:
   *  Inport: '<Root>/VsINP_HWA_RLHandleHall_sig_VsINP_HWA_RLHandleHall_sig'
   */
  (void)Rte_Read_VsINP_HWA_RLHandleHall_sig_VsINP_HWA_RLHandleHall_sig
    (&DHM_B.TmpSignalConversionAtVsINP_HW_a);

  /* Chart: '<S11>/LearnLogic' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion9'
   *  UnitDelay: '<S11>/Unit Delay'
   */
  DHM_LearnLogic(DHM_B.SO_b_HallStall, DHM_B.VbINP_HWA_DoorHandleLrnReq_flg_,
                 SO_e_MotorPwm_k, 0, DHM_B.TmpSignalConversionAtVsINP_HW_a,
                 &DHM_B.SO_e_MotorCmd_a, &DHM_B.SO_e_MotorPwm_e,
                 &SO_b_CorrectPosToZero_j, &SO_b_CorrectPosToMax_b,
                 &DHM_B.SO_m_LearnSts, &DHM_B.SO_s_MaxPos,
                 &DHM_DW.sf_LearnLogic_d);

  /* Outport: '<Root>/VeOUT_DHM_RRHandleFoldedStatus_sig_VeOUT_DHM_RRHandleFoldedStatus_sig' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion2'
   *  DataTypeConversion: '<S3>/Data Type Conversion6'
   */
  (void)
    Rte_Write_VeOUT_DHM_RRHandleFoldedStatus_sig_VeOUT_DHM_RRHandleFoldedStatus_sig
    (tmpRead_1);

  /* Chart: '<S8>/DoorHndPos' incorporates:
   *  UnitDelay: '<S8>/Unit Delay5'
   */
  DHM_DoorHndPos(DHM_B.TmpSignalConversionAtVsINP_HWA_, DHM_DW.UnitDelay5_DSTATE,
                 DHM_B.SO_m_LearnSts_b, &rtb_SO_m_DoorHndPosSts_i,
                 &DHM_B.SO_s_MaxSoftPos_k, &DHM_B.SO_s_MinSoftPos_n,
                 &DHM_B.SO_s_IceBrkPos_k, &DHM_DW.sf_DoorHndPos);

  /* Chart: '<S11>/DoorHndPos' incorporates:
   *  UnitDelay: '<S11>/Unit Delay5'
   */
  DHM_DoorHndPos(DHM_B.TmpSignalConversionAtVsINP_HW_a,
                 DHM_DW.UnitDelay5_DSTATE_h, DHM_B.SO_m_LearnSts,
                 &rtb_SO_m_DoorHndPosSts, &DHM_B.SO_s_MaxSoftPos,
                 &DHM_B.SO_s_MinSoftPos, &DHM_B.SO_s_IceBrkPos,
                 &DHM_DW.sf_DoorHndPos_m);

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

  /* Logic: '<S3>/Logical Operator1' incorporates:
   *  Constant: '<S4>/Constant'
   *  Constant: '<S5>/Constant'
   *  Constant: '<S6>/Constant'
   *  Constant: '<S7>/Constant'
   *  RelationalOperator: '<S4>/Compare'
   *  RelationalOperator: '<S5>/Compare'
   *  RelationalOperator: '<S6>/Compare'
   *  RelationalOperator: '<S7>/Compare'
   */
  SO_b_CorrectPosToZero_j = ((tmpRead_2 > 0) || (tmpRead_3 > 0) || (tmpRead_4 >
    0) || (tmpRead_5 > 0));

  /* Chart: '<S3>/FLDoorHndReq' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion7'
   */
  DHM_FLDoorHndReq(rtb_TmpSignalConversionAtVbOUT_,
                   rtb_TmpSignalConversionAtVeOUT_, SO_b_CorrectPosToZero_j,
                   tmpRead, rtb_SO_m_DoorHndPosSts_i, &DHM_B.SO_b_HndUnfoldReq_j,
                   &DHM_B.SO_b_HndFoldReq_dm, &DHM_DW.sf_FLDoorHndReq);

  /* Chart: '<S8>/CtrlLogic' incorporates:
   *  UnitDelay: '<S8>/Unit Delay4'
   */
  DHM_CtrlLogic(DHM_DW.UnitDelay4_DSTATE, DHM_B.TmpSignalConversionAtVsINP_HWA_,
                DHM_B.SO_s_MaxSoftPos_k, DHM_B.SO_s_MinSoftPos_n,
                DHM_B.SO_s_IceBrkPos_k, DHM_B.SO_b_HndFoldReq_dm,
                DHM_B.SO_b_HndUnfoldReq_j, DHM_B.SO_m_LearnSts_b,
                &DHM_B.SO_e_MotorCmd_g, &DHM_B.SO_e_MotorPwm_ew,
                &SO_b_CorrectPosToMax_b, &DHM_DW.sf_CtrlLogic);

  /* Chart: '<S8>/MotorLogic' */
  DHM_MotorLogic(DHM_B.SO_e_MotorCmd_j, DHM_B.SO_e_MotorPwm_m,
                 DHM_B.SO_e_MotorCmd_g, DHM_B.SO_e_MotorPwm_ew,
                 &DHM_B.SO_e_MotorCmd_c, &DHM_B.SO_b_MotorA_k, &SO_e_MotorPwm_k,
                 &DHM_DW.sf_MotorLogic);

  /* Chart: '<S8>/Stall' incorporates:
   *  UnitDelay: '<S8>/Unit Delay1'
   */
  DHM_Stall(DHM_B.TmpSignalConversionAtVsINP_HWA_, DHM_DW.UnitDelay1_DSTATE,
            &DHM_B.SO_b_HallStall_m, &DHM_DW.sf_Stall);

  /* Chart: '<S3>/FRDoorHndReq' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion4'
   *  DataTypeConversion: '<S3>/Data Type Conversion7'
   */
  DHM_FLDoorHndReq(rtb_TmpSignalConversionAtVbOUT_,
                   rtb_TmpSignalConversionAtVeOUT_, SO_b_CorrectPosToZero_j,
                   tmpRead, tmpRead_0, &DHM_B.SO_b_HndUnfoldReq_k,
                   &DHM_B.SO_b_HndFoldReq_d, &DHM_DW.sf_FRDoorHndReq);

  /* Chart: '<S3>/RLDoorHndReq' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion7'
   */
  DHM_FLDoorHndReq(rtb_TmpSignalConversionAtVbOUT_,
                   rtb_TmpSignalConversionAtVeOUT_, SO_b_CorrectPosToZero_j,
                   tmpRead, rtb_SO_m_DoorHndPosSts, &DHM_B.SO_b_HndUnfoldReq_a,
                   &DHM_B.SO_b_HndFoldReq_a, &DHM_DW.sf_RLDoorHndReq);

  /* Chart: '<S11>/CtrlLogic' incorporates:
   *  UnitDelay: '<S11>/Unit Delay4'
   */
  DHM_CtrlLogic(DHM_DW.UnitDelay4_DSTATE_n,
                DHM_B.TmpSignalConversionAtVsINP_HW_a, DHM_B.SO_s_MaxSoftPos,
                DHM_B.SO_s_MinSoftPos, DHM_B.SO_s_IceBrkPos,
                DHM_B.SO_b_HndUnfoldReq_a, DHM_B.SO_b_HndFoldReq_a,
                DHM_B.SO_m_LearnSts, &DHM_B.SO_e_MotorCmd_f,
                &DHM_B.SO_e_MotorPwm_g, &SO_b_CorrectPosToMax_b,
                &DHM_DW.sf_CtrlLogic_g);

  /* Chart: '<S11>/MotorLogic' */
  DHM_MotorLogic(DHM_B.SO_e_MotorCmd_a, DHM_B.SO_e_MotorPwm_e,
                 DHM_B.SO_e_MotorCmd_f, DHM_B.SO_e_MotorPwm_g,
                 &DHM_B.SO_e_MotorCmd, &DHM_B.SO_b_MotorA, &SO_e_MotorPwm_k,
                 &DHM_DW.sf_MotorLogic_l);

  /* Chart: '<S11>/Stall' incorporates:
   *  UnitDelay: '<S11>/Unit Delay1'
   */
  DHM_Stall(DHM_B.TmpSignalConversionAtVsINP_HW_a, DHM_DW.UnitDelay1_DSTATE_f,
            &DHM_B.SO_b_HallStall, &DHM_DW.sf_Stall_m);

  /* Chart: '<S3>/RRDoorHndReq' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion6'
   *  DataTypeConversion: '<S3>/Data Type Conversion7'
   */
  DHM_FLDoorHndReq(rtb_TmpSignalConversionAtVbOUT_,
                   rtb_TmpSignalConversionAtVeOUT_, SO_b_CorrectPosToZero_j,
                   tmpRead, tmpRead_1, &DHM_B.SO_b_HndUnfoldReq,
                   &DHM_B.SO_b_HndFoldReq, &DHM_DW.sf_RRDoorHndReq);

  /* Update for UnitDelay: '<S8>/Unit Delay5' */
  DHM_DW.UnitDelay5_DSTATE = DHM_B.SO_s_MaxPos_n;

  /* Update for UnitDelay: '<S11>/Unit Delay5' */
  DHM_DW.UnitDelay5_DSTATE_h = DHM_B.SO_s_MaxPos;

  /* Update for UnitDelay: '<S8>/Unit Delay4' */
  DHM_DW.UnitDelay4_DSTATE = DHM_B.SO_b_HallStall_m;

  /* Update for UnitDelay: '<S8>/Unit Delay1' */
  DHM_DW.UnitDelay1_DSTATE = DHM_B.SO_e_MotorCmd_c;

  /* Update for UnitDelay: '<S11>/Unit Delay4' */
  DHM_DW.UnitDelay4_DSTATE_n = DHM_B.SO_b_HallStall;

  /* Update for UnitDelay: '<S11>/Unit Delay1' */
  DHM_DW.UnitDelay1_DSTATE_f = DHM_B.SO_e_MotorCmd;

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/DHM_Step' */

  /* RootInportFunctionCallGenerator generated from: '<Root>/DHM_Step' incorporates:
   *  SubSystem: '<Root>/DHM_Step_sys'
   */
  /* Outport: '<Root>/VeOUT_DHM_FLHandleFoldedStatus_sig_VeOUT_DHM_FLHandleFoldedStatus_sig' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion3'
   */
  (void)
    Rte_Write_VeOUT_DHM_FLHandleFoldedStatus_sig_VeOUT_DHM_FLHandleFoldedStatus_sig
    (rtb_SO_m_DoorHndPosSts_i);

  /* Outport: '<Root>/VeOUT_DHM_RLHandleFoldedStatus_sig_VeOUT_DHM_RLHandleFoldedStatus_sig' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion5'
   */
  (void)
    Rte_Write_VeOUT_DHM_RLHandleFoldedStatus_sig_VeOUT_DHM_RLHandleFoldedStatus_sig
    (rtb_SO_m_DoorHndPosSts);

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/DHM_Step' */

  /* Outport: '<Root>/VeOUT_DHM_FRDoorHandleReq_sig_VeOUT_DHM_FRDoorHandleReq_sig' */
  (void)Rte_Write_VeOUT_DHM_FRDoorHandleReq_sig_VeOUT_DHM_FRDoorHandleReq_sig(0U);

  /* Outport: '<Root>/VeOUT_DHM_RRDoorHandleReq_sig_VeOUT_DHM_RRDoorHandleReq_sig' */
  (void)Rte_Write_VeOUT_DHM_RRDoorHandleReq_sig_VeOUT_DHM_RRDoorHandleReq_sig(0U);

  /* Outport: '<Root>/VbOUT_DHM_FLHadUnfold_flg_VbOUT_DHM_FLHadUnfold_flg' */
  (void)Rte_Write_VbOUT_DHM_FLHadUnfold_flg_VbOUT_DHM_FLHadUnfold_flg
    (DHM_B.SO_b_MotorA_k);

  /* Outport: '<Root>/VbOUT_DHM_FLHadFold_flg_VbOUT_DHM_FLHadFold_flg' */
  (void)Rte_Write_VbOUT_DHM_FLHadFold_flg_VbOUT_DHM_FLHadFold_flg
    (DHM_B.SO_b_MotorB_e);

  /* Outport: '<Root>/VbOUT_DHM_RLHandleUnfold_flg_VbOUT_DHM_RLHandleUnfold_flg' */
  (void)Rte_Write_VbOUT_DHM_RLHandleUnfold_flg_VbOUT_DHM_RLHandleUnfold_flg
    (DHM_B.SO_b_MotorA);

  /* Outport: '<Root>/VbOUT_DHM_RLHandleFold_flg_VbOUT_DHM_RLHandleFold_flg' */
  (void)Rte_Write_VbOUT_DHM_RLHandleFold_flg_VbOUT_DHM_RLHandleFold_flg
    (DHM_B.SO_b_MotorB);

  /* Outport: '<Root>/VsINP_DHM_FLDoorHandleEE_sig_VsINP_DHM_FLDoorHandleEE_sig' */
  (void)Rte_Write_VsINP_DHM_FLDoorHandleEE_sig_VsINP_DHM_FLDoorHandleEE_sig
    (DHM_B.SO_s_MaxPos_n);

  /* Outport: '<Root>/VsINP_DHM_RLDoorHandleEE_sig_VsINP_DHM_RLDoorHandleEE_sig' */
  (void)Rte_Write_VsINP_DHM_RLDoorHandleEE_sig_VsINP_DHM_RLDoorHandleEE_sig
    (DHM_B.SO_s_MaxPos);

  /* Outport: '<Root>/VeOUT_DHM_DoorHandleLrnSts_sig_VeOUT_DHM_DoorHandleLrnSts_sig' */
  (void)Rte_Write_VeOUT_DHM_DoorHandleLrnSts_sig_VeOUT_DHM_DoorHandleLrnSts_sig
    (0U);

  /* RootInportFunctionCallGenerator generated from: '<Root>/DHM_Step' incorporates:
   *  SubSystem: '<Root>/DHM_Step_sys'
   */
  /* Outport: '<Root>/VeOUT_DHM_FLDoorHandleLrnStsEE_sig_VeOUT_DHM_FLDoorHandleLrnStsEE_sig' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion10'
   */
  (void)
    Rte_Write_VeOUT_DHM_FLDoorHandleLrnStsEE_sig_VeOUT_DHM_FLDoorHandleLrnStsEE_sig
    (DHM_B.SO_m_LearnSts_b);

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
    HndPos_Sts_E rtb_SO_m_DoorHndPosSts;
    HndPos_Sts_E rtb_SO_m_DoorHndPosSts_i;
    uint8 SO_e_MotorPwm_k;
    boolean SO_b_CorrectPosToMax_b;
    boolean SO_b_Error_f;

    /* SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/DHM_Step' incorporates:
     *  SubSystem: '<Root>/DHM_Step_sys'
     */

    /* SystemInitialize for Chart: '<S8>/CtrlLogic' */
    DHM_CtrlLogic_Init(&DHM_B.SO_e_MotorCmd_g, &DHM_B.SO_e_MotorPwm_ew,
                       &SO_b_Error_f);

    /* SystemInitialize for Chart: '<S8>/DoorHndPos' */
    DHM_DoorHndPos_Init(&rtb_SO_m_DoorHndPosSts_i, &DHM_B.SO_s_MaxSoftPos_k,
                        &DHM_B.SO_s_MinSoftPos_n, &DHM_B.SO_s_IceBrkPos_k);

    /* SystemInitialize for Chart: '<S8>/LearnLogic' */
    DHM_LearnLogic_Init(&DHM_B.SO_e_MotorCmd_j, &DHM_B.SO_e_MotorPwm_m,
                        &SO_b_Error_f, &SO_b_CorrectPosToMax_b,
                        &DHM_B.SO_m_LearnSts_b, &DHM_B.SO_s_MaxPos_n);

    /* SystemInitialize for Chart: '<S8>/MotorLogic' */
    DHM_MotorLogic_Init(&DHM_B.SO_e_MotorCmd_c, &DHM_B.SO_b_MotorA_k,
                        &DHM_B.SO_b_MotorB_e, &SO_e_MotorPwm_k);

    /* SystemInitialize for Chart: '<S8>/Stall' */
    DHM_Stall_Init(&DHM_B.SO_b_HallStall_m);

    /* SystemInitialize for Chart: '<S3>/FLDoorHndReq' */
    DHM_FLDoorHndReq_Init(&DHM_B.SO_b_HndUnfoldReq_j, &DHM_B.SO_b_HndFoldReq_dm);

    /* SystemInitialize for Chart: '<S3>/FRDoorHndReq' */
    DHM_FLDoorHndReq_Init(&DHM_B.SO_b_HndUnfoldReq_k, &DHM_B.SO_b_HndFoldReq_d);

    /* SystemInitialize for Chart: '<S11>/CtrlLogic' */
    DHM_CtrlLogic_Init(&DHM_B.SO_e_MotorCmd_f, &DHM_B.SO_e_MotorPwm_g,
                       &SO_b_Error_f);

    /* SystemInitialize for Chart: '<S11>/DoorHndPos' */
    DHM_DoorHndPos_Init(&rtb_SO_m_DoorHndPosSts, &DHM_B.SO_s_MaxSoftPos,
                        &DHM_B.SO_s_MinSoftPos, &DHM_B.SO_s_IceBrkPos);

    /* SystemInitialize for Chart: '<S11>/LearnLogic' */
    DHM_LearnLogic_Init(&DHM_B.SO_e_MotorCmd_a, &DHM_B.SO_e_MotorPwm_e,
                        &SO_b_Error_f, &SO_b_CorrectPosToMax_b,
                        &DHM_B.SO_m_LearnSts, &DHM_B.SO_s_MaxPos);

    /* SystemInitialize for Chart: '<S11>/MotorLogic' */
    DHM_MotorLogic_Init(&DHM_B.SO_e_MotorCmd, &DHM_B.SO_b_MotorA,
                        &DHM_B.SO_b_MotorB, &SO_e_MotorPwm_k);

    /* SystemInitialize for Chart: '<S11>/Stall' */
    DHM_Stall_Init(&DHM_B.SO_b_HallStall);

    /* SystemInitialize for Chart: '<S3>/RLDoorHndReq' */
    DHM_FLDoorHndReq_Init(&DHM_B.SO_b_HndUnfoldReq_a, &DHM_B.SO_b_HndFoldReq_a);

    /* SystemInitialize for Chart: '<S3>/RRDoorHndReq' */
    DHM_FLDoorHndReq_Init(&DHM_B.SO_b_HndUnfoldReq, &DHM_B.SO_b_HndFoldReq);

    /* End of SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/DHM_Step' */

    /* SystemInitialize for Outport: '<Root>/VbOUT_DHM_FLHadUnfold_flg_VbOUT_DHM_FLHadUnfold_flg' */
    (void)Rte_Write_VbOUT_DHM_FLHadUnfold_flg_VbOUT_DHM_FLHadUnfold_flg
      (DHM_B.SO_b_MotorA_k);

    /* SystemInitialize for Outport: '<Root>/VbOUT_DHM_FLHadFold_flg_VbOUT_DHM_FLHadFold_flg' */
    (void)Rte_Write_VbOUT_DHM_FLHadFold_flg_VbOUT_DHM_FLHadFold_flg
      (DHM_B.SO_b_MotorB_e);

    /* SystemInitialize for Outport: '<Root>/VbOUT_DHM_RLHandleUnfold_flg_VbOUT_DHM_RLHandleUnfold_flg' */
    (void)Rte_Write_VbOUT_DHM_RLHandleUnfold_flg_VbOUT_DHM_RLHandleUnfold_flg
      (DHM_B.SO_b_MotorA);

    /* SystemInitialize for Outport: '<Root>/VbOUT_DHM_RLHandleFold_flg_VbOUT_DHM_RLHandleFold_flg' */
    (void)Rte_Write_VbOUT_DHM_RLHandleFold_flg_VbOUT_DHM_RLHandleFold_flg
      (DHM_B.SO_b_MotorB);

    /* SystemInitialize for Outport: '<Root>/VsINP_DHM_FLDoorHandleEE_sig_VsINP_DHM_FLDoorHandleEE_sig' */
    (void)Rte_Write_VsINP_DHM_FLDoorHandleEE_sig_VsINP_DHM_FLDoorHandleEE_sig
      (DHM_B.SO_s_MaxPos_n);

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
