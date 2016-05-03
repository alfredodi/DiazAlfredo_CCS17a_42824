/* 
 * File:   main.cpp
 * Author: Alfredo
 *
 */

#include "Car.h"

Car::Car(){
    speed=0;
}
void Car::setModel(int x){
    year=x;
}

int Car::getModel(){
    return year;
}

void Car::setMake(string x){
    make=x;
}

string Car::getMake(){
    return make;
}

int Car::accel(){
    speed+=5;
    cout << speed << endl;
}

int Car::brake(){
    speed-=5;
    cout << speed << endl;
}