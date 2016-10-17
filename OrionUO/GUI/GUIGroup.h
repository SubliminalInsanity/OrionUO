﻿/***********************************************************************************
**
** GUIGroup.h
**
** Компонента группы
**
** Copyright (C) August 2016 Hotride
**
************************************************************************************
*/
//----------------------------------------------------------------------------------
#ifndef GUIGROUP_H
#define GUIGROUP_H
//----------------------------------------------------------------------------------
#include "BaseGUI.h"
//----------------------------------------------------------------------------------
class CGUIGroup : public CBaseGUI
{
	//!Индекс группы. 0 - эквивалентно EndGroup
	SETGET(int, Index);

public:
	CGUIGroup(const int &index);
	virtual ~CGUIGroup();
};
//----------------------------------------------------------------------------------
#endif
//----------------------------------------------------------------------------------
