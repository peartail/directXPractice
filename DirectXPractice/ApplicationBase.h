#pragma once
#include "DXUT.h"

class ApplicationBase
{
public:
	ApplicationBase();
	~ApplicationBase();

public:
	virtual bool DeviceAcceptable(const CD3D11EnumAdapterInfo* , UINT , const CD3D11EnumDeviceInfo* , DXGI_FORMAT , bool , void * );
	virtual bool ModifyDeviceSettings(DXUTDeviceSettings*, void*);
	virtual HRESULT OnCreateDevice(ID3D11Device*, const DXGI_SURFACE_DESC*, void*);
	virtual HRESULT OnResizedSwapChain(ID3D11Device*, IDXGISwapChain*, const DXGI_SURFACE_DESC*, void*);
	virtual void OnFrameMove(double, float, void*);
	virtual void OnFrameRender(ID3D11Device*, ID3D11DeviceContext*, double, float, void*);
	virtual void OnReleasingSwapChain(void*);
	virtual void OnDestroyDevice(void*);
	virtual LRESULT OnMsg(HWND, UINT, WPARAM, LPARAM, bool*, void*);
	virtual void OnKeyboard(UINT, bool, bool, void*);
	virtual void OnMouse(bool, bool, bool, bool, bool, int, int, int, void*);
	virtual bool OnDeviceRemoved(void*);
};

