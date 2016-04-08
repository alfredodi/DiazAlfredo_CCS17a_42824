/* 
 * File:   main.cpp
 * Author: Alfredo
 *
 * Created on April 6, 2016, 7:49 PM
 */

//Library includes Here!!!
#include <iostream>
#include <string>
#include <iomanip>
#include <bits/stdc++.h>
using namespace std;

//Global Constants Here!!!

//Function Prototypes Here!!!
void Menu();
int getN();
void def(int);
void problem1();
void pntDol(float, bool = true);
void problem2();
void problem3();
void problem4();
void problem5();
void problem6();
void check(int &,int []);
void display(int []);

//Structures
struct Banking{
    string Name;
    string Address;
    char Account[6];
    float Balance;
    float Withdraw;
    float Deposit;
};
struct Payroll{
   string ename;
   string address;
   int hours;
   float pay;
};
void info(Payroll*, int);
float payCalc(Payroll *,float &);
string nToS(int);
struct statsResult
{
    float avg;
    float median;
    int *mode;   //array containing the modes
    int nModes;  //number of modes in the array
    int maxFreq; //max frequency of modes
};
int *fillAry(int);
void fillMod(int,int*);
void prntAry(int *,int);
void markSrt(int *,int);
int *mode(int *,int,int,int);
int findMax (int*,int);
void prntMod(int *,int);
int numMode(int *,int,int);
int *freqF(int*,int,int);
float med(int*,int);
float mean(int*,int);
statsResult printStat(int*,int,int,statsResult);

//Begin Execution Here!!!
int main(int argv,char *argc[]){
    int inN;
    do{
        Menu();
        inN=getN();
        switch(inN){
        case 1:    problem1();break;
        case 2:    problem2();break;
        case 3:    problem3();break;
        case 4:    problem4();break;
        case 5:    problem5();break;
        case 6:    problem6();break;
        default:   def(inN);}
    }while(inN>=1&&inN<=6);
    return 0;//If midterm not perfect, return something other than 1
}
void Menu(){
    cout<<"Menu for the Midterm"<<endl;
    cout<<"Type 1 for problem 1"<<endl;
    cout<<"Type 2 for problem 2"<<endl;
    cout<<"Type 3 for problem 3"<<endl;
    cout<<"Type 4 for problem 4"<<endl;
    cout<<"Type 5 for problem 5"<<endl;
    cout<<"Type 6 for problem 6"<<endl;
    cout<<"Type anything else to exit \n"<<endl;
}
int getN(){
        int inN;
        cout << "Enter your choice:";
        cin>>inN;
        return inN;
}
void problem1(){
    Banking *custom = new Banking;
    bool valid = false;
    const float OVERDRAFT = 15.0;
    const unsigned char LENGTH = 5;
    int temp=0;
    int answer=0;
    int balance=0;
    float chk =0.0, dep = 0.0;
    string in;
    
    cout << "Name:";
    cin.ignore();
    getline(cin,custom->Name);
    cout << "Address:";
    getline(cin,custom->Address);
    
    do{
        cout << "Enter the 5-digit account number:";
        cin >> in;
        if(in.size() == LENGTH){
            int i = 0;
            while(i != LENGTH){
                if(!isdigit(in[i]))
                    break;
                i++;
            }
            if(i == LENGTH)
                valid = true;
        }
    }
    while(!valid);
    for(int i=0;i != LENGTH;++i)
        custom->Account[i]=in[i];
        custom->Account[LENGTH]= '\0';
        cout << "Balance:";
        cin >> custom->Balance;
        
        cout << "Enter check written this month.Enter 0 when last one"
             << "is given.\n";
        do{
            cin >> chk;
            if(chk > 0.0)
                custom->Withdraw += chk;
        }while(chk > 0.0);
        cout << "Enter the deposits made this month. Enter 0 when last one"
             << "is given.\n";
        do{
            cin >> dep;
            if(dep > 0.0){
                custom->Deposit += dep;
            }
        }
        while(dep > 0.0);
        float nBalance = custom->Balance + custom->Deposit - custom->Withdraw;
        if(nBalance){
            cout << "You were charged the overdraft fee!" << endl;
            cout << "A fee of $15 has been applied to your account." << endl;
            nBalance -= OVERDRAFT;
        }
        cout << endl 
		 << "Account Information" << endl
	     << "-------------------" << endl
	     << "Name             : " 
	     << custom->Name << endl
	     << "Address          : " 
	     << custom->Address << endl
	     << "Account Number   : " 
	     << custom->Account << endl;
	cout << "Starting Balance : " ;
	pntDol(custom->Balance);
	cout << "Checks Written   : " ;
	pntDol(custom->Withdraw);
	cout << "Deposits Made    : "; 
	pntDol(custom->Deposit);
	cout << "Current Balance  : " ;
	pntDol(nBalance);
	cout << endl;
	     
	// Free memory used for dynamic structure
	delete custom;
    
}
void pntDol(float amt, bool nLn)
{
	string sign;
	sign = amt < 0 ? "-$" : "$";
	cout <<sign << fixed << setprecision(2);
	cout << (amt < 0 ? -amt : amt);
	if (nLn) cout << endl;
}
void problem2(){
    Payroll *employee;
    int size =0;
    float total;
    string company;
    
    cout << "In problem # 2" << endl;
    cout << "Enter the number of employee's:";
    cin >> size;
    employee = new Payroll[size];
    cout << "What is the company name?" << endl;
    cout << "Enter for each of the employee's" << endl;
    for(int i=0;i<size;i++){
        info(employee,size);
        float gross = payCalc(employee,total);
        cout << "-----------------------------------------------------" << endl;
        cout << "Paycheck" << endl;
        cout << company << endl;
        cout << employee->address << endl;
        cout<<"Name:" << employee->ename << "\t" << " Amount: $"<< total << endl;
        int dollars = floor(total);
        float cents=(total-dollars)*100;
        if(cents==0){
            string temp=nToS(dollars)+"dollars ";
            cout<<temp<<endl;
        }
        else{
            string temp=nToS(dollars)+"dollars "+nToS(cents)+"cents";
            cout<<temp<<endl;
        }
        cout<<"Signature:\n"<<employee->ename<<endl;
        cout<<"-----------------------------------------------------"<<endl;
    }
}
void info(Payroll *employee, int size){
    cout << "Employee Name:" << endl;
    cin.ignore();
    getline(cin,employee->ename);
    cout << "Enter Address:" << endl;
    getline(cin,employee->address);
    do{
        cout << "Hours worked:" << endl;
        cin >> employee->hours;
        if(employee->hours < 0){
            cout << "ERROR - you can not have a negative hours." <<endl;
        }
    }
    while(employee->hours < 0);
    do{
        cout << "Pay Rate:" << endl;
        cin >> employee->pay;
        if(employee->pay<0){
            cout << "ERROR - you can not have negative pay." << endl;
        }
    }
    while(employee->pay < 0);
}
float payCalc(Payroll *employee, float &total){
    if(employee->hours <= 40){
        total = (employee->hours)*(employee->pay);
        cout << "Gross Pay:$" << total <<endl;
    }
    else if(employee->hours > 40 && employee->hours < 50){
        total = 40*employee->pay+(employee->pay*2.0f)*(employee->hours - 40);
        cout << "Gross Pay:$" << total << endl;
    }
    else{
        total = 40*employee->pay+(employee->pay*2.0f)*50+(employee->pay*3.0f)*
                (employee->hours-50);
        cout << "Gross Pay:$" << total << endl;
    }
    return total;
}
string nToS(int n){
    int one, ten, hundred, thousand, tenThousand;
    unsigned int amt=n;
    string answer = "";
    thousand = n/1000;
    amt = (amt - thousand*1000);
    hundred = n/100;
    amt =(amt - hundred*100);
    ten = amt/10;
    amt = (amt - ten*10);
    one = amt;
    
        switch(thousand){
        case 9:  answer+="Nine Thousand";break; 
        case 8:  answer+="Eight Thousand ";break;
        case 7:  answer+="Seven Thousand ";break;
        case 6:  answer+="Six Thousand ";break;
        case 5:  answer+="Five Thousand ";break;
        case 4:  answer+="Four Thousand ";break;
        case 3:  answer+="Three Thousand ";break;
        case 2:  answer+="Two Thousand ";break;
        case 1:  answer+="One Thousand ";break;
    }
    switch(hundred){
        case 9:  answer+="Nine Hundred ";break; 
        case 8:  answer+="Eight Hundred ";break;
        case 7:  answer+="Seven Hundred ";break;
        case 6:  answer+="Six Hundred ";break;
        case 5:  answer+="Five Hundred ";break;
        case 4:  answer+="Four Hundred ";break;
        case 3:  answer+="Three Hundred ";break;
        case 2:  answer+="Two Hundred ";break;
        case 1:  answer+="One Hundred ";break;
    }
    switch(ten){
        case 9:  answer+="Ninety ";break;
        case 8:  answer+="Eighty ";break;
        case 7:  answer+="Seventy ";break;
        case 6:  answer+="Sixty ";break;
        case 5:  answer+="Fifty ";break;
        case 4:  answer+="Forty ";break;
        case 3:  answer+="Thirty ";break;
        case 2:  answer+="Twenty ";break;
        case 1:  answer+="Ten ";break;
    }
    switch(one){
        case 9:  answer+="Nine ";break;
        case 8:  answer+="Eight ";break;
        case 7:  answer+="Seven ";break;
        case 6:  answer+="Six ";break;
        case 5:  answer+="Five ";break;
        case 4:  answer+="Four ";break;
        case 3:  answer+="Three ";break;
        case 2:  answer+="Two ";break;
        case 1:  answer+="One ";break;
    }
    return answer;
}
void problem3(){
    cout<<"In problem # 3"<<endl<<endl;
    statsResult data;
    int size;
    int mod = 10;
    cout<<"Enter the size of the array: ";
    cin>>size;
    int array[size];
    for(int i=0;i<size;i++){
        cout<<"Enter the value for element #" << i+1 << ":";
        cin>>array[i];
    }
    //avgMedMode(array,size);
    printStat(array,mod,size,data);
    cout<<endl;
}
void problem4(){
    int srt=0;
    const int SIZE=4;
    int in,data,temp;
    int ary[SIZE];
    cout<<"In problem # 4"<<endl<<endl;
    do{
        cout<<"Menu"<<endl;
        cout<<"1.) Encrypt"<<endl;
        cout<<"2.) Decrypt"<<endl;
        cout<<"3.) Exit"<<endl;
        cout<<"Type in the number related to your choice from the menu above."<<endl;
        cin>>in;
        if(in==1){
            cout<<"Enter 4 digit integer between 0~7"<<endl;
            cin>>data;
            check(data,ary);
            //Each digit +3 % 8
            ary[0]=(ary[0]+5)%8;
            ary[1]=(ary[1]+5)%8;
            ary[2]=(ary[2]+5)%8;
            ary[3]=(ary[3]+5)%8;
            //Swap First 2
            temp=ary[0];
            ary[0]=ary[1];
            ary[1]=temp;
            //Swap Last 2
            temp=ary[2];
            ary[2]=ary[3];
            ary[3]=temp;
            //Display After
            cout<<"Encrpyted Data:";
            display(ary);
        }
        if(in==2){
            cout<<"Enter 4 digit integer to decrypt"<<endl;
            cin>>data;
            for(int i=3;i>=0;i--){
                ary[i]=data%10;
                data/=10;
            }
            //Swap
            temp=ary[0];
            ary[0]=ary[1];
            ary[1]=temp;
            temp=ary[2];
            ary[2]=ary[3];
            ary[3]=temp;
            //
            bool a1=1,a2=1,a3=1,a4=1;
            if(ary[0]-5<0&&a1==1){
                ary[0]=ary[0]+3;
                a1=0;
            }
            if(ary[1]-5<0&&a2==1){
                ary[1]=ary[1]+3;
                a2=0;
            }
            if(ary[2]-5<0&&a3==1){
                ary[2]=ary[2]+3;
                a3=0;
            }
            if(ary[3]-5<0&&a4==1){
                ary[3]=ary[3]+3;
                a4=0;
            }
            if(ary[0]-5<5&&a1==1){
                ary[0]=ary[0]-5;
                a1=0;
            }
            if(ary[1]-5<5&&a2==1){
                ary[1]=ary[1]-5;
                a2=0;
            }
            if(ary[2]-5<5&&a3==1){
                ary[2]=ary[2]-5;
                a3=0;
            }
            if(ary[3]-5<5&&a4==1){
                ary[3]=ary[3]-5;
                a4=0;
            }
            cout<<"Decrypted 4 Digit Integer"<<endl;
            display(ary);
        }
        if(in==3)srt=1;
        cout<<endl;
    }while(srt==0);
}
void problem5(){
    cout<<"In problem # 5"<<endl<<endl;
    cout << "Char:5 signed and 5 unsigned" << endl;
    cout << "Short:7 signed and 17 unsigned"<<endl;
    cout << "Int:16 signed and 17 unsigned"<<endl;
    cout << "Long:19 signed and 20 unsigned "<<endl;
    cout << "Float:34" <<endl;
    cout << "Double:170"<<endl;
    cout << endl;
}
void problem6(){
    cout << "PART A----------------"<<endl;
    cout << "Convert the following 2 numbres to binary, octal, and hex."<<endl;
    cout << "2.125, 0.1328125"<<endl;
    cout << "--------------"<<endl;
    cout << "2.125  base 10"<<endl;
    cout << "10.001 base 2"<<endl;
    cout << "2.1    base 8"<<endl;
    cout << "2.2    base 16"<<endl;
    cout << "-------------"<<endl;
    cout << "0.1328125  base 10"<<endl;
    cout << "0.0010001 base 2"<<endl;
    cout << "0.0104     base 8"<<endl;
    cout << "0.22       base 16"<<endl;
    cout << "PART B----------------"<<endl;
    cout << "Convert -2.125, -0.1328125 to float representation"<<endl;
    cout << "-------------"<<endl;
    cout << "-2.125"<<endl;
    cout << "BC000002"<<endl;
    cout << "-------------"<<endl;
    cout << "-0.1328125"<<endl;
    cout << "BC0000FE"<<endl;
    cout << "PART C----------------"<<endl;
    cout << "46666601 is 1.1 in base 10" << endl;
    cout << "46666602 is 2.2 in base 10" << endl;
    cout << "B9999AFE is -.1375 in base 10" << endl;
    
    
    cout<<endl;
}
void def(int inN){
        cout << "You typed " << inN << " to exit the program" << endl;
}
void check(int &data,int a[]){
    a[0]=data/1000;
    //If first digit isn't 0
    if(a[0]==!0){
        while(data>9999||data<1000){
            cout << "Enter 4 digit integer between 0~7"<<endl;
            cin>>data;
        }
    }
    for(int i=3;i>=0;i--){
        a[i]=data%10;
        data/=10;
    }
    //Check 0~7
    for(int i=0;i<4;i++){
        if(a[i]<0||a[i]>7){
            while(a[i]<0||a[i]>7){
                cout << "Enter 4 digit integer between 0~7"<<endl;
                cin >> data;
                for(int i=3;i>=0;i--){
                    a[i] = data%10;
                    data/=10;
                }
            }
        }
    }
}
void display(int a[]){
    for(int i=0;i<4;i++){
        cout << a[i];
    }
    cout<<endl;
}
void markSrt(int *a,int n){
    for(int pos=0;pos<n-1;pos++){
        for(int row=pos+1;row<n;row++){
            if(*(a+pos)>*(a+row)){
                *(a+pos)=*(a+pos)^*(a+row);
                a[row]=a[pos]^a[row];
                *(a+pos)=*(a+pos)^*(a+row);
            }
        }
    }
}
void prntAry(int *a,int n){
    for(int i=0;i<n;i++){
        cout << *(a+i) << " ";
    }
}
void fillMod(int n,int *a){
    cout << "fill the array"<<endl;
    for(int i=0;i<n;i++){
        cin >> *(a+i);
    }
}
int *mode(int *freq,int size,int max,int nModes){
    int *a=new int[nModes];
    int index=0;
    for (int i=0;i<size;i++){
        if (freq[i]==max){
            a[index]=i;
            index++;
        }
    }
    return a;
}
 statsResult printStat(int *array,int mod,int size,statsResult data) {
    int *freq=freqF(array,mod,size);
    data.maxFreq=findMax(freq,mod);
    data.nModes=numMode(freq,mod,data.maxFreq);
    data.mode=mode(freq,mod,data.maxFreq,data.nModes);
    cout << "The Original Array"<<endl;
    prntAry(array,size);
    markSrt(array,size);
    cout << "\nThe Sorted Random Array"<<endl;
    prntAry(array,size);
    cout << "\nMax frequency: "<<data.maxFreq<<" "<<endl;
    cout << "Number of Modes: "<<data.nModes<<endl;
    if (data.nModes>1){
        cout << "The modes are: ";
    }else 
        cout << "The mode is ";
    prntAry(data.mode,data.nModes);
    cout << "The median is ";
    data.median=med(array,size);
    cout << "\nThe mean of this set is ";
    data.avg=mean(array,size);
    cout << data.avg;
}
int findMax (int *a,int size){
    int max=0;
    for (int i=0;i<size;i++){
        if (a[i]>max)
            max=a[i];
    }
    return max;
}
int numMode(int *a,int size,int max){
    int counter=0;
    for (int i=0;i<size;i++){
        if (a[i]==max)
            counter++;
    }
    return counter;
}
int *freqF(int *array,int mod,int size){
    int *freq=new int[mod];
    for (int i=0;i<mod;i++){
        freq[i]=0;
    }
    for (int i=0;i<size;i++){
        freq[array[i]]++;
    }
    return freq;
}
float med(int *array,int n){
    float median;
    if (n%2==0){
        cout << array[n/2];
    }else
        cout << array[(n/2)-1];
    return median;
}
float mean(int *array,int n){
    float sum=0,mean;
    for(int i=0;i<n;i++){
        sum+=*(array+i);
    }
    mean=sum/n;
    return mean;
}