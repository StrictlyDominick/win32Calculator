//ControlIDDefines.h
#pragma once

#ifndef CONTROLIDDEFINES_H

//header define
#define CONTROLIDDEFINES_H

//edit boxes are 100 range
#define ID_EDIT 100

//static boxes are 300 range
#define ID_STATIC 300
//buttons are 200 range
#define ID_BUTTON0 200
#define ID_BUTTON1 201
#define ID_BUTTON2 202
#define ID_BUTTON3 203
#define ID_BUTTON4 204
#define ID_BUTTON5 205
#define ID_BUTTON6 206
#define ID_BUTTON7 207
#define ID_BUTTON8 208
#define ID_BUTTON9 209
#define ID_BUTTONDOT 210
#define ID_BUTTONCLEAR 211
#define ID_BUTTONDEL 212
#define ID_BUTTONPLUS 213
#define ID_BUTTONMINUS 214
#define ID_BUTTONMULTI 215
#define ID_BUTTONDIVISION 216
#define ID_BUTTONLPARENTHESIS 217
#define ID_BUTTONRPARENTHESIS 218
#define ID_BUTTONEQUAL 219

//menus is 1 parenthesis
#define ID_MENU 1

class Defines
{
public:
	static LPCSTR IDtoLPCSTR(int ID)
	{
		switch (ID)
		{
		case ID_BUTTON0:
			return TEXT("0");

		case ID_BUTTON1:
			return TEXT("1");

		case ID_BUTTON2:
			return TEXT("2");

		case ID_BUTTON3:
			return TEXT("3");

		case ID_BUTTON4:
			return TEXT("4");

		case ID_BUTTON5:
			return TEXT("5");

		case ID_BUTTON6:
			return TEXT("6");

		case ID_BUTTON7:
			return TEXT("7");

		case ID_BUTTON8:
			return TEXT("8");

		case ID_BUTTON9:
			return TEXT("9");

		case ID_BUTTONDOT:
			return TEXT(".");

		case ID_BUTTONMINUS:
			return TEXT("-");

		case ID_BUTTONPLUS:
			return TEXT("+");

		case ID_BUTTONMULTI:
			return TEXT("x");

		case ID_BUTTONDIVISION:
			return TEXT("÷");

		case ID_BUTTONEQUAL:
			return TEXT("=");

		case ID_BUTTONCLEAR:
			return TEXT("CL");

		case ID_BUTTONDEL:
			return TEXT("DEL");

		case ID_BUTTONLPARENTHESIS:
			return TEXT("(");

		case ID_BUTTONRPARENTHESIS:
			return TEXT(")");

		default:
			return "-1";

		}
	}
};
#endif // !CONTROLIDDEFINES.h

