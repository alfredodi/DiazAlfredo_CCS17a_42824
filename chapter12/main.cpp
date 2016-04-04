/* 
 * File:   main.cpp
 * Author: Alfredo
 *
 * Created on April 3, 2016, 3:07 PM
 */

#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
#include <vector>

using namespace std;

struct QrtSales{
    string divisionN;
    short qrt;
    float qrtSale;
    
};
void prb1();
void prb2();
void aryToFile(string, int *, short);
void fileToAry(string, int *, short);
void prb3();
void findSales(QrtSales *, string, short);

int main(int argc, char** argv) {
    short menuChoice;
    do{
        cout << "Type 1 for problem 1." << endl;
        cout << "Type 2 for problem 2." << endl;
        cout << "Type 3 for problem 3." << endl;
        cout << "Type 4 to exit program." << endl;
        cin >> menuChoice;
        switch(menuChoice){
            case 1: prb1(); break;
            case 2: prb2(); break;
            case 3: prb3(); break;
            case 4: break;
            default: cout << "Bad selection. Try again." << endl;
        }
    }while(menuChoice <4);

    return 0;
}
void prb1(){
    string inFileName = "";
    string outFileName = "";
    
    cout << "Enter the input file name: ";
    cin >> inFileName;
    cout << "Enter the output file name: ";
    cin >> outFileName;
    fstream infile(inFileName.c_str(), ios::in);
    fstream outfile(outFileName.c_str(), ios::out);
    
    char c;
    bool isNew = true;
    if(infile){
        infile.get(c);
        while(infile){
            if(isalpha(c)&& isNew){
                outfile << (char) toupper(c);
                isNew=false;
            }
            else if(c=='.'){
                isNew=true;
                outfile << c;
            }
            else outfile << (char) tolower(c);
            infile.get(c);
        }
        cout << endl;
        infile.close();
    }
    else cout << "error file cannot be opened" << endl;
    outfile.close();
}
void aryToFile(string fName, int *ary, short sizeOfAry) {
    fstream outFile(fName.c_str(), ios::out | ios::binary);   
    cout << "Writing array to file..." << endl;    
    outFile.write(reinterpret_cast<char *>(ary), sizeOfAry);    
    outFile.close();
    
}
void prb2() {
    short sizeOfIAry = 3;
    int iAry[sizeOfIAry] = {1, 2, 3};
    string fName = "binFile";
    short sizeOfOAry = 3;
    int oAry[sizeOfOAry];
    aryToFile(fName, iAry, sizeof(iAry));
    fileToAry(fName, oAry, sizeof(oAry));
    for (short i = 0; i < sizeOfOAry; i++) {       
        cout << oAry[i] << " ";       
    }    
    cout << endl;
    
}
void fileToAry(string fName, int *ary, short sizeOfAry) {   
    fstream inFile(fName.c_str(), ios::in | ios::binary);    
    cout << "Reading array from file..." << endl;    
    inFile.read(reinterpret_cast<char *>(ary), sizeOfAry);    
    inFile.close();    
}
void prb3() {
    short quarters = 4;
    QrtSales east[quarters];
    QrtSales west[quarters];
    QrtSales north[quarters];
    QrtSales south[quarters];
    
    fstream file; 
    
    file.open("sales.dat", ios::out | ios::binary);  
    findSales(east, "East", quarters);
    file.write(reinterpret_cast<char *>(&east), sizeof(east));  
    findSales(west, "West", quarters);
    file.write(reinterpret_cast<char *>(&west), sizeof(west));   
    findSales(north, "North", quarters);
    file.write(reinterpret_cast<char *>(&north), sizeof(north));    
    findSales(south, "South", quarters);
    file.write(reinterpret_cast<char *>(&south), sizeof(south));   
    file.close();    
    file.open("sales.dat", ios::in | ios::binary);    
    file.read(reinterpret_cast<char *>(east), sizeof(east));
    file.read(reinterpret_cast<char *>(west), sizeof(west));
    file.read(reinterpret_cast<char *>(north), sizeof(north));
    file.read(reinterpret_cast<char *>(south), sizeof(south)); 
    file.close(); 
    
    for (short i = 0; i < quarters; i++) {       
        cout << "Division: " << east[i].divisionN << ", "
             << "Quarter: " << east[i].qrt << ", Sales: $" 
             << east[i].qrtSale << endl;    
    }
    
    for (short i = 0; i < quarters; i++) {
        cout << "Division: " << west[i].divisionN << ", "
             << "Quarter: " << west[i].qrt << ", Sales: $" 
             << west[i].qrtSale << endl;   
    }
    
    for (short i = 0; i < quarters; i++) {
        cout << "Division: " << north[i].divisionN << ", "
             << "Quarter: " << north[i].qrt << ", Sales: $" 
             << north[i].qrtSale << endl;    
    }
    for (short i = 0; i < quarters; i++) {        
        cout << "Division: " << south[i].divisionN << ", "
             << "Quarter: " << south[i].qrt << ", Sales: $" 
             << south[i].qrtSale << endl;       
    }   
}

void findSales(QrtSales *qs, string divName, short quarters) {
    cout << "Division: " << divName << endl;
    for (short i = 0; i < quarters; i++) {
        qs[i].divisionN = divName;
        qs[i].qrt = i + 1;
        cout << "Please enter the sales for quarter " << i + 1 << ": $";
        do{
            cin >> qs[i].qrtSale;          
        }while (qs[i].qrtSale < 0);       
    }   
}
