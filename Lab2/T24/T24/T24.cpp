#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct Person 
{
    string name;
    int age;
    Person(string n, int a) : name(n), age(a) {}
    string toString() const 
    {
        return name + " (" + to_string(age) + ")";
    }
};

bool compareByAgeDescending(const Person& p1, const Person& p2) 
{
    return p1.age > p2.age;
}

bool compareByNameAscending(const Person& p1, const Person& p2) 
{
    return p1.name < p2.name;
}

int main() {
    vector<Person> people = 
    {
        Person("Alice", 30),
        Person("Bob", 25),
        Person("Charlie", 35),
        Person("David", 25),
        Person("Eve", 28)
    };

    cout << "Sorting by age (descending):\n";
    sort(people.begin(), people.end(), compareByAgeDescending);
    for (const auto& person : people) 
    {
        cout << person.toString() << endl;
    }
    cout << "\nSorting by name (ascending):\n";
    sort(people.begin(), people.end(), compareByNameAscending);
    for (const auto& person : people) 
    {
        cout << person.toString() << endl;
    }

    return 0;
}
