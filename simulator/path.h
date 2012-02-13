class Path {
public:
   Path(void);
  ~Path(void) {};
public:
  void Up   (float T);
  void Down (float T);
  float Mean(float T);
public:
  int n;
private:
  float W,t;
};

/* (C) Copyright 1998-2008 University of Stellenbosch */


