all: main

fileIO.o: fileIO.cpp
	g++ -g -c fileIO.cpp fileIO.h

lloyd.o: lloyd.cpp
	g++ -g -c lloyd.cpp lloyd.h

main: main.cpp lloyd.o fileIO.o
	g++ -g main.cpp lloyd.o fileIO.o -o a.out


clean:
	rm *.o *.gch a.out
