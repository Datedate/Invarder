#include "../Header/CEnemyEasy.h"

float CEnemyEasy::PlacementX(float _size, int _num) {
	return ((100 + (_num%ENEMY_X * 80)) + _size);
}
float CEnemyEasy::PlacementY(float _size, int _num) {
	return ((_num/(ENEMY_X))*56+16+_size);
}

CEnemyEasy::CEnemyEasy(Rect _rect, CAnimation _anm, string _texName) {
	m_rect = _rect;
	m_anm = _anm;
	m_tex = CTexture(_texName);
}
void CEnemyEasy::Move() {

}
void CEnemyEasy::Attack() {

}