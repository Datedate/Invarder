#ifndef _CWINDOWBASE_H_
#define _CWINDOWBASE_H_

//-----------�C���N���[�h�t�@�C��-------
#include <Windows.h>
class CWindowBase
{

// �R���X�g���N�^�E�f�X�g���N�^
public:
	CWindowBase() = delete;
	CWindowBase(HINSTANCE _hInstance, LPCSTR _wndName, int _width, int _height,int _cmdShow);
	~CWindowBase();
													
	BOOL Initialize(HINSTANCE _hInstance,LPCSTR _wndName,int _width,int _height,int _cmdShow);	// �������֐�
	BOOL RegisterWnd(HINSTANCE _hInstance, LPCSTR _wndName);		// �E�C���h�E�N���X�̓o�^
	BOOL CreateWnd(HINSTANCE _hInstance,int _width,int _height,int _cmdShow);	// �E�C���h�E�̍쐬
	HWND GetHwnd();
	// �E�C���h�E�v���V�[�W���֐�
	LRESULT WndProc(HWND _hWnd, UINT _msg, WPARAM _wParam, LPARAM _lParam);

private:
	WNDCLASSEX m_WndClass;	// �E�C���h�E�N���X�̍\����
protected:
	HWND m_hWnd;									// �E�C���h�E�n���h������������
};


#endif