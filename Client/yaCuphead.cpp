#include "yaCuphead.h"
#include "yaTime.h"
#include "yaSceneManager.h"
#include "yaInput.h"
#include "yaResources.h"
#include "yaTransform.h"

namespace ya
{
	Cuphead::Cuphead()
	{
	}
	Cuphead::~Cuphead()
	{
	}
	void Cuphead::Initialize()
	{
		mImage = Resources::Load<Image>(L"Cuphead", L"..\\Resources\\Idle.bmp");

		GameObject::Initialize();
	}
	void Cuphead::Update()
	{
		GameObject::Update();

		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		if (Input::GetKeyState(eKeyCode::A) == eKeyState::Pressed)
		{
			pos.x -= 100.0f * Time::DeltaTime();
		}

		if (Input::GetKeyState(eKeyCode::D) == eKeyState::Pressed)
		{
			pos.x += 100.0f * Time::DeltaTime();
		}

		//if (Input::GetKeyState(eKeyCode::D) == eKeyState::Up)
		//{
		//	mPos.x = 0.0f;
		//	mPos.y = 0.0f;
		//}
		// 이렇게 여러 상황들을 제어할 수 있음
		// ex. 아이템 클릭 후, 이동시 특정 위치가 아닐때는 다시 그 위치로 이동시키는 경우를 만들 수 있음

		if (Input::GetKeyState(eKeyCode::W) == eKeyState::Pressed)
		{
			pos.y -= 100.0f * Time::DeltaTime();
		}

		if (Input::GetKeyState(eKeyCode::S) == eKeyState::Pressed)
		{
			pos.y += 100.0f * Time::DeltaTime();
		}

		tr->SetPos(pos);
	}
	void Cuphead::Render(HDC hdc)
	{
		GameObject::Render(hdc);

		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		BitBlt(hdc, pos.x, pos.y, mImage->GetWidth(), mImage->GetHeight(), mImage->GetHdc(), 0, 0, SRCCOPY);
	}
	void Cuphead::Release()
	{
		GameObject::Release();
	}
}