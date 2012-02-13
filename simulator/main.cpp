using namespace std;

#include <iostream>

#include "queues.h"
#include "calendar.h"
#include "path.h"
#include "station.h"
#include "model.h"

/* global variables */

int   events    = 1000000; // the number of events to simulate
int noevents    = 0;       // the number of events simulated
int arrivals    = 0;       // the number of arrivals   to   the model
int completions = 0;       // the number of departures from the model
float Time      = 0.0;     // the global simulation time
float lambda    = 0.0;     // arrival rate
float mu        = 0.0;     // service rate
long  idum;                // randum number generator seed
Station * station1;        // a single service station
Ranked  * calendar;        // the calendar

int main()
{
  extern float ran2(long *idum);
  extern void  Simulate(void);

  Source * source;

  float L,rho;

  cout << "lambda = ";
  cin  >> lambda;
  cout << "\n";

  cout << "mu = ";
  cin  >> mu;
  cout << "\n";

  if (lambda >= mu) {
    cout << "lambda >= mu\n";
    return(0);
  }

  idum = -1;
  ran2(&idum);              // seed the random number generator
  Time = 0.0;               // initialise the simulation clock

  source   = new Source;    // create the first event, an arrival
  station1 = new Station;   // create a service station
  calendar = new Ranked;    // create the calendar

  source->Schedule(0);      // schedule the first arrival at time 0

  Simulate();               // do the simulation

  cout << "simulation time = " << Time << "\n";
  cout << "average queue length = " << station1->path->Mean(Time) << "\n";
  cout << "arrivals = " << arrivals;
  cout << " completions = " << completions << "\n";

  rho = lambda/mu;
  L   = rho   / (1.0 - rho);

  cout << "M/M/1 queue length = " << L << "\n";
  cout << station1->wl->Size() << " customer(s) remaining in queue\n";
  cout << calendar->Size() << " actor(s) in calendar\n";

  return(0);
}

/* (C) Copyright 1998-2008 University of Stellenbosch */

