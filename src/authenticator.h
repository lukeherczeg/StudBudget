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
	map<User*, int>::iterator it;
	map<User*, int> users;
	User * currentUser;
public:
	void logIn(string username, string password, bool & finished);
	void signUp(string username, string password);
	void printUsers(); // temporary
	void printUserObjects(); // for testing
	void fillMapOfUsers();
	User * getUser();
	void authenticate();
};



#endif /* AUTHENTICATOR_H_ */
