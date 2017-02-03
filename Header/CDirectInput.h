#ifndef _DIRECT_INPUT_H_
#define _DIRECT_INPUT_H_

//-----------------�}�N����`------------------
#define DIRECTINPUT_VERSION     0x0800          // DirectInput�̃o�[�W�����w��

#define RELEASE(x){if(x)x->Release();}

//------------�C���N���[�h�t�@�C��-------------
#include "SingletonBase.h"
#include <dinput.h>

//---------------���C�u�����ǉ�----------------
#pragma comment(lib, "dxguid.lib")
#pragma comment(lib, "dinput8.lib")

class CDirectInput:public SingletonBase<CDirectInput>
{
	friend SingletonBase<CDirectInput>;
	enum {
		PUSH_BIT=0x80,								// �����ꂽ���̃r�b�g
		INPUT_BUFFER_SIZE = 256 };					// �o�b�t�@�[�T�C�Y
public:
	/* �������E�X�V���� */
	HRESULT Init(HINSTANCE _hInstance,HWND _hWnd);		// ����������
	HRESULT InitKey(HINSTANCE _hInstance, HWND _hWnd);  // �L�[�{�[�h����������
	void Update();										// �X�V����
	void UnInit();
	void UnInitKey();
	
	/* �L�[�����`�F�b�N */
	bool KeyTrigger(int _code);							// �L�[�������ꂽ�u��
	bool KeyRelease(int _code);							// �L�[�������ꂽ�u��
	bool KeyPress(int _code);							// �L�[��������Ă����
	bool KeyRepeat(int _code);

private:
	CDirectInput() {};
	~CDirectInput() {};
private:
	// DirectInput�p�I�u�W�F�N�g�E�f�o�C�X
	LPDIRECTINPUT8 m_pDirectInput;						// DirectInput�I�u�W�F�N�g
	LPDIRECTINPUTDEVICE8 m_pKeyDevice;					// �L�[�{�[�h�p�̃f�o�C�X

	// �L�[�{�[�h�̏��̔z��
	BYTE	m_keyState[INPUT_BUFFER_SIZE];			// �L�[�{�[�h�̏�Ԃ��󂯎�郏�[�N
	BYTE	m_keyStateTrigger[INPUT_BUFFER_SIZE];		// �L�[�{�[�h�̏�Ԃ��󂯎�郏�[�N
	BYTE	m_keyStateRepeat[INPUT_BUFFER_SIZE];		// �L�[�{�[�h�̏�Ԃ��󂯎�郏�[�N
	BYTE	m_keyStateRelease[INPUT_BUFFER_SIZE];		// �L�[�{�[�h�̏�Ԃ��󂯎�郏�[�N
	int		m_keyStateRepeatCnt[INPUT_BUFFER_SIZE];	// �L�[�{�[�h�̃��s�[�g�J�E���^

	HWND m_hWnd;										// �E�C���h�E�n���h��
};



#endif