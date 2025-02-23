#include <iostream>
using namespace std;

class Shape {
public:
    // Run-time polymorphism (virtual function)
    // In run-time polymorphism,
    // the function to be called is determined at runtime using virtual functions and pointers to the base class.

    // when parent and child both have same function but different implementation.
    virtual void draw() {
        cout << "Drawing a shape." << endl;
    }

    // Compile-time polymorphism (overloaded function)
    void area(int side) {
        cout << "Area of square: " << side * side << endl;
    }

    void area(int length, int width) {
        cout << "Area of rectangle: " << length * width << endl;
    }
};

class Circle : public Shape {
public:
    void draw() override {  // Method overriding (run-time)
        cout << "Drawing a circle." << endl;
    }
};

int main() {
    Shape* shape = new Circle();

    // Run-time polymorphism
    shape->draw();  

    // Compile-time polymorphism
    shape->area(5);            
    shape->area(5, 10);        

    delete shape;
    return 0;
}
