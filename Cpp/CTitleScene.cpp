#include "../Header/CTitleScene.h"

CTitleScene::CTitleScene()
{
	// タイトルシーンで必要なもの初期化
	m_state = CONTINUE;
	// それぞれ new する 
	m_titleImage = new CTitleImage(Rect(0,0,640,480),CAnimation(1,1),"Resource/Title.png");
	m_button = new CButton(Rect(180,300,480,380),CAnimation(1,1),"Resource/GUITitleButton.png");
}

CTitleScene::~CTitleScene()
{
	// タイトルシーンで必要なもの終了処理
	// それぞれ delete する 
	delete m_button;
	delete m_titleImage;
}

SCENE_RESULT CTitleScene::Update() {
	// タイトルシーン内の更新処理
	// それぞれの Update を呼ぶ
	m_titleImage->Update();
	m_button->Update(m_state);
	// 次のシーンを渡す
	return m_state;
}

void CTitleScene::Render() {
	// タイトルシーン内の描画処理
	// それぞれの Draw を呼ぶ
	m_titleImage->SetTexture();
	m_titleImage->Draw();
	m_button->SetTexture();
	m_button->Draw();
}