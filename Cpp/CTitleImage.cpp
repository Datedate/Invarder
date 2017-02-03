#include "../Header/CTitleImage.h"

CTitleImage::CTitleImage(Rect _rect, CAnimation _anm,string _texName)
{
	m_rect = _rect;
	m_anm = _anm;
	m_tex = CTexture(_texName);
}

