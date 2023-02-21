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
		// 1�ʴ� 100�� �����ϴ� ���̶���ϸ�
		// �������� �� 0 > 200���� ���ߴٸ�
		// (200 - 0) / 100 �� �� �� �������� Ȯ�� ����
		// (mCurFrequency - mPrevFrequency) / mCpuFrequency

		static double mSecond; // ������ �̾��ִ� �� ��� �����ִ� �ð� �ɾ��ֱ����� ����
	};
}

