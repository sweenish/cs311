# Adam Sweeney

release : hotdog tidy

hotdog : Hotdog.o main.o
	g++ -Wall -std=c++11 -o  hotdog Hotdog.o main.o

Hotdog.o : Hotdog.cpp
	g++ -Wall -std=c++11 -c Hotdog.cpp

main.o : main.cpp
	g++ -Wall -std=c++11 -c main.cpp

tidy : 
	@rm -f core *.o

clean :
	rm -f core *.o hotdog
