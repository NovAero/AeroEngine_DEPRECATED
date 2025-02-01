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

	RECT GetClientWindowRect();
	void SetHWND(HWND hwnd);

	//Events
	virtual void OnCreate();
	virtual void OnUpdate() = 0;
	virtual void OnDestroy();

protected:

	HWND m_hwnd;
	bool m_isRun; //Is the window running
};

