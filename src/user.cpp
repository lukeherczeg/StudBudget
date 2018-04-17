/*
 * user.cpp
 *
 *  Created on: Mar 29, 2018
 *      Author: Luke H
 */
#include <cstdlib>
#include <iostream>
#include "user.h"
#include "account.h"

User::User(string username, string password){
	this->username = username;
	this->password = password;
	this->account = new Account();
}

Account * User::getAccount(){
	return this->account;
}

string User::getUsername(){
	return this->username;
}

string User::getPassword(){
	return this->password;
}
