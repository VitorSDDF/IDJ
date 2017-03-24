all: game executa limpa

game: main.o game.o
	g++ -c main.o game.o-o game -std=c++11

main.o: main.cpp game.cpp game.hpp
	g++ -c main.cpp -std=c++11 -lSDL2 -lSDL2_image

game.o: game.cpp  game.hpp state.cpp state.hpp
	g++ -c game.cpp -std=c++11 -lSDL2 -lSDL2_image
	
sprite.o:sprite.cpp sprite.hpp 
	g++ -c sprite.cpp -std=c++11 -lSDL2 -lSDL2_image

state.o: state.cpp state.hpp sprite.cpp sprite.hpp
	g++ -c state.cpp -std=c++11 -lSDL2 -lSDL2_image

executa:
	./game

limpa: 
	rm *.o 
