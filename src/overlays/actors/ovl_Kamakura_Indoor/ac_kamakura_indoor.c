#include "ac_kamakura_indoor.h"
#include "m_actor_dlftbls.h"
#include "m_object.h"
#include "overlays/gamestates/ovl_play/m_play.h"
#include "m_rcp.h"
#include "macros.h"

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

extern void func_800981B8_jp(Game_Play*);
extern Mtx D_60040E8;
extern xyz_t D_FLT_80A81250_jp[2];

#define AC_GCN_OPEN_DISP(gfxCtx)            \
    {                                       \
        GraphicsContext *__gfxCtx = gfxCtx; \
        int __gfx_opened = 0;               \
        do {} while (0)

#define AC_GCN_CLOSE_DISP(gfxCtx) \
        (void)__gfx_opened;       \
    }                             \
    do {} while (0)

void func_80A801C8_jp(Kamakura_Indoor* this, Game_Play* game_play) {
    s32 i;
    Mtx* temp_s1;
    f32 temp_fv0;

    _texture_z_light_fog_prim_xlu(game_play->state.gfxCtx);
    func_800981B8_jp(game_play);
    for (i = 0; i < ARRAY_COUNT(D_FLT_80A81250_jp); i++) {
        temp_s1 = GRAPH_ALLOC(game_play->state.gfxCtx, 64);
        temp_fv0 = this->unk_174[i].unk_4 * 0.0001f;
        if (1) {}
        AC_GCN_OPEN_DISP(game_play->state.gfxCtx);
        gDPPipeSync(POLY_XLU_DISP++);
        suMtxMakeTS(temp_s1, temp_fv0, temp_fv0, temp_fv0, D_FLT_80A81250_jp[i].x, D_FLT_80A81250_jp[i].y, D_FLT_80A81250_jp[i].z);
        gSPMatrix(POLY_XLU_DISP++, temp_s1, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPMatrix(POLY_XLU_DISP++, game_play->unk_1E9C, G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
        gDPSetPrimColor(POLY_XLU_DISP++, 0, 0xFF, this->unk_174[i].color.r, this->unk_174[i].color.g, this->unk_174[i].color.b, this->unk_174[i].color.a);
        gSPDisplayList(POLY_XLU_DISP++, &D_60040E8);
        AC_GCN_CLOSE_DISP(game_play->state.gfxCtx);
    }
}

Gfx* func_80A80370_jp(u8 arg0, u8 arg1, u8 arg2, u8 arg3, u8 arg4, u8 arg5, u8 arg6, u8 arg7, u8 arg8, Game_Play* game_play) {
    GraphicsContext* gfxCtx = game_play->state.gfxCtx;
    Gfx* gfx;

    gfx = GRAPH_ALLOC(gfxCtx, 32);

    if (gfx) {
        gDPPipeSync(gfx);
        gDPSetPrimColor(gfx + 1, 0, arg4, arg0, arg1, arg2, arg3);
        gDPSetEnvColor(gfx + 2, arg5, arg6, arg7, arg8);
        gSPEndDisplayList(gfx + 3);
        return gfx;
    }
    return NULL;
}

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
