#include <iostream>
#include "lib/sad.h"

using namespace std;

int main(){
    string day;
    int num;
    cin >> day >> num;
    cout << sad(day, num);
}