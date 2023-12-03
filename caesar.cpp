/*
Kenneth Guillont
Kenneth.guillont83@myhunter.cuny.edu
Lab 6 task B
*/

#include <iostream>
#include <cctype>

using namespace std;

char shiftChar(char c, int rshift) {
    if (isalpha(c)) {
        char base = isupper(c) ? 'A' : 'a';
        return static_cast<char>((c - base + rshift) % 26 + base);
    }
    return c;
}

string encryptCaesar(string plaintext, int rshift) {
    string newString;
    for (int i = 0; i < plaintext.length(); i++) {
        char c = plaintext[i];

        if (isalpha(c)) {
            char shiftedChar = shiftChar(c, rshift);
            newString += shiftedChar;
        }
        else {
            newString += c;
        }
    }
    return newString;
}

int main() {
    cout << "Enter plaintext: ";
    string plainText; getline(cin, plainText);

    cout << "Enter shift: ";
    int rightShift; cin >> rightShift;

    cout << "Ciphertext: " << encryptCaesar(plainText, rightShift) << endl;

    
    return 0;
}