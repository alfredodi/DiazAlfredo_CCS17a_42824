#include "Employee.h"

using namespace std;

Employee::Employee(){
    
    name="";
    id=0;
    hireDate="";
    
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
void Employee::setHireDate(string x){
    hireDate = x; 
}
string Employee::getHireDate(){
    return hireDate;
}
