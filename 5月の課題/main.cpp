/*--------1---------2---------3---------4---------5---------6---------7-------*/
//
//   testproject = main.cpp
//
//   
//
/*--------1---------2---------3---------4---------5---------6---------7-------*/
#include "DxLib.h"		//Dxlibライブラリを使用する
#include "main.h"
#include "keycheck.h"
#include "effect.h"

SCN_ID scnID;	//ｹﾞｰﾑの状況移管理用
SCN_ID ScnID_Old;//ｹﾞｰﾑの状態管理用


//変数
//----------------------------------
int gameCounter;
int haikeiImage;
int titleImage;
int overImage;

int playerImage;				//自機の画像ID
int playerPosX;					//自機のX座標
int playerPosY;					//自機のY座標

int enemyImage;




//ファイル操作関数
//bool SaveData(void);
//bool LoadData(void);

// ========= WinMain関数
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	if (!SystemInit())
	{
		return 0;
	}

	ClsDrawScreen(); // 画面消去

	// --------ゲームループ
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		
		KeyCheck();

		ClsDrawScreen(); // 画面消去

		switch (scnID)
		{
		case SCN_ID_TITLE:
			if (fadeIn)
			{
				if (!FadeInScreen(5)) {} // フェードインが終わった後の処理を書く
			}
			if (fadeOut)
			{
				if (!FadeOutScreen(5))
				{// フェードアウトが終わった後の処理を書く
					fadeIn = true;
					scnID = SCN_ID_GAME;
				}
			}
			TitleScene();
			break;
		case SCN_ID_GAME:
			if (fadeIn)
			{
				if (!FadeInScreen(5)) {} // フェードインが終わった後の処理を書く
			}
			if (fadeOut)
			{
				if (!FadeOutScreen(5))
				{// フェードアウトが終わった後の処理を書く
					fadeIn = true;
					scnID = SCN_ID_GAMEOVER;
				}
			}
			GameScene();
			break;
		case SCN_ID_GAMEOVER:
			if (fadeIn)
			{
				if (!FadeInScreen(5)) {} // フェードインが終わった後の処理を書く
			}
			if (fadeOut)
			{
				if (!FadeOutScreen(5))
				{// フェードアウトが終わった後の処理を書く
					fadeIn = true;
					scnID = SCN_ID_TITLE;
				}
			}
			GameOverScene();
			break;
		default:
			break;
		}

	}

	DxLib_End();			// DXライブラリの終了処理
	return 0;				//このプログラムの終了
}

//---------------------------------------------
// システムの初期化
bool SystemInit(void)
{
	bool rtnFlag = true;
	// ----------システム処理
	SetWindowText("カペリート");
	//システム処理
	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, 16);
	ChangeWindowMode(true);							//true:window false:フルスクリーン
	if (DxLib_Init() == -1)							//DXライブラリ初期化処理
	{
		return false;
	}
	SetDrawScreen(DX_SCREEN_BACK);					//ひとまずバックバッファに描画

	KeyInit();

	// ------グラフィックの登録　---------
	//ﾀｲﾄﾙ画面
	if ((titleImage = LoadGraph("image/title.png")) == -1)
	{
		rtnFlag = false;
	}
	//ゲームオーバー
	if ((overImage = LoadGraph("image/over.png")) == -1)
	{
		rtnFlag = false;
	}
	//背景
	if ((haikeiImage = LoadGraph("image/haikei.png")) == -1)
	{
		rtnFlag = false;
	}
	//自機
	playerImage = LoadGraph("image/player.png");
	//敵
	enemyImage = LoadGraph("image/enemy.png");


	// ------変数初期化　-----------
	gameCounter = 0;


	//ファイル用データ初期化
	///fileData.data1 = 1000;
	//fileData.hiscore = 5000;


	EffectInit();			// エフェクト用初期化処理

	return rtnFlag;
}

//ﾀｲﾄﾙｼｰﾝ用初期化
bool TitleInit(void)
{
	bool rtnFlag = true;	//返り値用変数

	scnID = SCN_ID_TITLE;

	return rtnFlag;
}

//ﾀｲﾄﾙ画面処理
void TitleScene(void)
{
	if (keyDownTrigger[KEY_ID_SPACE])
	{
		fadeOut = true;
		//scnID = SCN_ID_GAME;
	}
	TitleDraw();
}

void TitleDraw(void)
{
	ClsDrawScreen();	//画面消去

	//ﾀｲﾄﾙﾛｺﾞ表示
	DrawGraph(0, 0, titleImage, true);
	
	ScreenFlip();	//バックバッファとフロントﾊﾞｯﾌｧを入れ替える
}

//ｹﾞｰﾑｼｰﾝ用の初期化
bool GameInit(void)
{
	bool rtnFlag = true;	// 返り値用変数

	scnID = SCN_ID_GAME;

	return rtnFlag;
}

void GameScene(void)
{
	GameDraw();
	if (keyDownTrigger[KEY_ID_SPACE])
	{
		//scnID = SCN_ID_GAMEOVER;
		fadeOut = true;
	}
	
}

//---------------------------------------------
// プレイ中の描画
void GameDraw(void)
{
	ClsDrawScreen();	//裏になっているﾊﾞｯﾌｧをｸﾘｱする。

	//背景描画
	DrawGraph(0, 0, haikeiImage, true);

	/*DrawGraph(0, 450, playerImage, true);

	DrawGraph(150, 450, enemyImage, true);*/

	ScreenFlip();		// 裏画面と表画面を入れ替える
}

//ｹﾞｰﾑｵｰﾊﾞｰｼｰﾝの初期化
bool GameOverInit(void)
{
	int rtnFlag = true;	//返り値変数

	scnID = SCN_ID_GAMEOVER;

	return rtnFlag;
}

void GameOverScene(void)
{
	GameOverDraw();

	if (keyDownTrigger[KEY_ID_SPACE])
	{
		fadeOut = true;
		//scnID = SCN_ID_TITLE;
	}
	
}

void GameOverDraw(void)
{
	ClsDrawScreen();	//裏になっているﾊﾞｯﾌｧをｸﾘｱする。

	DrawGraph(0, 0, overImage, true);

	ScreenFlip();
}



