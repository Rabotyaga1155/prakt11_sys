// prakt11_sys.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include <commdlg.h>
#include "prakt11_sys.h"
#include <commctrl.h>

#pragma comment(lib, "comctl32.lib")


#define MAX_LOADSTRING 100

// Глобальные переменные:
HWND hTreeView;
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна

ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    Font(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK DialogProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);

BOOL CreateDialogWindow(HINSTANCE hInstance, HWND hWndParent);

BOOL CreateControls(HWND hWnd);

BOOL CreateDialogWindow(HINSTANCE hInstance, HWND hWndParent) {
   
    HWND hGroupBox = CreateWindowW(L"BUTTON", L"Пример GroupBox", WS_VISIBLE | WS_CHILD | BS_GROUPBOX,
        20, 20, 250, 100, hWndParent, nullptr, hInstance, nullptr);
    if (!hGroupBox)
        return FALSE;

    HWND hStaticText = CreateWindowW(L"STATIC", L"Пример текста", WS_VISIBLE | WS_CHILD,
        30, 40, 200, 20, hGroupBox, nullptr, hInstance, nullptr);
    if (!hStaticText)
        return FALSE;

    HWND hHotKey = CreateWindowW(L"msctls_hotkey32", L"HotKey", WS_VISIBLE | WS_CHILD | WS_BORDER,
        240, 140, 100, 20, hWndParent, nullptr, hInstance, nullptr);
    if (!hHotKey)
        return FALSE;

    return TRUE;
}

BOOL CreateControls(HWND hWnd) {
   
    if (!CreateDialogWindow(hInst, hWnd))
        return FALSE;

    return TRUE;
}




int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_PRAKT11SYS, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    if (!InitInstance (hInstance, nCmdShow))
    {

        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_PRAKT11SYS));

    MSG msg;

    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}


INT_PTR CALLBACK DialogProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
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

//
//  ФУНКЦИЯ: MyRegisterClass()
//
//  ЦЕЛЬ: Регистрирует класс окна.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_PRAKT11SYS));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_PRAKT11SYS);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   ФУНКЦИЯ: InitInstance(HINSTANCE, int)
//
//   ЦЕЛЬ: Сохраняет маркер экземпляра и создает главное окно
//
//   КОММЕНТАРИИ:
//
//        В этой функции маркер экземпляра сохраняется в глобальной переменной, а также
//        создается и выводится главное окно программы.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
    hInst = hInstance;
    

    HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

    if (!hWnd)
    {
        return FALSE;
    }

    

   
    HWND hGroupBox = CreateWindowW(L"BUTTON", L"Пример GroupBox", WS_VISIBLE | WS_CHILD | BS_GROUPBOX,
        20, 20, 250, 100, hWnd, nullptr, hInstance, nullptr);

    if (!hGroupBox)
    {
        return FALSE;
    }



    
    
    

   



   
    

    

    HWND hStaticText = CreateWindowW(L"STATIC", L"Пример текста", WS_VISIBLE | WS_CHILD,
        30, 40, 200, 20, hGroupBox, nullptr, hInstance, nullptr);

    if (!hStaticText)
    {
        return FALSE;
    }


    HWND hHotKey = CreateWindowW(L"msctls_hotkey32", L"HotKey", WS_VISIBLE | WS_CHILD | WS_BORDER,
        240, 140, 100, 20, hWnd, nullptr, hInstance, nullptr);


    if (!hHotKey)
    {
        return FALSE;
    }

    
    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    

    return TRUE;
}




//
//  ФУНКЦИЯ: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  ЦЕЛЬ: Обрабатывает сообщения в главном окне.
//
//  WM_COMMAND  - обработать меню приложения
//  WM_PAINT    - Отрисовка главного окна
//  WM_DESTROY  - отправить сообщение о выходе и вернуться
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
    {
        int wmId = LOWORD(wParam);

        switch (wmId)
        {
        case IDM_ABOUT:
            DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
            break;
        case IDM_FONTD:
        {
            CHOOSEFONT cf = { sizeof(CHOOSEFONT) };
            cf.hwndOwner = hWnd;
            cf.Flags = CF_SCREENFONTS | CF_INITTOLOGFONTSTRUCT;

            if (ChooseFont(&cf) != FALSE) {
                // Add your code here to handle the font change
            }
            break;
        }
            
            break;
        case IDM_PRINTD: {
            PRINTDLG pd = { sizeof(PRINTDLG) };

            if (PrintDlg(&pd) != FALSE) {

            }
        }

            break;
        case IDM_EXIT:
            DestroyWindow(hWnd);
            break;
        case IDC_GROUPBOX:
            DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, Font); 
            break;
        default:
            return DefWindowProc(hWnd, message, wParam, lParam);
        }
    }
    case WM_CHAR:
    {
        WCHAR charMessage[64];
        swprintf_s(charMessage, L"Received WM_CHAR: %c", (WCHAR)wParam);
        MessageBox(hWnd, charMessage, L"WM_CHAR Message", MB_OK | MB_ICONINFORMATION);
    }
    break;
    case WM_KEYUP:
    {
        WCHAR keyMessage[64];
        swprintf_s(keyMessage, L"Received WM_KEYUP: %c", (WCHAR)wParam);
        MessageBox(hWnd, keyMessage, L"WM_KEYUP Message", MB_OK | MB_ICONINFORMATION);
    }
    
    case WM_MBUTTONDBLCLK:
    {
        MessageBox(hWnd, L"Received WM_MBUTTONDBLCLK", L"WM_MBUTTONDBLCLK Message", MB_OK | MB_ICONINFORMATION);
    }
    
    case WM_MBUTTONDOWN:
    {
        MessageBox(hWnd, L"Received WM_MBUTTONDOWN", L"WM_MBUTTONDOWN Message", MB_OK | MB_ICONINFORMATION);
    }
    
    case WM_MBUTTONUP:
    {
        MessageBox(hWnd, L"Received WM_MBUTTONUP", L"WM_MBUTTONUP Message", MB_OK | MB_ICONINFORMATION);
    }
    
    case WM_MOUSEWHEEL:
    {
        short delta = GET_WHEEL_DELTA_WPARAM(wParam);
        WCHAR wheelMessage[64];
        swprintf_s(wheelMessage, L"Received WM_MOUSEWHEEL: Delta = %d", delta);
        MessageBox(hWnd, wheelMessage, L"WM_MOUSEWHEEL Message", MB_OK | MB_ICONINFORMATION);
    }
    break;
    case WM_EXITSIZEMOVE:
    {
        WCHAR movingMessage[64];
        swprintf_s(movingMessage, L"WM_EXITSIZEMOVE");
        MessageBox(hWnd, movingMessage, L"Сообщение WM_EXITSIZEMOVE", MB_OK | MB_ICONINFORMATION);
        break;
    }

    break;
    break;
    break;
    break;
    break;
    break;

    case WM_CTLCOLORSTATIC:
        if (((HWND)lParam) == GetDlgItem(hWnd, 3))
        {
            SetTextColor((HDC)wParam, RGB(0, 0, 255));
        }
        return (LRESULT)GetSysColorBrush(COLOR_WINDOW);
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
           
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

// Обработчик сообщений для окна "О программе".
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

INT_PTR CALLBACK Font(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
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


