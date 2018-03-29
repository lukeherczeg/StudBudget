/*
 * Authenticator.h
 *  Created on: Mar 26, 2018
 *      Author: Luke H
 */
#include "user.h"
#include <string>

#ifndef AUTHENTICATOR_H_
#define AUTHENTICATOR_H_

class Authenticator{
private:
	User user;
	string getUsername();
	string getPassword();
public:
	Authenticator(User user);
	void logIn(bool & finished);
	void signUp();
	void printUsers(); // temporary
	void authenticate();
};



#endif /* AUTHENTICATOR_H_ */
