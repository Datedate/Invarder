#ifndef _TEXTURE_H_
#define _TEXTURE_H_

//-----------インクルードファイル-------

#include <d3dx9.h>
#include <string>
#include "CSceneCommonData.h"
using namespace std;

class CTexture
{
public:
	CTexture() {};
	CTexture(string _texName);
	void ReadTexture();
	LPDIRECT3DTEXTURE9 m_pDirectTexture;
	string m_texName;
};

#endif