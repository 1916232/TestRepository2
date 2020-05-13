#pragma once

//画面
#define	SCREEN_SIZE_X	600	//画面の横サイズ
#define	SCREEN_SIZE_Y	500	//画面の縦サイズ

//ｹﾞｰﾑｻｲｽﾞ
#define	GAME_SIZE_X		600	//ゲームエリアの横サイズ
#define	GAME_SIZE_Y		500	//ゲームエリアの縦サイズ

//自機
#define	PLAYER_SIZE_X	48	//自機画像の横サイズ
#define	PLAYER_SIZE_Y	48	//自機画像の縦サイズ

//敵
#define	ENEMY_SIZE_X	32	//敵画像の横サイズ
#define	ENEMY_SIZE_Y	32	//敵画像の縦サイズ

//プロトタイプ宣言
//----------------------------------
bool SystemInit(void);

void GameMain(void);

void GameMainDraw(void);

//基幹関数
bool SystemInit(void);

void GameMain(void);

void GameMainDraw(void);
