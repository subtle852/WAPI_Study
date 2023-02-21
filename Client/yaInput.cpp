#include "yaInput.h"

namespace ya
{
	std::vector<Input::Key> Input::mKeys;
	
	int ASCII[(UINT)eKeyCode::END] =
	{
		'Q','W','E','R','T','Y','U','I','O','P',
		'A','S','D','F','G','H','J','K','L',
		'Z','X','C','V','B','N','M',
	}; 
	// 매번 'Q' 이렇게 작성하는 것보단
	// eKeyCode랑 짝을 맞춰서 Q로 사용하기 위해서 이러한 구조로 작성
	// GetAsyncKeyState쓰려면 ASCII형태여야 하는데
	// ASCII 배열의 인덱스와 헤더에 만든 eKeyCode의 숫자와 짝을 이루도록 만들어서 개편하쥬?
	
	void Input::Initialize()
	{
		for (UINT i = 0; i < (UINT)eKeyCode::END; i++)
		{
			Key keyinfo;
			keyinfo.key = (eKeyCode)i;
			keyinfo.state = eKeyState::None;
			keyinfo.bPressed = false;

			mKeys.push_back(keyinfo);
		}
	}
	void Input::Update()
	{
		for (UINT i = 0; i < (UINT)eKeyCode::END; i++)
		{
			if (GetAsyncKeyState(ASCII[i]) & 0x8000)// 현재 프레임에 키가 눌려있다
			{
				if (mKeys[i].bPressed)// 이전 프레임에도 눌려 있었다
				{
					mKeys[i].state = eKeyState::Pressed;
				}
				else
				{
					mKeys[i].state = eKeyState::Down;
				}
				mKeys[i].bPressed = true;
			}
			else // 현재 프레임에 키가 눌려있지 않다
			{
				if (mKeys[i].bPressed)// 이전 프레임에 키가 눌려있었다
				{
					mKeys[i].state = eKeyState::Up;
				}
				else
				{
					mKeys[i].state = eKeyState::None;
				}
				mKeys[i].bPressed = false;
			}
		}
	}
	void Input::Render(HDC hdc)
	{
	}
}