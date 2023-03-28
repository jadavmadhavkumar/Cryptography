#include <iostream>
#include <string>

using namespace std;

// Function to encrypt a message using the Caesar cipher
string encrypt(string message, int shift) {
    string cipher = "";
    for (int i = 0; i < message.length(); i++) {
        // Shift each character by the specified amount
        char c = message[i];
        if (isalpha(c)) {
            c = toupper(c);
            c = char(int(c + shift - 65) % 26 + 65);
        }
        cipher += c;
    }
    return cipher;
}

// Function to decrypt a message using the Caesar cipher
string decrypt(string message, int shift) {
    string plain = "";
    for (int i = 0; i < message.length(); i++) {
        // Shift each character back by the specified amount
        char c = message[i];
        if (isalpha(c)) {
            c = toupper(c);
            c = ((c - 65 - shift + 26) % 26) + 65;
        }
        plain += c;
    }
    return plain;
}

int main() {
    string message;
    int shift;
    cout << "Enter a message: ";
    getline(cin, message);
    cout << "Enter a shift value: ";
    cin >> shift;

    // Encrypt the message
    string cipher = encrypt(message, shift);
    cout << "Encrypted message: " << cipher << endl;

    // Decrypt the message
    string plain = decrypt(cipher, shift);
    cout << "Decrypted message: " << plain << endl;

    return 0;
}
