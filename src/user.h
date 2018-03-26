//
//  user.h
//  cop3503_termproject
//
//  Created by Madeline Farina on 3/23/18.
//  Copyright © 2018 Madeline Farina. All rights reserved.
//

#ifndef user_h
#define user_h

#include <string>
#include <cstdlib>
#include <iostream>
//#include "Account.h"

using namespace std;

class User {
    
private:
    const string name;
    //Account account; //can't uncomment until Account class exists
    
public:
    void setName(string x);
    string getName();
    
};

#endif /* user_h */
