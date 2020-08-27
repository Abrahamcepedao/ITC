#include <iostream>
#include <string>
#include <vector>
#ifndef Season_h
#define Season_h
#include "Series.h"
#include "Episode.h"
using namespace std;
class Season{
    protected:
        string seriesID;
        string seasonID;
        int numEpisodes;
        string episodes[200];
        
    public:
        Season();
        Season(string, string, int);
        
        string getSeriesID(){return seriesID;};
        string getSeasonID(){return seasonID;};
        int getNumEpisodes(){return numEpisodes;};

        void setSeriesID(string seriesID){this->seriesID = seriesID;};
        void setSeasonID(string seasonID){this->seasonID = seasonID;};
        void setNumEpisodes(int numEpisodes){this->numEpisodes = numEpisodes;};

        bool addEpisodes(string, int);
        int calculateEpisodes(int, int, int);
};
//constructors
Season::Season(){
    seriesID = "-";
    seasonID = "-";
    numEpisodes = 0;
}
Season::Season(string seriesID, string seasonID, int numEpisodes){
    this->seriesID = seriesID;
    this->seasonID = seasonID;
    this->numEpisodes = numEpisodes;
}

//methods
bool Season::addEpisodes(string episodeID, int episodeNumber){
    if(episodeNumber < numEpisodes){
        episodes[episodeNumber] = episodeID;
        return true;
    } else{
        return false;
    }
}

int Season::calculateEpisodes(int numEpisodes, int numSeasons, int count){
    int num = numEpisodes / numSeasons;
    int rem = numEpisodes % numSeasons;
    if(count < (numSeasons-1)){
        return num;
    } else{
        return num + rem;
    }
}
#endif