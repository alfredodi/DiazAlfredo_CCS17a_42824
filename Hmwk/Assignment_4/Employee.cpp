/*
 *
 * file: Employee.cpp
 * Author: Alfredo Diaz
 * 
 */

#include "Employee.h"

Employee::Employee(){
    name = "";
    id = 0;
    department = "";
    position = "";
}

void Employee::setName(string x){
    name = x;
}

string Employee::getName(){
    return name;
}

void Employee::setID(int x){
    id = x;
}

int Employee::getID(){
    return id;
}

void Employee::setDepartment(string x){
    department = x;
}

string Employee::getDepartment(){
    return department;
}

void Employee::setPosition(string x){
    position = x;
}

string Employee::getPosition(){
    return position;
}