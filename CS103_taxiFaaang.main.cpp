#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void PrintLine();              // function to output a line for decoration
void TitlePrinter(string tit); // prints title into center by printing spaces equal to the available spaces of width of console before printing title

int main()
{
    string title;

    // title output
    PrintLine();
    title = ("TAXI FAANG PROJECT");
    TitlePrinter(title);
    PrintLine();
    cout << endl;

    // terms agreement var container
    string terms_agreement_agree[5] = {"Yes", "yes", "Y", "y", "YES"};
    string terms_agreement_disagreed[5] = {"No", "no", "N", "n", "NO"};
    string user_agreement;

    // display terms and ask if user agrees or not
    title = ("Terms and Conditions");
    TitlePrinter(title);
    cout << R"(***enter terms and cond here***)" << endl;
    PrintLine();
    cout << endl;
termsR: // loop if wrong input
    title = ("Do you agree with the Terms and Conditions?");
    TitlePrinter(title);
    title = ("Yes / No");
    TitlePrinter(title);
    cin >> user_agreement;
    cin.ignore();

    // loop and filter on if user agreed or not or entered a wrong input
    for (int i = 0; i < 6; i++)
    {
        if (user_agreement == terms_agreement_agree[i])
        {
            cout << "Were looking forward to our happy Journey with you ( ^ 0 ^)/" << endl;
            break;
        }
        else if (user_agreement == terms_agreement_disagreed[i])
        {
            cout << "Were sad to see you go, we wish you a safe journey ( ^ 3 ^)/";
            return 0;
        }
        else if (i > 4)
        {
            cout << "Wrong Input, please enter either (Yes / No)" << endl
                 << endl;
            goto termsR;
        }
    }

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