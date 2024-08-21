#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <unordered_map>
#include <nlohmann/json.hpp>

class Student {
public:
    Student();
    Student(const std::string& name, int id, int age);

    void addOrUpdateAssignment(const std::string& assignmentName, double grade);
    void removeAssignment(const std::string& assignmentName);
    double calculateGPA() const;
    void display() const;
    void displayAssignments() const;

    void loadFromJson(const nlohmann::json& jsonData);
    nlohmann::json toJson() const;

private:
    std::string name;
    int id;
    int age;
    std::unordered_map<std::string, double> assignments;
};

#endif // STUDENT_H
