/*
Kenneth Guillont
kenneth.guillont83@myhunter.cuny.edu
Lab 6 task C
*/

#include <iostream>
#include <string>

using namespace std;

char shiftChar(char c, int rshift) {
    if (isalpha(c)) {
        char base;
    if (c >= 'A' && c <= 'Z') {
        base = 'A';
    } else {
        base = 'a';
    }
        return (c - base + rshift) % 26 + base;
    }
    return c;
}

string encryptVigenere(string plaintext, string keyword) {
    string ciphertext;
    int keywordLen = keyword.length();
    int keywordIndex = 0;

    for (int i = 0; i < plaintext.length(); i++) {
        char c = plaintext[i];
        if (isalpha(c)) {
            char base;
        if (islower(c)) {
            base = 'a';
        } else {
            base = 'A';
        }
            int shift = keyword[keywordIndex] - 'a';
            char shiftedChar = shiftChar(c, shift);
            ciphertext += shiftedChar;

            keywordIndex = (keywordIndex + 1) % keywordLen;
        }
        else {
            ciphertext += c;
        }
    }

    return ciphertext;
}

int main() {
    cout << "Enter plaintext: ";
    string plaintext;
    getline(cin, plaintext);

    cout << "Enter keyword  : ";
    string keyword;
    cin >> keyword;

    string ciphertext = encryptVigenere(plaintext, keyword);
    cout << "Ciphertext     : " << ciphertext << endl;

    return 0;
}