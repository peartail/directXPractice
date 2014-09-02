#pragma once
#include "ApplicationBase.h"
#include "SDKMesh.h"
#include "TestShaderUtil1.h"

class TestApplication : public ApplicationBase
{
private:
	sMouseEvent _mouseEvent;
	CDXUTSDKMesh  _Mesh11;
	TestShaderUtil1 _shaderutil;
	ID3D11Device* _device;
	ID3D11InputLayout* _vertexLayout;
public:
	TestApplication();
	~TestApplication();

	virtual HRESULT OnCreateDevice(ID3D11Device* pd3dDevice, const DXGI_SURFACE_DESC* pBackBufferSurfaceDesc,
		void* pUserContext);
	virtual void OnFrameRender(ID3D11Device*, ID3D11DeviceContext*, double, float, void*);
};

