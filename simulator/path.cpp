#include <iostream>

#include "path.h"

Path::Path(void) {
  n = 0;
  W = t = 0.0;
}

void Path::Up(float T) {
  W+= (float) (n) * (T - t);
  n++;
  t = T;
}

void Path::Down(float T) {
  W+= (float) (n) * (T - t);
  n--;
  t = T;
}

float Path::Mean(float T) {
  float x;
  x = (W + (float) (n) * (T - t)) / T;
  return(x);
}

/* (C) Copyright 1998-2008 University of Stellenbosch */

