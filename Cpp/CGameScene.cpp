#include "../Header/CGameScene.h"
#include "../Header/CEnemyEasy.h"

template<class T>
void RemoveIndex(std::vector<T>& _vector, unsigned int _index) {
	_vector.erase(_vector.begin() + _index);
}

CGameScene::CGameScene()
{
	// ゲームシーン内の初期化
	m_state = CONTINUE;
	SetEnemy(&CGameScene::Easy);
	// それぞれのポインタをnew
	m_player = new CPlayer(Rect(300,440,340,480),CAnimation(6,3),"Resource/Player.png");
	(this->*CreateEnemy)();
	//m_block = new CBlock(Rect(0, 0, 0, 0), CAnimation(1, 1));
}

CGameScene::~CGameScene()
{
	// ゲームシーン内の終了処理
	// それぞれのポインタをdelete
}

//-----------------------------------------------

SCENE_RESULT CGameScene::Update() {
	// ゲームシーン内の更新関数
	// それぞれのポインタのUpadateを呼ぶ
	(this->*CreateEnemy)();						// 敵生成
	m_player->Update();
	for (size_t i = 0; i < m_enemyList.size(); i++)
		m_enemyList[i]->Update();

	CollisionCheck();
	// 次のシーンを渡す
	return m_state;
}

void CGameScene::CollisionCheck() {
	for (unsigned int i = 0;i < m_player->m_bullet.size();) {
		for (unsigned int j = 0;j < m_enemyList.size();) {
			if (m_player->m_bullet[i]->IsCollision(m_enemyList[j])) { 
				RemoveIndex(m_player->m_bullet, i);
				RemoveIndex(m_enemyList, j);
				if (m_player->m_bullet.size() == 0) return;
				if (m_enemyList.size() == 0) return;
				continue; 
			}
			++j;
		}
		++i;
	}

}
//-------------------------------------------------
void CGameScene::Render() {
	// ゲームシーン内の描画関数
	// それぞれのポインタのDrawを呼ぶ
	m_player->SetTexture();
	m_player->Draw();
	
	m_enemyList[0]->SetTexture();
	for (size_t i = 0; i < m_enemyList.size(); i++)
		m_enemyList[i]->Draw();
}


void CGameScene::SetEnemy(void(CGameScene::*_CreateEnemy)()) {
	CreateEnemy = _CreateEnemy;
}

//-----------------------------------------------------------
void CGameScene::NotCreate() { return; }
void CGameScene::Easy() {
	// 第一段階の敵生成
	for (int i = 0; i < CEnemyEasy::ENEMY_NUM; i++)
	{
		m_enemyList.push_back(new CEnemyEasy(Rect(CEnemyEasy::PlacementX(0,i), CEnemyEasy::PlacementY(0,i), CEnemyEasy::PlacementX(40,i), CEnemyEasy::PlacementY(40,i)), CAnimation(4, 3), "Resource/EnemyEasy.png"));
	}
	SetEnemy(&CGameScene::NotCreate);
}
void CGameScene::Normal() {
	// 第二段階の敵生成
}
void CGameScene::Hard() {
	// 第三段階の敵生成
}


