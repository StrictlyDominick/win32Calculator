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
	bool extractAllNumbers(char* textToExtract, int* intArray, int textLength, int intLength) const;

	int countNumbers(const char* text, int textLength, bool delimited = false) const;

	bool isNum(char character) const;
private:

};

#endif // !MATHPARSER.h