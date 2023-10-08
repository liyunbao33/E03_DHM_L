/*
 * File: DHM.c
 *
 * Code generated for Simulink model 'DHM'.
 *
 * Model version                  : 1.353
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Sun Oct  8 16:54:32 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "DHM.h"
#include "rtwtypes.h"
#include "Rte_Type.h"
#include "DHM_types.h"
#include "DHM_private.h"

/* Named constants for Chart: '<S14>/CtrlLogic' */
#define DHM_IN_Check                   ((uint8_T)1U)
#define DHM_IN_Fold                    ((uint8_T)1U)
#define DHM_IN_IceBrk1                 ((uint8_T)2U)
#define DHM_IN_IceBrk2                 ((uint8_T)3U)
#define DHM_IN_IceBrk3                 ((uint8_T)4U)
#define DHM_IN_IceBrkWait              ((uint8_T)5U)
#define DHM_IN_Icebreak                ((uint8_T)1U)
#define DHM_IN_Idle                    ((uint8_T)2U)
#define DHM_IN_Interrupt1              ((uint8_T)3U)
#define DHM_IN_Interrupt2              ((uint8_T)4U)
#define DHM_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)
#define DHM_IN_Start                   ((uint8_T)2U)
#define DHM_IN_Start_i                 ((uint8_T)1U)
#define DHM_IN_Step1                   ((uint8_T)3U)
#define DHM_IN_Step1_o                 ((uint8_T)2U)
#define DHM_IN_Step2                   ((uint8_T)4U)
#define DHM_IN_Step2_l                 ((uint8_T)3U)
#define DHM_IN_Step3                   ((uint8_T)5U)
#define DHM_IN_Step3_o                 ((uint8_T)4U)
#define DHM_IN_Stop                    ((uint8_T)6U)
#define DHM_IN_Stop_e                  ((uint8_T)5U)
#define DHM_IN_Unfold                  ((uint8_T)5U)

/* Named constants for Chart: '<S14>/LearnLogic' */
#define DHM_IN_CorrectMaxPos           ((uint8_T)1U)
#define DHM_IN_CorrectZeroPos          ((uint8_T)2U)
#define DHM_IN_Failed                  ((uint8_T)3U)
#define DHM_IN_Finished                ((uint8_T)4U)
#define DHM_IN_GotoMaxPos              ((uint8_T)5U)
#define DHM_IN_GotoZeroPos             ((uint8_T)6U)
#define DHM_IN_Idle_j                  ((uint8_T)7U)
#define DHM_IN_LearnLogic              ((uint8_T)1U)
#define DHM_IN_PowerOn                 ((uint8_T)2U)

/* Named constants for Chart: '<S14>/Stall' */
#define DHM_IN_Checking                ((uint8_T)1U)
#define DHM_IN_Idle_a                  ((uint8_T)2U)
#define DHM_IN_Stall                   ((uint8_T)3U)

/* Named constants for Chart: '<S3>/FLDoorHndReq' */
#define DHM_IN_CrashUnfoldReq          ((uint8_T)1U)
#define DHM_IN_FoldReq                 ((uint8_T)1U)
#define DHM_IN_Idle_ai                 ((uint8_T)2U)
#define DHM_IN_NormalUnfoldReq         ((uint8_T)3U)

/* Block signals (default storage) */
B_DHM_T DHM_B;

/* Block states (default storage) */
DW_DHM_T DHM_DW;

/* External inputs (root inport signals with default storage) */
ExtU_DHM_T DHM_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_DHM_T DHM_Y;

/* Real-time model */
static RT_MODEL_DHM_T DHM_M_;
RT_MODEL_DHM_T *const DHM_M = &DHM_M_;

/* Forward declaration for local functions */
static void DHM_Unfold(boolean_T rtu_SI_b_HallStall, SInt16 rtu_SI_s_CurrentPos,
  int16_T rtu_SI_s_MaxSoftPos, int16_T rtu_SI_s_IceBrkPos, uint8_T
  *rty_SO_e_MotorCmd, uint8_T *rty_SO_e_MotorPwm, boolean_T *rty_SO_b_Error,
  DW_CtrlLogic_DHM_T *localDW);

/* Forward declaration for local functions */
static real_T DHM_GetPosSts(real_T CurrentPos, real_T MinSoftPos, real_T
  MaxSoftPos);
static uint8_T DHM_safe_cast_to_HndPos_Sts_E(uint8_T input);

/* Function for Chart: '<S14>/CtrlLogic' */
static void DHM_Unfold(boolean_T rtu_SI_b_HallStall, SInt16 rtu_SI_s_CurrentPos,
  int16_T rtu_SI_s_MaxSoftPos, int16_T rtu_SI_s_IceBrkPos, uint8_T
  *rty_SO_e_MotorCmd, uint8_T *rty_SO_e_MotorPwm, boolean_T *rty_SO_b_Error,
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
 *    '<S14>/CtrlLogic'
 *    '<S17>/CtrlLogic'
 */
void DHM_CtrlLogic_Init(uint8_T *rty_SO_e_MotorCmd, uint8_T *rty_SO_e_MotorPwm,
  boolean_T *rty_SO_b_Error)
{
  *rty_SO_e_MotorCmd = 0U;
  *rty_SO_e_MotorPwm = 0U;
  *rty_SO_b_Error = false;
}

/*
 * Output and update for atomic system:
 *    '<S14>/CtrlLogic'
 *    '<S17>/CtrlLogic'
 */
void DHM_CtrlLogic(boolean_T rtu_SI_b_HallStall, SInt16 rtu_SI_s_CurrentPos,
                   int16_T rtu_SI_s_MaxSoftPos, int16_T rtu_SI_s_MinSoftPos,
                   int16_T rtu_SI_s_IceBrkPos, boolean_T rtu_SI_b_DoorHndFoldReq,
                   boolean_T rtu_SI_b_DoorHndUnfoldReq, Learn_Sts_E
                   rtu_SI_m_LearnSts, uint8_T *rty_SO_e_MotorCmd, uint8_T
                   *rty_SO_e_MotorPwm, boolean_T *rty_SO_b_Error,
                   DW_CtrlLogic_DHM_T *localDW)
{
  if (localDW->temporalCounter_i1 < 255U) {
    localDW->temporalCounter_i1++;
  }

  localDW->SI_b_DoorHndUnfoldReq_prev = localDW->SI_b_DoorHndUnfoldReq_start;
  localDW->SI_b_DoorHndUnfoldReq_start = rtu_SI_b_DoorHndUnfoldReq;
  localDW->SI_b_DoorHndFoldReq_prev = localDW->SI_b_DoorHndFoldReq_start;
  localDW->SI_b_DoorHndFoldReq_start = rtu_SI_b_DoorHndFoldReq;

  /* Chart: '<S14>/CtrlLogic' */
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

  /* End of Chart: '<S14>/CtrlLogic' */
}

/* Function for Chart: '<S14>/DoorHndPos' */
static real_T DHM_GetPosSts(real_T CurrentPos, real_T MinSoftPos, real_T
  MaxSoftPos)
{
  real_T y;
  if (CurrentPos <= MinSoftPos) {
    y = 1.0;
  } else if (CurrentPos >= MaxSoftPos) {
    y = 0.0;
  } else {
    y = 2.0;
  }

  return y;
}

static uint8_T DHM_safe_cast_to_HndPos_Sts_E(uint8_T input)
{
  uint8_T output;

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
 *    '<S14>/DoorHndPos'
 *    '<S17>/DoorHndPos'
 */
void DHM_DoorHndPos_Init(HndPos_Sts_E *rty_SO_m_DoorHndPosSts, int16_T
  *rty_SO_s_MaxSoftPos, int16_T *rty_SO_s_MinSoftPos, int16_T
  *rty_SO_s_IceBrkPos)
{
  *rty_SO_m_DoorHndPosSts = Hnd_Fold;
  *rty_SO_s_MaxSoftPos = 0;
  *rty_SO_s_MinSoftPos = 0;
  *rty_SO_s_IceBrkPos = 0;
}

/*
 * Output and update for atomic system:
 *    '<S14>/DoorHndPos'
 *    '<S17>/DoorHndPos'
 */
void DHM_DoorHndPos(SInt16 rtu_SI_s_CurrentPos, int16_T rtu_SI_s_MaxPos,
                    Learn_Sts_E rtu_SI_m_LearnSts, HndPos_Sts_E
                    *rty_SO_m_DoorHndPosSts, int16_T *rty_SO_s_MaxSoftPos,
                    int16_T *rty_SO_s_MinSoftPos, int16_T *rty_SO_s_IceBrkPos,
                    DW_DoorHndPos_DHM_T *localDW)
{
  /* Chart: '<S14>/DoorHndPos' */
  if (localDW->is_active_c5_DoorHndDriver == 0U) {
    localDW->is_active_c5_DoorHndDriver = 1U;
    if (rtu_SI_m_LearnSts == Learn_Success) {
      real_T tmp;
      *rty_SO_s_MaxSoftPos = (int16_T)(rtu_SI_s_MaxPos * 95 / 100);
      *rty_SO_s_MinSoftPos = (int16_T)(rtu_SI_s_MaxPos * 5 / 100);
      *rty_SO_s_IceBrkPos = (int16_T)(rtu_SI_s_MaxPos * 20 / 100);
      tmp = DHM_GetPosSts((real_T)rtu_SI_s_CurrentPos, (real_T)
                          *rty_SO_s_MinSoftPos, (real_T)*rty_SO_s_MaxSoftPos);
      if (tmp < 2.147483648E+9) {
        if (tmp >= -2.147483648E+9) {
          *rty_SO_m_DoorHndPosSts = DHM_safe_cast_to_HndPos_Sts_E((uint8_T)
            (int32_T)tmp);
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
    real_T tmp;
    *rty_SO_s_MaxSoftPos = (int16_T)(rtu_SI_s_MaxPos * 95 / 100);
    *rty_SO_s_MinSoftPos = (int16_T)(rtu_SI_s_MaxPos * 5 / 100);
    *rty_SO_s_IceBrkPos = (int16_T)(rtu_SI_s_MaxPos * 20 / 100);
    tmp = DHM_GetPosSts((real_T)rtu_SI_s_CurrentPos, (real_T)
                        *rty_SO_s_MinSoftPos, (real_T)*rty_SO_s_MaxSoftPos);
    if (tmp < 2.147483648E+9) {
      if (tmp >= -2.147483648E+9) {
        *rty_SO_m_DoorHndPosSts = DHM_safe_cast_to_HndPos_Sts_E((uint8_T)
          (int32_T)tmp);
      } else {
        *rty_SO_m_DoorHndPosSts = DHM_safe_cast_to_HndPos_Sts_E(0);
      }
    } else {
      *rty_SO_m_DoorHndPosSts = DHM_safe_cast_to_HndPos_Sts_E(MAX_uint8_T);
    }
  } else {
    *rty_SO_m_DoorHndPosSts = Hnd_Unknown;
  }

  /* End of Chart: '<S14>/DoorHndPos' */
}

/*
 * System initialize for atomic system:
 *    '<S14>/LearnLogic'
 *    '<S17>/LearnLogic'
 */
void DHM_LearnLogic_Init(uint8_T *rty_SO_e_MotorCmd, uint8_T *rty_SO_e_MotorPwm,
  boolean_T *rty_SO_b_CorrectPosToZero, boolean_T *rty_SO_b_CorrectPosToMax,
  Learn_Sts_E *rty_SO_m_LearnSts, int16_T *rty_SO_s_MaxPos)
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
 *    '<S14>/LearnLogic'
 *    '<S17>/LearnLogic'
 */
void DHM_LearnLogic(boolean_T rtu_SI_b_HallStall, Boolean rtu_SI_b_LearnReq,
                    Learn_Sts_E rtu_SI_m_LearnStsFromEE, int16_T
                    rtu_SI_s_MaxPosFromEE, SInt16 rtu_SI_s_CurrentPos, uint8_T
                    *rty_SO_e_MotorCmd, uint8_T *rty_SO_e_MotorPwm, boolean_T
                    *rty_SO_b_CorrectPosToZero, boolean_T
                    *rty_SO_b_CorrectPosToMax, Learn_Sts_E *rty_SO_m_LearnSts,
                    int16_T *rty_SO_s_MaxPos, DW_LearnLogic_DHM_T *localDW)
{
  if (localDW->temporalCounter_i1 < 255U) {
    localDW->temporalCounter_i1++;
  }

  localDW->SI_b_LearnReq_prev = localDW->SI_b_LearnReq_start;
  localDW->SI_b_LearnReq_start = rtu_SI_b_LearnReq;

  /* Chart: '<S14>/LearnLogic' */
  if (localDW->is_active_c3_DoorHndDriver == 0U) {
    localDW->SI_b_LearnReq_prev = rtu_SI_b_LearnReq;
    localDW->is_active_c3_DoorHndDriver = 1U;
    localDW->is_c3_DoorHndDriver = DHM_IN_PowerOn;
    localDW->temporalCounter_i1 = 0U;
    *rty_SO_m_LearnSts = rtu_SI_m_LearnStsFromEE;
    localDW->SI_e_AutoLearnCount = 0U;
    *rty_SO_s_MaxPos = rtu_SI_s_MaxPosFromEE;
  } else if (localDW->is_c3_DoorHndDriver == DHM_IN_LearnLogic) {
    boolean_T guard1 = false;
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

  /* End of Chart: '<S14>/LearnLogic' */
}

/*
 * System initialize for atomic system:
 *    '<S14>/MotorLogic'
 *    '<S17>/MotorLogic'
 */
void DHM_MotorLogic_Init(uint8_T *rty_SO_e_MotorCmd, boolean_T *rty_SO_b_MotorA,
  boolean_T *rty_SO_b_MotorB, uint8_T *rty_SO_e_MotorPwm)
{
  *rty_SO_e_MotorCmd = 0U;
  *rty_SO_b_MotorA = false;
  *rty_SO_b_MotorB = false;
  *rty_SO_e_MotorPwm = 0U;
}

/*
 * Output and update for atomic system:
 *    '<S14>/MotorLogic'
 *    '<S17>/MotorLogic'
 */
void DHM_MotorLogic(uint8_T rtu_SI_e_LearnMotorCmd, uint8_T
                    rtu_SI_e_LearnMotorPwm, uint8_T rtu_SI_e_CtrlMotorCmd,
                    uint8_T rtu_SI_e_CtrlMotorPwm, uint8_T *rty_SO_e_MotorCmd,
                    boolean_T *rty_SO_b_MotorA, uint8_T *rty_SO_e_MotorPwm,
                    DW_MotorLogic_DHM_T *localDW)
{
  /* Chart: '<S14>/MotorLogic' */
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

  /* End of Chart: '<S14>/MotorLogic' */
}

/*
 * System initialize for atomic system:
 *    '<S14>/Stall'
 *    '<S17>/Stall'
 */
void DHM_Stall_Init(boolean_T *rty_SO_b_HallStall)
{
  *rty_SO_b_HallStall = false;
}

/*
 * Output and update for atomic system:
 *    '<S14>/Stall'
 *    '<S17>/Stall'
 */
void DHM_Stall(SInt16 rtu_SI_s_CurrentPos, uint8_T rtu_SI_e_MotorCmd, boolean_T *
               rty_SO_b_HallStall, DW_Stall_DHM_T *localDW)
{
  if (localDW->temporalCounter_i1 < 63U) {
    localDW->temporalCounter_i1++;
  }

  /* Chart: '<S14>/Stall' */
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

  /* End of Chart: '<S14>/Stall' */
}

/*
 * System initialize for atomic system:
 *    '<S3>/FLDoorHndReq'
 *    '<S3>/FRDoorHndReq'
 *    '<S3>/RLDoorHndReq'
 *    '<S3>/RRDoorHndReq'
 */
void DHM_FLDoorHndReq_Init(boolean_T *rty_SO_b_HndUnfoldReq, boolean_T
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
                      boolean_T rtu_SI_b_DoorOpen, Door_Sts_E
                      rtu_SI_m_DoorLockSts, HndPos_Sts_E rtu_SI_m_HndPosSts,
                      boolean_T *rty_SO_b_HndUnfoldReq, boolean_T
                      *rty_SO_b_HndFoldReq, DW_FLDoorHndReq_DHM_T *localDW)
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
  Door_Sts_E rtb_DataTypeConversion7;
  HndPos_Sts_E rtb_DataTypeConversion4;
  HndPos_Sts_E rtb_DataTypeConversion6;
  uint8_T SO_e_MotorCmd_g;
  uint8_T SO_e_MotorPwm_ew;
  uint8_T SO_e_MotorPwm_k;
  boolean_T SO_b_CorrectPosToMax_b;
  boolean_T SO_b_CorrectPosToZero_j;
  boolean_T rtb_LogicalOperator1;

  /* RootInportFunctionCallGenerator generated from: '<Root>/DHM_Step' incorporates:
   *  SubSystem: '<Root>/DHM_Step_sys'
   */
  /* Logic: '<S3>/Logical Operator1' incorporates:
   *  Constant: '<S10>/Constant'
   *  Constant: '<S11>/Constant'
   *  Constant: '<S12>/Constant'
   *  Constant: '<S13>/Constant'
   *  Constant: '<S6>/Constant'
   *  Constant: '<S7>/Constant'
   *  Constant: '<S8>/Constant'
   *  Constant: '<S9>/Constant'
   *  Inport: '<Root>/VeINP_CAN_RHFDoorSts_sig_VeINP_CAN_RHFDoorSts_sig'
   *  Inport: '<Root>/VeINP_CAN_RHRDoorSts_sig_VeINP_CAN_RHRDoorSts_sig'
   *  Inport: '<Root>/VeOUT_SP_LHFdoorSts_sig_VeOUT_SP_LHFdoorSts_sig'
   *  Inport: '<Root>/VeOUT_SP_LHRdoorSts_sig_VeOUT_SP_LHRdoorSts_sig'
   *  Logic: '<S3>/Logical Operator'
   *  Logic: '<S3>/Logical Operator2'
   *  Logic: '<S3>/Logical Operator3'
   *  Logic: '<S3>/Logical Operator4'
   *  RelationalOperator: '<S10>/Compare'
   *  RelationalOperator: '<S11>/Compare'
   *  RelationalOperator: '<S12>/Compare'
   *  RelationalOperator: '<S13>/Compare'
   *  RelationalOperator: '<S6>/Compare'
   *  RelationalOperator: '<S7>/Compare'
   *  RelationalOperator: '<S8>/Compare'
   *  RelationalOperator: '<S9>/Compare'
   */
  rtb_LogicalOperator1 = ((DHM_U.VeOUT_SP_LHFdoorSts_sig_VeOUT_S == 1) ||
    (DHM_U.VeOUT_SP_LHFdoorSts_sig_VeOUT_S == 2) ||
    ((DHM_U.VeOUT_SP_LHRdoorSts_sig_VeOUT_S == 1) ||
     (DHM_U.VeOUT_SP_LHRdoorSts_sig_VeOUT_S == 2)) ||
    ((DHM_U.VeINP_CAN_RHFDoorSts_sig_VeINP_ == 1) ||
     (DHM_U.VeINP_CAN_RHFDoorSts_sig_VeINP_ == 2)) ||
    ((DHM_U.VeINP_CAN_RHRDoorSts_sig_VeINP_ == 1) ||
     (DHM_U.VeINP_CAN_RHRDoorSts_sig_VeINP_ == 2)));

  /* DataTypeConversion: '<S3>/Data Type Conversion7' incorporates:
   *  Inport: '<Root>/VeOUT_DLK_LHFDoorLockSts_sig_VeOUT_DLK_LHFDoorLockSts_sig'
   */
  rtb_DataTypeConversion7 = DHM_U.VeOUT_DLK_LHFDoorLockSts_sig_Ve;

  /* DataTypeConversion: '<S3>/Data Type Conversion4' incorporates:
   *  Inport: '<Root>/VeINP_CAN_FRDoorHandleSts_sig_VeINP_CAN_FRDoorHandleSts_sig'
   */
  rtb_DataTypeConversion4 = DHM_U.VeINP_CAN_FRDoorHandleSts_sig_V;

  /* Chart: '<S3>/FRDoorHndReq' incorporates:
   *  Inport: '<Root>/VbOUT_SP_CrashOutpSts_flg_VbOUT_SP_CrashOutpSts_flg'
   *  Inport: '<Root>/VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh'
   */
  DHM_FLDoorHndReq(DHM_U.VbOUT_SP_CrashOutpSts_flg_VbOUT,
                   DHM_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP, rtb_LogicalOperator1,
                   rtb_DataTypeConversion7, rtb_DataTypeConversion4,
                   &DHM_B.SO_b_HndUnfoldReq_k, &DHM_B.SO_b_HndFoldReq_d,
                   &DHM_DW.sf_FRDoorHndReq);

  /* DataTypeConversion: '<S3>/Data Type Conversion6' incorporates:
   *  Inport: '<Root>/VeINP_CAN_RRDoorHandleSts_sig_VeINP_CAN_RRDoorHandleSts_sig'
   */
  rtb_DataTypeConversion6 = DHM_U.VeINP_CAN_RRDoorHandleSts_sig_V;

  /* Chart: '<S3>/RRDoorHndReq' incorporates:
   *  Inport: '<Root>/VbOUT_SP_CrashOutpSts_flg_VbOUT_SP_CrashOutpSts_flg'
   *  Inport: '<Root>/VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh'
   */
  DHM_FLDoorHndReq(DHM_U.VbOUT_SP_CrashOutpSts_flg_VbOUT,
                   DHM_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP, rtb_LogicalOperator1,
                   rtb_DataTypeConversion7, rtb_DataTypeConversion6,
                   &DHM_B.SO_b_HndUnfoldReq, &DHM_B.SO_b_HndFoldReq,
                   &DHM_DW.sf_RRDoorHndReq);

  /* Chart: '<S3>/Chart' */
  if (DHM_DW.is_active_c1_DHM == 0U) {
    DHM_DW.is_active_c1_DHM = 1U;

    /* Outport: '<Root>/VeOUT_DHM_FRDoorHandleReq_sig_VeOUT_DHM_FRDoorHandleReq_sig' */
    DHM_Y.VeOUT_DHM_FRDoorHandleReq_sig_V = 0U;

    /* Outport: '<Root>/VeOUT_DHM_RRDoorHandleReq_sig_VeOUT_DHM_RRDoorHandleReq_sig' */
    DHM_Y.VeOUT_DHM_RRDoorHandleReq_sig_V = 0U;
  }

  /* End of Chart: '<S3>/Chart' */

  /* Outport: '<Root>/VbOUT_DHM_DoorHandleLrnReq_flg_VbOUT_DHM_DoorHandleLrnReq_flg' incorporates:
   *  Inport: '<Root>/VbINP_HWA_DoorHandleLrnReq_flg_VbINP_HWA_DoorHandleLrnReq_flg'
   *  SignalConversion generated from: '<S2>/VbINP_HWA_DoorHandleLrnReq_flg_VbINP_HWA_DoorHandleLrnReq_flg_read'
   */
  DHM_Y.VbOUT_DHM_DoorHandleLrnReq_flg_ = DHM_U.VbINP_HWA_DoorHandleLrnReq_flg_;

  /* Chart: '<S14>/LearnLogic' incorporates:
   *  Inport: '<Root>/VeINP_EPRM_FLDoorHandleLrnStsEE_sig_VeINP_EPRM_FLDoorHandleLrnStsEE_sig'
   *  Inport: '<Root>/VsINP_HWA_DriverHandleHall_sig_VsINP_HWA_DriverHandleHall_sig'
   *  Outport: '<Root>/VbOUT_DHM_DoorHandleLrnReq_flg_VbOUT_DHM_DoorHandleLrnReq_flg'
   *  Outport: '<Root>/VsINP_DHM_FLDoorHandleEE_sig_VsINP_DHM_FLDoorHandleEE_sig'
   *  UnitDelay: '<S14>/Unit Delay'
   */
  DHM_LearnLogic(DHM_B.SO_b_HallStall_m, DHM_Y.VbOUT_DHM_DoorHandleLrnReq_flg_,
                 DHM_U.VeINP_EPRM_FLDoorHandleLrnStsEE, 0,
                 DHM_U.VsINP_HWA_DriverHandleHall_sig_, &DHM_B.SO_e_MotorCmd_j,
                 &DHM_B.SO_e_MotorPwm_m, &SO_b_CorrectPosToZero_j,
                 &SO_b_CorrectPosToMax_b, &DHM_B.SO_m_LearnSts_b,
                 &DHM_Y.VsINP_DHM_FLDoorHandleEE_sig_Vs, &DHM_DW.sf_LearnLogic);

  /* Chart: '<S17>/LearnLogic' incorporates:
   *  Inport: '<Root>/VeINP_EPRM_RLDoorHandleLrnStsEE_sig_VeINP_EPRM_RLDoorHandleLrnStsEE_sig'
   *  Inport: '<Root>/VsINP_HWA_RLHandleHall_sig_VsINP_HWA_RLHandleHall_sig'
   *  Outport: '<Root>/VbOUT_DHM_DoorHandleLrnReq_flg_VbOUT_DHM_DoorHandleLrnReq_flg'
   *  Outport: '<Root>/VsINP_DHM_RLDoorHandleEE_sig_VsINP_DHM_RLDoorHandleEE_sig'
   *  UnitDelay: '<S17>/Unit Delay'
   */
  DHM_LearnLogic(DHM_B.SO_b_HallStall, DHM_Y.VbOUT_DHM_DoorHandleLrnReq_flg_,
                 DHM_U.VeINP_EPRM_RLDoorHandleLrnStsEE, 0,
                 DHM_U.VsINP_HWA_RLHandleHall_sig_VsIN, &DHM_B.SO_e_MotorCmd_a,
                 &DHM_B.SO_e_MotorPwm_e, &SO_b_CorrectPosToZero_j,
                 &SO_b_CorrectPosToMax_b, &DHM_B.SO_m_LearnSts,
                 &DHM_Y.VsINP_DHM_RLDoorHandleEE_sig_Vs, &DHM_DW.sf_LearnLogic_d);

  /* Chart: '<S3>/Chart1' incorporates:
   *  Inport: '<Root>/VeINP_CAN_FRDoorHandleLrnSts_sig_VeINP_CAN_FRDoorHandleLrnSts_sig'
   *  Inport: '<Root>/VeINP_CAN_RRDoorHandleLrnSts_sig_VeINP_CAN_RRDoorHandleLrnSts_sig'
   */
  if (DHM_DW.is_active_c2_DHM == 0U) {
    Learn_Sts_E tmp;
    Learn_Sts_E tmp_0;
    DHM_DW.is_active_c2_DHM = 1U;
    tmp = DHM_U.VeINP_CAN_FRDoorHandleLrnSts_si;
    tmp_0 = DHM_U.VeINP_CAN_RRDoorHandleLrnSts_si;
    if ((DHM_B.SO_m_LearnSts_b == Learn_Success) && (tmp == Learn_Success) &&
        (DHM_B.SO_m_LearnSts == Learn_Success) && (tmp_0 == Learn_Success)) {
      /* Outport: '<Root>/VeOUT_DHM_DoorHandleLrnSts_sig_VeOUT_DHM_DoorHandleLrnSts_sig' */
      DHM_Y.VeOUT_DHM_DoorHandleLrnSts_sig_ = 1U;
    } else if ((DHM_B.SO_m_LearnSts_b == Learn_Fail) || (tmp == Learn_Fail) ||
               (DHM_B.SO_m_LearnSts == Learn_Fail) || (tmp_0 == Learn_Fail)) {
      /* Outport: '<Root>/VeOUT_DHM_DoorHandleLrnSts_sig_VeOUT_DHM_DoorHandleLrnSts_sig' */
      DHM_Y.VeOUT_DHM_DoorHandleLrnSts_sig_ = 2U;
    } else {
      /* Outport: '<Root>/VeOUT_DHM_DoorHandleLrnSts_sig_VeOUT_DHM_DoorHandleLrnSts_sig' */
      DHM_Y.VeOUT_DHM_DoorHandleLrnSts_sig_ = 0U;
    }
  }

  /* End of Chart: '<S3>/Chart1' */

  /* Outport: '<Root>/VeOUT_DHM_FRHandleFoldedStatus_sig_VeOUT_DHM_FRHandleFoldedStatus_sig' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion1'
   *  DataTypeConversion: '<S3>/Data Type Conversion4'
   */
  DHM_Y.VeOUT_DHM_FRHandleFoldedStatus_ = rtb_DataTypeConversion4;

  /* Outport: '<Root>/VeOUT_DHM_FLDoorHandleLrnStsEE_sig_VeOUT_DHM_FLDoorHandleLrnStsEE_sig' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion10'
   */
  DHM_Y.VeOUT_DHM_FLDoorHandleLrnStsEE_ = DHM_B.SO_m_LearnSts_b;

  /* Outport: '<Root>/VeOUT_DHM_RLDoorHandleLrnStsEE_sig_VeOUT_DHM_RLDoorHandleLrnStsEE_sig' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion11'
   */
  DHM_Y.VeOUT_DHM_RLDoorHandleLrnStsEE_ = DHM_B.SO_m_LearnSts;

  /* Outport: '<Root>/VeOUT_DHM_RRHandleFoldedStatus_sig_VeOUT_DHM_RRHandleFoldedStatus_sig' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion2'
   *  DataTypeConversion: '<S3>/Data Type Conversion6'
   */
  DHM_Y.VeOUT_DHM_RRHandleFoldedStatus_ = rtb_DataTypeConversion6;

  /* Chart: '<S14>/DoorHndPos' incorporates:
   *  Inport: '<Root>/VsINP_HWA_DriverHandleHall_sig_VsINP_HWA_DriverHandleHall_sig'
   *  UnitDelay: '<S14>/Unit Delay5'
   */
  DHM_DoorHndPos(DHM_U.VsINP_HWA_DriverHandleHall_sig_, DHM_DW.UnitDelay5_DSTATE,
                 DHM_B.SO_m_LearnSts_b, &rtb_DataTypeConversion4,
                 &DHM_B.SO_s_MaxSoftPos_k, &DHM_B.SO_s_MinSoftPos_n,
                 &DHM_B.SO_s_IceBrkPos_k, &DHM_DW.sf_DoorHndPos);

  /* Outport: '<Root>/VeOUT_DHM_FLHandleFoldedStatus_sig_VeOUT_DHM_FLHandleFoldedStatus_sig' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion3'
   */
  DHM_Y.VeOUT_DHM_FLHandleFoldedStatus_ = rtb_DataTypeConversion4;

  /* Chart: '<S17>/DoorHndPos' incorporates:
   *  Inport: '<Root>/VsINP_HWA_RLHandleHall_sig_VsINP_HWA_RLHandleHall_sig'
   *  UnitDelay: '<S17>/Unit Delay5'
   */
  DHM_DoorHndPos(DHM_U.VsINP_HWA_RLHandleHall_sig_VsIN,
                 DHM_DW.UnitDelay5_DSTATE_h, DHM_B.SO_m_LearnSts,
                 &rtb_DataTypeConversion6, &DHM_B.SO_s_MaxSoftPos,
                 &DHM_B.SO_s_MinSoftPos, &DHM_B.SO_s_IceBrkPos,
                 &DHM_DW.sf_DoorHndPos_m);

  /* Outport: '<Root>/VeOUT_DHM_RLHandleFoldedStatus_sig_VeOUT_DHM_RLHandleFoldedStatus_sig' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion5'
   */
  DHM_Y.VeOUT_DHM_RLHandleFoldedStatus_ = rtb_DataTypeConversion6;

  /* Chart: '<S3>/FLDoorHndReq' incorporates:
   *  Inport: '<Root>/VbOUT_SP_CrashOutpSts_flg_VbOUT_SP_CrashOutpSts_flg'
   *  Inport: '<Root>/VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh'
   */
  DHM_FLDoorHndReq(DHM_U.VbOUT_SP_CrashOutpSts_flg_VbOUT,
                   DHM_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP, rtb_LogicalOperator1,
                   rtb_DataTypeConversion7, rtb_DataTypeConversion4,
                   &DHM_B.SO_b_HndUnfoldReq_j, &DHM_B.SO_b_HndFoldReq_dm,
                   &DHM_DW.sf_FLDoorHndReq);

  /* Chart: '<S14>/CtrlLogic' incorporates:
   *  Inport: '<Root>/VsINP_HWA_DriverHandleHall_sig_VsINP_HWA_DriverHandleHall_sig'
   *  UnitDelay: '<S14>/Unit Delay4'
   */
  DHM_CtrlLogic(DHM_DW.UnitDelay4_DSTATE, DHM_U.VsINP_HWA_DriverHandleHall_sig_,
                DHM_B.SO_s_MaxSoftPos_k, DHM_B.SO_s_MinSoftPos_n,
                DHM_B.SO_s_IceBrkPos_k, DHM_B.SO_b_HndFoldReq_dm,
                DHM_B.SO_b_HndUnfoldReq_j, DHM_B.SO_m_LearnSts_b,
                &SO_e_MotorCmd_g, &SO_e_MotorPwm_ew, &SO_b_CorrectPosToZero_j,
                &DHM_DW.sf_CtrlLogic);

  /* Chart: '<S14>/MotorLogic' incorporates:
   *  Outport: '<Root>/VbOUT_DHM_FLHadUnfold_flg_VbOUT_DHM_FLHadUnfold_flg'
   */
  DHM_MotorLogic(DHM_B.SO_e_MotorCmd_j, DHM_B.SO_e_MotorPwm_m, SO_e_MotorCmd_g,
                 SO_e_MotorPwm_ew, &DHM_B.SO_e_MotorCmd_c,
                 &DHM_Y.VbOUT_DHM_FLHadUnfold_flg_VbOUT, &SO_e_MotorPwm_k,
                 &DHM_DW.sf_MotorLogic);

  /* Chart: '<S14>/Stall' incorporates:
   *  Inport: '<Root>/VsINP_HWA_DriverHandleHall_sig_VsINP_HWA_DriverHandleHall_sig'
   *  UnitDelay: '<S14>/Unit Delay1'
   */
  DHM_Stall(DHM_U.VsINP_HWA_DriverHandleHall_sig_, DHM_DW.UnitDelay1_DSTATE,
            &DHM_B.SO_b_HallStall_m, &DHM_DW.sf_Stall);

  /* Chart: '<S3>/RLDoorHndReq' incorporates:
   *  Inport: '<Root>/VbOUT_SP_CrashOutpSts_flg_VbOUT_SP_CrashOutpSts_flg'
   *  Inport: '<Root>/VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh'
   */
  DHM_FLDoorHndReq(DHM_U.VbOUT_SP_CrashOutpSts_flg_VbOUT,
                   DHM_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP, rtb_LogicalOperator1,
                   rtb_DataTypeConversion7, rtb_DataTypeConversion6,
                   &DHM_B.SO_b_HndUnfoldReq_a, &DHM_B.SO_b_HndFoldReq_a,
                   &DHM_DW.sf_RLDoorHndReq);

  /* Chart: '<S17>/CtrlLogic' incorporates:
   *  Inport: '<Root>/VsINP_HWA_RLHandleHall_sig_VsINP_HWA_RLHandleHall_sig'
   *  UnitDelay: '<S17>/Unit Delay4'
   */
  DHM_CtrlLogic(DHM_DW.UnitDelay4_DSTATE_n,
                DHM_U.VsINP_HWA_RLHandleHall_sig_VsIN, DHM_B.SO_s_MaxSoftPos,
                DHM_B.SO_s_MinSoftPos, DHM_B.SO_s_IceBrkPos,
                DHM_B.SO_b_HndUnfoldReq_a, DHM_B.SO_b_HndFoldReq_a,
                DHM_B.SO_m_LearnSts, &SO_e_MotorCmd_g, &SO_e_MotorPwm_ew,
                &rtb_LogicalOperator1, &DHM_DW.sf_CtrlLogic_g);

  /* Chart: '<S17>/MotorLogic' incorporates:
   *  Outport: '<Root>/VbOUT_DHM_RLHandleUnfold_flg_VbOUT_DHM_RLHandleUnfold_flg'
   */
  DHM_MotorLogic(DHM_B.SO_e_MotorCmd_a, DHM_B.SO_e_MotorPwm_e, SO_e_MotorCmd_g,
                 SO_e_MotorPwm_ew, &DHM_B.SO_e_MotorCmd,
                 &DHM_Y.VbOUT_DHM_RLHandleUnfold_flg_Vb, &SO_e_MotorPwm_k,
                 &DHM_DW.sf_MotorLogic_l);

  /* Chart: '<S17>/Stall' incorporates:
   *  Inport: '<Root>/VsINP_HWA_RLHandleHall_sig_VsINP_HWA_RLHandleHall_sig'
   *  UnitDelay: '<S17>/Unit Delay1'
   */
  DHM_Stall(DHM_U.VsINP_HWA_RLHandleHall_sig_VsIN, DHM_DW.UnitDelay1_DSTATE_f,
            &DHM_B.SO_b_HallStall, &DHM_DW.sf_Stall_m);

  /* Update for UnitDelay: '<S14>/Unit Delay5' incorporates:
   *  Outport: '<Root>/VsINP_DHM_FLDoorHandleEE_sig_VsINP_DHM_FLDoorHandleEE_sig'
   */
  DHM_DW.UnitDelay5_DSTATE = DHM_Y.VsINP_DHM_FLDoorHandleEE_sig_Vs;

  /* Update for UnitDelay: '<S17>/Unit Delay5' incorporates:
   *  Outport: '<Root>/VsINP_DHM_RLDoorHandleEE_sig_VsINP_DHM_RLDoorHandleEE_sig'
   */
  DHM_DW.UnitDelay5_DSTATE_h = DHM_Y.VsINP_DHM_RLDoorHandleEE_sig_Vs;

  /* Update for UnitDelay: '<S14>/Unit Delay4' */
  DHM_DW.UnitDelay4_DSTATE = DHM_B.SO_b_HallStall_m;

  /* Update for UnitDelay: '<S14>/Unit Delay1' */
  DHM_DW.UnitDelay1_DSTATE = DHM_B.SO_e_MotorCmd_c;

  /* Update for UnitDelay: '<S17>/Unit Delay4' */
  DHM_DW.UnitDelay4_DSTATE_n = DHM_B.SO_b_HallStall;

  /* Update for UnitDelay: '<S17>/Unit Delay1' */
  DHM_DW.UnitDelay1_DSTATE_f = DHM_B.SO_e_MotorCmd;

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/DHM_Step' */
}

/* Model initialize function */
void DHM_initialize(void)
{
  {
    HndPos_Sts_E rtb_SO_m_DoorHndPosSts_h;
    uint8_T SO_e_MotorCmd_g;
    uint8_T SO_e_MotorPwm_ew;
    boolean_T SO_b_CorrectPosToMax_b;
    boolean_T SO_b_Error_f;

    /* SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/DHM_Step' incorporates:
     *  SubSystem: '<Root>/DHM_Step_sys'
     */

    /* SystemInitialize for Chart: '<S14>/CtrlLogic' */
    DHM_CtrlLogic_Init(&SO_e_MotorCmd_g, &SO_e_MotorPwm_ew, &SO_b_Error_f);

    /* SystemInitialize for Chart: '<S14>/DoorHndPos' */
    DHM_DoorHndPos_Init(&rtb_SO_m_DoorHndPosSts_h, &DHM_B.SO_s_MaxSoftPos_k,
                        &DHM_B.SO_s_MinSoftPos_n, &DHM_B.SO_s_IceBrkPos_k);

    /* SystemInitialize for Chart: '<S14>/LearnLogic' incorporates:
     *  Outport: '<Root>/VsINP_DHM_FLDoorHandleEE_sig_VsINP_DHM_FLDoorHandleEE_sig'
     */
    DHM_LearnLogic_Init(&DHM_B.SO_e_MotorCmd_j, &DHM_B.SO_e_MotorPwm_m,
                        &SO_b_Error_f, &SO_b_CorrectPosToMax_b,
                        &DHM_B.SO_m_LearnSts_b,
                        &DHM_Y.VsINP_DHM_FLDoorHandleEE_sig_Vs);

    /* SystemInitialize for Chart: '<S14>/MotorLogic' incorporates:
     *  Outport: '<Root>/VbOUT_DHM_FLHadFold_flg_VbOUT_DHM_FLHadFold_flg'
     *  Outport: '<Root>/VbOUT_DHM_FLHadUnfold_flg_VbOUT_DHM_FLHadUnfold_flg'
     */
    DHM_MotorLogic_Init(&DHM_B.SO_e_MotorCmd_c,
                        &DHM_Y.VbOUT_DHM_FLHadUnfold_flg_VbOUT,
                        &DHM_Y.VbOUT_DHM_FLHadFold_flg_VbOUT_D, &SO_e_MotorCmd_g);

    /* SystemInitialize for Chart: '<S14>/Stall' */
    DHM_Stall_Init(&DHM_B.SO_b_HallStall_m);

    /* SystemInitialize for Chart: '<S3>/FLDoorHndReq' */
    DHM_FLDoorHndReq_Init(&DHM_B.SO_b_HndUnfoldReq_j, &DHM_B.SO_b_HndFoldReq_dm);

    /* SystemInitialize for Chart: '<S3>/FRDoorHndReq' */
    DHM_FLDoorHndReq_Init(&DHM_B.SO_b_HndUnfoldReq_k, &DHM_B.SO_b_HndFoldReq_d);

    /* SystemInitialize for Chart: '<S17>/CtrlLogic' */
    DHM_CtrlLogic_Init(&SO_e_MotorCmd_g, &SO_e_MotorPwm_ew, &SO_b_Error_f);

    /* SystemInitialize for Chart: '<S17>/DoorHndPos' */
    DHM_DoorHndPos_Init(&rtb_SO_m_DoorHndPosSts_h, &DHM_B.SO_s_MaxSoftPos,
                        &DHM_B.SO_s_MinSoftPos, &DHM_B.SO_s_IceBrkPos);

    /* SystemInitialize for Chart: '<S17>/LearnLogic' incorporates:
     *  Outport: '<Root>/VsINP_DHM_RLDoorHandleEE_sig_VsINP_DHM_RLDoorHandleEE_sig'
     */
    DHM_LearnLogic_Init(&DHM_B.SO_e_MotorCmd_a, &DHM_B.SO_e_MotorPwm_e,
                        &SO_b_Error_f, &SO_b_CorrectPosToMax_b,
                        &DHM_B.SO_m_LearnSts,
                        &DHM_Y.VsINP_DHM_RLDoorHandleEE_sig_Vs);

    /* SystemInitialize for Chart: '<S17>/MotorLogic' incorporates:
     *  Outport: '<Root>/VbOUT_DHM_RLHandleFold_flg_VbOUT_DHM_RLHandleFold_flg'
     *  Outport: '<Root>/VbOUT_DHM_RLHandleUnfold_flg_VbOUT_DHM_RLHandleUnfold_flg'
     */
    DHM_MotorLogic_Init(&DHM_B.SO_e_MotorCmd,
                        &DHM_Y.VbOUT_DHM_RLHandleUnfold_flg_Vb,
                        &DHM_Y.VbOUT_DHM_RLHandleFold_flg_VbOU, &SO_e_MotorCmd_g);

    /* SystemInitialize for Chart: '<S17>/Stall' */
    DHM_Stall_Init(&DHM_B.SO_b_HallStall);

    /* SystemInitialize for Chart: '<S3>/RLDoorHndReq' */
    DHM_FLDoorHndReq_Init(&DHM_B.SO_b_HndUnfoldReq_a, &DHM_B.SO_b_HndFoldReq_a);

    /* SystemInitialize for Chart: '<S3>/RRDoorHndReq' */
    DHM_FLDoorHndReq_Init(&DHM_B.SO_b_HndUnfoldReq, &DHM_B.SO_b_HndFoldReq);

    /* End of SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/DHM_Step' */
  }
}

/* Model terminate function */
void DHM_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
