#ifndef AC_AIRPLANE_H
#define AC_AIRPLANE_H

#include "ultra64.h"
#include "m_actor.h"
#include "unk.h"

struct Game_Play;
struct Airplane;

typedef void (*AirplaneActionFunc)(struct Airplane*, struct Game_Play*);

typedef struct Airplane {
    /* 0x000 */ Actor actor;
    /* 0x174 */ s16 unk_174;
    /* 0x176 */ s16 unk_176;
    /* 0x178 */ f32 unk_178;
    /* 0x17C */ f32 unk_17C;
    /* 0x180 */ f32 unk_180;
    /* 0x184 */ f32 unk_184;
    /* 0x188 */ f32 unk_188;
    /* 0x18C */ f32 unk_18C;
    /* 0x190 */ f32 unk_190;
    /* 0x194 */ s32 unk_194;
    /* 0x198 */ s32 unk_198;
    /* 0x19C */ s16 unk_19C;
    /* 0x19E */ s8 unk_19E[0x2];
    /* 0x1A0 */ s32 unk_1A0;
    /* 0x1A4 */ s32 unk_1A4;
    /* 0x1A8 */ s32 unk_1A8;
    /* 0x1AC */ s8 unk_1AC[0x1C];
} Airplane; // size = 0x1C8

#endif
