#include "DxLib.h"		//Dxlibライブラリを使用する
#include "main.h"
#include "keycheck.h"
#include "effect.h"
#include "player.h"
#include "Shot.h"
#include "enemy.h"

int enemyImage;	//敵描画用登録用変数
int enemyPosX;		//表示用の座標を記憶しておく変数
int enemyPosY;		//表示用の座標を記憶しておく変数
int enemySpeed;	//敵のスピード用変数

bool enemyFlag;

bool enemySystemInit(void)
{
	bool rtnFlag = true;

	//敵
	enemyImage = LoadGraph("image/enemy.png");
	enemyPosX = GetRand(SCREEN_SIZE_X - ENEMY_SIZE_X);//初期位置（横座標）
	enemyPosY = -ENEMY_SIZE_Y; //初期位置（縦座標
	enemySpeed = 4;		//移動速度
	enemyFlag = true;

	return rtnFlag;
}

void enemyDraw(void)
{
	if (enemyFlag == true)
	{
		DrawGraph(enemyPosX, enemyPosY, enemyImage, true);
	}
}

void enemyControl(void)
{
	enemyPosY += enemySpeed;
	if (enemyPosY >= SCREEN_SIZE_Y)
	{
		enemyPosX = GetRand(SCREEN_SIZE_X - ENEMY_SIZE_X);
		enemyPosY = -ENEMY_SIZE_Y;
	}
}