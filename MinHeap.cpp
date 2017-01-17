/*******************************
 File: MinHeap.cpp

 Project: CMSC 341 Project 4, fall 2016

 Author: Harrison Mann

 Date: 11/16/16

 Section: 4

 Email: mannhar1@umbc.edu

Source file for the MinHeap class.  Redefines
some of the functionality of the Heap class. Creates
a MinHeap where the values of the parents are lower than 
their children.

*********************************/

#ifndef MINHEAP_CPP_
#define MINHEAP_CPP_
#include "MinHeap.h"

using namespace std;


template<class T, int m_size>
MinHeap<T, m_size>::MinHeap() {
  this->m_array = new T[m_size];
  this->m_numItems = 0;//start off at 0
  //when inserting a new item into a heap, FIRST increment m_numItems and THEN add the item in at m_array[m_numItems] so we begin at index[1]
}

template<class T, int m_size>
MinHeap<T, m_size>::MinHeap(const Heap<T, m_size>& origHeap) : Heap<T, m_size>(origHeap) {

}

template<class T, int m_size>
T& MinHeap<T, m_size>::Remove() {
  if(this->m_numItems == 1){
    this->m_numItems = 0;
    return this->m_array[1];
  }
  if(this->m_numItems == 0){
    cout <<"Cant remove from an empty heap!" << endl;
  }

  this->m_array[0] = this->m_array[1];
  this->m_array[1] = this->m_array[this->m_numItems];
  this->m_numItems = this->m_numItems - 1;
  PercolateDown(1);

  return this->m_array[0]; 

}

template<class T, int m_size>
void MinHeap<T, m_size>::Insert(T& insertable) {
  this->m_numItems = this->m_numItems + 1;

  this->m_array[this->m_numItems] = insertable;

  PercolateUp(this->m_numItems);
}


template<class T, int m_size>
void MinHeap<T, m_size>::PercolateUp(int index) {
  T temp = this->m_array[index];
  int hits = this->m_array[index].GetValue();
  
  for ( ; index > 1 && hits < this->m_array[index/2].GetValue(); index = index/2){
    this->m_array[index] = this->m_array[index/2];
  }
  this->m_array[index] = temp;
}

template<class T, int m_size>
void MinHeap<T, m_size>::PercolateDown(int index) {
  int child;

  int hits = this->m_array[index].GetValue();
  T temp = this->m_array[index];

  for( ; index * 2 <= this->m_numItems; index = child){
    child = index * 2;

    if(child != this->m_numItems && this->m_array[child + 1].GetValue() < this->m_array[child].GetValue()){
      child = child + 1;
    }
    if(this->m_array[child].GetValue() < hits){
      this->m_array[index] = this->m_array[child];
    }else{break;}
  }
  this->m_array[index] = temp;
}


#endif

