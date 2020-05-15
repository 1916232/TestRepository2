#pragma once

// フェード処理用
extern bool fadeIn;					// フェードイン
extern bool fadeOut;				// フェードアウト

//プロトタイプ宣言
void EffectInit(void);					// エフェクト用初期化処理


// シーン遷移関数
bool FadeInScreen(int fadeStep);		// フェードイン用
bool FadeOutScreen(int fadeStep);		// フェードアウト用


