/*
* Configuration of module: PduR
*
* Created by:   parai          
* Copyright:    (C)parai@foxmail.com  
*
* Configured for (MCU):    MinGW ...
*
* Module vendor:           ArcCore
* Generator version:       2.0.34
*
* Generated by easySAR Studio (https://github.com/parai/OpenSAR)
*/

#ifndef PDUR_PB_CFG_H_H
#define PDUR_PB_CFG_H_H
#if !(((PDUR_SW_MAJOR_VERSION == 2) && (PDUR_SW_MINOR_VERSION == 0)) )
#error PduR: Configuration file expected BSW module version to be 2.0.*
#endif

#include "Dcm.h"
#include "Com.h"
#include "CanIf.h"
#include "CanTp.h"

extern const PduR_PBConfigType PduR_Config;

#if(PDUR_ZERO_COST_OPERATION == STD_OFF)
#define PDUR_ID_TxDiagP2P                        0
#define PDUR_ID2_TxDiagP2P                       0
#define PDUR_ID_RxDiagP2P                        1
#define PDUR_ID_TxDiagP2A                        2
#define PDUR_ID2_TxDiagP2A                       2
#define PDUR_ID_RxDiagP2A                        3
#define PDUR_ID_TxMsgTime                        4
#define PDUR_ID2_TxMsgTime                       4
#define PDUR_ID_RxMsgAbsInfo                     5

#else
#define PDUR_ID_TxDiagP2P                        CANTP_ID_TxDiagP2P
#define PDUR_ID2_TxDiagP2P                       DCM_ID_TxDiagP2P
#define PDUR_ID_RxDiagP2P                        DCM_ID_RxDiagP2P
#define PDUR_ID2_RxDiagP2P                       CANTP_ID_RxDiagP2P
#define PDUR_ID_TxDiagP2A                        CANTP_ID_TxDiagP2A
#define PDUR_ID2_TxDiagP2A                       DCM_ID_TxDiagP2A
#define PDUR_ID_RxDiagP2A                        DCM_ID_RxDiagP2A
#define PDUR_ID2_RxDiagP2A                       CANTP_ID_RxDiagP2A
#define PDUR_ID_TxMsgTime                        CANIF_ID_TxMsgTime
#define PDUR_ID2_TxMsgTime                       COM_ID_TxMsgTime
#define PDUR_ID_RxMsgAbsInfo                     COM_ID_RxMsgAbsInfo
#define PDUR_ID2_RxMsgAbsInfo                    CANIF_ID_RxMsgAbsInfo

#endif

#endif /* PDUR_PB_CFG_H_H */

