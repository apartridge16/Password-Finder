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

    string s;
    string target = "bob123";
    bool isFound = false;
    int count = 0;

    while (getline(inFile, s))
    {
        count++;

        if (s == target)
        {
            isFound = true;
            break;
        }
    }

    cout << "\n-----------------------------------------------------\n\n";

    if (isFound)
    {
        cout << "FOUND\n\n";
        cout << count << ": " << target;
    }
    else
    {
        cout << "CONGRATULATIONS, YOUR PASSWORD WASN'T FOUND";
    }

    cout << "\n\n-----------------------------------------------------\n";

    return 0;
}