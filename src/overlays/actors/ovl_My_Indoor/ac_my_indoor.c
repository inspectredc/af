#include "ac_my_indoor.h"
#include "m_actor_dlftbls.h"
#include "m_object.h"
#include "overlays/gamestates/ovl_play/m_play.h"
#include "m_field_info.h"
#include "m_scene_table.h"
#include "segment_symbols.h"
#include "audio.h"
#include "6C0690.h"
#include "m_kankyo.h"
#include "m_rcp.h"

void My_Indoor_Actor_ct(Actor* thisx, Game_Play* game_play);
void My_Indoor_Actor_dt(Actor* thisx, Game_Play* game_play);
void My_Indoor_Actor_move(Actor* thisx, Game_Play* game_play);
void My_Indoor_Actor_draw(Actor* thisx, Game_Play* game_play);


typedef struct unk_struct {
    uintptr_t segmentStart;
    uintptr_t segmentEnd;
    RomOffset romStart;
    RomOffset romEnd;
    Gfx* unk_10;
    Gfx* unk_14;
    Gfx* unk_18;
} unk_struct;

unk_struct D_809527B0_jp = {
    0x06000000,
    0x060017B0,
    0x013E5000,
    0x013E6770,
    0x06000568,
    0x06000DA0,
    0x06000E58,
};

unk_struct D_809527CC_jp = {
    0x06000000,
    0x06001850,
    0x013E7000,
    0x013E8850,
    0x060005B8,
    0x06000E60,
    0x06000F18,
};

unk_struct D_809527E8_jp = {
    0x06000000,
    0x06001760,
    0x013E9000,
    0x013EA760,
    0x060005B8,
    0x06000DA0,
    0x06000E58,
};

unk_struct* D_80952804_jp[] = {
    &D_809527B0_jp,
    &D_809527CC_jp,
    &D_809527E8_jp,
};

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

s32 func_80951A70_jp(u8 arg0) {
    if (common_data.unk_10001 == 1) {
        return true;
    }
    return false;
}

#define UNK_SIZE_1 (size_t)0x2020
#define UNK_SIZE_2 (size_t)0x1020

void func_80951A9C_jp(My_Indoor* this, Game_Play* game_play) {
    s32 i;
    unk_struct* temp = D_80952804_jp[this->unk_1A4];
    s32 num = game_play->objectExchangeBank.num;
    ObjectStatus* var_s1 = &game_play->objectExchangeBank.status[num];

    //! FAKE
    num = 0;

    {
        size_t size = temp->romEnd - temp->romStart;
    
        if (mSc_secure_exchange_keep_bank(&game_play->objectExchangeBank, 0, ALIGN8(size)) != 0) {
            this->unk_17C = var_s1->segment;
            var_s1++;
        }
    
        for (i = 0; i < 2; i++) {
            if (mSc_secure_exchange_keep_bank(&game_play->objectExchangeBank, 0, UNK_SIZE_2) == 0) {
                break;
            }
            this->unk_188[i] = var_s1->segment;
            var_s1++;
        }
    
        for (i = 0; i < 2; i++) {
            if (mSc_secure_exchange_keep_bank(&game_play->objectExchangeBank, 0, UNK_SIZE_1) == 0) {
                break;
            }
            this->unk_180[i] = var_s1->segment;
            var_s1++;
        }
    }
}


void func_80951BC4_jp(My_Indoor* this, s16 arg0, s16 arg1) {
    s32 i;
    void **vramPtr = this->unk_180;
    
    if (arg1 == 2) {
        for (i = 0; i < 2; i++) {
            if (vramPtr[i] != NULL) {
                DmaMgr_RequestSyncDebug(vramPtr[i], SEGMENT_ROM_START(object_017A1000) + (arg0 * UNK_SIZE_1), UNK_SIZE_1, "../ac_my_indoor.c", 364);
            }
        } 
    } else if (vramPtr[arg1] != NULL) {
        DmaMgr_RequestSyncDebug(vramPtr[arg1], SEGMENT_ROM_START(object_017A1000) + (arg0 * UNK_SIZE_1), UNK_SIZE_1, "../ac_my_indoor.c", 372);
    }
}

void func_80951CDC_jp(My_Indoor* this, s16 arg1, s16 arg2) {
    s32 i;
    void **vramPtr = this->unk_188;

    if (arg2 == 2) {
        for (i = 0; i < 2; i++) {
            if (vramPtr[i] != NULL) {
                DmaMgr_RequestSyncDebug(vramPtr[i], SEGMENT_ROM_START(object_0182A000) + (arg1 * UNK_SIZE_2), UNK_SIZE_2, "../ac_my_indoor.c", 404);
            }
        }
    } else if (vramPtr[arg2] != NULL) {
        DmaMgr_RequestSyncDebug(vramPtr[arg2], SEGMENT_ROM_START(object_0182A000) + (arg1 * UNK_SIZE_2), UNK_SIZE_2, "../ac_my_indoor.c", 416);
    }
}

void func_80951DF4_jp(Actor* thisx) {
    My_Indoor* this = (My_Indoor*)thisx;
    unk_struct* temp_v0 = D_80952804_jp[this->unk_1A4];

    if (this->unk_17C != 0) {
        RomOffset start = temp_v0->romStart;
        size_t size = temp_v0->romEnd - start;
        DmaMgr_RequestSyncDebug(this->unk_17C, start, ALIGN8(size), "../ac_my_indoor.c", 0x1BA);
    }
}

void func_80951E64_jp(My_Indoor* this, Game_Play* game_play) {
    func_80951DF4_jp(&this->actor);
    func_80951CDC_jp(this, this->unk_176, 2);
    func_80951BC4_jp(this, this->unk_174, 2);
    common_data.unk_107B5 = this->unk_174;
}

u16 func_809526D4_jp(u16);
u16 func_8095267C_jp(u16);
void func_80952754_jp();
void func_8095272C_jp();

void func_80951EBC_jp(My_Indoor* this, s32 arg0) {
    if (arg0 != 0) {
        common_data.clip.unk_09C = NULL;
        return;
    }
    common_data.clip.unk_09C = &this->unk_190;
    this->unk_190.actor = &this->actor;
    this->unk_190.unk_04 = func_809526D4_jp;
    this->unk_190.unk_08 = func_8095267C_jp;
    this->unk_190.unk_0C = func_80952754_jp;
    this->unk_190.unk_10 = func_8095272C_jp;
}

void func_80951F14_jp(My_Indoor* this, Game_Play* game_play) {
    s32 var_a1;
    u16 temp_v0;

    temp_v0 = mFI_GetFieldId();
    var_a1 = 0;
    if ((temp_v0 & 0xF000) == 0x6000) {
        var_a1 = temp_v0 - 0x6000;
    }
    switch (common_data.sceneNo) {
        case SCENE_MY_ROOM_S:
            this->unk_1A4 = 0;
            break;
        case SCENE_MY_ROOM_M:
            this->unk_1A4 = 1;
            break;
        case SCENE_MY_ROOM_L:
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
    //! FAKE
    if (this) {}
    if ((this->unk_180[temp_a2] != NULL) && (this->unk_17C != NULL)) {
        OPEN_DISPS(game_play->state.gfxCtx);
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
        CLOSE_DISPS(game_play->state.gfxCtx);
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
        OPEN_DISPS(game_play->state.gfxCtx);
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
        CLOSE_DISPS(game_play->state.gfxCtx);
    }
}

void My_Indoor_Actor_draw(Actor* thisx, Game_Play* game_play) {
    My_Indoor* this = (My_Indoor*)thisx;
    if (this->unk_17C != NULL) {
        func_80952254_jp(this, game_play);
        func_8095205C_jp(this, game_play);
    }
}

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
        if (func_80951A70_jp(playerNumber)) {
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
                sAdo_SysTrgStart(0x11B);
            }
        }
    }
}

void func_8095253C_jp(My_Indoor* this, Game_Play* game_play) {
    char pad[0x4];
    u16 var;
    u16 temp_v0;
    u8 new_var;
    s32 sp20;
    s32 temp_v1;

    if ((this->unk_1B0 != 0) && (game_play->submenu.moveProcIndex == 0)) {
        new_var = common_data.playerNumber;
        this->unk_1B0 = 0;
        if (func_80951A70_jp(new_var)) {
            sp20 = 0;
            temp_v0 = mFI_GetFieldId();
            var = this->unk_1B4;
            if ((temp_v0 & 0xF000) == 0x6000) {
                sp20 = (temp_v0 - 0x6000) & 3;
            }
            if ((var >= 0x2600) && (var < 0x2644)) {
                temp_v1 = this->unk_178 ^ 1;
                this->unk_174 = var - 0x2600;
                this->unk_178 = (u16)temp_v1 & 1;
                func_80951BC4_jp(this, this->unk_174, this->unk_178);
                common_data.homes[sp20].unk_014 = this->unk_174;
                common_data.unk_107B5 = this->unk_174;
                sAdo_SysTrgStart(0x11B);
                func_8009CC00_jp();
            }
        }
    }
}

void My_Indoor_Actor_move(Actor* thisx, Game_Play* game_play) {
    My_Indoor* this = (My_Indoor*)thisx;
    func_80952444_jp(this, game_play);
    func_8095253C_jp(this, game_play);
}

u16 func_8095267C_jp(u16 arg0) {
    Clip_unk_09C* temp_v0 = common_data.clip.unk_09C;
    My_Indoor* my_indoor;
    u16 ret;
    
    if (temp_v0 != NULL) {
        my_indoor = (My_Indoor*)temp_v0->actor;
        if ((my_indoor != NULL) && (my_indoor->unk_1B0 == 0)) {
            ret = my_indoor->unk_174 + 0x2600;
            my_indoor->unk_1B0 = 1;
            my_indoor->unk_1B4 = arg0;
            return ret;
        }
    }
    return 0;
}

u16 func_809526D4_jp(u16 arg0) {
    Clip_unk_09C* temp_v0 = common_data.clip.unk_09C;
    My_Indoor* my_indoor;
    u16 ret;

    if (temp_v0 != NULL) {
        my_indoor = (My_Indoor*)temp_v0->actor;
        if ((my_indoor != NULL) && (my_indoor->unk_1A8 == 0)) {
            ret = my_indoor->unk_176 + 0x2700;
            my_indoor->unk_1A8 = 1;
            my_indoor->unk_1AC = arg0;
            return ret;
        }
    }
    return 0;
}

void func_8095272C_jp() {
    func_809526D4_jp(0x2700);
    func_8095267C_jp(0x2600);
}

void func_80952754_jp() {
    My_Indoor* my_indoor;
    Clip_unk_09C* temp_v0 = common_data.clip.unk_09C;

    if (temp_v0 != NULL) {
        my_indoor = (My_Indoor*)temp_v0->actor;
        if (my_indoor != NULL) {
            func_80951DF4_jp(&my_indoor->actor);
            func_80951CDC_jp(my_indoor, my_indoor->unk_176, 2);
            func_80951BC4_jp(my_indoor, my_indoor->unk_174, 2);
        }
    }
}