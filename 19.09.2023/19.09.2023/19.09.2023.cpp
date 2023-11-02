#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include<windows.h>

using namespace std;


string nameList[] = {
            "Анна", "Борис", "Вікторія", "Григорій", "Дмитро", "Євгенія",
            "Жанна", "Ірина", "Костянтин", "Лариса", "Михайло",
            "Наталія", "Олександр", "Поліна", "Роман", "Світлана", "Тарас", };


class Student {
public:
    Student(const string& name) : name(name) {
        mathGrade = rand() % 101;
        physicsGrade = rand() % 101;
    }

    double getClassRaiting() const {
        return (mathGrade + physicsGrade) / 2.0;
    }
    string name = nameList[rand() % 16];
    int mathGrade;
    int physicsGrade;

};

class SchoolClass {
private:
    Student allStudents[26];
public:
    //SchoolClass() {
    //    for (char ch = 'A'; ch <= 'Z'; ch++) {
    //        string name = "Student ";
    //        name += ch;
    //        allStudents[ch - 'A'] = Student(name);
    //    }
    //}

    Student getBestStudent() const {
        Student bestStudent = allStudents[0];
        for (int i = 1; i < 26; i++) {
            if (allStudents[i].getClassRaiting() > bestStudent.getClassRaiting()) {
                bestStudent = allStudents[i];
            }
        }
        return bestStudent;
    }

    double getClassRaiting() const {
        double totalGrade = 0.0;
        for (int i = 0; i < 26; i++) {
            totalGrade += allStudents[i].getClassRaiting();
        }
        return totalGrade / 26.0;
    }


};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(static_cast<unsigned>(time(nullptr)));

    SchoolClass schoolClass;

    Student bestStudent = schoolClass.getBestStudent();
    cout << "Найкращий студент: " << bestStudent.getName() << endl;

    double classAverage = schoolClass.getClassRaiting();
    cout << "Середня оцінка класу: " << classAverage << endl;

}
