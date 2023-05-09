#include <iostream>
#include <string>

using namespace std;

// Function to encrypt a message using a simple substitution cipher
string encryptMessage(string message, string key) {
    string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ ";
    string encryptedMessage = "";

    for (char c : message) {
        size_t position = alphabet.find(c);
        if (position != string::npos) {
            char newChar = key.at(position);
            encryptedMessage += newChar;
        }
        else {
            encryptedMessage += c;
        }
    }

    return encryptedMessage;
}

// Function to decrypt a message using a simple substitution cipher
string decryptMessage(string message, string key) {
    string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ ";
    string decryptedMessage = "";

    for (char c : message) {
        size_t position = key.find(c);
        if (position != string::npos) {
            char newChar = alphabet.at(position);
            decryptedMessage += newChar;
        }
        else {
            decryptedMessage += c;
        }
    }

    return decryptedMessage;
}

int main() {
    string userMessage;
    string key = "THEQUICKBROWNFOXJUMPSOVERTHELAZYDOGthequickbrownfoxjumpsoverthelazydog";

    // Get user input
    cout << "Enter your message: ";
    getline(cin, userMessage);

    // Validate user input
    if (userMessage.empty()) {
        cout << "Error: Message cannot be empty." << endl;
        return 1;
    }

    // Encrypt the message
    string encryptedMessage = encryptMessage(userMessage, key);

    // Print the encrypted message
    cout << "\nEncrypted Message: " << encryptedMessage << endl;

    // Decrypt the message
    string decryptedMessage = decryptMessage(encryptedMessage, key);

    // Print the decrypted message
    cout << "\nDecrypted Message: " << decryptedMessage << endl;

    return 0;
}
