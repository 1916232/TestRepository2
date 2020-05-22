#include "DxLib.h"		//DxLibﾗｲﾌﾞﾗﾘを使用する
#include "keycheck.h"

// キー制御用
bool keyOld[KEY_ID_MAX];					// 1フレーム前のキー状態
bool keyNew[KEY_ID_MAX];					// 現在のキー状態
bool keyDownTrigger[KEY_ID_MAX];			// キー押下時のトリガー
bool keyUpTrigger[KEY_ID_MAX];			// キーアップ時のトリガー

// キー制御配列の初期化
void KeyInit(void)
{
	for (int keyID = 0; keyID < KEY_ID_MAX; keyID++)
	{
		keyOld[keyID] = false;
		keyNew[keyID] = false;
		keyDownTrigger[keyID] = false;
		keyUpTrigger[keyID] = false;
	}
}

// キー情報の取得
void KeyCheck(void)
{
	// １フレーム前のキー情報をコピー
	for (int keyID = 0; keyID < KEY_ID_MAX; keyID++)
	{
		keyOld[keyID] = keyNew[keyID];
	}

	//現在のキー情報を取得する
	keyNew[KEY_ID_SPACE] = CheckHitKey(KEY_INPUT_SPACE);
	keyNew[KEY_ID_CLEAR] = CheckHitKey(KEY_INPUT_RCONTROL);
	keyNew[KEY_ID_RIGHT] = CheckHitKey(KEY_INPUT_RIGHT);
	keyNew[KEY_ID_LEFT] = CheckHitKey(KEY_INPUT_LEFT);
	keyNew[KEY_ID_SHOT] = CheckHitKey(KEY_INPUT_LCONTROL);
	
	// トリガー情報を取得する
	for (int keyID = 0; keyID < KEY_ID_MAX; keyID++)
	{
		// トリガー情報の初期化
		keyDownTrigger[keyID] = false;
		keyUpTrigger[keyID] = false;


		// トリガー情報の取得
		if (!keyOld[keyID] && keyNew[keyID])
		{
			keyDownTrigger[keyID] = true;
		}

		if (keyOld[keyID] && !keyNew[keyID])
		{
			keyUpTrigger[keyID] = true;
		}

	}

}