/* 
 * File:   main.cpp
 * 
 * Author: Alfredo Diaz
 *
 * Purpose: This is the main file that defines and
 *          runs our game.
 *          Each function or method is defined below.
 *          This display that it was created June 6, 2016
 *          because it is more or less a port of my other versions.
 *          due to me breaking a part that i was no longer able to 
 *          find with out deleting and un-doing hours of progress, thus
 *          i simply when line for line until  was able to obtain a working
 *          version. also it allowed me to document what each function 
 *          does. 
 * 
 * Created on June 6, 2016, 2:15 PM
 */

/// System libraries used
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <ctime>
#include <vector>
#include <string>
#include <iomanip>

/// User Libraries
#include "Abstract.h"
#include "Template.h"
#include "Settings.h"
#include "Board.h"

/// Name spacing
using namespace std;

/// Execution starts here.
int main(int argc, char** argv) {
    
    ///Used for our game time for turns or rounds.
    srand(static_cast<unsigned int>(time(0)));
    
    /// Used for our template.
    BoardGame<Board> m = new Settings(10,10);
    
    try{
        m->config();
    }
    
    /// Error Checking 
    /// Catch used to alert the user that the board was
    /// either too small or too big.
    catch(Settings::badIn){
        cout << "ERROR!: BadIn{};" << endl;
        cout << "If you selected a number less then zero try"
                " using a positive number less then 10." << endl;
        cout << "If you selected a number greater then 10 then the size is "
                "too big try using a smaller number" << endl;
        
    }
    catch(const char* fix){
        cout << fix << endl;
    }

    /// Exit Stage left
    return 0;
}

/// Function Definitions

/// Check() returns true if user input is valid.

bool Settings::check() const{
    /// This will insure that our mines does not exceed the number
    /// of playing spot on our game board.
    return (((rows * cols) > mines) && (mines > 0));
}

/// continue_() is our function that reveals what is underneath the spot
/// that the client has selected and determines if one should continue or not.
/// For example, if the user selects a mine it will reveal it and the game is over.
bool Settings::continue_(int row, int col){
    /// check if the selected spot is a mine.
    if(data[row][col] == Settings::MINE)
        return false;
    
    /// If a spot is zero clear the surrounding area if it is possible.
    else if(noMine(row, col)){
        /// Displays our area of zeros.
        showZeros(row, col);
        bounds();
        reveal();
        
        return true;
    }
    /// The spot had a mine near it.
    /// Reveal it to the client.
    else{
        data[row][col] = proximity(row, col);
        reveal();
        
        return true;
    }
}

/// noMine() is our function that will return true if
/// there are  0 mines surrounding the spot selected.
bool Settings::noMine(int row, int col) const{
    if(proximity(row, col))
        /// if the adjacency is greater then 1.
        return false;
    /// if the adjacency is 0.
    return true;
}

/// hasWon is our function that defines our win condition.
/// this is achieved by clearing every spot and leaving behind only the mines.
bool Settings::hasWon() const{
    for(int i = 0; i != rows; ++i)
        for(int j = 0; j != cols; ++j)
            /// if there are still EMPTY spaces then the client has not won yet.
            if(data[i][j] == Settings::EMPTY)
                return false;
    /// There was no EMPTY spots left so the client has won.    
    return true;    
}

/// create() is our function that creates our game board.
/// This is based off of client selections.
void Settings::create(int row, int col){
    /// Used to create our board.
    rows = row;
    cols = col;
    
    /// Create each of our rows;
    data = new int *[rows];
    
    /// Creates each of our columns
    for(int row = 0; row != rows; ++ row)
        data[row] = new int [cols];
        /// This iterates in order to create our cols.
}

/// vRows() is used to validate if rows is valid
/// if less then or equal to zero then it throws BadIn{}.
void Settings::vRows(int row){
    if(row <= 0)
        throw badIn();
    rows = row;
}

/// vCols() is used to validate if columns is valid
/// if less then or equal to zero then it throws BadIn{}.
void Settings::vCols(int col){
    if(col <= 0)
        throw badIn();
    cols = col;
}

/// userInput() asks for the input needed to to create field.
/// asks for difficulty and field size.
void Settings::userInput(){
    /// Field size input display.
    cout << "                 " << endl;
    cout << " ---------------------------------- " << endl;
    cout << "|         Minefield Size:          |" << endl;
    cout << " ---------------------------------- " << endl;
    cout << "Note: Board will be of size NxN." << endl;
    cout << "For example, 10x10." << endl;
    cout << "Enter the value of n: ";
    
    int row;
    cin >> row;
    
    /// Difficulty selection
    cout << "                                    " << endl;
    cout << " ---------------------------------- " << endl;
    cout << "|        Difficulty Levels:        |" << endl;
    cout << " ---------------------------------- " << endl;
    cout << "| Easy       = 0                   |" << endl;
    cout << "| Normal     = 1                   |" << endl;
    cout << "| Hard       = 2                   |" << endl;
    cout << " ---------------------------------- " << endl;
    cout << "Please enter your difficulty level: ";
    int difficulty;
    cin >> difficulty;
    cout << "                                    " << endl;
    cout << "                                    " << endl;
    /// Allocates varying amounts of mines per game board via difficulty 
    /// selection.
    mines = nMines(convert(difficulty));
    
}

/// Game configuration based on user input.
void Settings::config() {
    int choice;
    bool exitStage = true;
    char *player = userName();
    
    /// The loop will persist until the exit choice is selected.
    cout << " " << endl;
    do{
        /// outputs our game menu.
        cout << " ---------------------------------- " << endl;
        cout << "|       Select From The Menu       |" << endl;
        cout << " ---------------------------------- " << endl;
        cout << "| 1. Play MineSweeper              |" << endl;
        cout << "| 2. Instructions and Gameplay     |" << endl;
        cout << "| 3. Press Anything Else to Exit   |" << endl;
        cout << " ---------------------------------- " << endl;
        cout << "Selection: ";
        cin>>choice;
        cout << "          " <<endl;
        cout << "          " <<endl;
        
        switch(choice){
            case 1:
                
                /// Ask the client if they wish to play
                cout << "Hello, " << player << " welcome to MineSweeper!" << endl;
                cout << "Would you like to continue? " << endl;
                cout << "| y for Yes| n for No |" << endl;
                char input; 
                cin >> input;
                cout << " " << endl;
                
                /// If yes, then it prompts the user to play the game
                if (input == 'y') {
                    cout << "Would you like to load a previous game? " << endl;
                    cout << "To continue:" << endl;
                    cout << "| y for yes | n for no |" << endl;
                    char input2;
                    cin >> input2;
                    cout << "          " <<endl;
                    ///Loads the previous game
                    if (input2 == 'y') {
                        loadGame();
                    }else
                        /// Retrieves row and column information from user
                        userInput();
                    
                    ///Verifies input
                    if (check()) {
                        while (input == 'y' && check()) {
                            ///Runs the actual program
                            run();
                            cout << endl;
                            cin.ignore();
                            cout << "Would you like to play again?" << endl;
                            cout << "To continue:" << endl;
                            cout << "| y for yes | n for no |" << endl;
                            cin >> input;
                            cout << endl;
                            /// Retrieves data if user wants to continue
                            if (input == 'y') {
                                userInput();
                                ///Wipes the boards
                                wipe();
                            }
                        }
                    }
                    ///Error Checking: information was invalid
                    else
                        throw badIn();
                }
                cout << "Game Over." << endl;

                /// Taking out the trash
                delete player;
                break;

            case 2:
                instructions();
                break;

                ///Exits Menu  
            default: exitStage = false;
        }
                
    }while(exitStage == false);
}

/// run() is the function that allows for the user to make there turn selection.
void Settings::run(){
    /// calls for the function that sets the mines.
    mineSet();
    /// Calls for the function that reveals the mines as selected.
    reveal();
    int row, col;
    
    /// start turn at zero
    int turn = 0;
    int initialTime = static_cast<unsigned int> (time(0));
    do{
        int start = static_cast<unsigned int> (time(0));
        cout << "Turn: " << turn++ << endl;
        
        /// Row selection
        do{
            /// save game.
            cout << "To exit and save the game: enter -1" << endl;
            cout << "Row: ";
            cin >> row;
            
            /// if the user wants to save
            if(row == -1){
                /// calls our save function.
                saveGame();
                return;
            }
            /// Input validation. we check for our bounds.
        }while(row < 0 || row >= rows);
        /// Columns selection
        do{
            cout << "Column: ";
            cin >> col;
            
            /// checks the bounds of columns
        }while (col < 0 || col >= cols);
        /// end our loop
        int turnEnd = static_cast<unsigned int> (time(0));
        cout << "Turn took: " << turnEnd - start << " seconds.\n";
        cout << endl;
    }while (continue_(row, col) && !hasWon());
    
    /// one the game has been won or lost.
    
    /// win case
    if(hasWon()){
        cout << "Winner!" << endl;
        cout << "You won, clearly you have more patience when it comes to " << endl;
        cout << " to playing this game of chance and strategy." << endl;
        cout << " " << endl;
        flagSet();
    }
    
    /// lose case
    else{
        cout << "Sorry you lost." << endl;
        cout << "better luck next time." << endl;
        data[row][col] = Settings::LOSER;
    }
    
    /// Display the time the entire game took.
    int totalTime = static_cast<unsigned int> (time(0));
    cout << "The game lasted a total of : " << totalTime - initialTime
         << " seconds.\n" << endl;
    
    /// print the final board.
    print();
}

char* Settings::userName(){
    cout << "Enter your desired username: ";
    string input;
    cin >> input;
    typedef string::size_type sType;
    sType size = input.size();
    char *name = new char[size + 1];
    for(sType i = 0; i != size; ++i){
        *(name + i) = input[i];
    }
    *(name + size + 1) = '\0';
    
    return name;
}

/// wipe() clears the game board.
void Settings::wipe(){
    /// makes sure that each spot is empty.
    for (int i = 0; i != rows; ++i)
        for (int j = 0; j != rows; ++j)
            data[i][j] = Settings::EMPTY;
}

/// takes in an integer variable and outputs as difficulty.
Settings::Difficulty Settings::convert(int choice){
    switch (choice) {
        case (0):
            return Settings::EASY;
            break;
        case (1):
            return Settings::NORMAL;
            break;
        case (2):
            return Settings::HARD;
        default:
            return Settings::EASY;
            break;
    }
}

/// allows for the locations of the mine to be revealed 
/// after the client has either won or lost.
void Settings::print() const{
    cout << "Board: \n";
    for (int row = 0; row != rows; ++row) {
        for (int col = 0; col != cols; ++col) {
            ///Used to identify mines/empty spots/proximity to mines
            if (*(*(data + row) + col) == Settings::LOSER)
                cout << "t  ";
            else if (*(*(data + row) + col) == Settings::MINE)
                cout << "x  ";
            else if (!noMine(row, col))
                cout << proximity(row, col) << "  ";
            else
                cout << "0  ";
        }
        cout << endl;
    }
    cout << endl;
}

/// Prints our columns and reveals our flags of spots
/// base on what it holds.
void Settings::reveal() const{
    /// Print the column index
    for (int i = 0; i != cols; ++i) {
        if (i == 0)
            cout << "  ";
        cout << setw(3) << i;
    }
    cout << endl;
    for (int row = 0; row != rows; ++row) {
        for (int col = 0; col != cols; ++col) {
            if (col == 0 && row < 10) cout << row << "  ";
            if (col == 0 && row >= 10) cout << row << " ";
            ///Keeps empty squares and mines hidden
            if (data[row][col] == Settings::EMPTY ||
                    data[row][col] == Settings::MINE)
                cout << setw(3) << right << "+ ";
                ///Reveals cleared areas
            else if (data[row][col] == Settings::NOMINE)
                cout << setw(2) << 0 << " ";
                /// Print out the actual value of the square
            else
                cout << setw(2) << data[row][col] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

/// calculations for how many mines should be placed.
/// this depends on user's selected difficulty.
int Settings::nMines(Settings::Difficulty userSet) const{
    if (userSet == Settings::EASY)
        return (rows * cols) / 10;
    else if (userSet == Settings::NORMAL)
        return (rows * cols) / 6;
    else
        return (rows * cols) / 4;
}

/// Randomly place our mines on the board.
void Settings::mineSet(){
    ///Determines how many mines will be used
    int copyM = mines;
    ///Continues looping through mines until they're all laid out
    while (copyM) {
        for (int i = 0; i != rows; ++i) {
            for (int j = 0; j != cols; ++j) {
                /// place mines if result of rand()%15 == 0
                if ((rand() % 100) % 10 == 0) {
                    ///only place mines if mines are still available
                    /// and current space is empty
                    if (copyM && data[i][j] == Settings::EMPTY) {
                        /// set the mine
                        data[i][j] = Settings::MINE;
                        /// decrement number of mines available
                        --copyM;
                    }
                }
            }
        }
    }
}

/// Determine how many mines are adjacent to the selected spot.
int Settings::proximity(int row, int col, int FLAG) const{
        
    ///The number of adjacent mines
    int adjMine = 0;
    ///Ignore first/last row/column
    /// Search interior
    if (row > 0 && col > 0 && row < rows - 1 && col < cols - 1) {
        for (int i = row - 1; i <= row + 1; ++i) {
            for (int j = col - 1; j <= col + 1; ++j)
                if (data[i][j] == FLAG)
                    ++adjMine;
        }
    }        
    /// checks first row, doesn't check first or last column
    else if (row == 0 && col > 0 && col < cols - 1) {
        for (int i = row; i <= row + 1; ++i) {
            for (int j = col - 1; j <= col + 1; ++j)
                if (data[i][j] == Settings::MINE)
                    ++adjMine;
        }
    }        
    /// checks last row, doesn't check first or last column
    else if (row == rows - 1 && col > 0 && col < cols - 1) {
        for (int i = row - 1; i <= row; ++i) {
            for (int j = col - 1; j <= col + 1; ++j)
                if (data[i][j] == Settings::MINE)
                    ++adjMine;
        }
    }        
    ///checks first column, doesn't check first or last row
    ///sweeps to the right
    else if (col == 0 && row > 0 && row < rows - 1) {
        for (int i = row - 1; i <= row + 1; ++i) {
            for (int j = col; j <= col + 1; ++j)
                if (data[i][j] == Settings::MINE)
                    ++adjMine;
        }
    }        
    /// checks last column, doesn't check first or last row  
    /// sweeps to the left
    else if (col == cols - 1 && row > 0 && row < rows - 1) {
        for (int i = row - 1; i <= row + 1; ++i) {
            for (int j = col - 1; j <= col; ++j)
                if (data[i][j] == Settings::MINE)
                    ++adjMine;
        }
    }        
    /// checks top left corner
    else if (row == 0 && col == 0) {
        if (data[row][col + 1] == Settings::MINE) ++adjMine;
        if (data[row + 1][col] == Settings::MINE) ++adjMine;
        if (data[row + 1][col + 1] == Settings::MINE) ++adjMine;
    }        
    /// checks top right corner
    else if (row == 0 && col == cols - 1) {
        if (data[row][col - 1] == Settings::MINE) ++adjMine;
        if (data[row + 1][col] == Settings::MINE) ++adjMine;
        if (data[row + 1][col - 1] == Settings::MINE) ++adjMine;
    }        
    /// checks bottom left corner
    else if (row == rows - 1 && col == 0) {
        if (data[row - 1][col] == Settings::MINE) ++adjMine;
        if (data[row - 1][col + 1] == Settings::MINE) ++adjMine;
        if (data[row][col + 1] == Settings::MINE) ++adjMine;
    }        
    /// checks bottom right corner
    else if (row == rows - 1 && col == cols - 1) {
        if (data[row - 1][col - 1] == Settings::MINE) ++adjMine;
        if (data[row - 1][col] == Settings::MINE) ++adjMine;
        if (data[row][col - 1] == Settings::MINE) ++adjMine;
    }
    /// return number of mines from appropriate if statement

    return adjMine;
}

/// clears an area that is marked as CLEAR
/// i.e 0 adjacent mines.
void Settings::showZeros(int row, int col){
    /// check bounds
    if (row >= rows || row < 0 || col >= cols || col < 0)
        return;
    if (noMine(row, col) && data[row][col] != Settings::NOMINE) {
        data[row][col] = Settings::NOMINE;
        /// go up one row
        showZeros(row + 1, col);
        /// go down one row
        showZeros(row - 1, col);
        /// go right one col
        showZeros(row, col + 1);
        /// go left one col
        showZeros(row, col - 1);
    }        
    /// space was not clear or already shown
    else
        return;
}

/// this shows how many mines are adjacent to the spot.
void Settings::flagSet(){
    for (int i = 0; i != rows; ++i)
        for (int j = 0; j != cols; ++j)
            /// do not look for adjacent mines in areas
            /// where mine is already present.
            if(data[i][j] != Settings::MINE)
                data[i][j] = proximity(i, j);
}

/// find the perimeter of the cleared area.
void Settings::bounds(){
    for (int row = 0; row != rows; ++row) {
        /// avoid searching at left and right edge of array
        for (int col = 0; col != cols; ++col) {
            /// when you're not on the bounds of the array
            if (row > 0 && row < rows - 1
                    && col > 0 && col < cols - 1) {
                if (data[row][col] == Settings::NOMINE) {
                    /// check that the previous number has mines adjacent
                    if (data[row][col - 1] != Settings::NOMINE)
                        data[row][col - 1] = proximity(row, col - 1);
                    /// check if the next number has mines adjacent
                    if (data[row][col + 1] != Settings::NOMINE)
                        data[row][col + 1] = proximity(row, col + 1);
                    if (data[row - 1][col] != Settings::NOMINE)
                        data[row - 1][col] = proximity(row - 1, col);
                    /// check if the next number has mines adjacent
                    if (data[row + 1][col] != Settings::NOMINE)
                        data[row + 1][col] = proximity(row + 1, col);
                    /// check the adjacent corners
                    if (data[row - 1][col - 1] != Settings::NOMINE)
                        data[row - 1][col - 1] = proximity(row - 1, col - 1);
                    if (data[row - 1][col + 1] != Settings::NOMINE)
                        data[row - 1][col + 1] = proximity(row - 1, col + 1);
                    if (data[row + 1][col - 1] != Settings::NOMINE)
                        data[row + 1][col - 1] = proximity(row + 1, col - 1);
                    if (data[row + 1][col + 1] != Settings::NOMINE)
                        data[row + 1][col + 1] = proximity(row + 1, col + 1);
                }
            }
        }
    }
}

/// allows for use to save the game.
void Settings::saveGame(){
    fstream saveFile("gameSave", ios::out | ios::binary);
    saveFile.write(reinterpret_cast<char*> (this), sizeof (*this));
    saveFile.close();
}

/// prints out the data variable from our structure
/// that is read from a binary file.
void Settings::loadGame(){
    fstream saveFile("gameSave", ios::in | ios::binary);
    if(!saveFile.is_open())
        throw "No previous save found.";
    
    saveFile.read(reinterpret_cast<char*> (this), sizeof (*this));
    saveFile.close();
}

Settings& Settings::operator =(const Settings &right){
    create(right.getRows(), right.getCols());
    for(int i = 0; i != right.getRows(); ++i){
        for(int j = 0; j != right.getCols(); ++j)
            data[i][j] = right[i][j];
    }
    return *this;
}

/// Creates our board
void Board::create(int row, int col){
    
    ///Used when creating dynamic board
    rows = row;
    cols = col;

    /// Creates each of the rows
    data = new int *[rows];

    /// Creates each of the columns
    for (int row = 0; row != rows; ++row)
        data[row] = new int [cols];
    //iterates to create board
}

/// wipes our board after use to ensure that
/// it is able to be deleted.
void Board::wipe() {
    for (int i = 0; i != rows; ++i){
        for (int j = 0; j != cols; ++j){
            data[i][j] = 0;
        }
    }
}

void Board::loadGame() {
}

void Board::config() {
}

/// Function deallocates memory
void Board::destroy() {
    ///Deletes each row
    for (int i = 0; i != rows; ++i){
        delete[] data[i];
    }
    ///Deletes the dynamically allocated structures
    delete data;
}

/// row validation
void Board::vRows(int row) {
    ///Checks whether the input value for rows is less than of equal to 0
    if (row <= 0){
        throw badIn();
    }
    rows = row;
}

/// column verification
void Board::vCols(int col) {
    ///Checks whether the input value for columns is less than of equal to 0
    if (col <= 0)
        throw badIn();
    cols = col;
}

/// board print function
void Board::print() const {
    for (int i = 0; i != rows; ++i) {
        for (int j = 0; j != cols; ++j) {
            std::cout << data[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

/// Game instructions and descriptions
void Settings::instructions() {
    
    /// Displays our game objective
    cout << "The Objective:" << endl;
    cout << "To locate all the mines without clicking/uncovering them." << endl;
    cout << "If you uncover a mine, you lose the game." << endl;
    cout << " " << endl;
    
    /// describes how our difficulty system works
    cout << "Difficulty Levels:" << endl;
    cout << "Beginner: 9x9 Area: 10 mines" << endl;
    cout << "Intermediate: 16x16 35 mines" << endl;
    cout << "Expert: 25x25 45 mines" << endl;
    cout << "Disclaimer: If you choose to make a grid that isn't stated " << endl;
    cout << "above, then the number of mines will be increased or decreased." << endl;
    cout << "accordingly" << endl;
    cout << "    " << endl;
    
    /// How our sizing works
    cout << "Your MineSweeper board will always be of size nxn." << endl;
    cout << "Example: When n=4" << endl;
    cout << "   1 2 3 4 " << endl;
    cout << " 1 x x x x " << endl;
    cout << " 2 x x x x " << endl;
    cout << " 3 x x x x " << endl;
    cout << " 4 x x x x " << endl;
    cout << "    " << endl;
    
    /// How the game play works
    cout << "Game Play:" << endl;
    cout << "When the game begins, every square will be covered," << endl;
    cout << "and it is up to you to discover in which squares the mines are." << endl;
    cout << "By selecting a row, followed by a column, you will reveal one " << endl;
    cout << "of the squares underneath. It will either be blank, marked by" << endl;
    cout << "a number to indicate how many adjacent mines are present, or a" << endl;
    cout << "mine. Uncovering a mine will end the game." << endl;
    cout << " " << endl;
    
    /// Explains how thw thw proximity indicator works.
    cout << "Numbered Squares: " << endl;
    cout << "These are the squares you use to decipher where the mines are hidden" << endl;
    cout << "Each of these has a number which determines how many mines are in the" << endl;
    cout << "surrounding 8 squares(e.g. North, North-East, East, South-East, South," << endl;
    cout << "South-West, West, and North-West of the square)." << endl;
    cout << " " << endl;
    cout << "Good luck!" << endl;
    cout << " " << endl;
};