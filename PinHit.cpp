/*******************************
 File: PinHit.cpp

 Project: CMSC 341 Project 4, fall 2016

 Author: Harrison Mann

 Date: 11/16/16

 Section: 4

 Email: mannhar1@umbc.edu

Source file for the PinHit class.  Basically creates
a comparable value that we can use to store pins and
the number of times that pin occurs in a text file.

*********************************/

#include <iostream>
#include "PinHit.h"

using namespace std;

PinHit::PinHit() {
  m_pin = -1;
  m_hits = 0;
}

PinHit::PinHit(int key, int value) {
  m_pin = key;
  m_hits = value;
  
  if(key > 9999 || key < 0){
    cerr << "Invalid pin... must be between 0 and 9999 inclusive." << endl;
    cerr << "-1 will be assigned to the pin in place of invalid num." << endl;
    m_pin = -1;
  }
}

void PinHit::SetKey(int pin) {
  if(pin > 9999 || pin < 0){
    cerr << "Invalid pin... must be between 0 and 9999 inclusive." << endl;
  }else{
    m_pin = pin;
  }
}

int PinHit::GetKey() const {
  return m_pin;
}

int PinHit::GetValue() const {
  return m_hits;
}

void PinHit::IncrementHits() {
  m_hits = m_hits + 1;
}

int PinHit::CompareTo(const PinHit& other) const {
  if(m_hits == other.GetValue()){
    return 0;
  }else if(m_hits < other.GetValue()){
    return -1;
  }else{
    return 1;
  }
}

bool PinHit::operator==(const PinHit& other) const{
  if(m_pin == other.GetKey()){
    return true;
  }else{
    return false;
  }
}
