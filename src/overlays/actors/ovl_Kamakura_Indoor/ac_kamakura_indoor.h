#ifndef AC_KAMAKURA_INDOOR_H
#define AC_KAMAKURA_INDOOR_H

#include "ultra64.h"
#include "m_actor.h"
#include "unk.h"
#include "color.h"

struct Game_Play;
struct Kamakura_Indoor;

typedef struct Kamakura_Indoor_unk_struct {
    Color_RGBA8 color;
    f32 unk_4;
} Kamakura_Indoor_unk_struct;// size 0x8;

typedef void (*Kamakura_IndoorActionFunc)(struct Kamakura_Indoor*, struct Game_Play*);

typedef struct Kamakura_Indoor {
    Actor actor;
    Kamakura_Indoor_unk_struct unk_174[2];
    void* unk_184;
    Color_RGBA8 unk_188;
    void* unk_18C;
    Color_RGBA8 unk_190;
    s32 unk_194;
    s8 unk_198;
    s8 unk_199[0x3];
    s8 unk_19C[0x24];
    xyz_t unk_1C0;
    xyz_t unk_1CC;
    s16 unk_1D8;
    s8 unk_1DA[0x2];
    s8 unk_1DC[0x4];
    xyz_t unk_1E0[2];
    f32 unk_1F8[2];
} Kamakura_Indoor; // size = 0x200

#endif
