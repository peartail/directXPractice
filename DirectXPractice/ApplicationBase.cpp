#include "DXUT.h"
#include "ApplicationBase.h"


ApplicationBase::ApplicationBase()
{
}


ApplicationBase::~ApplicationBase()
{
}

bool ApplicationBase::DeviceAcceptable(const CD3D11EnumAdapterInfo* adtInfo, UINT output, const CD3D11EnumDeviceInfo* deviceInfo, DXGI_FORMAT backbufferformat, bool bWindowsed, void *puserContext)
{
	return true;
}

bool ApplicationBase::ModifyDeviceSettings(DXUTDeviceSettings* pDeviceSettings, void* pUserContext)
{
	return true;
}

HRESULT ApplicationBase::OnCreateDevice(ID3D11Device* pd3dDevice, const DXGI_SURFACE_DESC* pBackBufferSurfaceDesc,
	void* pUserContext)
{

	return S_OK;
}

HRESULT ApplicationBase::OnResizedSwapChain(ID3D11Device* pd3dDevice, IDXGISwapChain* pSwapChain,
	const DXGI_SURFACE_DESC* pBackBufferSurfaceDesc, void* pUserContext)
{

	return S_OK;
}

void ApplicationBase::OnFrameMove(double fTime, float fElapsedTime, void* pUserContext)
{

}


//--------------------------------------------------------------------------------------
// Render the scene using the D3D11 device
//--------------------------------------------------------------------------------------
void ApplicationBase::OnFrameRender(ID3D11Device* pd3dDevice, ID3D11DeviceContext* pd3dImmediateContext,
	double fTime, float fElapsedTime, void* pUserContext)
{

}


//--------------------------------------------------------------------------------------
// Release D3D11 resources created in OnD3D11ResizedSwapChain 
//--------------------------------------------------------------------------------------
void ApplicationBase::OnReleasingSwapChain(void* pUserContext)
{

}


//--------------------------------------------------------------------------------------
// Release D3D11 resources created in OnD3D11CreateDevice 
//--------------------------------------------------------------------------------------
void ApplicationBase::OnDestroyDevice(void* pUserContext)
{

}


//--------------------------------------------------------------------------------------
// Handle messages to the application
//--------------------------------------------------------------------------------------
LRESULT ApplicationBase::OnMsg(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam,
	bool* pbNoFurtherProcessing, void* pUserContext)
{

	return 0;
}


//--------------------------------------------------------------------------------------
// Handle key presses
//--------------------------------------------------------------------------------------
void ApplicationBase::OnKeyboard(UINT nChar, bool bKeyDown, bool bAltDown, void* pUserContext)
{

}


//--------------------------------------------------------------------------------------
// Handle mouse button presses
//--------------------------------------------------------------------------------------
void ApplicationBase::OnMouse(bool bLeftButtonDown, bool bRightButtonDown, bool bMiddleButtonDown,
	bool bSideButton1Down, bool bSideButton2Down, int nMouseWheelDelta,
	int xPos, int yPos, void* pUserContext)
{

}


//--------------------------------------------------------------------------------------
// Call if device was removed.  Return true to find a new device, false to quit
//--------------------------------------------------------------------------------------
bool ApplicationBase::OnDeviceRemoved(void* pUserContext)
{

	return true;
}
