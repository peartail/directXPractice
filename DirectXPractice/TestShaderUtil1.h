#pragma once
#include "ShaderUtil.h"
#include "SDKmisc.h"

class TestShaderUtil1 :
	public ShaderUtil
{
private:
	ID3D11InputLayout* _vertexLayout;
	ID3D11VertexShader* _VertexShader;
	ID3D11PixelShader* _PixelShader;
	std::wstring _shaderfile;
	std::string _vsmain;
	std::string _psmain;
	D3D11_INPUT_ELEMENT_DESC* _layout;
public:
	TestShaderUtil1();
	~TestShaderUtil1();
	HRESULT ShaderSetting(ID3D11Device& pd3dDevice, ID3D11InputLayout* layout);
	void	SetShaderName(std::wstring shaderfile, std::string vsmain, std::string psmain);
	HRESULT SetVertexShader(std::string vsmain);
	HRESULT SetPixelShader(std::string psmain);
	HRESULT CompileShaderFromFile(std::wstring szFileName, LPCSTR szEntryPoint, LPCSTR szShaderModel, ID3DBlob** ppBlobOut);
};

