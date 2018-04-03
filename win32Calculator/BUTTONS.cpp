/********************************************************************
					HEADER FILE - BUTTONS_H
							Made By
						ProfoundDisputes
**********************************************************************/
#include "BUTTONS.h"


//=====================================
//============	CREATE  ===============
//=====================================
bool BUTTONS::CREATE::All(HWND parenthwnd)
{
	//Created the position reference button (ID_BUTTONEQUAL). All
	//buttons will be based off this buttons size and cords
	parentClass.Create.ButtonEQUAL(parenthwnd);

	//Ensures that ID_BUTTONEQUAL has been created before
	//creating rest of the windows control buttons
	if (parentClass.getButtonEQUAL())
	{
		//Creates top row (row 1) of buttons from left to right
		parentClass.Create.ButtonLPARENTHESIS(parenthwnd);
		parentClass.Create.ButtonRPARENTHESIS(parenthwnd);
		parentClass.Create.ButtonDEL(parenthwnd);
		parentClass.Create.ButtonDIVISION(parenthwnd);

		//Creates row 2 of buttons from left to right
		parentClass.Create.Button7(parenthwnd);
		parentClass.Create.Button8(parenthwnd);
		parentClass.Create.Button9(parenthwnd);
		parentClass.Create.ButtonMULTI(parenthwnd);

		//Creates row 3 of buttons from left to right
		parentClass.Create.Button4(parenthwnd);
		parentClass.Create.Button5(parenthwnd);
		parentClass.Create.Button6(parenthwnd);
		parentClass.Create.ButtonMINUS(parenthwnd);

		//Creates row 4 of buttons from left to right
		parentClass.Create.Button1(parenthwnd);
		parentClass.Create.Button2(parenthwnd);
		parentClass.Create.Button3(parenthwnd);
		parentClass.Create.ButtonPLUS(parenthwnd);

		//Creates row 5 of buttons from left to right
		//Except ButtonEQUAL since its used as a position
		//reference for all buttons it was created first
		parentClass.Create.ButtonCLEAR(parenthwnd);
		parentClass.Create.Button0(parenthwnd);
		parentClass.Create.ButtonDOT(parenthwnd);
		
	}
	else
	{
		//if 'pButtonEQUAL' isn't true. Than function fails. Return
		//false
		return false;
	}

	//stores the parent handle in object member
	parentClass.setparentHwnd(parenthwnd);

	//function has created all buttons and updated the parent handle
	return true;
}

bool BUTTONS::CREATE::Button0(HWND parenthwnd)
{
	//------Variable Decelerations------
	HWND buttonHandle;
	xyButton buttonReference;
	xyButton button0;

	//Position and Size are in relation to ID_BUTTONEQUAL
	//ensures that bBUTTONEQUAL has been flagged.
	if (!parentClass.getButtonEQUAL()) return false;

	//gets xy and size of button ID_BUTTONEQUAL located right
	//of ID_BUTTON0. This will be used as a reference for 
	//ID_BUTTON0's position
	buttonReference = parentClass.
		getButtonDimensions(parenthwnd, Defines::IDtoLPCSTR(ID_BUTTONEQUAL));

	//calculates the relative position, in respect to ID_BUTTONEQUAL,
	//for ID_BUTTON0
	button0.x = (buttonReference.x - buttonReference.width * 2) - 4;
	button0.y = buttonReference.y;

	//sets the size of the ID_BUTTON0 control to same as
	//the reference control button
	button0.width = buttonReference.width;
	button0.height = buttonReference.height;

	//creates the button
	buttonHandle = CreateWindowEx(NULL, TEXT("button"), Defines::IDtoLPCSTR(ID_BUTTON0),
		WS_VISIBLE | WS_TABSTOP | WS_CHILD, button0.x, button0.y, button0.width,
		button0.height, parenthwnd, (HMENU)ID_BUTTON0, NULL, NULL);

	//if handle is null than button creation has failed
	if (!buttonHandle)
	{
		//exit program unsuccessfully
		return false;
	}

	//If passed handle check then button was created
	//set the flag for creation of ID_BUTTONEQUAL
	parentClass.setButton0(true);

	//Exit function with success
	return true;
}

bool BUTTONS::CREATE::Button1(HWND parenthwnd)
{
	//------Variable Decelerations------
	HWND buttonHandle;
	xyButton buttonReference;
	xyButton button1;

	//Position and Size are in relation to ID_BUTTONEQUAL
	//ensures that bBUTTONEQUAL has been flagged.
	if (!parentClass.getButtonEQUAL()) return false;

	//gets xy and size of button ID_BUTTONEQUAL located right
	//of ID_BUTTON1. This will be used as a reference for 
	//ID_BUTTON1's position
	buttonReference = parentClass.
		getButtonDimensions(parenthwnd, Defines::IDtoLPCSTR(ID_BUTTONEQUAL));

	//calculates the relative position, in respect to ID_BUTTONEQUAL,
	//for ID_BUTTON1
	button1.x = (buttonReference.x - buttonReference.width * 3) - 6;
	button1.y = (buttonReference.y - buttonReference.height) - 2;

	//sets the size of the ID_BUTTON1 control to same as
	//the reference control button
	button1.width = buttonReference.width;
	button1.height = buttonReference.height;

	//creates the button
	buttonHandle = CreateWindowEx(NULL, TEXT("button"), Defines::IDtoLPCSTR(ID_BUTTON1),
		WS_VISIBLE | WS_TABSTOP | WS_CHILD, button1.x, button1.y, button1.width,
		button1.height, parenthwnd, (HMENU)ID_BUTTON1, NULL, NULL);

	//if handle is null than button creation has failed
	if (!buttonHandle)
	{
		//exit program unsuccessfully
		return false;
	}

	//If passed handle check then button was created
	//set the flag for creation of ID_BUTTONEQUAL
	parentClass.setButton1(true);

	//Exit function with success
	return true;
}

bool BUTTONS::CREATE::Button2(HWND parenthwnd)
{
	//------Variable Decelerations------
	HWND buttonHandle;
	xyButton buttonReference;
	xyButton button2;

	//Position and Size are in relation to ID_BUTTONEQUAL
	//ensures that bBUTTONEQUAL has been flagged.
	if (!parentClass.getButtonEQUAL()) return false;

	//gets xy and size of button ID_BUTTONEQUAL located right
	//of ID_BUTTON2. This will be used as a reference for 
	//ID_BUTTON2's position
	buttonReference = parentClass.
		getButtonDimensions(parenthwnd, Defines::IDtoLPCSTR(ID_BUTTONEQUAL));

	//calculates the relative position, in respect to ID_BUTTONEQUAL,
	//for ID_BUTTON2
	button2.x = (buttonReference.x - buttonReference.width * 2) - 4;
	button2.y = (buttonReference.y - buttonReference.height) - 2;

	//sets the size of the ID_BUTTON2 control to same as
	//the reference control button
	button2.width = buttonReference.width;
	button2.height = buttonReference.height;

	//creates the button
	buttonHandle = CreateWindowEx(NULL, TEXT("button"), Defines::IDtoLPCSTR(ID_BUTTON2),
		WS_VISIBLE | WS_TABSTOP | WS_CHILD, button2.x, button2.y, button2.width,
		button2.height, parenthwnd, (HMENU)ID_BUTTON2, NULL, NULL);

	//if handle is null than button creation has failed
	if (!buttonHandle)
	{
		//exit program unsuccessfully
		return false;
	}

	//If passed handle check then button was created
	//set the flag for creation of ID_BUTTONEQUAL
	parentClass.setButton2(true);

	//Exit function with success
	return true;
}

bool BUTTONS::CREATE::Button3(HWND parenthwnd)
{
	//------Variable Decelerations------
	HWND buttonHandle;
	xyButton buttonReference;
	xyButton button3;

	//Position and Size are in relation to ID_BUTTONEQUAL
	//ensures that bBUTTONEQUAL has been flagged.
	if (!parentClass.getButtonEQUAL()) return false;

	//gets xy and size of button ID_BUTTONEQUAL located right
	//of ID_BUTTON3. This will be used as a reference for 
	//ID_BUTTON3's position
	buttonReference = parentClass.
		getButtonDimensions(parenthwnd, Defines::IDtoLPCSTR(ID_BUTTONEQUAL));

	//calculates the relative position, in respect to ID_BUTTONEQUAL,
	//for ID_BUTTON3
	button3.x = (buttonReference.x - buttonReference.width) - 2;
	button3.y = (buttonReference.y - buttonReference.height) - 2;

	//sets the size of the ID_BUTTON3 control to same as
	//the reference control button
	button3.width = buttonReference.width;
	button3.height = buttonReference.height;

	//creates the button
	buttonHandle = CreateWindowEx(NULL, TEXT("button"), Defines::IDtoLPCSTR(ID_BUTTON3),
		WS_VISIBLE | WS_TABSTOP | WS_CHILD, button3.x, button3.y, button3.width,
		button3.height, parenthwnd, (HMENU)ID_BUTTON3, NULL, NULL);

	//if handle is null than button creation has failed
	if (!buttonHandle)
	{
		//exit program unsuccessfully
		return false;
	}

	//If passed handle check then button was created
	//set the flag for creation of ID_BUTTONEQUAL
	parentClass.setButton3(true);

	//Exit function with success
	return true;
}

bool BUTTONS::CREATE::Button4(HWND parenthwnd)
{
	//------Variable Decelerations------
	HWND buttonHandle;
	xyButton buttonReference;
	xyButton button4;

	//Position and Size are in relation to ID_BUTTONEQUAL
	//ensures that bBUTTONEQUAL has been flagged.
	if (!parentClass.getButtonEQUAL()) return false;

	//gets xy and size of button ID_BUTTONEQUAL located right
	//of ID_BUTTON4. This will be used as a reference for 
	//ID_BUTTON4's position
	buttonReference = parentClass.
		getButtonDimensions(parenthwnd, Defines::IDtoLPCSTR(ID_BUTTONEQUAL));

	//calculates the relative position, in respect to ID_BUTTONEQUAL,
	//for ID_BUTTON4
	button4.x = (buttonReference.x - buttonReference.width * 3) - 6;
	button4.y = (buttonReference.y - buttonReference.height * 2) - 4;

	//sets the size of the ID_BUTTON4 control to same as
	//the reference control button
	button4.width = buttonReference.width;
	button4.height = buttonReference.height;

	//creates the button
	buttonHandle = CreateWindowEx(NULL, TEXT("button"), Defines::IDtoLPCSTR(ID_BUTTON4),
		WS_VISIBLE | WS_TABSTOP | WS_CHILD, button4.x, button4.y, button4.width,
		button4.height, parenthwnd, (HMENU)ID_BUTTON4, NULL, NULL);

	//if handle is null than button creation has failed
	if (!buttonHandle)
	{
		//exit program unsuccessfully
		return false;
	}

	//If passed handle check then button was created
	//set the flag for creation of ID_BUTTONEQUAL
	parentClass.setButton4(true);

	//Exit function with success
	return true;
}

bool BUTTONS::CREATE::Button5(HWND parenthwnd)
{
	//------Variable Decelerations------
	HWND buttonHandle;
	xyButton buttonReference;
	xyButton button5;

	//Position and Size are in relation to ID_BUTTONEQUAL
	//ensures that bBUTTONEQUAL has been flagged.
	if (!parentClass.getButtonEQUAL()) return false;

	//gets xy and size of button ID_BUTTONEQUAL located right
	//of ID_BUTTON5. This will be used as a reference for 
	//ID_BUTTON5's position
	buttonReference = parentClass.
		getButtonDimensions(parenthwnd, Defines::IDtoLPCSTR(ID_BUTTONEQUAL));

	//calculates the relative position, in respect to ID_BUTTONEQUAL,
	//for ID_BUTTON5
	button5.x = (buttonReference.x - buttonReference.width * 2) - 4;
	button5.y = (buttonReference.y - buttonReference.height * 2) - 4;

	//sets the size of the ID_BUTTON5 control to same as
	//the reference control button
	button5.width = buttonReference.width;
	button5.height = buttonReference.height;

	//creates the button
	buttonHandle = CreateWindowEx(NULL, TEXT("button"), Defines::IDtoLPCSTR(ID_BUTTON5),
		WS_VISIBLE | WS_TABSTOP | WS_CHILD, button5.x, button5.y, button5.width,
		button5.height, parenthwnd, (HMENU)ID_BUTTON5, NULL, NULL);

	//if handle is null than button creation has failed
	if (!buttonHandle)
	{
		//exit program unsuccessfully
		return false;
	}

	//If passed handle check then button was created
	//set the flag for creation of ID_BUTTONEQUAL
	parentClass.setButton5(true);

	//Exit function with success
	return true;
}
bool BUTTONS::CREATE::Button6(HWND parenthwnd)
{
	//------Variable Decelerations------
	HWND buttonHandle;
	xyButton buttonReference;
	xyButton button6;

	//Position and Size are in relation to ID_BUTTONEQUAL
	//ensures that bBUTTONEQUAL has been flagged.
	if (!parentClass.getButtonEQUAL()) return false;

	//gets xy and size of button ID_BUTTONEQUAL located right
	//of ID_BUTTON6. This will be used as a reference for 
	//ID_BUTTON6's position
	buttonReference = parentClass.
		getButtonDimensions(parenthwnd, Defines::IDtoLPCSTR(ID_BUTTONEQUAL));

	//calculates the relative position, in respect to ID_BUTTONEQUAL,
	//for ID_BUTTON6
	button6.x = (buttonReference.x - buttonReference.width) - 2;
	button6.y = (buttonReference.y - buttonReference.height * 2) - 4;

	//sets the size of the ID_BUTTON6 control to same as
	//the reference control button
	button6.width = buttonReference.width;
	button6.height = buttonReference.height;

	//creates the button
	buttonHandle = CreateWindowEx(NULL, TEXT("button"), Defines::IDtoLPCSTR(ID_BUTTON6),
		WS_VISIBLE | WS_TABSTOP | WS_CHILD, button6.x, button6.y, button6.width,
		button6.height, parenthwnd, (HMENU)ID_BUTTON6, NULL, NULL);

	//if handle is null than button creation has failed
	if (!buttonHandle)
	{
		//exit program unsuccessfully
		return false;
	}

	//If passed handle check then button was created
	//set the flag for creation of ID_BUTTONEQUAL
	parentClass.setButton6(true);

	//Exit function with success
	return true;
}

bool BUTTONS::CREATE::Button7(HWND parenthwnd)
{
	//------Variable Decelerations------
	HWND buttonHandle;
	xyButton buttonReference;
	xyButton button7;

	//Position and Size are in relation to ID_BUTTONEQUAL
	//ensures that bBUTTONEQUAL has been flagged.
	if (!parentClass.getButtonEQUAL()) return false;

	//gets xy and size of button ID_BUTTONEQUAL located right
	//of ID_BUTTON7. This will be used as a reference for 
	//ID_BUTTON7's position
	buttonReference = parentClass.
		getButtonDimensions(parenthwnd, Defines::IDtoLPCSTR(ID_BUTTONEQUAL));

	//calculates the relative position, in respect to ID_BUTTONEQUAL,
	//for ID_BUTTON7
	button7.x = (buttonReference.x - buttonReference.width * 3) - 6;
	button7.y = (buttonReference.y - buttonReference.height * 3) - 6;

	//sets the size of the ID_BUTTON7 control to same as
	//the reference control button
	button7.width = buttonReference.width;
	button7.height = buttonReference.height;

	//creates the button
	buttonHandle = CreateWindowEx(NULL, TEXT("button"), Defines::IDtoLPCSTR(ID_BUTTON7),
		WS_VISIBLE | WS_TABSTOP | WS_CHILD, button7.x, button7.y, button7.width,
		button7.height, parenthwnd, (HMENU)ID_BUTTON7, NULL, NULL);

	//if handle is null than button creation has failed
	if (!buttonHandle)
	{
		//exit program unsuccessfully
		return false;
	}

	//If passed handle check then button was created
	//set the flag for creation of ID_BUTTONEQUAL
	parentClass.setButton7(true);

	//Exit function with success
	return true;
}

bool BUTTONS::CREATE::Button8(HWND parenthwnd)
{
	//------Variable Decelerations------
	HWND buttonHandle;
	xyButton buttonReference;
	xyButton button8;

	//Position and Size are in relation to ID_BUTTONEQUAL
	//ensures that bBUTTONEQUAL has been flagged.
	if (!parentClass.getButtonEQUAL()) return false;

	//gets xy and size of button ID_BUTTONEQUAL located right
	//of ID_BUTTON8. This will be used as a reference for 
	//ID_BUTTON8's position
	buttonReference = parentClass.
		getButtonDimensions(parenthwnd, Defines::IDtoLPCSTR(ID_BUTTONEQUAL));

	//calculates the relative position, in respect to ID_BUTTONEQUAL,
	//for ID_BUTTON8
	button8.x = (buttonReference.x - buttonReference.width * 2) - 4;
	button8.y = (buttonReference.y - buttonReference.height * 3) - 6;

	//sets the size of the ID_BUTTON8 control to same as
	//the reference control button
	button8.width = buttonReference.width;
	button8.height = buttonReference.height;

	//creates the button
	buttonHandle = CreateWindowEx(NULL, TEXT("button"), Defines::IDtoLPCSTR(ID_BUTTON8),
		WS_VISIBLE | WS_TABSTOP | WS_CHILD, button8.x, button8.y, button8.width,
		button8.height, parenthwnd, (HMENU)ID_BUTTON8, NULL, NULL);

	//if handle is null than button creation has failed
	if (!buttonHandle)
	{
		//exit program unsuccessfully
		return false;
	}

	//If passed handle check then button was created
	//set the flag for creation of ID_BUTTONEQUAL
	parentClass.setButton8(true);

	//Exit function with success
	return true;
}

bool BUTTONS::CREATE::Button9(HWND parenthwnd)
{
	//------Variable Decelerations------
	HWND buttonHandle;
	xyButton buttonReference;
	xyButton button9;

	//Position and Size are in relation to ID_BUTTONEQUAL
	//ensures that bBUTTONEQUAL has been flagged.
	if (!parentClass.getButtonEQUAL()) return false;

	//gets xy and size of button ID_BUTTONEQUAL located right
	//of ID_BUTTON9. This will be used as a reference for 
	//ID_BUTTON9's position
	buttonReference = parentClass.
		getButtonDimensions(parenthwnd, Defines::IDtoLPCSTR(ID_BUTTONEQUAL));

	//calculates the relative position, in respect to ID_BUTTONEQUAL,
	//for ID_BUTTON9
	button9.x = (buttonReference.x - buttonReference.width) - 2;
	button9.y = (buttonReference.y - buttonReference.height * 3) - 6;

	//sets the size of the ID_BUTTON9 control to same as
	//the reference control button
	button9.width = buttonReference.width;
	button9.height = buttonReference.height;

	//creates the button
	buttonHandle = CreateWindowEx(NULL, TEXT("button"), Defines::IDtoLPCSTR(ID_BUTTON9),
		WS_VISIBLE | WS_TABSTOP | WS_CHILD, button9.x, button9.y, button9.width,
		button9.height, parenthwnd, (HMENU)ID_BUTTON9, NULL, NULL);

	//if handle is null than button creation has failed
	if (!buttonHandle)
	{
		//exit program unsuccessfully
		return false;
	}

	//If passed handle check then button was created
	//set the flag for creation of ID_BUTTONEQUAL
	parentClass.setButton9(true);

	//Exit function with success
	return true;
}

bool BUTTONS::CREATE::ButtonDOT(HWND parenthwnd)
{
	//------Variable Decelerations------
	HWND buttonHandle;
	xyButton buttonReference;
	xyButton buttonDOT;

	//Position and Size are in relation to ID_BUTTONEQUAL
	//ensures that bBUTTONEQUAL has been flagged.
	if (!parentClass.getButtonEQUAL()) return false;

	//gets xy and size of button ID_BUTTONEQUAL located right
	//of ID_BUTTONDOT. This will be used as a reference for 
	//ID_BUTTONDOT's position
	buttonReference = parentClass.
		getButtonDimensions(parenthwnd, Defines::IDtoLPCSTR(ID_BUTTONEQUAL));

	//calculates the relative position, in respect to ID_BUTTONEQUAL,
	//for ID_BUTTONDOT
	buttonDOT.x = (buttonReference.x - buttonReference.width) - 2;
	buttonDOT.y = buttonReference.y;

	//sets the size of the ID_BUTTONDOT control to same as
	//the reference control button
	buttonDOT.width = buttonReference.width;
	buttonDOT.height = buttonReference.height;

	//creates the button
	buttonHandle = CreateWindowEx(NULL, TEXT("button"), Defines::IDtoLPCSTR(ID_BUTTONDOT),
		WS_VISIBLE | WS_TABSTOP | WS_CHILD, buttonDOT.x, buttonDOT.y, buttonDOT.width,
		buttonDOT.height, parenthwnd, (HMENU)ID_BUTTONDOT, NULL, NULL);

	//if handle is null than button creation has failed
	if (!buttonHandle)
	{
		//exit program unsuccessfully
		return false;
	}

	//If passed handle check then button was created
	//set the flag for creation of ID_BUTTONEQUAL
	parentClass.setButtonDOT(true);

	//Exit function with success
	return true;
}

bool BUTTONS::CREATE::ButtonCLEAR(HWND parenthwnd)
{
	//------Variable Decelerations------
	HWND buttonHandle;
	xyButton buttonReference;
	xyButton button0;

	//Position and Size are in relation to ID_BUTTONEQUAL
	//ensures that bBUTTONEQUAL has been flagged.
	if (!parentClass.getButtonEQUAL()) return false;

	//gets xy and size of button ID_BUTTONEQUAL located right
	//of ID_BUTTONCLEAR. This will be used as a reference for 
	//ID_BUTTONCLEAR's position
	buttonReference = parentClass.
		getButtonDimensions(parenthwnd, Defines::IDtoLPCSTR(ID_BUTTONEQUAL));

	//calculates the relative position, in respect to ID_BUTTONEQUAL,
	//for ID_BUTTONCLEAR
	button0.x = (buttonReference.x - buttonReference.width * 3) - 6;
	button0.y = buttonReference.y;

	//sets the size of the ID_BUTTONCLEAR control to same as
	//the reference control button
	button0.width = buttonReference.width;
	button0.height = buttonReference.height;

	//creates the button
	buttonHandle = CreateWindowEx(NULL, TEXT("button"), Defines::IDtoLPCSTR(ID_BUTTONCLEAR),
		WS_VISIBLE | WS_TABSTOP | WS_CHILD, button0.x, button0.y, button0.width,
		button0.height, parenthwnd, (HMENU)ID_BUTTONCLEAR, NULL, NULL);

	//if handle is null than button creation has failed
	if (!buttonHandle)
	{
		//exit program unsuccessfully
		return false;
	}

	//If passed handle check then button was created
	//set the flag for creation of ID_BUTTONEQUAL
	parentClass.setButtonCLEAR(true);

	//Exit function with success
	return true;
}

bool BUTTONS::CREATE::ButtonDEL(HWND parenthwnd)
{
	//------Variable Decelerations------
	HWND buttonHandle;
	xyButton buttonReference;
	xyButton buttonDEL;

	//Position and Size are in relation to ID_BUTTONEQUAL
	//ensures that bBUTTONEQUAL has been flagged.
	if (!parentClass.getButtonEQUAL()) return false;

	//gets xy and size of button ID_BUTTONEQUAL located right
	//of ID_BUTTONDEL. This will be used as a reference for 
	//ID_BUTTONDEL's position
	buttonReference = parentClass.
		getButtonDimensions(parenthwnd, Defines::IDtoLPCSTR(ID_BUTTONEQUAL));

	//calculates the relative position, in respect to ID_BUTTONEQUAL,
	//for ID_BUTTONDEL
	buttonDEL.x = (buttonReference.x - buttonReference.width) - 2;
	buttonDEL.y = (buttonReference.y - buttonReference.height * 4) - 8;

	//sets the size of the ID_BUTTONDEL control to same as
	//the reference control button
	buttonDEL.width = buttonReference.width;
	buttonDEL.height = buttonReference.height;

	//creates the button
	buttonHandle = CreateWindowEx(NULL, TEXT("button"), Defines::IDtoLPCSTR(ID_BUTTONDEL),
		WS_VISIBLE | WS_TABSTOP | WS_CHILD, buttonDEL.x, buttonDEL.y, buttonDEL.width,
		buttonDEL.height, parenthwnd, (HMENU)ID_BUTTONDEL, NULL, NULL);

	//if handle is null than button creation has failed
	if (!buttonHandle)
	{
		//exit program unsuccessfully
		return false;
	}

	//If passed handle check then button was created
	//set the flag for creation of ID_BUTTONEQUAL
	parentClass.setButtonDEL(true);

	//Exit function with success
	return true;
}


bool BUTTONS::CREATE::ButtonMINUS(HWND parenthwnd)
{
	//------Variable Decelerations------
	HWND buttonHandle;
	xyButton buttonReference;
	xyButton buttonMINUS;

	//Position and Size are in relation to ID_BUTTONEQUAL
	//ensures that bBUTTONEQUAL has been flagged.
	if (!parentClass.getButtonEQUAL()) return false;

	//gets xy and size of button ID_BUTTONEQUAL located right
	//of ID_BUTTONMINUS. This will be used as a reference for 
	//ID_BUTTONMINUS's position
	buttonReference = parentClass.
		getButtonDimensions(parenthwnd, Defines::IDtoLPCSTR(ID_BUTTONEQUAL));

	//calculates the relative position, in respect to ID_BUTTONEQUAL,
	//for ID_BUTTONMINUS
	buttonMINUS.x = (buttonReference.x);
	buttonMINUS.y = (buttonReference.y - buttonReference.height * 2) - 4;

	//sets the size of the ID_BUTTONMINUS control to same as
	//the reference control button
	buttonMINUS.width = buttonReference.width;
	buttonMINUS.height = buttonReference.height;

	//creates the button
	buttonHandle = CreateWindowEx(NULL, TEXT("button"), Defines::IDtoLPCSTR(ID_BUTTONMINUS),
		WS_VISIBLE | WS_TABSTOP | WS_CHILD, buttonMINUS.x, buttonMINUS.y, buttonMINUS.width,
		buttonMINUS.height, parenthwnd, (HMENU)ID_BUTTONMINUS, NULL, NULL);

	//if handle is null than button creation has failed
	if (!buttonHandle)
	{
		//exit program unsuccessfully
		return false;
	}

	//If passed handle check then button was created
	//set the flag for creation of ID_BUTTONEQUAL
	parentClass.setButtonMINUS(true);

	//Exit function with success
	return true;
}

bool BUTTONS::CREATE::ButtonPLUS(HWND parenthwnd)
{
	//------Variable Decelerations------
	HWND buttonHandle;
	xyButton buttonReference;
	xyButton buttonPLUS;

	//Position and Size are in relation to ID_BUTTONEQUAL
	//ensures that bBUTTONEQUAL has been flagged.
	if (!parentClass.getButtonEQUAL()) return false;

	//gets xy and size of button ID_BUTTONEQUAL located right
	//of ID_BUTTONPLUS. This will be used as a reference for 
	//ID_BUTTONPLUS's position
	buttonReference = parentClass.
		getButtonDimensions(parenthwnd, Defines::IDtoLPCSTR(ID_BUTTONEQUAL));

	//calculates the relative position, in respect to ID_BUTTONEQUAL,
	//for ID_BUTTONPLUS
	buttonPLUS.x = buttonReference.x;
	buttonPLUS.y = (buttonReference.y - buttonReference.height) - 2;

	//sets the size of the ID_BUTTONPLUS control to same as
	//the reference control button
	buttonPLUS.width = buttonReference.width;
	buttonPLUS.height = buttonReference.height;

	//creates the button
	buttonHandle = CreateWindowEx(NULL, TEXT("button"), Defines::IDtoLPCSTR(ID_BUTTONPLUS),
		WS_VISIBLE | WS_TABSTOP | WS_CHILD, buttonPLUS.x, buttonPLUS.y, buttonPLUS.width,
		buttonPLUS.height, parenthwnd, (HMENU)ID_BUTTONPLUS, NULL, NULL);

	//if handle is null than button creation has failed
	if (!buttonHandle)
	{
		//exit program unsuccessfully
		return false;
	}

	//If passed handle check then button was created
	//set the flag for creation of ID_BUTTONEQUAL
	parentClass.setButtonPLUS(true);

	//Exit function with success
	return true;
}

bool BUTTONS::CREATE::ButtonMULTI(HWND parenthwnd)
{
	//------Variable Decelerations------
	HWND buttonHandle;
	xyButton buttonReference;
	xyButton buttonMULTI;

	//Position and Size are in relation to ID_BUTTONEQUAL
	//ensures that bBUTTONEQUAL has been flagged.
	if (!parentClass.getButtonEQUAL()) return false;

	//gets xy and size of button ID_BUTTONEQUAL located right
	//of ID_BUTTONMULTI. This will be used as a reference for 
	//ID_BUTTONMULTI's position
	buttonReference = parentClass.
		getButtonDimensions(parenthwnd, Defines::IDtoLPCSTR(ID_BUTTONEQUAL));

	//calculates the relative position, in respect to ID_BUTTONEQUAL,
	//for ID_BUTTONMULTI
	buttonMULTI.x = (buttonReference.x);
	buttonMULTI.y = (buttonReference.y - buttonReference.height * 3) - 6;

	//sets the size of the ID_BUTTONMULTI control to same as
	//the reference control button
	buttonMULTI.width = buttonReference.width;
	buttonMULTI.height = buttonReference.height;

	//creates the button
	buttonHandle = CreateWindowEx(NULL, TEXT("button"), Defines::IDtoLPCSTR(ID_BUTTONMULTI),
		WS_VISIBLE | WS_TABSTOP | WS_CHILD, buttonMULTI.x, buttonMULTI.y, buttonMULTI.width,
		buttonMULTI.height, parenthwnd, (HMENU)ID_BUTTONMULTI, NULL, NULL);

	//if handle is null than button creation has failed
	if (!buttonHandle)
	{
		//exit program unsuccessfully
		return false;
	}

	//If passed handle check then button was created
	//set the flag for creation of ID_BUTTONEQUAL
	parentClass.setButtonMULTI(true);

	//Exit function with success
	return true;
}

bool BUTTONS::CREATE::ButtonDIVISION(HWND parenthwnd)
{
	//------Variable Decelerations------
	HWND buttonHandle;
	xyButton buttonReference;
	xyButton buttonDIVISION;

	//Position and Size are in relation to ID_BUTTONEQUAL
	//ensures that bBUTTONEQUAL has been flagged.
	if (!parentClass.getButtonEQUAL()) return false;

	//gets xy and size of button ID_BUTTONEQUAL located right
	//of ID_BUTTONDIVISION. This will be used as a reference for 
	//ID_BUTTONDIVISION's position
	buttonReference = parentClass.
		getButtonDimensions(parenthwnd, Defines::IDtoLPCSTR(ID_BUTTONEQUAL));

	//calculates the relative position, in respect to ID_BUTTONEQUAL,
	//for ID_BUTTONDIVISION
	buttonDIVISION.x = (buttonReference.x);
	buttonDIVISION.y = (buttonReference.y - buttonReference.height * 4) - 8;

	//sets the size of the ID_BUTTONDIVISION control to same as
	//the reference control button
	buttonDIVISION.width = buttonReference.width;
	buttonDIVISION.height = buttonReference.height;

	//creates the button
	buttonHandle = CreateWindowEx(NULL, TEXT("button"), Defines::IDtoLPCSTR(ID_BUTTONDIVISION),
		WS_VISIBLE | WS_TABSTOP | WS_CHILD, buttonDIVISION.x, buttonDIVISION.y, buttonDIVISION.width,
		buttonDIVISION.height, parenthwnd, (HMENU)ID_BUTTONDIVISION, NULL, NULL);

	//if handle is null than button creation has failed
	if (!buttonHandle)
	{
		//exit program unsuccessfully
		return false;
	}

	//If passed handle check then button was created
	//set the flag for creation of ID_BUTTONEQUAL
	parentClass.setButtonDIVISION(true);

	//Exit function with success
	return true;
}

bool BUTTONS::CREATE::ButtonEQUAL(HWND parenthwnd)
{
	//------Variable Decelerations------
	RECT rect;
	HWND buttonHandle;
	xyButton ButtonEQUAL;

	//ID_BUTTONEQUAL is the reference position and size for all
	//control buttons. To start ID_BUTTONEQUAL is set in the
	//lower right corner of the parent window's client area. First
	//we get client RECT structure
	GetClientRect(parenthwnd, &rect);

	//calculates the relative position, in respect to client window's
	//lower right corner of screen
	ButtonEQUAL.x = rect.right - 56;
	ButtonEQUAL.y = rect.bottom - 50;

	//sets the size of the ID_BUTTONEQUAL
	ButtonEQUAL.width = 55;
	ButtonEQUAL.height = 50;

	//create ID_BUTTONEQUAL control
	buttonHandle = CreateWindowEx(NULL, TEXT("button"), Defines::IDtoLPCSTR(ID_BUTTONEQUAL),
		WS_VISIBLE | WS_TABSTOP | WS_CHILD, ButtonEQUAL.x, ButtonEQUAL.y, ButtonEQUAL.width,
		ButtonEQUAL.height, parenthwnd, (HMENU)ID_BUTTONEQUAL, NULL, NULL);

	//if handle is null than button creation has failed
	if (!buttonHandle)
	{
		//exit program unsuccessfully
		return false;
	}

	//If passed handle check then button was created
	//set the flag for creation of ID_BUTTONEQUAL
	parentClass.setButtonEQUAL(true);

	//Exit function with success
	return true;
}

bool BUTTONS::CREATE::ButtonLPARENTHESIS(HWND parenthwnd)
{
	//------Variable Decelerations------
	HWND buttonHandle;
	xyButton buttonReference;
	xyButton buttonLPARENTHESIS;

	//Position and Size are in relation to ID_BUTTONEQUAL
	//ensures that bBUTTONEQUAL has been flagged.
	if (!parentClass.getButtonEQUAL()) return false;

	//gets xy and size of button ID_BUTTONEQUAL located right
	//of ID_BUTTONLPARENTHESIS. This will be used as a reference for 
	//ID_BUTTONLPARENTHESIS's position
	buttonReference = parentClass.
		getButtonDimensions(parenthwnd, Defines::IDtoLPCSTR(ID_BUTTONEQUAL));

	//calculates the relative position, in respect to ID_BUTTONEQUAL,
	//for ID_BUTTONLPARENTHESIS
	buttonLPARENTHESIS.x = (buttonReference.x - buttonReference.width * 3) - 6;
	buttonLPARENTHESIS.y = (buttonReference.y - buttonReference.height * 4) - 8;

	//sets the size of the ID_BUTTONLPARENTHESIS control to same as
	//the reference control button
	buttonLPARENTHESIS.width = buttonReference.width;
	buttonLPARENTHESIS.height = buttonReference.height;

	//creates the button
	buttonHandle = CreateWindowEx(NULL, TEXT("button"), Defines::IDtoLPCSTR(ID_BUTTONLPARENTHESIS),
		WS_VISIBLE | WS_TABSTOP | WS_CHILD, buttonLPARENTHESIS.x, buttonLPARENTHESIS.y, buttonLPARENTHESIS.width,
		buttonLPARENTHESIS.height, parenthwnd, (HMENU)ID_BUTTONLPARENTHESIS, NULL, NULL);

	//if handle is null than button creation has failed
	if (!buttonHandle)
	{
		//exit program unsuccessfully
		return false;
	}

	//If passed handle check then button was created
	//set the flag for creation of ID_BUTTONEQUAL
	parentClass.setButtonLPARENTHESIS(true);

	//Exit function with success
	return true;
}

bool BUTTONS::CREATE::ButtonRPARENTHESIS(HWND parenthwnd)
{
	//------Variable Decelerations------
	HWND buttonHandle;
	xyButton buttonReference;
	xyButton buttonRPARENTHESIS;

	//Position and Size are in relation to ID_BUTTONEQUAL
	//ensures that bBUTTONEQUAL has been flagged.
	if (!parentClass.getButtonEQUAL()) return false;

	//gets xy and size of button ID_BUTTONEQUAL located right
	//of ID_BUTTONRPARENTHESIS. This will be used as a reference for 
	//ID_BUTTONRPARENTHESIS's position
	buttonReference = parentClass.
		getButtonDimensions(parenthwnd, Defines::IDtoLPCSTR(ID_BUTTONEQUAL));

	//calculates the relative position, in respect to ID_BUTTONEQUAL,
	//for ID_BUTTONRPARENTHESIS
	buttonRPARENTHESIS.x = (buttonReference.x - buttonReference.width * 2) - 4;
	buttonRPARENTHESIS.y = (buttonReference.y - buttonReference.height * 4) - 8;

	//sets the size of the ID_BUTTONRPARENTHESIS control to same as
	//the reference control button
	buttonRPARENTHESIS.width = buttonReference.width;
	buttonRPARENTHESIS.height = buttonReference.height;

	//creates the button
	buttonHandle = CreateWindowEx(NULL, TEXT("button"), Defines::IDtoLPCSTR(ID_BUTTONRPARENTHESIS),
		WS_VISIBLE | WS_TABSTOP | WS_CHILD, buttonRPARENTHESIS.x, buttonRPARENTHESIS.y, buttonRPARENTHESIS.width,
		buttonRPARENTHESIS.height, parenthwnd, (HMENU)ID_BUTTONRPARENTHESIS, NULL, NULL);

	//if handle is null than button creation has failed
	if (!buttonHandle)
	{
		//exit program unsuccessfully
		return false;
	}

	//If passed handle check then button was created
	//set the flag for creation of ID_BUTTONEQUAL
	parentClass.setButtonRPARENTHESIS(true);

	//Exit function with success
	return true;
}


//=====================================
//===========   CLICKED  ==============
//=====================================
bool BUTTONS::CLICKED::Numbers(int buttonID)
{
	//resets focus the parent window to ensure keyboard input works
	SetFocus(parentClass.getparentHwnd());

	//retrieves handle to ID_EDIT. Handle used to get text and set text
	HWND editHandle = FindWindowEx(parentClass.parentHwnd, NULL, TEXT("edit"), TEXT("0"));

	//gets the char array length contained in ID_EDIT text. Used for limit
	//for GetWindowText(). Adds 1 because function does not count the null
	//terminating string char. Adds 2 to account for the added number after
	//button is clicked
	const int editTextSize = GetWindowTextLength(editHandle) + 2;

	//Text in edit box can't exceed 12 chars, otherwise, it causes
	//the string to clip in the edit window
	if (editTextSize >= 14)
	{
		//Updates object member iLastButtonClicked to reflect 
		//button clicked in window. Value used in math operations
		//function
		parentClass.setiLastButtonClicked(buttonID);

		//No errors were encountered simply
		//return back.
		return true;
	}

	//Dynamically allocates a LPSTR array used for GetWindowText()
	//LPSTR array is size according to return of GetWindowTextLength() + 2
	LPSTR text = new char[editTextSize];

	//ID_EDIT text is retrieved and stored into 'text'
	GetWindowText(editHandle, text, editTextSize);

	//When last button clicked is a math operator or '(' than
	//ID_EDIT text will be cleared and replaced with char 
	//associated with the button ID.
	if (((parentClass.getiLastButtontClicked() >= 213) & (parentClass.getiLastButtontClicked() <= 216))
		|| parentClass.getiLastButtontClicked() == ID_BUTTONLPARENTHESIS)
	{
		//sets the text of ID_EDIT to '0'
		SetWindowText(editHandle, Defines::IDtoLPCSTR(buttonID));

		//deletes pointer
		delete[] text;

		//Updates object member iLastButtonClicked to reflect 
		//button clicked in window. Value used in MathOperator()
		parentClass.setiLastButtonClicked(buttonID);

		//breaks the switch and returns function as success
		return true;
	}

	//When the edit box is cleared it uses
	//'0' as a place holder for edit text. This
	//prevents there being a leading zero
	if (text[0] == '0')
	{
		text[0] = *Defines::IDtoLPCSTR(buttonID);
	}
	else
	{
		//If edit box isn't empty than add button value
		//to the end of the edit text. Does this by adding
		//value to the second to last position in array 'text'
		text[editTextSize - 2] = *Defines::IDtoLPCSTR(buttonID);
	}

	//Makes text a null terminating string by adding null
	//to the end of the string
	text[editTextSize - 1] = '\0';

	//sets the text of ID_EDIT with an additional value
	SetWindowText(editHandle, text);

	//deletes pointer
	delete[] text;

	//Updates object member iLastButtonClicked to reflect 
	//button clicked in window. Value used in MathOperator()
	parentClass.setiLastButtonClicked(buttonID);

	//breaks the switch and returns function as success
	return true;

}

bool BUTTONS::CLICKED::CLR()
{
	//resets focus the parent window to ensure keyboard input works
	SetFocus(parentClass.getparentHwnd());

	//clears the ID_EDIT text by setting it to '0'
	SetWindowText(GetDlgItem(parentClass.getparentHwnd(), ID_EDIT), (LPSTR)"0");

	//clears the ID_STATIC text by setting it to '0'
	SetWindowText(GetDlgItem(parentClass.getparentHwnd(), ID_STATIC), (LPSTR)"\0");

	//Updates object member iLastButtonClicked to reflect 
	//button clicked in window. Value used in MathOperator()
	parentClass.setiLastButtonClicked(ID_BUTTONCLEAR);

	//breaks the switch and returns function as success
	return true;
}

bool BUTTONS::CLICKED::DEL()
{
	//resets focus the parent window to ensure keyboard input works
	SetFocus(parentClass.getparentHwnd());

	//retrieves handle to ID_EDIT. Handle used to get text and set text
	HWND editHandle = FindWindowEx(parentClass.getparentHwnd(), NULL, TEXT("edit"), TEXT("0"));

	//gets the char array length contained in ID_EDIT text. Used for limit
	//in GetWindowText(). Adds 1 because function does not count the null
	//terminating string char.
	const int editTextSize = GetWindowTextLength(editHandle) + 1;

	//Dynamically allocates a LPSTR array used for GetWindowText()
	//LPSTR array is size according to return of GetWindowTextLength() + 2
	LPSTR text = new char[editTextSize];

	//ID_EDIT text is retrieved and stored into 'text'
	GetWindowText(editHandle, text, editTextSize);

	//If size of the text is 2 than there is
	//one digit displayed in the edit box. Delete button
	//will never make the string value null. Deleting
	//past a single digit will just change the digit to
	//'0'.
	if (editTextSize <= 2)
	{
		//sets the edit box to "0"
		SetWindowText(editHandle, (LPSTR)"0");
	}
	else
	{
		//The last space in 'text' is the null terminating string
		//char. This will place a terminating string char just
		//before the current terminating char, thereby, deleting
		//the last character in the string
		text[editTextSize - 2] = '\0';

		//updates the edit box text
		SetWindowText(editHandle, text);
	}

	//clean up dynamically allocated array
	delete[] text;

	//Updates object member iLastButtonClicked to reflect 
	//button clicked in window. Value used in MathOperator()
	parentClass.setiLastButtonClicked(ID_BUTTONDEL);

	//function is successful
	return true;
}

bool BUTTONS::CLICKED::MathOperator(int buttonID)
{
	//resets focus the parent window to ensure keyboard input works
	SetFocus(parentClass.getparentHwnd());

	//retrieves handle to ID_EDIT. Handle used to get text and set text
	HWND editHandle = GetDlgItem(parentClass.getparentHwnd(), ID_EDIT);

	//gets the char array length contained in ID_EDIT text. Used for limit
	//for GetWindowText(). Plus one is for null terminating string
	const int editTextSize = GetWindowTextLength(editHandle) + 1;

	//Dynamically allocates a LPSTR array used for GetWindowText()
	//LPSTR array is size according to return of GetWindowTextLength()
	LPSTR editText = new char[editTextSize];

	//ID_EDIT text is retrieved and stored into 'editText'
	GetWindowText(editHandle, editText, editTextSize);

	//retrieves handle to ID_STATIC, Handle used to get text and set text
	HWND staticHandle = GetDlgItem(parentClass.getparentHwnd(), ID_STATIC);

	//gets th char array length contained in ID_STATIC text. Used for limit
	//for GetWindowText(). Adds 1 because function does not count null terminating
	//string character. Secondly, additional 2 chars are for adding two spaces. 'editTextSize'
	//is added to ensure array is accommodating to the text added from ID_EDIT
	const int staticTextSize = GetWindowTextLength(staticHandle) + editTextSize + 3;

	//Dynamically allocates a LPSTR array used for GetWindowText()
	//LPSTR array is size according to return of GetWindowTextLength() + 4
	LPSTR staticText = new char[staticTextSize];

	//ID_STATIC text is retrieved and stored into 'staticText'
	GetWindowText(staticHandle, staticText, staticTextSize);

	//initializes a counting variable
	int editIndex = 0;

	//Initializes a variable to calculate the size of
	//the static text before additional positions were added
	//such as editTextSize and 3
	const int staticRealTextSize = staticTextSize - editTextSize - 3;

	switch (buttonID)
	{
	case ID_BUTTONLPARENTHESIS:
	{
		//Initializes a variable to calculate the size of
		//the static text before additional positions were added
		//such as editTextSize and 3
		const int staticRealTextSize = staticTextSize - editTextSize - 3;

		//Adds a '(' to the end of ID_STATIC. Uses 'staticRealText' to
		//position at end of ID_STATIC text
		staticText[staticRealTextSize + 1] = '\0';
		staticText[staticRealTextSize] = '(';

		//Updates ID_STATIC's text to match 'staticText'
		SetWindowText(staticHandle, staticText);

		//deletes dynamically allocated pointers
		delete[] staticText;
		delete[] editText;

		//Updates object member iLastButtonClicked to reflect 
		//button clicked in window. Value used in math operations
		//function
		parentClass.setiLastButtonClicked(buttonID);

		//function is successful
		return true;
	}

	case ID_BUTTONRPARENTHESIS:
	{
		//initializes a counting variable
		int editIndex = 0;

		//Initializes a variable to calculate the size of
		//the static text before additional positions were added
		//such as editTextSize and 3
		const int staticRealTextSize = staticTextSize - editTextSize - 3;

		//fills the rest of the values of staticText with the values
		//from editText
		for (int i = (staticRealTextSize); i < staticTextSize; i++)
		{
			//if current index of editText contains null terminating string
			//character than end of string has been reached and should exit
			//copy loop
			if (editText[editIndex] == '\0') break;

			//i starts as the position after last char is string. No
			//null string char is currently in staticText
			staticText[i] = editText[editIndex];

			//increments the editText index counter
			editIndex++;
		}

		//'staticTextSize' accounts for an additional 3 chars when initialized. This
		//was done for math operations '/' '*' '-' '+'. Parenthesis don't require
		//this additional chars. The last two chars of this string account for this
		//by subtracting the 3 out in addition to what was needed at the end of the string.
		staticText[staticTextSize - 4] = ')';
		staticText[staticTextSize - 3] = '\0';

		//updates ID_STATIC to contents of 'staticHandle'
		SetWindowText(staticHandle, staticText);

		//Resets ID_EDIT value to '0'
		SetWindowText(editHandle, (LPSTR)"0");

		//deletes dynamically allocated pointers
		delete[] staticText;
		delete[] editText;

		//Updates object member iLastButtonClicked to reflect 
		//button clicked in window. Value used in math operations
		//function
		parentClass.setiLastButtonClicked(buttonID);

		//function is successful
		return true;
	}
	}// --end switch--

	//When 'staticRealTextSize' is 0 than nothing has been added
	//yet. Add ID_EDIT content first than add math operator
	if (staticRealTextSize == 0)
	{
		//When 'editText' only contains '.' value '0' will be used instead.
		//This skips the normal procedure of copying the contents of 'editText'
		//into 'staticText'
		if ((editText[0] == '.') & (editTextSize == 2))
		{
			//appends a '0' to 'staticText'
			staticText[staticRealTextSize] = '0';
		}
		else
		{
			//fills the rest of the values of staticText with the values
			//from editText
			for (int i = (staticRealTextSize); i < staticTextSize; i++)
			{
				//if current index of editText contains null terminating string
				//character than end of string has been reached and should exit
				//copy loop
				if (editText[editIndex] == '\0') break;

				//i starts as the position after last char is string. No
				//null string char is currently in staticText
				staticText[i] = editText[editIndex];

				//increments the editText index counter
				editIndex++;
			}
		}

		//adds a space after the text in staticText
		staticText[editTextSize - 1] = ' ';

		//adds the math operator
		staticText[editTextSize] = *Defines::IDtoLPCSTR(buttonID);

		//adds a space before adding the editText to string
		staticText[editTextSize + 1] = ' ';
	}
	//When the last char in 'staticText' is a ')' just needs to add a
	//space than the math operator than a space (eg. "(34 + 45) + ")
	else if (staticText[staticRealTextSize - 1] == ')')
	{
		//adds a space after the text in staticText
		staticText[staticRealTextSize] = ' ';

		//adds the math operator
		staticText[staticRealTextSize + 1] = *Defines::IDtoLPCSTR(buttonID);

		//adds a space before adding the editText to string
		staticText[staticRealTextSize + 2] = ' ';

		//adds null terminating string char to staticText to complete
		//the string
		staticText[staticRealTextSize + 3] = '\0';
	}
	//When ID_EDIT contains only a '.' than ID_STATIC should
	//get a '0' instead
	else if ((editText[0] == '.') & (editTextSize == 2))
	{
		//appends a '0' to 'staticText'
		staticText[staticRealTextSize] = '0';

		//adds a space after the '0' in 'staticText'
		staticText[staticRealTextSize + 1] = ' ';

		//adds the math operator
		staticText[staticRealTextSize + 2] = *Defines::IDtoLPCSTR(buttonID);

		//adds a space after the math operator in 'staticText'
		staticText[staticRealTextSize + 3] = ' ';

		//adds null terminating string char to staticText to complete
		//the string
		staticText[staticRealTextSize + 4] = '\0';
	}
	//checks if the text in ID_STATIC contains the two space or if ID_STATIC has a '(' at the end.
	//One space before a math operation and the space after the math operation. If it does it 
	//appends the ID_EDIT text to the end of ID_STATIC 
	else if ((staticText[staticRealTextSize - 1] == ' ') & (staticText[staticRealTextSize - 3] == ' ') ||
		(staticText[staticRealTextSize - 1] == '('))
	{
		//fills the rest of the values of staticText with the values
		//from editText
		for (int i = (staticRealTextSize); i < staticTextSize; i++)
		{
			//if current index of editText contains null terminating string
			//character than end of string has been reached and should exit
			//copy loop
			if (editText[editIndex] == '\0') break;

			//i starts as the position after last char is string. No
			//null string char is currently in staticText
			staticText[i] = editText[editIndex];

			//increments the editText index counter
			editIndex++;
		}

		//adds a space after the text in staticText
		staticText[staticTextSize - 4] = ' ';

		//adds the math operator
		staticText[staticTextSize - 3] = *Defines::IDtoLPCSTR(buttonID);

		//adds a space before adding the editText to string
		staticText[staticTextSize - 2] = ' ';
	}

	//adds null terminating string char to staticText to complete
	//the string
	staticText[staticTextSize - 1] = '\0';

	//updates ID_STATIC with the new text
	SetWindowText(staticHandle, staticText);

	//deletes dynamically allocated pointers
	delete[] staticText;
	delete[] editText;

	//Updates object member iLastButtonClicked to reflect 
	//button clicked in window. Value used in math operations
	//function
	parentClass.setiLastButtonClicked(buttonID);

	//function is successful
	return true;
}

bool BUTTONS::CLICKED::Equal()
{
	//Retrieves ID_STATIC handle
	HWND staticHandle = GetDlgItem(parentClass.getparentHwnd(), ID_STATIC);

	//Declare constant for length of ID_STATIC text
	const int staticTextSize = GetWindowTextLength(staticHandle);

	//Retrieves ID_EDIT handle
	HWND editHandle = GetDlgItem(parentClass.getparentHwnd(), ID_EDIT);

	//Declares constant int for length of ID_EDIT text
	const int editTextSize = GetWindowTextLength(editHandle);

	//Dynamically creates LPSTR for ID_STATIC
	LPSTR staticText = new char[staticTextSize];

	//Fills the text string with value from ID_Static
	GetWindowText(staticHandle, staticText, staticTextSize);

	//Dynamically creates LPSTR for ID_EDIT
	LPSTR editText = new char[editTextSize];


	delete [] staticText;
	delete [] editText;

	return true;
}


xyButton BUTTONS::getButtonDimensions(HWND parentHandle, LPCSTR windowName) const
{
	//----------Variable Declarations----------
	HWND buttonHandle;
	RECT rect;
	xyButton button{ 0,0,0,0 };

	//finds the handle to control button
	buttonHandle = FindWindowEx(parentHandle, NULL, TEXT("button"), windowName);

	//gets the width and height of the button control and stores in struct rect
	GetClientRect(buttonHandle, &rect);

	//stores rect data into 'button' structure
	button.width = rect.right;
	button.height = rect.bottom;

	//zeros rect values
	rect = { 0,0,0,0 };

	//retrieves the position of the control relative to the client of the parent window
	//x and y position of 'button' structure are positions in the client area of parent window
	MapWindowPoints(buttonHandle, parentHandle, (LPPOINT)&rect, 2);

	//transfers rect structure values to corresponding values of struct xyButtons
	button.x = rect.right;
	button.y = rect.bottom;

	//returns filled structure
	return button;
}

//---------------------------------------
//---------------------------------------
//Get Functions: Contains only a single
//	line of code returning the value. All
//	get functions more complex must be
//	commented separately.
//---------------------------------------
//---------------------------------------
HWND BUTTONS::getparentHwnd() const
{
	return parentHwnd;
}

bool BUTTONS::getButton0() const
{
	return bButton0;
}

bool BUTTONS::getButton1() const
{
	return bButton1;
}

bool BUTTONS::getButton2() const
{
	return bButton2;
}

bool BUTTONS::getButton3() const
{
	return bButton3;
}

bool BUTTONS::getButton4() const
{
	return bButton4;
}

bool BUTTONS::getButton5() const
{
	return bButton5;
}

bool BUTTONS::getButton6() const
{
	return bButton6;
}

bool BUTTONS::getButton7() const
{
	return bButton7;
}

bool BUTTONS::getButton8() const
{
	return bButton8;
}

bool BUTTONS::getButton9() const
{
	return bButton9;
}

bool BUTTONS::getButtonMINUS() const
{
	return bButtonMINUS;
}

bool BUTTONS::getButtonPLUS() const
{
	return bButtonPLUS;
}

bool BUTTONS::getButtonMULTI() const
{
	return bButtonMULTI;
}

bool BUTTONS::getButtonDIVISION() const
{
	return bButtonDIVISION;
}

bool BUTTONS::getButtonDOT() const
{
	return bButtonDOT;
}

bool BUTTONS::getButtonEQUAL() const
{
	return bButtonEQUAL;
}

bool BUTTONS::getButtonCLEAR() const
{
	return bButtonCLEAR;
}

bool BUTTONS::getButtonDEL() const
{
	return bButtonDEL;
}

bool BUTTONS::getButtonLPARENTHESIS() const
{
	return bButtonLPARENTHESIS;
}

bool BUTTONS::getButtonRPARENTHESIS() const
{
	return bButtonRPARENTHESIS;
}

int BUTTONS::getiLastButtontClicked() const
{
	return iLastButtonClicked;
}

//---------------------------------------
//---------------------------------------
//Set Functions: Contains only a single
//	line of code setting the value. All
//	set functions more complex must be
//	commented separately.
//---------------------------------------
//---------------------------------------
void BUTTONS::setparentHwnd(HWND theParentHandle)
{
	parentHwnd = theParentHandle;
}

void BUTTONS::setButton0(bool value)
{
	bButton0 = value;
}

void BUTTONS::setButton1(bool value)
{
	bButton1 = value;
}

void BUTTONS::setButton2(bool value)
{
	bButton2 = value;
}

void BUTTONS::setButton3(bool value)
{
	bButton3 = value;
}

void BUTTONS::setButton4(bool value)
{
	bButton4 = value;
}

void BUTTONS::setButton5(bool value)
{
	bButton5 = value;
}

void BUTTONS::setButton6(bool value)
{
	bButton6 = value;
}

void BUTTONS::setButton7(bool value)
{
	bButton7 = value;
}

void BUTTONS::setButton8(bool value)
{
	bButton8 = value;
}

void BUTTONS::setButton9(bool value)
{
	bButton9 = value;
}

void BUTTONS::setButtonMINUS(bool value)
{
	bButtonMINUS = value;
}

void BUTTONS::setButtonPLUS(bool value)
{
	bButtonPLUS = value;
}

void BUTTONS::setButtonMULTI(bool value)
{
	bButtonMULTI = value;
}

void BUTTONS::setButtonDIVISION(bool value)
{
	bButtonDIVISION = value;
}

void BUTTONS::setButtonDOT(bool value)
{
	bButtonDOT = value;
}

void BUTTONS::setButtonEQUAL(bool value)
{
	bButtonEQUAL = value;
}

void BUTTONS::setButtonCLEAR(bool value)
{
	bButtonCLEAR = value;
}

void BUTTONS::setButtonDEL(bool value)
{
	bButtonDEL = value;
}

void BUTTONS::setButtonLPARENTHESIS(bool value)
{
	bButtonLPARENTHESIS = value;
}

void BUTTONS::setButtonRPARENTHESIS(bool value)
{
	bButtonRPARENTHESIS = value;
}


bool BUTTONS::setiLastButtonClicked(int buttonID)
{
	if ((buttonID >= 200) & (buttonID <= 219))
	{
		//if buttonID is within in the range of 200-219 than
		//actual parameter is within range of valid button id.
		iLastButtonClicked = buttonID;

		//successfully changed value to buttonID return;
		if (iLastButtonClicked == buttonID) return true;
	}

	//if buttonID is not within the range of 200-219 than
	//actual parameter is not a valid button id.
	return false;
}
