/********************************************************************
						win32Calculator
							  By
						ProfoundDisputes

	Purpose:
		A simple replication of the windows calculator. Basic
		functions will include typing in equation to be calculated;
		these can be multiplication ,addition, subtraction and 
		division. Parenthesis can be used too prioritize order in 
		calculation. Buttons for numbers 0-9, addition and subtraction,
		multiplication and division, clear, and equal button.
	Goal:
		GUI will be implemented by win32 API via C++. Idea of
		project is to fully implement and understand, at a basic level,
		the fundamentals of win32 API based applications. An emphasis
		will be made to make classes whenever possible to allow portability
		while also giving a strong understanding of structuring applications
		for Object Oriented design.

	Third Party Dependencies:
		None

	Notes:

	TODO:
		-Comment all finished functions. (Should be done as you go)
		-3-6-2018 10:00pm
		 Most functions return bool values to indicating whether the
		 the function ran correctly or not. These functions are not
		 checked for 'true' often when used. Makes sure all functions
		 check the return value and act accordingly.
		-3-6-2018 10:30PM
		 MathOperator function in BUTTONS::CLICKED needs to check the
		 the value of 'buttonID'; currently, entering any int will cause
		 the function to return true. This is not how it should be.
		-3-15-2018 6:35am
		 Implement a limit to how long the equation can get in ID_EDIT
		 ID_EDIT can't exceed the size of its container. Also allows 
		 assumptions on the maximum size of the string contained in
		 the text field.
		-4-22-2018 7:11pm
		 extractAllNumbers() function within MathPaser.cpp needs to be
		 updated to include grabing numbers even when they are decimals

**********************************************************************/

//------INCLUDES------
#include <windows.h>
#include "BUTTONS.h"
#include "ControlIDDefines.h"

//linking visual theme from compiler directive
#pragma comment(linker,"\"/manifestdependency:type='win32' \
name='Microsoft.Windows.Common-Controls' version='6.0.0.0' \
processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")

//----------Function Prototypes----------

//Standard WinProc function for catching windows messages. See Official
//documentation.
//PostCondition:	See official Documentation
//PreCondition :	See Official Documentation
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

//Initializes window class by creating WNDCLASSEX object and
//initializing members. Upon return will register the class
//using RegisterClassEx() function; return value
//type 'ATOM' is returned value from RegisterClassEx().
//See Official Microsoft Documentation for more details.
//PostCondition:	A window Class is initialized and
//					registered in windows.
//PreCondition :	Calls the following members from <windows.h>:
//					RegisterClassEx(), WNDCLASSEX
ATOM InitiWinClass(HINSTANCE hInstance, LPCSTR AppName);

//Initializes windows creation. Calls CreateWindowEx() for
//parent window. Specifies the window class, window title,
//window style, and (optionally) the initial position and 
//size of the window. Will also update window using 
//UpdateWindow().
//PostCondition:	Parent window is created.
//PreCondition :	Uses the following members from <windows.h>:
//					CreateWindowEx(), ShowWindow(),
//					UpdateWindow(), HWND
HWND InitiWindowInstance(HINSTANCE hInstance, int iCmdShow);

//Creates the only edit box (ID_EDIT) in UI. Edit box
//is used for only user inputted equations. Will return
//handle to the edit box. Handle returned is directly from
//CreateWindowEx() return value.
//PostCondition:	ID_EDIT is created in parent window. Returns
//					handle from CreateWindowEx().
//PreCondition :	Handle to the parent window is parentHwnd.
//					Uses the following member functions:
//					<windows.h> GetClientRect(), CreateWindowEx()
HWND createEDITBOX(HWND parentHwnd);

//Sets the size an style of font or ID_ButtonFont. Sets too
//"Cambria Math" at 20 size. Will return false
//if CreateFont() returns null. Uses
//SendDlgItemMessage() function to send WM_SETFONT
//to ID_ButtonFont.
//PostCondition:	Changes font in all control ID_BUTTON to
//					"Cambria Math" 20 size. Returns
//					true if CreateFont() is successful.
//PreCondition :	Formal parameter parentHwnd is the
//					handle to the parent window. Uses
//					the following member functions:
//					<windows.h> CreateFont(), GetDC(),
//						SendDlgItemMessage(), ReleaseDC()
bool setID_ButtonFont(HWND parentHwnd);

//Sets the size an style of font or ID_STATIC. Sets too
//"Calibri" at 12 size. Will return false
//if CreateFont() returns null. Uses
//SendDlgItemMessage() function to send WM_SETFONT
//to ID_ButtonFont.
//PostCondition:	Changes font in all control ID_BUTTON to
//					"Calibri" 12 size. Returns
//					true if CreateFont() is successful.
//PreCondition :	Formal parameter parentHwnd is the
//					handle to the parent window. Uses
//					the following member functions:
//					<windows.h> CreateFont(), GetDC(),
//						SendDlgItemMessage(), ReleaseDC()
bool setID_StaticFont(HWND parentHwnd);

//Sets the size an style of font or ID_EDIT. Sets too
//"Times New Roman" at 25 size. Will return false
//if CreateFont() returns null. Uses
//SendDlgItemMessage() function to send WM_SETFONT
//to ID_EDIT.
//PostCondition:	Changes font in control ID_EDIT to
//					"Times New Roman" 25 size. Returns
//					true if CreateFont() is successful.
//PreCondition :	Formal parameter parentHwnd is the
//					handle to the parent window. Uses
//					the following member functions:
//					<windows.h> CreateFont(), GetDC(),
//						SendDlgItemMessage(), ReleaseDC()	
bool setID_EDITFont(HWND parentHwnd);

//Creates the only static box (ID_STATIC) in UI. Located 
//directly above the ID_EDIT control. Will return the handle
//created from CreateWindowEx(). 
//PostCondition:	ID_STATIC control in created in parent window
//					Return value is the handle to ID_STATIC
//PreCondition :	Formal Parameter 'parentHwnd' is handle to
//					parent window. Uses the following member functions:
//					<windows.h> GetClientRect(), CreateWindowEx()
HWND createSTATICBOX(HWND parentHwnd);

//Checks the button ID passed to ensure its in the range
//of 200-212. Function will call 'button.Clicked' member function 
//associated with buttonID. If function is passed a invalid
//ID will return false.
//PostCondition:	Associated ID function is called from
//					'button' object. Will return true if successful
//					false if nothing was called
//PreCondition :	'buttonID' parameter must be in the range 200-212
//					Calls the following member functions:
//					BUTTONS: getparentHwnd()
//					BUTTONS:CLICKED: CLR(), DEL(), Numbers()
//					Windows.h: GetWindowTextLength(), GetDlgItem()
bool bnClickUpdateEditBox(int buttonID);

//----------Global Variables-------
static TCHAR szAppName[] = TEXT("win32Calculator");

//---------Global Objects----------
BUTTONS Button;

//----------MAIN------------
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	PSTR szCmdLine, int iCmdShow)
{
	//----------Object Initializations--------
	MSG msg;

	//Register window class 'wc' if the register fails
	//it requires Windows NT, creates message box stating this
	if (!InitiWinClass(hInstance, szAppName))
	{
		MessageBox(NULL, TEXT("This program requires Windows NT!"),
			szAppName, MB_ICONERROR);
		return 0;
	}

	//Initializes windows creation.
	InitiWindowInstance(hInstance, iCmdShow);

	//Message Loop
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_CREATE:
	{
		//found off of forum - prevents user from resizing window
		SetWindowLong(hwnd, GWL_STYLE, GetWindowLong(hwnd, GWL_STYLE)&~WS_SIZEBOX);

		//creates all buttons for calculator application
		Button.Create.All(hwnd);

		setID_ButtonFont(hwnd);

		//creates the edit control (ID_EDIT) for user inputted equations
		createEDITBOX(hwnd);

		//creates the static control, ID_STATIC
		createSTATICBOX(hwnd);

		return 0;
	}
	case WM_COMMAND:
	{
		//Buttons are in the 200 range. Test to ensure that wParam
		//contains ID in that range
		if ((LOWORD(wParam) >= 200) & (LOWORD(wParam) < 300))
		{
			//All buttons when clicked that add to the ID_EDIT text
			//are in the ranges 200-213. All other buttons either
			//calculate or are math operators. Math operators modify
			//both ID_STATIC and ID_EDIT working in the 213-218 rang
			//, which is why it has its own function. ID_BUTTONEQUAL
			//does lots of calculations and parsing that require a separate
			//function.
			if ((LOWORD(wParam) >= 200) & (LOWORD(wParam) < 213))
			{
				//Buttons in the range 200-212 all update only ID_EDIT text field
				bnClickUpdateEditBox(LOWORD(wParam));

			}
			else if ((LOWORD(wParam) >= 213) & (LOWORD(wParam) <= 218))
			{
				//Buttons in the range 213-218 are math operators and
				//update both ID_EDIT and ID_STATIC text fields. Function
				//handles these text fields
				Button.Clicked.MathOperator(LOWORD(wParam));

			}
			else if (LOWORD(wParam) == 219)
			{
				//Button ID 219 is ID_BUTTONEQUAL call ID_BUTTONEQUAL
				//execution code
				Button.Clicked.Equal();
			}
		}
		return 0;
	}

	//Checks keyboard input from user. Calls function from
	//BUTTON:CLICKED object matching virtual key
	case WM_KEYDOWN:

		switch (wParam)
		{
		//SHIFT + 9 OR '(' key
		case 0x39:
			if (GetAsyncKeyState(VK_SHIFT))
			{
				Button.Clicked.MathOperator(ID_BUTTONLPARENTHESIS);
				return 0;
			}
			break;

		//SHIFT + 0 OR ')' key
		case 0x30:
			if (GetAsyncKeyState(VK_SHIFT))
			{
				Button.Clicked.MathOperator(ID_BUTTONRPARENTHESIS);
				return 0;
			}
			break;

		//SHIFT + 8 OR '*' key
		case 0x38:
			if (GetAsyncKeyState(VK_SHIFT))
			{
				Button.Clicked.MathOperator(ID_BUTTONMULTI);
				return 0;
			}
			break;

		//'-' key
		case VK_OEM_MINUS:
			Button.Clicked.MathOperator(ID_BUTTONMINUS);
			return 0;

		//'/' key
		case VK_OEM_2:
			Button.Clicked.MathOperator(ID_BUTTONDIVISION);
			return 0;

		//'+' key
		case VK_OEM_PLUS:
			Button.Clicked.MathOperator(ID_BUTTONPLUS);
			return 0;

		//backspace key
		case VK_BACK:
			Button.Clicked.DEL();
			return 0;

		//'.' key
		case VK_DECIMAL:
			Button.Clicked.Numbers(ID_BUTTONDOT);
			return 0;

		//'.' key
		case VK_OEM_PERIOD:
			Button.Clicked.Numbers(ID_BUTTONDOT);
			return 0;
		}

		//Loop works by using common single digits. ID Buttons 0-9
		//start at 200-209. Subtracting 200 makes 0-9. All 
		//Virtual-key codes for 0-9 are 0x30-0x39 (0x60-0x69
		//for NUMKEYS). Subtracting 0x30 (0x60 for NUMKEYS) will
		//give you single digits 0-9. These #'s line up allowing
		//easy assessment of which button was clicked
		for (int i = 0; i <= 9; i++)
		{
			if (((wParam - 0x30) == ((ID_BUTTON0 + i) - 200)) ||
				((wParam - 0x60) == ((ID_BUTTON0 + i) - 200)))
			{
				Button.Clicked.Numbers(ID_BUTTON0 + i);
				return 0;
			}

		}

		return 0;

	case WM_KILLFOCUS:
	{
		//Disables user from putting keyboard focus on ID_EDIT
		//Use is not allowed to type directly into ID_EDIT
		if (GetDlgItem(hwnd, ID_EDIT) == (HWND)wParam)
		{
			//Changes focus back to main  parent window
			SetFocus(hwnd);
		}
		return 0;
	}
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, message, wParam, lParam);
}

ATOM InitiWinClass(HINSTANCE hInstance, LPCSTR szAppName)
{
	//Variables
	WNDCLASSEX wexc;

	//Sets the window class values
	wexc.cbSize = sizeof(WNDCLASSEX);
	wexc.style = CS_HREDRAW | CS_VREDRAW;
	wexc.lpfnWndProc = WndProc;
	wexc.cbClsExtra = 0;
	wexc.cbWndExtra = 0;
	wexc.hInstance = hInstance;
	wexc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wexc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wexc.hbrBackground = GetSysColorBrush(COLOR_BACKGROUND + 1);
	wexc.lpszMenuName = MAKEINTRESOURCE(ID_MENU);
	wexc.lpszClassName = szAppName;
	wexc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	//registers windows class
	return RegisterClassEx(&wexc);
}

HWND InitiWindowInstance(HINSTANCE hInstance, int iCmdShow)
{
	//defines handle for window
	HWND hwnd;

	//Creates and initializes parent window
	hwnd = CreateWindowEx(WS_EX_CONTROLPARENT, szAppName, // window class name
		TEXT("win32Calculator"), // window caption
		WS_OVERLAPPEDWINDOW, // window style
		CW_USEDEFAULT, // initial x position
		CW_USEDEFAULT, // initial y position
		244, // initial x size
		410, // initial y size
		NULL, // parent window handle
		NULL, // window menu handle
		hInstance, // program instance handle
		NULL); // creation parameters

//Sets the specified window's show state.
	ShowWindow(hwnd, iCmdShow);

	//updates the client area of the specified window
	UpdateWindow(hwnd);

	return hwnd;
}

HWND createEDITBOX(HWND parentHwnd)
{
	//--------Variable Declarations--------
	HWND editHandle;
	RECT rect;

	//retrieves the client coordinates from parent window
	//these cords will be used for positioning the edit window
	GetClientRect(parentHwnd, &rect);

	//Creates ID_EDIT window and stores the returned handle from CreateWindowEx()
	editHandle = CreateWindowEx(NULL, TEXT("edit"), TEXT("0"),
		WS_VISIBLE | WS_TABSTOP | WS_CHILD | ES_RIGHT | ES_NUMBER, rect.right - 224, rect.bottom - 300,
		220, 40, parentHwnd, (HMENU)ID_EDIT, NULL, NULL);

	//sets the font for the ID_EDIT control to
	//"Times New Roman" 25 font
	setID_EDITFont(parentHwnd);

	return editHandle;
}

bool setID_ButtonFont(HWND parentHwnd)
{
	//--------Variable Declarations--------
	HFONT hf;
	HDC hdc;
	long lfHeight;

	//Gets the DC handle
	hdc = GetDC(NULL);

	//Converts pixel size to logical units size for CreateFont()
	lfHeight = -MulDiv(20, GetDeviceCaps(hdc, LOGPIXELSY), 72);
	ReleaseDC(NULL, hdc);

	//Creates the font and stores the returned result
	hf = CreateFont(lfHeight, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "Cambria Math");

	//Checks if CreateFont returned a valid value
	if (!hf)
	{
		MessageBox(parentHwnd, "Font creation failed!", "Error", MB_OK | MB_ICONEXCLAMATION);
		return false;
	}

	//Sets the font for all ID buttons. Loop will increment through all
	//button ID's and send WM_SETFONT message to them
	for (int i = 0; i < 20; i++)
	{
		SendDlgItemMessage(parentHwnd, ID_BUTTON0 + i, WM_SETFONT, (WPARAM)hf, TRUE);
	}
	

	return true;
}

bool setID_StaticFont(HWND parentHwnd)
{
	//--------Variable Declarations--------
	HFONT hf;
	HDC hdc;
	long lfHeight;

	//Gets the DC handle
	hdc = GetDC(NULL);

	//Converts pixel size to logical units size for CreateFont()
	lfHeight = -MulDiv(12, GetDeviceCaps(hdc, LOGPIXELSY), 72);
	ReleaseDC(NULL, hdc);

	//Creates the font and stores the returned result
	hf = CreateFont(lfHeight, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "Calibri");

	//Checks if CreateFont returned a valid value
	if (!hf)
	{
		MessageBox(parentHwnd, "Font creation failed!", "Error", MB_OK | MB_ICONEXCLAMATION);
		return false;
	}

	//sends WM_SETFONT to ID_STATIC to change font
	SendDlgItemMessage(parentHwnd, ID_STATIC, WM_SETFONT, (WPARAM)hf, TRUE);

	return true;
}

bool setID_EDITFont(HWND parentHwnd)
{
	//--------Variable Declarations--------
	HFONT hf;
	HDC hdc;
	long lfHeight;

	//Gets the DC handle
	hdc = GetDC(NULL);

	//Converts pixel size to logical units size for CreateFont()
	lfHeight = -MulDiv(25, GetDeviceCaps(hdc, LOGPIXELSY), 72);
	ReleaseDC(NULL, hdc);

	//Creates the font and stores the returned result
	hf = CreateFont(lfHeight, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "Times New Roman");

	//Checks if CreateFont returned a valid value
	if (!hf)
	{
		MessageBox(parentHwnd, "Font creation failed!", "Error", MB_OK | MB_ICONEXCLAMATION);
		return false;
	}

	//sends WM_SETFONT to ID_EDIT to change font
	SendDlgItemMessage(parentHwnd, ID_EDIT, WM_SETFONT, (WPARAM)hf, TRUE);

	//Success return true
	return true;
}

HWND createSTATICBOX(HWND parentHwnd)
{
	//--------Variable Declarations--------
	HWND staticHandle;
	RECT rect;

	//Gets parent window client size for positioning of ID_STATIC
	GetClientRect(parentHwnd, &rect);

	//Creates ID_STATIC and stores the returned handle
	staticHandle = CreateWindowEx(NULL, TEXT("static"), TEXT("\0"),
		WS_VISIBLE | WS_CHILD | ES_RIGHT, rect.right - 224, rect.bottom - 370,
		220, 70, parentHwnd, (HMENU)ID_STATIC, NULL, NULL);

	//Sets the font for ID_STATIC
	setID_StaticFont(parentHwnd);

	//returns return handle from CreateWindowEx()
	return staticHandle;
}

bool bnClickUpdateEditBox(int buttonID)
{
	//retrieves handle to ID_EDIT. Handle used to get text size
	HWND editHandle = GetDlgItem(Button.getparentHwnd(), ID_EDIT);

	//gets the char array length contained in ID_EDIT text. Used for limit
	//for GetWindowText(). Adds 1 because function does not count the null
	//terminating string char. Adds 2 to account for the added number after
	//button is clicked
	const int editTextSize = GetWindowTextLength(editHandle) + 2;

	//First switch checks for the 'del' and 'clr' buttons.
	//After this switch contains a if check for amount of chars in
	//edit box text. No additional char are to be added if editTextSize >= 14
	switch (buttonID)
	{
	case ID_BUTTONCLEAR:
		return Button.Clicked.CLR();

	case ID_BUTTONDEL:
		return Button.Clicked.DEL();

	}

	//Makes sure that actual parameter 'buttonID' is a value
	//between 200-212. This is the range that number represents
	//buttons 0-9 and '.' button. 
	if ((buttonID >= 200) & (buttonID < 213))
	{
		//Returns true if button ran code successfully
		return Button.Clicked.Numbers(buttonID);
	}
	else
	{
		//If 'buttonID' isn't within correct range for 
		//'Button.Clicked.Numbers()' than function failed
		//to run successfully return false
		return false;
	}

}

