#include <iostream>
#include <string>

using namespace std;

int main() {
    string plainText = "information security";
    cout << "Plain Text is: " << plainText << endl;

    char matrix[5][5];

    // Initialize the matrix with spaces (ASCII code 32)
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            matrix[i][j] = ' '; // Space character
        }
    }

    int length = plainText.size(); // Corrected assignment operator
    int index = 0;
    bool isComplete = false;

    // Fill matrix with plain text until it's complete
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            if(index < length) {
                matrix[i][j] = plainText[index];
                index++;
            } else {
                isComplete = true;
                break;
            }
        }
        if(isComplete) break;
    }

    // Print the created matrix
    cout << "Printing Created Matrix" << endl;
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // Encrypt the text based on user input
    cout << "Enter the choices" << endl;
    int input[5];

    // Take input from the user
    for(int i = 0; i < 5; i++) {
        cin >> input[i]; // Corrected input to take from the user
    }

    string encryptedText = "";
    int it = 0;

    // Create encrypted text
    while(it < 5) {
        int j = input[it];
        string str = "";

        for(int i = 0; i < 5; i++) {
            if(matrix[i][j] == ' ') // Ignore empty spaces
                continue;
            str = str + matrix[i][j];
        }

        encryptedText = encryptedText + str;
        it++;
    }

    // Output the plain text and the encrypted text
    cout << "The Plain Text is: " << plainText << endl;
    cout << "Encrypted Text is: " << encryptedText << endl;

    return 0;
}