#ifndef AC_TAMA_H
#define AC_TAMA_H

#include "ultra64.h"
#include "m_actor.h"
#include "unk.h"
#include "c_keyframe.h"

struct Game_Play;
struct Tama;

typedef void (*TamaActionFunc)(struct Tama*, struct Game_Play*);

typedef struct Tama {
    Actor actor;
    UNK_TYPE1 unk_174[0x134];
    s32 unk_2A8;
    s32 unk_2AC;
    UNK_TYPE1 unk_2B0[0x4];
    s32 unk_2B4;
    UNK_TYPE1 unk_2B8[0x20];
} Tama; // size = 0x2D8

#endif
