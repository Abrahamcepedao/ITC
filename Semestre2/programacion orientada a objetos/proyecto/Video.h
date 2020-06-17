#include <iostream>
#include <string>
#ifndef Video_h
#define Video_h
using namespace std;
class Video{
    protected:
        string videoID;
        string title;
        string videoGenre;
        int runtime; 
        float videoRating;
    public:
        Video();
        Video(string, string, string, int, float);

        string getVideoID(){return videoID;};
        string getTitle(){return title;};
        string getGenre(){return videoGenre;};
        int getRuntime() { return runtime; };
        float getVideoRating() { return videoRating; };

        void setVideoID(string videoID){this->videoID = videoID;};
        void setTitle(string title){this->title = title;};
        void setGenre(string videoGenre){this->videoGenre = videoGenre;};
        void setRuntime(int runtime) { this->runtime = runtime; };
        void setVideoRating(float videoRating) { this->videoRating = videoRating; };

        virtual void printVideo() = 0;
        virtual void shortPrint() = 0;
        virtual void play() = 0;
};
// constructors
Video::Video(){
    videoID = "";
    title = "-";
    videoGenre = "-";
    runtime = 0;
    videoRating = 1;
}
Video::Video(string videoID, string title, string videoGenre, int runtime, float videoRating){
    this->videoID = videoID;
    this->title = title;
    this->videoGenre = videoGenre;
    this->runtime = runtime;
    this->videoRating = videoRating;
}
#endif