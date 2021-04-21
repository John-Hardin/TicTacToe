#-*- Makefile -*-

#Target: dependencies
#	action




main:  main.o game.o
	g++ -w main.o game.o -o main
main.o: main.cpp
	g++ -c -w -g main.cpp 
game.o: game.cpp game.hpp board.hpp player.hpp
	g++ -c -w -g game.cpp 
clean:
	rm -f *.o *.out main