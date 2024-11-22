#include <iostream>
using namespace std;

class Rectangle {
private:
    double length;
    double width;

public:
    Rectangle(double l, double w) {
        length = l;
        width = w;
    }

    double getPerimeter() const {
        return 2 * (length + width);
    }

    double getArea() const {
        return length * width;
    }

    void display() const {
        cout << "Length: " << length << ", Width: " << width << endl;
        cout << "Perimeter: " << getPerimeter() << ", Area: " << getArea() << endl;
    }

    void comparePerimeter(const Rectangle& other) const {
        if (getPerimeter() > other.getPerimeter()) {
            cout << "Current rectangle has a larger perimeter." << endl;
        }
        else if (getPerimeter() < other.getPerimeter()) {
            cout << "Other rectangle has a larger perimeter." << endl;
        }
        else {
            cout << "Both rectangles have the same perimeter." << endl;
        }
    }

    void compareArea(const Rectangle& other) const {
        if (getArea() > other.getArea()) {
            cout << "Current rectangle has a larger area." << endl;
        }
        else if (getArea() < other.getArea()) {
            cout << "Other rectangle has a larger area." << endl;
        }
        else {
            cout << "Both rectangles have the same area." << endl;
        }
    }
};

int main() {
    Rectangle rect1(10, 5);
    Rectangle rect2(8, 7);

    cout << "First Rectangle:" << endl;
    rect1.display();
    cout << "\nSecond Rectangle:" << endl;
    rect2.display();

    cout << "\nPerimeter Comparison:" << endl;
    rect1.comparePerimeter(rect2);

    cout << "\nArea Comparison:" << endl;
    rect1.compareArea(rect2);

    return 0;
}
