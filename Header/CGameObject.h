#pragma once

class CGameObject
{
public:
	CGameObject() {};
	virtual ~CGameObject() {};
	virtual bool Init() { return true; };				// �������֐�
	virtual void Release() {};							// ����֐�
	virtual void Update() {};							// �X�V�֐�
	virtual void Draw() {};								// �`��֐�
};
