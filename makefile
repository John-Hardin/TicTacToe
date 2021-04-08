#-*- Makefile -*-

#Target: dependencies
#	action




main:  main.o game.o player.o board.o
	g++ -w main.o game.o player.o board.o -o main
main.o: main.cpp
	g++ -c -w -g main.cpp 
game.o: game.cpp game.hpp
	g++ -c -w -g game.cpp 
board.o: board.cpp board.hpp
	g++ -c -w -g board.cpp
player.o: player.cpp player.hpp
	g++ -c -w -g player.cpp 
clean:
	rm -f *.o *.out main