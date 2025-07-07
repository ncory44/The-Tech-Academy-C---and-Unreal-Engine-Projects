#include <iostream>
#include <string>
using namespace std;

class Dog {
public:
    string breed;
    string color;
    float height;     // feet
    float weight;     // pounds


    void shake() {
        cout << "The dog shakes your hand." << endl;
    }

    void sit() {
        cout << "The dog sits down." << endl;
    }

    void layDown() {
        cout << "The dog lays down." << endl;
    }

    // dog info
    void displayInfo() {
        cout << "Breed: " << breed << endl;
        cout << "Color: " << color << endl;
        cout << "Height: " << height << " feet" << endl;
        cout << "Weight: " << weight << " pounds" << endl;
    }
};

int main() {
    Dog myDog;

    myDog.breed = "Hound";
    myDog.color = "Brown";
    myDog.height = 2.0;
    myDog.weight = 60.0;

    myDog.displayInfo();

    myDog.shake();
    myDog.sit();
    myDog.layDown();

    return 0;
}
