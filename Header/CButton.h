#pragma once
#include "CGameObject2D.h"
#include "ISceneBase.h"
#include "CDirectInput.h"

class CButton:public CGameObject2D
{
public:
	CButton() {};
	CButton(Rect _rect, CAnimation _anm,string _texName);
	~CButton() {};
	void Release() {};
	void Update(SCENE_RESULT& _state);
private:
	void OnKey(SCENE_RESULT& _state);
};
