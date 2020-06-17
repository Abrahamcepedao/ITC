#include <iostream>
#include <string>
#ifndef Person_h
#define Person_h
using namespace std;
class Crew{
    protected:
        string director;
        string actor1;
        string actor2;
        string actor3;
    public:
        Crew();
        Crew(string, string, string, string);

        void printCrew();
};
// constructors
Crew::Crew(){
    director = "";
    actor1 = "";
    actor2 = "";
    actor3 = "";
}
Crew::Crew(string director, string actor1, string actor2, string actor3){
    this->director = director;
    this->actor1 = actor1;
    this->actor2 = actor2;
    this->actor3 = actor3;
}
// methods
void Crew::printCrew(){
    cout << "<---Crew--->\n";
    cout << "Director: " << director << "\n";
    cout << "Actor 1: " << actor1 << "\n";
    cout << "Actor 2: " << actor2 << "\n";
    cout << "Actor 3: " << actor3 << "\n\n\n";
}
#endif