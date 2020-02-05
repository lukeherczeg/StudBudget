#ifndef USER_H
#define USER_H
#include <string>
using namespace std;
class Account; // forward declaration


class User
{
private:
    string name;
    string username;
    string password;
    Account * account;
public:
    User();
    User(string username, string password);
    void setName(string x);
    Account * getAccount();
    string getUsername();
    string getPassword();
    string getName();
};

#endif // USER_H
