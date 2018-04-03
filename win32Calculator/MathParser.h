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

	int countNumbers(char* text, int textLength) const;
private:

};

#endif // !MATHPARSER.h