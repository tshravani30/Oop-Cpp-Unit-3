#include <iostream>

class Base {
public:
    void display() const {
        std::cout << "Base display function\n";
    }
};

class Derived : public Base {
public:
    void display() const {
        std::cout << "Derived display function\n";
    }
};

int main() {
    Derived derivedObject;

    Base* basePointer = &derivedObject;

    std::cout << "Calling using derived object: ";
    derivedObject.display();

    std::cout << "Calling using base pointer: ";
    basePointer->display();

    return 0;
}