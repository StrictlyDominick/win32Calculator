/********************************************************************
					HEADER FILE - MATHPARSER.h
							Made By
						ProfoundDisputes
**********************************************************************/

#include "MathParser.h"
#include <stdlib.h>

int* MATHPARSER::extractAllNumbers(char* textToExtract, int textLength) const
{
	//Retrieve amount of numbers in 'textToExtract'
	const int AMOUNTOFNUMS = countNumbers(textToExtract, textLength);

	//Dynamically creates pointer of size 'AMOUNTOFNUMS' for storing all numbers
	int* workingSetNums = new int[AMOUNTOFNUMS];

	//int array to store first and last position in string containing a number
	int iPosition[2] = { -1,-1 };

	//a temp char string for storing the number as a string before converting to int
	char tempString[10];

	//integer for keeping track of how many integers was placed in 'workingSetNums'
	int iUsed = 0;

	//Loop for iterating through array. Finding all the numbers and extracting them
	//into workingSetNums in left to right order.
	for (int i = 0; i < textLength; i++)
	{
		//when current position, 'i', is a number and a starting position has not
		//been set than current position becomes starting position of new number.
		//Starting position also occurs when a negative number is present. If 
		//current position, 'i', is a '-' char while also followed by a number
		//than current position becomes starting position of new number.
		if ((isNum(textToExtract[i]) & (iPosition[0] == -1)) ||
			((textToExtract[i] == '-') & (isNum(textToExtract[i+1]))))
		{
			//stores the first position of number in string 'textToExtract'
			iPosition[0] = i;
		}
		//The last position of a number occurs when there is no longer a number after
		//the starting position is set.
		else if (!isNum(textToExtract[i]) & iPosition[0] != -1)
		{
			iPosition[1] = i;

			//fill loop to fill 'tempString' with number from 'textToExtract'
			for (int iTextPo = iPosition[0], iTempPo = 0; iTextPo <= iPosition[1]; iTextPo++, iTempPo++)
			{
				tempString[iTempPo] = textToExtract[iTextPo];
			}

			//add a null terminating string character to tempString
			tempString[(iPosition[1] - iPosition[0]) + 1] = '\0';

			//reset 'position' int values to default -1 value
			iPosition[0] = -1;
			iPosition[1] = -1;

			//convert character string to integer
			workingSetNums[iUsed] = atoi(tempString);

			//defaults tempString
			char tempString[] = { '+', '+', '+', '+', '+', '+', '+', '+', '+', '+' };

			//increment 'used'
			iUsed++;

		}
		else if ((i == textLength - 1) & isNum(textToExtract[i]))
		{
			iPosition[1] = i;

			//fill loop to fill 'tempString' with number from 'textToExtract'
			for (int textPo = iPosition[0], tempPo = 0; textPo <= iPosition[1]; textPo++, tempPo++)
			{
				tempString[tempPo] = textToExtract[textPo];
			}

			//add a null terminating string character to tempString
			tempString[(iPosition[1] - iPosition[0]) + 1] = '\0';

			//reset 'position' int values to default -1 value
			iPosition[0] = -1;
			iPosition[1] = -1;

			//convert character string to integer
			workingSetNums[iUsed] = atoi(tempString);

			//defaults tempString
			char tempString[] = { '+', '+', '+', '+', '+', '+', '+', '+', '+', '+' };

			//increment 'used'
			iUsed++;

		}
	}
	return workingSetNums;
}

int MATHPARSER::countNumbers(char* text, int textLength, bool delimited) const
{
	//Stores the amount of number hits from 'text'
	int count = 0;

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
			else if ((i == (textLength - 1)) & isNum(text[i]))
			{
				//increment 'count'
				count++;
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