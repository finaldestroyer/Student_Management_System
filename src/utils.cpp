#include "Util.h"
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>

void saveStudentsToJson(const std::unordered_map<int, Student>& students, const std::string& filename) {
    nlohmann::json jsonData;
    for (const auto& [id, student] : students) {
        jsonData[std::to_string(id)] = student.toJson();
    }

    std::ofstream outFile(filename);
    if (!outFile) {
        throw std::runtime_error("Unable to open file for writing: " + filename);
    }
    outFile << jsonData.dump(4); // Pretty print with an indent of 4 spaces
}

void loadStudentsFromJson(std::unordered_map<int, Student>& students, const std::string& filename) {
    std::ifstream inFile(filename);
    if (!inFile) {
        std::cerr << "Unable to open file for reading: " + filename + ". Starting with an empty record.\n";
        return;
    }

    nlohmann::json jsonData;
    inFile >> jsonData;

    for (const auto& [idStr, studentJson] : jsonData.items()) {
        int id = std::stoi(idStr);
        Student student;
        student.loadFromJson(studentJson);
        students[id] = student;
    }
}
