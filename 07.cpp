#include <iostream>
#include <string>

using namespace std;

void generateEncrypted(string plainText) {
    char matrix[5][5];

    // Initialize matrix with spaces
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            matrix[i][j] = ' '; // Space character
        }
    }

    int rounds;
    cout << "Enter the number of rounds: " << endl;
    cin >> rounds;

    int round = 1;

    while(round <= rounds) {
        cout << "For Round " << round << endl;
        cout << "PlainText is: " << plainText << endl;

        int length = plainText.size(); // Corrected the syntax here
        int index = 0;
        bool isComplete = false;

        // Fill the matrix with plain text
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

        // Print the matrix
        cout << "Printing Created Matrix:" << endl;
        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 5; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }

        // Input for encryption (columns to use)
        int input[5];
        cout << "Enter 5 column indices for encryption (0-4):" << endl;
        for(int i = 0; i < 5; i++) {
            cin >> input[i];
        }

        // Encrypt the text based on column input
        string encryptedText = "";
        int it = 0;

        while(it < 5) {
            int j = input[it];
            string str = "";

            for(int i = 0; i < 5; i++) {
                if(matrix[i][j] == ' ') // Ignore spaces
                    continue;
                str = str + matrix[i][j];
            }

            encryptedText = encryptedText + str;
            it++;
        }

        // Show encrypted text after the round
        cout << "After Round " << round << " generated Encrypted Text is: " << encryptedText << endl;

        // Prepare for the next round by setting plainText as encryptedText
        plainText = encryptedText;
        round++;
    }
}

int main() {
    string plainText = "information security";

    // Call the encryption function
    generateEncrypted(plainText);

    return 0;
}