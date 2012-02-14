#ifndef TIME_H
#define TIME_H

class Time  {
    private:
        int hour;
        int minute;
        int second;

    public:
         Time();
         Time(int hr, int min, int sec);
        ~Time();

        void setTime(int hr, int min, int sec):
        //void printMilitary();
        void printStandard();
};

#endif
