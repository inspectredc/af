#include "ac_fuusen.h"
#include "m_actor_dlftbls.h"
#include "m_actor_shadow.h"
#include "m_object.h"
#include "overlays/gamestates/ovl_play/m_play.h"
#include "overlays/actors/player_actor/m_player.h"
#include "libc/math.h"
#include "macros.h"

void aFSN_actor_ct(Actor* thisx, Game_Play* game_play);
void aFSN_actor_dt(Actor* thisx, Game_Play* game_play);
void aFSN_actor_move(Actor* thisx, Game_Play* game_play);
void aFSN_actor_draw(Actor* thisx, Game_Play* game_play);
void func_80AADEC4_jp(Fuusen*, s32, Game_Play*);

#if 0
ActorProfile Fuusen_Profile = {
    /* */ ACTOR_FUUSEN,
    /* */ ACTOR_PART_7,
    /* */ ACTOR_FLAG_10,
    /* */ 0x0000,
    /* */ OBJECT_400,
    /* */ sizeof(Fuusen),
    /* */ aFSN_actor_ct,
    /* */ aFSN_actor_dt,
    /* */ aFSN_actor_move,
    /* */ aFSN_actor_draw,
    /* */ NULL,
};
#endif

extern void mAc_ActorShadowCircle(Actor*, LightsN*, Game_Play*);
extern f32 func_80072F9C_jp(xyz_t*);
extern BaseAnimationR D_6000F44;
extern BaseSkeletonR D_6000F88;
extern xyz_t D_80AAE4D4_jp;

void aFSN_actor_ct(Actor* thisx, Game_Play* game_play) {
    Fuusen* this = (Fuusen*)thisx;
    SkeletonInfoR *skeletonInfo = &this->skeletonInfo;
    xyz_t sp34;
    f32 sp30;
    sp34 = D_80AAE4D4_jp;
    sp30 = func_80072F9C_jp(&this->actor.world.pos);
    this->unk_184 = 0x3E8;
    cKF_SkeletonInfo_R_ct(skeletonInfo, &D_6000F88, &D_6000F44, this->jointTable, this->morphTable);
    cKF_SkeletonInfo_R_init_standard_repeat(skeletonInfo, Lib_SegmentedToVirtual(&D_6000F44), NULL);
    Shape_Info_init(&this->actor, 0.0f, mAc_ActorShadowCircle, 10.0f, 10.0f);
    this->actor.shape.unk_2C = 0;
    cKF_SkeletonInfo_R_play(skeletonInfo);
    skeletonInfo->frameControl.speed = 1.0f;
    xyz_t_move(&this->actor.scale, &sp34);
    this->actor.world.pos.y = sp30 + 200.0f;
    this->unk_1A0 = 110.0f;
    this->unk_178 = (void* ) game_play->objectExchangeBank.status[this->actor.unk_026].segment;
    this->actor.update = aFSN_actor_move;
    func_80AADEC4_jp(this, 0, game_play);
}

extern void func_80092B7C_jp();
extern void func_80092B8C_jp();

void aFSN_actor_dt(Actor* thisx, Game_Play* game_play) {
    Fuusen* this = (Fuusen*)thisx;
    if (this->unk_190 != 0) {
        func_80092B8C_jp();
        return;
    }
    func_80092B7C_jp();
}

extern s16 func_8009895C_jp();
extern s32 D_80AAE4E0_jp[16];
extern xyz_t D_80AAE520_jp[8];
extern xyz_t D_FLT_80AAE580_jp[8];

void func_80AAD270_jp(Fuusen* this, Game_Play* game_play) {
    s16 var_v0;
    f32 temp_fa1;
    f32 temp_fv0_2;
    f32 sp30;
    f32 temp_fv0;
    s32 var_v1;

    sp30 = func_80072F9C_jp(&this->actor.world.pos);
    this->actor.world.rot.y = func_8009895C_jp();
    var_v0 = this->actor.world.rot.y & 0xF000;
    this->unk_194 = (var_v0 >> 0xC) & 0xF;
    this->unk_194 = D_80AAE4E0_jp[this->unk_194];
    xyz_t_move(&this->actor.world.pos, &D_80AAE520_jp[this->unk_194]);
    this->actor.world.pos.y = (f32) (sp30 + 200.0f);
    this->unk_180 = (u32) ((u32) game_play->unk_1EA0 % 5U);
    this->unk_188 = 0xA;
    var_v1 = false;
    if ((D_FLT_80AAE580_jp[this->unk_194].x != 0.0f) && (D_FLT_80AAE580_jp[this->unk_194].z != 0.0f)) {
        var_v1 = game_play->unk_1EA0 & 1;
    } else if (D_FLT_80AAE580_jp[this->unk_194].z != 0.0f) {
        var_v1 = true;
    }
    if (!var_v1) {
        if (D_FLT_80AAE580_jp[this->unk_194].x != 0.0f) {
            temp_fa1 = fqrand();
            temp_fv0 = fabsf(D_FLT_80AAE580_jp[this->unk_194].x);
            if (D_FLT_80AAE580_jp[this->unk_194].x > 0.0f) {
                this->actor.world.pos.x += temp_fv0 * temp_fa1;
            } else {
                this->actor.world.pos.x -= temp_fv0 * temp_fa1;
            }
        }
    } else {
        if (D_FLT_80AAE580_jp[this->unk_194].z != 0.0f) {
            temp_fa1 = fqrand();
            temp_fv0_2 = fabsf(D_FLT_80AAE580_jp[this->unk_194].z);
            if (D_FLT_80AAE580_jp[this->unk_194].z > 0.0f) {
                this->actor.world.pos.z += temp_fv0_2 * temp_fa1;
            } else {
                this->actor.world.pos.z -= temp_fv0_2 * temp_fa1;
            }
        }
    }
}

void func_80AAD490_jp(Fuusen* this, Game_Play* game_play) {
    this->unk_1A4 = 0;
}

void func_80AAD4A0_jp(Fuusen* this, Game_Play* game_play) {
    this->unk_184 = 0x2631;
    this->actor.speed = 0.0f;
    sAdo_OngenTrgStart(0x402, &this->actor.world.pos, &this->actor);
}

void func_80AAD4DC_jp(Fuusen* this, Game_Play* game_play) {
    f32 temp_fa0;
    f32 temp_fv1;
    Player* player = get_player_actor_withoutCheck(game_play);
    
    temp_fv1 = player->actor.world.pos.x - this->actor.world.pos.x;
    temp_fa0 = player->actor.world.pos.z - this->actor.world.pos.z;
    this->unk_18C = 0;
    this->actor.terminalVelocity = 5.0f;
    this->actor.gravity = 0.5f;
    this->unk_190 = 0;
    if (this->unk_184 == 0x309) {
        this->unk_18C = 1;
        if (sqrtf(SQ(temp_fv1) + SQ(temp_fa0)) < 640.0f) {
            this->unk_190 = 1;
        }
    }
}

void func_80AAD580_jp(Fuusen* this, Game_Play* game_play) {
    func_80AADEC4_jp(this, 1, game_play);
}

extern void func_800765AC_jp(s32, Actor*, f32, f32, s32, s32, s32);
extern s32 func_800884E0_jp(xyz_t*, xyz_t);
extern f32 func_80098980_jp();
extern u16* mFI_GetUnitFG(xyz_t);
extern Vec2s D_80AAE608_jp[3];

void func_80AAD5A4_jp(Actor* thisx, Game_Play* game_play) {
    f32 temp_fa0;
    f32 sp70;
    s32 i;
    f32 temp_fa1;
    xyz_t sp5C;
    f32 temp_fv1_2;
    s16 temp_s1;
    u16* temp_v0_4;
    xyz_t* sp40;
    Fuusen* this = (Fuusen*)thisx;

    sp40 = &this->actor.world.pos;
    sp70 = func_80072F9C_jp(sp40) + this->unk_1A0;
    if (this->unk_184 > 0) {
        this->unk_184 -= 1;
    }
    else {
        if ((this->actor.world.pos.x <= 660.0f) || (this->actor.world.pos.x >= 3820.0f) || (this->actor.world.pos.z <= 660.0f) || (this->actor.world.pos.z >= 4460.0f)) {
            this->unk_184 = 0x309;
            func_80AADEC4_jp(this, 3, game_play);
            return;
        } else if ((this->actor.world.pos.x <= 2440.0f) && (this->actor.world.pos.x >= 2040.0f) && (this->actor.world.pos.z <= 960.0f) && (this->actor.world.pos.z >= 800.0f)) {
            this->unk_184 = 0x309;
            func_80AADEC4_jp(this, 3, game_play);
            return;
        }
    }
    this->unk_19C = func_80098980_jp();
    this->unk_198 += 0x1F4;
    this->actor.speed = (f32) ((this->unk_19C * 0.5f) + 1.0f);
    add_calc(&this->actor.world.pos.y, (sin_s(this->unk_198) * 10.0f) + sp70, 0.3f, 1.0f, 0.0f);
    Game_play_Projection_Trans(game_play, sp40, &sp5C);
    if (!(sp5C.x < -40.0f) && !(sp5C.x > 360.0f) && !(sp5C.y < -40.0f) && !(sp5C.y > 280.0f)) {
        func_800765AC_jp(0, &this->actor, 12.0f, 0, 0, 0, 0);
        if ((((u32) (this->actor.unk_098 << 6) >> 0x1B) & 1) || (((u32) (this->actor.unk_098 * 2) >> 0x1B) & 1)) {
            this->unk_1A0 = (f32) (this->unk_1A0 + 0.01f);
            if (this->unk_1A0 >= 300.0f) {
                this->unk_1A0 = 300.0f;
            }
        } else {
            if (this->unk_1A0 > 110.0f) {
                this->unk_1A0 -= 0.01f;
            }
        }
        temp_v0_4 = mFI_GetUnitFG(*sp40);
        if ((temp_v0_4 != NULL) && ((*temp_v0_4 == 0x804) || (*temp_v0_4 == 0x809) || (*temp_v0_4 == 0x811) || (*temp_v0_4 == 0x819) || (*temp_v0_4 == 0x821) || (*temp_v0_4 == 0x829) || (*temp_v0_4 == 0x80A) || (*temp_v0_4 == 0x812) || (*temp_v0_4 == 0x81A) || (*temp_v0_4 == 0x822) || (*temp_v0_4 == 0x82A) || (*temp_v0_4 == 0x80B) || (*temp_v0_4 == 0x813) || (*temp_v0_4 == 0x81B) || (*temp_v0_4 == 0x823) || (*temp_v0_4 == 0x82B))) {
            func_800884E0_jp(&sp5C, *sp40);
            sp5C.x -= 2.5f;
            sp5C.y = mCoBG_GetBgY_OnlyCenter_FromWpos2(*sp40, 0.0f) + 97.5f;
            sp5C.z += 7.5f;
            temp_fv1_2 = sp5C.x - this->actor.world.pos.x;
            temp_fa1 = sp5C.y - this->actor.world.pos.y;
            temp_fa0 = sp5C.z - this->actor.world.pos.z;
            if ((sqrtf(SQ(temp_fv1_2) + SQ(temp_fa0)) < 15.0f) && (sqrtf(SQ(temp_fa1)) < 15.0f)) {
                func_80AADEC4_jp(this, 2, game_play);
            }
        } else {
            if (this->unk_1A4 == 0) {
dummy_label:
                for (i = 0; i < ARRAY_COUNT(D_80AAE608_jp); i++) {
                    xyz_t_move(&sp5C, sp40);
                    temp_s1 = D_80AAE608_jp[i].z + this->actor.world.rot.y;
                    sp5C.x += sin_s(temp_s1) * 80.0f;
                    sp5C.z += cos_s(temp_s1) * 80.0f;
                    temp_v0_4 = mFI_GetUnitFG(sp5C);
                    if ((temp_v0_4 != NULL) && ((*temp_v0_4 == 0x804) || (*temp_v0_4 == 0x809) || (*temp_v0_4 == 0x811) || (*temp_v0_4 == 0x819) || (*temp_v0_4 == 0x821) || (*temp_v0_4 == 0x829) || (*temp_v0_4 == 0x80A) || (*temp_v0_4 == 0x812) || (*temp_v0_4 == 0x81A) || (*temp_v0_4 == 0x822) || (*temp_v0_4 == 0x82A) || (*temp_v0_4 == 0x80B) || (*temp_v0_4 == 0x813) || (*temp_v0_4 == 0x81B) || (*temp_v0_4 == 0x823) || (*temp_v0_4 == 0x82B))) {
                        this->actor.world.rot.y = temp_s1;
                        this->unk_1A4 = 1U;
                        break;
                    }
                }
            }
            if (this->unk_1A4 == 0) {
                this->actor.world.rot.y = func_8009895C_jp();
            }
        }
    }
}

extern s32 func_800B5BC0_jp(xyz_t*);
extern c_800B5C10_jp(xyz_t*);

void func_80AADB9C_jp(Fuusen* this, Game_Play* game_play) {
    s32 pad;
    xyz_t sp40;
    xyz_t sp34;
    f32 temp_fa0;
    f32 temp_fv1;

    this->unk_184 -= 1;
    if (this->unk_184 < 0x30A) {
        this->unk_184 = 0x309;
        func_80AADEC4_jp(this, 3, game_play);
    } else {
        func_800884E0_jp(&sp40, this->actor.world.pos);
        xyz_t_move(&sp34, &sp40);
        sp40.x -= 2.5f;
        sp40.y = mCoBG_GetBgY_OnlyCenter_FromWpos2(this->actor.world.pos, 0.0f) + 97.5f;
        sp40.z += 7.5f;
        temp_fv1 = this->actor.world.pos.x - sp40.x;
        temp_fa0 = this->actor.world.pos.z - sp40.z;
        if (sqrtf(SQ(temp_fv1) + SQ(temp_fa0)) > 2.0f) {
            add_calc(&this->actor.world.pos.x, sp40.x, 0.3f, 1.0f, 0.0f);
            add_calc(&this->actor.world.pos.y, sp40.y, 0.3f, 1.0f, 0.0f);
            add_calc(&this->actor.world.pos.z, sp40.z, 0.3f, 1.0f, 0.0f);
        } else if (func_800B5C10_jp(&sp34)) {
            this->actor.shape.rot.z = 0;
            func_80AADEC4_jp(this, 3, game_play);
        } else if (func_800B5BC0_jp(&sp34)) {
            if (!(this->unk_18C & 2)) {
                this->actor.shape.rot.z = 0x1F4;
            } else {
                this->actor.shape.rot.z = 0;
            }
            this->unk_18C += 1;
        } else {
            this->actor.shape.rot.z = 0;
            this->unk_18C = 0;
        }
    }
}

void func_80AADDA8_jp(Fuusen* this, Game_Play* game_play) {
    s32 pad;
    f32 sp48;
    xyz_t sp3C;
    s32 sp38;
    s32 sp34;

    sp48 = func_80072F9C_jp(&this->actor.world.pos);
    if (this->unk_18C == 0) {
        func_800884E0_jp(&sp3C, this->actor.world.pos);
        if ((common_data.unk_10080 != NULL) && (common_data.unk_10080->unk_38 != 0) && func_80088344_jp(&sp38, &sp34, sp3C)) {
            common_data.unk_10080->unk_30(0x251C, sp38, sp34, 1);
            this->unk_18C = 1;
        };
        // ^ FAKE ?
    }
    if (this->unk_18C == 1) {
        if (this->actor.world.pos.y > (sp48 + 500.0f)) {
            Actor_delete(&this->actor);
        }
    }
}

extern void (*D_80AAE614_jp[4])(Fuusen*,Game_Play*);
extern void (*D_80AAE624_jp[4])(Fuusen*,Game_Play*);

void func_80AADEC4_jp(Fuusen* this, s32 arg0, Game_Play* game_play) {

    this->unk_17C = arg0;
    this->unk_174 = D_80AAE624_jp[arg0];
    D_80AAE614_jp[arg0](this, game_play);
}

void func_80AADF10_jp(Fuusen* this, Game_Play* game_play) {
    s32 pad;
    void* sp20;
    SkeletonInfoR* sp18;

    sp20 = game_play->objectExchangeBank.status[this->actor.unk_026].segment;
    if (this->unk_178 != sp20) {
        sp18 = &this->skeletonInfo;
        sp18->skeleton = Lib_SegmentedToVirtual(&D_6000F88);
        sp18->animation = Lib_SegmentedToVirtual(&D_6000F44);
        this->unk_178 = sp20;
    }
}

extern s32 D_80106E10_jp;
extern void Debug_Display_new(f32, f32, f32, s32, s32, s32, f32, f32, f32, s32, s32, s32, s32, s32, GraphicsContext*);

void aFSN_actor_move(Actor* thisx, Game_Play* game_play) {
    s32 pad;
    Fuusen* this = (Fuusen*)thisx;
    s32 pad2;
    Player* sp58;

    func_80AADF10_jp(this, game_play);
    if (this->unk_188 == 0) {
        Actor_position_moveF(&this->actor);
    } else if (this->unk_188 > 0) {
        this->unk_188--;
    }
    if (D_80106E10_jp != 0) {
        sp58 = get_player_actor_withoutCheck(game_play);
        Debug_Display_new((sin_s((s16) (this->actor.yawTowardsPlayer + 0x8000)) * 30.0f) + sp58->actor.world.pos.x, sp58->actor.world.pos.y + 60.0f, (cos_s((s16) (this->actor.yawTowardsPlayer + 0x8000)) * 30.0f) + sp58->actor.world.pos.z, 0, this->actor.yawTowardsPlayer + 0x8000, 0, 1.0f, 1.0f, 1.0f, 0xFA, 0x64, 0x78, 0x80, 4, game_play->state.gfxCtx);
    }
    cKF_SkeletonInfo_R_play(&this->skeletonInfo);
    this->unk_174(this, game_play);
    D_80106E10_jp = 0;
}

Gfx* func_80AAE10C_jp(u8 arg0, u8 arg1, u8 arg2, u8 arg3, Game_Play* game_play) {
    GraphicsContext* gfxCtx = game_play->state.gfxCtx;
    Gfx* gfx;
    gfx = GRAPH_ALLOC(gfxCtx, 1);
    if (gfx) {
        gDPSetPrimColor(gfx, 0, 0xFF, arg0, arg1, arg2, arg3);
        gSPEndDisplayList(gfx + 1);
        return gfx;
    }
    return NULL;
}

extern void _texture_z_light_fog_prim(GraphicsContext*);
extern s32 func_80060970_jp();
extern s32 func_80060B18_jp(f32, f32, f32);
extern void mAc_ActorShadowDraw_ShadowDrawFlagOn(Actor*, Game_Play*, s32, xyz_t, f32);

extern s32 D_4009580;
extern s32 D_4009620;
extern Color_RGBA8 D_80AAE5E0_jp[5];
extern Color_RGBA8 D_80AAE5F4_jp[5];
extern xyz_t D_80AAE634_jp;

#define OPEN_CUSTOM_POLY_OPA()                \
    {                                         \
        Gfx* __polyOpa = __gfxCtx->polyOpa.p; \
        int __opa_opened = 0;                 \
        do {} while (0)

#define CLOSE_CUSTOM_POLY_OPA()          \
        __gfxCtx->polyOpa.p = __polyOpa; \
        (void)__opa_opened;              \
    }                                    \
    while (0)

void aFSN_actor_draw(Actor* thisx, Game_Play* game_play) {
    Fuusen* this = (Fuusen*)thisx;
    s32 sp58;
    char pad[0x8];
    s16 objBankIndex;
    Gfx* sp48;
    Gfx* sp44;
    sp58 = game_play->state.unk_A0 & 1;
    objBankIndex = this->actor.unk_026;
    sp48 = game_play->objectExchangeBank.status[objBankIndex].segment;
    sp44 = func_80AAE10C_jp(D_80AAE5E0_jp[this->unk_180].r, D_80AAE5E0_jp[this->unk_180].g, D_80AAE5E0_jp[this->unk_180].b, D_80AAE5E0_jp[this->unk_180].a, game_play);
    if ((sp44 != NULL) && ((func_80060970_jp() == 0) || (func_80060B18_jp(this->actor.world.pos.x, this->actor.world.pos.z, 60.0f) == 0))) {
        func_80AADF10_jp(this, game_play);
        Matrix_push();
        if ((this->unk_17C != 3) || (this->unk_184 == 0x309) || ((this->unk_17C == 3) && (this->unk_18C == 0))) {
            _texture_z_light_fog_prim(game_play->state.gfxCtx);
            OPEN_DISPS(game_play->state.gfxCtx);
            OPEN_CUSTOM_POLY_OPA();
            Matrix_translate(this->actor.world.pos.x, this->actor.world.pos.y, this->actor.world.pos.z, 0U);
            Matrix_scale(0.01f, 0.01f, 0.01f, 1U);
            Matrix_RotateX(this->actor.shape.rot.x, MTXMODE_APPLY);
            Matrix_RotateZ(this->actor.shape.rot.z, MTXMODE_APPLY);
            Matrix_RotateY(this->actor.shape.rot.y, MTXMODE_APPLY);
            gSPMatrix(__polyOpa++, _Matrix_to_Mtx_new(game_play->state.gfxCtx), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gSPDisplayList(__polyOpa++, &D_4009580);
            gSPDisplayList(__polyOpa++, &D_4009620);
            CLOSE_CUSTOM_POLY_OPA()
            CLOSE_DISPS(game_play->state.gfxCtx);
        }
        OPEN_DISPS(game_play->state.gfxCtx);
        gSPSegment(POLY_OPA_DISP++, 0x06, sp48);
        gSPSegment(POLY_OPA_DISP++, 0x08, sp44);
        gDPPipeSync(POLY_OPA_DISP++);
        gDPSetEnvColor(POLY_OPA_DISP++, D_80AAE5F4_jp[this->unk_180].r, D_80AAE5F4_jp[this->unk_180].g, D_80AAE5F4_jp[this->unk_180].b, D_80AAE5F4_jp[this->unk_180].a);
        CLOSE_DISPS(game_play->state.gfxCtx);
        Setpos_HiliteReflect_init(&this->actor.world.pos, game_play);
        cKF_Si3_draw_R_SV(game_play, &this->skeletonInfo, this->unk_248[sp58], NULL, NULL, &this->actor);
        mAc_ActorShadowDraw_ShadowDrawFlagOn(&this->actor, game_play, 0, D_80AAE634_jp, 170.0f);
        Matrix_pull();
    }
}
