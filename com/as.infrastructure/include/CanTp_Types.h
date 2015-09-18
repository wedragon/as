/* -------------------------------- Arctic Core ------------------------------
 * Arctic Core - the open source AUTOSAR platform http://arccore.com
 *
 * Copyright (C) 2009  ArcCore AB <contact@arccore.com>
 *
 * This source code is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 as published by the
 * Free Software Foundation; See <http://www.gnu.org/licenses/old-licenses/gpl-2.0.txt>.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * for more details.
 * -------------------------------- Arctic Core ------------------------------*/

/*
 *  General requirements
 */
/** @req CANTP160 */

/*
 * Definitions generated by tools
 */
/** @req CANTP239 */
/** @req CANTP242 */

//lint -save -e451 //PC-Lint Wrong interpretation, "Platform_Types.h included twice without a standard include guard."

#ifndef CANTP_TYPES_H_
#define CANTP_TYPES_H_

#include "ComStack_Types.h"

// - - - - - - - - - - -

typedef enum {
	CANTP_NOT_LAST_ENTRY, CANTP_END_OF_LIST
} CanTp_ListItemType;


typedef enum {
	CANTP_EXTENDED, CANTP_STANDARD
} CanTp_AddressingFormantType;

typedef enum {
	CANTP_OFF, CANTP_ON
} CanTp_StateType;

typedef enum {
	CANTP_RX_WAIT,
	CANTP_RX_PROCESSING,
	CANTP_TX_WAIT,
	CANTP_TX_PROCESSING
} CanTp_TransferInstanceMode;


typedef enum {
	CANTP_FUNCTIONAL, CANTP_PHYSICAL
} CanTp_TaTypeType;


typedef struct {
	uint32 CanTpNSa; /** @req CANTP254 */
} CanTp_NSaType; /** @req CANTP253 */

typedef struct {
	uint32 CanTpNTa; /** @req CANTP255 */ /* TODO John: Why is this 32-bit */
} CanTp_NTaType; /** @req CANTP139 */

typedef struct {
	const uint32 CanTpRxNPduId; /** @req CANTP258 */
	const uint32 CanTpRxNPduRef; /** @req CANTP257 */
} CanTp_RxNPduType; /** @req CANTP256 */

typedef struct {
	const uint32 CanTpTxNPduId; /* TODO: Remove this? */
	const uint32 CanTpTxNPduRef; /** @req CANTP275 */
} CanTp_TxNPduType; /** @req CANTP274 */

typedef struct {
	const uint32 CanTpTxFcNPduRef; /** @req CANTP260 */ /* Reference to a PDU in the COM stack. */
} CanTp_TxFcNPduType; /** @req CANTP259 */

typedef struct {
	const uint32 CanTpRxFcNPduRef; /** @req CANTP272 */ /* Reference to a PDU in the COM stack. */
	const uint32 CanTpRxFcNPduId; /** @req CANTP273 */
} CanTp_RxFcNPduType; /** @req CANTP271 */


typedef struct {
	const PduIdType CanTp_FcPduId; // When recieving this Pdu this conf can be used (if TA match in extended).
	const PduIdType CanIf_FcPduId; // The polite CanIf PDU index.
	const PduIdType PduR_PduId; // The polite PduR index.
	const CanTp_AddressingFormantType CanTpAddressingFormant;	/** @req CANTP242 */
	const uint8 CanTpBs; /** @req CANTP243 */ /* Sets the maximum number of messages of N-PDUs before flow control. */
	const uint16 CanTpNar; /** @req CANTP244 */ /* Timeout for transmission of a CAN frame (ms). */
	const uint16 CanTpNbr; /** @req CANTP245 */
	const uint16 CanTpNcr; /** @req CANTP246 */ /* Time out for consecutive frames (ms). */
	const uint8 CanTpRxChannel; /** @req CANTP247 */ /* Connection to runtime variable index, see CanTp 266. */
	const uint16 CanTpRxDI; /** @req CANTP248 */ /* Data length code for of this RxNsdu. */
	CanTp_StateType CanTpRxPaddingActivation; /** @req CANTP249 */ /* Enable use of padding. */
	CanTp_TaTypeType CanTpRxTaType; /** @req CANTP250 */ /* Functional or physical addressing. */
	const uint8 CanTpWftMax; /** @req CANTP251 */ /* Max number FC wait that can be transmitted consecutively. */
	const uint16 CanTpSTmin; /** @req CANTP252 */ /* Minimum time the sender shall wait between transmissions of two N-PDU. */
	/*const uint32							CanTpNSduRef ** req: CanTp241. This is PDU id - typeless enum. */
	const CanTp_NSaType *CanTpNSa;
	const CanTp_NTaType *CanTpNTa;
	//CanTp_RxNPduType *CanTpRxNPdu;
	//CanTp_TxFcNPduType *CanTpTxFcNPdu;
	//const PduIdType CanTpRxPduId;

} CanTp_RxNSduType; /** @req CANTP137 */

typedef struct {
	const PduIdType CanIf_PduId; // The polite CanIf index.
	const PduIdType PduR_PduId; // The polite PduR index.
	const PduIdType CanTp_FcPduId;
	const CanTp_AddressingFormantType CanTpAddressingMode; /** @req CANTP262 */
	const uint16 CanTpNas; /** @req CANTP263 */ /* N_As timeout for transmission of any CAN frame. */
	const uint16 CanTpNbs; /** @req CANTP264 */ /* N_Bs timeout of transmission until reception of next Flow Control. */
	const uint16 CanTpNcs; /** @req CANTP265 */ /* N_Bs timeout of transmission until reception of next Flow Control. */
	const uint8	CanTpTxChannel; /** @req CANTP266 */ /* Link to the TX connection channel (why?). */
	const uint16 CanTpTxDI; /** @req CANTP267 */ /* Data length code for of this TxNsdu. */
	/*const uint32						CanTpTxNSduId; / ** req: CanTp268: Data length code for of this TxNsdu. */
	CanTp_StateType CanTpTxPaddingActivation; /** @req CANTP269 */ /* Enable use of padding. */
	CanTp_TaTypeType CanTpTxTaType; /** @req CANTP270 */ /* Functional or physical addressing. */
	/*const uint32						CanTpNSduRef ** req: CanTp261. This is PDU id - typeless enum. */
	const CanTp_NSaType *CanTpNSa;
	const CanTp_NTaType *CanTpNTa;
	//CanTp_RxFcNPduType *CanTpRxFcNPdu;
	//CanTp_TxNPduType *CanTpTxNPdu;
	//PduIdType CanTpTxPduId;

} CanTp_TxNSduType; /** @req CANTP138 */

// - - - - - - - - - - -

typedef struct {
	uint32 main_function_period; /** @req CANTP240 */
} CanTp_GeneralType; /** @req CANTP238 */

// - - - - - - - - - - -

typedef enum {
	IS015765_TRANSMIT, ISO15765_RECEIVE
} CanTp_DirectionType;


// - - - - - - - - - - -

typedef struct {
	const CanTp_DirectionType direction;
	const CanTp_ListItemType listItemType;
	union {
		const CanTp_RxNSduType 	CanTpRxNSdu;
		const CanTp_TxNSduType 	CanTpTxNSdu;
	} configData;
} CanTp_NSduType;

typedef struct {
	const CanTp_AddressingFormantType CanTpAddressingMode;
	const PduIdType CanTpNSduIndex;
	const PduIdType CanTpReferringTxIndex;
} CanTp_RxIdType;

// - - - - - - - - - - -

/** Top level config container for CANTP implementation. */
typedef struct {
	/** General configuration paramters for the CANTP module. */
	const CanTp_GeneralType *CanTpGeneral; // 10.2.3

	/** */
	const CanTp_NSduType *CanTpNSduList;

	const CanTp_RxIdType *CanTpRxIdList;

	/**  */
	//const CanTp_RxNSduType 	*CanTpRxNSduList;

	/** This container contains the init parameters of the CAN Interface. */
	//const CanTp_TxNSduType 	*CanTpTxNSduList;

} CanTp_ConfigType;

#endif /* CANTP_TYPES_H_ */
