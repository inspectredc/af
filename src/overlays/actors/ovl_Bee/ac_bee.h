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
    s8 unk_174[0x4];
    void* unk_178;
    s8 unk_17C[0x4];
    SkeletonInfoR skeletonInfo; // 0x180
    s_xyz jointTable[3]; // 0x1f0
    s8 unk_202[0x6];
    s_xyz morphTable[3]; // 0x208
    s8 unk_21A[0x206];
    xyz_t unk_420;
    s8 unk_42C[0x4];
    f32 unk_430;
    f32 unk_434;
    s32 unk_438;
    s8 unk_43C[0x6];
    s16 unk_442;
    s8 unk_444[0xC];
} Bee;

#endif
