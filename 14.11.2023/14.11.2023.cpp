#include <iostream>
#include <string>

using namespace std;

const int DAYS = 31;
const int MONTHS = 12;
const int MINUTES = 60;

class Day {
private:
    int minutes[MINUTES];

public:
    Day() {
        for (int i = 0; i < MINUTES; ++i) {
            minutes[i] = i;
        }
    }
};

class Month {
private:
    Day days[DAYS];

public:
    Month() {
    }
};

class Year {
private:
    Month months[MONTHS];

public:
    Year() {
    }
};

class Book {
private:
    Year years[1]; 

public:
    Book() {
    }
};

int main() {
    Book myBook;

}
