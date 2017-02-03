#pragma once
#include "ISceneBase.h"
#include "CSceneCommonData.h"
#include "CTitleImage.h"
#include "CButton.h"

class CTitleScene:public ISceneBase
{
public:
	CTitleScene();
	~CTitleScene();
	SCENE_RESULT Update();
	void Render();
private:
	
	// �^�C�g���V�[���ŕK�v�Ȃ���
	CTitleImage* m_titleImage;
	CButton*     m_button;
};
