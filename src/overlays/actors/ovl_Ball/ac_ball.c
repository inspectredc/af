#include "ac_ball.h"
#include "m_actor_dlftbls.h"
#include "m_object.h"
#include "m_actor_shadow.h"
#include "overlays/gamestates/ovl_play/m_play.h"
#include "overlays/actors/player_actor/m_player.h"
#include "libc/math.h"

void aBALL_actor_ct(Actor* thisx, Game_Play* game_play);
void aBALL_actor_dt(Actor* thisx, Game_Play* game_play);
void aBALL_actor_move(Actor* thisx, Game_Play* game_play);
void aBALL_actor_draw(Actor* thisx, Game_Play* game_play);

void func_8096A86C_jp(void);

#if 0
ActorProfile Ball_Profile = {
    /* */ ACTOR_BALL,
    /* */ ACTOR_PART_4,
    /* */ ACTOR_FLAG_10,
    /* */ 0x8001,
    /* */ GAMEPLAY_KEEP,
    /* */ sizeof(Ball),
    /* */ aBALL_actor_ct,
    /* */ aBALL_actor_dt,
    /* */ aBALL_actor_move,
    /* */ aBALL_actor_draw,
    /* */ NULL,
};
#endif

extern ClObjPipe_Init aBALL_CoInfoData;
extern CollisionCheck_Status_Init aBALL_StatusData;

#if 0
ClObjPipe_Init aBALL_CoInfoData = { { OC1_1 | OC1_TYPE_8 | OC1_TYPE_10 | OC1_TYPE_20, OC2_TYPE_20, COLSHAPE_PIPE }, { ELEM_FLAG_1 }, { { 0xD, 0x1E, -0xA, { 0, 0, 0 } } }, };
CollisionCheck_Status_Init aBALL_StatusData = { 0, 0xD, 0x1E, -0xA, 100, };
#endif

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Ball/ac_ball/func_80968A10_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Ball/ac_ball/func_80968AF4_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Ball/ac_ball/func_80968B9C_jp.s")

extern Actor* B_8096A980_jp;
extern void mAc_ActorShadowEllipse(Actor*, LightsN*, Game_Play*);

void aBALL_actor_ct(Actor* thisx, Game_Play* game_play) {
    Ball* this = (Ball*)thisx;
    PosRot* sp34;

    B_8096A980_jp = &this->actor;
    if ((common_data.unk_10A6C.x == 0.0f) && (common_data.unk_10A6C.y == 0.0f) && (common_data.unk_10A6C.z == 0.0f)) {
        sp34 = &this->actor.world;
        if (func_80968B9C_jp(sp34) == 0) {
            sp34->pos = this->actor.home.pos;
        }
        common_data.unk_10A78 = (s8) (u32) (fqrand() * 3.0f);
        common_data.unk_10A6C = sp34->pos;
        this->unk_1F8 = (s32) (u8) common_data.unk_10A78;
    } else {
        this->actor.world.pos = common_data.unk_10A6C;
        this->unk_1F8 = (s32) (u8) common_data.unk_10A78;
    }
    func_80968A10_jp(this, game_play, this->unk_1F8);
    func_80968AF4_jp(this, this->unk_1F8);
    common_data.unk_100DC = func_8096A86C_jp;
    Shape_Info_init(this, 0.0f, mAc_ActorShadowEllipse, 9.0f, 17.0f);
    ClObjPipe_ct(game_play, (ClObjPipe* ) &this->collider);
    ClObjPipe_set5(game_play, (ClObjPipe* ) &this->collider, &this->actor, &aBALL_CoInfoData);
    CollisionCheck_Status_set3(&this->actor.colStatus, &aBALL_StatusData);
    this->unk_206 = 3;
    func_80969998_jp(this, game_play);
    this->unk_1DC = 0;
    this->actor.terminalVelocity = -20.0f;
    this->actor.gravity = 0.6f;
    this->actor.speed = 0.0f;
    this->unk_1EC = 0.0f;
    this->unk_1F0 = 0.12f;
    this->actor.scale.x = 0.01f;
    this->actor.scale.y = 0.01f;
    this->actor.scale.z = 0.01f;
    this->unk_1F4 = 0.0f;
    this->unk_20A = 0;
}

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Ball/ac_ball/aBALL_actor_dt.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Ball/ac_ball/func_80969040_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Ball/ac_ball/func_80969114_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Ball/ac_ball/func_809693EC_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Ball/ac_ball/func_80969800_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Ball/ac_ball/func_8096983C_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Ball/ac_ball/func_809698E8_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Ball/ac_ball/func_80969998_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Ball/ac_ball/func_809699D8_jp.s")

// TODO: this function includes an unreferenced float. It was forced to be in this function to
// be able to build and match the file. It needs to be figured out where to put this float and
// how to handle this when this file gets decompiled.
#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Ball/ac_ball/func_80969DE8_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Ball/ac_ball/func_80969FBC_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Ball/ac_ball/func_80969FD8_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Ball/ac_ball/func_8096A0CC_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Ball/ac_ball/func_8096A0EC_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Ball/ac_ball/func_8096A23C_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Ball/ac_ball/func_8096A334_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Ball/ac_ball/func_8096A3D8_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Ball/ac_ball/aBALL_actor_move.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Ball/ac_ball/aBALL_actor_draw.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Ball/ac_ball/func_8096A86C_jp.s")
