#include <iostream>
#include <string>
#include <utility>
#include <memory>
#include <vector>

class Employee {
protected:
    int employeeId;
    std::string name;

public:
    Employee(int id, std::string employeeName)
        : employeeId(id),
          name(std::move(employeeName)) {}

    virtual double calculateSalary() const = 0;

    void displayBasicDetails() const {
        std::cout << "Employee ID: "
                  << employeeId << '\n';

        std::cout << "Name: "
                  << name << '\n';
    }

    virtual ~Employee() = default;
};

class PermanentEmployee : public Employee {
private:
    double basicSalary;
    double allowance;
    double taxRate;

public:
    PermanentEmployee(
        int id,
        std::string employeeName,
        double basic,
        double extra,
        double tax
    )
        : Employee(id, std::move(employeeName)),
          basicSalary(basic),
          allowance(extra),
          taxRate(tax) {}

    double calculateSalary() const override {
        double grossSalary = basicSalary + allowance;

        double taxAmount =
            grossSalary * taxRate / 100.0;

        return grossSalary - taxAmount;
    }
};

class ContractEmployee : public Employee {
private:
    double hourlyRate;
    int hoursWorked;

public:
    ContractEmployee(
        int id,
        std::string employeeName,
        double rate,
        int hours
    )
        : Employee(id, std::move(employeeName)),
          hourlyRate(rate),
          hoursWorked(hours) {}

    double calculateSalary() const override {
        return hourlyRate * hoursWorked;
    }
};

// Modified: Freelance Employee
class FreelanceEmployee : public Employee {
private:
    double projectAmount;

public:
    FreelanceEmployee(
        int id,
        std::string employeeName,
        double amount
    )
        : Employee(id, std::move(employeeName)),
          projectAmount(amount) {}

    double calculateSalary() const override {
        return projectAmount;
    }
};

void printPaySlip(const Employee& employee) {
    employee.displayBasicDetails();

    std::cout << "Salary: Rs. "
              << employee.calculateSalary()
              << "\n\n";
}

int main() {

    // Modified: vector of polymorphic employees
    std::vector<std::unique_ptr<Employee>> employees;

    employees.push_back(
        std::make_unique<PermanentEmployee>(
            101,
            "Adarsh",
            40000.0,
            8000.0,
            10.0
        )
    );

    employees.push_back(
        std::make_unique<ContractEmployee>(
            102,
            "Meghraj",
            500.0,
            80
        )
    );

    employees.push_back(
        std::make_unique<FreelanceEmployee>(
            103,
            "Sumit",
            30000.0
        )
    );

    double totalPayroll = 0.0;

    for (const auto& employee : employees) {
        printPaySlip(*employee);

        totalPayroll +=
            employee->calculateSalary();
    }

    // Modified: Total payroll
    std::cout << "Total Payroll: Rs. "
              << totalPayroll << '\n';

    return 0;
}