﻿/***********************************************************************************
**
** GumpQuestion.cpp
**
** Copyright (C) August 2016 Hotride
**
************************************************************************************
*/
//----------------------------------------------------------------------------------
#include "GumpQuestion.h"
#include "../OrionUO.h"
#include "../Managers/GumpManager.h"
#include "../Screen stages/GameScreen.h"
//----------------------------------------------------------------------------------
CGumpQuestion::CGumpQuestion(uint serial, short x, short y, uchar variant)
: CGump(GT_QUESTION, serial, x, y), m_Variant(variant)
{
	m_Blocked = true;
	g_GrayMenuCount++;

	Add(new CGUIGumppic(0x0816, 0, 0));

	CGUIText *obj = (CGUIText*)Add(new CGUIText(0x0386, 33, 30));

	if (m_Variant == ID_GQ_STATE_QUIT)
		obj->CreateTextureA(1, "Quit\nUltima Online?");
	else if (m_Variant == ID_GQ_STATE_ATTACK_REQUEST)
		obj->CreateTextureA(1, "This may flag\nyou criminal!");

	Add(new CGUIButton(ID_GQ_BUTTON_CANCEL, 0x0817, 0x0819, 0x0818, 37, 75));
	Add(new CGUIButton(ID_GQ_BUTTON_OKAY, 0x081A, 0x081C, 0x081B, 100, 75));
}
//----------------------------------------------------------------------------------
CGumpQuestion::~CGumpQuestion()
{
}
//----------------------------------------------------------------------------
void CGumpQuestion::GUMP_BUTTON_EVENT_C
{
	if (serial == ID_GQ_BUTTON_CANCEL) //Button cancel
		m_RemoveMark = true;
	else if (serial == ID_GQ_BUTTON_OKAY) //Button okay
	{
		if (m_Variant == ID_GQ_STATE_QUIT)
			g_GameScreen.CreateSmoothAction(CGameScreen::ID_SMOOTH_GS_LOGOUT);
		else if (m_Variant == ID_GQ_STATE_ATTACK_REQUEST)
		{
			g_Orion.AttackReq(m_ID);
			m_RemoveMark = true;
		}
	}
}
//---------------------------------------------------------------------------