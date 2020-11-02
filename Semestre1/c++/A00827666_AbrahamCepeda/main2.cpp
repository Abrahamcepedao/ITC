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
#include "Flights.h"
#include "Passenger.h"
#include "Admin.h"

using namespace std;

// vectors
vector<Flight>vectorFlights;
vector<Passenger>vectorPassengers;
vector<Admin>vectorAdmins;

//<---------functions----------->
// data and objetcs
void createData(int n);
void createObjects();

//<---------Admin----------->
// admin login and user creation
Admin checkAdminLogin(string u, string p);
void adminLogin();
void createAdminUser();

// admin menus
void adminMenu(int, int, Admin);
int printAdminOptions(Admin, int);

// admin functions
void addFlight(Admin);
void addFlightMenu(Admin); //inside add flight
void setCrew(Flight); //inside add flight
void setDate(Flight); //inside add flight
void deleteFlight(Flight, Admin);
void changeFlight(Admin);


//<---------search----------->
// Search flights
void searchFlights(Admin); // for Admin
//void searchFlightsP(Passenger passengerUser, int what); // for passenger 
Flight searchById(string, Admin);
//string searchByIdP(string, Passenger passengerUser, int what); 
//string searchByOrigin(Passenger passengerUser, int what);
//string searchByDestiny(Passenger passengerUser, int what);
//string searchByAirline(Passenger passengerUser, int what);
//tring searchByDate(Passenger passengerUser, int what);

//<---------Passenger----------->
// passenger login and user creation
//Passenger checkPassengerLogin(string u, string p);
//void passengerLogin();
//void createPassengerUser();

// passenger menus
//void passengerMenu(int, int, Passenger);
//int printPassengerOptions(Passenger, int);

// passenger functions
//void seePassengerData(Passenger passengerUser);
//void updatePassengerData(Passenger);
//void bookFlight(Passenger, string);
//void changeFlightP(Passenger, string);
//void cancelFlight(Passenger);
//void seeFlight(Passenger); 
//we me tengo que ir, espero que acabes esto rapido. estoy casi seguro de que es algo con el orden o algo de ese estilo, checa los links que mande
// va weyy ntp muchas gracias por la ayuda! si los voy a leer para ver que pex jajaj
// nos vemos ✌

//<---------Main & Menu----------->
// main menu and main
void mainMenu();
int main();

//<--------------------------Coding begins-------------------------->

//<---------Data & Objects----------->
//create data
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
    
    /* crew << "Flight ID" << setw(24) << "Pilot" << setw(30) << "Co-pilot" << setw(30) << "Attendant1" << setw(30) << "Attendant2" << setw(30) << "Attendant2\n";
    passengers << "Flight ID" << setw(24) << "Key" << setw(15) << "First Name" << setw(15) << "Last Name" << setw(15) << "Sex" << setw(15) << "Age\n";
    flights << "Flight ID" << setw(24) << "Flight Number" << setw(15) << "Origin" << setw(15) << "Destiny" << setw(15) << "Time flight" << setw(15) << "Capacity\n";
    dates << "Flight ID" << setw(24) << "Years" << setw(15) << "Month" << setw(15) << "Day" << setw(15) << "Hour" << setw(15) << "Minute\n";
     */
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
//create objects
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


    // add object date to flights vector
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
            cout << word;
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

//<-------------Admin--------------->
// check admin login
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
        int ans;
        bool adminContinuee = true;
        while(adminContinuee){
            cout << "User name does not exists... please enter a valid one or create one\n";
            cout << "Enter 1 to enter a new one\n";
            cout << "Enter 2 to create one\n";
            cout << "Enter 0 to return to main menu\n";
            cin >> ans;
            switch(ans){
                case 1:
                    adminLogin();
                    break;
                case 2:
                    createAdminUser();
                    break;
                case 0: 
                    mainMenu();
                    break;
                default:
                    cout << "Enter a valid option\n";
            }
        }
        
    }
    // check if password is correct
    int passwordCount = 0;
    while (p != vectorAdmins[uNum].getPassword() && passwordCount < 10){
        cout << "Enter a valid passowrd please \n";
        cin >> p;
        passwordCount++;
    }
    // check if attemps exceeded
    if(passwordCount > 9){
        cout << "You exceeded your attemps... You will now be logged out\n";
        mainMenu();
    }
    return vectorAdmins[uNum];
}
// admin login
void adminLogin(){
    string userName;
    string password;
    cout << "\n<------Welcome to login (Admin)------>\n";
    cout << "Enter your username: ";
    cin >> userName;
    cout << "Enter your password: ";
    cin >> password;
    Admin adminUser = checkAdminLogin(userName, password);
    int n = printAdminOptions(adminUser, 1);
    adminMenu(n, 1, adminUser);
}
// create admin user
void createAdminUser(){
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
    int n = printAdminOptions(newAdmin, 1);
    adminMenu(n, 1, newAdmin);
}
// admin menu
void adminMenu(int ans, int n, Admin adminUser){
    int n2;
    if(n == 1){
        switch (ans){
        case 0:
            mainMenu();
            break;
        case 1:
            addFlight(adminUser);
            break;
        case 2:
            deleteFlight(vectorFlights[0], adminUser);
            break;
        case 3:
            cout << "Not available\n";
            //changeFlight(adminUser); //create
            break;
        case 4:
            //searchFlights(adminUser);
            break;
        default:
            cout << "Enter a valid option: \n";
            n2 = printAdminOptions(adminUser, 1);
            adminMenu(n2, 1, adminUser);
            break;
        }
    }
    else{
        switch (ans){
        case 0:
            mainMenu();
            break;
        case 1:
            adminLogin();
            break;
        case 2:
            createAdminUser();
            break;
        default:
            cout << "Enter a valid option: \n";
            n2 = printAdminOptions(adminUser, 1);
            adminMenu(n2, 1, adminUser);
            break;
        }
    }
    n2 = printAdminOptions(adminUser, 1);
    adminMenu(n, 1, adminUser);
}
// print Admin options
int printAdminOptions(Admin user, int n){
    int ans;
    if(n == 1){
        bool adminOptionsContinuee = true;
        cout << "<----Welcome " << user.getUser() << "---->\n\n";
        cout << "Select an option...\n";
        cout << "Enter 1 to add flight\n";
        cout << "Enter 2 to delete flight\n";
        cout << "Enter 3 to change flight\n";
        cout << "Enter 4 to search flight\n";
        cout << "Enter 0 to go to main menu\n";
        cin >> ans;   
    }
    else{
        cout << "\n\n\n<------Welcome admin------>\n\n\n";
        cout << "Enter 0 to return to main menu\n";
        cout << "Enter 1 to login\n";
        cout << "Enter 2 to create a new user\n";
        cin >> ans;
    }
    return ans;
}


// add flight
void addFlight(Admin adminUser){
    int currentFlightNum = vectorFlights[vectorFlights.size() - 1].getFlightNum();
    string flightId;
    string airline;
    string origin;
    string destiny;
    int timeFlight;
    int capacity;
    int occupied = 0;
    int flightNum = currentFlightNum++;
    cout << "\n\n<-----Welcome " << adminUser.getUser() << "!----->\n";
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
    setDate(newFlight);
    cout << "Now lets set the crew!\n";
    setCrew(newFlight);
    cout << "Here is it's data: \n";
    newFlight.printFlight();

    // print add flight menu
    addFlightMenu(adminUser);
}
void setCrew(Flight flight){ //we corre el codigo para que pueda ver que onda
    string crew[5] = {"Pilot", "Co_pilot", "Attendant1", "Attendant2", "Attendant3"};
    string crewData[5];
    string fName;
    string lName;
    for(int i = 0; i < 5; i++){
        cout << "\nEnter the " << crew[i] << "data\n";
        cout << "First name: ";
        cin >> fName;
        cout << "Last name: ";
        cin >> lName;
        crewData[i] = fName + "_" + lName;
    }
    Crew newCrew;
    newCrew.setPilot(crewData[0]);
    newCrew.setCoPilot(crewData[1]);
    newCrew.setAttendant1(crewData[2]);
    newCrew.setAttendant2(crewData[3]);
    newCrew.setAttendant3(crewData[4]);
    cout << "Try: " << crewData[4] << endl;
    flight.setCrew(newCrew);
}
void setDate(Flight flight){
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int arrayDiasMes[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    cout << "Enter date data\n";
    cout << "Year: ";
    cin >> year;
    cout << "Month: ";
    cin >> month;
    cout << "Day: ";
    cin >> day;
    cout << "Hour: ";
    cin >> hour;
    cout << "Minute: ";
    cin >> minute;
    while(year < 2019){
        cout << "Enter valid year: ";
        cin >> year;
    }
    while (month < 1 || month > 12){
        cout << "Enter valid month: ";
        cin >> month;
    }
    while (arrayDiasMes[month - 1] < day || day < 1){
        cout << "Enter valid day: ";
        cin >> day;
    }
    while (hour < 7 || hour > 22){
        cout << "Enter valid hour: ";
        cin >> hour;
    }
    while (minute != 0 && minute != 30){
        cout << "Enter valid min: ";
        cin >> minute;
    }
    Date date = Date(year, month, day, hour, minute);
    flight.setDate(date);
}
void addFlightMenu(Admin adminUser){
    cout << "What do you want to do next?\n";
    int ans;
    int n;
    cout << "Enter 0 to go to main menu\n";
    cout << "Enter 1 to create another flight\n";
    cout << "Enter 2 to admin menu\n";
    cin >> ans;
    switch (ans){
        case 0:
            mainMenu();
            break;
        case 1:
            addFlight(adminUser);
            break;
        case 2:
            n = printAdminOptions(adminUser, 1);
            adminMenu(n, 1, adminUser);
        default:
            cout << "Enter a valid number please...\n";
            addFlightMenu(adminUser);
            break;
    }
}
// delete flight
void deleteFlight(Flight flight, Admin adminUser){
    string flightID = flight.getFlightId();
    int n = flight.getFlightNum() - 1000;
    vectorFlights.erase(vectorFlights.begin() + n);
    cout << "Flight deleted susaccesfully!\n";
    int nn = printAdminOptions(adminUser, 1);
    adminMenu(nn, 1, adminUser);
}

//<-------------Search flights--------------->
// search flights for Admin
void searchFLights(Admin adminUser){
    cout << "<---Welcome to our search flights engine--->\n";
    string flightID;
    int ans;
    int n;
    bool continuee = true;
    while(continuee){
        cout << "Enter flight ID: ";
        cin >> flightID;
        Flight flight = searchById(flightID, adminUser);
        cout << "Select what you want to do with the flight\n";
        cout << "Enter 1 to delete\n";
        cout << "Enter 2 to print data\n";
        cout << "Enter 0 to go to admin menu\n";
        cin >> ans;
        switch(ans){
            case 1:
                deleteFlight(flight, adminUser);
                break;
            case 2:
                flight.printFlight();
                n = printAdminOptions(adminUser, 1);
                adminMenu(n, 1, adminUser);
                break;
            case 0:
                n = printAdminOptions(adminUser, 1);
                adminMenu(n, 1, adminUser);
                break;
            default:
                cout << "Enter a valid number please..\n";
                break;
        }
    } 
}
// search by flight Id
Flight searchById(string flightId, Admin adminUser){
    bool continuee = true;
    int count = 0;
    int fNum;
    while(continuee){
        if(flightId == vectorFlights[count].getFlightId()){
            continuee = false;
            fNum = count;
        }
        count++;
    }
    if(continuee == true){
        cout << "It appears the ID does not exist, please enter a valid one\n";
        searchFLights(adminUser);

    }
    return vectorFlights[fNum];
}

/* //search flights for passenger
void searchFlightsP(Passenger passengerUser, int what){
    string flightID2;
    string flightID;
    int ans;
    int n;
    cout << "<---Welcome to our search flights engine--->\n";
    cout << "Select how do you want to search\n";
    cout << "Enter 1 to search by ID\n";
    cout << "Enter 2 to search by origin\n";
    cout << "Enter 3 to search by destiny\n";
    cout << "Enter 4 to search by airline\n";
    cout << "Enter 5 to search by date\n";
    cout << "Enter 0 to passeenger menu\n";
    cin >> ans;
    switch(ans){
        case 1:
            cout << "Enter flight ID: ";
            cin >> flightID2;
            flightID = searchByIdP(flightID2, passengerUser, 1);
            break;
        case 2:
            flightID = searchByOrigin(passengerUser, what);
            break;
        case 3:
            flightID = searchByDestiny(passengerUser, what);
            break;
        case 4:
            flightID = searchByAirline(passengerUser, what);
            break;
        case 5:
            cout << "Not available\n";
            //flightID = searchByDate(passengerUser, what); //create
            break;
        case 0:
            n = printPassengerOptions(passengerUser, 1);
            passengerMenu(n, 1, passengerUser);
            break;
        default:
            cout << "Enter a valid number\n";
            searchFlightsP(passengerUser, 1);
            break;
    }
    if(what == 2){
        bookFlight(passengerUser, flightID);
    }
    else if(what == 3){
        changeFlightP(passengerUser, flightID);
    } 
    else{
        n = printPassengerOptions(passengerUser, 1);
        passengerMenu(n, 1, passengerUser);
    }
}
// search flight by id passenger
string searchByIdP(string flightId, Passenger passengerUser, int what){
    bool continuee = true;
    int count = 0;
    int fNum;
    while(continuee){
        if(flightId == vectorFlights[count].getFlightId()){
            continuee = false;
            fNum = count;
        }
        count++;
    }
    if(continuee == true){
        cout << "It appears the ID does not exist\n";
        searchFlightsP(passengerUser, what);
    }
    return vectorFlights[fNum].getFlightId();
}
// search by origin for passenger
string searchByOrigin(Passenger passengerUser, int what){
    int ans;
    int count = 1;
    bool originExists = false;
    string origin;
    string id;
    cout << "<---searching by origin--->\n";
    cout << "Enter 1 for Mexico\n";
    cout << "Enter 2 for Us\n";
    cout << "Enter 0 to go to admin menu\n";
    cin >> ans;
    cout << "Enter origin (MTY): ";
    cin >> origin;
    if(ans == 1){
        origin += "-M";
        for(int i = 0; i < vectorFlights.size(); i++){
            if(origin == vectorFlights[i].getOrigin()){
                cout << "<----Flight " << count << "---->\n";
                vectorFlights[i].printFlight();
                count++;
                originExists = true;
            }
        }
    }
    else if(ans == 2){
        origin += "-US";
        for(int i = 0; i < vectorFlights.size(); i++){
            if(origin == vectorFlights[i].getOrigin()){
                cout << "<----Flight " << count << "---->\n";
                vectorFlights[i].printFlight();
                count++;
                originExists = true;
            }
        }
    } else if(ans == 0){
        int n = printPassengerOptions(passengerUser, 1);
        passengerMenu(n, 1, passengerUser);
    } else{
        cout << "Enter a valid number please..\n";
        searchFlightsP(passengerUser, what);
    }
    if(!originExists){
        cout << "There is no flight with such origin... enter another one\n";
        searchFlightsP(passengerUser, what);
    }
    if(what == 2){
        int ans2;
        int n;
        count = 0;
        bool continuee = false;
        string id;
        cout << "Enter the id of the flight you want to book: ";
        cin >> id;
        while(continuee){
            if(id == vectorFlights[count].getFlightId()){
                continuee = true;
            }
            count++;
        }
        if(!continuee){
            cout << "Invalid ID... look for another one\n";
            searchFlightsP(passengerUser, what);
        }
    } else{
        searchFlightsP(passengerUser, what);
    }
    return id;
}
// search by destiny for passenger
string searchByDestiny(Passenger passengerUser, int what){
    int ans;
    int count = 1;
    bool originExists = false;
    string destiny;
    string id;
    cout << "<---searching by destiny--->\n";
    cout << "Enter 1 for Mexico\n";
    cout << "Enter 2 for Us\n";
    cout << "Enter 0 to go to admin menu\n";
    cin >> ans;
    cout << "Enter origin (MTY): ";
    cin >> destiny;
    if(ans == 1){
        destiny += "-M";
        for(int i = 0; i < vectorFlights.size(); i++){
            if(destiny == vectorFlights[i].getDestiny()){
                cout << "<----Flight " << count << "---->\n";
                vectorFlights[i].printFlight();
                count++;
            }
        }
    }
    else if(ans == 2){
        destiny += "-US";
        for(int i = 0; i < vectorFlights.size(); i++){
            if(destiny == vectorFlights[i].getDestiny()){
                cout << "<----Flight " << count << "---->\n";
                vectorFlights[i].printFlight();
                count++;
            }
        }
    } else if(ans == 0){
        int n = printPassengerOptions(passengerUser, 1);
        passengerMenu(n, 1, passengerUser);
    } else{
        cout << "Enter a valid number please..\n";
        searchFlightsP(passengerUser, what);
    }
    if(!originExists){
        cout << "There is no flight with such origin... enter another one\n";
        searchFlightsP(passengerUser, what);
    }
    if(what == 2){
        int ans2;
        int n;
        count = 0;
        bool continuee = false;
        string id;
        cout << "Enter the id of the flight you want to book: ";
        cin >> id;
        while(continuee){
            if(id == vectorFlights[count].getFlightId()){
                continuee = true;
            }
            count++;
        }
        if(!continuee){
            cout << "Invalid ID... look for another one\n";
            searchFlightsP(passengerUser, what);
        }
    } else{
        searchFlightsP(passengerUser, what);
    }
    return id;
} */

//<-------------Passenger--------------->

// passenger login and user creation
/* Passenger checkPassengerLogin(string u, string p){
    // check if username exists
    bool uExists = false;
    int uNum;
    for(int i = 0; i < vectorPassengers.size(); i++){
        if(u == vectorPassengers[i].getpUserName()){
            uExists = true;
            uNum = i;
        }
    }
    // do if user does not exist
    cout << "Bool: " << uExists << endl;
    if(!uExists){
        int ans;
        bool passengerContinuee = true;
        while(passengerContinuee){
            cout << "User name does not exists... please enter a valid one or create one\n";
            cout << "Enter 1 to enter a new one\n";
            cout << "Enter 2 to create one\n";
            cout << "Enter 0 to return to main menu\n";
            cin >> ans;
            switch(ans){
                case 1:
                    passengerLogin();
                    break;
                case 2:
                    createPassengerUser();
                    break;
                case 0: 
                    mainMenu();
                    break;
                default:
                    cout << "Enter a valid option\n";
            }
        }
        
    }
    // check if password is correct
    int passwordCount = 0;
    while (p != vectorPassengers[uNum].getpPassword() && passwordCount < 10)
    {
        cout << "Enter a valid passowrd please \n";
        cin >> p;
        passwordCount++;
    }
    // check if attemps exceeded
    if(passwordCount > 9){
        cout << "You exceeded your attemps... You will now be logged out\n";
        mainMenu();
    }
    return vectorPassengers[uNum];
}
void passengerLogin(){
    string userName;
    string password;
    cout << "\n<------Welcome to login (Passenger)------>\n";
    cout << "Enter your username: ";
    cin >> userName;
    cout << "Enter your password: ";
    cin >> password;
    Passenger passengerUser = checkPassengerLogin(userName, password);
    int n = printPassengerOptions(passengerUser, 1);
    passengerMenu(n, 1, passengerUser);
}
void createPassengerUser(){
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
    int n = printPassengerOptions(newPassenger, 1);
    passengerMenu(n, 1, newPassenger);
} */


// passenger menus
/* void passengerMenu(int ans, int n, Passenger passengerUser){
    int n2;
    if(n == 1){
        switch (ans){
        case 0:
            mainMenu();
            break;
        case 1:
            seePassengerData(passengerUser);
            break;
        case 2:
            updatePassengerData(passengerUser);
            break;
        case 3:
            searchFlightsP(passengerUser, 1);
            break;
        case 4:
            searchFlightsP(passengerUser, 2);
            break;
        case 5:
            searchFlightsP(passengerUser, 3);
            break;
        case 6:
            cancelFlight(passengerUser);
            break;
        case 7:
            seeFlight(passengerUser);
            break;
        default:
            cout << "Enter a valid option: \n";
            n2 = printPassengerOptions(passengerUser, 1);
            passengerMenu(n2, 1, passengerUser);
            break;
        }
    }
    else{
        switch (ans){
        case 0:
            mainMenu();
            break;
        case 1:
            adminLogin();
            break;
        case 2:
            createAdminUser();
            break;
        default:
            cout << "Enter a valid option: \n";
            n2 = printPassengerOptions(passengerUser, 1);
            passengerMenu(n2, 1, passengerUser);
            break;
        }
    }
}
int printPassengerOptions(Passenger user, int n){
    int ans;
    if(n == 1){
        cout << "<----Welcome " << user.getpUserName() << "---->\n\n";
        cout << "Select an option...\n";
        cout << "Enter 1 to see personal data\n";
        cout << "Enter 2 to update personal data\n";
        cout << "Enter 3 to search flights\n";
        cout << "Enter 4 to book flight\n";
        cout << "Enter 5 to change flight\n";
        cout << "Enter 6 to cancel flight\n";
        cout << "Enter 7 to see flight details\n";
        cout << "Enter 0 to go to main menu\n";
        cin >> ans;   
    }
    else{
        cout << "\n\n\n<------Welcome admin------>\n\n\n";
        cout << "Enter 0 to return to main menu\n";
        cout << "Enter 1 to login\n";
        cout << "Enter 2 to create a new user\n";
        cin >> ans;
    }
    return ans;
} */

// passenger functions
/* void updatePassengerData(Passenger passengerUser){
    int ans;
    cout << "<----Update passenger data----->\n";
    cout << "Select what do you want to change?\n";
    cout << "Enter 1 for Username\n";
    cout << "Enter 2 for Passowrd\n";
    cout << "Enter 3 for First name\n";
    cout << "Enter 4 for Lasta name\n";
    cout << "Enter 5 for Sex\n";
    cout << "Enter 6 for Age\n";
    cout << "Enter 0 to go to Passenger menu";
    if(ans == 1){
        string username;
        cout << "Enter new username: ";
        cin >> username;
        passengerUser.setpUserName(username);
    }
    else if(ans == 2){
        string password;
        cout << "Enter new username: ";
        cin >> password;
        passengerUser.setpPassword(password);
    }
    else if(ans == 3){
        string fName;
        cout << "Enter new first name: ";
        cin >> fName;
        passengerUser.setpfName(fName);
    }
    else if(ans == 4){
        string lName;
        cout << "Enter new last name: ";
        cin >> lName;
        passengerUser.setplName(lName);
    }
    else if(ans == 5){
        string sex;
        cout << "Enter new sex: ";
        cin >> sex;
        passengerUser.setpSex(sex);
    }
    else if(ans == 6){
        int age;
        cout << "Enter new age: ";
        cin >> age;
        passengerUser.setpAge(age);
    } 
    else if(ans == 0){
        int n = printPassengerOptions(passengerUser, 1);
        passengerMenu(n, 1, passengerUser);
    } else{
        cout << "Enter a valid number pleasee..\n";
        updatePassengerData(passengerUser);
    }
}
void bookFlight(Passenger passengerUser, string id){
    searchFlightsP(passengerUser, 2);
    passengerUser.setpFlightId(id);
    cout << "Flight booked successfully!\n\n";
    int n = printPassengerOptions(passengerUser, 1);
    passengerMenu(n, 1, passengerUser);

}
void changeFlightP(Passenger passengerUser, string newFlightId){
    searchFlightsP(passengerUser, 3);
    passengerUser.setpFlightId(newFlightId);
    cout << "Flight changed successfully!\n\n";
    int n = printPassengerOptions(passengerUser, 1);
    passengerMenu(n, 1, passengerUser);
}
void cancelFlight(Passenger passengerUser){
    passengerUser.setpFlightId("--");
    int n = printPassengerOptions(passengerUser, 1);
    passengerMenu(n, 1, passengerUser);
}
void seeFlight(Passenger passengerUser){
    string flightId = passengerUser.getpFlightId();
    bool continuee = false;
    int count = 0;
    int fNum;
    while(continuee){
        if(flightId == vectorFlights[count].getFlightId()){
            continuee = true;
            fNum = count;
        }
        count++;
    }
    vectorFlights[fNum].printFlight();
    int n = printPassengerOptions(passengerUser, 1);
    passengerMenu(n, 1, passengerUser);
} */

//<-------------Main & Menu--------------->
// main menu
void mainMenu(){
    bool continuee = true;
    int ans;
    int n;
    while(continuee){
        cout << "\n\n\nAre you a flight admin or a user?\n\n\n";
        cout << "Enter 1 for flight admin\n";
        cout << "Enter 2 for user\n";
        cout << "Enter 0 for termination\n";
        cin >> ans;
        switch (ans){
        case 1:
            n = printAdminOptions(vectorAdmins[0], 2);
            adminMenu(n, 2, vectorAdmins[0]);
            break;
        case 2:
            //n = printPassengerOptions(vectorPassengers[0], 2);
            //passengerMenu(n, 2, vectorPassengers[0]);
            break;
        case 0:
            continuee = false;
            cout << "\nThe program has terminated with ease\n";
            break;
        default:
            cout << "\nEnter a valid option\n\n\n";
            break;
        }
    }
    
}
// main
int main(){
    int nFlights;
    bool continuee = true;
    cout << "\n\n\n                        <--------------------Welcome to our airport console site!!-------------------->\n\n\n";
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
