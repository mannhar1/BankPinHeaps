all: PinHit.o Heap.o MinHeap.o MaxHeap.o Driver.o
	g++ -Wall PinHit.cpp Heap.cpp MinHeap.cpp MaxHeap.cpp Driver.cpp -o driver.out


PinHit.o: PinHit.cpp
	g++ -Wall -c PinHit.cpp

Heap.o: Heap.cpp
	g++ -Wall -c Heap.cpp

MinHeap.o: MinHeap.cpp
	g++ -Wall -c MinHeap.cpp

MaxHeap.o: MaxHeap.cpp
	g++ -Wall -c MaxHeap.cpp


Driver.o: Driver.cpp
	g++ -Wall -c Driver.cpp


clean:
	rm -rf *.o
	rm -f *.out
	rm -f *~ *.h.gch *#

run:
	./driver.out $(INPUT) $(FLAG)

valgrind:
	valgrind driver.out $(INPUT) $(FLAG)
