#include <iostream>
#include <unordered_map>
#include <limits>
#include "Student.h"
#include "Util.h"

void addStudent(std::unordered_map<int, Student>& students) {
    int id;
    std::string name;
    int age;

    std::cout << "Enter student ID: ";
    std::cin >> id;
    std::cin.ignore(); // Ignore newline character
    std::cout << "Enter student name: ";
    std::getline(std::cin, name);
    std::cout << "Enter student age: ";
    std::cin >> age;

    if (students.find(id) != students.end()) {
        std::cerr << "Student with ID " << id << " already exists.\n";
    } else {
        students[id] = Student(name, id, age);
        std::cout << "Student added successfully.\n";
    }
}

void addOrUpdateAssignment(std::unordered_map<int, Student>& students) {
    int id;
    std::string assignmentName;
    double grade;

    std::cout << "Enter student ID: ";
    std::cin >> id;
    if (students.find(id) == students.end()) {
        std::cerr << "Student not found.\n";
    } else {
        std::cout << "Enter assignment name: ";
        std::cin.ignore();
        std::getline(std::cin, assignmentName);
        std::cout << "Enter grade: ";
        std::cin >> grade;

        try {
            students[id].addOrUpdateAssignment(assignmentName, grade);
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << "\n";
        }
    }
}

void removeAssignment(std::unordered_map<int, Student>& students) {
    int id;
    std::string assignmentName;

    std::cout << "Enter student ID: ";
    std::cin >> id;
    if (students.find(id) == students.end()) {
        std::cerr << "Student not found.\n";
    } else {
        std::cout << "Enter assignment name to remove: ";
        std::cin.ignore();
        std::getline(std::cin, assignmentName);

        try {
            students[id].removeAssignment(assignmentName);
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << "\n";
        }
    }
}

void displayStudentInfo(const std::unordered_map<int, Student>& students) {
    int id;

    std::cout << "Enter student ID: ";
    std::cin >> id;
    auto it = students.find(id);
    if (it == students.end()) {
        std::cerr << "Student not found.\n";
    } else {
        it->second.display();
    }
}

void displayAllAssignments(const std::unordered_map<int, Student>& students) {
    int id;

    std::cout << "Enter student ID: ";
    std::cin >> id;
    auto it = students.find(id);
    if (it == students.end()) {
        std::cerr << "Student not found.\n";
    } else {
        try {
            it->second.displayAssignments();
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << "\n";
        }
    }
}

void calculateGPA(const std::unordered_map<int, Student>& students) {
    int id;

    std::cout << "Enter student ID: ";
    std::cin >> id;
    auto it = students.find(id);
    if (it == students.end()) {
        std::cerr << "Student not found.\n";
    } else {
        try {
            std::cout << "GPA: " << it->second.calculateGPA() << "\n";
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << "\n";
        }
    }
}

int main() {
    std::unordered_map<int, Student> students;

    // Load students from JSON file
    try {
        loadStudentsFromJson(students, "students.json");
    } catch (const std::exception& e) {
        std::cerr << "Error loading data: " << e.what() << "\n";
    }

    int choice;
    do {
        std::cout << "\n--- Student Management System ---\n";
        std::cout << "1. Add a student\n";
        std::cout << "2. Add or update an assignment\n";
        std::cout << "3. Remove an assignment\n";
        std::cout << "4. Display student information\n";
        std::cout << "5. Display all assignments for a student\n";
        std::cout << "6. Calculate GPA\n";
        std::cout << "7. Save and exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cerr << "Invalid input. Please enter a number between 1 and 7.\n";
            continue;
        }

        switch (choice) {
            case 1:
                addStudent(students);
                break;
            case 2:
                addOrUpdateAssignment(students);
                break;
            case 3:
                removeAssignment(students);
                break;
            case 4:
                displayStudentInfo(students);
                break;
            case 5:
                displayAllAssignments(students);
                break;
            case 6:
                calculateGPA(students);
                break;
            case 7:
                try {
                    saveStudentsToJson(students, "students.json");
                    std::cout << "Data saved. Exiting...\n";
                } catch (const std::exception& e) {
                    std::cerr << "Error saving data: " << e.what() << "\n";
                }
                break;
            default:
                std::cerr << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 7);

    return 0;
}
