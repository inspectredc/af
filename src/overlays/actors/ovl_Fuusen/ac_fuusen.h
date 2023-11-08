#ifndef AC_FUUSEN_H
#define AC_FUUSEN_H

#include "ultra64.h"
#include "m_actor.h"
#include "unk.h"
#include "c_keyframe.h"

struct Game_Play;
struct Fuusen;

typedef void (*FuusenActionFunc)(struct Fuusen*, struct Game_Play*);

typedef struct Fuusen {
    Actor actor;
    FuusenActionFunc unk_174;
    void* unk_178;
    s32 unk_17C;
    u32 unk_180;
    s32 unk_184;
    s32 unk_188;
    s32 unk_18C;
    s32 unk_190;
    s32 unk_194;
    s16 unk_198;
    s8 unk_19A[0x2];
    f32 unk_19C;
    f32 unk_1A0;
    u8 unk_1A4;
    s8 unk_1A5[0x3];
    SkeletonInfoR skeletonInfo; // 0x1A8
    s_xyz jointTable[0x4]; // 0x218
    s_xyz morphTable[0x4]; // 0x230
    s8 unk_248[0x200];
} Fuusen; // size = 0x448

#endif
