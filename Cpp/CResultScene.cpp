#include "../Header/CResultScene.h"

CResultScene::CResultScene(CSceneCommonData& _data)
{
	m_data = &_data;
	// リザルトシーン内の初期化処理
	m_state = CONTINUE;
	// それぞれのポインタをnew
}

CResultScene::~CResultScene()
{
	// リザルトシーン内の終了処理
	// それぞれのポインタをdelete
}

SCENE_RESULT CResultScene::Update() {
	// リザルトシーン内の更新関数
	// それぞれのポインタのUpdateを呼ぶ
	// 次のシーンを渡す
	return m_state;
}
void CResultScene::Render() {
	// リザルトシーン内の描画関数
	// それぞれのポインタのDrawを呼ぶ
}
