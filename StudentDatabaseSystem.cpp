#include <iostream>
#include <vector>
#include <algorithm>

// Define the Student class
class Student {
public:
    std::string name;
    int rollNumber;
    std::string course;
};

// Define the Database class
class StudentDatabase {
private:
    std::vector<Student> students;

public:
    // Function to add a new student record
    void addStudent(const Student& newStudent) {
        students.push_back(newStudent);
    }

    // Function to search for a student record by roll number
    void searchByRollNumber(int rollNumber) {
        auto it = std::find_if(students.begin(), students.end(), [rollNumber](const Student& s) {
            return s.rollNumber == rollNumber;
        });
        if (it != students.end()) {
            displayStudent(*it);
        } else {
            std::cout << "Student with roll number " << rollNumber << " not found." << std::endl;
        }
    }

    // Function to search for a student record by name
    void searchByName(const std::string& name) {
        auto it = std::find_if(students.begin(), students.end(), [name](const Student& s) {
            return s.name == name;
        });
        if (it != students.end()) {
            displayStudent(*it);
        } else {
            std::cout << "Student with name " << name << " not found." << std::endl;
        }
    }

    // Function to display all student records
    void displayAllStudents() {
        for (const auto& student : students) {
            displayStudent(student);
        }
    }

    // Function to update student information by roll number
    void updateStudentInfo(int rollNumber, const std::string& newName, const std::string& newCourse) {
        auto it = std::find_if(students.begin(), students.end(), [rollNumber](const Student& s) {
            return s.rollNumber == rollNumber;
        });
        if (it != students.end()) {
            it->name = newName;
            it->course = newCourse;
            std::cout << "Student information updated successfully." << std::endl;
        } else {
            std::cout << "Student with roll number " << rollNumber << " not found." << std::endl;
        }
    }

    // Function to delete a student record by roll number
    void deleteStudent(int rollNumber) {
        auto it = std::remove_if(students.begin(), students.end(), [rollNumber](const Student& s) {
            return s.rollNumber == rollNumber;
        });
        if (it != students.end()) {
            students.erase(it, students.end());
            std::cout << "Student with roll number " << rollNumber << " deleted successfully." << std::endl;
        } else {
            std::cout << "Student with roll number " << rollNumber << " not found." << std::endl;
        }
    }

private:
    // Helper function to display a single student record
    void displayStudent(const Student& student) {
        std::cout << "Name: " << student.name << ", Roll Number: " << student.rollNumber << ", Course: " << student.course << std::endl;
    }
};

// Function to display menu and handle user input
int displayMenu() {
    std::cout << "\nMenu:\n";
    std::cout << "1. Add a new student record\n";
    std::cout << "2. Search for a student record by roll number\n";
    std::cout << "3. Search for a student record by name\n";
    std::cout << "4. Display all student records\n";
    std::cout << "5. Update a student's information\n";
    std::cout << "6. Delete a student record\n";
    std::cout << "7. Exit\n";
    std::cout << "Enter your choice: ";
    int choice;
    std::cin >> choice;
    return choice;
}

int main() {
    StudentDatabase database;

    int choice;
    do {
        choice = displayMenu();

        switch (choice) {
            case 1: {
                std::cout << "Enter student name: ";
                std::string name;
                std::cin >> name;
                std::cout << "Enter roll number: ";
                int rollNumber;
                std::cin >> rollNumber;
                std::cout << "Enter course: ";
                std::string course;
                std::cin >> course;
                Student newStudent;
                newStudent.name = name;
                newStudent.rollNumber = rollNumber;
                newStudent.course = course;
                database.addStudent(newStudent);
                break;
            }
            case 2: {
                std::cout << "Enter roll number to search: ";
                int rollNumber;
                std::cin >> rollNumber;
                database.searchByRollNumber(rollNumber);
                break;
            }
            case 3: {
                std::cout << "Enter name to search: ";
                std::string name;
                std::cin >> name;
                database.searchByName(name);
                break;
            }
            case 4: {
                std::cout << "All student records:\n";
                database.displayAllStudents();
                break;
            }
            case 5: {
                std::cout << "Enter roll number to update: ";
                int rollNumber;
                std::cin >> rollNumber;
                std::cout << "Enter new name: ";
                std::string newName;
                std::cin >> newName;
                std::cout << "Enter new course: ";
                std::string newCourse;
                std::cin >> newCourse;
                database.updateStudentInfo(rollNumber, newName, newCourse);
                break;
            }
            case 6: {
                std::cout << "Enter roll number to delete: ";
                int rollNumber;
                std::cin >> rollNumber;
                database.deleteStudent(rollNumber);
                break;
            }
            case 7: {
                std::cout << "Exiting program...\n";
                break;
            }
            default: {
                std::cout << "Invalid choice. Please try again.\n";
                break;
            }
        }
    } while (choice != 7);

    return 0;
}
