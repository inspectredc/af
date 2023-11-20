#include "ac_my_indoor.h"
#include "m_actor_dlftbls.h"
#include "m_object.h"
#include "overlays/gamestates/ovl_play/m_play.h"

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

s32 func_80951A70_jp(s32 arg0) {
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

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_My_Indoor/ac_my_indoor/func_80951E64_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_My_Indoor/ac_my_indoor/func_80951EBC_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_My_Indoor/ac_my_indoor/func_80951F14_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_My_Indoor/ac_my_indoor/My_Indoor_Actor_ct.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_My_Indoor/ac_my_indoor/My_Indoor_Actor_dt.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_My_Indoor/ac_my_indoor/func_8095205C_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_My_Indoor/ac_my_indoor/func_80952254_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_My_Indoor/ac_my_indoor/My_Indoor_Actor_draw.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_My_Indoor/ac_my_indoor/func_80952444_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_My_Indoor/ac_my_indoor/func_8095253C_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_My_Indoor/ac_my_indoor/My_Indoor_Actor_move.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_My_Indoor/ac_my_indoor/func_8095267C_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_My_Indoor/ac_my_indoor/func_809526D4_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_My_Indoor/ac_my_indoor/func_8095272C_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_My_Indoor/ac_my_indoor/func_80952754_jp.s")
