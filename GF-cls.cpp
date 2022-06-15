#include <iostream>
#include "GFglobal_functions.h"

void cls()
{
#ifdef _WIN32
    int OSver = 1;

// Checking for mac OS with
// __APPLE__ macro
#elif __APPLE__
    int OSver = 2;

// Checking for linux OS with
// __linux__ macro
#elif __linux__
    int OSver = 3;

#endif

    if (OSver == 1)
    {
        system("cls");
    }
    else if (OSver == 2 || OSver == 3)
    {
        system("clear");
    }
}