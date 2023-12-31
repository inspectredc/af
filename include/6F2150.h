#ifndef C_6F2150_H
#define C_6F2150_H

#include "ultra64.h"

void mRlib_spdXZ_to_spdF_Angle(xyz_t*, f32*, s16*);
void mRlib_spdF_Angle_to_spdXZ(xyz_t*, f32*, s16*);
void mRlib_position_move_for_sloop(struct Actor*, xyz_t*);
void func_800CE694_jp(struct Actor*, xyz_t*);
void func_800CE7E4_jp(struct Actor*, void*, s16);
s16 mRlib_Get_HitWallAngleY(struct Actor*);
void mRlib_Station_step_modify_to_wall(struct Actor*);
s32 mRlib_Set_Position_Check(struct Actor*);
s32 func_800CEB1C_jp(void);
// void func_800CEC30_jp();
s32 func_800CEC98_jp(struct Actor*, xyz_t*, f32*, s16*, s16*, f32);
// void func_800CEE24_jp();
// void func_800CEED4_jp();
// void func_800CF05C_jp();
// void func_800CF16C_jp();

#endif
