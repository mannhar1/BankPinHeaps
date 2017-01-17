# BankPinHeaps
Concepts in use:
Min Heap,
Max Heap,
File I/O,
Templates,
Inheritance

This project reads in from a txt file listing bank pins and organizes them into either a min or max heap (depending on command line argument), based on the frequency of the pins appearance.  Once the Heap is entirely built, it is sent to a function "Hack" to try and hack into a randomly generated bank pin by using the item at the top of the stack.  After each trial the item is taken off the top of the stack and the next item is used to try and "hack" into the pin.  After a certain number of attempts, the program ceases and the "hack" has failed.

To run the program:

make clean

make

make run INPUT=Input1.txt FLAG=--max (could also be --min for a min heap)


The "hack" function in the file Driver.cpp was supplied by my instructor. I did not write anything inside of this function.
