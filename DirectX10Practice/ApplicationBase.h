#pragma once
#include "DXUT.h"



class ApplicationBase
{
public:
	ApplicationBase();
	~ApplicationBase();

	virtual bool DeviceAcceptable(UINT Adapter, UINT Output, D3D10_DRIVER_TYPE DeviceType,
		DXGI_FORMAT BackBufferFormat, bool bWindowed, void* pUserContext);
	virtual bool ModifyDeviceSettings(DXUTDeviceSettings* pDeviceSettings, void* pUserContext);
	virtual HRESULT OnCreateDevice(ID3D10Device* pd3dDevice, const DXGI_SURFACE_DESC* pBackBufferSurfaceDesc,
		void* pUserContext);
	virtual HRESULT OnResizedSwapChain(ID3D10Device* pd3dDevice, IDXGISwapChain* pSwapChain,
		const DXGI_SURFACE_DESC* pBackBufferSurfaceDesc, void* pUserContext);
	virtual void OnReleasingSwapChain(void* pUserContext);

	virtual void OnFrameMove(double fTime, float fElapsedTime, void* pUserContext);
	virtual void OnFrameRender(ID3D10Device* pd3dDevice, double fTime, float fElapsedTime, void* pUserContext);
	virtual void OnDestroyDevice(void*);
	virtual LRESULT OnMsg(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam,
		bool* pbNoFurtherProcessing, void* pUserContext);
	virtual void OnKeyboard(UINT nChar, bool bKeyDown, bool bAltDown, void* pUserContext);
	virtual void OnMouse(bool bLeftButtonDown, bool bRightButtonDown, bool bMiddleButtonDown,
		bool bSideButton1Down, bool bSideButton2Down, int nMouseWheelDelta,
		int xPos, int yPos, void* pUserContext);
	virtual bool OnDeviceRemoved(void*);
};

