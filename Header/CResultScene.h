#pragma once
#include "ISceneBase.h"
#include "CSceneCommonData.h"

class CResultScene:public ISceneBase
{
public:
	CResultScene() {};
	CResultScene(CSceneCommonData& _data);
	~CResultScene();
	SCENE_RESULT Update();
	void Render();
private:
	CSceneCommonData* m_data;
	// リザルトシーン中に必要なもの
	//CBackGround* m_back;
	//CGUIButton* m_button;
	//CResultImage* m_resultImage;
};

