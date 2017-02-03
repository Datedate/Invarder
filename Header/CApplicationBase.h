#ifndef _CAPPBASE_H_
#define _CAPPBASE_H_

#define STRICT					// �^�`�F�b�N�������ɍs��
#define WIN32_LEAN_AND_MEAN		// �w�b�_�[���炠�܂�g���Ȃ��֐����Ȃ�

//-----------�C���N���[�h�t�@�C��-------
#include "CWindowBase.h"				// �E�C���h�E�N���X
#include "CGame.h"						// �Q�[���N���X
#include "CD3D9.h"						// Direct3Device9�N���X
#include <memory>
#include <time.h>
#include <mmsystem.h>

//-----------�A�v���P�[�V�����N���X�̐錾---------

#pragma comment(lib,"winmm.lib")

struct FPSControl {
	int countFps;
	DWORD dwLostTime, dwCurrentTime, dwFrameCount;	// FPS�v�Z�p
	const float FPS = 1000.0f / 60;
	bool ElapsedTime() {
		dwCurrentTime = timeGetTime();
		return (dwCurrentTime - dwLostTime >= FPS);
	}
};

class CApplicationBase
{

// �R���X�g���N�^�ƃf�X�g���N�^
public:
	CApplicationBase() = delete;
	CApplicationBase(HINSTANCE _hInstance,int _cmdShow);
	virtual ~CApplicationBase();

// �����o�ϐ�
private:
	HINSTANCE m_hInstance;		// �A�v���P�[�V�����n���h��
	WNDCLASSEX m_WndClassEx;	// �E�C���h�E�N���X�̍\����
protected:
	std::unique_ptr<CWindowBase> m_Wnd;			// �E�C���h�E�N���X
	std::unique_ptr<CGame> m_game;				// �Q�[���N���X
	std::unique_ptr<CD3D9> m_D3D9;				// D3D9�N���X
	FPSControl m_fps;
// �����o�֐�
public:
	// ���s
	int Run(HINSTANCE hInstance);
private:
	// �C���X�^���X�n���h�����擾
	HINSTANCE GetHInstance() { return m_hInstance; }
	// �E�C���h�E�N���X�\���̂��擾
	void GetWndClass(WNDCLASSEX* wc) { *wc = m_WndClassEx; }
	// �A�v���P�[�V�����Ǝ��̏���������
	void Initialize(HINSTANCE _hInstance,int _cmdShow);
	// ���b�Z�[�W���[�v
	void Loop();
	// �A�v���P�[�V�����̏I������
	void ReleaseApp();

};



#endif