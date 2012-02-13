extern Ranked * calendar;

class                     Message { };
class    BeginMsg: public Message { };
class CalendarMsg: public Message { };

class Actor: public Item { // an abstract class
public:
           Actor(void) {};
  virtual ~Actor(void) {}; // a polymorphic class needs a virtual destructor

public:
  virtual void Handler(BeginMsg    &msg) = 0;
  virtual void Handler(CalendarMsg &msg) = 0;

public:
  void Schedule(float t);
};

/* (C) Copyright 1998-2008 University of Stellenbosch */

