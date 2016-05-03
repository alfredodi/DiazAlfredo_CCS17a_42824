/* 
 * File:   Date.h
 * Author: Alfredo
 *
 */

#include <iostream>
using namespace std;

#ifndef DATE_H
#define	DATE_H

class Date{
public:
    void setDay(int);
    void setMonth(int);
    void setYear(int);
    int getDay();
    int getMonth();
    int getYear();
    void mmDDyy();
    void monthDayYear();
    void dayMonthYear();
private:
    int month;
    int day;
    int year;
};

#endif	/* DATE_H */

