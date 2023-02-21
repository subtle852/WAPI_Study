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
	// �Ź� 'Q' �̷��� �ۼ��ϴ� �ͺ���
	// eKeyCode�� ¦�� ���缭 Q�� ����ϱ� ���ؼ� �̷��� ������ �ۼ�
	// GetAsyncKeyState������ ASCII���¿��� �ϴµ�
	// ASCII �迭�� �ε����� ����� ���� eKeyCode�� ���ڿ� ¦�� �̷絵�� ���� ��������?
	
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
			if (GetAsyncKeyState(ASCII[i]) & 0x8000)// ���� �����ӿ� Ű�� �����ִ�
			{
				if (mKeys[i].bPressed)// ���� �����ӿ��� ���� �־���
				{
					mKeys[i].state = eKeyState::Pressed;
				}
				else
				{
					mKeys[i].state = eKeyState::Down;
				}
				mKeys[i].bPressed = true;
			}
			else // ���� �����ӿ� Ű�� �������� �ʴ�
			{
				if (mKeys[i].bPressed)// ���� �����ӿ� Ű�� �����־���
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