/********************************************************************
							BUTTONS_H
								By
							ProfoundDisputes
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

		//Creates '0' (ID_BUTTON0) button on the calculator. ID_BUTTONEQUAL is required
		//to be created before hand. The position/size is based off of ID_BUTTONEQUAL. 
		//This function will test to ensure that ID_BUTTONEQUAL has been created before
		//attempting to create button. After ID_BUTTON0 has been created it will set
		//bButton0 as true. Function will return 'true' if successful.
		//PostCondition:	ID_BUTTON0 will be create in the parent window. bButton0
		//					will be set to true if successful. Function will return true
		//					if successful and false if unsuccessful.
		//PreCondition :	ID_BUTTONEQUAL must be created before calling function.
		//					The following member functions are used:
		//					BUTTONS:    getButtonDimensions(), setButton0(), getButtonEQUAL()
		//					ControlIDDefines: IDtoLPCSTR()
		//					<windows.h> HWND, CreateWindowEx()
		bool Button0(HWND parenthwnd);

		//Creates '1' (ID_BUTTON1) button on the calculator. ID_BUTTONEQUAL is required
		//to be created before hand. The position/size is based off of ID_BUTTONEQUAL. 
		//This function will test to ensure that ID_BUTTONEQUAL has been created before
		//attempting to create button. After ID_BUTTON1 has been created it will set
		//bButton1 as true. Function will return 'true' if successful.
		//PostCondition:	ID_BUTTON1 will be create in the parent window. bButton1
		//					will be set to true if successful. Function will return true
		//					if successful and false if unsuccessful.
		//PreCondition :	ID_BUTTONEQUAL must be created before calling function.
		//					The following member functions are used:
		//					BUTTONS:  getButtonDimensions(), getButtonEQUAL(), setButton1()
		//					ControlIDDefines: IDtoLPCSTR()
		//					<windows.h> HWND, CreateWindowEx()
		bool Button1(HWND parenthwnd);

		//Creates '2' (ID_BUTTON2) button on the calculator. ID_BUTTONEQUAL is required
		//to be created before hand. The position/size is based off of ID_BUTTONEQUAL. 
		//This function will test to ensure that ID_BUTTONEQUAL has been created before
		//attempting to create button. After ID_BUTTON2 has been created it will set
		//bButton2 as true. Function will return 'true' if successful.
		//PostCondition:	ID_BUTTON2 will be create in the parent window. bButton2
		//					will be set to true if successful. Function will return true
		//					if successful and false if unsuccessful.
		//PreCondition :	ID_BUTTONEQUAL must be created before calling function.
		//					The following member functions are used:
		//					BUTTONS:  getButtonDimensions(), getButtonEQUAL(), setButton2()
		//					ControlIDDefines: IDtoLPCSTR()
		//					<windows.h> HWND, CreateWindowEx()
		bool Button2(HWND parenthwnd);

		//Creates '3' (ID_BUTTON3) button on the calculator. ID_BUTTONEQUAL is required
		//to be created before hand. The position/size is based off of ID_BUTTONEQUAL. 
		//This function will test to ensure that ID_BUTTONEQUAL has been created before
		//attempting to create button. After ID_BUTTON3 has been created it will set
		//bButton3 as true. Function will return 'true' if successful.
		//PostCondition:	ID_BUTTON3 will be create in the parent window. bButton3
		//					will be set to true if successful. Function will return true
		//					if successful and false if unsuccessful.
		//PreCondition :	ID_BUTTONEQUAL must be created before calling function.
		//					The following member functions are used:
		//					BUTTONS:  getButtonDimensions(), getButtonEQUAL(), setButton3()
		//					ControlIDDefines: IDtoLPCSTR()
		//					<windows.h> HWND, CreateWindowEx()
		bool Button3(HWND parenthwnd);

		//Creates '4' (ID_BUTTON4) button on the calculator. ID_BUTTONEQUAL is required
		//to be created before hand. The position/size is based off of ID_BUTTONEQUAL. 
		//This function will test to ensure that ID_BUTTONEQUAL has been created before
		//attempting to create button. After ID_BUTTON4 has been created it will set
		//bButton4 as true. Function will return 'true' if successful.
		//PostCondition:	ID_BUTTON4 will be create in the parent window. bButton4
		//					will be set to true if successful. Function will return true
		//					if successful and false if unsuccessful.
		//PreCondition :	ID_BUTTONEQUAL must be created before calling function.
		//					The following member functions are used:
		//					BUTTONS:  getButtonDimensions(), getButtonEQUAL(), setButton4()
		//					ControlIDDefines: IDtoLPCSTR()
		//					<windows.h> HWND, CreateWindowEx()
		bool Button4(HWND parenthwnd);

		//Creates '5' (ID_BUTTON5) button on the calculator. ID_BUTTONEQUAL is required
		//to be created before hand. The position/size is based off of ID_BUTTONEQUAL. 
		//This function will test to ensure that ID_BUTTONEQUAL has been created before
		//attempting to create button. After ID_BUTTON5 has been created it will set
		//bButton5 as true. Function will return 'true' if successful.
		//PostCondition:	ID_BUTTON5 will be create in the parent window. bButton5
		//					will be set to true if successful. Function will return true
		//					if successful and false if unsuccessful.
		//PreCondition :	ID_BUTTONEQUAL must be created before calling function.
		//					The following member functions are used:
		//					BUTTONS:  getButtonDimensions(), getButtonEQUAL(), setButton5()
		//					ControlIDDefines: IDtoLPCSTR()
		//					<windows.h> HWND, CreateWindowEx()
		bool Button5(HWND parenthwnd);

		//Creates '6' (ID_BUTTON6) button on the calculator. ID_BUTTONEQUAL is required
		//to be created before hand. The position/size is based off of ID_BUTTONEQUAL. 
		//This function will test to ensure that ID_BUTTONEQUAL has been created before
		//attempting to create button. After ID_BUTTON6 has been created it will set
		//bButton6 as true. Function will return 'true' if successful.
		//PostCondition:	ID_BUTTON6 will be create in the parent window. bButton6
		//					will be set to true if successful. Function will return true
		//					if successful and false if unsuccessful.
		//PreCondition :	ID_BUTTONEQUAL must be created before calling function.
		//					The following member functions are used:
		//					BUTTONS:  getButtonDimensions(), getButtonEQUAL(), setButton6()
		//					ControlIDDefines: IDtoLPCSTR()
		//					<windows.h> HWND, CreateWindowEx()
		bool Button6(HWND parenthwnd);

		//Creates '7' (ID_BUTTON7) button on the calculator. ID_BUTTONEQUAL is required
		//to be created before hand. The position/size is based off of ID_BUTTONEQUAL. 
		//This function will test to ensure that ID_BUTTONEQUAL has been created before
		//attempting to create button. After ID_BUTTON7 has been created it will set
		//bButton7 as true. Function will return 'true' if successful.
		//PostCondition:	ID_BUTTON7 will be create in the parent window. bButton7
		//					will be set to true if successful. Function will return true
		//					if successful and false if unsuccessful.
		//PreCondition :	ID_BUTTONEQUAL must be created before calling function.
		//					The following member functions are used:
		//					BUTTONS:  getButtonDimensions(), getButtonEQUAL(), setButton7()
		//					ControlIDDefines: IDtoLPCSTR()
		//					<windows.h> HWND, CreateWindowEx()
		bool Button7(HWND parenthwnd);

		//Creates '8' (ID_BUTTON8) button on the calculator. ID_BUTTONEQUAL is required
		//to be created before hand. The position/size is based off of ID_BUTTONEQUAL. 
		//This function will test to ensure that ID_BUTTONEQUAL has been created before
		//attempting to create button. After ID_BUTTON8 has been created it will set
		//bButton8 as true. Function will return 'true' if successful.
		//PostCondition:	ID_BUTTON8 will be create in the parent window. bButton8
		//					will be set to true if successful. Function will return true
		//					if successful and false if unsuccessful.
		//PreCondition :	ID_BUTTONEQUAL must be created before calling function.
		//					The following member functions are used:
		//					BUTTONS:  getButtonDimensions(), getButtonEQUAL(), setButton8()
		//					ControlIDDefines: IDtoLPCSTR()
		//					<windows.h> HWND, CreateWindowEx()
		bool Button8(HWND parenthwnd);

		//Creates '9' (ID_BUTTON9) button on the calculator. ID_BUTTONEQUAL is required
		//to be created before hand. The position/size is based off of ID_BUTTONEQUAL. 
		//This function will test to ensure that ID_BUTTONEQUAL has been created before
		//attempting to create button. After ID_BUTTON9 has been created it will set
		//bButton9 as true. Function will return 'true' if successful.
		//PostCondition:	ID_BUTTON9 will be create in the parent window. bButton9
		//					will be set to true if successful. Function will return true
		//					if successful and false if unsuccessful.
		//PreCondition :	ID_BUTTONEQUAL must be created before calling function.
		//					The following member functions are used:
		//					BUTTONS:  getButtonDimensions(), getButtonEQUAL(), setButton9()
		//					ControlIDDefines: IDtoLPCSTR()
		//					<windows.h> HWND, CreateWindowEx()
		bool Button9(HWND parenthwnd);

		//Creates '.' (ID_BUTTONDOT) button on the calculator. ID_BUTTONEQUAL is required
		//to be created before hand. The position/size is based off of ID_BUTTONEQUAL. 
		//This function will test to ensure that ID_BUTTONEQUAL has been created before
		//attempting to create button. After ID_BUTTONDOT has been created it will set
		//bButtonDOT as true. Function will return 'true' if successful.
		//PostCondition:	ID_BUTTONDOT will be create in the parent window. bButtonDOT
		//					will be set to true if successful. Function will return true
		//					if successful and false if unsuccessful.
		//PreCondition :	ID_BUTTONEQUAL must be created before calling function.
		//					The following member functions are used:
		//					BUTTONS:  getButtonDimensions(), getButtonEQUAL(), setButtonDOT()
		//					ControlIDDefines: IDtoLPCSTR()
		//					<windows.h> HWND, CreateWindowEx()
		bool ButtonDOT(HWND parenthwnd);

		//Creates 'CL' (ID_BUTTON0) button on the calculator. ID_BUTTONEQUAL is required
		//to be created before hand. The position/size is based off of ID_BUTTONEQUAL. 
		//This function will test to ensure that ID_BUTTONEQUAL has been created before
		//attempting to create button. After ID_BUTTON0 has been created it will set
		//bbuttonCLEAR as true. Function will return 'true' if successful.
		//PostCondition:	ID_BUTTON0 will be create in the parent window. bbuttonCLEAR
		//					will be set to true if successful. Function will return true
		//					if successful and false if unsuccessful.
		//PreCondition :	ID_BUTTONEQUAL must be created before calling function.
		//					The following member functions are used:
		//					BUTTONS:  getButtonDimensions(), getButtonEQUAL(), setbuttonCLEAR()
		//					ControlIDDefines: IDtoLPCSTR()
		//					<windows.h> HWND, CreateWindowEx()
		bool ButtonCLEAR(HWND parenthwnd);

		//Creates 'DEL' (ID_BUTTONDEL) button on the calculator. ID_BUTTONEQUAL is required
		//to be created before hand. The position/size is based off of ID_BUTTONEQUAL. 
		//This function will test to ensure that ID_BUTTONEQUAL has been created before
		//attempting to create button. After ID_BUTTONDEL has been created it will set
		//bButtonDEL as true. Function will return 'true' if successful.
		//PostCondition:	ID_BUTTONDEL will be create in the parent window. bButtonDEL
		//					will be set to true if successful. Function will return true
		//					if successful and false if unsuccessful.
		//PreCondition :	ID_BUTTONEQUAL must be created before calling function.
		//					The following member functions are used:
		//					BUTTONS:  getButtonDimensions(), getButtonEQUAL(), setButtonDEL()
		//					ControlIDDefines: IDtoLPCSTR()
		//					<windows.h> HWND, CreateWindowEx()
		bool ButtonDEL(HWND parenthwnd);

		//Creates '-' (ID_BUTTONMINUS) button on the calculator. ID_BUTTONEQUAL is required
		//to be created before hand. The position/size is based off of ID_BUTTONEQUAL. 
		//This function will test to ensure that ID_BUTTONEQUAL has been created before
		//attempting to create button. After ID_BUTTONMINUS has been created it will set
		//bButtonMINUS as true. Function will return 'true' if successful.
		//PostCondition:	ID_BUTTONMINUS will be create in the parent window. bButtonMINUS
		//					will be set to true if successful. Function will return true
		//					if successful and false if unsuccessful.
		//PreCondition :	ID_BUTTONEQUAL must be created before calling function.
		//					The following member functions are used:
		//					BUTTONS:  getButtonDimensions(), getButtonEQUAL(), setButtonMINUS()
		//					ControlIDDefines: IDtoLPCSTR()
		//					<windows.h> HWND, CreateWindowEx()
		bool ButtonMINUS(HWND parenthwnd);

		//Creates '+' (ID_BUTTONPLUS) button on the calculator. ID_BUTTONEQUAL is required
		//to be created before hand. The position/size is based off of ID_BUTTONEQUAL. 
		//This function will test to ensure that ID_BUTTONEQUAL has been created before
		//attempting to create button. After ID_BUTTONPLUS has been created it will set
		//bButtonPLUS as true. Function will return 'true' if successful.
		//PostCondition:	ID_BUTTONPLUS will be create in the parent window. bButtonPLUS
		//					will be set to true if successful. Function will return true
		//					if successful and false if unsuccessful.
		//PreCondition :	ID_BUTTONEQUAL must be created before calling function.
		//					The following member functions are used:
		//					BUTTONS:  getButtonDimensions(), getButtonEQUAL(), setButtonPLUS()
		//					ControlIDDefines: IDtoLPCSTR()
		//					<windows.h> HWND, CreateWindowEx()
		bool ButtonPLUS(HWND parenthwnd);

		//Creates 'X' (ID_BUTTONMULTI) button on the calculator. ID_BUTTONEQUAL is required
		//to be created before hand. The position/size is based off of ID_BUTTONEQUAL. 
		//This function will test to ensure that ID_BUTTONEQUAL has been created before
		//attempting to create button. After ID_BUTTONMULTI has been created it will set
		//bButtonMULTI as true. Function will return 'true' if successful.
		//PostCondition:	ID_BUTTONMULTI will be create in the parent window. bButtonMULTI
		//					will be set to true if successful. Function will return true
		//					if successful and false if unsuccessful.
		//PreCondition :	ID_BUTTONEQUAL must be created before calling function.
		//					The following member functions are used:
		//					BUTTONS:  getButtonDimensions(), getButtonEQUAL(), setButtonMULTI()
		//					ControlIDDefines: IDtoLPCSTR()
		//					<windows.h> HWND, CreateWindowEx()
		bool ButtonMULTI(HWND parenthwnd);

		//Creates '÷' (ID_BUTTONDIVISION) button on the calculator. ID_BUTTONEQUAL is required
		//to be created before hand. The position/size is based off of ID_BUTTONEQUAL. 
		//This function will test to ensure that ID_BUTTONEQUAL has been created before
		//attempting to create button. After ID_BUTTONDIVISION has been created it will set
		//bButtonDIVISION as true. Function will return 'true' if successful.
		//PostCondition:	ID_BUTTONDIVISION will be create in the parent window. bButtonDIVISION
		//					will be set to true if successful. Function will return true
		//					if successful and false if unsuccessful.
		//PreCondition :	ID_BUTTONEQUAL must be created before calling function.
		//					The following member functions are used:
		//					BUTTONS:  getButtonDimensions(), getButtonEQUAL(), setButtonDIVISION()
		//					ControlIDDefines: IDtoLPCSTR()
		//					<windows.h> HWND, CreateWindowEx()
		bool ButtonDIVISION(HWND parenthwnd);

		//Creates '=' (ID_BUTTONEQUAL) button on the calculator. ID_BUTTONEQUAL is used
		//for all control button creations. Call this function first before
		//attempting to create any other buttons. After ID_BUTTONEQUAL has been created
		//it will set. bButtonEQUAL as true. Function will return 'true' if successful.
		//PostCondition:	ID_BUTTONEQUAL will be create in the parent window. bButtonEQUAL
		//					will be set to true if successful. Function will return true
		//					if successful and false if unsuccessful.
		//PreCondition :	The following member functions are used:
		//					BUTTONS:  setButtonEQUAL()
		//					ControlIDDefines: IDtoLPCSTR()
		//					<windows.h> HWND, CreateWindowEx(), GetClientRect()
		bool ButtonEQUAL(HWND parenthwnd);

		//Creates '(' (ID_BUTTONLPARENTHESIS) button on the calculator. ID_BUTTONEQUAL is required
		//to be created before hand. The position/size is based off of ID_BUTTONEQUAL. 
		//This function will test to ensure that ID_BUTTONEQUAL has been created before
		//attempting to create button. After ID_BUTTONLPARENTHESIS has been created it will set
		//bButtonLPARENTHESIS as true. Function will return 'true' if successful.
		//PostCondition:	ID_BUTTONLPARENTHESIS will be create in the parent window. bButtonLPARENTHESIS
		//					will be set to true if successful. Function will return true
		//					if successful and false if unsuccessful.
		//PreCondition :	ID_BUTTONEQUAL must be created before calling function.
		//					The following member functions are used:
		//					BUTTONS:  getButtonDimensions(), getButtonEQUAL(), setButtonLPARENTHESIS()
		//					ControlIDDefines: IDtoLPCSTR()
		//					<windows.h> HWND, CreateWindowEx()
		bool ButtonLPARENTHESIS(HWND parenthwnd);

		//Creates ')' (ID_BUTTONRPARENTHESIS) button on the calculator. ID_BUTTONEQUAL is required
		//to be created before hand. The position/size is based off of ID_BUTTONEQUAL. 
		//This function will test to ensure that ID_BUTTONEQUAL has been created before
		//attempting to create button. After ID_BUTTONRPARENTHESIS has been created it will set
		//bButtonRPARENTHESIS as true. Function will return 'true' if successful.
		//PostCondition:	ID_BUTTONRPARENTHESIS will be create in the parent window. bButtonRPARENTHESIS
		//					will be set to true if successful. Function will return true
		//					if successful and false if unsuccessful.
		//PreCondition :	ID_BUTTONEQUAL must be created before calling function.
		//					The following member functions are used:
		//					BUTTONS:  getButtonDimensions(), getButtonEQUAL(), setButtonRPARENTHESIS()
		//					ControlIDDefines: IDtoLPCSTR()
		//					<windows.h> HWND, CreateWindowEx()
		bool ButtonRPARENTHESIS(HWND parenthwnd);

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

	bool getButton0() const;
	bool getButton1() const;
	bool getButton2() const;
	bool getButton3() const;
	bool getButton4() const;
	bool getButton5() const;
	bool getButton6() const;
	bool getButton7() const;
	bool getButton8() const;
	bool getButton9() const;
	bool getButtonMINUS() const;
	bool getButtonPLUS() const;
	bool getButtonMULTI() const;
	bool getButtonDIVISION() const;
	bool getButtonEQUAL() const;
	bool getButtonDOT() const;
	bool getButtonCLEAR() const;
	bool getButtonDEL() const;
	bool getButtonLPARENTHESIS() const;
	bool getButtonRPARENTHESIS() const;

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

	void setButton0(bool value);
	void setButton1(bool value);
	void setButton2(bool value);
	void setButton3(bool value);
	void setButton4(bool value);
	void setButton5(bool value);
	void setButton6(bool value);
	void setButton7(bool value);
	void setButton8(bool value);
	void setButton9(bool value);
	void setButtonMINUS(bool value);
	void setButtonPLUS(bool value);
	void setButtonMULTI(bool value);
	void setButtonDIVISION(bool value);
	void setButtonDOT(bool value);
	void setButtonEQUAL(bool value);
	void setButtonCLEAR(bool value);
	void setButtonDEL(bool value);
	void setButtonLPARENTHESIS(bool value);
	void setButtonRPARENTHESIS(bool value);

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



