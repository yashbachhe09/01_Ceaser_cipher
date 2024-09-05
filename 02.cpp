#include <iostream>
using namespace std;

int main() {
    string plainText;
    cout << "Enter the Plain Text: " << endl;
    cin >> plainText;

    string key;
    cout << "Enter the Key: " << endl;
    cin >> key;


    if (key.size() != plainText.size()) {
        int index = 0;
        int length = key.size();
        int difference = plainText.size() - length;

        while (difference > 0) {
            key += key[index];
            index++;
            if (index == length) {
                index = 0;
            }
            difference--;
        }
    }

    cout << "Plain Text: " << plainText << endl;
    cout << "Key: " << key << endl;


    string encryptedText = "";
    int index = 0;

    while (index < plainText.size()) {
        int a = plainText[index] - 'a'; 
        int b = key[index] - 'a'; 
        int temp = (a + b) % 26; 
        char character = temp + 'a'; 
        encryptedText += character;
        index++;
    }

    cout << "Encrypted Text: " << encryptedText << endl;

    return 0;
}