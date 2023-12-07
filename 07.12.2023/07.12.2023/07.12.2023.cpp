#include <iostream>
#include <vector>

using namespace std;

class Point {
private:
	int x = 0,
		y = 0;
public:
	Point() {

	}
	Point(double x, double y) {
		this->x = x;
		this->y = y;
	}
    void showCoords() {
        cout << "x: " << this->x << endl;
        cout << "y: " << this->y << "\n" << endl;
    }
    double getX() { return this->x; }
    double getY() { return this->y; }
    double Distance(Point p) {
        double newx = this->x - p.getX();
        double newy = this->y - p.getY();
        return sqrt(newx * newx + newy * newy);
    }
    double createCentral(Point p) {
        double centralX = (this->x + p.getX()) / 2.0;
        double centralY = (this->y + p.getY()) / 2.0;


    }


};

int main() {
    vector<Point> system = {{0.0,0.0},
                            {10.0,7.0},}; 
    cout << system[0].Distance(system[1]) << endl;
    system.push_back(point)

}
   
