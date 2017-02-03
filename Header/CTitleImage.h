#pragma once
#include "CGameObject2D.h"

class CTitleImage:public CGameObject2D
{
public:
	CTitleImage() {};
	CTitleImage(Rect _rect, CAnimation _anm,string _texName);
	~CTitleImage() {};
	void Release() {};
	void Update() {};
};

