//
//  user.h
//  cop3503_termproject
//
//  Created by Madeline Farina on 3/23/18.
//  Copyright © 2018 Madeline Farina. All rights reserved.
//
using namespace std;
#include <string>

#ifndef user_h
#define user_h

class User {
    
private:
    string name;
    string username;
    string password;
    //Account account; //can't uncomment until Account class exists
    
public:
    User(string username, string password);
    void setName(string x);
    string getUsername();
    string getPassword();
    string getName();
    
};

#endif /* user_h */