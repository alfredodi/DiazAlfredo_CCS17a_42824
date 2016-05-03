/* 
 * File:   Car.h
 * Author: Alfredo
 *
 */

#include <string>
#include <iostream>

using namespace std;

#ifndef CAR_H
#define	CAR_H

class Car {
private:
    int year;
    int speed;
    string make;
public:
    Car();
    void setModel(int);
    void setMake(string);
    string getMake();
    int getModel();
    int accel();
    int brake();
};

#endif	/* CAR_H */