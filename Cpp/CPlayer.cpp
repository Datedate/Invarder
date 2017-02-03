#include "../Header/CPlayer.h"
#include "../Header/CBulletMySelf.h"

CPlayer::CPlayer(Rect _rect, CAnimation _anm ,string _texName) {
	m_rect = _rect;
	m_anm = _anm;
	m_tex = CTexture(_texName);
	m_state = IDLE;
}

//============================== —˜—pŽÒ‘¤‚Ìƒƒ“ƒoŠÖ” ==============================
void CPlayer::Release() {
	// ’e‚ÌŠJ•ú
}
void CPlayer::Update() {
	Move();
	Attack();
	BulletUpdate();
	Animation();
}
// ============================== §Œä‘¤‚Ìƒƒ“ƒoŠÖ” ===============================
// ---------ˆÚ“®ŠÖ”--------
void CPlayer::Move() {
	if (CDirectInput::GetInstance()->KeyPress(DIK_RIGHT))
		RightMove();
	if (CDirectInput::GetInstance()->KeyPress(DIK_LEFT))
		LeftMove();
}
void CPlayer::RightMove() {
	m_rect = m_rect.Translate(Vector2(2.0f, 0.0f));
	if (m_rect.Max().x > 640) {
		m_rect.Min().x = 600;
		m_rect.Max().x = 640;
	}
}
void CPlayer::LeftMove() {
	m_rect = m_rect.Translate(Vector2(-2.0f, 0.0f));
	if (m_rect.Min().x < 0) {
		m_rect.Min().x = 0;
		m_rect.Max().x = 40;
	}
}
// ---------UŒ‚ŠÖ”--------
void CPlayer::Attack() {
	if (CDirectInput::GetInstance()->KeyTrigger(DIK_X)) {
		m_bullet.push_back(new CBulletMySelf(Rect(m_rect.Min(),m_rect.Max()),CAnimation(8,2),"Resource/Bullet_01.png"));
		m_state = ATTACK;
	}
}

void CPlayer::BulletUpdate() {
	if (m_bullet.size() == 0)return;
	for (unsigned i = 0;i < m_bullet.size();++i)
		m_bullet[i]->Update();
}

void CPlayer::Animation() {
	if (m_state == ATTACK&&m_anm.GetCnt()>=ATTACK_ANM)
		m_state = IDLE;
	switch (m_state)
	{
	case IDLE:
		m_anm.SetAnmNow(IdleANM[m_anm.AddCnt(IDLE_ANM)]);
		break;
	case ATTACK:
		m_anm.SetAnmNow(AttackANM[m_anm.AddCnt(ATTACK_ANM)]);
		break;
	default:
		break;
	}
	m_anm.Update();
}

void CPlayer::Draw() {
	VERTEX2D vx[VERTEX_NUM] = {
		{ m_rect.Min().x,m_rect.Min().y,0,1,DIFFUESE(255),m_anm.tu,m_anm.tv },
		{ m_rect.Max().x,m_rect.Min().y,0,1,DIFFUESE(255),m_anm.tu + m_anm.texSizeX,m_anm.tv },
		{ m_rect.Max().x,m_rect.Max().y,0,1,DIFFUESE(255),m_anm.tu + m_anm.texSizeX,m_anm.tv + m_anm.texSizeY },
		{ m_rect.Min().x,m_rect.Max().y,0,1,DIFFUESE(255),m_anm.tu,m_anm.tv + m_anm.texSizeY }
	};
	CSceneCommonData::m_pd3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, vx, sizeof(VERTEX2D));

	if (m_bullet.size() == 0) return;				// ’e‚ª‚È‚¯‚ê‚Î‹A‚é

	m_bullet[0]->SetTexture();

	for (unsigned int i = 0;i < m_bullet.size();++i) {
		m_bullet[i]->Draw();
	}
}