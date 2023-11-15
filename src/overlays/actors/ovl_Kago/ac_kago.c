#include "ac_kago.h"
#include "m_actor_dlftbls.h"
#include "m_object.h"
#include "overlays/gamestates/ovl_play/m_play.h"
#include "overlays/actors/player_actor/m_player.h"
#include "69E2C0.h"
#include "m_field_info.h"
#include "m_player_lib.h"

void aKAG_actor_ct(Actor* thisx, Game_Play* game_play);
void func_80A8F340_jp(Actor* thisx, Game_Play* game_play);
void aKAG_actor_init(Actor* thisx, Game_Play* game_play);
void aKAG_actor_draw(Actor* thisx, Game_Play* game_play);

#if 0
ActorProfile Kago_Profile = {
    /* */ ACTOR_KAGO,
    /* */ ACTOR_PART_0,
    /* */ 0,
    /* */ 0x5835,
    /* */ GAMEPLAY_KEEP,
    /* */ sizeof(Kago),
    /* */ aKAG_actor_ct,
    /* */ func_80A8F340_jp,
    /* */ aKAG_actor_init,
    /* */ aKAG_actor_draw,
    /* */ NULL,
};
#endif

void func_80A8F3CC_jp(Kago* this, s32 arg0);
void func_80A8F428_jp(Kago* this, s32 arg0);

void aKAG_actor_ct(Actor* thisx, Game_Play* game_play) {
    Kago* this = (Kago*)thisx;
    s32 temp_v0;

    temp_v0 = this->actor.fgName - 0x5835;
    this->unk_2B4 = temp_v0;
    this->unk_2A8 = temp_v0 + 0x23;
    this->unk_2AC = temp_v0 + 0x4C;
    func_80A8F428_jp(this, 0);
    func_80A8F3CC_jp(this, 1);
}

void func_80A8F340_jp(Actor* thisx, Game_Play* game_play) {
    Kago* this = (Kago*)thisx;

    common_data.unk_10098->unk_A8(&common_data.unk_10098->unk_B0, 8, this->unk_2A8, &this->actor);
    common_data.unk_10098->unk_A8(&common_data.unk_10098->unk_454, 9, this->unk_2AC, &this->actor);
    common_data.unk_10098->unk_A8(&common_data.unk_10098->unk_86C, 8, this->unk_2A8, &this->actor);
}

extern void func_800739FC_jp(xyz_t, s32, s32);

void func_80A8F3CC_jp(Kago* this, s32 arg0) {
    s32 var = arg0 == 0 ? 0 : 0;
    func_800739FC_jp(this->actor.home.pos, 0xA, 0x64);
}

void func_80A8F418_jp(Kago* this, s32 arg0) {

}

extern KagoActionFunc D_80A8F728_jp[1];

void func_80A8F428_jp(Kago* this, s32 arg0) {
    this->unk_2A0 = D_80A8F728_jp[arg0];
    this->unk_2B8 = arg0;
}

void func_80A8F448_jp(Kago* this, Game_Play* game_play) {
    s8 pad[0x8];
    Player* player;
    s32 sp30;
    s32 sp2C;
    s32 sp28;
    s32 sp24;

    player = get_player_actor_withoutCheck(game_play);
    mFI_Wpos2BlockNum(&sp30, &sp2C, this->actor.world.pos);
    mFI_Wpos2BlockNum(&sp28, &sp24, player->actor.world.pos);
    if ((mDemo_Check(1, &player->actor) == 0) && (mDemo_Check(5, &player->actor) == 0) && ((sp30 != sp28) || (sp2C != sp24))) {
        Actor_delete(&this->actor);
        return;
    }
    this->unk_2A0(this, game_play);
}

void aKAG_actor_init(Actor* thisx, Game_Play* game_play) {
    Kago* this = (Kago*)thisx;
    mFI_SetFG_common(0xF0FD, this->actor.home.pos, 0);
    func_80A8F448_jp(this, game_play);
    this->actor.update = func_80A8F448_jp;
}

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Kago/ac_kago/aKAG_actor_draw.s")
