#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <thread>
#include <stdlib.h>

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
void CusLogin();
void FAQ();

/*MAIN MENUS*/
void MenuJunction();
void DriverMenu();
void DrivMenu2();
void DrivLogin();
void CustomerMenu();
void TitlePage();
void AdminMenu();
void TaxiFare();

//CHANGES
//For customers
struct customer
{
    string fname;//for first name
    string lname;//for last name
    string phno;//for Registration No number
    string cusemail;//for class info
}customerData;//Variable of type

//For drivers
struct driver
{
    string fst_name;//first name of teacher
    string lst_name;//last name of teacher
    string qualification;//Qualification of teacher
    string exp;//Experience of the person
    string pay;//Pay
    string subj;//
    string lec;//hours per Week
    string addrs;//Address of home
    string cel_no;//Phone number

    string serves;//Number of

}driv[50];//Variable of




    /*UNKNOWN*/
    //rideinfo request(string pickup, string dropoff);
    //int count; // create variables
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
    // customer terms and conditions
    cout << "\t\t\t_________For Our Customers__________" << endl
        << endl;
    cout << "\t\t1. Stay safe and wear a mask unless you need to drink water" << endl;
    cout << "\t\t2. Please sit in the back seat if available to avoid transmission of Covid-19" << endl;
    cout << "\t\t3.If you have covid or flu symptoms please stay home and take a rapid-antigen test" << endl;
    cout << "\t\t4. Discrimination towards our drivers will not be tolerated." << endl;
    cout << "\t\t5. No consumption of food or drinks allowed within the taxi unless it is water." << endl;
    cout << "\t\t6. If you feel you need to be sick please ask our friendly staff to stop the car as to avoid messes." << endl;
    cout << "\t\t7. Any spill of food or drink may result in a customer being charged a fee for car cleaning." << endl
        << endl
        << endl;
    // driver terms and conditions
    cout << "\t\t\t__________For our Drivers___________" << endl
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
    cout << "Do you agree to these terms and conditions? (Answer: yes/no)" << endl;
    bool yn = yesno();
    if (yn == 1)
    {
        cout << "Welcome to our service";
        MenuJunction();
        
    }
    else
    {
        // everytime the code is processed the screen will clear
        cout << " Unless you agree you are not able to use our service. \n"
            << endl;
    }
}

/*MENU JUNCTION*/
void MenuJunction()
{
    cls();
kInvalidInput:

    cout << "\t\t\t ______________.~'~._.~'~._.~'~._.~'~.______________" << endl;
    cout << "\t\t\t ------------------- TAXI FANNG ---------------------" << endl;
    cout << "\t\t\t|                                                   |" << endl;
    cout << "\t\t\t|___________________________________________________|" << endl;
    cout << "\t\t\t| Press 1 for Customer Menu                         |" << endl;
    cout << "\t\t\t| Press 2 for Driver Menu                           |" << endl;
    cout << "\t\t\t| Press 3 for Administrator Menu                    |" << endl;
    cout << "\t\t\t| Press 4 to EXIT application                       |" << endl;
    cout << "\t\t\t ^^^^^ Select your choice from above ^^^^^ : ";
    cout << "\t\t\t                       ____" << endl;
    cout << "\t\t\t                   __/  |_|_" << endl;
    cout << "\t\t\t------------------|  _     _``-.--------------------" << endl;
    cout << "\t\t\t                  '-(_)---(_)--'" << endl;
    cout << "\t\t\t\tSafety is our middle name" << endl
        << endl
        << endl;


    cin >> choice;

    switch (choice)
    {
    case '1':
        CustomerMenu();
        break;
    case '2':
        DriverMenu();
        break;
    case '3':
        AdminMenu();
        break;
    case '4':
        TaxiFare();

    default:
        cout << "Invalid Input\nTry Again\n\nPress any key to CONTINUE" << endl;
        system("pause");
        cls();
       
    }

    cls();
}

/*CUSTOMER SUB-MENUS*/
void CustomerMenu()
{
    cls();
    int b;
    cout << "\t\t\t ______________.~'~._.~'~._.~'~._.~'~.______________" << endl;
    cout << "\t\t\t --------------------- KIA ORA ---------------------" << endl;
    cout << "\t\t\t|                                                   |" << endl;
    cout << "\t\t\t|___________________________________________________|" << endl;
    cout << "\t\t\t| Press 1 to Register / Login                       |" << endl;
    cout << "\t\t\t| Press 2 to become a driver with us!               |" << endl;
    cout << "\t\t\t| Press 3 for FAQ                                   |" << endl;
    cout << "\t\t\t| Press 4 to EXIT application                       |" << endl;
    cout << "\t\t\t ^^^^^ Select your choice from above ^^^^^ : ";
    cout << endl;

    cin >> b;

    switch (b)
    {
    case '1':
        CusLogin();
        break;
    case '2':
        DriverMenu();
        break;
    case '3':
        FAQ();
        break;
    default:
        cout << " Thank you, Have a nice day! :) " << endl;
        break;
    }
}
void CusLogin()
{
    cls();
    while (1)
    {

        cout << "\t\t\t ______________.~'~._.~'~._.~'~._.~'~.______________" << endl;
        cout << "\t\t\t ------------How can we help you today?-------------" << endl;
        cout << "\t\t\t|___________________________________________________|" << endl;
        cout << "\t\t\t| Press 1 for Customer Login                        |" << endl;
        cout << "\t\t\t| Press 2 for Customer Registration                 |" << endl;
        cout << "\t\t\t| Press 3 if you Forgot Password (or) Username      |" << endl;
        cout << "\t\t\t| Press 4 to EXIT application                       |" << endl;
        cout << "\t\t\t ^^^^^ Select your choice from above ^^^^^ : ";


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
            /*cout << "Enter Password: ";*/
            cout << "________________________________________________________________________________________" << endl;
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
            cout << "Enter Card Expiry Date: ";
            getline(cin, CusEX);

            g << CusName; //this put whatever's to the right (registerName) into , g (("driverdata.txt"))

            g << '\n'; //and change to anew line in file
            g << CusPassword; //and now write/store,the password
            //all data placed  safely insidea the file that g opened
            g << '\n';
            g << regquese;
            g << '\n';
            g << regquesd;
            g << '\n';
            g << regquesf;
            g << '\n';
            g << CusEml;
            g << '\n';
            g << CusAddr;
            g << '\n';
            g << CusPh;
            g << '\n';
            g << CusCardno;
            g << '\n';
            g << CusCardna;
            g << '\n';
            g << CusCVV;
            g << '\n';
            g << CusEX;
            g << '\n';


            g.close(); //always make sure to close the file, or else we might have to deal with some nasty unwanted stuff in the memory

            cout << "\nRegistration is ..Successful!\n";
            CusLogin();
        }
        if (Canswer == "1")
        {
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
                    break; //just exit the while loop if you've entered the valid account
                }
                cout << "incorrect name or password\n"; //if user  entered the wrong account details ,
                system("CLS");
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
// once customer is logged in - this will be the menu : 
// 1. book trip - need to pull a driver name, need to add GST // thomas task
// 2. support - lost items , complaints - go to admin also // bree task
// admin contacts between customer and driver, provide support number (rand number gen)
// 3. account info
// 4. exit


/*DRIVER SUB-MENUS*/
void DriverMenu()
{
    cls();
    int c;
    cout << "\t\t\t ______________.~'~._.~'~._.~'~._.~'~.______________" << endl; // Altered Menu
    cout << "\t\t\t ----------------- DRIVER MENU ---------------------" << endl;
    cout << "\t\t\t|                                                   |" << endl;
    cout << "\t\t\t|___________________________________________________|" << endl;
    cout << "\t\t\t| Press 1 to Register / Login                       |" << endl;
    cout << "\t\t\t| Press 2 EXIT program                              |" << endl;
    cout << "\t\t\t ^^^^^^^ Select your choice from above ^^^^^^^ : ";
    cin >> c;
    cout << endl;

    switch (c)
    {
    case 1:
        DrivMenu2();
        

    case 2:
        cout << "Goodbye! " << endl;
        break;
    default:

        cout << " Please select a given option from above. \n"
            << endl;
        MenuJunction();

    }
}
void DrivMenu2()
{
    cls();
    while (1)
    {

        cout << "\t\t\t ______________.~'~._.~'~._.~'~._.~'~.______________" << endl;
        cout << "\t\t\t ------------How can we help you today?-------------" << endl;
        cout << "\t\t\t|___________________________________________________|" << endl;
        cout << "\t\t\t| Press 1 for Driver Login                          |" << endl;
        cout << "\t\t\t| Press 2 to Driver Registration                    |" << endl;
        cout << "\t\t\t| Press 3 if you Forgot Password (or) Username      |" << endl;
        cout << "\t\t\t| Press 4 to go back to Main Menu                   |" << endl;
        cout << "\t\t\t ^^^^^ Select your choice from above ^^^^^ : ";

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


            string q[5] = { "Have you held a valid full New Zealand driver's licence for at least 1 year? (Yes/No):\t",  };
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
                    MenuJunction();
                }
            }
            cin.ignore();

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

            cout << "\nRegistration is ..Successful!\n" << endl;
            this_thread::sleep_for(chrono::milliseconds(3000));
            DrivMenu2();
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
                //you are going to input the name and password here
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
                    DrivLogin();
                    
                }
                cout << "incorrect name or password\n"; //if user  entered the wrong account details ,
                this_thread::sleep_for(chrono::milliseconds(3000));
                system("CLS");
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

                DrivMenu2();
            }

        }

        //now process about the account

        cout << "\n\n\n\n\n"; //give it 5 newlines
    }
    /*return 1;*/
}
void DrivLogin()
{
    cls();
    cout << "\t\t\t ______________.~'~._.~'~._.~'~._.~'~.______________" << endl;
    cout << "\t\t\t ------------How can we help you today?-------------" << endl;
    cout << "\t\t\t|___________________________________________________|" << endl;
    cout << "\t\t\t| Press 1 to Begin Driving                          |" << endl;
    cout << "\t\t\t| Press 2 to Access Account Information             |" << endl;
    cout << "\t\t\t| Press 3 for Support                               |" << endl;
    cout << "\t\t\t| Press 4 to EXIT application                       |" << endl;
    cout << "\t\t\t ^^^^^ Select your choice from above ^^^^^ : ";
}
// additions to driver menu
// 1. idenitical to request function just needs modifying to suit driver // thomas
// 2. driver info
// 3. support - driver support file - (1 for driver 1 for customer)
// what can we do to help? 

/*ADMIN SUB-MENUS*/
//void AdminLogin() --to be able to access admin menu
void AdminMenu()
{
    // a function that's triggered by another set of numbers
    // login to validate admin with secure password

    //int i = 0, j;//for processing usage
    char choice1;//for getting choice
    //char choice2;
    //char choice3;
    //string find;//for sorting
    //string srch;
    cls();
AdminMain:
    
    cout << "\t\t\t ______________.~'~._.~'~._.~'~._.~'~.______________" << endl;
    cout << "\t\t\t ----------------- WELCOME ADMIN -------------------" << endl;
    cout << "\t\t\t|                                                   |" << endl;
    cout << "\t\t\t|___________________________________________________|" << endl;
    cout << "\t\t\t| Press 1 for Driver Info                           |" << endl;
    cout << "\t\t\t| Press 2 for Customer Info                         |" << endl;
    cout << "\t\t\t| Press 3 if Access Driver Applications             |" << endl;
    cout << "\t\t\t| Press 4 if Access Feedback/Complaints             |" << endl;
    cout << "\t\t\t| Press 5 to EXIT application                       |" << endl;
    cout << "\t\t\t ^^^^^^^^ Select your choice from above ^^^^^^^^ : ";
 

   

    cin >> choice1;

    system("cls");//Clear screen


    switch (choice1)//First switch
    {

        {
    case '1'://inner loop-1
    {
        cusdata();
    }

    case '2'://drivers data
    {
        drivdata();

    case '3':
    {
        system("cls");
        cout << " Here are you're current pending applications";
        ifstream f("driver.txt");
    }//case 3


    }
        }



        return 0;
        break;//Control pass to 1st loop  
    }
}
// not connecting for some reason to menujunction();
void cusdata() {
    int i = 0, j;//for processing usage
    char choice1;//for getting choice
    char choice2;
    char choice3;
    string find;//for sorting
    string srch;
    customer customerData;
    system("cls");//Clear screen
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
    {  ifstream f2("customerdata.txt");

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
    int i = 0, j;//for processing usage
    char choice1;//for getting choice
    char choice2;
    char choice3;
    string find;//for sorting
    string srch;
    system("cls");//Clear screen
//Level-2 Display process
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
                cin >> driv[i].qualification;
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
        system("cls");



        t1.close();
    }//case 1

    //continue;//Control pass to inner loop-2

    case '2'://Display data
    {
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
                getline(t2, driv[j].qualification);
                cout << "Qualification: " << driv[j].qualification << endl;
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

            }//if

        }//for loop
        t2.close();
        if (notFound == 0) {

            cout << "No Record Found" << endl;
        }
        cout << "Press any key two times to proceed";
        getch();//To hold data on screen
        getch();//To hold data on screen
    }//case 2
    }

    //continue;//Control pass to inner loop-2
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
void FAQ()
{
    cls();
    cout << "\t\t\tFrequently Asked Questions" << endl;
    cout << "________________________________________________________________________________________________" << endl;
    cout << "Are you guys cheap?" << endl;
    cout << "\t\t Yes heaps cheap, 2 bucks a KM." << endl;
    cout << "Will your drivers stop at maccies on the way home from town? " << endl;
    cout << "\t\tNo. Stop asking." << endl;
    cout << "Can I give the driver a wee kiss on the forehead for good luck?" << endl;
    cout << "\t\tNot only is that incredibly innappropriate but it is " << endl;
    cout << "\t\talso against our strict Covid-19 Policy on mask-wearing and social distancing." << endl;
    cout << "Is it wrong to throw up in my hands and toss it out the window?" << endl;
    cout << "\t\tGlad you asked! Yes! It is! If you so much as get a smidge of sick on our drivers car interior" << endl;
    cout << "\t\t a cleaning fee will be charged to your account. Please just politely ask the driver to pull over." << endl;
    cout << "Can I vape sick clouds in the car?" << endl;
    cout << "\t\tAt the Drivers discretion. Please ask before doing so." << endl;
    cout << "________________________________________________________________________________________________" << endl;

}
/*SIGN IN*/
void SignIn() // add funcction in which if username and password == admin login admin menu will open up
{
    int count;
    string username, password, userid, pass;

    cout << "Sign In: " << endl;
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
            CusLogin();
        }
        else
        {
            cout << "Incorrect Password, Try Again...\n";
            SignIn();
        }
    }
}
void SignUp() // place customers terms and conditions here
{
    string rusername, rpassword, rpass, remail, raddress, rmobile, rpayment1, rpayment2, rpayment3, rpayment4, rpayment5;
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

    cout << "\t\t\t Enter your mobile number: ";
    cin.ignore();
    cin >> rmobile;
    cout << "\t\t\t Enter your payment method: ";
    cin.ignore();
    cin >> rpayment1;
    cout << "\t\t\t Card Number: ";
    cin.ignore();
    cin >> rpayment2;
    cout << "\t\t\t Name on Card: ";
    cin.ignore();
    cin >> rpayment3;
    cout << "\t\t\t Security Code / CVV: ";
    cin.ignore();
    cin >> rpayment4;
    cout << "\t\t\t Expiry Date: ";
    cin.ignore();
    cin >> rpayment5;

    cout << "Would you like to Log-in as a customer today ?\n";
    bool yn = yesno();

    if (yn == 0)
    {
        cout << "Thank you, come again. \n";
        MenuJunction();
    }

    ofstream f1(ruserid, ios::app); // used to write inside the file with app mode
    f1 << rpassword << endl
        << remail << endl
        << rmobile << endl
        << rpayment1 << endl
        << rpayment2 << endl
        << rpayment3 << endl
        << rpayment4 << endl
        << rpayment5 << endin; // f1 is objectname for the file

    f1.close();
    cls();
    PrintLine();
    cout << "\n\t\t\t Thank you for registering! \n";
    PrintLine();
    this_thread::sleep_for(chrono::milliseconds(5000));

    cls();
    SignIn();
}
bool emailcheck(string email)
{
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
void ForgotPassword()
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
        ForgotPassword();
    }
}

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
//rideinfo request(string pickup, string dropoff)
//{
//    rideinfo info;
//    info.pick = pickup;
//    info.drop = dropoff;
//    srand(time(0));
//    info.dis = rand() % 25;
//
//    if (info.dis > 0 && info.dis < 6)
//    {
//        info.cost = 10;
//    }
//    else if (info.dis > 5 && info.dis < 16)
//    {
//        info.cost = info.dis * 1.8;
//    }
//    else if (info.dis > 15 && info.dis < 25)
//    {
//        info.cost = info.dis * 1.5;
//    }
//
//    TitlePrinter("CONFIRM BOOKING");
//    cout << "\tPickup from: " << pickup << "\n\tDropoff at: " << dropoff << "\n\tDistance to Travel: " << info.dis << "\n\tTotal Cost: $" << info.cost << "\n\tConfirm: (Yes/No) ";
//    bool yn = yesno();
//
//    if (yn == 0)
//    {
//        cout << "\n\tBOOKING CANCELED";
//        main();
//    }
//    else if (yn == 1)
//    {
//        // GET RANDOM DRIVER FROM DB --
//        TitlePrinter("SEARCHING AVAILABLE DRIVERS...");
//        PrintLine();
//
//        string line;
//        int lncnt = 0;
//
//        ifstream drivls("driverDB/driverls");
//        if (drivls.is_open())
//        {
//            while (!drivls.eof())
//            {
//                getline(drivls, line);
//                lncnt++;
//            }
//        }
//
//        srand(time(0));
//        int drivln = rand() % lncnt;
//
//        int schln = 0;
//
//        if (drivls.is_open())
//        {
//            while (getline(drivls, line))
//            {
//
//                if (schln == drivln)
//                {
//                    info.driver = line;
//                    cout << line;
//                    drivls.close();
//                    break;
//                }
//                schln++;
//            }
//        }
//        cls();
//    }
//}

// FAKE DISTANCE COUNT
/*
for (int i = info.drivdis; i > 0 ; i--)
{
     // replace with wait 1 min (enter to trigger)
}
*/


