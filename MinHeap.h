/*******************************
 File: MinHeap.h

 Project: CMSC 341 Project 4, fall 2016

 Author: Harrison Mann

 Date: 11/16/16

 Section: 4

 Email: mannhar1@umbc.edu

header file for the MinHeap class, derived from Heap.
Shows which functions will be defined within the class.

*********************************/

#ifndef MINHEAP_H_
#define MINHEAP_H_

#include "Heap.h"

using namespace std;

template<class T, int m_size> class MinHeap : public Heap<T, m_size>{

 public:

  //overrided functions from Heap class
  MinHeap();
  MinHeap(const Heap<T, m_size>& origHeap);
  T& Remove();
  void Insert(T& insertable);
  void PercolateUp(int index);
  void PercolateDown(int index);



 private:

  //T* m_array; created in the base class so it exists here too

  //int m_numItems; created in base class
};

#include "MinHeap.cpp"
#endif 


