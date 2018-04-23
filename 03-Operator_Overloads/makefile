GXX=g++
LFLAGS=-Wall -std=c++11
CFLAGS=-Wall -std=c++11 -c
PROG=extraCredit

PROG: main.cpp DayOfYearEC.o
	$(GXX) $(LFLAGS) -o $(PROG) main.cpp DayOfYearEC.o

DayOfYearEC.o: DayOfYearEC.cpp DayOfYear.hpp
	$(GXX) $(CFLAGS) DayOfYearEC.cpp

clean:
	rm -f *.o $(PROG) core

