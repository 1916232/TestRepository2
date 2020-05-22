#pragma once
#define SHOT_SIZE_X     10 //弾の横サイズ
#define SHOT_SIZE_Y    10 //弾の縦サイズ
#define SHOT_MAX 4


void ShotSystemInit(void);
void ShotConttrol(void);
void ShotDraw(void);

extern int shotPosX;
extern int shotPosY;
extern int shotFlag;