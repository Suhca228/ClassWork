#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Point {
public:  
    static vector<Point> system;

private:
    double x = 0, y = 0;

public:
    Point() {}

    Point(double x, double y) {
        this->x = x;
        this->y = y;
    }

    void showCoords() {
        cout << "x: " << this->x << endl;
        cout << "y: " << this->y << endl;
    }

    double getX() { return this->x; }

    double getY() { return this->y; }

    double Distance(Point p) {
        double newx = p.getX() - this->x;
        double newY = p.getY() - this->y;
        return sqrt((newx * newx) + (newY * newY));
    }

    void createCenter(Point p) {t
        double centerX = (this->x + p.getX()) / 2;
        double centerY = (this->y + p.getY()) / 2;

        Point centerPoint(centerX, centerY);

        Point::system.push_back(centerPoint);
    }
};

vector<Point> Point::system = {{0.0, 0.0}, {10.0, 7.0}};

int main() {
    Point point1(10.0, 10.0);
    Point point2(20.0, 20.0);

    point1.showCoords();
    point2.showCoords();

    double distance = point1.Distance(point2);
    cout << "The distance between the two points is " << distance << endl;

    point1.createCenter(point2);

    Point::system[Point::system.size() - 1].showCoords();

}
