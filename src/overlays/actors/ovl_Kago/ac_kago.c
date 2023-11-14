#include "ac_kago.h"
#include "m_actor_dlftbls.h"
#include "m_object.h"
#include "overlays/gamestates/ovl_play/m_play.h"
#include "overlays/actors/player_actor/m_player.h"

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

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Kago/ac_kago/func_80A8F428_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Kago/ac_kago/func_80A8F448_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Kago/ac_kago/aKAG_actor_init.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Kago/ac_kago/aKAG_actor_draw.s")
