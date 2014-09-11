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

	D3DXMatrixTranslation(&_mCenterMesh, -vCenter.x, -vCenter.y, -vCenter.z);
	D3DXMATRIXA16 m;
	D3DXMatrixRotationY(&m, D3DX_PI);
	_mCenterMesh *= m;
	D3DXMatrixRotationX(&m, D3DX_PI / 2.0f);
	_mCenterMesh *= m;
	
	// Create our vertex input layout
	_shaderutil.SetShaderName(L"Shader\\SpecularMapping_2.fx", "SpecularMapping");
	_shaderutil.ShaderSetting(*pd3dDevice);
	// Load the mesh
	V_RETURN(_Mesh.Create(pd3dDevice, L"Model\\Sphere.sdkmesh", true));

	// Setup the camera's view parameters
	D3DXVECTOR3 vecEye(0.0f, 0.0f, -15.0f);
	D3DXVECTOR3 vecAt(0.0f, 0.0f, -0.0f);
	_camera.SetViewParams(&vecEye, &vecAt);
	_camera.SetRadius(fObjectRadius * 3.0f, fObjectRadius * 0.5f, fObjectRadius * 10.0f);

	return S_OK;
}

void TestApplication1::OnFrameRender(ID3D10Device* pd3dDevice, double fTime, float fElapsedTime, void* pUserContext)
{
	HRESULT hr;

	//Render
	ID3D10EffectTechnique* pRenderTechnique;
	D3D10_TECHNIQUE_DESC techDesc;
	pRenderTechnique = _shaderutil.GetTechnique();
	pRenderTechnique->GetDesc(&techDesc);
	SDKMESH_SUBSET* pSubset = NULL;
	ID3D10ShaderResourceView* pDiffuseRV = NULL;
	D3D10_PRIMITIVE_TOPOLOGY PrimType;

	D3DXMATRIX mWorldViewProjection;
	//D3DXVECTOR3 vLightDir[MAX_LIGHTS];
	//D3DXVECTOR4 vLightDiffuse[MAX_LIGHTS];
	D3DXMATRIX mWorld;
	D3DXMATRIX mView;
	D3DXMATRIX mProj;

	// Get the projection & view matrix from the camera class
	mWorld = _mCenterMesh * *_camera.GetWorldMatrix();
	mProj = *_camera.GetProjMatrix();
	mView = *_camera.GetViewMatrix();

	mWorldViewProjection = mWorld * mView * mProj;

	_shaderutil.SetWorldMatrix(mWorld);
	_shaderutil.SetViewMatrix(mView);
	_shaderutil.SetProjectionMatrix(mProj);

	for (UINT p = 0; p < techDesc.Passes; ++p)
	{
		for (UINT subset = 0; subset < _Mesh.GetNumSubsets(0); ++subset)
		{
			// Get the subset
			pSubset = _Mesh.GetSubset(0, subset);

			PrimType = CDXUTSDKMesh::GetPrimitiveType10((SDKMESH_PRIMITIVE_TYPE)pSubset->PrimitiveType);
			pd3dDevice->IASetPrimitiveTopology(PrimType);

			//pDiffuseRV = _Mesh.GetMaterial(pSubset->MaterialID)->pDiffuseRV10;
			//g_ptxDiffuse->SetResource(pDiffuseRV);

			pRenderTechnique->GetPassByIndex(p)->Apply(0);
			pd3dDevice->DrawIndexed((UINT)pSubset->IndexCount, 0, (UINT)pSubset->VertexStart);
		}
	}
}
