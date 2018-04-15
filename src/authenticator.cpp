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
using namespace std;
#include "authenticator.h"
#include "user.h"


/*string Authenticator::getPassword(int i){
	return this->users[i]->first.getPassword();
}

string Authenticator::getUsername(int i){
	return this->users[i].getUsername();
}
*/
int characterCountUntilSpace(std::string word) // This is done, functions well.
{
    int count = 0;
    for(unsigned int i = 0; i < word.size(); i++) {
        if (isspace(word[i]))
            break;
    	count++;
    }
    return count;
}

User Authenticator::logIn(string username, string password, bool & finished){
	string tempUser;
	string auth = "Username: " + username + "    Password: " + password;

	bool login = false;
	ifstream readData;

	readData.open("authData.txt");
	this->it = this->users.begin();
	User currentUser = this->it->first;

	while(getline(readData, tempUser)){
		currentUser = this->it->first;
		if(tempUser == auth){
			login = true;
			break;
		}
		this->it++;
	}
	if(login){
		cout << "You're in! :)" << endl;
		finished = true;
		return currentUser;
	}
	else
		cout << "Didn't find your username or password. Please sign up." << endl;
	readData.close();
}

void Authenticator::signUp(string username, string password){
	ifstream readData;
	bool exists = false;
	string tempUser, tempUsername, tempPassword;
	int passwordStart, tempPasswordLength, tempUsernameLength;
	int usernameStart = 10;

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
		User newUser(username, password);
		this->users[newUser]++;
		string auth = "Username: " + username + "    Password: " + password;
		//			  Length 10	^			      Length 14 ^
		ofstream writeData;
		writeData.open ("authData.txt", ios_base::app);
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
	if(count == 0)
		cout << "No users found." << endl;
	readData.close();
}

User Authenticator::authenticate(){
	string username = "";
	string password = "";
	int choice = 0;
	int count = 0;
	string choice2 = "";
	bool finished = false;

	cout << "\nWelcome to the Budgeting app. Sign up below! \nIf you have an account already, please enter your username and password.\n" << endl;
	cout << "\t1. Log in\n\t2. Sign up\n\t3. Print users\n\t4. Clear all users\n\t5. Exit" << endl;

	while(!finished) {
		while (true){
			cin >> choice;
			if(cin.fail()){
				cin.clear(); //This corrects the stream.
				cin.ignore(); //This skips the left over stream data.
				if(count == 0)
					cout << "Please enter an Integer only." << endl;
				count++;
			}
			else{
				break;
			}
		}

		switch(choice){
			case 1:
				cout << "Username : "; cin >> username;
				cout << "Password : "; cin >> password;

				return this->logIn(username, password, finished);
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
				if(choice2 == "y")
					remove("authData.txt");
				else
					break;
				cin.clear();
				break;
			case 5:
				finished = true;
				break;
			default:
				cout << "WRONG." << endl;
				break;
		}
		count = 0;
	}
}


