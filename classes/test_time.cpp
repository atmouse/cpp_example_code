#include <stdio.h>
#include "time.h"

using namespace std;

int main()  {
    Time t;
    t.setTime(1, 1);
    t.printStandard();

    Time * r = new Time;
    r->printStandard();

    r->setTime(5);
    r->printStandard();

    return 0;
}
