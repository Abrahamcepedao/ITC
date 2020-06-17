#include <iostream>
#include <string>
#ifndef Product_h
#define Product_h
using namespace std;
class Product{
    protected:
        string ID;
        string name;
        string genre;
        string ageClassification;
        string studio;
        float rate;
        int year;
    public:
        Product();
        Product(string, string, string, string, string, float, int);

        string getID(){return ID;};
        string getName(){return name;};
        string getGenre(){return genre;};
        string getAgeClassification(){return ageClassification;};
        string getStudio(){return studio;};
        float getRate() { return rate; };
        int getYear(){return year;};

        void setID(string ID){this->ID = ID;};
        void setName(string name){this->name = name;};
        void setGenre(string genre){this->genre = genre;};
        void setAgeClassification(string ageClassification){this->ageClassification = ageClassification;};
        void setStudio(string studio){this->studio = studio;};
        void setRate(float rate) { this->rate = rate; };
        void setYear(int year){this->year = year;};

        virtual void printProduct() = 0;
};
// constructors
Product::Product(){
    ID = "-";
    name = "-";
    genre = "unkown";
    ageClassification = "pg-12";
    studio = "";
    rate = 5;
    year = 2020;
}
Product::Product(string ID, string name, string genre, string ageClassification, string studio, float rate, int year){
    this->ID = ID;
    this->name = name;
    this->genre = genre;
    this->ageClassification = ageClassification;
    this->studio = studio;
    this->rate = rate;
    this->year = year;
}

//methods

#endif