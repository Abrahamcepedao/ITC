#include <iostream>
#include <math.h>
#include <fstream>
#include <stdlib.h> /* srand, rand */
#include <time.h>   /* time */
using namespace std;
int main(){
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
    
    int flightNumber = 1000;
    int numberOfFlights = 100;
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
    string flightIdArray[numberOfFlights];

    for (int i = 0; i < numberOfFlights; i++){
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

    for (int i = 0; i < numberOfFlights; i++){
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
    
    return 0;
}

