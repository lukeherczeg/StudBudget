/*
 * user.cpp
 *
 *  Created on: Mar 29, 2018
 *      Author: Luke H
 */
#include <string>
#include <cstdlib>
#include <iostream>
//#include "Account.h"
#include "user.h"

using namespace std;

User::User(string username, string password){
	this->username = username;
	this->password = password;
}

string User::getUsername(){
	return this->username;
}

string User::getPassword(){
	return this->password;
}


