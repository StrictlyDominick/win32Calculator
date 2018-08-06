/********************************************************************
					HEADER FILE - BUTTONS_H
							Made By
						StrictlyDomininck
**********************************************************************/
#include "BUTTONS.h"
#include <cmath>
#include <cstdio>

//=====================================
//============	CREATE  ===============
//=====================================
bool BUTTONS::CREATE::All(HWND parenthwnd)
{
	parentClass.Create.Button(ID_BUTTONEQUAL, parenthwnd);

	//Creates top row (row 1) of buttons from left to right
	parentClass.Create.Button(ID_BUTTONLPARENTHESIS, parenthwnd);
	parentClass.Create.Button(ID_BUTTONRPARENTHESIS, parenthwnd);
	parentClass.Create.Button(ID_BUTTONDEL, parenthwnd);
	parentClass.Create.Button(ID_BUTTONDIVISION, parenthwnd);

	//Creates row 2 of buttons from left to right
	parentClass.Create.Button(ID_BUTTON7, parenthwnd);
	parentClass.Create.Button(ID_BUTTON8, parenthwnd);
	parentClass.Create.Button(ID_BUTTON9, parenthwnd);
	parentClass.Create.Button(ID_BUTTONMULTI, parenthwnd);

	//Creates row 3 of buttons from left to right
	parentClass.Create.Button(ID_BUTTON4, parenthwnd);
	parentClass.Create.Button(ID_BUTTON5, parenthwnd);
	parentClass.Create.Button(ID_BUTTON6, parenthwnd);
	parentClass.Create.Button(ID_BUTTONMINUS, parenthwnd);

	//Creates row 4 of buttons from left to right
	parentClass.Create.Button(ID_BUTTON1, parenthwnd);
	parentClass.Create.Button(ID_BUTTON2, parenthwnd);
	parentClass.Create.Button(ID_BUTTON3, parenthwnd);
	parentClass.Create.Button(ID_BUTTONPLUS, parenthwnd);

	//Creates row 5 of buttons from left to right
	//Except ButtonEQUAL since its used as a position
	//reference for all buttons it was created first
	parentClass.Create.Button(ID_BUTTONCLEAR, parenthwnd);
	parentClass.Create.Button(ID_BUTTON0, parenthwnd);
	parentClass.Create.Button(ID_BUTTONDOT, parenthwnd);

	//stores the parent handle in object member
	parentClass.setparentHwnd(parenthwnd);

	//function has created all buttons and updated the parent handle
	return true;
}

bool BUTTONS::CREATE::Button(int buttonID, HWND parenthwnd)
{
	//------Variable Decelerations------
	HWND buttonHandle;
	int index = buttonID - 200;

	//check array index is from 0-9 for numeric button creation
	if ((index < 0) & (index > 19))
	{
		return false;
	}
	else if (parentClass.getButtonCreated(buttonID))
	{
		return false;
	}
	//creates the button
	buttonHandle = CreateWindowEx(NULL, TEXT("button"), Defines::IDtoLPCSTR(buttonID),
		WS_VISIBLE | WS_TABSTOP | WS_CHILD, NumButtonsDetails[index].x, NumButtonsDetails[index].y, NumButtonsDetails[index].width,
		NumButtonsDetails[index].height, parenthwnd, (HMENU)buttonID, NULL, NULL);

	//if handle is null than button creation has failed
	if (!buttonHandle)
	{
		//exit program unsuccessfully
		return false;
	}

	//If passed handle check then button was created
	//set the flag for creation of ID_BUTTONEQUAL
	parentClass.setButtonCreated(buttonID, true);

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

	//Fills 'staticHandle' with value from ID_Static
	GetWindowText(staticHandle, staticText, staticTextSize);

	//Dynamically creates LPSTR for ID_EDIT
	LPSTR editText = new char[editTextSize];

	//Retrieves ID_EDIT text and stores in 'editText'
	GetWindowText(editHandle, editText, editTextSize);

	//Declares MATHPASER object for extracting math operators
	//and numbers from char strings
	MATHPARSER mathParser;

	//sets the how many numbers are contained in 'staticText'
	const int iTotalNumbers = mathParser.countNumbers(staticText, staticTextSize, true);

	//Dynamically allocates array for storing all numbers to be calculated
	double* iWorkingSetNumbers = new double[iTotalNumbers];

	iWorkingSetNumbers = mathParser.extractAllNumbers(staticText, staticTextSize);

	int found = mathParser.countOperations(staticText, staticTextSize);

	double check = -1;

	char* texts = new char[20];
	snprintf(texts, 20, "% .10g", iWorkingSetNumbers[0]);
	SetWindowText(editHandle, texts);

	for (int i = 0; i < iTotalNumbers; i++)
	{
		//check = iWorkingSetNumbers[0] * 1000000000000;
		//check = round(check)=
		//check = check / 1000000000000;
	}

	delete[] iWorkingSetNumbers;
	delete[] staticText;
	delete[] editText;

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

int BUTTONS::getiLastButtontClicked() const
{
	return iLastButtonClicked;
}

bool BUTTONS::getButtonCreated(int buttonID) const
{
	switch (buttonID)
	{
	case ID_BUTTON0:
	{
		return bButton0;
	}
	case ID_BUTTON1:
	{
		return bButton1;
	}
	case ID_BUTTON2:
	{
		return bButton2;
	}
	case ID_BUTTON3:
	{
		return bButton3;
	}
	case ID_BUTTON4:
	{
		return bButton4;
	}
	case ID_BUTTON5:
	{
		return bButton5;
	}
	case ID_BUTTON6:
	{
		return bButton6;
	}
	case ID_BUTTON7:
	{
		return bButton7;
	}
	case ID_BUTTON8:
	{
		return bButton8;
	}
	case ID_BUTTON9:
	{
		return bButton9;
	}
	case ID_BUTTONDOT:
	{
		return bButtonDOT;
	}
	case ID_BUTTONCLEAR:
	{
		return bButtonCLEAR;
	}
	case ID_BUTTONDEL:
	{
		return bButtonDEL;
	}
	case ID_BUTTONPLUS:
	{
		return bButtonPLUS;
	}
	case ID_BUTTONMINUS:
	{
		return bButtonMINUS;
	}
	case ID_BUTTONMULTI:
	{
		return bButtonMULTI;
	}
	case ID_BUTTONDIVISION:
	{
		return bButtonDIVISION;
	}
	case ID_BUTTONLPARENTHESIS:
	{
		return bButtonLPARENTHESIS;
	}
	case ID_BUTTONRPARENTHESIS:
	{
		return bButtonRPARENTHESIS;
	}
	case ID_BUTTONEQUAL:
	{
		return bButtonEQUAL;
	}

	}

	//fails if it gets here
	return false;
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

void BUTTONS::setButtonCreated(int button_to_set, bool value)
{
	switch (button_to_set)
	{
	case ID_BUTTON0:
	{
		bButton0 = value;
		break;
	}
	case ID_BUTTON1:
	{
		bButton1 = value;
		break;
	}
	case ID_BUTTON2:
	{
		bButton2 = value;
		break;
	}
	case ID_BUTTON3:
	{
		bButton3 = value;
		break;
	}
	case ID_BUTTON4:
	{
		bButton4 = value;
		break;
	}
	case ID_BUTTON5:
	{
		bButton5 = value;
		break;
	}
	case ID_BUTTON6:
	{
		bButton6 = value;
		break;
	}
	case ID_BUTTON7:
	{
		bButton7 = value;
		break;
	}
	case ID_BUTTON8:
	{
		bButton8 = value;
		break;
	}
	case ID_BUTTON9:
	{
		bButton9 = value;
		break;
	}
	case ID_BUTTONDOT:
	{
		bButtonDOT = value;
		break;
	}
	case ID_BUTTONCLEAR:
	{
		bButtonCLEAR = value;
		break;
	}
	case ID_BUTTONDEL:
	{
		bButtonDEL = value;
		break;
	}
	case ID_BUTTONPLUS:
	{
		bButtonPLUS = value;
		break;
	}
	case ID_BUTTONMINUS:
	{
		bButtonMINUS = value;
		break;
	}
	case ID_BUTTONMULTI:
	{
		bButtonMULTI = value;
		break;
	}
	case ID_BUTTONDIVISION:
	{
		bButtonDIVISION = value;
		break;
	}
	case ID_BUTTONLPARENTHESIS:
	{
		bButtonLPARENTHESIS = value;
		break;
	}
	case ID_BUTTONRPARENTHESIS:
	{
		bButtonRPARENTHESIS = value;
		break;
	}
	case ID_BUTTONEQUAL:
	{
		bButtonEQUAL = value;
		break;
	}
	}
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
