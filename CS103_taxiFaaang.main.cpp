#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void PrintLine();              // function to output a line for decoration
void TitlePrinter(string tit); // prints title into center by printing spaces equal to the available spaces of width of console before printing title
bool yesno();
void login();                  // function declaration
void registerinfo();
void forgot();
void drivertest();
int count; // create variables
string username, password, userid, pass;
string rusername, rpassword, ruserid, rpass, remail, raddress, rmobile, rpayment;
string susername, suserid, spass;
string gp = "|", endin = "\n************************************************************\n";



int main()
{
    

    string title;

    // title output
    PrintLine();
    title = ("TAXI FAANG PROJECT");
    TitlePrinter(title);
    PrintLine();
    cout << endl;



    // debug ---
    int a;
    cout << "***************************************************\n";
    cout << "___________TaxiFANNG NZ Booking Service____________\n";
    cout << "***************************************************\n";
    cout << "*********************** MENU **********************\n";
    cout << "\t| Press 1 to Log in to your Booking Account|" << endl;
    cout << "\t| Press 2 to Register with us! |" << endl;
    cout << "\t| Press 3 if you forgot your password |" << endl;
    cout << "\t| Press 4 to EXIT application |" << endl;
    cout << "\t ^^^^^ Select your choice from above ^^^^^ : ";

    cin >> a;
    cout << endl;

    switch (a)
    {
    case 1:
        login();
        break;

    case 2:
        registerinfo();
        break;
    case 3:
        forgot();
        break;

    case 4:
        cout << " \t\t\t Kia ora !!! \n\n";
        break;
    default:
        system("cls"); // everytime the code is processed the screen will clear
        cout << " Please select a given option from above. \n"
             << endl;
        main();
    }
    //---debug

    return 0;
}

void PrintLine()
{
    for (int i = 0; i < 60; i++)
    {
        cout << "*";
    }
    cout << endl;
}

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

bool yesno(){
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
}

// debug---
void login()
{
    int count;
    string username, password, userid, pass;
    system("cls");
    cout << " Please Enter your Username and Password : " << endl;
    cout << " USERNAME : ";
    cin >> username;
    cout << " PASSWORD : ";
    cin >> password;


    

    
}

bool emailcheck(string email){
    int at = -1, dot = -1;

    if (!isalpha(email[0]))
    {
        return 0;
    }

    for (int i = 0; i <= email.length(); i++)
    {
        if (email[i] == '@')
        {
            at = i;
        } else if (email[i] == '.')
        {
            dot = i;
        }
        
        
    }

    

    if (at == -1 || dot == -1)
    {
        return 0;
    }

    if (at > dot)
    {
        return 0;
    }
    





    return 1;

    
    
    
    
    


    
}

void drivertest(){
    
    string q[5] = {"Have held a valid full New Zealand driver's licence for at least 1 year? (Yes/No):\t", "Question", "Question", "Question", "Question"};
    
    TitlePrinter("Driver Eligibility Questions");


    for (int i = 0; i < 4; i++)
    {
        bool yn = NULL;
        cout << q[i];
        yn = yesno();
        if (yn == 1)
        {
            continue;
        } else if (yn == 0)
        {
            cout << "Sorry you are ineligible...\t";
            main();
        }
        
        
    }

    
    
}

void registerinfo()
{
    string rusername, rpassword, rpass, remail, raddress, rmobile, rpayment;
    string ruserid = "userDB/";
    system("cls");
    cout << "\t\t\t Enter a username : ";
    cin >> rusername;

    ruserid.append(rusername);
    
    cout << "\t\t\t Enter a password : ";
    cin.ignore();
    cin >> rpassword;
    email:
    cout << "\t\t\t Enter an email address : ";
    cin.ignore();
    cin >> remail;

    if (emailcheck(remail) == 0)
    {
        cout << "Invalid Input, Please Try Again...\n";
        goto email;
    }
    
    cout << "\t\t\t Enter your mobile number : ";
    cin.ignore();
    cin >> rmobile;
    cout << "\t\t\t Enter your payment method :";
    cin.ignore();
    cin >> rpayment;


    cout << "(INSERT T&C'S HERE)\n";
    bool yn = yesno();

    if (yn == 0)
    {
        cout << "Sorry you can not Register...\n";
        main();
    }
    

    

    
    ofstream f1(ruserid, ios::app);   // used to write inside the file with app mode
    f1 << rusername << endl << rpassword << endl << remail << endl <<  rmobile << endl << rpayment << endin; // f1 is objectname for the file
    f1.close(); 
    system("cls");
    cout << "\n\t\t\t Thank you for registering! \n";
    main();
}

void forgot()
{
    bool count = 0;
    int option;
    system("cls");
    cout << "\t\t\t You forgot your password? \n";
    cout << " Press 1 to search via entering your username" << endl;
    cout << " Press 2 to go back " << endl;
    cout << "\t\t\t Choose : ";
    cin >> option;

    switch (option)
    {
    case 1:
    {
        string susername, suserid, spass;
        cout << "\n\t\t\t Enter your username : ";
        cin >> suserid;

        ifstream f2("businessinfo.txt");
        while (f2 >> suserid >> spass)
        {
            if (suserid == susername)
            {
                count = 1;
            }
        }
        f2.close();
        if (count == 1)
        {
            cout << "\n\n Your account is in our database! \n";
            cout << "\n\n Your password is : " << spass << endl;
            main();
        }
        else
        {
            cout << "\n\t Sorry, You don't have an account with us. \n";
            main();
        }
    }
    break;

    case 2:
        main();
        break;

    default:
        cout << "\t\t\t Invalid choice, please try again " << endl;
        forgot();
    }
}
//---debug