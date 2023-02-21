#pragma once
#include "YamYamEngine.h"
namespace ya
{
	// 키 입력은 총 4가지 상태로 구분
	// DOWN : 처음 눌렀을 때
	// PRESSED : 계속 눌러져있을 때
	// UP : 때질 때
	// NONE : 입력 없음 

	enum class eKeyCode
	{
		Q,W,E,R,T,Y,U,I,O,P,
		A,S,D,F,G,H,J,K,L,
		Z,X,C,V,B,N,M,
		END,
	};

	enum class eKeyState
	{
		Down,
		Pressed,
		Up,
		None,
	};

	class Input
	{
	public:
		// Enum에 안넣어준 이유는 
		// Enum에 있는 놈들은 어디서나 사용할 가능성이 높은데
		// struct Key는 
		// 어짜피 여기서 cpp랑 헤더에서 만 사용하니 클래스 멤버 구조체로 선언함
		struct Key
		{
			eKeyCode key;// 키
			eKeyState state;// 상태
			bool bPressed;// 눌러져 있는 지
		};

	public:
		static void Initialize();
		static void Update();
		static void Render(HDC hdc);

		inline static eKeyState GetKeyState(eKeyCode keyCode)
		// inline은 함수를 처리하는 일반적인 방법(한번 타고가서)과 달리
		// 이 함수를 호출하면 바로 아래 내부 구현부를 복붙해서 
		// 바로 실행되도록 하는 것
		// inline 붙여도 적용이 컴파일러가 판단해서 사용하기에
		// __forceinline을 붙여서 강제로 적용시킬 수도 있음
		// 그리고 inline은 cpp에서는 사용할 수 없음
		// cpp 자체가 한번 타고간 것이기에 의미가 없쥬?
		{
			return mKeys[(UINT)keyCode].state;
		}

	private:
		static std::vector<Key> mKeys;
	};
}

