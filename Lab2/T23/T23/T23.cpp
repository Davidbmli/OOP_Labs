#include <iostream>
#include <stdexcept>
using namespace std; 
class InfiniteSolutions : public exception 
{
public:
    const char* what() const noexcept override 
    {
        return "The equation has infinitely many solutions.";
    }
};

class NoSolution : public exception 
{
public:
    const char* what() const noexcept override 
    {
        return "The equation has no solution.";
    }
};

double solveLinearEquation(double a, double b) 
{
    if (a == 0) 
    {
        if (b == 0) 
        {
            throw InfiniteSolutions();
        }
        else 
        {
            throw NoSolution();
        }
    }
    return -b / a;
}

int main() {
    try {
        double a, b;
        cout << "Enter coefficients a and b for the equation ax + b = 0: ";
        cin >> a >> b;
        double solution = solveLinearEquation(a, b);
        cout << "The solution is x = " << solution << endl;
    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
    return 0;
}
