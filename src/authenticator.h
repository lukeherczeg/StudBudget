/*
 * Authenticator.h
 *  Created on: Mar 26, 2018
 *      Author: Luke H
 */

#ifndef AUTHENTICATOR_H_
#define AUTHENTICATOR_H_

class Authenticator{
	string username;
	string password;
	void getUser(string);
public:
	void logIn(User);
	void signUp(User);
	void setUsername(string username);
	string getUsername(User user);
	void setPassword(string password);
	string getPassword(User user);

};



#endif /* AUTHENTICATOR_H_ */
