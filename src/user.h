//
//  user.h
//  cop3503_termproject
//
//  Created by Madeline Farina on 3/23/18.
//  Copyright © 2018 Madeline Farina. All rights reserved.
//

#ifndef user_h
#define user_h

class User {
    
private:
    const string name;
    const string username;
    const string password;
    //Account account; //can't uncomment until Account class exists
    
public:
    User(string username, string password);
    void setName(string x);
    string getName();
    
};

#endif /* user_h */
