#include "../Header/CD3D9.h"

CD3D9::CD3D9()
{

}

CD3D9::~CD3D9()
{
	RELEASE(m_pd3dDevice);
	RELEASE(m_pD3D);
}

BOOL CD3D9::Initialize(HWND _hWnd, int _width, int _height) {
	// IDirect3D9�̃R���|�[�l���g�擾
	if (NULL == (m_pD3D = Direct3DCreate9(D3D_SDK_VERSION)))
		return FALSE;
	// IDirectD3D9DEVICE�̐ݒ�
	ZeroMemory(&m_d3dpp, sizeof(D3DPRESENT_PARAMETERS));											//�\���̂̒��g���O�ŏ�����
	m_d3dpp.BackBufferWidth = _width;
	m_d3dpp.BackBufferHeight = _height;
	m_d3dpp.BackBufferCount = 1;
	m_d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
	m_d3dpp.MultiSampleType = D3DMULTISAMPLE_NONE;
	m_d3dpp.MultiSampleQuality = 0;
	m_d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	m_d3dpp.hDeviceWindow = NULL;
	m_d3dpp.Windowed = TRUE;
	m_d3dpp.EnableAutoDepthStencil = TRUE;
	m_d3dpp.AutoDepthStencilFormat = D3DFMT_D16;
	m_d3dpp.Flags = 0;
	m_d3dpp.FullScreen_RefreshRateInHz = D3DPRESENT_RATE_DEFAULT;
	m_d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_DEFAULT;

	// IDirectD3D9DEVICE�̃R���|�[�l���g���擾
	if (FAILED(m_pD3D->CreateDevice(
		D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,								// �n�[�h�E�F�A�̏��� 
		_hWnd,
		D3DCREATE_HARDWARE_VERTEXPROCESSING,		// �n�[�h�E�F�A���_����
		&m_d3dpp,
		&m_pd3dDevice)))
		return FALSE;				

	//�A���t�@�u�����h�̐ݒ�
	m_pd3dDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
	m_pd3dDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	m_pd3dDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	m_pd3dDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	m_pd3dDevice->LightEnable(0, FALSE);

	return TRUE;
}

LPDIRECT3DDEVICE9 CD3D9::GetPtrD3dDevice() {
	return m_pd3dDevice;
}