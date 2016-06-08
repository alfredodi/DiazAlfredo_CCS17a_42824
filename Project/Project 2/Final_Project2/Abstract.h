/* 
 * File:   Abstract.h
 * 
 * Author: Alfredo Diaz
 * 
 * Purpose: This is our abstract class that holds our 
 *          functions that will be defined via other classes.
 *          mostly used for when different classes define it 
 *          differently the other ones (classes.
 *          used in main to define a few of these functions / methods.
 * 
 * Created on June 6, 2016, 2:58 PM
 */

#ifndef ABSTRACT_H
#define	ABSTRACT_H

// Class definition of our abstract class
class AbstractClass{
/// our public members    
public:
    /// virtual functions that are left pure in order 
    /// to be defined within other classes.
    virtual void vRows(int) = 0;
    virtual void vCols(int) = 0;
    virtual void config() = 0;
    virtual void print() const = 0;
    virtual int getRows() const = 0;
    virtual int getCols() const = 0; 
};

#endif	/* ABSTRACT_H */