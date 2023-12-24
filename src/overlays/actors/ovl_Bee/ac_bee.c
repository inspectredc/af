#include "ac_bee.h"
#include "m_actor_dlftbls.h"
#include "m_object.h"
#include "overlays/gamestates/ovl_play/m_play.h"
#include "overlays/actors/player_actor/m_player.h"
#include "m_field_info.h"
#include "libc/math.h"
#include "m_player_lib.h"
#include "m_rcp.h"

void aBEE_actor_ct(Actor* thisx, Game_Play* game_play);
void func_80A93DD0_jp(Actor* thisx, Game_Play* game_play);
void aBEE_actor_move(Actor* thisx, Game_Play* game_play);
void aBEE_actor_draw(Actor* thisx, Game_Play* game_play);

#if 0
ActorProfile Bee_Profile = {
    /* */ ACTOR_BEE,
    /* */ ACTOR_PART_4,
    /* */ ACTOR_FLAG_10,
    /* */ 0x0000,
    /* */ OBJECT_392,
    /* */ sizeof(Bee),
    /* */ aBEE_actor_ct,
    /* */ func_80A93DD0_jp,
    /* */ aBEE_actor_move,
    /* */ aBEE_actor_draw,
    /* */ NULL,
};
#endif

void func_80A94450_jp(Bee*, s32, Game_Play*);          /* extern */
extern BaseAnimationR* D_60008E4;
extern BaseSkeletonR* D_6000928;
extern xyz_t D_80A94974_jp;

void aBEE_actor_ct(Actor* thisx, Game_Play* game_play) {
    Bee *this = thisx;
    SkeletonInfoR *tmp = &this->skeletonInfo;
    xyz_t sp34;
    sp34 = D_80A94974_jp;
    cKF_SkeletonInfo_R_ct(&this->skeletonInfo, &D_6000928, &D_60008E4, this->jointTable, this->morphTable);
    cKF_SkeletonInfo_R_init_standard_repeat(&this->skeletonInfo, Lib_SegmentedToVirtual(&D_60008E4), 0);
    tmp->frameControl.currentFrame = 90.0f;
    cKF_SkeletonInfo_R_play(tmp);
    tmp->frameControl.speed = 0.0f;
    this->unk_442 = -0x8000;
    this->unk_430 = 90.0f;
    xyz_t_move(&this->actor.scale, &sp34);
    this->unk_178 = (void *) game_play->objectExchangeBank.status[this->actor.unk_026].segment;
    this->actor.update = aBEE_actor_move;
    func_80A94450_jp(this, 0, game_play);
}

void func_80A93DD0_jp(Actor* thisx, Game_Play* game_play) {

}

extern xyz_t D_80A94980_jp;

void func_80A93DE0_jp(Bee* this, Game_Play* game_play) {
    xyz_t sp1C;

    sp1C = D_80A94980_jp;
    xyz_t_move(&this->unk_420, &sp1C);
    common_data.unk107E6[0x253] = 1;
}

void func_80A93E38_jp(Bee* this, Game_Play* game_play) {

}

void func_80A93E48_jp(Bee* this, Game_Play* game_play) {
    
    this->actor.speed = 9.7f;
    this->actor.shape.rot.x = this->actor.shape.rot.z = 0;
}

void func_80A93E6C_jp(Bee* this, Game_Play* game_play) {
    Player* player = get_player_actor_withoutCheck(game_play);
    s32 *var = &this->unk_438;
    this->unk_434 = player->actor.world.pos.y + 50.0f;
    this->unk_438 += 6;
    if (this->unk_438 >= 0xFF) {
        this->unk_438 = 0xFF;
    }
    this->actor.shape.rot.x = 0x7FFF;
    this->actor.shape.rot.z += 0x1000;
    if (*var == 0xFF) {
        func_80A94450_jp(this, 1, game_play);
    }
}

#define	ABS_2(d)		((d) >= 0) ? (d) : -(d)

void func_80A93EFC_jp(Bee* this, Game_Play* game_play) {
    f32 temp_fv;
    Player* player;
    s16 var_v0;
    f32 var_fv1 = 0;
    f32 var_fv2;
    Actor* sp68;
    s32 sp64;
    xyz_t sp58;
    s32 sp54;
    CommonData_unk_10088_unk_0_arg0 sp3C;

    player = get_player_actor_withoutCheck(game_play);
    sp68 = func_800B3B74_jp();
    sp64 = func_800B56D0_jp();
    add_calc_short_angle2(&this->actor.shape.rot.z, 0, 0.3f, 0x7D0, 0);
    add_calc_short_angle2(&this->actor.shape.rot.x, 0, 0.3f, 0x7D0, 0);
    if (&this->actor != sp68) {
        if (this->actor.shape.rot.x < 0x1001) {
            if (this->unk_446 != 2) {

                if (((get_player_actor_withoutCheck((Game_Play*)gamePT)->unk_1234Func((Player*)get_player_actor_withoutCheck((Game_Play*)gamePT), (Game_Play*)gamePT) > 0.0f) || (func_800B3B24_jp(&sp58) != 0)) && (this->actor.xzDistToPlayer < 40.0f)) {
                    get_player_actor_withoutCheck((Game_Play*)gamePT)->unk_1238Func((Player*)get_player_actor_withoutCheck((Game_Play*)gamePT), (Game_Play*)gamePT, &this->actor, 1);
                } else {
                    get_player_actor_withoutCheck((Game_Play*)gamePT)->unk_1230Func((Player*)get_player_actor_withoutCheck((Game_Play*)gamePT), (Game_Play*)gamePT, &this->actor, 1, &this->actor.world.pos, 24.0f);
                }
            }
        } else {
            return;
        }
    }

    if (&this->actor == sp68) {
        if (this->unk_448 == 0) {
            sp3C.unk_00 = 8;
            xyz_t_move(&sp3C.unk_04, &this->actor.world.pos);
            sp3C.unk_10 = 0;
            sp3C.unk_14 = game_play;
            this->unk_448 = common_data.unk_10088->unk_0(&sp3C, 1);
            // FAKE label and xor
dummy_label: ;
        } else if (func_800B3BBC_jp(this->unk_448 ^ 0, 0) != 0) {
            func_80A94450_jp(this, 2, game_play);
            return;
        }
    }

    if (this->unk_448 == 0) {
        if (func_800B5EA4_jp(game_play) != 0) {
            this->unk_446 = 1;
        }

        if (this->unk_446 != 2) {
            if ((this->unk_446 != 0) || (this->actor.xzDistToPlayer < 30.0f)) {
                this->unk_446 = 1;
                if (sp64 == 1) {
                    func_800B2AD0_jp((Game_Play*)gamePT);
                    this->unk_446 = 2;
                } else if (sp64 == 2) {
                    func_80A94450_jp(this, 2, game_play);
                    return;
                }
            }
        } else if ((func_800B1CBC_jp((Game_Play*)gamePT) == 0x5E) != 0) {
            if (func_800B5718_jp() != 0) {
                func_80A94450_jp(this, 2, game_play);
                return;
            }
        } else {
            func_800B2AD0_jp((Game_Play*)gamePT);
        }
    }
    var_fv2 = fabsf(90.0f - this->unk_430);
    this->unk_444 = 0x640;
    if (this->unk_446 != 0) {
        this->unk_444 = 0x1388;
    }
    var_fv2 *= 7.5f;
    add_calc_short_angle2(&this->unk_43E, this->unk_444 - (s16) (var_fv2), 0.4f, 0x1F4, 0);
    add_calc_short_angle2(&this->actor.world.rot.y, this->actor.yawTowardsPlayer, 0.4f, this->unk_43E, 0);
    this->actor.shape.rot.y = this->actor.world.rot.y;

    var_v0 = ABS_2((s16) (this->actor.world.rot.y - this->actor.yawTowardsPlayer));

    if (var_v0 >= -0x7FFF) {
        var_v0 = 0;
    }

    temp_fv = fabsf((0x8000 - var_v0) / 5461);
    this->unk_42C = 2.9f + temp_fv;
    add_calc(&this->actor.speed, this->unk_42C , 0.3f, 0.3f, 0.0f);
    this->unk_43C += 0x1200;
    this->unk_434 = player->actor.world.pos.y + 50.0f;
    this->unk_434 += sin_s(this->unk_43C) * 5.0f;
    
    temp_fv = this->actor.yawTowardsPlayer - this->actor.world.rot.y;
    var_fv1 = (temp_fv / 30.0f) + 90.0f;
    
    if (var_fv1 < 0.0f) {
        var_fv1 = 0.0f;
    } else if (var_fv1 > 180.0f) {
        var_fv1 = 180.0f;
    }
    add_calc(&this->unk_430, var_fv1, 0.5f, 10.0f, 0.0f);
}

void func_80A94408_jp(Bee* this, Game_Play* game_play) {

    this->unk_420.x = 0.03f;
    this->unk_420.z = 0.03f;
    this->unk_420.y = 0.03f;
    this->unk_438 -= 0x1E;
    if (this->unk_438 < 0) {
        this->unk_438 = 0;
        Actor_delete(&this->actor);
    }
}

extern void(*D_80A9498C_jp[])(Bee*, Game_Play*);
extern void(*D_80A94998_jp[]);

void func_80A94450_jp(Bee* this, s32 arg0, Game_Play* game_play) {
    this->unk_17C = arg0;
    this->unk_174 = D_80A94998_jp[this->unk_17C];
    D_80A9498C_jp[this->unk_17C](this, game_play);
}

void func_80A9449C_jp(Bee* this, Game_Play* game_play) {
    s32 pad;
    void* sp20;
    SkeletonInfoR* sp18;

    sp20 = game_play->objectExchangeBank.status[this->actor.unk_026].segment;
    if (sp20 != this->unk_178) {
        sp18 = &this->skeletonInfo;
        sp18->skeleton = Lib_SegmentedToVirtual(&D_6000928);
        sp18->animation = Lib_SegmentedToVirtual(&D_60008E4);
        this->unk_178 = sp20;
    }
}

extern f32 D_80A949A4_jp[3];
extern f32 D_80A949B0_jp[4];

void aBEE_actor_move(Actor* thisx, Game_Play* game_play) {
    SkeletonInfoR* sp30;
    Bee* this = (Bee*)thisx;
    f32 f_var;

    sp30 = &this->skeletonInfo;
    func_80A9449C_jp(this, game_play);
    sAdo_OngenPos(&this->actor, 0x30, &this->actor.world);
    if (!(this->actor.world.pos.x < 0.0f) || !(this->actor.world.pos.z < 0.0f)) {
        if ((this->unk_446 == 2) || (func_8008C120_jp() == 0)) {
            Actor_position_moveF(&this->actor);
        }
        this->unk_174(this, game_play);
        if ((this->unk_17C == 0) || (this->unk_17C == 2)) {
            add_calc(&this->actor.scale.x, this->unk_420.x, D_80A949A4_jp[this->unk_17C], D_80A949B0_jp[this->unk_17C], 0.0f);
            add_calc(&this->actor.scale.y, this->unk_420.y, D_80A949A4_jp[this->unk_17C], D_80A949B0_jp[this->unk_17C], 0.0f);
            add_calc(&this->actor.scale.z, this->unk_420.z, D_80A949A4_jp[this->unk_17C], D_80A949B0_jp[this->unk_17C], 0.0f);
        } else {
            f_var = fabsf(90.0f - this->unk_430);
            this->unk_420.x = ((f_var / 360.0f) + 0.75f) * 0.01f;
            this->unk_420.y = ((f_var / 360.0f) + 0.75f) * 0.01f;
            this->unk_420.z = ((1.5f - (f_var / 180.0f)) * 0.01f);
            add_calc(&this->actor.scale.x, this->unk_420.x, 0.2f, 0.01f, 0.0f);
            add_calc(&this->actor.scale.y, this->unk_420.y, 0.2f, 0.01f, 0.0f);
            add_calc(&this->actor.scale.z, this->unk_420.z, 0.2f, 0.01f, 0.0f);
        }
        this->unk_440 += 0x3E8;
        this->unk_442 -= 0x3E8;
        sp30->frameControl.currentFrame = this->unk_430;
        cKF_SkeletonInfo_R_play(sp30);
        sp30->frameControl.speed = 0.0f;
        add_calc(&this->actor.world.pos.y, this->unk_434, 0.3f, 3.0f, 0.0f);
    }
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

#define OPEN_CUSTOM_POLY_XLU()                \
    {                                         \
        Gfx* __polyXlu = __gfxCtx->polyXlu.p; \
        int __xlu_opened = 0;                 \
        do {} while (0)

#define CLOSE_CUSTOM_POLY_XLU()          \
        __gfxCtx->polyXlu.p = __polyXlu; \
        (void)__xlu_opened;              \
    }                                    \
    do {} while (0)

void aBEE_actor_draw(Actor* thisx, Game_Play* game_play) {
    Bee* this = (Bee*)thisx;
    s32 sp78 = game_play->state.unk_A0 & 1;
    s8 pad[0x8];
    Gfx* texScroll;

    if (!(thisx->world.pos.x < 0.0f) && !(thisx->world.pos.z < 0.0f)) {
        func_80A9449C_jp(this, game_play);
        texScroll = two_tex_scroll(game_play->state.gfxCtx, 0, sin_s(this->unk_440) * 90.0f, cos_s(this->unk_440) * 90.0f, 0x20, 0x20, 1, cos_s(this->unk_442) * 90.0f, sin_s(this->unk_442) * 90.0f, 0x20, 0x20);
        if (texScroll != 0) {
            Matrix_push();
            _texture_z_light_fog_prim_xlu(game_play->state.gfxCtx);
            Setpos_HiliteReflect_xlu_init(&thisx->world.pos, game_play);

            AC_GCN_OPEN_DISP(game_play->state.gfxCtx);    
            OPEN_CUSTOM_POLY_XLU();
            gDPSetPrimColor(__polyXlu++, 0, 0xFF, 0, 0, 0, this->unk_438);
            gSPSegment(__polyXlu++, 0x08, texScroll);
            CLOSE_CUSTOM_POLY_XLU();
            AC_GCN_CLOSE_DISP(game_play->state.gfxCtx);
            cKF_Si3_draw_R_SV(game_play, &this->skeletonInfo, &this->unk_220[sp78], 0, 0, this);
            Matrix_pull();
        }
    }
}
