#include <iostream>
#include <fstream>
#include "GFglobal_functions.h"
using namespace std;

void login()
{

    int count;
    string username, password, userid, pass;
    cls();

    cout << " Please Enter your Username and Password : " << endl;
    cout << " USERNAME : ";
    cin >> username;
    string ruserid = "userDB/";
    ruserid.append(username);

    cout << " PASSWORD : ";
    cin >> password;

    fstream user;
    user.open(ruserid, ios::in);
    if (!user)
    {
        cout << "USER NOT FOUND";
    }
    else
    {
        string pass;

        user >> pass;

        if (password == pass)
        {
            cout << "Login Successful";
        }
        else
        {
            cout << "Incorrect Password, Try Again...\n";
            login();
        }
    }
}