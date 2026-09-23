#include <iostream>

class Complex {
private:
    int real;
    int imaginary;

public:
    Complex(int realPart = 0, int imaginaryPart = 0)
        : real(realPart), imaginary(imaginaryPart) {}

    friend Complex operator+(int value, const Complex& number);

    // Modified: Friend subtraction operator
    friend Complex operator-(int value, const Complex& number);

    void display() const {
        std::cout << real;

        if (imaginary >= 0) {
            std::cout << " + ";
        } else {
            std::cout << " - ";
        }

        std::cout << (imaginary >= 0
                          ? imaginary
                          : -imaginary)
                  << "i\n";
    }
};

Complex operator+(int value, const Complex& number) {
    return Complex(
        value + number.real,
        number.imaginary
    );
}

// Modified
Complex operator-(int value, const Complex& number) {
    return Complex(
        value - number.real,
        -number.imaginary
    );
}

int main() {
    Complex number(2, 3);

    Complex result1 = 10 + number;
    Complex result2 = 10 - number;

    std::cout << "10 + complex number: ";
    result1.display();

    std::cout << "10 - complex number: ";
    result2.display();

    return 0;
}