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
		mHdc = GetDC(hWnd);// �ڵ鸸 �޾ƿͼ� GetDc�� ���� HDC �޾ƿ� �� ����

		{
			mWidth = 1600;
			mHeight = 900;

			// ��Ʈ�� �ػ󵵸� �����ϱ� ���� ���� ������ ũ�⸦ �˾Ƽ� �������
			RECT rect = { 0,0, mWidth, mHeight };
			AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

			// ������ ũ�� ���� �� ��� ����
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
			DeleteObject(defaultBitmap);// mBackBuffer�� �ٲ�� ���� �Ͼ� ȭ���� defalutBitmap���� ����ְ� �������� ��
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
		Rectangle(mBackHDC, -1, -1, 1602, 902);// Reder ���� �� �����ֱ�
		// �׷��� �ػ󵵰� â ũ���� ���� ��ܺ���, ���� ���ʺ��� ������ �� ���̶� �׿��κ��� ����
		// �׷��⿡ Initialize���� mWidth, mHeight�� ���� ��


		Time::Render(mBackHDC);
		Input::Render(mBackHDC);

		SceneManager::Render(mBackHDC);

		// ����ۿ� �ϴ� �׸��� ����� ������
		// ����ۿ� �ִ� �׸��� �������ۿ� ����������Ѵ�
		BitBlt(mHdc, 0, 0, mWidth, mHeight, mBackHDC, 0, 0, SRCCOPY);
	}
}
