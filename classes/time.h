#ifndef TIME_H
#define TIME_H

class Time  {
    private:
        int hour;
        int minute;
        int second;

    public:
        //Time();
        Time(int hr = 0, int min = 0, int sec = 0);
        ~Time();

        void setTime(int hr = 0, int min = 0, int sec = 0);
        //void printMilitary();
        void printStandard();
};

#endif
