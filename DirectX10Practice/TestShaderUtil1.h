#pragma once
#include "common.h"

class TestShaderUtil1
{
private:
	std::wstring _shaderfile;
	std::string _vsmain;
	std::string _psmain;
	std::string _techniqueName;
	D3D10_INPUT_ELEMENT_DESC _layout[3];

	ID3D10EffectTechnique* _shaderTechnique;
	ID3D10Effect* _Effect10;
	
	ID3D10InputLayout* _vertexLayout;
public:
	TestShaderUtil1();
	~TestShaderUtil1();

	HRESULT ShaderSetting(ID3D10Device& pd3dDevice);
	void	SetShaderName(std::wstring shaderfile, std::string techniqueName);
	HRESULT SetVertexShader(std::string vsmain);
	HRESULT SetPixelShader(std::string psmain);
	HRESULT CompileShaderFromFile(std::wstring szFileName, LPCSTR szEntryPoint, LPCSTR szShaderModel, ID3DBlob** ppBlobOut);
};

