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
        enum gameDif {EASY, NORMAL, HARD}; /// Our Game difficulty.
        enum state {EMPTY=10, MINE, CLEAR, LOSER}; /// The State or flag of a
                                                   /// spot on our game board.
        int mines;
        
        /// Utility Functions 
        void create(int, int);
        MineSweep::gameDif intTODiff(int);
        bool Valid() const;
        int numMine(MineSweep::gameDif) const;
        void setMine();
        void setState();
        int Adjacent(int, int, int = MineSweep::MINE) const;
        bool clear(int, int) const;
        void setPerimeter();
        void disZeros(int, int);
        bool winner()const;
        bool replay(int, int);
        void display();
        char *user();
        
    public:
        /// Constructor 
        MineSweep(int row, int colm):GameBoard(row, colm){
            clear();
        }
        
        /// Function Prototypes
        void setRow(int);
        void setColm(int);
        int getRow() const{
            return row;
        }
        int getColm() const{
            return colm;
        }
        int getMine() const{
            return mines;
        }
        void print() const;
        void init();
        void play();
        void clear();
        void save();
        void load();
        
        MineSweep& operator=(const MineSweep&);
        
};

#endif	/* MINESWEEP_H */

