#include "ac_fuusen.h"
#include "m_actor_dlftbls.h"
#include "m_actor_shadow.h"
#include "m_object.h"
#include "overlays/gamestates/ovl_play/m_play.h"
#include "overlays/actors/player_actor/m_player.h"

void aFSN_actor_ct(Actor* thisx, Game_Play* game_play);
void aFSN_actor_dt(Actor* thisx, Game_Play* game_play);
void aFSN_actor_move(Actor* thisx, Game_Play* game_play);
void aFSN_actor_draw(Actor* thisx, Game_Play* game_play);

#if 0
ActorProfile Fuusen_Profile = {
    /* */ ACTOR_FUUSEN,
    /* */ ACTOR_PART_7,
    /* */ ACTOR_FLAG_10,
    /* */ 0x0000,
    /* */ OBJECT_400,
    /* */ sizeof(Fuusen),
    /* */ aFSN_actor_ct,
    /* */ aFSN_actor_dt,
    /* */ aFSN_actor_move,
    /* */ aFSN_actor_draw,
    /* */ NULL,
};
#endif

extern void mAc_ActorShadowCircle(Actor*, LightsN*, Game_Play*);
extern f32 func_80072F9C_jp(PosRot*);
extern BaseAnimationR D_6000F44;
extern BaseSkeletonR D_6000F88;
extern xyz_t D_80AAE4D4_jp;

void aFSN_actor_ct(Actor* thisx, Game_Play* game_play) {
    Fuusen* this = (Fuusen*)thisx;
    SkeletonInfoR *skeletonInfo = &this->skeletonInfo;
    xyz_t sp34;
    f32 sp30;
    sp34 = D_80AAE4D4_jp;
    sp30 = func_80072F9C_jp(&this->actor.world);
    this->unk_184 = 0x3E8;
    cKF_SkeletonInfo_R_ct(skeletonInfo, &D_6000F88, &D_6000F44, this->jointTable, this->morphTable);
    cKF_SkeletonInfo_R_init_standard_repeat(skeletonInfo, Lib_SegmentedToVirtual(&D_6000F44), NULL);
    Shape_Info_init(&this->actor, 0.0f, mAc_ActorShadowCircle, 10.0f, 10.0f);
    this->actor.shape.unk_2C = 0;
    cKF_SkeletonInfo_R_play(skeletonInfo);
    skeletonInfo->frameControl.speed = 1.0f;
    xyz_t_move(&this->actor.scale, &sp34);
    this->actor.world.pos.y = sp30 + 200.0f;
    this->unk_1A0 = 110.0f;
    this->unk_178 = (void* ) game_play->objectExchangeBank.status[this->actor.unk_026].segment;
    this->actor.update = aFSN_actor_move;
    func_80AADEC4_jp(this, 0, game_play);
}

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Fuusen/ac_fuusen/aFSN_actor_dt.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Fuusen/ac_fuusen/func_80AAD270_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Fuusen/ac_fuusen/func_80AAD490_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Fuusen/ac_fuusen/func_80AAD4A0_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Fuusen/ac_fuusen/func_80AAD4DC_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Fuusen/ac_fuusen/func_80AAD580_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Fuusen/ac_fuusen/func_80AAD5A4_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Fuusen/ac_fuusen/func_80AADB9C_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Fuusen/ac_fuusen/func_80AADDA8_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Fuusen/ac_fuusen/func_80AADEC4_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Fuusen/ac_fuusen/func_80AADF10_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Fuusen/ac_fuusen/aFSN_actor_move.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Fuusen/ac_fuusen/func_80AAE10C_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Fuusen/ac_fuusen/aFSN_actor_draw.s")
