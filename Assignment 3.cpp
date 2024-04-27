/******************************************
* Edgardo Richard Ventura                 *
* Week 12                                 *
* Assignment 3                            *
* Instructor: Frank Alvino                *
* CIS 121-061                             *
******************************************/
#include <iostream>
#include <vector>
#include <string>

// Global structure definition for a student
struct Student {
    std::string firstName;
    std::string lastName;
    char districtCode;
    int credits;
    double tuitionBalance;
};

// Compute tuition based on district code and credit hours
double computeTuition(char districtCode, int credits) {
    if (districtCode == 'I' || districtCode == 'i') {  // In-district
        return credits * 250.00;
    }
    else {  // Out-of-district
        return credits * 500.00;
    }
}

// Display all student records and the total count
void displayStudents(const std::vector<Student>& students) {
    std::cout << "\nStudent Records:";
    for (const auto& student : students) {
        std::cout << "\n\nName: " << student.firstName << " " << student.lastName
            << "\nDistrict Code: " << student.districtCode
            << "\nCredits: " << student.credits
            << "\nTuition Balance: $" << student.tuitionBalance << std::endl;
    }
    std::cout << "\nTotal number of students: " << students.size() << std::endl;
}

int main() {
    std::vector<Student> students;  // Vector to store student data
    Student tempStudent;

    // Input loop for student data
    std::cout << "(Ctrl+Z and press enter twice to stop)\n~ student data ~\n";
    while (true) {
        std::cout << "\nEnter first name: ";
        if (!(std::cin >> tempStudent.firstName)) break;

        std::cout << "Enter last name: ";
        if (!(std::cin >> tempStudent.lastName)) break;

        std::cout << "Enter district code (I or O): ";
        if (!(std::cin >> tempStudent.districtCode)) break;

        std::cout << "Enter credits taken: ";
        if (!(std::cin >> tempStudent.credits)) break;

        // Compute tuition and add to the student record
        tempStudent.tuitionBalance = computeTuition(tempStudent.districtCode, tempStudent.credits);
        students.push_back(tempStudent);  // Add student to vector
    }

    // Clear the input buffer and reset
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // Display all student records
    displayStudents(students);

    return 0;
}
