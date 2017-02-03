#pragma once

#include <cmath>

// 2D�x�N�g���N���X
class Vector2
{
public:
	// �R���X�g���N�^
	Vector2(float _x = 0, float _y = 0) :x(_x), y(_y){}
	// ���ς����߂�
	float Dot(Vector2& other);
	// �O�ς����߂�
	float Cross(Vector2& other);
	// ���������߂�
	float Length();
	// ���������߂�
	float Distance(Vector2& other);
	// ���K������
	Vector2 Normalize();
	// �[���x�N�g�����ǂ���
	bool IsZero();

public:
//----���Z�q�I�[�o�[���[�h----
	Vector2& operator+=(Vector2& other) {
		return *this = *this + other;
	}
	Vector2& operator-=(Vector2& other) {
		return *this = *this - other;
	}
	Vector2& operator*=(float scaler) {
		return *this = *this * scaler;
	}
	Vector2& operator/=(float scaler) {
		return *this = *this / scaler;
	}
	Vector2 operator+(Vector2& other){
		return Vector2(x + other.x, y + other.y);
	}
	Vector2 operator-(Vector2& other){
		return Vector2(x - other.x, y - other.y);
	}
	Vector2 operator*(float scaler){
		return Vector2(x * scaler, y * scaler);
	}
	Vector2 operator/(float scaler){
		return Vector2(x / scaler, y / scaler);
	}
	Vector2 operator-(){
		return Vector2(-x, -y);
	}
	bool operator==(const Vector2& other){
		return (x == other.x) && (y == other.y);
	}
	bool operator!=(const Vector2& other){
		return (*this != other);
	}
	bool operator<(const Vector2& other){
		if (x < other.x)return true;
		if (y < other.y)return true;
		return false;
	}

public:
	// �萔
	static const Vector2 ZERO;	// �[���x�N�g��
	static const Vector2 LEFT;	// ��
	static const Vector2 RIGHT;	// �E
	static const Vector2 DOWN;	// ��
	static const Vector2 UP;	// ��
public:
	float x, y;
};
