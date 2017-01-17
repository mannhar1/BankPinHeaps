/*******************************
 File: Heap.h

 Project: CMSC 341 Project 4, fall 2016

 Author: Harrison Mann

 Date: 11/16/16

 Section: 4

 Email: mannhar1@umbc.edu

Header file for the Heap class.  Shows which functions will
be completed by the class as well as some virtual functions
that will end up being overridden in derived classes

*********************************/

#ifndef HEAP_H_
#define HEAP_H_

template<class T, int m_size> class Heap{

 public:

  // required functions by UML
  Heap();
  Heap(const Heap<T, m_size>& origHeap);
  bool Contains(const T& needle) const;
  const T* Find(const T& needle) const;
  virtual T& Remove();
  virtual void Insert(T& insertable);
  virtual void PercolateUp(int index);
  virtual void PercolateDown(int index);

  // student-made functions below
  int GetNumItems() const;
  
 protected:
  
  // UML-required member variables
  T* m_array;

  // student-made member variables
  int m_numItems;

};

#include "Heap.cpp"
#endif /* HEAP_H_ */
