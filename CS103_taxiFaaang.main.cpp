#define RESET_COLOR "\u001b[37m" // to change color back
#define ANSI_YELLOW "\x1b[33m" // to turn txt yellow
#define ANSI_CYAN "\x1b[36m" // to turn txt cyan
#define ANSI_RED "\x1b[31m" // to turn txt red
#define ANSI_MAGENTA "\x1b[35m" //to turn txt magenta
#define  _CRT_NONSTDC_NO_WARNINGS
//^^^^Macros used for colour and error evasion^^^^
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <thread>
#include <stdlib.h>
#include <conio.h>
#include <cctype>
// ASCII Art by lgbeard - (https://www.asciiart.eu/vehicles/cars)
using namespace std;

/*DATA BASE*/
struct rideinfo
{
    int dis, drivdis;
    float cost;
    string driver, pick, drop;
};
class driverfiles
{
public:
    string names;
};

/*GLOBAL FUNCTIONS*/
void PrintLine() // function to output a line for decoration
{
    for (int i = 0; i < 60; i++)
    {
        cout << "*";
    }
    cout << endl;
}
void TitlePrinter(string title) // prints title into center
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
bool yesno() // iterate if user has selected yes or no
{
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
void cls() // clear console
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

/*SIGN IN*/
void SignIn();
void SignUp();
bool emailcheck(string email);
void ForgotPassword();
void DriverTest();
void CusRegoLogin();
void FAQ();
void CusBooking();
void CusSupport();
void CaccInfo();

/*MAIN MENUS*/
void MenuJunction();
void DriverMenu();
void DriverRegoLogin();
void StartDrive();
void CustomerMenu();
void TitlePage();
void TaxiFare();
void AdminMenu();

/*ADMIN AND SUPPORT FUNCTIONS AND VARIABLES*/
struct customer
{
    string fname;//for first name
    string lname;//for last name
    string phno;//for phone number
    string cusemail;//for email
}customerData;//Variable of type

//For drivers
struct driver
{
    string fst_name;//first name 
    string lst_name;//last name 
    string endorsement;
    string exp;//Experience of the person
    string pay;//Pay
    string subj;//
    string lec;//hours per Week
    string addrs;//Address of home
    string cel_no;//Phone number

    string serves;//Number of

}driv[50];
void cusdata();
void drivdata();
int i = 0, j;//for processing usage
char choice1;//for getting choice
char choice2;
char choice3;
string find;//for sorting
string srch;

class feedback
{
public:
    void customer_storeFeedback();
    void AdminMenu1();
    void SubmitInquiry();

    void ViewInquiry();
    void exit();
    feedback();
};
feedback::feedback()
{
}
struct node
{
    int feedback_number;
    string customerName;
    string date;
    string t;
    node* prev;
    node* next;
    node* link;
}*q, * temp;
node* start_ptr = NULL;
node* head = NULL;
node* last = NULL;
int count;
char ch;


    /*UNKNOWN*/
string username, password, userid, pass;
string rusername, rpassword, ruserid, rpass, remail, raddress, rmobile, rpayment;
string susername, suserid, spass;
string gp = "|", endin = "\n************************************************************\n";

/*Driver and customer Registration Variables*/
string
Danswer, // input command
dname, dpassword, quesb, quesa, quesc, // what is found in file
inName, inPassword, inquesa, inquesb, inquesc, // user gives input from keyboard
regquesb, regquesa, regquesc, drivName, Uname, drivPassword, drivRego, drivCar, drivLic, drivEml, drivVisa, // which variables the user is giving
Canswer,
cname, cpassword, quesd, quese, quesf,
inName2, inPassword2, inquesd, inquese, inquesf,
regquesd, regquese, regquesf, CusName, CusPassword, CusEml, CusAddr, CusPh, CusCardno, CusCardna, CusCVV, CusEX;
char choice;

/*TITLE*/
void TitlePage()
{
    startagain:
    // customer terms and conditions
    cout <<  "\t\t __________________________________________________________________________________________" << endl;
    cout << "\t\t |---------------------------TAXI-FANNG TERMS AND CONDITIONS------------------------------|" << endl;
    cout << "\t\t |________________________________________________________________________________________|" << endl;
    cout << endl;
    cout << "\t\t\tFor Our Customers__________" << endl
        << endl;
    cout << "\t\t1. Stay safe and wear a mask unless you need to drink water" << endl;
    cout << "\t\t2. Please sit in the back seat if available to avoid transmission of Covid-19" << endl;
    cout << "\t\t3. If you have covid or flu symptoms please stay home and take a rapid-antigen test" << endl;
    cout << "\t\t4. Discrimination towards our drivers will not be tolerated." << endl;
    cout << "\t\t5. No consumption of food or drinks allowed within the taxi unless it is water." << endl;
    cout << "\t\t6. If you feel you need to be sick please ask our friendly staff to stop the vehicle." << endl;
    cout << "\t\t7. Any spill of food or drink may result in a customer being charged a fee for car cleaning." << endl
        << endl
        << endl;
    // driver terms and conditions
    cout << "\t\t\tFor our Drivers___________" << endl
        << endl;
    cout << "\t\t1. You must be at least 21 years of age to drive for us." << endl;
    cout << "\t\t1. In order to drive for us, you will need to have had both Covid-19" << endl;
    cout << "\t\t   vaccinations." << endl;
    cout << "\t\t2. Always wear a face mask when driving with a passenger (unless you" << endl;
    cout << "\t\t   have a medical exemption)." << endl;
    cout << "\t\t3. Always conduct yourself in a professional manner with" << endl;
    cout << "\t\t   all customers. Discrimination will not be tolerated." << endl;
    cout << "\t\t5. All drivers who choose to participate in TaxiFanng NZ booking Service" << endl;
    cout << "\t\t   must hold a full license and hold an approved license endorsement." << endl
        << endl
        << endl
        << endl;
    cout << "\t\t\tDo you Agree with our T's and C's?" << endl;
    cout << "\t\t\t(Type Yes / No): ";
  
    bool yn = yesno(); 
    if (yn == 1)
    {
        cout << "Welcome to our service";
        MenuJunction();

    }
    else
    {
        // everytime the code is processed the screen will clear
        cout << " Unless you agree to our Terms and Conditions you are not able to use our service. \n"
            << endl;
        goto startagain;
    }
}

/*MENU JUNCTION*/
void MenuJunction()
{
    cls();

    cout << "\t\t\t ______________.~'~._.~'~._.~'~._.~'~.______________" << endl;
    cout << "\t\t\t -------------------- WELCOME ----------------------" << endl;
    cout << "\t\t\t|                                                   |" << endl;
    cout << "\t\t\t|___________________________________________________|" << endl;
    cout << ANSI_MAGENTA"\t\t\t| Press 1 for Customer Menu                         |" << endl;
    cout << ANSI_CYAN"\t\t\t| Press 2 for Driver Menu                           |" << endl;
    cout << ANSI_RED"\t\t\t| Press 3 for Administrator Menu                    |" << endl;
    cout << endl;
    cout << RESET_COLOR"\t\t\t| Press 4 to EXIT application                       |" << endl;
 
    cout << ANSI_YELLOW R"(

                              __..-======-------..__
                          . '    ______    ___________`.
                        .' .--. '.-----.`. `.-----.-----`.
                       / .'   | ||      `.` \\     \     \\            _
                     .' /     | ||        \\ \\_____\_____\\__________[_]
                    /   `-----' |'---------`\  .'                       \
                   /============|============\'-------------------.._____|
                .-`---.         |-==.        |'.__________________  =====|-._
              .'        `.      |  * * * *   |      .--------.    _` ====|  _ .
             /     __     \     |  T A X I   |   .'           `. [_] `.==| [_] \
            [   .`    `.  |     | F A N N G  | .'     .---.     \      \=|     |
            |  | / .-. '  |_____\___________/_/     .'---. `.    |     | |     |
             `-'| | O |'..`------------------'.....'/ .-. \ |    |       ___.--'
                \ `-' / /   `._.'                 | | O | |'___...----''___.--'
                  `._.'.'                           \ `-' / [___...----''_.'
                                                     `._.'.'



)" << '\n';
    
    cout << RESET_COLOR"What is your choice?" << endl;
    cout << "(type a valid choice number from above): ";
    cin >> choice;

    switch (choice)
    {
    case '1':
        CustomerMenu(); // Sends User to Customer Menu
        break;
    case '2':
        DriverMenu(); // Sends User to Driver Menu
        break;
    case '3':
        AdminMenu(); // Sends Admin to the Administrative page
        break;
    case '4':
        EXIT_SUCCESS; // Closes Program

    default:
        cout << "Invalid Input\nTry Again\n\nPress any key to CONTINUE" << endl;
        system("pause");
        cls();
        break;
        
    }

    cls();
}

/*CUSTOMER SUB-MENUS*/
void CustomerMenu()
{
    restart:
    cls();
    int b;
    cout << ANSI_MAGENTA"\t\t\t ______________.~'~._.~'~._.~'~._.~'~.______________" << endl;
    cout << "\t\t\t ------------------ CUSTOMER MENU ------------------" << endl;
    cout << "\t\t\t|                                                   |" << endl;
    cout << "\t\t\t|___________________________________________________|" << endl;
    cout << "\t\t\t| Press 1 to Register / Login                       |" << endl;
    cout << "\t\t\t| Press 2 to become a driver with us!               |" << endl;
    cout << "\t\t\t| Press 3 for FAQ                                   |" << endl;
    cout << RESET_COLOR"\t\t\t| Press 4 to EXIT application                       |" << endl;

    cout << endl;

    cout << "What is your choice?" << endl;
    cout << "(type a valid choice number from above): ";
    cin >> b;

    switch (b)
    {
    case 1:

        CusRegoLogin();
        goto restart;
    case 2:
        goto restart;
        break;
    case 3:
        FAQ();
        goto restart;
    default:
        cout << " Thank you, Have a nice day! :) " << endl;
        EXIT_SUCCESS;
    }
}
void CusRegoLogin()
{
    cls();
    while (1)
    {

        cout << ANSI_MAGENTA"\t\t\t ______________.~'~._.~'~._.~'~._.~'~.______________" << endl;
        cout << "\t\t\t -----------CUSTOMER LOGIN / REGISTRATION------------" << endl;
        cout << "\t\t\t|___________________________________________________|" << endl;
        cout << "\t\t\t| Press 1 for Customer Login                        |" << endl;
        cout << "\t\t\t| Press 2 for Customer Registration                 |" << endl;
        cout << "\t\t\t| Press 3 if you Forgot Password (or) Username      |" << endl;
        cout << "\t\t\t| Press 4 to EXIT application                       |" << endl;
        cout << "\t\t\t ^^^^^ Select your choice from above ^^^^^ : ";

        cout << endl;
        cout << RESET_COLOR"What is your choice?" << endl;
        cout << "(type a valid choice number from above): ";
        getline(cin, Canswer);

        if (Canswer == "4")
        {
            MenuJunction();
        }
        if (Canswer == "2")
        {
            cls();
            string q[5] = { "Are you over the age of 18? (Yes/No):\t", };
            for (int i = 0; i < 4; i++)
            {
                bool yn = NULL;
                cout << q[i];
                yn = yesno();
                if (yn == 1)
                {
                    goto secQuest2;
                }
                else if (yn == 0)
                {
                    cout << "Sorry, you need to be at least 18 years of age to use this service...\t";
                    MenuJunction();
                }
            }
        secQuest2:
            //open a file for registration
            ofstream g("customerdata.txt"); //'ofstream' is  for getting the stored data from the file,


            if (!g.is_open()) //if it's not open, then there is no such file with the given name inside this folder (means, in the folder where the .exe file is going to be made )
            {
                cout << "could not open file customerdata.txt\n"; //just so we can know why it ain't working if it doesn't

            }

            cout << "\nCustomer Registration: ";
            getline(cin, CusName); //user input from keyboard will go into registerName variable for registration
            cout << "\nEnter Username: ";
            getline(cin, CusName);
            cout << "\nEnter Password: ";
            getline(cin, CusPassword); //user input from keyboard will go into registerPassword variable fors registration
            cout << "Enter Email Address: ";
            getline(cin, CusEml);
            cout << "Enter Home Address: ";
            getline(cin, CusAddr);
            cout << "Enter Mobile / Landline Number: ";
            getline(cin, CusPh);
            cout << "Enter you payment card number: ";
            getline(cin, CusCardno);
            cout << "Enter the name present on this card: ";
            getline(cin, CusCardna);
            cout << "Enter Security Code / CVV: ";
            getline(cin, CusCVV);
            cout << "Enter Card Expiry Date (DD/MM): ";
            getline(cin, CusEX);

            cout << "\nIn case you forget your password/username here are some security questions: " << endl;
            cout << "________________________________________________________________________________________" << endl;
            cout << "\n Q1: What is Your favorite colour? Please enter everything in lowercase: ";
            cout << "\nEnter the security question's answer: ";
            getline(cin, regquese);
            cout << "\n Q2: What was your first best friends name? Please enter everything in lowercase: ";
            cout << "\nEnter the security question's answer: ";
            getline(cin, regquesd);
            cout << "\n Q3: What was the name of the first street you lived on? Please enter everything in lowercase: ";
            cout << "\nEnter the security question's answer: ";
            getline(cin, regquesf);
            cout << "Enter Password: ";
            cout << "________________________________________________________________________________________" << endl;

            g << CusName; //this put whatever's to the right (registerName) into , g 

            g << '\n'; //and change to anew line in file
            g << CusPassword; //and now write/store,the password
            //all data placed  safely insidea the file that g opened
            g << '\n';
            g << CusPh;
            g << '\n';
            g << CusEml;
            g << '\n';
            g << CusAddr;
            g << '\n';
            g << CusCardno;
            g << '\n';
            g << CusCardna;
            g << '\n';
            g << CusCVV;
            g << '\n';
            g << CusEX;
            g << '\n';
            g << '\n';
            g << regquese;
            g << '\n';
            g << regquesd;
            g << '\n';
            g << regquesf;

            g.close(); //always make sure to close the file, or else we might have to deal with some nasty unwanted stuff in the memory

            cout << "\nRegistration is ..Successful!\n";
            this_thread::sleep_for(chrono::milliseconds(3000));
            CusRegoLogin();
        }
        if (Canswer == "1")
        {
            

            //login
            //while (1)
            //{
                //tplogin:
                //string cusfile = "userDB/";
                ////you are going to input the name and password here
                //cout << "\n\n\n"
                //    << "Enter Username: ";
                //getline(cin, inName2);
                ////open the file, and then put the name and password into the strings
                //cusfile.append(inName2);
                //ifstream f(cusfile); //'ifstream' is   for getting the data from the file, and
                ////let us assume we've already created a file
                //if (!f.is_open()) //if file is not open, then there is no such file with the given name inside
                ////the folder (that is, in this folder where the .exe file is going to be made)
                //{
                //    cout << "User not found\n"; //just so we know why it won't work if it doesn't at any instance
                //    goto tplogin;

                //}
                //getline(f, cname, '\n'); //reads the user name  from file f 
                //getline(f, cpassword, '\n'); //reads the password from file f 
                ////also, we are here telling the file to get the  text up until '\n', here ishow  we  know it reads the whole line at most, and won't go any further
                ////and that is done by the 3rd parameter '\n'
                //f.close(); //it is not required to open now, since you have the name and password from the file
                //cout << "\nEnter Password: ";
                //getline(cin, inPassword2);

                //if (inName2 == cname && inPassword2 == cpassword)
                //{
                //    cout << "\nLogin Successful\n" //the '\n' is a character, so that's why I can add it
                //    //and it will automatically output a newline in console, alongside the string
                //        << "Welcome, "
                //        << inName2;
                //    CusBooking();
                //     //just exit the while loop if you've entered the valid account
                //}
                //else {
                //    cout << "incorrect name or password\n"; //if user  entered the wrong account details ,
                //    cls();
                //    goto tplogin;
                //}

                
                //then the while loop is not done yet. So that's why this output is without condition
            //}
            //now do something about the account
               //open the file, and then put the name and password into the strings
            ifstream f("customerdata.txt"); //'ifstream' is   for getting the data from the file, and
            //let us assume we've already created a file
            if (!f.is_open()) //if file is not open, then there is no such file with the given name inside
            //the folder (that is, in this folder where the .exe file is going to be made)
            {
                cout << "could not open file\n"; //just so we know why it won't work if it doesn't at any instance

            }
            getline(f, cname, '\n'); //reads the user name  from file f 
            getline(f, cpassword, '\n'); //reads the password from file f 
            //also, we are here telling the file to get the  text up until '\n', here ishow  we  know it reads the whole line at most, and won't go any further
            //and that is done by the 3rd parameter '\n'
            f.close(); //it is not required to open now, since you have the name and password from the file

            //login
            while (1)
            {
                //you are going to input the name and password here
                cout << "\n\n\n"
                    << "Enter Username: ";
                getline(cin, inName2);
                cout << "\nEnter Password: ";
                getline(cin, inPassword2);

                if (inName2 == cname && inPassword2 == cpassword)
                {
                    cout << "\nLogin Successful\n" //the '\n' is a character, so that's why I can add it
                    //and it will automatically output a newline in console, alongside the string
                        << "Welcome, "
                        << inName2;
                    CusBooking();
                    break; //just exit the while loop if you've entered the valid account
                }
                cout << "incorrect name or password\n"; //if user  entered the wrong account details ,
                cls();
                //then the while loop is not done yet. So that's why this output is without condition
            }
            //now do something about the account
        }

        if (Canswer == "3") //(for C strings) if (!strcmp(usercommand, "forgots password or "))
        {
        forgotp:
            string ch;
            //open file, and then put the name and password into the strings
            ifstream f("customerdata.txt"); //'ifstream' is the one for getting data from the file, and
            //let us assume you've already created a file called "registration.txt"
            if (!f.is_open()) //if it's not open, then there is no such file with the given name inside
            //the folder (that is, in the folder where the .exe file is going to be)
            {
                cout << "could not open file\n"; //just so that you know why it won't work if it doesn't

            }
            getline(f, cname, '\n'); //reads the user name from file f (which is using "registration.txt")
            getline(f, cpassword, '\n'); //reads the password from file f (which is using "registration.txt")
            getline(f, quese, '\n');
            getline(f, quesd, '\n');
            getline(f, quesf, '\n');
            //also, if you tell the file to get you that text up until '\n', that's when you know it reads
            //the whole line at most, and won't go any further
            //and that is done by the 3rd parameter
            f.close(); //you don't need it open now, since we now have the name and password from the file
            cout << "________________________________________________" << endl;
            cout << "Forgotten something? Happens to the best of us.\n";
            cout << "1. Search your ID by the username you remember" << endl;
            cout << "2. Search your ID by the password you remember" << endl;
            cout << "3. Go Back" << endl;
            cout << "Enter your choice :";
            getline(cin, ch);
            if (ch == "1") {

                //forgot
                while (1)
                {
                    //user has to input the name and  question's answers here

                    cout << "\n\n\n"
                        << "Enter Username: ";
                    getline(cin, inName2);


                    cout << "\n Q1: What is Your favorite colour? Please enter everything in  lowercase.";
                    cout << "\nPlease Enter the security question's answer: ";
                    getline(cin, inquesd);

                    cout << "\n Q2: What was your first best friends name? Please enter everything in lowercase. ";
                    cout << "\nEnter the security question's answer: ";
                    getline(cin, inquese);

                    cout << "\n Q3: What was the name of the first street you lived on? Please enter everything in lowercase:";
                    cout << "\nEnter the security question's answer: ";
                    getline(cin, inquesd);

                    if (inName2 == cname && inquese == quesd && inquesd == quesf && inquesd == quese)
                    {
                        cout << "\nFinding and Searching  Successful\n" //the '\n' is a character, so we can add it and it will then automatically output a newline in the console, alongside the string
                            << "Welcome, "
                            << inName2;

                        CusBooking(); //changesbybree
                        cout << "\nYour retrieved password is:" << cpassword;
                        break; //this will  exit the while loop if user  entered a valid / correct account credentials
                    }
                    cout << "incorrect username or security answers\n"; //if the user entered wrong  account details then the while loop is not done yet and should be iterated again till
                    //the correct details are filled in. So this 'cout' is outside  without any 'if' condition
                    goto forgotp;
                }
                //now process the account

            }
            if (ch == "2")
            {

                //forgot
                while (1)
                {
                    //user will input the name and password here
                    cout << "\n\n\nEnter Password: ";
                    getline(cin, inPassword2);

                    cout << "\n Q1: What is Your favorite color? Please enter everything in  lowercase :";
                    cout << "\nPlease Enter the security question's answer:";
                    getline(cin, inquesd);

                    cout << "\n Q2: What is your contact no: ?:";
                    cout << "\nEnter the security question's answer:";
                    getline(cin, inquese);

                    cout << "\n Q3: Where have you completed your high school ,(also specify city  and state)Please enter everything in  lowercase :";
                    cout << "\nEnter the security question's answer:";
                    getline(cin, inquesd);

                    if (inPassword2 == cpassword && inquese == quesd && inquesd == quesf && inquesd == quese)
                    {
                        cout << "\nFinding and Searching  Successful\n" //the '\n' is a character, so we can  add it and it will then automatically output a newline in the console, alongside the string
                            << "Welcome, "
                            << cname;
                        cout << "\nYour Username is:" << cname;
                        break; //we have to exit the whole while loop if user has entered the valid account
                    }
                    cout << "incorrect password or security answers\n"; //if the user entered the wrong account            details, then then the while loop is not done yet. So here we have this output "cout .."  without any 'if' condition
                }
            }

            if (ch == "3")
            {

                MenuJunction();
            }

        }

        //now process about the account

        cout << "\n\n\n\n\n"; //give it 5 newlines
    }
}
void CusBooking() {

    // 1. book trip - need to pull a driver name, need to add GST // thomas task
    // 2. support - lost items , complaints - go to admin also // bree task
    // admin contacts between customer and driver, provide support number (rand number gen)
    // 3. account info
    // 4. exit
    restart2:
    cls();
    int h;
    cout << "ANSI_MAGENTA\t\t\t ______________.~'~._.~'~._.~'~._.~'~.______________" << endl;
    cout << "\t\t\t ----------------- CUSTOMER MENU -------------------" << endl;
    cout << "\t\t\t|___________________________________________________|" << endl;
    cout << "\t\t\t| Press 1 to Book a Ride                            |" << endl;
    cout << "\t\t\t| Press 2 for Customer Support                      |" << endl;
    cout << "\t\t\t| Press 3 for Account Information                   |" << endl;
    cout << "\t\t\t| Press 4 to EXIT application                       |" << endl;
    
    cout << RESET_COLOR"What is your choice?" << endl;
    cout << "(type a valid choice number from above): ";
    //NOTE!!! WHEN BOOKING A RIDE ADD THE GENERATION OF A RANDOM REFERENCE NUMBER SO IT MAY BE USED IN CUSTOMER/ADMIN SUPPORT FUNCTION
    cin >> h;

    switch (h) {
    case 1:
        cls();
        cout << "Let's go" << endl;
        goto restart2;
    case 2:
        CusSupport();
        goto restart2;
    case 3:
        cls();
        CaccInfo(); // function to access account information that has been inputted in the registration phase
        goto restart2;
    default:
        MenuJunction();
    }


}
void CusSupport() {
    feedback admin;

    cout << "Are wanting to submit an inquiry to us, today?" << endl;
    bool yn = yesno();
    if (yn == 1)
    {
        admin.customer_storeFeedback();

    }
    else
    {
        // everytime the code is processed the screen will clear
        cout << " You are being sent back to the Main Menu " << endl;

        MenuJunction();
    }
}
void feedback::customer_storeFeedback()
{
    cls();
    cout << "\n";
    cout << "\n ______________.~'~._.~'~._.~'~._.~'~.______________" << endl;
    cout << "\n---------------- CUSTOMER SUPPORT ------------------" << endl;
    cout << "\n====================================================";
    cout << "\nIf you need assistance or to contact a driver please enter inquiry details here: \n";
    cout << "________________________________\n\n";
    node* temp;
    temp = new node;
    cout << "Enter your trip reference number: ";
    cin >> temp->feedback_number;
    cout << "Enter Your Username: ";
    cin.ignore();
    getline(cin, temp->customerName);
    cout << "Enter Date Trip Occured: ";
    cin >> temp->date;
    cout << "Inquiry ( Please include Driver Details ) : ";

    cin.ignore();
    getline(cin, temp->t);
    cout << "===========================================================================" << endl;
    cout << "\t\t\tFeedback added Successfully" << endl;
    cout << "===========================================================================" << endl;
    cout << "\t\t\t An Administrator will be in contact with you shortly." << endl;
    system("PAUSE");
    temp->next = NULL;
    if (start_ptr != NULL)
    {
        temp->next = start_ptr;
    }
    start_ptr = temp;
    MenuJunction();
}

/*DRIVER SUB-MENUS*/
void DriverMenu()
{
    restart3:
    cls();
    int c;
    cout << ANSI_CYAN "\t\t\t ______________.~'~._.~'~._.~'~._.~'~.______________" << endl; // Altered Menu
    cout << "\t\t\t ----------------- DRIVER MENU ---------------------" << endl;
    cout << "\t\t\t|                                                   |" << endl;
    cout << "\t\t\t|___________________________________________________|" << endl;
    cout << "\t\t\t| Press 1 to Register / Login                       |" << endl;
    cout << "\t\t\t| Press 2 to go back to the Main Menu               |" << endl;
    cout << "\t\t\t| Press 3 to EXIT PROGRAM                           |" << endl;
    
    cout << RESET_COLOR"What is your choice?" << endl;
    cout << "(type a valid choice number from above): ";
    cin >> c;
    cout << endl;

    switch (c)
    {
    case 1:
        DriverRegoLogin();
        goto restart3;

    case 2:
        MenuJunction();
    case 3:
        EXIT_SUCCESS;

    default:

        cout << " Please select a given option from above. \n"
            << endl;
        goto restart3;

    }
}
void DriverRegoLogin()
{
    cls();
    while (1)
    {
        cout << ANSI_CYAN"\t\t\t ______________.~'~._.~'~._.~'~._.~'~.______________" << endl;
        cout << "\t\t\t ----------- DRIVER LOGIN / REGISTRATION------------" << endl;
        cout << "\t\t\t|___________________________________________________|" << endl;
        cout << "\t\t\t| Press 1 for Driver Login                          |" << endl;
        cout << "\t\t\t| Press 2 for Driver Registration                    |" << endl;
        cout << "\t\t\t| Press 3 if you Forgot Password (or) Username      |" << endl;
        cout << "\t\t\t| Press 4 to go back to Main Menu                   |" << endl;
      
        cout << RESET_COLOR"What is your choice?" << endl;
        cout << "(type a valid choice number from above): ";

        getline(cin, Danswer);

        if (Danswer == "4")
        {
            MenuJunction();
        }
        /*DRIVER REG*/
        if (Danswer == "2")
        {
            cls();

        secQuest:
            //open a file for registration
            //ofstream g("driverdata.txt"); //'ofstream' is  for getting the stored data from the file,
            //and the file does not need to have to exist or be made beforehand. It is 'ofstream', so, it'll take care of it for you!
            //but please be sure that if there is a file called "registration.txt" in the same folder as the
            //.exe file, the contents will be deleted/ overwritten



            cout << "\nDriver Application: \n";
            //cin.ignore();//getline(cin, drivName); //user input from keyboard will go into registerName variable for registration
            cout << "\nEnter Username: ";
            getline(cin, drivName);
            string drivfile = "driverDB/";
            drivfile.append(drivName);
            fstream g(drivfile);

            if (g.is_open()) //if it's not open, then there is no such file with the given name inside this folder (means, in the folder where the .exe file is going to be made )
            {
                cout << "Username is already taken, please try again...\n"; //just so we can know why it ain't working if it doesn't
                drivfile = "driverDB/";
                goto secQuest;
            }

            g.close();
            cout << "\nEnter Password: ";
            getline(cin, drivPassword); //user input from keyboard will go into registerPassword variable fors registration
            cout << "\nIn case you forget your password/username here are some security questions: " << endl;
            cout << "________________________________________________________________________________________" << endl;
            cout << endl;
            cout << "\n Q1: What is Your favorite colour? Please enter everything in lowercase: ";
            cout << "\nEnter the security question's answer: ";
            getline(cin, regquesa);
            cout << "\n Q2: What was your first best friends name? Please enter everything in lowercase: ";
            cout << "\nEnter the security question's answer: ";
            getline(cin, regquesb);
            cout << "\n Q3: What was the name of the first street you lived on? Please enter everything in lowercase: ";
            cout << "\nEnter the security question's answer: ";
            getline(cin, regquesc);
            /*cout << "Enter Password: ";*/
            cout << "________________________________________________________________________________________" << endl;


            string q[5] = { "Have you held a valid full New Zealand driver's licence for at least 1 year? (Yes/No):\t", };
            for (int i = 0; i < 4; i++)
            {
                bool yn = NULL;
                cout << q[i];
                yn = yesno();
                if (yn == 1)
                {
                    goto elquest;
                }
                else if (yn == 0)
                {
                    cout << "Sorry you are ineligible...\t";
                    MenuJunction();
                }
            }
            cin.ignore();

        elquest:
            cout << "Enter Vehicle Registration Number: ";
            getline(cin, drivRego);
            cout << "Enter Car Make and Model: ";
            getline(cin, drivCar);
            cout << "Enter NZ Drivers License Number: ";
            getline(cin, drivLic);
            cout << "Enter your Email Address: ";
            getline(cin, drivEml);
            cout << "If you do not hold a NZ citizenship please enter Visa status - If you do type 'N/A': ";
            getline(cin, drivVisa);

            ofstream regwrite(drivfile);

            regwrite << drivName; //this put whatever's to the right into g (("driverdata.txt"))

            regwrite << '\n'; //and change to anew line in file
            regwrite << drivPassword; //and now write/store,the password
            //all data placed  safely insidea the file that g opened
            regwrite << '\n';
            regwrite << regquesa;
            regwrite << '\n';
            regwrite << regquesb;
            regwrite << '\n';
            regwrite << regquesc;
            regwrite << '\n';
            regwrite << drivRego;
            regwrite << '\n';
            regwrite << drivCar;
            regwrite << '\n';
            regwrite << drivLic;
            regwrite << '\n';
            regwrite << drivEml;
            regwrite << '\n';
            regwrite << drivVisa;
            regwrite << '\n';


            regwrite.close(); //always make sure to close the file, or else we might have to deal with some nasty unwanted stuff in the memory

          
            cout << "Thank you for registering, " << drivName << "!" << endl;
            this_thread::sleep_for(chrono::milliseconds(3000));
            DriverRegoLogin();
        }
        if (Danswer == "1")
        {
            string drivfillogin = "driverDB/";
            //open the file, and then put the name and password into the strings
            ifstream f("driverdata.txt"); //'ifstream' is   for getting the data from the file, and
            //let us assume we've already created a file
            if (!f.is_open()) //if file is not open, then there is no such file with the given name inside
            //the folder (that is, in this folder where the .exe file is going to be made)
            {
                cout << "could not open file\n"; //just so we know why it won't work if it doesn't at any instance

            }
            getline(f, dname, '\n');
            getline(f, dpassword, '\n');
            f.close();

            //login
            while (1)
            {
                // you are going to input the name and password here
                cout << "\n\n\n"
                    << "Enter Username: ";
                getline(cin, inName);
                cout << "\nEnter Password: ";
                getline(cin, inPassword);

                cout << inName << '\t' << dname << '\t' << inPassword << '\t' << dpassword;
                if (inName == dname && inPassword == dpassword)
                {
                    cout << "\nLogin Successful\n" //the '\n' is a character, so that's why I can add it
                    //and it will automatically output a newline in console, alongside the string
                        << "Welcome, "
                        << inName;
                    this_thread::sleep_for(chrono::milliseconds(3000));
                    StartDrive();

                }
                cout << "incorrect name or password\n"; //if user  entered the wrong account details ,
                this_thread::sleep_for(chrono::milliseconds(3000));
                cls();
                //then the while loop is not done yet. So that's why this output is without condition
            }
            //now do something about the account
        }

        if (Danswer == "3") //(for C strings) if (!strcmp(usercommand, "forgots password or "))
        {

            string ch;
            //open file, and then put the name and password into the strings
            ifstream f("driverdata.txt"); //'ifstream' is the one for getting data from the file, and
            //let us assume you've already created a file called "registration.txt"
            if (!f.is_open()) //if it's not open, then there is no such file with the given name inside
            //the folder (that is, in the folder where the .exe file is going to be)
            {
                cout << "could not open file\n"; //just so that you know why it won't work if it doesn't
                /*return 0;*/
            }
            getline(f, dname, '\n'); //reads the user name from file f (which is using "registration.txt")
            getline(f, dpassword, '\n'); //reads the password from file f (which is using "registration.txt")
            getline(f, quesa, '\n');
            getline(f, quesb, '\n');
            getline(f, quesc, '\n');
            //also, if you tell the file to get you that text up until '\n', that's when you know it reads
            //the whole line at most, and won't go any further
            //and that is done by the 3rd parameter
            f.close(); //you don't need it open now, since we now have the name and password from the file
            cout << "Forgotten something? Happens to the best of us.\n";
            cout << "1. Search your ID by username you remember" << endl;
            cout << "2. Search your ID by password you remember" << endl;
            cout << "3. Go Back" << endl;
            cout << "Enter your choice: ";
            getline(cin, ch);
            if (ch == "1") {

                //forgot
                while (1)
                {
                    //user has to input the name and  question's answers here

                    cout << "\n\n\n"
                        << "Enter Username: ";
                    getline(cin, inName);


                    cout << "\n Q1: What is Your favorite colour? Please enter everything in  lowercase.";
                    cout << "\nPlease Enter the security question's answer: ";
                    getline(cin, inquesa);

                    cout << "\n Q2: What was your first best friends name? Please enter everything in lowercase. ";
                    cout << "\nEnter the security question's answer: ";
                    getline(cin, inquesb);

                    cout << "\n Q3: What was the name of the first street you lived on? Please enter everything in lowercase:";
                    cout << "\nEnter the security question's answer: ";
                    getline(cin, inquesc);

                    if (inName == dname && inquesb == quesb && inquesc == quesc && inquesa == quesa)
                    {
                        cout << "\nFinding and Searching  Successful\n" //the '\n' is a character, so we can add it and it will then automatically output a newline in the console, alongside the string
                            << "Welcome, "
                            << inName;
                        cout << "\nYour retrieved password is: " << dpassword;
                        break; //this will  exit the while loop if user  entered a valid / correct account credentials
                    }
                    cout << "incorrect username or security answers\n"; //if the user entered wrong  account details then the while loop is not done yet and should be iterated again till
                    //the correct details are filled in. So this 'cout' is outside  without any 'if' condition
                }
                //now process the account

            }
            if (ch == "2")
            {

                //forgot
                while (1)
                {
                    //user will input the name and password here
                    cout << "\n\n\nEnter Password: ";
                    getline(cin, inPassword);

                    cout << "\n Q1: What is Your favorite color? Please enter everything in  lowercase :";
                    cout << "\nPlease Enter the security question's answer:";
                    getline(cin, inquesa);

                    cout << "\n Q2: What is your contact no: ?:";
                    cout << "\nEnter the security question's answer:";
                    getline(cin, inquesb);

                    cout << "\n Q3: Where have you completed your high school ,(also specify city  and state)Please enter everything in  lowercase :";
                    cout << "\nEnter the security question's answer:";
                    getline(cin, inquesc);

                    if (inPassword == dpassword && inquesb == quesb && inquesc == quesc && inquesa == quesa)
                    {
                        cout << "\nFinding and Searching  Successful\n" //the '\n' is a character, so we can  add it and it will then automatically output a newline in the console, alongside the string
                            << "Welcome, "
                            << dname;
                        cout << "\nYour Username is:" << dname;
                        break; //we have to exit the whole while loop if user has entered the valid account
                    }
                    cout << "incorrect password or security answers\n"; //if the user entered the wrong account details, then then the while loop is not done yet. So here we have this output "cout .."  without any 'if' condition
                }
            }

            if (ch == "3")
            {

                DriverRegoLogin();
            }

        }

        //now process about the account

        cout << "\n\n\n\n\n"; //give it 5 newlines
    }
    /*return 1;*/
}
void StartDrive()
{
    cls();
    cout << ANSI_CYAN"\t\t\t ______________.~'~._.~'~._.~'~._.~'~.______________" << endl;
    cout << "\t\t\t --------------- LET'S START DRIVING ---------------" << endl;
    cout << "\t\t\t|___________________________________________________|" << endl;
    cout << "\t\t\t| Press 1 to Begin Driving                          |" << endl;
    cout << "\t\t\t| Press 2 to Access Account Information             |" << endl;
    cout << "\t\t\t| Press 3 for Support                               |" << endl;
    cout << "\t\t\t| Press 4 to EXIT application                       |" << endl;
    
    cout << RESET_COLOR"What is your choice?" << endl;
    cout << "(type a valid choice number from above): ";
}
// additions to driver menu
// 1. idenitical to request function just needs modifying to suit driver // thomas
// 2. driver info
// 3. support - driver support file - (1 for driver 1 for customer)
// what can we do to help? 

/*ADMIN PROCESS*/
void AdminMenu() {
    feedback admin;
    cls();
    cout << ANSI_RED"\t\t\t_____________________________________________________________________________" << endl;
    cout << "\t\t\tEnter your code to access our Secure Administrator Server: "; // code is admin
    string codeYes = "admin";
    string codeNo;
        string codeInput;
    code:
        cin >> codeInput;
        for (int i = 0; i < 6; i++)
        {
            if (codeInput == codeYes)
            {
                admin.AdminMenu1();
                break;
            }
            else
            {
                cout << " You are being sent back to the Main Menu " << endl;

                MenuJunction();
            }
                /*cout << "Wrong passcode, Try again or exit program: " << endl;
                goto code;*/
            }
    //}
    //if (codeInput == 1)
    //{
    //    admin.AdminMenu1();

    //}
    //else
    //{
    //    // everytime the code is processed the screen will clear
    //    cout << " You are being sent back to the Main Menu " << endl;

    //    MenuJunction();
    //}
    
    
}
void feedback::AdminMenu1()
{
    feedback admin;
    int menu;

    cls();

    ///* int menu;*/
    //string userName, userPassword;
    //system("cls");
    //cout << "\n";
    //cout << " ===================================================\n";
    //cout << "|               NZ TAXI FANNG SERVICE               |\n";
    //cout << " ===================================================\n\n\n";
    //cout << " ---------------------------------------------------\n";
    //cout << "|            Administrator / Staff Login            |\n";
    //cout << " ---------------------------------------------------\n\n";
    //cout << "\nPlease enter your username: ";
    //cin >> userName;
    //cout << "\nPlease enter your user password: ";
    //cin >> userPassword;

    //if (userName == "admin" && userPassword == "admin")
    //{
    //    do

    cls();
    cout << "\n";
    cout << " ===================================================\n";
    cout << "|                     Admin Menu                    |\n";
    cout << " ===================================================\n\n\n";
    cout << "____________________________________________________\n";
    cout << "||\t1. Contact a User \t\t\t ||\n";
    cout << "||\t2. View User Inquiry's \t\t\t ||\n";
    cout << "||\t3. For Driver Info \t\t\t ||\n";
    cout << "||\t4. For Customer Info \t\t\t ||\n";
    cout << "||\t5. Logout\t\t\t\t ||\n";
    cout << "____________________________________________________\n";
    cout << "Enter choice: ";
    cin >> menu;
    switch (menu)
    {
    case 1:

        admin.SubmitInquiry();
        break;

    case 2:

        admin.ViewInquiry();
        system("PAUSE");
        break;

    case 3:

        drivdata();
        system("PAUSE");
        break;

    case 4:

        cusdata();
        system("PAUSE");
        break;


    case 5:

        cout << "You are Logged Out...!\n\n\n\n";
        system("PAUSE");
        MenuJunction();
        break;

    }
}
void feedback::SubmitInquiry()
    {
        cls();
        cout << "\n";
        cout << "\t\t ================================================\n";
        cout << "\t\t|           Feedback Management System           |\n";
        cout << "\t\t ================================================\n\n\n";
        cout << "\nInquiry Details: \n";
        cout << "_____________________________________ \n\n";
        node* temp;
        temp = new node;
        cout << "Reference Number: ";
        cin >> temp->feedback_number;
        cout << "Enter Customer Name: ";
        cin.ignore();
        getline(cin, temp->customerName);
        cout << "Enter Date : ";
        cin >> temp->date;
        cout << "Complaint Description:";
        cout << "( 1000 words max ) \n";
        cin.ignore();
        getline(cin, temp->t);
        cout << "===========================================================================" << endl;
        cout << "\t\tMessage Sent." << endl;
        cout << "===========================================================================" << endl;

        system("PAUSE");
        temp->next = NULL;
        if (start_ptr != NULL)
        {
            temp->next = start_ptr;
        }
        start_ptr = temp;
        cls();
    }
void feedback::ViewInquiry()
{
    int num;
    bool found;            //variable to search
    cls();
    node* temp;
    temp = start_ptr;
    found = false;
    cout << "\n";
    cout << " ================================================\n";
    cout << "|           Feedback Management System          |\n";
    cout << " ================================================\n\n\n";
    cout << " Enter the Reference Number To Look into The Inquiry Details\n";
    cin >> num;
    cout << "\n";
    cout << "---------------------------------------------------------------------------" << endl;
    cout << "\t\tHere are the details based on that reference number.\n";
    cout << "---------------------------------------------------------------------------" << endl;
    if (temp == NULL)
    {
        cout << "\tThere is no feedback or message to show in our database.";
    }
    while (temp != NULL && !found)
    {
        if (temp->feedback_number == num)
        {
            found = true;
        }
        else
        {
            temp = temp->next;
        }
        if (found)
        {
            cout << "Reference Number : " << temp->feedback_number;
            cout << "\n";
            cout << "Customer Name: " << temp->customerName << endl;
            cout << "Date : " << temp->date << endl;
            cout << "_____________________________________________________________________________" << endl;
            cout << " _______________________" << endl;
            cout << endl;
            cout << "|Complaint description: |" << endl;
            cout << " _______________________" << endl;
            cout << temp->t;
            cout << "\n";
            cout << "_____________________________________________________________________________" << endl;
        }
    }
}
void feedback::exit()
{
    cout << "Sad to see you go!" << endl;
}
void cusdata() {

    cls();//Clear screen
    //Level-2 display
    cout << "\t\t\tCUSTOMER INFORMATION SECTION\n\n\n";
    cout << "Enter your choice: " << endl;
    cout << "1.Create new entry\n";
    cout << "2.Find and display entry\n";
    cout << "3.Jump to main\n";
    cin >> choice2;

    switch (choice2)//Second switch

    {
    case '1'://Insert data
    {  ofstream f1("customerdata.txt", ios::app);

    for (i = 0; choice2 != 'n'; i++)
    {

        if ((choice2 == 'y') || (choice2 == 'Y') || (choice2 == '1'))
        {
            cout << "Enter First name: ";
            cin >> customerData.fname;
            cout << "Enter Last name: ";
            cin >> customerData.lname;
            cout << "Enter Phone Number: ";
            cin >> customerData.phno;
            cout << "Enter Email Address: ";
            cin >> customerData.cusemail;

            f1 << customerData.fname << endl << customerData.lname << endl << customerData.phno << endl << customerData.cusemail << endl;
            cout << "Do you want to enter data: ";
            cout << "Press Y for Continue and N to Exit Program:  ";
            cin >> choice2;
        }
    }
    f1.close();
    }
    break;//control back to inner loop -1

    case '2'://Display data
    {
        string find;
        ifstream f2("customerdata.txt");

        cout << "Enter First name to be displayed: ";
        cin >> find;
        cout << endl;
        int notFound = 0;
        for (j = 0; (j < i) || (!f2.eof()); j++)
        {

            getline(f2, customerData.fname);

            if (customerData.fname == find)
            {
                notFound = 1;
                cout << "First Name: " << customerData.fname << endl;
                cout << "Last Name: " << customerData.lname << endl;

                getline(f2, customerData.phno);
                cout << "Phone Number: " << customerData.phno << endl;
                getline(f2, customerData.cusemail);
                cout << "Email: " << customerData.cusemail << endl << endl;
            }

        }

        if (notFound == 0) {

            cout << "No Record Found" << endl;
        }
        f2.close();
        cout << "Press any key two times to proceed";
        getch();//To hold data on screen
        getch();//To hold data on screen

    }
    break;//control back to inner loop -1

    case 3://Jump to main
    {
        break;//inner switch breaking
    }
    }

    //break;//inner loop-1 breaking
}
void drivdata() {
 
    cls();

    cout << "\t\t\tDriver Information Section\n\n\n";
    cout << "Enter your choice: " << endl;
    cout << "1.Create new entry\n";
    cout << "2.Find and display\n";
    cout << "3.Jump to main\n";


    cin >> choice3;

    switch (choice3)//Third switch
    {
    case '1'://Insert data
    {
        ofstream t1("driverdata.txt", ios::app);

        for (i = 0; choice3 != 'n' && choice3 != 'N'; i++)
        {

            if ((choice3 == 'y') || (choice3 == 'Y') || (choice3 == '1'))
            {
                cout << "Enter First name: ";
                cin >> driv[i].fst_name;
                cout << "Enter Last name: ";
                cin >> driv[i].lst_name;
                cout << "Enter License Endorsement: ";
                cin >> driv[i].endorsement;
                cout << "Enter Experience(year): ";
                cin >> driv[i].exp;
                cout << "Enter Age: ";
                cin >> driv[i].serves;
                cout << "Enter Prior Work: ";
                cin >> driv[i].subj;
                cout << "Enter Hours Worked Per Week : ";
                cin >> driv[i].lec;
                cout << "Enter pay: ";
                cin >> driv[i].pay;
                cout << "Enter Phone Number: ";
                cin >> driv[i].cel_no;

                /*cout << endl;
                t1 << driv[i].fst_name << endl << driv[i].lst_name << endl
                << driv[i].qualification << endl << driv[i].exp << endl
                << driv[i].serves << endl << driv[i].subj << endl << driv[i].lec
                << endl << driv[i].pay << endl << driv[i].cel_no << endl;*/
                cout << "Do you want to enter more driver data: " << endl;
                cout << "Type yes to continue or no to FINISH: ";
                cin >> choice3;
            }//if
        }//for loop
        //for finding through name
        cls();



        t1.close();
    }//case 1

    //continue;//Control pass to inner loop-2

    case '2'://Display data
    {
        string find;
        ifstream t2("driverdata.txt");

        cout << "Enter name to be displayed: ";
        cin >> find;

        cout << endl;
        int notFound = 0;
        for (j = 0; ((j < i) || (!t2.eof())); j++)
        {

            getline(t2, driv[j].fst_name);

            if (driv[j].fst_name == find)
            {
                notFound = 1;
                cout << "First name: " << driv[j].fst_name << endl;
                getline(t2, driv[j].lst_name);
                cout << "Last name: " << driv[j].lst_name << endl;
                getline(t2, driv[j].endorsement);
                cout << "Qualification: " << driv[j].endorsement << endl;
                getline(t2, driv[j].exp);
                cout << "Experience: " << driv[j].exp << endl;

                getline(t2, driv[j].serves);
                cout << " Age : " << driv[j].serves << endl;

                getline(t2, driv[j].subj);
                cout << "Prior Work : " << driv[j].subj << endl;

                getline(t2, driv[j].lec);
                cout << "Enter hours worked(per Week): " << driv[j].lec << endl;
                getline(t2, driv[j].pay);
                cout << "pay: " << driv[j].pay << endl;

                getline(t2, driv[j].addrs);
                cout << "Address: " << driv[j].addrs << endl;

                getline(t2, driv[j].cel_no);
                cout << "Phone Number: " << driv[j].cel_no << endl;

            }

        }//for loop
        t2.close();
        if (notFound == 0) {

            cout << "No Record Found" << endl;

        }
        cout << "Press any key two times to proceed";
        getch();//To hold data on screen
        getch();//To hold data on screen
    }

    }
}


void FAQ()
{

    cout << "\t\t\tFrequently Asked Questions" << endl;
    cout << "________________________________________________________________________________________________" << endl;
    cout << "How do I become a Driver for this Company" << endl;
    cout << "\t\t Go back to the Main Menu and access the Driver Menu from there to apply with us." << endl;
    cout << "How do I get my property back if I left it in the taxi? " << endl;
    cout << "\t\tAs a customer you can reach out to our Admins in the Support section of the Customer Menu." << endl;
    cout << "\t\tAdmins have the ability to initiate contact between drivers and riders even after a ride has ended." << endl;
    cout << "How do I complain about a Driver?" << endl;
    cout << "\t\tAccess your support option in the customer menu and our admins will make an inquiry for you. " << endl;
    cout << "What if I don't want to wear a mask?" << endl;
    cout << "\t\t Unless you have a valid exemption you must wear a mask at all times." << endl;
    cout << "What happens if I need to be sick because I've drunk too much in town?" << endl;
    cout << "\t\t Please just politely ask the driver to pull over. If you throw up a cleaning fee will be charged." << endl;

    cout << "________________________________________________________________________________________________" << endl;

}
int main()
{
    TitlePage();
    /* MenuJunction();*/
     /*if (choice = '1')
     {
         CustomerMenu();
     }
     else if (choice = '2')
     {
         DriverTest();
         DriverMenu();
     }*/

    return 0;
}




/*UNUSED FUNCTIONS
/*SIGN IN*/
//void SignIn() // add funcction in which if username and password == admin login admin menu will open up
//{
//    int count;
//    string username, password, userid, pass;
//
//    cout << "Sign In: " << endl;
//    cout << " USERNAME : ";
//    cin >> username;
//    string ruserid = "userDB/";
//    ruserid.append(username);
//    cout << " PASSWORD : ";
//    cin >> password;
//
//    fstream user;
//    user.open(ruserid, ios::in);
//    if (!user)
//    {
//        cout << "USER NOT FOUND";
//    }
//    else
//    {
//        string pass;
//        user >> pass;
//        if (password == pass)
//        {
//            cout << "Login Successful";
//            CusLogin();
//        }
//        else
//        {
//            cout << "Incorrect Password, Try Again...\n";
//            SignIn();
//        }
//    }
//}
//void SignUp() // place customers terms and conditions here
//{
//    string rusername, rpassword, rpass, remail, raddress, rmobile, rpayment1, rpayment2, rpayment3, rpayment4, rpayment5;
//    string ruserid = "userDB/";
//    cls();
//user:
//    cout << "\t\t\t Enter a username : ";
//    cin >> rusername;
//
//    ruserid.append(rusername);
//
//    fstream test; // Check if username in use
//    test.open(ruserid, ios::in);
//    if (test)
//    {
//        test.close();
//        cout << "Username in use... Use Another\n";
//        ruserid = "userDB/";
//        goto user;
//    }
//
//    cout << "\t\t\t Enter a password : ";
//    cin.ignore();
//    cin >> rpassword;
//email:
//    cout << "\t\t\t Enter an email address : ";
//    cin.ignore();
//    cin >> remail;
//
//    if (emailcheck(remail) == 0)
//    {
//        cout << "Invalid Input, Please Try Again...\n";
//        goto email;
//    }
//
//    cout << "\t\t\t Enter your mobile number: ";
//    cin.ignore();
//    cin >> rmobile;
//    cout << "\t\t\t Enter your payment method: ";
//    cin.ignore();
//    cin >> rpayment1;
//    cout << "\t\t\t Card Number: ";
//    cin.ignore();
//    cin >> rpayment2;
//    cout << "\t\t\t Name on Card: ";
//    cin.ignore();
//    cin >> rpayment3;
//    cout << "\t\t\t Security Code / CVV: ";
//    cin.ignore();
//    cin >> rpayment4;
//    cout << "\t\t\t Expiry Date: ";
//    cin.ignore();
//    cin >> rpayment5;
//
//    cout << "Would you like to Log-in as a customer today ?\n";
//    bool yn = yesno();
//
//    if (yn == 0)
//    {
//        cout << "Thank you, come again. \n";
//        MenuJunction();
//    }
//
//    ofstream f1(ruserid, ios::app); // used to write inside the file with app mode
//    f1 << rpassword << endl
//        << remail << endl
//        << rmobile << endl
//        << rpayment1 << endl
//        << rpayment2 << endl
//        << rpayment3 << endl
//        << rpayment4 << endl
//        << rpayment5 << endin; // f1 is objectname for the file
//
//    f1.close();
//    cls();
//    PrintLine();
//    cout << "\n\t\t\t Thank you for registering! \n";
//    PrintLine();
//    this_thread::sleep_for(chrono::milliseconds(5000));
//
//    cls();
//    SignIn();
//}
//bool emailcheck(string email)
//{
//    int at = -1, dot = -1;
//
//    if (!isalpha(email[0]))
//    {
//        return 0;
//    }
//
//    for (int i = 0; i <= email.length(); i++)
//    {
//        if (email[i] == '@')
//        {
//            at = i;
//        }
//        else if (email[i] == '.')
//        {
//            dot = i;
//        }
//    }
//
//    if (at == -1 || dot == -1)
//    {
//        return 0;
//    }
//
//    if (at > dot)
//    {
//        return 0;
//    }
//
//    return 1;
//}
//void DriverTest() // place drivers terms and conditions here
//{
//
//    string q[5] = { "Have held a valid full New Zealand driver's licence for at least 1 year? (Yes/No):\t", "Question", "Question", "Question", "Question" };
//    char vehmnm[50], rego[7], disname[20];
//    int rating = 0;
//
//    TitlePrinter("Driver Eligibility Questions");
//
//    for (int i = 0; i < 4; i++)
//    {
//        bool yn = NULL;
//        cout << q[i];
//        yn = yesno();
//        if (yn == 1)
//        {
//            continue;
//        }
//        else if (yn == 0)
//        {
//            cout << "Sorry you are ineligible...\t";
//            main();
//        }
//    }
//
//    cout << "Please enter your vehicle make and model: ";
//    cin.ignore();
//    cin.getline(vehmnm, 50);
//
//    cout << "Please enter your REGO: ";
//
//    cin.getline(rego, 7);
//
//dis:
//    for (int f = 0; f < 19; f++)
//    {
//        disname[f] = '\0';
//    }
//    cout << "Please enter Display Name: (20 Character Limit) ";
//    cin.getline(disname, 20);
//
//    bool spchk = 0;
//    for (int j = 0; j < 19; j++)
//    {
//        if (disname[j] == ' ')
//        {
//            spchk = 1;
//        }
//    }
//
//    if (spchk == 1)
//    {
//        cout << "ERROR: No spaces allowed, Try again...";
//        goto dis;
//    }
//
//    string drivpath = "driverDB/";
//    drivpath.append(disname);
//
//    ofstream drivls("driverDB/driverls", ios::app);
//
//    drivls << endl
//        << disname;
//
//    ofstream drivinfo(drivpath, ios::app);
//    int a = 0;
//    while (vehmnm[a] != '\0')
//    {
//        drivinfo << vehmnm[a];
//        a++;
//    }
//    drivinfo << endl;
//    a = 0;
//    while (rego[a] != '\0')
//    {
//        drivinfo << rego[a];
//        a++;
//    }
//    drivinfo << endl
//        << '0';
//    drivls.close();
//    drivinfo.close();
//}


void TaxiFare()
{
    cls();
    int dist;
    cout << endl;
    cout << endl;
    cout << "________________________________________________________________________________________________" << endl;
    cout << endl;
    cout << "\t\t\tWhat distance will you travel? (KM): ";
    cin >> dist;
    if (dist <= 5)
        cout << "Fare is: $ " << 10;
    else if (dist > 5 && dist < 10)
        cout << "Fare is: $ " << 20;
    else if (dist >= 10 && dist < 30)
        cout << "Fare is: $ " << 50;
    else if (dist >= 30 && dist < 50)
        cout << "Fare is: $ " << 100;
    else if (dist >= 50 && dist < 80)
        cout << "Fare is: $ " << 150;
    else if (dist >= 80 && dist <= 100)
        cout << "Fare is: $ " << 250;
    else
        cout << "Your ride is cancelled. ";
}

/*UNKNOWN*/
rideinfo request(string pickup, string dropoff)
{
    rideinfo info;
    info.pick = pickup;
    info.drop = dropoff;
    srand(time(0));
    info.dis = rand() % 25;
    string drivers[15];

    float cost;
    
    if (info.dis > 0 && info.dis < 6)
    {
        cost = 10;
    }
    else if (info.dis > 5 && info.dis < 16)
    {
        cost = info.dis * 1.8;
    }
    else if (info.dis > 15 && info.dis < 25)
    {
        cost = info.dis * 1.5;
    }

    info.cost = (cost / 100) * 15 + cost; //GST Add

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
            for (int i = 0; i < 15; i++)
            {
                getline(drivls, drivers[i], '\n');
            }
            
        }

        srand(time(0));
        int drivln = rand() % 14;

        info.driver = drivers[drivln];
        cls();

        return info;
    }
}

// FAKE DISTANCE COUNT
/*
for (int i = info.drivdis; i > 0 ; i--)
{
     // replace with wait 1 min (enter to trigger)
}
*/


void CaccInfo() {
    string find;
    ifstream f2("customerdata.txt");
    string cusfile = "userDB/";
    cusfile.append(CusName);
    fstream g(cusfile);

    cout << "Please enter your name to access your data ";
    cin >> find;
    cout << endl;
    int notFound = 0;
    for (j = 0; (j < i) || (!f2.eof()); j++)
    {

        getline(f2, CusName);

        if (CusName == find)
        {

            notFound = 1;
            cout << " _____________________________________________________________" << endl;
            cout << "||                                                           ||" << endl;
            cout << "||Here are your Details--------------------------------------||" << endl;
            cout << "||___________________________________________________________||" << endl;
            cout << "Username: " << CusName << endl;
            getline(f2, CusPassword);
            cout << "Password: " << CusPassword << endl;
            getline(f2, CusPh);
            cout << "Phone Number: " << CusPh << endl;
            getline(f2, CusEml);
            cout << "Email: " << CusEml << endl;

            cout << "Card information: " << CusCardno << endl;
            cout << "Card Exp Date: " << CusEX << endl;
            cout << "CVV: " << CusCVV << endl;
            cout << "||___________________________________________________________||" << endl;
            cout << "||___________________________________________________________||" << endl;

            cout << endl;
            cout << "Would you like to edit your information " << customerData.fname << "? (Yes / No): " << endl;

            bool edit = yesno();

            if (edit == 1)
            {
                //open a file for registration
                ofstream g("customerdata.txt"); //'ofstream' is  for getting the stored data from the file,


                if (!g.is_open()) //if it's not open, then there is no such file with the given name inside this folder (means, in the folder where the .exe file is going to be made )
                {
                    cout << "could not open file customerdata.txt\n"; //just so we can know why it ain't working if it doesn't

                }

                cout << "\nCustomer Registration: ";
                getline(cin, CusName); //user input from keyboard will go into registerName variable for registration
                cout << "\nEnter New Username: ";
                getline(cin, CusName);
                cout << "\nEnter New Password: ";
                getline(cin, CusPassword); //user input from keyboard will go into registerPassword variable fors registration
                cout << "Enter New Email Address: ";
                getline(cin, CusEml);
                cout << "Enter New Home Address: ";
                getline(cin, CusAddr);
                cout << "Enter New Mobile / Landline Number: ";
                getline(cin, CusPh);
                cout << "Enter your payment card number: ";
                getline(cin, CusCardno);
                cout << "Enter the name present on this card: ";
                getline(cin, CusCardna);
                cout << "Enter Security Code / CVV: ";
                getline(cin, CusCVV);
                cout << "Enter Card Expiry Date: ";
                getline(cin, CusEX);

                cout << "\nIn case you forget your password/username here are some security questions for your new password: " << endl;
                cout << "________________________________________________________________________________________" << endl;
                cout << "\n Q1: What is Your favorite colour? Please enter everything in lowercase: ";
                cout << "\nEnter the security question's answer: ";
                getline(cin, regquese);
                cout << "\n Q2: What was your first best friends name? Please enter everything in lowercase: ";
                cout << "\nEnter the security question's answer: ";
                getline(cin, regquesd);
                cout << "\n Q3: What was the name of the first street you lived on? Please enter everything in lowercase: ";
                cout << "\nEnter the security question's answer: ";
                getline(cin, regquesf);
                cout << "Enter Password: ";
                cout << "________________________________________________________________________________________" << endl;

                g << CusName; //this put whatever's to the right (registerName) into , g 

                g << '\n'; //and change to anew line in file
                g << CusPassword; //and now write/store,the password
                //all data placed  safely insidea the file that g opened
                g << '\n';
                g << CusPh;
                g << '\n';
                g << CusEml;
                g << '\n';
                g << CusAddr;
                g << '\n';
                g << CusCardno;
                g << '\n';
                g << CusCardna;
                g << '\n';
                g << CusCVV;
                g << '\n';
                g << CusEX;
                g << '\n';
                g << '\n';
                g << regquese;
                g << '\n';
                g << regquesd;
                g << '\n';
                g << regquesf;

                g.close(); //always make sure to close the file, or else we might have to deal with some nasty unwanted stuff in the memory

                cout << "\nInformation Change is Successful!\n";
                this_thread::sleep_for(chrono::milliseconds(3000));
                CusRegoLogin();
            }
            else
            {
                cout << "Going back to the Customer Menu";
                this_thread::sleep_for(chrono::milliseconds(2000));
                cout << "...";
                this_thread::sleep_for(chrono::milliseconds(2000));
                cout << "...";
                this_thread::sleep_for(chrono::milliseconds(2000));
                cout << "..." << endl;
                CusBooking();
            }
        }
        //getline(cin, CusName); //user input from keyboard will go into registerName variable for registration
        //cout << "\nEnter Username: ";
        //getline(cin, CusName);
        //cout << "\nEnter Password: ";
        //getline(cin, CusPassword); //user input from keyboard will go into registerPassword variable fors registration
        //cout << "\nIn case you forget your password/username here are some security questions: " << endl;
        //cout << "________________________________________________________________________________________" << endl;
        //cout << "\n Q1: What is Your favorite colour? Please enter everything in lowercase: ";
        //cout << "\nEnter the security question's answer: ";
        //getline(cin, regquese);
        //cout << "\n Q2: What was your first best friends name? Please enter everything in lowercase: ";
        //cout << "\nEnter the security question's answer: ";
        //getline(cin, regquesd);
        //cout << "\n Q3: What was the name of the first street you lived on? Please enter everything in lowercase: ";
        //cout << "\nEnter the security question's answer: ";
        //getline(cin, regquesf);
        ///*cout << "Enter Password: ";*/
        //cout << "________________________________________________________________________________________" << endl;
        //cout << "Enter Email Address: ";
        //getline(cin, CusEml);
        //cout << "Enter Home Address: ";
        //getline(cin, CusAddr);
        //cout << "Enter Mobile / Landline Number: ";
        //getline(cin, CusPh);
        //cout << "Enter you payment card number: ";
        //getline(cin, CusCardno);
        //cout << "Enter the name present on this card: ";
        //getline(cin, CusCardna);
        //cout << "Enter Security Code / CVV: ";
        //getline(cin, CusCVV);
        //cout << "Enter Card Expiry Date: ";
        //getline(cin, CusEX);
    }

    if (notFound == 0) {

        cout << "No Record Found" << endl;
    }
    f2.close();
    cout << "Press any key two times to proceed";
    getch();//To hold data on screen
    getch();//To hold data on screen

}