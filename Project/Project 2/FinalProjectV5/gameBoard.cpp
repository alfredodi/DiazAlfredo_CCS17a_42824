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
void GameBoard::create(int row, int col){
    /// Dynamically create a game board.
    rows = row;
    cols = col;
    
    /// set up our board using input data.
    data = new int *[rows]; /// Creates each row
    /// Create each column for our game board
    for(int row=0; row != rows; ++row){
        data[row] = new int [cols];
    }
}

/// A function to reset our came board.
void GameBoard::clearBoard(){
    for (int i = 0; i != rows; ++i)
        for(int j = 0; j != cols; ++j)
            data[i][j] = 0;
}

/// Function to de-allocate memory used
void GameBoard::destroy(){
    /// Delete each row.
    for(int i = 0; i != rows; ++i){
        delete[] data[i];
    }
    /// delete our structure
    delete data;
}

void GameBoard::setRow(int row){
    if(row <=0){
        throw BadInput();
    }    
    rows = row;    
}

void GameBoard::setColm(int col){
    if (col <= 0){
        throw BadInput();
    }
    cols = col;
}

void GameBoard::print() const{
    for(int i = 0; i != rows; ++i){
        for(int j = 0; j != cols; ++j){
            cout << data[i][j] << " ";
        }
        cout << endl;
    }
}

void GameBoard::loadGame(){
    cout << "Calls the base class load."
            "This should be calling our derived class.\n";
}

void GameBoard::initilize(){
    cout << "calls the wrong function. should use polymorphism to call"
            " our derived class initilize function.\n";
}