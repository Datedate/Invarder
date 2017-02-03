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
	float tu, tv;				// ���݂̃A�j���[�V�������_
	float texSizeX, texSizeY;	// �e�N�X�`���̃A�j���[�V�����̃T�C�Y
private:
	int now;					// ���݂̃A�j���[�V�����ԍ�
	int cnt;					// ���݂̃A�j���[�V�����v�f��
	int texNumX, texNumY;		// �e�N�X�`���̃A�j���[�V�����̐�
	int texNumMax;				// �A�j���[�V�����ԍ��̍ő�
};


#endif