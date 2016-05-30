/* 
 * File:   MineSweep.h
 * Author: Alfredo Diaz
 * Purpose: This will contain MineSweeper for our program.
 *          as well as hold our enumerated flags when a space is selected
 *          i.e. Difficulty and Mine and clear.
 * Created on May 23, 2016, 2:57 PM
 */

#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <iomanip>

#include "MineSweep.h"

using namespace std;
/// Function definitions from MineSweep.h

void MineSweep::create(int rows, int colms){
    /// Dynamically create our board
    row = rows;
    colm = colms;
    
    /// Initiate rows and columns 
    data = new int *[row];
    
    for(int rows = 0; row != row; ++ rows){
        data[rows] = new int[colm];
    }
}

void MineSweep::setRow(int rows){
    if(row <= 0){
        throw BadInput{
            
        };
    }
    row = rows;
    
}

void MineSweep::setColm(int colms){
    if(colms <= 0){
        throw BadInput{
            
        }; 
    }
    colm = colms;
}

void MineSweep::display(){
    cout << "Enter information in order to create the game board.\n\n"
         << "\tEnter the number of row (1 - 10): ";
    int rows;
    cin  >> rows;
    cout << "The game board will be in the size " 
         << rows << " by " << rows << endl;
    if(rows < 1 || rows >10){
        throw BadInput{
            
        };
    }
    // got bored 5/23 @ 3:39 pPM finish after i take a break.
    // Todo: finish display implimitation and others from MineSweep.h
}