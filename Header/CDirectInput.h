#ifndef _DIRECT_INPUT_H_
#define _DIRECT_INPUT_H_

//-----------------マクロ定義------------------
#define DIRECTINPUT_VERSION     0x0800          // DirectInputのバージョン指定

#define RELEASE(x){if(x)x->Release();}

//------------インクルードファイル-------------
#include "SingletonBase.h"
#include <dinput.h>

//---------------ライブラリ追加----------------
#pragma comment(lib, "dxguid.lib")
#pragma comment(lib, "dinput8.lib")

class CDirectInput:public SingletonBase<CDirectInput>
{
	friend SingletonBase<CDirectInput>;
	enum {
		PUSH_BIT=0x80,								// 押されたかのビット
		INPUT_BUFFER_SIZE = 256 };					// バッファーサイズ
public:
	/* 初期化・更新処理 */
	HRESULT Init(HINSTANCE _hInstance,HWND _hWnd);		// 初期化処理
	HRESULT InitKey(HINSTANCE _hInstance, HWND _hWnd);  // キーボード初期化処理
	void Update();										// 更新処理
	void UnInit();
	void UnInitKey();
	
	/* キー押下チェック */
	bool KeyTrigger(int _code);							// キーが押された瞬間
	bool KeyRelease(int _code);							// キーが離された瞬間
	bool KeyPress(int _code);							// キーが押されている間
	bool KeyRepeat(int _code);

private:
	CDirectInput() {};
	~CDirectInput() {};
private:
	// DirectInput用オブジェクト・デバイス
	LPDIRECTINPUT8 m_pDirectInput;						// DirectInputオブジェクト
	LPDIRECTINPUTDEVICE8 m_pKeyDevice;					// キーボード用のデバイス

	// キーボードの情報の配列
	BYTE	m_keyState[INPUT_BUFFER_SIZE];			// キーボードの状態を受け取るワーク
	BYTE	m_keyStateTrigger[INPUT_BUFFER_SIZE];		// キーボードの状態を受け取るワーク
	BYTE	m_keyStateRepeat[INPUT_BUFFER_SIZE];		// キーボードの状態を受け取るワーク
	BYTE	m_keyStateRelease[INPUT_BUFFER_SIZE];		// キーボードの状態を受け取るワーク
	int		m_keyStateRepeatCnt[INPUT_BUFFER_SIZE];	// キーボードのリピートカウンタ

	HWND m_hWnd;										// ウインドウハンドル
};



#endif