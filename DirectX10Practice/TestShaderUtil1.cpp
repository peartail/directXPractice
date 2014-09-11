#include "DXUT.h"
#include "SDKmisc.h"
#include "TestShaderUtil1.h"


TestShaderUtil1::TestShaderUtil1()
{
	_layout[0] = { "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D10_INPUT_PER_VERTEX_DATA, 0 };
	_layout[0] = { "NORMAL", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 12, D3D10_INPUT_PER_VERTEX_DATA, 0 };
	_layout[0] = { "TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT, 0, 24, D3D10_INPUT_PER_VERTEX_DATA, 0 };

	_vertexLayout = NULL;
	_shaderTechnique = NULL;
}


TestShaderUtil1::~TestShaderUtil1()
{
}

HRESULT TestShaderUtil1::ShaderSetting(ID3D10Device& pd3dDevice)
{
	HRESULT hr;

	DWORD dwShaderFlags = D3D10_SHADER_ENABLE_STRICTNESS;
	ID3D10Blob* ret = NULL;

	ID3D10Blob* pError = NULL;
#if defined( DEBUG ) || defined( _DEBUG )
	// Set the D3D10_SHADER_DEBUG flag to embed debug information in the shaders.
	// Setting this flag improves the shader debugging experience, but still allows 
	// the shaders to be optimized and to run exactly the way they will run in 
	// the release configuration of this program.
	dwShaderFlags |= D3D10_SHADER_DEBUG;
#endif


	// Read the D3DX effect file
	WCHAR str[MAX_PATH];
	V_RETURN(DXUTFindDXSDKMediaFileCch(str, MAX_PATH, _shaderfile.c_str()));
	V_RETURN(D3DX10CreateEffectFromFile(str, NULL, NULL, "fx_4_0", dwShaderFlags, 0, &pd3dDevice, NULL,
		NULL, &_Effect10, &ret, &hr));

	_shaderTechnique = _Effect10->GetTechniqueByName(_techniqueName.c_str());

	_WorldMatrix = _Effect10->GetVariableByName("gWm")->AsMatrix();
	_ViewMatrix = _Effect10->GetVariableByName("gVm")->AsMatrix();
	_projectionMatrix = _Effect10->GetVariableByName("gPm")->AsMatrix();

	D3D10_PASS_DESC PassDesc;
	V_RETURN(_shaderTechnique->GetPassByIndex(0)->GetDesc(&PassDesc));
	V_RETURN(pd3dDevice.CreateInputLayout(_layout, ARRAYSIZE(_layout), PassDesc.pIAInputSignature,
		PassDesc.IAInputSignatureSize, &_vertexLayout));

	return S_OK;
}

void TestShaderUtil1::SetShaderName(std::wstring shaderfile, std::string techniqueName)
{
	_shaderfile = shaderfile;
	_techniqueName = techniqueName;
}

HRESULT TestShaderUtil1::SetVertexShader(std::string vsmain)
{
	return S_OK;
}

HRESULT TestShaderUtil1::SetPixelShader(std::string psmain)
{
	return S_OK;
}

HRESULT TestShaderUtil1::CompileShaderFromFile(std::wstring szFileName, LPCSTR szEntryPoint, LPCSTR szShaderModel, ID3DBlob** ppBlobOut)
{
	return S_OK;
}

void TestShaderUtil1::SetWorldMatrix(D3DXMATRIX mat)
{
	_WorldMatrix->SetMatrix(mat);
}

void TestShaderUtil1::SetViewMatrix(D3DXMATRIX mat)
{
	_ViewMatrix->SetMatrix(mat);
}

void TestShaderUtil1::SetProjectionMatrix(D3DXMATRIX mat)
{
	_projectionMatrix->SetMatrix(mat);
}