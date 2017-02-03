#pragma once
#include "CGameObject2D.h"

class CBullet:public CGameObject2D
{
public:
	CBullet() {};
	~CBullet() {};
	virtual void Update() {};
	virtual void Move() {};
	virtual bool IsCollision(CGameObject2D* _other) { return false; };
	virtual void Animation() {};
	void OutOfRange() {
		if (m_rect.Min().x > 0) return;
		if (m_rect.Min().y > 0) return;
		if (m_rect.Max().x < 640) return;
		if (m_rect.Max().y < 480) return;
		delete this;
	}
};
