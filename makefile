lol: Racional.o main.o
	g++ Racional.o main.o -o lol

main.o: main.cpp Racional.h
	g++ -c main.cpp

Racional.o: Racional.cpp Racional.h
	g++ -c Racional.cpp
