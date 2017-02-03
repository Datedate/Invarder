#include "../Header/CTitleScene.h"

CTitleScene::CTitleScene()
{
	// �^�C�g���V�[���ŕK�v�Ȃ��̏�����
	m_state = CONTINUE;
	// ���ꂼ�� new ���� 
	m_titleImage = new CTitleImage(Rect(0,0,640,480),CAnimation(1,1),"Resource/Title.png");
	m_button = new CButton(Rect(180,300,480,380),CAnimation(1,1),"Resource/GUITitleButton.png");
}

CTitleScene::~CTitleScene()
{
	// �^�C�g���V�[���ŕK�v�Ȃ��̏I������
	// ���ꂼ�� delete ���� 
	delete m_button;
	delete m_titleImage;
}

SCENE_RESULT CTitleScene::Update() {
	// �^�C�g���V�[�����̍X�V����
	// ���ꂼ��� Update ���Ă�
	m_titleImage->Update();
	m_button->Update(m_state);
	// ���̃V�[����n��
	return m_state;
}

void CTitleScene::Render() {
	// �^�C�g���V�[�����̕`�揈��
	// ���ꂼ��� Draw ���Ă�
	m_titleImage->SetTexture();
	m_titleImage->Draw();
	m_button->SetTexture();
	m_button->Draw();
}