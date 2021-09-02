
/* 
    This program greets a user and calculates area of given circle
*/
#include <iostream>
#include <string>

using namespace std;

double radius, area;
string name;

int main(){
    cout <<  "Your name: ";
    cin >> name;
    cout << "Welcome " << name << "!" << endl;
    cout << "Radius of circle: ";
    cin >> radius;
    area = 3.14 * radius * radius;
    cout << "Area of your circle is: " << area << endl;
    return 0;
}