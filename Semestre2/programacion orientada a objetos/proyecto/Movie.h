#include <iostream>
#include <string>
#ifndef Movie_h
#define Movie_h
#include "Product.h"
#include "Video.h"
#include "Crew.h"
using namespace std;
class Movie: public Video, public Product{
    private:
        int movie_nominee;
        int movie_win;
        int actor_win;
        int actress_win;
        int dir_win;
        int top;
        Crew crew;
    public:
        Movie();
        Movie(string, string, string, string, string, float, int, int, int, int, int, int, int, Crew); // as Product
        Movie(string, string, string, int, float, Crew);                                                        // Aas Video

        int getMovieNominee(){return movie_nominee;};
        int getMovieWin(){return movie_win;};
        int getActorWin(){return actor_win;};
        int getActressWin(){return actress_win;};
        int getDirWIn(){return dir_win;};
        int getTop(){return top;};

        void setMovieNominee(int movie_nominee){this->movie_nominee = movie_nominee;};
        void setMovieWin(int movie_win){this->movie_win = movie_win;};
        void setActorWin(int actor_win){this->actor_win = actor_win;};
        void setActressWin(int actress_win){this->actress_win = actress_win;};
        void setDirectorWin(int dir_win){this->dir_win = dir_win;};

        void printCrew();
        void printProduct();
        void printVideo();
        void shortPrint();
        void play();
};
// constructors
Movie::Movie(){
    movie_nominee = 0;
    movie_win = 0;
    actor_win = 0;
    actress_win = 0;
    dir_win = 0;
    top = 0;
    crew = Crew();
}
Movie::Movie(string ID, string name, string genre, string ageClassification, string studio, float rate, int year, int movie_nominee, int movie_win, int actor_win, int actress_win, int dir_win, int top, Crew crew):Product(ID,name,genre,ageClassification,studio, rate,year){
    this->movie_nominee = movie_nominee;
    this->movie_win = movie_win;
    this->actor_win = actor_win;
    this->actress_win = actress_win;
    this->dir_win = dir_win;
    this->top = top;
    this->crew = crew;
}
Movie::Movie(string casillavideoID, string title, string videoGenre, int duration, float videoRating, Crew crew):Video(videoID, title, videoGenre, duration, videoRating){
    this->crew = crew;
}
//methods
void Movie::printCrew(){
    crew.printCrew();
}

void Movie::printProduct(){
    cout << "<----Data of Movie----->\n";
    cout << "ID: " << ID << "\n";
    cout << "Title: " << name << "\n";
    cout << "Genre: " << genre << "\n";
    cout << "Age Classification: " << ageClassification << "\n";
    cout << "Studio: " << studio << "\n";
    cout << "Rating: " << rate << "\n";
    cout << "Year published: " << year << "\n";
    printCrew();
}
void Movie::printVideo(){
    cout << "<-----Video Data----->\n";
    cout << "ID: " << videoID << " - Title: " << title << " - Runtime: " << runtime << " - Rating: " << videoRating << "\n";
    printCrew();
}
void Movie::shortPrint(){
    cout << "ID: " << videoID << " - Title: " << title << " - Rating: " << videoRating << "\n";
}
/* string Movie::name2(){
    return typeid(Movie).name();
} */
void Movie::play(){
    string space = "       ";
    printVideo();
    cout << "\n\n" << space << "You are now watching " << title << "!! We hope you enjoy the movie\n\n";
    cout << space << runtime << " minutes later..\n\n";
    cout << space << "The movie has finished with ease..!\n";
}
#endif