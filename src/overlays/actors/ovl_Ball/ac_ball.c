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
void func_809698E8_jp(Ball* this, Game_Play* game_play);
void func_809699D8_jp(Ball* this, Game_Play* game_play);
void func_80969998_jp(Ball* this, Game_Play* game_play);
void func_80969FBC_jp(Ball* this, Game_Play* game_play);
void func_8096A0CC_jp(Ball* this, Game_Play* game_play);

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

extern UNK_TYPE D_1100000;
extern UNK_TYPE D_11003C0;
extern UNK_TYPE D_1101000;
extern UNK_TYPE D_1101770;
extern UNK_TYPE D_1102000;
extern UNK_TYPE D_11029E0;

s32 func_80968A10_jp(Ball* this, Game_Play* game_play, s32 arg0) {
    s32 sp18;
    s32 temp_v1;
    s32 var_a2;

    temp_v1 = game_play->objectExchangeBank.num;
    switch (arg0) {
        case 0:
            var_a2 = (s32)&D_11003C0 - (s32)&D_1100000;
            break;
        case 1:
            var_a2 = (s32)&D_1101770 - (s32)&D_1101000;
            break;
        case 2:
            var_a2 = (s32)&D_11029E0 - (s32)&D_1102000;
            break;
        default:
            var_a2 = (s32)&D_11003C0 - (s32)&D_1100000;
            break;
    }
    sp18 = temp_v1;
    if (mSc_secure_exchange_keep_bank(&game_play->objectExchangeBank, 0, var_a2) != 0) {
        this->unk_1E4 = game_play->objectExchangeBank.status[temp_v1].segment;
        return 1;
    }
    return 0;
}

void func_80968AF4_jp(Ball* this, s32 arg0) {
    s32 var_a1;
    s32 var_v0;

    switch (arg0) {
        case 0:
            var_a1 = &D_1100000;
            var_v0 = &D_11003C0;
            break;
        case 1:
            var_a1 = &D_1101000;
            var_v0 = &D_1101770;
            break;
        case 2:
            var_a1 = &D_1102000;
            var_v0 = &D_11029E0;
            break;
        default:
            var_a1 = &D_1100000;
            var_v0 = &D_11003C0;
            break;
    }
    if ((var_a1 != NULL) && (var_v0 != NULL)) {
        DmaMgr_RequestSyncDebug(this->unk_1E4, var_a1, var_v0 - var_a1, "../ac_ball.c", 0x11D);
    }
}

s32 func_80968B9C_jp(s32 arg0) {
    s32 temp_fp;
    s32 temp_s3;
    s32 sp64;
    s32 sp60;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 var_s0;
    s32 j;
    s32 var_s2;
    s32 i;

    temp_fp = func_80087E58_jp();
    temp_s3 = func_80087E94_jp();
    var_s2 = (s32) (fqrand() * (f32) temp_fp);
    var_s0 = (s32) (fqrand() * (f32) temp_s3);
    for (i = 0; i < temp_fp; i++) {
        for (j = 0; j < temp_s3; j++) {
            if ((func_80089404_jp(var_s2, var_s0, 0x8023) == 0) && (func_800ADD20_jp(&sp64, &sp60, var_s2, var_s0, 2) == 1)) {
                func_80088C74_jp(arg0, var_s2, var_s0, sp64, sp60);
                return 1;
            }
            temp_v0 = var_s0 + 1;
            var_s0 = temp_s3;
            if (var_s0 == temp_v0) {
                var_s0 = 0;
            } else {
                var_s0 = temp_v0;
            }
        }
        temp_v0_2 = var_s2 + 1;
        var_s2 = temp_fp;
        if (var_s2 == temp_v0_2) {
            var_s2 = 0;
        } else {
            var_s2 = temp_v0_2;
        }
    }
    return 0;
}

extern Ball* B_8096A980_jp;
extern void mAc_ActorShadowEllipse(Actor*, LightsN*, Game_Play*);

void aBALL_actor_ct(Actor* thisx, Game_Play* game_play) {
    Ball* this = (Ball*)thisx;
    PosRot* sp34;

    B_8096A980_jp = this;
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
    this->unk_1DC = NULL;
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

void aBALL_actor_dt(Actor* thisx, Game_Play* game_play) {
    Ball* this = (Ball*)thisx;
    s16 temp_v0;

    temp_v0 = this->unk_208;
    if ((temp_v0 & 1) || (temp_v0 & 2) || (func_800CE9C4_jp(&this->actor) == 0)) {
        common_data.unk_10A6C = ZeroVec;
    } else {
        common_data.unk_10A6C = this->actor.world.pos;
    }
    common_data.unk_100DC = NULL;
    ClObjPipe_dt(game_play, &this->collider);
}

extern f32 func_80071884_jp(xyz_t*, xyz_t, f32);
// extern void func_800CE4F4_jp(xyz_t*, f32*, f32*);
// extern void func_800CE554_jp(Actor*, xyz_t*);

void func_80969040_jp(Ball* this) {
    xyz_t sp2C;
    u32 temp_v0;

    func_80071884_jp(&sp2C, this->actor.world.pos, 0.0f);
    temp_v0 = this->actor.unk_098;
    if (((temp_v0 >> 0x1F) != 0) || (s32)((temp_v0 & 0xFFFF) << 0x16) < 0) {
        chase_f(&this->actor.speed, this->unk_1EC, this->unk_1F0);
    }
    if (!(this->unk_208 & 2)) {
        func_800CE4F4_jp(&this->actor.velocity, &this->actor.speed, &this->actor.world.rot.y);
        chase_f(&this->actor.velocity.y, this->actor.terminalVelocity, this->actor.gravity);
        func_800CE554_jp(&this->actor, &sp2C);
        if (this->actor.world.pos.z < 840.0f) {
            this->actor.world.pos.z = 840.0f;
        }
    }
}

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Ball/ac_ball/func_80969114_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Ball/ac_ball/func_809693EC_jp.s")

extern s32 func_800CEB1C_jp();

void func_80969800_jp(Ball* this) {
    if (func_800CEB1C_jp() != 1) {
        this->unk_208 |= 1;
        Actor_delete(&this->actor);
    }
}

extern void func_800D1D58_jp(s32, void*);

void func_8096983C_jp(Ball* this, Game_Play* game_play) {
    void* sp2C;
    f32 temp;

    sp2C = &this->actor.world.pos;
    temp = func_80071884_jp(NULL, this->actor.world.pos, 0.0f);
    this->actor.shape.unk_2C = 1;
    if ((this->unk_1E0 == func_809699D8_jp) && ((this->actor.world.pos.y - temp) > 20.0f)) {
        func_800D1D58_jp(0x43D, sp2C);
    }
    this->unk_1E0 = func_809698E8_jp;
}

void func_809698E8_jp(Ball* this, Game_Play* game_play) {
    u32 temp_v0;

    this->unk_1F0 = 0.0f;
    add_calc0(&this->unk_1E8, 0.5f, 100.0f);
    temp_v0 = this->actor.unk_098;
    this->actor.terminalVelocity = -20.0f;
    this->actor.gravity = 0.6f;
    this->unk_1F4 = this->actor.speed;
    if (temp_v0 >> 0x1F) {
        if (((s32)(temp_v0 & 0xFFFF) << 0x16) < 0) {
            func_8096A0CC_jp(this, game_play);
        } else {
            func_80969998_jp(this, game_play);
        }
    } else if (((s32)(temp_v0 & 0xFFFF) << 0x16) < 0) {
        func_80969FBC_jp(this, game_play);
    }
}

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

void func_8096A86C_jp(void) {
    if ((common_data.unk_100DC != NULL) && (B_8096A980_jp != NULL)) {
        func_80968AF4_jp(B_8096A980_jp, B_8096A980_jp->unk_1F8);
    }
}
