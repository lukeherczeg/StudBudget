/*
 * Authenticator.h
 *  Created on: Mar 26, 2018
 *      Author: Luke H
 */
#include "user.h"
#include <map>

#ifndef AUTHENTICATOR_H_
#define AUTHENTICATOR_H_

class Authenticator{
private:
	map<int, User*>::iterator it; // Iterator to iterate through the hash map
	map<int, User*> users;
	User * currentUser;
public:
	Authenticator();
	void logIn(string username, string password, bool & finished);
	void signUp(string username, string password);
	void printUsers(); // temporary
	void printUserObjects(); // for testing
	void fillMapOfUsers();
	bool isUser(string username);
	User * getUser();
	void authenticate();
};



#endif /* AUTHENTICATOR_H_ */
