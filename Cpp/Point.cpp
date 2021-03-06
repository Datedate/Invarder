#include "../Header/Point.h"

// 定数の実体
const Point Point::ZERO(0, 0);
const Point Point::LEFT(-1, 0);
const Point Point::RIGHT(1, 0);
const Point Point::DOWN(0, -1);
const Point Point::UP(0, 1);

// メンバ関数
bool Point::IsZero() {
	return *this == Point::ZERO;
}