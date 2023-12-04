#include "ac_kago.h"
#include "m_actor_dlftbls.h"
#include "m_object.h"
#include "overlays/gamestates/ovl_play/m_play.h"
#include "overlays/actors/player_actor/m_player.h"
#include "69E2C0.h"
#include "m_field_info.h"
#include "m_player_lib.h"
#include "m_rcp.h"
#include "code_variables.h"

void aKAG_actor_ct(Actor* thisx, Game_Play* game_play);
void func_80A8F340_jp(Actor* thisx, Game_Play* game_play);
void aKAG_actor_init(Actor* thisx, Game_Play* game_play);
void aKAG_actor_draw(Actor* thisx, Game_Play* game_play);

void func_80A8F3CC_jp(Kago*, s32);
void func_80A8F428_jp(Kago*, s32);

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

void func_80A8F3CC_jp(Kago* this, s32 arg0) {
    s32 var = arg0 == 0 ? 0 : 0;
    func_800739FC_jp(this->actor.home.pos, 0xA, 0x64);
}

void func_80A8F418_jp(Kago* this, s32 arg0) {

}

UNK_TYPE D_80A8F704_jp[4] = { 0x01000001, 0x01000001, 0x00010000, 0x01000000 };

UNK_PTR D_80A8F714_jp[5] = { (UNK_PTR)0x0000000D, D_80A8F704_jp, (UNK_PTR)0x42700000, (UNK_PTR)0x06001628, (UNK_PTR)0x060016F8 };

static KagoActionFunc D_80A8F728_jp[1] = { func_80A8F418_jp };

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
    } else {
        this->unk_2A0(this, game_play);
    }
}

void aKAG_actor_init(Actor* thisx, Game_Play* game_play) {
    Kago* this = (Kago*)thisx;
    mFI_SetFG_common(0xF0FD, this->actor.home.pos, 0);
    func_80A8F448_jp(this, game_play);
    this->actor.update = func_80A8F448_jp;
}

Gfx* D_80A8F72C_jp[5] = { (Gfx*)0x06016EA8, (Gfx*)0x06018EA0, NULL, NULL, NULL };

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

void aKAG_actor_draw(Actor* thisx, Game_Play* game_play) {
    GraphicsContext* gfxCtx = game_play->state.gfxCtx;
    Kago* this = (Kago*)thisx;
    s32 sp24;
    s32 sp20;
    Mtx* sp1C;

    sp24 = common_data.unk_10098->unk_AC(this->unk_2A8);
    sp20 = common_data.unk_10098->unk_450(this->unk_2AC);
    AC_GCN_OPEN_DISP(gfxCtx);
    sp1C = _Matrix_to_Mtx_new(gfxCtx);
    if (sp1C != NULL) {
        _texture_z_light_fog_prim(gfxCtx);
        OPEN_CUSTOM_POLY_OPA();
        gSPSegment(__polyOpa++, 0x08, sp20);
        gSegments[6] = (uintptr_t)OS_PHYSICAL_TO_K0(sp24);
        gSPSegment(__polyOpa++, 0x06, sp24);
        gSPMatrix(__polyOpa++, sp1C, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(__polyOpa++, D_80A8F72C_jp[this->unk_2B4]);
        CLOSE_CUSTOM_POLY_OPA();
        common_data.unk_10080->unk_04(game_play, &D_80A8F714_jp, this->unk_2A8, &this->actor);
    }
    AC_GCN_CLOSE_DISP(gfxCtx);
}
