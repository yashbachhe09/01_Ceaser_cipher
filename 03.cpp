#include <iostream>
#include <map>
using namespace std;


string getCipherText(char keyMatrix[][5], string input) {
    int r1, c1, r2, c2;


    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (keyMatrix[i][j] == input[0]) {
                r1 = i;
                c1 = j;
            }
            if (keyMatrix[i][j] == input[1]) {
                r2 = i;
                c2 = j;
            }
        }
    }

    string answer = "";

    if (r1 == r2) {
        char a, b;
        a = (c1 + 1) < 5 ? keyMatrix[r1][c1 + 1] : keyMatrix[r1][0];
        b = (c2 + 1) < 5 ? keyMatrix[r2][c2 + 1] : keyMatrix[r2][0];
        answer += a;
        answer += b;
    }

  
    else if (c1 == c2) {
        char a, b;
        a = (r1 + 1) < 5 ? keyMatrix[r1 + 1][c1] : keyMatrix[0][c1];
        b = (r2 + 1) < 5 ? keyMatrix[r2 + 1][c2] : keyMatrix[0][c2];
        answer += a;
        answer += b;
    }


    else {
        answer += keyMatrix[r1][c2];
        answer += keyMatrix[r2][c1];
    }

    return answer;
}


void generateKeyMatrix(string key, char keyMatrix[5][5]) {
    map<char, bool> visited;
    int keyLength = key.length();
    int index = 0;

    
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            while (index < keyLength && visited[key[index]]) {
                index++;
            }

            if (index < keyLength) {
                keyMatrix[i][j] = key[index];
                visited[key[index]] = true;
                index++;
            } else {
           
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    if (ch != 'j' && !visited[ch]) {
                        keyMatrix[i][j] = ch;
                        visited[ch] = true;
                        break;
                    }
                }
            }
        }
    }
}


void displayKeyMatrix(char keyMatrix[5][5]) {
    cout << "Key Matrix:" << endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << keyMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    string plainText, key;

    
    cout << "Enter the plain text: ";
    cin >> plainText;
    
    cout << "Enter the key: ";
    cin >> key;

    char keyMatrix[5][5];
    generateKeyMatrix(key, keyMatrix);

    
    displayKeyMatrix(keyMatrix);

    
    string input[10];
    int index = 0;
    for (int i = 0; i < plainText.size(); i += 2) {
        string temp = "";
        temp += plainText[i];
        temp += (i + 1 < plainText.size()) ? plainText[i + 1] : 'x'; 
        input[index++] = temp;
    }

   
    cout << "Plain Text Digraphs:" << endl;
    for (int i = 0; i < index; i++) {
        cout << input[i] << " ";
    }
    cout << endl;

 
    string encryptedText = "";
    for (int i = 0; i < index; i++) {
        encryptedText += getCipherText(keyMatrix, input[i]);
    }

   
    cout << "Encrypted Text: " << encryptedText << endl;

    return 0;
}
