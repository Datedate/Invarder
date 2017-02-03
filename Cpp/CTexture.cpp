#include "../Header/CTexture.h"

CTexture::CTexture(string _texName) {
	m_texName = _texName;
	ReadTexture();
}

void CTexture::ReadTexture() {
	// テクスチャの読み込み
	if (!SUCCEEDED(D3DXCreateTextureFromFile(CSceneCommonData::m_pd3dDevice, (char*)m_texName.c_str(), &m_pDirectTexture))) {
		exit(1);
	}
}