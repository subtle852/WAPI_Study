// Client.cpp : 애플리케이션에 대한 진입점을 정의합니다.
// wapi 생성은 데스크톱 마법사로 생성
// wapi는 메시지 큐를 이용한 메시지 기반 프로그램

// wapi 작동 방식
// 1. 윈도우의 정보를 담고있는 클래스를 정의(메모리에 등록)해주어야한다.
// 2. CreateWindow함수를 통해서 메모리상에 윈도우를 할당해준다.
// 3. ShowWindow함수를 통해서 화면에 보여준다.
// 4. 윈도우 클래스를 정의할떄 등록된 메서지 처리함수를
//    순회하면서 들어오는 메세지를 처리해준다.

#include "framework.h"
#include "Client.h"
#include "yaApplication.h"
#include "yaSceneManager.h"
#include "yaResources.h"

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

ya::Application application; // 총괄하는 Application을 전역변수로 생성

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

// wapi도 결국 wWinMain에서 시작
int APIENTRY wWinMain(_In_ HINSTANCE hInstance, // 프로그램 핸들(id)
                     _In_opt_ HINSTANCE hPrevInstance, // 앞에 실행된 프로그램 핸들(id)
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    //_CrtSetBreakAlloc)(217); 메모리 릭 잡는 방법

    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_CLIENT, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다
    // MyRegisterClass로 윈도우 정보를 등록했고
    // InitInstance로 등록한 윈도우를 만들어 줌
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_CLIENT));

    MSG msg;


    while (true)// 기존에 while문 조건의 GetMessage는 메세지가 있을 때만 들어오니 
    {
        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
            // PeekMessage를 통해, 메세지가 있을 때는 여기로 들어오게하고 없을 때는 아래 else문으로 들어오게 가능
        {
            if (WM_QUIT == msg.message)// 종료 메세지가 오면 반복문 나가도록
                break;

            if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
            {
                TranslateMessage(&msg); // 메세지 해석
                DispatchMessage(&msg);
            }
        }
        else
        {
            // 여기서 게임 로직이 돌아가야한다.
            // 혹여나 윈도우 관련 메세지가 들어오면 if문으로 들어가는 것
            application.Run();
        }
    }


    if (WM_QUIT == msg.message)
    {

    }

    ya::SceneManager::Release();// application이 사라지기 전에 mScenes들을 사라지게 하는 Release함수를 호출하게 한 것
    ya::Resources::Release();
    return (int) msg.wParam;
}



//
//  함수: MyRegisterClass()
//
//  용도: 창 클래스를 등록합니다.
//
ATOM MyRegisterClass(HINSTANCE hInstance)// 윈도우 구성요소 설정
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;  // lpfnWndProc 타고 가면 나오는 CALLBACK(__stdcall)은 함수호출 규약 중 하나
                                    // 함수 포인터가 들어간 형태
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_CLIENT)); // 리소스 파일의 Client.ico를 바꾸면 아이콘 모습 변경
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW); // 커서 변경
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_CLIENT);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   함수: InitInstance(HINSTANCE, int)
//
//   용도: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//
//   주석:
//
//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

   //#define CreateWindowW(lpClassName, lpWindowName, dwStyle, 
   //  x, y(창 시작위치), nWidth, nHeight(창 크기), hWndParent, hMenu, hInstance, lpParam)
   // 
   // wapi는 좌측위가 0,0 오른쪽과 아래쪽이 양수
   // 이미지 파일(texture, bitmap)은 좌측아래가 0,0
   // dx는 정중앙이 0,0
   HWND hWnd = CreateWindowW(szWindowClass, szTitle/* 여기서 제목표시줄 수정 */, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, 1600, 900, nullptr/* 창 여러개일때 연결 시킬 때 사용 */, nullptr/* 디폴트 세팅 */, hInstance, nullptr);
   // 핸들을 부여하는 이유: 원자성 보장

   // 윈도우 정보를 2개로 만들어서 2개다 Show, Update 가능
   //HWND hWnd2 = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
   //    CW_USEDEFAULT, 0, 500, 500, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   application.Initialize(hWnd); // 윈도우 처음 만들어지는 순간에 핸들 받아와서 application도 Initialize 해버림
   //ShowWindow(hWnd2, nCmdShow);
   //UpdateWindow(hWnd2);

   //SetTimer(hWnd, 0, 1000, nullptr); 시간마다 반복되기 때문에 모든 컴퓨터가 똑같이 동작하기에 게임을 만들 때는 적합하지 않음

   return TRUE;
}

//
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  용도: 주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 애플리케이션 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//
//

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)// 메시지 호출 함수
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // 메뉴 선택을 구문 분석합니다:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About/* About이라는 함수를 받은 것*/);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT: // 윈도우 생성 시 최초 한번 호출되는 그리기 메시지
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps); // 그림을 그리는 핸들인 HDC hdc

           
            //Ellipse(hdc, 500, 500(위치), 600, 700(크기));
            //RoundRect(hdc, 200, 200, 300, 300, 500, 500);
            
            // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// 정보 대화 상자의 메시지 처리기입니다.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
