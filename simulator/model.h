extern float expdev(long *idum);
extern float Time, lambda, mu; //, arrivals, completions, station1;
extern long  idum;

class Customer: public Actor {
public:
   Customer(void) {};
  ~Customer(void) {};
public:
  void Handler(BeginMsg    &msg);
  void Handler(CalendarMsg &msg);
public:
  float ts;
  Station * station;
};

class Source: public Actor {
public:
   Source(void) {};
  ~Source(void) {};
public:
  void Handler(BeginMsg    &   ) { };  // never used
  void Handler(CalendarMsg &msg);
};

/* (C) Copyright 1998-2008 University of Stellenbosch */

