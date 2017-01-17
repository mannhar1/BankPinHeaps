/*******************************
 File: Heap.cpp

 Project: CMSC 341 Project 4, fall 2016

 Author: Harrison Mann

 Date: 11/16/16

 Section: 4

 Email: mannhar1@umbc.edu

Source file for the Heap class.  Has a constructor 
as well as copy constructor utilized by the derived 
classes.  Also creates the base version of some virtual functions
and defines the find and contains functions for this AND
the derived classes.


*********************************/

#ifndef HEAP_CPP_
#define HEAP_CPP_
#include <cstddef>
#include <iostream>
#include "Heap.h"

using namespace std;


template<class T, int m_size>
Heap<T, m_size>::Heap() {
  m_array = new T[m_size];
  m_numItems = 0;//start off at 0
  //when inserting a new item into a heap, FIRST increment m_numItems and THEN add the item in at m_array[m_numItems] so we begin at index[1]
}

template<class T, int m_size>
Heap<T, m_size>::Heap(const Heap<T, m_size>& origHeap) {
  m_array = new T[m_size];

  for (int i = 1; i <= origHeap.GetNumItems(); i++){
    m_array[i] = origHeap.m_array[i];//adds each item starting at the first index since index[0] is blank
  }
  
  m_numItems = origHeap.GetNumItems();
}

template<class T, int m_size>
bool Heap<T, m_size>::Contains(const T& needle) const {
  if(m_numItems < 1){
    return false;
  }

  for (int i = 1; i <= m_numItems; i++){
    if (needle == m_array[i]){
      cout << "Found at index: " << i;
      return true;
    }
  }
  return false;
}


template<class T, int m_size>
const T* Heap<T, m_size>::Find(const T& needle) const {
  if(m_numItems < 1){
    return NULL;
  }

  T* ptr = m_array;

  
  for (int i = 1; i <= m_numItems; i++){
    ptr++;

    if (needle == *ptr){
      return ptr;
    }
  }
  
  return NULL;
}

template<class T, int m_size>
T& Heap<T, m_size>::Remove() {
  if(m_numItems == 1){
    m_numItems = 0;
    return m_array[1];
  }
  if(m_numItems == 0){
    cout <<"Cant remove from an empty heap!" << endl;
  }

  m_array[0] = m_array[1];
  m_array[1] = m_array[m_numItems];
  m_numItems = m_numItems - 1;
  PercolateDown(1);

  return m_array[0];

  

}

template<class T, int m_size>
void Heap<T, m_size>::Insert(T& insertable) {
  m_numItems = m_numItems + 1;

  m_array[m_numItems] = insertable;

  PercolateUp(m_numItems);
}

template<class T, int m_size>
void Heap<T, m_size>::PercolateUp(int index) {
  //do nothing for regular heaps
  //overloaded in sub classes
}

template<class T, int m_size>
void Heap<T, m_size>::PercolateDown(int index) {
  //do nothing for regular heaps
  //overloaded in sub classes
}

template<class T, int m_size>
int Heap<T, m_size>::GetNumItems() const{
  return m_numItems;
}


#endif /* HEAP_CPP_ */
