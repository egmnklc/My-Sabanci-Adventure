#include <iostream>
using namespace std;

int ifahr;
double dfahr;

int main(){

    cout << "Enter another temperature: ";
    cin >> dfahr;
    cout << dfahr << " F = " << (dfahr-32) * 5/9 << " Celcius" << endl;

    cout << "Enter a Fahrenheit temperature: ";
    cin >> ifahr;
    cout << ifahr << " F = " << (ifahr-32) * 5/9 << " Celcius" << endl;

    return 0;     

}