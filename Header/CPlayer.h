#pragma once
#include "CGameObject2D.h"
#include "CBullet.h"
#include "CDirectInput.h"
//#include "Ability.h"
#include "CTitleImage.h"
#include <vector>

#define IDLE_ANM (35)
#define ATTACK_ANM (25)

class CPlayer:public CGameObject2D
{
public:
	enum State {
		IDLE,
		ATTACK,
		DAMAGE
	};
public:
	CPlayer() {};
	CPlayer(Rect _rect, CAnimation _anm,string _texName);
	~CPlayer() {};
	void Release();
	void Update();
	void Draw();
private:
	void Move();
	void RightMove();
	void LeftMove();

	void Attack();
	void BulletUpdate();
	void Animation();
public:
	std::vector<CBullet*> m_bullet;
private:
	const int IdleANM[IDLE_ANM] = { 0,0,0,0,0,1,1,1,1,2,2,2,2,3,3,3,3,3,3,3,3,3,2,2,2,2,1,1,1,1,0,0,0,0,0 };
	const int AttackANM[ATTACK_ANM] = { 6,6,6,6,7,7,7,8,8,8,8,8,9,9,9,9,9,9,8,8,8,8,7,7,7 };
	State m_state;
private:
	//Ability::HitPoint m_hp;
private:
	CPlayer::State operator=(CPlayer::State _state) {
		m_anm.CntClear();
		return _state;
	}
};

