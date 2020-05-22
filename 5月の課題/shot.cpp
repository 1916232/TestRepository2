#include "DxLib.h"
#include "main.h"
#include "keycheck.h"
#include "effect.h"
#include "player.h"
#include "Shot.h"
#include "enemy.h"


int shotImage;
int shotPosX, shotPosY;
int shotSpeed;
int shotFlag;
void ShotSystemInit(void)
{
	shotImage = LoadGraph("image/shot.png");

	shotSpeed = 5;
	shotFlag = false;
}
void ShotConttrol(void)
{
	if (shotFlag == true)
	{
		shotPosY = shotPosY - shotSpeed;
		if (shotPosY < -SHOT_SIZE_Y)
		{
			shotFlag = false;
		}
	}
}

void ShotDraw(void)
{
	if (shotFlag == true)
	{
		DrawGraph(shotPosX, shotPosY, shotImage, true);
	}
}
