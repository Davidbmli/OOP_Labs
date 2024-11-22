#include <iostream>
#include <cmath>
using namespace std;

struct nrComplex 
{
    double real;
    double imag;
};

double absoluteValue(double realNumber) 
{
    return fabs(realNumber);
}

double absoluteValue(const nrComplex& complexNumber) 
{
    return sqrt(complexNumber.real * complexNumber.real + complexNumber.imag * complexNumber.imag);
}

int main() 
{
    double realNumber = -5.7;
    cout << "Absolute value of real number " << realNumber << " is: "<< absoluteValue(realNumber) << endl;

    nrComplex complexNumber = { 3.0, 4.0 };
    cout << "Absolute value of complex number " << complexNumber.real<< "+" << complexNumber.imag << "i is: "<< absoluteValue(complexNumber) << endl;

    return 0;
}
