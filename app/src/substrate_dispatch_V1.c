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

#include "substrate_dispatch_V1.h"
#include "substrate_strings.h"
#include "zxmacros.h"
#include <stdint.h>

__Z_INLINE parser_error_t _readMethod_utility_batch_V1(
    parser_context_t* c, pd_utility_batch_V1_t* m)
{
    CHECK_ERROR(_readVecCall(c, &m->calls))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_utility_batch_all_V1(
    parser_context_t* c, pd_utility_batch_all_V1_t* m)
{
    CHECK_ERROR(_readVecCall(c, &m->calls))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_transfer_V1(
    parser_context_t* c, pd_balances_transfer_V1_t* m)
{
    CHECK_ERROR(_readLookupSource_V1(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_transfer_keep_alive_V1(
    parser_context_t* c, pd_balances_transfer_keep_alive_V1_t* m)
{
    CHECK_ERROR(_readLookupSource_V1(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_bond_V1(
    parser_context_t* c, pd_staking_bond_V1_t* m)
{
    CHECK_ERROR(_readLookupSource_V1(c, &m->controller))
    CHECK_ERROR(_readCompactBalanceOf(c, &m->value))
    CHECK_ERROR(_readRewardDestination_V1(c, &m->payee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_bond_extra_V1(
    parser_context_t* c, pd_staking_bond_extra_V1_t* m)
{
    CHECK_ERROR(_readCompactBalanceOf(c, &m->max_additional))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_unbond_V1(
    parser_context_t* c, pd_staking_unbond_V1_t* m)
{
    CHECK_ERROR(_readCompactBalanceOf(c, &m->value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_withdraw_unbonded_V1(
    parser_context_t* c, pd_staking_withdraw_unbonded_V1_t* m)
{
    CHECK_ERROR(_readu32(c, &m->num_slashing_spans))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_validate_V1(
    parser_context_t* c, pd_staking_validate_V1_t* m)
{
    CHECK_ERROR(_readValidatorPrefs_V1(c, &m->prefs))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_nominate_V1(
    parser_context_t* c, pd_staking_nominate_V1_t* m)
{
    CHECK_ERROR(_readVecLookupSource_V1(c, &m->targets))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_chill_V1(
    parser_context_t* c, pd_staking_chill_V1_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_payee_V1(
    parser_context_t* c, pd_staking_set_payee_V1_t* m)
{
    CHECK_ERROR(_readRewardDestination_V1(c, &m->payee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_payout_stakers_V1(
    parser_context_t* c, pd_staking_payout_stakers_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->validator_stash))
    CHECK_ERROR(_readEraIndex_V1(c, &m->era))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_rebond_V1(
    parser_context_t* c, pd_staking_rebond_V1_t* m)
{
    CHECK_ERROR(_readCompactBalanceOf(c, &m->value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_session_set_keys_V1(
    parser_context_t* c, pd_session_set_keys_V1_t* m)
{
    CHECK_ERROR(_readKeys_V1(c, &m->keys))
    CHECK_ERROR(_readBytes(c, &m->proof))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_session_purge_keys_V1(
    parser_context_t* c, pd_session_purge_keys_V1_t* m)
{
    return parser_ok;
}

#ifdef SUBSTRATE_PARSER_FULL
__Z_INLINE parser_error_t _readMethod_system_fill_block_V1(
    parser_context_t* c, pd_system_fill_block_V1_t* m)
{
    CHECK_ERROR(_readPerbill_V1(c, &m->_ratio))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_remark_V1(
    parser_context_t* c, pd_system_remark_V1_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->_remark))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_heap_pages_V1(
    parser_context_t* c, pd_system_set_heap_pages_V1_t* m)
{
    CHECK_ERROR(_readu64(c, &m->pages))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_code_V1(
    parser_context_t* c, pd_system_set_code_V1_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->code))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_code_without_checks_V1(
    parser_context_t* c, pd_system_set_code_without_checks_V1_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->code))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_changes_trie_config_V1(
    parser_context_t* c, pd_system_set_changes_trie_config_V1_t* m)
{
    CHECK_ERROR(_readOptionChangesTrieConfiguration_V1(c, &m->changes_trie_config))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_storage_V1(
    parser_context_t* c, pd_system_set_storage_V1_t* m)
{
    CHECK_ERROR(_readVecKeyValue_V1(c, &m->items))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_kill_storage_V1(
    parser_context_t* c, pd_system_kill_storage_V1_t* m)
{
    CHECK_ERROR(_readVecKey_V1(c, &m->keys))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_kill_prefix_V1(
    parser_context_t* c, pd_system_kill_prefix_V1_t* m)
{
    CHECK_ERROR(_readKey_V1(c, &m->prefix))
    CHECK_ERROR(_readu32(c, &m->_subkeys))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_suicide_V1(
    parser_context_t* c, pd_system_suicide_V1_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_utility_as_derivative_V1(
    parser_context_t* c, pd_utility_as_derivative_V1_t* m)
{
    CHECK_ERROR(_readu16(c, &m->index))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_timestamp_set_V1(
    parser_context_t* c, pd_timestamp_set_V1_t* m)
{
    CHECK_ERROR(_readCompactMoment_V1(c, &m->now))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_authorship_set_uncles_V1(
    parser_context_t* c, pd_authorship_set_uncles_V1_t* m)
{
    CHECK_ERROR(_readVecHeader(c, &m->new_uncles))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_indices_claim_V1(
    parser_context_t* c, pd_indices_claim_V1_t* m)
{
    CHECK_ERROR(_readAccountIndex_V1(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_indices_transfer_V1(
    parser_context_t* c, pd_indices_transfer_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->new_))
    CHECK_ERROR(_readAccountIndex_V1(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_indices_free_V1(
    parser_context_t* c, pd_indices_free_V1_t* m)
{
    CHECK_ERROR(_readAccountIndex_V1(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_indices_force_transfer_V1(
    parser_context_t* c, pd_indices_force_transfer_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->new_))
    CHECK_ERROR(_readAccountIndex_V1(c, &m->index))
    CHECK_ERROR(_readbool(c, &m->freeze))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_indices_freeze_V1(
    parser_context_t* c, pd_indices_freeze_V1_t* m)
{
    CHECK_ERROR(_readAccountIndex_V1(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_set_balance_V1(
    parser_context_t* c, pd_balances_set_balance_V1_t* m)
{
    CHECK_ERROR(_readLookupSource_V1(c, &m->who))
    CHECK_ERROR(_readCompactBalance(c, &m->new_free))
    CHECK_ERROR(_readCompactBalance(c, &m->new_reserved))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_force_transfer_V1(
    parser_context_t* c, pd_balances_force_transfer_V1_t* m)
{
    CHECK_ERROR(_readLookupSource_V1(c, &m->source))
    CHECK_ERROR(_readLookupSource_V1(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_controller_V1(
    parser_context_t* c, pd_staking_set_controller_V1_t* m)
{
    CHECK_ERROR(_readLookupSource_V1(c, &m->controller))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_validator_count_V1(
    parser_context_t* c, pd_staking_set_validator_count_V1_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_increase_validator_count_V1(
    parser_context_t* c, pd_staking_increase_validator_count_V1_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->additional))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_scale_validator_count_V1(
    parser_context_t* c, pd_staking_scale_validator_count_V1_t* m)
{
    CHECK_ERROR(_readPercent_V1(c, &m->factor))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_no_eras_V1(
    parser_context_t* c, pd_staking_force_no_eras_V1_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_new_era_V1(
    parser_context_t* c, pd_staking_force_new_era_V1_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_invulnerables_V1(
    parser_context_t* c, pd_staking_set_invulnerables_V1_t* m)
{
    CHECK_ERROR(_readVecAccountId_V1(c, &m->invulnerables))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_unstake_V1(
    parser_context_t* c, pd_staking_force_unstake_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->stash))
    CHECK_ERROR(_readu32(c, &m->num_slashing_spans))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_new_era_always_V1(
    parser_context_t* c, pd_staking_force_new_era_always_V1_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_cancel_deferred_slash_V1(
    parser_context_t* c, pd_staking_cancel_deferred_slash_V1_t* m)
{
    CHECK_ERROR(_readEraIndex_V1(c, &m->era))
    CHECK_ERROR(_readVecu32(c, &m->slash_indices))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_history_depth_V1(
    parser_context_t* c, pd_staking_set_history_depth_V1_t* m)
{
    CHECK_ERROR(_readCompactEraIndex_V1(c, &m->new_history_depth))
    CHECK_ERROR(_readCompactu32(c, &m->_era_items_deleted))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_reap_stash_V1(
    parser_context_t* c, pd_staking_reap_stash_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->stash))
    CHECK_ERROR(_readu32(c, &m->num_slashing_spans))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_submit_election_solution_V1(
    parser_context_t* c, pd_staking_submit_election_solution_V1_t* m)
{
    CHECK_ERROR(_readVecValidatorIndex_V1(c, &m->winners))
    CHECK_ERROR(_readCompactAssignments_V1(c, &m->compact))
    CHECK_ERROR(_readElectionScore_V1(c, &m->score))
    CHECK_ERROR(_readEraIndex_V1(c, &m->era))
    CHECK_ERROR(_readElectionSize_V1(c, &m->size))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_submit_election_solution_unsigned_V1(
    parser_context_t* c, pd_staking_submit_election_solution_unsigned_V1_t* m)
{
    CHECK_ERROR(_readVecValidatorIndex_V1(c, &m->winners))
    CHECK_ERROR(_readCompactAssignments_V1(c, &m->compact))
    CHECK_ERROR(_readElectionScore_V1(c, &m->score))
    CHECK_ERROR(_readEraIndex_V1(c, &m->era))
    CHECK_ERROR(_readElectionSize_V1(c, &m->size))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_propose_V1(
    parser_context_t* c, pd_democracy_propose_V1_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    CHECK_ERROR(_readCompactBalanceOf(c, &m->value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_second_V1(
    parser_context_t* c, pd_democracy_second_V1_t* m)
{
    CHECK_ERROR(_readCompactPropIndex_V1(c, &m->proposal))
    CHECK_ERROR(_readCompactu32(c, &m->seconds_upper_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_vote_V1(
    parser_context_t* c, pd_democracy_vote_V1_t* m)
{
    CHECK_ERROR(_readCompactReferendumIndex_V1(c, &m->ref_index))
    CHECK_ERROR(_readAccountVote_V1(c, &m->vote))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_emergency_cancel_V1(
    parser_context_t* c, pd_democracy_emergency_cancel_V1_t* m)
{
    CHECK_ERROR(_readReferendumIndex_V1(c, &m->ref_index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_external_propose_V1(
    parser_context_t* c, pd_democracy_external_propose_V1_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_external_propose_majority_V1(
    parser_context_t* c, pd_democracy_external_propose_majority_V1_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_external_propose_default_V1(
    parser_context_t* c, pd_democracy_external_propose_default_V1_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_fast_track_V1(
    parser_context_t* c, pd_democracy_fast_track_V1_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    CHECK_ERROR(_readBlockNumber(c, &m->voting_period))
    CHECK_ERROR(_readBlockNumber(c, &m->delay))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_veto_external_V1(
    parser_context_t* c, pd_democracy_veto_external_V1_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_cancel_referendum_V1(
    parser_context_t* c, pd_democracy_cancel_referendum_V1_t* m)
{
    CHECK_ERROR(_readCompactReferendumIndex_V1(c, &m->ref_index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_cancel_queued_V1(
    parser_context_t* c, pd_democracy_cancel_queued_V1_t* m)
{
    CHECK_ERROR(_readReferendumIndex_V1(c, &m->which))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_delegate_V1(
    parser_context_t* c, pd_democracy_delegate_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->to))
    CHECK_ERROR(_readConviction_V1(c, &m->conviction))
    CHECK_ERROR(_readBalanceOf(c, &m->balance))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_undelegate_V1(
    parser_context_t* c, pd_democracy_undelegate_V1_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_clear_public_proposals_V1(
    parser_context_t* c, pd_democracy_clear_public_proposals_V1_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_note_preimage_V1(
    parser_context_t* c, pd_democracy_note_preimage_V1_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->encoded_proposal))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_note_preimage_operational_V1(
    parser_context_t* c, pd_democracy_note_preimage_operational_V1_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->encoded_proposal))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_note_imminent_preimage_V1(
    parser_context_t* c, pd_democracy_note_imminent_preimage_V1_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->encoded_proposal))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_note_imminent_preimage_operational_V1(
    parser_context_t* c, pd_democracy_note_imminent_preimage_operational_V1_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->encoded_proposal))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_reap_preimage_V1(
    parser_context_t* c, pd_democracy_reap_preimage_V1_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    CHECK_ERROR(_readCompactu32(c, &m->proposal_len_upper_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_unlock_V1(
    parser_context_t* c, pd_democracy_unlock_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->target))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_remove_vote_V1(
    parser_context_t* c, pd_democracy_remove_vote_V1_t* m)
{
    CHECK_ERROR(_readReferendumIndex_V1(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_remove_other_vote_V1(
    parser_context_t* c, pd_democracy_remove_other_vote_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->target))
    CHECK_ERROR(_readReferendumIndex_V1(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_enact_proposal_V1(
    parser_context_t* c, pd_democracy_enact_proposal_V1_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    CHECK_ERROR(_readReferendumIndex_V1(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_blacklist_V1(
    parser_context_t* c, pd_democracy_blacklist_V1_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    CHECK_ERROR(_readOptionReferendumIndex_V1(c, &m->maybe_ref_index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_cancel_proposal_V1(
    parser_context_t* c, pd_democracy_cancel_proposal_V1_t* m)
{
    CHECK_ERROR(_readCompactPropIndex_V1(c, &m->prop_index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_council_set_members_V1(
    parser_context_t* c, pd_council_set_members_V1_t* m)
{
    CHECK_ERROR(_readVecAccountId_V1(c, &m->new_members))
    CHECK_ERROR(_readOptionAccountId_V1(c, &m->prime))
    CHECK_ERROR(_readMemberCount_V1(c, &m->old_count))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_council_execute_V1(
    parser_context_t* c, pd_council_execute_V1_t* m)
{
    CHECK_ERROR(_readProposal(c, &m->proposal))
    CHECK_ERROR(_readCompactu32(c, &m->length_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_council_propose_V1(
    parser_context_t* c, pd_council_propose_V1_t* m)
{
    CHECK_ERROR(_readCompactMemberCount_V1(c, &m->threshold))
    CHECK_ERROR(_readProposal(c, &m->proposal))
    CHECK_ERROR(_readCompactu32(c, &m->length_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_council_vote_V1(
    parser_context_t* c, pd_council_vote_V1_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal))
    CHECK_ERROR(_readCompactProposalIndex_V1(c, &m->index))
    CHECK_ERROR(_readbool(c, &m->approve))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_council_close_V1(
    parser_context_t* c, pd_council_close_V1_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    CHECK_ERROR(_readCompactProposalIndex_V1(c, &m->index))
    CHECK_ERROR(_readCompactWeight_V1(c, &m->proposal_weight_bound))
    CHECK_ERROR(_readCompactu32(c, &m->length_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_council_disapprove_proposal_V1(
    parser_context_t* c, pd_council_disapprove_proposal_V1_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_elections_vote_V1(
    parser_context_t* c, pd_elections_vote_V1_t* m)
{
    CHECK_ERROR(_readVecAccountId_V1(c, &m->votes))
    CHECK_ERROR(_readCompactBalanceOf(c, &m->value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_elections_remove_voter_V1(
    parser_context_t* c, pd_elections_remove_voter_V1_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_elections_report_defunct_voter_V1(
    parser_context_t* c, pd_elections_report_defunct_voter_V1_t* m)
{
    CHECK_ERROR(_readDefunctVoter_V1(c, &m->defunct))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_elections_submit_candidacy_V1(
    parser_context_t* c, pd_elections_submit_candidacy_V1_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->candidate_count))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_elections_renounce_candidacy_V1(
    parser_context_t* c, pd_elections_renounce_candidacy_V1_t* m)
{
    CHECK_ERROR(_readRenouncing_V1(c, &m->renouncing))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_elections_remove_member_V1(
    parser_context_t* c, pd_elections_remove_member_V1_t* m)
{
    CHECK_ERROR(_readLookupSource_V1(c, &m->who))
    CHECK_ERROR(_readbool(c, &m->has_replacement))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_grandpa_report_equivocation_V1(
    parser_context_t* c, pd_grandpa_report_equivocation_V1_t* m)
{
    CHECK_ERROR(_readGrandpaEquivocationProof_V1(c, &m->equivocation_proof))
    CHECK_ERROR(_readKeyOwnerProof_V1(c, &m->key_owner_proof))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_grandpa_report_equivocation_unsigned_V1(
    parser_context_t* c, pd_grandpa_report_equivocation_unsigned_V1_t* m)
{
    CHECK_ERROR(_readGrandpaEquivocationProof_V1(c, &m->equivocation_proof))
    CHECK_ERROR(_readKeyOwnerProof_V1(c, &m->key_owner_proof))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_grandpa_note_stalled_V1(
    parser_context_t* c, pd_grandpa_note_stalled_V1_t* m)
{
    CHECK_ERROR(_readBlockNumber(c, &m->delay))
    CHECK_ERROR(_readBlockNumber(c, &m->best_finalized_block_number))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_treasury_propose_spend_V1(
    parser_context_t* c, pd_treasury_propose_spend_V1_t* m)
{
    CHECK_ERROR(_readCompactBalanceOf(c, &m->value))
    CHECK_ERROR(_readLookupSource_V1(c, &m->beneficiary))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_treasury_reject_proposal_V1(
    parser_context_t* c, pd_treasury_reject_proposal_V1_t* m)
{
    CHECK_ERROR(_readCompactProposalIndex_V1(c, &m->proposal_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_treasury_approve_proposal_V1(
    parser_context_t* c, pd_treasury_approve_proposal_V1_t* m)
{
    CHECK_ERROR(_readCompactProposalIndex_V1(c, &m->proposal_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_contracts_update_schedule_V1(
    parser_context_t* c, pd_contracts_update_schedule_V1_t* m)
{
    CHECK_ERROR(_readSchedule_V1(c, &m->schedule))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_contracts_put_code_V1(
    parser_context_t* c, pd_contracts_put_code_V1_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->code))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_contracts_call_V1(
    parser_context_t* c, pd_contracts_call_V1_t* m)
{
    CHECK_ERROR(_readLookupSource_V1(c, &m->dest))
    CHECK_ERROR(_readCompactBalanceOf(c, &m->value))
    CHECK_ERROR(_readCompactGas_V1(c, &m->gas_limit))
    CHECK_ERROR(_readBytes(c, &m->data))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_contracts_instantiate_V1(
    parser_context_t* c, pd_contracts_instantiate_V1_t* m)
{
    CHECK_ERROR(_readCompactBalanceOf(c, &m->endowment))
    CHECK_ERROR(_readCompactGas_V1(c, &m->gas_limit))
    CHECK_ERROR(_readCodeHash_V1(c, &m->code_hash))
    CHECK_ERROR(_readBytes(c, &m->data))
    CHECK_ERROR(_readBytes(c, &m->salt))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_contracts_claim_surcharge_V1(
    parser_context_t* c, pd_contracts_claim_surcharge_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->dest))
    CHECK_ERROR(_readOptionAccountId_V1(c, &m->aux_sender))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_sudo_sudo_V1(
    parser_context_t* c, pd_sudo_sudo_V1_t* m)
{
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_sudo_sudo_unchecked_weight_V1(
    parser_context_t* c, pd_sudo_sudo_unchecked_weight_V1_t* m)
{
    CHECK_ERROR(_readCall(c, &m->call))
    CHECK_ERROR(_readWeight_V1(c, &m->_weight))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_sudo_set_key_V1(
    parser_context_t* c, pd_sudo_set_key_V1_t* m)
{
    CHECK_ERROR(_readLookupSource_V1(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_sudo_sudo_as_V1(
    parser_context_t* c, pd_sudo_sudo_as_V1_t* m)
{
    CHECK_ERROR(_readLookupSource_V1(c, &m->who))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_imonline_heartbeat_V1(
    parser_context_t* c, pd_imonline_heartbeat_V1_t* m)
{
    CHECK_ERROR(_readHeartbeat(c, &m->heartbeat))
    CHECK_ERROR(_readSignature_V1(c, &m->_signature))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_add_registrar_V1(
    parser_context_t* c, pd_identity_add_registrar_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->account))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_set_identity_V1(
    parser_context_t* c, pd_identity_set_identity_V1_t* m)
{
    CHECK_ERROR(_readIdentityInfo_V1(c, &m->info))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_set_subs_V1(
    parser_context_t* c, pd_identity_set_subs_V1_t* m)
{
    CHECK_ERROR(_readVecTupleAccountIdData_V1(c, &m->subs))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_clear_identity_V1(
    parser_context_t* c, pd_identity_clear_identity_V1_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_request_judgement_V1(
    parser_context_t* c, pd_identity_request_judgement_V1_t* m)
{
    CHECK_ERROR(_readCompactRegistrarIndex_V1(c, &m->reg_index))
    CHECK_ERROR(_readCompactBalanceOf(c, &m->max_fee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_cancel_request_V1(
    parser_context_t* c, pd_identity_cancel_request_V1_t* m)
{
    CHECK_ERROR(_readRegistrarIndex_V1(c, &m->reg_index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_set_fee_V1(
    parser_context_t* c, pd_identity_set_fee_V1_t* m)
{
    CHECK_ERROR(_readCompactRegistrarIndex_V1(c, &m->index))
    CHECK_ERROR(_readCompactBalanceOf(c, &m->fee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_set_account_id_V1(
    parser_context_t* c, pd_identity_set_account_id_V1_t* m)
{
    CHECK_ERROR(_readCompactRegistrarIndex_V1(c, &m->index))
    CHECK_ERROR(_readAccountId_V1(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_set_fields_V1(
    parser_context_t* c, pd_identity_set_fields_V1_t* m)
{
    CHECK_ERROR(_readCompactRegistrarIndex_V1(c, &m->index))
    CHECK_ERROR(_readIdentityFields_V1(c, &m->fields))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_provide_judgement_V1(
    parser_context_t* c, pd_identity_provide_judgement_V1_t* m)
{
    CHECK_ERROR(_readCompactRegistrarIndex_V1(c, &m->reg_index))
    CHECK_ERROR(_readLookupSource_V1(c, &m->target))
    CHECK_ERROR(_readIdentityJudgement_V1(c, &m->judgement))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_kill_identity_V1(
    parser_context_t* c, pd_identity_kill_identity_V1_t* m)
{
    CHECK_ERROR(_readLookupSource_V1(c, &m->target))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_add_sub_V1(
    parser_context_t* c, pd_identity_add_sub_V1_t* m)
{
    CHECK_ERROR(_readLookupSource_V1(c, &m->sub))
    CHECK_ERROR(_readData(c, &m->data))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_rename_sub_V1(
    parser_context_t* c, pd_identity_rename_sub_V1_t* m)
{
    CHECK_ERROR(_readLookupSource_V1(c, &m->sub))
    CHECK_ERROR(_readData(c, &m->data))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_remove_sub_V1(
    parser_context_t* c, pd_identity_remove_sub_V1_t* m)
{
    CHECK_ERROR(_readLookupSource_V1(c, &m->sub))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_quit_sub_V1(
    parser_context_t* c, pd_identity_quit_sub_V1_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_recovery_as_recovered_V1(
    parser_context_t* c, pd_recovery_as_recovered_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->account))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_recovery_set_recovered_V1(
    parser_context_t* c, pd_recovery_set_recovered_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->lost))
    CHECK_ERROR(_readAccountId_V1(c, &m->rescuer))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_recovery_create_recovery_V1(
    parser_context_t* c, pd_recovery_create_recovery_V1_t* m)
{
    CHECK_ERROR(_readVecAccountId_V1(c, &m->friends))
    CHECK_ERROR(_readu16(c, &m->threshold))
    CHECK_ERROR(_readBlockNumber(c, &m->delay_period))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_recovery_initiate_recovery_V1(
    parser_context_t* c, pd_recovery_initiate_recovery_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->account))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_recovery_vouch_recovery_V1(
    parser_context_t* c, pd_recovery_vouch_recovery_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->lost))
    CHECK_ERROR(_readAccountId_V1(c, &m->rescuer))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_recovery_claim_recovery_V1(
    parser_context_t* c, pd_recovery_claim_recovery_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->account))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_recovery_close_recovery_V1(
    parser_context_t* c, pd_recovery_close_recovery_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->rescuer))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_recovery_remove_recovery_V1(
    parser_context_t* c, pd_recovery_remove_recovery_V1_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_recovery_cancel_recovered_V1(
    parser_context_t* c, pd_recovery_cancel_recovered_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->account))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_vesting_vest_V1(
    parser_context_t* c, pd_vesting_vest_V1_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_vesting_vest_other_V1(
    parser_context_t* c, pd_vesting_vest_other_V1_t* m)
{
    CHECK_ERROR(_readLookupSource_V1(c, &m->target))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_vesting_vested_transfer_V1(
    parser_context_t* c, pd_vesting_vested_transfer_V1_t* m)
{
    CHECK_ERROR(_readLookupSource_V1(c, &m->target))
    CHECK_ERROR(_readVestingInfo_V1(c, &m->schedule))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_vesting_force_vested_transfer_V1(
    parser_context_t* c, pd_vesting_force_vested_transfer_V1_t* m)
{
    CHECK_ERROR(_readLookupSource_V1(c, &m->source))
    CHECK_ERROR(_readLookupSource_V1(c, &m->target))
    CHECK_ERROR(_readVestingInfo_V1(c, &m->schedule))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_scheduler_schedule_V1(
    parser_context_t* c, pd_scheduler_schedule_V1_t* m)
{
    CHECK_ERROR(_readBlockNumber(c, &m->when))
    CHECK_ERROR(_readOptionPeriod_V1(c, &m->maybe_periodic))
    CHECK_ERROR(_readPriority_V1(c, &m->priority))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_scheduler_cancel_V1(
    parser_context_t* c, pd_scheduler_cancel_V1_t* m)
{
    CHECK_ERROR(_readBlockNumber(c, &m->when))
    CHECK_ERROR(_readu32(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_scheduler_schedule_named_V1(
    parser_context_t* c, pd_scheduler_schedule_named_V1_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->id))
    CHECK_ERROR(_readBlockNumber(c, &m->when))
    CHECK_ERROR(_readOptionPeriod_V1(c, &m->maybe_periodic))
    CHECK_ERROR(_readPriority_V1(c, &m->priority))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_scheduler_cancel_named_V1(
    parser_context_t* c, pd_scheduler_cancel_named_V1_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_scheduler_schedule_after_V1(
    parser_context_t* c, pd_scheduler_schedule_after_V1_t* m)
{
    CHECK_ERROR(_readBlockNumber(c, &m->after))
    CHECK_ERROR(_readOptionPeriod_V1(c, &m->maybe_periodic))
    CHECK_ERROR(_readPriority_V1(c, &m->priority))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_scheduler_schedule_named_after_V1(
    parser_context_t* c, pd_scheduler_schedule_named_after_V1_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->id))
    CHECK_ERROR(_readBlockNumber(c, &m->after))
    CHECK_ERROR(_readOptionPeriod_V1(c, &m->maybe_periodic))
    CHECK_ERROR(_readPriority_V1(c, &m->priority))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_proxy_V1(
    parser_context_t* c, pd_proxy_proxy_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->real))
    CHECK_ERROR(_readOptionProxyType_V1(c, &m->force_proxy_type))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_add_proxy_V1(
    parser_context_t* c, pd_proxy_add_proxy_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->delegate))
    CHECK_ERROR(_readProxyType_V1(c, &m->proxy_type))
    CHECK_ERROR(_readBlockNumber(c, &m->delay))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_remove_proxy_V1(
    parser_context_t* c, pd_proxy_remove_proxy_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->delegate))
    CHECK_ERROR(_readProxyType_V1(c, &m->proxy_type))
    CHECK_ERROR(_readBlockNumber(c, &m->delay))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_remove_proxies_V1(
    parser_context_t* c, pd_proxy_remove_proxies_V1_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_anonymous_V1(
    parser_context_t* c, pd_proxy_anonymous_V1_t* m)
{
    CHECK_ERROR(_readProxyType_V1(c, &m->proxy_type))
    CHECK_ERROR(_readBlockNumber(c, &m->delay))
    CHECK_ERROR(_readu16(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_kill_anonymous_V1(
    parser_context_t* c, pd_proxy_kill_anonymous_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->spawner))
    CHECK_ERROR(_readProxyType_V1(c, &m->proxy_type))
    CHECK_ERROR(_readu16(c, &m->index))
    CHECK_ERROR(_readCompactBlockNumber(c, &m->height))
    CHECK_ERROR(_readCompactu32(c, &m->ext_index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_announce_V1(
    parser_context_t* c, pd_proxy_announce_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->real))
    CHECK_ERROR(_readCallHashOf_V1(c, &m->call_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_remove_announcement_V1(
    parser_context_t* c, pd_proxy_remove_announcement_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->real))
    CHECK_ERROR(_readCallHashOf_V1(c, &m->call_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_reject_announcement_V1(
    parser_context_t* c, pd_proxy_reject_announcement_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->delegate))
    CHECK_ERROR(_readCallHashOf_V1(c, &m->call_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_proxy_announced_V1(
    parser_context_t* c, pd_proxy_proxy_announced_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->delegate))
    CHECK_ERROR(_readAccountId_V1(c, &m->real))
    CHECK_ERROR(_readOptionProxyType_V1(c, &m->force_proxy_type))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_as_multi_threshold_1_V1(
    parser_context_t* c, pd_multisig_as_multi_threshold_1_V1_t* m)
{
    CHECK_ERROR(_readVecAccountId_V1(c, &m->other_signatories))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_as_multi_V1(
    parser_context_t* c, pd_multisig_as_multi_V1_t* m)
{
    CHECK_ERROR(_readu16(c, &m->threshold))
    CHECK_ERROR(_readVecAccountId_V1(c, &m->other_signatories))
    CHECK_ERROR(_readOptionTimepoint_V1(c, &m->maybe_timepoint))
    CHECK_ERROR(_readOpaqueCall_V1(c, &m->call))
    CHECK_ERROR(_readbool(c, &m->store_call))
    CHECK_ERROR(_readWeight_V1(c, &m->max_weight))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_approve_as_multi_V1(
    parser_context_t* c, pd_multisig_approve_as_multi_V1_t* m)
{
    CHECK_ERROR(_readu16(c, &m->threshold))
    CHECK_ERROR(_readVecAccountId_V1(c, &m->other_signatories))
    CHECK_ERROR(_readOptionTimepoint_V1(c, &m->maybe_timepoint))
    CHECK_ERROR(_readu8_array_32_V1(c, &m->call_hash))
    CHECK_ERROR(_readWeight_V1(c, &m->max_weight))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_cancel_as_multi_V1(
    parser_context_t* c, pd_multisig_cancel_as_multi_V1_t* m)
{
    CHECK_ERROR(_readu16(c, &m->threshold))
    CHECK_ERROR(_readVecAccountId_V1(c, &m->other_signatories))
    CHECK_ERROR(_readTimepoint_V1(c, &m->timepoint))
    CHECK_ERROR(_readu8_array_32_V1(c, &m->call_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_create_V1(
    parser_context_t* c, pd_assets_create_V1_t* m)
{
    CHECK_ERROR(_readCompactAssetId_V1(c, &m->id))
    CHECK_ERROR(_readLookupSource_V1(c, &m->admin))
    CHECK_ERROR(_readu32(c, &m->max_zombies))
    CHECK_ERROR(_readTAssetBalance_V1(c, &m->min_balance))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_force_create_V1(
    parser_context_t* c, pd_assets_force_create_V1_t* m)
{
    CHECK_ERROR(_readCompactAssetId_V1(c, &m->id))
    CHECK_ERROR(_readLookupSource_V1(c, &m->owner))
    CHECK_ERROR(_readCompactu32(c, &m->max_zombies))
    CHECK_ERROR(_readCompactTAssetBalance_V1(c, &m->min_balance))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_destroy_V1(
    parser_context_t* c, pd_assets_destroy_V1_t* m)
{
    CHECK_ERROR(_readCompactAssetId_V1(c, &m->id))
    CHECK_ERROR(_readCompactu32(c, &m->zombies_witness))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_force_destroy_V1(
    parser_context_t* c, pd_assets_force_destroy_V1_t* m)
{
    CHECK_ERROR(_readCompactAssetId_V1(c, &m->id))
    CHECK_ERROR(_readCompactu32(c, &m->zombies_witness))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_mint_V1(
    parser_context_t* c, pd_assets_mint_V1_t* m)
{
    CHECK_ERROR(_readCompactAssetId_V1(c, &m->id))
    CHECK_ERROR(_readLookupSource_V1(c, &m->beneficiary))
    CHECK_ERROR(_readCompactTAssetBalance_V1(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_burn_V1(
    parser_context_t* c, pd_assets_burn_V1_t* m)
{
    CHECK_ERROR(_readCompactAssetId_V1(c, &m->id))
    CHECK_ERROR(_readLookupSource_V1(c, &m->who))
    CHECK_ERROR(_readCompactTAssetBalance_V1(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_transfer_V1(
    parser_context_t* c, pd_assets_transfer_V1_t* m)
{
    CHECK_ERROR(_readCompactAssetId_V1(c, &m->id))
    CHECK_ERROR(_readLookupSource_V1(c, &m->target))
    CHECK_ERROR(_readCompactTAssetBalance_V1(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_force_transfer_V1(
    parser_context_t* c, pd_assets_force_transfer_V1_t* m)
{
    CHECK_ERROR(_readCompactAssetId_V1(c, &m->id))
    CHECK_ERROR(_readLookupSource_V1(c, &m->source))
    CHECK_ERROR(_readLookupSource_V1(c, &m->dest))
    CHECK_ERROR(_readCompactTAssetBalance_V1(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_freeze_V1(
    parser_context_t* c, pd_assets_freeze_V1_t* m)
{
    CHECK_ERROR(_readCompactAssetId_V1(c, &m->id))
    CHECK_ERROR(_readLookupSource_V1(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_thaw_V1(
    parser_context_t* c, pd_assets_thaw_V1_t* m)
{
    CHECK_ERROR(_readCompactAssetId_V1(c, &m->id))
    CHECK_ERROR(_readLookupSource_V1(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_transfer_ownership_V1(
    parser_context_t* c, pd_assets_transfer_ownership_V1_t* m)
{
    CHECK_ERROR(_readCompactAssetId_V1(c, &m->id))
    CHECK_ERROR(_readLookupSource_V1(c, &m->new_owner))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_set_team_V1(
    parser_context_t* c, pd_assets_set_team_V1_t* m)
{
    CHECK_ERROR(_readCompactAssetId_V1(c, &m->id))
    CHECK_ERROR(_readLookupSource_V1(c, &m->issuer))
    CHECK_ERROR(_readLookupSource_V1(c, &m->admin))
    CHECK_ERROR(_readLookupSource_V1(c, &m->freezer))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_set_max_zombies_V1(
    parser_context_t* c, pd_assets_set_max_zombies_V1_t* m)
{
    CHECK_ERROR(_readCompactAssetId_V1(c, &m->id))
    CHECK_ERROR(_readCompactu32(c, &m->max_zombies))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_treasuryreward_set_current_payout_V1(
    parser_context_t* c, pd_treasuryreward_set_current_payout_V1_t* m)
{
    CHECK_ERROR(_readBalanceOf(c, &m->payout))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_treasuryreward_set_minting_interval_V1(
    parser_context_t* c, pd_treasuryreward_set_minting_interval_V1_t* m)
{
    CHECK_ERROR(_readBlockNumber(c, &m->interval))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_ethereum_transact_V1(
    parser_context_t* c, pd_ethereum_transact_V1_t* m)
{
    CHECK_ERROR(_readEthTransaction_V1(c, &m->transaction))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_evm_withdraw_V1(
    parser_context_t* c, pd_evm_withdraw_V1_t* m)
{
    CHECK_ERROR(_readH160_V1(c, &m->address))
    CHECK_ERROR(_readBalanceOf(c, &m->value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_evm_call_V1(
    parser_context_t* c, pd_evm_call_V1_t* m)
{
    CHECK_ERROR(_readH160_V1(c, &m->source))
    CHECK_ERROR(_readH160_V1(c, &m->target))
    CHECK_ERROR(_readBytes(c, &m->input))
    CHECK_ERROR(_readU256_V1(c, &m->value))
    CHECK_ERROR(_readu32(c, &m->gas_limit))
    CHECK_ERROR(_readU256_V1(c, &m->gas_price))
    CHECK_ERROR(_readOptionU256_V1(c, &m->nonce))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_evm_create_V1(
    parser_context_t* c, pd_evm_create_V1_t* m)
{
    CHECK_ERROR(_readH160_V1(c, &m->source))
    CHECK_ERROR(_readBytes(c, &m->init))
    CHECK_ERROR(_readU256_V1(c, &m->value))
    CHECK_ERROR(_readu32(c, &m->gas_limit))
    CHECK_ERROR(_readU256_V1(c, &m->gas_price))
    CHECK_ERROR(_readOptionU256_V1(c, &m->nonce))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_evm_create2_V1(
    parser_context_t* c, pd_evm_create2_V1_t* m)
{
    CHECK_ERROR(_readH160_V1(c, &m->source))
    CHECK_ERROR(_readBytes(c, &m->init))
    CHECK_ERROR(_readH256_V1(c, &m->salt))
    CHECK_ERROR(_readU256_V1(c, &m->value))
    CHECK_ERROR(_readu32(c, &m->gas_limit))
    CHECK_ERROR(_readU256_V1(c, &m->gas_price))
    CHECK_ERROR(_readOptionU256_V1(c, &m->nonce))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_chainbridge_set_threshold_V1(
    parser_context_t* c, pd_chainbridge_set_threshold_V1_t* m)
{
    CHECK_ERROR(_readu32(c, &m->threshold))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_chainbridge_set_resource_V1(
    parser_context_t* c, pd_chainbridge_set_resource_V1_t* m)
{
    CHECK_ERROR(_readResourceId_V1(c, &m->id))
    CHECK_ERROR(_readBytes(c, &m->method))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_chainbridge_remove_resource_V1(
    parser_context_t* c, pd_chainbridge_remove_resource_V1_t* m)
{
    CHECK_ERROR(_readResourceId_V1(c, &m->id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_chainbridge_whitelist_chain_V1(
    parser_context_t* c, pd_chainbridge_whitelist_chain_V1_t* m)
{
    CHECK_ERROR(_readChainId_V1(c, &m->id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_chainbridge_add_relayer_V1(
    parser_context_t* c, pd_chainbridge_add_relayer_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->v))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_chainbridge_remove_relayer_V1(
    parser_context_t* c, pd_chainbridge_remove_relayer_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->v))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_chainbridge_acknowledge_proposal_V1(
    parser_context_t* c, pd_chainbridge_acknowledge_proposal_V1_t* m)
{
    CHECK_ERROR(_readDepositNonce_V1(c, &m->nonce))
    CHECK_ERROR(_readChainId_V1(c, &m->src_id))
    CHECK_ERROR(_readResourceId_V1(c, &m->r_id))
    CHECK_ERROR(_readProposal(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_chainbridge_reject_proposal_V1(
    parser_context_t* c, pd_chainbridge_reject_proposal_V1_t* m)
{
    CHECK_ERROR(_readDepositNonce_V1(c, &m->nonce))
    CHECK_ERROR(_readChainId_V1(c, &m->src_id))
    CHECK_ERROR(_readResourceId_V1(c, &m->r_id))
    CHECK_ERROR(_readProposal(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_chainbridge_eval_vote_state_V1(
    parser_context_t* c, pd_chainbridge_eval_vote_state_V1_t* m)
{
    CHECK_ERROR(_readDepositNonce_V1(c, &m->nonce))
    CHECK_ERROR(_readChainId_V1(c, &m->src_id))
    CHECK_ERROR(_readProposal(c, &m->prop))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_edgebridge_transfer_native_V1(
    parser_context_t* c, pd_edgebridge_transfer_native_V1_t* m)
{
    CHECK_ERROR(_readBalanceOf(c, &m->amount))
    CHECK_ERROR(_readBytes(c, &m->recipient))
    CHECK_ERROR(_readChainId_V1(c, &m->dest_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_edgebridge_transfer_V1(
    parser_context_t* c, pd_edgebridge_transfer_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->to))
    CHECK_ERROR(_readBalanceOf(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bounties_propose_bounty_V1(
    parser_context_t* c, pd_bounties_propose_bounty_V1_t* m)
{
    CHECK_ERROR(_readCompactBalanceOf(c, &m->value))
    CHECK_ERROR(_readBytes(c, &m->description))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bounties_approve_bounty_V1(
    parser_context_t* c, pd_bounties_approve_bounty_V1_t* m)
{
    CHECK_ERROR(_readCompactBountyIndex_V1(c, &m->bounty_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bounties_propose_curator_V1(
    parser_context_t* c, pd_bounties_propose_curator_V1_t* m)
{
    CHECK_ERROR(_readCompactBountyIndex_V1(c, &m->bounty_id))
    CHECK_ERROR(_readLookupSource_V1(c, &m->curator))
    CHECK_ERROR(_readCompactBalanceOf(c, &m->fee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bounties_unassign_curator_V1(
    parser_context_t* c, pd_bounties_unassign_curator_V1_t* m)
{
    CHECK_ERROR(_readCompactBountyIndex_V1(c, &m->bounty_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bounties_accept_curator_V1(
    parser_context_t* c, pd_bounties_accept_curator_V1_t* m)
{
    CHECK_ERROR(_readCompactBountyIndex_V1(c, &m->bounty_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bounties_award_bounty_V1(
    parser_context_t* c, pd_bounties_award_bounty_V1_t* m)
{
    CHECK_ERROR(_readCompactBountyIndex_V1(c, &m->bounty_id))
    CHECK_ERROR(_readLookupSource_V1(c, &m->beneficiary))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bounties_claim_bounty_V1(
    parser_context_t* c, pd_bounties_claim_bounty_V1_t* m)
{
    CHECK_ERROR(_readCompactBountyIndex_V1(c, &m->bounty_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bounties_close_bounty_V1(
    parser_context_t* c, pd_bounties_close_bounty_V1_t* m)
{
    CHECK_ERROR(_readCompactBountyIndex_V1(c, &m->bounty_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bounties_extend_bounty_expiry_V1(
    parser_context_t* c, pd_bounties_extend_bounty_expiry_V1_t* m)
{
    CHECK_ERROR(_readCompactBountyIndex_V1(c, &m->bounty_id))
    CHECK_ERROR(_readBytes(c, &m->_remark))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_tips_report_awesome_V1(
    parser_context_t* c, pd_tips_report_awesome_V1_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->reason))
    CHECK_ERROR(_readAccountId_V1(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_tips_retract_tip_V1(
    parser_context_t* c, pd_tips_retract_tip_V1_t* m)
{
    CHECK_ERROR(_readHash(c, &m->hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_tips_tip_new_V1(
    parser_context_t* c, pd_tips_tip_new_V1_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->reason))
    CHECK_ERROR(_readAccountId_V1(c, &m->who))
    CHECK_ERROR(_readCompactBalanceOf(c, &m->tip_value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_tips_tip_V1(
    parser_context_t* c, pd_tips_tip_V1_t* m)
{
    CHECK_ERROR(_readHash(c, &m->hash))
    CHECK_ERROR(_readCompactBalanceOf(c, &m->tip_value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_tips_close_tip_V1(
    parser_context_t* c, pd_tips_close_tip_V1_t* m)
{
    CHECK_ERROR(_readHash(c, &m->hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_tips_slash_tip_V1(
    parser_context_t* c, pd_tips_slash_tip_V1_t* m)
{
    CHECK_ERROR(_readHash(c, &m->hash))
    return parser_ok;
}

#endif

parser_error_t _readMethod_V1(
    parser_context_t* c,
    uint8_t moduleIdx,
    uint8_t callIdx,
    pd_Method_V1_t* method)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {

    case 256: /* module 1 call 0 */
        CHECK_ERROR(_readMethod_utility_batch_V1(c, &method->basic.utility_batch_V1))
        break;
    case 258: /* module 1 call 2 */
        CHECK_ERROR(_readMethod_utility_batch_all_V1(c, &method->basic.utility_batch_all_V1))
        break;
    case 1536: /* module 6 call 0 */
        CHECK_ERROR(_readMethod_balances_transfer_V1(c, &method->basic.balances_transfer_V1))
        break;
    case 1539: /* module 6 call 3 */
        CHECK_ERROR(_readMethod_balances_transfer_keep_alive_V1(c, &method->basic.balances_transfer_keep_alive_V1))
        break;
    case 2048: /* module 8 call 0 */
        CHECK_ERROR(_readMethod_staking_bond_V1(c, &method->basic.staking_bond_V1))
        break;
    case 2049: /* module 8 call 1 */
        CHECK_ERROR(_readMethod_staking_bond_extra_V1(c, &method->basic.staking_bond_extra_V1))
        break;
    case 2050: /* module 8 call 2 */
        CHECK_ERROR(_readMethod_staking_unbond_V1(c, &method->basic.staking_unbond_V1))
        break;
    case 2051: /* module 8 call 3 */
        CHECK_ERROR(_readMethod_staking_withdraw_unbonded_V1(c, &method->basic.staking_withdraw_unbonded_V1))
        break;
    case 2052: /* module 8 call 4 */
        CHECK_ERROR(_readMethod_staking_validate_V1(c, &method->basic.staking_validate_V1))
        break;
    case 2053: /* module 8 call 5 */
        CHECK_ERROR(_readMethod_staking_nominate_V1(c, &method->basic.staking_nominate_V1))
        break;
    case 2054: /* module 8 call 6 */
        CHECK_ERROR(_readMethod_staking_chill_V1(c, &method->basic.staking_chill_V1))
        break;
    case 2055: /* module 8 call 7 */
        CHECK_ERROR(_readMethod_staking_set_payee_V1(c, &method->basic.staking_set_payee_V1))
        break;
    case 2066: /* module 8 call 18 */
        CHECK_ERROR(_readMethod_staking_payout_stakers_V1(c, &method->basic.staking_payout_stakers_V1))
        break;
    case 2067: /* module 8 call 19 */
        CHECK_ERROR(_readMethod_staking_rebond_V1(c, &method->basic.staking_rebond_V1))
        break;
    case 2304: /* module 9 call 0 */
        CHECK_ERROR(_readMethod_session_set_keys_V1(c, &method->basic.session_set_keys_V1))
        break;
    case 2305: /* module 9 call 1 */
        CHECK_ERROR(_readMethod_session_purge_keys_V1(c, &method->basic.session_purge_keys_V1))
        break;

#ifdef SUBSTRATE_PARSER_FULL
    case 0: /* module 0 call 0 */
        CHECK_ERROR(_readMethod_system_fill_block_V1(c, &method->basic.system_fill_block_V1))
        break;
    case 1: /* module 0 call 1 */
        CHECK_ERROR(_readMethod_system_remark_V1(c, &method->basic.system_remark_V1))
        break;
    case 2: /* module 0 call 2 */
        CHECK_ERROR(_readMethod_system_set_heap_pages_V1(c, &method->basic.system_set_heap_pages_V1))
        break;
    case 3: /* module 0 call 3 */
        CHECK_ERROR(_readMethod_system_set_code_V1(c, &method->basic.system_set_code_V1))
        break;
    case 4: /* module 0 call 4 */
        CHECK_ERROR(_readMethod_system_set_code_without_checks_V1(c, &method->basic.system_set_code_without_checks_V1))
        break;
    case 5: /* module 0 call 5 */
        CHECK_ERROR(_readMethod_system_set_changes_trie_config_V1(c, &method->basic.system_set_changes_trie_config_V1))
        break;
    case 6: /* module 0 call 6 */
        CHECK_ERROR(_readMethod_system_set_storage_V1(c, &method->basic.system_set_storage_V1))
        break;
    case 7: /* module 0 call 7 */
        CHECK_ERROR(_readMethod_system_kill_storage_V1(c, &method->basic.system_kill_storage_V1))
        break;
    case 8: /* module 0 call 8 */
        CHECK_ERROR(_readMethod_system_kill_prefix_V1(c, &method->basic.system_kill_prefix_V1))
        break;
    case 9: /* module 0 call 9 */
        CHECK_ERROR(_readMethod_system_suicide_V1(c, &method->basic.system_suicide_V1))
        break;
    case 257: /* module 1 call 1 */
        CHECK_ERROR(_readMethod_utility_as_derivative_V1(c, &method->basic.utility_as_derivative_V1))
        break;
    case 768: /* module 3 call 0 */
        CHECK_ERROR(_readMethod_timestamp_set_V1(c, &method->basic.timestamp_set_V1))
        break;
    case 1024: /* module 4 call 0 */
        CHECK_ERROR(_readMethod_authorship_set_uncles_V1(c, &method->basic.authorship_set_uncles_V1))
        break;
    case 1280: /* module 5 call 0 */
        CHECK_ERROR(_readMethod_indices_claim_V1(c, &method->basic.indices_claim_V1))
        break;
    case 1281: /* module 5 call 1 */
        CHECK_ERROR(_readMethod_indices_transfer_V1(c, &method->basic.indices_transfer_V1))
        break;
    case 1282: /* module 5 call 2 */
        CHECK_ERROR(_readMethod_indices_free_V1(c, &method->basic.indices_free_V1))
        break;
    case 1283: /* module 5 call 3 */
        CHECK_ERROR(_readMethod_indices_force_transfer_V1(c, &method->basic.indices_force_transfer_V1))
        break;
    case 1284: /* module 5 call 4 */
        CHECK_ERROR(_readMethod_indices_freeze_V1(c, &method->basic.indices_freeze_V1))
        break;
    case 1537: /* module 6 call 1 */
        CHECK_ERROR(_readMethod_balances_set_balance_V1(c, &method->basic.balances_set_balance_V1))
        break;
    case 1538: /* module 6 call 2 */
        CHECK_ERROR(_readMethod_balances_force_transfer_V1(c, &method->basic.balances_force_transfer_V1))
        break;
    case 2056: /* module 8 call 8 */
        CHECK_ERROR(_readMethod_staking_set_controller_V1(c, &method->basic.staking_set_controller_V1))
        break;
    case 2057: /* module 8 call 9 */
        CHECK_ERROR(_readMethod_staking_set_validator_count_V1(c, &method->basic.staking_set_validator_count_V1))
        break;
    case 2058: /* module 8 call 10 */
        CHECK_ERROR(_readMethod_staking_increase_validator_count_V1(c, &method->basic.staking_increase_validator_count_V1))
        break;
    case 2059: /* module 8 call 11 */
        CHECK_ERROR(_readMethod_staking_scale_validator_count_V1(c, &method->basic.staking_scale_validator_count_V1))
        break;
    case 2060: /* module 8 call 12 */
        CHECK_ERROR(_readMethod_staking_force_no_eras_V1(c, &method->basic.staking_force_no_eras_V1))
        break;
    case 2061: /* module 8 call 13 */
        CHECK_ERROR(_readMethod_staking_force_new_era_V1(c, &method->basic.staking_force_new_era_V1))
        break;
    case 2062: /* module 8 call 14 */
        CHECK_ERROR(_readMethod_staking_set_invulnerables_V1(c, &method->basic.staking_set_invulnerables_V1))
        break;
    case 2063: /* module 8 call 15 */
        CHECK_ERROR(_readMethod_staking_force_unstake_V1(c, &method->basic.staking_force_unstake_V1))
        break;
    case 2064: /* module 8 call 16 */
        CHECK_ERROR(_readMethod_staking_force_new_era_always_V1(c, &method->basic.staking_force_new_era_always_V1))
        break;
    case 2065: /* module 8 call 17 */
        CHECK_ERROR(_readMethod_staking_cancel_deferred_slash_V1(c, &method->basic.staking_cancel_deferred_slash_V1))
        break;
    case 2068: /* module 8 call 20 */
        CHECK_ERROR(_readMethod_staking_set_history_depth_V1(c, &method->basic.staking_set_history_depth_V1))
        break;
    case 2069: /* module 8 call 21 */
        CHECK_ERROR(_readMethod_staking_reap_stash_V1(c, &method->basic.staking_reap_stash_V1))
        break;
    case 2070: /* module 8 call 22 */
        CHECK_ERROR(_readMethod_staking_submit_election_solution_V1(c, &method->basic.staking_submit_election_solution_V1))
        break;
    case 2071: /* module 8 call 23 */
        CHECK_ERROR(_readMethod_staking_submit_election_solution_unsigned_V1(c, &method->basic.staking_submit_election_solution_unsigned_V1))
        break;
    case 2560: /* module 10 call 0 */
        CHECK_ERROR(_readMethod_democracy_propose_V1(c, &method->basic.democracy_propose_V1))
        break;
    case 2561: /* module 10 call 1 */
        CHECK_ERROR(_readMethod_democracy_second_V1(c, &method->basic.democracy_second_V1))
        break;
    case 2562: /* module 10 call 2 */
        CHECK_ERROR(_readMethod_democracy_vote_V1(c, &method->basic.democracy_vote_V1))
        break;
    case 2563: /* module 10 call 3 */
        CHECK_ERROR(_readMethod_democracy_emergency_cancel_V1(c, &method->basic.democracy_emergency_cancel_V1))
        break;
    case 2564: /* module 10 call 4 */
        CHECK_ERROR(_readMethod_democracy_external_propose_V1(c, &method->basic.democracy_external_propose_V1))
        break;
    case 2565: /* module 10 call 5 */
        CHECK_ERROR(_readMethod_democracy_external_propose_majority_V1(c, &method->basic.democracy_external_propose_majority_V1))
        break;
    case 2566: /* module 10 call 6 */
        CHECK_ERROR(_readMethod_democracy_external_propose_default_V1(c, &method->basic.democracy_external_propose_default_V1))
        break;
    case 2567: /* module 10 call 7 */
        CHECK_ERROR(_readMethod_democracy_fast_track_V1(c, &method->basic.democracy_fast_track_V1))
        break;
    case 2568: /* module 10 call 8 */
        CHECK_ERROR(_readMethod_democracy_veto_external_V1(c, &method->basic.democracy_veto_external_V1))
        break;
    case 2569: /* module 10 call 9 */
        CHECK_ERROR(_readMethod_democracy_cancel_referendum_V1(c, &method->basic.democracy_cancel_referendum_V1))
        break;
    case 2570: /* module 10 call 10 */
        CHECK_ERROR(_readMethod_democracy_cancel_queued_V1(c, &method->basic.democracy_cancel_queued_V1))
        break;
    case 2571: /* module 10 call 11 */
        CHECK_ERROR(_readMethod_democracy_delegate_V1(c, &method->basic.democracy_delegate_V1))
        break;
    case 2572: /* module 10 call 12 */
        CHECK_ERROR(_readMethod_democracy_undelegate_V1(c, &method->basic.democracy_undelegate_V1))
        break;
    case 2573: /* module 10 call 13 */
        CHECK_ERROR(_readMethod_democracy_clear_public_proposals_V1(c, &method->basic.democracy_clear_public_proposals_V1))
        break;
    case 2574: /* module 10 call 14 */
        CHECK_ERROR(_readMethod_democracy_note_preimage_V1(c, &method->basic.democracy_note_preimage_V1))
        break;
    case 2575: /* module 10 call 15 */
        CHECK_ERROR(_readMethod_democracy_note_preimage_operational_V1(c, &method->basic.democracy_note_preimage_operational_V1))
        break;
    case 2576: /* module 10 call 16 */
        CHECK_ERROR(_readMethod_democracy_note_imminent_preimage_V1(c, &method->basic.democracy_note_imminent_preimage_V1))
        break;
    case 2577: /* module 10 call 17 */
        CHECK_ERROR(_readMethod_democracy_note_imminent_preimage_operational_V1(c, &method->basic.democracy_note_imminent_preimage_operational_V1))
        break;
    case 2578: /* module 10 call 18 */
        CHECK_ERROR(_readMethod_democracy_reap_preimage_V1(c, &method->basic.democracy_reap_preimage_V1))
        break;
    case 2579: /* module 10 call 19 */
        CHECK_ERROR(_readMethod_democracy_unlock_V1(c, &method->basic.democracy_unlock_V1))
        break;
    case 2580: /* module 10 call 20 */
        CHECK_ERROR(_readMethod_democracy_remove_vote_V1(c, &method->basic.democracy_remove_vote_V1))
        break;
    case 2581: /* module 10 call 21 */
        CHECK_ERROR(_readMethod_democracy_remove_other_vote_V1(c, &method->basic.democracy_remove_other_vote_V1))
        break;
    case 2582: /* module 10 call 22 */
        CHECK_ERROR(_readMethod_democracy_enact_proposal_V1(c, &method->basic.democracy_enact_proposal_V1))
        break;
    case 2583: /* module 10 call 23 */
        CHECK_ERROR(_readMethod_democracy_blacklist_V1(c, &method->basic.democracy_blacklist_V1))
        break;
    case 2584: /* module 10 call 24 */
        CHECK_ERROR(_readMethod_democracy_cancel_proposal_V1(c, &method->basic.democracy_cancel_proposal_V1))
        break;
    case 2816: /* module 11 call 0 */
        CHECK_ERROR(_readMethod_council_set_members_V1(c, &method->basic.council_set_members_V1))
        break;
    case 2817: /* module 11 call 1 */
        CHECK_ERROR(_readMethod_council_execute_V1(c, &method->basic.council_execute_V1))
        break;
    case 2818: /* module 11 call 2 */
        CHECK_ERROR(_readMethod_council_propose_V1(c, &method->basic.council_propose_V1))
        break;
    case 2819: /* module 11 call 3 */
        CHECK_ERROR(_readMethod_council_vote_V1(c, &method->basic.council_vote_V1))
        break;
    case 2820: /* module 11 call 4 */
        CHECK_ERROR(_readMethod_council_close_V1(c, &method->basic.council_close_V1))
        break;
    case 2821: /* module 11 call 5 */
        CHECK_ERROR(_readMethod_council_disapprove_proposal_V1(c, &method->basic.council_disapprove_proposal_V1))
        break;
    case 3072: /* module 12 call 0 */
        CHECK_ERROR(_readMethod_elections_vote_V1(c, &method->basic.elections_vote_V1))
        break;
    case 3073: /* module 12 call 1 */
        CHECK_ERROR(_readMethod_elections_remove_voter_V1(c, &method->basic.elections_remove_voter_V1))
        break;
    case 3074: /* module 12 call 2 */
        CHECK_ERROR(_readMethod_elections_report_defunct_voter_V1(c, &method->basic.elections_report_defunct_voter_V1))
        break;
    case 3075: /* module 12 call 3 */
        CHECK_ERROR(_readMethod_elections_submit_candidacy_V1(c, &method->basic.elections_submit_candidacy_V1))
        break;
    case 3076: /* module 12 call 4 */
        CHECK_ERROR(_readMethod_elections_renounce_candidacy_V1(c, &method->basic.elections_renounce_candidacy_V1))
        break;
    case 3077: /* module 12 call 5 */
        CHECK_ERROR(_readMethod_elections_remove_member_V1(c, &method->basic.elections_remove_member_V1))
        break;
    case 3584: /* module 14 call 0 */
        CHECK_ERROR(_readMethod_grandpa_report_equivocation_V1(c, &method->basic.grandpa_report_equivocation_V1))
        break;
    case 3585: /* module 14 call 1 */
        CHECK_ERROR(_readMethod_grandpa_report_equivocation_unsigned_V1(c, &method->basic.grandpa_report_equivocation_unsigned_V1))
        break;
    case 3586: /* module 14 call 2 */
        CHECK_ERROR(_readMethod_grandpa_note_stalled_V1(c, &method->basic.grandpa_note_stalled_V1))
        break;
    case 3840: /* module 15 call 0 */
        CHECK_ERROR(_readMethod_treasury_propose_spend_V1(c, &method->basic.treasury_propose_spend_V1))
        break;
    case 3841: /* module 15 call 1 */
        CHECK_ERROR(_readMethod_treasury_reject_proposal_V1(c, &method->basic.treasury_reject_proposal_V1))
        break;
    case 3842: /* module 15 call 2 */
        CHECK_ERROR(_readMethod_treasury_approve_proposal_V1(c, &method->basic.treasury_approve_proposal_V1))
        break;
    case 4096: /* module 16 call 0 */
        CHECK_ERROR(_readMethod_contracts_update_schedule_V1(c, &method->basic.contracts_update_schedule_V1))
        break;
    case 4097: /* module 16 call 1 */
        CHECK_ERROR(_readMethod_contracts_put_code_V1(c, &method->basic.contracts_put_code_V1))
        break;
    case 4098: /* module 16 call 2 */
        CHECK_ERROR(_readMethod_contracts_call_V1(c, &method->basic.contracts_call_V1))
        break;
    case 4099: /* module 16 call 3 */
        CHECK_ERROR(_readMethod_contracts_instantiate_V1(c, &method->basic.contracts_instantiate_V1))
        break;
    case 4100: /* module 16 call 4 */
        CHECK_ERROR(_readMethod_contracts_claim_surcharge_V1(c, &method->basic.contracts_claim_surcharge_V1))
        break;
    case 4352: /* module 17 call 0 */
        CHECK_ERROR(_readMethod_sudo_sudo_V1(c, &method->basic.sudo_sudo_V1))
        break;
    case 4353: /* module 17 call 1 */
        CHECK_ERROR(_readMethod_sudo_sudo_unchecked_weight_V1(c, &method->basic.sudo_sudo_unchecked_weight_V1))
        break;
    case 4354: /* module 17 call 2 */
        CHECK_ERROR(_readMethod_sudo_set_key_V1(c, &method->basic.sudo_set_key_V1))
        break;
    case 4355: /* module 17 call 3 */
        CHECK_ERROR(_readMethod_sudo_sudo_as_V1(c, &method->basic.sudo_sudo_as_V1))
        break;
    case 4608: /* module 18 call 0 */
        CHECK_ERROR(_readMethod_imonline_heartbeat_V1(c, &method->basic.imonline_heartbeat_V1))
        break;
    case 5888: /* module 23 call 0 */
        CHECK_ERROR(_readMethod_identity_add_registrar_V1(c, &method->basic.identity_add_registrar_V1))
        break;
    case 5889: /* module 23 call 1 */
        CHECK_ERROR(_readMethod_identity_set_identity_V1(c, &method->basic.identity_set_identity_V1))
        break;
    case 5890: /* module 23 call 2 */
        CHECK_ERROR(_readMethod_identity_set_subs_V1(c, &method->basic.identity_set_subs_V1))
        break;
    case 5891: /* module 23 call 3 */
        CHECK_ERROR(_readMethod_identity_clear_identity_V1(c, &method->basic.identity_clear_identity_V1))
        break;
    case 5892: /* module 23 call 4 */
        CHECK_ERROR(_readMethod_identity_request_judgement_V1(c, &method->basic.identity_request_judgement_V1))
        break;
    case 5893: /* module 23 call 5 */
        CHECK_ERROR(_readMethod_identity_cancel_request_V1(c, &method->basic.identity_cancel_request_V1))
        break;
    case 5894: /* module 23 call 6 */
        CHECK_ERROR(_readMethod_identity_set_fee_V1(c, &method->basic.identity_set_fee_V1))
        break;
    case 5895: /* module 23 call 7 */
        CHECK_ERROR(_readMethod_identity_set_account_id_V1(c, &method->basic.identity_set_account_id_V1))
        break;
    case 5896: /* module 23 call 8 */
        CHECK_ERROR(_readMethod_identity_set_fields_V1(c, &method->basic.identity_set_fields_V1))
        break;
    case 5897: /* module 23 call 9 */
        CHECK_ERROR(_readMethod_identity_provide_judgement_V1(c, &method->basic.identity_provide_judgement_V1))
        break;
    case 5898: /* module 23 call 10 */
        CHECK_ERROR(_readMethod_identity_kill_identity_V1(c, &method->basic.identity_kill_identity_V1))
        break;
    case 5899: /* module 23 call 11 */
        CHECK_ERROR(_readMethod_identity_add_sub_V1(c, &method->basic.identity_add_sub_V1))
        break;
    case 5900: /* module 23 call 12 */
        CHECK_ERROR(_readMethod_identity_rename_sub_V1(c, &method->basic.identity_rename_sub_V1))
        break;
    case 5901: /* module 23 call 13 */
        CHECK_ERROR(_readMethod_identity_remove_sub_V1(c, &method->basic.identity_remove_sub_V1))
        break;
    case 5902: /* module 23 call 14 */
        CHECK_ERROR(_readMethod_identity_quit_sub_V1(c, &method->basic.identity_quit_sub_V1))
        break;
    case 6144: /* module 24 call 0 */
        CHECK_ERROR(_readMethod_recovery_as_recovered_V1(c, &method->basic.recovery_as_recovered_V1))
        break;
    case 6145: /* module 24 call 1 */
        CHECK_ERROR(_readMethod_recovery_set_recovered_V1(c, &method->basic.recovery_set_recovered_V1))
        break;
    case 6146: /* module 24 call 2 */
        CHECK_ERROR(_readMethod_recovery_create_recovery_V1(c, &method->basic.recovery_create_recovery_V1))
        break;
    case 6147: /* module 24 call 3 */
        CHECK_ERROR(_readMethod_recovery_initiate_recovery_V1(c, &method->basic.recovery_initiate_recovery_V1))
        break;
    case 6148: /* module 24 call 4 */
        CHECK_ERROR(_readMethod_recovery_vouch_recovery_V1(c, &method->basic.recovery_vouch_recovery_V1))
        break;
    case 6149: /* module 24 call 5 */
        CHECK_ERROR(_readMethod_recovery_claim_recovery_V1(c, &method->basic.recovery_claim_recovery_V1))
        break;
    case 6150: /* module 24 call 6 */
        CHECK_ERROR(_readMethod_recovery_close_recovery_V1(c, &method->basic.recovery_close_recovery_V1))
        break;
    case 6151: /* module 24 call 7 */
        CHECK_ERROR(_readMethod_recovery_remove_recovery_V1(c, &method->basic.recovery_remove_recovery_V1))
        break;
    case 6152: /* module 24 call 8 */
        CHECK_ERROR(_readMethod_recovery_cancel_recovered_V1(c, &method->basic.recovery_cancel_recovered_V1))
        break;
    case 6400: /* module 25 call 0 */
        CHECK_ERROR(_readMethod_vesting_vest_V1(c, &method->basic.vesting_vest_V1))
        break;
    case 6401: /* module 25 call 1 */
        CHECK_ERROR(_readMethod_vesting_vest_other_V1(c, &method->basic.vesting_vest_other_V1))
        break;
    case 6402: /* module 25 call 2 */
        CHECK_ERROR(_readMethod_vesting_vested_transfer_V1(c, &method->basic.vesting_vested_transfer_V1))
        break;
    case 6403: /* module 25 call 3 */
        CHECK_ERROR(_readMethod_vesting_force_vested_transfer_V1(c, &method->basic.vesting_force_vested_transfer_V1))
        break;
    case 6656: /* module 26 call 0 */
        CHECK_ERROR(_readMethod_scheduler_schedule_V1(c, &method->basic.scheduler_schedule_V1))
        break;
    case 6657: /* module 26 call 1 */
        CHECK_ERROR(_readMethod_scheduler_cancel_V1(c, &method->basic.scheduler_cancel_V1))
        break;
    case 6658: /* module 26 call 2 */
        CHECK_ERROR(_readMethod_scheduler_schedule_named_V1(c, &method->basic.scheduler_schedule_named_V1))
        break;
    case 6659: /* module 26 call 3 */
        CHECK_ERROR(_readMethod_scheduler_cancel_named_V1(c, &method->basic.scheduler_cancel_named_V1))
        break;
    case 6660: /* module 26 call 4 */
        CHECK_ERROR(_readMethod_scheduler_schedule_after_V1(c, &method->basic.scheduler_schedule_after_V1))
        break;
    case 6661: /* module 26 call 5 */
        CHECK_ERROR(_readMethod_scheduler_schedule_named_after_V1(c, &method->basic.scheduler_schedule_named_after_V1))
        break;
    case 6912: /* module 27 call 0 */
        CHECK_ERROR(_readMethod_proxy_proxy_V1(c, &method->basic.proxy_proxy_V1))
        break;
    case 6913: /* module 27 call 1 */
        CHECK_ERROR(_readMethod_proxy_add_proxy_V1(c, &method->basic.proxy_add_proxy_V1))
        break;
    case 6914: /* module 27 call 2 */
        CHECK_ERROR(_readMethod_proxy_remove_proxy_V1(c, &method->basic.proxy_remove_proxy_V1))
        break;
    case 6915: /* module 27 call 3 */
        CHECK_ERROR(_readMethod_proxy_remove_proxies_V1(c, &method->basic.proxy_remove_proxies_V1))
        break;
    case 6916: /* module 27 call 4 */
        CHECK_ERROR(_readMethod_proxy_anonymous_V1(c, &method->basic.proxy_anonymous_V1))
        break;
    case 6917: /* module 27 call 5 */
        CHECK_ERROR(_readMethod_proxy_kill_anonymous_V1(c, &method->basic.proxy_kill_anonymous_V1))
        break;
    case 6918: /* module 27 call 6 */
        CHECK_ERROR(_readMethod_proxy_announce_V1(c, &method->basic.proxy_announce_V1))
        break;
    case 6919: /* module 27 call 7 */
        CHECK_ERROR(_readMethod_proxy_remove_announcement_V1(c, &method->basic.proxy_remove_announcement_V1))
        break;
    case 6920: /* module 27 call 8 */
        CHECK_ERROR(_readMethod_proxy_reject_announcement_V1(c, &method->basic.proxy_reject_announcement_V1))
        break;
    case 6921: /* module 27 call 9 */
        CHECK_ERROR(_readMethod_proxy_proxy_announced_V1(c, &method->basic.proxy_proxy_announced_V1))
        break;
    case 7168: /* module 28 call 0 */
        CHECK_ERROR(_readMethod_multisig_as_multi_threshold_1_V1(c, &method->basic.multisig_as_multi_threshold_1_V1))
        break;
    case 7169: /* module 28 call 1 */
        CHECK_ERROR(_readMethod_multisig_as_multi_V1(c, &method->basic.multisig_as_multi_V1))
        break;
    case 7170: /* module 28 call 2 */
        CHECK_ERROR(_readMethod_multisig_approve_as_multi_V1(c, &method->basic.multisig_approve_as_multi_V1))
        break;
    case 7171: /* module 28 call 3 */
        CHECK_ERROR(_readMethod_multisig_cancel_as_multi_V1(c, &method->basic.multisig_cancel_as_multi_V1))
        break;
    case 7424: /* module 29 call 0 */
        CHECK_ERROR(_readMethod_assets_create_V1(c, &method->basic.assets_create_V1))
        break;
    case 7425: /* module 29 call 1 */
        CHECK_ERROR(_readMethod_assets_force_create_V1(c, &method->basic.assets_force_create_V1))
        break;
    case 7426: /* module 29 call 2 */
        CHECK_ERROR(_readMethod_assets_destroy_V1(c, &method->basic.assets_destroy_V1))
        break;
    case 7427: /* module 29 call 3 */
        CHECK_ERROR(_readMethod_assets_force_destroy_V1(c, &method->basic.assets_force_destroy_V1))
        break;
    case 7428: /* module 29 call 4 */
        CHECK_ERROR(_readMethod_assets_mint_V1(c, &method->basic.assets_mint_V1))
        break;
    case 7429: /* module 29 call 5 */
        CHECK_ERROR(_readMethod_assets_burn_V1(c, &method->basic.assets_burn_V1))
        break;
    case 7430: /* module 29 call 6 */
        CHECK_ERROR(_readMethod_assets_transfer_V1(c, &method->basic.assets_transfer_V1))
        break;
    case 7431: /* module 29 call 7 */
        CHECK_ERROR(_readMethod_assets_force_transfer_V1(c, &method->basic.assets_force_transfer_V1))
        break;
    case 7432: /* module 29 call 8 */
        CHECK_ERROR(_readMethod_assets_freeze_V1(c, &method->basic.assets_freeze_V1))
        break;
    case 7433: /* module 29 call 9 */
        CHECK_ERROR(_readMethod_assets_thaw_V1(c, &method->basic.assets_thaw_V1))
        break;
    case 7434: /* module 29 call 10 */
        CHECK_ERROR(_readMethod_assets_transfer_ownership_V1(c, &method->basic.assets_transfer_ownership_V1))
        break;
    case 7435: /* module 29 call 11 */
        CHECK_ERROR(_readMethod_assets_set_team_V1(c, &method->basic.assets_set_team_V1))
        break;
    case 7436: /* module 29 call 12 */
        CHECK_ERROR(_readMethod_assets_set_max_zombies_V1(c, &method->basic.assets_set_max_zombies_V1))
        break;
    case 8192: /* module 32 call 0 */
        CHECK_ERROR(_readMethod_treasuryreward_set_current_payout_V1(c, &method->basic.treasuryreward_set_current_payout_V1))
        break;
    case 8193: /* module 32 call 1 */
        CHECK_ERROR(_readMethod_treasuryreward_set_minting_interval_V1(c, &method->basic.treasuryreward_set_minting_interval_V1))
        break;
    case 8448: /* module 33 call 0 */
        CHECK_ERROR(_readMethod_ethereum_transact_V1(c, &method->basic.ethereum_transact_V1))
        break;
    case 8704: /* module 34 call 0 */
        CHECK_ERROR(_readMethod_evm_withdraw_V1(c, &method->basic.evm_withdraw_V1))
        break;
    case 8705: /* module 34 call 1 */
        CHECK_ERROR(_readMethod_evm_call_V1(c, &method->basic.evm_call_V1))
        break;
    case 8706: /* module 34 call 2 */
        CHECK_ERROR(_readMethod_evm_create_V1(c, &method->basic.evm_create_V1))
        break;
    case 8707: /* module 34 call 3 */
        CHECK_ERROR(_readMethod_evm_create2_V1(c, &method->basic.evm_create2_V1))
        break;
    case 8960: /* module 35 call 0 */
        CHECK_ERROR(_readMethod_chainbridge_set_threshold_V1(c, &method->basic.chainbridge_set_threshold_V1))
        break;
    case 8961: /* module 35 call 1 */
        CHECK_ERROR(_readMethod_chainbridge_set_resource_V1(c, &method->basic.chainbridge_set_resource_V1))
        break;
    case 8962: /* module 35 call 2 */
        CHECK_ERROR(_readMethod_chainbridge_remove_resource_V1(c, &method->basic.chainbridge_remove_resource_V1))
        break;
    case 8963: /* module 35 call 3 */
        CHECK_ERROR(_readMethod_chainbridge_whitelist_chain_V1(c, &method->basic.chainbridge_whitelist_chain_V1))
        break;
    case 8964: /* module 35 call 4 */
        CHECK_ERROR(_readMethod_chainbridge_add_relayer_V1(c, &method->basic.chainbridge_add_relayer_V1))
        break;
    case 8965: /* module 35 call 5 */
        CHECK_ERROR(_readMethod_chainbridge_remove_relayer_V1(c, &method->basic.chainbridge_remove_relayer_V1))
        break;
    case 8966: /* module 35 call 6 */
        CHECK_ERROR(_readMethod_chainbridge_acknowledge_proposal_V1(c, &method->basic.chainbridge_acknowledge_proposal_V1))
        break;
    case 8967: /* module 35 call 7 */
        CHECK_ERROR(_readMethod_chainbridge_reject_proposal_V1(c, &method->basic.chainbridge_reject_proposal_V1))
        break;
    case 8968: /* module 35 call 8 */
        CHECK_ERROR(_readMethod_chainbridge_eval_vote_state_V1(c, &method->basic.chainbridge_eval_vote_state_V1))
        break;
    case 9216: /* module 36 call 0 */
        CHECK_ERROR(_readMethod_edgebridge_transfer_native_V1(c, &method->basic.edgebridge_transfer_native_V1))
        break;
    case 9217: /* module 36 call 1 */
        CHECK_ERROR(_readMethod_edgebridge_transfer_V1(c, &method->basic.edgebridge_transfer_V1))
        break;
    case 9472: /* module 37 call 0 */
        CHECK_ERROR(_readMethod_bounties_propose_bounty_V1(c, &method->basic.bounties_propose_bounty_V1))
        break;
    case 9473: /* module 37 call 1 */
        CHECK_ERROR(_readMethod_bounties_approve_bounty_V1(c, &method->basic.bounties_approve_bounty_V1))
        break;
    case 9474: /* module 37 call 2 */
        CHECK_ERROR(_readMethod_bounties_propose_curator_V1(c, &method->basic.bounties_propose_curator_V1))
        break;
    case 9475: /* module 37 call 3 */
        CHECK_ERROR(_readMethod_bounties_unassign_curator_V1(c, &method->basic.bounties_unassign_curator_V1))
        break;
    case 9476: /* module 37 call 4 */
        CHECK_ERROR(_readMethod_bounties_accept_curator_V1(c, &method->basic.bounties_accept_curator_V1))
        break;
    case 9477: /* module 37 call 5 */
        CHECK_ERROR(_readMethod_bounties_award_bounty_V1(c, &method->basic.bounties_award_bounty_V1))
        break;
    case 9478: /* module 37 call 6 */
        CHECK_ERROR(_readMethod_bounties_claim_bounty_V1(c, &method->basic.bounties_claim_bounty_V1))
        break;
    case 9479: /* module 37 call 7 */
        CHECK_ERROR(_readMethod_bounties_close_bounty_V1(c, &method->basic.bounties_close_bounty_V1))
        break;
    case 9480: /* module 37 call 8 */
        CHECK_ERROR(_readMethod_bounties_extend_bounty_expiry_V1(c, &method->basic.bounties_extend_bounty_expiry_V1))
        break;
    case 9728: /* module 38 call 0 */
        CHECK_ERROR(_readMethod_tips_report_awesome_V1(c, &method->basic.tips_report_awesome_V1))
        break;
    case 9729: /* module 38 call 1 */
        CHECK_ERROR(_readMethod_tips_retract_tip_V1(c, &method->basic.tips_retract_tip_V1))
        break;
    case 9730: /* module 38 call 2 */
        CHECK_ERROR(_readMethod_tips_tip_new_V1(c, &method->basic.tips_tip_new_V1))
        break;
    case 9731: /* module 38 call 3 */
        CHECK_ERROR(_readMethod_tips_tip_V1(c, &method->basic.tips_tip_V1))
        break;
    case 9732: /* module 38 call 4 */
        CHECK_ERROR(_readMethod_tips_close_tip_V1(c, &method->basic.tips_close_tip_V1))
        break;
    case 9733: /* module 38 call 5 */
        CHECK_ERROR(_readMethod_tips_slash_tip_V1(c, &method->basic.tips_slash_tip_V1))
        break;
#endif
    default:
        return parser_not_supported;
    }

    return parser_ok;
}

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

const char* _getMethod_ModuleName_V1(uint8_t moduleIdx)
{
    switch (moduleIdx) {
    case 1:
        return STR_MO_UTILITY;
    case 6:
        return STR_MO_BALANCES;
    case 8:
        return STR_MO_STAKING;
    case 9:
        return STR_MO_SESSION;
#ifdef SUBSTRATE_PARSER_FULL
    case 0:
        return STR_MO_SYSTEM;
    case 3:
        return STR_MO_TIMESTAMP;
    case 4:
        return STR_MO_AUTHORSHIP;
    case 5:
        return STR_MO_INDICES;
    case 10:
        return STR_MO_DEMOCRACY;
    case 11:
        return STR_MO_COUNCIL;
    case 12:
        return STR_MO_ELECTIONS;
    case 14:
        return STR_MO_GRANDPA;
    case 15:
        return STR_MO_TREASURY;
    case 16:
        return STR_MO_CONTRACTS;
    case 17:
        return STR_MO_SUDO;
    case 18:
        return STR_MO_IMONLINE;
    case 19:
        return STR_MO_AUTHORITYDISCOVERY;
    case 20:
        return STR_MO_OFFENCES;
    case 22:
        return STR_MO_RANDOMNESSCOLLECTIVEFLIP;
    case 23:
        return STR_MO_IDENTITY;
    case 24:
        return STR_MO_RECOVERY;
    case 25:
        return STR_MO_VESTING;
    case 26:
        return STR_MO_SCHEDULER;
    case 27:
        return STR_MO_PROXY;
    case 28:
        return STR_MO_MULTISIG;
    case 29:
        return STR_MO_ASSETS;
    case 32:
        return STR_MO_TREASURYREWARD;
    case 33:
        return STR_MO_ETHEREUM;
    case 34:
        return STR_MO_EVM;
    case 35:
        return STR_MO_CHAINBRIDGE;
    case 36:
        return STR_MO_EDGEBRIDGE;
    case 37:
        return STR_MO_BOUNTIES;
    case 38:
        return STR_MO_TIPS;
#endif
    default:
        return NULL;
    }

    return NULL;
}

const char* _getMethod_Name_V1(uint8_t moduleIdx, uint8_t callIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 256: /* module 1 call 0 */
        return STR_ME_BATCH;
    case 258: /* module 1 call 2 */
        return STR_ME_BATCH_ALL;
    case 1536: /* module 6 call 0 */
        return STR_ME_TRANSFER;
    case 1539: /* module 6 call 3 */
        return STR_ME_TRANSFER_KEEP_ALIVE;
    case 2048: /* module 8 call 0 */
        return STR_ME_BOND;
    case 2049: /* module 8 call 1 */
        return STR_ME_BOND_EXTRA;
    case 2050: /* module 8 call 2 */
        return STR_ME_UNBOND;
    case 2051: /* module 8 call 3 */
        return STR_ME_WITHDRAW_UNBONDED;
    case 2052: /* module 8 call 4 */
        return STR_ME_VALIDATE;
    case 2053: /* module 8 call 5 */
        return STR_ME_NOMINATE;
    case 2054: /* module 8 call 6 */
        return STR_ME_CHILL;
    case 2055: /* module 8 call 7 */
        return STR_ME_SET_PAYEE;
    case 2066: /* module 8 call 18 */
        return STR_ME_PAYOUT_STAKERS;
    case 2067: /* module 8 call 19 */
        return STR_ME_REBOND;
    case 2304: /* module 9 call 0 */
        return STR_ME_SET_KEYS;
    case 2305: /* module 9 call 1 */
        return STR_ME_PURGE_KEYS;
#ifdef SUBSTRATE_PARSER_FULL
    case 0: /* module 0 call 0 */
        return STR_ME_FILL_BLOCK;
    case 1: /* module 0 call 1 */
        return STR_ME_REMARK;
    case 2: /* module 0 call 2 */
        return STR_ME_SET_HEAP_PAGES;
    case 3: /* module 0 call 3 */
        return STR_ME_SET_CODE;
    case 4: /* module 0 call 4 */
        return STR_ME_SET_CODE_WITHOUT_CHECKS;
    case 5: /* module 0 call 5 */
        return STR_ME_SET_CHANGES_TRIE_CONFIG;
    case 6: /* module 0 call 6 */
        return STR_ME_SET_STORAGE;
    case 7: /* module 0 call 7 */
        return STR_ME_KILL_STORAGE;
    case 8: /* module 0 call 8 */
        return STR_ME_KILL_PREFIX;
    case 9: /* module 0 call 9 */
        return STR_ME_SUICIDE;
    case 257: /* module 1 call 1 */
        return STR_ME_AS_DERIVATIVE;
    case 768: /* module 3 call 0 */
        return STR_ME_SET;
    case 1024: /* module 4 call 0 */
        return STR_ME_SET_UNCLES;
    case 1280: /* module 5 call 0 */
        return STR_ME_CLAIM;
    case 1281: /* module 5 call 1 */
        return STR_ME_TRANSFER;
    case 1282: /* module 5 call 2 */
        return STR_ME_FREE;
    case 1283: /* module 5 call 3 */
        return STR_ME_FORCE_TRANSFER;
    case 1284: /* module 5 call 4 */
        return STR_ME_FREEZE;
    case 1537: /* module 6 call 1 */
        return STR_ME_SET_BALANCE;
    case 1538: /* module 6 call 2 */
        return STR_ME_FORCE_TRANSFER;
    case 2056: /* module 8 call 8 */
        return STR_ME_SET_CONTROLLER;
    case 2057: /* module 8 call 9 */
        return STR_ME_SET_VALIDATOR_COUNT;
    case 2058: /* module 8 call 10 */
        return STR_ME_INCREASE_VALIDATOR_COUNT;
    case 2059: /* module 8 call 11 */
        return STR_ME_SCALE_VALIDATOR_COUNT;
    case 2060: /* module 8 call 12 */
        return STR_ME_FORCE_NO_ERAS;
    case 2061: /* module 8 call 13 */
        return STR_ME_FORCE_NEW_ERA;
    case 2062: /* module 8 call 14 */
        return STR_ME_SET_INVULNERABLES;
    case 2063: /* module 8 call 15 */
        return STR_ME_FORCE_UNSTAKE;
    case 2064: /* module 8 call 16 */
        return STR_ME_FORCE_NEW_ERA_ALWAYS;
    case 2065: /* module 8 call 17 */
        return STR_ME_CANCEL_DEFERRED_SLASH;
    case 2068: /* module 8 call 20 */
        return STR_ME_SET_HISTORY_DEPTH;
    case 2069: /* module 8 call 21 */
        return STR_ME_REAP_STASH;
    case 2070: /* module 8 call 22 */
        return STR_ME_SUBMIT_ELECTION_SOLUTION;
    case 2071: /* module 8 call 23 */
        return STR_ME_SUBMIT_ELECTION_SOLUTION_UNSIGNED;
    case 2560: /* module 10 call 0 */
        return STR_ME_PROPOSE;
    case 2561: /* module 10 call 1 */
        return STR_ME_SECOND;
    case 2562: /* module 10 call 2 */
        return STR_ME_VOTE;
    case 2563: /* module 10 call 3 */
        return STR_ME_EMERGENCY_CANCEL;
    case 2564: /* module 10 call 4 */
        return STR_ME_EXTERNAL_PROPOSE;
    case 2565: /* module 10 call 5 */
        return STR_ME_EXTERNAL_PROPOSE_MAJORITY;
    case 2566: /* module 10 call 6 */
        return STR_ME_EXTERNAL_PROPOSE_DEFAULT;
    case 2567: /* module 10 call 7 */
        return STR_ME_FAST_TRACK;
    case 2568: /* module 10 call 8 */
        return STR_ME_VETO_EXTERNAL;
    case 2569: /* module 10 call 9 */
        return STR_ME_CANCEL_REFERENDUM;
    case 2570: /* module 10 call 10 */
        return STR_ME_CANCEL_QUEUED;
    case 2571: /* module 10 call 11 */
        return STR_ME_DELEGATE;
    case 2572: /* module 10 call 12 */
        return STR_ME_UNDELEGATE;
    case 2573: /* module 10 call 13 */
        return STR_ME_CLEAR_PUBLIC_PROPOSALS;
    case 2574: /* module 10 call 14 */
        return STR_ME_NOTE_PREIMAGE;
    case 2575: /* module 10 call 15 */
        return STR_ME_NOTE_PREIMAGE_OPERATIONAL;
    case 2576: /* module 10 call 16 */
        return STR_ME_NOTE_IMMINENT_PREIMAGE;
    case 2577: /* module 10 call 17 */
        return STR_ME_NOTE_IMMINENT_PREIMAGE_OPERATIONAL;
    case 2578: /* module 10 call 18 */
        return STR_ME_REAP_PREIMAGE;
    case 2579: /* module 10 call 19 */
        return STR_ME_UNLOCK;
    case 2580: /* module 10 call 20 */
        return STR_ME_REMOVE_VOTE;
    case 2581: /* module 10 call 21 */
        return STR_ME_REMOVE_OTHER_VOTE;
    case 2582: /* module 10 call 22 */
        return STR_ME_ENACT_PROPOSAL;
    case 2583: /* module 10 call 23 */
        return STR_ME_BLACKLIST;
    case 2584: /* module 10 call 24 */
        return STR_ME_CANCEL_PROPOSAL;
    case 2816: /* module 11 call 0 */
        return STR_ME_SET_MEMBERS;
    case 2817: /* module 11 call 1 */
        return STR_ME_EXECUTE;
    case 2818: /* module 11 call 2 */
        return STR_ME_PROPOSE;
    case 2819: /* module 11 call 3 */
        return STR_ME_VOTE;
    case 2820: /* module 11 call 4 */
        return STR_ME_CLOSE;
    case 2821: /* module 11 call 5 */
        return STR_ME_DISAPPROVE_PROPOSAL;
    case 3072: /* module 12 call 0 */
        return STR_ME_VOTE;
    case 3073: /* module 12 call 1 */
        return STR_ME_REMOVE_VOTER;
    case 3074: /* module 12 call 2 */
        return STR_ME_REPORT_DEFUNCT_VOTER;
    case 3075: /* module 12 call 3 */
        return STR_ME_SUBMIT_CANDIDACY;
    case 3076: /* module 12 call 4 */
        return STR_ME_RENOUNCE_CANDIDACY;
    case 3077: /* module 12 call 5 */
        return STR_ME_REMOVE_MEMBER;
    case 3584: /* module 14 call 0 */
        return STR_ME_REPORT_EQUIVOCATION;
    case 3585: /* module 14 call 1 */
        return STR_ME_REPORT_EQUIVOCATION_UNSIGNED;
    case 3586: /* module 14 call 2 */
        return STR_ME_NOTE_STALLED;
    case 3840: /* module 15 call 0 */
        return STR_ME_PROPOSE_SPEND;
    case 3841: /* module 15 call 1 */
        return STR_ME_REJECT_PROPOSAL;
    case 3842: /* module 15 call 2 */
        return STR_ME_APPROVE_PROPOSAL;
    case 4096: /* module 16 call 0 */
        return STR_ME_UPDATE_SCHEDULE;
    case 4097: /* module 16 call 1 */
        return STR_ME_PUT_CODE;
    case 4098: /* module 16 call 2 */
        return STR_ME_CALL;
    case 4099: /* module 16 call 3 */
        return STR_ME_INSTANTIATE;
    case 4100: /* module 16 call 4 */
        return STR_ME_CLAIM_SURCHARGE;
    case 4352: /* module 17 call 0 */
        return STR_ME_SUDO;
    case 4353: /* module 17 call 1 */
        return STR_ME_SUDO_UNCHECKED_WEIGHT;
    case 4354: /* module 17 call 2 */
        return STR_ME_SET_KEY;
    case 4355: /* module 17 call 3 */
        return STR_ME_SUDO_AS;
    case 4608: /* module 18 call 0 */
        return STR_ME_HEARTBEAT;
    case 5888: /* module 23 call 0 */
        return STR_ME_ADD_REGISTRAR;
    case 5889: /* module 23 call 1 */
        return STR_ME_SET_IDENTITY;
    case 5890: /* module 23 call 2 */
        return STR_ME_SET_SUBS;
    case 5891: /* module 23 call 3 */
        return STR_ME_CLEAR_IDENTITY;
    case 5892: /* module 23 call 4 */
        return STR_ME_REQUEST_JUDGEMENT;
    case 5893: /* module 23 call 5 */
        return STR_ME_CANCEL_REQUEST;
    case 5894: /* module 23 call 6 */
        return STR_ME_SET_FEE;
    case 5895: /* module 23 call 7 */
        return STR_ME_SET_ACCOUNT_ID;
    case 5896: /* module 23 call 8 */
        return STR_ME_SET_FIELDS;
    case 5897: /* module 23 call 9 */
        return STR_ME_PROVIDE_JUDGEMENT;
    case 5898: /* module 23 call 10 */
        return STR_ME_KILL_IDENTITY;
    case 5899: /* module 23 call 11 */
        return STR_ME_ADD_SUB;
    case 5900: /* module 23 call 12 */
        return STR_ME_RENAME_SUB;
    case 5901: /* module 23 call 13 */
        return STR_ME_REMOVE_SUB;
    case 5902: /* module 23 call 14 */
        return STR_ME_QUIT_SUB;
    case 6144: /* module 24 call 0 */
        return STR_ME_AS_RECOVERED;
    case 6145: /* module 24 call 1 */
        return STR_ME_SET_RECOVERED;
    case 6146: /* module 24 call 2 */
        return STR_ME_CREATE_RECOVERY;
    case 6147: /* module 24 call 3 */
        return STR_ME_INITIATE_RECOVERY;
    case 6148: /* module 24 call 4 */
        return STR_ME_VOUCH_RECOVERY;
    case 6149: /* module 24 call 5 */
        return STR_ME_CLAIM_RECOVERY;
    case 6150: /* module 24 call 6 */
        return STR_ME_CLOSE_RECOVERY;
    case 6151: /* module 24 call 7 */
        return STR_ME_REMOVE_RECOVERY;
    case 6152: /* module 24 call 8 */
        return STR_ME_CANCEL_RECOVERED;
    case 6400: /* module 25 call 0 */
        return STR_ME_VEST;
    case 6401: /* module 25 call 1 */
        return STR_ME_VEST_OTHER;
    case 6402: /* module 25 call 2 */
        return STR_ME_VESTED_TRANSFER;
    case 6403: /* module 25 call 3 */
        return STR_ME_FORCE_VESTED_TRANSFER;
    case 6656: /* module 26 call 0 */
        return STR_ME_SCHEDULE;
    case 6657: /* module 26 call 1 */
        return STR_ME_CANCEL;
    case 6658: /* module 26 call 2 */
        return STR_ME_SCHEDULE_NAMED;
    case 6659: /* module 26 call 3 */
        return STR_ME_CANCEL_NAMED;
    case 6660: /* module 26 call 4 */
        return STR_ME_SCHEDULE_AFTER;
    case 6661: /* module 26 call 5 */
        return STR_ME_SCHEDULE_NAMED_AFTER;
    case 6912: /* module 27 call 0 */
        return STR_ME_PROXY;
    case 6913: /* module 27 call 1 */
        return STR_ME_ADD_PROXY;
    case 6914: /* module 27 call 2 */
        return STR_ME_REMOVE_PROXY;
    case 6915: /* module 27 call 3 */
        return STR_ME_REMOVE_PROXIES;
    case 6916: /* module 27 call 4 */
        return STR_ME_ANONYMOUS;
    case 6917: /* module 27 call 5 */
        return STR_ME_KILL_ANONYMOUS;
    case 6918: /* module 27 call 6 */
        return STR_ME_ANNOUNCE;
    case 6919: /* module 27 call 7 */
        return STR_ME_REMOVE_ANNOUNCEMENT;
    case 6920: /* module 27 call 8 */
        return STR_ME_REJECT_ANNOUNCEMENT;
    case 6921: /* module 27 call 9 */
        return STR_ME_PROXY_ANNOUNCED;
    case 7168: /* module 28 call 0 */
        return STR_ME_AS_MULTI_THRESHOLD_1;
    case 7169: /* module 28 call 1 */
        return STR_ME_AS_MULTI;
    case 7170: /* module 28 call 2 */
        return STR_ME_APPROVE_AS_MULTI;
    case 7171: /* module 28 call 3 */
        return STR_ME_CANCEL_AS_MULTI;
    case 7424: /* module 29 call 0 */
        return STR_ME_CREATE;
    case 7425: /* module 29 call 1 */
        return STR_ME_FORCE_CREATE;
    case 7426: /* module 29 call 2 */
        return STR_ME_DESTROY;
    case 7427: /* module 29 call 3 */
        return STR_ME_FORCE_DESTROY;
    case 7428: /* module 29 call 4 */
        return STR_ME_MINT;
    case 7429: /* module 29 call 5 */
        return STR_ME_BURN;
    case 7430: /* module 29 call 6 */
        return STR_ME_TRANSFER;
    case 7431: /* module 29 call 7 */
        return STR_ME_FORCE_TRANSFER;
    case 7432: /* module 29 call 8 */
        return STR_ME_FREEZE;
    case 7433: /* module 29 call 9 */
        return STR_ME_THAW;
    case 7434: /* module 29 call 10 */
        return STR_ME_TRANSFER_OWNERSHIP;
    case 7435: /* module 29 call 11 */
        return STR_ME_SET_TEAM;
    case 7436: /* module 29 call 12 */
        return STR_ME_SET_MAX_ZOMBIES;
    case 8192: /* module 32 call 0 */
        return STR_ME_SET_CURRENT_PAYOUT;
    case 8193: /* module 32 call 1 */
        return STR_ME_SET_MINTING_INTERVAL;
    case 8448: /* module 33 call 0 */
        return STR_ME_TRANSACT;
    case 8704: /* module 34 call 0 */
        return STR_ME_WITHDRAW;
    case 8705: /* module 34 call 1 */
        return STR_ME_CALL;
    case 8706: /* module 34 call 2 */
        return STR_ME_CREATE;
    case 8707: /* module 34 call 3 */
        return STR_ME_CREATE2;
    case 8960: /* module 35 call 0 */
        return STR_ME_SET_THRESHOLD;
    case 8961: /* module 35 call 1 */
        return STR_ME_SET_RESOURCE;
    case 8962: /* module 35 call 2 */
        return STR_ME_REMOVE_RESOURCE;
    case 8963: /* module 35 call 3 */
        return STR_ME_WHITELIST_CHAIN;
    case 8964: /* module 35 call 4 */
        return STR_ME_ADD_RELAYER;
    case 8965: /* module 35 call 5 */
        return STR_ME_REMOVE_RELAYER;
    case 8966: /* module 35 call 6 */
        return STR_ME_ACKNOWLEDGE_PROPOSAL;
    case 8967: /* module 35 call 7 */
        return STR_ME_REJECT_PROPOSAL;
    case 8968: /* module 35 call 8 */
        return STR_ME_EVAL_VOTE_STATE;
    case 9216: /* module 36 call 0 */
        return STR_ME_TRANSFER_NATIVE;
    case 9217: /* module 36 call 1 */
        return STR_ME_TRANSFER;
    case 9472: /* module 37 call 0 */
        return STR_ME_PROPOSE_BOUNTY;
    case 9473: /* module 37 call 1 */
        return STR_ME_APPROVE_BOUNTY;
    case 9474: /* module 37 call 2 */
        return STR_ME_PROPOSE_CURATOR;
    case 9475: /* module 37 call 3 */
        return STR_ME_UNASSIGN_CURATOR;
    case 9476: /* module 37 call 4 */
        return STR_ME_ACCEPT_CURATOR;
    case 9477: /* module 37 call 5 */
        return STR_ME_AWARD_BOUNTY;
    case 9478: /* module 37 call 6 */
        return STR_ME_CLAIM_BOUNTY;
    case 9479: /* module 37 call 7 */
        return STR_ME_CLOSE_BOUNTY;
    case 9480: /* module 37 call 8 */
        return STR_ME_EXTEND_BOUNTY_EXPIRY;
    case 9728: /* module 38 call 0 */
        return STR_ME_REPORT_AWESOME;
    case 9729: /* module 38 call 1 */
        return STR_ME_RETRACT_TIP;
    case 9730: /* module 38 call 2 */
        return STR_ME_TIP_NEW;
    case 9731: /* module 38 call 3 */
        return STR_ME_TIP;
    case 9732: /* module 38 call 4 */
        return STR_ME_CLOSE_TIP;
    case 9733: /* module 38 call 5 */
        return STR_ME_SLASH_TIP;
#endif
    default:
        return NULL;
    }

    return NULL;
}

uint8_t _getMethod_NumItems_V1(uint8_t moduleIdx, uint8_t callIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 256: /* module 1 call 0 */
        return 1;
    case 258: /* module 1 call 2 */
        return 1;
    case 1536: /* module 6 call 0 */
        return 2;
    case 1539: /* module 6 call 3 */
        return 2;
    case 2048: /* module 8 call 0 */
        return 3;
    case 2049: /* module 8 call 1 */
        return 1;
    case 2050: /* module 8 call 2 */
        return 1;
    case 2051: /* module 8 call 3 */
        return 1;
    case 2052: /* module 8 call 4 */
        return 1;
    case 2053: /* module 8 call 5 */
        return 1;
    case 2054: /* module 8 call 6 */
        return 0;
    case 2055: /* module 8 call 7 */
        return 1;
    case 2066: /* module 8 call 18 */
        return 2;
    case 2067: /* module 8 call 19 */
        return 1;
    case 2304: /* module 9 call 0 */
        return 2;
    case 2305: /* module 9 call 1 */
        return 0;
#ifdef SUBSTRATE_PARSER_FULL
    case 0: /* module 0 call 0 */
        return 1;
    case 1: /* module 0 call 1 */
        return 1;
    case 2: /* module 0 call 2 */
        return 1;
    case 3: /* module 0 call 3 */
        return 1;
    case 4: /* module 0 call 4 */
        return 1;
    case 5: /* module 0 call 5 */
        return 1;
    case 6: /* module 0 call 6 */
        return 1;
    case 7: /* module 0 call 7 */
        return 1;
    case 8: /* module 0 call 8 */
        return 2;
    case 9: /* module 0 call 9 */
        return 0;
    case 257: /* module 1 call 1 */
        return 2;
    case 768: /* module 3 call 0 */
        return 1;
    case 1024: /* module 4 call 0 */
        return 1;
    case 1280: /* module 5 call 0 */
        return 1;
    case 1281: /* module 5 call 1 */
        return 2;
    case 1282: /* module 5 call 2 */
        return 1;
    case 1283: /* module 5 call 3 */
        return 3;
    case 1284: /* module 5 call 4 */
        return 1;
    case 1537: /* module 6 call 1 */
        return 3;
    case 1538: /* module 6 call 2 */
        return 3;
    case 2056: /* module 8 call 8 */
        return 1;
    case 2057: /* module 8 call 9 */
        return 1;
    case 2058: /* module 8 call 10 */
        return 1;
    case 2059: /* module 8 call 11 */
        return 1;
    case 2060: /* module 8 call 12 */
        return 0;
    case 2061: /* module 8 call 13 */
        return 0;
    case 2062: /* module 8 call 14 */
        return 1;
    case 2063: /* module 8 call 15 */
        return 2;
    case 2064: /* module 8 call 16 */
        return 0;
    case 2065: /* module 8 call 17 */
        return 2;
    case 2068: /* module 8 call 20 */
        return 2;
    case 2069: /* module 8 call 21 */
        return 2;
    case 2070: /* module 8 call 22 */
        return 5;
    case 2071: /* module 8 call 23 */
        return 5;
    case 2560: /* module 10 call 0 */
        return 2;
    case 2561: /* module 10 call 1 */
        return 2;
    case 2562: /* module 10 call 2 */
        return 2;
    case 2563: /* module 10 call 3 */
        return 1;
    case 2564: /* module 10 call 4 */
        return 1;
    case 2565: /* module 10 call 5 */
        return 1;
    case 2566: /* module 10 call 6 */
        return 1;
    case 2567: /* module 10 call 7 */
        return 3;
    case 2568: /* module 10 call 8 */
        return 1;
    case 2569: /* module 10 call 9 */
        return 1;
    case 2570: /* module 10 call 10 */
        return 1;
    case 2571: /* module 10 call 11 */
        return 3;
    case 2572: /* module 10 call 12 */
        return 0;
    case 2573: /* module 10 call 13 */
        return 0;
    case 2574: /* module 10 call 14 */
        return 1;
    case 2575: /* module 10 call 15 */
        return 1;
    case 2576: /* module 10 call 16 */
        return 1;
    case 2577: /* module 10 call 17 */
        return 1;
    case 2578: /* module 10 call 18 */
        return 2;
    case 2579: /* module 10 call 19 */
        return 1;
    case 2580: /* module 10 call 20 */
        return 1;
    case 2581: /* module 10 call 21 */
        return 2;
    case 2582: /* module 10 call 22 */
        return 2;
    case 2583: /* module 10 call 23 */
        return 2;
    case 2584: /* module 10 call 24 */
        return 1;
    case 2816: /* module 11 call 0 */
        return 3;
    case 2817: /* module 11 call 1 */
        return 2;
    case 2818: /* module 11 call 2 */
        return 3;
    case 2819: /* module 11 call 3 */
        return 3;
    case 2820: /* module 11 call 4 */
        return 4;
    case 2821: /* module 11 call 5 */
        return 1;
    case 3072: /* module 12 call 0 */
        return 2;
    case 3073: /* module 12 call 1 */
        return 0;
    case 3074: /* module 12 call 2 */
        return 1;
    case 3075: /* module 12 call 3 */
        return 1;
    case 3076: /* module 12 call 4 */
        return 1;
    case 3077: /* module 12 call 5 */
        return 2;
    case 3584: /* module 14 call 0 */
        return 2;
    case 3585: /* module 14 call 1 */
        return 2;
    case 3586: /* module 14 call 2 */
        return 2;
    case 3840: /* module 15 call 0 */
        return 2;
    case 3841: /* module 15 call 1 */
        return 1;
    case 3842: /* module 15 call 2 */
        return 1;
    case 4096: /* module 16 call 0 */
        return 1;
    case 4097: /* module 16 call 1 */
        return 1;
    case 4098: /* module 16 call 2 */
        return 4;
    case 4099: /* module 16 call 3 */
        return 5;
    case 4100: /* module 16 call 4 */
        return 2;
    case 4352: /* module 17 call 0 */
        return 1;
    case 4353: /* module 17 call 1 */
        return 2;
    case 4354: /* module 17 call 2 */
        return 1;
    case 4355: /* module 17 call 3 */
        return 2;
    case 4608: /* module 18 call 0 */
        return 2;
    case 5888: /* module 23 call 0 */
        return 1;
    case 5889: /* module 23 call 1 */
        return 1;
    case 5890: /* module 23 call 2 */
        return 1;
    case 5891: /* module 23 call 3 */
        return 0;
    case 5892: /* module 23 call 4 */
        return 2;
    case 5893: /* module 23 call 5 */
        return 1;
    case 5894: /* module 23 call 6 */
        return 2;
    case 5895: /* module 23 call 7 */
        return 2;
    case 5896: /* module 23 call 8 */
        return 2;
    case 5897: /* module 23 call 9 */
        return 3;
    case 5898: /* module 23 call 10 */
        return 1;
    case 5899: /* module 23 call 11 */
        return 2;
    case 5900: /* module 23 call 12 */
        return 2;
    case 5901: /* module 23 call 13 */
        return 1;
    case 5902: /* module 23 call 14 */
        return 0;
    case 6144: /* module 24 call 0 */
        return 2;
    case 6145: /* module 24 call 1 */
        return 2;
    case 6146: /* module 24 call 2 */
        return 3;
    case 6147: /* module 24 call 3 */
        return 1;
    case 6148: /* module 24 call 4 */
        return 2;
    case 6149: /* module 24 call 5 */
        return 1;
    case 6150: /* module 24 call 6 */
        return 1;
    case 6151: /* module 24 call 7 */
        return 0;
    case 6152: /* module 24 call 8 */
        return 1;
    case 6400: /* module 25 call 0 */
        return 0;
    case 6401: /* module 25 call 1 */
        return 1;
    case 6402: /* module 25 call 2 */
        return 2;
    case 6403: /* module 25 call 3 */
        return 3;
    case 6656: /* module 26 call 0 */
        return 4;
    case 6657: /* module 26 call 1 */
        return 2;
    case 6658: /* module 26 call 2 */
        return 5;
    case 6659: /* module 26 call 3 */
        return 1;
    case 6660: /* module 26 call 4 */
        return 4;
    case 6661: /* module 26 call 5 */
        return 5;
    case 6912: /* module 27 call 0 */
        return 3;
    case 6913: /* module 27 call 1 */
        return 3;
    case 6914: /* module 27 call 2 */
        return 3;
    case 6915: /* module 27 call 3 */
        return 0;
    case 6916: /* module 27 call 4 */
        return 3;
    case 6917: /* module 27 call 5 */
        return 5;
    case 6918: /* module 27 call 6 */
        return 2;
    case 6919: /* module 27 call 7 */
        return 2;
    case 6920: /* module 27 call 8 */
        return 2;
    case 6921: /* module 27 call 9 */
        return 4;
    case 7168: /* module 28 call 0 */
        return 2;
    case 7169: /* module 28 call 1 */
        return 6;
    case 7170: /* module 28 call 2 */
        return 5;
    case 7171: /* module 28 call 3 */
        return 4;
    case 7424: /* module 29 call 0 */
        return 4;
    case 7425: /* module 29 call 1 */
        return 4;
    case 7426: /* module 29 call 2 */
        return 2;
    case 7427: /* module 29 call 3 */
        return 2;
    case 7428: /* module 29 call 4 */
        return 3;
    case 7429: /* module 29 call 5 */
        return 3;
    case 7430: /* module 29 call 6 */
        return 3;
    case 7431: /* module 29 call 7 */
        return 4;
    case 7432: /* module 29 call 8 */
        return 2;
    case 7433: /* module 29 call 9 */
        return 2;
    case 7434: /* module 29 call 10 */
        return 2;
    case 7435: /* module 29 call 11 */
        return 4;
    case 7436: /* module 29 call 12 */
        return 2;
    case 8192: /* module 32 call 0 */
        return 1;
    case 8193: /* module 32 call 1 */
        return 1;
    case 8448: /* module 33 call 0 */
        return 1;
    case 8704: /* module 34 call 0 */
        return 2;
    case 8705: /* module 34 call 1 */
        return 7;
    case 8706: /* module 34 call 2 */
        return 6;
    case 8707: /* module 34 call 3 */
        return 7;
    case 8960: /* module 35 call 0 */
        return 1;
    case 8961: /* module 35 call 1 */
        return 2;
    case 8962: /* module 35 call 2 */
        return 1;
    case 8963: /* module 35 call 3 */
        return 1;
    case 8964: /* module 35 call 4 */
        return 1;
    case 8965: /* module 35 call 5 */
        return 1;
    case 8966: /* module 35 call 6 */
        return 4;
    case 8967: /* module 35 call 7 */
        return 4;
    case 8968: /* module 35 call 8 */
        return 3;
    case 9216: /* module 36 call 0 */
        return 3;
    case 9217: /* module 36 call 1 */
        return 2;
    case 9472: /* module 37 call 0 */
        return 2;
    case 9473: /* module 37 call 1 */
        return 1;
    case 9474: /* module 37 call 2 */
        return 3;
    case 9475: /* module 37 call 3 */
        return 1;
    case 9476: /* module 37 call 4 */
        return 1;
    case 9477: /* module 37 call 5 */
        return 2;
    case 9478: /* module 37 call 6 */
        return 1;
    case 9479: /* module 37 call 7 */
        return 1;
    case 9480: /* module 37 call 8 */
        return 2;
    case 9728: /* module 38 call 0 */
        return 2;
    case 9729: /* module 38 call 1 */
        return 1;
    case 9730: /* module 38 call 2 */
        return 3;
    case 9731: /* module 38 call 3 */
        return 2;
    case 9732: /* module 38 call 4 */
        return 1;
    case 9733: /* module 38 call 5 */
        return 1;
#endif
    default:
        return 0;
    }

    return 0;
}

const char* _getMethod_ItemName_V1(uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 256: /* module 1 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_calls;
        default:
            return NULL;
        }
    case 258: /* module 1 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_calls;
        default:
            return NULL;
        }
    case 1536: /* module 6 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_value;
        default:
            return NULL;
        }
    case 1539: /* module 6 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_value;
        default:
            return NULL;
        }
    case 2048: /* module 8 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_controller;
        case 1:
            return STR_IT_value;
        case 2:
            return STR_IT_payee;
        default:
            return NULL;
        }
    case 2049: /* module 8 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_max_additional;
        default:
            return NULL;
        }
    case 2050: /* module 8 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_value;
        default:
            return NULL;
        }
    case 2051: /* module 8 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_num_slashing_spans;
        default:
            return NULL;
        }
    case 2052: /* module 8 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_prefs;
        default:
            return NULL;
        }
    case 2053: /* module 8 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_targets;
        default:
            return NULL;
        }
    case 2054: /* module 8 call 6 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 2055: /* module 8 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_payee;
        default:
            return NULL;
        }
    case 2066: /* module 8 call 18 */
        switch (itemIdx) {
        case 0:
            return STR_IT_validator_stash;
        case 1:
            return STR_IT_era;
        default:
            return NULL;
        }
    case 2067: /* module 8 call 19 */
        switch (itemIdx) {
        case 0:
            return STR_IT_value;
        default:
            return NULL;
        }
    case 2304: /* module 9 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_keys;
        case 1:
            return STR_IT_proof;
        default:
            return NULL;
        }
    case 2305: /* module 9 call 1 */
        switch (itemIdx) {
        default:
            return NULL;
        }
#ifdef SUBSTRATE_PARSER_FULL
    case 0: /* module 0 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT__ratio;
        default:
            return NULL;
        }
    case 1: /* module 0 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT__remark;
        default:
            return NULL;
        }
    case 2: /* module 0 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_pages;
        default:
            return NULL;
        }
    case 3: /* module 0 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_code;
        default:
            return NULL;
        }
    case 4: /* module 0 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_code;
        default:
            return NULL;
        }
    case 5: /* module 0 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_changes_trie_config;
        default:
            return NULL;
        }
    case 6: /* module 0 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_items;
        default:
            return NULL;
        }
    case 7: /* module 0 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_keys;
        default:
            return NULL;
        }
    case 8: /* module 0 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_prefix;
        case 1:
            return STR_IT__subkeys;
        default:
            return NULL;
        }
    case 9: /* module 0 call 9 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 257: /* module 1 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        case 1:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 768: /* module 3 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_now;
        default:
            return NULL;
        }
    case 1024: /* module 4 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_uncles;
        default:
            return NULL;
        }
    case 1280: /* module 5 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 1281: /* module 5 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        case 1:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 1282: /* module 5 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 1283: /* module 5 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        case 1:
            return STR_IT_index;
        case 2:
            return STR_IT_freeze;
        default:
            return NULL;
        }
    case 1284: /* module 5 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 1537: /* module 6 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        case 1:
            return STR_IT_new_free;
        case 2:
            return STR_IT_new_reserved;
        default:
            return NULL;
        }
    case 1538: /* module 6 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_source;
        case 1:
            return STR_IT_dest;
        case 2:
            return STR_IT_value;
        default:
            return NULL;
        }
    case 2056: /* module 8 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_controller;
        default:
            return NULL;
        }
    case 2057: /* module 8 call 9 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 2058: /* module 8 call 10 */
        switch (itemIdx) {
        case 0:
            return STR_IT_additional;
        default:
            return NULL;
        }
    case 2059: /* module 8 call 11 */
        switch (itemIdx) {
        case 0:
            return STR_IT_factor;
        default:
            return NULL;
        }
    case 2060: /* module 8 call 12 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 2061: /* module 8 call 13 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 2062: /* module 8 call 14 */
        switch (itemIdx) {
        case 0:
            return STR_IT_invulnerables;
        default:
            return NULL;
        }
    case 2063: /* module 8 call 15 */
        switch (itemIdx) {
        case 0:
            return STR_IT_stash;
        case 1:
            return STR_IT_num_slashing_spans;
        default:
            return NULL;
        }
    case 2064: /* module 8 call 16 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 2065: /* module 8 call 17 */
        switch (itemIdx) {
        case 0:
            return STR_IT_era;
        case 1:
            return STR_IT_slash_indices;
        default:
            return NULL;
        }
    case 2068: /* module 8 call 20 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_history_depth;
        case 1:
            return STR_IT__era_items_deleted;
        default:
            return NULL;
        }
    case 2069: /* module 8 call 21 */
        switch (itemIdx) {
        case 0:
            return STR_IT_stash;
        case 1:
            return STR_IT_num_slashing_spans;
        default:
            return NULL;
        }
    case 2070: /* module 8 call 22 */
        switch (itemIdx) {
        case 0:
            return STR_IT_winners;
        case 1:
            return STR_IT_compact;
        case 2:
            return STR_IT_score;
        case 3:
            return STR_IT_era;
        case 4:
            return STR_IT_size;
        default:
            return NULL;
        }
    case 2071: /* module 8 call 23 */
        switch (itemIdx) {
        case 0:
            return STR_IT_winners;
        case 1:
            return STR_IT_compact;
        case 2:
            return STR_IT_score;
        case 3:
            return STR_IT_era;
        case 4:
            return STR_IT_size;
        default:
            return NULL;
        }
    case 2560: /* module 10 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        case 1:
            return STR_IT_value;
        default:
            return NULL;
        }
    case 2561: /* module 10 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal;
        case 1:
            return STR_IT_seconds_upper_bound;
        default:
            return NULL;
        }
    case 2562: /* module 10 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ref_index;
        case 1:
            return STR_IT_vote;
        default:
            return NULL;
        }
    case 2563: /* module 10 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ref_index;
        default:
            return NULL;
        }
    case 2564: /* module 10 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        default:
            return NULL;
        }
    case 2565: /* module 10 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        default:
            return NULL;
        }
    case 2566: /* module 10 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        default:
            return NULL;
        }
    case 2567: /* module 10 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        case 1:
            return STR_IT_voting_period;
        case 2:
            return STR_IT_delay;
        default:
            return NULL;
        }
    case 2568: /* module 10 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        default:
            return NULL;
        }
    case 2569: /* module 10 call 9 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ref_index;
        default:
            return NULL;
        }
    case 2570: /* module 10 call 10 */
        switch (itemIdx) {
        case 0:
            return STR_IT_which;
        default:
            return NULL;
        }
    case 2571: /* module 10 call 11 */
        switch (itemIdx) {
        case 0:
            return STR_IT_to;
        case 1:
            return STR_IT_conviction;
        case 2:
            return STR_IT_balance;
        default:
            return NULL;
        }
    case 2572: /* module 10 call 12 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 2573: /* module 10 call 13 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 2574: /* module 10 call 14 */
        switch (itemIdx) {
        case 0:
            return STR_IT_encoded_proposal;
        default:
            return NULL;
        }
    case 2575: /* module 10 call 15 */
        switch (itemIdx) {
        case 0:
            return STR_IT_encoded_proposal;
        default:
            return NULL;
        }
    case 2576: /* module 10 call 16 */
        switch (itemIdx) {
        case 0:
            return STR_IT_encoded_proposal;
        default:
            return NULL;
        }
    case 2577: /* module 10 call 17 */
        switch (itemIdx) {
        case 0:
            return STR_IT_encoded_proposal;
        default:
            return NULL;
        }
    case 2578: /* module 10 call 18 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        case 1:
            return STR_IT_proposal_len_upper_bound;
        default:
            return NULL;
        }
    case 2579: /* module 10 call 19 */
        switch (itemIdx) {
        case 0:
            return STR_IT_target;
        default:
            return NULL;
        }
    case 2580: /* module 10 call 20 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 2581: /* module 10 call 21 */
        switch (itemIdx) {
        case 0:
            return STR_IT_target;
        case 1:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 2582: /* module 10 call 22 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        case 1:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 2583: /* module 10 call 23 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        case 1:
            return STR_IT_maybe_ref_index;
        default:
            return NULL;
        }
    case 2584: /* module 10 call 24 */
        switch (itemIdx) {
        case 0:
            return STR_IT_prop_index;
        default:
            return NULL;
        }
    case 2816: /* module 11 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_members;
        case 1:
            return STR_IT_prime;
        case 2:
            return STR_IT_old_count;
        default:
            return NULL;
        }
    case 2817: /* module 11 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal;
        case 1:
            return STR_IT_length_bound;
        default:
            return NULL;
        }
    case 2818: /* module 11 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_threshold;
        case 1:
            return STR_IT_proposal;
        case 2:
            return STR_IT_length_bound;
        default:
            return NULL;
        }
    case 2819: /* module 11 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal;
        case 1:
            return STR_IT_index;
        case 2:
            return STR_IT_approve;
        default:
            return NULL;
        }
    case 2820: /* module 11 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        case 1:
            return STR_IT_index;
        case 2:
            return STR_IT_proposal_weight_bound;
        case 3:
            return STR_IT_length_bound;
        default:
            return NULL;
        }
    case 2821: /* module 11 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        default:
            return NULL;
        }
    case 3072: /* module 12 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_votes;
        case 1:
            return STR_IT_value;
        default:
            return NULL;
        }
    case 3073: /* module 12 call 1 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 3074: /* module 12 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_defunct;
        default:
            return NULL;
        }
    case 3075: /* module 12 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_candidate_count;
        default:
            return NULL;
        }
    case 3076: /* module 12 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_renouncing;
        default:
            return NULL;
        }
    case 3077: /* module 12 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        case 1:
            return STR_IT_has_replacement;
        default:
            return NULL;
        }
    case 3584: /* module 14 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_equivocation_proof;
        case 1:
            return STR_IT_key_owner_proof;
        default:
            return NULL;
        }
    case 3585: /* module 14 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_equivocation_proof;
        case 1:
            return STR_IT_key_owner_proof;
        default:
            return NULL;
        }
    case 3586: /* module 14 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_delay;
        case 1:
            return STR_IT_best_finalized_block_number;
        default:
            return NULL;
        }
    case 3840: /* module 15 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_value;
        case 1:
            return STR_IT_beneficiary;
        default:
            return NULL;
        }
    case 3841: /* module 15 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_id;
        default:
            return NULL;
        }
    case 3842: /* module 15 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_id;
        default:
            return NULL;
        }
    case 4096: /* module 16 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_schedule;
        default:
            return NULL;
        }
    case 4097: /* module 16 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_code;
        default:
            return NULL;
        }
    case 4098: /* module 16 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_value;
        case 2:
            return STR_IT_gas_limit;
        case 3:
            return STR_IT_data;
        default:
            return NULL;
        }
    case 4099: /* module 16 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_endowment;
        case 1:
            return STR_IT_gas_limit;
        case 2:
            return STR_IT_code_hash;
        case 3:
            return STR_IT_data;
        case 4:
            return STR_IT_salt;
        default:
            return NULL;
        }
    case 4100: /* module 16 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_aux_sender;
        default:
            return NULL;
        }
    case 4352: /* module 17 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 4353: /* module 17 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_call;
        case 1:
            return STR_IT__weight;
        default:
            return NULL;
        }
    case 4354: /* module 17 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 4355: /* module 17 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        case 1:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 4608: /* module 18 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_heartbeat;
        case 1:
            return STR_IT__signature;
        default:
            return NULL;
        }
    case 5888: /* module 23 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_account;
        default:
            return NULL;
        }
    case 5889: /* module 23 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_info;
        default:
            return NULL;
        }
    case 5890: /* module 23 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_subs;
        default:
            return NULL;
        }
    case 5891: /* module 23 call 3 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 5892: /* module 23 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_reg_index;
        case 1:
            return STR_IT_max_fee;
        default:
            return NULL;
        }
    case 5893: /* module 23 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_reg_index;
        default:
            return NULL;
        }
    case 5894: /* module 23 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        case 1:
            return STR_IT_fee;
        default:
            return NULL;
        }
    case 5895: /* module 23 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        case 1:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 5896: /* module 23 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        case 1:
            return STR_IT_fields;
        default:
            return NULL;
        }
    case 5897: /* module 23 call 9 */
        switch (itemIdx) {
        case 0:
            return STR_IT_reg_index;
        case 1:
            return STR_IT_target;
        case 2:
            return STR_IT_judgement;
        default:
            return NULL;
        }
    case 5898: /* module 23 call 10 */
        switch (itemIdx) {
        case 0:
            return STR_IT_target;
        default:
            return NULL;
        }
    case 5899: /* module 23 call 11 */
        switch (itemIdx) {
        case 0:
            return STR_IT_sub;
        case 1:
            return STR_IT_data;
        default:
            return NULL;
        }
    case 5900: /* module 23 call 12 */
        switch (itemIdx) {
        case 0:
            return STR_IT_sub;
        case 1:
            return STR_IT_data;
        default:
            return NULL;
        }
    case 5901: /* module 23 call 13 */
        switch (itemIdx) {
        case 0:
            return STR_IT_sub;
        default:
            return NULL;
        }
    case 5902: /* module 23 call 14 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 6144: /* module 24 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_account;
        case 1:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 6145: /* module 24 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_lost;
        case 1:
            return STR_IT_rescuer;
        default:
            return NULL;
        }
    case 6146: /* module 24 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_friends;
        case 1:
            return STR_IT_threshold;
        case 2:
            return STR_IT_delay_period;
        default:
            return NULL;
        }
    case 6147: /* module 24 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_account;
        default:
            return NULL;
        }
    case 6148: /* module 24 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_lost;
        case 1:
            return STR_IT_rescuer;
        default:
            return NULL;
        }
    case 6149: /* module 24 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_account;
        default:
            return NULL;
        }
    case 6150: /* module 24 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_rescuer;
        default:
            return NULL;
        }
    case 6151: /* module 24 call 7 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 6152: /* module 24 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_account;
        default:
            return NULL;
        }
    case 6400: /* module 25 call 0 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 6401: /* module 25 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_target;
        default:
            return NULL;
        }
    case 6402: /* module 25 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_target;
        case 1:
            return STR_IT_schedule;
        default:
            return NULL;
        }
    case 6403: /* module 25 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_source;
        case 1:
            return STR_IT_target;
        case 2:
            return STR_IT_schedule;
        default:
            return NULL;
        }
    case 6656: /* module 26 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_when;
        case 1:
            return STR_IT_maybe_periodic;
        case 2:
            return STR_IT_priority;
        case 3:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 6657: /* module 26 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_when;
        case 1:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 6658: /* module 26 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_when;
        case 2:
            return STR_IT_maybe_periodic;
        case 3:
            return STR_IT_priority;
        case 4:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 6659: /* module 26 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        default:
            return NULL;
        }
    case 6660: /* module 26 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_after;
        case 1:
            return STR_IT_maybe_periodic;
        case 2:
            return STR_IT_priority;
        case 3:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 6661: /* module 26 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_after;
        case 2:
            return STR_IT_maybe_periodic;
        case 3:
            return STR_IT_priority;
        case 4:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 6912: /* module 27 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_real;
        case 1:
            return STR_IT_force_proxy_type;
        case 2:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 6913: /* module 27 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_delegate;
        case 1:
            return STR_IT_proxy_type;
        case 2:
            return STR_IT_delay;
        default:
            return NULL;
        }
    case 6914: /* module 27 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_delegate;
        case 1:
            return STR_IT_proxy_type;
        case 2:
            return STR_IT_delay;
        default:
            return NULL;
        }
    case 6915: /* module 27 call 3 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 6916: /* module 27 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proxy_type;
        case 1:
            return STR_IT_delay;
        case 2:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 6917: /* module 27 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_spawner;
        case 1:
            return STR_IT_proxy_type;
        case 2:
            return STR_IT_index;
        case 3:
            return STR_IT_height;
        case 4:
            return STR_IT_ext_index;
        default:
            return NULL;
        }
    case 6918: /* module 27 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_real;
        case 1:
            return STR_IT_call_hash;
        default:
            return NULL;
        }
    case 6919: /* module 27 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_real;
        case 1:
            return STR_IT_call_hash;
        default:
            return NULL;
        }
    case 6920: /* module 27 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_delegate;
        case 1:
            return STR_IT_call_hash;
        default:
            return NULL;
        }
    case 6921: /* module 27 call 9 */
        switch (itemIdx) {
        case 0:
            return STR_IT_delegate;
        case 1:
            return STR_IT_real;
        case 2:
            return STR_IT_force_proxy_type;
        case 3:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 7168: /* module 28 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_other_signatories;
        case 1:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 7169: /* module 28 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_threshold;
        case 1:
            return STR_IT_other_signatories;
        case 2:
            return STR_IT_maybe_timepoint;
        case 3:
            return STR_IT_call;
        case 4:
            return STR_IT_store_call;
        case 5:
            return STR_IT_max_weight;
        default:
            return NULL;
        }
    case 7170: /* module 28 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_threshold;
        case 1:
            return STR_IT_other_signatories;
        case 2:
            return STR_IT_maybe_timepoint;
        case 3:
            return STR_IT_call_hash;
        case 4:
            return STR_IT_max_weight;
        default:
            return NULL;
        }
    case 7171: /* module 28 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_threshold;
        case 1:
            return STR_IT_other_signatories;
        case 2:
            return STR_IT_timepoint;
        case 3:
            return STR_IT_call_hash;
        default:
            return NULL;
        }
    case 7424: /* module 29 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_admin;
        case 2:
            return STR_IT_max_zombies;
        case 3:
            return STR_IT_min_balance;
        default:
            return NULL;
        }
    case 7425: /* module 29 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_owner;
        case 2:
            return STR_IT_max_zombies;
        case 3:
            return STR_IT_min_balance;
        default:
            return NULL;
        }
    case 7426: /* module 29 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_zombies_witness;
        default:
            return NULL;
        }
    case 7427: /* module 29 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_zombies_witness;
        default:
            return NULL;
        }
    case 7428: /* module 29 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_beneficiary;
        case 2:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 7429: /* module 29 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_who;
        case 2:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 7430: /* module 29 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_target;
        case 2:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 7431: /* module 29 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_source;
        case 2:
            return STR_IT_dest;
        case 3:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 7432: /* module 29 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 7433: /* module 29 call 9 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 7434: /* module 29 call 10 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_new_owner;
        default:
            return NULL;
        }
    case 7435: /* module 29 call 11 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_issuer;
        case 2:
            return STR_IT_admin;
        case 3:
            return STR_IT_freezer;
        default:
            return NULL;
        }
    case 7436: /* module 29 call 12 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_max_zombies;
        default:
            return NULL;
        }
    case 8192: /* module 32 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_payout;
        default:
            return NULL;
        }
    case 8193: /* module 32 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_interval;
        default:
            return NULL;
        }
    case 8448: /* module 33 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_transaction;
        default:
            return NULL;
        }
    case 8704: /* module 34 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_address;
        case 1:
            return STR_IT_value;
        default:
            return NULL;
        }
    case 8705: /* module 34 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_source;
        case 1:
            return STR_IT_target;
        case 2:
            return STR_IT_input;
        case 3:
            return STR_IT_value;
        case 4:
            return STR_IT_gas_limit;
        case 5:
            return STR_IT_gas_price;
        case 6:
            return STR_IT_nonce;
        default:
            return NULL;
        }
    case 8706: /* module 34 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_source;
        case 1:
            return STR_IT_init;
        case 2:
            return STR_IT_value;
        case 3:
            return STR_IT_gas_limit;
        case 4:
            return STR_IT_gas_price;
        case 5:
            return STR_IT_nonce;
        default:
            return NULL;
        }
    case 8707: /* module 34 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_source;
        case 1:
            return STR_IT_init;
        case 2:
            return STR_IT_salt;
        case 3:
            return STR_IT_value;
        case 4:
            return STR_IT_gas_limit;
        case 5:
            return STR_IT_gas_price;
        case 6:
            return STR_IT_nonce;
        default:
            return NULL;
        }
    case 8960: /* module 35 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_threshold;
        default:
            return NULL;
        }
    case 8961: /* module 35 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_method;
        default:
            return NULL;
        }
    case 8962: /* module 35 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        default:
            return NULL;
        }
    case 8963: /* module 35 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        default:
            return NULL;
        }
    case 8964: /* module 35 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_v;
        default:
            return NULL;
        }
    case 8965: /* module 35 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_v;
        default:
            return NULL;
        }
    case 8966: /* module 35 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_nonce;
        case 1:
            return STR_IT_src_id;
        case 2:
            return STR_IT_r_id;
        case 3:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 8967: /* module 35 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_nonce;
        case 1:
            return STR_IT_src_id;
        case 2:
            return STR_IT_r_id;
        case 3:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 8968: /* module 35 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_nonce;
        case 1:
            return STR_IT_src_id;
        case 2:
            return STR_IT_prop;
        default:
            return NULL;
        }
    case 9216: /* module 36 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_amount;
        case 1:
            return STR_IT_recipient;
        case 2:
            return STR_IT_dest_id;
        default:
            return NULL;
        }
    case 9217: /* module 36 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_to;
        case 1:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 9472: /* module 37 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_value;
        case 1:
            return STR_IT_description;
        default:
            return NULL;
        }
    case 9473: /* module 37 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bounty_id;
        default:
            return NULL;
        }
    case 9474: /* module 37 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bounty_id;
        case 1:
            return STR_IT_curator;
        case 2:
            return STR_IT_fee;
        default:
            return NULL;
        }
    case 9475: /* module 37 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bounty_id;
        default:
            return NULL;
        }
    case 9476: /* module 37 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bounty_id;
        default:
            return NULL;
        }
    case 9477: /* module 37 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bounty_id;
        case 1:
            return STR_IT_beneficiary;
        default:
            return NULL;
        }
    case 9478: /* module 37 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bounty_id;
        default:
            return NULL;
        }
    case 9479: /* module 37 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bounty_id;
        default:
            return NULL;
        }
    case 9480: /* module 37 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bounty_id;
        case 1:
            return STR_IT__remark;
        default:
            return NULL;
        }
    case 9728: /* module 38 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_reason;
        case 1:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 9729: /* module 38 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_hash;
        default:
            return NULL;
        }
    case 9730: /* module 38 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_reason;
        case 1:
            return STR_IT_who;
        case 2:
            return STR_IT_tip_value;
        default:
            return NULL;
        }
    case 9731: /* module 38 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_hash;
        case 1:
            return STR_IT_tip_value;
        default:
            return NULL;
        }
    case 9732: /* module 38 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_hash;
        default:
            return NULL;
        }
    case 9733: /* module 38 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_hash;
        default:
            return NULL;
        }
#endif
    default:
        return NULL;
    }

    return NULL;
}

parser_error_t _getMethod_ItemValue_V1(
    pd_Method_V1_t* m,
    uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx,
    char* outValue, uint16_t outValueLen,
    uint8_t pageIdx, uint8_t* pageCount)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 256: /* module 1 call 0 */
        switch (itemIdx) {
        case 0: /* utility_batch_V1 - calls */;
            return _toStringVecCall(
                &m->basic.utility_batch_V1.calls,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 258: /* module 1 call 2 */
        switch (itemIdx) {
        case 0: /* utility_batch_all_V1 - calls */;
            return _toStringVecCall(
                &m->basic.utility_batch_all_V1.calls,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1536: /* module 6 call 0 */
        switch (itemIdx) {
        case 0: /* balances_transfer_V1 - dest */;
            return _toStringLookupSource_V1(
                &m->basic.balances_transfer_V1.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_transfer_V1 - value */;
            return _toStringCompactBalance(
                &m->basic.balances_transfer_V1.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1539: /* module 6 call 3 */
        switch (itemIdx) {
        case 0: /* balances_transfer_keep_alive_V1 - dest */;
            return _toStringLookupSource_V1(
                &m->basic.balances_transfer_keep_alive_V1.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_transfer_keep_alive_V1 - value */;
            return _toStringCompactBalance(
                &m->basic.balances_transfer_keep_alive_V1.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2048: /* module 8 call 0 */
        switch (itemIdx) {
        case 0: /* staking_bond_V1 - controller */;
            return _toStringLookupSource_V1(
                &m->basic.staking_bond_V1.controller,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_bond_V1 - value */;
            return _toStringCompactBalanceOf(
                &m->basic.staking_bond_V1.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* staking_bond_V1 - payee */;
            return _toStringRewardDestination_V1(
                &m->basic.staking_bond_V1.payee,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2049: /* module 8 call 1 */
        switch (itemIdx) {
        case 0: /* staking_bond_extra_V1 - max_additional */;
            return _toStringCompactBalanceOf(
                &m->basic.staking_bond_extra_V1.max_additional,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2050: /* module 8 call 2 */
        switch (itemIdx) {
        case 0: /* staking_unbond_V1 - value */;
            return _toStringCompactBalanceOf(
                &m->basic.staking_unbond_V1.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2051: /* module 8 call 3 */
        switch (itemIdx) {
        case 0: /* staking_withdraw_unbonded_V1 - num_slashing_spans */;
            return _toStringu32(
                &m->basic.staking_withdraw_unbonded_V1.num_slashing_spans,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2052: /* module 8 call 4 */
        switch (itemIdx) {
        case 0: /* staking_validate_V1 - prefs */;
            return _toStringValidatorPrefs_V1(
                &m->basic.staking_validate_V1.prefs,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2053: /* module 8 call 5 */
        switch (itemIdx) {
        case 0: /* staking_nominate_V1 - targets */;
            return _toStringVecLookupSource_V1(
                &m->basic.staking_nominate_V1.targets,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2054: /* module 8 call 6 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 2055: /* module 8 call 7 */
        switch (itemIdx) {
        case 0: /* staking_set_payee_V1 - payee */;
            return _toStringRewardDestination_V1(
                &m->basic.staking_set_payee_V1.payee,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2066: /* module 8 call 18 */
        switch (itemIdx) {
        case 0: /* staking_payout_stakers_V1 - validator_stash */;
            return _toStringAccountId_V1(
                &m->basic.staking_payout_stakers_V1.validator_stash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_payout_stakers_V1 - era */;
            return _toStringEraIndex_V1(
                &m->basic.staking_payout_stakers_V1.era,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2067: /* module 8 call 19 */
        switch (itemIdx) {
        case 0: /* staking_rebond_V1 - value */;
            return _toStringCompactBalanceOf(
                &m->basic.staking_rebond_V1.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2304: /* module 9 call 0 */
        switch (itemIdx) {
        case 0: /* session_set_keys_V1 - keys */;
            return _toStringKeys_V1(
                &m->basic.session_set_keys_V1.keys,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* session_set_keys_V1 - proof */;
            return _toStringBytes(
                &m->basic.session_set_keys_V1.proof,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2305: /* module 9 call 1 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
#ifdef SUBSTRATE_PARSER_FULL
    case 0: /* module 0 call 0 */
        switch (itemIdx) {
        case 0: /* system_fill_block_V1 - _ratio */;
            return _toStringPerbill_V1(
                &m->basic.system_fill_block_V1._ratio,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1: /* module 0 call 1 */
        switch (itemIdx) {
        case 0: /* system_remark_V1 - _remark */;
            return _toStringBytes(
                &m->basic.system_remark_V1._remark,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2: /* module 0 call 2 */
        switch (itemIdx) {
        case 0: /* system_set_heap_pages_V1 - pages */;
            return _toStringu64(
                &m->basic.system_set_heap_pages_V1.pages,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3: /* module 0 call 3 */
        switch (itemIdx) {
        case 0: /* system_set_code_V1 - code */;
            return _toStringBytes(
                &m->basic.system_set_code_V1.code,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4: /* module 0 call 4 */
        switch (itemIdx) {
        case 0: /* system_set_code_without_checks_V1 - code */;
            return _toStringBytes(
                &m->basic.system_set_code_without_checks_V1.code,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5: /* module 0 call 5 */
        switch (itemIdx) {
        case 0: /* system_set_changes_trie_config_V1 - changes_trie_config */;
            return _toStringOptionChangesTrieConfiguration_V1(
                &m->basic.system_set_changes_trie_config_V1.changes_trie_config,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6: /* module 0 call 6 */
        switch (itemIdx) {
        case 0: /* system_set_storage_V1 - items */;
            return _toStringVecKeyValue_V1(
                &m->basic.system_set_storage_V1.items,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7: /* module 0 call 7 */
        switch (itemIdx) {
        case 0: /* system_kill_storage_V1 - keys */;
            return _toStringVecKey_V1(
                &m->basic.system_kill_storage_V1.keys,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8: /* module 0 call 8 */
        switch (itemIdx) {
        case 0: /* system_kill_prefix_V1 - prefix */;
            return _toStringKey_V1(
                &m->basic.system_kill_prefix_V1.prefix,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* system_kill_prefix_V1 - _subkeys */;
            return _toStringu32(
                &m->basic.system_kill_prefix_V1._subkeys,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9: /* module 0 call 9 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 257: /* module 1 call 1 */
        switch (itemIdx) {
        case 0: /* utility_as_derivative_V1 - index */;
            return _toStringu16(
                &m->basic.utility_as_derivative_V1.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* utility_as_derivative_V1 - call */;
            return _toStringCall(
                &m->basic.utility_as_derivative_V1.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 768: /* module 3 call 0 */
        switch (itemIdx) {
        case 0: /* timestamp_set_V1 - now */;
            return _toStringCompactMoment_V1(
                &m->basic.timestamp_set_V1.now,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1024: /* module 4 call 0 */
        switch (itemIdx) {
        case 0: /* authorship_set_uncles_V1 - new_uncles */;
            return _toStringVecHeader(
                &m->basic.authorship_set_uncles_V1.new_uncles,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1280: /* module 5 call 0 */
        switch (itemIdx) {
        case 0: /* indices_claim_V1 - index */;
            return _toStringAccountIndex_V1(
                &m->basic.indices_claim_V1.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1281: /* module 5 call 1 */
        switch (itemIdx) {
        case 0: /* indices_transfer_V1 - new_ */;
            return _toStringAccountId_V1(
                &m->basic.indices_transfer_V1.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* indices_transfer_V1 - index */;
            return _toStringAccountIndex_V1(
                &m->basic.indices_transfer_V1.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1282: /* module 5 call 2 */
        switch (itemIdx) {
        case 0: /* indices_free_V1 - index */;
            return _toStringAccountIndex_V1(
                &m->basic.indices_free_V1.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1283: /* module 5 call 3 */
        switch (itemIdx) {
        case 0: /* indices_force_transfer_V1 - new_ */;
            return _toStringAccountId_V1(
                &m->basic.indices_force_transfer_V1.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* indices_force_transfer_V1 - index */;
            return _toStringAccountIndex_V1(
                &m->basic.indices_force_transfer_V1.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* indices_force_transfer_V1 - freeze */;
            return _toStringbool(
                &m->basic.indices_force_transfer_V1.freeze,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1284: /* module 5 call 4 */
        switch (itemIdx) {
        case 0: /* indices_freeze_V1 - index */;
            return _toStringAccountIndex_V1(
                &m->basic.indices_freeze_V1.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1537: /* module 6 call 1 */
        switch (itemIdx) {
        case 0: /* balances_set_balance_V1 - who */;
            return _toStringLookupSource_V1(
                &m->basic.balances_set_balance_V1.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_set_balance_V1 - new_free */;
            return _toStringCompactBalance(
                &m->basic.balances_set_balance_V1.new_free,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* balances_set_balance_V1 - new_reserved */;
            return _toStringCompactBalance(
                &m->basic.balances_set_balance_V1.new_reserved,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1538: /* module 6 call 2 */
        switch (itemIdx) {
        case 0: /* balances_force_transfer_V1 - source */;
            return _toStringLookupSource_V1(
                &m->basic.balances_force_transfer_V1.source,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_force_transfer_V1 - dest */;
            return _toStringLookupSource_V1(
                &m->basic.balances_force_transfer_V1.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* balances_force_transfer_V1 - value */;
            return _toStringCompactBalance(
                &m->basic.balances_force_transfer_V1.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2056: /* module 8 call 8 */
        switch (itemIdx) {
        case 0: /* staking_set_controller_V1 - controller */;
            return _toStringLookupSource_V1(
                &m->basic.staking_set_controller_V1.controller,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2057: /* module 8 call 9 */
        switch (itemIdx) {
        case 0: /* staking_set_validator_count_V1 - new_ */;
            return _toStringCompactu32(
                &m->basic.staking_set_validator_count_V1.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2058: /* module 8 call 10 */
        switch (itemIdx) {
        case 0: /* staking_increase_validator_count_V1 - additional */;
            return _toStringCompactu32(
                &m->basic.staking_increase_validator_count_V1.additional,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2059: /* module 8 call 11 */
        switch (itemIdx) {
        case 0: /* staking_scale_validator_count_V1 - factor */;
            return _toStringPercent_V1(
                &m->basic.staking_scale_validator_count_V1.factor,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2060: /* module 8 call 12 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 2061: /* module 8 call 13 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 2062: /* module 8 call 14 */
        switch (itemIdx) {
        case 0: /* staking_set_invulnerables_V1 - invulnerables */;
            return _toStringVecAccountId_V1(
                &m->basic.staking_set_invulnerables_V1.invulnerables,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2063: /* module 8 call 15 */
        switch (itemIdx) {
        case 0: /* staking_force_unstake_V1 - stash */;
            return _toStringAccountId_V1(
                &m->basic.staking_force_unstake_V1.stash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_force_unstake_V1 - num_slashing_spans */;
            return _toStringu32(
                &m->basic.staking_force_unstake_V1.num_slashing_spans,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2064: /* module 8 call 16 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 2065: /* module 8 call 17 */
        switch (itemIdx) {
        case 0: /* staking_cancel_deferred_slash_V1 - era */;
            return _toStringEraIndex_V1(
                &m->basic.staking_cancel_deferred_slash_V1.era,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_cancel_deferred_slash_V1 - slash_indices */;
            return _toStringVecu32(
                &m->basic.staking_cancel_deferred_slash_V1.slash_indices,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2068: /* module 8 call 20 */
        switch (itemIdx) {
        case 0: /* staking_set_history_depth_V1 - new_history_depth */;
            return _toStringCompactEraIndex_V1(
                &m->basic.staking_set_history_depth_V1.new_history_depth,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_set_history_depth_V1 - _era_items_deleted */;
            return _toStringCompactu32(
                &m->basic.staking_set_history_depth_V1._era_items_deleted,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2069: /* module 8 call 21 */
        switch (itemIdx) {
        case 0: /* staking_reap_stash_V1 - stash */;
            return _toStringAccountId_V1(
                &m->basic.staking_reap_stash_V1.stash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_reap_stash_V1 - num_slashing_spans */;
            return _toStringu32(
                &m->basic.staking_reap_stash_V1.num_slashing_spans,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2070: /* module 8 call 22 */
        switch (itemIdx) {
        case 0: /* staking_submit_election_solution_V1 - winners */;
            return _toStringVecValidatorIndex_V1(
                &m->basic.staking_submit_election_solution_V1.winners,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_submit_election_solution_V1 - compact */;
            return _toStringCompactAssignments_V1(
                &m->basic.staking_submit_election_solution_V1.compact,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* staking_submit_election_solution_V1 - score */;
            return _toStringElectionScore_V1(
                &m->basic.staking_submit_election_solution_V1.score,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* staking_submit_election_solution_V1 - era */;
            return _toStringEraIndex_V1(
                &m->basic.staking_submit_election_solution_V1.era,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* staking_submit_election_solution_V1 - size */;
            return _toStringElectionSize_V1(
                &m->basic.staking_submit_election_solution_V1.size,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2071: /* module 8 call 23 */
        switch (itemIdx) {
        case 0: /* staking_submit_election_solution_unsigned_V1 - winners */;
            return _toStringVecValidatorIndex_V1(
                &m->basic.staking_submit_election_solution_unsigned_V1.winners,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_submit_election_solution_unsigned_V1 - compact */;
            return _toStringCompactAssignments_V1(
                &m->basic.staking_submit_election_solution_unsigned_V1.compact,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* staking_submit_election_solution_unsigned_V1 - score */;
            return _toStringElectionScore_V1(
                &m->basic.staking_submit_election_solution_unsigned_V1.score,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* staking_submit_election_solution_unsigned_V1 - era */;
            return _toStringEraIndex_V1(
                &m->basic.staking_submit_election_solution_unsigned_V1.era,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* staking_submit_election_solution_unsigned_V1 - size */;
            return _toStringElectionSize_V1(
                &m->basic.staking_submit_election_solution_unsigned_V1.size,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2560: /* module 10 call 0 */
        switch (itemIdx) {
        case 0: /* democracy_propose_V1 - proposal_hash */;
            return _toStringHash(
                &m->basic.democracy_propose_V1.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* democracy_propose_V1 - value */;
            return _toStringCompactBalanceOf(
                &m->basic.democracy_propose_V1.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2561: /* module 10 call 1 */
        switch (itemIdx) {
        case 0: /* democracy_second_V1 - proposal */;
            return _toStringCompactPropIndex_V1(
                &m->basic.democracy_second_V1.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* democracy_second_V1 - seconds_upper_bound */;
            return _toStringCompactu32(
                &m->basic.democracy_second_V1.seconds_upper_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2562: /* module 10 call 2 */
        switch (itemIdx) {
        case 0: /* democracy_vote_V1 - ref_index */;
            return _toStringCompactReferendumIndex_V1(
                &m->basic.democracy_vote_V1.ref_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* democracy_vote_V1 - vote */;
            return _toStringAccountVote_V1(
                &m->basic.democracy_vote_V1.vote,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2563: /* module 10 call 3 */
        switch (itemIdx) {
        case 0: /* democracy_emergency_cancel_V1 - ref_index */;
            return _toStringReferendumIndex_V1(
                &m->basic.democracy_emergency_cancel_V1.ref_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2564: /* module 10 call 4 */
        switch (itemIdx) {
        case 0: /* democracy_external_propose_V1 - proposal_hash */;
            return _toStringHash(
                &m->basic.democracy_external_propose_V1.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2565: /* module 10 call 5 */
        switch (itemIdx) {
        case 0: /* democracy_external_propose_majority_V1 - proposal_hash */;
            return _toStringHash(
                &m->basic.democracy_external_propose_majority_V1.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2566: /* module 10 call 6 */
        switch (itemIdx) {
        case 0: /* democracy_external_propose_default_V1 - proposal_hash */;
            return _toStringHash(
                &m->basic.democracy_external_propose_default_V1.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2567: /* module 10 call 7 */
        switch (itemIdx) {
        case 0: /* democracy_fast_track_V1 - proposal_hash */;
            return _toStringHash(
                &m->basic.democracy_fast_track_V1.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* democracy_fast_track_V1 - voting_period */;
            return _toStringBlockNumber(
                &m->basic.democracy_fast_track_V1.voting_period,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* democracy_fast_track_V1 - delay */;
            return _toStringBlockNumber(
                &m->basic.democracy_fast_track_V1.delay,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2568: /* module 10 call 8 */
        switch (itemIdx) {
        case 0: /* democracy_veto_external_V1 - proposal_hash */;
            return _toStringHash(
                &m->basic.democracy_veto_external_V1.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2569: /* module 10 call 9 */
        switch (itemIdx) {
        case 0: /* democracy_cancel_referendum_V1 - ref_index */;
            return _toStringCompactReferendumIndex_V1(
                &m->basic.democracy_cancel_referendum_V1.ref_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2570: /* module 10 call 10 */
        switch (itemIdx) {
        case 0: /* democracy_cancel_queued_V1 - which */;
            return _toStringReferendumIndex_V1(
                &m->basic.democracy_cancel_queued_V1.which,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2571: /* module 10 call 11 */
        switch (itemIdx) {
        case 0: /* democracy_delegate_V1 - to */;
            return _toStringAccountId_V1(
                &m->basic.democracy_delegate_V1.to,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* democracy_delegate_V1 - conviction */;
            return _toStringConviction_V1(
                &m->basic.democracy_delegate_V1.conviction,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* democracy_delegate_V1 - balance */;
            return _toStringBalanceOf(
                &m->basic.democracy_delegate_V1.balance,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2572: /* module 10 call 12 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 2573: /* module 10 call 13 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 2574: /* module 10 call 14 */
        switch (itemIdx) {
        case 0: /* democracy_note_preimage_V1 - encoded_proposal */;
            return _toStringBytes(
                &m->basic.democracy_note_preimage_V1.encoded_proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2575: /* module 10 call 15 */
        switch (itemIdx) {
        case 0: /* democracy_note_preimage_operational_V1 - encoded_proposal */;
            return _toStringBytes(
                &m->basic.democracy_note_preimage_operational_V1.encoded_proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2576: /* module 10 call 16 */
        switch (itemIdx) {
        case 0: /* democracy_note_imminent_preimage_V1 - encoded_proposal */;
            return _toStringBytes(
                &m->basic.democracy_note_imminent_preimage_V1.encoded_proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2577: /* module 10 call 17 */
        switch (itemIdx) {
        case 0: /* democracy_note_imminent_preimage_operational_V1 - encoded_proposal */;
            return _toStringBytes(
                &m->basic.democracy_note_imminent_preimage_operational_V1.encoded_proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2578: /* module 10 call 18 */
        switch (itemIdx) {
        case 0: /* democracy_reap_preimage_V1 - proposal_hash */;
            return _toStringHash(
                &m->basic.democracy_reap_preimage_V1.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* democracy_reap_preimage_V1 - proposal_len_upper_bound */;
            return _toStringCompactu32(
                &m->basic.democracy_reap_preimage_V1.proposal_len_upper_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2579: /* module 10 call 19 */
        switch (itemIdx) {
        case 0: /* democracy_unlock_V1 - target */;
            return _toStringAccountId_V1(
                &m->basic.democracy_unlock_V1.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2580: /* module 10 call 20 */
        switch (itemIdx) {
        case 0: /* democracy_remove_vote_V1 - index */;
            return _toStringReferendumIndex_V1(
                &m->basic.democracy_remove_vote_V1.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2581: /* module 10 call 21 */
        switch (itemIdx) {
        case 0: /* democracy_remove_other_vote_V1 - target */;
            return _toStringAccountId_V1(
                &m->basic.democracy_remove_other_vote_V1.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* democracy_remove_other_vote_V1 - index */;
            return _toStringReferendumIndex_V1(
                &m->basic.democracy_remove_other_vote_V1.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2582: /* module 10 call 22 */
        switch (itemIdx) {
        case 0: /* democracy_enact_proposal_V1 - proposal_hash */;
            return _toStringHash(
                &m->basic.democracy_enact_proposal_V1.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* democracy_enact_proposal_V1 - index */;
            return _toStringReferendumIndex_V1(
                &m->basic.democracy_enact_proposal_V1.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2583: /* module 10 call 23 */
        switch (itemIdx) {
        case 0: /* democracy_blacklist_V1 - proposal_hash */;
            return _toStringHash(
                &m->basic.democracy_blacklist_V1.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* democracy_blacklist_V1 - maybe_ref_index */;
            return _toStringOptionReferendumIndex_V1(
                &m->basic.democracy_blacklist_V1.maybe_ref_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2584: /* module 10 call 24 */
        switch (itemIdx) {
        case 0: /* democracy_cancel_proposal_V1 - prop_index */;
            return _toStringCompactPropIndex_V1(
                &m->basic.democracy_cancel_proposal_V1.prop_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2816: /* module 11 call 0 */
        switch (itemIdx) {
        case 0: /* council_set_members_V1 - new_members */;
            return _toStringVecAccountId_V1(
                &m->basic.council_set_members_V1.new_members,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* council_set_members_V1 - prime */;
            return _toStringOptionAccountId_V1(
                &m->basic.council_set_members_V1.prime,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* council_set_members_V1 - old_count */;
            return _toStringMemberCount_V1(
                &m->basic.council_set_members_V1.old_count,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2817: /* module 11 call 1 */
        switch (itemIdx) {
        case 0: /* council_execute_V1 - proposal */;
            return _toStringProposal(
                &m->basic.council_execute_V1.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* council_execute_V1 - length_bound */;
            return _toStringCompactu32(
                &m->basic.council_execute_V1.length_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2818: /* module 11 call 2 */
        switch (itemIdx) {
        case 0: /* council_propose_V1 - threshold */;
            return _toStringCompactMemberCount_V1(
                &m->basic.council_propose_V1.threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* council_propose_V1 - proposal */;
            return _toStringProposal(
                &m->basic.council_propose_V1.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* council_propose_V1 - length_bound */;
            return _toStringCompactu32(
                &m->basic.council_propose_V1.length_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2819: /* module 11 call 3 */
        switch (itemIdx) {
        case 0: /* council_vote_V1 - proposal */;
            return _toStringHash(
                &m->basic.council_vote_V1.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* council_vote_V1 - index */;
            return _toStringCompactProposalIndex_V1(
                &m->basic.council_vote_V1.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* council_vote_V1 - approve */;
            return _toStringbool(
                &m->basic.council_vote_V1.approve,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2820: /* module 11 call 4 */
        switch (itemIdx) {
        case 0: /* council_close_V1 - proposal_hash */;
            return _toStringHash(
                &m->basic.council_close_V1.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* council_close_V1 - index */;
            return _toStringCompactProposalIndex_V1(
                &m->basic.council_close_V1.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* council_close_V1 - proposal_weight_bound */;
            return _toStringCompactWeight_V1(
                &m->basic.council_close_V1.proposal_weight_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* council_close_V1 - length_bound */;
            return _toStringCompactu32(
                &m->basic.council_close_V1.length_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2821: /* module 11 call 5 */
        switch (itemIdx) {
        case 0: /* council_disapprove_proposal_V1 - proposal_hash */;
            return _toStringHash(
                &m->basic.council_disapprove_proposal_V1.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3072: /* module 12 call 0 */
        switch (itemIdx) {
        case 0: /* elections_vote_V1 - votes */;
            return _toStringVecAccountId_V1(
                &m->basic.elections_vote_V1.votes,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* elections_vote_V1 - value */;
            return _toStringCompactBalanceOf(
                &m->basic.elections_vote_V1.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3073: /* module 12 call 1 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 3074: /* module 12 call 2 */
        switch (itemIdx) {
        case 0: /* elections_report_defunct_voter_V1 - defunct */;
            return _toStringDefunctVoter_V1(
                &m->basic.elections_report_defunct_voter_V1.defunct,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3075: /* module 12 call 3 */
        switch (itemIdx) {
        case 0: /* elections_submit_candidacy_V1 - candidate_count */;
            return _toStringCompactu32(
                &m->basic.elections_submit_candidacy_V1.candidate_count,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3076: /* module 12 call 4 */
        switch (itemIdx) {
        case 0: /* elections_renounce_candidacy_V1 - renouncing */;
            return _toStringRenouncing_V1(
                &m->basic.elections_renounce_candidacy_V1.renouncing,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3077: /* module 12 call 5 */
        switch (itemIdx) {
        case 0: /* elections_remove_member_V1 - who */;
            return _toStringLookupSource_V1(
                &m->basic.elections_remove_member_V1.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* elections_remove_member_V1 - has_replacement */;
            return _toStringbool(
                &m->basic.elections_remove_member_V1.has_replacement,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3584: /* module 14 call 0 */
        switch (itemIdx) {
        case 0: /* grandpa_report_equivocation_V1 - equivocation_proof */;
            return _toStringGrandpaEquivocationProof_V1(
                &m->basic.grandpa_report_equivocation_V1.equivocation_proof,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* grandpa_report_equivocation_V1 - key_owner_proof */;
            return _toStringKeyOwnerProof_V1(
                &m->basic.grandpa_report_equivocation_V1.key_owner_proof,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3585: /* module 14 call 1 */
        switch (itemIdx) {
        case 0: /* grandpa_report_equivocation_unsigned_V1 - equivocation_proof */;
            return _toStringGrandpaEquivocationProof_V1(
                &m->basic.grandpa_report_equivocation_unsigned_V1.equivocation_proof,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* grandpa_report_equivocation_unsigned_V1 - key_owner_proof */;
            return _toStringKeyOwnerProof_V1(
                &m->basic.grandpa_report_equivocation_unsigned_V1.key_owner_proof,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3586: /* module 14 call 2 */
        switch (itemIdx) {
        case 0: /* grandpa_note_stalled_V1 - delay */;
            return _toStringBlockNumber(
                &m->basic.grandpa_note_stalled_V1.delay,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* grandpa_note_stalled_V1 - best_finalized_block_number */;
            return _toStringBlockNumber(
                &m->basic.grandpa_note_stalled_V1.best_finalized_block_number,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3840: /* module 15 call 0 */
        switch (itemIdx) {
        case 0: /* treasury_propose_spend_V1 - value */;
            return _toStringCompactBalanceOf(
                &m->basic.treasury_propose_spend_V1.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* treasury_propose_spend_V1 - beneficiary */;
            return _toStringLookupSource_V1(
                &m->basic.treasury_propose_spend_V1.beneficiary,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3841: /* module 15 call 1 */
        switch (itemIdx) {
        case 0: /* treasury_reject_proposal_V1 - proposal_id */;
            return _toStringCompactProposalIndex_V1(
                &m->basic.treasury_reject_proposal_V1.proposal_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3842: /* module 15 call 2 */
        switch (itemIdx) {
        case 0: /* treasury_approve_proposal_V1 - proposal_id */;
            return _toStringCompactProposalIndex_V1(
                &m->basic.treasury_approve_proposal_V1.proposal_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4096: /* module 16 call 0 */
        switch (itemIdx) {
        case 0: /* contracts_update_schedule_V1 - schedule */;
            return _toStringSchedule_V1(
                &m->basic.contracts_update_schedule_V1.schedule,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4097: /* module 16 call 1 */
        switch (itemIdx) {
        case 0: /* contracts_put_code_V1 - code */;
            return _toStringBytes(
                &m->basic.contracts_put_code_V1.code,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4098: /* module 16 call 2 */
        switch (itemIdx) {
        case 0: /* contracts_call_V1 - dest */;
            return _toStringLookupSource_V1(
                &m->basic.contracts_call_V1.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* contracts_call_V1 - value */;
            return _toStringCompactBalanceOf(
                &m->basic.contracts_call_V1.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* contracts_call_V1 - gas_limit */;
            return _toStringCompactGas_V1(
                &m->basic.contracts_call_V1.gas_limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* contracts_call_V1 - data */;
            return _toStringBytes(
                &m->basic.contracts_call_V1.data,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4099: /* module 16 call 3 */
        switch (itemIdx) {
        case 0: /* contracts_instantiate_V1 - endowment */;
            return _toStringCompactBalanceOf(
                &m->basic.contracts_instantiate_V1.endowment,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* contracts_instantiate_V1 - gas_limit */;
            return _toStringCompactGas_V1(
                &m->basic.contracts_instantiate_V1.gas_limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* contracts_instantiate_V1 - code_hash */;
            return _toStringCodeHash_V1(
                &m->basic.contracts_instantiate_V1.code_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* contracts_instantiate_V1 - data */;
            return _toStringBytes(
                &m->basic.contracts_instantiate_V1.data,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* contracts_instantiate_V1 - salt */;
            return _toStringBytes(
                &m->basic.contracts_instantiate_V1.salt,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4100: /* module 16 call 4 */
        switch (itemIdx) {
        case 0: /* contracts_claim_surcharge_V1 - dest */;
            return _toStringAccountId_V1(
                &m->basic.contracts_claim_surcharge_V1.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* contracts_claim_surcharge_V1 - aux_sender */;
            return _toStringOptionAccountId_V1(
                &m->basic.contracts_claim_surcharge_V1.aux_sender,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4352: /* module 17 call 0 */
        switch (itemIdx) {
        case 0: /* sudo_sudo_V1 - call */;
            return _toStringCall(
                &m->basic.sudo_sudo_V1.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4353: /* module 17 call 1 */
        switch (itemIdx) {
        case 0: /* sudo_sudo_unchecked_weight_V1 - call */;
            return _toStringCall(
                &m->basic.sudo_sudo_unchecked_weight_V1.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* sudo_sudo_unchecked_weight_V1 - _weight */;
            return _toStringWeight_V1(
                &m->basic.sudo_sudo_unchecked_weight_V1._weight,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4354: /* module 17 call 2 */
        switch (itemIdx) {
        case 0: /* sudo_set_key_V1 - new_ */;
            return _toStringLookupSource_V1(
                &m->basic.sudo_set_key_V1.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4355: /* module 17 call 3 */
        switch (itemIdx) {
        case 0: /* sudo_sudo_as_V1 - who */;
            return _toStringLookupSource_V1(
                &m->basic.sudo_sudo_as_V1.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* sudo_sudo_as_V1 - call */;
            return _toStringCall(
                &m->basic.sudo_sudo_as_V1.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4608: /* module 18 call 0 */
        switch (itemIdx) {
        case 0: /* imonline_heartbeat_V1 - heartbeat */;
            return _toStringHeartbeat(
                &m->basic.imonline_heartbeat_V1.heartbeat,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* imonline_heartbeat_V1 - _signature */;
            return _toStringSignature_V1(
                &m->basic.imonline_heartbeat_V1._signature,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5888: /* module 23 call 0 */
        switch (itemIdx) {
        case 0: /* identity_add_registrar_V1 - account */;
            return _toStringAccountId_V1(
                &m->basic.identity_add_registrar_V1.account,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5889: /* module 23 call 1 */
        switch (itemIdx) {
        case 0: /* identity_set_identity_V1 - info */;
            return _toStringIdentityInfo_V1(
                &m->basic.identity_set_identity_V1.info,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5890: /* module 23 call 2 */
        switch (itemIdx) {
        case 0: /* identity_set_subs_V1 - subs */;
            return _toStringVecTupleAccountIdData_V1(
                &m->basic.identity_set_subs_V1.subs,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5891: /* module 23 call 3 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 5892: /* module 23 call 4 */
        switch (itemIdx) {
        case 0: /* identity_request_judgement_V1 - reg_index */;
            return _toStringCompactRegistrarIndex_V1(
                &m->basic.identity_request_judgement_V1.reg_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_request_judgement_V1 - max_fee */;
            return _toStringCompactBalanceOf(
                &m->basic.identity_request_judgement_V1.max_fee,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5893: /* module 23 call 5 */
        switch (itemIdx) {
        case 0: /* identity_cancel_request_V1 - reg_index */;
            return _toStringRegistrarIndex_V1(
                &m->basic.identity_cancel_request_V1.reg_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5894: /* module 23 call 6 */
        switch (itemIdx) {
        case 0: /* identity_set_fee_V1 - index */;
            return _toStringCompactRegistrarIndex_V1(
                &m->basic.identity_set_fee_V1.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_set_fee_V1 - fee */;
            return _toStringCompactBalanceOf(
                &m->basic.identity_set_fee_V1.fee,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5895: /* module 23 call 7 */
        switch (itemIdx) {
        case 0: /* identity_set_account_id_V1 - index */;
            return _toStringCompactRegistrarIndex_V1(
                &m->basic.identity_set_account_id_V1.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_set_account_id_V1 - new_ */;
            return _toStringAccountId_V1(
                &m->basic.identity_set_account_id_V1.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5896: /* module 23 call 8 */
        switch (itemIdx) {
        case 0: /* identity_set_fields_V1 - index */;
            return _toStringCompactRegistrarIndex_V1(
                &m->basic.identity_set_fields_V1.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_set_fields_V1 - fields */;
            return _toStringIdentityFields_V1(
                &m->basic.identity_set_fields_V1.fields,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5897: /* module 23 call 9 */
        switch (itemIdx) {
        case 0: /* identity_provide_judgement_V1 - reg_index */;
            return _toStringCompactRegistrarIndex_V1(
                &m->basic.identity_provide_judgement_V1.reg_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_provide_judgement_V1 - target */;
            return _toStringLookupSource_V1(
                &m->basic.identity_provide_judgement_V1.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* identity_provide_judgement_V1 - judgement */;
            return _toStringIdentityJudgement_V1(
                &m->basic.identity_provide_judgement_V1.judgement,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5898: /* module 23 call 10 */
        switch (itemIdx) {
        case 0: /* identity_kill_identity_V1 - target */;
            return _toStringLookupSource_V1(
                &m->basic.identity_kill_identity_V1.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5899: /* module 23 call 11 */
        switch (itemIdx) {
        case 0: /* identity_add_sub_V1 - sub */;
            return _toStringLookupSource_V1(
                &m->basic.identity_add_sub_V1.sub,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_add_sub_V1 - data */;
            return _toStringData(
                &m->basic.identity_add_sub_V1.data,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5900: /* module 23 call 12 */
        switch (itemIdx) {
        case 0: /* identity_rename_sub_V1 - sub */;
            return _toStringLookupSource_V1(
                &m->basic.identity_rename_sub_V1.sub,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_rename_sub_V1 - data */;
            return _toStringData(
                &m->basic.identity_rename_sub_V1.data,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5901: /* module 23 call 13 */
        switch (itemIdx) {
        case 0: /* identity_remove_sub_V1 - sub */;
            return _toStringLookupSource_V1(
                &m->basic.identity_remove_sub_V1.sub,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5902: /* module 23 call 14 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 6144: /* module 24 call 0 */
        switch (itemIdx) {
        case 0: /* recovery_as_recovered_V1 - account */;
            return _toStringAccountId_V1(
                &m->basic.recovery_as_recovered_V1.account,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* recovery_as_recovered_V1 - call */;
            return _toStringCall(
                &m->basic.recovery_as_recovered_V1.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6145: /* module 24 call 1 */
        switch (itemIdx) {
        case 0: /* recovery_set_recovered_V1 - lost */;
            return _toStringAccountId_V1(
                &m->basic.recovery_set_recovered_V1.lost,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* recovery_set_recovered_V1 - rescuer */;
            return _toStringAccountId_V1(
                &m->basic.recovery_set_recovered_V1.rescuer,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6146: /* module 24 call 2 */
        switch (itemIdx) {
        case 0: /* recovery_create_recovery_V1 - friends */;
            return _toStringVecAccountId_V1(
                &m->basic.recovery_create_recovery_V1.friends,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* recovery_create_recovery_V1 - threshold */;
            return _toStringu16(
                &m->basic.recovery_create_recovery_V1.threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* recovery_create_recovery_V1 - delay_period */;
            return _toStringBlockNumber(
                &m->basic.recovery_create_recovery_V1.delay_period,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6147: /* module 24 call 3 */
        switch (itemIdx) {
        case 0: /* recovery_initiate_recovery_V1 - account */;
            return _toStringAccountId_V1(
                &m->basic.recovery_initiate_recovery_V1.account,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6148: /* module 24 call 4 */
        switch (itemIdx) {
        case 0: /* recovery_vouch_recovery_V1 - lost */;
            return _toStringAccountId_V1(
                &m->basic.recovery_vouch_recovery_V1.lost,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* recovery_vouch_recovery_V1 - rescuer */;
            return _toStringAccountId_V1(
                &m->basic.recovery_vouch_recovery_V1.rescuer,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6149: /* module 24 call 5 */
        switch (itemIdx) {
        case 0: /* recovery_claim_recovery_V1 - account */;
            return _toStringAccountId_V1(
                &m->basic.recovery_claim_recovery_V1.account,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6150: /* module 24 call 6 */
        switch (itemIdx) {
        case 0: /* recovery_close_recovery_V1 - rescuer */;
            return _toStringAccountId_V1(
                &m->basic.recovery_close_recovery_V1.rescuer,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6151: /* module 24 call 7 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 6152: /* module 24 call 8 */
        switch (itemIdx) {
        case 0: /* recovery_cancel_recovered_V1 - account */;
            return _toStringAccountId_V1(
                &m->basic.recovery_cancel_recovered_V1.account,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6400: /* module 25 call 0 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 6401: /* module 25 call 1 */
        switch (itemIdx) {
        case 0: /* vesting_vest_other_V1 - target */;
            return _toStringLookupSource_V1(
                &m->basic.vesting_vest_other_V1.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6402: /* module 25 call 2 */
        switch (itemIdx) {
        case 0: /* vesting_vested_transfer_V1 - target */;
            return _toStringLookupSource_V1(
                &m->basic.vesting_vested_transfer_V1.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* vesting_vested_transfer_V1 - schedule */;
            return _toStringVestingInfo_V1(
                &m->basic.vesting_vested_transfer_V1.schedule,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6403: /* module 25 call 3 */
        switch (itemIdx) {
        case 0: /* vesting_force_vested_transfer_V1 - source */;
            return _toStringLookupSource_V1(
                &m->basic.vesting_force_vested_transfer_V1.source,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* vesting_force_vested_transfer_V1 - target */;
            return _toStringLookupSource_V1(
                &m->basic.vesting_force_vested_transfer_V1.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* vesting_force_vested_transfer_V1 - schedule */;
            return _toStringVestingInfo_V1(
                &m->basic.vesting_force_vested_transfer_V1.schedule,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6656: /* module 26 call 0 */
        switch (itemIdx) {
        case 0: /* scheduler_schedule_V1 - when */;
            return _toStringBlockNumber(
                &m->basic.scheduler_schedule_V1.when,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* scheduler_schedule_V1 - maybe_periodic */;
            return _toStringOptionPeriod_V1(
                &m->basic.scheduler_schedule_V1.maybe_periodic,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* scheduler_schedule_V1 - priority */;
            return _toStringPriority_V1(
                &m->basic.scheduler_schedule_V1.priority,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* scheduler_schedule_V1 - call */;
            return _toStringCall(
                &m->basic.scheduler_schedule_V1.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6657: /* module 26 call 1 */
        switch (itemIdx) {
        case 0: /* scheduler_cancel_V1 - when */;
            return _toStringBlockNumber(
                &m->basic.scheduler_cancel_V1.when,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* scheduler_cancel_V1 - index */;
            return _toStringu32(
                &m->basic.scheduler_cancel_V1.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6658: /* module 26 call 2 */
        switch (itemIdx) {
        case 0: /* scheduler_schedule_named_V1 - id */;
            return _toStringBytes(
                &m->basic.scheduler_schedule_named_V1.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* scheduler_schedule_named_V1 - when */;
            return _toStringBlockNumber(
                &m->basic.scheduler_schedule_named_V1.when,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* scheduler_schedule_named_V1 - maybe_periodic */;
            return _toStringOptionPeriod_V1(
                &m->basic.scheduler_schedule_named_V1.maybe_periodic,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* scheduler_schedule_named_V1 - priority */;
            return _toStringPriority_V1(
                &m->basic.scheduler_schedule_named_V1.priority,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* scheduler_schedule_named_V1 - call */;
            return _toStringCall(
                &m->basic.scheduler_schedule_named_V1.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6659: /* module 26 call 3 */
        switch (itemIdx) {
        case 0: /* scheduler_cancel_named_V1 - id */;
            return _toStringBytes(
                &m->basic.scheduler_cancel_named_V1.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6660: /* module 26 call 4 */
        switch (itemIdx) {
        case 0: /* scheduler_schedule_after_V1 - after */;
            return _toStringBlockNumber(
                &m->basic.scheduler_schedule_after_V1.after,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* scheduler_schedule_after_V1 - maybe_periodic */;
            return _toStringOptionPeriod_V1(
                &m->basic.scheduler_schedule_after_V1.maybe_periodic,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* scheduler_schedule_after_V1 - priority */;
            return _toStringPriority_V1(
                &m->basic.scheduler_schedule_after_V1.priority,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* scheduler_schedule_after_V1 - call */;
            return _toStringCall(
                &m->basic.scheduler_schedule_after_V1.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6661: /* module 26 call 5 */
        switch (itemIdx) {
        case 0: /* scheduler_schedule_named_after_V1 - id */;
            return _toStringBytes(
                &m->basic.scheduler_schedule_named_after_V1.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* scheduler_schedule_named_after_V1 - after */;
            return _toStringBlockNumber(
                &m->basic.scheduler_schedule_named_after_V1.after,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* scheduler_schedule_named_after_V1 - maybe_periodic */;
            return _toStringOptionPeriod_V1(
                &m->basic.scheduler_schedule_named_after_V1.maybe_periodic,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* scheduler_schedule_named_after_V1 - priority */;
            return _toStringPriority_V1(
                &m->basic.scheduler_schedule_named_after_V1.priority,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* scheduler_schedule_named_after_V1 - call */;
            return _toStringCall(
                &m->basic.scheduler_schedule_named_after_V1.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6912: /* module 27 call 0 */
        switch (itemIdx) {
        case 0: /* proxy_proxy_V1 - real */;
            return _toStringAccountId_V1(
                &m->basic.proxy_proxy_V1.real,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_proxy_V1 - force_proxy_type */;
            return _toStringOptionProxyType_V1(
                &m->basic.proxy_proxy_V1.force_proxy_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* proxy_proxy_V1 - call */;
            return _toStringCall(
                &m->basic.proxy_proxy_V1.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6913: /* module 27 call 1 */
        switch (itemIdx) {
        case 0: /* proxy_add_proxy_V1 - delegate */;
            return _toStringAccountId_V1(
                &m->basic.proxy_add_proxy_V1.delegate,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_add_proxy_V1 - proxy_type */;
            return _toStringProxyType_V1(
                &m->basic.proxy_add_proxy_V1.proxy_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* proxy_add_proxy_V1 - delay */;
            return _toStringBlockNumber(
                &m->basic.proxy_add_proxy_V1.delay,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6914: /* module 27 call 2 */
        switch (itemIdx) {
        case 0: /* proxy_remove_proxy_V1 - delegate */;
            return _toStringAccountId_V1(
                &m->basic.proxy_remove_proxy_V1.delegate,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_remove_proxy_V1 - proxy_type */;
            return _toStringProxyType_V1(
                &m->basic.proxy_remove_proxy_V1.proxy_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* proxy_remove_proxy_V1 - delay */;
            return _toStringBlockNumber(
                &m->basic.proxy_remove_proxy_V1.delay,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6915: /* module 27 call 3 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 6916: /* module 27 call 4 */
        switch (itemIdx) {
        case 0: /* proxy_anonymous_V1 - proxy_type */;
            return _toStringProxyType_V1(
                &m->basic.proxy_anonymous_V1.proxy_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_anonymous_V1 - delay */;
            return _toStringBlockNumber(
                &m->basic.proxy_anonymous_V1.delay,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* proxy_anonymous_V1 - index */;
            return _toStringu16(
                &m->basic.proxy_anonymous_V1.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6917: /* module 27 call 5 */
        switch (itemIdx) {
        case 0: /* proxy_kill_anonymous_V1 - spawner */;
            return _toStringAccountId_V1(
                &m->basic.proxy_kill_anonymous_V1.spawner,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_kill_anonymous_V1 - proxy_type */;
            return _toStringProxyType_V1(
                &m->basic.proxy_kill_anonymous_V1.proxy_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* proxy_kill_anonymous_V1 - index */;
            return _toStringu16(
                &m->basic.proxy_kill_anonymous_V1.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* proxy_kill_anonymous_V1 - height */;
            return _toStringCompactBlockNumber(
                &m->basic.proxy_kill_anonymous_V1.height,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* proxy_kill_anonymous_V1 - ext_index */;
            return _toStringCompactu32(
                &m->basic.proxy_kill_anonymous_V1.ext_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6918: /* module 27 call 6 */
        switch (itemIdx) {
        case 0: /* proxy_announce_V1 - real */;
            return _toStringAccountId_V1(
                &m->basic.proxy_announce_V1.real,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_announce_V1 - call_hash */;
            return _toStringCallHashOf_V1(
                &m->basic.proxy_announce_V1.call_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6919: /* module 27 call 7 */
        switch (itemIdx) {
        case 0: /* proxy_remove_announcement_V1 - real */;
            return _toStringAccountId_V1(
                &m->basic.proxy_remove_announcement_V1.real,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_remove_announcement_V1 - call_hash */;
            return _toStringCallHashOf_V1(
                &m->basic.proxy_remove_announcement_V1.call_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6920: /* module 27 call 8 */
        switch (itemIdx) {
        case 0: /* proxy_reject_announcement_V1 - delegate */;
            return _toStringAccountId_V1(
                &m->basic.proxy_reject_announcement_V1.delegate,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_reject_announcement_V1 - call_hash */;
            return _toStringCallHashOf_V1(
                &m->basic.proxy_reject_announcement_V1.call_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6921: /* module 27 call 9 */
        switch (itemIdx) {
        case 0: /* proxy_proxy_announced_V1 - delegate */;
            return _toStringAccountId_V1(
                &m->basic.proxy_proxy_announced_V1.delegate,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_proxy_announced_V1 - real */;
            return _toStringAccountId_V1(
                &m->basic.proxy_proxy_announced_V1.real,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* proxy_proxy_announced_V1 - force_proxy_type */;
            return _toStringOptionProxyType_V1(
                &m->basic.proxy_proxy_announced_V1.force_proxy_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* proxy_proxy_announced_V1 - call */;
            return _toStringCall(
                &m->basic.proxy_proxy_announced_V1.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7168: /* module 28 call 0 */
        switch (itemIdx) {
        case 0: /* multisig_as_multi_threshold_1_V1 - other_signatories */;
            return _toStringVecAccountId_V1(
                &m->basic.multisig_as_multi_threshold_1_V1.other_signatories,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_as_multi_threshold_1_V1 - call */;
            return _toStringCall(
                &m->basic.multisig_as_multi_threshold_1_V1.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7169: /* module 28 call 1 */
        switch (itemIdx) {
        case 0: /* multisig_as_multi_V1 - threshold */;
            return _toStringu16(
                &m->basic.multisig_as_multi_V1.threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_as_multi_V1 - other_signatories */;
            return _toStringVecAccountId_V1(
                &m->basic.multisig_as_multi_V1.other_signatories,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* multisig_as_multi_V1 - maybe_timepoint */;
            return _toStringOptionTimepoint_V1(
                &m->basic.multisig_as_multi_V1.maybe_timepoint,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* multisig_as_multi_V1 - call */;
            return _toStringOpaqueCall_V1(
                &m->basic.multisig_as_multi_V1.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* multisig_as_multi_V1 - store_call */;
            return _toStringbool(
                &m->basic.multisig_as_multi_V1.store_call,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 5: /* multisig_as_multi_V1 - max_weight */;
            return _toStringWeight_V1(
                &m->basic.multisig_as_multi_V1.max_weight,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7170: /* module 28 call 2 */
        switch (itemIdx) {
        case 0: /* multisig_approve_as_multi_V1 - threshold */;
            return _toStringu16(
                &m->basic.multisig_approve_as_multi_V1.threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_approve_as_multi_V1 - other_signatories */;
            return _toStringVecAccountId_V1(
                &m->basic.multisig_approve_as_multi_V1.other_signatories,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* multisig_approve_as_multi_V1 - maybe_timepoint */;
            return _toStringOptionTimepoint_V1(
                &m->basic.multisig_approve_as_multi_V1.maybe_timepoint,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* multisig_approve_as_multi_V1 - call_hash */;
            return _toStringu8_array_32_V1(
                &m->basic.multisig_approve_as_multi_V1.call_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* multisig_approve_as_multi_V1 - max_weight */;
            return _toStringWeight_V1(
                &m->basic.multisig_approve_as_multi_V1.max_weight,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7171: /* module 28 call 3 */
        switch (itemIdx) {
        case 0: /* multisig_cancel_as_multi_V1 - threshold */;
            return _toStringu16(
                &m->basic.multisig_cancel_as_multi_V1.threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_cancel_as_multi_V1 - other_signatories */;
            return _toStringVecAccountId_V1(
                &m->basic.multisig_cancel_as_multi_V1.other_signatories,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* multisig_cancel_as_multi_V1 - timepoint */;
            return _toStringTimepoint_V1(
                &m->basic.multisig_cancel_as_multi_V1.timepoint,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* multisig_cancel_as_multi_V1 - call_hash */;
            return _toStringu8_array_32_V1(
                &m->basic.multisig_cancel_as_multi_V1.call_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7424: /* module 29 call 0 */
        switch (itemIdx) {
        case 0: /* assets_create_V1 - id */;
            return _toStringCompactAssetId_V1(
                &m->basic.assets_create_V1.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_create_V1 - admin */;
            return _toStringLookupSource_V1(
                &m->basic.assets_create_V1.admin,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* assets_create_V1 - max_zombies */;
            return _toStringu32(
                &m->basic.assets_create_V1.max_zombies,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* assets_create_V1 - min_balance */;
            return _toStringTAssetBalance_V1(
                &m->basic.assets_create_V1.min_balance,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7425: /* module 29 call 1 */
        switch (itemIdx) {
        case 0: /* assets_force_create_V1 - id */;
            return _toStringCompactAssetId_V1(
                &m->basic.assets_force_create_V1.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_force_create_V1 - owner */;
            return _toStringLookupSource_V1(
                &m->basic.assets_force_create_V1.owner,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* assets_force_create_V1 - max_zombies */;
            return _toStringCompactu32(
                &m->basic.assets_force_create_V1.max_zombies,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* assets_force_create_V1 - min_balance */;
            return _toStringCompactTAssetBalance_V1(
                &m->basic.assets_force_create_V1.min_balance,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7426: /* module 29 call 2 */
        switch (itemIdx) {
        case 0: /* assets_destroy_V1 - id */;
            return _toStringCompactAssetId_V1(
                &m->basic.assets_destroy_V1.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_destroy_V1 - zombies_witness */;
            return _toStringCompactu32(
                &m->basic.assets_destroy_V1.zombies_witness,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7427: /* module 29 call 3 */
        switch (itemIdx) {
        case 0: /* assets_force_destroy_V1 - id */;
            return _toStringCompactAssetId_V1(
                &m->basic.assets_force_destroy_V1.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_force_destroy_V1 - zombies_witness */;
            return _toStringCompactu32(
                &m->basic.assets_force_destroy_V1.zombies_witness,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7428: /* module 29 call 4 */
        switch (itemIdx) {
        case 0: /* assets_mint_V1 - id */;
            return _toStringCompactAssetId_V1(
                &m->basic.assets_mint_V1.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_mint_V1 - beneficiary */;
            return _toStringLookupSource_V1(
                &m->basic.assets_mint_V1.beneficiary,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* assets_mint_V1 - amount */;
            return _toStringCompactTAssetBalance_V1(
                &m->basic.assets_mint_V1.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7429: /* module 29 call 5 */
        switch (itemIdx) {
        case 0: /* assets_burn_V1 - id */;
            return _toStringCompactAssetId_V1(
                &m->basic.assets_burn_V1.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_burn_V1 - who */;
            return _toStringLookupSource_V1(
                &m->basic.assets_burn_V1.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* assets_burn_V1 - amount */;
            return _toStringCompactTAssetBalance_V1(
                &m->basic.assets_burn_V1.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7430: /* module 29 call 6 */
        switch (itemIdx) {
        case 0: /* assets_transfer_V1 - id */;
            return _toStringCompactAssetId_V1(
                &m->basic.assets_transfer_V1.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_transfer_V1 - target */;
            return _toStringLookupSource_V1(
                &m->basic.assets_transfer_V1.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* assets_transfer_V1 - amount */;
            return _toStringCompactTAssetBalance_V1(
                &m->basic.assets_transfer_V1.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7431: /* module 29 call 7 */
        switch (itemIdx) {
        case 0: /* assets_force_transfer_V1 - id */;
            return _toStringCompactAssetId_V1(
                &m->basic.assets_force_transfer_V1.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_force_transfer_V1 - source */;
            return _toStringLookupSource_V1(
                &m->basic.assets_force_transfer_V1.source,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* assets_force_transfer_V1 - dest */;
            return _toStringLookupSource_V1(
                &m->basic.assets_force_transfer_V1.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* assets_force_transfer_V1 - amount */;
            return _toStringCompactTAssetBalance_V1(
                &m->basic.assets_force_transfer_V1.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7432: /* module 29 call 8 */
        switch (itemIdx) {
        case 0: /* assets_freeze_V1 - id */;
            return _toStringCompactAssetId_V1(
                &m->basic.assets_freeze_V1.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_freeze_V1 - who */;
            return _toStringLookupSource_V1(
                &m->basic.assets_freeze_V1.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7433: /* module 29 call 9 */
        switch (itemIdx) {
        case 0: /* assets_thaw_V1 - id */;
            return _toStringCompactAssetId_V1(
                &m->basic.assets_thaw_V1.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_thaw_V1 - who */;
            return _toStringLookupSource_V1(
                &m->basic.assets_thaw_V1.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7434: /* module 29 call 10 */
        switch (itemIdx) {
        case 0: /* assets_transfer_ownership_V1 - id */;
            return _toStringCompactAssetId_V1(
                &m->basic.assets_transfer_ownership_V1.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_transfer_ownership_V1 - new_owner */;
            return _toStringLookupSource_V1(
                &m->basic.assets_transfer_ownership_V1.new_owner,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7435: /* module 29 call 11 */
        switch (itemIdx) {
        case 0: /* assets_set_team_V1 - id */;
            return _toStringCompactAssetId_V1(
                &m->basic.assets_set_team_V1.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_set_team_V1 - issuer */;
            return _toStringLookupSource_V1(
                &m->basic.assets_set_team_V1.issuer,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* assets_set_team_V1 - admin */;
            return _toStringLookupSource_V1(
                &m->basic.assets_set_team_V1.admin,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* assets_set_team_V1 - freezer */;
            return _toStringLookupSource_V1(
                &m->basic.assets_set_team_V1.freezer,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7436: /* module 29 call 12 */
        switch (itemIdx) {
        case 0: /* assets_set_max_zombies_V1 - id */;
            return _toStringCompactAssetId_V1(
                &m->basic.assets_set_max_zombies_V1.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_set_max_zombies_V1 - max_zombies */;
            return _toStringCompactu32(
                &m->basic.assets_set_max_zombies_V1.max_zombies,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8192: /* module 32 call 0 */
        switch (itemIdx) {
        case 0: /* treasuryreward_set_current_payout_V1 - payout */;
            return _toStringBalanceOf(
                &m->basic.treasuryreward_set_current_payout_V1.payout,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8193: /* module 32 call 1 */
        switch (itemIdx) {
        case 0: /* treasuryreward_set_minting_interval_V1 - interval */;
            return _toStringBlockNumber(
                &m->basic.treasuryreward_set_minting_interval_V1.interval,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8448: /* module 33 call 0 */
        switch (itemIdx) {
        case 0: /* ethereum_transact_V1 - transaction */;
            return _toStringEthTransaction_V1(
                &m->basic.ethereum_transact_V1.transaction,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8704: /* module 34 call 0 */
        switch (itemIdx) {
        case 0: /* evm_withdraw_V1 - address */;
            return _toStringH160_V1(
                &m->basic.evm_withdraw_V1.address,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* evm_withdraw_V1 - value */;
            return _toStringBalanceOf(
                &m->basic.evm_withdraw_V1.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8705: /* module 34 call 1 */
        switch (itemIdx) {
        case 0: /* evm_call_V1 - source */;
            return _toStringH160_V1(
                &m->basic.evm_call_V1.source,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* evm_call_V1 - target */;
            return _toStringH160_V1(
                &m->basic.evm_call_V1.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* evm_call_V1 - input */;
            return _toStringBytes(
                &m->basic.evm_call_V1.input,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* evm_call_V1 - value */;
            return _toStringU256_V1(
                &m->basic.evm_call_V1.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* evm_call_V1 - gas_limit */;
            return _toStringu32(
                &m->basic.evm_call_V1.gas_limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 5: /* evm_call_V1 - gas_price */;
            return _toStringU256_V1(
                &m->basic.evm_call_V1.gas_price,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 6: /* evm_call_V1 - nonce */;
            return _toStringOptionU256_V1(
                &m->basic.evm_call_V1.nonce,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8706: /* module 34 call 2 */
        switch (itemIdx) {
        case 0: /* evm_create_V1 - source */;
            return _toStringH160_V1(
                &m->basic.evm_create_V1.source,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* evm_create_V1 - init */;
            return _toStringBytes(
                &m->basic.evm_create_V1.init,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* evm_create_V1 - value */;
            return _toStringU256_V1(
                &m->basic.evm_create_V1.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* evm_create_V1 - gas_limit */;
            return _toStringu32(
                &m->basic.evm_create_V1.gas_limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* evm_create_V1 - gas_price */;
            return _toStringU256_V1(
                &m->basic.evm_create_V1.gas_price,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 5: /* evm_create_V1 - nonce */;
            return _toStringOptionU256_V1(
                &m->basic.evm_create_V1.nonce,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8707: /* module 34 call 3 */
        switch (itemIdx) {
        case 0: /* evm_create2_V1 - source */;
            return _toStringH160_V1(
                &m->basic.evm_create2_V1.source,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* evm_create2_V1 - init */;
            return _toStringBytes(
                &m->basic.evm_create2_V1.init,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* evm_create2_V1 - salt */;
            return _toStringH256_V1(
                &m->basic.evm_create2_V1.salt,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* evm_create2_V1 - value */;
            return _toStringU256_V1(
                &m->basic.evm_create2_V1.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* evm_create2_V1 - gas_limit */;
            return _toStringu32(
                &m->basic.evm_create2_V1.gas_limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 5: /* evm_create2_V1 - gas_price */;
            return _toStringU256_V1(
                &m->basic.evm_create2_V1.gas_price,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 6: /* evm_create2_V1 - nonce */;
            return _toStringOptionU256_V1(
                &m->basic.evm_create2_V1.nonce,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8960: /* module 35 call 0 */
        switch (itemIdx) {
        case 0: /* chainbridge_set_threshold_V1 - threshold */;
            return _toStringu32(
                &m->basic.chainbridge_set_threshold_V1.threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8961: /* module 35 call 1 */
        switch (itemIdx) {
        case 0: /* chainbridge_set_resource_V1 - id */;
            return _toStringResourceId_V1(
                &m->basic.chainbridge_set_resource_V1.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* chainbridge_set_resource_V1 - method */;
            return _toStringBytes(
                &m->basic.chainbridge_set_resource_V1.method,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8962: /* module 35 call 2 */
        switch (itemIdx) {
        case 0: /* chainbridge_remove_resource_V1 - id */;
            return _toStringResourceId_V1(
                &m->basic.chainbridge_remove_resource_V1.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8963: /* module 35 call 3 */
        switch (itemIdx) {
        case 0: /* chainbridge_whitelist_chain_V1 - id */;
            return _toStringChainId_V1(
                &m->basic.chainbridge_whitelist_chain_V1.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8964: /* module 35 call 4 */
        switch (itemIdx) {
        case 0: /* chainbridge_add_relayer_V1 - v */;
            return _toStringAccountId_V1(
                &m->basic.chainbridge_add_relayer_V1.v,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8965: /* module 35 call 5 */
        switch (itemIdx) {
        case 0: /* chainbridge_remove_relayer_V1 - v */;
            return _toStringAccountId_V1(
                &m->basic.chainbridge_remove_relayer_V1.v,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8966: /* module 35 call 6 */
        switch (itemIdx) {
        case 0: /* chainbridge_acknowledge_proposal_V1 - nonce */;
            return _toStringDepositNonce_V1(
                &m->basic.chainbridge_acknowledge_proposal_V1.nonce,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* chainbridge_acknowledge_proposal_V1 - src_id */;
            return _toStringChainId_V1(
                &m->basic.chainbridge_acknowledge_proposal_V1.src_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* chainbridge_acknowledge_proposal_V1 - r_id */;
            return _toStringResourceId_V1(
                &m->basic.chainbridge_acknowledge_proposal_V1.r_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* chainbridge_acknowledge_proposal_V1 - call */;
            return _toStringProposal(
                &m->basic.chainbridge_acknowledge_proposal_V1.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8967: /* module 35 call 7 */
        switch (itemIdx) {
        case 0: /* chainbridge_reject_proposal_V1 - nonce */;
            return _toStringDepositNonce_V1(
                &m->basic.chainbridge_reject_proposal_V1.nonce,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* chainbridge_reject_proposal_V1 - src_id */;
            return _toStringChainId_V1(
                &m->basic.chainbridge_reject_proposal_V1.src_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* chainbridge_reject_proposal_V1 - r_id */;
            return _toStringResourceId_V1(
                &m->basic.chainbridge_reject_proposal_V1.r_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* chainbridge_reject_proposal_V1 - call */;
            return _toStringProposal(
                &m->basic.chainbridge_reject_proposal_V1.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8968: /* module 35 call 8 */
        switch (itemIdx) {
        case 0: /* chainbridge_eval_vote_state_V1 - nonce */;
            return _toStringDepositNonce_V1(
                &m->basic.chainbridge_eval_vote_state_V1.nonce,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* chainbridge_eval_vote_state_V1 - src_id */;
            return _toStringChainId_V1(
                &m->basic.chainbridge_eval_vote_state_V1.src_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* chainbridge_eval_vote_state_V1 - prop */;
            return _toStringProposal(
                &m->basic.chainbridge_eval_vote_state_V1.prop,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9216: /* module 36 call 0 */
        switch (itemIdx) {
        case 0: /* edgebridge_transfer_native_V1 - amount */;
            return _toStringBalanceOf(
                &m->basic.edgebridge_transfer_native_V1.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* edgebridge_transfer_native_V1 - recipient */;
            return _toStringBytes(
                &m->basic.edgebridge_transfer_native_V1.recipient,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* edgebridge_transfer_native_V1 - dest_id */;
            return _toStringChainId_V1(
                &m->basic.edgebridge_transfer_native_V1.dest_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9217: /* module 36 call 1 */
        switch (itemIdx) {
        case 0: /* edgebridge_transfer_V1 - to */;
            return _toStringAccountId_V1(
                &m->basic.edgebridge_transfer_V1.to,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* edgebridge_transfer_V1 - amount */;
            return _toStringBalanceOf(
                &m->basic.edgebridge_transfer_V1.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9472: /* module 37 call 0 */
        switch (itemIdx) {
        case 0: /* bounties_propose_bounty_V1 - value */;
            return _toStringCompactBalanceOf(
                &m->basic.bounties_propose_bounty_V1.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* bounties_propose_bounty_V1 - description */;
            return _toStringBytes(
                &m->basic.bounties_propose_bounty_V1.description,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9473: /* module 37 call 1 */
        switch (itemIdx) {
        case 0: /* bounties_approve_bounty_V1 - bounty_id */;
            return _toStringCompactBountyIndex_V1(
                &m->basic.bounties_approve_bounty_V1.bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9474: /* module 37 call 2 */
        switch (itemIdx) {
        case 0: /* bounties_propose_curator_V1 - bounty_id */;
            return _toStringCompactBountyIndex_V1(
                &m->basic.bounties_propose_curator_V1.bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* bounties_propose_curator_V1 - curator */;
            return _toStringLookupSource_V1(
                &m->basic.bounties_propose_curator_V1.curator,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* bounties_propose_curator_V1 - fee */;
            return _toStringCompactBalanceOf(
                &m->basic.bounties_propose_curator_V1.fee,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9475: /* module 37 call 3 */
        switch (itemIdx) {
        case 0: /* bounties_unassign_curator_V1 - bounty_id */;
            return _toStringCompactBountyIndex_V1(
                &m->basic.bounties_unassign_curator_V1.bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9476: /* module 37 call 4 */
        switch (itemIdx) {
        case 0: /* bounties_accept_curator_V1 - bounty_id */;
            return _toStringCompactBountyIndex_V1(
                &m->basic.bounties_accept_curator_V1.bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9477: /* module 37 call 5 */
        switch (itemIdx) {
        case 0: /* bounties_award_bounty_V1 - bounty_id */;
            return _toStringCompactBountyIndex_V1(
                &m->basic.bounties_award_bounty_V1.bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* bounties_award_bounty_V1 - beneficiary */;
            return _toStringLookupSource_V1(
                &m->basic.bounties_award_bounty_V1.beneficiary,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9478: /* module 37 call 6 */
        switch (itemIdx) {
        case 0: /* bounties_claim_bounty_V1 - bounty_id */;
            return _toStringCompactBountyIndex_V1(
                &m->basic.bounties_claim_bounty_V1.bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9479: /* module 37 call 7 */
        switch (itemIdx) {
        case 0: /* bounties_close_bounty_V1 - bounty_id */;
            return _toStringCompactBountyIndex_V1(
                &m->basic.bounties_close_bounty_V1.bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9480: /* module 37 call 8 */
        switch (itemIdx) {
        case 0: /* bounties_extend_bounty_expiry_V1 - bounty_id */;
            return _toStringCompactBountyIndex_V1(
                &m->basic.bounties_extend_bounty_expiry_V1.bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* bounties_extend_bounty_expiry_V1 - _remark */;
            return _toStringBytes(
                &m->basic.bounties_extend_bounty_expiry_V1._remark,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9728: /* module 38 call 0 */
        switch (itemIdx) {
        case 0: /* tips_report_awesome_V1 - reason */;
            return _toStringBytes(
                &m->basic.tips_report_awesome_V1.reason,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* tips_report_awesome_V1 - who */;
            return _toStringAccountId_V1(
                &m->basic.tips_report_awesome_V1.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9729: /* module 38 call 1 */
        switch (itemIdx) {
        case 0: /* tips_retract_tip_V1 - hash */;
            return _toStringHash(
                &m->basic.tips_retract_tip_V1.hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9730: /* module 38 call 2 */
        switch (itemIdx) {
        case 0: /* tips_tip_new_V1 - reason */;
            return _toStringBytes(
                &m->basic.tips_tip_new_V1.reason,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* tips_tip_new_V1 - who */;
            return _toStringAccountId_V1(
                &m->basic.tips_tip_new_V1.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* tips_tip_new_V1 - tip_value */;
            return _toStringCompactBalanceOf(
                &m->basic.tips_tip_new_V1.tip_value,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9731: /* module 38 call 3 */
        switch (itemIdx) {
        case 0: /* tips_tip_V1 - hash */;
            return _toStringHash(
                &m->basic.tips_tip_V1.hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* tips_tip_V1 - tip_value */;
            return _toStringCompactBalanceOf(
                &m->basic.tips_tip_V1.tip_value,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9732: /* module 38 call 4 */
        switch (itemIdx) {
        case 0: /* tips_close_tip_V1 - hash */;
            return _toStringHash(
                &m->basic.tips_close_tip_V1.hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9733: /* module 38 call 5 */
        switch (itemIdx) {
        case 0: /* tips_slash_tip_V1 - hash */;
            return _toStringHash(
                &m->basic.tips_slash_tip_V1.hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
#endif
    default:
        return parser_ok;
    }

    return parser_ok;
}

bool _getMethod_ItemIsExpert_V1(uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 2051: // Staking:Withdraw Unbonded
        switch (itemIdx) {
        case 0: // Num slashing spans
            return true;
        default:
            return false;
        }
    case 2063: // Staking:Force unstake
        switch (itemIdx) {
        case 1: // Num slashing spans
            return true;
        default:
            return false;
        }
    case 2069: // Staking:Reap stash
        switch (itemIdx) {
        case 1: // Num slashing spans
            return true;
        default:
            return false;
        }
    case 8705: // EVM:Call
        switch (itemIdx) {
        case 6: // Nonce
            return true;
        default:
            return false;
        }
    case 8706: // EVM:Create
        switch (itemIdx) {
        case 5: // Nonce
            return true;
        default:
            return false;
        }
    case 8707: // EVM:Create2
        switch (itemIdx) {
        case 6: // Nonce
            return true;
        default:
            return false;
        }
    case 8966: // ChainBridge:Acknowledge proposal
        switch (itemIdx) {
        case 0: // Nonce
            return true;
        default:
            return false;
        }
    case 8967: // ChainBridge:Reject proposal
        switch (itemIdx) {
        case 0: // Nonce
            return true;
        default:
            return false;
        }
    case 8968: // ChainBridge:Eval vote state
        switch (itemIdx) {
        case 0: // Nonce
            return true;
        default:
            return false;
        }

    default:
        return false;
    }
}

bool _getMethod_IsNestingSupported_V1(uint8_t moduleIdx, uint8_t callIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 0: // System:Fill block
    case 1: // System:Remark
    case 2: // System:Set heap pages
    case 3: // System:Set code
    case 4: // System:Set code without checks
    case 5: // System:Set changes trie config
    case 6: // System:Set storage
    case 7: // System:Kill storage
    case 8: // System:Kill prefix
    case 9: // System:Suicide
    case 256: // Utility:Batch
    case 257: // Utility:As derivative
    case 258: // Utility:Batch all
    case 768: // Timestamp:Set
    case 1024: // Authorship:Set uncles
    case 1280: // Indices:Claim
    case 1281: // Indices:Transfer
    case 1282: // Indices:Free
    case 1283: // Indices:Force transfer
    case 1284: // Indices:Freeze
    case 1536: // Balances:Transfer
    case 1537: // Balances:Set balance
    case 1538: // Balances:Force transfer
    case 1539: // Balances:Transfer keep alive
    case 2048: // Staking:Bond
    case 2049: // Staking:Bond extra
    case 2050: // Staking:Unbond
    case 2051: // Staking:Withdraw Unbonded
    case 2052: // Staking:Validate
    case 2053: // Staking:Nominate
    case 2054: // Staking:Chill
    case 2055: // Staking:Set payee
    case 2056: // Staking:Set controller
    case 2057: // Staking:Set validator count
    case 2058: // Staking:Increase validator count
    case 2059: // Staking:Scale validator count
    case 2060: // Staking:Force no eras
    case 2061: // Staking:Force new era
    case 2062: // Staking:Set invulnerables
    case 2063: // Staking:Force unstake
    case 2064: // Staking:Force new era always
    case 2065: // Staking:Cancel deferred slash
    case 2066: // Staking:Payout stakers
    case 2067: // Staking:Rebond
    case 2068: // Staking:Set history depth
    case 2069: // Staking:Reap stash
    case 2070: // Staking:Submit election solution
    case 2071: // Staking:Submit election solution unsigned
    case 2304: // Session:Set keys
    case 2305: // Session:Purge keys
    case 2560: // Democracy:Propose
    case 2561: // Democracy:Second
    case 2562: // Democracy:Vote
    case 2563: // Democracy:Emergency cancel
    case 2564: // Democracy:External propose
    case 2565: // Democracy:External propose majority
    case 2566: // Democracy:External propose default
    case 2567: // Democracy:Fast track
    case 2568: // Democracy:Veto external
    case 2569: // Democracy:Cancel referendum
    case 2570: // Democracy:Cancel queued
    case 2571: // Democracy:Delegate
    case 2572: // Democracy:Undelegate
    case 2573: // Democracy:Clear public proposals
    case 2574: // Democracy:Note preimage
    case 2575: // Democracy:Note preimage operational
    case 2576: // Democracy:Note imminent preimage
    case 2577: // Democracy:Note imminent preimage operational
    case 2578: // Democracy:Reap preimage
    case 2579: // Democracy:Unlock
    case 2580: // Democracy:Remove vote
    case 2581: // Democracy:Remove other vote
    case 2582: // Democracy:Enact proposal
    case 2583: // Democracy:Blacklist
    case 2584: // Democracy:Cancel proposal
    case 2816: // Council:Set members
    case 2817: // Council:Execute
    case 2818: // Council:Propose
    case 2819: // Council:Vote
    case 2820: // Council:Close
    case 2821: // Council:Disapprove proposal
    case 3072: // Elections:Vote
    case 3073: // Elections:Remove voter
    case 3074: // Elections:Report defunct voter
    case 3075: // Elections:Submit candidacy
    case 3076: // Elections:Renounce candidacy
    case 3077: // Elections:Remove member
    case 3584: // Grandpa:Report equivocation
    case 3585: // Grandpa:Report equivocation unsigned
    case 3586: // Grandpa:Note stalled
    case 3840: // Treasury:Propose spend
    case 3841: // Treasury:Reject proposal
    case 3842: // Treasury:Approve proposal
    case 4096: // Contracts:Update schedule
    case 4097: // Contracts:Put code
    case 4098: // Contracts:Call
    case 4099: // Contracts:Instantiate
    case 4100: // Contracts:Claim surcharge
    case 4352: // Sudo:Sudo
    case 4353: // Sudo:Sudo unchecked weight
    case 4354: // Sudo:Set key
    case 4355: // Sudo:Sudo as
    case 4608: // ImOnline:Heartbeat
    case 5888: // Identity:Add registrar
    case 5889: // Identity:Set identity
    case 5890: // Identity:Set subs
    case 5891: // Identity:Clear identity
    case 5892: // Identity:Request judgement
    case 5893: // Identity:Cancel request
    case 5894: // Identity:Set fee
    case 5895: // Identity:Set account id
    case 5896: // Identity:Set fields
    case 5897: // Identity:Provide judgement
    case 5898: // Identity:Kill identity
    case 5899: // Identity:Add sub
    case 5900: // Identity:Rename sub
    case 5901: // Identity:Remove sub
    case 5902: // Identity:Quit sub
    case 6144: // Recovery:As recovered
    case 6145: // Recovery:Set recovered
    case 6146: // Recovery:Create recovery
    case 6147: // Recovery:Initiate recovery
    case 6148: // Recovery:Vouch recovery
    case 6149: // Recovery:Claim recovery
    case 6150: // Recovery:Close recovery
    case 6151: // Recovery:Remove recovery
    case 6152: // Recovery:Cancel recovered
    case 6400: // Vesting:Vest
    case 6401: // Vesting:Vest other
    case 6402: // Vesting:Vested transfer
    case 6403: // Vesting:Force vested transfer
    case 6656: // Scheduler:Schedule
    case 6657: // Scheduler:Cancel
    case 6658: // Scheduler:Schedule named
    case 6659: // Scheduler:Cancel named
    case 6660: // Scheduler:Schedule after
    case 6661: // Scheduler:Schedule named after
    case 6912: // Proxy:Proxy
    case 6913: // Proxy:Add proxy
    case 6914: // Proxy:Remove proxy
    case 6915: // Proxy:Remove proxies
    case 6916: // Proxy:Anonymous
    case 6917: // Proxy:Kill anonymous
    case 6918: // Proxy:Announce
    case 6919: // Proxy:Remove announcement
    case 6920: // Proxy:Reject announcement
    case 6921: // Proxy:Proxy announced
    case 7168: // Multisig:As multi threshold 1
    case 7169: // Multisig:As multi
    case 7170: // Multisig:Approve as multi
    case 7171: // Multisig:Cancel as multi
    case 7424: // Assets:Create
    case 7425: // Assets:Force create
    case 7426: // Assets:Destroy
    case 7427: // Assets:Force destroy
    case 7428: // Assets:Mint
    case 7429: // Assets:Burn
    case 7430: // Assets:Transfer
    case 7431: // Assets:Force transfer
    case 7432: // Assets:Freeze
    case 7433: // Assets:Thaw
    case 7434: // Assets:Transfer ownership
    case 7435: // Assets:Set team
    case 7436: // Assets:Set max zombies
    case 8192: // TreasuryReward:Set current payout
    case 8193: // TreasuryReward:Set minting interval
    case 8448: // Ethereum:Transact
    case 8704: // EVM:Withdraw
    case 8705: // EVM:Call
    case 8706: // EVM:Create
    case 8707: // EVM:Create2
    case 8960: // ChainBridge:Set threshold
    case 8961: // ChainBridge:Set resource
    case 8962: // ChainBridge:Remove resource
    case 8963: // ChainBridge:Whitelist chain
    case 8964: // ChainBridge:Add relayer
    case 8965: // ChainBridge:Remove relayer
    case 8966: // ChainBridge:Acknowledge proposal
    case 8967: // ChainBridge:Reject proposal
    case 8968: // ChainBridge:Eval vote state
    case 9216: // EdgeBridge:Transfer native
    case 9217: // EdgeBridge:Transfer
    case 9472: // Bounties:Propose bounty
    case 9473: // Bounties:Approve bounty
    case 9474: // Bounties:Propose curator
    case 9475: // Bounties:Unassign curator
    case 9476: // Bounties:Accept curator
    case 9477: // Bounties:Award bounty
    case 9478: // Bounties:Claim bounty
    case 9479: // Bounties:Close bounty
    case 9480: // Bounties:Extend bounty expiry
    case 9728: // Tips:Report awesome
    case 9729: // Tips:Retract tip
    case 9730: // Tips:Tip new
    case 9731: // Tips:Tip
    case 9732: // Tips:Close tip
    case 9733: // Tips:Slash tip
        return false;
    default:
        return true;
    }
}
