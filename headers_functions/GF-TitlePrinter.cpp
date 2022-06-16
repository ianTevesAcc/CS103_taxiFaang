#include <iostream>
#include "GFglobal_functions.h"
using namespace std;

void TitlePrinter(string title)
{
    int total_spaces, space, space_print;
    total_spaces = title.length();
    space = 60 - total_spaces;
    space_print = space / 2;
    for (int i = 0; i != space_print; i++)
    {
        cout << " ";
    }
    cout << title << endl;
}