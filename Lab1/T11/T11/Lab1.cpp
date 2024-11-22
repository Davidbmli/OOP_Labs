#include <iostream>
#include <cstring> 
using namespace std;

void FahrenheitToCelsius(double* temperatura)
{
    *temperatura = (*temperatura - 32) * 5.0 / 9.0; 
}

void CelsiusToFahrenheit(double* temperatura)
{
    *temperatura = *temperatura * (9.0 / 5.0) + 32; 
}

int main()
{
    double temperatura = 0;
    char alegere[100];
    cout << "Temperatura: ";
    cin >> temperatura;
    cout << endl;
    cout << "Fahrenheit or Celsius? ";
    cin >> alegere;
    cout << endl;
    if (strcmp(alegere, "Fahrenheit") == 0)
    {
        FahrenheitToCelsius(&temperatura); 
    }
    else
    {
        CelsiusToFahrenheit(&temperatura); 
    }
    cout << "Temeratura dupa conversie:" << temperatura;
    return 0;
}