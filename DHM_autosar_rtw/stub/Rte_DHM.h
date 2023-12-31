/* This file contains stub implementations of the AUTOSAR RTE functions.
   The stub implementations can be used for testing the generated code in
   Simulink, for example, in SIL/PIL simulations of the component under
   test. Note that this file should be replaced with an appropriate RTE
   file when deploying the generated code outside of Simulink.

   This file is generated for:
   Atomic software component:  "DHM"
   ARXML schema: "4.3"
   File generated on: "28-Oct-2023 12:28:29"  */

#ifndef Rte_DHM_h
#define Rte_DHM_h
#include "Rte_Type.h"
#include "Compiler.h"

/* Data access functions */
#define Rte_Write_VsINP_DHM_FLDoorHandleEE_sig_VsINP_DHM_FLDoorHandleEE_sig Rte_Write_DHM_VsINP_DHM_FLDoorHandleEE_sig_VsINP_DHM_FLDoorHandleEE_sig

Std_ReturnType
  Rte_Write_VsINP_DHM_FLDoorHandleEE_sig_VsINP_DHM_FLDoorHandleEE_sig(SInt16 u);

#define Rte_Invalidate_VsINP_DHM_FLDoorHandleEE_sig_VsINP_DHM_FLDoorHandleEE_sig Rte_Invalidate_DHM_VsINP_DHM_FLDoorHandleEE_sig_VsINP_DHM_FLDoorHandleEE_sig

Std_ReturnType
  Rte_Invalidate_VsINP_DHM_FLDoorHandleEE_sig_VsINP_DHM_FLDoorHandleEE_sig(void);

#define Rte_Write_VsINP_DHM_RLDoorHandleEE_sig_VsINP_DHM_RLDoorHandleEE_sig Rte_Write_DHM_VsINP_DHM_RLDoorHandleEE_sig_VsINP_DHM_RLDoorHandleEE_sig

Std_ReturnType
  Rte_Write_VsINP_DHM_RLDoorHandleEE_sig_VsINP_DHM_RLDoorHandleEE_sig(SInt16 u);

#define Rte_Invalidate_VsINP_DHM_RLDoorHandleEE_sig_VsINP_DHM_RLDoorHandleEE_sig Rte_Invalidate_DHM_VsINP_DHM_RLDoorHandleEE_sig_VsINP_DHM_RLDoorHandleEE_sig

Std_ReturnType
  Rte_Invalidate_VsINP_DHM_RLDoorHandleEE_sig_VsINP_DHM_RLDoorHandleEE_sig(void);

#define Rte_Read_VbINP_HWA_DoorHandleLrnReq_flg_VbINP_HWA_DoorHandleLrnReq_flg Rte_Read_DHM_VbINP_HWA_DoorHandleLrnReq_flg_VbINP_HWA_DoorHandleLrnReq_flg

Std_ReturnType
  Rte_Read_VbINP_HWA_DoorHandleLrnReq_flg_VbINP_HWA_DoorHandleLrnReq_flg(Boolean*
  u);

#define Rte_Read_VbOUT_SP_CrashOutpSts_flg_VbOUT_SP_CrashOutpSts_flg Rte_Read_DHM_VbOUT_SP_CrashOutpSts_flg_VbOUT_SP_CrashOutpSts_flg

Std_ReturnType Rte_Read_VbOUT_SP_CrashOutpSts_flg_VbOUT_SP_CrashOutpSts_flg
  (Boolean* u);

#define Rte_Read_VeINP_CAN_FRDoorHandleLrnSts_sig_VeINP_CAN_FRDoorHandleLrnSts_sig Rte_Read_DHM_VeINP_CAN_FRDoorHandleLrnSts_sig_VeINP_CAN_FRDoorHandleLrnSts_sig

Std_ReturnType
  Rte_Read_VeINP_CAN_FRDoorHandleLrnSts_sig_VeINP_CAN_FRDoorHandleLrnSts_sig
  (UInt8* u);

#define Rte_Read_VeINP_CAN_FRDoorHandleSts_sig_VeINP_CAN_FRDoorHandleSts_sig Rte_Read_DHM_VeINP_CAN_FRDoorHandleSts_sig_VeINP_CAN_FRDoorHandleSts_sig

Std_ReturnType
  Rte_Read_VeINP_CAN_FRDoorHandleSts_sig_VeINP_CAN_FRDoorHandleSts_sig(UInt8* u);

#define Rte_Read_VeINP_CAN_RHFDoorSts_sig_VeINP_CAN_RHFDoorSts_sig Rte_Read_DHM_VeINP_CAN_RHFDoorSts_sig_VeINP_CAN_RHFDoorSts_sig

Std_ReturnType Rte_Read_VeINP_CAN_RHFDoorSts_sig_VeINP_CAN_RHFDoorSts_sig(UInt8*
  u);

#define Rte_Read_VeINP_CAN_RHRDoorSts_sig_VeINP_CAN_RHRDoorSts_sig Rte_Read_DHM_VeINP_CAN_RHRDoorSts_sig_VeINP_CAN_RHRDoorSts_sig

Std_ReturnType Rte_Read_VeINP_CAN_RHRDoorSts_sig_VeINP_CAN_RHRDoorSts_sig(UInt8*
  u);

#define Rte_Read_VeINP_CAN_RRDoorHandleLrnSts_sig_VeINP_CAN_RRDoorHandleLrnSts_sig Rte_Read_DHM_VeINP_CAN_RRDoorHandleLrnSts_sig_VeINP_CAN_RRDoorHandleLrnSts_sig

Std_ReturnType
  Rte_Read_VeINP_CAN_RRDoorHandleLrnSts_sig_VeINP_CAN_RRDoorHandleLrnSts_sig
  (UInt8* u);

#define Rte_Read_VeINP_CAN_RRDoorHandleSts_sig_VeINP_CAN_RRDoorHandleSts_sig Rte_Read_DHM_VeINP_CAN_RRDoorHandleSts_sig_VeINP_CAN_RRDoorHandleSts_sig

Std_ReturnType
  Rte_Read_VeINP_CAN_RRDoorHandleSts_sig_VeINP_CAN_RRDoorHandleSts_sig(UInt8* u);

#define Rte_Read_VeINP_EPRM_FLDoorHandleLrnStsEE_sig_VeINP_EPRM_FLDoorHandleLrnStsEE_sig Rte_Read_DHM_VeINP_EPRM_FLDoorHandleLrnStsEE_sig_VeINP_EPRM_FLDoorHandleLrnStsEE_sig

Std_ReturnType
  Rte_Read_VeINP_EPRM_FLDoorHandleLrnStsEE_sig_VeINP_EPRM_FLDoorHandleLrnStsEE_sig
  (UInt8* u);

#define Rte_Read_VeINP_EPRM_RLDoorHandleLrnStsEE_sig_VeINP_EPRM_RLDoorHandleLrnStsEE_sig Rte_Read_DHM_VeINP_EPRM_RLDoorHandleLrnStsEE_sig_VeINP_EPRM_RLDoorHandleLrnStsEE_sig

Std_ReturnType
  Rte_Read_VeINP_EPRM_RLDoorHandleLrnStsEE_sig_VeINP_EPRM_RLDoorHandleLrnStsEE_sig
  (UInt8* u);

#define Rte_Read_VeOUT_DLK_LHFDoorLockSts_sig_VeOUT_DLK_LHFDoorLockSts_sig Rte_Read_DHM_VeOUT_DLK_LHFDoorLockSts_sig_VeOUT_DLK_LHFDoorLockSts_sig

Std_ReturnType
  Rte_Read_VeOUT_DLK_LHFDoorLockSts_sig_VeOUT_DLK_LHFDoorLockSts_sig(UInt8* u);

#define Rte_Read_VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh Rte_Read_DHM_VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh

Std_ReturnType Rte_Read_VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh(UInt8* u);

#define Rte_Read_VeOUT_SP_LHFdoorSts_sig_VeOUT_SP_LHFdoorSts_sig Rte_Read_DHM_VeOUT_SP_LHFdoorSts_sig_VeOUT_SP_LHFdoorSts_sig

Std_ReturnType Rte_Read_VeOUT_SP_LHFdoorSts_sig_VeOUT_SP_LHFdoorSts_sig(UInt8* u);

#define Rte_Read_VeOUT_SP_LHRdoorSts_sig_VeOUT_SP_LHRdoorSts_sig Rte_Read_DHM_VeOUT_SP_LHRdoorSts_sig_VeOUT_SP_LHRdoorSts_sig

Std_ReturnType Rte_Read_VeOUT_SP_LHRdoorSts_sig_VeOUT_SP_LHRdoorSts_sig(UInt8* u);

#define Rte_Read_VsINP_EPRM_FLDoorHandleFromEE_sig_VsINP_EPRM_FLDoorHandleFromEE_sig Rte_Read_DHM_VsINP_EPRM_FLDoorHandleFromEE_sig_VsINP_EPRM_FLDoorHandleFromEE_sig

Std_ReturnType
  Rte_Read_VsINP_EPRM_FLDoorHandleFromEE_sig_VsINP_EPRM_FLDoorHandleFromEE_sig
  (SInt16* u);

#define Rte_Read_VsINP_EPRM_RLDoorHandleFromEE_sig_VsINP_EPRM_RLDoorHandleFromEE_sig Rte_Read_DHM_VsINP_EPRM_RLDoorHandleFromEE_sig_VsINP_EPRM_RLDoorHandleFromEE_sig

Std_ReturnType
  Rte_Read_VsINP_EPRM_RLDoorHandleFromEE_sig_VsINP_EPRM_RLDoorHandleFromEE_sig
  (SInt16* u);

#define Rte_Read_VsINP_HWA_DriverHandleHall_sig_VsINP_HWA_DriverHandleHall_sig Rte_Read_DHM_VsINP_HWA_DriverHandleHall_sig_VsINP_HWA_DriverHandleHall_sig

Std_ReturnType
  Rte_Read_VsINP_HWA_DriverHandleHall_sig_VsINP_HWA_DriverHandleHall_sig(SInt16*
  u);

#define Rte_Read_VsINP_HWA_RLHandleHall_sig_VsINP_HWA_RLHandleHall_sig Rte_Read_DHM_VsINP_HWA_RLHandleHall_sig_VsINP_HWA_RLHandleHall_sig

Std_ReturnType Rte_Read_VsINP_HWA_RLHandleHall_sig_VsINP_HWA_RLHandleHall_sig
  (SInt16* u);

#define Rte_Write_VeOUT_DHM_FLHandleFoldedStatus_sig_VeOUT_DHM_FLHandleFoldedStatus_sig Rte_Write_DHM_VeOUT_DHM_FLHandleFoldedStatus_sig_VeOUT_DHM_FLHandleFoldedStatus_sig

Std_ReturnType
  Rte_Write_VeOUT_DHM_FLHandleFoldedStatus_sig_VeOUT_DHM_FLHandleFoldedStatus_sig
  (UInt8 u);

#define Rte_Invalidate_VeOUT_DHM_FLHandleFoldedStatus_sig_VeOUT_DHM_FLHandleFoldedStatus_sig Rte_Invalidate_DHM_VeOUT_DHM_FLHandleFoldedStatus_sig_VeOUT_DHM_FLHandleFoldedStatus_sig

Std_ReturnType
  Rte_Invalidate_VeOUT_DHM_FLHandleFoldedStatus_sig_VeOUT_DHM_FLHandleFoldedStatus_sig
  (void);

#define Rte_Write_VeOUT_DHM_RLHandleFoldedStatus_sig_VeOUT_DHM_RLHandleFoldedStatus_sig Rte_Write_DHM_VeOUT_DHM_RLHandleFoldedStatus_sig_VeOUT_DHM_RLHandleFoldedStatus_sig

Std_ReturnType
  Rte_Write_VeOUT_DHM_RLHandleFoldedStatus_sig_VeOUT_DHM_RLHandleFoldedStatus_sig
  (UInt8 u);

#define Rte_Invalidate_VeOUT_DHM_RLHandleFoldedStatus_sig_VeOUT_DHM_RLHandleFoldedStatus_sig Rte_Invalidate_DHM_VeOUT_DHM_RLHandleFoldedStatus_sig_VeOUT_DHM_RLHandleFoldedStatus_sig

Std_ReturnType
  Rte_Invalidate_VeOUT_DHM_RLHandleFoldedStatus_sig_VeOUT_DHM_RLHandleFoldedStatus_sig
  (void);

#define Rte_Write_VeOUT_DHM_FRHandleFoldedStatus_sig_VeOUT_DHM_FRHandleFoldedStatus_sig Rte_Write_DHM_VeOUT_DHM_FRHandleFoldedStatus_sig_VeOUT_DHM_FRHandleFoldedStatus_sig

Std_ReturnType
  Rte_Write_VeOUT_DHM_FRHandleFoldedStatus_sig_VeOUT_DHM_FRHandleFoldedStatus_sig
  (UInt8 u);

#define Rte_Invalidate_VeOUT_DHM_FRHandleFoldedStatus_sig_VeOUT_DHM_FRHandleFoldedStatus_sig Rte_Invalidate_DHM_VeOUT_DHM_FRHandleFoldedStatus_sig_VeOUT_DHM_FRHandleFoldedStatus_sig

Std_ReturnType
  Rte_Invalidate_VeOUT_DHM_FRHandleFoldedStatus_sig_VeOUT_DHM_FRHandleFoldedStatus_sig
  (void);

#define Rte_Write_VeOUT_DHM_RRHandleFoldedStatus_sig_VeOUT_DHM_RRHandleFoldedStatus_sig Rte_Write_DHM_VeOUT_DHM_RRHandleFoldedStatus_sig_VeOUT_DHM_RRHandleFoldedStatus_sig

Std_ReturnType
  Rte_Write_VeOUT_DHM_RRHandleFoldedStatus_sig_VeOUT_DHM_RRHandleFoldedStatus_sig
  (UInt8 u);

#define Rte_Invalidate_VeOUT_DHM_RRHandleFoldedStatus_sig_VeOUT_DHM_RRHandleFoldedStatus_sig Rte_Invalidate_DHM_VeOUT_DHM_RRHandleFoldedStatus_sig_VeOUT_DHM_RRHandleFoldedStatus_sig

Std_ReturnType
  Rte_Invalidate_VeOUT_DHM_RRHandleFoldedStatus_sig_VeOUT_DHM_RRHandleFoldedStatus_sig
  (void);

#define Rte_Write_VeOUT_DHM_FRDoorHandleReq_sig_VeOUT_DHM_FRDoorHandleReq_sig Rte_Write_DHM_VeOUT_DHM_FRDoorHandleReq_sig_VeOUT_DHM_FRDoorHandleReq_sig

Std_ReturnType
  Rte_Write_VeOUT_DHM_FRDoorHandleReq_sig_VeOUT_DHM_FRDoorHandleReq_sig(UInt8 u);

#define Rte_Invalidate_VeOUT_DHM_FRDoorHandleReq_sig_VeOUT_DHM_FRDoorHandleReq_sig Rte_Invalidate_DHM_VeOUT_DHM_FRDoorHandleReq_sig_VeOUT_DHM_FRDoorHandleReq_sig

Std_ReturnType
  Rte_Invalidate_VeOUT_DHM_FRDoorHandleReq_sig_VeOUT_DHM_FRDoorHandleReq_sig
  (void);

#define Rte_Write_VeOUT_DHM_RRDoorHandleReq_sig_VeOUT_DHM_RRDoorHandleReq_sig Rte_Write_DHM_VeOUT_DHM_RRDoorHandleReq_sig_VeOUT_DHM_RRDoorHandleReq_sig

Std_ReturnType
  Rte_Write_VeOUT_DHM_RRDoorHandleReq_sig_VeOUT_DHM_RRDoorHandleReq_sig(UInt8 u);

#define Rte_Invalidate_VeOUT_DHM_RRDoorHandleReq_sig_VeOUT_DHM_RRDoorHandleReq_sig Rte_Invalidate_DHM_VeOUT_DHM_RRDoorHandleReq_sig_VeOUT_DHM_RRDoorHandleReq_sig

Std_ReturnType
  Rte_Invalidate_VeOUT_DHM_RRDoorHandleReq_sig_VeOUT_DHM_RRDoorHandleReq_sig
  (void);

#define Rte_Write_VbOUT_DHM_FLHadUnfold_flg_VbOUT_DHM_FLHadUnfold_flg Rte_Write_DHM_VbOUT_DHM_FLHadUnfold_flg_VbOUT_DHM_FLHadUnfold_flg

Std_ReturnType Rte_Write_VbOUT_DHM_FLHadUnfold_flg_VbOUT_DHM_FLHadUnfold_flg
  (Boolean u);

#define Rte_Invalidate_VbOUT_DHM_FLHadUnfold_flg_VbOUT_DHM_FLHadUnfold_flg Rte_Invalidate_DHM_VbOUT_DHM_FLHadUnfold_flg_VbOUT_DHM_FLHadUnfold_flg

Std_ReturnType
  Rte_Invalidate_VbOUT_DHM_FLHadUnfold_flg_VbOUT_DHM_FLHadUnfold_flg(void);

#define Rte_Write_VbOUT_DHM_FLHadFold_flg_VbOUT_DHM_FLHadFold_flg Rte_Write_DHM_VbOUT_DHM_FLHadFold_flg_VbOUT_DHM_FLHadFold_flg

Std_ReturnType Rte_Write_VbOUT_DHM_FLHadFold_flg_VbOUT_DHM_FLHadFold_flg(Boolean
  u);

#define Rte_Invalidate_VbOUT_DHM_FLHadFold_flg_VbOUT_DHM_FLHadFold_flg Rte_Invalidate_DHM_VbOUT_DHM_FLHadFold_flg_VbOUT_DHM_FLHadFold_flg

Std_ReturnType Rte_Invalidate_VbOUT_DHM_FLHadFold_flg_VbOUT_DHM_FLHadFold_flg
  (void);

#define Rte_Write_VbOUT_DHM_RLHandleUnfold_flg_VbOUT_DHM_RLHandleUnfold_flg Rte_Write_DHM_VbOUT_DHM_RLHandleUnfold_flg_VbOUT_DHM_RLHandleUnfold_flg

Std_ReturnType
  Rte_Write_VbOUT_DHM_RLHandleUnfold_flg_VbOUT_DHM_RLHandleUnfold_flg(Boolean u);

#define Rte_Invalidate_VbOUT_DHM_RLHandleUnfold_flg_VbOUT_DHM_RLHandleUnfold_flg Rte_Invalidate_DHM_VbOUT_DHM_RLHandleUnfold_flg_VbOUT_DHM_RLHandleUnfold_flg

Std_ReturnType
  Rte_Invalidate_VbOUT_DHM_RLHandleUnfold_flg_VbOUT_DHM_RLHandleUnfold_flg(void);

#define Rte_Write_VbOUT_DHM_RLHandleFold_flg_VbOUT_DHM_RLHandleFold_flg Rte_Write_DHM_VbOUT_DHM_RLHandleFold_flg_VbOUT_DHM_RLHandleFold_flg

Std_ReturnType Rte_Write_VbOUT_DHM_RLHandleFold_flg_VbOUT_DHM_RLHandleFold_flg
  (Boolean u);

#define Rte_Invalidate_VbOUT_DHM_RLHandleFold_flg_VbOUT_DHM_RLHandleFold_flg Rte_Invalidate_DHM_VbOUT_DHM_RLHandleFold_flg_VbOUT_DHM_RLHandleFold_flg

Std_ReturnType
  Rte_Invalidate_VbOUT_DHM_RLHandleFold_flg_VbOUT_DHM_RLHandleFold_flg(void);

#define Rte_Write_VsINP_DHM_FLDoorHandleEE_sig_VsINP_DHM_FLDoorHandleEE_sig Rte_Write_DHM_VsINP_DHM_FLDoorHandleEE_sig_VsINP_DHM_FLDoorHandleEE_sig

Std_ReturnType
  Rte_Write_VsINP_DHM_FLDoorHandleEE_sig_VsINP_DHM_FLDoorHandleEE_sig(SInt16 u);

#define Rte_Invalidate_VsINP_DHM_FLDoorHandleEE_sig_VsINP_DHM_FLDoorHandleEE_sig Rte_Invalidate_DHM_VsINP_DHM_FLDoorHandleEE_sig_VsINP_DHM_FLDoorHandleEE_sig

Std_ReturnType
  Rte_Invalidate_VsINP_DHM_FLDoorHandleEE_sig_VsINP_DHM_FLDoorHandleEE_sig(void);

#define Rte_Write_VsINP_DHM_RLDoorHandleEE_sig_VsINP_DHM_RLDoorHandleEE_sig Rte_Write_DHM_VsINP_DHM_RLDoorHandleEE_sig_VsINP_DHM_RLDoorHandleEE_sig

Std_ReturnType
  Rte_Write_VsINP_DHM_RLDoorHandleEE_sig_VsINP_DHM_RLDoorHandleEE_sig(SInt16 u);

#define Rte_Invalidate_VsINP_DHM_RLDoorHandleEE_sig_VsINP_DHM_RLDoorHandleEE_sig Rte_Invalidate_DHM_VsINP_DHM_RLDoorHandleEE_sig_VsINP_DHM_RLDoorHandleEE_sig

Std_ReturnType
  Rte_Invalidate_VsINP_DHM_RLDoorHandleEE_sig_VsINP_DHM_RLDoorHandleEE_sig(void);

#define Rte_Write_VeOUT_DHM_DoorHandleLrnSts_sig_VeOUT_DHM_DoorHandleLrnSts_sig Rte_Write_DHM_VeOUT_DHM_DoorHandleLrnSts_sig_VeOUT_DHM_DoorHandleLrnSts_sig

Std_ReturnType
  Rte_Write_VeOUT_DHM_DoorHandleLrnSts_sig_VeOUT_DHM_DoorHandleLrnSts_sig(UInt8
  u);

#define Rte_Invalidate_VeOUT_DHM_DoorHandleLrnSts_sig_VeOUT_DHM_DoorHandleLrnSts_sig Rte_Invalidate_DHM_VeOUT_DHM_DoorHandleLrnSts_sig_VeOUT_DHM_DoorHandleLrnSts_sig

Std_ReturnType
  Rte_Invalidate_VeOUT_DHM_DoorHandleLrnSts_sig_VeOUT_DHM_DoorHandleLrnSts_sig
  (void);

#define Rte_Write_VeOUT_DHM_FLDoorHandleLrnStsEE_sig_VeOUT_DHM_FLDoorHandleLrnStsEE_sig Rte_Write_DHM_VeOUT_DHM_FLDoorHandleLrnStsEE_sig_VeOUT_DHM_FLDoorHandleLrnStsEE_sig

Std_ReturnType
  Rte_Write_VeOUT_DHM_FLDoorHandleLrnStsEE_sig_VeOUT_DHM_FLDoorHandleLrnStsEE_sig
  (UInt8 u);

#define Rte_Invalidate_VeOUT_DHM_FLDoorHandleLrnStsEE_sig_VeOUT_DHM_FLDoorHandleLrnStsEE_sig Rte_Invalidate_DHM_VeOUT_DHM_FLDoorHandleLrnStsEE_sig_VeOUT_DHM_FLDoorHandleLrnStsEE_sig

Std_ReturnType
  Rte_Invalidate_VeOUT_DHM_FLDoorHandleLrnStsEE_sig_VeOUT_DHM_FLDoorHandleLrnStsEE_sig
  (void);

#define Rte_Write_VeOUT_DHM_RLDoorHandleLrnStsEE_sig_VeOUT_DHM_RLDoorHandleLrnStsEE_sig Rte_Write_DHM_VeOUT_DHM_RLDoorHandleLrnStsEE_sig_VeOUT_DHM_RLDoorHandleLrnStsEE_sig

Std_ReturnType
  Rte_Write_VeOUT_DHM_RLDoorHandleLrnStsEE_sig_VeOUT_DHM_RLDoorHandleLrnStsEE_sig
  (UInt8 u);

#define Rte_Invalidate_VeOUT_DHM_RLDoorHandleLrnStsEE_sig_VeOUT_DHM_RLDoorHandleLrnStsEE_sig Rte_Invalidate_DHM_VeOUT_DHM_RLDoorHandleLrnStsEE_sig_VeOUT_DHM_RLDoorHandleLrnStsEE_sig

Std_ReturnType
  Rte_Invalidate_VeOUT_DHM_RLDoorHandleLrnStsEE_sig_VeOUT_DHM_RLDoorHandleLrnStsEE_sig
  (void);

#define Rte_Write_VbOUT_DHM_DoorHandleLrnReq_flg_VbOUT_DHM_DoorHandleLrnReq_flg Rte_Write_DHM_VbOUT_DHM_DoorHandleLrnReq_flg_VbOUT_DHM_DoorHandleLrnReq_flg

Std_ReturnType
  Rte_Write_VbOUT_DHM_DoorHandleLrnReq_flg_VbOUT_DHM_DoorHandleLrnReq_flg
  (Boolean u);

#define Rte_Invalidate_VbOUT_DHM_DoorHandleLrnReq_flg_VbOUT_DHM_DoorHandleLrnReq_flg Rte_Invalidate_DHM_VbOUT_DHM_DoorHandleLrnReq_flg_VbOUT_DHM_DoorHandleLrnReq_flg

Std_ReturnType
  Rte_Invalidate_VbOUT_DHM_DoorHandleLrnReq_flg_VbOUT_DHM_DoorHandleLrnReq_flg
  (void);

/* Entry point functions */
extern FUNC(void, DHM_CODE) DHM_Init(void);
extern FUNC(void, DHM_CODE) DHM_Step(void);

#endif
