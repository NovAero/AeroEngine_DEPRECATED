#pragma once
#include <Windows.h>

class Window
{
public:
	Window();
	~Window();

	//Initalise window
	bool Init();
	bool Broadcast();
	//Release the Window
	bool Release();
	bool IsRun();

	//Events
	virtual void OnCreate() = 0;
	virtual void OnUpdate() = 0;
	virtual void OnDestroy();

protected:

	HWND m_hwnd;
	bool m_isRun;
};

