// Abraham Cepeda
// A00827666
// Class date
#include <iostream>
using namespace std;
int arrayDiasMes[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
class Date {
private:
    int year;
    int month;
    int day;
    int hour;
    int minute;
public:
    Date();
    Date(int yr, int mh, int d, int h, int min);

    int getYear();
    int getMonth();
    int getDay();
    int getHour();
    int getMinute();

    void setYear(int yr);
    void setMonth(int mh);
    void setDay(int d);
    void setHour(int h);
    void setMinute(int min);
    void setDate();

    Date checkDate(int yr, int mh, int d, int h, int min);
    void printDate();
};


// constructors
Date::Date(){
    year = 2019;
    month = 12;
    day = 1;
    hour = 7;
    minute = 0;
}
Date::Date(int yr, int mh, int d, int h, int min){
    year = yr;
    month = mh;
    day = d;
    hour = h;
    minute = min;
}

// get methods
int Date::getYear(){
    return year;
}
int Date::getMonth(){
    return month;
}
int Date::getDay(){
    return day;
}
int Date::getHour(){
    return hour;
}
int Date::getMinute(){
    return minute;
}

// set methods
void Date::setYear(int yr){
    year = yr;
}
void Date::setMonth(int mh){
    month = mh;
}
void Date::setDay(int d){
    day = d;
}
void Date::setHour(int h){
    hour = h;
}
void Date::setMinute(int min){
    minute = min;
}


// change date method
Date Date::checkDate(int yr, int mh, int d, int h, int min){
    bool okey = false;
    while(yr < 2019){
        cout << "Enter valid year: ";
        cin >> yr;
    }
    while (mh < 1 || mh > 12){
        cout << "Enter valid month: ";
        cin >> mh;
    }
    while (arrayDiasMes[mh - 1] < d || d < 1){
        cout << "Enter valid day: ";
        cin >> d;
    }
    while (h < 7 || h > 22){
        cout << "Enter valid hour: ";
        cin >> h;
    }
    while (min != 0 && min != 30){
        cout << "Enter valid min: ";
        cin >> min;
    }
    Date date = Date(yr, mh, d, h, min);
    return date;
}

// sate date method
void Date::setDate(){
    int yr;
    int mh;
    int dy;
    int hr;
    int min;
    cout << "Enter date data\n";
    cout << "Year: ";
    cin >> yr;
    cout << "Month: ";
    cin >> mh;
    cout << "Day: ";
    cin >> dy;
    cout << "Hour: ";
    cin >> hr;
    cout << "Minute: ";
    cin >> min;
    Date date = checkDate(yr, mh, dy, hr, min);
    year = date.getYear();
    month = date.getMonth();
    day = date.getDay();
    hour = date.getHour();
    minute = date.getMinute();
}

// print date method
void Date::printDate(){
    if(minute == 0){
        cout << "\n" << day << "/" << month << "/" << year << "----" << hour << ":" << minute << "0" << "\n\n";
    } else{
        cout << "\n" << day << "/" << month << "/" << year << "----" << hour << ":" << minute << "\n\n";
    }
}

