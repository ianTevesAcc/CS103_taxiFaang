#include <iostream>
#include <string>
using namespace std;

void printLine();              // decor func
void titlePrinter(string tit); // line centerer

int main()
{
    string title;

    // Title Output
    printLine();
    title = ("TAXI FAANG PROJECT");
    titlePrinter(title);
    printLine();
    cout << endl;

    // terms agreement var cont
    string termsAgreementY[5] = {"Yes", "yes", "Y", "y", "YES"}, termsAgreementN[5] = {"No", "no", "N", "n", "NO"}, userAgreement;

    // display terms and ask if user agrees or not
    title = ("Terms and Conditions");
    titlePrinter(title);
    cout << R"(***enter terms and cond here***)" << endl;
    printLine();
    cout << endl;
termsR: // loop if wrong input
    title = ("Do you agree with the Terms and Conditions?");
    titlePrinter(title);
    title = ("Yes / No");
    titlePrinter(title);
    cin >> userAgreement;
    cin.ignore();

    // loop and filter on if user agreed or not or entered a wrong input
    for (int i = 0; i < 6; i++)
    {
        if (userAgreement == termsAgreementY[i])
        {
            cout << "Were looking forward to our happy Journey with you ( ^ 0 ^)/" << endl;
            break;
        }
        else if (userAgreement == termsAgreementN[i])
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
    cout << "just testing the water" << endl;

    return 0;
}

void printLine()
{
    for (int i = 0; i < 60; i++)
    {
        cout << "*";
    }
    cout << endl;
}

void titlePrinter(string tit)
{
    int tot, spa, s;
    tot = tit.length();
    spa = 60 - tot;
    s = spa / 2;
    for (int i = 0; i != s; i++)
    {
        cout << " ";
    }
    cout << tit << endl;
}