#include "../Header/CDirectInput.h"

HRESULT CDirectInput::Init(HINSTANCE _hInstance,HWND _hWnd) {
	HRESULT hr;

	if (!m_pDirectInput)
	{
		// DirectInputオブジェクトの作成
		hr = DirectInput8Create(_hInstance, DIRECTINPUT_VERSION,
			IID_IDirectInput8, (void**)&m_pDirectInput, NULL);
	}

	// キーボードの初期化
	InitKey(_hInstance, _hWnd);

	m_hWnd = _hWnd;

	return hr;

}

HRESULT CDirectInput::InitKey(HINSTANCE _hInstance, HWND _hWnd) {
	
	HRESULT hr;

	// デバイスオブジェクトを作成
	hr = m_pDirectInput->CreateDevice(GUID_SysKeyboard, &m_pKeyDevice, NULL);
	if (FAILED(hr) || m_pKeyDevice == NULL)
	{
		MessageBox(_hWnd, "キーボードがねぇ！", "警告！", MB_ICONWARNING);
		return hr;
	}

	// データフォーマットを設定
	hr = m_pKeyDevice->SetDataFormat(&c_dfDIKeyboard);
	if (FAILED(hr))
	{
		MessageBox(_hWnd, "キーボードのデータフォーマットを設定できませんでした。", "警告！", MB_ICONWARNING);
		return hr;
	}

	// 協調モードを設定（フォアグラウンド＆非排他モード）
	hr = m_pKeyDevice->SetCooperativeLevel(_hWnd, (DISCL_FOREGROUND | DISCL_NONEXCLUSIVE));
	if (FAILED(hr))
	{
		MessageBox(_hWnd, "キーボードの協調モードを設定できませんでした。", "警告！", MB_ICONWARNING);
		return hr;
	}

	// キーボードへのアクセス権を獲得(入力制御開始)
	m_pKeyDevice->Acquire();

	return S_OK;
}

void CDirectInput::Update() {
	BYTE keyStateOld[256];

	// 前回のデータを保存
	memcpy(keyStateOld, m_keyState, INPUT_BUFFER_SIZE);

	// デバイスからデータを取得
	m_pKeyDevice->GetDeviceState(sizeof(m_keyState), m_keyState);
	for (int cnt = 0; cnt < INPUT_BUFFER_SIZE; cnt++)
	{
		// トリガーとリリースを取得
		m_keyStateTrigger[cnt] = (m_keyState[cnt] ^ keyStateOld[cnt]) & m_keyState[cnt];
		m_keyStateRelease[cnt] = (m_keyState[cnt] ^ keyStateOld[cnt]) & keyStateOld[cnt];

		// キーが押されているならリピートの判定処理
		if (m_keyState[cnt])
		{
			if (m_keyStateRepeatCnt[cnt] < 20)
			{
				m_keyStateRepeatCnt[cnt]++;
				// 「初回入力」もしくは「ボタンを押してから20フレーム経過」
				// した場合、リピート用配列のデータを有効にする
				// 上記条件以外はリピート用配列のデータを無効にする
				if (m_keyStateRepeatCnt[cnt] == 1 || m_keyStateRepeatCnt[cnt] >= 20) {
					m_keyStateRepeat[cnt] = 0x80;
				}
				else {
					m_keyStateRepeat[cnt] = 0;
				}
			}
		}
		else
		{
			m_keyStateRepeatCnt[cnt] = 0;
			m_keyStateRepeat[cnt] = 0;
		}
	}

}



/* キー押下チェック */
// 前回押されていなくて、現在押されている状態であればtrueを返す
bool CDirectInput::KeyTrigger(int _code) {
	return ((m_keyStateTrigger[_code] & 0x80) != 0);
}
// 前回押されていて、現在押されていない状態であればtrueを返す
bool CDirectInput::KeyRelease(int _code) {
	return ((m_keyStateRelease[_code] & 0x80) != 0);
}
// 現在押されている状態であればtrueで返す
bool CDirectInput::KeyPress(int _code) {
	return ((m_keyState[_code] & 0x80) != 0);
}
bool CDirectInput::KeyRepeat(int _code) {
	return ((m_keyStateRepeat[_code] & 0x80) != 0);
}

void CDirectInput::UnInit() {
	// キーボードの終了処理
	UnInitKey();

	if (m_pDirectInput)
	{
		m_pDirectInput->Release();
		m_pDirectInput = NULL;
	}
}
void CDirectInput::UnInitKey() {
	if (m_pKeyDevice)
	{
		m_pKeyDevice->Unacquire();

		m_pKeyDevice->Release();
		m_pKeyDevice = NULL;
	}
}