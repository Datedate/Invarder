#ifndef _SINGLETON_BASE_H_
#define _SINGLETON_BASE_H_

// シングルトンパターンの基底クラス

//
//	・継承先のコンストラクタとデストラクタはprivate
//	・friend SingletonBase<継承したクラス>
//

template<class T>

class SingletonBase
{
public:
	static T* GetInstance() {
		if (!m_Instance)
			m_Instance = new T();
		return m_Instance;
	}
private:
	static T* m_Instance;				// 唯一のインスタンス
protected:
	/* 禁止事項 */
	SingletonBase() {};
	~SingletonBase() {};
	SingletonBase(const SingletonBase& single) = delete;
	const SingletonBase& operator= (const SingletonBase& single) = delete;
};

template<class T>
T* SingletonBase<T>::m_Instance = NULL;

#endif