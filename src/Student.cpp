#include "Student.h"
#include <iostream>
#include <stdexcept>
#include <iomanip>

Student::Student() : id(0), age(0) {}

Student::Student(const std::string& name, int id, int age) : name(name), id(id), age(age) {}

void Student::addOrUpdateAssignment(const std::string& assignmentName, double grade) {
    if (grade < 0 || grade > 100) {
        throw std::out_of_range("Grade must be between 0 and 100.");
    }
    assignments[assignmentName] = grade;
}

void Student::removeAssignment(const std::string& assignmentName) {
    if (assignments.find(assignmentName) == assignments.end()) {
        throw std::invalid_argument("Assignment not found.");
    }
    assignments.erase(assignmentName);
}

double Student::calculateGPA() const {
    if (assignments.empty()) {
        return 0.0;
    }
    double total = 0.0;
    for (const auto& [_, grade] : assignments) {
        total += grade;
    }
    return total / assignments.size();
}

void Student::display() const {
    std::cout << "Student ID: " << id << "\n";
    std::cout << "Name: " << name << "\n";
    std::cout << "Age: " << age << "\n";
    std::cout << "Assignments:\n";
    displayAssignments();
}

void Student::displayAssignments() const {
    if (assignments.empty()) {
        std::cout << "No assignments available.\n";
    } else {
        for (const auto& [assignmentName, grade] : assignments) {
            std::cout << " - " << assignmentName << ": " << grade << "\n";
        }
    }
}

void Student::loadFromJson(const nlohmann::json& jsonData) {
    name = jsonData.at("name").get<std::string>();
    id = jsonData.at("id").get<int>();
    age = jsonData.at("age").get<int>();
    assignments = jsonData.at("assignments").get<std::unordered_map<std::string, double>>();
}

nlohmann::json Student::toJson() const {
    nlohmann::json jsonData;
    jsonData["name"] = name;
    jsonData["id"] = id;
    jsonData["age"] = age;
    jsonData["assignments"] = assignments;
    return jsonData;
}
