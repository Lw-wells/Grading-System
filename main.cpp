#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Student class definition
class Student {
private:
    string name;
    string studentID;
    double assignment1, assignment2, assignment3;
    double exam1, exam2;

public:
    // Constructor to initialize student data
    Student(string n, string id, double a1, double a2, double a3, double e1, double e2)
        : name(n), studentID(id), assignment1(a1), assignment2(a2), assignment3(a3), exam1(e1), exam2(e2) {}

    // Function to calculate and return the final grade
    double calculateFinalGrade() const {
        double assignmentAverage = (assignment1 + assignment2 + assignment3) / 3;
        double examAverage = (exam1 + exam2) / 2;

        // Weighted average calculation (40% assignments, 60% exams)
        double finalGrade = (assignmentAverage * 0.4) + (examAverage * 0.6);
        return finalGrade;
    }

    // Function to display the student details and final grade
    void displayStudentInfo() const {
        cout << "Student Name: " << name << ", ID: " << studentID << endl;
        cout << "Final Grade: " << calculateFinalGrade() << endl;
    }
};

// Function to add student data
void addStudent(vector<Student>& students) {
    string name, studentID;
    double a1, a2, a3, e1, e2;

    cout << "Enter student name: ";
    cin >> name;
    cout << "Enter student ID: ";
    cin >> studentID;

    cout << "Enter marks for Assignment 1: ";
    cin >> a1;
    cout << "Enter marks for Assignment 2: ";
    cin >> a2;
    cout << "Enter marks for Assignment 3: ";
    cin >> a3;

    cout << "Enter marks for Exam 1: ";
    cin >> e1;
    cout << "Enter marks for Exam 2: ";
    cin >> e2;

    // Create a new student and add to the vector
    Student newStudent(name, studentID, a1, a2, a3, e1, e2);
    students.push_back(newStudent);
}

// Function to display all students' final grades
void displayAllStudents(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No student data available." << endl;
        return;
    }

    for (const auto& student : students) {
        student.displayStudentInfo();
        cout << endl;
    }
}

int main() {
    vector<Student> students;
    int choice;

    while (true) {
        // Menu for student grade system
        cout << "\nStudent Grade Management System\n";
        cout << "1. Add a student\n";
        cout << "2. Display all students' final grades\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            // Add a new student
            addStudent(students);

        } else if (choice == 2) {
            // Display all students and their final grades
            displayAllStudents(students);

        } else if (choice == 3) {
            // Exit the system
            cout << "Exiting the system..." << endl;
            break;

        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
