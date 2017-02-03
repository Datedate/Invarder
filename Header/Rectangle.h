#pragma once
#include "Vector2.h"

// 矩形クラス

class Rect
{
public:
	// コンストラクタ
	Rect(float left=0,float up=0,float right=0,float down=0)
		:m_min(left,up),m_max(right,down){}
	Rect(const Vector2& min,const Vector2& max)
		:m_min(min),m_max(max){}

	// 点が矩形の内側に入っているか？
	bool Contains(Vector2& position);
		
	// 矩形が重なっているか？
	bool Intersects(Rect& other);

	// 矩形が触れているか？
	bool Touch(Rect& other);

	// 平行移動
	Rect Translate(Vector2& position);

	// サイズ拡張
	Rect Expand(Vector2& size);

	// 幅を取得
	float Width();

	// 高さを取得
	float Height();

	// 左上の座標を取得
	Vector2& Min();

	// 右下の座標を取得
	Vector2& Max();

private:
	Vector2 m_min;		// 矩形の左上座標	
	Vector2 m_max;		// 矩形の右下座標
};
