#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
 
using namespace std;
 
class Person {
private :
	string name;
	int age;
public:
	/*Person(string n, int a) {
		this->name = n;
		this->age = a;
	}*/
	Person(string n, int a) : name(move(n)), age(a) {}
	string getName() const {return name;}
	int getAge() const {return age;}
};
 
class Town {
private:
	int floor;
	int apartments;
	int firstFloor;
public:
	Town(int f, int a) : floor(f), apartments(a), firstFloor(rand() % 2){}
	int getFloor() { return floor; }
	int getApartments() { return apartments; }
};
 
int main()
{
	vector <Person> group = {
		Person("Artur",13),
		Person("Vlad",28),
		Person("Maxim",14),
	};
 
	auto a = [](const Person& a, const Person& b) {return a.getAge() < b.getAge(); };
 
	sort(group.begin(), group.end(), a);
 
	for (const auto& i : group) {
		cout << i.getName() << "-" << i.getAge() << endl;
	}
}

