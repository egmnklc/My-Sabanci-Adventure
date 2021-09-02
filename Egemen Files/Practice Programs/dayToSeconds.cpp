#include <iostream>
using namespace std;

double days, seconds;

int main() {
    cout << "Type in day no to convert to seconds: ";
    cin >> days;
    seconds = days * 24 * 3600;
    cout << days << " day is " << seconds << " seconds." << endl;
    return 0;
}