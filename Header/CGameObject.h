#pragma once

class CGameObject
{
public:
	CGameObject() {};
	virtual ~CGameObject() {};
	virtual bool Init() { return true; };				// 初期化関数
	virtual void Release() {};							// 解放関数
	virtual void Update() {};							// 更新関数
	virtual void Draw() {};								// 描画関数
};
