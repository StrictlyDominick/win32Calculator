/********************************************************************
							BUTTONS_H
								By
							StrictlyDominick
**********************************************************************/

#pragma once
#ifndef BUTTONS_H

#include <Windows.h>
#include "ControlIDDefines.h"
#include "MathParser.h"

struct xyButton { int x; int y; int width; int height; };

class BUTTONS
{
public:

	class CREATE
	{
	public:
		xyButton NumButtonsDetails[20] = {
											{ 58,321,55,50 },
											{ 1,269,55,50 },
											{ 58,269,55,50 },
											{ 115,269,55,50 },
											{ 1,217,55,50 },
											{ 58,217,55,50 },
											{ 115,217,55,50 },
											{ 1,165,55,50 },
											{ 58,165,55,50 },
											{ 115,165,55,50 },
											{ 115,321,55,50 }, //DOT
											{ 1,321,55,50 },   //CELAR
											{ 115,113,55,50 }, //DEL
											{ 172,269,55,50 }, //PLUS
											{ 172,217,55,50 }, //MINUS
											{ 172,165,55,50 }, //MULTI
											{ 172,113,55,50 }, //DIVISION
											{ 1,113,55,50 },   //LPARENTHESIS
											{ 58,113,55,50 },  //RPARENTHESIS
											{ 172,321,55,50 }  //EQUAL
										 };

		//Constructor:
		//When parent class BUTTONS is initialize its constructor sends in '*this'
		//to 'parentAddress'. This will allow BUTTONS object 'parentClass' to have
		//access to parent class BUTTONS members. 'parentClass' is used in every
		//function in class CREATE.
		CREATE(BUTTONS& parentAddress) : parentClass(parentAddress) {}

		//Will initialize and create all control buttons for the application,
		//starting with ID_BUTTONEQUAL. Will create all buttons starting
		//from top of window and each row from left to right. Also responsible
		//for setting object's parent window handle variable 'parentHwnd'
		//Postcondition:	Will create all buttons in application window. Also
		//					calls setparentHwnd() to set parent handle to object
		//Precondition:		Calls the following member functions indirectly using
		//					reference variable parentClass:
		//					CREATE:  ButtonLPARENTHESIS(), ButtonRPARENTHESIS()
		//							 ButtonDEL, ButtonDIVISION(), Button7(),
		//							 Button8(), BUtton9(), ButtonMULTI(),
		//							 Button4(), Button5(), Button6(), ButtonMINUS(),
		//							 Button1(), Button2(), Button3(), ButtonPLUS(),
		//							 ButtonCLEAR(), Button0(), ButtonDOT(), ButtonEQUAL()
		//					BUTTONS: getButtonEqual(), setparentHwnd()
		bool All(HWND parenthwnd);

		bool Button(int buttonID, HWND parenthwnd);

		private:
			BUTTONS & parentClass;
	};

	class CLICKED
	{
	public:
		//Constructor:
		//When parent class BUTTONS is initialize its constructor sends in '*this'
		//to 'parentAddress'. This will allow BUTTONS object 'parentClass' to have
		//access to parent class BUTTONS members. 'parentClass' is used in every
		//function in class CLICKED.
		CLICKED(BUTTONS& parentAddress) : parentClass(parentAddress) {}

		//Updates ID_EDIT to text value of button clicked. Numbers(int) handles buttons
		//0-9 and the '.' button, not math operators. When there is only a zero
		//value will be replaced by text value of 'buttonID'. When there contains a 
		//text value 'buttonID''s text value will be appended to string. If the last
		//button to be clicked was a math operator than ID_EDIT text will clear and 
		//be replaced with the text value of 'buttonID'
		//Postcondition:	ID_EDIT text field will be updated by appending new char
		//					or by replacing the text field with the new char. The 
		//					parent window will receive keyboard focus.
		//Precondition:		The following member functions are used:
		//					BUTTONS: getparentHwnd(), setiLastButtonClicked()
		//					ControlIDDefines: Defines::IDtoLPCSTR()
		//					Windows.h: FindWindowEx(), GetWindowLength(),
		//							   SetWindowText()
		bool Numbers(int buttonID);

		//Clears ID_EDIT and ID_STATIC text fields. ID_EDIT text field will be 
		//cleared to '0' while ID_STATIC will contain nothing but a null terminating
		//string character
		//Postcondition:	ID_EDIT text field will be changed to '0'. ID_STATIC will
		//					be changed to '\0'. Calling object will have its iLastButtonClicked
		//					value updated
		//Precondition:		The following member functions will be called:
		//					Windows.h: SetFocus(), SetWindowText(), GetDlgItem()
		//					BUTTONS: getparentHwnd(), setiLastButtonClicked()
		bool CLR();

		//Deletes the last char in the text field for ID_EDIT. If the
		//text field contains only a single char than its set to '0'.
		//Postcondition:	Deletes last char in ID_EDIT text field.
		//					If text field is a single char that its set
		//					to '0'. Also switches keyboard focus to
		//					parent window.
		//Precondition:		The following member functions are called:
		//					Windows.h: FindWindowEx(), SetFocus(),
		//							   GetWindowTextLength(), GetWindowText(),
		//							   SetWindowText(),
		//					BUTTONS:   getparentHwnd(), setiLastButtonClicked()
		bool DEL();

		//When buttons 213-218 (see ControlIDDefines.h) is clicked both ID_EDIT and
		//ID_STATIC text fields will be updated. ID_STATIC text field will be changed
		//differently depending if its the first math operator clicked or if
		//ID_BUTTONLPARENTHESIS or ID_BUTTONRPARENTHESIS is clicked. In both cases
		//ID_STATIC will be updated with the char that matches the math operator
		//clicked. ID_EDIT will stay the same is unless ID_BUTTONRPARENTHESIS is
		//clicked; in which case ID_EDIT text field is set to '0'. Any other math
		//operator leaves the current value in ID__EDIT but sets iLastButtonClicked
		//variable in BUTTONS object. This will cause the text field to be reset to
		//the next entered number.
		//Postcondition:	ID_STATIC is updated with math operator included. If
		//					ID_BUTTONRPARENTHESIS is selected than ID_EDIT will 
		//					change to '0' as well. Parent window will receive 
		//					the keyboard focus.
		//Precondition:		The following member functions are called:
		//					BUTTONS:	getparentHwnd(), setiLastButtonClicked(),
		//					Windows.h:	SetFocus(), GetDlgItem(), GetWindowTextLength(),
		//								GetWindowText(), SetWindowText()
		//					ControlIDDefines:	Defines::IDtoLPCSTR()
		bool MathOperator(int buttonID);

		bool Equal();

	private:
		BUTTONS & parentClass;
	};

	//Constructor:
	//When BUTTONS object is created it must take the reference to the object
	//pass it along to the member classes. The member classes uses this to call
	//functions from the parent class. Without these constructor classes 'Clicked'
	//and 'Create' won't work. They rely on being able to access object's BUTTON
	//member functions.
	BUTTONS() : Create(*this), Clicked(*this) {}

	//Retrieves WxL dimensions of control button 'windowName' and 
	//stores in 'width' and 'length' members of 'xyButton' structure.
	//In addition, it will retrieve x and y coordinates, relative to parent's
	//client window; storing them in 'x' and 'y' members of structure
	//'xyButton'. 'xyButton' is then returned.
	//Postcondition:	Returns xyButtons structure for the 'windowName' 
	//					control button.
	//Precondition :	Uses following functions from <windows.h>:
	//					GetClientRect(), MapWindowPoints(), FindWindowEx()
	xyButton getButtonDimensions(HWND parentHandle, LPCSTR windowName) const;

	CREATE Create;

	CLICKED Clicked;

	//---------------------------------------
	//---------------------------------------
	//Get Functions: Contains only a single
	//	line of code returning the value. All
	//	get functions more complex must be
	//	commented separately.
	//---------------------------------------
	//---------------------------------------
	HWND getparentHwnd() const;

	bool getButtonCreated(int buttonID) const;

	int getiLastButtontClicked() const;

	//---------------------------------------
	//---------------------------------------
	//Set Functions: Contains only a single
	//	line of code setting the value. All
	//	set functions more complex must be
	//	commented separately.
	//---------------------------------------
	//---------------------------------------
	void setparentHwnd(HWND theParentHandle);

	void setButtonCreated(int button_to_set, bool value);

	bool setiLastButtonClicked(int buttonID);

private:
	HWND parentHwnd;

	bool bButton0 = false;
	bool bButton1 = false;
	bool bButton2 = false;
	bool bButton3 = false;
	bool bButton4 = false;
	bool bButton5 = false;
	bool bButton6 = false;
	bool bButton7 = false;
	bool bButton8 = false;
	bool bButton9 = false;
	bool bButtonMINUS = false;
	bool bButtonPLUS = false;
	bool bButtonMULTI = false;
	bool bButtonDIVISION = false;
	bool bButtonDOT = false;
	bool bButtonEQUAL = false;
	bool bButtonCLEAR = false;
	bool bButtonDEL = false;
	bool bButtonLPARENTHESIS = false;
	bool bButtonRPARENTHESIS = false;

	int iLastButtonClicked;
};


#endif // !BUTTONS_H



