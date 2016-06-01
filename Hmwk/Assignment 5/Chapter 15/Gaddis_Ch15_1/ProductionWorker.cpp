#include "ProductionWorker.h"
#include "Employee.h"

using namespace std;

ProductionWorker::ProductionWorker() : Employee(){
    shift = 0;
    rate = 0.0;
}

void ProductionWorker::setShift(int x){
    if(x == 1 || x == 2)shift = x;
    else throw BadClass();
}
int ProductionWorker::getShift(){
    return shift;
}
void ProductionWorker::setRate(float x){
    rate = x;
}
float ProductionWorker::getRate(){
    return rate;
}
