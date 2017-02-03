#include "../Header/CDirectInput.h"

HRESULT CDirectInput::Init(HINSTANCE _hInstance,HWND _hWnd) {
	HRESULT hr;

	if (!m_pDirectInput)
	{
		// DirectInput�I�u�W�F�N�g�̍쐬
		hr = DirectInput8Create(_hInstance, DIRECTINPUT_VERSION,
			IID_IDirectInput8, (void**)&m_pDirectInput, NULL);
	}

	// �L�[�{�[�h�̏�����
	InitKey(_hInstance, _hWnd);

	m_hWnd = _hWnd;

	return hr;

}

HRESULT CDirectInput::InitKey(HINSTANCE _hInstance, HWND _hWnd) {
	
	HRESULT hr;

	// �f�o�C�X�I�u�W�F�N�g���쐬
	hr = m_pDirectInput->CreateDevice(GUID_SysKeyboard, &m_pKeyDevice, NULL);
	if (FAILED(hr) || m_pKeyDevice == NULL)
	{
		MessageBox(_hWnd, "�L�[�{�[�h���˂��I", "�x���I", MB_ICONWARNING);
		return hr;
	}

	// �f�[�^�t�H�[�}�b�g��ݒ�
	hr = m_pKeyDevice->SetDataFormat(&c_dfDIKeyboard);
	if (FAILED(hr))
	{
		MessageBox(_hWnd, "�L�[�{�[�h�̃f�[�^�t�H�[�}�b�g��ݒ�ł��܂���ł����B", "�x���I", MB_ICONWARNING);
		return hr;
	}

	// �������[�h��ݒ�i�t�H�A�O���E���h����r�����[�h�j
	hr = m_pKeyDevice->SetCooperativeLevel(_hWnd, (DISCL_FOREGROUND | DISCL_NONEXCLUSIVE));
	if (FAILED(hr))
	{
		MessageBox(_hWnd, "�L�[�{�[�h�̋������[�h��ݒ�ł��܂���ł����B", "�x���I", MB_ICONWARNING);
		return hr;
	}

	// �L�[�{�[�h�ւ̃A�N�Z�X�����l��(���͐���J�n)
	m_pKeyDevice->Acquire();

	return S_OK;
}

void CDirectInput::Update() {
	BYTE keyStateOld[256];

	// �O��̃f�[�^��ۑ�
	memcpy(keyStateOld, m_keyState, INPUT_BUFFER_SIZE);

	// �f�o�C�X����f�[�^���擾
	m_pKeyDevice->GetDeviceState(sizeof(m_keyState), m_keyState);
	for (int cnt = 0; cnt < INPUT_BUFFER_SIZE; cnt++)
	{
		// �g���K�[�ƃ����[�X���擾
		m_keyStateTrigger[cnt] = (m_keyState[cnt] ^ keyStateOld[cnt]) & m_keyState[cnt];
		m_keyStateRelease[cnt] = (m_keyState[cnt] ^ keyStateOld[cnt]) & keyStateOld[cnt];

		// �L�[��������Ă���Ȃ烊�s�[�g�̔��菈��
		if (m_keyState[cnt])
		{
			if (m_keyStateRepeatCnt[cnt] < 20)
			{
				m_keyStateRepeatCnt[cnt]++;
				// �u������́v�������́u�{�^���������Ă���20�t���[���o�߁v
				// �����ꍇ�A���s�[�g�p�z��̃f�[�^��L���ɂ���
				// ��L�����ȊO�̓��s�[�g�p�z��̃f�[�^�𖳌��ɂ���
				if (m_keyStateRepeatCnt[cnt] == 1 || m_keyStateRepeatCnt[cnt] >= 20) {
					m_keyStateRepeat[cnt] = 0x80;
				}
				else {
					m_keyStateRepeat[cnt] = 0;
				}
			}
		}
		else
		{
			m_keyStateRepeatCnt[cnt] = 0;
			m_keyStateRepeat[cnt] = 0;
		}
	}

}



/* �L�[�����`�F�b�N */
// �O�񉟂���Ă��Ȃ��āA���݉�����Ă����Ԃł����true��Ԃ�
bool CDirectInput::KeyTrigger(int _code) {
	return ((m_keyStateTrigger[_code] & 0x80) != 0);
}
// �O�񉟂���Ă��āA���݉�����Ă��Ȃ���Ԃł����true��Ԃ�
bool CDirectInput::KeyRelease(int _code) {
	return ((m_keyStateRelease[_code] & 0x80) != 0);
}
// ���݉�����Ă����Ԃł����true�ŕԂ�
bool CDirectInput::KeyPress(int _code) {
	return ((m_keyState[_code] & 0x80) != 0);
}
bool CDirectInput::KeyRepeat(int _code) {
	return ((m_keyStateRepeat[_code] & 0x80) != 0);
}

void CDirectInput::UnInit() {
	// �L�[�{�[�h�̏I������
	UnInitKey();

	if (m_pDirectInput)
	{
		m_pDirectInput->Release();
		m_pDirectInput = NULL;
	}
}
void CDirectInput::UnInitKey() {
	if (m_pKeyDevice)
	{
		m_pKeyDevice->Unacquire();

		m_pKeyDevice->Release();
		m_pKeyDevice = NULL;
	}
}