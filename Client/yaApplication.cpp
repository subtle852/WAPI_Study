#include "yaApplication.h"
#include "yaSceneManager.h"
#include "yaTime.h"
#include "yaInput.h"

namespace ya
{
	Application::Application()
		: mHwnd(NULL)
		, mHdc(NULL)
	{
	}

	Application::~Application()
	{
	}

	void Application::Initialize(HWND hWnd)
	{
		mHwnd = hWnd;
		mHdc = GetDC(hWnd);// 핸들만 받아와서 GetDc를 통해 HDC 받아올 수 있음

		{
			mWidth = 1600;
			mHeight = 900;

			// 비트맵 해상도를 설정하기 위한 실제 윈도우 크기를 알아서 계산해줌
			RECT rect = { 0,0, mWidth, mHeight };
			AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

			// 윈도우 크기 변경 및 출력 설정
			SetWindowPos(mHwnd
				, nullptr
				, 100, 50
				, rect.right - rect.left
				, rect.bottom - rect.top
				, 0);
			ShowWindow(hWnd, true);
		}

		{
			mBackBuffer = CreateCompatibleBitmap(mHdc, mWidth, mHeight);
			mBackHDC = CreateCompatibleDC(mHdc);
			HBITMAP defaultBitmap = (HBITMAP)SelectObject(mBackHDC, mBackBuffer);
			DeleteObject(defaultBitmap);// mBackBuffer로 바뀌기 전의 하얀 화면을 defalutBitmap으로 뱉어주고 삭제해준 것
		}

		Time::Initialize();
		Input::Initialize();
		SceneManager::Initialize();
	}

	void Application::Run()
	{
		Update();
		Render();
	}

	void Application::Update()
	{
		Time::Update();
		Input::Update();
		SceneManager::Update();
		//if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		//{
		//	mPos.x -= 0.01f;
		//}

		//if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		//{
		//	mPos.x += 0.01f;
		//}

		//if (GetAsyncKeyState(VK_UP) & 0x8000)
		//{
		//	mPos.y -= 0.01f;
		//}

		//if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		//{
		//	mPos.y += 0.01f;
		//}
	}

	void Application::Render()
	{
		Rectangle(mBackHDC, -1, -1, 1602, 902);// Reder 해준 것 지워주기
		// 그런데 해상도가 창 크기의 완전 상단부터, 완전 왼쪽부터 측정이 된 것이라 잉여부분이 남음
		// 그렇기에 Initialize에서 mWidth, mHeight를 정한 것


		Time::Render(mBackHDC);
		Input::Render(mBackHDC);

		SceneManager::Render(mBackHDC);

		// 백버퍼에 싹다 그리고 지우기 때문에
		// 백버퍼에 있는 그림을 원본버퍼에 복사해줘야한다
		BitBlt(mHdc, 0, 0, mWidth, mHeight, mBackHDC, 0, 0, SRCCOPY);
	}
}
