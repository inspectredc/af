#include "ac_kamakura.h"
#include "m_actor_dlftbls.h"
#include "m_object.h"
#include "overlays/gamestates/ovl_play/m_play.h"

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

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Kamakura/ac_kamakura/func_80A0510C_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Kamakura/ac_kamakura/func_80A052F4_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Kamakura/ac_kamakura/func_80A054F4_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Kamakura/ac_kamakura/func_80A055EC_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Kamakura/ac_kamakura/func_80A05690_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Kamakura/ac_kamakura/func_80A05760_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Kamakura/ac_kamakura/func_80A05780_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Kamakura/ac_kamakura/aKKR_actor_init.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Kamakura/ac_kamakura/aKKR_actor_draw.s")
