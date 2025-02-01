#include <iostream>
#include <fstream>

using namespace std;

/*************************************************
 * Function main()
 * Putpose: To check for matching text in a given file
 **************************************************/
int main()
{
    string files[2] = {"rockyou.txt", "test.txt"};
    const int SIZE = sizeof(files) / sizeof(files[0]);

    char choice = 'y';
    do
    {
        int count = 0;
        string s = "";
        string pw = "";
        bool isFound = false;

        cout << "\nEnter Password: ";
        cin >> pw;

        for (int i = 0; i < SIZE; i++)
        {
            ifstream inFile(files[i]);

            if (!inFile)
            {
                cerr << "Error: Could not open file.\n";
                return 1;
            }

            inFile.close();
            inFile.open(files[i]);

            while (getline(inFile, s))
            {
                count++;

                if (s == pw)
                {
                    isFound = true;
                    break;
                }
            }

            if (isFound)
            {
                cout << "\n-----------------------------------------------------\n\n";
                cout << "FOUND\n\n";
                cout << count << ": " << pw;
                cout << "\n\n-----------------------------------------------------\n\n";
                break;
            }
            else if (!isFound && i == SIZE - 1)
            {
                cout << "\n-----------------------------------------------------\n\n";
                cout << "CONGRATULATIONS, YOUR PASSWORD WASN'T FOUND";
                cout << "\n\n-----------------------------------------------------\n\n";
                break;
            }
        }

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