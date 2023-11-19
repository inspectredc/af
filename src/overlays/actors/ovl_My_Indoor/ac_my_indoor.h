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
                s8 unk_174[0x8];
                void* unk_17C;
                void* unk_180[2];
                void* unk_188[2];
                s8 unk_190[0x14];
                s32 unk_1A4;
                s8 unk_1A8[0x10];
} My_Indoor; // size = 0x1B8

#endif
