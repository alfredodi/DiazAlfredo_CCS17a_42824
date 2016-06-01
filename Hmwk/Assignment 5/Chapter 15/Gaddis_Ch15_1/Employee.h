/* 
 * File:   Employee.h
 * Author: Alfredo
 *
 * Created on May 31, 2016, 8:10 PM
 */

#ifndef EMPLOYEE_H
#define	EMPLOYEE_H

#include <string>

using namespace std;

class Employee{
    private:
        string name;
        string hireDate;
        int id;
    public:
        Employee();
        void setName(string);
        void setID(int);
        void setHireDate(string);
        string getName();
        string getHireDate();
        int getID();
    
        
};

#endif	/* EMPLOYEE_H */

