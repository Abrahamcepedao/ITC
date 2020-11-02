// Abraham Cepeda
// A00827666
// Class Passenger
#include <iostream>
#include <fstream>
#include "Flights.h"
using namespace std;

class Passenger{
    private:
        string pFlightId;
        int pKey;
        string pfName;
        string plName;
        string pSex;
        int pAge;
        string pUserName;
        string pPassword;
        Flight flight;
    public:
        Passenger();
        Passenger(string pdf, int pk, string pfn, string pln, char ps, int pa, string pun, string pp);
        
        string getpFlightId();
        int getpKey();
        string getName();
        string getpSex();
        int getpAge();
        string getpUserName();
        string getpPassword();

        void setpFlightId(string pdf);
        void setpKey(int pk);
        void setpfName(string pfn);
        void setplName(string pln);
        void setName(string pfn, string pln);
        void setpSex(string ps);
        void setpAge(int pa);
        void setpUserName(string pun);
        void setpPassword(string pp);
       
        void setFlight(Flight);
        void printFlight();

        void printPassenger();
        void changeData();
        void cancelFlight();
};

// constructors
Passenger::Passenger(){
    pFlightId = "--";
    pKey = 0;
    pfName = "SN";
    plName = "SN";
    pSex = 'A';
    pAge = 0;
    pUserName = "user";
    pPassword = "1234";
}
Passenger::Passenger(string pdf, int pk, string pfn, string pln, char ps, int pa, string pun, string pp){
    pFlightId = pdf;
    pKey = pk;
    pfName = pfn;
    plName = pln;
    pSex = ps;
    pAge = pa;
    pUserName = pun;
    pPassword = pp;
}

// get methods
string Passenger::getpFlightId(){
    return pFlightId;
}
int Passenger::getpKey(){
    return pKey;
}
string Passenger::getName(){
    return pfName + " " + plName;
}
string Passenger::getpSex(){
    return pSex;
}
int Passenger::getpAge(){
    return pAge;
}
string Passenger::getpUserName(){
    return pUserName;
}
string Passenger::getpPassword(){
    return pPassword;
}

// set methods
void Passenger::setpFlightId(string pdf){
    pFlightId = pdf;
}    
void Passenger::setpKey(int pk){
    pKey = pk;
}    
void Passenger::setpfName(string pfn){
    pfName = pfn;
}
void Passenger::setplName(string pln){
    plName = pln;
}
void Passenger::setName(string pfn,string pln){
    pfName = pfn;
    plName = pln;
}    
void Passenger::setpSex(string ps){
    pSex = ps;
}    
void Passenger::setpAge(int pa){
    pAge = pa;
}    
void Passenger::setpUserName(string pun){
    pUserName = pun;
}    
void Passenger::setpPassword(string pp){
    pPassword = pp;
}

// flight methods
void Passenger::setFlight(Flight iflight){
    flight = iflight;
}
void Passenger::printFlight(){
    flight.printFlight();
}



// print method
void Passenger::printPassenger(){
    cout << "Key:        " << pKey << endl;
    cout << "Username:   " << pUserName << endl;
    cout << "Password:   " << pPassword << endl;
    cout << "First name: " << pfName << endl;
    cout << "Last name:  " << plName << endl;
    cout << "Sex:        " << pSex << endl;
    cout << "Age:        " << pAge << endl;
    cout << "<----Flight details----->\n";
    flight.printFlight();
}

// change data
void Passenger::changeData(){
    Passenger passenger;
    int ans;
    cout << "\n\n<----Update passenger data----->\n";
    cout << "Select what do you want to change?\n";
    cout << "Enter 1 for Username\n";
    cout << "Enter 2 for Passowrd\n";
    cout << "Enter 3 for First name\n";
    cout << "Enter 4 for Lasta name\n";
    cout << "Enter 5 for Sex\n";
    cout << "Enter 6 for Age\n";
    cin >> ans;
    if(ans == 1){
        string username;
        cout << "Enter new username: ";
        cin >> username;
        pUserName = username;
    }
    else if(ans == 2){
        string password;
        cout << "Enter new username: ";
        cin >> password;
        pPassword = password;
    }
    else if(ans == 3){
        string fName;
        cout << "Enter new first name: ";
        cin >> fName;
        pfName = fName;
    }
    else if(ans == 4){
        string lName;
        cout << "Enter new last name: ";
        cin >> lName;
        plName = lName;
    }
    else if(ans == 5){
        string sex;
        cout << "Enter new sex: ";
        cin >> sex;
        pSex = sex;
    }
    else if(ans == 6){
        int age;
        cout << "Enter new age: ";
        cin >> age;
        pAge = age;
    } 
    else{
        cout << "Enter a valid number pleasee..\n";
    }
}
// cancel flight
void Passenger::cancelFlight(){
    pFlightId = "--";
}

