#include "ac_ball.h"
#include "m_actor_dlftbls.h"
#include "m_object.h"
#include "m_actor_shadow.h"
#include "overlays/gamestates/ovl_play/m_play.h"
#include "overlays/actors/player_actor/m_player.h"
#include "libc/math.h"
#include "m_npc.h"
#include "audio.h"
#include "6F2150.h"
#include "m_field_info.h"
#include "sys_math_atan.h"
#include "m_player_lib.h"
#include "macros.h"

void aBALL_actor_ct(Actor* thisx, Game_Play* game_play);
void aBALL_actor_dt(Actor* thisx, Game_Play* game_play);
void aBALL_actor_move(Actor* thisx, Game_Play* game_play);
void aBALL_actor_draw(Actor* thisx, Game_Play* game_play);

void func_8096A86C_jp(void);
void func_809698E8_jp(Ball* this, Game_Play* game_play);
void func_809699D8_jp(Ball* this, Game_Play* game_play);
void func_80969998_jp(Ball* this, Game_Play* game_play);
void func_80969FBC_jp(Ball* this, Game_Play* game_play);
void func_80969FD8_jp(Ball* this, Game_Play* game_play);
void func_8096A0CC_jp(Ball* this, Game_Play* game_play);
void func_8096A0EC_jp(Ball* this, Game_Play* game_play);

static Ball* Global_Actor_p;

Gfx* D_8096A8B0_jp[3] = {
    0x060001A8,
    0x06000368,
    0x06000708,
};

ActorProfile Ball_Profile = {
    /* */ ACTOR_BALL,
    /* */ ACTOR_PART_4,
    /* */ ACTOR_FLAG_10,
    /* */ 0x8001,
    /* */ GAMEPLAY_KEEP,
    /* */ sizeof(Ball),
    /* */ aBALL_actor_ct,
    /* */ aBALL_actor_dt,
    /* */ aBALL_actor_move,
    /* */ aBALL_actor_draw,
    /* */ NULL,
};

ClObjPipe_Init aBALL_CoInfoData = { 
    { OC1_1 | OC1_TYPE_8 | OC1_TYPE_10 | OC1_TYPE_20, OC2_TYPE_20, COLSHAPE_PIPE },
    { ELEM_FLAG_1 },
    { { 0xD, 0x1E, -0xA, { 0, 0, 0 } } },
};

CollisionCheck_Status_Init aBALL_StatusData = { 0, 0xD, 0x1E, -0xA, 100, };

extern UNK_TYPE D_1100000;
extern UNK_TYPE D_11003C0;
extern UNK_TYPE D_1101000;
extern UNK_TYPE D_1101770;
extern UNK_TYPE D_1102000;
extern UNK_TYPE D_11029E0;

s32 func_80968A10_jp(Ball* this, Game_Play* game_play, s32 arg0) {
    s32 sp18;
    s32 temp_v1;
    s32 var_a2;

    temp_v1 = game_play->objectExchangeBank.num;
    switch (arg0) {
        case 0:
            var_a2 = (s32)&D_11003C0 - (s32)&D_1100000;
            break;
        case 1:
            var_a2 = (s32)&D_1101770 - (s32)&D_1101000;
            break;
        case 2:
            var_a2 = (s32)&D_11029E0 - (s32)&D_1102000;
            break;
        default:
            var_a2 = (s32)&D_11003C0 - (s32)&D_1100000;
            break;
    }
    sp18 = temp_v1;
    if (mSc_secure_exchange_keep_bank(&game_play->objectExchangeBank, 0, var_a2) != 0) {
        this->unk_1E4 = game_play->objectExchangeBank.status[temp_v1].segment;
        return 1;
    }
    return 0;
}

void func_80968AF4_jp(Ball* this, s32 arg0) {
    s32 var_a1;
    s32 var_v0;

    switch (arg0) {
        case 0:
            var_a1 = &D_1100000;
            var_v0 = &D_11003C0;
            break;
        case 1:
            var_a1 = &D_1101000;
            var_v0 = &D_1101770;
            break;
        case 2:
            var_a1 = &D_1102000;
            var_v0 = &D_11029E0;
            break;
        default:
            var_a1 = &D_1100000;
            var_v0 = &D_11003C0;
            break;
    }
    if ((var_a1 != NULL) && (var_v0 != NULL)) {
        DmaMgr_RequestSyncDebug(this->unk_1E4, var_a1, var_v0 - var_a1, "../ac_ball.c", 0x11D);
    }
}

s32 aBALL_Random_pos_set(xyz_t* arg0) {
    s32 temp_fp;
    s32 temp_s3;
    s32 sp64;
    s32 sp60;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 var_s0;
    s32 var_s2;
    s32 i;
    s32 j;

    temp_fp = mFI_GetBlockXMax();
    temp_s3 = mFI_GetBlockZMax();
    var_s2 = RANDOM_F(temp_fp);
    var_s0 = RANDOM_F(temp_s3);
    for (i = 0; i < temp_fp; i++) {
        for (j = 0; j < temp_s3; j++) {
            if ((mFI_CheckBlockKind_OR(var_s2, var_s0, 0x8023) == 0) && (mNpc_GetMakeUtNuminBlock_hard_area(&sp64, &sp60, var_s2, var_s0, 2) == 1)) {
                mFI_BkandUtNum2CenterWpos(arg0, var_s2, var_s0, sp64, sp60);
                return 1;
            }
            temp_v0 = var_s0 + 1;
            var_s0 = temp_s3;
            if (var_s0 == temp_v0) {
                var_s0 = 0;
            } else {
                var_s0 = temp_v0;
            }
        }
        temp_v0_2 = var_s2 + 1;
        var_s2 = temp_fp;
        if (var_s2 == temp_v0_2) {
            var_s2 = 0;
        } else {
            var_s2 = temp_v0_2;
        }
    }
    return 0;
}

void aBALL_actor_ct(Actor* thisx, Game_Play* game_play) {
    Ball* this = (Ball*)thisx;
    char pad[0x4];

    Global_Actor_p = this;
    if ((common_data.unk_10A6C.x == 0.0f) && (common_data.unk_10A6C.y == 0.0f) && (common_data.unk_10A6C.z == 0.0f)) {

        if (!aBALL_Random_pos_set(&this->actor.world.pos)) {
            this->actor.world.pos = this->actor.home.pos;
        }
        common_data.unk_10A78 = RANDOM_F(3.0f);
        common_data.unk_10A6C = this->actor.world.pos;
        this->unk_1F8 = common_data.unk_10A78;
    } else {
        this->actor.world.pos = common_data.unk_10A6C;
        this->unk_1F8 = common_data.unk_10A78;
    }
    func_80968A10_jp(this, game_play, this->unk_1F8);
    func_80968AF4_jp(this, this->unk_1F8);
    common_data.unk_100DC = func_8096A86C_jp;
    Shape_Info_init(&this->actor, 0.0f, mAc_ActorShadowEllipse, 9.0f, 17.0f);
    ClObjPipe_ct(game_play, &this->collider);
    ClObjPipe_set5(game_play, &this->collider, &this->actor, &aBALL_CoInfoData);
    CollisionCheck_Status_set3(&this->actor.colStatus, &aBALL_StatusData);
    this->unk_206 = 3;
    func_80969998_jp(this, game_play);
    this->unk_1DC = 0;
    this->actor.terminalVelocity = -20.0f;
    this->actor.gravity = 0.6f;
    this->actor.speed = 0.0f;
    this->unk_1EC = 0.0f;
    this->unk_1F0 = 0.12f;
    this->actor.scale.x = 0.01f;
    this->actor.scale.y = 0.01f;
    this->actor.scale.z = 0.01f;
    this->unk_1F4 = 0.0f;
    this->unk_20A = 0;
}

void aBALL_actor_dt(Actor* thisx, Game_Play* game_play) {
    Ball* this = (Ball*)thisx;

    if ((this->unk_208 & 1) || (this->unk_208 & 2) || !mRlib_Set_Position_Check(&this->actor)) {
        common_data.unk_10A6C = ZeroVec;
    } else {
        common_data.unk_10A6C = this->actor.world.pos;
    }
    common_data.unk_100DC = NULL;
    ClObjPipe_dt(game_play, &this->collider);
}

void aBALL_position_move(Ball* this) {
    xyz_t sp2C;

    mCoBG_GetBgY_AngleS_FromWpos(&sp2C, this->actor.world.pos, 0.0f);

    if (this->actor.colResult.unk0 || this->actor.colResult.unk7) {
        chase_f(&this->actor.speed, this->unk_1EC, this->unk_1F0);
    }
    if (!(this->unk_208 & 2)) {
        mRlib_spdF_Angle_to_spdXZ(&this->actor.velocity, &this->actor.speed, &this->actor.world.rot.y);
        chase_f(&this->actor.velocity.y, this->actor.terminalVelocity, this->actor.gravity);
        mRlib_position_move_for_sloop(&this->actor, &sp2C);
        if (this->actor.world.pos.z < 840.0f) {
            this->actor.world.pos.z = 840.0f;
        }
    }
}

void func_80969114_jp(Ball* this) {
    char pad[0x4];
    f32 sp68;
    s32 var_v0;
    s16 sp62;
    s16 sp60;
    xyz_t sp54;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    s32 var_v1;

    sp68 = this->actor.velocity.y;

    if ((this->unk_1E0 == func_80969FD8_jp) || (this->unk_1E0 == func_8096A0EC_jp) || (this->actor.colResult.unk5 == 0xB)) {
        func_800765AC_jp(&this->unk_1D0, &this->actor, 12.0f, -12.0f, 0, 1, 0);
        this->actor.world.pos.x += this->unk_1D0.x;
        this->actor.world.pos.z += this->unk_1D0.z;
    } else {
        func_800765AC_jp(&this->unk_1D0, &this->actor, 12.0f, -12.0f, 0, 0, 0);
        func_800CE8F0_jp(&this->actor);
    }

    if (((this->unk_1E0 == func_809698E8_jp) || (this->unk_1E0 == func_80969FD8_jp)) && this->actor.colResult.unk0) {
        if (this->unk_206 < 3) {
            do {
                this->unk_206++;
            } while (0);

            if (this->actor.colResult.unk7) {
                this->actor.velocity.y = 0.2f;
            } else {
                this->actor.velocity.y = -sp68 * 0.7f;
            }
        }
    }
    var_v0 = this->actor.colResult.unk2;
    if (var_v0 & 1) {
        sp62 = func_800CE874_jp(&this->actor);
        sp60 = (this->actor.world.rot.y - sp62) - 0x8000;
        var_v1 = ABS_2(sp60);
        if (var_v1 < 0x4000) {
            sp54 = this->actor.velocity;
            sp50 = sin_s(sp62);
            sp4C = cos_s(sp62);
            sp48 = sp50 * sp4C;
            sp44 = -((sp54.z * sp4C) + (sp54.x * sp50));
            sp40 = (sp44 * 0.07f) + 1.2f;
            if (sp44 > 1.0f) {
                sAdo_OngenTrgStartSpeed(0x26, &this->actor.world.pos, sp44);
            }
            this->actor.velocity.z = ((1.0f - (sp40 * sp4C * sp4C)) * sp54.z) - (sp54.x * sp40 * sp48);
            this->actor.velocity.x = (-sp54.z * sp40 * sp48) + (sp54.x * (1.0f - (sp40 * sp50 * sp50)));
            func_800CE4B0_jp(&this->actor.velocity, &this->actor.speed, &this->actor.world.rot.y);
        }
    }
}

void func_809693EC_jp(Ball* this) {
    s32 sp8C;
    Actor* sp88;
    s16 sp86;
    f32 sp80;
    f32 sp7C;
    f32 sp78;
    f32 sp74;
    f32 sp70;
    char pad[0x4];
    f32 sp68;
    
    sp8C = func_8008C120_jp();

    if (this->collider.base.prop.ocFlags1 & 2) {
        xyz_t sp5C;
        f32 sp58;
        f32 sp54;
        f32 sp50;
        f32 sp4C;
        char pad2[0x4];
        
        this->collider.base.prop.ocFlags1 &= ~2;

        sp88 = this->collider.base.oc;
        if (mQst_CheckSoccerTarget(this->unk_1DC) != 0) {

            mQst_NextSoccer(this->unk_1DC);
            this->actor.speed = 0.0f;
            this->actor.velocity = ZeroVec;
        } else if ((sp88 != NULL) && (!(this->unk_208 & 2)) && ((sp8C != 1) && (sp8C != 2))) {

            if (sp88 != this->unk_1DC) {

                sp5C = sp88->velocity;
                this->unk_1DC = sp88;
                sp86 = atans_table(this->actor.world.pos.z - sp88->world.pos.z, this->actor.world.pos.x - sp88->world.pos.x);
                sp68 = sin_s(sp86);
                sp70 = cos_s(sp86);
                sp7C = (this->actor.velocity.x * sp68) + (sp70 * this->actor.velocity.z);

                sp78 = sqrtf(SQ(sp5C.x) + SQ(sp5C.z));
                
                xyz_t_mult_v(&sp5C, (24.0f/180.0f) * sp78 * 0.9f + 0.1f);
                
                sp74 = (sp68 * sp5C.x) + (sp70 * sp5C.z);
                sp80 = ABS_F(sp7C + sp74);
                
                sp58 = sin_s(sp86) * sp80;
                sp54 = cos_s(sp86) * sp80;
                sp50 = this->actor.velocity.x + sp58;
                sp4C = this->actor.velocity.z + sp54;
                sp7C = sqrtf(SQ(sp50) + SQ(sp4C));
                sp7C = CLAMP_MAX(sp7C, 11.0f);
                
                if (this->actor.colResult.unk0) {
                    f32 temp_fv1;
                    s16 sp42;

                    if (this->actor.speed == 0.0f) {

                        temp_fv1 = sp7C / 11.0f;
                        sp42 = DEG_TO_BINANG_ALT3(((fqrand2() * (35.0f * temp_fv1)) + (90.0f * temp_fv1)));

                        this->actor.speed = cos_s(sp42) * sp7C;
                        this->actor.velocity.y = sin_s(sp42) * sp7C;
                    } else {
                        this->actor.speed = sp7C * 0.75f;
                    }
                } else {
                    this->actor.speed = sp7C * 0.75f;
                }

                this->actor.world.rot.y = atans_table(sp4C, sp50);
                this->actor.speed *= 0.9f;
                sAdo_OngenTrgStartSpeed(0x25, &this->actor.world.pos, this->actor.speed);
                
            } else {
                xyz_t sp34;
                xyz_t sp28;

                sp28 = this->actor.colStatus.displacement;
                xyz_t_add(&this->actor.velocity, &sp28, &sp34);
                if ((sp8C != 1) && (sp8C != 2)) {
    
                    this->actor.speed = sqrtf(SQ(sp34.x) + SQ(sp34.z));
                    this->actor.speed = CLAMP_MAX(this->actor.speed, 11.0f);
                    
                    this->actor.world.rot.y = atans_table(sp34.z, sp34.x);
                }
            }
        } else {
            this->unk_1DC = NULL;
        }
    } else {
        this->unk_1DC = NULL;
    }
}

void func_80969800_jp(Ball* this) {
    if (func_800CEB1C_jp() != 1) {
        this->unk_208 |= 1;
        Actor_delete(&this->actor);
    }
}

void func_8096983C_jp(Ball* this, Game_Play* game_play) {
    void* sp2C;
    f32 temp;

    sp2C = &this->actor.world.pos;
    temp = mCoBG_GetBgY_AngleS_FromWpos(NULL, this->actor.world.pos, 0.0f);
    this->actor.shape.unk_2C = 1;
    if ((this->unk_1E0 == func_809699D8_jp) && ((this->actor.world.pos.y - temp) > 20.0f)) {
        sAdo_OngenTrgStart(0x43D, sp2C);
    }
    this->unk_1E0 = func_809698E8_jp;
}

void func_809698E8_jp(Ball* this, Game_Play* game_play) {

    this->unk_1F0 = 0.0f;
    add_calc0(&this->unk_1E8, 0.5f, 100.0f);
    this->actor.terminalVelocity = -20.0f;
    this->actor.gravity = 0.6f;
    this->unk_1F4 = this->actor.speed;
    if (this->actor.colResult.unk0) {
        if (this->actor.colResult.unk7) {
            func_8096A0CC_jp(this, game_play);
        } else {
            func_80969998_jp(this, game_play);
        }
    } else if (this->actor.colResult.unk7) {
        func_80969FBC_jp(this, game_play);
    }
}

void func_80969998_jp(Ball* this, Game_Play* game_play) {
    this->actor.shape.unk_2C = 1;
    if (this->actor.velocity.y > 0.0f) {
        this->unk_1E0 = func_809698E8_jp;
    } else {
        this->unk_1E0 = func_809699D8_jp;
    }
}

void func_809699D8_jp(Ball* this, Game_Play* game_play) {
    char pad[0x4];
    xyz_t sp58;
    f32 sp54;
    s16 sp52;
    s16 sp50;
    s32 var_v0;
    f32 var_fv1_2;
    f32 var_fv1_3;

    func_80071C1C_jp(&sp58, this->actor.world.pos);
    if (func_800CEC98_jp(&this->actor, &sp58, &sp54, &sp50, &sp52, 1.0f)) {
        f32 var_fv1;

        var_fv1 = (sp54 - 40.0f) - 5.0f;
        if (!(sp54 - 40.0f < 5.0f)) {
            var_fv1 = 0;
        }
        var_fv1 *= 25.0f;
        add_calc(&this->unk_1E8, var_fv1, 0.5f, 200.0f, 5.0f);
        this->actor.velocity.x *= 0.7f;
        this->actor.velocity.z *= 0.7f;
        if (sp54 < 1.0f) {
            var_fv1_2 = ABS_F(this->actor.velocity.x);

            if (var_fv1_2 < 1.0f) {
                var_fv1_3 = ABS_F(this->actor.velocity.z);

                if (var_fv1_3 < 1.0f) {
                    this->unk_208 |= 2;
                    this->collider.attribute.dim.unk_2 = 0x14;
                    this->collider.attribute.dim.radius = 0x12;
                    this->actor.colStatus.mass = 0xFE;
                    this->actor.speed = 0.0f;
                    return;
                }
            }
        }
    } else {
        func_800CE694_jp(&this->actor, &sp58);
        add_calc0(&this->unk_1E8, 0.5f, 100.0f);
    }

    if (!(fabsf(sp58.x) < 0.008f) || !(fabsf(sp58.z) < 0.008f)) {
        if (Math3d_normalizeXyz_t(&sp58)) {
            this->actor.velocity.x += 1.35f * sp58.x;
            this->actor.velocity.z += 1.35f * sp58.z;
            func_800CE4B0_jp(&this->actor.velocity, &this->unk_1EC, &this->actor.world.rot.y);
            if (this->unk_1EC < 8.0f) {
                this->unk_1EC = this->unk_1EC;
            } else {
                this->unk_1EC = 8.0f;
            }
            this->unk_1F0 = 0.1f;
        }
    } else {
        this->unk_1EC = 0.0f;
        this->unk_1F0 = 0.12f;
    }

    this->actor.terminalVelocity = -20.0f;
    this->actor.gravity = 0.6f;
    this->unk_1F4 = this->actor.speed;
    if (this->actor.colResult.unk7 || this->actor.colResult.unk5 == 0xB) {
        if (this->actor.colResult.unk0 != 0) {
            func_8096A0CC_jp(this, game_play);
        } else {
            this->unk_206 = 0;
            func_80969FBC_jp(this, game_play);
        }
    } else if (this->actor.colResult.unk0 == 0) {
        this->unk_206 = 0;
        func_8096983C_jp(this, game_play);
        return;
    }

    if (!(game_play->state.unk_A0 & 7) && this->actor.colResult.unk5 == 9) {
        if (this->actor.speed > 1.0f) {
            
            if (this->actor.speed > 4.0f) {
                var_v0 = 1;
            } else {
                var_v0 = 0;
            }

            common_data.unk_1009C->unk_00(0x33, this->actor.world.pos, 1, this->actor.world.rot.y, game_play, this->actor.fgName, 0, var_v0);
        }
    }
}

// TODO: this function includes an unreferenced float. It was forced to be in this function to
// be able to build and match the file. It needs to be figured out where to put this float and
// how to handle this when this file gets decompiled.

// RO_FLT_8096A96C_jp 0.200000003

// angl_add_table
s16 D_8096A8FC_jp[2] = {
    0x100,
    0x400,
};

void func_80969DE8_jp(Ball* this, Game_Play* game_play) {
    char pad[0x4];
    xyz_t sp50;
    s16 temp_v0_2;
    f32 sp48;
    s32 var_a3;

    sp48 = func_80075EA0_jp(this->actor.world.pos, "../ac_ball.c", 0x3B5);
    add_calc0(&this->unk_1E8, 0.5f, 100.0f);
    func_80076290_jp(&sp50, this->actor.colResult.unk5);
    temp_v0_2 = atans_table(sp50.z, sp50.x);
    var_a3 = ABS_2((s16) (this->actor.world.rot.y - temp_v0_2));

    chase_angle(&this->actor.world.rot.y, temp_v0_2, D_8096A8FC_jp[((var_a3 > 0x4000))]);
    if (this->actor.world.pos.y < sp48) {
        this->actor.terminalVelocity = 1.0f;
    } else {
        this->actor.terminalVelocity = -1.0f;
    }

    if (this->unk_1FC < 0x20) {
        if ((!(game_play->state.unk_A0 & 3) && (this->unk_1FC < 0x10)) || !(game_play->state.unk_A0 & 7)) {
            common_data.unk_1009C->unk_00(0x45, this->actor.world.pos, 1, this->actor.world.rot.y, game_play, this->actor.fgName, 1, 0);
        }
        this->unk_1FC++;
    }
    this->actor.gravity = 0.2f;
    this->unk_1F0 = 0.2f;
    this->unk_1EC = 1.0f;
}

void func_80969FBC_jp(Ball* this, Game_Play* game_play) {
    this->actor.shape.unk_2C = 0;
    this->unk_1E0 = func_80969FD8_jp;
}

void func_80969FD8_jp(Ball* this, Game_Play* game_play) {
    

    func_80969DE8_jp(this, game_play);
    add_calc0(&this->unk_1E8, 0.5f, 100.0f);
    
    {
        f32 var_fv0;
        var_fv0 = this->unk_1F4;
        var_fv0 -= 0.5f;
        var_fv0 = CLAMP_MIN(var_fv0, 0.0f);
        this->unk_1F4 = var_fv0;
    }

    if (common_data.unk_100B4 != NULL) {
        common_data.unk_100B4->unk_C(&this->actor.world.pos, 20.0f, 1);
    }
    
    if (this->actor.colResult.unk0) {
        if (this->actor.colResult.unk7) {
            func_8096A0CC_jp(this, game_play);
        } else if (this->actor.colResult.unk5 != 0xB) {
            func_80969998_jp(this, game_play);
        }
    } else if (!this->actor.colResult.unk7) {
        func_8096983C_jp(this, game_play);
    }
}

void func_8096A0CC_jp(Ball* this, Game_Play* game_play) {
    this->actor.shape.unk_2C = 0;
    this->unk_1FC = 0;
    this->unk_1E0 = func_8096A0EC_jp;
}

void func_8096A0EC_jp(Ball* this, Game_Play* game_play) {
    f32 var_fv1;
    u32 unitAttribute;
    xyz_t* var;

    unitAttribute = this->actor.colResult.unk5;

    func_80969DE8_jp(this, game_play);
    this->unk_1F4 = this->actor.speed;

    if (common_data.unk_100B4 != NULL) {
        common_data.unk_100B4->unk_C(&this->actor.world.pos, 20.0f, 1);
    }
    if (this->actor.colResult.unk0) {
        if (!this->actor.colResult.unk7 && (unitAttribute != 0xB) && (unitAttribute != 0x16)) {
            func_80969998_jp(this, game_play);
        }
    } else if (!this->actor.colResult.unk7) {
        func_8096983C_jp(this, game_play);
    } else {
        func_80969FBC_jp(this, game_play);
    }
    
    if ((unitAttribute == 0xB) || (unitAttribute == 0x16)) {
        var = &this->unk_1D0;
        this->actor.world.pos.y += (0.5f * var->y);

        if (unitAttribute == 0x16) {
            var_fv1 = ABS_2(var->y);

            if (var_fv1 < 1.0f) {
                func_80969998_jp(this, game_play);
            }
        }
    }
}

void func_8096A23C_jp(Ball* this) {
    f32 temp_f;
    s16 sp1A;

    sp1A = this->actor.speed * 869.63904f;
    if ((this->unk_1E0 == func_80969FD8_jp) || (this->unk_1E0 == func_8096A0EC_jp)) {
        temp_f = ((-1.0f) - this->actor.velocity.y) / (-2.0f);
        sp1A *= sin_s(DEG_TO_BINANG((60.0f * temp_f) + 30.0f));
    }
    func_800CE7E4_jp(&this->actor, &this->unk_200, sp1A);
}

s32 aBALL_player_angle_distance_check(Ball* this, Player* player) {
    f32 sp2C;
    s16 temp_v1;
    s32 var_v0;
    
    sp2C = search_position_distance(&this->actor.world.pos, &player->actor.world.pos);
    temp_v1 = player->actor.shape.rot.y - search_position_angleY(&player->actor.world.pos, &this->actor.world.pos);
    if (sp2C < 60.0f) {
        var_v0 = ABS_2(temp_v1);
        
        if (var_v0 < 0x2000) {
            return 1;
        }
    }
    return 0;
}

void func_8096A3D8_jp(Ball* this, Game_Play* game_play) {
    s32 i;

    if (this->unk_208 & 4) {
        Player* player;
        player = get_player_actor_withoutCheck(game_play);
        this->unk_208 &= ~4;
        if ((aBALL_player_angle_distance_check(this, player)) || (fabsf(this->actor.speed) < 0.008f)) {
            this->actor.world.rot.y = player->actor.shape.rot.y;
            this->actor.speed = 2.0f;
            this->actor.velocity.y = 4.5f;
            if (this->unk_208 & 2) {
                this->collider.attribute.dim.unk_2 = 0x1E;
                this->collider.attribute.dim.radius = 0xD;
                this->unk_208 &= ~2;
                this->actor.colStatus.mass = 0x64;
            }
        }
    }
    if (this->unk_208 & 8) {
        this->unk_208 &= ~8;
        if (!(this->unk_208 & 2)) {
            Player* player;
            player = get_player_actor_withoutCheck(game_play);
            if ((aBALL_player_angle_distance_check(this, player)) || (fabsf(this->actor.speed) < 0.008f)) {
                this->actor.world.rot.y = player->actor.shape.rot.y + 0x2000;
                this->actor.speed = 4.5f;
                this->actor.velocity.y = 3.0f;
            }
        }
    }
    if (!(this->unk_208 & 1)) {
        if (this->actor.colResult.unk7) {
            sAdo_OngenTrgStart(0x27, &this->actor.world.pos);
            this->unk_208 |= 1;
            if (common_data.unk_100B4 != NULL) {
                common_data.unk_100B4->unk_C(&this->actor.world.pos, 20.0f, 0);
            }
            this->collider.attribute.dim.unk_2 = 0xA;
            common_data.unk_1009C->unk_00(0x3A, this->actor.world.pos, 1, 0, game_play, this->actor.fgName, 1, 0);

            for (i = 2; i < 6; i++) {
                common_data.unk_1009C->unk_00(0x3B, this->actor.world.pos, 1, this->actor.world.rot.y, game_play, this->actor.fgName, 0, i | 0x3000);
            }
        }
    }
}

void aBALL_actor_move(Actor* thisx, Game_Play* game_play) {
    char pad[0x4];
    Ball* this = (Ball*)thisx;

    func_80969800_jp(this);
    if (!((this->actor.flags) & 0x40)) {
        if ((this->actor.colResult.unk7) || (this->unk_208 & 2)) {
            Actor_delete(&this->actor);
        }
        if (this->actor.speed == 0.0f) {
            return; 
        }
    }
    
    common_data.unk_10A6C = this->actor.world.pos;
    aBALL_position_move(this);
    this->unk_1E0(this, game_play);
    func_80969114_jp(this);
    func_809693EC_jp(this);

    CollisionCheck_Uty_ActorWorldPosSetPipeC(&this->actor, &this->collider);
    CollisionCheck_setOC(game_play, &game_play->unk_2138, &this->collider.base);
    func_8096A23C_jp(this);
    func_8096A3D8_jp(this, game_play);
}

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

void aBALL_actor_draw(Actor* thisx, Game_Play* game_play) {
    GraphicsContext* gfxCtx = game_play->state.gfxCtx;
    Ball* this = (Ball*)thisx;
    
    AC_GCN_OPEN_DISP(gfxCtx);
    OPEN_CUSTOM_POLY_OPA();
    gSPSegment(__polyOpa++, 0x06, this->unk_1E4);
    Matrix_translate(0.0f, this->unk_1E8, 0.0f, 1);
    Matrix_rotateXYZ(this->unk_200.x, this->unk_200.y, this->unk_200.z, MTXMODE_APPLY);
    gDPPipeSync(__polyOpa++);
    gSPMatrix(__polyOpa++, _Matrix_to_Mtx_new(gfxCtx), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(__polyOpa++, D_8096A8B0_jp[this->unk_1F8]);
    CLOSE_CUSTOM_POLY_OPA();
    AC_GCN_CLOSE_DISP(gfxCtx);
    // FAKE: two extra if (1) {}s are needed somewhere (can be any line + split apart) to match?
    if (1) {} if (1) {}
}

void func_8096A86C_jp(void) {
    if ((common_data.unk_100DC != NULL) && (Global_Actor_p != NULL)) {
        func_80968AF4_jp(Global_Actor_p, Global_Actor_p->unk_1F8);
    }
}
