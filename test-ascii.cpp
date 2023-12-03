/*
Kenneth Guillont
kenneth.guillont83@myhunter.cuny.edu
Lab 6 task A
*/

#include <iostream>

using namespace std;

int main()
{
string str; getline(cin, str);

    for(int i = 0; i < str.length(); i++)
    {
        char c = str[i];

        cout << str[i] << " " << (int)c << endl;
    }

return 0;
}