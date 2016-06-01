#include <iostream>

#include "AbsoluteValue.h"
using namespace std;

int main(int argc, char** argv) {
    
    float number;
    AbsValue <float> num;
    
    cout << "Enter a number to find its absolute value: " << endl;
    cin >> number;
    num.setAbsolute(number);
    
    cout << num.findAbsolute();
    
    return 0;
}

