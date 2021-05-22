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
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wextern-c-compat"
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "substrate_types.h"
#include "substrate_types_V1.h"
#include <stddef.h>
#include <stdint.h>

#define PD_CALL_SYSTEM_V1 0
#define PD_CALL_UTILITY_V1 1
#define PD_CALL_TIMESTAMP_V1 3
#define PD_CALL_AUTHORSHIP_V1 4
#define PD_CALL_INDICES_V1 5
#define PD_CALL_BALANCES_V1 6
#define PD_CALL_STAKING_V1 8
#define PD_CALL_SESSION_V1 9
#define PD_CALL_DEMOCRACY_V1 10
#define PD_CALL_COUNCIL_V1 11
#define PD_CALL_ELECTIONS_V1 12
#define PD_CALL_GRANDPA_V1 14
#define PD_CALL_TREASURY_V1 15
#define PD_CALL_CONTRACTS_V1 16
#define PD_CALL_SUDO_V1 17
#define PD_CALL_IMONLINE_V1 18
#define PD_CALL_AUTHORITYDISCOVERY_V1 19
#define PD_CALL_OFFENCES_V1 20
#define PD_CALL_RANDOMNESSCOLLECTIVEFLIP_V1 22
#define PD_CALL_IDENTITY_V1 23
#define PD_CALL_RECOVERY_V1 24
#define PD_CALL_VESTING_V1 25
#define PD_CALL_SCHEDULER_V1 26
#define PD_CALL_PROXY_V1 27
#define PD_CALL_MULTISIG_V1 28
#define PD_CALL_ASSETS_V1 29
#define PD_CALL_TREASURYREWARD_V1 32
#define PD_CALL_ETHEREUM_V1 33
#define PD_CALL_EVM_V1 34
#define PD_CALL_CHAINBRIDGE_V1 35
#define PD_CALL_EDGEBRIDGE_V1 36
#define PD_CALL_BOUNTIES_V1 37
#define PD_CALL_TIPS_V1 38

#define PD_CALL_UTILITY_BATCH_V1 0
typedef struct {
    pd_VecCall_t calls;
} pd_utility_batch_V1_t;

#define PD_CALL_UTILITY_BATCH_ALL_V1 2
typedef struct {
    pd_VecCall_t calls;
} pd_utility_batch_all_V1_t;

#define PD_CALL_STAKING_BOND_V1 0
typedef struct {
    pd_LookupSource_V1_t controller;
    pd_CompactBalanceOf_t value;
    pd_RewardDestination_V1_t payee;
} pd_staking_bond_V1_t;

#define PD_CALL_STAKING_BOND_EXTRA_V1 1
typedef struct {
    pd_CompactBalanceOf_t max_additional;
} pd_staking_bond_extra_V1_t;

#define PD_CALL_STAKING_UNBOND_V1 2
typedef struct {
    pd_CompactBalanceOf_t value;
} pd_staking_unbond_V1_t;

#define PD_CALL_STAKING_WITHDRAW_UNBONDED_V1 3
typedef struct {
    pd_u32_t num_slashing_spans;
} pd_staking_withdraw_unbonded_V1_t;

#define PD_CALL_STAKING_VALIDATE_V1 4
typedef struct {
    pd_ValidatorPrefs_V1_t prefs;
} pd_staking_validate_V1_t;

#define PD_CALL_STAKING_NOMINATE_V1 5
typedef struct {
    pd_VecLookupSource_V1_t targets;
} pd_staking_nominate_V1_t;

#define PD_CALL_STAKING_CHILL_V1 6
typedef struct {
} pd_staking_chill_V1_t;

#define PD_CALL_STAKING_SET_PAYEE_V1 7
typedef struct {
    pd_RewardDestination_V1_t payee;
} pd_staking_set_payee_V1_t;

#define PD_CALL_STAKING_PAYOUT_STAKERS_V1 18
typedef struct {
    pd_AccountId_V1_t validator_stash;
    pd_EraIndex_V1_t era;
} pd_staking_payout_stakers_V1_t;

#define PD_CALL_STAKING_REBOND_V1 19
typedef struct {
    pd_CompactBalanceOf_t value;
} pd_staking_rebond_V1_t;

#define PD_CALL_SESSION_SET_KEYS_V1 0
typedef struct {
    pd_Keys_V1_t keys;
    pd_Bytes_t proof;
} pd_session_set_keys_V1_t;

#define PD_CALL_SESSION_PURGE_KEYS_V1 1
typedef struct {
} pd_session_purge_keys_V1_t;

#ifdef SUBSTRATE_PARSER_FULL

#define PD_CALL_UTILITY_AS_DERIVATIVE_V1 1
typedef struct {
    pd_u16_t index;
    pd_Call_t call;
} pd_utility_as_derivative_V1_t;

#define PD_CALL_TIMESTAMP_SET_V1 0
typedef struct {
    pd_CompactMoment_V1_t now;
} pd_timestamp_set_V1_t;

#define PD_CALL_AUTHORSHIP_SET_UNCLES_V1 0
typedef struct {
    pd_VecHeader_t new_uncles;
} pd_authorship_set_uncles_V1_t;

#define PD_CALL_INDICES_CLAIM_V1 0
typedef struct {
    pd_AccountIndex_V1_t index;
} pd_indices_claim_V1_t;

#define PD_CALL_INDICES_TRANSFER_V1 1
typedef struct {
    pd_AccountId_V1_t new_;
    pd_AccountIndex_V1_t index;
} pd_indices_transfer_V1_t;

#define PD_CALL_INDICES_FREE_V1 2
typedef struct {
    pd_AccountIndex_V1_t index;
} pd_indices_free_V1_t;

#define PD_CALL_INDICES_FORCE_TRANSFER_V1 3
typedef struct {
    pd_AccountId_V1_t new_;
    pd_AccountIndex_V1_t index;
    pd_bool_t freeze;
} pd_indices_force_transfer_V1_t;

#define PD_CALL_INDICES_FREEZE_V1 4
typedef struct {
    pd_AccountIndex_V1_t index;
} pd_indices_freeze_V1_t;

#define PD_CALL_STAKING_SET_CONTROLLER_V1 8
typedef struct {
    pd_LookupSource_V1_t controller;
} pd_staking_set_controller_V1_t;

#define PD_CALL_STAKING_SET_VALIDATOR_COUNT_V1 9
typedef struct {
    pd_Compactu32_t new_;
} pd_staking_set_validator_count_V1_t;

#define PD_CALL_STAKING_INCREASE_VALIDATOR_COUNT_V1 10
typedef struct {
    pd_Compactu32_t additional;
} pd_staking_increase_validator_count_V1_t;

#define PD_CALL_STAKING_SCALE_VALIDATOR_COUNT_V1 11
typedef struct {
    pd_Percent_V1_t factor;
} pd_staking_scale_validator_count_V1_t;

#define PD_CALL_STAKING_FORCE_NO_ERAS_V1 12
typedef struct {
} pd_staking_force_no_eras_V1_t;

#define PD_CALL_STAKING_FORCE_NEW_ERA_V1 13
typedef struct {
} pd_staking_force_new_era_V1_t;

#define PD_CALL_STAKING_SET_INVULNERABLES_V1 14
typedef struct {
    pd_VecAccountId_V1_t invulnerables;
} pd_staking_set_invulnerables_V1_t;

#define PD_CALL_STAKING_FORCE_UNSTAKE_V1 15
typedef struct {
    pd_AccountId_V1_t stash;
    pd_u32_t num_slashing_spans;
} pd_staking_force_unstake_V1_t;

#define PD_CALL_STAKING_FORCE_NEW_ERA_ALWAYS_V1 16
typedef struct {
} pd_staking_force_new_era_always_V1_t;

#define PD_CALL_STAKING_CANCEL_DEFERRED_SLASH_V1 17
typedef struct {
    pd_EraIndex_V1_t era;
    pd_Vecu32_t slash_indices;
} pd_staking_cancel_deferred_slash_V1_t;

#define PD_CALL_STAKING_SET_HISTORY_DEPTH_V1 20
typedef struct {
    pd_CompactEraIndex_V1_t new_history_depth;
    pd_Compactu32_t _era_items_deleted;
} pd_staking_set_history_depth_V1_t;

#define PD_CALL_STAKING_REAP_STASH_V1 21
typedef struct {
    pd_AccountId_V1_t stash;
    pd_u32_t num_slashing_spans;
} pd_staking_reap_stash_V1_t;

#define PD_CALL_STAKING_SUBMIT_ELECTION_SOLUTION_V1 22
typedef struct {
    pd_VecValidatorIndex_V1_t winners;
    pd_CompactAssignments_V1_t compact;
    pd_ElectionScore_V1_t score;
    pd_EraIndex_V1_t era;
    pd_ElectionSize_V1_t size;
} pd_staking_submit_election_solution_V1_t;

#define PD_CALL_STAKING_SUBMIT_ELECTION_SOLUTION_UNSIGNED_V1 23
typedef struct {
    pd_VecValidatorIndex_V1_t winners;
    pd_CompactAssignments_V1_t compact;
    pd_ElectionScore_V1_t score;
    pd_EraIndex_V1_t era;
    pd_ElectionSize_V1_t size;
} pd_staking_submit_election_solution_unsigned_V1_t;

#define PD_CALL_DEMOCRACY_PROPOSE_V1 0
typedef struct {
    pd_Hash_t proposal_hash;
    pd_CompactBalanceOf_t value;
} pd_democracy_propose_V1_t;

#define PD_CALL_DEMOCRACY_SECOND_V1 1
typedef struct {
    pd_CompactPropIndex_V1_t proposal;
    pd_Compactu32_t seconds_upper_bound;
} pd_democracy_second_V1_t;

#define PD_CALL_DEMOCRACY_VOTE_V1 2
typedef struct {
    pd_CompactReferendumIndex_V1_t ref_index;
    pd_AccountVote_V1_t vote;
} pd_democracy_vote_V1_t;

#define PD_CALL_DEMOCRACY_EMERGENCY_CANCEL_V1 3
typedef struct {
    pd_ReferendumIndex_V1_t ref_index;
} pd_democracy_emergency_cancel_V1_t;

#define PD_CALL_DEMOCRACY_EXTERNAL_PROPOSE_V1 4
typedef struct {
    pd_Hash_t proposal_hash;
} pd_democracy_external_propose_V1_t;

#define PD_CALL_DEMOCRACY_EXTERNAL_PROPOSE_MAJORITY_V1 5
typedef struct {
    pd_Hash_t proposal_hash;
} pd_democracy_external_propose_majority_V1_t;

#define PD_CALL_DEMOCRACY_EXTERNAL_PROPOSE_DEFAULT_V1 6
typedef struct {
    pd_Hash_t proposal_hash;
} pd_democracy_external_propose_default_V1_t;

#define PD_CALL_DEMOCRACY_FAST_TRACK_V1 7
typedef struct {
    pd_Hash_t proposal_hash;
    pd_BlockNumber_t voting_period;
    pd_BlockNumber_t delay;
} pd_democracy_fast_track_V1_t;

#define PD_CALL_DEMOCRACY_VETO_EXTERNAL_V1 8
typedef struct {
    pd_Hash_t proposal_hash;
} pd_democracy_veto_external_V1_t;

#define PD_CALL_DEMOCRACY_CANCEL_REFERENDUM_V1 9
typedef struct {
    pd_CompactReferendumIndex_V1_t ref_index;
} pd_democracy_cancel_referendum_V1_t;

#define PD_CALL_DEMOCRACY_CANCEL_QUEUED_V1 10
typedef struct {
    pd_ReferendumIndex_V1_t which;
} pd_democracy_cancel_queued_V1_t;

#define PD_CALL_DEMOCRACY_DELEGATE_V1 11
typedef struct {
    pd_AccountId_V1_t to;
    pd_Conviction_V1_t conviction;
    pd_BalanceOf_t balance;
} pd_democracy_delegate_V1_t;

#define PD_CALL_DEMOCRACY_UNDELEGATE_V1 12
typedef struct {
} pd_democracy_undelegate_V1_t;

#define PD_CALL_DEMOCRACY_CLEAR_PUBLIC_PROPOSALS_V1 13
typedef struct {
} pd_democracy_clear_public_proposals_V1_t;

#define PD_CALL_DEMOCRACY_NOTE_PREIMAGE_V1 14
typedef struct {
    pd_Bytes_t encoded_proposal;
} pd_democracy_note_preimage_V1_t;

#define PD_CALL_DEMOCRACY_NOTE_PREIMAGE_OPERATIONAL_V1 15
typedef struct {
    pd_Bytes_t encoded_proposal;
} pd_democracy_note_preimage_operational_V1_t;

#define PD_CALL_DEMOCRACY_NOTE_IMMINENT_PREIMAGE_V1 16
typedef struct {
    pd_Bytes_t encoded_proposal;
} pd_democracy_note_imminent_preimage_V1_t;

#define PD_CALL_DEMOCRACY_NOTE_IMMINENT_PREIMAGE_OPERATIONAL_V1 17
typedef struct {
    pd_Bytes_t encoded_proposal;
} pd_democracy_note_imminent_preimage_operational_V1_t;

#define PD_CALL_DEMOCRACY_REAP_PREIMAGE_V1 18
typedef struct {
    pd_Hash_t proposal_hash;
    pd_Compactu32_t proposal_len_upper_bound;
} pd_democracy_reap_preimage_V1_t;

#define PD_CALL_DEMOCRACY_UNLOCK_V1 19
typedef struct {
    pd_AccountId_V1_t target;
} pd_democracy_unlock_V1_t;

#define PD_CALL_DEMOCRACY_REMOVE_VOTE_V1 20
typedef struct {
    pd_ReferendumIndex_V1_t index;
} pd_democracy_remove_vote_V1_t;

#define PD_CALL_DEMOCRACY_REMOVE_OTHER_VOTE_V1 21
typedef struct {
    pd_AccountId_V1_t target;
    pd_ReferendumIndex_V1_t index;
} pd_democracy_remove_other_vote_V1_t;

#define PD_CALL_DEMOCRACY_ENACT_PROPOSAL_V1 22
typedef struct {
    pd_Hash_t proposal_hash;
    pd_ReferendumIndex_V1_t index;
} pd_democracy_enact_proposal_V1_t;

#define PD_CALL_DEMOCRACY_BLACKLIST_V1 23
typedef struct {
    pd_Hash_t proposal_hash;
    pd_OptionReferendumIndex_V1_t maybe_ref_index;
} pd_democracy_blacklist_V1_t;

#define PD_CALL_DEMOCRACY_CANCEL_PROPOSAL_V1 24
typedef struct {
    pd_CompactPropIndex_V1_t prop_index;
} pd_democracy_cancel_proposal_V1_t;

#define PD_CALL_COUNCIL_SET_MEMBERS_V1 0
typedef struct {
    pd_VecAccountId_V1_t new_members;
    pd_OptionAccountId_V1_t prime;
    pd_MemberCount_V1_t old_count;
} pd_council_set_members_V1_t;

#define PD_CALL_COUNCIL_EXECUTE_V1 1
typedef struct {
    pd_Proposal_t proposal;
    pd_Compactu32_t length_bound;
} pd_council_execute_V1_t;

#define PD_CALL_COUNCIL_PROPOSE_V1 2
typedef struct {
    pd_CompactMemberCount_V1_t threshold;
    pd_Proposal_t proposal;
    pd_Compactu32_t length_bound;
} pd_council_propose_V1_t;

#define PD_CALL_COUNCIL_VOTE_V1 3
typedef struct {
    pd_Hash_t proposal;
    pd_CompactProposalIndex_V1_t index;
    pd_bool_t approve;
} pd_council_vote_V1_t;

#define PD_CALL_COUNCIL_CLOSE_V1 4
typedef struct {
    pd_Hash_t proposal_hash;
    pd_CompactProposalIndex_V1_t index;
    pd_CompactWeight_V1_t proposal_weight_bound;
    pd_Compactu32_t length_bound;
} pd_council_close_V1_t;

#define PD_CALL_COUNCIL_DISAPPROVE_PROPOSAL_V1 5
typedef struct {
    pd_Hash_t proposal_hash;
} pd_council_disapprove_proposal_V1_t;

#define PD_CALL_ELECTIONS_VOTE_V1 0
typedef struct {
    pd_VecAccountId_V1_t votes;
    pd_CompactBalanceOf_t value;
} pd_elections_vote_V1_t;

#define PD_CALL_ELECTIONS_REMOVE_VOTER_V1 1
typedef struct {
} pd_elections_remove_voter_V1_t;

#define PD_CALL_ELECTIONS_REPORT_DEFUNCT_VOTER_V1 2
typedef struct {
    pd_DefunctVoter_V1_t defunct;
} pd_elections_report_defunct_voter_V1_t;

#define PD_CALL_ELECTIONS_SUBMIT_CANDIDACY_V1 3
typedef struct {
    pd_Compactu32_t candidate_count;
} pd_elections_submit_candidacy_V1_t;

#define PD_CALL_ELECTIONS_RENOUNCE_CANDIDACY_V1 4
typedef struct {
    pd_Renouncing_V1_t renouncing;
} pd_elections_renounce_candidacy_V1_t;

#define PD_CALL_ELECTIONS_REMOVE_MEMBER_V1 5
typedef struct {
    pd_LookupSource_V1_t who;
    pd_bool_t has_replacement;
} pd_elections_remove_member_V1_t;

#define PD_CALL_GRANDPA_REPORT_EQUIVOCATION_V1 0
typedef struct {
    pd_GrandpaEquivocationProof_V1_t equivocation_proof;
    pd_KeyOwnerProof_V1_t key_owner_proof;
} pd_grandpa_report_equivocation_V1_t;

#define PD_CALL_GRANDPA_REPORT_EQUIVOCATION_UNSIGNED_V1 1
typedef struct {
    pd_GrandpaEquivocationProof_V1_t equivocation_proof;
    pd_KeyOwnerProof_V1_t key_owner_proof;
} pd_grandpa_report_equivocation_unsigned_V1_t;

#define PD_CALL_GRANDPA_NOTE_STALLED_V1 2
typedef struct {
    pd_BlockNumber_t delay;
    pd_BlockNumber_t best_finalized_block_number;
} pd_grandpa_note_stalled_V1_t;

#define PD_CALL_TREASURY_PROPOSE_SPEND_V1 0
typedef struct {
    pd_CompactBalanceOf_t value;
    pd_LookupSource_V1_t beneficiary;
} pd_treasury_propose_spend_V1_t;

#define PD_CALL_TREASURY_REJECT_PROPOSAL_V1 1
typedef struct {
    pd_CompactProposalIndex_V1_t proposal_id;
} pd_treasury_reject_proposal_V1_t;

#define PD_CALL_TREASURY_APPROVE_PROPOSAL_V1 2
typedef struct {
    pd_CompactProposalIndex_V1_t proposal_id;
} pd_treasury_approve_proposal_V1_t;

#define PD_CALL_CONTRACTS_UPDATE_SCHEDULE_V1 0
typedef struct {
    pd_Schedule_V1_t schedule;
} pd_contracts_update_schedule_V1_t;

#define PD_CALL_CONTRACTS_PUT_CODE_V1 1
typedef struct {
    pd_Bytes_t code;
} pd_contracts_put_code_V1_t;

#define PD_CALL_CONTRACTS_CALL_V1 2
typedef struct {
    pd_LookupSource_V1_t dest;
    pd_CompactBalanceOf_t value;
    pd_CompactGas_V1_t gas_limit;
    pd_Bytes_t data;
} pd_contracts_call_V1_t;

#define PD_CALL_CONTRACTS_INSTANTIATE_V1 3
typedef struct {
    pd_CompactBalanceOf_t endowment;
    pd_CompactGas_V1_t gas_limit;
    pd_CodeHash_V1_t code_hash;
    pd_Bytes_t data;
    pd_Bytes_t salt;
} pd_contracts_instantiate_V1_t;

#define PD_CALL_CONTRACTS_CLAIM_SURCHARGE_V1 4
typedef struct {
    pd_AccountId_V1_t dest;
    pd_OptionAccountId_V1_t aux_sender;
} pd_contracts_claim_surcharge_V1_t;

#define PD_CALL_SUDO_SUDO_V1 0
typedef struct {
    pd_Call_t call;
} pd_sudo_sudo_V1_t;

#define PD_CALL_SUDO_SUDO_UNCHECKED_WEIGHT_V1 1
typedef struct {
    pd_Call_t call;
    pd_Weight_V1_t _weight;
} pd_sudo_sudo_unchecked_weight_V1_t;

#define PD_CALL_SUDO_SET_KEY_V1 2
typedef struct {
    pd_LookupSource_V1_t new_;
} pd_sudo_set_key_V1_t;

#define PD_CALL_SUDO_SUDO_AS_V1 3
typedef struct {
    pd_LookupSource_V1_t who;
    pd_Call_t call;
} pd_sudo_sudo_as_V1_t;

#define PD_CALL_IMONLINE_HEARTBEAT_V1 0
typedef struct {
    pd_Heartbeat_t heartbeat;
    pd_Signature_V1_t _signature;
} pd_imonline_heartbeat_V1_t;

#define PD_CALL_IDENTITY_ADD_REGISTRAR_V1 0
typedef struct {
    pd_AccountId_V1_t account;
} pd_identity_add_registrar_V1_t;

#define PD_CALL_IDENTITY_SET_IDENTITY_V1 1
typedef struct {
    pd_IdentityInfo_V1_t info;
} pd_identity_set_identity_V1_t;

#define PD_CALL_IDENTITY_SET_SUBS_V1 2
typedef struct {
    pd_VecTupleAccountIdData_V1_t subs;
} pd_identity_set_subs_V1_t;

#define PD_CALL_IDENTITY_CLEAR_IDENTITY_V1 3
typedef struct {
} pd_identity_clear_identity_V1_t;

#define PD_CALL_IDENTITY_REQUEST_JUDGEMENT_V1 4
typedef struct {
    pd_CompactRegistrarIndex_V1_t reg_index;
    pd_CompactBalanceOf_t max_fee;
} pd_identity_request_judgement_V1_t;

#define PD_CALL_IDENTITY_CANCEL_REQUEST_V1 5
typedef struct {
    pd_RegistrarIndex_V1_t reg_index;
} pd_identity_cancel_request_V1_t;

#define PD_CALL_IDENTITY_SET_FEE_V1 6
typedef struct {
    pd_CompactRegistrarIndex_V1_t index;
    pd_CompactBalanceOf_t fee;
} pd_identity_set_fee_V1_t;

#define PD_CALL_IDENTITY_SET_ACCOUNT_ID_V1 7
typedef struct {
    pd_CompactRegistrarIndex_V1_t index;
    pd_AccountId_V1_t new_;
} pd_identity_set_account_id_V1_t;

#define PD_CALL_IDENTITY_SET_FIELDS_V1 8
typedef struct {
    pd_CompactRegistrarIndex_V1_t index;
    pd_IdentityFields_V1_t fields;
} pd_identity_set_fields_V1_t;

#define PD_CALL_IDENTITY_PROVIDE_JUDGEMENT_V1 9
typedef struct {
    pd_CompactRegistrarIndex_V1_t reg_index;
    pd_LookupSource_V1_t target;
    pd_IdentityJudgement_V1_t judgement;
} pd_identity_provide_judgement_V1_t;

#define PD_CALL_IDENTITY_KILL_IDENTITY_V1 10
typedef struct {
    pd_LookupSource_V1_t target;
} pd_identity_kill_identity_V1_t;

#define PD_CALL_IDENTITY_ADD_SUB_V1 11
typedef struct {
    pd_LookupSource_V1_t sub;
    pd_Data_t data;
} pd_identity_add_sub_V1_t;

#define PD_CALL_IDENTITY_RENAME_SUB_V1 12
typedef struct {
    pd_LookupSource_V1_t sub;
    pd_Data_t data;
} pd_identity_rename_sub_V1_t;

#define PD_CALL_IDENTITY_REMOVE_SUB_V1 13
typedef struct {
    pd_LookupSource_V1_t sub;
} pd_identity_remove_sub_V1_t;

#define PD_CALL_IDENTITY_QUIT_SUB_V1 14
typedef struct {
} pd_identity_quit_sub_V1_t;

#define PD_CALL_RECOVERY_AS_RECOVERED_V1 0
typedef struct {
    pd_AccountId_V1_t account;
    pd_Call_t call;
} pd_recovery_as_recovered_V1_t;

#define PD_CALL_RECOVERY_SET_RECOVERED_V1 1
typedef struct {
    pd_AccountId_V1_t lost;
    pd_AccountId_V1_t rescuer;
} pd_recovery_set_recovered_V1_t;

#define PD_CALL_RECOVERY_CREATE_RECOVERY_V1 2
typedef struct {
    pd_VecAccountId_V1_t friends;
    pd_u16_t threshold;
    pd_BlockNumber_t delay_period;
} pd_recovery_create_recovery_V1_t;

#define PD_CALL_RECOVERY_INITIATE_RECOVERY_V1 3
typedef struct {
    pd_AccountId_V1_t account;
} pd_recovery_initiate_recovery_V1_t;

#define PD_CALL_RECOVERY_VOUCH_RECOVERY_V1 4
typedef struct {
    pd_AccountId_V1_t lost;
    pd_AccountId_V1_t rescuer;
} pd_recovery_vouch_recovery_V1_t;

#define PD_CALL_RECOVERY_CLAIM_RECOVERY_V1 5
typedef struct {
    pd_AccountId_V1_t account;
} pd_recovery_claim_recovery_V1_t;

#define PD_CALL_RECOVERY_CLOSE_RECOVERY_V1 6
typedef struct {
    pd_AccountId_V1_t rescuer;
} pd_recovery_close_recovery_V1_t;

#define PD_CALL_RECOVERY_REMOVE_RECOVERY_V1 7
typedef struct {
} pd_recovery_remove_recovery_V1_t;

#define PD_CALL_RECOVERY_CANCEL_RECOVERED_V1 8
typedef struct {
    pd_AccountId_V1_t account;
} pd_recovery_cancel_recovered_V1_t;

#define PD_CALL_VESTING_VEST_V1 0
typedef struct {
} pd_vesting_vest_V1_t;

#define PD_CALL_VESTING_VEST_OTHER_V1 1
typedef struct {
    pd_LookupSource_V1_t target;
} pd_vesting_vest_other_V1_t;

#define PD_CALL_VESTING_VESTED_TRANSFER_V1 2
typedef struct {
    pd_LookupSource_V1_t target;
    pd_VestingInfo_V1_t schedule;
} pd_vesting_vested_transfer_V1_t;

#define PD_CALL_VESTING_FORCE_VESTED_TRANSFER_V1 3
typedef struct {
    pd_LookupSource_V1_t source;
    pd_LookupSource_V1_t target;
    pd_VestingInfo_V1_t schedule;
} pd_vesting_force_vested_transfer_V1_t;

#define PD_CALL_SCHEDULER_SCHEDULE_V1 0
typedef struct {
    pd_BlockNumber_t when;
    pd_OptionPeriod_V1_t maybe_periodic;
    pd_Priority_V1_t priority;
    pd_Call_t call;
} pd_scheduler_schedule_V1_t;

#define PD_CALL_SCHEDULER_CANCEL_V1 1
typedef struct {
    pd_BlockNumber_t when;
    pd_u32_t index;
} pd_scheduler_cancel_V1_t;

#define PD_CALL_SCHEDULER_SCHEDULE_NAMED_V1 2
typedef struct {
    pd_Bytes_t id;
    pd_BlockNumber_t when;
    pd_OptionPeriod_V1_t maybe_periodic;
    pd_Priority_V1_t priority;
    pd_Call_t call;
} pd_scheduler_schedule_named_V1_t;

#define PD_CALL_SCHEDULER_CANCEL_NAMED_V1 3
typedef struct {
    pd_Bytes_t id;
} pd_scheduler_cancel_named_V1_t;

#define PD_CALL_SCHEDULER_SCHEDULE_AFTER_V1 4
typedef struct {
    pd_BlockNumber_t after;
    pd_OptionPeriod_V1_t maybe_periodic;
    pd_Priority_V1_t priority;
    pd_Call_t call;
} pd_scheduler_schedule_after_V1_t;

#define PD_CALL_SCHEDULER_SCHEDULE_NAMED_AFTER_V1 5
typedef struct {
    pd_Bytes_t id;
    pd_BlockNumber_t after;
    pd_OptionPeriod_V1_t maybe_periodic;
    pd_Priority_V1_t priority;
    pd_Call_t call;
} pd_scheduler_schedule_named_after_V1_t;

#define PD_CALL_PROXY_ADD_PROXY_V1 1
typedef struct {
    pd_AccountId_V1_t delegate;
    pd_ProxyType_V1_t proxy_type;
    pd_BlockNumber_t delay;
} pd_proxy_add_proxy_V1_t;

#define PD_CALL_PROXY_REMOVE_PROXY_V1 2
typedef struct {
    pd_AccountId_V1_t delegate;
    pd_ProxyType_V1_t proxy_type;
    pd_BlockNumber_t delay;
} pd_proxy_remove_proxy_V1_t;

#define PD_CALL_PROXY_REMOVE_PROXIES_V1 3
typedef struct {
} pd_proxy_remove_proxies_V1_t;

#define PD_CALL_PROXY_ANONYMOUS_V1 4
typedef struct {
    pd_ProxyType_V1_t proxy_type;
    pd_BlockNumber_t delay;
    pd_u16_t index;
} pd_proxy_anonymous_V1_t;

#define PD_CALL_PROXY_KILL_ANONYMOUS_V1 5
typedef struct {
    pd_AccountId_V1_t spawner;
    pd_ProxyType_V1_t proxy_type;
    pd_u16_t index;
    pd_CompactBlockNumber_t height;
    pd_Compactu32_t ext_index;
} pd_proxy_kill_anonymous_V1_t;

#define PD_CALL_PROXY_ANNOUNCE_V1 6
typedef struct {
    pd_AccountId_V1_t real;
    pd_CallHashOf_V1_t call_hash;
} pd_proxy_announce_V1_t;

#define PD_CALL_PROXY_REMOVE_ANNOUNCEMENT_V1 7
typedef struct {
    pd_AccountId_V1_t real;
    pd_CallHashOf_V1_t call_hash;
} pd_proxy_remove_announcement_V1_t;

#define PD_CALL_PROXY_REJECT_ANNOUNCEMENT_V1 8
typedef struct {
    pd_AccountId_V1_t delegate;
    pd_CallHashOf_V1_t call_hash;
} pd_proxy_reject_announcement_V1_t;

#define PD_CALL_PROXY_PROXY_ANNOUNCED_V1 9
typedef struct {
    pd_AccountId_V1_t delegate;
    pd_AccountId_V1_t real;
    pd_OptionProxyType_V1_t force_proxy_type;
    pd_Call_t call;
} pd_proxy_proxy_announced_V1_t;

#define PD_CALL_ASSETS_CREATE_V1 0
typedef struct {
    pd_CompactAssetId_V1_t id;
    pd_LookupSource_V1_t admin;
    pd_u32_t max_zombies;
    pd_TAssetBalance_V1_t min_balance;
} pd_assets_create_V1_t;

#define PD_CALL_ASSETS_FORCE_CREATE_V1 1
typedef struct {
    pd_CompactAssetId_V1_t id;
    pd_LookupSource_V1_t owner;
    pd_Compactu32_t max_zombies;
    pd_CompactTAssetBalance_V1_t min_balance;
} pd_assets_force_create_V1_t;

#define PD_CALL_ASSETS_DESTROY_V1 2
typedef struct {
    pd_CompactAssetId_V1_t id;
    pd_Compactu32_t zombies_witness;
} pd_assets_destroy_V1_t;

#define PD_CALL_ASSETS_FORCE_DESTROY_V1 3
typedef struct {
    pd_CompactAssetId_V1_t id;
    pd_Compactu32_t zombies_witness;
} pd_assets_force_destroy_V1_t;

#define PD_CALL_ASSETS_MINT_V1 4
typedef struct {
    pd_CompactAssetId_V1_t id;
    pd_LookupSource_V1_t beneficiary;
    pd_CompactTAssetBalance_V1_t amount;
} pd_assets_mint_V1_t;

#define PD_CALL_ASSETS_BURN_V1 5
typedef struct {
    pd_CompactAssetId_V1_t id;
    pd_LookupSource_V1_t who;
    pd_CompactTAssetBalance_V1_t amount;
} pd_assets_burn_V1_t;

#define PD_CALL_ASSETS_TRANSFER_V1 6
typedef struct {
    pd_CompactAssetId_V1_t id;
    pd_LookupSource_V1_t target;
    pd_CompactTAssetBalance_V1_t amount;
} pd_assets_transfer_V1_t;

#define PD_CALL_ASSETS_FORCE_TRANSFER_V1 7
typedef struct {
    pd_CompactAssetId_V1_t id;
    pd_LookupSource_V1_t source;
    pd_LookupSource_V1_t dest;
    pd_CompactTAssetBalance_V1_t amount;
} pd_assets_force_transfer_V1_t;

#define PD_CALL_ASSETS_FREEZE_V1 8
typedef struct {
    pd_CompactAssetId_V1_t id;
    pd_LookupSource_V1_t who;
} pd_assets_freeze_V1_t;

#define PD_CALL_ASSETS_THAW_V1 9
typedef struct {
    pd_CompactAssetId_V1_t id;
    pd_LookupSource_V1_t who;
} pd_assets_thaw_V1_t;

#define PD_CALL_ASSETS_TRANSFER_OWNERSHIP_V1 10
typedef struct {
    pd_CompactAssetId_V1_t id;
    pd_LookupSource_V1_t new_owner;
} pd_assets_transfer_ownership_V1_t;

#define PD_CALL_ASSETS_SET_TEAM_V1 11
typedef struct {
    pd_CompactAssetId_V1_t id;
    pd_LookupSource_V1_t issuer;
    pd_LookupSource_V1_t admin;
    pd_LookupSource_V1_t freezer;
} pd_assets_set_team_V1_t;

#define PD_CALL_ASSETS_SET_MAX_ZOMBIES_V1 12
typedef struct {
    pd_CompactAssetId_V1_t id;
    pd_Compactu32_t max_zombies;
} pd_assets_set_max_zombies_V1_t;

#define PD_CALL_TREASURYREWARD_SET_CURRENT_PAYOUT_V1 0
typedef struct {
    pd_BalanceOf_t payout;
} pd_treasuryreward_set_current_payout_V1_t;

#define PD_CALL_TREASURYREWARD_SET_MINTING_INTERVAL_V1 1
typedef struct {
    pd_BlockNumber_t interval;
} pd_treasuryreward_set_minting_interval_V1_t;

#define PD_CALL_ETHEREUM_TRANSACT_V1 0
typedef struct {
    pd_EthTransaction_V1_t transaction;
} pd_ethereum_transact_V1_t;

#define PD_CALL_EVM_WITHDRAW_V1 0
typedef struct {
    pd_H160_V1_t address;
    pd_BalanceOf_t value;
} pd_evm_withdraw_V1_t;

#define PD_CALL_EVM_CALL_V1 1
typedef struct {
    pd_H160_V1_t source;
    pd_H160_V1_t target;
    pd_Bytes_t input;
    pd_U256_V1_t value;
    pd_u32_t gas_limit;
    pd_U256_V1_t gas_price;
    pd_OptionU256_V1_t nonce;
} pd_evm_call_V1_t;

#define PD_CALL_EVM_CREATE_V1 2
typedef struct {
    pd_H160_V1_t source;
    pd_Bytes_t init;
    pd_U256_V1_t value;
    pd_u32_t gas_limit;
    pd_U256_V1_t gas_price;
    pd_OptionU256_V1_t nonce;
} pd_evm_create_V1_t;

#define PD_CALL_EVM_CREATE2_V1 3
typedef struct {
    pd_H160_V1_t source;
    pd_Bytes_t init;
    pd_H256_V1_t salt;
    pd_U256_V1_t value;
    pd_u32_t gas_limit;
    pd_U256_V1_t gas_price;
    pd_OptionU256_V1_t nonce;
} pd_evm_create2_V1_t;

#define PD_CALL_CHAINBRIDGE_SET_THRESHOLD_V1 0
typedef struct {
    pd_u32_t threshold;
} pd_chainbridge_set_threshold_V1_t;

#define PD_CALL_CHAINBRIDGE_SET_RESOURCE_V1 1
typedef struct {
    pd_ResourceId_V1_t id;
    pd_Bytes_t method;
} pd_chainbridge_set_resource_V1_t;

#define PD_CALL_CHAINBRIDGE_REMOVE_RESOURCE_V1 2
typedef struct {
    pd_ResourceId_V1_t id;
} pd_chainbridge_remove_resource_V1_t;

#define PD_CALL_CHAINBRIDGE_WHITELIST_CHAIN_V1 3
typedef struct {
    pd_ChainId_V1_t id;
} pd_chainbridge_whitelist_chain_V1_t;

#define PD_CALL_CHAINBRIDGE_ADD_RELAYER_V1 4
typedef struct {
    pd_AccountId_V1_t v;
} pd_chainbridge_add_relayer_V1_t;

#define PD_CALL_CHAINBRIDGE_REMOVE_RELAYER_V1 5
typedef struct {
    pd_AccountId_V1_t v;
} pd_chainbridge_remove_relayer_V1_t;

#define PD_CALL_CHAINBRIDGE_ACKNOWLEDGE_PROPOSAL_V1 6
typedef struct {
    pd_DepositNonce_V1_t nonce;
    pd_ChainId_V1_t src_id;
    pd_ResourceId_V1_t r_id;
    pd_Proposal_t call;
} pd_chainbridge_acknowledge_proposal_V1_t;

#define PD_CALL_CHAINBRIDGE_REJECT_PROPOSAL_V1 7
typedef struct {
    pd_DepositNonce_V1_t nonce;
    pd_ChainId_V1_t src_id;
    pd_ResourceId_V1_t r_id;
    pd_Proposal_t call;
} pd_chainbridge_reject_proposal_V1_t;

#define PD_CALL_CHAINBRIDGE_EVAL_VOTE_STATE_V1 8
typedef struct {
    pd_DepositNonce_V1_t nonce;
    pd_ChainId_V1_t src_id;
    pd_Proposal_t prop;
} pd_chainbridge_eval_vote_state_V1_t;

#define PD_CALL_EDGEBRIDGE_TRANSFER_NATIVE_V1 0
typedef struct {
    pd_BalanceOf_t amount;
    pd_Bytes_t recipient;
    pd_ChainId_V1_t dest_id;
} pd_edgebridge_transfer_native_V1_t;

#define PD_CALL_EDGEBRIDGE_TRANSFER_V1 1
typedef struct {
    pd_AccountId_V1_t to;
    pd_BalanceOf_t amount;
} pd_edgebridge_transfer_V1_t;

#define PD_CALL_BOUNTIES_PROPOSE_BOUNTY_V1 0
typedef struct {
    pd_CompactBalanceOf_t value;
    pd_Bytes_t description;
} pd_bounties_propose_bounty_V1_t;

#define PD_CALL_BOUNTIES_APPROVE_BOUNTY_V1 1
typedef struct {
    pd_CompactBountyIndex_V1_t bounty_id;
} pd_bounties_approve_bounty_V1_t;

#define PD_CALL_BOUNTIES_PROPOSE_CURATOR_V1 2
typedef struct {
    pd_CompactBountyIndex_V1_t bounty_id;
    pd_LookupSource_V1_t curator;
    pd_CompactBalanceOf_t fee;
} pd_bounties_propose_curator_V1_t;

#define PD_CALL_BOUNTIES_UNASSIGN_CURATOR_V1 3
typedef struct {
    pd_CompactBountyIndex_V1_t bounty_id;
} pd_bounties_unassign_curator_V1_t;

#define PD_CALL_BOUNTIES_ACCEPT_CURATOR_V1 4
typedef struct {
    pd_CompactBountyIndex_V1_t bounty_id;
} pd_bounties_accept_curator_V1_t;

#define PD_CALL_BOUNTIES_AWARD_BOUNTY_V1 5
typedef struct {
    pd_CompactBountyIndex_V1_t bounty_id;
    pd_LookupSource_V1_t beneficiary;
} pd_bounties_award_bounty_V1_t;

#define PD_CALL_BOUNTIES_CLAIM_BOUNTY_V1 6
typedef struct {
    pd_CompactBountyIndex_V1_t bounty_id;
} pd_bounties_claim_bounty_V1_t;

#define PD_CALL_BOUNTIES_CLOSE_BOUNTY_V1 7
typedef struct {
    pd_CompactBountyIndex_V1_t bounty_id;
} pd_bounties_close_bounty_V1_t;

#define PD_CALL_BOUNTIES_EXTEND_BOUNTY_EXPIRY_V1 8
typedef struct {
    pd_CompactBountyIndex_V1_t bounty_id;
    pd_Bytes_t _remark;
} pd_bounties_extend_bounty_expiry_V1_t;

#define PD_CALL_TIPS_REPORT_AWESOME_V1 0
typedef struct {
    pd_Bytes_t reason;
    pd_AccountId_V1_t who;
} pd_tips_report_awesome_V1_t;

#define PD_CALL_TIPS_RETRACT_TIP_V1 1
typedef struct {
    pd_Hash_t hash;
} pd_tips_retract_tip_V1_t;

#define PD_CALL_TIPS_TIP_NEW_V1 2
typedef struct {
    pd_Bytes_t reason;
    pd_AccountId_V1_t who;
    pd_CompactBalanceOf_t tip_value;
} pd_tips_tip_new_V1_t;

#define PD_CALL_TIPS_TIP_V1 3
typedef struct {
    pd_Hash_t hash;
    pd_CompactBalanceOf_t tip_value;
} pd_tips_tip_V1_t;

#define PD_CALL_TIPS_CLOSE_TIP_V1 4
typedef struct {
    pd_Hash_t hash;
} pd_tips_close_tip_V1_t;

#define PD_CALL_TIPS_SLASH_TIP_V1 5
typedef struct {
    pd_Hash_t hash;
} pd_tips_slash_tip_V1_t;

#endif

typedef union {
    pd_utility_batch_V1_t utility_batch_V1;
    pd_utility_batch_all_V1_t utility_batch_all_V1;
    pd_staking_bond_V1_t staking_bond_V1;
    pd_staking_bond_extra_V1_t staking_bond_extra_V1;
    pd_staking_unbond_V1_t staking_unbond_V1;
    pd_staking_withdraw_unbonded_V1_t staking_withdraw_unbonded_V1;
    pd_staking_validate_V1_t staking_validate_V1;
    pd_staking_nominate_V1_t staking_nominate_V1;
    pd_staking_chill_V1_t staking_chill_V1;
    pd_staking_set_payee_V1_t staking_set_payee_V1;
    pd_staking_payout_stakers_V1_t staking_payout_stakers_V1;
    pd_staking_rebond_V1_t staking_rebond_V1;
    pd_session_set_keys_V1_t session_set_keys_V1;
    pd_session_purge_keys_V1_t session_purge_keys_V1;
#ifdef SUBSTRATE_PARSER_FULL
    pd_utility_as_derivative_V1_t utility_as_derivative_V1;
    pd_timestamp_set_V1_t timestamp_set_V1;
    pd_authorship_set_uncles_V1_t authorship_set_uncles_V1;
    pd_indices_claim_V1_t indices_claim_V1;
    pd_indices_transfer_V1_t indices_transfer_V1;
    pd_indices_free_V1_t indices_free_V1;
    pd_indices_force_transfer_V1_t indices_force_transfer_V1;
    pd_indices_freeze_V1_t indices_freeze_V1;
    pd_staking_set_controller_V1_t staking_set_controller_V1;
    pd_staking_set_validator_count_V1_t staking_set_validator_count_V1;
    pd_staking_increase_validator_count_V1_t staking_increase_validator_count_V1;
    pd_staking_scale_validator_count_V1_t staking_scale_validator_count_V1;
    pd_staking_force_no_eras_V1_t staking_force_no_eras_V1;
    pd_staking_force_new_era_V1_t staking_force_new_era_V1;
    pd_staking_set_invulnerables_V1_t staking_set_invulnerables_V1;
    pd_staking_force_unstake_V1_t staking_force_unstake_V1;
    pd_staking_force_new_era_always_V1_t staking_force_new_era_always_V1;
    pd_staking_cancel_deferred_slash_V1_t staking_cancel_deferred_slash_V1;
    pd_staking_set_history_depth_V1_t staking_set_history_depth_V1;
    pd_staking_reap_stash_V1_t staking_reap_stash_V1;
    pd_staking_submit_election_solution_V1_t staking_submit_election_solution_V1;
    pd_staking_submit_election_solution_unsigned_V1_t staking_submit_election_solution_unsigned_V1;
    pd_democracy_propose_V1_t democracy_propose_V1;
    pd_democracy_second_V1_t democracy_second_V1;
    pd_democracy_vote_V1_t democracy_vote_V1;
    pd_democracy_emergency_cancel_V1_t democracy_emergency_cancel_V1;
    pd_democracy_external_propose_V1_t democracy_external_propose_V1;
    pd_democracy_external_propose_majority_V1_t democracy_external_propose_majority_V1;
    pd_democracy_external_propose_default_V1_t democracy_external_propose_default_V1;
    pd_democracy_fast_track_V1_t democracy_fast_track_V1;
    pd_democracy_veto_external_V1_t democracy_veto_external_V1;
    pd_democracy_cancel_referendum_V1_t democracy_cancel_referendum_V1;
    pd_democracy_cancel_queued_V1_t democracy_cancel_queued_V1;
    pd_democracy_delegate_V1_t democracy_delegate_V1;
    pd_democracy_undelegate_V1_t democracy_undelegate_V1;
    pd_democracy_clear_public_proposals_V1_t democracy_clear_public_proposals_V1;
    pd_democracy_note_preimage_V1_t democracy_note_preimage_V1;
    pd_democracy_note_preimage_operational_V1_t democracy_note_preimage_operational_V1;
    pd_democracy_note_imminent_preimage_V1_t democracy_note_imminent_preimage_V1;
    pd_democracy_note_imminent_preimage_operational_V1_t democracy_note_imminent_preimage_operational_V1;
    pd_democracy_reap_preimage_V1_t democracy_reap_preimage_V1;
    pd_democracy_unlock_V1_t democracy_unlock_V1;
    pd_democracy_remove_vote_V1_t democracy_remove_vote_V1;
    pd_democracy_remove_other_vote_V1_t democracy_remove_other_vote_V1;
    pd_democracy_enact_proposal_V1_t democracy_enact_proposal_V1;
    pd_democracy_blacklist_V1_t democracy_blacklist_V1;
    pd_democracy_cancel_proposal_V1_t democracy_cancel_proposal_V1;
    pd_council_set_members_V1_t council_set_members_V1;
    pd_council_execute_V1_t council_execute_V1;
    pd_council_propose_V1_t council_propose_V1;
    pd_council_vote_V1_t council_vote_V1;
    pd_council_close_V1_t council_close_V1;
    pd_council_disapprove_proposal_V1_t council_disapprove_proposal_V1;
    pd_elections_vote_V1_t elections_vote_V1;
    pd_elections_remove_voter_V1_t elections_remove_voter_V1;
    pd_elections_report_defunct_voter_V1_t elections_report_defunct_voter_V1;
    pd_elections_submit_candidacy_V1_t elections_submit_candidacy_V1;
    pd_elections_renounce_candidacy_V1_t elections_renounce_candidacy_V1;
    pd_elections_remove_member_V1_t elections_remove_member_V1;
    pd_grandpa_report_equivocation_V1_t grandpa_report_equivocation_V1;
    pd_grandpa_report_equivocation_unsigned_V1_t grandpa_report_equivocation_unsigned_V1;
    pd_grandpa_note_stalled_V1_t grandpa_note_stalled_V1;
    pd_treasury_propose_spend_V1_t treasury_propose_spend_V1;
    pd_treasury_reject_proposal_V1_t treasury_reject_proposal_V1;
    pd_treasury_approve_proposal_V1_t treasury_approve_proposal_V1;
    pd_contracts_update_schedule_V1_t contracts_update_schedule_V1;
    pd_contracts_put_code_V1_t contracts_put_code_V1;
    pd_contracts_call_V1_t contracts_call_V1;
    pd_contracts_instantiate_V1_t contracts_instantiate_V1;
    pd_contracts_claim_surcharge_V1_t contracts_claim_surcharge_V1;
    pd_sudo_sudo_V1_t sudo_sudo_V1;
    pd_sudo_sudo_unchecked_weight_V1_t sudo_sudo_unchecked_weight_V1;
    pd_sudo_set_key_V1_t sudo_set_key_V1;
    pd_sudo_sudo_as_V1_t sudo_sudo_as_V1;
    pd_imonline_heartbeat_V1_t imonline_heartbeat_V1;
    pd_identity_add_registrar_V1_t identity_add_registrar_V1;
    pd_identity_set_identity_V1_t identity_set_identity_V1;
    pd_identity_set_subs_V1_t identity_set_subs_V1;
    pd_identity_clear_identity_V1_t identity_clear_identity_V1;
    pd_identity_request_judgement_V1_t identity_request_judgement_V1;
    pd_identity_cancel_request_V1_t identity_cancel_request_V1;
    pd_identity_set_fee_V1_t identity_set_fee_V1;
    pd_identity_set_account_id_V1_t identity_set_account_id_V1;
    pd_identity_set_fields_V1_t identity_set_fields_V1;
    pd_identity_provide_judgement_V1_t identity_provide_judgement_V1;
    pd_identity_kill_identity_V1_t identity_kill_identity_V1;
    pd_identity_add_sub_V1_t identity_add_sub_V1;
    pd_identity_rename_sub_V1_t identity_rename_sub_V1;
    pd_identity_remove_sub_V1_t identity_remove_sub_V1;
    pd_identity_quit_sub_V1_t identity_quit_sub_V1;
    pd_recovery_as_recovered_V1_t recovery_as_recovered_V1;
    pd_recovery_set_recovered_V1_t recovery_set_recovered_V1;
    pd_recovery_create_recovery_V1_t recovery_create_recovery_V1;
    pd_recovery_initiate_recovery_V1_t recovery_initiate_recovery_V1;
    pd_recovery_vouch_recovery_V1_t recovery_vouch_recovery_V1;
    pd_recovery_claim_recovery_V1_t recovery_claim_recovery_V1;
    pd_recovery_close_recovery_V1_t recovery_close_recovery_V1;
    pd_recovery_remove_recovery_V1_t recovery_remove_recovery_V1;
    pd_recovery_cancel_recovered_V1_t recovery_cancel_recovered_V1;
    pd_vesting_vest_V1_t vesting_vest_V1;
    pd_vesting_vest_other_V1_t vesting_vest_other_V1;
    pd_vesting_vested_transfer_V1_t vesting_vested_transfer_V1;
    pd_vesting_force_vested_transfer_V1_t vesting_force_vested_transfer_V1;
    pd_scheduler_schedule_V1_t scheduler_schedule_V1;
    pd_scheduler_cancel_V1_t scheduler_cancel_V1;
    pd_scheduler_schedule_named_V1_t scheduler_schedule_named_V1;
    pd_scheduler_cancel_named_V1_t scheduler_cancel_named_V1;
    pd_scheduler_schedule_after_V1_t scheduler_schedule_after_V1;
    pd_scheduler_schedule_named_after_V1_t scheduler_schedule_named_after_V1;
    pd_proxy_add_proxy_V1_t proxy_add_proxy_V1;
    pd_proxy_remove_proxy_V1_t proxy_remove_proxy_V1;
    pd_proxy_remove_proxies_V1_t proxy_remove_proxies_V1;
    pd_proxy_anonymous_V1_t proxy_anonymous_V1;
    pd_proxy_kill_anonymous_V1_t proxy_kill_anonymous_V1;
    pd_proxy_announce_V1_t proxy_announce_V1;
    pd_proxy_remove_announcement_V1_t proxy_remove_announcement_V1;
    pd_proxy_reject_announcement_V1_t proxy_reject_announcement_V1;
    pd_proxy_proxy_announced_V1_t proxy_proxy_announced_V1;
    pd_assets_create_V1_t assets_create_V1;
    pd_assets_force_create_V1_t assets_force_create_V1;
    pd_assets_destroy_V1_t assets_destroy_V1;
    pd_assets_force_destroy_V1_t assets_force_destroy_V1;
    pd_assets_mint_V1_t assets_mint_V1;
    pd_assets_burn_V1_t assets_burn_V1;
    pd_assets_transfer_V1_t assets_transfer_V1;
    pd_assets_force_transfer_V1_t assets_force_transfer_V1;
    pd_assets_freeze_V1_t assets_freeze_V1;
    pd_assets_thaw_V1_t assets_thaw_V1;
    pd_assets_transfer_ownership_V1_t assets_transfer_ownership_V1;
    pd_assets_set_team_V1_t assets_set_team_V1;
    pd_assets_set_max_zombies_V1_t assets_set_max_zombies_V1;
    pd_treasuryreward_set_current_payout_V1_t treasuryreward_set_current_payout_V1;
    pd_treasuryreward_set_minting_interval_V1_t treasuryreward_set_minting_interval_V1;
    pd_ethereum_transact_V1_t ethereum_transact_V1;
    pd_evm_withdraw_V1_t evm_withdraw_V1;
    pd_evm_call_V1_t evm_call_V1;
    pd_evm_create_V1_t evm_create_V1;
    pd_evm_create2_V1_t evm_create2_V1;
    pd_chainbridge_set_threshold_V1_t chainbridge_set_threshold_V1;
    pd_chainbridge_set_resource_V1_t chainbridge_set_resource_V1;
    pd_chainbridge_remove_resource_V1_t chainbridge_remove_resource_V1;
    pd_chainbridge_whitelist_chain_V1_t chainbridge_whitelist_chain_V1;
    pd_chainbridge_add_relayer_V1_t chainbridge_add_relayer_V1;
    pd_chainbridge_remove_relayer_V1_t chainbridge_remove_relayer_V1;
    pd_chainbridge_acknowledge_proposal_V1_t chainbridge_acknowledge_proposal_V1;
    pd_chainbridge_reject_proposal_V1_t chainbridge_reject_proposal_V1;
    pd_chainbridge_eval_vote_state_V1_t chainbridge_eval_vote_state_V1;
    pd_edgebridge_transfer_native_V1_t edgebridge_transfer_native_V1;
    pd_edgebridge_transfer_V1_t edgebridge_transfer_V1;
    pd_bounties_propose_bounty_V1_t bounties_propose_bounty_V1;
    pd_bounties_approve_bounty_V1_t bounties_approve_bounty_V1;
    pd_bounties_propose_curator_V1_t bounties_propose_curator_V1;
    pd_bounties_unassign_curator_V1_t bounties_unassign_curator_V1;
    pd_bounties_accept_curator_V1_t bounties_accept_curator_V1;
    pd_bounties_award_bounty_V1_t bounties_award_bounty_V1;
    pd_bounties_claim_bounty_V1_t bounties_claim_bounty_V1;
    pd_bounties_close_bounty_V1_t bounties_close_bounty_V1;
    pd_bounties_extend_bounty_expiry_V1_t bounties_extend_bounty_expiry_V1;
    pd_tips_report_awesome_V1_t tips_report_awesome_V1;
    pd_tips_retract_tip_V1_t tips_retract_tip_V1;
    pd_tips_tip_new_V1_t tips_tip_new_V1;
    pd_tips_tip_V1_t tips_tip_V1;
    pd_tips_close_tip_V1_t tips_close_tip_V1;
    pd_tips_slash_tip_V1_t tips_slash_tip_V1;
#endif
} pd_MethodBasic_V1_t;

#define PD_CALL_BALANCES_TRANSFER_V1 0
typedef struct {
    pd_LookupSource_V1_t dest;
    pd_CompactBalance_t value;
} pd_balances_transfer_V1_t;

#define PD_CALL_BALANCES_TRANSFER_KEEP_ALIVE_V1 3
typedef struct {
    pd_LookupSource_V1_t dest;
    pd_CompactBalance_t value;
} pd_balances_transfer_keep_alive_V1_t;

#ifdef SUBSTRATE_PARSER_FULL
#define PD_CALL_SYSTEM_FILL_BLOCK_V1 0
typedef struct {
    pd_Perbill_V1_t _ratio;
} pd_system_fill_block_V1_t;

#define PD_CALL_SYSTEM_REMARK_V1 1
typedef struct {
    pd_Bytes_t _remark;
} pd_system_remark_V1_t;

#define PD_CALL_SYSTEM_SET_HEAP_PAGES_V1 2
typedef struct {
    pd_u64_t pages;
} pd_system_set_heap_pages_V1_t;

#define PD_CALL_SYSTEM_SET_CODE_V1 3
typedef struct {
    pd_Bytes_t code;
} pd_system_set_code_V1_t;

#define PD_CALL_SYSTEM_SET_CODE_WITHOUT_CHECKS_V1 4
typedef struct {
    pd_Bytes_t code;
} pd_system_set_code_without_checks_V1_t;

#define PD_CALL_SYSTEM_SET_CHANGES_TRIE_CONFIG_V1 5
typedef struct {
    pd_OptionChangesTrieConfiguration_V1_t changes_trie_config;
} pd_system_set_changes_trie_config_V1_t;

#define PD_CALL_SYSTEM_SET_STORAGE_V1 6
typedef struct {
    pd_VecKeyValue_V1_t items;
} pd_system_set_storage_V1_t;

#define PD_CALL_SYSTEM_KILL_STORAGE_V1 7
typedef struct {
    pd_VecKey_V1_t keys;
} pd_system_kill_storage_V1_t;

#define PD_CALL_SYSTEM_KILL_PREFIX_V1 8
typedef struct {
    pd_Key_V1_t prefix;
    pd_u32_t _subkeys;
} pd_system_kill_prefix_V1_t;

#define PD_CALL_SYSTEM_SUICIDE_V1 9
typedef struct {
} pd_system_suicide_V1_t;

#define PD_CALL_BALANCES_SET_BALANCE_V1 1
typedef struct {
    pd_LookupSource_V1_t who;
    pd_CompactBalance_t new_free;
    pd_CompactBalance_t new_reserved;
} pd_balances_set_balance_V1_t;

#define PD_CALL_BALANCES_FORCE_TRANSFER_V1 2
typedef struct {
    pd_LookupSource_V1_t source;
    pd_LookupSource_V1_t dest;
    pd_CompactBalance_t value;
} pd_balances_force_transfer_V1_t;

#define PD_CALL_PROXY_PROXY_V1 0
typedef struct {
    pd_AccountId_V1_t real;
    pd_OptionProxyType_V1_t force_proxy_type;
    pd_Call_t call;
} pd_proxy_proxy_V1_t;

#define PD_CALL_MULTISIG_AS_MULTI_THRESHOLD_1_V1 0
typedef struct {
    pd_VecAccountId_V1_t other_signatories;
    pd_Call_t call;
} pd_multisig_as_multi_threshold_1_V1_t;

#define PD_CALL_MULTISIG_AS_MULTI_V1 1
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_V1_t other_signatories;
    pd_OptionTimepoint_V1_t maybe_timepoint;
    pd_OpaqueCall_V1_t call;
    pd_bool_t store_call;
    pd_Weight_V1_t max_weight;
} pd_multisig_as_multi_V1_t;

#define PD_CALL_MULTISIG_APPROVE_AS_MULTI_V1 2
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_V1_t other_signatories;
    pd_OptionTimepoint_V1_t maybe_timepoint;
    pd_u8_array_32_V1_t call_hash;
    pd_Weight_V1_t max_weight;
} pd_multisig_approve_as_multi_V1_t;

#define PD_CALL_MULTISIG_CANCEL_AS_MULTI_V1 3
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_V1_t other_signatories;
    pd_Timepoint_V1_t timepoint;
    pd_u8_array_32_V1_t call_hash;
} pd_multisig_cancel_as_multi_V1_t;

#endif

typedef union {
    pd_balances_transfer_V1_t balances_transfer_V1;
    pd_balances_transfer_keep_alive_V1_t balances_transfer_keep_alive_V1;
#ifdef SUBSTRATE_PARSER_FULL
    pd_system_fill_block_V1_t system_fill_block_V1;
    pd_system_remark_V1_t system_remark_V1;
    pd_system_set_heap_pages_V1_t system_set_heap_pages_V1;
    pd_system_set_code_V1_t system_set_code_V1;
    pd_system_set_code_without_checks_V1_t system_set_code_without_checks_V1;
    pd_system_set_changes_trie_config_V1_t system_set_changes_trie_config_V1;
    pd_system_set_storage_V1_t system_set_storage_V1;
    pd_system_kill_storage_V1_t system_kill_storage_V1;
    pd_system_kill_prefix_V1_t system_kill_prefix_V1;
    pd_system_suicide_V1_t system_suicide_V1;
    pd_balances_set_balance_V1_t balances_set_balance_V1;
    pd_balances_force_transfer_V1_t balances_force_transfer_V1;
    pd_proxy_proxy_V1_t proxy_proxy_V1;
    pd_multisig_as_multi_threshold_1_V1_t multisig_as_multi_threshold_1_V1;
    pd_multisig_as_multi_V1_t multisig_as_multi_V1;
    pd_multisig_approve_as_multi_V1_t multisig_approve_as_multi_V1;
    pd_multisig_cancel_as_multi_V1_t multisig_cancel_as_multi_V1;
#endif
} pd_MethodNested_V1_t;

typedef union {
    pd_MethodBasic_V1_t basic;
    pd_MethodNested_V1_t nested;
} pd_Method_V1_t;

#ifdef __cplusplus
}
#endif

#pragma clang diagnostic pop
