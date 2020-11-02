// Abraham Cepeda
// A00827666
// Class date
#include <iostream>
#include <fstream>
using namespace std;

string crew[5] = {"Pilot", "Co_pilot", "Attendant1", "Attendant2", "Attendant3"};

class Crew{
    private:
        string pilot;
        string co_pilot;
        string attendant1;
        string attendant2;
        string attendant3;
    public:
        Crew();
        Crew(string pi, string copi, string a1, string a2, string a3);
        
        string getPilot();
        string getCoPilot();
        string getAttendant1();
        string getAttendant2();
        string getAttendant3();

        void setCrew();
        void changeCrew();

        void setPilot(string pi);
        void setCoPilot(string copi);
        void setAttendant1(string a1);
        void setAttendant2(string a2);
        void setAttendant3(string a3);
        void printCrew();
};

//constructors
Crew::Crew(){
    pilot = "--";
    co_pilot = "--";
    attendant1 = "--";
    attendant2 = "--";
    attendant3 = "--";
}
Crew::Crew(string pi, string copi, string a1, string a2, string a3){
    pilot = pi;
    co_pilot = copi;
    attendant1 = a1;
    attendant2 = a2;
    attendant3 = a3;
}

// get methods
string Crew::getPilot(){
    return pilot;
}
string Crew::getCoPilot(){
    return co_pilot;
}
string Crew::getAttendant1(){
    return attendant1;
}
string Crew::getAttendant2(){
    return attendant2;
}
string Crew::getAttendant3(){
    return attendant3;
}

// set methods
void Crew::setCrew(){
    string crewData[5];
    string fName;
    string lName;
    for(int i = 0; i < 5; i++){
        cout << "\nEnter the " << crew[i] << " data\n";
        cout << "First name: ";
        cin >> fName;
        cout << "Last name: ";
        cin >> lName;
        crewData[i] = fName + "_" + lName;
    }
    Crew newCrew;
    pilot = crewData[0];
    co_pilot = crewData[1];
    attendant1 = crewData[2];
    attendant2 = crewData[3];
    attendant3 = crewData[4];
}

// set methods
void Crew::setPilot(string pi){
    pilot = pi;
}
void Crew::setCoPilot(string copi){
    co_pilot = copi;
}
void Crew::setAttendant1(string a1){
    attendant1 = a1;
}
void Crew::setAttendant2(string a2){
    attendant2 = a2;
}
void Crew::setAttendant3(string a3){
    attendant3 = a3;
}

// print crew
void Crew::printCrew(){
    cout << "\nPilot:      " << pilot << "\n";
    cout << "Co-pilot:   " << co_pilot << "\n";
    cout << "Attendant1: " << attendant1 << "\n";
    cout << "Attendant2: " << attendant2 << "\n";
    cout << "Attendant3: " << attendant3 << "\n";
}