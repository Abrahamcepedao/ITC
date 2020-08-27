#include <iostream>
#include <string>
#ifndef User_h
#define User_h
#include "Product.h"
using namespace std;
class User{
    protected:
        string username;
        string password;
        string movies[100];
        string wishMovies[100];
        string series[100];
        string wishSeries[100];
        int episodes[100];
        int numMovies;
        int numWishMovies;
        int numSeries;
        int numWishSeries;
    public:
        User();
        User(string, string);

        string getUsername(){return username;};
        string getPassword(){return password;};
        int getNumMovies(){return numMovies;};
        int getNumWishMovies(){return numWishMovies;};
        int getNumSeries(){return numSeries;};
        int getNumWishSeries(){return numWishSeries;};

        void setUsername(string username){this->username = username;};
        void setPassword(string password){this->password = password;};
        void setNumMovies(int numMovies){this->numMovies = numMovies;};

        bool userLogin(string);
        void addMovie(string);
        void getMovies(string listMovies[]);
        void addWishMovie(string);
        void getWishMovies(string listMovies[]);
        void addSeries(string);
        void addEpisode(int, string);
        void addWishSeries(string);
        void getSeries(string listSeries[]);
        void getWishSeries(string listSeries[]);
        int getEpisode(string);
};
// Constructors
User::User(){
    username = "-";
    password = "-";
    numMovies = 0;
    numWishMovies = 0;
    numSeries = 0;
    numWishSeries = 0;
}
User::User(string username, string password){
    this->username = username;
    this->password = password;
}

bool User::userLogin(string password){
    if (this->password == password){
        return true;
    } else{
        cout << "Incorrect password!\n";
        return false;
    }
    
}
//Methods
//<---------------------Movies--------------------->
void User::addMovie(string movieID){
    bool check = true;
    for(int count = 0; count < numMovies; count++){
        if(movies[count] == movieID){
            check = false;
        }
    } 
    if(check){
        numMovies++;
        movies[numMovies-1] = movieID;
    }
}
void User::getMovies(string listMovies[]){
    for(int count = 0; count < numMovies; count++){
        listMovies[count] = movies[count];
    }
}
void User::addWishMovie(string movieID){
    bool check = true;
    for(int count = 0; count < numWishMovies; count++){
        if(wishMovies[count] == movieID){
            check = false;
        }
    }
    if(check){
        numWishMovies++;
        wishMovies[numWishMovies-1] = movieID;
    }
}
void User::getWishMovies(string listMovies[]){
    for(int count = 0; count < numWishMovies; count++){
        listMovies[count] = wishMovies[count];
    }
}



//<---------------------Series--------------------->
void User::addSeries(string seriesID){
    bool check = true;
    for(int count = 0; count < numSeries; count++){
        if(series[count] == seriesID){
            check = false;
        }
    } 
    if(check){
        numSeries++;
        series[numSeries-1] = seriesID;
    }
}
void User::getSeries(string listSeries[]){
    for(int count = 0; count < numSeries; count++){
        listSeries[count] = series[count];
    }
}
void User::addEpisode(int episodeNum, string seriesID){
    for(int count = 0; count < numSeries; count++){
        if(series[count] == seriesID){
            episodes[count] = episodeNum;
        }
    }
}
int User::getEpisode(string seriesID){
    for(int count = 0; count < numSeries; count++){
        if(series[count] == seriesID){
            if(episodes[count] > 1000){
                return 0;
            } else{
                return episodes[count];
            }
        }
    }
    return 0;
}
void User::addWishSeries(string seriesID){
    bool check = true;
    for(int count = 0; count < numWishSeries; count++){
        if(wishSeries[count] == seriesID){
            check = false;
        }
    }
    if(check){
        numWishSeries++;
        wishSeries[numWishSeries-1] = seriesID;
    }
}
void User::getWishSeries(string listSeries[]){
    for(int count = 0; count < numWishSeries; count++){
        listSeries[count] = wishSeries[count];
    }
}
#endif