#include "TeamLeaders.h"

TeamLeaders::TeamLeaders() : ProductionWorker(){
    trainHoursReq = 0; 
    trainHoursAttn = 0;
    monthBonus = 0.0;
}
void TeamLeaders::setTrainHoursReq(int x){
    trainHoursReq = x;
}
void TeamLeaders::setTrainHoursAttn(int x){
    trainHoursAttn = x;
}
void TeamLeaders::setMonthBonus(float x){
    monthBonus = x;
}
int TeamLeaders::getTrainHoursReq(){
    return trainHoursReq;
}
int TeamLeaders::getTrainHoursAttn(){
    return trainHoursAttn;
}
float TeamLeaders::getMonthBonus(){
    return monthBonus;
}  
