#include <stdio.h>
#include "time.h"

//constructor
Time::Time()    {
    hour = minute = second = 0;
}

//constructor
Time::Time(int hr, int min, int sec)    {
    setTime(hr, min, sec);
}

//Time member function
void Time::printStandard()    {
    printf("The time is: %d : %d : %d.\n", hour, minute, second);
}

//Time member function
void Time::setTime(int hr, int min, int sec)  {
    hour = hr;
    minute = min;
    second = sec;
}
