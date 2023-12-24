#include "ac_dump.h"
#include "m_actor_dlftbls.h"
#include "m_object.h"
#include "overlays/gamestates/ovl_play/m_play.h"
#include "69E2C0.h"
#include "m_player_lib.h"
#include "overlays/actors/player_actor/m_player.h"
#include "m_field_info.h"
#include "code_variables.h"
#include "m_rcp.h"

void aDUM_actor_ct(Actor* thisx, Game_Play* game_play);
void aDUM_actor_dt(Actor* thisx, Game_Play* game_play);
void aDUM_actor_init(Actor* thisx, Game_Play* game_play);
void aDUM_actor_draw(Actor* thisx, Game_Play* game_play);

#if 0
ActorProfile Dump_Profile = {
    /* */ ACTOR_DUMP,
    /* */ ACTOR_PART_0,
    /* */ ACTOR_FLAG_10 | ACTOR_FLAG_20,
    /* */ 0x583A,
    /* */ GAMEPLAY_KEEP,
    /* */ sizeof(Dump),
    /* */ aDUM_actor_ct,
    /* */ aDUM_actor_dt,
    /* */ aDUM_actor_init,
    /* */ aDUM_actor_draw,
    /* */ NULL,
};
#endif

void func_80A96B28_jp(Dump*, s32);
void func_80A96D04_jp(Dump*, s32);

void aDUM_actor_ct(Actor* thisx, Game_Play* game_play) {
    Dump* this = (Dump*)thisx;
    func_80A96B28_jp(this, 1);
    func_80A96D04_jp(this, 0);
    this->actor.world.pos.x -= 40.0f;
}

void aDUM_actor_dt(Actor* thisx, Game_Play* game_play) {
    Dump* this = (Dump*)thisx;

    common_data.unk_10098->unk_A8(&common_data.unk_10098->unk_B0, 8, 0x28, &this->actor);
    common_data.unk_10098->unk_A8(&common_data.unk_10098->unk_454, 9, 0x51, &this->actor);
    common_data.unk_10098->unk_A8(&common_data.unk_10098->unk_86C, 8, 0x28, &this->actor);
    this->actor.world.pos.x += 40.0f;
}

extern void func_800739FC_jp(xyz_t, s16, s32);
extern s32 D_80A97058_jp[6][6];

void func_80A96A70_jp(Dump* this, s32 arg1, s32 arg2, s16 arg3) {
    xyz_t sp24;

    sp24.x = this->actor.home.pos.x - (f32) (arg1 * 40);
    sp24.y = this->actor.home.pos.y;
    sp24.z = this->actor.home.pos.z - (f32) (arg2 * 40);

    if (D_80A97058_jp[arg2][arg1]) {
        func_800739FC_jp(sp24, arg3, 0x64);
    }
}

void func_80A96B28_jp(Dump* this, s32 arg1) {
    s32 i;
    s32 unused = arg1 == 0 ? 0 : 0;

    for (i = 0; i < 6; i++) {
        func_80A96A70_jp(this, 0, i, 4);
        func_80A96A70_jp(this, 1, i, 4);
        func_80A96A70_jp(this, 2, i, 4);
        func_80A96A70_jp(this, 3, i, 4);
        func_80A96A70_jp(this, 4, i, 4);
        func_80A96A70_jp(this, 5, i, 4);
    }
}

void func_80A96BE4_jp(Actor* thisx) {
    Color_RGBA8 sp1C;

    mDemo_Set_msg_num(0x136A);
    mDemo_Set_talk_display_name(0);
    mDemo_Set_camera(1);
    mPlib_Set_able_hand_all_item_in_demo(1);
    mDemo_Set_ListenAble();
    sp1C.r = 0xB9;
    sp1C.g = 0x3C;
    sp1C.b = 0x28;
    sp1C.a = 0xFF;
    mDemo_Set_talk_window_color(&sp1C);
}

#define	ABS_2(d)		((d) >= 0) ? (d) : -(d)

void func_80A96C50_jp(Dump* this, Game_Play* game_play) {
    Player* player;
    xyz_t sp20;
    s32 var_v1;

    player = get_player_actor_withoutCheck(game_play);
    xyz_t_move(&sp20, &this->actor.world.pos);
    if ((mDemo_Check(7, &this->actor) != 1) && (player != NULL) && (func_8007B410_jp() == 0) && (sp20.z <= player->actor.world.pos.z)) {
        var_v1 = ABS_2(this->actor.yawTowardsPlayer);
        
        if (var_v1 < 0x2000) {
            mDemo_Request(7, &this->actor, &func_80A96BE4_jp);
        }
    }
}

extern DumpActionFunc D_80A970E8_jp[1];
// DumpActionFunc D_80A970E8_jp[1] = {func_80A96C50_jp};

void func_80A96D04_jp(Dump* this, s32 arg1) {
    this->unk_2A0 = D_80A970E8_jp[arg1];
    this->unk_2B4 = arg1;
}

void func_80A96D24_jp(Actor* thisx, Game_Play* game_play) {
    s32 pad;
    Dump* this = (Dump*)thisx;
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

void aDUM_actor_init(Actor* thisx, Game_Play* game_play) {
    Dump* this = (Dump*)thisx;
    
    mFI_SetFG_common(0xF101, this->actor.home.pos, 0);
    func_80A96D24_jp(&this->actor, game_play);
    this->actor.update = func_80A96D24_jp;
}

extern UNK_PTR D_80A97044_jp[];
extern UNK_PTR D_80A970EC_jp[];

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

void aDUM_actor_draw(Actor* thisx, Game_Play* game_play) {
    GraphicsContext* gfxCtx = game_play->state.gfxCtx;
    s32 sp30;
    s32 sp2C;
    s32 sp28;
    Mtx* mtx;

    if (common_data.time.season == 3) {
        sp28 = 1;
    } else {
        sp28 = 0;
    }
    
    AC_GCN_OPEN_DISP(gfxCtx);
    sp30 = common_data.unk_10098->unk_AC(0x28);
    sp2C = common_data.unk_10098->unk_450(0x51);
    func_800BD5E8_jp(gfxCtx);
    OPEN_CUSTOM_POLY_OPA();
    gSPSegment(__polyOpa++, 0x08, sp2C);
    gSegments[6] = (uintptr_t)OS_PHYSICAL_TO_K0(sp30);
    gSPSegment(__polyOpa++, 0x06, sp30);
    
    Matrix_translate(-6000.0f, 0.0f, -10000.0f, 1);
    mtx = _Matrix_to_Mtx_new(gfxCtx);
    if (mtx != NULL) {
        gSPMatrix(__polyOpa++, mtx, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(__polyOpa++, D_80A970EC_jp[sp28]);
        CLOSE_CUSTOM_POLY_OPA();
    }
    common_data.unk_10080->unk_04(game_play, &D_80A97044_jp, 0x28);
    AC_GCN_CLOSE_DISP(gfxCtx);
}
