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
		void Run(); // Run�� Update�� Render�� �ɰ�����
		void Update();
		void Render();

		HWND GetHwnd() { return mHwnd; }
		HDC GetHdc() { return mHdc; }

	private:
		HWND mHwnd;
		HDC mHdc;
		
		// ����ۿ� ����
		HBITMAP/* wapi������ �̹��� ���� Ȯ���ڰ� bitmap�� ����*/ mBackBuffer;
		HDC mBackHDC;

		UINT mWidth; // ������ �� �ػ�
		UINT mHeight;

		Vector2 mPos;

		//Scene mScene[256];
	};
}

// ���� ����
// Scene -- PlayScene
// SceneManager
// Layer
// GameObj -- Player
// Component