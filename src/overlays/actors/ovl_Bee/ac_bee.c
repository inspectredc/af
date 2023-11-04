#include "ac_bee.h"
#include "m_actor_dlftbls.h"
#include "m_object.h"
#include "overlays/gamestates/ovl_play/m_play.h"

void aBEE_actor_ct(Actor* thisx, Game_Play* game_play);
void func_80A93DD0_jp(Actor* thisx, Game_Play* game_play);
void aBEE_actor_move(Actor* thisx, Game_Play* game_play);
void aBEE_actor_draw(Actor* thisx, Game_Play* game_play);

#if 0
ActorProfile Bee_Profile = {
    /* */ ACTOR_BEE,
    /* */ ACTOR_PART_4,
    /* */ ACTOR_FLAG_10,
    /* */ 0x0000,
    /* */ OBJECT_392,
    /* */ sizeof(Bee),
    /* */ aBEE_actor_ct,
    /* */ func_80A93DD0_jp,
    /* */ aBEE_actor_move,
    /* */ aBEE_actor_draw,
    /* */ NULL,
};
#endif

void func_80A94450_jp(Actor*, s32, Game_Play*);          /* extern */
extern BaseAnimationR* D_60008E4;
extern BaseSkeletonR* D_6000928;
extern xyz_t D_80A94974_jp;

// #pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Bee/ac_bee/aBEE_actor_ct.s")
void aBEE_actor_ct(Actor* thisx, Game_Play* game_play) {
    Bee *this = thisx;
    SkeletonInfoR *tmp = &this->skeletonInfo;
    xyz_t sp34;
    sp34 = D_80A94974_jp;
    cKF_SkeletonInfo_R_ct(&this->skeletonInfo, &D_6000928, &D_60008E4, this->jointTable, this->morphTable);
    cKF_SkeletonInfo_R_init_standard_repeat(&this->skeletonInfo, Lib_SegmentedToVirtual(&D_60008E4), 0);
    tmp->frameControl.currentFrame = 90.0f;
    cKF_SkeletonInfo_R_play(tmp);
    tmp->frameControl.speed = 0.0f;
    this->unk_442 = -0x8000;
    this->unk_430 = 90.0f;
    xyz_t_move(&this->actor.scale, &sp34);
    this->unk_178 = (void *) game_play->objectExchangeBank.status[this->actor.unk_026].segment;
    this->actor.update = aBEE_actor_move;
    func_80A94450_jp(this, 0, game_play);
}

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Bee/ac_bee/func_80A93DD0_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Bee/ac_bee/func_80A93DE0_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Bee/ac_bee/func_80A93E38_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Bee/ac_bee/func_80A93E48_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Bee/ac_bee/func_80A93E6C_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Bee/ac_bee/func_80A93EFC_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Bee/ac_bee/func_80A94408_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Bee/ac_bee/func_80A94450_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Bee/ac_bee/func_80A9449C_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Bee/ac_bee/aBEE_actor_move.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Bee/ac_bee/aBEE_actor_draw.s")
