// Abraham Cepeda
// A00827666
// Class date
#include <iostream>
#include <fstream>
using namespace std;

class Admin{
    private:
        string user;
        string password;
    public:
        Admin();
        Admin(string u, string p);

        string getUser();
        string getPassword();

        void setUser(string u);
        void setPassword(string p);
};
// constructors
Admin::Admin(){
    user = "user";
    password = "1234";
}
Admin::Admin(string u, string p){
    user = u;
    password = p;
}

// get methods
string Admin::getUser(){
    return user;
}
 string Admin::getPassword(){
    return password;
}

// set methods
void Admin::setUser(string u){
    user = u;
}
void Admin::setPassword(string p){
    password = p;
}
