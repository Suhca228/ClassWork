#include <iostream>
#include <cmath>
using namespace std;
class Point {
public:
    int x;
    int y;
    int thickness = 1;
    string color;
    Point(int x = 4, int y = 0) {
        this->x = x;
        this->y = y;
        this->color = "black";
    }
};



class Line : public Point {
public:
    Point p1;
    Point p2;
    double dowjina;
    Line(Point p1, Point p2) : p1(p1), p2(p2) {
        calculatedowjina();


    }
private:
    void calculatedowjina() {
        int storonaX = p2.x - p1.x;
        int storonaY = p2.y - p1.y;
        dowjina = sqrt(storonaX * storonaX + storonaY * storonaY);
    }

};



int main()
{
    Point p1(50, 60);
    Point p2(30, 40);
    Line line(p1, p2);
    cout << line.dowjina;


}