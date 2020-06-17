#include <iostream>
#include <string>
#ifndef Episode_h
#define Episode_h
#include "Season.h"
#include "Video.h"
using namespace std;
class Episode: public Video{
    private:
        string seasonID;
    public:
        Episode();
        Episode(string, string, string, int, float, string seasonID);

        
        string getSeasonID(){return seasonID;};
        
        void setSeasonID(string seasonID){this->seasonID = seasonID;};

        void printVideo();
        void shortPrint();
        void play();
};
//constructors
Episode::Episode(){
    seasonID = "";
}
Episode::Episode(string videoID, string title, string videoGenre, int duration, float videoRating, string seasonID):Video(videoID, title, videoGenre, duration, videoRating){
    this->seasonID = seasonID;
}

//methods
void Episode::printVideo(){
    cout << "<-----Video Data----->\n";
    cout << "Season: " << seasonID << "\n";
    cout << "ID: " << videoID << " - Title: " << title << " - Runtime: " << runtime << " - Rating: " << videoRating << "\n";
}
void Episode::shortPrint(){
    cout << "ID: " << videoID << " - Title: " << title << " - Rating: " << videoRating << "\n";
}
/* string Episode::name2(){
    return typeid(Episode).name();
} */
void Episode::play(){
    string space = "       ";
    cout << "\n\n" << space << " You are now watching " << title << "!! We hope you enjoy the episode\n\n";
    cout << space << space << runtime << " minutes later..\n\n";
    cout << space << " The episode has finished with ease..!\n\n";
}
#endif