#ifndef _CD3D9_H_
#define _CD3D9_H_

//-----------インクルードファイル-------
#include <windows.h>
#include <d3dx9.h>

//-----------ライブラリ追加------------
#pragma comment(lib,"d3d9.lib")
#if defined(DEBUG) || defined(_DEBUG)
#pragma comment(lib,"d3dx9d.lib")
#else
#pragma comment(lib,"d3dx9.lib")
#endif
#pragma comment(lib,"dxerr.lib")
#pragma comment(lib,"dxguid.lib")

//-----------マクロ定義----------
#define RELEASE(x){if(x)x->Release();}

class CD3D9
{
public:
	CD3D9();
	~CD3D9();
	BOOL Initialize(HWND _hWnd,int _width,int _height);
	LPDIRECT3DDEVICE9 GetPtrD3dDevice();
private:
	LPDIRECT3D9 m_pD3D;
	LPDIRECT3DDEVICE9 m_pd3dDevice;
	D3DPRESENT_PARAMETERS m_d3dpp;
};

#endif