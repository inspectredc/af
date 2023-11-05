#include "ac_bee.h"
#include "m_actor_dlftbls.h"
#include "m_object.h"
#include "overlays/gamestates/ovl_play/m_play.h"
#include "overlays/actors/player_actor/m_player.h"

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

void func_80A94450_jp(Bee*, s32, Game_Play*);          /* extern */
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

// #pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Bee/ac_bee/func_80A93DD0_jp.s")
void func_80A93DD0_jp(Actor* thisx, Game_Play* game_play) {

}

// #pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Bee/ac_bee/func_80A93DE0_jp.s")
extern xyz_t D_80A94980_jp;

void func_80A93DE0_jp(Bee* this, Game_Play* game_play) {
    xyz_t sp1C;

    sp1C = D_80A94980_jp;
    xyz_t_move(&this->unk_420, &sp1C);
    common_data.unk107E6[0x253] = 1;
}

// #pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Bee/ac_bee/func_80A93E38_jp.s")
void func_80A93E38_jp(Bee* this, Game_Play* game_play) {

}

// #pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Bee/ac_bee/func_80A93E48_jp.s")
void func_80A93E48_jp(Bee* this, Game_Play* game_play) {
    
    this->actor.speed = 9.7f;
    this->actor.shape.rot.x = this->actor.shape.rot.z = 0;
}

// #pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Bee/ac_bee/func_80A93E6C_jp.s")
void func_80A93E6C_jp(Bee* this, Game_Play* game_play) {
    Player* player = get_player_actor_withoutCheck(game_play);
    s32 *var = &this->unk_438;
    this->unk_434 = player->actor.world.pos.y + 50.0f;
    this->unk_438 += 6;
    if (this->unk_438 >= 0xFF) {
        this->unk_438 = 0xFF;
    }
    this->actor.shape.rot.x = 0x7FFF;
    this->actor.shape.rot.z += 0x1000;
    if (*var == 0xFF) {
        func_80A94450_jp(this, 1, game_play);
    }
}

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Bee/ac_bee/func_80A93EFC_jp.s")

void func_80A94408_jp(Bee* this, Game_Play* game_play) {

    this->unk_420.x = 0.03f;
    this->unk_420.z = 0.03f;
    this->unk_420.y = 0.03f;
    this->unk_438 -= 0x1E;
    if (this->unk_438 < 0) {
        this->unk_438 = 0;
        Actor_delete(&this->actor);
    }
}

// #pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Bee/ac_bee/func_80A94450_jp.s")
extern void(*D_80A9498C_jp[])(Bee*, Game_Play*);
extern void(*D_80A94998_jp[]);

void func_80A94450_jp(Bee* this, s32 arg0, Game_Play* game_play) {
    this->unk_17C = arg0;
    this->unk_174 = D_80A94998_jp[this->unk_17C];
    D_80A9498C_jp[this->unk_17C](this, game_play);
}


// #pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Bee/ac_bee/func_80A9449C_jp.s")
void func_80A9449C_jp(Bee* this, Game_Play* game_play) {
    s32 pad;
    void* sp20;
    SkeletonInfoR* sp18;

    sp20 = game_play->objectExchangeBank.status[this->actor.unk_026].segment;
    if (sp20 != this->unk_178) {
        sp18 = &this->skeletonInfo;
        sp18->skeleton = Lib_SegmentedToVirtual(&D_6000928);
        sp18->animation = Lib_SegmentedToVirtual(&D_60008E4);
        this->unk_178 = sp20;
    }
}

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Bee/ac_bee/aBEE_actor_move.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Bee/ac_bee/aBEE_actor_draw.s")
