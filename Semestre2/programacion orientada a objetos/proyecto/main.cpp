// Proyecto - Servicio de Streaming
// Abraham Cepeda Oseguera
// A00827666

#include <iostream>
#include <string>
#include <fstream>
#include <math.h>
#include <limits>
#include "Series.h"
#include "Season.h"
#include "Episode.h"
#include "Movie.h"
#include "User.h"

using namespace std;

// constants
int numVideos = 18715;
int numMovies = 651;
int numSeries = 445;
int numProducts = numMovies + numSeries;
int numSeasons = 1118;
int numUsers = 0;
int numGenres = 0;
int numStudios = 0;
// Array de objetos
Product *products[1096];
Video *videos[18715];
Season seasons[1118];
User users[100];
User currentUser;
string genres[100];
string studios[1000];

// <---------------------Data--------------------->

void checkGenre(string genre){
    bool check = true;
    for(int count = 0; count < numGenres; count++){
        if(genres[count] == genre){
            check = false;
        }
    }
    if(check){
        genres[numGenres] = genre;
        numGenres++;
    }
}

void listGenres(){
    cout << "\n\nHere is the list of genres...\n\n";
    for(int count = 0; count < numGenres; count++){
        cout <<  genres[count] << "\n";
    }
}

void checkStudios(string studio){
    bool check = true;
    for(int count = 0; count < numStudios; count++){
        if(studios[count] == studio){
            check = false;
        }
    }
    if(check){
        studios[numStudios] = studio;
        numStudios++;
    }
}

void listStudios(){
    cout << "\n\nHere is the list of studios...\n\n";
    for(int count = 0; count < numStudios; count++){
        cout <<  studios[count] << "\n";
    }
}

// create objects (movies, series, seasons,)
void creatObjects(){
    // declare variables
    int count = 0;
    string ID, name, genre, ageClassification, studio, title, director, actor1, actor2, actor3, description;
    float rate;
    int year, movie_nominee, movie_win, actor_win, actress_win, dir_win, top, runtime, videoRating, numEpisodes, numSeasons;
    
    // add movie objects
    ifstream movieFile;
    movieFile.open("movies.txt");
    while (movieFile >> ID >> name >> genre >> runtime >> ageClassification >> studio >> year >> rate >> movie_nominee >> movie_win >> actor_win >> actress_win >> dir_win >> top >> director >> actor1 >> actor2 >> actor3){
        Crew crew(director, actor1, actor2, actor3);
        products[count] = new Movie(ID, name, genre, ageClassification, studio, rate, year, movie_nominee, movie_win, actor_win, actress_win, dir_win, top, crew);
        videos[count] = new Movie(ID, name, genre, runtime, rate, crew);
        checkGenre(genre);
        checkStudios(studio);
        count++;
    }
    movieFile.close();

    // add series objects
    ifstream showFile;
    showFile.open("shows.txt");
    int countSeasons = 0, videosCount = count;
    float videoRate;
    string seasonID, episodeID, episodeTitle;
    while(showFile >> ID >> name >> description >> numEpisodes >> genre >> rate >> numSeasons >> studio >> year >> ageClassification >> runtime){
        products[count] = new Series(ID, name, genre, ageClassification, studio, rate, year, numSeasons, numEpisodes, description);
        for(int countS = 0; countS < numSeasons; countS++){
            seasonID = ID + "_season" + to_string(countS + 1);
            seasons[countSeasons].setSeriesID(ID);
            seasons[countSeasons].setSeasonID(seasonID);
            seasons[countSeasons].setNumEpisodes(seasons[countSeasons].calculateEpisodes(numEpisodes, numSeasons, countS));
            for(int countE = 0; countE < seasons[countSeasons].getNumEpisodes(); countE++){
                episodeID = seasonID + "_episode" + to_string(countE + 1);
                episodeTitle = "Episode " + to_string(countE + 1);
                videoRate = rate + pow(-1.0,countE)*0.5;
                videos[videosCount] = new Episode(episodeID, episodeTitle, genre, runtime, videoRate, seasonID);
                videosCount++;
            }
            checkGenre(genre);
            checkStudios(studio);
            countSeasons++;
        }
        count++;
    }

    // add user objects
    ifstream usersFile;
    usersFile.open("users.txt");
    string username, password;
    count = 0;
    while(usersFile >> username >> password){
        users[count].setUsername(username);
        users[count].setPassword(password);
        count++;
    }
    numUsers = count;
}

// Input validation
int checkInt(int min, int max){
    int num;
    cin >> num;
    while(1){
        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "Input must be a number.. try again!\n";
            cin >> num;
        }
        if(!cin.fail()){
            if(num < min || num > max){
                cout << "Enter a valid number.. try again!\n";
                cin >> num;
            } else{
                break;
            }
        }
    }
    return num;
}

float checkFloat(float min, float max){
    float num;
    cin >> num;
    while(1){
        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "Input must be a number.. try again!\n";
            cin >> num;
        }
        if(!cin.fail()){
            if(num < min || num > max){
                cout << "Enter a valid number.. try again!\n";
                cin >> num;
            } else{
                break;
            }
        }
    }
    return num;
}

// <---------------------Movies--------------------->
// movie functions
void listMovies(){
    cout << "Do you want to see the entire description or solely de title?\n";
    cout << "1. Title Only\n";
    cout << "2. Entire descrption\n";
    int answer = checkInt(1,2);
    if(answer == 1){
        for(int count = 0; count < numMovies; count++){
            cout << products[count]->getID() << " - " << products[count]->getName() << "\n";
        }
    } else{
        for(int count = 0; count < numMovies; count++){
            Movie *movie = (Movie *)(products[count]);
            movie->printProduct();
        }
    }
}

void movieGenre(){
    string genre;
    int countMovies = 0;
    cout << "Enter the genre you want to look for: ";
    cin >> genre;
    for(int count = 0; count < numMovies; count++){
        if(products[count]->getGenre() == genre){
            products[count]->printProduct();
            countMovies++;
        }
    }
    cout << countMovies << endl;
    if(countMovies == 0){
        cout << "No movies of " << genre << " where found..\n";
        cout << " 1. See list of genres\n";
        cout << " 2. Search for another genre\n";
        int answer = checkInt(1,2);
        if(answer == 1){
            listGenres();
        }
        movieGenre();
    }
}

void movieRate(){
    cout << "Enter the minimum rating (1,5,0.5): ";
    float rate = checkFloat(1.0,5.0);
    cout << "Do you want to see the entire description or solely de title?\n";
    cout << "1. Title Only\n";
    cout << "2. Entire description\n";
    int answer = checkInt(1,2);
    if (answer == 1){
        for(int count = 0; count < numMovies; count++){
            if(videos[count]->getVideoRating() >= rate){
                videos[count]->shortPrint();
            }
        }
    } else{
        for(int count = 0; count < numMovies; count++){
            if(videos[count]->getVideoRating() >= rate){
                videos[count]->printVideo();
            }
        }
    }
}

void movieYear(){
    int countMovies = 0;
    cout << "Enter the year you want to search for (1970-2104): ";
    int year = checkInt(1970, 2014);
    for(int count = 0; count < numMovies; count++){
        if(products[count]->getYear() == year){
            products[count]->printProduct();
            countMovies++;
        }
    }
    if(countMovies == 0){
        cout << "No movies from " << year << " were found.. try again!\n";
        movieYear();
    }
}

void movieStudio(){
    string studio;
    int countMovies = 0;
    cout << "Enter the studio: ";
    cin >> studio;
    for(int count = 0; count < numMovies; count++){
        if(products[count]->getStudio() == studio){
            products[count]->printProduct();
            countMovies++;
        }
    }
    if(countMovies == 0){
        cout << " No movies produced by " << studio << " were found..\n";
        cout << " 1. See list of studios\n";
        cout << " 2. Search for another studio\n";
        int answer = checkInt(1,2);
        if(answer == 1){
            listStudios();
        }
        movieStudio();
    }
}

void movieAge(){
    string age;
    int movieCount = 0;
    cout << "Enter the age classification: ";
    cin >> age;
    for(int count = 0; count < numMovies; count++){
        if(products[count]->getAgeClassification() == age){
            products[count]->printProduct();
        }
    }
    if(movieCount == 0){
      cout << "No movies with " << age << " were found.. try again!\n";
    }
}

void movieNominee(){
    cout << "\n\n<---------Here are the nomited for the Oscar movies!\n\n";
    for(int count = 0; count < numMovies; count++){
        Movie *movie = (Movie *)(products[count]);
        if(movie->getMovieNominee() == 1){
            movie->printProduct();
        }
    }
}

void movieWinner(){
    cout << "\n\n<---------Here are the movies that won an Oscar!\n\n";
    for(int count = 0; count < numMovies; count++){
        Movie *movie = (Movie *)(products[count]);
        if(movie->getMovieWin() == 1){
            movie->printProduct();
        }
    }
}

void movieActor(){
    cout << "\n\n<---------Here are the movies that the actor won an Oscar!\n\n";
    for(int count = 0; count < numMovies; count++){
        Movie *movie = (Movie *)(products[count]);
        if(movie->getActorWin() == 1){
            movie->printProduct();
        }
    }
}

void movieActress(){
    cout << "\n\n<---------Here are the movies that the actress won an Oscar!\n\n";
    for(int count = 0; count < numMovies; count++){
        Movie *movie = (Movie *)(products[count]);
        if(movie->getActressWin() == 1){
            movie->printProduct();
        }
    }
}

void movieDirector(){
    cout << "\n\n<---------Here are the movies that the director won an Oscar!\n\n";
    for(int count = 0; count < numMovies; count++){
        Movie *movie = (Movie *)(products[count]);
        if(movie->getDirWIn() == 1){
            movie->printProduct();
        }
    }
}

void movieTop(){
    cout << "\n\n<---------Here are the movies that made the Top200 list!\n\n";
    for(int count = 0; count < numMovies; count++){
        Movie *movie = (Movie *)(products[count]);
        if(movie->getTop() == 1){
            movie->printProduct();
        }
    }
}

// Movie Query
Movie *movieByID(string movieID){
    for(int count = 0; count < numMovies; count++){
        if(videos[count]->getVideoID() == movieID){
            Movie *movie = (Movie *)(videos[count]);
            return movie;
        }
    }
    Movie *movie;
    return movie;
}

Movie *movieByTitle(string title){
    for(int count = 0; count < numMovies; count++){
        if(videos[count]->getTitle() == title){
            Movie *movie = (Movie *)(videos[count]);
            return movie;
        }
    }
    cout << "Such title does not exist..";
    cout << "Do you want to sea the list of movies?\n";
    cout << "1. Yes\n";
    cout << "2. Search for another title\n";
    int answer = checkInt(1, 2);
    if(answer == 1){
        listMovies();
    }
    cout << "Enter new title: ";
    cin >> title;
    Movie *movie = movieByTitle(title);
    return movie;
}

void searchMovie(string action){
    Movie *movie;
    cout << "Enter how do you want to conduct the search\n";
    cout << "1. By number (ID)\n";
    cout << "2. By Title \n";
    int answer = checkInt(1, 2);
    if (answer == 1){
        cout << "Enter number of movie (1-651): ";
        int numberID = checkInt(1, 651);
        string movieID = "movie_" + to_string(numberID);
        movie = movieByID(movieID);
    } else{
        string title;
        cout << "Enter title: ";
        cin >> title;
        movie = movieByTitle(title);
    }
    if(action == "watch"){
        movie->play();
        currentUser.addMovie(movie->getVideoID());
    } else{
        movie->printProduct();
        currentUser.addWishMovie(movie->getVideoID());
    }
}

void movieQuestion(){
    cout << "What do you want to do next?\n";
    cout << " 1. Watch a movie\n";
    cout << " 2. Add movie to your wish list\n";
    cout << " 3. Return to movie menu\n";
    int answer = checkInt(1,3);
    if(answer == 1){
        searchMovie("watch");
    } else if(answer == 2){
        searchMovie("wishlist");
    } else{
        cout << "Returning to main menu now..\n";
    }
}

// <---------------------Series--------------------->
// Series Funcionts
void listSeries(){
    cout << "Do you want to see the entire description or solely de title?\n";
    cout << "1. Title Only\n";
    cout << "2. Entire descrption\n";
    int answer = checkInt(1, 2);
    if(answer == 1){
        for(int count = numMovies; count < (numMovies+numSeries); count++){
            cout << products[count]->getID() << " - " << products[count]->getName() << "\n";
        }
    } else{
        for(int count = numMovies; count < (numMovies+numSeries); count++){
            Series *series = (Series *)(products[count]);
            series->printProduct();
        }
    }
}

void seriesGenre(){
    string genre;
    int countSeries;
    cout << "Enter the genre you want to look for: ";
    cin >> genre;
    for(int count = numMovies; count < numProducts; count++){
        if(products[count]->getGenre() == genre){
            products[count]->printProduct();
            countSeries++;
        }
    }
    if(countSeries == 0){
        cout << "No series of " << genre << " where found..\n";
        cout << " 1. See list of genres\n";
        cout << " 2. Search for another genre\n";
        int answer = checkInt(1,2);
        if(answer == 1){
            listGenres();
        }
        seriesGenre();
    }
}

void seriesStudio(){
    string studio;
    int countSeries = 0;
    cout << "Enter the studio you want to look for: ";
    cin >> studio;
    for(int count = numMovies; count < numProducts; count++){
        if(products[count]->getStudio() == studio){
            products[count]->printProduct();
            countSeries++;
        }
    }
    if(countSeries == 0){
        cout << " No series produced by " << studio << " were found..\n ";
        cout << " 1. See list of studios\n";
        cout << " 2. Search for another studio\n";
        int answer = checkInt(1,2);
        if(answer == 1){
            listStudios();
        }
        seriesStudio();
    }
}

void seriesYear(){
    int countSeries = 0;
    cout << "Enter the year you want to look for (2007-2019): ";
    int year = checkInt(2007, 2019);
    for(int count = numMovies; count < numProducts; count++){
        if(products[count]->getYear() == year){
            products[count]->printProduct();
            countSeries++;
        }
    }
    if(countSeries == 0){
        cout << "No series from " << year << " where found.. try again!\n";
        cin >> year;
        seriesYear();
    }
}

void seriesRate(){
    cout << "Enter the minimum rating (0,5,0.5): ";
    float rate = checkFloat(1.0,5.0);
    cout << "Do you want to see the entire description or solely de title?\n";
    cout << "1. Title Only\n";
    cout << "2. Entire description\n";
    int answer = checkInt(1, 2);
    if (answer == 1){
        for(int count = numMovies; count < numProducts; count++){
            if(products[count]->getRate() >= rate){
                cout << "ID: " << products[count]->getID() << " - Title: " << products[count]->getName() << " - Rating: " << products[count]->getRate() << "\n";
            }
        }
    } else{
        for(int count = numMovies; count < numProducts; count++){
            if(products[count]->getRate() >= rate){
                products[count]->printProduct();
            }
        }
    }
}

void printSeason(Season season){
    cout << " Season: " << season.getSeasonID() << "\n";
    int countE = 0, count = numMovies;
    while(countE < season.getNumEpisodes()){
        Episode *episode = (Episode *)(videos[count]);
        if(episode->getSeasonID() == season.getSeasonID()){
            cout << " ----> " << episode->getTitle() << "\n";
            countE++;
        }
        count++;
    }
}

void printEpisodes(Series *series){
    int countS = 0, count = 0;
    while(countS < series->getNumSeasons()){
        if(seasons[count].getSeriesID() == series->getID()){
            printSeason(seasons[count]);
            countS++;
        }
        count++;
    }
}

Season seasonByID(string seasonID){
    for(int countS = 0; countS < numSeasons; countS++){
        if(seasons[countS].getSeasonID() == seasonID){
            return seasons[countS];
        }
    }
    Season season;
    return season;
}

Episode *episodeByID(string episodeID){
    Episode *episode;
    for(int count = numMovies; count < numVideos; count++){
        if(videos[count]->getVideoID() == episodeID){
            episode = (Episode *)(videos[count]);
            return episode;
        }
    }
    return episode;
}

Episode *getEpisode(Series *series, int episodeNum){
    string episodeID = series->getID() + "_season";
    int episodesInSeason= series->getNumEpisodes()/series->getNumSeasons();
    int seasonN = (episodeNum / episodesInSeason) + 1;
    int episodeN = episodeNum % episodesInSeason;
    if(episodeN == 0){
        episodeN = episodesInSeason;
        seasonN--;
    }
    if(seasonN > series->getNumSeasons()){
        seasonN--;
        episodeN += episodesInSeason;
    }
    episodeID += (to_string(seasonN) + "_episode" + to_string(episodeN));
    Episode *episode = episodeByID(episodeID);
    return episode;
}

void printSeries(Series *series){
    series->printProduct();
    cout << "Do you want to sea all the episodes or those of a specific season?\n";
    cout << "1. All episodes\n";
    cout << "2. Specific season\n";
    int answer = checkInt(1, 2);
    if(answer == 1){
        printEpisodes(series);
    } else{
        string seasonID = series->getID();
        cout << "Enter number of Season: ";
        int seasonNumber = checkInt(1, series->getNumSeasons());
        seasonID += "_season" + to_string(seasonNumber);
        Season season = seasonByID(seasonID);
        printSeason(season);
    }
}

void playEpisode(Series *series, int episodeNum){
    currentUser.addSeries(series->getID());
    int max = series->getNumEpisodes();
    int answer = 1;
    while(episodeNum <= max &&  answer == 1){
        Episode *episode = getEpisode(series, episodeNum);
        episode->printVideo();
        episode->play();
        currentUser.addEpisode(episodeNum, series->getID());
        cout << "Do you want to play the next episode?\n";
        cout << " 1. Yes!\n";
        cout << " 2. No!\n";
        answer = checkInt(1,2);
        if(answer == 1){
            episodeNum++;
        }
    }
    cout << episodeNum << endl;
    if(episodeNum > max){
        cout << "You have finished the series..\n\n";
        currentUser.addEpisode(0, series->getID());
    } else{
        cout << "You are now being redirected to the series menu..\n\n";
    }
    

}

void watchSeries(Series *series){
    int numEpisode;
    series->printProduct();
    cout << "Which episode do you want to watch?\n";
    cout << " 1. From the beginning\n";
    cout << " 2. Continue watching next episode\n";
    cout << " 3. A specific episode\n";
    cout << " 4. Exit Series\n";
    int answer = checkInt(1, 4);
    if(answer == 1){
        numEpisode = 1;
    } else if(answer == 2){
        numEpisode = currentUser.getEpisode(series->getID()) + 1;
    } else if(answer == 3){
        cout << "Enter number of episode: ";
        numEpisode = checkInt(1, series->getNumEpisodes());
    }
    if(answer != 4){
        playEpisode(series, numEpisode);
    }
}

// Series Query
Series *seriesByID(string seriesID){
    for(int countS = numMovies; countS < numProducts; countS++){
        if(products[countS]->getID() == seriesID){
            Series *series = (Series *)(products[countS]);
            return series;
        }
    }
    Series *series;
    return series;
}

Series *seriesByTitle(string title){
    for(int countS = numMovies; countS < numProducts; countS++){
        if(products[countS]->getName() == title){
            Series *series = (Series *)(products[countS]);
            return series;
        }
    }
    cout << "Such title does not exist..";
    cout << "Do you want to sea the list of series?\n";
    cout << "1. Yes\n";
    cout << "2. Search for another title\n";
    int answer = checkInt(1,2);
    if(answer == 1){
        listSeries();
    }
    cout << "Enter new title: ";
    cin >> title;
    Series *series = seriesByTitle(title);
    return series;
}

void searchSeries(string action){
    Series *series;
    cout << "Enter how do you want to conduct the search\n";
    cout << "1. By number (ID)\n";
    cout << "2. By Title (lower-case)\n";
    int answer = checkInt(1,2);
    if (answer == 1){
        cout << "Enter number of series (1-1000): ";
        int numberID = checkInt(1, 1000);
        string seriesID = "series_" + to_string(numberID);
        series = seriesByID(seriesID);
    } else{
        string title;
        cout << "Enter title: ";
        cin >> title;
        series = seriesByTitle(title);
    }
    if(action == "print"){
        printSeries(series);
    } else if(action == "watch"){
        watchSeries(series);
    } else if(action == "wishlist"){
        currentUser.addWishSeries(series->getID());
    }
}


// <---------------------Videos--------------------->
// videos funcionts
void videosRate(){
    cout << "Enter the minimum rating (1,5,0.5): ";
    float rate =  checkFloat(1.0,5.0);
    cout << "Do you want to see the entire description or solely de title?\n";
    cout << "1. Title Only\n";
    cout << "2. Entire description\n";
    int answer = checkInt(1, 2);
    if (answer == 1){
        for(int count = 0; count < numVideos; count++){
            if(videos[count]->getVideoRating() >= rate){
                videos[count]->shortPrint();
            }
        }
    } else{
        for(int count = 0; count < numVideos; count++){
            if(videos[count]->getVideoRating() >= rate){
                videos[count]->printVideo();
            }
        }
    }
}

void videosGenre(){
    string genre;
    int countGenre = 0;
    cout << "Enter the genre you want to look for: ";
    cin >> genre;
    cout << "Do you want to see the entire description or solely de title?\n";
    cout << "1. Title Only\n";
    cout << "2. Entire description\n";
    int answer = checkInt(1, 2);
    if(answer == 1){
        for(int count = 0; count < numVideos; count++){
            if(videos[count]->getGenre() == genre){
                videos[count]->shortPrint();
                countGenre++;
            }
        }
    } else{
        for(int count = 0; count < numVideos; count++){
            if(videos[count]->getGenre() == genre){
                videos[count]->printVideo();
                countGenre++;
            }
        }
    }
    if(countGenre == 0){
        cout << "No videos of " << genre << " where found..\n";
        cout << " 1. See list of genres\n";
        cout << " 2. Search for another genre\n";
        int answer = checkInt(1,2);
        if(answer == 1){
            listGenres();
        }
        videosGenre();}
}

// <---------------------User Functions--------------------->
// Movie related
void recentlyWatchedMovies(){
    string listMovies[100];
    currentUser.getMovies(listMovies);
    cout << "------------>  Hi " << currentUser.getUsername() << "! here are the movies that you have recently watched..\n";
    for(int count = 0; count < currentUser.getNumMovies(); count++){
        Movie *movie = movieByID(listMovies[count]);
        movie->printVideo();
    }
}

void viewWishListMovies(){
    string listMovies[100];
    currentUser.getWishMovies(listMovies);
    cout << "------------>  Hi " << currentUser.getUsername() << "! here are the movies in your wish list!\n";
    for(int count = 0; count < currentUser.getNumWishMovies(); count++){
        Movie *movie = movieByID(listMovies[count]);
        movie->printVideo();
    }
}

// Users related
void recentlyWatchedSeries(){
    string listSeries[100];
    currentUser.getSeries(listSeries);
    cout << "------------>  Hi " << currentUser.getUsername() << "! here are the series that you have recently watched..\n";
    for(int count = 0; count < currentUser.getNumSeries(); count++){
        Series *series = seriesByID(listSeries[count]);
        series->printProduct();
    }
}

void viewWishListSeries(){
    string listSeries[100];
    currentUser.getWishSeries(listSeries);
    cout << "------------>  Hi " << currentUser.getUsername() << "! here are the series in your wish list!\n";
    for(int count = 0; count < currentUser.getNumWishSeries(); count++){
        Series *series = seriesByID(listSeries[count]);
        series->printProduct();
    }
}

// <---------------------Menus--------------------->
int mainMenu(){
    cout << "\n\n\n<-------Welcome to the Main Menu------->\n";
    cout << " Enter the number of the option you prefer\n";
    cout << " 1. Movies Menu\n";
    cout << " 2. Series Menu\n";
    cout << " 3. Videos Menu\n";
    cout << " 0. To exit\n";
    int answer = checkInt(0,3);
    return answer;
}

void movieMenu(){
    cout << "\n\n\n<-------Welcome " << currentUser.getUsername() << " to the Movie Menu------->\n";
    cout << " Enter the number of the option you prefer\n";
    cout << " 1. List of movies\n";
    cout << " 2. Movies with a certain rate\n";
    cout << " 3. Movies with a certain genre\n";
    cout << " 4. Movies from a certain year\n";
    cout << " 5. Movies from a certain studio\n";
    cout << " 6. Nominated movies\n";
    cout << " 7. Winner of Oscar movies\n";
    cout << " 8. Actor won the Oscar\n";
    cout << " 9. Actress won the Oscar\n";
    cout << " 10. Director won the Oscar\n";
    cout << " 11. Movie made the Top200 list\n";
    cout << " 12. Watch a movie\n";
    cout << " 13. Add movie to wish list\n";
    cout << " 14. Recently watched movies\n";
    cout << " 15. View Movies Wish List\n";
    cout << " 0. To exit\n";
    int answer = checkInt(0,15);
    switch (answer){
        case 1:
            listMovies();
            break;
        case 2:
            movieRate();
            break;
        case 3:
            movieGenre();
            break;
        case 4:
            movieYear();
            break;
        case 5:
            movieStudio();
            break;
        case 6:
            movieNominee();
            break;
        case 7:
            movieWinner();
            break;
        case 8:
            movieActor();
            break;
        case 9:
            movieActress();
            break;
        case 10:
            movieDirector();
            break;
        case 11:
            movieTop();
            break;
        case 12:
            searchMovie("watch");
            break;
        case 13:
            searchMovie("wishlist");
            break;
        case 14:
            recentlyWatchedMovies();
            break;
        case 15:
            viewWishListMovies();
            break;
        case 0:
            cout << "You will now exit the movie menu!\n\n";
            break;
        default:
            cout << "Enter a valid answer!\n";
            break;
    }
    if(answer != 0){
        movieQuestion();
        movieMenu();
    }
}

void seriesMenu(){
    cout << "\n\n\n<-------Welcome to the Series Menu------->\n";
    cout << " Enter the number of the option you prefer\n";
    cout << " 1. List of series\n";
    cout << " 2. Episodes of a certain series\n";
    cout << " 3. Series with a certain genre\n";
    cout << " 4. Series with a certain year\n";
    cout << " 5. Series with a certain studio\n";
    cout << " 6. Series with a certain rate\n";
    cout << " 7. Watch a series\n";
    cout << " 8. Add series to wishlist\n";
    cout << " 9. Recently watched series\n";
    cout << " 10. View Series Wish List\n";
    cout << " 0. To exit\n";
    int answer = checkInt(0,10);
    switch (answer){
        case 1:
            listSeries();
            break;
        case 2:
            searchSeries("print");
            break;
        case 3:
            seriesGenre();
            break;
        case 4:
            seriesYear();
            break;
        case 5:
            seriesStudio();
            break;
        case 6:
            seriesRate();
            break;
        case 7:
            searchSeries("watch");
            break;
        case 8:
            searchSeries("wishlist");
            break;
        case 9:
            recentlyWatchedSeries();
            break;
        case 10:
            viewWishListSeries();
            break;
        case 0:
            cout << "You will now exit the series menu!\n\n";
            break;
        default:
            cout << "Enter a valid answer!\n";
            break;
    }
    if(answer != 0){
        seriesMenu();
    }
}

void videoMenu(){
    cout << "\n\n\n<-------Welcome to the Video Menu------->\n";
    cout << " Enter the number of the option you prefer\n";
    cout << " 1. Videos with a certain rate\n";
    cout << " 2. Videos  with a certain genre\n";
    cout << " 0. To exit\n";
    int answer = checkInt(0,2);
    switch (answer){
        case 1:
            videosRate();
            break;
        case 2:
            videosGenre();
            break;
        case 0:
            cout << "You will now exit the video menu!\n\n";
            break;
        default:
            cout << "Enter a valid answer!\n";
            break;
    }
    if(answer != 0){
        videoMenu();
    }
}


// Series related

// <---------------------User Login--------------------->
User createLogin(string username, string password){
    for(int count = 0; count < numUsers; count++){
        if(users[count].getUsername() == username){
            cout << "Username already exists.. please enter a new one: ";
            cin >> username;
            count = 0;
        }
    }
    users[numUsers].setUsername(username);
    users[numUsers].setPassword(password);
    numUsers++;
    return users[numUsers-1];
}

User checkLogin(string username, string password){
    for(int count = 0; count < numUsers; count++){
        if(users[count].getUsername() == username){
            if(users[count].getPassword() == password){
                return users[count];
            } else{
                while(users[count].getPassword() != password){
                    cout << "Incorrect password.. try again: ";
                    cin >> password;
                }
                return users[count];
            }
        }
    }
    int answer;
    cout << "It appears the username does not exist..\n";
    cout << "Do you want to create a new user or enter another username: \n";
    cout << " 1. Create new user\n";
    cout << " 2. Enter another username\n";
    if(answer == 1){
        User user = createLogin(username, password);
        return user;
    } else{
        cout << "Enter new username: ";
        cin >> username;
        User user = checkLogin(username, password);
    }
    User user;
    return user;
}

User login(){
    string username, password;
    cout << "Do you want to login or create a new user?\n";
    cout << " 1. Login\n";
    cout << " 2. Create user\n";
    int answer = checkInt(1,2);
    if(answer == 1){
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;
        User user = checkLogin(username, password);
        return user;
    } else{
        string confirPassowrd;
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;
        cout << "Confirm password: ";
        cin >> confirPassowrd;
        while(confirPassowrd != password){
            cout << "Passwords do not match..\n";
            cout << "Enter again password: ";
            cin >> confirPassowrd;
        }
        User user = createLogin(username, password);
        return user;
    }
    User user;
    return user;
}

int getUser(string username){
    for(int count = 0; count < numUsers; count++){
        if(users[count].getUsername() == username){
            return count;
        }
    }
    return 0;
}

// Update data files
bool is_emptyy(ifstream& pFile){
    return pFile.peek() == ifstream::traits_type::eof();
}

void loadData(){
    string username, movieID, seriesID;
    int episodeNum;
    int user;
    ifstream watchedMovies;
    watchedMovies.open("watched_movies.txt");
    if (!is_emptyy(watchedMovies)){
        while(watchedMovies >> username >> movieID){
            user = getUser(username);
            users[user].addMovie(movieID);
        }
    } else{
        cout << "watched movies is empty\n";
    } 
    watchedMovies.close();
    
    ifstream wishlistMovies;
    wishlistMovies.open("wishlist_movies.txt");
    if (!is_emptyy(wishlistMovies)){
        while(wishlistMovies >> username >> movieID){
            user = getUser(username);
            users[user].addWishMovie(movieID);
        }
    } else{
        cout << "wishlist movies is empty\n";
    }
    wishlistMovies.close();

    ifstream watchedSeries;
    watchedSeries.open("watched_series.txt");
    if (!is_emptyy(watchedSeries)){
        while(watchedSeries >> username >> seriesID >> episodeNum){
            user = getUser(username);
            users[user].addSeries(seriesID);
            users[user].addEpisode(episodeNum, seriesID);
        }
    } else{
        cout << "watched series is empty\n";
    }
    watchedSeries.close();

    ifstream wishlistSeries;
    wishlistSeries.open("wishlist_series.txt");
    if (!is_emptyy(wishlistSeries)){
        while(wishlistSeries >> username >> seriesID){
            user = getUser(username);
            users[user].addWishSeries(seriesID);
        }
    } else{
        cout << "wishlist series is empty\n";
    }
    wishlistSeries.close();
}

void updateData(){
    ofstream usersFile;
    usersFile.open("users.txt");
    for(int count = 0; count < numUsers; count++){
        usersFile << users[count].getUsername() << "\t" << users[count].getPassword() << endl;
    }
    usersFile.close();

    ofstream wacthedMovies;
    wacthedMovies.open("watched_movies.txt");
    for(int countU = 0; countU < numUsers; countU++){
        string movies[100];
        if(users[countU].getUsername() == currentUser.getUsername()){
            currentUser.getMovies(movies);
            for(int countM = 0; countM < currentUser.getNumMovies(); countM++){
                wacthedMovies << currentUser.getUsername() << "\t" << movies[countM] << endl;
            }
        } else{
            users[countU].getMovies(movies);
            for(int countM = 0; countM < users[countU].getNumMovies(); countM++){
                wacthedMovies << users[countU].getUsername() << "\t" << movies[countM] << endl;
            }
        }
    }
    wacthedMovies.close();

    ofstream wishlistMovies;
    wishlistMovies.open("wishlist_movies.txt");
    for(int countU = 0; countU < numUsers; countU++){
        string wishMovies[100];
        if(users[countU].getUsername() == currentUser.getUsername()){
            currentUser.getWishMovies(wishMovies);
            for(int countM = 0; countM < currentUser.getNumWishMovies(); countM++){
                wishlistMovies << currentUser.getUsername() << "\t" << wishMovies[countM] << endl;
            }
        } else{
            users[countU].getWishMovies(wishMovies);
            for(int countM = 0; countM < users[countU].getNumWishMovies(); countM++){
                wishlistMovies << users[countU].getUsername() << "\t" << wishMovies[countM] << endl;
            }
        }
    }
    wishlistMovies.close();

    ofstream wacthedSeries;
    wacthedSeries.open("watched_series.txt");
    for(int countU = 0; countU < numUsers; countU++){
        string series[100];
        if(users[countU].getUsername() == currentUser.getUsername()){
            currentUser.getSeries(series);
            for(int countM = 0; countM < currentUser.getNumSeries(); countM++){
                wacthedSeries << currentUser.getUsername() << "\t" << series[countM] << "\t" << currentUser.getEpisode(series[countM]) << endl;
            }
        } else{
            users[countU].getSeries(series);
            for(int countM = 0; countM < users[countU].getNumSeries(); countM++){
                wacthedSeries << users[countU].getUsername() << "\t" << series[countM] << "\t" << users[countU].getEpisode(series[countM]) << endl;
            }
        }
    }
    wacthedSeries.close();

    ofstream wishlistSeries;
    wishlistSeries.open("wishlist_series.txt");
    for(int countU = 0; countU < numUsers; countU++){
        string wishSeries[100];
        if(users[countU].getUsername() == currentUser.getUsername()){
            currentUser.getWishSeries(wishSeries);
            for(int countM = 0; countM < currentUser.getNumWishSeries(); countM++){
                wishlistSeries << currentUser.getUsername() << "\t" << wishSeries[countM] << endl;
            }
        } else{
            users[countU].getWishSeries(wishSeries);
            for(int countM = 0; countM < users[countU].getNumWishSeries(); countM++){
                wishlistSeries << users[countU].getUsername() << "\t" << wishSeries[countM] << endl;
            }
        }
    }
    wishlistSeries.close();
}
// <---------------------Main--------------------->
int main(){
    creatObjects();
    cout << "\n\n\n<-----------Welcome to Netflix 2.0--------->\n\n\n";
    loadData();
    currentUser = login();
    cout << "Welcome " << currentUser.getUsername() << " we hope you enjoy our streaming service!\n\n\n";
    int answer = mainMenu();
    while (answer != 0){
        switch (answer){
            case 1:
                movieMenu();
                break;
            case 2:
                seriesMenu();
                break;
            case 3:
                videoMenu();
                break;
            case 0:
                break;
            default:
                cout << "Enter a valid answer!\n";
                break;
        }
        answer = mainMenu();
    }
    updateData();
    cout << "Thanks for using our system!\n\n";
    return 0;
}