/* 
 * File:   Employee.h
 * Author: Alfredo
 *
 */

#include <string>
#include <iostream>

using namespace std;

#ifndef EMPLOYEE_H
#define	EMPLOYEE_H

class Employee{
public:
    Employee();
    void setName(string);
    void setID(int);
    void setDepartment(string);
    void setPosition(string);
    string getName();
    string getDepartment();
    string getPosition();
    int getID();
private:
    string name;
    string department;
    string position;
    int id;
    
};


#endif	/* EMPLOYEE_H */

