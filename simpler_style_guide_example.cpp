// Sample file using the Google C++ coding standard.
// http://google-styleguide.googlecode.com/svn/trunk/cppguide.xml
// Video example of google style guide
// https://www.youtube.com/watch?v=dPULxf6f-vs

// General rules:
//   - Indents are two spaces. No tabs should be used anywhere.
//   - Each line must be at most 80 characters long.
//   - Comments can be // or /* but // is most commonly used.
//   - File names should be lower_case.c or lower-case.c

// Header Files must be located at the top of your code before
// any other statements are created
// There is an order for the types of headers
//   1. C system headers
//   2. C++ standard library headers
//   3. User-defined libraries headers
#include <stdlib.h>
#include <iostream>
#include "header_file.h"

// use variable names that are easy to be understood
// use valid variable names such as "name" not "1name" or "float"
int main()
{
    int var;
}