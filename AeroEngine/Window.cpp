#include "Window.h"

Window::Window()
{

}
Window::~Window()
{
}
LRESULT CALLBACK WindProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) {

    switch (msg) {
    case WM_CREATE:
    {   //Event fired when the window will be created
        Window* window = (Window*)((LPCREATESTRUCT)lparam)->lpCreateParams;
        //and then stored for later lookup
        SetWindowLongPtr(hwnd, GWLP_USERDATA, (LONG_PTR)window);
        window->OnCreate();
        break;
    }
    case WM_DESTROY:
    {   //Event fired when the window will be destroyed
        Window* window = (Window*)GetWindowLongPtr(hwnd, GWLP_USERDATA);
        window->OnDestroy();
        ::PostQuitMessage(0);
        break;
    }
    default:
        return ::DefWindowProc(hwnd, msg, wparam, lparam);
    }

    return NULL;
}

bool Window::Init()
{
    //Initialise window class
    WNDCLASSEX wc;
    wc.cbClsExtra = NULL;
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.cbWndExtra = NULL;
    wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
    wc.hInstance = NULL;
    wc.lpszClassName = (L"WindowClass");
    wc.lpszMenuName = (L"");
    wc.style = NULL;
    wc.lpfnWndProc = &WindProc;

    //If the registration will fail, functions returns false
    if (!::RegisterClassEx(&wc)) {
        return false;
    }

    //Create window
    m_hwnd = ::CreateWindowEx(WS_EX_OVERLAPPEDWINDOW, L"WindowClass",
                    L"AeroEngine - Using DX11", WS_OVERLAPPEDWINDOW,
                    CW_USEDEFAULT, CW_USEDEFAULT, 1024, 768,
                    NULL, NULL, NULL, this);

    //If creation fails, return false
    if (m_hwnd == 0) {
        return false;
    }

    //Display the window
    ::ShowWindow(m_hwnd, SW_SHOW);
    ::UpdateWindow(m_hwnd);

    //Set flag to indicate is running and has sucessfully initalised
    m_isRun = true;

    return true;
}

bool Window::Broadcast()
{
    MSG msg;

    while (::PeekMessage(&msg, NULL, 0,0,PM_REMOVE) > 0) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    this->OnUpdate();

    Sleep(0);

    return true;
}

bool Window::Release()
{
    //Try to destroy window
    if (!::DestroyWindow(m_hwnd)){
        return false;
    }

    return true;
}

bool Window::IsRun()
{
    return m_isRun;
}

void Window::OnCreate()
{
}

void Window::OnDestroy()
{
    m_isRun = false;
}
