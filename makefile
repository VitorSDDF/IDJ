all: game executa limpa

game: main.o game.o sprite.o state.o
	g++ -c main.o game.o sprite.o state.o -o game -std=c++11  -fmax-errors=3 -Wall -pedantic

main.o: main.cpp game.cpp game.hpp
	g++ -c main.cpp -std=c++11 -lSDL2 -lSDL2_image  -fmax-errors=3 -Wall -pedantic

game.o: game.cpp  game.hpp state.cpp state.hpp
	g++ -c game.cpp -std=c++11 -lSDL2 -lSDL2_image  -fmax-errors=3 -Wall -pedantic
	
sprite.o:sprite.cpp sprite.hpp 
	g++ -c sprite.cpp -std=c++11 -lSDL2 -lSDL2_image  -fmax-errors=3 -Wall -pedantic

state.o: state.cpp state.hpp sprite.cpp sprite.hpp
	g++ -c state.cpp -std=c++11 -lSDL2 -lSDL2_image  -fmax-errors=3

executa:
	./game

limpa: 
	rm *.o 
