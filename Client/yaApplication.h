#pragma once
#include "YamYamEngine.h"
#include "yaTime.h"

namespace ya
{
	class Application
	{
	public:
		Application();
		~Application();

		void Initialize(HWND hWnd);
		void Run(); // Run을 Update와 Render로 쪼갠거임
		void Update();
		void Render();

		HWND GetHwnd() { return mHwnd; }
		HDC GetHdc() { return mHdc; }

	private:
		HWND mHwnd;
		HDC mHdc;
		
		// 백버퍼용 변수
		HBITMAP/* wapi에서는 이미지 파일 확장자가 bitmap만 가능*/ mBackBuffer;
		HDC mBackHDC;

		UINT mWidth; // 지워줄 때 해상도
		UINT mHeight;

		Vector2 mPos;

		//Scene mScene[256];
	};
}

// 현재 구성
// Scene -- PlayScene
// SceneManager
// Layer
// GameObj -- Player
// Component