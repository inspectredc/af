#include "ac_kamakura_indoor.h"
#include "m_actor_dlftbls.h"
#include "m_object.h"
#include "overlays/gamestates/ovl_play/m_play.h"

void Kamakura_Indoor_Actor_ct(Actor* thisx, Game_Play* game_play);
void Kamakura_Indoor_Actor_dt(Actor* thisx, Game_Play* game_play);
void Kamakura_Indoor_Actor_move(Actor* thisx, Game_Play* game_play);
void Kamakura_Indoor_Actor_draw(Actor* thisx, Game_Play* game_play);

#if 0
ActorProfile Kamakura_Indoor_Profile = {
    /* */ ACTOR_KAMAKURA_INDOOR,
    /* */ ACTOR_PART_5,
    /* */ ACTOR_FLAG_10 | ACTOR_FLAG_20,
    /* */ 0x0000,
    /* */ OBJECT_22,
    /* */ sizeof(Kamakura_Indoor),
    /* */ Kamakura_Indoor_Actor_ct,
    /* */ Kamakura_Indoor_Actor_dt,
    /* */ Kamakura_Indoor_Actor_move,
    /* */ Kamakura_Indoor_Actor_draw,
    /* */ NULL,
};
#endif

extern f32 D_80A81234_jp[4];
extern xyz_t D_80A81244_jp;

void Kamakura_Indoor_Actor_ct(Actor *thisx, Game_Play *game_play) {
    Kamakura_Indoor *this = (Kamakura_Indoor *) thisx;
    
    this->unk_1C0 = D_80A81244_jp;
    this->unk_1CC = D_80A81244_jp;
    this->unk_1D8 = 0;
    this->unk_194 = mCoBG_RegistMoveBg(&this->unk_198, &this->unk_1C0, &this->unk_1CC, &this->unk_1D8, 35.0f, D_80A81234_jp, 0, 0, 0, 6, 7, 100.0f);
}

void Kamakura_Indoor_Actor_dt(Actor* thisx, Game_Play* game_play) {
    Kamakura_Indoor* this = (Kamakura_Indoor*)thisx;
    mCoBG_CrossOffMoveBg(this->unk_194, thisx);
}

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Kamakura_Indoor/ac_kamakura_indoor/func_80A801C8_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Kamakura_Indoor/ac_kamakura_indoor/func_80A80370_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Kamakura_Indoor/ac_kamakura_indoor/func_80A80440_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Kamakura_Indoor/ac_kamakura_indoor/func_80A806B8_jp.s")

// clang-format off
#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Kamakura_Indoor/ac_kamakura_indoor/Kamakura_Indoor_Actor_draw.s")
// clang-format on

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Kamakura_Indoor/ac_kamakura_indoor/func_80A80804_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Kamakura_Indoor/ac_kamakura_indoor/func_80A80A9C_jp.s")

// clang-format off
#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Kamakura_Indoor/ac_kamakura_indoor/Kamakura_Indoor_Actor_move.s")
// clang-format on
