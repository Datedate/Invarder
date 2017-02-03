#ifndef _ANIMATION_H_
#define _ANIMATION_H_

class CAnimation
{
public:
	CAnimation();
	CAnimation(int _texNumX, int _texNum_y);
	~CAnimation();
public:
	void Update();
	int AddCnt(int _limit);
	void SetAnmNow(int _anmNum);
	void CntClear();
	int GetCnt();
public:
	float tu, tv;				// 現在のアニメーション頂点
	float texSizeX, texSizeY;	// テクスチャのアニメーションのサイズ
private:
	int now;					// 現在のアニメーション番号
	int cnt;					// 現在のアニメーション要素数
	int texNumX, texNumY;		// テクスチャのアニメーションの数
	int texNumMax;				// アニメーション番号の最大
};


#endif