/* 
 * File:   AbsBoard.h
 * Author: Alfredo Diaz
 *
 * Created on May 19, 2016, 11:51 AM
 */

#ifndef ABSBOARD_H
#define	ABSBOARD_H

class AbsBoard {
    virtual void setRow(int) = 0;
    virtual void setColm(int) = 0;
    virtual int getRow() const = 0;
    virtual int getColm() const = 0;
    virtual void initilize() = 0;
    virtual void print() const = 0;
};

#endif	/* ABSBOARD_H */