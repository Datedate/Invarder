#pragma once

#include "CBullet.h"

#define BULLET_NUM (30)

class CBulletMySelf :public CBullet
{
public:
	CBulletMySelf() {};
	CBulletMySelf(Rect _rect, CAnimation _anm, string _texName);
	~CBulletMySelf() {};
	void Update();
	void Move();
	bool IsCollision(CGameObject2D* _other);
	void Animation();
private:
	const int IdleANM[BULLET_NUM] = { 0,0,0,0,0,0,1,1,1,1,1,1,2,2,2,2,2,3,3,3,4,4,4,5,5,5,6,6,7,7, };
};
