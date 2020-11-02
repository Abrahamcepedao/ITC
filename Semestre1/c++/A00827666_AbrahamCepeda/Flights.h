// Abraham Cepeda
// A00827666
// Class date
#include "Date.h"
#include "Crew.h"

class Flight{
    private: 
        string flightId;
        string airline;
        int flightNum;
        string origin;
        string destiny;
        int timeFlight;
        int capacity;
        int occupied;
        Crew crew;
        Date date;
    public:
        Flight();
        Flight(string fID, string al, int fNum, string ori, string des, int tF, int cap, int occ);
        string getFlightId();
        string getFlightAirline();
        int getFlightNum();
        string getOrigin();
        string getDestiny();
        int getTimeFlight();
        int getCapacity();
        int getOccupied();
        int getAvailability();
        
        void printFlight();
        void printDate();
        void printCrew();

        void setFlightId(string fID);
        void setFlightAirline(string al);
        void setFlightNum(int fNum);
        void setOrigin(string ori);
        void setDestiny(string des);
        void setTimeFlight(int tF);
        void setCapacity(int cap);
        void setOccupied(int occ);

        void setDate2();
        void setDate(Date);
        void setCrew2();
        void setCrew(Crew);

        void changeFlight();
};

//constructors
Flight::Flight(){
    flightId = "--";
    airline = "--";
    flightNum = 0;
    origin = "--";
    destiny = "--";
    timeFlight = 0;
    capacity = 0;
    occupied = 0;
}
Flight::Flight(string fID, string al, int fNum, string ori, string des, int tF, int cap, int occ){
    flightId = fID;
    airline = al;
    flightNum = fNum;
    origin = ori;
    destiny = des;
    timeFlight = tF;
    capacity = cap;
    occupied = occ;
}

// get methods
string Flight::getFlightId(){
    return flightId;
}
string Flight::getFlightAirline(){
    return airline;
}
int Flight::getFlightNum(){
    return flightNum;
}
string Flight::getOrigin(){
    return origin;
}
string Flight::getDestiny(){
    return destiny;
}
int Flight::getTimeFlight(){
    return timeFlight;
}
int Flight::getCapacity(){
    return capacity;
}
int Flight::getOccupied(){
    return occupied;
}
int Flight::getAvailability(){
    return capacity - occupied;
}

// print methods
void Flight::printFlight(){
    cout << "Flight ID: " << flightId << endl;
    cout << "Flight airline: " << airline << endl;
    cout << "Flight number: " << flightNum << endl;
    cout << "Flight origin: " << origin << endl;
    cout << "Flight destiny: " << destiny << endl;
    cout << "Flight duration: " << timeFlight << endl;
    cout << "Flight capacity: " << capacity << endl;
    cout << "Flight availability: " << getAvailability() << endl;
    cout << "<----Crew---->" << endl;
    crew.printCrew();
    cout << "<----Date---->" << endl;
    date.printDate();
}
void Flight::printDate(){
    return date.printDate();
}
void Flight::printCrew(){
    return crew.printCrew();
}

//set methods
void Flight::setFlightId(string fID){
    flightId = fID;
} 
void Flight::setFlightAirline(string al){
    airline = al;
}
void Flight::setFlightNum(int fNum){
    flightNum = fNum;
}
void Flight::setOrigin(string ori){
    origin = ori;
}
void Flight::setDestiny(string des){
    destiny = des;
}
void Flight::setTimeFlight(int tF){
    timeFlight = tF;
}
void Flight::setCapacity(int cap){
    capacity = cap;
}
void Flight::setOccupied(int occ){
    occupied = occ;
}

// set methods (objects)
void Flight::setDate2(){
    date.setDate();
}
void Flight::setDate(Date idate){
    date = idate;
}
void Flight::setCrew2(){
    crew.setCrew();
}
void Flight::setCrew(Crew icrew){
    crew = icrew;
}

// other methods
void Flight::changeFlight(){
    int ans;
    cout << "<-------Welcome Admin------->\n\n";
    cout << "Select an option to change...\n";
    cout << "Enter 1 to time fligth\n";
    cout << "Enter 2 to capacity\n";
    cout << "Enter 3 to date\n";
    cout << "Enter 4 to crew\n";
    cin >> ans;
    if(ans == 1){
        int tf;
        cout << "New timeflight: ";
        cin >> tf;
        while(tf < 1 || tf > 12){
            cout << "Enter valid time flight (1-12)\n";
            cin >> tf;
            timeFlight = tf;
        }
    }
    else if(ans == 2){
        int cap;
        cout << "New cappacity: ";
        cin >> cap;
        while(cap < occupied){
            cout << "Enter more than " << occupied << endl;
            cin >> cap;
            capacity = cap;
        }
    }
    else if(ans == 3){
        date.setDate();
    }
    else if(ans == 4){
        crew.setCrew();
    } else{
        cout << "Enter a valid number pleasee..\n";
    }
}
