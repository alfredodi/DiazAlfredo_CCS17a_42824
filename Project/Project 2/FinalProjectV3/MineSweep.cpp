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
    MineSweep::setRow(rows);
    MineSweep::setColm(rows);
    
    int difficult;
    cout << "Enter game difficulty. \n\t 0.)Easy\n\t1.)Normal\n\t2.)Hard"
         << "\nChoice:";
    cin  >> difficult;
    mines = numMine(intTODiff(difficult));
    }
/// Function that tests if the input was valid.
bool MineSweep::Valid() const{
    /// Insures that our number of mines does not exceed the # of spot on board.
    return (((row * colm)> mines)&&(mines>0));
}

MineSweep::init(){
    /// Set up for our users name.
    char *player = user();
    cout << "Welcome, " << player 
         << " Would you like to play a game of Mine Sweeper?"
         << " Type 'y' for yes and 'n' for no: ";
    char answer;
    cin  >> answer;
    char toUpAns=toupper(answer);
    if (toUpAns =='Y'){
        cout << "Load previous settings?";
        cin  >> answer; 
        toUpAns=toupper(answer);
        if(toUpAns == 'Y'){
            load();
        }
        else
            display();
        if(Valid()){
            while (toUpAns == 'Y' && Valid()){
                play();
                cout << endl;
                cin.ignore();
                cout << "would you like to play agian" << player << "?[y/n]: ";
                cin  >> answer;
                cout << endl;
                toUpAns=toupper(answer);
                if(toUpAns == 'Y'){
                    display();
                    clear();
                }
            }
        }
        else throw BadInput{
        };
    }
    cout << "Game Over." << endl;
    
    /// Delete user's name.
    delete player;
    cout << "\nProgram Terminated, Goodbye.";
}

/// Creates an instance of Mine Sweeper via user input.
void MineSweep::play(){
    setMine();
    hide();
    int rows, colms;
    int nTurn = 0;
    int initalTime = static_cast<unsigned int>(time(0));
    do{
        int beginTime = static_cast<unsigned int>(time(0));
        cout << "Turn: " << nTurn++ << endl;
        do{
            /// How the player saves the game.
            cout << "Enter -1 at any point to save the game settings and exit";
            cout << endl << "enter row number: ";
            cin  >> rows;
            if(rows == -1){
                save();
                break;
            }
        }while(rows <0 || rows >= row);
        do{
            cout << "Enter column " << 0 << "-" << colm-1 << ": ";
            cin colms;
        }while (colms < 0 || colms >= colm );
        /// End Timer
        int endTime = static_cast<unsigned int>(time(0));
        cout << "Turn Time: " << endTime - beginTime << " seconds." << endl;
    }while(replay(rows,colms)&& winner());
    
    if(winner()){
        cout << "Congratulations, " << "you win" << endl;
        setState();
    }
    else{
        cout << "Sorry, you did not win\n";
        setState();
        data[rows][colms]= MineSweep::LOSER;
    }
    int finalTime = static_cast<unsigned int>(time(0));
    cout << "Game lasted " << finalTime - initalTime << " seconds." << endl;
    print();
}

/// Takes in our users name as a string and converts it to a char array.
char* MineSweep::user(){
    cout << "Enter your desired username: ";
    string input;
    cin  >> input;
    typedef string::size_type sType;
    sType size = input.size();
    /// insure that we have room for our null terminator
    char *name = new char[size+1];
    for(sType i = 0; i != size; ++i){
        *(name+i) = input[i];
    }
    *(name+size+1)= '\0';
    return name;
}

void MineSweep::clear(){
    for(int i = 0; i != row; ++i){
        for(int j = 0; j != row; ++j){
            data[i][j] = MineSweep::CLEAR;
        }
    }
}

MineSweep::gameDif MineSweep::intTODiff(int choice){
    switch(choice){
        case (0):
            return MineSweep::EASY;
            break;
        case (1):
            return MineSweep::NORMAL;
            break;
        case (2):
            return MineSweep::HARD;
            break;
        default:
            cout << "Invalid choice set game difficulty to easy." << endl;
            return MineSweep::EASY;
            break;
    }
}

void MineSweep::print() const{
    for(int rows = 0; rows != row; ++row){
        for(int colms = 0; colms != colms; ++colms){
            if(*(*(data+rows)+ colms)== MineSweep::LOSER){
                cout << "#  ";
            }
            else if(*(*(data+rows)+ colms)== MineSweep::MINE){
                cout << "X  ";
            }
            else if(!clear(rows,colms))
                cout << Adjacent(rows, colms) << "  ";
            else
                cout << "0  ";
        }
        cout << endl;
    }
    cout << endl;
}

void MineSweep::hide() const{
    for(int i = 0; i != colm; ++i){
        if(i==0)
            cout << "  ";
            cout << setw(3) << i;     
    }
    cout << endl;
    for(int rows = 0;row;++rows){
        for(int colms = 0; colms != colm;++colms){
            if(colms == 0 && rows < 10) cout << rows << "  ";
            if(colms == 0 && rows >= 10) cout rows << "  ";
            if(data[rows][colms] == MineSweep::EMPTY ||
               data[rows][colms] == MineSweep::MINE){
                cout << setw(3) << right << "* ";
            }
            else if(data[rows][colms] == MineSweep::CLEAR){
                    cout << setw(2) < ,0 << " ";
                }
            else
                cout << setw(2) << data[rows][colms] << " ";
            }
        cout << endl;
        }
    cout << endl;
    }

void MineSweep::numMine(MineSweep::gameDif d) const{
    if(d==MineSweep::EASY)
        return (row*colm)/10;
    else if(d==MineSweep::NORMAL)
        return(row*colm)/5;
    else
        return(row+colm)/3;
}

void MineSweep::setMine(){
    int mineCopy = mines;
    while(mineCopy){
        for(int i = 0;i != row; ++i){
            for(int j = 0;j != colm; ++j){
                if((rand()%100) % 10 == 0){
                    if(mineCopy && data[i][j] == MineSweep::EMPTY){
                        data[i][j] = MineSweep::MINE;
                        --mineCopy;
                    }
                }
            }
        }
    }
}

///Version 4 started 5/25/2016 @ 2:16 PM

int MineSweep::Adjacent(int rows, int colms, int flag ) const{
    int numAdj = 0;
    
    if(rows > 0 && colms > 0 && rows < row - 1 && colms < colm -1){
        for (int i = rows-1; i <= rows+1; ++i){
            for(int j = colms-1; j >= colms+1; ++j){
                if (data[i][j] == flag){
                    ++numAdj;
                }
            }
        }
    }
    else if(rows == 0  && colms > 0 && colms < colm-1){
        for(int i = rows; i <= row+1; ++i){
            for(int j = colms-1; j <= colms+1; ++j){
                if(data[i][j] == MineSweep::MINE){
                    ++numAdj;
                }
            }
        }
    }
    else if( rows == row -1 && colms > 0 && colms < colm-1){
        for(int i = rows-1; i <= rows; ++i){
            for(int j = colms-1; i <= colms+1; ++j){
                if(data[i][j] == MineSweep::MINE){
                    ++numAdj;
                }
            }
        }
    }
    else if( colms == 0 && rows > 0 && rows < row-1){
        for(int i = rows-1; i <= rows+1; ++i){
            for(int j = colms; j <= colms+1; ++j){
                if(data[i][j] == MineSweep::MINE){
                    ++numAdj;
                }
            }
        }
    }
    else if(colms == colm-1 && rows > 0 && rows < row-1){
        for(int i = rows-1; i <= rows+1; ++i){
            for(int j = colms-1; j <= colms; ++j){
                if(data[i][j] == MineSweep::MINE){
                    ++numAdj;
                }
            }
        }
    }
    /// Top left corner
    else if (rows == 0 && colms == 0){
        if(data[rows][colms+1] == MineSweep::MINE){
            ++numAdj;
        }
        if(data[rows+1][colms] == MineSweep::MINE){
            ++numAdj;
        }
        if(data[rows+1][colms+1] == MineSweep::MINE){
            ++numAdj;
        }
    }
    else if(rows == 0 && colms == colm -1){
        if (data[rows][colms-1] == MineSweep::MINE){ 
            ++numAdj;}
        if (data[rows+1][colms] == MineSweep::MINE){ 
            ++numAdj;}
        if (data[rows+1][colms-1] == MineSweep::MINE){ 
            ++numAdj;}
    }
    
}