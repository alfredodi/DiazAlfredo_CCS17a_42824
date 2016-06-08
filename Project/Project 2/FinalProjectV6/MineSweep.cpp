#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <iomanip>

#include "MineSweep.h"

using namespace std;
/// Function definitions from MineSweep.h

void MineSweep::create(int row, int col){
    /// Dynamically create our board
    rows = row;
    cols = col;
    
    /// Initiate rows and columns 
    data = new int *[rows];
    
    for(int row = 0; row != rows; ++ row){
        data[row] = new int[cols];
    }
}

void MineSweep::setRow(int row){
    if(row <= 0){
        throw BadInput{
            
        };
    }
    rows = row;
    
}

void MineSweep::setColm(int col){
    if(col <= 0){
        throw BadInput{
            
        }; 
    }
    cols = col;
}

void MineSweep::display(){
    cout << "Enter information in order to create the game board.\n\n"
         << "\tEnter the number of row (1 - 10): ";
    int row;
    cin  >> row;
    cout << "The game board will be in the size " 
         << row << " by " << row << endl;
    if(row > 10 || row < 1){
        throw BadInput{
            
        };
    }
    rows = row;
    cols = row;
    
    int difficult;
    cout << "Enter game difficulty. \n\t0.)Easy\n\t1.)Normal\n\t2.)Hard"
         << "\nChoice:";
    cin  >> difficult;
    mines = nMine(intToDiff(difficult));
    }
/// Function that tests if the input was valid.
bool MineSweep::isValidIn() const{
    /// Insures that our number of mines does not exceed the # of spot on board.
    return (((rows * cols) > mines) && (mines > 0));
}

void MineSweep::initilize(){
    /// Set up for our users name.
    char *player = userName();
    cout << "Welcome, " << player 
         << " Would you like to play a game of Mine Sweeper?"
         << " Type 'y' for yes and 'n' for no: ";
    char answer;
    cin  >> answer;
    
    if (answer == 'y' || answer == 'Y'){
        cout << "Load previous settings?";
        char answer2;
        cin  >> answer2; 
        if(answer2 == 'y' || answer2 == 'Y'){
            loadGame();
        }
        else
            display();
        if(isValidIn() && answer == 'y'||answer =='Y'){
            while (answer == 'y' || (answer = 'Y' && !isValidIn())){
                playGame();
                cout << endl;
                cin.ignore();
                cout << "would you like to play again, " << player << "?[y/n]: ";
                cin  >> answer;
                cout << endl;
                if(answer == 'y' || answer == 'Y'){
                    display();
                    clearBoard();
                    answer2 = 'n';
                    answer = 'n';
                    break;
                }
                
            }
        }
        else 
            throw BadInput{
        };
    }
    cout << "Game Over." << endl;
    
    /// Delete user's name.
    delete player;
    cout << "\nProgram Terminated, Goodbye.\n";
}

/// Creates an instance of Mine Sweeper via user input.
void MineSweep::playGame(){
    setMines();
    prntObscr();
    for( int i = 0; i < rows; i++ ){
        for( int j = 0; j < cols; j++)
        if( data[i][j] == MineSweep::MINE ) cout << "mine locations:" << i << j <<endl;
    }
    int row, col;
    int nTurn = 0;
    int initalTime = static_cast<unsigned int>(time(0));
    do{
        int beginTime = static_cast<unsigned int>(time(0));
        cout << "Turn: " << nTurn++ << endl;
        do{
            /// How the player saves the game.
            cout << "Enter -1 at any point to save the game settings and exit";
            cout << endl << "enter row number: ";
            cin  >> row;
            if(row == -1){
                saveGame();
                return;
            }
        }while(row < 0 || row >= rows);
        do{
            cout << "Enter column " << 0 << "-" << cols << ": ";
            cin >> col;
        }while(col < 0 || col >= cols );
        /// End Timer
        int endTime = static_cast<unsigned int>(time(0));
        cout << "Turn Time: " << endTime - beginTime << " seconds." << endl;
    }while(replay(row,col)&& !hasWon());
    
    if(hasWon()){
        cout << "Congratulations, " << "you win" << endl;
        setFlags();
    }
    else{
        cout << "Sorry, you did not win\n";
        setFlags();
        data[row][col]= MineSweep::LOSER;
    }
    int finalTime = static_cast<unsigned int>(time(0));
    cout << "Game lasted " << finalTime - initalTime << " seconds." << endl;
    print();
}

/// Takes in our users name as a string and converts it to a char array.
char* MineSweep::userName(){
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

void MineSweep::clearBoard(){
    for(int i = 0; i != rows; ++i){
        for(int j = 0; j != rows; ++j){
            data[i][j] = MineSweep::EMPTY;
        }
    }
}

MineSweep::Difficulty MineSweep::intToDiff(int choice){
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
    for(int row = 0; row != rows; ++row){
        for(int col = 0; col != cols; ++col){
            if(*(*(data+row)+ col) == MineSweep::LOSER){
                cout << "#  ";
            }
            else if(*(*(data+row)+ col)== MineSweep::MINE){
                cout << "X  ";
            }
            else if(isClear(row,col))
                cout << nAdjacent(row, col) << "  ";
            else
                cout << "0  ";
        }
        cout << endl;
    }
    cout << endl;
}

void MineSweep::prntObscr() const{
    for(int i = 0; i != cols; ++i){
        if(i==0){
            cout << "  ";
        }
            cout << setw(3) << i;  
    }
    cout << endl;
    for(int row = 0;row != rows; ++row){
        for(int col = 0; col != cols; ++col){
            if(col == 0 && row < 10) cout << row << "  ";
            if(col == 0 && row >= 10) cout << row << "  ";
            if(data[row][col] == MineSweep::EMPTY ||
               data[row][col] == MineSweep::MINE){
                cout << setw(3) << right << "* ";
            }
            else if(data[row][col] == MineSweep::CLEAR){
                    cout << setw(2) << 0 << " ";
                }
            else
                cout << setw(2) << data[row][col] << " ";
            }
        cout << endl;
        }
    cout << endl;
    }

int MineSweep::nMine(MineSweep::Difficulty d) const{
    if(d==MineSweep::EASY)
        return (rows*cols)/10;
    else if(d==MineSweep::NORMAL)
        return(rows*cols)/5;
    else
        return(rows+cols)/3;
}

void MineSweep::setMines(){
    int mineCopy = mines;
    while(mineCopy){
        for(int i = 0;i != rows; ++i){
            for(int j = 0;j != cols; ++j){
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

///@TODO may 24, 2016 @ 1:39 PM started at 11:00 am
/// Adjacent(), displayZero(), clear(), states, replay, winner, perimeter, 
/// save and load and operator=.

int MineSweep::nAdjacent(int row, int col) const{
    int numAdj=0;              /// the number of adjacent mines
    
    /// not on first or last row or first or last column
    /// most of the searches take place in this area
    if ( row > 0 && col > 0 && row < rows-1 && col < cols-1) {
        /// search the 3x3 grid surrounding a cell
        for (int i = row-1; i <= row+1; ++i) {
            for (int j = col-1; j <= col+1; ++j)
                if (data[i][j] == MineSweep::MINE)
                    ++numAdj;
        }
    }
    /// on the first row, not on first or last column
    else if ( row == 0 && col > 0 && col < cols - 1) {
        for (int i = row; i <= row+1; ++i) {
            for (int j = col-1; j <= col+1; ++j)
                if (data[i][j] == MineSweep::MINE)
                    ++numAdj;
        }
    }
    /// on the last row, not on first or last column
    else if ( row == rows-1 && col > 0 && col < cols - 1) {
        for (int i = row-1; i <= rows-1; ++i) {
            for (int j = col-1; j <= cols-1; ++j)
                if (data[i][j] == MineSweep::MINE)
                    ++numAdj;
        }
    }
    /// on the first column, not on first or last row
    /// search to the right
    else if ( col == 0 && row > 0 && row < rows - 1) {
        for (int i = row-1; i <= row+1; ++i) {
            for (int j = col; j <= col+1; ++j)
                if (data[i][j] == MineSweep::MINE)
                    ++numAdj;
        }
    }
    /// on the last column, not on first or last row
    /// search to the left
    else if ( col == cols-1 && row > 0 && row < rows - 1) {
        for (int i = row-1; i <= row+1; ++i) {
            for (int j = col-1; j <= col; ++j)
                if (data[i][j] == MineSweep::MINE)
                    ++numAdj;
        }
    }
    /// top left corner
    else if (row == 0 && col == 0) {
        if (data[row][col] == MineSweep::MINE) ++numAdj;//seems redunant should lose
        if (data[row][col+1] == MineSweep::MINE) ++numAdj;
        if (data[row+1][col] == MineSweep::MINE) ++numAdj;
        if (data[row+1][col+1] == MineSweep::MINE) ++numAdj;
    }
    /// top right corner
    else if (row == 0 && col == cols-1) {
        if (data[row][col] == MineSweep::MINE) ++numAdj;
        if (data[row][col-1] == MineSweep::MINE) ++numAdj;
        if (data[row+1][col] == MineSweep::MINE) ++numAdj;
        if (data[row+1][col-1] == MineSweep::MINE) ++numAdj;
    }
    /// bottom left corner
    else if (row == rows-1 && col == 0) {
        if (data[row][col] == MineSweep::MINE) ++numAdj;
        if (data[row-1][col] == MineSweep::MINE) ++numAdj;
        if (data[row-1][col+1] == MineSweep::MINE) ++numAdj;
        if (data[row][col+1] == MineSweep::MINE) ++numAdj;
    }
    /// bottom right corner
    else if (row == rows-1 && col == cols-1) {
        if (data[row][col] == MineSweep::MINE) ++numAdj;
        if (data[row-1][col-1] == MineSweep::MINE) ++numAdj;
        if (data[row-1][col] == MineSweep::MINE) ++numAdj;
        if (data[row][col-1] == MineSweep::MINE) ++numAdj;
    }
    /// return number of mines from appropriate if statement
    return numAdj;
}

bool MineSweep::isClear(int row, int col) const{
    if( data[row][col] == MineSweep::MINE ){
        return false;
    }
    else return true;
}

void MineSweep::showZeros(int row, int col){
    /// Bounds check
    if(row >= rows || row < 0 || col >= cols || col < 0){
        return;
    }
    if( isClear(row,col) && data[row][col] != MineSweep::CLEAR){
        data[row][col] = MineSweep::CLEAR;
        showZeros(row+1, col); /// check down one.
        showZeros(row-1, col); /// check up one.
        showZeros(row, col+1); /// check one to the right.
        showZeros(row, col-1); /// check one to the left.
    }
    else{
       return;
    }
}

void MineSweep::setFlags(){
    for(int i=0; i!= rows; ++i){
        for(int j=0; j != cols; ++j){
            if(data[i][j] != MineSweep::MINE){
                data[i][j] = nAdjacent(i,j);
            }
        }
    }
}

bool MineSweep::replay(int row, int col){
    /// Check is a losing space was selected by the user.
    if(data[row][col] == MineSweep::MINE){
        return false;
    }
    else if(isClear(row, col)){
        showZeros(row, col);
        setPerim();
        prntObscr();
        return true;
    }
    else{
        data[row][col] = nAdjacent(row, col);
        prntObscr();
        return true;
    }
}

bool MineSweep::hasWon() const{
    for(int i = 0; i != rows; ++i){
        for(int j = 0; j != cols; ++j){
            if(data[i][j] == MineSweep::EMPTY){
                return false;
            }
        }
    }
    return true;
}

void MineSweep::setPerim(){
    for(int row = 0; row != rows; ++row){
        for(int col = 0; col != cols; ++col){
            if(row > 0 && row < rows-1 && col > 0 &&  col < cols-1){
                if(data[row][col] == MineSweep::CLEAR) {
                    /// check that the previous number has mines adjacent
                    if(data[row][col-1] != MineSweep::CLEAR){
                        data[row][col-1] = nAdjacent(row,col-1);
                    }
                    /// check if the next number has mines adjacent
                    if(data[row][col+1] != MineSweep::CLEAR){
                        data[row][col+1] = nAdjacent(row,col+1);
                    }
                    if(data[row-1][col] != MineSweep::CLEAR){
                       data[row-1][col] = nAdjacent(row-1, col);
                    }
                    /// check if the next number has mines adjacent
                    if(data[row+1][col] != MineSweep::CLEAR){
                       data[row+1][col] = nAdjacent(row+1, col);
                    }
                    /// check the adjacent corners
                    if(data[row-1][col-1] != MineSweep::CLEAR){
                       data[row-1][col-1] = nAdjacent(row-1, col-1);
                    }
                    if(data[row-1][col+1] != MineSweep::CLEAR){
                       data[row-1][col+1] = nAdjacent(row-1, col+1);
                    }
                    if(data[row+1][col-1] != MineSweep::CLEAR){
                       data[row+1][col-1] = nAdjacent(row+1, col-1);
                    }
                    if(data[row+1][col+1] != MineSweep::CLEAR){
                       data[row+1][col+1] = nAdjacent(row+1, col+1);
                    }
                }
            }
        }
    }
}

void MineSweep::saveGame(){
    fstream gameSave("gameSave", ios::out | ios::binary);
    gameSave.write(reinterpret_cast<char*>(this), sizeof(*this));
    gameSave.close();
}

void MineSweep::loadGame(){
    fstream gameSave("gameSave", ios::in | ios::binary);
    if(!gameSave.is_open()){
        throw "No Previous game setting were found\n";
    }
    gameSave.read(reinterpret_cast<char*>(this), sizeof(*this));
    gameSave.close();
}

MineSweep& MineSweep::operator =(const MineSweep &rhs){
    create(rhs.getRow(), rhs.getColm());
    
    for(int i = 0; i != rhs.getRow(); ++i){
        for(int j = 0; j != rhs.getColm(); ++j){
            data[i][j] = rhs[i][j];
        }
    }
    return *this;
}