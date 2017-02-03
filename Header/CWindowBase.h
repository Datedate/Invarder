#ifndef _CWINDOWBASE_H_
#define _CWINDOWBASE_H_

//-----------インクルードファイル-------
#include <Windows.h>
class CWindowBase
{

// コンストラクタ・デストラクタ
public:
	CWindowBase() = delete;
	CWindowBase(HINSTANCE _hInstance, LPCSTR _wndName, int _width, int _height,int _cmdShow);
	~CWindowBase();
													
	BOOL Initialize(HINSTANCE _hInstance,LPCSTR _wndName,int _width,int _height,int _cmdShow);	// 初期化関数
	BOOL RegisterWnd(HINSTANCE _hInstance, LPCSTR _wndName);		// ウインドウクラスの登録
	BOOL CreateWnd(HINSTANCE _hInstance,int _width,int _height,int _cmdShow);	// ウインドウの作成
	HWND GetHwnd();
	// ウインドウプロシージャ関数
	LRESULT WndProc(HWND _hWnd, UINT _msg, WPARAM _wParam, LPARAM _lParam);

private:
	WNDCLASSEX m_WndClass;	// ウインドウクラスの構造体
protected:
	HWND m_hWnd;									// ウインドウハンドルを所持する
};


#endif