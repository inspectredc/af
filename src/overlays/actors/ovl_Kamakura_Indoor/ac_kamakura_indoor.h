#ifndef AC_KAMAKURA_INDOOR_H
#define AC_KAMAKURA_INDOOR_H

#include "ultra64.h"
#include "m_actor.h"
#include "unk.h"

struct Game_Play;
struct Kamakura_Indoor;

typedef void (*Kamakura_IndoorActionFunc)(struct Kamakura_Indoor*, struct Game_Play*);

typedef struct Kamakura_Indoor {
    Actor actor;
    s8 unk_174[0x20];
    s32 unk_194;
    s8 unk_198;
    s8 unk_199[0x3];
    s8 unk_19C[0x24];
    xyz_t unk_1C0;
    xyz_t unk_1CC;
    s16 unk_1D8;
    s8 unk_1DA[0x2];
    s8 unk_1DC[0x24];
} Kamakura_Indoor; // size = 0x200

#endif
