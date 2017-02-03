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
	// �G�����
	void (CGameScene::*CreateEnemy)();
	// �ǂ̓G����邩
	void NotCreate();
	void Easy();
	void Normal();
	void Hard();

private:
	void CollisionCheck();
private:
	// �Q�[���V�[�����ɕK�v�Ȃ���
	CPlayer* m_player;
	std::vector<CEnemy*> m_enemyList;
	//CBlock* m_block;
};
