extern int   events, noevents;
extern float Time;

using namespace std;

#include <iostream>

#include   "queues.h"
#include "calendar.h"

/* an event occurs at time t: enter the event into the event calendar */

void Actor::Schedule(float t) {
  setKey(t);
  calendar->Enqueue(this);
  return;
}

void Simulate(void) {

  Actor * current;
  CalendarMsg calendarmsg;

  while (noevents < events) {
    noevents++;              // count the next event

    if (!calendar->Empty()) {

/* get the next event from the event calendar */

      current = (Actor *) calendar->DequeuedItem();
      Time    = current->getKey();     // update the simulation time
      current->Handler(calendarmsg);   // do the next event
    }
    else {
      cout << "empty calendar\n";
      break;
    }
  }
}

/* (C) Copyright 1998-2008 University of Stellenbosch */

