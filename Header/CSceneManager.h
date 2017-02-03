#pragma once

#include "ISceneBase.h"
#include "CSceneCommonData.h"

#include "CTitleScene.h"
#include "CGameScene.h"
#include "CResultScene.h"

#define MY_FVF (D3DFVF_XYZRHW|D3DFVF_DIFFUSE|D3DFVF_TEX1)

class CSceneManager
{
public:
	CSceneManager();
	~CSceneManager();
	void Init(const LPDIRECT3DDEVICE9& _dev);
	SCENE_RESULT Update();
	void UnInit();
private:	
	void Process();
	void Render();
	void ChangeScene();
private:
	ISceneBase* m_scene;
	SCENE_RESULT m_sceneResult;
};

