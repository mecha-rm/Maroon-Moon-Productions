// Random utility functions
#include "Utilities.h"

namespace util
{
	// converts a string to all lowercase
	std::string Utilities::toLower(std::string str)
	{
		// returns the string if its of length zero.
		if (str.length() == 0)
			return str;

		std::string strL;
		strL.assign(str); // copies original string

		for (int i = 0; i < strL.length(); i++)
		{
			strL.at(i) = tolower(strL.at(i)); // converts each 'char' to its lowercase version if applicable
		}

		return strL;
	}

	// converts a string to all uppercase
	std::string Utilities::toUpper(std::string str)
	{
		// returns the string if its of length zero.
		if (str.length() == 0)
			return str;

		std::string strL;
		strL.assign(str); // copies original string

		for (int i = 0; i < strL.length(); i++)
		{
			strL.at(i) = toupper(strL.at(i)); // converts each 'char' to its lowercase version if applicable
		}

		return strL;
	}

	// capitalizes the string
	std::string Utilities::captialize(std::string str)
	{
		// returns the string if its of length zero.
		if (str.length() == 0)
			return str;

		std::string strL;
		strL.assign(str); // copies original string

		str = toLower(str); // makes the string all lowercase
		str.at(0) = toupper(str.at(0)); // capitalizes the first letter

		return strL;
	}

	// compares two strings to see if they're equal, ignoring any case differences
	bool Utilities::equalsIgnoreCase(std::string str1, std::string str2)
	{
		// making both strings lowercase
		str1 = toLower(str1);
		str2 = toLower(str2);
		return str1 == str2; // returning whether the two are equal
	}

	//checks to see if a string is numeric
	bool Utilities::isNum(std::string str) {
		std::string arr[10] = { "1","2","3","4","5","6","7","8","9","0" };
		for (int x = 0; x < str.length(); x++) {
			for (int y = 0; y < 10; y++) {
				if (str.substr(x, 1) == arr[y]) {
					break;
				}
				else if (y == 9) {
					return false;
				}
			}
		}
		return true;
	}

}
