#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Student {
private:
    int id;
    string name;

public:
    Student(int i, string n) : id(i), name(n) {}

    int getId() const { return id; }
    string getName() const { return name; }

    void display() const {
        cout << "ID: " << id << ", Name: " << name << endl;
    }
};

int main() {
    vector<Student> students = {
        Student(1, "Alice"),
        Student(2, "Bob"),
        Student(3, "Charlie"),
        Student(4, "David")
    };

    int searchId;
    cout << "Enter Student ID to search: ";
    cin >> searchId;

    auto it = find_if(students.begin(), students.end(), [searchId](const Student& s) {
        return s.getId() == searchId;
        });

    if (it != students.end()) {
        cout << "Student found: ";
        it->display();
    }
    else {
        cout << "Student with ID " << searchId << " not found." << endl;
    }

    return 0;
}
