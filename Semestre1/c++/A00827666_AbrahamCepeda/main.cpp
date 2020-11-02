// Proyecto - Aeropuerto internacional de la ciudad de Mexico
// Abraham Cepeda Oseguera
// A00827666

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstring>
#include <stdlib.h> /* srand, rand */
#include <time.h>   /* time */
#include <limits>
#include "Passenger.h"
#include "Admin.h"

using namespace std;

// vectors
vector<Flight> vectorFlights;
vector<Passenger> vectorPassengers;
vector<Admin> vectorAdmins;

//<--------------------------Coding begins-------------------------->

//<---------Create data----------->
void createData(int n){
    string maleFirstName[40] = {
        "Abraham",
        "Axel",
        "Juan",
        "Carlos",
        "Rafael",
        "Gabriel",
        "Alfredo",
        "Manuel",
        "Emilio",
        "Jose",
        "Alejandro",
        "Alec",
        "Brian",
        "Hernan",
        "Guillermo",
        "Pable",
        "Eduardo",
        "Santiago",
        "Daniel",
        "Andres",
        "James",
        "Joaquin",
        "Antonio",
        "Omar",
        "John",
        "Robert",
        "Michael",
        "Logan",
        "Diego",
        "Oliver",
        "Jacob",
        "Fabian",
        "David",
        "William",
        "Charles",
        "Joseph",
        "Thomas",
        "Mateo",
        "Matias",
        "Sebastian"
    };

    string lastNames[80] = {
        "Cepeda",
        "Oseguera",
        "Mercado",
        "Gasque",
        "Garfias",
        "Bricston",
        "Bolio",
        "Prieto",
        "Gutierrez",
        "Castillo",
        "Olivares",
        "Fernandez",
        "Herrera",
        "Pizarro",
        "Braniff",
        "Caamal",
        "Camara",
        "Diaz",
        "Canto",
        "Carriedo",
        "Castellanos",
        "Bernes",
        "Chang",
        "Macias",
        "Thomassiny",
        "Lascurain",
        "Gallegos",
        "Cruz",
        "Almada",
        "Benites",
        "Degetau",
        "Gomez",
        "Dominguez",
        "Solis",
        "Guzman",
        "Gamboa",
        "Martinez",
        "Escobar",
        "Villareal",
        "Fuentes",
        "Smith",
        "Johnson",
        "Spieth",
        "Williams",
        "Brown",
        "Jones",
        "Garcia",
        "Miller",
        "Davis",
        "Rodriguez",
        "Hernandez",
        "Lopez",
        "Wilson",
        "Anderson",
        "Thomas",
        "Taylor",
        "Moore",
        "Jackson",
        "Martin",
        "Lee",
        "Perez",
        "Thompson",
        "White",
        "Harris",
        "Sanchez",
        "Clark",
        "Kent",
        "Ramirez",
        "Lewis",
        "Specter",
        "Robinson",
        "Walker",
        "Young",
        "Allen",
        "King",
        "Wright",
        "Scott",
        "Torres",
        "Hill",
        "Adamas"
    };

    string femaleFirstName[40] = {
        "Abril",
        "Alexa",
        "Ana",
        "Sofia",
        "Felicia",
        "Camila",
        "Regina",
        "Adriana",
        "Aileth",
        "Alejandra",
        "Marian",
        "Mariana",
        "Jimena",
        "Rocio",
        "Erika",
        "Julia",
        "Isabela",
        "Desiree",
        "Andrea",
        "Shakti",
        "Maria",
        "Lucia",
        "Catalina",
        "Elena",
        "Cecilia",
        "Miranda",
        "Valentina",
        "Emilia",
        "Paula",
        "Zoe",
        "Ava",
        "Chloe",
        "Sara",
        "Mia",
        "Abigail",
        "Micaela",
        "Margaret",
        "Susan",
        "Antonella",
        "Liz"
    };

    string mexicoCities[38] = {
        "ACA-M",
        "AGU-M",
        "HUX-M",
        "CUN-M",
        "CPE-M",
        "CUU-M",
        "CTM-M",
        "CME-M",
        "CJS-M",
        "CVM-M",
        "CEN-M",
        "CLQ-M",
        "CZM-M",
        "CUL-M",
        "DGO-M",
        "BJX-M",
        "GUB-M",
        "GYM-M",
        "HMO-M",
        "JAL-M",
        "LAP-M",
        "LZC-M",
        "SJD-M",
        "LMM-M",
        "LTO-M",
        "ZLO-M",
        "MAM-M",
        "MZT-M",
        "MID-M",
        "MXL-M",
        "MEX-M",
        "MTT-M",
        "MTY-M",
        "LOV-M",
        "MLM-M",
        "NLD-M",
        "OAX-M",
        "PDS-M"
    };

    string usCities[50] = {
        "AL-US",
        "AK-US",
        "AZ-US",
        "AR-US",
        "CA-US",
        "CO-US",
        "CT-US",
        "DE-US",
        "FL-US",
        "GA-US",
        "HI-US",
        "ID-US",
        "IL-US",
        "IN-US",
        "IA-US",
        "KS-US",
        "KY-US",
        "LA-US",
        "ME-US",
        "MD-US",
        "MA-US",
        "MI-US",
        "MN-US",
        "MS-US",
        "MO-US",
        "MT-US",
        "NE-US",
        "NV-US",
        "NH-US",
        "NJ-US",
        "NM-US",
        "NY-US",
        "NC-US",
        "ND-US",
        "OH-US",
        "OK-US",
        "OR-US",
        "PA-US",
        "RI-US",
        "SC-US",
        "SD-US",
        "TN-US",
        "TX-US",
        "UT-US",
        "VT-US",
        "VA-US",
        "WA-US",
        "WV-US",
        "WI-US",
        "WY-US"
    };

    string airlines[6] = {
        "Mexicana",
        "Aeromexico",
        "Interjet",
        "VivaAerobus",
        "Volaris",
        "AmericanAirlines"
    };
    int planeCappacity[5] = {
        80,
        90,
        100,
        150,
        300
    };

    ofstream flights;
    flights.open("Flights.txt");

    ofstream passengers;
    passengers.open("Passengers.txt");
    
    ofstream crew;
    crew.open("Crew.txt");
    
    ofstream dates;
    dates.open("Dates.txt");

    ofstream admin;
    admin.open("Admins.txt");
    
    int flightNumber = 1000;
    int countPassengers = 1;
    string flightId;
    
    int year = 2019;
    int month = 12;
    int day = 1;
    int hour = 7;
    int minute = 0;
    int arrayDiasMes[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    string flightIdArray[n];

    for (int i = 0; i < n; i++){
        int randIntId = rand() % 900 + 100;
        int randIntId2 = rand() % 10;
        int randAirline = rand() % 6;
        int randTimeFlight = rand() % 5 + 2;
        int randPlaneCappacity = rand() % 5;
        if(flightNumber % 4 == 0){
            int randOriginMx = rand() % 38;
            int randDestinynMx = rand() % 38;
            flightId = to_string(randIntId) + "-" + mexicoCities[randOriginMx] + "-" + airlines[randAirline].at(0) + "-" + to_string(randIntId2);
            flights << flightId << setw(20) << airlines[randAirline] << setw(20) << flightNumber << setw(15) << mexicoCities[randOriginMx] << setw(15) << mexicoCities[randDestinynMx] << setw(15) << randTimeFlight << setw(15) << planeCappacity[randPlaneCappacity] << endl;
        } 
        else if (flightNumber % 4 == 1){
            int randOriginUs = rand() % 50;
            int randDestinynUs = rand() % 50;
            flightId = to_string(randIntId) + "-" + usCities[randOriginUs] + "-" + airlines[randAirline].at(0) + "-" + to_string(randIntId2);
            flights << flightId << setw(20) << airlines[randAirline] << setw(20) << flightNumber << setw(15) << usCities[randOriginUs] << setw(15) << usCities[randDestinynUs] << setw(15) << randTimeFlight << setw(15) << planeCappacity[randPlaneCappacity] << endl;
        } 
        else if (flightNumber % 4 == 2){
            int randOriginMx = rand() % 38;
            int randDestinynUs = rand() % 50;
            flightId = to_string(randIntId) + "-" + mexicoCities[randOriginMx] + "-" + airlines[randAirline].at(0) + "-" + to_string(randIntId2);
            flights << flightId << setw(20) << airlines[randAirline] << setw(20) << flightNumber << setw(15) << mexicoCities[randOriginMx] << setw(15) << usCities[randDestinynUs] << setw(15) << randTimeFlight << setw(15) << planeCappacity[randPlaneCappacity] << endl;
        } 
        else if (flightNumber % 4 == 3){
            int randOriginUs = rand() % 50;
            int randDestinynMx = rand() % 38;
            flightId = to_string(randIntId) + "-" + usCities[randOriginUs] + "-" + airlines[randAirline].at(0) + "-" + to_string(randIntId2);
            flights << flightId << setw(20) << airlines[randAirline] << setw(20) << flightNumber << setw(15) << usCities[randOriginUs] << setw(15) << mexicoCities[randDestinynMx] << setw(15) << randTimeFlight << setw(15) << planeCappacity[randPlaneCappacity] << endl;
        }
        
        for (int i = 0; i < planeCappacity[randPlaneCappacity] - 2; i++){
            int randMaleName = rand() % 40;
            int randFemaleName = rand() % 40;
            int randLastName = rand() % 80;
            int passengerAge = rand() % 90 + 10;
            string passengerSex;
            if (countPassengers % 2 == 1){
                passengerSex = "M";
                passengers << flightId << setw(20) << countPassengers << setw(15) << maleFirstName[randMaleName] << setw(15) << lastNames[randLastName] << setw(15) << passengerSex << setw(15) << passengerAge << endl;
            }
            else{
                passengerSex = "F";
                passengers << flightId << setw(20) << countPassengers << setw(15) << femaleFirstName[randFemaleName] << setw(15) << lastNames[randLastName] << setw(15) << passengerSex << setw(15) << passengerAge << endl;
            }
            countPassengers++;
        }
       
        string crewName;
        //crew << flightId << setw(25);
       
        for(int i = 0; i < 5; i++){
            int randFirstName = rand() % 40;
            int randLastName = rand() % 40;
            if(i <= 1){
                crewName = maleFirstName[randFirstName] + "_" + lastNames[randLastName];
                crew << crewName << setw(30);
            } else{
                crewName = femaleFirstName[randFirstName] + "_" + lastNames[randLastName];
                crew << crewName << setw(30);
            }
        }
       
        crew << endl << setw(0);
        flightIdArray[i] = flightId;
        flightNumber++;
    }
    // create date data
    for (int i = 0; i < n; i++){
        dates << year << setw(15) << month << setw(15) << day << setw(15) << hour << setw(15) << minute << endl;
        minute = minute + 30;
        if(minute == 60){
            minute = 0;
            hour++;
        }
        if(hour == 22 && minute == 30){
            hour = 7;
            minute = 0;
            day++;
        }
        if(arrayDiasMes[month - 1] < day){
            day = 1;
            if(month == 12){
                month = 1;
                year++;
            } else{
                month++;
            }
        }
    }
    // create admin data
    for(int i = 0; i < 5; i++){
        int randFirstName = rand() % 40;
        int randLastName = rand() % 40;
        int randSex = rand() % 2;
        int randPassword = rand() % 900 + 100;
        if(randSex == 0){
            string user = maleFirstName[randFirstName] + "_" + lastNames[randLastName];
            string password = maleFirstName[randFirstName] + to_string(randPassword);
            admin << user << setw(30) << password << setw(30);
        } else{
            string user = femaleFirstName[randFirstName] + "_" + lastNames[randLastName];
            string password = femaleFirstName[randFirstName] + to_string(randPassword);
            admin << user << setw(30) << password << setw(30);
        }
        admin << endl << setw(0); 
    }
}

//<---------Create objects----------->
void createObjects(){
    // create vector for flights
    int count = 0;
    string text;
    Flight newFlight;
    ifstream flightsFile;
    flightsFile.open("Flights.txt");
    while (getline(flightsFile, text)){
        istringstream ss(text);
        while(ss){
            string word;
            ss >> word;
            if(count == 0){
                newFlight.setFlightId(word);
            }
            else if (count == 1){
                newFlight.setFlightAirline(word);
            }
            else if(count == 2){
                newFlight.setFlightNum(stoi(word));
            }
            else if(count == 3){
                newFlight.setOrigin(word);
            }
            else if(count == 4){
                newFlight.setDestiny(word);
            }
            else if(count == 5){
                newFlight.setTimeFlight(stoi(word));
            }
            else if(count == 6){
                newFlight.setCapacity(stoi(word));
                newFlight.setOccupied(newFlight.getCapacity() - 2);
            }
            count++;
        }
        count = 0;
        vectorFlights.push_back(newFlight);
    }
    flightsFile.close();

    // add object date to flights vector
    count = 0;
    int count2 = 0;
    string text2;
    Date newDate;
    ifstream dateFile;
    dateFile.open("Dates.txt");
    while (getline(dateFile, text2)){
        istringstream ss(text2);
        while(ss){
            string word;
            ss >> word;
            if(count == 0){
                newDate.setYear(stoi(word));
            }
            else if(count == 1){
                newDate.setMonth(stoi(word));
            }
            else if(count == 2){
                newDate.setDay(stoi(word));
            }
            else if(count == 3){
                newDate.setHour(stoi(word));
            }
            else if(count == 4){
                newDate.setMinute(stoi(word));
            }
            count++;
        }
        vectorFlights[count2].setDate(newDate);
        count = 0;
        count2++;
    }
    dateFile.close();

    // add object date to flights vector
    count = 0;
    count2 = 0;
    string text3;
    Crew newCrew;
    ifstream crewFile;
    crewFile.open("Crew.txt");
    while (getline(crewFile, text3)){
        istringstream ss(text3);
        while(ss){
            string word;
            ss >> word;
            if(count == 0){
                newCrew.setPilot(word);
            }
            else if(count == 1){
                newCrew.setCoPilot(word);
            }
            else if(count == 2){
                newCrew.setAttendant1(word);
            }
            else if(count == 3){
                newCrew.setAttendant2(word);
            }
            else if(count == 4){
                newCrew.setAttendant3(word);
            }
            count++;
        }
        vectorFlights[count2].setCrew(newCrew);
        count = 0;
        count2++;
    }
    crewFile.close();


    // create passengers vector
    count = 0;
    string text4;
    Passenger newPassenger;
    ifstream passengerFile;
    passengerFile.open("Passengers.txt");
    while (getline(passengerFile, text4)){
        istringstream ss(text4);
        while(ss){
            string word;
            ss >> word;
            if(count == 0){
                newPassenger.setpFlightId(word);
            }
            else if(count == 1){
                newPassenger.setpKey(stoi(word));
            }
            else if(count == 2){
                newPassenger.setpfName(word);
            }
            else if(count == 3){
                newPassenger.setplName(word);
            }
            else if(count == 4){
                newPassenger.setpSex(word);
            }
            else if(count == 5){
                newPassenger.setpAge(stoi(word));
            }
            count++;
        }
        vectorPassengers.push_back(newPassenger);
        count = 0;
    }
    crewFile.close();
    count = 0;
    for(int x = 0; x < vectorFlights.size(); x++){
        int size = vectorFlights[x].getOccupied();
        for(int i = 0; i < size; i++){
            vectorPassengers[0].setFlight(vectorFlights[x]);
        }
    }

    // Create admin objects
    count = 0;
    string text5;
    Admin newAdmin;
    ifstream adminFile;
    adminFile.open("Admins.txt");
    while (getline(adminFile, text5)){
        istringstream ss(text5);
        while(ss){
            string word;
            ss >> word;
            if(count == 0){
                newAdmin.setUser(word);
            }
            else if(count == 1){
                newAdmin.setPassword(word);
            }
            count++;
        }
        vectorAdmins.push_back(newAdmin);
        count = 0;
    }
    adminFile.close();
}


//<-------------Print main menu--------------->
int printMainMenu(){
    int ans;
    cout << "\n\n\nAre you a flight admin or a user?\n\n\n";
    cout << "Enter 1 for flight admin\n";
    cout << "Enter 2 for user\n";
    cout << "Enter 0 for termination\n";
    cin >> ans;
    return ans;
}

//<--------------------------Admin login-------------------------->
//<-------------Check admin login--------------->
Admin checkAdminLogin(string u, string p){
    // check if username exists
    bool uExists = false;
    int uNum;
    for(int i = 0; i < vectorAdmins.size(); i++){
        if(u == vectorAdmins[i].getUser()){
            uExists = true;
            uNum = i;
        }
    }
    // do if user does not exist
    cout << "Bool: " << uExists << endl;
    if(!uExists){
        cout << "User name does not exists... please enter a valid one or create one\n";
        cout << "Enter your username: ";
        cin >> u;
        cout << "Enter your password: ";
        cin >> p;
        checkAdminLogin(u, p);
    }
    // check if password is correct
    while (p != vectorAdmins[uNum].getPassword()){
        cout << "Enter a valid password please \n";
        cin >> p;
    }
    return vectorAdmins[uNum];
}
//<-------------Admin login--------------->
Admin adminLogin(){
    string userName;
    string password;
    cout << "\n<------Welcome to login (Admin)------>\n";
    cout << "Enter your username: ";
    cin >> userName;
    cout << "Enter your password: ";
    cin >> password;
    Admin adminUser = checkAdminLogin(userName, password);
    return adminUser;
}
// create admin user
Admin createAdminUser(){
    string fName;
    string lName;
    string password;
    Admin newAdmin;
    cout << "\n<------Welcome to create admin user------>\n";
    cout << "Enter your first name: ";
    cin >> fName;
    cout << "Enter your last name: ";
    cin >> lName;
    cout << "Enter your password: ";
    cin >> password;
    newAdmin.setUser(fName + "_" + lName);
    newAdmin.setPassword(password);
    vectorAdmins.push_back(newAdmin);
    return newAdmin;
}

//<--------------------------Passenger login-------------------------->
Passenger checkPassengerLogin(string u, string p){
    // check if username exists
    bool uExists = false;
    int uNum;
    for(int i = 0; i < vectorPassengers.size(); i++){
        if (u == vectorPassengers[i].getpUserName()){
            uExists = true;
            uNum = i;
        }
    }
    // do if user does not exist
    cout << "Bool: " << uExists << endl;
    if(!uExists){
        cout << "User name does not exists... please enter a valid one or create one\n";
        cout << "Enter your username: ";
        cin >> u;
        cout << "Enter your password: ";
        cin >> p;
        checkAdminLogin(u, p);
    }
    // check if password is correct
    while (p != vectorPassengers[uNum].getpPassword()){
        cout << "Enter a valid password please \n";
        cin >> p;
    }
    return vectorPassengers[uNum];
}
//<-------------Admin login--------------->
Passenger passengerLogin(){
    string userName;
    string password;
    cout << "\n<------Welcome to login (Admin)------>\n";
    cout << "Enter your username: ";
    cin >> userName;
    cout << "Enter your password: ";
    cin >> password;
    Passenger passengerUser = checkPassengerLogin(userName, password);
    return passengerUser;
}
// create passenger user
Passenger createPassengerUser(){
    int pKey = (vectorPassengers[vectorPassengers.size()-1].getpKey()) + 1;
    string fName;
    string lName;
    string password;
    string sex;
    int age;
    Passenger newPassenger;
    cout << "\n<------Welcome to create passenger user------>\n";
    cout << "Enter your first name: ";
    cin >> fName;
    cout << "Enter your last name: ";
    cin >> lName;
    cout << "Enter your password: ";
    cin >> password;
    cout << "Enter your sex (F/M): ";
    cin >> sex;
    while(sex != "F" && sex != "M"){
        cout << "Enter valid sex (F/M): ";
        cin >> sex;
    }
    cout << "Enter your age: ";
    cin >> age;
    while(age < 1 || age > 130){
        cout << "Enter valid age: ";
        cin >> age;
    }
    newPassenger.setpKey(pKey);
    newPassenger.setpfName(fName);
    newPassenger.setplName(lName);
    newPassenger.setpSex(sex);
    newPassenger.setpAge(age);
    newPassenger.setpUserName(fName + "_" + lName);
    newPassenger.setpPassword(password);
    vectorPassengers.push_back(newPassenger);
    return newPassenger;
}

//<--------------------------Flight search-------------------------->
//<-------------Search flights by ID--------------->
Flight searchById(){
    string flightId;
    cout << "Enter flight ID: ";
    cin >> flightId;
    bool continuee = true;
    int count = 0;
    int fNum;
    while(continuee && count < vectorFlights.size()-1){
        if(flightId == vectorFlights[count].getFlightId()){
            continuee = false;
            fNum = count;
        }
        count++;
    }
    if(continuee){
        cout << "It appears the ID does not exist, please enter a valid one\n";
        searchById();
    }
    return vectorFlights[fNum];
}
//<-------------Search flights by origin--------------->
void searchByOrigin(){
    int ans;
    int count = 1;
    bool originExists = false;
    string origin;
    string id;
    cout << "<---searching by origin--->\n";
    cout << "Enter 1 for Mexico\n";
    cout << "Enter 2 for Us\n";
    cin >> ans;
    if(ans == 1){
        cout << "Enter origin (MTY): ";
        cin >> origin;
        origin += "-M";
        for(int i = 0; i < vectorFlights.size(); i++){
            if(origin == vectorFlights[i].getOrigin()){
                cout << "<----------------Flight " << count << "---------------->\n";
                vectorFlights[i].printFlight();
                count++;
                originExists = true;
            }
        }
    }
    else if(ans == 2){
        cout << "Enter origin (TX): ";
        cin >> origin;
        origin += "-US";
        for(int i = 0; i < vectorFlights.size(); i++){
            if(origin == vectorFlights[i].getOrigin()){
                cout << "<----------------Flight " << count << "---------------->\n";
                vectorFlights[i].printFlight();
                count++;
                originExists = true;
            }
        }
    } 
    else{
        cout << "Enter a valid number please..\n";
        searchByOrigin();
    }
    if(!originExists){
        cout << "There is no flight with such origin... enter another one\n";
        searchByOrigin();
    }
}
//<-------------Search flights by destiny--------------->
void searchByDestiny(){
    int ans;
    int count = 1;
    bool destinyExists = false;
    string destiny;
    string id;
    cout << "<---Searching by destiny--->\n";
    cout << "Enter 1 for Mexico\n";
    cout << "Enter 2 for Us\n";
    cin >> ans;
    if(ans == 1){
        cout << "Enter destiny (MTY): ";
        cin >> destiny;
        destiny += "-M";
        for(int i = 0; i < vectorFlights.size(); i++){
            if (destiny == vectorFlights[i].getDestiny()){
                cout << "<----------------Flight " << count << "---------------->\n";
                vectorFlights[i].printFlight();
                count++;
                destinyExists = true;
            }
        }
    }
    else if(ans == 2){
        cout << "Enter destiny (TX): ";
        cin >> destiny;
        destiny += "-US";
        for(int i = 0; i < vectorFlights.size(); i++){
            if(destiny == vectorFlights[i].getDestiny()){
                cout << "<----------------Flight " << count << "---------------->\n";
                vectorFlights[i].printFlight();
                count++;
                destinyExists = true;
            }
        }
    } 
    else{
        cout << "Enter a valid number please..\n";
        searchByDestiny();
    }
    if (!destinyExists){
        cout << "There is no flight with such destiny... enter another one\n";
        searchByDestiny();
    }
}
//<-------------Search flights by airline--------------->
void searchByAirline(){
    int ans;
    int count = 1;
    bool airlineExist = false;
    string airline;
    string id;
    cout << "<---Searching by airline--->\n";
    cout << "Airline: ";
    cin >> airline;
    for(int i = 0; i < vectorFlights.size(); i++){
        if (airline == vectorFlights[i].getFlightAirline()){
            cout << "<----------------Flight " << count << "---------------->\n";
            vectorFlights[i].printFlight();
            count++;
            airlineExist = true;
        }
    }
    if(!airlineExist){
        cout << "There is no such airline... enter another one\n";
        searchByAirline();
    }
}
//<-------------Search flights--------------->
void searchFlights(){
    int ans;
    cout << "<-------Welcome to search flights engine------->\n\n";
    cout << "Select an option...\n";
    cout << "Enter 1 for ID\n";
    cout << "Enter 2 for origin\n";
    cout << "Enter 3 for destiny\n";
    cout << "Enter 4 for airline\n";
    cin >> ans;
    Flight flight;
    switch(ans){
        case 1:
            flight = searchById();
            break;
        case 2:
            searchByOrigin();
            break;
        case 3:
            searchByDestiny();
            break;
        case 4:
            searchByAirline();
            break;
        default:
            cout << "Enter a valid number please...\n";
            searchFlights();
            break;
    }
}

//<--------------------------Admin functions-------------------------->
//<-------------Add flight--------------->
void addFlight(){
    int currentFlightNum = vectorFlights[vectorFlights.size() - 1].getFlightNum();
    string flightId, airline, origin, destiny;
    int timeFlight, capacity, occupied;
    int flightNum = currentFlightNum++;
    cout << "\n\n<-----Welcome!----->\n";
    cout << "You can now create a new flight!\n\n\n";
    cout << "Enter the airline: ";
    cin >> airline;
    cout << "Enter the origin: ";
    cin >> origin;
    cout << "Enter the destiny: ";
    cin >> destiny;
    cout << "Enter the time flight: ";
    cin >> timeFlight;
    cout << "Enter the capacity: ";
    cin >> capacity;
    int randIdNum = rand() % 900 + 100;
    int randIdNum2 = rand() % 9 + 1;
    flightId = to_string(randIdNum) + "-" + origin + "-" + destiny + "-" + airline.at(0) + "-" + to_string(randIdNum2);
    Flight newFlight = Flight(flightId, airline, flightNum, origin, destiny, timeFlight, capacity, occupied);
    vectorFlights.push_back(newFlight);
    cout << "The flight has been created succesfully!\n";
    cout << "Now lets set the date!\n";
    newFlight.setDate2();
    cout << "Now lets set the crew!\n";
    newFlight.setCrew2();
    cout << "Here is it's data: \n";
    newFlight.printFlight();
}
//<-------------Delete flight--------------->
void deleteFlight(){
    cout << "\n\n<-----Welcome!----->\n";
    cout << "You can now delete a flight!\n\n\n";
    Flight flight = searchById();
    int n = flight.getFlightNum() - 1000;
    vectorFlights.erase(vectorFlights.begin() + n);
    cout << "Flight deleted successfully!\n\n";
}

//<--------------------------Admin Menu & Main-------------------------->
//<-------------Admin Menu--------------->
int adminMenu(Admin adminUser){
    int ans;
    cout << "<-------Welcome Admin " << adminUser.getUser() << "!------->\n\n";
    cout << "Select an option...\n";
    cout << "Enter 1 to add flight\n";
    cout << "Enter 2 to delete flight\n";
    cout << "Enter 3 to change flight\n";
    cout << "Enter 4 to search flights\n";
    cout << "Enter 5 to log out\n";
    cout << "Enter 0 to terminate\n";
    cin >> ans;
    return ans;
}
//<-------------Admin Main--------------->
void admin(){
    Admin adminUser;
    int num;
    bool continuee = true;
    Flight flight;
    cout << "<-------Welcome Admin Please login------->\n\n";
    cout << "Enter 1 to login\n";
    cout << "Enter 2 to create admin\n";
    cin >> num;
    switch(num){
        case 1:
            adminUser = adminLogin();
            break;
        case 2:
            adminUser = createAdminUser();
            break;
        default:
            cout << "Enter valid number please...\n";
            admin();
    }
    while(continuee){
        int ans = adminMenu(adminUser);
        switch (ans){
            case 1:
                addFlight();
                break;
            case 2:
                deleteFlight();
                break;
            case 3:
                flight = searchById();
                flight.changeFlight();
                break;
            case 4:
                searchFlights();
                break;
            case 5:
                admin();
                break;
            case 0:
                continuee = false;
                break;
            default:
                cout << "Enter a valid option: \n";
                break;
        }
    }
}

//<--------------------------Passenger functions-------------------------->
// book flights
Passenger bookFlight(Passenger passengerUser){
    searchFlights();
    Flight flight = searchById();
    passengerUser.setpFlightId(flight.getFlightId());
    passengerUser.setFlight(flight);
    passengerUser.printFlight();
    cout << "You flight has been succesfully booked!\n\n";
    return passengerUser;
}
// change flight
Passenger changeFlight(Passenger passengerUser){
    searchFlights();
    Flight flight = searchById();
    passengerUser.setpFlightId(flight.getFlightId());
    passengerUser.setFlight(flight);
    cout << "You have successfuly changed your flight!\n\n";
    return passengerUser;
}


//<--------------------------Passengerr Menu & Main-------------------------->
//<-------------Passenger menu--------------->
int passengerMenu(Passenger passengerUser){
    int ans;
    cout << "<-------Welcome Passenger " << passengerUser.getpUserName() << "!------->\n\n";
    cout << "Enter 1 to see personal data\n";
    cout << "Enter 2 to update personal data\n";
    cout << "Enter 3 to search flights\n";
    cout << "Enter 4 to book flight\n";
    cout << "Enter 5 to change flight\n";
    cout << "Enter 6 to cancel flight\n";
    cout << "Enter 7 to see flight details\n";
    cout << "Enter 8 to log out\n";
    cout << "Enter 0 to terminate\n";
    cin >> ans;
    return ans;
}
//<-------------Passenger Main--------------->
void passenger(){
    Passenger passengerUser;
    int num;
    bool continuee = true;
    Flight flight;
    cout << "<-------Welcome Passenger Please login------->\n\n";
    cout << "Enter 1 to login\n";
    cout << "Enter 2 to create passenger\n";
    cin >> num;
    switch(num){
        case 1:
            passengerUser = passengerLogin();
            break;
        case 2:
            passengerUser = createPassengerUser();
            break;
        default:
            cout << "Enter valid number please...\n";
            admin();
    }
    while(continuee){
        int ans = passengerMenu(passengerUser);
        switch (ans){
            case 1:
                cout << "<----Passenger " << passengerUser.getpUserName() << " data----->\n";
                passengerUser.printPassenger();
                break;
            case 2:
                passengerUser.changeData();
                cout << "<-------Let's view your new data!------->\n";
                passengerUser.printPassenger();
                break;
            case 3:
                searchFlights();
                break;
            case 4:
                passengerUser = bookFlight(passengerUser);
                break;
            case 5:
                passengerUser = changeFlight(passengerUser);
                break;
            case 6:
                passengerUser.cancelFlight();
                break;
            case 7:
                vectorPassengers[0].printFlight();
                passengerUser.printFlight();
                break;
            case 8:
                passenger();
                break;
            case 0:
                continuee = false;
                break;
            default:
                cout << "Enter a valid option: \n";
                break;
        }
    }
}

//<--------------------------Main Menu & Main-------------------------->
int mainMenu(){
    bool continuee = true;
    int ans = printMainMenu();
    int num = 1;
        switch (ans){
        case 1:
            admin();
            break;
        case 2:
            passenger();
            break;
        case 0:
            continuee = false;
            num = 0;
            cout << "\nThe program has terminated with ease\n";
            break;
        default:
            cout << "\nEnter a valid option\n\n\n";
            break;
        }
    
    return num;
}
//<-------------Main--------------->
int main(){
    int nFlights;
    bool continuee = true;
    cout << "\n\n\n                      <--------------------Welcome to our airport console site!!-------------------->\n\n\n";
    cout << "Enter how many flights do you want to create: ";
    cin >> nFlights;
    while (nFlights < 1){
        cout << "Come on! Enter more flights for us to create!: ";
        cin >> nFlights;
    }
    createData(nFlights);
    createObjects();
    cout << "\n\n\nFlights created successfully!!\n\n\n";
    mainMenu();
}