/*
 * Authenticator.h
 *  Created on: Mar 26, 2018
 *      Author: Luke H
 */


#ifndef AUTHENTICATOR_H_
#define AUTHENTICATOR_H_

#include "user.h"
#include <map>
#include <string>

using namespace std;

class Authenticator{
private:
    map<int, User*>::iterator it; // Iterator to iterate through the hash map
    map<int, User*> users;
    User * currentUser;
public:
    Authenticator();
    User * getUser();
    void logIn(string username, string password, bool & finished);
    void signUp(string username, string password, bool & exists);
    void fillMapOfUsers();
    void clearUsers();
    bool isUser(string username);
};


#endif /* AUTHENTICATOR_H_ */
