#include "../Header/CGame.h"
CGame::CGame(const LPDIRECT3DDEVICE9 &_pd3dDevice,HINSTANCE _hInstance,HWND _hWnd)
{
	m_pd3dDevice = _pd3dDevice;
	m_StateManager.Init(m_pd3dDevice);
	CDirectInput::GetInstance()->Init(_hInstance,_hWnd);
}

CGame::~CGame()
{
	CDirectInput::GetInstance()->UnInit();
}

HRESULT CGame::Update() {
	HRESULT hr = E_FAIL;
	CDirectInput::GetInstance()->Update();
	if (FINISH == m_StateManager.Update())
		hr = S_OK;
	return hr;
}
 