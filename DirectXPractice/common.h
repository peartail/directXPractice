#ifndef __COMMON_H__
#define __COMMON_H__

#include "DXUT.h"
#include "app_setting.h"

template<typename T>
struct VECTOR2
{
	T x;
	T y;
};

//#define iVECTOR2 VECTOR2<int>

enum MouseButtonDownType
{
	LEFT_BUTTON_DOWN = 1,
	RIGHT_BUTTON_DOWN = 2,
	MIDDLE_BUTTON_DOWN = 4,
	SIDE_BUTTON_DOWN = 8,
	SIDE_2_BUTTON_DOWN = 16,
};

struct sMouseEvent
{
	bool isLeftButtonDown;
	bool isRightButtonDown;
	bool isMiddleButtonDown;
	bool isSide1ButtonDown;
	bool isSide2ButtonDown;
	int MouseWheelDelta;
	VECTOR2<int> mpos;
};

#endif