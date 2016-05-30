/* 
 * File:   Template.h
 * Author: Alfredo
 *
 * Created on May 26, 2016, 12:36 PM
 */

#ifndef TEMPLATE_H
#define	TEMPLATE_H

template<class T>
class AnyGame{
    private:
        T* p;
        
    public:
        AnyGame():p(0){
        }
        AnyGame(T* t):p(t){            
        }
        ~AnyGame(){
            delete p;
        }
        AnyGame<T>& operator=(const T&);
        operator bool(){
            return p;
        }
        T* operator->() const;
        T& operator*() const;        
};

template<class T>
T* AnyGame<T>::operator ->() const{
    if(p){
        return p;
    }
    return 0;
}

template<class T>
T& AnyGame<T>::operator *() const{
    if(p){
        return p;
    }
    return 0;
}

template<class T>
AnyGame<T>& AnyGame<T>::operator =(const T& board){
    p = &board;
}

#endif	/* TEMPLATE_H */

