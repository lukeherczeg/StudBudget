/*
 * authenticator.cpp
 *
 *  Created on: Mar 29, 2018
 *      Author: Luke H
 */
#include <iostream>
#include <string>
#include <map>
#include <iterator>
#include <fstream>
#include <istream>
#include <string>
#include <vector>
#include <QMessageBox>
#include "authenticator.h"
#include "user.h"

using namespace std;

Authenticator::Authenticator(){
    this->currentUser = NULL;

}

int characterCountUntilSpace(string word) // This is done, functions well.
{
    int count = 0;
    for(unsigned int i = 0; i < word.size(); i++) {
        if (isspace(word[i])){
            break;
        }
        count++;
    }
    return count;
}

User * Authenticator::getUser(){
    return this->currentUser;
}

void Authenticator::fillMapOfUsers(){
    ifstream readData;
    string tempUser, tempUsername, tempPassword;
    int passwordStart, tempPasswordLength, tempUsernameLength, usernameStart = 10, count = 0;
    readData.open("authData.txt");

    while(getline(readData, tempUser)){
        if(tempUser.size() > 1){
            count++;
            tempUsernameLength = characterCountUntilSpace(tempUser.substr(usernameStart));
            passwordStart = 24 + tempUsernameLength;  //24 is the length of the formatting string up to that point.
            tempPasswordLength = characterCountUntilSpace(tempUser.substr(passwordStart));

            tempUsername = tempUser.substr(usernameStart, tempUsernameLength);
            tempPassword = tempUser.substr(passwordStart, tempPasswordLength);

            User * newUser = new User(tempUsername, tempPassword);
            this->users.insert(make_pair(count, newUser));
        }
    }
    readData.close();
}

void Authenticator::clearUsers(){
    this->users.clear();
}

void Authenticator::logIn(string username, string password, bool & finished){
    bool login = false;
    string tempUser = "";
    ifstream readData;
    string auth = "Username: " + username + "    Password: " + password;
    readData.open("authData.txt");

    this->it = this->users.begin();

    while(getline(readData, tempUser)){
        this->currentUser = this->it->second;
        if(tempUser == auth){
            login = true;
            break;
        }
        if(this->it != this->users.end()){
            this->it++;
        }
    }

    if(login){
        finished = true;
    }

    readData.close();
}

void Authenticator::signUp(string username, string password, bool &exists){
    ifstream readData;
    string tempUser, tempUsername, tempPassword;
    int passwordStart, tempPasswordLength, tempUsernameLength, usernameStart = 10;

    readData.open("authData.txt");

    while(getline(readData, tempUser)){
        tempUsernameLength = characterCountUntilSpace(tempUser.substr(usernameStart));
        passwordStart = 24 + tempUsernameLength;  //24 is the length of the formatting string up to that point.
        tempPasswordLength = characterCountUntilSpace(tempUser.substr(passwordStart));

        tempUsername = tempUser.substr(usernameStart, tempUsernameLength);
        tempPassword = tempUser.substr(passwordStart, tempPasswordLength);


        if(tempUsername == username || tempPassword == password ){
            exists = true;
            break;
        }
    }

    if(!exists){
        string auth = "Username: " + username + "    Password: " + password;
        //			  Length 10	^			      Length 14 ^
        ofstream writeData;
        writeData.open ("authData.txt", ios_base::app); // Appends new data to the file
        writeData << auth << endl;
        writeData.close();
    }
}

