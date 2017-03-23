all: game executa limpa

game: main.o game.o sprite.o state.o
	g++ main.o game.o sprite.o state.o -o game -std=c++11 -Wall -pedantic

main.o: main.cpp game.cpp game.hpp
	g++ main.cpp -std=c++11 -lSDL2 -lSDL2_image -Wall -pedantic -c

game.o: game.cpp  game.hpp state.cpp state.hpp
	g++ game.cpp -std=c++11 -lSDL2 -lSDL2_image -Wall -pedantic -c
	
sprite.o:sprite.cpp sprite.hpp
	g++ sprite.cpp -std=c++11 -lSDL2 -lSDL2_image -Wall -pedantic -c

state.o: state.cpp state.hpp sprite.cpp sprite.hpp
	g++ state.cpp -std=c++11 -lSDL2 -lSDL2_image -Wall -pedantic -c
	
executa:
	./game

limpa: 
	rm *.o 
