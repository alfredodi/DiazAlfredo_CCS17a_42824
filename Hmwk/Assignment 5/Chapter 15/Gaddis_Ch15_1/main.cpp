#include <iostream>
#include <string>

#include "ProductionWorker.h"

using namespace std;

int main(int argc, char** argv) {
    
    string name;
    string hireDate;
    bool valid = true;
    float rate;
    int number;
    int shift;
    
    ProductionWorker emp;
    
    cout << "Enter Employee's Name: ";
    getline(cin,name);
    emp.setName(name);
    cout << "Employee's Id Number: ";
    cin >> number;
    emp.setID(number);
    cout << "Employee's shift [1 for morning / 2 for night]: ";
    cin >> shift;
    while(valid){
        try{
            emp.setShift(shift);
            valid = false;
        }
        catch (ProductionWorker::BadClass){
                cout << "Invalid data input. Shift must be either 1 or 2:";
                cin >> shift;
        }
    }
    cout << "Employee Pay Rate: ";
    cin >> rate;
    emp.setRate(rate);
    cout << "Employee's Hire date (mm/dd/yy): ";
    cin >> hireDate;
    emp.setHireDate(hireDate);
    
    cout << "--------------------------------------" << endl;
    cout << "Production Worker Information " << endl;
    cout << "Name: " << emp.getName() << endl;
    cout << "Employee Id: " << emp.getID() << endl;
    cout << "Hire Date: " << emp.getHireDate() << endl;
    cout << "Shift: " << emp.getShift() << endl;
    cout << "Hourly Pay Rate: $" << emp.getRate() << endl;
    cout << "--------------------------------------" << endl;
    
    return 0;
}

