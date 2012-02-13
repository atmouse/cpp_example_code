class Item {
  friend class Queue;
  friend class FIFO;
  friend class LIFO;
  friend class Ranked;
public:
   Item(void);
  ~Item(void) {};
public:
   float getKey(void)    {return key;}
   void  setKey(float t) {key = t;}
private:
  float  key;
  Item * next;
};

class Queue {
public:
   Queue(void);
  ~Queue(void);
public:
  virtual void Enqueue(Item *i) = 0;
  Item  * DequeuedItem(void);
  int             Size(void);
  int            Empty(void);
protected:
  Item * first;
};

class FIFO: public Queue {
public:
   FIFO(void);
  ~FIFO(void);
public:
  void Enqueue(Item *i);
private:
  Item * last;
};

class LIFO: public Queue {
public:
   LIFO(void);
  ~LIFO(void);
public:
  void Enqueue(Item *i);
};

class Ranked: public Queue {
public:
   Ranked(void) {};
  ~Ranked(void);
public:
  void Enqueue(Item *i);
};

/* (C) Copyright 1998-2008 University of Stellenbosch */

