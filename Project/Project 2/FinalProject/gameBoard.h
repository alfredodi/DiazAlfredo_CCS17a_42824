/* 
 * File:   gameBoard.h
 * Author: Alfredo Diaz
 *
 * Created on May 19, 2016, 11:56 AM
 */

#ifndef GAMEBOARD_H
#define	GAMEBOARD_H

#include "AbsBoard.h"

/// This is a base class that could be utilized by any game that needs a n N*M
/// array game board such as Mine Sweeper or BattleShip.
class GameBoard: public AbsBoard{
    private:
        // Add Any Private members here.
        
    protected:
        
        // Add any protected members here>
        int **data;
        int row;
        int colm;
        /// Creates our game board.
        virtual void create(int, int);
        
    public:
        // Add any public members here.
        class BadInput {};
        
        /// Our game constructor
        GameBoard(int row, int colm){
            create(row,colm);
            clear();
        }
        /// Our de-constructor
        virtual ~GameBoard(){
            destroy();
        }
        virtual void destroy();
        virtual void setRow(int);
        virtual void setColm(int);
        virtual int getRow() const{
            return row;
        }
        virtual int getColm() const{
            return colm;
        }
        virtual void clear();
        virtual void setUp();
        virtual void load();
        virtual void print() const;
        int* operator[](int idx){
            return data[idx];
        }
        int* operator[](int idx) const{
            return data[idx];
        }
            
            
};

#endif	/* GAMEBOARD_H */

