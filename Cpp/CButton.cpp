#include "../Header/CButton.h"

CButton::CButton(Rect _rect, CAnimation _anm,string _texName)
{
	m_rect = _rect;
	m_anm = _anm;
	m_tex = CTexture(_texName);
}

void CButton::Update(SCENE_RESULT& _state) {
	OnKey(_state);
}
void CButton::OnKey(SCENE_RESULT& _state) {
	if (CDirectInput::GetInstance()->KeyTrigger(DIK_RETURN))
		_state = SCENE_RESULT::GAME;
}
