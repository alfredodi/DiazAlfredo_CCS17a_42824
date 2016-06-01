#ifndef TEAMLEADERS_H
#define	TEAMLEADERS_H

#include "ProductionWorker.h"

class TeamLeaders : public ProductionWorker{
    private:
        int trainHoursReq; 
        int trainHoursAttn;
        float monthBonus;
    public:
        TeamLeaders();
        void setTrainHoursReq(int);
        void setTrainHoursAttn(int);
        void setMonthBonus(float);
        int getTrainHoursReq();
        int getTrainHoursAttn();
        float getMonthBonus(); 
};

#endif	/* TEAMLEADERS_H */

