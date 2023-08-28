/*
@author Ritika Shrestha, Long Pham
@description Project3: Caesar Cipher - decrypting message with keys
@date 2023-02-07
@updated 2023-02-12
@keyused: 7
@quoteauthor: Lady Gaga
*/

#include <iostream>              //import libraries
#include <string>
#include <cctype>
using namespace std;
void decryptCipherText(const int key) {
    string plainText,line;

    while (getline(cin,line)) {      //get line from input
        int letterToInt, keyShifted, decryptedLetter, keyInRange;

        for (char letter:line){      //iterate through letters in a line
            if (isspace(letter)) {                //if letter is a space
                plainText += letter;              //print as-is
            }
            else {
            letterToInt = (int(letter) - 97);    //subtract 97 from ASCII values
            keyShifted = letterToInt - key;      //shift using the key
            keyInRange = (keyShifted + 26) % 26; //ensure keys are in 0 to 25
            decryptedLetter = keyInRange + 97;   //convert decrypted letter to ASCII values
            plainText += char(decryptedLetter);
            }

        }
        plainText += "\n";  //newline after every line
    }

    cout << plainText << endl;

}

int main(int argc, char *argv[]) {
    int key;
    if ( argc > 1 )
      key = atoi(argv[1]);
    else
      key = 3;

    decryptCipherText(key);
    return 0;
}
