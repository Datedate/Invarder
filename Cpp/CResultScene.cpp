#include "../Header/CResultScene.h"

CResultScene::CResultScene(CSceneCommonData& _data)
{
	m_data = &_data;
	// ���U���g�V�[�����̏���������
	m_state = CONTINUE;
	// ���ꂼ��̃|�C���^��new
}

CResultScene::~CResultScene()
{
	// ���U���g�V�[�����̏I������
	// ���ꂼ��̃|�C���^��delete
}

SCENE_RESULT CResultScene::Update() {
	// ���U���g�V�[�����̍X�V�֐�
	// ���ꂼ��̃|�C���^��Update���Ă�
	// ���̃V�[����n��
	return m_state;
}
void CResultScene::Render() {
	// ���U���g�V�[�����̕`��֐�
	// ���ꂼ��̃|�C���^��Draw���Ă�
}
