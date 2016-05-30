/*
 *  File: gameBoard.cpp
 *  Author: Alfredo Diaz
 * 
 *  Created on May 19, 2016
 * 
 *  source code for our gameBoard.h 
 */

#include <iostream>
#include "GameBoard.h"

using namespace std;

/// A function that creates our game board grid in which the user will play on.
void GameBoard::create(int nRows, int nColms){
    /// Dynamically create a game board.
    row = nRows;
    colm = nColms;
    
    /// set up our board using input data.
    data = new int *[row]; /// Creates each row
    /// Create each column for our game board
    for(int nRows=0; nRows != row; ++nRows){
        data[nRows] = new int [colm];
    }
}

/// A function to reset our came board.
void GameBoard::clear(){
    for (int i=0; i != row; ++i)
        for(int j=0; j != colm; ++j)
            data[i][j] = 0;
}

/// Function to de-allocate memory used
void GameBoard::destroy(){
    /// Delete each row.
    for(int i = 0; i != row; ++i){
        delete[] data[i];
    }
    /// delete our structure
    delete data;
}

void GameBoard::setRow(int rows){
    if(rows <=0){
        throw BadInput();
    }    
    row = rows;    
}

void GameBoard::setColm(int colms){
    if (colms <= 0){
        throw BadInput();
    }
    colm = colms;
}

void GameBoard::print() const{
    for(int i = 0; i != row; ++i){
        for(int j = 0; j != colm; ++j){
            cout << data[i][j] << " ";
        }
        cout << endl;
    }
}

void GameBoard::load(){
    cout << "Calls the base class load."
            "yhis should be calling our derived class.\n";
}

void GameBoard::setUp(){
    cout << "calls the wrong function. shoud use polymorphism to call"
            " our derived class setUp function.\n";
}