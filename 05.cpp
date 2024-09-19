#include <iostream>
using namespace std;

int main() {
    string plainText;

    // Ask the user to enter plain text
    cout << "Enter the Plain Text:" << endl;
    getline(cin, plainText);

    string str1 = "";  // To store alternate characters
    string str2 = "";  // To store other alternate characters
    bool flag = true;  // Flag to alternate between str1 and str2

    int length = plainText.size();

    for (int i = 0; i < length; i++) {
        if (plainText[i] == 32)  // Ignore spaces
            continue;

        if (flag == true) {
            str1 = str1 + plainText[i];  // Add to str1
            flag = false;  // Set flag to false to alternate
        } else {
            str2 = str2 + plainText[i];  // Add to str2
            flag = true;  // Set flag back to true
        }
    }

    // Display results
    cout << str1 << " " << str2 << endl;

    string encryptedText = str1 + str2;

    cout << "The Plain Text is: " << plainText << endl;
    cout << "The Encrypted Text is: " << encryptedText << endl;

    return 0;
}