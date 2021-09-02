#include <iostream>
using namespace std;
int x, y, no;

int main(){
    cout << "Type in two different integers: ";
    cin >> x >> y;
    no = y;
    if(x > y){
        no = x;
    }
    cout << no;
    return 0;

}