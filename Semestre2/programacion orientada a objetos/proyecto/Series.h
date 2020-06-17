#include <iostream>
#include <string>
#ifndef Series_h
#define Series_h
#include "Product.h"
using namespace std;
class Series: public Product{
    protected:
        int numSeasons;
        int numEpisodes;
        string description;
        string seasons[26];
    public:
        Series();
        Series(string, string, string, string, string, float, int, int, int, string);

        int getNumSeasons(){return numSeasons;};
        int getNumEpisodes(){return numEpisodes;};
        string getDescription(){return description;};

        void setNumEpisodes(int numEpisodes){this->numEpisodes = numEpisodes;};
        void setNumSeasons(int numSeasons){this->numSeasons = numSeasons;};
        void setDescription(string description){this->description = description;};

        bool addSeason(string, int);
        void printProduct();
};
//constructors
Series::Series(){
    numSeasons = 0;
    numEpisodes = 0;
    description = "-";
}
Series::Series(string ID, string name, string genre, string ageClassification, string studio, float rate, int year, int numSeasons, int numEpisodes, string description):Product(ID,name,genre,ageClassification,studio, rate,year){
    this->numSeasons = numSeasons;
    this->numEpisodes = numEpisodes;
    this->description = description;
}

//methods
bool Series::addSeason(string seasonID, int seasonNumber){
    if(seasonNumber < numSeasons){
        seasons[seasonNumber] = seasonID;
        return true;
    } else{
        return false;
    }
}

void Series::printProduct(){
    cout << "<----Data of show----->\n";
    cout << "ID: " << ID << "\n";
    cout << "Title: " << name << "\n";
    cout << "Descrition: " << description << "\n";
    cout << "Genre: " << genre << "\n";
    cout << "Age Classification: " << ageClassification << "\n";
    cout << "Studio: " << studio << "\n";
    cout << "Rating: " << rate << "\n";
    cout << "Year published: " << year << "\n";
    cout << "Number of seasons: " << numSeasons << "\n";
    cout << "Number of episodes: " << numEpisodes << "\n\n\n";
}
#endif