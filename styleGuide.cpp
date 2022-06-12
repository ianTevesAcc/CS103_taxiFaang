// Sample file using the Google C++ coding standard.
// http://google-styleguide.googlecode.com/svn/trunk/cppguide.xml
// Video example of google style guide
// https://www.youtube.com/watch?v=dPULxf6f-vs

// General Rules
// •	Indents are two spaces. No tabs shoud be used anywhere
// •	Each line must be at most 80 characters long
// •	Comments can be // or /* but // is most commonly used
// •	File name should be lower_case.c or lower-case.c
// •	variable names must be lower_case
// •	Function Names must be CAPITAL_CASE
// •	Structure Names must be a Mix_Case

// Header Files must be locareated
// There is an order for the headers at the top of your code before
// any other statements are ctypes of headers
//   1. C system headers
//   2. C++ standard library headers
//   3. User-defined libraries headers
#include <stdlib.h>
#include <iostream>
// #include "header_file.h" //// commented out as this isn't used, so it appears as an error in the program

// use variable names that are easy to be understood
// use valid variable names such as "name" not "1name" or "float"
int main()
{
	int var;
}