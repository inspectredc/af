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
#include "code_variables.h"
#include "m_rcp.h"

void aTAM_actor_ct(Actor* thisx, Game_Play* game_play);
void func_80A8EF30_jp(Actor* thisx, Game_Play* game_play);
void aTAM_actor_init(Actor* thisx, Game_Play* game_play);
void aTAM_actor_draw(Actor* thisx, Game_Play* game_play);

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

void func_80A8EFCC_jp(Tama*, s32);

void aTAM_actor_ct(Actor* thisx, Game_Play* game_play) {
    Tama* this = (Tama*)thisx;

    this->unk_2B4 = this->actor.fgName - 0x5833;
    this->unk_2A8 = this->unk_2B4 + 0x23;
    this->unk_2AC = this->unk_2B4 + 0x4C;
    func_80A8EFCC_jp(this, 0);
}

void func_80A8EF30_jp(Actor* thisx, Game_Play* game_play) {
    Tama* this = (Tama*)thisx;

    common_data.unk_10098->unk_A8(&common_data.unk_10098->unk_B0, 8, this->unk_2A8, &this->actor);
    common_data.unk_10098->unk_A8(&common_data.unk_10098->unk_454, 9, this->unk_2AC, &this->actor);
    common_data.unk_10098->unk_A8(&common_data.unk_10098->unk_86C, 8, this->unk_2A8, &this->actor);
}

void func_80A8EFBC_jp(Tama* this, Game_Play* game_play) {

}

TamaActionFunc D_80A8F294_jp[1] = { func_80A8EFBC_jp };

void func_80A8EFCC_jp(Tama* this, s32 arg0) {
    this->unk_2A0 = D_80A8F294_jp[arg0];
    this->unk_2B8 = arg0;
}

void func_80A8EFEC_jp(Actor* thisx, Game_Play* game_play) {
    UNK_TYPE1 pad[0x4];
    Tama* this = (Tama*)thisx;
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

void aTAM_actor_init(Actor* thisx, Game_Play* game_play) {
    Tama* this = (Tama*)thisx;
    
    mFI_SetFG_common(0xF0FC, this->actor.home.pos, 0);
    func_80A8EFEC_jp(&this->actor, game_play);
    this->actor.update = func_80A8EFEC_jp;
}

Gfx* D_80A8F298_jp[2] = { (Gfx*)0x06018220, (Gfx*)0x0601A1E0 };

#define AC_GCN_OPEN_DISP(gfxCtx)            \
    {                                       \
        GraphicsContext *__gfxCtx = gfxCtx; \
        int __gfx_opened = 0;               \
        do {} while (0)

#define AC_GCN_CLOSE_DISP(gfxCtx) \
        (void)__gfx_opened;       \
    }                             \
    do {} while (0)

#define OPEN_CUSTOM_POLY_OPA()                \
    {                                         \
        Gfx* __polyOpa = __gfxCtx->polyOpa.p; \
        int __opa_opened = 0;                 \
        do {} while (0)

#define CLOSE_CUSTOM_POLY_OPA()          \
        __gfxCtx->polyOpa.p = __polyOpa; \
        (void)__opa_opened;              \
    }                                    \
    do {} while (0)

void aTAM_actor_draw(Actor* thisx, Game_Play* game_play) {
    GraphicsContext* gfxCtx;
    Tama* this = (Tama*)thisx;
    s32 sp2C;
    s32 sp28;
    Mtx* mtx;

    gfxCtx = game_play->state.gfxCtx;
    sp2C = common_data.unk_10098->unk_AC(this->unk_2A8);
    sp28 = common_data.unk_10098->unk_450(this->unk_2AC);
    _texture_z_light_fog_prim(gfxCtx);
    AC_GCN_OPEN_DISP(gfxCtx);
    OPEN_CUSTOM_POLY_OPA();

    gSPSegment(__polyOpa++, 0x08, sp28);
    gSegments[6] = (uintptr_t)OS_PHYSICAL_TO_K0(sp2C);

    gSPSegment(__polyOpa++, 0x06, sp2C);
    Matrix_translate(0.0f, 0.0f, 4000.0f, 1);
    mtx = _Matrix_to_Mtx_new(gfxCtx);
    if (mtx != NULL) {

        gSPMatrix(__polyOpa++, mtx, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

        gSPDisplayList(__polyOpa++, D_80A8F298_jp[this->unk_2B4]);
        CLOSE_CUSTOM_POLY_OPA();
    }
    AC_GCN_CLOSE_DISP(gfxCtx);
}
