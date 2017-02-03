#include "../Header/Rectangle.h"

// ƒƒ“ƒoŠÖ”
bool Rect::Contains(Vector2& position){
	return (m_min.x <= position.x&&position.x <= m_max.x)
		&& (m_min.y <= position.y&&position.y <= m_max.y);
}

bool Rect::Intersects(Rect& other){
	if (m_min.x > m_max.x)return false;
	if (m_max.x < m_min.x)return false;
	if (m_min.y > m_max.y)return false;
	if (m_max.y < m_min.y)return false;
	return true;
}

bool Rect::Touch(Rect& _other) {
	if (Contains(_other.Min())) return true;
	if (Contains(_other.Max()))return true;
	return false;
}

Rect Rect::Translate(Vector2& position){
	return Rect(m_min + position, m_max + position);
}

Rect Rect::Expand(Vector2& size){
	return Rect(m_min - size, m_max + size);
}

float Rect::Width(){
	return m_max.x - m_min.x;
}

float Rect::Height(){
	return m_max.y - m_min.y;
}

Vector2& Rect::Min(){
	return m_min;
}

Vector2& Rect::Max(){
	return m_max;
}