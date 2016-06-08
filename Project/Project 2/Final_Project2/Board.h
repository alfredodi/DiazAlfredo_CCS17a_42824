/* 
 *  File:   board.h
 * 
 *  Author: Alfredo Diaz
 *
 *  Purpose: This class is used to create our structure 
 *           that will hold our data in this case it will
 *           hold our game board matrix. as well as a few 
 *           methods that are used by them. everything 
 *           here is defined in our main function.
 *           This is due to the fact that it saves folder space
 *           no need to clutter a project folder with two file
 *           per class. 
 * 
 *  Created on June 6, 2016, 2:35 PM
 */

#ifndef BOARD_H
#define	BOARD_H

/// System Libraries

/// User Libraries
#include "Abstract.h"

/// class definition of Board holds our game field
/// inheritances our abstract class 
class Board : public AbstractClass{
    /// private members 
    private:
        
    /// protected members    
    protected:
        /// Holds our games data
        int **data;
        /// Rows on minefield
        int rows;
        /// Columns on minefield
        int cols;
        /// create the game board
        virtual void create(int, int);
    
    /// public members
    public:
        /// Throw this if user tries to set negative row or column
        class badIn{};
    
        Board(int rows, int cols) {
            create(rows,cols);
            wipe();
        }
        virtual ~Board(){
            destroy();
        }
        virtual void destroy();
        virtual void vRows(int);
        virtual void vCols(int);
        virtual int getRows() const {
            return rows;
        }
        virtual int getCols() const {
            return cols;
        }
        virtual void wipe();
        virtual void config();
        virtual void loadGame();
        virtual void print() const;
        int* operator[](int index) {
            return data[index];
        }
        int* operator[](int index) const { 
            return data[index];
        }
};

#endif	/* BOARD_H */