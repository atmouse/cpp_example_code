extern int arrivals, completions;

#include <iostream>

#include   "queues.h"
#include "calendar.h"
#include     "path.h"
#include  "station.h"
#include    "model.h"

extern Station * station1;

void Customer::Handler(BeginMsg &) {

  float x;

  x = Time + expdev(&idum)/mu;
  Schedule(x); // schedule the completion event
}

void Customer::Handler(CalendarMsg &) {

  Station * this_station;

  this_station = station;
  delete(this);         // destroy the completed customer
  this_station->Free(); // serve the next customer (if any) at this station

  completions++;        // count the number of completions
}

void Source::Handler(CalendarMsg &) {

  float x;
  Customer * customer;

  customer          = new Customer;     // create a  new customer
  customer->ts      = Time;             // timestamp the customer
  customer->station = station1;         // route the customer to station 1
  customer->station->Request(customer); // serve or queue the customer

  x = Time + expdev(&idum)/lambda;
  Schedule(x); // schedule the next arrival

  arrivals++;  // count the number of arrivals
}

/* (C) Copyright 1998-2008 University of Stellenbosch */

