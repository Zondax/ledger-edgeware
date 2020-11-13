/*******************************************************************************
*  (c) 2019 Zondax GmbH
*
*  Licensed under the Apache License, Version 2.0 (the "License");
*  you may not use this file except in compliance with the License.
*  You may obtain a copy of the License at
*
*      http://www.apache.org/licenses/LICENSE-2.0
*
*  Unless required by applicable law or agreed to in writing, software
*  distributed under the License is distributed on an "AS IS" BASIS,
*  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
*  See the License for the specific language governing permissions and
*  limitations under the License.
********************************************************************************/
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "substrate_types.h"
#include <stddef.h>
#include <stdint.h>

// Based
// https://github.com/paritytech/substrate/blob/master/node/primitives/src/lib.rs

typedef struct {
    uint8_t value;
} pd_Conviction_V1_t;

typedef struct {
    const uint8_t* _ptr;
} pd_AccountId_V1_t;

typedef struct {
    compactInt_t value;
} pd_CompactAccountIndex_V1_t;

typedef struct {
    pd_bool_t aye;
    pd_Conviction_V1_t conviction;
} pd_Vote_V1_t;

typedef struct {
    pd_BalanceOf_t aye;
    pd_BalanceOf_t nay;
} pd_AccountVoteSplit_V1_t;

typedef struct {
    pd_Vote_V1_t vote;
    pd_BalanceOf_t balance;
} pd_AccountVoteStandard_V1_t;

typedef struct {
    pd_u32_t digest_interval;
    pd_u32_t digest_levels;
} pd_ChangesTrieConfiguration_V1_t;

typedef struct {
    compactInt_t value;
} pd_CompactPerBill_V1_t;

typedef struct {
    const uint8_t* _ptr;
} pd_KeyValue_V1_t;

typedef struct {
    const uint8_t* _ptr;
} pd_Key_V1_t;

typedef struct {
    uint8_t value;
    union {
        pd_AccountId_V1_t id;
        pd_CompactAccountIndex_V1_t index;
        pd_Bytes_t raw;
        const uint8_t* _ptr;
    };
} pd_LookupSource_V1_t;

typedef struct {
    uint64_t value;
} pd_Period_V1_t;

typedef struct {
    uint8_t value;
} pd_ProxyType_V1_t;

typedef struct {
    uint32_t value;
} pd_ReferendumIndex_V1_t;

typedef struct {
    pd_u32_t dependency_id;
    uint8_t weight;
    pd_bool_t is_exclusive;
} pd_StreamDependency_V1_t;

typedef struct {
    pd_BlockNumber_t height;
    uint32_t index;
} pd_Timepoint_V1_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_TupleAccountIdData_V1_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_U256_V1_t;

typedef struct {
    uint16_t value;
} pd_ValidatorIndex_V1_t;

typedef struct {
    uint8_t value;
    union {
        pd_AccountVoteStandard_V1_t voteStandard;
        pd_AccountVoteSplit_V1_t voteSplit;
    };
} pd_AccountVote_V1_t;

typedef struct {
    // https://github.com/paritytech/substrate/blob/effe489951d1edab9d34846b1eefdfaf9511dab9/frame/identity/src/lib.rs#L276
    pd_VecTupleDataData_t additional;
    pd_Data_t display;
    pd_Data_t legal;
    pd_Data_t web;
    pd_Data_t riot;
    pd_Data_t email;
    pd_Optionu8_array_20_t pgp_fingerprint;
    pd_Data_t image;
    pd_Data_t twitter;
} pd_IdentityInfo_V1_t;

typedef struct {
    pd_Call_t call;
} pd_OpaqueCall_V1_t;

typedef struct {
    uint8_t some;
    pd_ChangesTrieConfiguration_V1_t contained;
} pd_OptionChangesTrieConfiguration_V1_t;

typedef struct {
    uint8_t some;
    pd_Timepoint_V1_t contained;
} pd_OptionTimepoint_V1_t;

typedef struct {
    uint32_t stream_id;
    pd_StreamDependency_V1_t dependency;
} pd_Priority_V1_t;

typedef struct {
    pd_CompactPerBill_V1_t commission;
} pd_ValidatorPrefs_V1_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecLookupSource_V1_t;

typedef struct {
    pd_BalanceOf_t locked;
    pd_BalanceOf_t per_block;
    pd_BlockNumber_t starting_block;
} pd_VestingInfo_V1_t;

typedef struct {
    uint32_t value;
} pd_AccountIndex_V1_t;

typedef struct {
    const uint8_t* _ptr;
} pd_CallHashOf_V1_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_ChainId_V1_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_CodeHash_V1_t;

typedef compactInt_t pd_CompactAssetId_V1_t;

typedef compactInt_t pd_CompactAssignments_V1_t;

typedef compactInt_t pd_CompactBountyIndex_V1_t;

typedef compactInt_t pd_CompactEraIndex_V1_t;

typedef compactInt_t pd_CompactGas_V1_t;

typedef compactInt_t pd_CompactMemberCount_V1_t;

typedef compactInt_t pd_CompactMoment_V1_t;

typedef compactInt_t pd_CompactPropIndex_V1_t;

typedef compactInt_t pd_CompactProposalIndex_V1_t;

typedef compactInt_t pd_CompactReferendumIndex_V1_t;

typedef compactInt_t pd_CompactRegistrarIndex_V1_t;

typedef compactInt_t pd_CompactTAssetBalance_V1_t;

typedef compactInt_t pd_CompactWeight_V1_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_DefunctVoter_V1_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_DepositNonce_V1_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_ElectionScore_V1_t;

typedef struct {
    compactInt_t validators;
    compactInt_t nominators;
} pd_ElectionSize_V1_t;

typedef struct {
    uint32_t value;
} pd_EraIndex_V1_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_EthTransaction_V1_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_GrandpaEquivocationProof_V1_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_H160_V1_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_H256_V1_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_IdentityFields_V1_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_IdentityJudgement_V1_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_KeyOwnerProof_V1_t;

typedef struct {
    const uint8_t* _ptr;
} pd_Keys_V1_t;

typedef struct {
    uint32_t value;
} pd_MemberCount_V1_t;

typedef struct {
    uint8_t some;
    pd_AccountId_V1_t contained;
} pd_OptionAccountId_V1_t;

typedef struct {
    uint8_t some;
    pd_Period_V1_t contained;
} pd_OptionPeriod_V1_t;

typedef struct {
    uint8_t some;
    pd_ProxyType_V1_t contained;
} pd_OptionProxyType_V1_t;

typedef struct {
    uint8_t some;
    pd_ReferendumIndex_V1_t contained;
} pd_OptionReferendumIndex_V1_t;

typedef struct {
    uint8_t some;
    pd_U256_V1_t contained;
} pd_OptionU256_V1_t;

typedef struct {
    uint32_t value;
} pd_Perbill_V1_t;

typedef struct {
    compactInt_t value;
} pd_Percent_V1_t;

typedef struct {
    uint32_t value;
} pd_RegistrarIndex_V1_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_Renouncing_V1_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_ResourceId_V1_t;

typedef struct {
    uint8_t value;
} pd_RewardDestination_V1_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_Schedule_V1_t;

typedef struct {
    const uint8_t* _ptr;
} pd_Signature_V1_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_TAssetBalance_V1_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecAccountId_V1_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecKeyValue_V1_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecKey_V1_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecTupleAccountIdData_V1_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecValidatorIndex_V1_t;

typedef struct {
    uint64_t value;
} pd_Weight_V1_t;

typedef struct {
    const uint8_t* _ptr;
} pd_u8_array_32_V1_t;

#ifdef __cplusplus
}
#endif
