# Student Management System

## Overview

This C++ project implements a student management system using a JSON file to store and retrieve student records, including assignments and grades. It allows for adding, updating, and removing student information and assignments, as well as calculating GPAs.

## Features

- Add a new student
- Add or update assignments for a student
- Remove assignments from a student
- Display student information and assignments
- Calculate GPA for a student
- Save and load student data to and from a JSON file

## Getting Started

### Prerequisites

- C++ compiler (e.g., g++, clang++)
- CMake (for building the project)
- nlohmann/json library

### Installation

1. Clone the repository:

   ```bash
   git clone https://github.com/finaldestroyer/Student_Management_System.git
   cd student-management-system

2. Create a build directory and navigate into it:
   ```bash
   mkdir build
   cd build

3. Run CMake to configure the project:
   ```bash
   cmake ..

4. Build the project:
   ```bash
   cmake --build .

### Example
   ```bash
   --- Student Management System ---
   1. Add a student
   2. Add or update an assignment
   3. Remove an assignment
   4. Display student information
   5. Display all assignments for a student
   6. Calculate GPA
   7. Save and exit
   Enter your choice: 1

