/* 
 * File:   ShiftSupervisor.h
 * Author: Alfredo
 *
 * Created on May 31, 2016, 9:08 PM
 */

#ifndef SHIFTSUPERVISOR_H
#define	SHIFTSUPERVISOR_H

#include "Employee.h"

class ShiftSupervisor : public Employee{
    protected:
        float salary;
        float bonus;
    public:
        ShiftSupervisor();
        void setSalary(float);
        float getSalary();
        void setBonus(float);
        float getBonus();
};

#endif	/* SHIFTSUPERVISOR_H */

