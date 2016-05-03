/* 
 * File:   RetailItem.h
 * Author: Alfredo
 *
 */

#include "RetailItem.h"

void RetailItem::setDescription(string x){
    description = x;
}

string RetailItem::getDescription(){
    return description;
}

void RetailItem::setUnit(int x){
    unit = x;
}

int RetailItem::getUnit(){
    return unit;
}

void RetailItem::setPrice(float x){
    price = x;
}

float RetailItem::getPrice(){
    return price;
}