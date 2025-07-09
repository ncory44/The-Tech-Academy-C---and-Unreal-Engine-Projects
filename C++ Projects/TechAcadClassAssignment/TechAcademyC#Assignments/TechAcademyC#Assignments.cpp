#include <iostream>
#include <cmath> // M_PI
#ifndef M_PI
#define M_PI 3.1415926535
#endif // !M_PI


using namespace std;


class Shape {
public:
    string color;


    virtual double getArea() const {
        return 0.0;
    }

    void setColor(const string& c) {
        color = c;
    }

    void displayColor() const {
        cout << "Color: " << color << endl;
    }
};

// rectangle subclass
class Rectangle : public Shape {
public:
    double height;
    double width;

    Rectangle(double h, double w, string c) {
        height = h;
        width = w;
        color = c;
    }

    double getArea() const override {
        return height * width;
    }
};

// triangle subclass
class Triangle : public Shape {
public:
    double base;
    double height;

    Triangle(double b, double h, string c) {
        base = b;
        height = h;
        color = c;
    }

    double getArea() const override {
        return 0.5 * base * height;
    }
};

// circle subclass
class Circle : public Shape {
public:
    double radius;

    Circle(double r, string c) {
        radius = r;
        color = c;
    }

    double getArea() const override {
        return M_PI * radius * radius;
    }
};

// tests class
int main() {
    Rectangle rect(5, 3, "Red");
    Triangle tri(4, 6, "Blue");
    Circle circ(2.5, "Green");

    cout << "Rectangle - ";
    rect.displayColor();
    cout << "Area: " << rect.getArea() << endl << endl;

    cout << "Triangle - ";
    tri.displayColor();
    cout << "Area: " << tri.getArea() << endl << endl;

    cout << "Circle - ";
    circ.displayColor();
    cout << "Area: " << circ.getArea() << endl;

    return 0;
}
