#include "../Header/CGameObject2D.h"

CGameObject2D::CGameObject2D(Rect _rect, CAnimation _anm, string _texName) {
	m_rect = _rect;
	m_anm = _anm;
	m_tex = CTexture(_texName);
}
void CGameObject2D::SetTexture() {
	CSceneCommonData::m_pd3dDevice->SetTexture(0, m_tex.m_pDirectTexture);
}
void CGameObject2D::Draw() {
	
	VERTEX2D vx[VERTEX_NUM] = {
		{ m_rect.Min().x,m_rect.Min().y,0,1,DIFFUESE(255),m_anm.tu,m_anm.tv },
		{ m_rect.Max().x,m_rect.Min().y,0,1,DIFFUESE(255),m_anm.tu + m_anm.texSizeX,m_anm.tv },
		{ m_rect.Max().x,m_rect.Max().y,0,1,DIFFUESE(255),m_anm.tu + m_anm.texSizeX,m_anm.tv + m_anm.texSizeY },
		{ m_rect.Min().x,m_rect.Max().y,0,1,DIFFUESE(255),m_anm.tu,m_anm.tv + m_anm.texSizeY }
	};
	CSceneCommonData::m_pd3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, vx, sizeof(VERTEX2D));
}
Rect& CGameObject2D::GetRect() {
	return m_rect;
}