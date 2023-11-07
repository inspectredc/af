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
    s8 unk_174[0x4];
    void* unk_178;
    s8 unk_17C[0x8];
    s32 unk_184;
    s8 unk_188[0x8];
    s32 unk_190;
    s8 unk_194[0xC];
    f32 unk_1A0;
    s8 unk_1A4[0x4];
    SkeletonInfoR skeletonInfo; // 0x1A8
    s_xyz jointTable[0x4]; // 0x218
    s_xyz morphTable[0x4]; // 0x230
    s8 unk_248[0x200];
} Fuusen; // size = 0x448

#endif
