#ifndef _CAPPBASE_H_
#define _CAPPBASE_H_

#define STRICT					// 型チェックを厳密に行う
#define WIN32_LEAN_AND_MEAN		// ヘッダーからあまり使われない関数を省く

//-----------インクルードファイル-------
#include "CWindowBase.h"				// ウインドウクラス
#include "CGame.h"						// ゲームクラス
#include "CD3D9.h"						// Direct3Device9クラス
#include <memory>
#include <time.h>
#include <mmsystem.h>

//-----------アプリケーションクラスの宣言---------

#pragma comment(lib,"winmm.lib")

struct FPSControl {
	int countFps;
	DWORD dwLostTime, dwCurrentTime, dwFrameCount;	// FPS計算用
	const float FPS = 1000.0f / 60;
	bool ElapsedTime() {
		dwCurrentTime = timeGetTime();
		return (dwCurrentTime - dwLostTime >= FPS);
	}
};

class CApplicationBase
{

// コンストラクタとデストラクタ
public:
	CApplicationBase() = delete;
	CApplicationBase(HINSTANCE _hInstance,int _cmdShow);
	virtual ~CApplicationBase();

// メンバ変数
private:
	HINSTANCE m_hInstance;		// アプリケーションハンドル
	WNDCLASSEX m_WndClassEx;	// ウインドウクラスの構造体
protected:
	std::unique_ptr<CWindowBase> m_Wnd;			// ウインドウクラス
	std::unique_ptr<CGame> m_game;				// ゲームクラス
	std::unique_ptr<CD3D9> m_D3D9;				// D3D9クラス
	FPSControl m_fps;
// メンバ関数
public:
	// 実行
	int Run(HINSTANCE hInstance);
private:
	// インスタンスハンドルを取得
	HINSTANCE GetHInstance() { return m_hInstance; }
	// ウインドウクラス構造体を取得
	void GetWndClass(WNDCLASSEX* wc) { *wc = m_WndClassEx; }
	// アプリケーション独自の初期化処理
	void Initialize(HINSTANCE _hInstance,int _cmdShow);
	// メッセージループ
	void Loop();
	// アプリケーションの終了処理
	void ReleaseApp();

};



#endif