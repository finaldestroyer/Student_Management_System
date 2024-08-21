#ifndef UTIL_H
#define UTIL_H

#include <unordered_map>
#include "Student.h"

// Loads student data from a JSON file into the students map
void loadStudentsFromJson(std::unordered_map<int, Student>& students, const std::string& filename);

// Saves student data from the students map to a JSON file
void saveStudentsToJson(const std::unordered_map<int, Student>& students, const std::string& filename);

#endif // UTIL_H
