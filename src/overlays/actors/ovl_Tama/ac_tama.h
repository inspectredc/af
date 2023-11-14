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
    UNK_TYPE1 unk_174[0x12C];
    TamaActionFunc unk_2A0;
    UNK_TYPE1 unk_2A4[0x4];
    union {
        s32 unk_2A8;
        struct {
            s16 unk_2A8;
            s16 unk_2AA;
        } unk_2A8_struct;
    } unk_2A8_union;
    union {
        s32 unk_2AC;
        struct {
            s16 unk_2AC;
            s16 unk_2AE;
        } unk_2AC_struct;
    } unk_2AC_union;
    UNK_TYPE1 unk_2B0[0x4];
    s32 unk_2B4;
    s32 unk_2B8;
    UNK_TYPE1 unk_2BC[0x1C];
} Tama; // size = 0x2D8

#endif
