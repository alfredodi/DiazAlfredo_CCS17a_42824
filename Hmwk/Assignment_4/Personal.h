/* 
 * File:   Personal.h
 * Author: Alfredo
 *
 */

#include <iostream>
#include <string>

using namespace std;

#ifndef PERSONAL_H
#define	PERSONAL_H

class Personal {
public:
    void setName(string);
    void setAdd(string);
    void setAge(int); 
    void setPhone(string);
    string getPhone();
    string getName();
    string getAdd();
    int getAge();
private:
    string name;
    string add;
    string phone;
    int age;
};

#endif	/* PERSONAL_H */
