#include <iostream>
#include <string>

using namespace std;

const int DAYS = 31;
const int MONTHS = 12;
const int MINUTES = 60;

class Entry {
private:
    string title;
    string description;
public:
    Entry(){

    }
};

class Time{
private:
    int hours;
    int minutes;
    string putPutTime;
public:
    Time(int hiours, itn minutes){
        if (hours >= 0 && hours <= 24){
            this->hours = hours;
        }
        if (minutes >= 0 && minutes <= 24){
            this->minutes = minutes;
        }
    }

}

class Month {
private:
    string listname[12] = {"January","February","March","April","May","June","July","August","September","October","November","December"};

public:
    string name;
    Month(int number = 0) {
        this->name = listname[number];
    }
    string getName(int number = 0){
        cout << this->listname[number];
    }
};


class Year {
private:
    int year;
    Month months[MONTHS];
public:
    Year(int year = 1939) {
        this->year = year;
        for (int i = 0;i < 12; i++){
            this->months[i]= i;
        }
    }
    int setYear(int year){
        this->year = year;
    }
    int getYear(){
        return this->year;
    }
    string getmonth(int number){
        return this->months->name;
    }
};

class Book {
private:
    Year year; 
public:
    void create(int year) {
        this->year = year;
    }
    void showInfo(){
        cout << this->year.getYear();
    }
};

int main() {
    Book myBook;

}

