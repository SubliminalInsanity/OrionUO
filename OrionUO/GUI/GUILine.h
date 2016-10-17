﻿/***********************************************************************************
**
** GUILine.h
**
** Компонента для отображения линии
**
** Copyright (C) August 2016 Hotride
**
************************************************************************************
*/
//----------------------------------------------------------------------------------
#ifndef GUILINE_H
#define GUILINE_H
//----------------------------------------------------------------------------------
#include "BaseGUI.h"
//----------------------------------------------------------------------------------
class CGUILine : public CBaseGUI
{
	//!Целевая координата по оси X
	SETGET(int, TargetX);

	//!Целевая координата по оси Y
	SETGET(int, TargetY);

	//!R-компонента цвета
	SETGET(uchar, ColorR);

	//!G-компонента цвета
	SETGET(uchar, ColorG);

	//!B-компонента цвета
	SETGET(uchar, ColorB);

	//!Значение альфа-канала
	SETGET(uchar, ColorA);

public:
	CGUILine(const int &x, const int &y, const int &targetX, const int &targetY, const uint &polygoneColor);
	virtual ~CGUILine();

	virtual void Draw(const bool &checktrans = false);
};
//----------------------------------------------------------------------------------
#endif
//----------------------------------------------------------------------------------
