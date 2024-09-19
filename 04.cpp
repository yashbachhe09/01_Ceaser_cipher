#include <iostream>
using namespace std;

int main() {
    string plainText = "coe";
    string key = "anotherbz";

    cout << "Plain Text is: " << plainText << endl;
    cout << "The Key is: " << key << endl;

    // Create key matrix
    char keyMatrix[3][3];
    int index = 0;
    bool isComplete = false;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            keyMatrix[i][j] = key[index];
            index++;
            if (index == key.size()) {
                isComplete = true;
                break;
            }
        }
        if (isComplete == true) break;
    }

    // Print the Key Matrix
    cout << "Printing Key Matrix:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << keyMatrix[i][j] << " ";
        }
        cout << endl;
    }

    // Create plain text matrix
    char ptMatrix[3][1];
    index = 0;
    isComplete = false;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 1; j++) {
            ptMatrix[i][j] = plainText[index];
            index++;
            if (index == plainText.size()) {
                isComplete = true;
                break;
            }
        }
        if (isComplete == true) break;
    }

    // Print the Plain Text Matrix
    cout << "Printing Plain Text Matrix:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 1; j++) {
            cout << ptMatrix[i][j] << " ";
        }
        cout << endl;
    }

    // Initialize cipher matrix
    int ctMatrix[3][1] = {0};

    // Multiply key matrix with plain text matrix
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 1; j++) {
            for (int k = 0; k < 3; k++) {
                int x = keyMatrix[i][k] - 97;  // Convert to 0-based alphabet index
                int y = ptMatrix[k][j] - 97;
                ctMatrix[i][j] += x * y;
            }
        }
    }

    // Print the Cipher Matrix
    cout << "Printing Cipher Matrix" << endl;
    string encryptedText = "";

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 1; j++) {
            int temp = ctMatrix[i][j] % 26;
            char ch = 97 + temp;  // Convert back to character
            encryptedText += ch;
            cout << ch << " ";
        }
        cout << endl;
    }

    cout << "The Plain Text is: " << plainText << endl;
    cout << "The Encrypted Text is: " << encryptedText << endl;

    return 0;
}