#ifndef PRODUCTIONWORKER_H
#define	PRODUCTIONWORKER_H

#include "Employee.h"

using namespace std;

class ProductionWorker : public Employee{
protected:
    int shift;
    float rate;
public:
    ProductionWorker();
    void setShift(int);
    int getShift();
    void setRate(float);
    float getRate();
    class BadClass{};
};

#endif	/* PRODUCTIONWORKER_H */

