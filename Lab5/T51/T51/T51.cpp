#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Address {
private:
    string street, city;
public:
    Address(string s, string c) : street(s), city(c) {}
    string getStreet() const { return street; }
    string getCity() const { return city; }
    void display() const {
        cout << street << ", " << city << endl;
    }
};

class Person {
protected:
    string name;
    int age;
    Address address;
public:
    Person(string n, int a, Address addr) : name(n), age(a), address(addr) {}
    string getName() const { return name; }
    Address getAddress() const { return address; }
    virtual void display() const {
        cout << "Name: " << name << ", Age: " << age << ", Address: ";
        address.display();
    }
};

class Driver : public Person {
private:
    string licenseNumber;
public:
    Driver(string n, int a, Address addr, string license)
        : Person(n, a, addr), licenseNumber(license) {
    }
    string getLicense() const { return licenseNumber; }
    void display() const override {
        Person::display();
        cout << "License Number: " << licenseNumber << endl;
    }
};

class Commuter : public Person {
public:
    Commuter(string n, int a, Address addr) : Person(n, a, addr) {}
};

class Student : public Commuter {
public:
    Student(string n, int a, Address addr) : Commuter(n, a, addr) {}
};

class Engine {
private:
    int horsepower;
public:
    Engine(int hp) : horsepower(hp) {}
    void start() const {
        cout << "Engine with " << horsepower << " HP is starting..." << endl;
    }
};

class Vehicle {
protected:
    string model;
    Engine engine;
public:
    Vehicle(string m, Engine e) : model(m), engine(e) {}
    virtual void display() const {
        cout << "Vehicle Model: " << model << endl;
    }
    void startEngine() const {
        engine.start();
    }
};

class Car : public Vehicle {
private:
    vector<Student*> students;
public:
    Car(string m, Engine e) : Vehicle(m, e) {}
    void addStudent(Student* student) {
        students.push_back(student);
    }
    bool hasStudent(Student* student) {
        return find(students.begin(), students.end(), student) != students.end();
    }
};

class Bus : public Vehicle {
private:
    Driver* driver;
    vector<Commuter*> commuters;
public:
    Bus(string m, Engine e, Driver* d) : Vehicle(m, e), driver(d) {}
    void addCommuter(Commuter* commuter) {
        commuters.push_back(commuter);
    }
    int getCommuterCount() const {
        return commuters.size();
    }
    void display() const override {
        Vehicle::display();
        cout << "Driver: ";
        driver->display();
    }
};

class BusStation {
private:
    string stationName;
    Address address;
    vector<Bus*> buses;
public:
    BusStation(string name, Address addr) : stationName(name), address(addr) {}
    void addBus(Bus* bus) {
        buses.push_back(bus);
    }
    void displayBuses() const {
        cout << "Buses at " << stationName << ":" << endl;
        for (const auto& bus : buses) {
            bus->display();
        }
    }
    bool containsBus(Bus* bus) {
        return find(buses.begin(), buses.end(), bus) != buses.end();
    }
};

class Mosquito {
private:
    string type;
public:
    Mosquito(string t) : type(t) {}
};

class Apartment {
private:
    Address address;
public:
    Apartment(Address addr) : address(addr) {}
};

int main() {
    Address addr1("123 Main St", "Metropolis");
    Address addr2("456 Elm St", "Gotham");

    Driver driver1("John Doe", 40, addr1, "DJ 70 POR");

    Engine busEngine(350);
    Bus bus1("City Bus", busEngine, &driver1);

    Commuter commuter1("Alice", 25, addr2);
    bus1.addCommuter(&commuter1);

    BusStation station1("Central Station", addr1);
    station1.addBus(&bus1);

    station1.displayBuses();
    cout << "Commuters in bus: " << bus1.getCommuterCount() << endl;

    bus1.startEngine();

    return 0;
}
