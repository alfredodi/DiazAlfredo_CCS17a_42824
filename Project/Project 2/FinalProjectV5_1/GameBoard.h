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
        int rows;
        int cols;
        /// Creates our game board.
        virtual void create(int, int);
        
    public:
        // Add any public members here.
        class BadInput {};
        
        /// Our game constructor
        GameBoard(int row, int colm){
            create(row,colm);
            clearBoard();
        }
        /// Our de-constructor
        virtual ~GameBoard(){
            destroy();
        }
        virtual void destroy();
        virtual void setRow(int);
        virtual void setColm(int);
        virtual int getRow() const{
            return rows;
        }
        virtual int getColm() const{
            return cols;
        }
        virtual void clearBoard();
        virtual void initilize();
        virtual void loadGame();
        virtual void print() const;
        int* operator[](int index){
            return data[index];
        }
        int* operator[](int index) const{
            return data[index];
        }        
};

#endif	/* GAMEBOARD_H */