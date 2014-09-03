#include "DXUT.h"
#include "TestApplication1.h"


TestApplication1::TestApplication1()
{
	_Effect10 = NULL;
}


TestApplication1::~TestApplication1()
{
}

HRESULT TestApplication1::OnCreateDevice(ID3D10Device* pd3dDevice, const DXGI_SURFACE_DESC* pBackBufferSurfaceDesc,
	void* pUserContext)
{
	HRESULT hr;

	D3DXVECTOR3 vCenter(0.25767413f, -28.503521f, 111.00689f);
	FLOAT fObjectRadius = 378.15607f;

	
	// Create our vertex input layout
	_shaderutil.SetShaderName(L"Shader\\specularmapping.fx", "Lighting");
	_shaderutil.ShaderSetting(*pd3dDevice);
	// Load the mesh
	V_RETURN(_Mesh.Create(pd3dDevice, L"Model\\Sphere.sdkmesh", true));

	// Setup the camera's view parameters
	D3DXVECTOR3 vecEye(0.0f, 0.0f, -15.0f);
	D3DXVECTOR3 vecAt(0.0f, 0.0f, -0.0f);
	//g_Camera.SetViewParams(&vecEye, &vecAt);
	//g_Camera.SetRadius(fObjectRadius * 3.0f, fObjectRadius * 0.5f, fObjectRadius * 10.0f);

	return S_OK;
}

void TestApplication1::OnFrameRender(ID3D10Device* pd3dDevice, double fTime, float fElapsedTime, void* pUserContext)
{
	HRESULT hr;

	

}