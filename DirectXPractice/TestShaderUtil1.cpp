#include "DXUT.h"
#include "TestShaderUtil1.h"


TestShaderUtil1::TestShaderUtil1()
{
	// Create our vertex input layout
	//_layout = new D3D11_INPUT_ELEMENT_DESC[3];
	_layout[0] = { "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 };
	_layout[0] = { "NORMAL", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 12, D3D11_INPUT_PER_VERTEX_DATA, 0 };
	_layout[0] = { "TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT, 0, 24, D3D11_INPUT_PER_VERTEX_DATA, 0 };
}


TestShaderUtil1::~TestShaderUtil1()
{
	SAFE_RELEASE(_vertexLayout);
	SAFE_RELEASE(_VertexShader);
	SAFE_RELEASE(_PixelShader);

}

HRESULT TestShaderUtil1::ShaderSetting(ID3D11Device& pd3dDevice, ID3D11InputLayout* vlayout)
{
	_vertexLayout = vlayout;
	HRESULT hr;
	// Create the shaders
	ID3DBlob* pPixelShaderBuffer = NULL;

	ID3DBlob* pVertexShaderBuffer = NULL;
	
	V_RETURN(CompileShaderFromFile(L"Practice_VS.hlsl", _vsmain.c_str(), "vs_4_0_level_9_1", &pVertexShaderBuffer));

	V_RETURN(CompileShaderFromFile(L"Practice_PS.hlsl", _psmain.c_str(), "ps_4_0_level_9_1", &pPixelShaderBuffer));

	V_RETURN(pd3dDevice.CreateVertexShader(pVertexShaderBuffer->GetBufferPointer(),
		pVertexShaderBuffer->GetBufferSize(), NULL, &_VertexShader));
	DXUT_SetDebugName(_VertexShader, _vsmain.c_str());
	V_RETURN(pd3dDevice.CreatePixelShader(pPixelShaderBuffer->GetBufferPointer(),
		pPixelShaderBuffer->GetBufferSize(), NULL, &_PixelShader));
	DXUT_SetDebugName(_PixelShader, _vsmain.c_str());


	V_RETURN(pd3dDevice.CreateInputLayout(_layout, ARRAYSIZE(_layout), pVertexShaderBuffer->GetBufferPointer(),
		pVertexShaderBuffer->GetBufferSize(), &_vertexLayout));
	DXUT_SetDebugName(g_pVertexLayout11, "Primary");

	SAFE_RELEASE(pVertexShaderBuffer);
	SAFE_RELEASE(pPixelShaderBuffer);

	return S_OK;
}

void TestShaderUtil1::SetShaderName(std::wstring sname,std::string vsmain,std::string psmain)
{
	_shaderfile = sname;
	_vsmain = vsmain;
	_psmain = psmain;
}

HRESULT TestShaderUtil1::CompileShaderFromFile(std::wstring szFileName, LPCSTR szEntryPoint, LPCSTR szShaderModel, ID3DBlob** ppBlobOut)
{
	HRESULT hr = S_OK;

	// find the file
	WCHAR str[MAX_PATH];
	V_RETURN(DXUTFindDXSDKMediaFileCch(str, MAX_PATH, szFileName.c_str()));

	DWORD dwShaderFlags = D3DCOMPILE_ENABLE_STRICTNESS;
#if defined( DEBUG ) || defined( _DEBUG )
	// Set the D3DCOMPILE_DEBUG flag to embed debug information in the shaders.
	// Setting this flag improves the shader debugging experience, but still allows 
	// the shaders to be optimized and to run exactly the way they will run in 
	// the release configuration of this program.
	dwShaderFlags |= D3DCOMPILE_DEBUG;
#endif

	ID3DBlob* pErrorBlob;
	hr = D3DX11CompileFromFile(str, NULL, NULL, szEntryPoint, szShaderModel,
		dwShaderFlags, 0, NULL, ppBlobOut, &pErrorBlob, NULL);
	if (FAILED(hr))
	{
		if (pErrorBlob != NULL)
			OutputDebugStringA((char*)pErrorBlob->GetBufferPointer());
		SAFE_RELEASE(pErrorBlob);
		return hr;
	}
	SAFE_RELEASE(pErrorBlob);

	return S_OK;
}