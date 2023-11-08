#include "ac_fuusen.h"
#include "m_actor_dlftbls.h"
#include "m_actor_shadow.h"
#include "m_object.h"
#include "overlays/gamestates/ovl_play/m_play.h"
#include "overlays/actors/player_actor/m_player.h"
#include "libc/math.h"

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
extern f32 func_80072F9C_jp(xyz_t*);
extern BaseAnimationR D_6000F44;
extern BaseSkeletonR D_6000F88;
extern xyz_t D_80AAE4D4_jp;

void aFSN_actor_ct(Actor* thisx, Game_Play* game_play) {
    Fuusen* this = (Fuusen*)thisx;
    SkeletonInfoR *skeletonInfo = &this->skeletonInfo;
    xyz_t sp34;
    f32 sp30;
    sp34 = D_80AAE4D4_jp;
    sp30 = func_80072F9C_jp(&this->actor.world.pos);
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

extern void func_80092B7C_jp();
extern void func_80092B8C_jp();

void aFSN_actor_dt(Actor* thisx, Game_Play* game_play) {
    Fuusen* this = (Fuusen*)thisx;
    if (this->unk_190 != 0) {
        func_80092B8C_jp();
        return;
    }
    func_80092B7C_jp();
}

s16 func_8009895C_jp();                             /* extern */
extern s32 D_80AAE4E0_jp[16];
extern xyz_t D_80AAE520_jp[8];
extern xyz_t D_FLT_80AAE580_jp[8];

void func_80AAD270_jp(Fuusen* this, Game_Play* game_play) {
    s16 var_v0;
    f32 temp_fa1;
    f32 temp_fv0_2;
    f32 sp30;
    f32 temp_fv0;
    s32 var_v1;

    sp30 = func_80072F9C_jp(&this->actor.world.pos);
    this->actor.world.rot.y = func_8009895C_jp();
    var_v0 = this->actor.world.rot.y & 0xF000;
    this->unk_194 = (var_v0 >> 0xC) & 0xF;
    this->unk_194 = D_80AAE4E0_jp[this->unk_194];
    xyz_t_move(&this->actor.world.pos, &D_80AAE520_jp[this->unk_194]);
    this->actor.world.pos.y = (f32) (sp30 + 200.0f);
    this->unk_180 = (u32) ((u32) game_play->unk_1EA0 % 5U);
    this->unk_188 = 0xA;
    var_v1 = false;
    if ((D_FLT_80AAE580_jp[this->unk_194].x != 0.0f) && (D_FLT_80AAE580_jp[this->unk_194].z != 0.0f)) {
        var_v1 = game_play->unk_1EA0 & 1;
    } else if (D_FLT_80AAE580_jp[this->unk_194].z != 0.0f) {
        var_v1 = true;
    }
    if (!var_v1) {
        if (D_FLT_80AAE580_jp[this->unk_194].x != 0.0f) {
            temp_fa1 = fqrand();
            temp_fv0 = fabsf(D_FLT_80AAE580_jp[this->unk_194].x);
            if (D_FLT_80AAE580_jp[this->unk_194].x > 0.0f) {
                this->actor.world.pos.x += temp_fv0 * temp_fa1;
            } else {
                this->actor.world.pos.x -= temp_fv0 * temp_fa1;
            }
        }
    } else {
        if (D_FLT_80AAE580_jp[this->unk_194].z != 0.0f) {
            temp_fa1 = fqrand();
            temp_fv0_2 = fabsf(D_FLT_80AAE580_jp[this->unk_194].z);
            if (D_FLT_80AAE580_jp[this->unk_194].z > 0.0f) {
                this->actor.world.pos.z += temp_fv0_2 * temp_fa1;
            } else {
                this->actor.world.pos.z -= temp_fv0_2 * temp_fa1;
            }
        }
    }
}

void func_80AAD490_jp(Fuusen* this, Game_Play* game_play) {
    this->unk_1A4 = 0;
}

extern void func_800D1D58_jp(s32, xyz_t*, Actor*);

void func_80AAD4A0_jp(Fuusen* this, Game_Play* game_play) {
    this->unk_184 = 0x2631;
    this->actor.speed = 0.0f;
    func_800D1D58_jp(0x402, &this->actor.world.pos, &this->actor);
}

void func_80AAD4DC_jp(Fuusen* this, Game_Play* game_play) {
    f32 temp_fa0;
    f32 temp_fv1;
    Player* player = get_player_actor_withoutCheck(game_play);
    
    temp_fv1 = player->actor.world.pos.x - this->actor.world.pos.x;
    temp_fa0 = player->actor.world.pos.z - this->actor.world.pos.z;
    this->unk_18C = 0;
    this->actor.terminalVelocity = 5.0f;
    this->actor.gravity = 0.5f;
    this->unk_190 = 0;
    if (this->unk_184 == 0x309) {
        this->unk_18C = 1;
        if (sqrtf(SQ(temp_fv1) + SQ(temp_fa0)) < 640.0f) {
            this->unk_190 = 1;
        }
    }
}

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Fuusen/ac_fuusen/func_80AAD580_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Fuusen/ac_fuusen/func_80AAD5A4_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Fuusen/ac_fuusen/func_80AADB9C_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Fuusen/ac_fuusen/func_80AADDA8_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Fuusen/ac_fuusen/func_80AADEC4_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Fuusen/ac_fuusen/func_80AADF10_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Fuusen/ac_fuusen/aFSN_actor_move.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Fuusen/ac_fuusen/func_80AAE10C_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Fuusen/ac_fuusen/aFSN_actor_draw.s")
