#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    int key;
    cout << "Enter the Key" << endl;
    cin >> key;

    string input;
    cout << "Enter the plain text" << endl;
    cin >> input;

    map<char, int> mapping;
    char ch = 97; 
    for (int i = 0; i < 26; i++) {
        mapping[ch] = i;
        ch++;
    }

    int length = input.size();
    char* newString = new char[length]; 

    
    for (int i = 0; i < length; i++) {
        char ch = input[i];
        int mapValue = mapping[ch];
        int result = (mapValue + key) % 26;
        newString[i] = 97 + result; 
    }

    string cipherText = "";
    for (int i = 0; i < length; i++) {
        cipherText += newString[i];
    }
    cout << "The cipherText is: " << cipherText << endl;

    char* temp = new char[length]; 

    
    for (int i = 0; i < length; i++) {
        char ch = newString[i];
        int mapValue = mapping[ch];
        int result = (mapValue - key + 26) % 26; 
        temp[i] = 97 + result; 
    }

    string plainText = "";
    for (int i = 0; i < length; i++) {
        plainText += temp[i];
    }
    cout << "The plainText is: " << plainText << endl;

    
    delete[] newString;
    delete[] temp;

    return 0;
}