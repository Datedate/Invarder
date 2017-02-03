#pragma once

#include "CD3D9.h"

class CSceneCommonData
{
public:
	CSceneCommonData() {};
	CSceneCommonData(const LPDIRECT3DDEVICE9& _dev);
	~CSceneCommonData();
public:
	//CStage stage;
	static LPDIRECT3DDEVICE9 m_pd3dDevice;
};

