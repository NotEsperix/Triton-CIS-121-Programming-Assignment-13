/******************************************
* Edgardo Richard Ventura                 *
* Week 12                                 *
* Assignment 2                            *
* Instructor: Frank Alvino                *
* CIS 121-061                             *
******************************************/
#include <iostream>
#include <vector>
#include <string>

// Define the Employee structure
struct Employee {
    std::string firstName;
    std::string lastName;
    double hours;
    double rate;
    double grossPay;
};

// Function to compute gross pay
double computeGrossPay(double hours, double rate) {
    if (hours > 40) {
        return 40 * rate + (hours - 40) * rate * 1.5;  // Overtime calculation
    }
    return hours * rate;  // Normal pay calculation
}

// Function to display employee data
void displayEmployees(const std::vector<Employee>& employees) {
    std::cout << "\nEmployee Data:";
    for (const auto& emp : employees) {
        std::cout << "\nName: " << emp.firstName << " " << emp.lastName
            << "\nHours Worked: " << emp.hours
            << "\nHourly Rate: $" << emp.rate
            << "\nGross Pay: $" << emp.grossPay << std::endl;
    }
}

int main() {
    int n;
    std::cout << "Enter the number of employees: ";
    std::cin >> n;

    std::vector<Employee> employees;  // Vector to store employee data

    // Input data for each employee
    for (int i = 0; i < n; ++i) {
        Employee emp;
        std::cout << "\nEnter first name for employee " << (i + 1) << ": ";
        std::cin >> emp.firstName;
        std::cout << "Enter last name for employee " << (i + 1) << ": ";
        std::cin >> emp.lastName;
        std::cout << "Enter hours worked by " << emp.firstName << ": ";
        std::cin >> emp.hours;
        std::cout << "Enter hourly rate for " << emp.firstName << ": ";
        std::cin >> emp.rate;

        // Compute gross pay and store it in the structure
        emp.grossPay = computeGrossPay(emp.hours, emp.rate);
        employees.push_back(emp);  // Add the employee to the vector
    }

    // Display all employee data
    displayEmployees(employees);

    return 0;
}
