class Station {
public:
   Station(void);
  ~Station(void) {};
public:
  void Request(Actor *customer);
  void Free(void);
public:
  Path * path;
  int    no_servers;
  FIFO * wl;
};

/* (C) Copyright 1998-2008 University of Stellenbosch */

