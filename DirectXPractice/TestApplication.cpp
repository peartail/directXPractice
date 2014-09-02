#include "TestApplication.h"


TestApplication::TestApplication()
{
}


TestApplication::~TestApplication()
{
}

HRESULT TestApplication::OnCreateDevice(ID3D11Device* pd3dDevice, const DXGI_SURFACE_DESC* pBackBufferSurfaceDesc,
	void* pUserContext)
{
	HRESULT hr;

	ID3D11DeviceContext* pd3dImmediateContext = DXUTGetD3D11DeviceContext();

	D3DXVECTOR3 vCenter(0.25767413f, -28.503521f, 111.00689f);
	FLOAT fObjectRadius = 378.15607f;

	

	

	// Load the mesh
	V_RETURN(g_Mesh11.Create(pd3dDevice, L"tiny\\tiny.sdkmesh", true));

	// Create a sampler state
	D3D11_SAMPLER_DESC SamDesc;
	SamDesc.Filter = D3D11_FILTER_MIN_MAG_MIP_LINEAR;
	SamDesc.AddressU = D3D11_TEXTURE_ADDRESS_WRAP;
	SamDesc.AddressV = D3D11_TEXTURE_ADDRESS_WRAP;
	SamDesc.AddressW = D3D11_TEXTURE_ADDRESS_WRAP;
	SamDesc.MipLODBias = 0.0f;
	SamDesc.MaxAnisotropy = 1;
	SamDesc.ComparisonFunc = D3D11_COMPARISON_ALWAYS;
	SamDesc.BorderColor[0] = SamDesc.BorderColor[1] = SamDesc.BorderColor[2] = SamDesc.BorderColor[3] = 0;
	SamDesc.MinLOD = 0;
	SamDesc.MaxLOD = D3D11_FLOAT32_MAX;
	V_RETURN(pd3dDevice->CreateSamplerState(&SamDesc, &g_pSamLinear));
	DXUT_SetDebugName(g_pSamLinear, "Primary");

	// Setup constant buffers
	D3D11_BUFFER_DESC Desc;
	Desc.Usage = D3D11_USAGE_DYNAMIC;
	Desc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
	Desc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
	Desc.MiscFlags = 0;

	Desc.ByteWidth = sizeof(CB_VS_PER_OBJECT);
	V_RETURN(pd3dDevice->CreateBuffer(&Desc, NULL, &g_pcbVSPerObject));
	DXUT_SetDebugName(g_pcbVSPerObject, "CB_VS_PER_OBJECT");

	Desc.ByteWidth = sizeof(CB_PS_PER_OBJECT);
	V_RETURN(pd3dDevice->CreateBuffer(&Desc, NULL, &g_pcbPSPerObject));
	DXUT_SetDebugName(g_pcbPSPerObject, "CB_PS_PER_OBJECT");

	Desc.ByteWidth = sizeof(CB_PS_PER_FRAME);
	V_RETURN(pd3dDevice->CreateBuffer(&Desc, NULL, &g_pcbPSPerFrame));
	DXUT_SetDebugName(g_pcbPSPerFrame, "CB_PS_PER_FRAME");

	// Setup the camera's view parameters
	D3DXVECTOR3 vecEye(0.0f, 0.0f, -100.0f);
	D3DXVECTOR3 vecAt(0.0f, 0.0f, -0.0f);
	g_Camera.SetViewParams(&vecEye, &vecAt);
	g_Camera.SetRadius(fObjectRadius * 3.0f, fObjectRadius * 0.5f, fObjectRadius * 10.0f);

	return S_OK;
}
