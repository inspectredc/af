#ifndef AC_KAGO_H
#define AC_KAGO_H

#include "ultra64.h"
#include "m_actor.h"
#include "unk.h"
#include "c_keyframe.h"

struct Game_Play;
struct Kago;

typedef void (*KagoActionFunc)(struct Kago*, struct Game_Play*);

typedef struct Kago {
    Actor actor;
    UNK_TYPE1 unk_174[0x12C];
    KagoActionFunc unk_2A0;
    UNK_TYPE1 unk_2A4[0x4];
    s32 unk_2A8;
    s32 unk_2AC;
    UNK_TYPE1 unk_2B0[0x4];
    s32 unk_2B4;
    s32 unk_2B8;
    UNK_TYPE1 unk_2BC[0x20];
} Kago; // size = 0x2D8

#endif
