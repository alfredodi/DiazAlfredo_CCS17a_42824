 /*
  * File:   Date.cpp
  * Author: Alfredo
  * 
  */

#include "Date.h"

void Date::setDay(int x){
    day = x;
}

int Date::getDay(){
    return day;
}

void Date::setMonth(int x){
    month = x;
}

int Date::getMonth(){
    return month;
}

void Date::setYear(int x){
    year = x;
}

int Date::getYear(){
    return year;
}

void Date::mmDDyy(){
    cout << endl;
    cout << month << "/" << day << "/" << year;
    cout << endl;
}

void Date::monthDayYear(){
    switch(month){
        case 1: 
            cout << "January ";
            break;
        case 2:
            cout << "February ";
            break;
        case 3:
            cout << "March ";
            break;
        case 4:
            cout << "April ";
            break;
        case 5:
            cout << "May ";
            break;
        case 6:
            cout << "June ";
            break;
        case 7:
            cout << "July ";
            break;             
        case 8:
            cout << "August ";
            break;             
        case 9:
            cout << "September ";
            break;             
        case 10:
            cout << "October ";
            break;             
        case 11:
            cout << "November ";
            break;             
        case 12:
            cout << "December ";
            break; 
        default:
            cout << "Illegal Month Declaration!";
    }
    cout << day << "," << year << endl;
}

void Date::dayMonthYear(){
    cout << day;
        switch(month){
        case 1: 
            cout << "January ";
            break;
        case 2:
            cout << "February ";
            break;
        case 3:
            cout << "March ";
            break;
        case 4:
            cout << "April ";
            break;
        case 5:
            cout << "May ";
            break;
        case 6:
            cout << "June ";
            break;
        case 7:
            cout << "July ";
            break;             
        case 8:
            cout << "August ";
            break;             
        case 9:
            cout << "September ";
            break;             
        case 10:
            cout << "October ";
            break;             
        case 11:
            cout << "November ";
            break;             
        case 12:
            cout << "December ";
            break; 
        default:
            cout << "Illegal Month Declaration!";
    }
    cout << year << endl;
}