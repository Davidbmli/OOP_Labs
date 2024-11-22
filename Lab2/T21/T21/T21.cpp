#include <iostream>
#include <stdexcept>
#include <string>
#include <functional>

using namespace std;

double rectangleArea(double length, double width) {
    return length * width;
}

double squareArea(double side, double = 0) {
    return side * side;
}

double parseInput(const string& input) {
    try {
        size_t pos;
        double value = stod(input, &pos);
        if (pos != input.length()) {
            throw invalid_argument("Invalid character in input");
        }
        return value;
    }
    catch (const invalid_argument&) {
        throw invalid_argument("Invalid input: " + input);
    }
    catch (const out_of_range&) {
        throw out_of_range("Input value out of range");
    }
}

double calculateArea(const string& input1, const string& input2 = "",
    function<double(double, double)> areaFunction = squareArea) {
    double dimension1 = parseInput(input1);
    double dimension2 = (input2.empty()) ? dimension1 : parseInput(input2);

    if (dimension1 <= 0 || dimension2 <= 0) {
        throw invalid_argument("Dimensions must be positive numbers");
    }

    return areaFunction(dimension1, dimension2);
}

int main() {
    try {
        string input1, input2;
        cout << "Enter the first dimension: ";
        cin >> input1;

        cout << "Enter the second dimension (leave blank for square): ";
        cin.ignore();
        getline(cin, input2);

        double area;
        if (input2.empty()) {
            area = calculateArea(input1);
        }
        else {
            area = calculateArea(input1, input2, rectangleArea);
        }

        cout << "The calculated area is: " << area << endl;
    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
