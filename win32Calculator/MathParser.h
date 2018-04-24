/********************************************************************
							MathParser.h
								By
							ProfoundDisputes
**********************************************************************/

#pragma once
#ifndef MATHPARSER_H

class MATHPARSER
{
public:
	int * extractAllNumbers(char* textToExtract, int textLength) const;

	//Count numbers contained in char string in two different ways depending on optional param.
	//If "delimited" is true it will count consecutive numbers as a single number. For example
	//"121d32sde" will count as 2 numbers; without delimiter enabled "121d32sde" will count
	//as 5 numbers. Once numbers have been counted it will return the tallied amount as integer.
	//Postcondition:	Will return integer showing tallied amount of numbers contained in 
	//					'text'. Return value will change depending on 'delimited' value.
	//Precondition :	'textLength' must be the size of the array
	int countNumbers(char* text, int textLength, bool delimited = false) const;

	bool isNum(char character) const;
private:

};

#endif // !MATHPARSER.h