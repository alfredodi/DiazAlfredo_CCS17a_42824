#include "Date.h"
#include <iostream>
#include <string>

using namespace std;

Date::Date() {
    month=0;
    day=0;
    year="";
}
void Date::setMonth(int n){
    month = n;
}
void Date::setDay(int n){
    if(n <= 31 && n >= 1){
        day = n;
    }else{
        throw BadClass();
    }
}
void Date::setYear(string n){
    year = n;
}
int Date::getMonth() const{
    return month;
}
string Date::getYear() const{
    return year;
}
int Date::getDay() const{
    return day;
}

void Date::prntMonth(){
    switch(month){
        case 1:
            cout << "January";
            break;
        case 2:
            cout << "February";
            break;
        case 3:
            cout << "March";
            break;
        case 4:
            cout << "April";
            break;
        case 5:
            cout << "May";
            break;
        case 6:
            cout << "June";
            break;
        case 7:
            cout << "July";
            break;
        case 8:
            cout << "August";
            break;
        case 9:
            cout << "September";
            break;
        case 10:
            cout << "October";
            break;
        case 11:
            cout<<"November";
            break;
        case 12:
            cout<<"December";
            break;   
    }
}
void Date::slashForm(){
    cout << month << "/" << day << "/" << year << endl;
}
void Date::cmaForm(){
    Date::prntMonth();
    cout << " " << day << "," <<year << endl;
}
void Date::mlaForm(){
    cout << day << " ";
    Date::prntMonth();
    cout << " " << year << endl;
}