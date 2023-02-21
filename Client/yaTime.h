#pragma once
#include "CommonInclude.h"

namespace ya
{
	class Time
	{
	public:
		static void Initialize();
		static void Update();
		static void Render(HDC hdc);

		__forceinline static double DeltaTime() { return mDeltaTime; }
		
	private:
		static double mDeltaTime;
		static LARGE_INTEGER mCpuFrequency;
		static LARGE_INTEGER mPrevFrequency;
		static LARGE_INTEGER mCurFrequency;
		// 1초당 100번 진동하는 컴이라고하면
		// 시작했을 때 0 > 200으로 변했다면
		// (200 - 0) / 100 이 몇 초 지났는지 확인 가능
		// (mCurFrequency - mPrevFrequency) / mCpuFrequency

		static double mSecond; // 프레임 뽑아주는 걸 계속 보여주니 시간 걸어주기위한 변수
	};
}

