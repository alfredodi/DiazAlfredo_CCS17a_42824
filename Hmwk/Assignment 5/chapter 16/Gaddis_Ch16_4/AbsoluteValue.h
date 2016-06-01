template <class T>

#ifndef ABSOLUTEVALUE_H
#define	ABSOLUTEVALUE_H

class AbsValue {
    private:
        T absolute;
    public:
        void setAbsolute(T a){
            absolute=a;
        }
        T getAbsolute(){
            return absolute;
        }
        T findAbsolute(){
            if(absolute < 0){
                return -absolute;
            }else{
                getAbsolute();
            }
        }
};

#endif	/* ABSOLUTEVALUE_H */

