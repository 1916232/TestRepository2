#include "DxLib.h"		//DxLibﾗｲﾌﾞﾗﾘを使用する
#include "effect.h"

// フェード処理用
bool fadeIn;				// フェードイン
bool fadeOut;				// フェードアウト
int fadeCnt;				// フェードカウンタ


// エフェクト用初期化処理
void EffectInit(void)
{
	// フェード管理用
	fadeIn = true;
	fadeOut = false;
	fadeCnt = 0;
}

// フェードイン用
bool FadeInScreen(int fadeStep)
{
	if (fadeCnt < 255)
	{
		SetDrawBright(fadeCnt, fadeCnt, fadeCnt);
		fadeCnt += fadeStep;
		return true;
	}
	else
	{
		SetDrawBright(255, 255, 255);
		fadeIn = false;
		fadeCnt = 0;
		return false;
	}
}

// フェードアウト用
bool FadeOutScreen(int fadeStep)
{
	if (fadeCnt <= 255)
	{
		SetDrawBright(255 - fadeCnt, 255 - fadeCnt, 255 - fadeCnt);
		fadeCnt += fadeStep;
		return true;
	}

	if (fadeCnt >= 255)
	{
		SetDrawBright(0, 0, 0);
		fadeOut = false;
		fadeCnt = 0;
		return false;
	}
}