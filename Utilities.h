// Miscellaneous utility functions
#ifndef UTILITIES_H
#define UTILITIES_H

#include <string>

namespace util
{
	struct Utilities
	{
	public:
		static std::string toLower(std::string); // converts to lowercase
		static std::string toUpper(std::string); // converts to uppercase
		static std::string captialize(std::string); // capitalizes a string
		static bool equalsIgnoreCase(std::string, std::string); // sees if two strings are equal to each other, ignoring case differences
		static bool isNum(std::string); //checks if a string is a number
	private:
	};
}

#endif UTILITIES_H