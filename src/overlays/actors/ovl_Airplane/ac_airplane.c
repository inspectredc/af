#include "ac_airplane.h"
#include "m_actor_dlftbls.h"
#include "m_object.h"
#include "overlays/gamestates/ovl_play/m_play.h"
#include "overlays/actors/player_actor/m_player.h"
#include "m_player_lib.h"

void Airplane_Actor_ct(Actor* thisx, Game_Play* game_play);
void Airplane_Actor_dt(Actor* thisx, Game_Play* game_play);
void Airplane_Actor_move(Actor* thisx, Game_Play* game_play);
void Airplane_Actor_draw(Actor* thisx, Game_Play* game_play);

ActorProfile Airplane_Profile = {
    /* */ ACTOR_AIRPLANE,
    /* */ ACTOR_PART_4,
    /* */ ACTOR_FLAG_10 | ACTOR_FLAG_20,
    /* */ 0x8000,
    /* */ OBJECT_7,
    /* */ sizeof(Airplane),
    /* */ Airplane_Actor_ct,
    /* */ Airplane_Actor_dt,
    /* */ Airplane_Actor_move,
    /* */ Airplane_Actor_draw,
    /* */ NULL,
};

extern void mAc_ActorShadowEllipse(Actor*, LightsN*, Game_Play*);
extern f32 func_80071884_jp(s32, xyz_t, f32);

#ifdef NON_MATCHING
void Airplane_Actor_ct(Actor* thisx, Game_Play* game_play) {
    Airplane* this = (Airplane*)thisx;
    
    Shape_Info_init(thisx, 0.0f, mAc_ActorShadowEllipse, 6.5f, 6.5f);

    this->unk_174 = 5;
    this->unk_178 = 6.2f;
    this->actor.speed = 6.2f;
    this->unk_17C = 0.0f;
    this->unk_188 = BINANG_TO_RAD(RAD_TO_DEG(thisx->world.rot.y));

    this->unk_19C = 0;
    this->unk_1A0 = 0;
    this->unk_1A4 = 0;
    this->unk_1A8 = NULL;
    this->unk_190 = 0.0f;
    this->unk_18C = 0.0f;

    this->unk_180 = this->unk_188;
    this->unk_184 = this->unk_188;       

    this->actor.world.pos.y = func_80071884_jp(0, this->actor.world.pos, -5.5f);
}
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Airplane/ac_airplane/Airplane_Actor_ct.s")
#endif

void Airplane_Actor_dt(Actor* thisx, Game_Play* game_play) {
    Airplane* this = (Airplane* ) thisx;

}

extern Gfx* D_60000B0;

#define AC_GCN_OPEN_DISP(gfxCtx)            \
    {                                       \
        GraphicsContext *__gfxCtx = gfxCtx; \
        int __gfx_opened = 0;               \
        do {} while (0)

#define AC_GCN_CLOSE_DISP(gfxCtx) \
        (void)__gfx_opened;       \
    }                             \
    do {} while (0)

#ifdef NON_MATCHING
void Airplane_Actor_draw(Actor* thisx, Game_Play* game_play) {
    Airplane* this = (Airplane* ) thisx;

    if ((this->unk_174 != 6) && (this->unk_174 != 4)) {
        AC_GCN_OPEN_DISP(game_play->state.gfxCtx);
        _texture_z_light_fog_prim(game_play->state.gfxCtx);
        Matrix_RotateX(RAD_TO_BINANG(BINANG_TO_RAD(this->unk_18C)), MTXMODE_APPLY);
        Matrix_RotateZ(RAD_TO_BINANG(BINANG_TO_RAD(this->unk_190)), MTXMODE_APPLY);
        Matrix_scale(50.0f, 50.0f, 50.0f, 1);
        gSPMatrix(POLY_OPA_DISP++, _Matrix_to_Mtx_new(game_play->state.gfxCtx), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(POLY_OPA_DISP++, &D_60000B0);
        if (1) {} if (1) {}
        AC_GCN_CLOSE_DISP(game_play->state.gfxCtx);
    }
}
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Airplane/ac_airplane/Airplane_Actor_draw.s")
#endif

void func_80967B50_jp(f32* arg0, f32 arg1, f32 arg2) {

    *arg0 = *arg0 + ((arg1 - *arg0) * arg2);
}

void func_80967B78_jp(Airplane* this) {
    if (((u32) (this->actor.unk_098 << 6) >> 0x1B) != 0) {
        this->unk_174 = 1;
    }
}

void func_80967B9C_jp(Airplane* this, Game_Play* game_play) {
    if (((u32) this->actor.unk_098 >> 0x1F) != 0) {
        func_80967B50_jp(&this->unk_178, 0.0f, 0.6f);
        if (this->unk_178 < 1.0f) {
            this->unk_174 = 5;
            this->unk_178 = 0.0f;
            if (this->unk_19C >= 5) {
                this->unk_19C = 0;
                common_data.unk_1009C->unk_00(1, this->actor.world.pos, 1, this->actor.world.rot.y, game_play, this->actor.fgName, 0, 8);
            }
            this->unk_19C++;
        }
    }
}

void func_80967C8C_jp(Airplane* this, Game_Play* game_play) {
    func_80967B50_jp(&this->unk_178, 3.0f, 0.01f);
    func_80967B50_jp(&this->unk_18C, 19.0f, 0.045f);
    func_80967B50_jp(&this->unk_190, 0.0f, 0.05f);
    func_80967B9C_jp(this, game_play);
    func_80967B78_jp(this);
}

#define	ABS_2(d)		((d) >= 0) ? (d) : -(d)

void func_80967D04_jp(Airplane* this, Game_Play* game_play) {
    f32 var_fv1;

    switch (this->unk_176) {
        case 0:
            func_80967B50_jp(&this->unk_18C, -89.0f, 0.2f);
            func_80967B50_jp(&this->unk_178, 9.0f, 0.1f);
            if (this->unk_18C < -87.0f) {
                this->unk_176 = 1;
                this->unk_18C = 60.0f;
            }
            break;
        case 1:
            func_80967B50_jp(&this->unk_18C, 0.0f, 0.04f);
            func_80967B50_jp(&this->unk_178, 10.0f, 0.1f);
            var_fv1 = ABS_2(this->unk_18C);
    
            if (var_fv1 < 3.0f) {
                this->unk_174 = 0;
                this->unk_176 = 0;
            }
            func_80967B9C_jp(this, game_play);
            break;
        default:
            break;
    }
    func_80967B78_jp(this);
}

s32 func_80967E1C_jp(Airplane* this, s32 arg1) {
    f32 temp_fv0;

    temp_fv0 = fqrand();
    if (arg1 >= 0x44) {
        if ((s32) (temp_fv0 * 7.0f) & 1) {
            this->unk_174 = 2;
        } else {
            this->unk_174 = 3;
            this->unk_176 = 0;
        }
    } else {
        this->unk_174 = 0;
    }
    return 1;
}

static s16 D_80968734_jp[8] = {
    0x093E,
    0x07D2,
    0xFBBC,
    0xF6C2,
    0x0000,
    0x1110,
    0xEFA6,
    0x105A,
};

static s16 D_80968744_jp[8] = {
    0x31C4,
    0x1FFE,
    0xDC74,
    0xE002,
    0xD558,
    0x2AA8,
    0x238C,
    0x0000,
};

// s32 func_80967E1C_jp(f32, Airplane*, s32, s32);
extern void func_800B2414_jp(Game_Play*);
#define	ABS_3(d)		(((d) >= (0,0)) ? (d) : -(d))

void func_80967E98_jp(Airplane* this, Game_Play* game_play) {
    f32 var_fv1;
    s32 sp38;
    Player* player;
    s32 temp_a2;
    s16* var_v0;
    s32 temp_v0;
    s32 var_a1;

    sp38 = getJoystick_Y();
    player = get_player_actor_withoutCheck(game_play);
    temp_a2 = RANDOM_F(8);
    temp_v0 = this->unk_194;
    if ((sp38 - temp_v0) >= 0x1F) {

        var_a1 = ABS_2(temp_v0);

        this->unk_178 = ABS_3((f32) temp_v0) * 0.0875f + 3.0f;
        func_80967E1C_jp(this, var_a1);
        if (var_a1 >= 0x33) {
            var_v0 = D_80968744_jp;
        } else {
            var_v0 = D_80968734_jp;
        }
        this->actor.world.pos.y = player->actor.world.pos.y + 25.0f;
        this->actor.world.pos.x = player->actor.world.pos.x;
        this->actor.world.pos.z = player->actor.world.pos.z;
        this->unk_188 = RAD_TO_DEG(BINANG_TO_RAD(player->actor.shape.rot.y));
        this->unk_180 = RAD_TO_DEG(BINANG_TO_RAD(var_v0[temp_a2])) + this->unk_188;
        this->unk_18C = (f32) ((this->unk_178 * -8.571428f) + 30.0f);
        this->unk_190 = 0.0f;
        this->unk_17C = 0.0f;
        func_800B2414_jp(game_play);
    }
}

void func_80968058_jp(Airplane* this, Game_Play* game_play) {

}

void func_80968068_jp(Airplane* this, Game_Play* game_play) {
    this->unk_178 = 0.0f;
    if ((this->actor.xzDistToPlayer <= 30.0f) && (chkTrigger(0x8000) != 0)) {
        this->unk_174 = 6;
    }
}

void func_809680C8_jp(Airplane* this, Game_Play* arg1) {
    func_80967B50_jp(&this->unk_18C, 60.0f, 0.04f);
    func_80967B50_jp(&this->unk_178, 5.0f, 0.02f);
    this->actor.world.pos.y -= 0.15f;
    if (((u32) this->actor.unk_098 >> 0x1F) != 0) {
        common_data.unk_1009C->unk_00(1, this->actor.world.pos, 1, this->actor.world.rot.y, arg1, this->actor.fgName, 0, 8);
        this->unk_174 = 5;
    }
}

void func_809681A4_jp(Airplane* this, Game_Play* game_play) {
    func_80967B50_jp(&this->unk_18C, 70.0f, 0.15f);
    func_80967B50_jp(&this->unk_178, 10.0f, 0.02f);
    this->actor.world.pos.y -= 0.15f;
    if (((u32) this->actor.unk_098 >> 0x1F) != 0) {
        common_data.unk_1009C->unk_00(1, this->actor.world.pos, 1, this->actor.world.rot.y, game_play, this->actor.fgName, 0, 8);
        this->unk_174 = 5;
    }
}

void func_80968280_jp(Airplane* this) {
    if (this->unk_174 == 0) {
        func_80967B50_jp(&this->unk_190, 0.0f, 0.05f);
        return;
    }
    if (this->unk_188 < this->unk_184) {
        func_80967B50_jp(&this->unk_190, 50.0f, 0.05f);
        return;
    }
    func_80967B50_jp(&this->unk_190, -50.0f, 0.05f);
}

extern void sMath_RotateX(xyz_t*, f32);
extern void sMath_RotateY(xyz_t*, f32);
extern void sMath_RotateZ(xyz_t*, f32);
static xyz_t D_80968754_jp = { 2.0f, 1.0f, 4.0f };
static xyz_t D_80968760_jp = { -3.0f, -4.0f, -7.0f };
static xyz_t D_8096876C_jp = { 4.0f, -3.0f, 1.0f };
static xyz_t D_80968778_jp = { -1.0f, 3.0f, -4.0f };

static xyz_t* D_80968784_jp[4] = {
    &D_80968754_jp,
    &D_80968760_jp,
    &D_8096876C_jp,
    &D_80968778_jp,
};

static s32 D_80968794_jp[10] = {
    0x0000012C,
    0x00000014,
    0x000001F4,
    0x000003E8,
    0x00000064,
    0x000002BC,
    0x00000014,
    0x000000C8,
    0x00000050,
    0x00000046,
};

static xyz_t D_809687BC_jp = { 0.0f, 1.0f, 0.0f };

#ifdef NON_MATCHING
void func_80968304_jp(Actor* thisx, Game_Play* game_play) {
    Airplane* this = (Airplane*)thisx;
    xyz_t sp30;
    s32 sp2C;
    s32 temp_v1;

    sp30 = D_809687BC_jp;
    this->unk_1A0++;
    if (this->unk_1A4 < this->unk_1A0) {
        sp2C = RANDOM_F(4);
        temp_v1 = RANDOM_F(10);
        this->unk_1A0 = 0;
        this->unk_1A4 = D_80968794_jp[temp_v1];
        this->unk_1A8 = D_80968784_jp[sp2C];
    }

    if (this->unk_174 != 5 && this->unk_174 != 4 && this->unk_174 != 6 && this->unk_1A8) {
        sMath_RotateX(&sp30, RAD_TO_DEG(this->unk_18C));
        sMath_RotateZ(&sp30, RAD_TO_DEG(this->unk_190));
        sMath_RotateY(&sp30, RAD_TO_DEG(this->unk_188));
    }
}
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Airplane/ac_airplane/func_80968304_jp.s")
#endif

extern f32 cosf_table(f32);

#ifdef NON_MATCHING
void func_80968464_jp(Actor* actor, Airplane* this, Game_Play* game_play) {

    func_80968280_jp(this);
    actor->speed = cosf_table(RAD_TO_DEG(this->unk_18C)) * this->unk_178;
    this->unk_17C = sinf_table(RAD_TO_DEG(this->unk_18C)) * this->unk_178;

    actor->world.pos.y -= this->unk_17C;
    actor->world.rot.y = RAD_TO_BINANG(RAD_TO_DEG(this->unk_188));
    actor->shape.rot.y = RAD_TO_BINANG(RAD_TO_DEG(this->unk_188));
    Actor_position_moveF(actor);
    
    this->unk_198 = getJoystick_X();
    this->unk_194 = getJoystick_Y();

    switch (this->unk_174) {
        case 4:
        case 6:
            actor->shape.unk_2C = 0;
            break;
        case 0:
        case 1:
        case 2:
        case 3:
            func_80967B50_jp(&this->unk_188, this->unk_180, 0.07f);
            actor->shape.unk_2C = 1;
            break;
        default:
            actor->shape.unk_2C = 1;
            break;
    }
    func_80968304_jp(actor, game_play);
}
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_Airplane/ac_airplane/func_80968464_jp.s")
#endif

extern void func_800B23DC_jp(Game_Play*);
extern void func_800B2414_jp(Game_Play*);

void func_809685B8_jp(Airplane* this, Game_Play* game_play) {
    if (chkButton(0x2000) != 0) {
        if (this->unk_174 == 6) {
            func_800B23DC_jp(game_play);
            this->unk_174 = 4;
        }
    } else if (this->unk_174 == 4) {
        func_800B2414_jp(game_play);
        this->unk_174 = 6;
    }
}

f32 func_80968638_jp(s16 arg0) {
    if ((arg0 == 1) || (arg0 == 5)) {
        return -5.5f;
    }
    return 0.0f;
}

extern void func_800765AC_jp(s32, Actor*, f32, f32, s32, s32, s32);
static AirplaneActionFunc D_809687C8_jp[7] = {
    func_80967C8C_jp,
    func_809680C8_jp,
    func_809681A4_jp,
    func_80967D04_jp,
    func_80967E98_jp,
    func_80968068_jp,
    func_80968058_jp,
};

void Airplane_Actor_move(Actor* thisx, Game_Play* game_play) {
    Airplane* this = (Airplane* ) thisx;
    this->unk_184 = this->unk_188;
    D_809687C8_jp[this->unk_174](this, game_play);
    func_809685B8_jp(this, game_play);
    func_80968464_jp(&this->actor, this, game_play);
    func_800765AC_jp(0, &this->actor, 15.0f, func_80968638_jp(this->unk_174), 0, 0, 0);
}
