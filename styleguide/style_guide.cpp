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

// Order of Includes...
//   1. C system headers
//   2. C++ standard library headers
//   3. User-defined libraries headers
#include <stdlib.h>
#include <iostream> // using of streams to make writting of code faster
#include <fstream>
// #include "header_file.h" //// commented out as this isn't used, so it appears as an error in the program

using namespace std;

// Type Names should start with a capital letter for each new word
struct UserDataBase
{
	int age;
	enum kSize
	{
		a,
		b,
		c
	}; // enumerator names follow Type Name rules except they have a "k" before the name
};

// this is the same with functions
void DesignFunction()
{
	for (int i = 0; i < 20; ++i)
	{
		cout << "*";
	}

	cout << endl;
}

int main()
{
	cout << "STYLE GUIDE EXAMPLE" << endl;
	DesignFunction();

	// variables must be..
	// •	lower_case and seperated by underscores(_) or (-)
	// •	easy to understand name
	//	 •	instead of...
	//		 *	int u_age = 10; //// itis...
	// •	inclusive language
	// •	placed in the narrowest scope possible
	//	 •	instead of...
	//		 *	int user_age;
	//		 *	user_age = 10; //// it is...
	int user_age = 10;
	const int kUserSwag = 1; // constants follow Type Name rules but has "k" before the var name

	// do not use scopes and when used must be used in small portions of code only

	// preincrement and deincrement is done by ++a / --a
	--user_age;
	cout << user_age << endl; // output == 9

	UserDataBase *user = new UserDataBase;
	user->age = user_age;
	cout << user->age << endl; // output == 9

	// use variable rules for file names which is lowercase serperated by (_)
	ofstream test_file("style_guide.txt");
	test_file << user->age;
	test_file.close();

	// use nullptr for pointers and '\0' for char
	delete user;
	user = nullptr;

	return 0;
}