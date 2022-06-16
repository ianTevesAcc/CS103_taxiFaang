#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <thread>

#include "test.h"

using namespace std;

struct rideinfo
{
    int dis, drivdis;
    float cost;
    string driver, pick, drop;
};


class driverfiles {

public:
    string names;
};

void PrintLine();              // function to output a line for decoration
void TitlePrinter(string tit); // prints title into center by printing spaces equal to the available spaces of width of console before printing title
bool yesno();
void cls();
void login(); // function declaration
void registerinfo();
void forgot();
void drivertest();
rideinfo request(string pickup, string dropoff);
int count; // create variables
string username, password, userid, pass;
string rusername, rpassword, ruserid, rpass, remail, raddress, rmobile, rpayment;
string susername, suserid, spass;
string gp = "|", endin = "\n************************************************************\n";

int main()
{



    cout << "\t\t CS103 GROUP PROJECT - Ian, Thomas, Bree" << endl;
    cout << "\t\t\t                 ____" << endl;
    cout << "\t\t\t             __/  |_|_" << endl;
    cout << "\t\t\t------------|  _     _``-.-------TAXIFANNG----------" << endl;
    cout << "\t\t\t            '-(_)---(_)--'" << endl;
    cout << "\t\t\t______________Please read Our T's & C's_____________" << endl << endl << endl;

    // Customer terms and conditions
    cout << "\t\t\t_________For Our Customers__________" << endl << endl;
    cout << "\t\t1. Stay safe and wear a mask unless you need to drink water" << endl;
    cout << "\t\t2. Please sit in the back seat if available to avoid transmission of Covid-19" << endl;
    cout << "\t\t3.If you have covid or flu symptoms please stay home and take a rapid-antigen test" << endl;
    cout << "\t\t4. Discrimination towards our drivers will not be tolerated." << endl;
    cout << "\t\t5. No consumption of food or drinks allowed within the taxi unless it is water." << endl;
    cout << "\t\t6. If you feel you need to be sick please ask our friendly staff to stop the car as to avoid messes." << endl;
    cout << "\t\t7. Any spill of food or drink may result in a customer being charged a fee for car cleaning." << endl << endl << endl;

    // Driver terms and conditions
    cout << "\t\t\t__________For our Drivers___________" << endl << endl;
    cout << "\t\t1. You must be at least 21 years of age to drive for us." << endl;
    cout << "\t\t1. In order to drive for us, you will need to have had both Covid-19" << endl;
    cout << "\t\t   vaccinations." << endl;
    cout << "\t\t2. Always wear a face mask when driving with a passenger (unless you" << endl;
    cout << "\t\t   have a medical exemption)." << endl;
    cout << "\t\t3. Always conduct yourself in a professional manner with" << endl;
    cout << "\t\t   all customers. Discrimination will not be tolerated." << endl;
    cout << "\t\t5. All drivers who choose to participate in TaxiFanng NZ booking Service" << endl;
    cout << "\t\t   must hold a full license and hold an approved license endorsement." << endl << endl << endl << endl;

    cout << "Do you agree to these terms and conditions? (Answer: yes/no)" << endl;

    bool yn = yesno();
    if (yn == 1) {
        cout << "Welcome to our service";
        goto mainMenu;
    }
    else {
        // everytime the code is processed the screen will clear
        cout << " Unless you agree you are not able to use our service. \n"
            << endl;
    }


mainMenu:

    int a;
    cout << "\t\t\t ______________.~'~._.~'~._.~'~._.~'~.______________" << endl; // Altered Menu
    cout << "\t\t\t ------------------- MAIN MENU ---------------------" << endl;
    cout << "\t\t\t|                                                   |" << endl;
    cout << "\t\t\t|___________________________________________________|" << endl;
    cout << "\t\t\t| Press 1 to Log-in                                 |" << endl;
    cout << "\t\t\t| Press 2 to Register with Us                       |" << endl;
    cout << "\t\t\t| Press 3 if you forgot your password               |" << endl;
    cout << "\t\t\t| Press 4 to EXIT application                       |" << endl;
    cout << "\t\t\t ^^^^^ Select your choice from above ^^^^^ : ";

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
        cls(); // everytime the code is processed the screen will clear
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


bool yesno() {
    string agree[5] = { "Yes", "yes", "Y", "y", "YES" };
    string disagreed[5] = { "No", "no", "N", "n", "NO" };

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

#endif;




    if (OSver == 1)
    {

        system("cls");

    }
    else if (OSver == 2 || OSver == 3)


    {

        system("clear");

    }


}

// debug---
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

    else {

        string pass;

        user >> pass;


        if (password == pass) {
            cout << "Login Successful";
        }
        else {

            cout << "Incorrect Password, Try Again...\n";
            login();
        }
    }





}

bool emailcheck(string email) {

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
        }
        else if (email[i] == '.')
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

void drivertest() {

    string q[5] = { "Have held a valid full New Zealand driver's licence for at least 1 year? (Yes/No):\t", "Question", "Question", "Question", "Question" };
    char vehmnm[50], rego[7], disname[20];
    int rating = 0;

    TitlePrinter("Driver Eligibility Questions");


    for (int i = 0; i < 4; i++)
    {
        bool yn = NULL;
        cout << q[i];
        yn = yesno();
        if (yn == 1)
        {
            continue;
        }
        else if (yn == 0)
        {
            cout << "Sorry you are ineligible...\t";
            main();
        }

    }

    cout << "Please enter your vehicle make and model: ";
    cin.ignore();
    cin.getline(vehmnm, 50);

    cout << "Please enter your REGO: ";

    cin.getline(rego, 7);

dis:
    for (int f = 0; f < 19; f++)
    {
        disname[f] = '\0';
    }
    cout << "Please enter Display Name: (20 Character Limit) ";
    cin.getline(disname, 20);

    bool spchk = 0;
    for (int j = 0; j < 19; j++)
    {
        if (disname[j] == ' ')
        {
            spchk = 1;
        }

    }

    if (spchk == 1)
    {
        cout << "ERROR: No spaces allowed, Try again...";
        goto dis;
    }


    string drivpath = "driverDB/";
    drivpath.append(disname);

    ofstream drivls("driverDB/driverls", ios::app);

    drivls << endl << disname;


    ofstream drivinfo(drivpath, ios::app);
    int a = 0;
    while (vehmnm[a] != '\0')
    {
        drivinfo << vehmnm[a];
        a++;
    }
    drivinfo << endl;
    a = 0;
    while (rego[a] != '\0')
    {
        drivinfo << rego[a];
        a++;
    }
    drivinfo << endl
             << '0';
    drivls.close();
    drivinfo.close();

}

void registerinfo()
{
    string rusername, rpassword, rpass, remail, raddress, rmobile, rpayment;
    string ruserid = "userDB/";
    cls();
user:
    cout << "\t\t\t Enter a username : ";
    cin >> rusername;

    ruserid.append(rusername);

    fstream test; // Check if username in use
    test.open(ruserid, ios::in);
    if (test)
    {
        test.close();
        cout << "Username in use... Use Another\n";
        ruserid = "userDB/";
        goto user;
    }


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
    f1 << rpassword << endl << remail << endl << rmobile << endl << rpayment << endin; // f1 is objectname for the file

    f1.close();
    cls();
    PrintLine();
    cout << "\n\t\t\t Thank you for registering! \n";
    PrintLine();
    this_thread::sleep_for(chrono::milliseconds(5000));
    cls();
    main();
}

void forgot()
{
    bool count = 0;
    int option;
    cls();
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

rideinfo request(string pickup, string dropoff)
{
    rideinfo info;
    info.pick = pickup;
    info.drop = dropoff;
    srand(time(0));
    info.dis = rand() % 25;

    if (info.dis > 0 && info.dis < 6)
    {
        info.cost = 10;
    }
    else if (info.dis > 5 && info.dis < 16)
    {
        info.cost = info.dis * 1.8;
    }
    else if (info.dis > 15 && info.dis < 25)
    {
        info.cost = info.dis * 1.5;
    }

    TitlePrinter("CONFIRM BOOKING");
    cout << "\tPickup from: " << pickup << "\n\tDropoff at: " << dropoff << "\n\tDistance to Travel: " << info.dis << "\n\tTotal Cost: $" << info.cost << "\n\tConfirm: (Yes/No) ";
    bool yn = yesno();

    if (yn == 0)
    {
        cout << "\n\tBOOKING CANCELED";
        main();
    }
    else if (yn == 1)
    {
        // GET RANDOM DRIVER FROM DB --
        TitlePrinter("SEARCHING AVAILABLE DRIVERS...");
        PrintLine();

        string line;
        int lncnt = 0;

        ifstream drivls("driverDB/driverls");
        if (drivls.is_open())
        {
            while (!drivls.eof())
            {
                getline(drivls, line);
                lncnt++;
            }
        }

        srand(time(0));
        int drivln = rand() % lncnt;

        int schln = 0;

        if (drivls.is_open())
        {
            while (getline(drivls, line))
            {

                if (schln == drivln)
                {
                    info.driver = line;
                    cout << line;
                    drivls.close();
                    break;
                }
                schln++;
            }
        }
        cls();






// FAKE DISTANCE COUNT
/*for (int i = info.drivdis; i > 0 ; i--)
{
     // replace with wait 1 min (enter to trigger)


=======

