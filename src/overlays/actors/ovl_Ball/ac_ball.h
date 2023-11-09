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

// typedef struct Ball {
//     /* 0x000 */ Actor actor;
//     /* 0x174 */ ClObjPipe collider;
//     /* 0x190 */ UNK_TYPE1 unk_190[0x8C];
// } Ball; // size = 0x21C

typedef struct Ball {
    Actor actor;
    ClObjPipe collider; // 0x174
    s8 unk_190[0x40];
    xyz_t unk_1D0;
    s32 unk_1DC;
    void* unk_1E0;
    void* unk_1E4;
    s8 unk_1E8[0x4];
    f32 unk_1EC;
    f32 unk_1F0;
    f32 unk_1F4;
    s32 unk_1F8;
    s8 unk_1FC[0x8];
    s8 unk_204[0x2];
    s16 unk_206;
    s16 unk_208;
    s16 unk_20A;
    s8 unk_20C[0x10];
} Ball; // size 0x21C (wrong on base)

#endif
