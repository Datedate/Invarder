#include "../Header/CSceneCommonData.h"

LPDIRECT3DDEVICE9 CSceneCommonData::m_pd3dDevice = NULL;

CSceneCommonData::CSceneCommonData(const LPDIRECT3DDEVICE9& _dev)
{
	m_pd3dDevice = _dev;
}

CSceneCommonData::~CSceneCommonData()
{

}