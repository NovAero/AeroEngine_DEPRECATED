#pragma once
#include <d3d11.h>

class GraphicsEngine
{
public:
	GraphicsEngine();
	~GraphicsEngine();

	//Initialise Graphics engine on DirectX11
	bool Init();
	//Release all resources loaded
	bool Release();

public:
	static GraphicsEngine* Get();

private:

	//DX11 device
	ID3D11Device* m_d3d_device;
	D3D_FEATURE_LEVEL* m_feature_level;
	ID3D11DeviceContext* m_imm_context;
};


