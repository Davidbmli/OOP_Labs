#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Student {
private:
    string name;
    double grade;

public:
    Student(string n, double g) : name(n), grade(g) {}

    double getGrade() const { return grade; }
    string getName() const { return name; }

    void display() const {
        cout << "Name: " << name << ", Grade: " << grade << endl;
    }
};

vector<Student> findHighestGradeStudents(const vector<Student>& students) {
    double maxGrade = max_element(students.begin(), students.end(), [](const Student& a, const Student& b) {
        return a.getGrade() < b.getGrade();
        })->getGrade();

    vector<Student> highestGradeStudents;
    for (const auto& student : students) {
        if (student.getGrade() == maxGrade) {
            highestGradeStudents.push_back(student);
        }
    }
    return highestGradeStudents;
}

int main() {
    vector<Student> students = {
        Student("Alice", 90.5),
        Student("Bob", 92.3),
        Student("Charlie", 92.3),
        Student("David", 85.0)
    };

    vector<Student> topStudents = findHighestGradeStudents(students);

    cout << "Student(s) with the highest grade:" << endl;
    for (const auto& student : topStudents) {
        student.display();
    }

    return 0;
}
