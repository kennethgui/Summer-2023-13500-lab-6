/*
Kenneth Guillont
kenneth.guillont83@myhunter.cuny.edu
Lab 6 task C
*/

#include <iostream>
#include <string>
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

string encryptVigenere(string plaintext, string keyword) {
    string ciphertext;
    int keywordLen = keyword.length();
    int keywordIndex = 0;

    for (int i = 0; i < plaintext.length(); i++) {
        char c = plaintext[i];
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
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

string decryptCaesar(string ciphertext, int rshift) {
    return encryptCaesar(ciphertext, 26 - rshift);
}


string decryptVigenere(string ciphertext, string keyword) {
    string plaintext;
    int keywordLen = keyword.length();
    int keywordIndex = 0;

    for (int i = 0; i < ciphertext.length(); i++) {
        char c = ciphertext[i];
        if (isalpha(c)) {
            char base;
        if (islower(c)) {
            base = 'a';
        } else {
            base = 'A';
        }
            int shift = keyword[keywordIndex] - 'a';
            char shiftedChar = shiftChar(c, 26 - shift);
            plaintext += shiftedChar;

            keywordIndex = (keywordIndex + 1) % keywordLen;
        }
        else {
            plaintext += c;
        }
    }

    return plaintext;
}

int main() {
    cout << "Enter plaintext: ";
    string plaintext;
    getline(cin, plaintext);

    cout << "= Caesar =" << endl;
    cout << "Enter shift    : ";
    int rshift;
    cin >> rshift;


    string caesarCiphertext = encryptCaesar(plaintext, rshift);
    cout << "Ciphertext     : " << caesarCiphertext << endl;

    string caesarDecrypted = decryptCaesar(caesarCiphertext, rshift);
    cout << "Decrypted      : " << caesarDecrypted << endl;

    cout << "= Vigenere =" << endl;
    cout << "Enter keyword  : ";
    string keyword;
    getline(cin, keyword);

    string vigenereCiphertext = encryptVigenere(plaintext, keyword);
    cout << "Ciphertext     : " << vigenereCiphertext << endl;

    string vigenereDecrypted = decryptVigenere(vigenereCiphertext, keyword);
    cout << "Decrypted      : " << vigenereDecrypted << endl;

    return 0;
}
