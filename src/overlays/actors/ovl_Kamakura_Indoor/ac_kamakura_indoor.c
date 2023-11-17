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

extern Gfx D_6001148;
extern Gfx D_6001230;

void func_80A80440_jp(Kamakura_Indoor* this, Game_Play* game_play) {
    Gfx* sp54;
    Gfx* sp50;

    
    sp54 = func_80A80370_jp(this->unk_184[0].color.r, this->unk_184[0].color.g, this->unk_184[0].color.b, this->unk_184[0].color.a, 0x80, 0xFF, 0x32, 0, 0xFF, game_play);
    sp50 = func_80A80370_jp(this->unk_184[1].color.r, this->unk_184[1].color.g, this->unk_184[1].color.b, this->unk_184[1].color.a, 0x80, 0xFF, 0x32, 0, 0xFF, game_play);
    if ((sp54) && (sp50)) {
        _texture_z_light_fog_prim(game_play->state.gfxCtx);
        _texture_z_light_fog_prim_xlu(game_play->state.gfxCtx);
        func_800981B8_jp(game_play);
        AC_GCN_OPEN_DISP(game_play->state.gfxCtx);
        if (1) { } if (1) { } if (1) { }
        Matrix_translate(0.0f, 0.0f, 0.0f, 0);
        Matrix_scale(0.05f, 0.05f, 0.05f, 1);
        gSPMatrix(POLY_XLU_DISP++, _Matrix_to_Mtx_new(game_play->state.gfxCtx), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPMatrix(POLY_OPA_DISP++, _Matrix_to_Mtx_new(game_play->state.gfxCtx), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPSegment(POLY_XLU_DISP++, 0x09, Lib_SegmentedToVirtual(this->unk_184[0].unk_0));
        gSPSegment(POLY_XLU_DISP++, 0x08, sp54);
        gSPSegment(POLY_XLU_DISP++, 0x0A, Lib_SegmentedToVirtual(this->unk_184[1].unk_0));
        gSPSegment(POLY_XLU_DISP++, 0x0B, sp50);
        gSPDisplayList(POLY_OPA_DISP++, &D_6001230);
        gSPDisplayList(POLY_XLU_DISP++, &D_6001148);
        AC_GCN_CLOSE_DISP(game_play->state.gfxCtx);
    }
}

extern Gfx D_6004308;
extern xyz_t D_80A81268_jp[2];

void func_80A806B8_jp(Kamakura_Indoor* this, Game_Play* game_play) {
    s32 i;

    for (i = 0; i < 2; i++) {
        AC_GCN_OPEN_DISP(game_play->state.gfxCtx);
        Matrix_translate(D_80A81268_jp[i].x, D_80A81268_jp[i].y + this->unk_1F8[i], D_80A81268_jp[i].z, 0);
        Matrix_scale(this->unk_1E0[i].x, this->unk_1E0[i].y, this->unk_1E0[i].z, 1);
        gSPMatrix(POLY_OPA_DISP++, _Matrix_to_Mtx_new(game_play->state.gfxCtx), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(POLY_OPA_DISP++, &D_6004308);
        AC_GCN_CLOSE_DISP(game_play->state.gfxCtx);
    }
}

void Kamakura_Indoor_Actor_draw(Actor* thisx, Game_Play* game_play) {
    Kamakura_Indoor* this = (Kamakura_Indoor*)thisx;
    func_80A80440_jp(this, game_play);
    func_80A801C8_jp(this, game_play);
    func_80A806B8_jp(this, game_play);
}

f32 func_80A80804_jp(s16 arg0, f32 arg1, s16 arg2, f32 arg3, s16 arg4, s16 arg5) {
    char pad[0x10];
    f32 sp1C;

    if ((arg2 < arg0) || (arg0 == arg2)) {
        return arg1;
    }
    if (arg0 >= arg4) {
        return arg1;
    }
    if (arg4 >= arg2) {
        return arg3;
    }

    sp1C = ABS(arg3 - arg1);

    if (arg5 == 0) {
        if (arg3 <= arg1) {
            return cos_s((((f32) arg4 - arg0) * 1.57f) / ((f32) arg2 - arg0) * 10430.378f) * sp1C + arg3;
        }
        return cos_s(((((f32) arg4 - arg0) * 1.57f) / ((f32) arg2 - arg0) - 1.57f) * 10430.378f) * sp1C + arg1;
    }

    if (arg3 <= arg1) {
        return cos_s(((((f32) arg4 - arg0) * 1.57f) / ((f32) arg2 - arg0) + 1.57f) * 10430.378f) * sp1C + (sp1C + arg3);
    }

    return cos_s(((((f32) arg4 - arg0) * 1.57f) / ((f32) arg2 - arg0) - 3.14f) * 10430.378f) * sp1C + (sp1C + arg1);
}

f32 func_80A80A9C_jp(s16 arg0, f32 arg1, s16 arg2, f32 arg3, s16 arg4) {
    char pad[0x18];
    f32 sp24;
    f32 sp1C;

    if ((arg2 < arg0) || (arg0 == arg2)) {
        return arg1;
    }
    if (arg0 >= arg4) {
        return arg1;
    }
    if (arg4 >= arg2) {
        return arg3;
    }

    sp1C = (arg1 + arg3) * 0.5f;
    sp24 = ABS(arg3 - sp1C);
    
    if (arg3 <= arg1) {
        return cos_s((((f32) arg4 - arg0) * 3.14f) / ((f32) arg2 - arg0) * 10430.378f) * sp24 + sp1C;
    }
    
    return cos_s((((f32) arg4 - arg0) * 3.14f) / ((f32) arg2 - arg0) * 10430.378f) * -sp24 + sp1C;
}

#ifdef NON_EQUIVALENT
// https://decomp.me/scratch/nJ5Z7 issues in first for loop
typedef struct unk_struct_1 {
    s16 unk_00;
    f32 unk_04;
    f32 unk_08;
    f32 unk_0C;
    s16 unk_10;
    f32 unk_14;
    f32 unk_18;
    f32 unk_1C;
} unk_struct_1; // size = 0x20

typedef struct unk_struct_2 {
    s32 unk_00;
    s16 unk_04;
    f32 unk_08;
    f32 unk_0C;
    f32 unk_10;
    f32 unk_14;
    s16 unk_18;
    f32 unk_1C;
    f32 unk_20;
    f32 unk_24;
    f32 unk_28;
} unk_struct_2; // size = 0x2C


extern void func_800D1D58_jp(s16, xyz_t*);

extern xyz_t D_80A81268_jp[2];
// new struct unk1C max referenced
extern unk_struct_1 D_80A81280_jp[17];
// new struct size 0x2C
extern unk_struct_2 D_80A814A0_jp[10];
extern Color_RGBA8 D_80A81658_jp[12];
extern void* D_80A81688_jp[12];
extern u32 D_80A816B8_jp[2];
extern u32 D_80A816C0_jp[2];
extern s32 D_80A816C8_jp[2];

void Kamakura_Indoor_Actor_move(Actor* thisx, Game_Play* game_play) {
    Kamakura_Indoor* this = (Kamakura_Indoor*)thisx;
    char pad[0x08];
    s32 j;
    s32 temp_s7;
    u32 temp_hi_2;
    s32 i;
    s32 temp_s3;

    temp_s7 = game_play->state.unk_A0;
    for (i = 0; i < 2; i++) {
        temp_hi_2 = (temp_s7 - D_80A816B8_jp[i]) % 17;

        this->unk_174[i].color.r = 0xFF;
        this->unk_174[i].color.g = (u8) (s32) ABS(func_80A80A9C_jp(D_80A81280_jp[temp_hi_2].unk_00, D_80A81280_jp[temp_hi_2].unk_08, D_80A81280_jp[temp_hi_2].unk_10, D_80A81280_jp[temp_hi_2].unk_18, temp_hi_2));
        this->unk_174[i].color.b = 0;
        this->unk_174[i].color.a = (u8) (s32) ABS(func_80A80A9C_jp(D_80A81280_jp[temp_hi_2].unk_00, D_80A81280_jp[temp_hi_2].unk_0C, D_80A81280_jp[temp_hi_2].unk_10, D_80A81280_jp[temp_hi_2].unk_1C, temp_hi_2));
        this->unk_174[i].unk_4 = func_80A80A9C_jp(D_80A81280_jp[temp_hi_2].unk_00, D_80A81280_jp[temp_hi_2].unk_04, D_80A81280_jp[temp_hi_2].unk_10, D_80A81280_jp[temp_hi_2].unk_14, temp_hi_2);
        
        temp_hi_2 = (temp_s7 - D_80A816C0_jp[i]) % 12;
        this->unk_184[i].unk_0 = D_80A81688_jp[temp_hi_2];
        this->unk_184[i].color = D_80A81658_jp[temp_hi_2];
    }
    // equivalent from here on
    for (i = 0; i < 2; i++) {
        temp_hi_2 = (game_play->state.unk_A0 + D_80A816C8_jp[i]) % 700U;
        if (((temp_hi_2 == 0x17C) || (temp_hi_2 == 0x299)) && (common_data.unk_1009C)) {
            xyz_t sp94;
            sp94 = D_80A81268_jp[i];
            sp94.y += this->unk_1F8[i];
            common_data.unk_1009C->unk_00(0x69, sp94, 2, 0, game_play, 0xFFFF, 0, 0);
        }
        if ((temp_hi_2 == 0x17C) || (temp_hi_2 == 0x299)) {
            xyz_t sp88;
            sp88 = D_80A81268_jp[i];
            sp88.y += this->unk_1F8[i];
            func_800D1D58_jp(0x439, &sp88);
        }


        for (j = 0; j < ARRAY_COUNT(D_80A814A0_jp); j++) {
            if (temp_hi_2 >= D_80A814A0_jp[j].unk_04) {
                if (D_80A814A0_jp[j].unk_18 >= temp_hi_2) {
                    temp_s3 = D_80A814A0_jp[j].unk_00 & 1;
                    if (D_80A814A0_jp[j].unk_00 == 2) {
                        if (common_data.unk_1009C != NULL) {
                            this->unk_1E0[i].x = common_data.unk_1009C->unk_14(temp_hi_2, D_80A814A0_jp[j].unk_04, D_80A814A0_jp[j].unk_18, D_80A814A0_jp[j].unk_08, D_80A814A0_jp[j].unk_1C) * 0.0001f;
                            this->unk_1E0[i].y = common_data.unk_1009C->unk_14(temp_hi_2, D_80A814A0_jp[j].unk_04, D_80A814A0_jp[j].unk_18, D_80A814A0_jp[j].unk_0C, D_80A814A0_jp[j].unk_20) * 0.0001f;
                            this->unk_1E0[i].z = common_data.unk_1009C->unk_14(temp_hi_2, D_80A814A0_jp[j].unk_04, D_80A814A0_jp[j].unk_18, D_80A814A0_jp[j].unk_10, D_80A814A0_jp[j].unk_24) * 0.0001f;
                            this->unk_1F8[i] = common_data.unk_1009C->unk_14(temp_hi_2, D_80A814A0_jp[j].unk_04, D_80A814A0_jp[j].unk_18, D_80A814A0_jp[j].unk_14, D_80A814A0_jp[j].unk_28);
                        }
                    } else {
                        this->unk_1E0[i].x = func_80A80804_jp(D_80A814A0_jp[j].unk_04, D_80A814A0_jp[j].unk_08, D_80A814A0_jp[j].unk_18, D_80A814A0_jp[j].unk_1C, temp_hi_2, temp_s3) * 0.0001f;
                        this->unk_1E0[i].y = func_80A80804_jp(D_80A814A0_jp[j].unk_04, D_80A814A0_jp[j].unk_0C, D_80A814A0_jp[j].unk_18, D_80A814A0_jp[j].unk_20, temp_hi_2, temp_s3) * 0.0001f;
                        this->unk_1E0[i].z = func_80A80804_jp(D_80A814A0_jp[j].unk_04, D_80A814A0_jp[j].unk_10, D_80A814A0_jp[j].unk_18, D_80A814A0_jp[j].unk_24, temp_hi_2, temp_s3) * 0.0001f;
                        this->unk_1F8[i] = func_80A80804_jp(D_80A814A0_jp[j].unk_04, D_80A814A0_jp[j].unk_14, D_80A814A0_jp[j].unk_18, D_80A814A0_jp[j].unk_28, temp_hi_2, temp_s3);
                    }
                }
            }
        }
    }
}
#else
// clang-format off
#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Kamakura_Indoor/ac_kamakura_indoor/Kamakura_Indoor_Actor_move.s")
// clang-format on
#endif
