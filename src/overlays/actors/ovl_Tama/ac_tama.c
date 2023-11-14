#include "ac_tama.h"
#include "m_actor_dlftbls.h"
#include "m_object.h"
#include "m_actor_shadow.h"
#include "overlays/gamestates/ovl_play/m_play.h"
#include "overlays/actors/player_actor/m_player.h"
#include "m_player_lib.h"
#include "libc/math.h"
#include "69E2C0.h"
#include "m_field_info.h"

void aTAM_actor_ct(Actor* thisx, Game_Play* game_play);
void func_80A8EF30_jp(Actor* thisx, Game_Play* game_play);
void aTAM_actor_init(Actor* thisx, Game_Play* game_play);
void aTAM_actor_draw(Actor* thisx, Game_Play* game_play);

#if 0
ActorProfile Tama_Profile = {
    /* */ ACTOR_TAMA,
    /* */ ACTOR_PART_0,
    /* */ 0,
    /* */ 0x5833,
    /* */ GAMEPLAY_KEEP,
    /* */ sizeof(Tama),
    /* */ aTAM_actor_ct,
    /* */ func_80A8EF30_jp,
    /* */ aTAM_actor_init,
    /* */ aTAM_actor_draw,
    /* */ NULL,
};
#endif

void func_80A8EFCC_jp(Tama*, UNK_TYPE);

void aTAM_actor_ct(Actor* thisx, Game_Play* game_play) {
    Tama* this = (Tama*)thisx;
    s32 temp_v0;

    temp_v0 = this->actor.fgName - 0x5833;
    this->unk_2B4 = temp_v0;
    this->unk_2A8_union.unk_2A8 = temp_v0 + 0x23;
    this->unk_2AC_union.unk_2AC = temp_v0 + 0x4C;
    func_80A8EFCC_jp(this, 0);
}

void func_80A8EF30_jp(Actor* thisx, Game_Play* game_play) {
    Tama* this = (Tama*)thisx;
    CommonData_unk_10098* temp_v0;
    CommonData_unk_10098* temp_v0_2;
    CommonData_unk_10098* temp_v0_3;

    temp_v0 = common_data.unk_10098;
    temp_v0->unk_A8(&temp_v0->unk_B0, 8, this->unk_2A8_union.unk_2A8_struct.unk_2AA, &this->actor);
    temp_v0_2 = common_data.unk_10098;
    temp_v0_2->unk_A8(&temp_v0_2->unk_454, 9, this->unk_2AC_union.unk_2AC_struct.unk_2AE, &this->actor);
    temp_v0_3 = common_data.unk_10098;
    temp_v0_3->unk_A8(&temp_v0_3->unk_86C, 8, this->unk_2A8_union.unk_2A8_struct.unk_2AA, &this->actor);
}

void func_80A8EFBC_jp(Tama* this, Game_Play* game_play) {

}

extern TamaActionFunc D_80A8F294_jp[1];

void func_80A8EFCC_jp(Tama* this, s32 arg0) {
    this->unk_2A0 = D_80A8F294_jp[arg0];
    this->unk_2B8 = arg0;
}

void func_80A8EFEC_jp(Tama* this, Game_Play* game_play) {
    UNK_TYPE1 pad[0x8];
    Player* player;
    s32 sp30;
    s32 sp2C;
    s32 sp28;
    s32 sp24;

    player = get_player_actor_withoutCheck(game_play);
    mFI_Wpos2BlockNum(&sp30, &sp2C, this->actor.world.pos);
    mFI_Wpos2BlockNum(&sp28, &sp24, player->actor.world.pos);
    if ((mDemo_Check(1, player) == 0) && (mDemo_Check(5, &player->actor) == 0) && ((sp30 != sp28) || (sp2C != sp24))) {
        Actor_delete(&this->actor);
        return;
    }
    this->unk_2A0(this, game_play);
}

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Tama/ac_tama/aTAM_actor_init.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Tama/ac_tama/aTAM_actor_draw.s")
