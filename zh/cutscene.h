/**
*  One way of using these:
*
*  if (zh_cscmd_get_actor_action(globalCtx, 1) != NULL){
*    this->thing = zh_cscmd_get_action_id(globalCtx, 1);
*    zh_cscmd_move_actor(&this->actor, globalCtx, 1);
*  }
*
*/

static inline z64_cutscene_actor_action_t* zh_cscmd_get_actor_action(z64_global_t* globalCtx, int32_t npc_slot_id)
{
  if (globalCtx->cutscene.state != 0)
    return globalCtx->cutscene.npc_action[npc_slot_id];
  return NULL;
}

static inline int32_t zh_cscmd_get_start_frame(z64_global_t* globalCtx, int32_t npc_slot_id)
{
  z64_cutscene_actor_action_t* cscmd_slot = zh_cscmd_get_actor_action(globalCtx, npc_slot_id);

  if (cscmd_slot != NULL)
    return cscmd_slot->start_frame;
}

static inline int16_t zh_cscmd_get_action_id(z64_global_t* globalCtx, int32_t npc_slot_id)
{
  z64_cutscene_actor_action_t* cscmd_slot = zh_cscmd_get_actor_action(globalCtx, npc_slot_id);

  if (cscmd_slot != NULL && cscmd_slot->action != 0)
    return cscmd_slot->action;
}

static inline float zh_cscmd_timer(z64_cutscene_actor_action_t* cscmd_slot, z64_global_t* globalCtx) {
  int32_t cutscene_frames = globalCtx->cutscene.frame;
  if ((cutscene_frames < cscmd_slot->end_frame) && (cscmd_slot->end_frame - cscmd_slot->start_frame > 0))
    return (z_coss(((cutscene_frames - cscmd_slot->start_frame) / (float)(cscmd_slot->end_frame - cscmd_slot->start_frame)) * 32768.0f) * -0.5f) + 0.5f;
  return 1.0f;
}

static inline float zh_cscmd_move_axis(float timer, int32_t start_pos_axis, int32_t end_pos_axis) {
    return (((float)end_pos_axis - start_pos_axis) * timer) + start_pos_axis;
}

static inline void zh_cscmd_move_actor(z64_actor_t* this, z64_global_t* globalCtx, int32_t npc_slot_id) {
  vec3f_t* thisPos;
  float time;
  z64_cutscene_actor_action_t* cscmd_slot = zh_cscmd_get_actor_action(globalCtx, npc_slot_id);

  if (cscmd_slot != NULL) {
    time = zh_cscmd_timer(cscmd_slot, globalCtx);
    this->pos.x = zh_cscmd_move_axis(time, cscmd_slot->start_pos.x, cscmd_slot->end_pos.x);
    this->pos.y = zh_cscmd_move_axis(time, cscmd_slot->start_pos.y, cscmd_slot->end_pos.y);
    this->pos.z = zh_cscmd_move_axis(time, cscmd_slot->start_pos.z, cscmd_slot->end_pos.z);
  }
}
