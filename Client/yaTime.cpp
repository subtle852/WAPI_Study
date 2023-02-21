#include "yaTime.h"
#include "yaApplication.h"

extern ya::Application application; // 전역변수 이렇게 생겼어ㅎ

namespace ya
{
	double Time::mDeltaTime = 0.0l;
	LARGE_INTEGER Time::mCpuFrequency = {};
	LARGE_INTEGER Time::mPrevFrequency = {};
	LARGE_INTEGER Time::mCurFrequency = {};

	double Time::mSecond = 0.0f;

	void Time::Initialize()
	{
		// CPU 고유 진동수 가져오기
		QueryPerformanceFrequency(&mCpuFrequency);

		// 프로그램이 처음 시작할 때 진동수
		QueryPerformanceCounter(&mPrevFrequency);

	}
	void Time::Update()
	{
		QueryPerformanceCounter(&mCurFrequency);
		double differenceFrequency = mCurFrequency.QuadPart - mPrevFrequency.QuadPart;
		mDeltaTime = differenceFrequency / mCpuFrequency.QuadPart;

		mPrevFrequency.QuadPart = mCurFrequency.QuadPart;
	}
	void Time::Render(HDC hdc)
	{
		mSecond += mDeltaTime;

		if (mSecond > 1.0f) // 1초마다 보여줌
		{
			HWND hWnd = application.GetHwnd();

			wchar_t szFloat[50] = {};
			float FPS = 1.0f / (float)mDeltaTime;
			// 한바퀴(1프레임)도는 데 0.2초가 걸렸다고 하면
			// 1초에 5번 도는 것
			// 프레임은 그럼 5
			// 프레임 공식: 1 / 0.2 
			swprintf_s(szFloat, 50, L"FPS : %d", (UINT)FPS);
			//int iLen = wcsnlen_s(szFloat, 50);

			SetWindowText(hWnd, szFloat);
			mSecond = 0.0f;
		}

	}
}