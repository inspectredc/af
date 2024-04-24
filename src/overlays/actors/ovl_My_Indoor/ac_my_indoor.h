#ifndef AC_MY_INDOOR_H
#define AC_MY_INDOOR_H

#include "ultra64.h"
#include "m_actor.h"
#include "unk.h"
#include "m_clip.h"

struct Game_Play;
struct My_Indoor;

typedef void (*My_IndoorActionFunc)(struct My_Indoor*, struct Game_Play*);

typedef struct My_Indoor {
    Actor actor;
    s16 unk_174;
    s16 unk_176;
    s16 unk_178;
    s16 unk_17A;
    void* unk_17C;
    void* unk_180[2];
    void* unk_188[2];
    Clip_unk_09C unk_190;
    s16 unk_1A4;
    s32 unk_1A8;
    u16 unk_1AC;
    s32 unk_1B0;
    u16 unk_1B4;
} My_Indoor; // size = 0x1B8

#endif
