#pragma once
#include <d3d11.h>

class GraphicsEngine;

class SwapChain
{
public:
	SwapChain();
	~SwapChain();

	//initialise swapchain for a window
	bool Init(HWND hwnd, UINT width, UINT height);
	//Release all resources
	bool Release();

private:
	IDXGISwapChain* m_swap_chain;
};

