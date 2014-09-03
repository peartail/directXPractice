#include "DXUT.h"
#include "TestApplication.h"


TestApplication::TestApplication()
{
	_vertexLayout = NULL;
}


TestApplication::~TestApplication()
{
	SAFE_RELEASE(_vertexLayout);
}

HRESULT TestApplication::OnCreateDevice(ID3D11Device* pd3dDevice, const DXGI_SURFACE_DESC* pBackBufferSurfaceDesc,
	void* pUserContext)
{
	HRESULT hr;

	_device = pd3dDevice;

	ID3D11DeviceContext* pd3dImmediateContext = DXUTGetD3D11DeviceContext();

	D3DXVECTOR3 vCenter(0.25767413f, -28.503521f, 111.00689f);
	FLOAT fObjectRadius = 378.15607f;

	_shaderutil.SetShaderName(L"Practice", "VSMain", "PSMain");
	_shaderutil.ShaderSetting(*_device, _vertexLayout);

	// Load the mesh
	V_RETURN(_Mesh11.Create(pd3dDevice, L"Model\\Sphere.sdkmesh", true));

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
	//V_RETURN(pd3dDevice->CreateSamplerState(&SamDesc, &g_pSamLinear));
	DXUT_SetDebugName(g_pSamLinear, "Primary");

	// Setup constant buffers
	D3D11_BUFFER_DESC Desc;
	Desc.Usage = D3D11_USAGE_DYNAMIC;
	Desc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
	Desc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
	Desc.MiscFlags = 0;

	

	// Setup the camera's view parameters
	D3DXVECTOR3 vecEye(0.0f, 0.0f, -100.0f);
	D3DXVECTOR3 vecAt(0.0f, 0.0f, -0.0f);
	//g_Camera.SetViewParams(&vecEye, &vecAt);
	//g_Camera.SetRadius(fObjectRadius * 3.0f, fObjectRadius * 0.5f, fObjectRadius * 10.0f);

	return S_OK;
}

void TestApplication::OnFrameRender(ID3D11Device* pd3Device, ID3D11DeviceContext* context, double time, float etime, void* userCtx)
{
	HRESULT hr;

	// Clear the render target and depth stencil
	float ClearColor[4] = { 0.0f, 0.25f, 0.25f, 0.55f };
	ID3D11RenderTargetView* pRTV = DXUTGetD3D11RenderTargetView();
	context->ClearRenderTargetView(pRTV, ClearColor);
	ID3D11DepthStencilView* pDSV = DXUTGetD3D11DepthStencilView();
	context->ClearDepthStencilView(pDSV, D3D11_CLEAR_DEPTH, 1.0, 0);

	D3DXMATRIX mWorldViewProjection;
	D3DXVECTOR3 vLightDir;
	D3DXMATRIX mWorld;
	D3DXMATRIX mView;
	D3DXMATRIX mProj;

	// Get the projection & view matrix from the camera class
	//mProj = *g_Camera.GetProjMatrix();
	//mView = *g_Camera.GetViewMatrix();

	// Get the light direction
	//vLightDir = g_LightControl.GetLightDirection();

	//Get the mesh
	//IA setup
	context->IASetInputLayout(_shaderutil.GetVertexLayout());
	UINT Strides[1];
	UINT Offsets[1];
	ID3D11Buffer* pVB[1];
	pVB[0] = _Mesh11.GetVB11(0, 0);
	Strides[0] = (UINT)_Mesh11.GetVertexStride(0, 0);
	Offsets[0] = 0;
	context->IASetVertexBuffers(0, 1, pVB, Strides, Offsets);
	context->IASetIndexBuffer(_Mesh11.GetIB11(0), _Mesh11.GetIBFormat11(0), 0);

	// Set the shaders
	context->VSSetShader(_shaderutil.GetVertexShader(), NULL, 0);
	context->PSSetShader(_shaderutil.GetPixelShader(), NULL, 0);

	// Set the per object constant data
	//mWorld = g_mCenterMesh * *g_Camera.GetWorldMatrix();
	//mProj = *g_Camera.GetProjMatrix();
	//mView = *g_Camera.GetViewMatrix();

	//mWorldViewProjection = mWorld * mView * mProj;

	//pd3dImmediateContext->PSSetConstantBuffers(g_iCBPSPerObjectBind, 1, &g_pcbPSPerObject);

	//Render
	SDKMESH_SUBSET* pSubset = NULL;
	D3D11_PRIMITIVE_TOPOLOGY PrimType;

	//pd3dImmediateContext->PSSetSamplers(0, 1, &g_pSamLinear);

	for (UINT subset = 0; subset < _Mesh11.GetNumSubsets(0); ++subset)
	{
		// Get the subset
		pSubset = _Mesh11.GetSubset(0, subset);

		/*PrimType = CDXUTSDKMesh::GetPrimitiveType11((SDKMESH_PRIMITIVE_TYPE)pSubset->PrimitiveType);
		context->IASetPrimitiveTopology(PrimType);
		*/
		// TODO: D3D11 - material loading
//		ID3D11ShaderResourceView* pDiffuseRV = _Mesh11.GetMaterial(pSubset->MaterialID)->pDiffuseRV11;
		//context->PSSetShaderResources(0, 1, &pDiffuseRV);

		context->DrawIndexed((UINT)pSubset->IndexCount, 0, (UINT)pSubset->VertexStart);
	}

}