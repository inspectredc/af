#ifndef AC_BEE_H
#define AC_BEE_H

#include "ultra64.h"
#include "m_actor.h"
#include "unk.h"
#include "c_keyframe.h"

struct Game_Play;
struct Bee;

typedef void (*BeeActionFunc)(struct Bee*, struct Game_Play*);

typedef struct Bee {
    Actor actor;
    BeeActionFunc unk_174;
    void* unk_178;
    s32 unk_17C;
    SkeletonInfoR skeletonInfo; // 0x180
    s_xyz jointTable[3]; // 0x1f0
    s8 unk_202[0x6];
    s_xyz morphTable[3]; // 0x208
    s8 unk_21A[0x206];
    xyz_t unk_420;
    f32 unk_42C;
    f32 unk_430;
    f32 unk_434;
    s32 unk_438;
    s16 unk_43C;
    s16 unk_43E;
    s16 unk_440;
    s16 unk_442;
    s16 unk_444;
    u8 unk_446;
    s8 unk_447[0x1];
    s32 unk_448;
    s8 unk_44C[0x4];
} Bee; // size 0x450

#endif
