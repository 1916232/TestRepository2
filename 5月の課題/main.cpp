/*--------1---------2---------3---------4---------5---------6---------7-------*/
//
//   testproject = main.cpp
//
//   
//
/*--------1---------2---------3---------4---------5---------6---------7-------*/
#include "DxLib.h"		//Dxlibライブラリを使用する
#include "main.h"

//定数
//----------------------------------
#define SCREEN_SIZE_X 600
#define SCREEN_SIZE_Y 500

//変数
//----------------------------------
int gameCounter;
int haikeiImage;

int playerImage;				//自機の画像ID
int playerPosX;					//自機のX座標
int playerPosY;					//自機のY座標

int enemyImage;

//構造体定義
struct FILE_DATA {
	int data1;
	int hiscore;
};

//ファイル情報定義
char filename[] = "data.dat";
struct FILE_DATA fileData;



//ファイル操作関数
//bool SaveData(void);
//bool LoadData(void);

// ========= WinMain関数
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	// システムの初期化
	if (SystemInit() == false)
	{
		return -1;
	}

	// --------ゲームループ
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		ClsDrawScreen();	//画面消去

		GameMain();

		gameCounter++;
		ScreenFlip();		//裏画面を表画面に瞬間コピー
	}

	DxLib_End();			// DXライブラリの終了処理
	return 0;				//このプログラムの終了
}

//---------------------------------------------
// システムの初期化
bool SystemInit(void)
{
	// ----------システム処理
	SetWindowText("TestProject");
	//システム処理
	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, 16);
	ChangeWindowMode(true);							//true:window false:フルスクリーン
	if (DxLib_Init() == -1)							//DXライブラリ初期化処理
	{
		return false;
	}
	SetDrawScreen(DX_SCREEN_BACK);					//ひとまずバックバッファに描画

	// ------グラフィックの登録　---------

	//背景
	haikeiImage = LoadGraph("image/haikei.png");
	//自機
	playerImage = LoadGraph("image/player.png");

	enemyImage = LoadGraph("image/enemy.png");


	// ------変数初期化　-----------
	gameCounter = 0;


	//ファイル用データ初期化
	///fileData.data1 = 1000;
	//fileData.hiscore = 5000;

	return true;
}

//---------------------------------------------
// プレイ中処理
void GameMain(void)
{
	GameMainDraw();
}


//---------------------------------------------
// プレイ中の描画
void GameMainDraw(void)
{


	//背景描画
	DrawGraph(0, 0, haikeiImage, true);

	DrawGraph(0, 450, playerImage, true);

	DrawGraph(150, 450, enemyImage, true);

	DrawFormatString(0, 0, 0xFFFFFF, "GameMain : %d", gameCounter);
}


