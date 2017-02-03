#include "../Header/CApplicationBase.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCommandLine, int cmdShow) {
	CApplicationBase pApp(hInstance, cmdShow);	// 実体を定義するとpAppにこれ自身のポインタが格納
	return pApp.Run(hInstance);					// アプリケーション開始
}