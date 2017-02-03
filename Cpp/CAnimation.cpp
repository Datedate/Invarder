#include "../Header/CAnimation.h"
CAnimation::CAnimation()
{
}
CAnimation::CAnimation(int _texNumX, int _texNumY) {
	cnt = now = 0;
	texNumX = _texNumX;
	texNumY = _texNumY;
	texNumMax = texNumX*texNumY;
	texSizeX = (float)1.0f / texNumX;
	texSizeY = (float)1.0f / texNumY;
	tu = (float)((now % texNumX)*texSizeX);
	tv = (float)((now / texNumX)*texSizeY);
	
}
CAnimation::~CAnimation()
{
}

void CAnimation::Update() {
	tu = (float)((now % texNumX)*texSizeX);
	tv = (float)((now / texNumX)*texSizeY);
}
int CAnimation::AddCnt(int _limit) {
	return cnt < _limit ? cnt++ : cnt = 0;
}
void CAnimation::SetAnmNow(int _anmNum) {
	now = _anmNum;
}
void CAnimation::CntClear() {
	cnt = 0;
}
int CAnimation::GetCnt() {
	return cnt;
}