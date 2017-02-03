#include "../Header/CSceneManager.h"



CSceneManager::CSceneManager(){}

CSceneManager::~CSceneManager()
{
	UnInit();
}

void CSceneManager::Init(const LPDIRECT3DDEVICE9& _dev) {
	CSceneCommonData::m_pd3dDevice = _dev;
	m_scene = new CTitleScene();
}
void CSceneManager::UnInit() {
	delete m_scene;
}
SCENE_RESULT CSceneManager::Update() {
	Process();
	Render();
	ChangeScene();
	return m_sceneResult;
}

void CSceneManager::Process() {	
	m_sceneResult = m_scene->Update();
}
void CSceneManager::Render() {
	CSceneCommonData::m_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(255, 255, 255), 1.0f, 0);
	if (SUCCEEDED(CSceneCommonData::m_pd3dDevice->BeginScene())) {
		// •`‰æŠJŽn
		CSceneCommonData::m_pd3dDevice->SetFVF(MY_FVF);
		m_scene->Render();
		CSceneCommonData::m_pd3dDevice->EndScene();
	}CSceneCommonData::m_pd3dDevice->Present(NULL, NULL , NULL, NULL);
	
}
void CSceneManager::ChangeScene() {
	if (m_sceneResult == CONTINUE) return;
	if (m_sceneResult == FINISH) return;
	if (m_scene != nullptr)	delete m_scene;
	switch (m_sceneResult)
	{
	case TITLE:
		m_scene = new CTitleScene;
		break;
	case GAME:
		m_scene = new CGameScene;
		break;
	case RESULT:
		m_scene = new CResultScene;
		break;
	default:
		break;
	}
}