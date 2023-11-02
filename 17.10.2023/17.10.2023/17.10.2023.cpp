#include <iostream>

using namespace std;

class Figure {
protected:
	char* line;
	char** box;
	char** tank;
	char** lighthing;
	char** udg;
public:
	string type;
	char symbol;
	Figure(string type, char symbol) {
		this->symbol = symbol;
		if (type == "line") { //|| type == "tank" || type == "lightning" || type == "UDG" || type == "box") {
			this->type = type;
			this->line = new char[4];
			for (int i = 0; i < 4; i++) {
				this->line[i] = this->symbol;
			}
			delete[] box, lighthing, tank, udg;
		}
		else if (type == "box") {
			this->type = type;
			this->box = new char* [2];
			for (int i = 0; i < 2; i++) {
				this->box[i] = new char[2];
				for (int j = 0; j < 2; j++) {
					this->box[i][j] = symbol;
				}
			}
			delete[] line, lighthing, tank, udg;
		}
		else if (type == "tank") {
			this->type = type;
			this->tank = new char* [3];
			for (int i = 0; i < 3; i++) {
				this->tank[i] = new char[3];
				for (int j = 0; j < 3; j++) {
					this->tank[i][j] = symbol;
				}
			}
			delete[] box, line, tank, udg;
		}
		else if (type == "lighthing") {
			this->type = type;
			this->lighthing = new char* [2];
			for (int i = 0; i < 2; i++) {
				this->lighthing[i] = new char[3];
				for (int j = 0; j < 3; j++) {
					this->lighthing[i][j] = symbol;
				}
			}
			this->lighthing[0][1] = ' ';
			this->lighthing[2][0] = ' ';

			delete[] tank, box, line, udg;
		}
		else if (type == "udg") {
			this->type = type;
			this->udg = new char* [2];
			for (int i = 0; i < 2; i++) {
				this->udg[i] = new char[3];
				for (int j = 0; j < 3; j++) {
					this->udg[i][j] = symbol;
				}
			}
			this->udg[0][1] = ' ';
			this->udg[1][1] = ' ';

			delete[] tank, box, line;
		}

		else { this->type = "error"; }
	}
};
class Field {
public:
	char** array = new char* [10];
	Field() {
		for (int i = 0; i < 10; i++) {
			this->array[i] = new char[10];
			for (int j = 0; j < 10; j++) {
				this->array[i][j] = ' ';
			}
		}
	}
	void addFigure(Figure figure) {
		int x = rand() % 10,
			y = rand() % 10;
		//cout << "\n" << "Random X = " << x << endl;
		bool write = false;

		if (this->array[x][y] == ' ') {
			// << "stage 1 is OK" << endl;
			if (figure.type == "line") {
				//cout << "stage 2 is OK" << endl;
				if (x < 7) {
					//cout << "stage 3 is OK" << endl;
					for (int i = x; i < x + 4; i++) {
						if (this->array[y][i] == ' ') {
							write = true;
						}
						else {
							write = false;
							break;
						}
					}
					//cout << "stage 4 is OK" << endl;
					if (write == true) {
						//cout << "stage 5 is OK" << endl;
						for (int i = x; i < x + 4; i++) {
							this->array[y][i] = figure.symbol;
						}
						//cout << "stage 6 is OK" << endl;
					}
				}
			}
		}
	}
	void showField() {
		for (int i = 0; i < 30; i++) {
			cout << '-';
		}
		cout << endl;
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				cout << '|' << array[i][j] << '|';
			}
			cout << endl;
		}
		for (int i = 0; i < 30; i++) {
			cout << '-';
		}
	}
	void addChar(char symbol = '-', int x = 0, int y = 0, int iterator = 4, int start = 3) {
		for (int i = start; i < iterator + start; i++) {
			this->array[y][i] = symbol;
		}
	}
};

int main()
{
	srand(time(NULL));
	Field game;
	Figure first{ "line",'c' };
	game.showField();
	game.addFigure(first);
	cout << endl;
	game.showField();
}

//---------------------
//|s|c| | | | | | |o|o|
//|s|c|c| | | | | |o|o|
//|s|s|c| | | | | | | |
//| | | | | | |a|a|a|a|
//| | | | | | | | | | |
//| | | |n|n|n|n| | | |
//| | | | | | | | | | |
//| | | | |l|l| | |x| |
//| | | | |l|l| | |x|x|
//| | | | | | | | | |x|
//---------------------
//|0|1|2|3|4|5|6|7|8|9|



//
//if (this->array[x][y] == ' ') {
//	// << "stage 1 is OK" << endl;
//	if (figure.type == "line") {
//		//cout << "stage 2 is OK" << endl;
//		if (x < 7) {
//			//cout << "stage 3 is OK" << endl;
//			for (int i = x; i < x + 4; i++) {
//				if (this->array[y][i] == ' ') {
//					write = true;
//				}
//				else {
//					write = false;
//					break;
//				}
//			}
//			//cout << "stage 4 is OK" << endl;
//			if (write == true) {
//				//cout << "stage 5 is OK" << endl;
//				for (int i = x; i < x + 4; i++) {
//					this->array[y][i] = figure.symbol;
//				}
//				//cout << "stage 6 is OK" << endl;
//			}
//		}
//	}
//}
//	}