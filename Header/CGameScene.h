#pragma once
#include "ISceneBase.h"
#include "CSceneCommonData.h"
#include <vector>
#include "CPlayer.h"
#include "CEnemy.h"


class CGameScene:public ISceneBase{
public:
	enum MODE {
		EASY_MODE,
		NORMAL_MODE,
		HARD_MODE,
	};
public:
	CGameScene();
	~CGameScene();
	SCENE_RESULT Update();
	void Render();
	void SetEnemy(void(CGameScene::*_CreateEnemy)());
private:
	// 敵を作る
	void (CGameScene::*CreateEnemy)();
	// どの敵を作るか
	void NotCreate();
	void Easy();
	void Normal();
	void Hard();

private:
	void CollisionCheck();
private:
	// ゲームシーン中に必要なもの
	CPlayer* m_player;
	std::vector<CEnemy*> m_enemyList;
	//CBlock* m_block;
};
