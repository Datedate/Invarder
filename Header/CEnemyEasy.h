#pragma once
#include "CEnemy.h"


class CEnemyEasy:public CEnemy
{
public:
	static const int ENEMY_X = 6;
	static const int ENEMY_Y = 4;
	static const int ENEMY_NUM = ENEMY_X * ENEMY_Y;
	static float PlacementX(float _size, int _num);
	static float PlacementY(float _size, int _num);
public:
	CEnemyEasy() {};
	CEnemyEasy(Rect _rec, CAnimation _anm, string _texName);
	~CEnemyEasy() {};
	void Move();
	void Attack();
private:

};

