/* 
 * File:   RetailItem.h
 * Author: Alfredo
 *
 */

#include <string>
#include <iostream>
using namespace std;

#ifndef RETAILITEM_H
#define	RETAILITEM_H

class RetailItem {
public:
    void setDescription(string);
    void setUnit(int);
    void setPrice(float);
    int getUnit();
    float getPrice();
    string getDescription();
private:
    string description;
    int unit;
    float price;
};

#endif	/* RETAILITEM_H */


