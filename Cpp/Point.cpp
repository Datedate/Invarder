#include "../Header/Point.h"

// ’è”‚ÌÀ‘Ì
const Point Point::ZERO(0, 0);
const Point Point::LEFT(-1, 0);
const Point Point::RIGHT(1, 0);
const Point Point::DOWN(0, -1);
const Point Point::UP(0, 1);

// ƒƒ“ƒoŠÖ”
bool Point::IsZero() {
	return *this == Point::ZERO;
}