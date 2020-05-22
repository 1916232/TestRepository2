#pragma once
//敵
#define	ENEMY_SIZE_X	32	//敵画像の横サイズ
#define	ENEMY_SIZE_Y	32	//敵画像の縦サイズ

bool enemySystemInit(void);
void enemyDraw(void);
void enemyControl(void);

extern bool enemyFlag;
extern int enemyPosX;		//表示用の座標を記憶しておく変数
extern int enemyPosY;		//表示用の座標を記憶しておく変数
