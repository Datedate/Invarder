#include "../Header/Vector2.h"

// ’è”‚ÌÀ‘Ì
const Vector2 Vector2::ZERO(0.0f, 0.0f);
const Vector2 Vector2::LEFT(-1.0f, 0.0f);
const Vector2 Vector2::RIGHT(1.0f, 0.0f);
const Vector2 Vector2::DOWN(0.0f, -1.0f);
const Vector2 Vector2::UP(0.0f, 1.0f);

// ƒƒ“ƒoŠÖ”
float Vector2::Dot(Vector2& other){
	return (x*other.x) + (y*other.y);
}

float Vector2::Cross(Vector2& other){
	return (x*other.y) - (y*other.x);
}

float Vector2::Length(){
	return std::sqrt(Dot(*this));
}

float Vector2::Distance(Vector2& other){
	return (*this - other).Length();
}

Vector2 Vector2::Normalize(){
	const float len = Length();
	return *this / len;
}

bool Vector2::IsZero() {
	return *this == Vector2::ZERO;
}