/********************************************************************
					HEADER FILE - MATHPARSER.h
							Made By
						ProfoundDisputes
**********************************************************************/

#include "MathParser.h"

bool MATHPARSER::extractAllNumbers(char* textToExtract, int* intArray, int textLength, int intLength) const
{

	return true;
}

int MATHPARSER::countNumbers(char* text, int textLength) const
{
	//Stores the amount of number hits from 'text'
	int count;
	bool isNum = false;

	//First loop for searching array
	for (int i = 1; i <= textLength; i++)
	{


		if (isNum == false)
		{
			if (text[i - 1] == ' ')
			{

			}
		}
	}

	return count;
}

bool MATHPARSER::isNum(char character) const
{
	switch (character])
	{

	case '0':
		return true;
		break;
	case '1':
		return true;
		break;
	case '2':
		return true;
		break;
	case '3':
		return true;
		break;
	case '4':
		return true;
		break;
	case '5':
		return true;
		break;
	case '6':
		return true;
		break;
	case '7':
		return true;
		break;
	case '8':
		return true;
		break;
	case '9':
		return true;
		break;
	default:
		return false;
		break;

	}
}