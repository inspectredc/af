#include "ac_douzou.h"
#include "m_actor_dlftbls.h"
#include "m_object.h"
#include "overlays/gamestates/ovl_play/m_play.h"
#include "m_player_lib.h"
#include "overlays/actors/player_actor/m_player.h"
#include "code_variables.h"
#include "m_field_info.h"
#include "6D9D80.h"
#include "m_msg_main.h"
#include "69E2C0.h"


void aDOU_actor_ct(Actor* thisx, Game_Play* game_play);
void aDOU_actor_dt(Actor* thisx, Game_Play* game_play);
void aDOU_actor_init(Actor* thisx, Game_Play* game_play);
void aDOU_actor_draw(Actor* thisx, Game_Play* game_play);

#if 0
ActorProfile Douzou_Profile = {
    /* */ ACTOR_DOUZOU,
    /* */ ACTOR_PART_0,
    /* */ 0,
    /* */ 0x5842,
    /* */ GAMEPLAY_KEEP,
    /* */ sizeof(Douzou),
    /* */ aDOU_actor_ct,
    /* */ aDOU_actor_dt,
    /* */ aDOU_actor_init,
    /* */ aDOU_actor_draw,
    /* */ NULL,
};
#endif

extern BaseSkeletonR* D_80AA6EE0_jp[];
extern f32 D_FLT_80AA6EA4_jp[];
extern f32 D_FLT_80AA6EB4_jp[];

void func_80AA5ED8_jp(Douzou*);
void func_80AA6304_jp(Douzou*, s32);
void func_80AA6744_jp(Douzou*, s32);

void aDOU_actor_ct(Actor* thisx, Game_Play* game_play) {
    Douzou* this = (Douzou*)thisx;
    s32 sp38;
    xyz_t sp2C;
    

    sp38 = common_data.time.season == 3;
    gSegments[6] = (uintptr_t)OS_PHYSICAL_TO_K0(common_data.unk_10098->unk_AC(0x2CU));
    cKF_SkeletonInfo_R_ct(&this->unk_178, D_80AA6EE0_jp[sp38], NULL, this->jointTable, this->morphTable);
    func_80AA6304_jp(this, 1);
    sp2C.x = D_FLT_80AA6EB4_jp[0] + this->actor.world.pos.x;
    sp2C.y = this->actor.world.pos.y;
    sp2C.z = D_FLT_80AA6EA4_jp[0] + this->actor.world.pos.z;
    this->actor.world.pos.y = mCoBG_GetBgY_OnlyCenter_FromWpos2(sp2C, 0.0f);
    this->actor.uncullZoneScale = 850.0f;
    this->actor.unk_140 = 850.0f;
    func_80AA6744_jp(this, 0);
    cKF_SkeletonInfo_R_play(&this->unk_178);
    func_80AA5ED8_jp(this);
}

void aDOU_actor_dt(Actor* thisx, Game_Play* game_play) {
    Douzou* this = (Douzou*)thisx;

    common_data.unk_10098->unk_A8(&common_data.unk_10098->unk_B0, 8, 0x2CU, &this->actor);
    common_data.unk_10098->unk_A8(&common_data.unk_10098->unk_454, 9, 0x59U, &this->actor);
    common_data.unk_10098->unk_A8(&common_data.unk_10098->unk_86C, 8, 0x2CU, &this->actor);
    cKF_SkeletonInfo_R_dt(&this->unk_178);
}

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Douzou/ac_douzou/func_80AA5C30_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Douzou/ac_douzou/func_80AA5D54_jp.s")

extern s32 func_80094C10_jp(s32);
extern s32 func_8009519C_jp(s32);

s32 func_80AA5D94_jp(s32 arg0) {
    s8 pad[0x4];
    PrivateInfo* sp20;
    s8 sp1F;
    s8 sp1E;
    s32 temp_v0;
    s32 unused = arg0 == 0 ? 0 : 0;

    temp_v0 = func_80094C10_jp(arg0);
    sp20 = &common_data.saveFilePrivateInfo[temp_v0];
    sp1F = 0;
    sp1E = 0;
    if ((func_8009519C_jp(temp_v0 & 0xFF) == 0) && (mPr_CheckPrivate(sp20) != 0)) {
        sp1F = sp20->gender;
        sp1E = sp20->unk011[0];
    }
    return (sp1F * 8) + sp1E;
}


void func_80AA5E28_jp(xyz_t arg0) {
    u16* temp_v0;
    u16* sp24;

    temp_v0 = mFI_GetUnitFG(arg0);
    if (temp_v0 != NULL) {
        sp24 = temp_v0;
        mFI_Wpos2DepositOFF(arg0);
        mPB_keep_item(*sp24);
        mFI_SetFG_common(0, arg0, 1);
    }
}
s32 func_80AA5C30_jp(s32);
void func_80AA5ED8_jp(Douzou* this) {
    xyz_t sp44;
    s32 i;

    for (i = 0; i < 4; i++) {
        if (func_80AA5C30_jp(i) != 0) {
            xyz_t_move(&sp44, &this->actor.world.pos);
            sp44.x = sp44.x + D_FLT_80AA6EB4_jp[i];
            sp44.z = sp44.z + D_FLT_80AA6EA4_jp[i];
            func_80AA5E28_jp(sp44);
        }
    }
}

extern xyz_t D_80AA6EE8_jp[];
extern xyz_t D_FLT_80AA6F18_jp[];

s32 func_80AA5FAC_jp(Douzou* this, Game_Play* game_play, s32 arg2, s32 arg3) {
    xyz_t sp54;
    xyz_t sp48;
    xyz_t sp3C;
    f32 rand;

    Matrix_push();
    xyz_t_move(&sp3C, &this->actor.world.pos);
    sp3C.x = sp3C.x + D_FLT_80AA6EB4_jp[arg2];
    sp3C.z = sp3C.z + D_FLT_80AA6EA4_jp[arg2];
    Matrix_translate(sp3C.x, sp3C.y, sp3C.z, 0);

    xyz_t_move(&sp54, &D_80AA6EE8_jp[arg3]);

    rand = (fqrand() - 0.5f);
    sp54.x = sp54.x + D_FLT_80AA6F18_jp[arg3].x * rand;
    rand = (fqrand() - 0.5f);
    sp54.y = sp54.y + D_FLT_80AA6F18_jp[arg3].y * rand;
    rand = (fqrand() - 0.5f);
    sp54.z = sp54.z + D_FLT_80AA6F18_jp[arg3].z * rand;
    Matrix_Position(&sp54, &sp48);
    common_data.unk_1009C->unk_00(0x66, sp48, 1, 0, game_play, 0x5842, arg3, 0);
    Matrix_pull();
    return 1;
}

extern f32 D_FLT_80AA6F48_jp[];
extern f32 D_FLT_80AA6F58_jp[];
u32 func_80AA5D54_jp(s32);

#ifdef NON_MATCHING
void func_80AA6164_jp(Douzou* this, Game_Play* game_play) {
    s16 sp58[4];
    s32 i;

    sp58[0] = this->unk_2C8;
    sp58[1] = this->unk_2CC;
    sp58[2] = this->unk_2D0;
    sp58[3] = this->unk_2D4;
    
    for (i = 0; i < 4; i++) {
        if (func_80AA5C30_jp(i)) {
            s32 temp_s2;
            
            if (sp58[i] == 0) {
                temp_s2 = func_80AA5D54_jp(i);
                sp58[i] = RANDOM_F(D_FLT_80AA6F58_jp[temp_s2]) + D_FLT_80AA6F48_jp[temp_s2];
                func_80AA5FAC_jp(this, game_play, i, temp_s2);
            } else {
                sp58[i]--;
            }
        }
    }

    this->unk_2C8 = sp58[0];
    this->unk_2CC = sp58[1];
    this->unk_2D0 = sp58[2];
    this->unk_2D4 = sp58[3];
}
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Douzou/ac_douzou/func_80AA6164_jp.s")
#endif

void func_80AA6304_jp(Douzou* this, s32 arg0) {
    xyz_t sp4C;
    s32 i;
    s32 unused = (arg0 == 0) ? 0 : 0;

    for (i = 0; i < 4; i++) {
        if (func_80AA5C30_jp(i) != 0) {
            xyz_t_move(&sp4C, &this->actor.home.pos);
            sp4C.x += D_FLT_80AA6EB4_jp[i];
            sp4C.z += D_FLT_80AA6EA4_jp[i];
            func_800739FC_jp(sp4C, 9, 0x64);
        }
    }
}

extern s32 func_800B785C_jp(xyz_t*, s32);
extern void func_8007B908_jp(s32);

void func_80AA63E4_jp(Douzou* this) {
    s32 sp2C;
    xyz_t sp20;
    Color_RGBA8 sp1C;
    s32 sp18;

    sp2C = mMsg_Get_base_window_p();
    sp18 = func_80094C10_jp(this->unk_2C0);
    if ((func_8009519C_jp(sp18 & 0xFF) == 0) && (func_800B785C_jp(&sp20, sp18) != 0)) {
        mMsg_Set_free_str(sp2C, 0, &sp20, 6);
    }
    func_8007B908_jp(0);
    mDemo_Set_msg_num(0x136B);
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

extern s32 func_8007B410_jp();
#define	ABS_2(d)		((d) >= 0) ? (d) : -(d)

#ifdef NON_MATCHING
void func_80AA64A4_jp(Actor* thisx, Game_Play* game_play) {
    Player* player;
    s32 i;
    f32 temp_fs0;
    xyz_t sp78;
    xyz_t sp6C;
    s_xyz sp64;
    s32 var_v0;
    s16 sp5E;
    s16 temp_a1;
    Douzou* this = (Douzou*)thisx;

    player = get_player_actor_withoutCheck(game_play);
    if (mDemo_Check(8, &this->actor) == 1) {
        i = this->unk_2C0;
        xyz_t_move(&sp78, &this->actor.world.pos);
        sp78.x += D_FLT_80AA6EB4_jp[i];
        sp78.z += D_FLT_80AA6EA4_jp[i];
        temp_a1 = search_position_angleY(&player->actor.world.pos, &sp78);
        sp5E = player->actor.shape.rot.y;
        add_calc_short_angle2(&sp5E, temp_a1, 0.3f, 0x1000, 0);
        sp64.x = player->actor.shape.rot.x;
        sp64.y = sp5E;
        sp64.z = player->actor.shape.rot.z;
        get_player_actor_withoutCheck((Game_Play* ) gamePT)->unk_123C(gamePT, 0, &sp64, 0x20);
    } else if (chkTrigger(0x8000) != 0) {
        var_v0 = ABS_2(player->actor.shape.rot.y);
        if (var_v0 >= 0x6000 && (func_8007B410_jp() == 0)) {
            xyz_t_move(&sp6C, &this->actor.world.pos);
            for (i = 0; i < 4; i++) {
                if (func_80AA5C30_jp(i) != 0) {
                    sp78.x = D_FLT_80AA6EB4_jp[i] + sp6C.x;
                    sp78.z = D_FLT_80AA6EA4_jp[i] + sp6C.z;
                    temp_fs0 = search_position_distanceXZ(&player->actor.world.pos, &sp78);
                    sp5E = search_position_angleY(&sp78, &player->actor.world.pos);
                    if (!(temp_fs0 > 50.0f)) {
                        if (1){if (1){}}
                        var_v0 = ABS_2(sp5E);
                        if (var_v0 < 0x1801) {
                            if (common_data.unk_10A68 == 1) {
                                common_data.unk_10A69 = 4;
                            } else {
                                this->unk_2C0 = i;
                                mDemo_Request(8, &this->actor, &func_80AA63E4_jp);
                            }
                            return;
                        }
                    }
                }
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Douzou/ac_douzou/func_80AA64A4_jp.s")
#endif

extern BaseAnimationR* D_80AA6F68_jp[];
extern DouzouActionFunc D_80AA6F70_jp[];

void func_80AA6744_jp(Douzou* this, s32 arg0) {
    s32 var;

    var = common_data.time.season == 3;
    cKF_SkeletonInfo_R_init(&this->unk_178, this->unk_178.skeleton, D_80AA6F68_jp[var], 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, ANIMATION_REPEAT, NULL);
    this->unk_2A0 = D_80AA6F70_jp[arg0];
    this->unk_2B4 = arg0;
}

void func_80AA67DC_jp(Douzou* this, Game_Play* game_play) {
    gSegments[6] = (uintptr_t)OS_PHYSICAL_TO_K0(common_data.unk_10098->unk_AC(0x2CU));
    this->unk_174 = cKF_SkeletonInfo_R_play(&this->unk_178);
    this->unk_1E8 = this->unk_178.frameControl.currentFrame;
    this->unk_2A0(this, game_play);
    func_80AA6164_jp(this, game_play);
}

void aDOU_actor_init(Actor* thisx, Game_Play* game_play) {
    Douzou* this = (Douzou*)thisx;
    
    mFI_SetFG_common(0xF109, this->actor.home.pos, 0);
    func_80AA67DC_jp(this, game_play);
    this->actor.update = func_80AA67DC_jp;
}

extern Color_RGBA8 D_80AA6F74_jp[];
extern Color_RGBA8 D_80AA6F84_jp[];
extern f32 D_FLT_80AA6F94_jp[];

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

s32 func_80AA68D0_jp(Game_Play* game_play, s32 arg1, s32 arg2, s32* arg3, s32 arg4, Actor* thisx) {
    GraphicsContext* gfxCtx = game_play->state.gfxCtx;
    f32 scale;
    s32 var_v0;
    s32 temp_v1;
    Douzou* this = (Douzou*)thisx;

    var_v0 = 0;
    temp_v1 = this->unk_2BC;
    if (arg2 == 2) {
        scale = D_FLT_80AA6F94_jp[temp_v1];
        Matrix_scale(scale, scale, scale, 1);
        var_v0 = 0;
    }
    if ((arg2 == 2) || (arg2 == 3) || (arg2 == 4)) {
        if (this->unk_2B8 >= 8) {
            *arg3 = 0;
        } else {
            var_v0 = 1;
        }
    } else if ((arg2 == 5) || (arg2 == 6) || (arg2 == 7)) {
        if (this->unk_2B8 < 8) {
            *arg3 = 0;
        } else {
            var_v0 = 1;
        }
    }
    AC_GCN_OPEN_DISP(gfxCtx);
    if ((var_v0 != 0) || (arg2 == 8)) {
        if (1) {}
        OPEN_CUSTOM_POLY_OPA();
        if (1) {}
        gDPPipeSync(__polyOpa++);
        gDPSetEnvColor(__polyOpa++, D_80AA6F84_jp[temp_v1].r, D_80AA6F84_jp[temp_v1].g, D_80AA6F84_jp[temp_v1].b, 0xFF);
        gDPSetPrimColor(__polyOpa++, 0, 0xFF, D_80AA6F74_jp[temp_v1].r, D_80AA6F74_jp[temp_v1].g, D_80AA6F74_jp[temp_v1].b, D_80AA6F74_jp[temp_v1].a);
        CLOSE_CUSTOM_POLY_OPA();
    }
    AC_GCN_CLOSE_DISP(gfxCtx);
    return 1;
}

#define GRAPH_ALLOC_2(gfxCtx, size) ((void*)((gfxCtx)->polyOpa.d = (Gfx*)((u8*)(gfxCtx)->polyOpa.d - size)))

extern void* D_80AA6DA4_jp[];
extern void* D_80AA6E24_jp[];
extern void* D_80AA6ECC_jp[];

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Douzou/ac_douzou/aDOU_actor_draw.s")
