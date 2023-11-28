#ifndef AC_DOUZOU_H
#define AC_DOUZOU_H

#include "ultra64.h"
#include "m_actor.h"
#include "unk.h"
#include "c_keyframe.h"

struct Game_Play;
struct Douzou;

typedef void (*DouzouActionFunc)(struct Douzou*, struct Game_Play*);

typedef struct Douzou {
    Actor actor;
    s32 unk_174;
    SkeletonInfoR unk_178;
    s32 unk_1E8;
    s_xyz jointTable[15];
    s_xyz morphTable[15];
    DouzouActionFunc unk_2A0;
    s8 unk_2A4[0x10];
    s32 unk_2B4;
    s32 unk_2B8;
    s32 unk_2BC;
    s32 unk_2C0;
    s8 unk_2C4[0x4];
    f32 unk_2C8;
    f32 unk_2CC;
    f32 unk_2D0;
    f32 unk_2D4;
} Douzou; // size = 0x2D8

#endif
