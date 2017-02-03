#pragma once

#include "CSceneCommonData.h"
#include "CGameObject.h"
#include "Rectangle.h"
#include "Vertex2D.h"
#include "CAnimation.h"
#include "CTexture.h"

#define VERTEX_NUM (4)

class CGameObject2D:public CGameObject
{
public:
	CGameObject2D() {};
	CGameObject2D(Rect _rect, CAnimation _anm, string _texName);
	~CGameObject2D() {};
	virtual bool Init() { return true; };
	virtual void Release() {};
	virtual void Update() {};
	virtual void Draw();
	virtual void SetTexture();
	virtual Rect& GetRect();
protected:
	Rect m_rect;
	CAnimation m_anm;
	CTexture m_tex;
};
