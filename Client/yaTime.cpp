#include "yaTime.h"
#include "yaApplication.h"

extern ya::Application application; // �������� �̷��� ����

namespace ya
{
	double Time::mDeltaTime = 0.0l;
	LARGE_INTEGER Time::mCpuFrequency = {};
	LARGE_INTEGER Time::mPrevFrequency = {};
	LARGE_INTEGER Time::mCurFrequency = {};

	double Time::mSecond = 0.0f;

	void Time::Initialize()
	{
		// CPU ���� ������ ��������
		QueryPerformanceFrequency(&mCpuFrequency);

		// ���α׷��� ó�� ������ �� ������
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

		if (mSecond > 1.0f) // 1�ʸ��� ������
		{
			HWND hWnd = application.GetHwnd();

			wchar_t szFloat[50] = {};
			float FPS = 1.0f / (float)mDeltaTime;
			// �ѹ���(1������)���� �� 0.2�ʰ� �ɷȴٰ� �ϸ�
			// 1�ʿ� 5�� ���� ��
			// �������� �׷� 5
			// ������ ����: 1 / 0.2 
			swprintf_s(szFloat, 50, L"FPS : %d", (UINT)FPS);
			//int iLen = wcsnlen_s(szFloat, 50);

			SetWindowText(hWnd, szFloat);
			mSecond = 0.0f;
		}

	}
}