#pragma once
#include "Vector2.h"

// ��`�N���X

class Rect
{
public:
	// �R���X�g���N�^
	Rect(float left=0,float up=0,float right=0,float down=0)
		:m_min(left,up),m_max(right,down){}
	Rect(const Vector2& min,const Vector2& max)
		:m_min(min),m_max(max){}

	// �_����`�̓����ɓ����Ă��邩�H
	bool Contains(Vector2& position);
		
	// ��`���d�Ȃ��Ă��邩�H
	bool Intersects(Rect& other);

	// ��`���G��Ă��邩�H
	bool Touch(Rect& other);

	// ���s�ړ�
	Rect Translate(Vector2& position);

	// �T�C�Y�g��
	Rect Expand(Vector2& size);

	// �����擾
	float Width();

	// �������擾
	float Height();

	// ����̍��W���擾
	Vector2& Min();

	// �E���̍��W���擾
	Vector2& Max();

private:
	Vector2 m_min;		// ��`�̍�����W	
	Vector2 m_max;		// ��`�̉E�����W
};
