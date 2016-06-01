#ifndef DATE_H
#define	DATE_H

#include <string>

using namespace std;

class Date{
private:
    int month;
    int day;
    string year;
public:
    Date();
    void setMonth(int);
    void setDay(int);
    void setYear(std::string);
    int getMonth()const;
    int getDay()const;
    string getYear()const;
    void prntMonth();
    void slashForm();
    void cmaForm();
    void mlaForm();
    class BadClass{};
};

#endif	/* DATE_H */

