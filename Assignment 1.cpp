/******************************************
* Edgardo Richard Ventura                 *
* Week 12                                 *
* Assignment 1                            *
* Instructor: Frank Alvino                *
* CIS 121-061                             *
******************************************/
#include <iostream>
#include <string>

// Function to display the contents of the arrays
void displayArrays(const std::string* makes, const std::string* models, int size) {
    std::cout << "Auto Makes and Models:\n";
    for (int i = 0; i < size; i++) {
        std::cout << (i + 1) << ". Make: " << makes[i] << ", Model: " << models[i] << std::endl;
    }
}

int main() {
    int n;
    std::cout << "Enter the number of autos: ";
    std::cin >> n;

    // Dynamic allocation of arrays based on user input
    std::string* makes = new std::string[n];
    std::string* models = new std::string[n];

    // Input data into the arrays
    for (int i = 0; i < n; i++) {
        std::cout << "Enter make for auto " << (i + 1) << ": ";
        std::cin >> makes[i];
        std::cout << "Enter model for auto " << (i + 1) << ": ";
        std::cin >> models[i];
    }

    // Display the arrays
    displayArrays(makes, models, n);

    // Clean up dynamic memory
    delete[] makes;
    delete[] models;

    return 0;
}
