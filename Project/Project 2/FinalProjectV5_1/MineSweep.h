/* 
 * File:   MineSweep.h
 * Author: Alfredo Diaz
 * Purpose: This will contain MineSweeper for our program.
 *          as well as hold our enumerated flags when a space is selected
 *          i.e. Difficulty and Mine and clear.
 * Created on May 23, 2016, 2:15 PM
 */

#ifndef MINESWEEP_H
#define	MINESWEEP_H

#include <string>
#include "GameBoard.h"

class MineSweep:public GameBoard{
    
    private:
        enum Difficulty {EASY, NORMAL, HARD}; /// Our Game difficulty.
        enum Flags {EMPTY=10, MINE, CLEAR, LOSER}; /// The State or flag of a
                                                   /// spot on our game board.
        int mines;
        
        /// Utility Functions 
        void create(int, int);
        MineSweep::Difficulty intToDiff(int);
        bool isValidIn() const;
        int nMine(MineSweep::Difficulty) const;
        void setMines();
        void setFlags();
        int nAdjacent(int, int, int = MineSweep::MINE) const;
        bool isClear(int, int) const;
        void setPerim();
        void showZeros(int, int);
        bool hasWon()const;
        bool replay(int, int);
        void display();
        char *userName();
        
    public:
        /// Constructor 
        MineSweep(int rows, int colms):GameBoard(rows, colms){
            clearBoard();
        }
        
        /// Function Prototypes
        void setRow(int);
        void setColm(int);
        int getRow() const{
            return rows;
        }
        int getColm() const{
            return cols;
        }
        int getMine() const{
            return mines;
        }
        void print() const;
        void prntObscr()const;
        void initilize();
        void playGame();
        void clearBoard();
        void saveGame();
        void loadGame();
        
        MineSweep& operator=(const MineSweep&);
        
};

#endif	/* MINESWEEP_H */

