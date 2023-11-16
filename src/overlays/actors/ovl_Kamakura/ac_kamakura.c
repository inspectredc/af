#include "ac_kamakura.h"
#include "m_actor_dlftbls.h"
#include "m_object.h"
#include "overlays/gamestates/ovl_play/m_play.h"
#include "overlays/actors/player_actor/m_player.h"
#include "m_player_lib.h"
#include "m_field_info.h"
#include "m_police_box.h"
#include "macros.h"
#include "67E840.h"
#include "69E2C0.h"

void aKKR_actor_ct(Actor* thisx, Game_Play* game_play);
void aKKR_actor_dt(Actor* thisx, Game_Play* game_play);
void aKKR_actor_init(Actor* thisx, Game_Play* game_play);
void aKKR_actor_draw(Actor* thisx, Game_Play* game_play);

#if 0
ActorProfile Kamakura_Profile = {
    /* */ ACTOR_KAMAKURA,
    /* */ ACTOR_PART_0,
    /* */ 0,
    /* */ 0x5829,
    /* */ GAMEPLAY_KEEP,
    /* */ sizeof(Kamakura),
    /* */ aKKR_actor_ct,
    /* */ aKKR_actor_dt,
    /* */ aKKR_actor_init,
    /* */ aKKR_actor_draw,
    /* */ NULL,
};
#endif

void func_80A0510C_jp(Kamakura*, s32);
void func_80A052F4_jp(Kamakura*, s32);
void func_80A05760_jp(Kamakura*, s32);

void aKKR_actor_ct(Actor* thisx, Game_Play* game_play) {
    Kamakura* this = (Kamakura*)thisx;
    func_80A0510C_jp(this, 1);
    func_80A05760_jp(this, 0);
    func_80A052F4_jp(this, 1);
}

void aKKR_actor_dt(Actor* thisx, Game_Play* game_play) {
    Kamakura* this = (Kamakura*)thisx;

    common_data.unk_10098->unk_A8(&common_data.unk_10098->unk_B0, 8, 0x1A, &this->actor);
    common_data.unk_10098->unk_A8(&common_data.unk_10098->unk_454, 9, 0x43, &this->actor);
    common_data.unk_10098->unk_A8(&common_data.unk_10098->unk_86C, 8, 0x1A, &this->actor);
    func_80A0510C_jp(this, 0);
}

extern u16 func_800A5A0C_jp(u16);

void func_80A0510C_jp(Kamakura* this, s32 arg0) {
    u16* sp44;
    s32 var_v0;
    xyz_t sp34;

    xyz_t_move(&sp34, &this->actor.world.pos);
    sp34.z += 80.0f;
    if (arg0 == 0) {
        mFI_SetFG_common(0, sp34, 1);
        return;
    }
    sp44 = mFI_GetUnitFG(sp34);
    if (sp44 != NULL) {
        if (mSN_ClearSnowman(sp44) == 0) {
            if ((var_v0 = (*sp44 < 0x2A) ^ 1, (var_v0 == 0)) || (var_v0 = *sp44 < 0x43, (var_v0 == 0))) {
                var_v0 = *sp44 == 0x5C;
            }
            if (var_v0 == 1) {
                mPB_keep_item(func_800A5A0C_jp(*sp44));
                mFI_SetFG_common(0xFFFF, sp34, 1);
                mFI_Wpos2DepositOFF(sp34);
                return;
            }
            mFI_Wpos2DepositOFF(sp34);
            mPB_keep_item(*sp44);
            mFI_SetFG_common(0xFFFF, sp34, 1);
            return;
        }
        mFI_SetFG_common(0xFFFF, sp34, 1);
    }
}

extern mCoBG_OffsetTable* D_80A05C10_jp[2];
extern f32 D_FLT_80A05C18_jp[3];
extern f32 D_FLT_80A05C24_jp[3];

void func_80A052F4_jp(Kamakura* this, s32 arg0) {
    s32 i;
    xyz_t sp58;
    mCoBG_OffsetTable* var_s0 = D_80A05C10_jp[arg0];

    for (i = 0; i < ARRAY_COUNT(D_FLT_80A05C24_jp); i++) {
        sp58.z = D_FLT_80A05C24_jp[i] + this->actor.home.pos.z;
        sp58.x = D_FLT_80A05C18_jp[0] + this->actor.home.pos.x;
        mCoBG_SetPluss5PointOffset_file(sp58, *var_s0, "../ac_kamakura_move.c_inc", 178);
        var_s0++;
        sp58.x = D_FLT_80A05C18_jp[1] + this->actor.home.pos.x;
        mCoBG_SetPluss5PointOffset_file(sp58, *var_s0, "../ac_kamakura_move.c_inc", 182);
        var_s0++;
        sp58.x = D_FLT_80A05C18_jp[2] + this->actor.home.pos.x;
        mCoBG_SetPluss5PointOffset_file(sp58, *var_s0, "../ac_kamakura_move.c_inc", 186);
        var_s0++;
    }
}

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Kamakura/ac_kamakura/func_80A054F4_jp.s")

s32 func_80A055EC_jp(Kamakura* this, Game_Play* game_play) {
    Player* player = get_player_actor_withoutCheck(game_play);
    s32 var_a0 = 0;
    u16 temp_v0;
    f32 temp_fv0;
    f32 temp_fv1;

    if (!player) {
        return 0;
    }
    temp_v0 = player->actor.shape.rot.y;
    temp_fv0 = player->actor.world.pos.x - this->actor.world.pos.x;
    temp_fv1 = player->actor.world.pos.z - (this->actor.world.pos.z + 40.0f);
    // FAKE
    if (temp_v0) {}
    if ((temp_v0 >= 0x6001) && (temp_v0 < 0xA000) && ((SQ(temp_fv0)+ SQ(temp_fv1)) < 1600.0f)) {
        var_a0 = 1;
    }
    return var_a0;
}

extern void func_800B27B0_jp(Game_Play*, xyz_t*, s32, s32, Actor*);
extern void func_800C6C10_jp(Game_Play*, s32*, s32);

extern s32 D_80A05BBC_jp[5];

void func_80A05690_jp(Kamakura* this, Game_Play* game_play) {
    xyz_t sp2C;

    if (get_player_actor_withoutCheck((Game_Play*)gamePT)->unk_122C(gamePT) == &this->actor) {
        func_80A054F4_jp(this, game_play);
        func_800C6C10_jp(game_play, D_80A05BBC_jp, 1);
    } else if (func_80A055EC_jp(this, game_play) != 0) {
        sp2C.x = this->actor.world.pos.x;
        sp2C.y = get_player_actor_withoutCheck(game_play)->actor.world.pos.y;
        sp2C.z = this->actor.world.pos.z + 68.0f;
        func_800B27B0_jp(game_play, &sp2C, -0x8000, 1, &this->actor);
    }
}

extern KamakuraActionFunc D_80A05C30_jp[];

void func_80A05760_jp(Kamakura* this, s32 arg0) {
    this->unk_2A0 = D_80A05C30_jp[arg0];
    this->unk_2B4 = arg0;
}

void func_80A05780_jp(Kamakura* this, Game_Play* game_play) {
    char pad[0x8];
    Player* player;
    s32 sp30;
    s32 sp2C;
    s32 sp28;
    s32 sp24;

    player = get_player_actor_withoutCheck(game_play);
    mFI_Wpos2BlockNum(&sp30, &sp2C, this->actor.world.pos);
    mFI_Wpos2BlockNum(&sp28, &sp24, player->actor.world.pos);
    if (!mDemo_Check(1, player) && !mDemo_Check(5, player) && ((sp30 != sp28) || (sp2C != sp24))) {
        Actor_delete(&this->actor);
    } else {
        this->unk_2A0(this, game_play);
    }
}

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Kamakura/ac_kamakura/aKKR_actor_init.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Kamakura/ac_kamakura/aKKR_actor_draw.s")
