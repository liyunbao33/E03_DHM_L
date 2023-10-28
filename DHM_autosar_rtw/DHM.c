/*
 * File: DHM.c
 *
 * Code generated for Simulink model 'DHM'.
 *
 * Model version                  : 1.430
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Sat Oct 28 12:28:23 2023
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

/* Named constants for Chart: '<S16>/CtrlLogic' */
#define DHM_IN_Check                   ((uint8)1U)
#define DHM_IN_Fold                    ((uint8)1U)
#define DHM_IN_IceBrk                  ((uint8)2U)
#define DHM_IN_IceBrkSuccess           ((uint8)3U)
#define DHM_IN_Icebreak                ((uint8)1U)
#define DHM_IN_Idle                    ((uint8)2U)
#define DHM_IN_Interrupt1              ((uint8)3U)
#define DHM_IN_Interrupt2              ((uint8)4U)
#define DHM_IN_NO_ACTIVE_CHILD         ((uint8)0U)
#define DHM_IN_Start                   ((uint8)2U)
#define DHM_IN_Start_f                 ((uint8)1U)
#define DHM_IN_Step1                   ((uint8)3U)
#define DHM_IN_Step1_h                 ((uint8)2U)
#define DHM_IN_Step2                   ((uint8)4U)
#define DHM_IN_Step2_h                 ((uint8)3U)
#define DHM_IN_Step3                   ((uint8)5U)
#define DHM_IN_Step3_i                 ((uint8)4U)
#define DHM_IN_Stop                    ((uint8)6U)
#define DHM_IN_Stop_e                  ((uint8)5U)
#define DHM_IN_Unfold                  ((uint8)5U)

/* Named constants for Chart: '<S16>/LearnLogic' */
#define DHM_IN_Check_m                 ((uint8)1U)
#define DHM_IN_CorrectZeroPos          ((uint8)2U)
#define DHM_IN_Delay                   ((uint8)3U)
#define DHM_IN_Failed                  ((uint8)4U)
#define DHM_IN_Finished                ((uint8)5U)
#define DHM_IN_GotoMaxPos1             ((uint8)6U)
#define DHM_IN_GotoZeroPos             ((uint8)7U)
#define DHM_IN_Idle_d                  ((uint8)8U)
#define DHM_IN_LearnLogic              ((uint8)1U)
#define DHM_IN_PowerOn                 ((uint8)2U)

/* Named constants for Chart: '<S16>/Stall' */
#define DHM_IN_Checking                ((uint8)1U)
#define DHM_IN_Idle_a                  ((uint8)2U)
#define DHM_IN_Stall                   ((uint8)3U)

/* Named constants for Chart: '<S3>/FLDoorHndReq' */
#define DHM_IN_CrashUnfoldReq          ((uint8)1U)
#define DHM_IN_FoldReq                 ((uint8)1U)
#define DHM_IN_Func                    ((uint8)1U)
#define DHM_IN_Idle_ai                 ((uint8)2U)
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

/* Forward declaration for local functions */
static void DHM_Unfold(SInt16 rtu_SI_s_CurrentPos, sint16 rtu_SI_s_MaxSoftPos,
  sint16 rtu_SI_s_IceBrkPos, boolean rtu_SI_b_Learning, uint8 *rty_SO_e_MotorCmd,
  uint8 *rty_SO_e_MotorPwm, boolean *rty_SO_b_Error, DW_CtrlLogic_DHM_T *localDW);

/* Forward declaration for local functions */
static float64 DHM_GetPosSts(float64 CurrentPos, float64 MinSoftPos, float64
  MaxSoftPos);
static uint8 DHM_safe_cast_to_HndPos_Sts_E(uint8 input);

/* Function for Chart: '<S16>/CtrlLogic' */
static void DHM_Unfold(SInt16 rtu_SI_s_CurrentPos, sint16 rtu_SI_s_MaxSoftPos,
  sint16 rtu_SI_s_IceBrkPos, boolean rtu_SI_b_Learning, uint8 *rty_SO_e_MotorCmd,
  uint8 *rty_SO_e_MotorPwm, boolean *rty_SO_b_Error, DW_CtrlLogic_DHM_T *localDW)
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
  } else if (rtu_SI_b_Learning) {
    localDW->is_Icebreak = DHM_IN_NO_ACTIVE_CHILD;
    localDW->is_Unfold = DHM_IN_NO_ACTIVE_CHILD;
    localDW->is_Ctrl = DHM_IN_Idle;
    *rty_SO_e_MotorCmd = 0U;
    *rty_SO_e_MotorPwm = 0U;
  } else {
    switch (localDW->is_Unfold) {
     case DHM_IN_Icebreak:
      {
        switch (localDW->is_Icebreak) {
         case DHM_IN_Check:
          *rty_SO_e_MotorCmd = 0U;
          *rty_SO_e_MotorPwm = 0U;
          if (rtu_SI_s_CurrentPos > rtu_SI_s_IceBrkPos) {
            localDW->is_Icebreak = DHM_IN_IceBrkSuccess;
            localDW->temporalCounter_i1 = 0U;
            *rty_SO_e_MotorCmd = 1U;
            *rty_SO_e_MotorPwm = 100U;
          } else if (localDW->SL_e_CycleCount >= 3) {
            *rty_SO_b_Error = true;

            /*  破冰达到指定次数，报错  */
            localDW->is_Icebreak = DHM_IN_NO_ACTIVE_CHILD;
            localDW->is_Unfold = DHM_IN_NO_ACTIVE_CHILD;
            localDW->is_Ctrl = DHM_IN_Idle;
            *rty_SO_e_MotorCmd = 0U;
            *rty_SO_e_MotorPwm = 0U;
          } else if (localDW->temporalCounter_i1 >= 50) {
            localDW->is_Icebreak = DHM_IN_IceBrk;
            localDW->temporalCounter_i1 = 0U;
            *rty_SO_e_MotorCmd = 1U;
            *rty_SO_e_MotorPwm = 100U;
          }
          break;

         case DHM_IN_IceBrk:
          {
            *rty_SO_e_MotorCmd = 1U;
            *rty_SO_e_MotorPwm = 100U;
            if (localDW->temporalCounter_i1 >= 50) {
              sint32 tmp;
              localDW->is_Icebreak = DHM_IN_Check;
              localDW->temporalCounter_i1 = 0U;
              *rty_SO_e_MotorCmd = 0U;
              *rty_SO_e_MotorPwm = 0U;
              tmp = localDW->SL_e_CycleCount + 1;
              if (localDW->SL_e_CycleCount + 1 > 255) {
                tmp = 255;
              }

              localDW->SL_e_CycleCount = (uint8)tmp;
            }
          }
          break;

         default:
          /* case IN_IceBrkSuccess: */
          *rty_SO_e_MotorCmd = 1U;
          *rty_SO_e_MotorPwm = 100U;
          if (localDW->temporalCounter_i1 >= 10) {
            localDW->SL_e_IceBrkCount = 0U;

            /*  破冰完成  */
            localDW->is_Icebreak = DHM_IN_NO_ACTIVE_CHILD;
            localDW->is_Unfold = DHM_IN_Step2;
            localDW->temporalCounter_i1 = 0U;
            *rty_SO_e_MotorCmd = 1U;
            *rty_SO_e_MotorPwm = 85U;
          }
          break;
        }
      }
      break;

     case DHM_IN_Start:
      *rty_SO_e_MotorCmd = 1U;
      *rty_SO_e_MotorPwm = 100U;
      if (localDW->temporalCounter_i1 >= 240) {
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
      if ((localDW->temporalCounter_i1 >= 130) && (localDW->SL_e_IceBrkCount <=
           0) && (rtu_SI_s_CurrentPos < rtu_SI_s_IceBrkPos)) {
        localDW->SL_e_IceBrkCount = 1U;
        localDW->is_Unfold = DHM_IN_Icebreak;
        localDW->SL_e_CycleCount = 0U;
        localDW->is_Icebreak = DHM_IN_IceBrk;
        localDW->temporalCounter_i1 = 0U;
        *rty_SO_e_MotorCmd = 1U;
        *rty_SO_e_MotorPwm = 100U;
      } else if (rtu_SI_s_CurrentPos >= rtu_SI_s_MaxSoftPos) {
        localDW->is_Unfold = DHM_IN_Step3;
        localDW->temporalCounter_i1 = 0U;

        /*  缓停  */
        *rty_SO_e_MotorCmd = 1U;
        *rty_SO_e_MotorPwm = 60U;
      } else if (localDW->temporalCounter_i1 >= 200) {
        /*  超时报错  */
        localDW->is_Unfold = DHM_IN_NO_ACTIVE_CHILD;
        localDW->is_Ctrl = DHM_IN_Idle;
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
void DHM_CtrlLogic(SInt16 rtu_SI_s_CurrentPos, sint16 rtu_SI_s_MaxSoftPos,
                   sint16 rtu_SI_s_MinSoftPos, sint16 rtu_SI_s_IceBrkPos,
                   boolean rtu_SI_b_DoorHndFoldReq, boolean
                   rtu_SI_b_DoorHndUnfoldReq, Learn_Sts_E rtu_SI_m_LearnSts,
                   boolean rtu_SI_b_Learning, uint8 *rty_SO_e_MotorCmd, uint8
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
      } else if (rtu_SI_b_Learning) {
        localDW->is_Fold = DHM_IN_NO_ACTIVE_CHILD;
        localDW->is_Ctrl = DHM_IN_Idle;
        *rty_SO_e_MotorCmd = 0U;
        *rty_SO_e_MotorPwm = 0U;
      } else {
        switch (localDW->is_Fold) {
         case DHM_IN_Start_f:
          *rty_SO_e_MotorCmd = 2U;
          *rty_SO_e_MotorPwm = 100U;
          if (localDW->temporalCounter_i1 >= 240) {
            localDW->is_Fold = DHM_IN_Stop_e;
            *rty_SO_e_MotorCmd = 0U;
            *rty_SO_e_MotorPwm = 0U;
            *rty_SO_b_Error = false;
          }
          break;

         case DHM_IN_Step1_h:
          *rty_SO_e_MotorCmd = 2U;
          *rty_SO_e_MotorPwm = 60U;
          if (localDW->temporalCounter_i1 >= 20) {
            localDW->is_Fold = DHM_IN_Step2_h;
            localDW->temporalCounter_i1 = 0U;
            *rty_SO_e_MotorCmd = 2U;
            *rty_SO_e_MotorPwm = 85U;
          }
          break;

         case DHM_IN_Step2_h:
          *rty_SO_e_MotorCmd = 2U;
          *rty_SO_e_MotorPwm = 85U;
          if (rtu_SI_s_CurrentPos <= rtu_SI_s_MinSoftPos) {
            localDW->is_Fold = DHM_IN_Step3_i;
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

         case DHM_IN_Step3_i:
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
          localDW->is_Fold = DHM_IN_Step1_h;
          localDW->temporalCounter_i1 = 0U;

          /*  缓启  */
          *rty_SO_e_MotorCmd = 2U;
          *rty_SO_e_MotorPwm = 60U;
        } else {
          /*  未学习  */
          localDW->is_Fold = DHM_IN_Start_f;
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
          localDW->is_Fold = DHM_IN_Step1_h;
          localDW->temporalCounter_i1 = 0U;

          /*  缓启  */
          *rty_SO_e_MotorCmd = 2U;
          *rty_SO_e_MotorPwm = 60U;
        } else {
          /*  未学习  */
          localDW->is_Fold = DHM_IN_Start_f;
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
      DHM_Unfold(rtu_SI_s_CurrentPos, rtu_SI_s_MaxSoftPos, rtu_SI_s_IceBrkPos,
                 rtu_SI_b_Learning, rty_SO_e_MotorCmd, rty_SO_e_MotorPwm,
                 rty_SO_b_Error, localDW);
      break;
    }
  }

  /* End of Chart: '<S16>/CtrlLogic' */
}

/* Function for Chart: '<S16>/DoorHndPos' */
static float64 DHM_GetPosSts(float64 CurrentPos, float64 MinSoftPos, float64
  MaxSoftPos)
{
  float64 HndSts;
  if (CurrentPos <= MinSoftPos) {
    HndSts = 0.0;
  } else if (CurrentPos >= MaxSoftPos) {
    HndSts = 1.0;
  } else {
    HndSts = 2.0;
  }

  return HndSts;
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
void DHM_DoorHndPos(SInt16 rtu_SI_s_CurrentPos, sint16 rtu_SI_s_MaxPos,
                    Learn_Sts_E rtu_SI_m_LearnSts, HndPos_Sts_E
                    *rty_SO_m_DoorHndPosSts, sint16 *rty_SO_s_MaxSoftPos, sint16
                    *rty_SO_s_MinSoftPos, sint16 *rty_SO_s_IceBrkPos,
                    DW_DoorHndPos_DHM_T *localDW)
{
  /* Chart: '<S16>/DoorHndPos' */
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
 * Output and update for atomic system:
 *    '<S16>/LearnLogic'
 *    '<S21>/LearnLogic'
 */
void DHM_LearnLogic(boolean rtu_SI_b_HallStall, Boolean rtu_SI_b_LearnReq,
                    Learn_Sts_E rtu_SI_m_LearnStsFromEE, SInt16
                    rtu_SI_s_MaxPosFromEE, SInt16 rtu_SI_s_CurrentPos, uint8
                    *rty_SO_e_LearnMotorCmd, uint8 *rty_SO_e_LearnMotorPwm,
                    boolean *rty_SO_b_CorrectPosToZero, Learn_Sts_E
                    *rty_SO_m_LearnSts, sint16 *rty_SO_s_MaxPos, boolean
                    *rty_SO_b_Learning, DW_LearnLogic_DHM_T *localDW)
{
  if (localDW->temporalCounter_i1 < 511U) {
    localDW->temporalCounter_i1++;
  }

  localDW->SI_b_LearnReq_prev = localDW->SI_b_LearnReq_start;
  localDW->SI_b_LearnReq_start = rtu_SI_b_LearnReq;

  /* Chart: '<S16>/LearnLogic' */
  if (localDW->is_active_c3_DoorHndDriver == 0U) {
    localDW->SI_b_LearnReq_prev = rtu_SI_b_LearnReq;
    localDW->is_active_c3_DoorHndDriver = 1U;
    localDW->is_c3_DoorHndDriver = DHM_IN_PowerOn;
    localDW->temporalCounter_i1 = 0U;
    localDW->SL_e_AutoLearnCount = 0U;

    /* 上电自动学习 */
    *rty_SO_s_MaxPos = rtu_SI_s_MaxPosFromEE;
    *rty_SO_m_LearnSts = rtu_SI_m_LearnStsFromEE;
  } else if (localDW->is_c3_DoorHndDriver == DHM_IN_LearnLogic) {
    boolean guard1 = false;
    guard1 = false;
    switch (localDW->is_LearnLogic) {
     case DHM_IN_Check_m:
      if (*rty_SO_s_MaxPos > 400) {
        localDW->is_LearnLogic = DHM_IN_Finished;
        localDW->temporalCounter_i1 = 0U;

        /*  学习成功  */
        *rty_SO_m_LearnSts = Learn_Success;
      } else {
        localDW->is_LearnLogic = DHM_IN_Failed;
        localDW->temporalCounter_i1 = 0U;

        /*  学习失败  */
        *rty_SO_e_LearnMotorCmd = 0U;
        *rty_SO_e_LearnMotorPwm = 0U;
        *rty_SO_m_LearnSts = Learn_Fail;
      }
      break;

     case DHM_IN_CorrectZeroPos:
      if (localDW->temporalCounter_i1 >= 20) {
        localDW->is_LearnLogic = DHM_IN_Check_m;

        /*  学习结果判断  */
      }
      break;

     case DHM_IN_Delay:
      if (localDW->temporalCounter_i1 >= 20) {
        localDW->is_LearnLogic = DHM_IN_GotoZeroPos;
        localDW->temporalCounter_i1 = 0U;

        /*  折叠  */
        *rty_SO_e_LearnMotorCmd = 2U;
        *rty_SO_e_LearnMotorPwm = 100U;
      }
      break;

     case DHM_IN_Failed:
      if (localDW->temporalCounter_i1 >= 3) {
        localDW->is_LearnLogic = DHM_IN_Idle_d;
        *rty_SO_b_Learning = false;
        *rty_SO_e_LearnMotorCmd = 0U;
        *rty_SO_e_LearnMotorPwm = 0U;
        *rty_SO_b_CorrectPosToZero = false;
      }
      break;

     case DHM_IN_Finished:
      if (localDW->temporalCounter_i1 >= 3) {
        localDW->is_LearnLogic = DHM_IN_Idle_d;
        *rty_SO_b_Learning = false;
        *rty_SO_e_LearnMotorCmd = 0U;
        *rty_SO_e_LearnMotorPwm = 0U;
        *rty_SO_b_CorrectPosToZero = false;
      }
      break;

     case DHM_IN_GotoMaxPos1:
      {
        if (rtu_SI_b_HallStall) {
          sint16 tmp;
          tmp = rtu_SI_s_CurrentPos;
          if (rtu_SI_s_CurrentPos < 0) {
            tmp = 0;
          } else if (rtu_SI_s_CurrentPos > 255) {
            tmp = 255;
          }

          localDW->SL_e_tempPos = (uint8)tmp;
          localDW->is_LearnLogic = DHM_IN_Delay;
          localDW->temporalCounter_i1 = 0U;
          *rty_SO_e_LearnMotorCmd = 0U;
          *rty_SO_e_LearnMotorPwm = 0U;
        } else if (localDW->temporalCounter_i1 >= 400) {
          localDW->is_LearnLogic = DHM_IN_Failed;
          localDW->temporalCounter_i1 = 0U;

          /*  学习失败  */
          *rty_SO_e_LearnMotorCmd = 0U;
          *rty_SO_e_LearnMotorPwm = 0U;
          *rty_SO_m_LearnSts = Learn_Fail;
        } else {
          /*  展开  */
          *rty_SO_b_Learning = true;
          *rty_SO_e_LearnMotorCmd = 1U;
          *rty_SO_e_LearnMotorPwm = 100U;
        }
      }
      break;

     case DHM_IN_GotoZeroPos:
      {
        if (localDW->temporalCounter_i1 >= 400) {
          localDW->is_LearnLogic = DHM_IN_Failed;
          localDW->temporalCounter_i1 = 0U;

          /*  学习失败  */
          *rty_SO_e_LearnMotorCmd = 0U;
          *rty_SO_e_LearnMotorPwm = 0U;
          *rty_SO_m_LearnSts = Learn_Fail;
        } else if (rtu_SI_b_HallStall) {
          sint32 tmp_0;
          tmp_0 = localDW->SL_e_tempPos - rtu_SI_s_CurrentPos;
          if (tmp_0 > 32767) {
            tmp_0 = 32767;
          }

          *rty_SO_s_MaxPos = (sint16)tmp_0;
          localDW->is_LearnLogic = DHM_IN_CorrectZeroPos;
          localDW->temporalCounter_i1 = 0U;

          /*  零点校准  */
          *rty_SO_e_LearnMotorCmd = 0U;
          *rty_SO_e_LearnMotorPwm = 0U;
          *rty_SO_b_CorrectPosToZero = true;
        } else {
          /*  折叠  */
          *rty_SO_e_LearnMotorCmd = 2U;
          *rty_SO_e_LearnMotorPwm = 100U;
        }
      }
      break;

     default:
      /* case IN_Idle: */
      if ((*rty_SO_m_LearnSts != Learn_Success) && (localDW->SL_e_AutoLearnCount
           > 0)) {
        localDW->SL_e_AutoLearnCount--;
        guard1 = true;
      } else if ((localDW->SI_b_LearnReq_prev != localDW->SI_b_LearnReq_start) &&
                 localDW->SI_b_LearnReq_start) {
        guard1 = true;
      }
      break;
    }

    if (guard1) {
      localDW->is_LearnLogic = DHM_IN_GotoMaxPos1;
      localDW->temporalCounter_i1 = 0U;

      /*  展开  */
      *rty_SO_b_Learning = true;
      *rty_SO_e_LearnMotorCmd = 1U;
      *rty_SO_e_LearnMotorPwm = 100U;
    }

    /* case IN_PowerOn: */
  } else if (localDW->temporalCounter_i1 >= 50) {
    /*  500ms内读取E2学习状态和最大hall位置  */
    localDW->is_c3_DoorHndDriver = DHM_IN_LearnLogic;
    localDW->is_LearnLogic = DHM_IN_Idle_d;
    *rty_SO_b_Learning = false;
    *rty_SO_e_LearnMotorCmd = 0U;
    *rty_SO_e_LearnMotorPwm = 0U;
    *rty_SO_b_CorrectPosToZero = false;
  } else {
    localDW->SL_e_AutoLearnCount = 0U;

    /* 上电自动学习 */
    *rty_SO_s_MaxPos = rtu_SI_s_MaxPosFromEE;
    *rty_SO_m_LearnSts = rtu_SI_m_LearnStsFromEE;
  }

  /* End of Chart: '<S16>/LearnLogic' */
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
 * Output and update for atomic system:
 *    '<S16>/Stall'
 *    '<S21>/Stall'
 */
void DHM_Stall(SInt16 rtu_SI_s_CurrentPos, uint8 rtu_SI_e_MotorCmd, boolean
               *rty_SO_b_HallStall, DW_Stall_DHM_T *localDW)
{
  if (localDW->temporalCounter_i1 < 31U) {
    localDW->temporalCounter_i1++;
  }

  /* Chart: '<S16>/Stall' */
  if (localDW->is_active_c2_DoorHndDriver == 0U) {
    localDW->is_active_c2_DoorHndDriver = 1U;
    localDW->is_Stall_Handler = DHM_IN_Idle_a;
    *rty_SO_b_HallStall = false;
  } else {
    switch (localDW->is_Stall_Handler) {
     case DHM_IN_Checking:
      if ((rtu_SI_s_CurrentPos - localDW->SL_s_CurrentPos_Old > 5) ||
          (localDW->SL_s_CurrentPos_Old - rtu_SI_s_CurrentPos > 5)) {
        localDW->is_Stall_Handler = DHM_IN_Checking;
        localDW->temporalCounter_i1 = 0U;
        localDW->SL_s_CurrentPos_Old = rtu_SI_s_CurrentPos;
      } else if (rtu_SI_e_MotorCmd == 0) {
        localDW->is_Stall_Handler = DHM_IN_Idle_a;
        *rty_SO_b_HallStall = false;
      } else if (localDW->temporalCounter_i1 >= 30) {
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
      if (localDW->temporalCounter_i1 >= 5) {
        localDW->is_Stall_Handler = DHM_IN_Idle_a;
        *rty_SO_b_HallStall = false;
      }
      break;
    }
  }

  /* End of Chart: '<S16>/Stall' */
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
        localDW->is_Fold = DHM_IN_Idle_ai;
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
        localDW->is_Unfold = DHM_IN_Idle_ai;
        *rty_SO_b_HndUnfoldReq = false;
        localDW->SL_b_UnfoldReqTrig = ((rtu_SI_b_DoorOpen ||
          (rtu_SI_m_DoorLockSts == Door_Unlock)) && localDW->SL_b_UnfoldReqTrig);
      }
      break;

     case DHM_IN_Idle_ai:
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
        localDW->is_Unfold = DHM_IN_Idle_ai;
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
    localDW->is_Fold = DHM_IN_Idle_ai;
    *rty_SO_b_HndFoldReq = false;
    localDW->SL_b_FoldReqTrig = (((rtu_SI_m_DoorLockSts == Door_Lock) ||
      (rtu_SI_e_EspVehSpd >= 15)) && localDW->SL_b_FoldReqTrig);
    localDW->is_Unfold = DHM_IN_Idle_ai;
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
  UInt8 rtb_TmpSignalConversionAtVeOUT_;
  uint8 rtb_SO_e_MotorCmd;
  uint8 rtb_SO_e_MotorPwm;
  uint8 rtb_SO_e_MotorCmd_a;
  uint8 rtb_SO_e_MotorPwm_b;
  Boolean rtb_TmpSignalConversionAtVbOUT_;
  HndPos_Sts_E rtb_SO_m_DoorHndPosSts;
  HndPos_Sts_E rtb_SO_m_DoorHndPosSts_h;
  SInt16 tmpRead_0;
  SInt16 tmpRead_1;
  UInt8 rtb_TmpSignalConversionAtVeINP_;
  UInt8 rtb_TmpSignalConversionAtVeIN_i;
  UInt8 rtb_TmpSignalConversionAtVeOU_a;
  UInt8 rtb_TmpSignalConversionAtVeOU_f;
  UInt8 tmpRead;
  UInt8 tmpRead_2;
  UInt8 tmpRead_3;
  UInt8 tmpRead_4;
  UInt8 tmpRead_5;
  uint8 SO_e_FRHndReq;
  uint8 SO_e_RRHndReq;
  boolean SO_b_CorrectPosToZero_e;
  boolean SO_b_Error_f;

  /* SignalConversion generated from: '<S2>/VbINP_HWA_DoorHandleLrnReq_flg_VbINP_HWA_DoorHandleLrnReq_flg_read' incorporates:
   *  Inport: '<Root>/VbINP_HWA_DoorHandleLrnReq_flg_VbINP_HWA_DoorHandleLrnReq_flg'
   */
  (void)Rte_Read_VbINP_HWA_DoorHandleLrnReq_flg_VbINP_HWA_DoorHandleLrnReq_flg
    (&DHM_B.VbINP_HWA_DoorHandleLrnReq_flg_);

  /* Inport: '<Root>/VeINP_CAN_RRDoorHandleLrnSts_sig_VeINP_CAN_RRDoorHandleLrnSts_sig' */
  (void)
    Rte_Read_VeINP_CAN_RRDoorHandleLrnSts_sig_VeINP_CAN_RRDoorHandleLrnSts_sig
    (&tmpRead_5);

  /* Inport: '<Root>/VeINP_CAN_FRDoorHandleLrnSts_sig_VeINP_CAN_FRDoorHandleLrnSts_sig' */
  (void)
    Rte_Read_VeINP_CAN_FRDoorHandleLrnSts_sig_VeINP_CAN_FRDoorHandleLrnSts_sig
    (&tmpRead_4);

  /* Inport: '<Root>/VeINP_EPRM_RLDoorHandleLrnStsEE_sig_VeINP_EPRM_RLDoorHandleLrnStsEE_sig' */
  (void)
    Rte_Read_VeINP_EPRM_RLDoorHandleLrnStsEE_sig_VeINP_EPRM_RLDoorHandleLrnStsEE_sig
    (&tmpRead_3);

  /* Inport: '<Root>/VeINP_EPRM_FLDoorHandleLrnStsEE_sig_VeINP_EPRM_FLDoorHandleLrnStsEE_sig' */
  (void)
    Rte_Read_VeINP_EPRM_FLDoorHandleLrnStsEE_sig_VeINP_EPRM_FLDoorHandleLrnStsEE_sig
    (&tmpRead_2);

  /* Inport: '<Root>/VsINP_EPRM_RLDoorHandleFromEE_sig_VsINP_EPRM_RLDoorHandleFromEE_sig' */
  (void)
    Rte_Read_VsINP_EPRM_RLDoorHandleFromEE_sig_VsINP_EPRM_RLDoorHandleFromEE_sig
    (&tmpRead_1);

  /* Inport: '<Root>/VsINP_EPRM_FLDoorHandleFromEE_sig_VsINP_EPRM_FLDoorHandleFromEE_sig' */
  (void)
    Rte_Read_VsINP_EPRM_FLDoorHandleFromEE_sig_VsINP_EPRM_FLDoorHandleFromEE_sig
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
    (&DHM_B.TmpSignalConversionAtVsINP_HWA_);

  /* Chart: '<S16>/LearnLogic' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion8'
   *  UnitDelay: '<S16>/Unit Delay'
   */
  DHM_LearnLogic(DHM_B.SO_b_HallStall_d, DHM_B.VbINP_HWA_DoorHandleLrnReq_flg_,
                 tmpRead_2, tmpRead_0, DHM_B.TmpSignalConversionAtVsINP_HWA_,
                 &DHM_B.SO_e_LearnMotorCmd_j, &DHM_B.SO_e_LearnMotorPwm_i,
                 &SO_b_CorrectPosToZero_e, &DHM_B.SO_m_LearnSts_g,
                 &DHM_B.SO_s_MaxPos_i, &DHM_B.SO_b_Learning_e,
                 &DHM_DW.sf_LearnLogic);

  /* Chart: '<S16>/DoorHndPos' incorporates:
   *  UnitDelay: '<S16>/Unit Delay5'
   */
  DHM_DoorHndPos(DHM_B.TmpSignalConversionAtVsINP_HWA_, DHM_DW.UnitDelay5_DSTATE,
                 DHM_B.SO_m_LearnSts_g, &rtb_SO_m_DoorHndPosSts_h,
                 &DHM_B.SO_s_MaxSoftPos_p, &DHM_B.SO_s_MinSoftPos_f,
                 &DHM_B.SO_s_IceBrkPos_e, &DHM_DW.sf_DoorHndPos);

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
  SO_b_CorrectPosToZero_e = ((rtb_TmpSignalConversionAtVeOU_a == 1) ||
    (rtb_TmpSignalConversionAtVeOU_a == 2) || ((rtb_TmpSignalConversionAtVeOU_f ==
    1) || (rtb_TmpSignalConversionAtVeOU_f == 2)) ||
    ((rtb_TmpSignalConversionAtVeINP_ == 1) || (rtb_TmpSignalConversionAtVeINP_ ==
    2)) || ((rtb_TmpSignalConversionAtVeIN_i == 1) ||
            (rtb_TmpSignalConversionAtVeIN_i == 2)));

  /* Chart: '<S3>/FLDoorHndReq' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion7'
   */
  DHM_FLDoorHndReq(rtb_TmpSignalConversionAtVbOUT_,
                   rtb_TmpSignalConversionAtVeOUT_, SO_b_CorrectPosToZero_e,
                   tmpRead, rtb_SO_m_DoorHndPosSts_h, &DHM_B.SO_b_HndUnfoldReq_j,
                   &DHM_B.SO_b_HndFoldReq_dm, &DHM_DW.sf_FLDoorHndReq);

  /* Chart: '<S16>/CtrlLogic' */
  DHM_CtrlLogic(DHM_B.TmpSignalConversionAtVsINP_HWA_, DHM_B.SO_s_MaxSoftPos_p,
                DHM_B.SO_s_MinSoftPos_f, DHM_B.SO_s_IceBrkPos_e,
                DHM_B.SO_b_HndFoldReq_dm, DHM_B.SO_b_HndUnfoldReq_j,
                DHM_B.SO_m_LearnSts_g, DHM_B.SO_b_Learning_e,
                &DHM_B.SO_e_MotorCmd_e, &DHM_B.SO_e_MotorPwm_d, &SO_b_Error_f,
                &DHM_DW.sf_CtrlLogic);

  /* Chart: '<S16>/MotorLogic' */
  DHM_MotorLogic(DHM_B.SO_e_LearnMotorCmd_j, DHM_B.SO_e_LearnMotorPwm_i,
                 DHM_B.SO_e_MotorCmd_e, DHM_B.SO_e_MotorPwm_d,
                 &rtb_SO_e_MotorCmd_a, &rtb_SO_e_MotorPwm_b,
                 &DHM_DW.sf_MotorLogic);

  /* SignalConversion generated from: '<S2>/VsINP_HWA_RLHandleHall_sig_VsINP_HWA_RLHandleHall_sig_read' incorporates:
   *  Inport: '<Root>/VsINP_HWA_RLHandleHall_sig_VsINP_HWA_RLHandleHall_sig'
   */
  (void)Rte_Read_VsINP_HWA_RLHandleHall_sig_VsINP_HWA_RLHandleHall_sig
    (&DHM_B.TmpSignalConversionAtVsINP_HW_a);

  /* Chart: '<S21>/LearnLogic' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion9'
   *  UnitDelay: '<S21>/Unit Delay'
   */
  DHM_LearnLogic(DHM_B.SO_b_HallStall, DHM_B.VbINP_HWA_DoorHandleLrnReq_flg_,
                 tmpRead_3, tmpRead_1, DHM_B.TmpSignalConversionAtVsINP_HW_a,
                 &DHM_B.SO_e_LearnMotorCmd, &DHM_B.SO_e_LearnMotorPwm,
                 &SO_b_Error_f, &DHM_B.SO_m_LearnSts, &DHM_B.SO_s_MaxPos,
                 &DHM_B.SO_b_Learning, &DHM_DW.sf_LearnLogic_p);

  /* Chart: '<S21>/DoorHndPos' incorporates:
   *  UnitDelay: '<S21>/Unit Delay5'
   */
  DHM_DoorHndPos(DHM_B.TmpSignalConversionAtVsINP_HW_a,
                 DHM_DW.UnitDelay5_DSTATE_g, DHM_B.SO_m_LearnSts,
                 &rtb_SO_m_DoorHndPosSts, &DHM_B.SO_s_MaxSoftPos,
                 &DHM_B.SO_s_MinSoftPos, &DHM_B.SO_s_IceBrkPos,
                 &DHM_DW.sf_DoorHndPos_a);

  /* Chart: '<S3>/RLDoorHndReq' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion7'
   */
  DHM_FLDoorHndReq(rtb_TmpSignalConversionAtVbOUT_,
                   rtb_TmpSignalConversionAtVeOUT_, SO_b_CorrectPosToZero_e,
                   tmpRead, rtb_SO_m_DoorHndPosSts, &DHM_B.SO_b_HndUnfoldReq_a,
                   &DHM_B.SO_b_HndFoldReq_a, &DHM_DW.sf_RLDoorHndReq);

  /* Chart: '<S21>/CtrlLogic' */
  DHM_CtrlLogic(DHM_B.TmpSignalConversionAtVsINP_HW_a, DHM_B.SO_s_MaxSoftPos,
                DHM_B.SO_s_MinSoftPos, DHM_B.SO_s_IceBrkPos,
                DHM_B.SO_b_HndFoldReq_a, DHM_B.SO_b_HndUnfoldReq_a,
                DHM_B.SO_m_LearnSts, DHM_B.SO_b_Learning, &DHM_B.SO_e_MotorCmd,
                &DHM_B.SO_e_MotorPwm, &SO_b_Error_f, &DHM_DW.sf_CtrlLogic_e);

  /* Chart: '<S21>/MotorLogic' */
  DHM_MotorLogic(DHM_B.SO_e_LearnMotorCmd, DHM_B.SO_e_LearnMotorPwm,
                 DHM_B.SO_e_MotorCmd, DHM_B.SO_e_MotorPwm, &rtb_SO_e_MotorCmd,
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

  /* Chart: '<S16>/Stall' incorporates:
   *  UnitDelay: '<S16>/Unit Delay1'
   */
  DHM_Stall(DHM_B.TmpSignalConversionAtVsINP_HWA_, DHM_DW.UnitDelay1_DSTATE,
            &DHM_B.SO_b_HallStall_d, &DHM_DW.sf_Stall);

  /* Chart: '<S3>/FRDoorHndReq' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion4'
   *  DataTypeConversion: '<S3>/Data Type Conversion7'
   */
  DHM_FLDoorHndReq(rtb_TmpSignalConversionAtVbOUT_,
                   rtb_TmpSignalConversionAtVeOUT_, SO_b_CorrectPosToZero_e,
                   tmpRead, SO_e_RRHndReq, &DHM_B.SO_b_HndUnfoldReq_k,
                   &DHM_B.SO_b_HndFoldReq_d, &DHM_DW.sf_FRDoorHndReq);

  /* Chart: '<S3>/RRDoorHndReq' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion6'
   *  DataTypeConversion: '<S3>/Data Type Conversion7'
   */
  DHM_FLDoorHndReq(rtb_TmpSignalConversionAtVbOUT_,
                   rtb_TmpSignalConversionAtVeOUT_, SO_b_CorrectPosToZero_e,
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

  /* Chart: '<S21>/Stall' incorporates:
   *  UnitDelay: '<S21>/Unit Delay1'
   */
  DHM_Stall(DHM_B.TmpSignalConversionAtVsINP_HW_a, DHM_DW.UnitDelay1_DSTATE_a,
            &DHM_B.SO_b_HallStall, &DHM_DW.sf_Stall_i);

  /* Update for UnitDelay: '<S16>/Unit Delay5' */
  DHM_DW.UnitDelay5_DSTATE = DHM_B.SO_s_MaxPos_i;

  /* Update for UnitDelay: '<S21>/Unit Delay5' */
  DHM_DW.UnitDelay5_DSTATE_g = DHM_B.SO_s_MaxPos;

  /* Update for UnitDelay: '<S16>/Unit Delay1' */
  DHM_DW.UnitDelay1_DSTATE = rtb_SO_e_MotorCmd_a;

  /* Update for UnitDelay: '<S21>/Unit Delay1' */
  DHM_DW.UnitDelay1_DSTATE_a = rtb_SO_e_MotorCmd;

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
    uint8 rtb_SO_e_MotorCmd_a;
    uint8 rtb_SO_e_MotorPwm_b;
    HndPos_Sts_E rtb_SO_m_DoorHndPosSts;
    HndPos_Sts_E rtb_SO_m_DoorHndPosSts_h;
    boolean SO_b_Error_f;

    /* SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/DHM_Step' incorporates:
     *  SubSystem: '<Root>/DHM_Step_sys'
     */

    /* SystemInitialize for Chart: '<S16>/CtrlLogic' */
    DHM_CtrlLogic_Init(&DHM_B.SO_e_MotorCmd_e, &DHM_B.SO_e_MotorPwm_d,
                       &SO_b_Error_f);

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
    DHM_CtrlLogic_Init(&DHM_B.SO_e_MotorCmd, &DHM_B.SO_e_MotorPwm, &SO_b_Error_f);

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
