#include <iostream>

using namespace std;

class Student {
public:
    //Властивості
    string name;
    int age;
    //Метод
    void sayHi() {
        cout << "Hello? my name is" << name;
    }
};


Student olderStudent(Student newList[], int size) {
    Student oldest = newList[0];
    
    for (int i = 1; i < size; i++) {
        if (newList[i].age > oldest.age) {
            oldest = newList[i];
        }
    }
    
    return oldest;
}

int main() {
    Student newList[3]{ {"Vlad",18},
                       {"Maxim",16},
                       {"Oleg",20} };
    Student oldestStudent = olderStudent(newList, 3);
    
    cout << "Найстарший: " << oldestStudent.name << endl;
    
}

