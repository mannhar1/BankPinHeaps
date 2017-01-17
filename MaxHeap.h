/*******************************
 File: MaxHeap.h

 Project: CMSC 341 Project 4, fall 2016

 Author: Harrison Mann

 Date: 11/16/16

 Section: 4

 Email: mannhar1@umbc.edu

Header file for the MaxHeap class derived from Heap. 
Shows which functions will be defined in this class

*********************************/

#ifndef MAXHEAP_H_
#define MAXHEAP_H_

#include "Heap.h"

using namespace std;

template<class T, int m_size> class MaxHeap : public Heap<T, m_size>{

 public:

  //overrided functions from Heap class
  MaxHeap();
  MaxHeap(const Heap<T, m_size>& origHeap);
  T& Remove();
  void Insert(T& insertable);
  void PercolateUp(int index);
  void PercolateDown(int index);



 private:

  //T* m_array; created in the base class so it exists here too

  //int m_numItems; created in the base class

};

#include "MaxHeap.cpp"
#endif 
