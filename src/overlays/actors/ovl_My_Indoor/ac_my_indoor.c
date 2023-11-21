#include "ac_my_indoor.h"
#include "m_actor_dlftbls.h"
#include "m_object.h"
#include "overlays/gamestates/ovl_play/m_play.h"
#include "m_field_info.h"

void My_Indoor_Actor_ct(Actor* thisx, Game_Play* game_play);
void My_Indoor_Actor_dt(Actor* thisx, Game_Play* game_play);
void My_Indoor_Actor_move(Actor* thisx, Game_Play* game_play);
void My_Indoor_Actor_draw(Actor* thisx, Game_Play* game_play);

#if 0
ActorProfile My_Indoor_Profile = {
    /* */ ACTOR_MY_INDOOR,
    /* */ ACTOR_PART_5,
    /* */ ACTOR_FLAG_10 | ACTOR_FLAG_20,
    /* */ 0x0000,
    /* */ GAMEPLAY_KEEP,
    /* */ sizeof(My_Indoor),
    /* */ My_Indoor_Actor_ct,
    /* */ My_Indoor_Actor_dt,
    /* */ My_Indoor_Actor_move,
    /* */ My_Indoor_Actor_draw,
    /* */ NULL,
};
#endif

s32 func_80951A70_jp(u8 arg0) {
    if (common_data.unk_10001 == 1) {
        return 1;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_My_Indoor/ac_my_indoor/func_80951A9C_jp.s")

extern UNK_TYPE D_17A1000;
#define UNK_SIZE_1 0x2020

void func_80951BC4_jp(My_Indoor* this, s16 arg0, s16 arg1) {
    s32 i;
    void **vramPtr;
    vramPtr = this->unk_180;
    if (arg1 == 2) {
        for (i = 0; i < 2; i++) {
            if (vramPtr[i] != NULL) {
                DmaMgr_RequestSyncDebug(vramPtr[i], (uintptr_t)&D_17A1000 + (arg0 * UNK_SIZE_1), UNK_SIZE_1, "../ac_my_indoor.c", 0x16C);
            }
        } 
    } else if (vramPtr[arg1] != NULL) {
        DmaMgr_RequestSyncDebug(vramPtr[arg1], (uintptr_t)&D_17A1000 + (arg0 * UNK_SIZE_1), UNK_SIZE_1, "../ac_my_indoor.c", 0x174);
    }
}

extern UNK_TYPE D_182A000;
#define UNK_SIZE_2 0x1020

void func_80951CDC_jp(My_Indoor* this, s16 arg1, s16 arg2) {
    s32 i;
    void **vramPtr;
    vramPtr = this->unk_188;
    if (arg2 == 2) {
        for (i = 0; i < 2; i++) {
            if (vramPtr[i] != NULL) {
                DmaMgr_RequestSyncDebug(vramPtr[i], (uintptr_t)&D_182A000 + (arg1 * UNK_SIZE_2), UNK_SIZE_2, "../ac_my_indoor.c", 0x194);
            }
        }
    } else if (vramPtr[arg2] != NULL) {
        DmaMgr_RequestSyncDebug(vramPtr[arg2], (uintptr_t)&D_182A000 + (arg1 * UNK_SIZE_2), UNK_SIZE_2, "../ac_my_indoor.c", 0x1A0);
    }
}

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_My_Indoor/ac_my_indoor/func_80951DF4_jp.s")

void func_80951E64_jp(My_Indoor* this, Game_Play* game_play) {
    func_80951DF4_jp(this);
    func_80951CDC_jp(this, this->unk_176, 2);
    func_80951BC4_jp(this, this->unk_174, 2);
    common_data.unk_107B5 = this->unk_174;
}

void func_8095267C_jp(My_Indoor*,Game_Play*);
void func_809526D4_jp(My_Indoor*,Game_Play*);
void func_8095272C_jp(My_Indoor*,Game_Play*);
void func_80952754_jp(My_Indoor*,Game_Play*);

void func_80951EBC_jp(My_Indoor* this, s32 arg0) {
    if (arg0 != 0) {
        common_data.unk_100A8 = NULL;
        return;
    }
    common_data.unk_100A8 = &this->unk_190;
    this->unk_190 = &this->actor;
    this->unk_194 = func_809526D4_jp;
    this->unk_198 = func_8095267C_jp;
    this->unk_19C = func_80952754_jp;
    this->unk_1A0 = func_8095272C_jp;
}

void func_80951F14_jp(My_Indoor* this, Game_Play* game_play) {
    s32 var_a1;
    u16 temp_v0;

    temp_v0 = mFI_GetFieldId();
    var_a1 = 0;
    if ((temp_v0 & 0xF000) == 0x6000) {
        var_a1 = temp_v0 - 0x6000;
    }
    switch (common_data.unk_00014) {
        case 20:
            this->unk_1A4 = 0;
            break;
        case 21:
            this->unk_1A4 = 1;
            break;
        case 22:
            this->unk_1A4 = 2;
            break;
    }
    this->unk_174 = common_data.homes[var_a1].unk_014;
    this->unk_176 = common_data.homes[var_a1].unk_015;
    this->unk_178 = 0;
    this->unk_17A = 0;
    this->unk_17C = NULL;
    this->unk_180[0] = NULL;
    this->unk_180[1] = NULL;
    this->unk_188[0] = NULL;
    this->unk_188[1] = NULL;
}

void My_Indoor_Actor_ct(Actor* thisx, Game_Play* game_play) {
    My_Indoor* this = (My_Indoor*)thisx;
    func_80951F14_jp(this, game_play);
    func_80951A9C_jp(this, game_play);
    func_80951E64_jp(this, game_play);
    func_80951EBC_jp(this, 0);
}

void My_Indoor_Actor_dt(Actor* thisx, Game_Play* game_play) {
    My_Indoor* this = (My_Indoor*)thisx;
    func_80951EBC_jp(this, 1);
}

void func_800981B8_jp(Game_Play*);

typedef struct unk_struct {
    s8 unk_00[0x08];
    RomOffset unk_08;
    RomOffset unk_0C;
    Gfx* unk_10;
    Gfx* unk_14;
    Gfx* unk_18;
} unk_struct;

extern unk_struct* D_80952804_jp[];
#define AC_GCN_OPEN_DISP(gfxCtx)            \
    {                                       \
        GraphicsContext *__gfxCtx = gfxCtx; \
        int __gfx_opened = 0;               \
        do {} while (0)

#define AC_GCN_CLOSE_DISP(gfxCtx) \
        (void)__gfx_opened;       \
    }                             \
    do {} while (0)

void func_8095205C_jp(My_Indoor* this, Game_Play* game_play) {
    GraphicsContext* gfxCtx;
    unk_struct* sp60;
    s16 temp_a2;
    void* sp58;
    void* sp54;
    void* sp50;
    void* sp4C;
    void* sp48;

    sp60 = D_80952804_jp[this->unk_1A4];
    temp_a2 = this->unk_178;
    sp58 = this->unk_180[temp_a2];
    sp54 = (uintptr_t)(this->unk_180[temp_a2]) + 0x20;
    sp50 = (uintptr_t)(this->unk_180[temp_a2]) + 0x820;
    sp4C = (uintptr_t)(this->unk_180[temp_a2]) + 0x1020;
    sp48 = (uintptr_t)(this->unk_180[temp_a2]) + 0x1820;
    func_800981B8_jp(game_play);
    // FAKE!
    if (this) {}
    if ((this->unk_180[temp_a2] != NULL) && (this->unk_17C != NULL)) {
        AC_GCN_OPEN_DISP(game_play->state.gfxCtx);
        _texture_z_light_fog_prim(game_play->state.gfxCtx);
        Matrix_translate(0.0f, 0.0f, 0.0f, 0);
        Matrix_scale(0.05f, 0.05f, 0.05f, 1);
        gSPMatrix(POLY_OPA_DISP++, _Matrix_to_Mtx_new(game_play->state.gfxCtx), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPSegment(POLY_OPA_DISP++, 0x06, this->unk_17C);
        gSPSegment(POLY_OPA_DISP++, 0x08, sp54);
        gSPSegment(POLY_OPA_DISP++, 0x09, sp50);
        gSPSegment(POLY_OPA_DISP++, 0x0A, sp4C);
        gSPSegment(POLY_OPA_DISP++, 0x0B, sp48);
        gSPSegment(POLY_OPA_DISP++, 0x0C, sp58);
        gSPDisplayList(POLY_OPA_DISP++, sp60->unk_10);
        AC_GCN_CLOSE_DISP(game_play->state.gfxCtx);
    }
}

void func_80952254_jp(My_Indoor* this, Game_Play* game_play) {
    s32 pad;
    unk_struct* sp50;
    s16 temp_a2;
    void* sp48;
    void* sp44;
    void* sp40;


    sp50 = D_80952804_jp[this->unk_1A4];
    temp_a2 = this->unk_17A;
    sp44 = (uintptr_t)this->unk_188[temp_a2] + 0x20;
    sp40 = (uintptr_t)this->unk_188[temp_a2] + 0x820;
    sp48 = this->unk_188[temp_a2];
    func_800981B8_jp(game_play);
    if (this->unk_188[temp_a2] != NULL) {
        AC_GCN_OPEN_DISP(game_play->state.gfxCtx);
        _texture_z_light_fog_prim(game_play->state.gfxCtx);
        Matrix_translate(0.0f, 0.0f, 0.0f, 0);
        Matrix_scale(0.05f, 0.05f, 0.05f, 1);
        gSPMatrix(POLY_OPA_DISP++, _Matrix_to_Mtx_new(game_play->state.gfxCtx), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPSegment(POLY_OPA_DISP++, 0x06, this->unk_17C);
        gSPSegment(POLY_OPA_DISP++, 0x08, sp44);
        gSPSegment(POLY_OPA_DISP++, 0x09, sp40);
        gSPSegment(POLY_OPA_DISP++, 0x0A, sp48);
        gSPDisplayList(POLY_OPA_DISP++, sp50->unk_14);
        gSPDisplayList(POLY_OPA_DISP++, sp50->unk_18);
        AC_GCN_CLOSE_DISP(game_play->state.gfxCtx);
    }
}

void My_Indoor_Actor_draw(Actor* thisx, Game_Play* game_play) {
    My_Indoor* this = (My_Indoor*)thisx;
    if (this->unk_17C != NULL) {
        func_80952254_jp(this, game_play);
        func_8095205C_jp(this, game_play);
    }
}

void func_8009CC00_jp();
void func_800D1A9C_jp(s32);
void func_80951CDC_jp(My_Indoor*, s16, s16);

void func_80952444_jp(My_Indoor* this, Game_Play* game_play) {
    char pad[0x4];
    u16 temp_v;
    u16 temp_v0;
    u8 playerNumber;
    s32 sp20;
    u16 temp_v1;

    if ((this->unk_1A8 != 0) && (game_play->submenu.moveProcIndex == 0)) {
        playerNumber = common_data.playerNumber;
        this->unk_1A8 = 0;
        if (func_80951A70_jp(playerNumber) != 0) {
            sp20 = 0;
            temp_v0 = mFI_GetFieldId();
            temp_v = this->unk_1AC;
            if ((temp_v0 & 0xF000) == 0x6000) {
                sp20 = temp_v0 - 0x6000;
            }
            if ((temp_v >= 0x2700) && (temp_v < 0x2744)) {
                temp_v1 = this->unk_17A ^ 1;
                this->unk_176 = temp_v - 0x2700;
                this->unk_17A = (temp_v1 & 0xFFFF) & 1;
                func_80951CDC_jp(this, this->unk_176, this->unk_17A);
                common_data.homes[sp20].unk_015 = this->unk_176;
                func_8009CC00_jp();
                func_800D1A9C_jp(0x11B);
            }
        }
    }
}

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_My_Indoor/ac_my_indoor/func_8095253C_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_My_Indoor/ac_my_indoor/My_Indoor_Actor_move.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_My_Indoor/ac_my_indoor/func_8095267C_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_My_Indoor/ac_my_indoor/func_809526D4_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_My_Indoor/ac_my_indoor/func_8095272C_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_My_Indoor/ac_my_indoor/func_80952754_jp.s")
