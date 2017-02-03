#pragma once

#include <cmath>

// 2Dベクトルクラス
class Vector2
{
public:
	// コンストラクタ
	Vector2(float _x = 0, float _y = 0) :x(_x), y(_y){}
	// 内積を求める
	float Dot(Vector2& other);
	// 外積を求める
	float Cross(Vector2& other);
	// 長さを求める
	float Length();
	// 距離を求める
	float Distance(Vector2& other);
	// 正規化する
	Vector2 Normalize();
	// ゼロベクトルかどうか
	bool IsZero();

public:
//----演算子オーバーロード----
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
	// 定数
	static const Vector2 ZERO;	// ゼロベクトル
	static const Vector2 LEFT;	// 左
	static const Vector2 RIGHT;	// 右
	static const Vector2 DOWN;	// 下
	static const Vector2 UP;	// 上
public:
	float x, y;
};
