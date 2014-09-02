#pragma once
#include "ApplicationBase.h"

class TestApplication : public ApplicationBase
{
private:
	sMouseEvent _mouseEvent;
public:
	TestApplication();
	~TestApplication();

	virtual HRESULT OnCreateDevice(ID3D11Device* pd3dDevice, const DXGI_SURFACE_DESC* pBackBufferSurfaceDesc,
		void* pUserContext);
};

