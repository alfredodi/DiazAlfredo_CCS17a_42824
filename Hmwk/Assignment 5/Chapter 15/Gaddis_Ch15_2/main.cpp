/* 
 * File:   main.cpp
 * Author: Alfredo
 *
 * Created on May 31, 2016, 9:05 PM
 */

#include <iostream>

#include "ShiftSupervisor.h"

using namespace std;

int main(int argc, char** argv) {

    string name; 
    int number; 
    string hireDate; 
    int shift; 
    float salary; 
    float bonus;
    ShiftSupervisor emp;
    
    cout << "Employee's Name: "<<endl;
    getline(cin,name);
    emp.setName(name);
    cout << "Employee's Id:  " << endl;
    cin >> number;
    emp.setID(number);
    cout<<"Employee's Hire Date (mm/dd/yy) : "<<endl;
    cin>>hireDate;
    emp.setHireDate(hireDate);
    cout<<"What is the supervisor's annual salary? "<<endl;
    cin>>salary;
    emp.setSalary(salary);
    cout<<"What is the production bonus the supervisor made?"<<endl;
    cin>>bonus;
    emp.setBonus(bonus);
    
    
    cout << "--------------------------------------" << endl;
    cout << "Shift Supervisor Information " << endl;
    cout << "Name: "<<emp.getName() << endl;
    cout << "Employee Id: " << emp.getID() << endl;
    cout << "Hire Date: " << emp.getHireDate() << endl;
    cout << "Annual Salary: $" << emp.getSalary() << endl;
    cout << "Bonus: $" << emp.getBonus() << endl;
    cout << "Total Salary with Bonus: " 
         << (emp.getSalary() + emp.getBonus()) << endl;
    cout << "--------------------------------------" << endl;
    return 0;
}
