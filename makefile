all: game executa limpa

game: sprite.o game.o state.o main.o
	g++ main.o game.o sprite.o state.o -o game -std=c++11  -fmax-errors=3 -Wall -pedantic -lSDL2 -lSDL2_image -g

main.o: main.cpp game.cpp game.hpp
	g++ -c main.cpp -std=c++11 -fmax-errors=3 -Wall -pedantic -g

game.o: game.cpp  game.hpp state.cpp state.hpp
	g++ -c game.cpp -std=c++11 -fmax-errors=3 -Wall -pedantic -g
	
sprite.o:sprite.cpp sprite.hpp 
	g++ -c sprite.cpp -std=c++11 -fmax-errors=3 -Wall -pedantic -g

state.o: state.cpp state.hpp sprite.cpp sprite.hpp
	g++ -c state.cpp -std=c++11 -fmax-errors=3 -Wall -pedantic -g

executa:
	valgrind ./game

limpa: 
	rm *.o 

