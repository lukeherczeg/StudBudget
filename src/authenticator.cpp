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
using namespace std;
#include "authenticator.h"
#include "user.h"

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

void Authenticator::printUserObjects(){
	cout << "  Memory    |  User" << endl;
	for(this->it = this->users.begin(); this->it != this->users.end(); this->it++){
		cout << "["<< this->it->second << "] | [";
		cout << this->it->second->getUsername() << "]"<< endl;
	}
	cout << "____________________________________________" << endl;
}

bool Authenticator::isUser(string username){
	for(this->it = this->users.begin(); this->it != this->users.end(); this->it++){
		if(this->it->second->getUsername() == username){
			return true;
		}
	}
	return false;
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
	else{
		cout << "Didn't find your username or password. Please sign up." << endl;
	}

	readData.close();
}

void Authenticator::signUp(string username, string password){
	ifstream readData;
	string tempUser, tempUsername, tempPassword;
	int passwordStart, tempPasswordLength, tempUsernameLength, usernameStart = 10;
	bool exists = false;

	readData.open("authData.txt");

	while(getline(readData, tempUser)){
		tempUsernameLength = characterCountUntilSpace(tempUser.substr(usernameStart));
		passwordStart = 24 + tempUsernameLength;  //24 is the length of the formatting string up to that point.
		tempPasswordLength = characterCountUntilSpace(tempUser.substr(passwordStart));

		tempUsername = tempUser.substr(usernameStart, tempUsernameLength);
		tempPassword = tempUser.substr(passwordStart, tempPasswordLength);


		if(tempUsername == username || tempPassword == password ){
			cout << "Username or password already in use! Try something else." << endl;
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

		cout << "Account created! You can now log in." << endl;
		writeData.close();
	}
}

void Authenticator::printUsers(){
	ifstream readData;
	string tempUser;
	int count = 0;

	cout << "Users:" << endl;
	readData.open("authData.txt");
	while(getline(readData, tempUser)){
		count++;
		cout << count << ".) " << tempUser << endl;
	}
	if(count == 0){
		cout << "No users found." << endl;
	}
	readData.close();
}

void Authenticator::authenticate(){
	string username = "", password = "", choice2 = "";
	int choice = 0, count = 0;
	bool finished = false;

	cout << "\nWelcome to the Budgeting App. Sign up below! \nIf you have an account already, please enter your username and password.\n" << endl
		 << "\t1. Log in\n\t2. Sign up\n\t3. Print users\n\t4. Clear all users\n\t5. Exit" << endl;

	while(!finished) {
		while (true){
			cout << "\nYour choice: "; cin >> choice;
			if(cin.fail()){
				cin.clear(); //This corrects the stream.
				cin.ignore(); //This skips the left over stream data.
				if(count == 0)
					cout << "Please enter an integer only." << endl;
				count++;
			}
			else break;
		}

		switch(choice){
			case 1:
				this->fillMapOfUsers(); // Properly assigns pointers to every user.
				cout << "Username : "; cin >> username;
				cout << "Password : "; cin >> password;
				this->logIn(username, password, finished);
				break;
			case 2:
				cout << "Username : "; cin >> username;
				cout << "Password : "; cin >> password;
				this->signUp(username, password);
				break;
			case 3:
				this->printUsers();
				break;
			case 4:
				cout << "Are you sure you want to clear all users? y/n : ";
				cin >> choice2;
				if(choice2 == "y"){
					remove("authData.txt");
				}
				else break;
				this->users.clear();
				cin.clear();
				break;
			case 5:
				this->currentUser = NULL; //Set to null to exit
				finished = true;
				break;
			default:
				cout << "Please enter an integer 1-5!" << endl;
				break;
		}
		count = 0;
	}
}

