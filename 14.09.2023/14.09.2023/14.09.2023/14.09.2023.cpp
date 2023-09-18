#include<iostream>
#include<string>
#include<windows.h>

using namespace std;

class Image {

private:
    unsigned short int width;
    unsigned short int height;
    string name;
    string extension;
    unsigned short int imageWeightInByte;

public:
    string format;
    string comment;
    string tags[100];
    unsigned short int rating;

    Image(unsigned short int inputWidth = 1000, unsigned short int inputHeight = 1000) {
        width = inputWidth;
        height = inputHeight;
        format = "";
        comment = "";
        extension = ".jpg";
        name = "Image_01" + extension;
        rating = 0;
        imageWeightInByte = width * height * 3;
    }

    unsigned short int getWidth() const { return width; }
    unsigned short int getImageWeightInByte() const { return imageWeightInByte; }
    string getName() const { return name; }
    string getExtension() const { return extension; }

    void setName(const string& newName) {
        name = "";
        for (char c : newName) {
            if (!isdigit(c)) {
                name += c;
            }
        }
    }

    void setExtension(const string& newExtension) {
        if (newExtension == ".jpg" || newExtension == ".png" || newExtension == ".tiff") {
            extension = newExtension;
        }
        else {
            cout << "Неправильне розширення файлу. Допустимі розширення: .jpg, .png, .tiff." << endl;
        }
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Image first{ 640, 1280 };
    cout << "Початкове ім'я: " << first.getName() << endl;

    first.setName("Image_12345");
    cout << "Змінене ім'я: " << first.getName() << endl;

    first.setExtension(".png");
    cout << "Змінене розширення: " << first.getExtension() << endl;

}