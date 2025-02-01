#include <iostream>
#include <fstream>

using namespace std;

/*************************************************
 * Function main()
 * Putpose: To check for matching text in a given file
 **************************************************/
int main()
{
    ifstream inFile("rockyou.txt");

    if (!inFile)
    {
        cerr << "Error: Could not open file.\n";
        return 1;
    }

    char choice = 'y';
    do
    {
        inFile.close();
        inFile.open("rockyou.txt");

        int count = 0;
        string s = "";
        string pw = "";
        bool isFound = false;

        cout << "\nEnter Password: ";
        cin >> pw;

        while (getline(inFile, s))
        {
            count++;

            if (s == pw)
            {
                isFound = true;
                break;
            }
        }

        cout << "\n-----------------------------------------------------\n\n";

        if (isFound)
        {
            cout << "FOUND\n\n";
            cout << count << ": " << pw;
        }
        else
        {
            cout << "CONGRATULATIONS, YOUR PASSWORD WASN'T FOUND";
        }

        cout << "\n\n-----------------------------------------------------\n\n";

        cout << "Would you like to continue? (y/n): ";
        cin >> choice;
        choice = tolower(choice);
        if (choice != 'y' && choice != 'n')
        {
            do
            {
                cout << "\nInvalid Input\n";
                cout << "Would you like to continue? (y/n): ";
                cin >> choice;
                choice = tolower(choice);
            } while (choice != 'y' && choice != 'n');
        }

    } while (choice == 'y');

    return 0;
}