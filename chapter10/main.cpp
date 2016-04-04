/* 
 * File:   main.cpp
 * Author: Alfredo
 *
 * Created on April 3, 2016, 2:14 PM
 */

#include <iostream>
#include <cctype>
#include <string>
#include <iomanip>
#include <cstring>

using namespace std;

/*
 * 
 */

void pntMenu();
void prb1();
float* words(const char *);
float* words(const string);
void prb2();
void getString(char *, short);
void countVowels(char *);
void countConsonants(char *);


int main(int argc, char** argv) {
    short menuChoice=0;
    do{
        cout << "Type 1 for problem 1" << endl;
        cout << "Type 2 for problem 2" << endl;
        cout << "Type 3 to exit program" << endl;
        cin >> menuChoice;
        
        switch(menuChoice){
            case 1: prb1(); break;
            case 2: prb2(); break;
            case 3: break;
            default: cout << "Bad Selection try again.";
        }        
    }while(menuChoice !=3);
    
    return 0;
}
void prb1() {
    
    const short SIZE = 51;
    char str[SIZE];
    char *strPtr = str;
    string strObj = "";
    float *valsPtr = 0;
    
    cout << "Please enter a string no more than " << (SIZE - 1) 
         << " characters long: ";
    cin.ignore();
    cin.getline(str, SIZE);
    valsPtr = words(strPtr);
    strObj = strPtr;
    cout.unsetf(ios_base::floatfield);
    cout << noshowpoint;
    valsPtr = words(strObj);
    cout << "Your string contained " << valsPtr[0] << " words.\n";
    cout << "It contained an average of "
         << showpoint << fixed << setprecision(2)
         << valsPtr[1] << " letters per word.\n";   
    delete[] valsPtr;
    
}

float* words(const char *strPtr) {
    
    float words = 0.0;
    float letters = 0.0;
    float avg = 0.0;
    short count = 0;
    const short VALS_RETURNED = 2;
    float *valsPtr = new float[VALS_RETURNED];
    
    while (strPtr[count] != '\0') {       
        while (!isalpha(strPtr[count]) && strPtr[count] != '\0') {           
            count++;        
        }       
        while(isalpha(strPtr[count]) && strPtr[count] != '\0') {           
            letters++;
            count++;            
        }        
        while (!isalpha(strPtr[count]) && strPtr[count] != '\0') {           
            count++;        
        }        
        words++;
        avg = letters / words;
        
        valsPtr[0] = words;
        valsPtr[1] = avg;
        
        return valsPtr; 
    }
}
float* words(const string strObj) {
    
    return words(strObj.c_str());
    
}

void prb2() {
    
    const short SIZE = 51;
    char str[SIZE];
    char *strPtr = str;
    int menuSelection = 6;
    
    getString(strPtr, SIZE);
    
    do {
        
        cout << "\n1) Count the number of vowels in the string" << endl;
        cout << "2) Count the number of consonants in the string" << endl;
        cout << "3) Count both the vowels and consonants in the string" << endl;
        cout << "4) Enter another string" << endl;
        cout << "5) Exit the program" << endl;
        
        cin >> menuSelection;
        
        switch (menuSelection) {
            
            case 1:   countVowels(strPtr); break;
            case 2:   countConsonants(strPtr); break;
            case 3:   countVowels(strPtr);
                      countConsonants(strPtr);
                      break;
            case 4:   getString(strPtr, SIZE); break;
            
        }
        
    } while (menuSelection != 5);
    
}
void getString(char *str, short SIZE) {
    
    cout << "Please enter a string no more than " << (SIZE - 1) 
         << " characters long: ";
    cin.ignore();
    cin.getline(str, SIZE);
    
}

void countVowels(char *strPtr) {
    
    short count = 0;
    short vowels = 0;
    
    while (strPtr[count] != '\0') {
        
        if (tolower(strPtr[count]) == 'a' ||
            tolower(strPtr[count]) == 'e' ||
            tolower(strPtr[count]) == 'i' ||
            tolower(strPtr[count]) == 'o' ||
            tolower(strPtr[count]) == 'u') {
            
            vowels++;
            
        }
        
        count++;
        
    }
    
    cout << "The string selected had " << vowels << " vowels." << endl;
    
}

void countConsonants(char *strPtr) {
    
    short count = 0;
    short consonants = 0;
    
    while (strPtr[count] != '\0') {
        
        if (isalpha(strPtr[count]) &&
            tolower(strPtr[count]) != 'a' &&
            tolower(strPtr[count]) != 'e' &&
            tolower(strPtr[count]) != 'i' &&
            tolower(strPtr[count]) != 'o' &&
            tolower(strPtr[count]) != 'u') {
            
            consonants++;
            
        }
        
        count++;
        
    }
    
    cout << "The string selected had " << consonants << " consonants."
         << endl;
    
}
