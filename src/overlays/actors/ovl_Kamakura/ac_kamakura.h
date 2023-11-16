#ifndef AC_KAMAKURA_H
#define AC_KAMAKURA_H

#include "ultra64.h"
#include "m_actor.h"
#include "unk.h"

struct Game_Play;
struct Kamakura;

typedef void (*KamakuraActionFunc)(struct Kamakura*, struct Game_Play*);

typedef struct Kamakura {
    /* 0x000 */ Actor actor;
    /* 0x174 */ s8 unk_174[0x12C];
    /* 0x2A0 */ KamakuraActionFunc unk_2A0;
    /* 0x2A4 */ s8 unk_2A4[0x10];
    /* 0x2B4 */ s32 unk_2B4;
    /* 0x2B8 */ s8 unk_2B8[0x20];
} Kamakura; // size = 0x2D8

#endif
