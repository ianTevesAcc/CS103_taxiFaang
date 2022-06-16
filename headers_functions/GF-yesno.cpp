#include <iostream>
#include "GFglobal_functions.h"
using namespace std;

bool yesno()
{
    string agree[5] = {"Yes", "yes", "Y", "y", "YES"};
    string disagreed[5] = {"No", "no", "N", "n", "NO"};
    string in;

yntp:

    cin >> in;

    for (int i = 0; i < 6; i++)
    {
        if (in == agree[i])
        {
            return 1;
            break;
        }
        else if (in == disagreed[i])
        {
            return 0;
            break;
        }
        else if (i > 4)
        {
            cout << "Wrong Input, please enter either (Yes / No)" << endl
                 << endl;
            goto yntp;
        }
    }
    return 0;
}