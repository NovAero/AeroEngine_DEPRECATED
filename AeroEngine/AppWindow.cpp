#include "AppWindow.h"

AppWindow::AppWindow()
{
}

AppWindow::~AppWindow()
{
}

void AppWindow::OnCreate()
{
	Window::OnCreate();
	GraphicsEngine::Get()->Init();
	m_swap_chain = GraphicsEngine::Get()->CreateSwapChain();

	RECT rec = this->GetClientWindowRect();
	m_swap_chain->Init(this->m_hwnd, rec.right - rec.left, rec.top - rec.bottom);
}

void AppWindow::OnUpdate()
{
}

void AppWindow::OnDestroy()
{
	Window::OnDestroy();
	GraphicsEngine::Get()->Release();
}
