#include <iostream>

class Balance {
private:
    double balance;

public:
    explicit Balance(double givenBalance)
        : balance(givenBalance) {}

    Balance operator-() const {
        return Balance(-balance);
    }

    void display() const {
        std::cout << balance << '\n';
    }
};

int main() {
    Balance originalBalance(5000.0);

    Balance negativeBalance = -originalBalance;

    std::cout << "Original balance: ";
    originalBalance.display();

    std::cout << "Negative balance: ";
    negativeBalance.display();

    return 0;
}