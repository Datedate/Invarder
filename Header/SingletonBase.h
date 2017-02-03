#ifndef _SINGLETON_BASE_H_
#define _SINGLETON_BASE_H_

// �V���O���g���p�^�[���̊��N���X

//
//	�E�p����̃R���X�g���N�^�ƃf�X�g���N�^��private
//	�Efriend SingletonBase<�p�������N���X>
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
	static T* m_Instance;				// �B��̃C���X�^���X
protected:
	/* �֎~���� */
	SingletonBase() {};
	~SingletonBase() {};
	SingletonBase(const SingletonBase& single) = delete;
	const SingletonBase& operator= (const SingletonBase& single) = delete;
};

template<class T>
T* SingletonBase<T>::m_Instance = NULL;

#endif