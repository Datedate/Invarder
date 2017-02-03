#pragma once

#include "CGameObject2D.h"
#include "Ability.h"

enum ENEMY_KIND {
	EASY,
	NORMAL,
	HARD,
	MAX,
};

class CEnemy:public CGameObject2D
{
public:
	CEnemy() {};
	~CEnemy() {};
	virtual void Move() {};
	virtual void Attack() {};
private:
	Ability::HitPoint m_hp;
};
