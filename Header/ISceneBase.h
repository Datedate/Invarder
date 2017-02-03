#pragma once
enum SCENE_RESULT
{
	FINISH = 0,
	CONTINUE,
	TITLE,
	GAME,
	RESULT
};

class ISceneBase
{
	
public:
	virtual SCENE_RESULT Update() = 0;
	virtual void Render() = 0;
protected:
	SCENE_RESULT m_state;
};
