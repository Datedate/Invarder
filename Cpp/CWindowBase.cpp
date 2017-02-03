#include "../Header/CWindowBase.h"

LRESULT CALLBACK MainWndProc(HWND _hWnd, UINT _msg, WPARAM _wParam, LPARAM _lParam) {
	CWindowBase* pThisPtr = (CWindowBase*)GetWindowLong(_hWnd, GWL_USERDATA);
	if (pThisPtr)
		return (pThisPtr->WndProc(_hWnd, _msg, _wParam, _lParam));
	else
		return (DefWindowProc(_hWnd, _msg, _wParam, _lParam));
}

CWindowBase::CWindowBase(HINSTANCE _hInstance,LPCSTR _wndName,int _width,int _height,int _cmdShow)
{
	Initialize(_hInstance, _wndName, _width, _height,_cmdShow);
}

CWindowBase::~CWindowBase()
{
}
BOOL CWindowBase::Initialize(HINSTANCE _hInstance,LPCSTR _wndName,int _width,int _height,int _cmdShow) {
	if (!(RegisterWnd(_hInstance, _wndName)))
		return FALSE;						// エラー
		
	if (!(CreateWnd(_hInstance, _width, _height,_cmdShow)))
		return FALSE;						// エラー
	return TRUE;
}
BOOL CWindowBase::RegisterWnd(HINSTANCE _hInstance,LPCSTR _wndName) {
	// ウインドウクラスの登録
	m_WndClass.cbSize = sizeof(WNDCLASSEX);							// 構造体の大きさ
	m_WndClass.style = CS_HREDRAW | CS_VREDRAW;						// CS_HREDRAW（水平）又はCS_VREDRAW（垂直）に
																	// ウインドウズサイズが変更されたときに再描画
	m_WndClass.lpfnWndProc = MainWndProc;								// メッセージを受け取るWndProc関数へのポインタを渡す
	m_WndClass.cbClsExtra = m_WndClass.cbWndExtra = 0;				// クラス構造体、ウインドウ構造体の追加領域（BYTE）
	m_WndClass.hInstance = _hInstance;								// アプリケーションのハンドル
	m_WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);				// タスクバーやタイトルバーのアイコンのビットマップ
																	// システム定義されているアイコンを使ってます
	m_WndClass.hCursor = LoadCursor(NULL, IDI_APPLICATION);			// ウインドウのクライアント領域のマウスカーソルの指定
																	// システムで定義されているカーソルを使っています
	m_WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	// クライアント領域の背景色を指定（HBRUSH）のハンドルを渡す
	m_WndClass.lpszMenuName = NULL;									// メニューはいらないのでNULL
	m_WndClass.lpszClassName = _wndName;							// ウインドウクラスの名前

	if (!RegisterClassEx(&m_WndClass))			// ウインドウの基本性能・見た目を登録
		return FALSE;								// 失敗

	return TRUE;									// 成功
}
BOOL CWindowBase::CreateWnd(HINSTANCE _hInstance,int _width,int _height,int _cmdShow ) {
	m_hWnd = CreateWindow(m_WndClass.lpszClassName,
		(LPCSTR)"DirectX9",
		WS_CAPTION | WS_SYSMENU,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		_width,
		_height,
		NULL,
		NULL,
		_hInstance,
		NULL);

	if (!m_hWnd)
		return FALSE;

	//::SetWindowLong(m_hWnd, GWLP_USERDATA, (LONG)this);
	//return TRUE;
	ShowWindow(m_hWnd, _cmdShow);
	UpdateWindow(m_hWnd);
	return true;
}

HWND CWindowBase::GetHwnd() {
	return m_hWnd;
}

LRESULT CWindowBase::WndProc(HWND _hWnd, UINT _msg, WPARAM _wParam, LPARAM _lParam) {
	switch (_msg)
	{
	case WM_KEYDOWN:
		if (_wParam == VK_ESCAPE)
			PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(_hWnd, _msg, _wParam, _lParam);
		break;
	}
	return 0;
}