extern float Time;

#include <iostream>

#include   "queues.h"
#include "calendar.h"
#include     "path.h"
#include  "station.h"

Station::Station(void) {
  no_servers = 1;       // the service station is a single server
  wl   = new FIFO;      // create the waiting line
  path = new Path;      // create the new path to store performance measures
}

/* customer arrives at station */

void Station::Request(Actor * customer) {

  BeginMsg beginmsg;

  if (path->n < no_servers)
    customer->Handler(beginmsg);  // the server is free, begin service
  else
    wl->Enqueue(customer);        // the server is busy, queue the customer

  path->Up(Time);
}

/* customer completes service */

void Station::Free(void) {

  Actor  * customer;
  BeginMsg beginmsg;

// accumulate performance measures

  path->Down(Time);

// get the next customer from the waiting line

  customer = (Actor *) wl->DequeuedItem();

// service the next customer

  if (customer) customer->Handler(beginmsg);
}

/* (C) Copyright 1998-2008 University of Stellenbosch */

