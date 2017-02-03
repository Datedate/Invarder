#ifndef _CGAME_H_
#define _CGAME_H_

//--------------インクルードファイル------------
#include "CD3D9.h"
#include "CSceneManager.h"


class CGame
{
public:
	CGame()=delete;
	CGame(const LPDIRECT3DDEVICE9 &_pd3dDevice, HINSTANCE _hInstance, HWND _hWnd);
	virtual ~CGame();
	virtual HRESULT Update();
public :
	LPDIRECT3DDEVICE9 m_pd3dDevice;
private:
	// シーン管理者
	CSceneManager m_StateManager;
};


#endif