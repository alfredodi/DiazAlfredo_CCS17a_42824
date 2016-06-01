#include <iostream>

using namespace std;

#include "Date.h"

int main(int argc, char** argv) {

    int day;
    int month; 
    string year;
    bool valid = true;
    Date info;
    
    do{
        cout << "Input the month: ";
        cin >> month;
        if(month > 12 || month < 1)
            cout << "Invalid month entry." << endl;
    }while(month > 12 || month < 1);
    info.setMonth(month);
    cout << "Input the day: ";
    cin >> day;
    while(valid){
        try{
            info.setDay(day);
            valid = false;
        }catch(Date::BadClass){
            cout << "Invalid Entry. Input Day:" << endl;
            cin >> day;
        }
    }
    do{
        cout << "Input the year: ";
        cin >> year;
    }while(year.length()!=4);
    info.setYear(year);
    cout << "The date in its three forms: " << endl;
    info.slashForm();
    info.cmaForm();
    info.mlaForm();
    return 0;
}
