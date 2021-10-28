#include <iostream>
#include <vector>

using namespace std;

//Call this function to decrypt
vector<long long> decryptor(vector<long long> encryptedMessage, int d, int n); 

//Call this function to print the message
void printMessage(vector<long long> message);

int main(){                         //test harness
    
vector<long long> encryptedMessage = {19, 14, 51, 20, 7, 10, 21,
                                      7, 10, 25, 7, 26, 27, 12,
                                      10, 26, 33, 25, 7, 21, 14,
                                      8, 21, 7, 21, 14, 51, 7,
                                      17, 26, 8, 52, 25, 7, 9,
                                      8, 20, 20, 26, 21, 7, 27,
                                      51, 7, 39, 51, 8, 9, 14,
                                      51, 15, 7, 15, 26, 7, 20,
                                      26, 21, 7, 8, 15, 11, 33,
                                      25, 21, 7, 21, 14, 51, 7,
                                      17, 26, 8, 52, 25, 7, 8,
                                      15, 11, 33, 25, 21, 7, 21,
                                      14, 51, 7, 8, 9, 21, 10,
                                      26, 20, 7, 25, 21, 51, 18,
                                      25};
//long long type so that we can convert one vector to the other without overflowing #'s

//7 is d and 55 is n for Alice's secret key    
vector<long long> decryptedMessage = decryptor(encryptedMessage, 7, 55);

//print the decrypted message
printMessage(decryptedMessage);                                             

    return 0;
}

vector<long long> decryptor(vector<long long> encryptedMessage, int d, int n){ 
    vector<long long> newVal; //create another vector to push new converted val
    for (unsigned int i = 0; i < encryptedMessage.size(); i++) {
        long long ValToMod = encryptedMessage.at(i); //create a variable to modify value
        for (int j = 0; j < d - 1; j++) {
            ValToMod = ValToMod * encryptedMessage.at(i); //for loop for power conversion
        }

        newVal.push_back(ValToMod % n); //newVals take on the values modded
    }

    return newVal;
}

void printMessage(vector<long long> messageLetter){
    for (unsigned int i = 0; i < messageLetter.size(); i++) {
        if (messageLetter.at(i) == 28) {     //spaces in this case are the value 28
            cout << " ";
        }

        else {
            char print = 63 + messageLetter.at(i);  //63 = ascii value of where A starts in ex
            cout << print;                          //cout the letter to print
        }
    }
}
