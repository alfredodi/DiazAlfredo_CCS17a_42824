#include "ShiftSupervisor.h"
#include "Employee.h"
ShiftSupervisor::ShiftSupervisor() : Employee() {
    salary = 0.0;
    bonus = 0.0;
}
void ShiftSupervisor::setSalary(float x){
    salary = x;
}
float ShiftSupervisor::getSalary(){
    return salary;
}
void ShiftSupervisor::setBonus(float x){
    bonus = x;
}
float ShiftSupervisor::getBonus(){
    return bonus;
}