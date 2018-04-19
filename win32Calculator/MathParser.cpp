/********************************************************************
					HEADER FILE - MATHPARSER.h
							Made By
						ProfoundDisputes
**********************************************************************/

#include "MathParser.h"

int* MATHPARSER::extractAllNumbers(char* textToExtract, int* intArray, int textLength, int intLength) const
{

	return true;
}

int MATHPARSER::countNumbers(char* text, int textLength, bool delimited) const
{
	//Stores the amount of number hits from 'text'
	int count = 0;
	char tempChar;

	//If delimited is true it will count consecutive numbers as a single number.
	//For example "121d32sde" will count as 2 numbers; without delimiter
	//enabled "121d32sde" will count as 5 numbers
	if (delimited == true)
	{
		//Will loop through each element in array. Each time checking
		//if its a number or not and incrementing 'count' as appropriate
		for (int i = 1; i < textLength; i++)
		{
			//Loop works by always finding the non-number char.
			if (!isNum(text[i]))
			{
				
				//Once the non-number char is found you need to check
				//if the previous char was a number; happens if there
				//is a consecutive string of numbers such as "1234a".
				if (isNum(text[i - 1]))
				{
					//increment count
					count++;
				}
			}

		}
	}
	else
	{
		//Loop for incrementing through array elements. Will check each
		//char element for a number and count if true
		for (int i = 0; i <= textLength; i++)
		{
			//When array element is a number it counts toward total number count
			if (isNum(text[i]))
			{
				//increment count
				count++;
			}
		}
	}

	//Return the tallied number of number char's found
	return count;
}

bool MATHPARSER::isNum(char character) const
{
	//Checks all possible number char values against char
	switch (character)
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