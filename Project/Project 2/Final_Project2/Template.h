/* 
 * File:   Abstract.h
 * 
 * Author: Alfredo Diaz
 *
 * Purpose: This is our template class that could
 *          be used for a majority of games that 
 *          require a board. It is simple but functional
 *          for what was asked of.
 * 
 * Created on June 6, 2016, 2:17 PM
 */

#ifndef TEMPLATE_H
#define	TEMPLATE_H

/// defines our template class.
template<class T>

class BoardGame {

    private:
        T* p;

    public:
        BoardGame():p(0){}
        BoardGame(T* t):p(t){}
        ~BoardGame() {delete p;}
        BoardGame<T>& operator=(const T&);
        operator bool(){return p;}
        T* operator->() const;
        T& operator*() const;
};

template<class T>

T* BoardGame<T>::operator->() const {
    /// only return p if it points to something
    if (p)
        return p;
    return 0;
}

template<class T>

T& BoardGame<T>::operator*() const{
    if (p)
        return *p;
}

template<class T>

BoardGame<T>& BoardGame<T>::operator=(const T& rhs) {
    p = &rhs;
}

#endif	/* TEMPLATE_H */