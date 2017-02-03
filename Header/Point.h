#pragma once

// �����^2D�x�N�g���N���X

class Point
{
public:
	// �R���X�g���N�^
	Point(int _x=0,int _y=0):x(_x),y(_y){}
	// �[���x�N�g�����ǂ���
	bool IsZero();

public:
//----���Z�q�I�[�o�[���[�h----
	Point& operator+=(const Point& other) {
		return *this = *this + other;
	}
	Point& operator-=(const Point& other) {
		return *this = *this - other;
	}
	const Point operator+(const Point& other)const {
		return Point(x + other.x, y + other.y);
	}
	const Point operator-(const Point& other)const {
		return Point(x - other.x, y - other.y);
	}
	const Point operator-()const {
		return Point(-x, -y);
	}
	bool operator==(const Point& other)const {
		return (x == other.x) && (y == other.y);
	}
	bool operator!=(const Point& other)const {
		return (*this != other);
	}
	bool operator<(const Point& other)const {
		if (x < other.x)return true;
		if (y < other.y)return true;
		return false;
	}
public:
	// �萔
	static const Point ZERO;
	static const Point LEFT;
	static const Point RIGHT;
	static const Point DOWN;
	static const Point UP;
public:
	int x, y;
};
