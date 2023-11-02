#include <iostream>



using namespace std;



class Player {
private:
    string name;
    int hp;
    float speed;
    float accuracy; //damage = speed * accuracy
public:
    Player(string name) {
        this->name = name;
        this->hp = 100;
        this->speed = this->hp / 10;
        this->accuracy = rand() % 3;
    }
    void newStep() { this->accuracy = rand() % 10; }
    void setHP(int hp) { this->hp = hp; }
    int damage() { return this->speed * this->accuracy; }
};



class Game {
    bool isStart = false;
    int round = 0;
    Player list[4] = { {"Max"},{"Yan"},{"Dima"},{"Oleg"} };
public:
    void Start() {
        if (isStart == false) { isStart = true; }
        this->nextRound();
    }
    void Finish() { if (isStart == true) { isStart = false; } }
    int getRound() {
        cout << this->round;
        return this->round;
    };
    void nextRound() {
        this->list[0].setHP(this->list[rand() % 3 + 1].damage());
    };
};



int main()
{
    Game first;
    first.Start();
}
