/* 
 * File:   main.cpp
 * Author: rcc
 *
 * Created on May 19, 2016, 11:17 AM
 */

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <vector>

#include "MineSweep.h"
#include "Template.h"

using namespace std;

int main(int argc, char** argv) {
    
    srand(static_cast<unsigned int>(time(0)));
    
    AnyGame<GameBoard> n(new MineSweep(10,10));
    try{
        n->initilize();
    }
    catch(MineSweep::BadInput){
        cout << "Size was invalid\n";
    }
    catch(const char* line){
        cout << line << endl;
    }

    return 0;
}

