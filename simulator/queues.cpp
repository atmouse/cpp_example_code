#include <iostream>

#include   "queues.h"
#include "calendar.h"

Item::Item(void) {
  key  = 0.0;
  next = NULL;
}

/*-----------------------------------------------------------------*/
Queue::Queue(void) {
  first = NULL;
}

Item * Queue::DequeuedItem(void) {

  Item * x;

  x = first;
  if (x)
    first = x->next;
  return(x);
}

int Queue::Empty(void) {
  return(first == NULL);
}

int Queue::Size(void) {

  int n = 0;
  Item * x;

  x = first;
  while (x) {
    x = x->next;
    n++;
  }
  return(n);
}
/*-----------------------------------------------------------------*/
FIFO::FIFO(void) {
  last = NULL;
}

void FIFO::Enqueue(Item *i) {
  i->next = NULL;
  if (first)
    last->next = i;
  else
    first = i;
  last = i;
}
/*-----------------------------------------------------------------*/
void LIFO::Enqueue(Item *i) {
  i->next = first;
  first   = i;
}
/*-----------------------------------------------------------------*/
void Ranked::Enqueue(Item *i) {

  Item * x;

  if ((first == NULL) || (i->key < first->key)) {
    i->next = first;
    first   = i;
  }
  else {
    x = first;

    while ((x->next) && (i->key >= x->next->key)) x = x->next;

    i->next = x->next;
    x->next = i;
  }
}

/* (C) Copyright 1998-2008 University of Stellenbosch */

