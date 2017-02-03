#include "../Header/CApplicationBase.h"

CApplicationBase::CApplicationBase(HINSTANCE _hInstance,int _cmdShow) {
	Initialize(_hInstance,_cmdShow);
}

CApplicationBase::~CApplicationBase() {}



int CApplicationBase::Run(HINSTANCE hInstance) {		
	Loop();								// ���b�Z�[�W���[�v
	ReleaseApp();						// �A�v���P�[�V�����̏I������
	return S_OK;
}



void CApplicationBase::Initialize(HINSTANCE _hInstance,int _cmdShow){
	m_hInstance = _hInstance;			// �C���X�^���X�n���h���̕ێ�
	m_Wnd.reset(new CWindowBase(m_hInstance, (LPCSTR)"Directx9 class", 640, 480,_cmdShow));
	m_D3D9.reset(new CD3D9);
	m_D3D9->Initialize(m_Wnd->GetHwnd(), 640, 480);
	m_game.reset(new CGame(
		m_D3D9->GetPtrD3dDevice()
		, m_hInstance
		, m_Wnd->GetHwnd()));
}


void CApplicationBase::Loop() {
	MSG msg;

	timeBeginPeriod(1);
	m_fps.dwLostTime = timeGetTime();
	m_fps.dwCurrentTime = m_fps.dwFrameCount = 0;

	while (1) {
		if (PeekMessage(&msg, NULL, 0, 0, PM_NOREMOVE)) {
			if (GetMessage(&msg, NULL, 0, 0) == 0) {
				break;										//	"WM_QUIT"���b�Z�[�W���擾�����ꍇ"0"��Ԃ�
			}
			//	���b�Z�[�W�̖|��Ƒ��o
			TranslateMessage(&msg);							//	���z�L�[���b�Z�[�W�𕶎����b�Z�[�W�֕ϊ�
			DispatchMessage(&msg);							//	�E�B���h�E�v���V�[�W���փ��b�Z�[�W�𑗏o
		}
		else if (m_fps.ElapsedTime()) {
			m_fps.dwLostTime = m_fps.dwCurrentTime;
			if (SUCCEEDED(m_game->Update()))
				break;
			m_fps.dwFrameCount++;
		}
	}
}
void CApplicationBase::ReleaseApp() {
}