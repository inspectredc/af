#ifndef AC_BALL_H
#define AC_BALL_H

#include "ultra64.h"
#include "m_actor.h"
#include "m_collision_obj.h"
#include "unk.h"
#include "c_keyframe.h"

struct Game_Play;
struct Ball;

typedef void (*BallActionFunc)(struct Ball*, struct Game_Play*);

typedef struct Ball {
    /* 0x000 */ Actor actor;
    /* 0x174 */ ClObjPipe collider;
    /* 0x190 */ UNK_TYPE1 unk_190[0x40];
    /* 0x1D0 */ xyz_t unk_1D0;
    /* 0x1DC */ Actor* unk_1DC;
    /* 0x1E0 */ BallActionFunc unk_1E0;
    /* 0x1E4 */ void* unk_1E4;
    /* 0x1E8 */ f32 unk_1E8;
    /* 0x1EC */ f32 unk_1EC;
    /* 0x1F0 */ f32 unk_1F0;
    /* 0x1F4 */ f32 unk_1F4;
    /* 0x1F8 */ s32 unk_1F8;
    /* 0x1FC */ s16 unk_1FC;
    /* 0x1FE */ UNK_TYPE1 unk_1FE[0x2];
    /* 0x200 */ s_xyz unk_200;
    /* 0x206 */ s16 unk_206;
    /* 0x208 */ s16 unk_208;
    /* 0x20A */ s16 unk_20A;
} Ball; // size 0x20C

#endif
