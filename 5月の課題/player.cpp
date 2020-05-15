#include "DxLib.h"
#include "main.h"
#include "player.h"
#include "keycheck.h"

int playerImage;				//自機の画像ID
int playerPosX;					//自機のX座標
int playerPosY;					//自機のY座標
int playerSpeed;


void PlayerSystemInit(void)
{
	playerImage = LoadGraph("image/player.png");
	playerPosX = 280;//初期位置
	playerPosY = 450;//初期位置
	playerSpeed = 5;
}
void PlayerConttrol(void)
{
	if (CheckHitKey(KEY_INPUT_LEFT))
	{
		playerPosX -= playerSpeed;
	}
	if (CheckHitKey(KEY_INPUT_RIGHT))
	{
		playerPosX += playerSpeed;
	}


	if (playerPosX <= 25 - PLAYER_SIZE_X / 2)
	{
		playerPosX = 25 - PLAYER_SIZE_X / 2;
	}
	if (playerPosX >= SCREEN_SIZE_X - PLAYER_SIZE_X)
	{
		playerPosX = SCREEN_SIZE_X - PLAYER_SIZE_X;
	}

}

void PlayerDraw(void)
{
	DrawGraph(playerPosX, playerPosY, playerImage, true);
}

