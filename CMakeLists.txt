cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(StudentManagementSystem VERSION 1.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the include directory
include_directories(include)

# Find the nlohmann_json package
find_package(nlohmann_json REQUIRED)

# Add the executable
add_executable(StudentManagementSystem src/main.cpp src/Student.cpp src/utils.cpp)

# Link the nlohmann_json library
target_link_libraries(StudentManagementSystem PRIVATE nlohmann_json::nlohmann_json)
