#pragma once
enum KEY_ID
{
	KEY_ID_SPACE,
	KEY_ID_CLEAR,
	KEY_ID_RIGHT,
	KEY_ID_LEFT,
	KEY_ID_SHOT,
	KEY_ID_MAX,
};

// プロトタイプ宣言
//---------------------
void KeyInit(void);				// キー制御配列の初期化処理
void KeyCheck(void);			// キー情報の取得


// キー制御用
extern bool keyOld[KEY_ID_MAX];					// 1フレーム前のキー状態
extern bool keyNew[KEY_ID_MAX];					// 現在のキー状態
extern bool keyDownTrigger[KEY_ID_MAX];			// キー押下時のトリガー
extern bool keyUpTrigger[KEY_ID_MAX];			// キーアップ時のトリガー