/*
 * Authenticator.h
 *  Created on: Mar 26, 2018
 *      Author: Luke H
 */
#include "user.h"
#include <string>
#include <vector>

#ifndef AUTHENTICATOR_H_
#define AUTHENTICATOR_H_

class Authenticator{
private:
	std::map<User, int>::iterator it;
	std::map<User, int> users;
	//std::vector<User> users;
	//string getUsername(int i);
	//string getPassword(int i);
public:
	Authenticator();
	User logIn(string username, string password, bool & finished);
	void signUp(string username, string password);
	void printUsers(); // temporary
	void authenticate();
};



#endif /* AUTHENTICATOR_H_ */
