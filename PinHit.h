/*******************************
 File: PinHit.h

 Project: CMSC 341 Project 4, fall 2016

 Author: Harrison Mann

 Date: 11/16/16

 Section: 4

 Email: mannhar1@umbc.edu

Header file for the PinHit class. Shows which 
functions will be implemented by the class and creates
its member variables.

*********************************/

#ifndef PINHIT_H_
#define PINHIT_H_

class PinHit {
  
 public:
  PinHit();
  PinHit(int key, int value);
  void SetKey(int pin);
  int GetKey() const;
  int GetValue() const;
  void IncrementHits();
  int CompareTo(const PinHit& other) const;
  bool operator==(const PinHit& other) const;

 private:

  int m_pin, m_hits;
  //m_pin is the actual pin.....KEY
  //m_hits is the number of times the pin was seen.....VALUE

};

#endif /* PinHit_H_ */


