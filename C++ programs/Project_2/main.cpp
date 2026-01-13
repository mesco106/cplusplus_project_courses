#include <iostream>
#include <string>

using namespace std;

int main(){
    string alphabet {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    string key  {"XZNLWEBGJHQDYVTKFUOMPCIASRxznlwebgjhqdyvtkfuompciasr"};

    cout << "Enter you secret message: ";
    string message;
    getline(cin, message);

    cout << "\nEncrypting message..." << endl;

    string encryptedMessage;
    for (char letter : message){
        size_t position{alphabet.find(letter)};
        (position != string::npos) ? encryptedMessage.push_back(key.at(position)) : encryptedMessage.push_back(letter);
    }
 
    cout << endl << "Encrypted message: " <<encryptedMessage << endl;
    cout << "\nDencrypting message..." << endl;

    message.clear();
    for (char letter : encryptedMessage){
        size_t position{key.find(letter)};
        (position != string::npos) ? message.push_back(alphabet.at(position)) : message.push_back(letter);
    }

    cout << endl << "Decrypted message: " << message << endl;
    return 0;
}