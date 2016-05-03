/* 
 * File:   Personal.h
 * Author: Alfredo
 *
 */

#include "Personal.h"

void Personal::setName(string x) {
    name = x;
}
string Personal::getName(){
    return name;
}
void Personal::setAdd(string x){
    add = x;
}
string Personal::getAdd(){
    return add;
}
void Personal::setAge(int x){
    age = x;
}
int Personal::getAge(){
    return age;
}
void Personal::setPhone(string x){
    phone = x;
}
string Personal::getPhone(){
    return phone;
}