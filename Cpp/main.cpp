#include "../Header/CApplicationBase.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCommandLine, int cmdShow) {
	CApplicationBase pApp(hInstance, cmdShow);	// ���̂��`�����pApp�ɂ��ꎩ�g�̃|�C���^���i�[
	return pApp.Run(hInstance);					// �A�v���P�[�V�����J�n
}