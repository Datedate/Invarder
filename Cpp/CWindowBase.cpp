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
		return FALSE;						// �G���[
		
	if (!(CreateWnd(_hInstance, _width, _height,_cmdShow)))
		return FALSE;						// �G���[
	return TRUE;
}
BOOL CWindowBase::RegisterWnd(HINSTANCE _hInstance,LPCSTR _wndName) {
	// �E�C���h�E�N���X�̓o�^
	m_WndClass.cbSize = sizeof(WNDCLASSEX);							// �\���̂̑傫��
	m_WndClass.style = CS_HREDRAW | CS_VREDRAW;						// CS_HREDRAW�i�����j����CS_VREDRAW�i�����j��
																	// �E�C���h�E�Y�T�C�Y���ύX���ꂽ�Ƃ��ɍĕ`��
	m_WndClass.lpfnWndProc = MainWndProc;								// ���b�Z�[�W���󂯎��WndProc�֐��ւ̃|�C���^��n��
	m_WndClass.cbClsExtra = m_WndClass.cbWndExtra = 0;				// �N���X�\���́A�E�C���h�E�\���̂̒ǉ��̈�iBYTE�j
	m_WndClass.hInstance = _hInstance;								// �A�v���P�[�V�����̃n���h��
	m_WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);				// �^�X�N�o�[��^�C�g���o�[�̃A�C�R���̃r�b�g�}�b�v
																	// �V�X�e����`����Ă���A�C�R�����g���Ă܂�
	m_WndClass.hCursor = LoadCursor(NULL, IDI_APPLICATION);			// �E�C���h�E�̃N���C�A���g�̈�̃}�E�X�J�[�\���̎w��
																	// �V�X�e���Œ�`����Ă���J�[�\�����g���Ă��܂�
	m_WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	// �N���C�A���g�̈�̔w�i�F���w��iHBRUSH�j�̃n���h����n��
	m_WndClass.lpszMenuName = NULL;									// ���j���[�͂���Ȃ��̂�NULL
	m_WndClass.lpszClassName = _wndName;							// �E�C���h�E�N���X�̖��O

	if (!RegisterClassEx(&m_WndClass))			// �E�C���h�E�̊�{���\�E�����ڂ�o�^
		return FALSE;								// ���s

	return TRUE;									// ����
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