#pragma once

class CGameObject
{
public:
	CGameObject() {};
	virtual ~CGameObject() {};
	virtual bool Init() { return true; };				// ‰Šú‰»ŠÖ”
	virtual void Release() {};							// ‰ğ•úŠÖ”
	virtual void Update() {};							// XVŠÖ”
	virtual void Draw() {};								// •`‰æŠÖ”
};
