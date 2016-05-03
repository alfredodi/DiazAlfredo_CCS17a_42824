/* 
 * File:   main.cpp
 * Author: Alfredo
 *
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <string>
#include <iomanip>

// Classes for chapter 13 problems
#include "Date.h"
#include "Employee.h"
#include "Car.h"
#include "Personal.h"
#include "RetailItem.h"

// Classes for chapter 14 problems
// got too lazy in making an individual one for each class
#include "chapter14_Classes.h"

using namespace std;

//Function Prototypes
void Menu();
int getN();
void def(int);
void problem1();
void problem2();
void problem3();
void problem4();
void problem5();
void problem6();
void problem7();
void problem8();
void problem9();
void problem10();

//Execution begins Here
int main(int argc, char** argv) {
int inN;
    do{
        Menu();
        inN=getN();
        switch(inN){
        case 1:    
            problem1();
            break;
        case 2:    
            problem2();
            break;
        case 3:    
            problem3();
            break;
        case 4:    
            problem4();
            break;
        case 5:    
            problem5();
            break;
        case 6:    
            problem6();
            break;
        case 7:    
            problem7();
            break;    
        case 8:
            problem8();
            break;
        case 9:
            problem9();
            break;
        case 10:
            problem10();
            break;
        default:   
            def(inN);
        }
    }while(inN >= 1 && inN <= 10);
    
    return 0;
}

void Menu(){
    cout << "Menu for the Assignment #4" << endl;
    cout << "Type 1 for problem 1" << endl;
    cout << "Type 2 for problem 2" << endl;
    cout << "Type 3 for problem 3" << endl;
    cout << "Type 4 for problem 4" << endl;
    cout << "Type 5 for problem 5" << endl;
    cout << "Type 6 for problem 6" << endl;
    cout << "Type 7 for problem 7" << endl;
    cout << "Type 8 for problem 8" << endl;
    cout << "Type 9 for problem 9" << endl;
    cout << "Type 10 for problem 10" << endl;
    cout << "Type anything else to exit \n" << endl;
}

int getN(){
        int inN;
        cout << "Enter your choice:";
        cin >> inN;
        return inN;
}

void def(int inN){
        cout << "You typed " << inN << " to exit the program" << endl;
}

void problem1(){
    //Declare and initialize the variables
    int day = 0;
    int month = 0;
    int year = 0;
    
    Date Instance;
    
    cout << "Enter the month:";
    cin >> month;
    
    while(month > 12 || month < 1){
        if(month > 12 || month < 1){
            cout << "ERROR!! Please enter a valid month January-December."
                 << endl;
        }
        cin >> month;
    }
    Instance.setMonth(month);
    
    cout << "Enter the day:";
    cin >> day;
    
    while(day > 31 || day < 1){
        if(day > 31 || day < 1){
            cout << "ERROR!! Please enter a valid day 1-31."
                 << endl;
        }
        cin >> day;
    }
    Instance.setDay(day);

    cout << "Please enter the year." << endl;
    cin >> year; 
    Instance.setYear(year);
    
    Instance.mmDDyy();
    Instance.monthDayYear();
    Instance.dayMonthYear();
}

void problem2(){
    string name;
    string department;
    string position;
    int id;
    
    Employee Record1;
    Employee Record2;
    Employee Record3;
    
    Record1.setName("Susan Meyers");
    Record1.setID(47899);
    Record1.setDepartment("Accounting");
    Record1.setPosition("Vice President");
    Record2.setName("Mark Jones");
    Record2.setID(391119);
    Record2.setDepartment("IT");
    Record2.setPosition("Programmer");
    Record3.setName("Joy Rogers");
    Record3.setID(81774);
    Record3.setDepartment("Manufacturing");
    Record3.setPosition("Engineer");
    
    cout << "----------------------------------"
            "-----------------------------------" << endl;
    cout << "* Name           ID Number           Department"
            "           Position" << endl;
    cout << "----------------------------------"
            "-----------------------------------" << endl;
    cout << Record1.getName() << "       "
            <<Record1.getID() << "             "
            <<Record1.getDepartment() << "           "
            <<Record1.getPosition()<<endl;
    cout << Record2.getName() << "         "
            <<Record2.getID() << "                 "
            <<Record2.getDepartment() << "               "
            <<Record2.getPosition()<<endl;
    cout << Record3.getName() << "         "
            <<Record3.getID() << "             "
            <<Record3.getDepartment() << "           "
            <<Record3.getPosition()<<endl;
    cout << "-------------------------------------"
            "--------------------------------" << endl;
}

void problem3(){
    int year;
    string make;
    Car object;
    
    cout << "Please enter the model year of the car." << endl;
    cin >> year;
    object.setModel(year);
    cout << "Please enter the make of the car." << endl;
    cin >> make;
    object.setMake(make);
    cout << "The year of the car is ";
    cout << object.getModel() << endl;
    cout << "The make of the car is ";
    cout << object.getMake();
    cout << endl << endl << "The car will accelerate five times." << endl;
    cout << "The speed of the car after the first time is:" << endl;
    object.accel();
    cout << "The speed of the car after the second time is:" << endl;
    object.accel();
    cout << "The speed of the car after the third time is:" << endl;
    object.accel();
    cout << "The speed of the car after the fourth time is:" << endl;
    object.accel();
    cout << "The speed of the car after the fifth time is:" << endl;
    object.accel();
    
    
    cout << endl << endl << "The car will brake five times." << endl;
    cout << "The speed of the car after the first time is:" << endl;
    object.brake();
    cout << "The speed of the car after the second time is:" << endl;
    object.brake();
    cout << "The speed of the car after the third time is:" << endl;
    object.brake();
    cout << "The speed of the car after the fourth time is:" << endl;
    object.brake();
    cout << "The speed of the car after the fifth time is:" << endl;
    object.brake();
}

void problem4(){
    string name;
    string add;
    int age;
    string phone;
    char choice;
    Personal mine;
    Personal family;
    Personal friends;
    
    cout << "Whose personal information will you be recording?" << endl;
    cout << "Enter f for family,m for mine, or r for friend." << endl;
    cin >> choice;
    choice=toupper(choice);
    cin.ignore();
    if(choice=='F')
    {
        cout << "What is your family member's name?" << endl;
        getline(cin,name);
        family.setName(name);
        cout << "What is your family member's address?" << endl;
        getline(cin,add);
        family.setAdd(add);
        cout << "What is your family member's age?" << endl;
        cin >> age;
        family.setAge(age);
        cout << "What is your family member's Phone number?" << endl;
        cin.ignore();
        getline(cin,phone);
        family.setPhone(phone);
        
        cout << endl << endl << endl;
        cout << "Information entered:" << endl;
        cout << "Name: " << family.getName() << endl;
        cout << "Address: " << family.getAdd() << endl;
        cout << "Age: " << family.getAge() << endl;
        cout << "Phone Number: " << family.getPhone() << endl;
    }
    else if(choice=='M')
    {
        cout << "What is your name?" << endl;
        getline(cin,name);
        mine.setName(name);
        cout << "What is your address?" << endl;
        getline(cin,add);
        mine.setAdd(add);
        cout << "What is your age?" << endl;
        cin >> age;
        mine.setAge(age);
        cout << "What is your Phone number?" << endl;
        cin.ignore();
        getline(cin,phone);
        mine.setPhone(phone);
        
        cout << endl<<endl<<endl;
        cout << "Information entered:" << endl;
        cout << "Name: " << mine.getName()<<endl;
        cout << "Address: " << mine.getAdd()<<endl;
        cout << "Age: " << mine.getAge()<<endl;
        cout << "Phone Number: " << mine.getPhone()<<endl;
    }
    else if(choice=='R')
    {
        cout << "What is your friend's name?" << endl;
        getline(cin,name);
        friends.setName(name);
        cout << "What is your friend's address?" << endl;
        getline(cin,add);
        friends.setAdd(add);
        cout << "What is your friend's age?" << endl;
        cin >> age;
        friends.setAge(age);
        cout << "What is your Phone friend's number?" << endl;
        cin.ignore();
        getline(cin,phone);
        friends.setPhone(phone);
        
        cout << endl<<endl<<endl;
        cout << "Information entered:" << endl;
        cout << "Name: " << friends.getName()<<endl;
        cout << "Address: " << friends.getAdd()<<endl;
        cout << "Age: " << friends.getAge()<<endl;
        cout << "Phone Number: " << friends.getPhone()<<endl;
    }
    else
    {
        cout << "Please restart and enter a correct letter choice." << endl;
    }
}

void problem5(){
     string descrpttion;
    int unit;
    float price;
    RetailItem item1;
    RetailItem item2;
    RetailItem item3;
    
    item1.setDescription("Jacket");
    item1.setUnit(12);
    item1.setPrice(59.95);
  
    item2.setDescription("Designer Jeans");
    item2.setUnit(40);
    item2.setPrice(34.95);
    
    item3.setDescription("Shirt");
    item3.setUnit(20);
    item3.setPrice(24.95);
    
    cout << "--------------------------------"
            "-------------------------------------" << endl;
    cout << "                 Description           "
            "Units on Hand       Price           " << endl;
    cout << "----------------------------------"
            "-----------------------------------" << endl;
    cout << "Item #1          "
         << item1.getDescription() << "                     "
            <<item1.getUnit() << "            $" << item1.getPrice() << endl;
    cout << "Item #2          "
         << item2.getDescription() << "             "
         << item2.getUnit() << "            $" << item2.getPrice() << endl;
    cout << "Item #3          "
         << item3.getDescription() << "                      "
         << item3.getUnit() << "            $" << item3.getPrice() << endl;
    cout << "-----------------------------------"
          "----------------------------------" << endl;
}

void problem6(){
    int inputDays;
    cout << "Please the day in digit form: ";
    cin >> inputDays;
    
    DayOfYear a(inputDays);
    a.calculate();
    a.displayDay();
    cout << endl;
}

void problem7(){
    int inputDays;
        
    cout << "Enter a day of the year: ";
    cin >> inputDays;
       
    DayOfYearProb3 instance(inputDays);
    instance.calculate();
    instance.display();

    cout  << "\n-------------\n";
    for(int count = 0; count < 90; count++){
        inputDays++;
        instance.setDay(inputDays);
        instance.calculate();
        instance.display();
    }
    cout << endl;
}
    
void problem8(){
    int hour, day;
    NumDays one, two, result;
    
    cout << "First Info.:\n";
    cout << "Please enter the amount of day(s): ";
    cin >> day;
    cout << "Please enter amount of hour(s): ";
    cin >> hour;
    
    one.setHour(hour);
    one.setDays(day);

    cout << "\nSecond Info.:\n";
    cout << "Please enter the amount of day(s): ";
    cin >> day;
    cout << "Please enter amount of hour(s): ";
    cin >> hour;

    two.setHour(hour);
    two.setDays(day);

    result = one + two;
    
    cout << "\nSummed = ";
    cout << result.getDays() << " day(s) & " 
         << result.getHour() << " hour(s)\n";
       
    result = one - two;

    cout << "\nSubtracted = " << result.getDays() << " day(s) & " 
         << result.getHour() << " hour(s)\n";

    cout << "\n++ Operator (Adds an hour each time)\n";
    cout << "-------------------------------\n";
    
    for(int count = 0; count < 20; count++){
        result.operator ++();
        cout << result.getDays() << " day(s) and " << result.getHour()
             << " hour(s)\n";
    }
    cout << "\n--Operator (Deducts an hour each time)\n";
    cout << "-------------------------------\n";
    
    for(int count = 0; count < 20; count++){
        result.operator --();
        cout << result.getDays() << " day(s) and " << result.getHour()
             << " hour(s)\n";
    }
    cout << endl;
}

void problem9(){
    DateProb4 instance;
    instance.setMonth();
    instance.setDay();
    instance.setYear();
    instance.display();
    for(int count = 0; count < 12; count++){
        instance.operator ++();
        instance.display();
    }
    cout << endl;
}
    
void problem10(){
    DivSales DivisionSale[6];
    int quarter, division;

    for (division = 0; division < 6; division++){
        int Qrt1, Qrt2, Qrt3, Qrt4;
        int check;

        cout << "\nEnter Sales of Division: " << division+1<<endl;
        cout << "Enter Quarter 1 Sales: ";
        cin >> Qrt1;
        check = Qrt1;
        if (check < 0){
            validate();
        }

        cout << "\nEnter Quarter 2 Sales: ";
        cin >> Qrt2;
        check = Qrt2;
        if (check < 0){
            validate();
        }

        cout << "\nEnter Quarter 3 Sales: ";
        cin >> Qrt3;
        check = Qrt3;
        if (check < 0){
            validate();
        }
        
        cout << "\nEnter Quarter 4 Sales: ";
        cin >> Qrt4;
        check = Qrt4;
        if (check < 0){
            validate();
        }
        
        DivisionSale[division].totalSales(Qrt1,Qrt2,Qrt3,Qrt4);
    }
    
    cout << "\n---------------Results---------------\n";
    cout << "\t" << "Q1" << "\t" << "Q2" << "\t" << "Q3" << "\t" << "Q4\n";
    for (division = 0; division < 6; division++){
        cout << "Div " << division + 1;
        
        for (quarter = 0; quarter < 4; quarter++){
            cout << "\t$" << DivisionSale[division].Sales(quarter);
        }
        cout << endl;
    }
    cout << "\n\nTotal Annual Sales: ";
    cout << "$ " << DivisionSale[0].getvalue()<<endl;
    cout << endl;
}




