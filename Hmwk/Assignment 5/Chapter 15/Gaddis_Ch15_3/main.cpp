#include <iostream>
using namespace std;

#include "TeamLeaders.h"
int main(int argc, char** argv) {

    string name; 
    int number; 
    string hireDate; 
    int shift; 
    float rate; 
    float bonus; 
    int hrsR;
    int hrsA; 
    TeamLeaders emp; 
    
    
    cout << "What is the required number of training hours to be a team leader?"<<endl;
    cin >> hrsR;
    emp.setTrainHoursReq(hrsR);
    cout << "What is the amount of training hours the employee has already attended?"<<endl;
    cin >> hrsA;
    emp.setTrainHoursAttn(hrsA);
    cout << "What is the name of the team leader? "<<endl;
    cin.ignore();
    getline(cin,name);
    emp.setName(name);
    cout << "What is the team leader's id number? "<<endl;
    cin >> number;
    emp.setID(number);
    cout << "What was the hire date of the team leader's? (mm/dd/yy) " << endl;
    cin >> hireDate;
    emp.setHireDate(hireDate);
    do{
        cout << "What is the team leader's shift? [1 for morning / 2 for night]"<<endl;
        cin >> shift;
        if(shift<1||shift>2)cout << "Invalid shift number" << endl;
    }while(shift<1||shift>2);
    emp.setShift(shift);
    cout << "What is the team leader's rate of pay? "<<endl;
    cin >> rate;
    emp.setRate(rate);
    cout << "What is the team leader's monthly bonus? "<<endl;
    cin >> bonus;
    emp.setMonthBonus(bonus);
    
    cout<<"--------------------------------------------"<<endl;
    cout<<"Team Leader Information " << endl;
    cout<<"Name: " << emp.getName() << endl;
    cout<<"Employee Id: " << emp.getID() << endl;
    cout<<"Hire Date: " << emp.getHireDate() << endl;
    cout<<"Shift: " << emp.getShift() << endl;
    cout<<"Monthly Bonus: $" << emp.getMonthBonus() << endl;
    cout<<"Hourly Pay Rate: $"<<emp.getRate() << endl;
    cout<<"Required Total Training Hours: "<<emp.getTrainHoursReq() << endl;
    cout<<"Training Hours Already Attended: "<<emp.getTrainHoursAttn() << endl;
    if(hrsA<hrsR){
        cout << "Hours Still Needed: "<<(emp.getTrainHoursReq()-emp.getTrainHoursAttn()) << endl;
    }
    cout<<"---------------------------------------------"<<endl;
    return 0;
}

