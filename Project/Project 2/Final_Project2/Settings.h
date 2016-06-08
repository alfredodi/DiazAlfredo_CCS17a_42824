/* 
 * File:   Settings.h
 * Author: Alfredo Diaz
 * 
 * Purpose: Settings is used to define / create
 *          a majority of functions that will be
 *          needed in order to run the game. This 
 *          includes our states such as difficulty, 
 *          and flags. overall declares a majority of 
 *          our methods that will be needed. 
 *
 * Created on June 6, 2016, 3:13 PM
 */

#ifndef SETTINGS_H
#define	SETTINGS_H

/// System Libraries
#include <string>

/// User Libraries
#include "Board.h"

/// class definition  of settings
/// inheritance our board class
class Settings: public Board{
    
    private:
        enum Difficulty {EASY, NORMAL, HARD};
        enum Flag {EMPTY = 10, MINE, NOMINE, LOSER};
        int mines;
        Settings::Difficulty convert(int);
        bool check() const;
        bool continue_(int, int);
        bool noMine(int, int) const;
        bool hasWon() const;
        char *userName();
        int nMines(Settings::Difficulty) const;
        void create(int, int);
        void bounds();
        void flagSet();
        void mineSet();
        int proximity(int, int, int = Settings::MINE) const;
        void showZeros(int, int);
        void userInput();
        
    public:
        /// Constructors and Destructors. 
        Settings(int row, int col):Board(row, col){
            wipe();
        }
        int getCols() const{
            return cols;
        }
        int getRows() const{
            return rows;
        }
        int getMines() const{
            return mines;
        }
        void config();
        void instructions();
        void loadGame();
        void run();
        void print() const;
        void reveal() const;
        void saveGame();
        void vCols(int);
        void vRows(int);
        void wipe();
        
        Settings& operator=(const Settings&);    
};

#endif	/* SETTINGS_H */