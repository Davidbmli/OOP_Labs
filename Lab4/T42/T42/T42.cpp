#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Address Class
class Address {
private:
    string street;
    string city;
    string zipCode;

public:
    Address(string s, string c, string z) : street(s), city(c), zipCode(z) {}

    void display() const {
        cout << street << ", " << city << ", " << zipCode << endl;
    }
};

// Engine Class
class Engine {
private:
    int horsepower;
    string type;

public:
    Engine(int hp, string t) : horsepower(hp), type(t) {}

    void display() const {
        cout << "Engine: " << horsepower << " HP, Type: " << type << endl;
    }
};

// Base Class: Vehicle
class Vehicle {
protected:
    string model;
    Engine engine;

public:
    Vehicle(string m, Engine e) : model(m), engine(e) {}

    virtual void display() const {
        cout << "Model: " << model << endl;
        engine.display();
    }
};

// Car Class (inherits from Vehicle)
class Car : public Vehicle {
private:
    int numberOfSeats;

public:
    Car(string m, Engine e, int seats) : Vehicle(m, e), numberOfSeats(seats) {}

    void display() const override {
        Vehicle::display();
        cout << "Seats: " << numberOfSeats << endl;
    }
};

// Bus Class (inherits from Vehicle)
class Bus : public Vehicle {
private:
    int capacity;
    bool isDoubleDecker;

public:
    Bus(string m, Engine e, int cap, bool doubleDecker)
        : Vehicle(m, e), capacity(cap), isDoubleDecker(doubleDecker) {
    }

    void display() const override {
        Vehicle::display();
        cout << "Capacity: " << capacity << ", Double Decker: " << (isDoubleDecker ? "Yes" : "No") << endl;
    }
};

// Person Class (Base for Driver and Commuter)
class Person {
protected:
    string name;
    int age;
    Address address;

public:
    Person(string n, int a, Address addr) : name(n), age(a), address(addr) {}

    virtual void display() const {
        cout << "Name: " << name << ", Age: " << age << endl;
        cout << "Address: ";
        address.display();
    }
};

// Driver Class (inherits from Person)
class Driver : public Person {
private:
    string licenseNumber;
    int experienceYears;

public:
    Driver(string n, int a, Address addr, string license, int exp)
        : Person(n, a, addr), licenseNumber(license), experienceYears(exp) {
    }

    void display() const override {
        Person::display();
        cout << "License Number: " << licenseNumber << ", Experience: " << experienceYears << " years" << endl;
    }
};

// Commuter Class (inherits from Person)
class Commuter : public Person {
private:
    string commuterID;
    bool hasMonthlyPass;

public:
    Commuter(string n, int a, Address addr, string id, bool pass)
        : Person(n, a, addr), commuterID(id), hasMonthlyPass(pass) {
    }

    void display() const override {
        Person::display();
        cout << "Commuter ID: " << commuterID << ", Monthly Pass: " << (hasMonthlyPass ? "Yes" : "No") << endl;
    }
};

// Mosquito Class
class Mosquito {
private:
    string type;
    bool isDangerous;

public:
    Mosquito(string t, bool dangerous) : type(t), isDangerous(dangerous) {}

    void display() const {
        cout << "Mosquito Type: " << type << ", Dangerous: " << (isDangerous ? "Yes" : "No") << endl;
    }
};

// BusStation Class
class BusStation {
private:
    string stationName;
    Address address;
    vector<Bus> buses;
    vector<Driver> drivers;

public:
    BusStation(string name, Address addr) : stationName(name), address(addr) {}

    void addBus(const Bus& bus) {
        buses.push_back(bus);
    }

    void addDriver(const Driver& driver) {
        drivers.push_back(driver);
    }

    void display() const {
        cout << "Bus Station: " << stationName << endl;
        address.display();

        cout << "\nBuses:" << endl;
        for (const auto& bus : buses) {
            bus.display();
            cout << endl;
        }

        cout << "\nDrivers:" << endl;
        for (const auto& driver : drivers) {
            driver.display();
            cout << endl;
        }
    }
};

// Main Function
int main() {
    Address addr1("123 Main St", "Metropolis", "45678");
    Address addr2("456 Elm St", "Smallville", "12345");

    Engine busEngine(350, "Diesel");
    Engine carEngine(150, "Petrol");

    Driver driver1("John Doe", 45, addr1, "DL123456", 20);
    Driver driver2("Jane Smith", 38, addr2, "DL654321", 15);

    Bus bus1("City Bus", busEngine, 50, false);
    Bus bus2("Double Decker", busEngine, 100, true);

    Commuter commuter1("Alice", 30, addr1, "C123", true);

    BusStation station("Central Bus Station", addr1);
    station.addBus(bus1);
    station.addBus(bus2);
    station.addDriver(driver1);
    station.addDriver(driver2);

    cout << "\n--- Bus Station Information ---" << endl;
    station.display();

    cout << "\n--- Commuter Information ---" << endl;
    commuter1.display();

    Mosquito mosquito("Aedes", true);
    cout << "\n--- Mosquito Information ---" << endl;
    mosquito.display();

    return 0;
}
