#ifndef AC_MY_INDOOR_H
#define AC_MY_INDOOR_H

#include "ultra64.h"
#include "m_actor.h"
#include "unk.h"

struct Game_Play;
struct My_Indoor;

typedef void (*My_IndoorActionFunc)(struct My_Indoor*, struct Game_Play*);

typedef struct My_Indoor {
    Actor actor;
    s16 unk_174;
    s16 unk_176;
    UNK_TYPE1 unk_178[0x4];
    void* unk_17C;
    void* unk_180[2];
    void* unk_188[2];
    Actor* unk_190;
    My_IndoorActionFunc unk_194;
    My_IndoorActionFunc unk_198;
    My_IndoorActionFunc unk_19C;
    My_IndoorActionFunc unk_1A0;
    s32 unk_1A4;
    UNK_TYPE1 unk_1A8[0x10];
} My_Indoor; // size = 0x1B8

#endif
