#pragma once
#include "DXUT.h"
#include "SDKmesh.h"
#include "ApplicationBase.h"
#include "TestShaderUtil1.h"

#define TShader TestShaderUtil1

class TestApplication1 : public ApplicationBase
{
private:
	ID3D10Device* _device;
	ID3D10InputLayout* _vertexLayout;
	ID3D10Effect* _Effect10; 

	CDXUTSDKMesh _Mesh;
	TShader _shaderutil;
public:
	TestApplication1();
	~TestApplication1();
	virtual HRESULT OnCreateDevice(ID3D10Device* pd3dDevice, const DXGI_SURFACE_DESC* pBackBufferSurfaceDesc,
		void* pUserContext);
	virtual void OnFrameRender(ID3D10Device* pd3dDevice, double fTime, float fElapsedTime, void* pUserContext);
};

