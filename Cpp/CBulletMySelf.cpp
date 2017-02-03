#include "../Header/CBulletMySelf.h"

CBulletMySelf::CBulletMySelf(Rect _rect, CAnimation _anm, string _texName) {
	m_rect = _rect;
	m_anm = _anm;
	m_tex = CTexture(_texName);
}


void CBulletMySelf::Update() {
	Move();
	Animation();
	OutOfRange();
}
void CBulletMySelf::Move() {
	m_rect = m_rect.Translate(Vector2(0.0f, -5.0f));
}
void CBulletMySelf::Animation() {
	m_anm.SetAnmNow(IdleANM[m_anm.AddCnt(BULLET_NUM)]);
	m_anm.Update();
}
// ---------�Փˊ֐�--------
bool CBulletMySelf::IsCollision(CGameObject2D* _other) {
	// ������������
	if (!m_rect.Touch(_other->GetRect())) return false;
	return true;
	// ���������Ƃ��ɒʒm���V�[���ɓ�����
}
