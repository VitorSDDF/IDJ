all: game executa limpa

game:  rect.o sprite.o game.o face.o state.o main.o
	g++  rect.o state.o face.o main.o game.o sprite.o -o game -std=c++11  -fmax-errors=3 -Wall -pedantic -lSDL2 -lSDL2_image -g

main.o: main.cpp game.cpp game.hpp
	g++ -c main.cpp -std=c++11 -fmax-errors=5 -Wall -pedantic -g

game.o: game.cpp  game.hpp state.cpp state.hpp
	g++ -c game.cpp -std=c++11 -fmax-errors=5 -Wall -pedantic -g
	
sprite.o:sprite.cpp sprite.hpp
	g++ -c sprite.cpp -std=c++11 -fmax-errors=5 -Wall -pedantic -g

state.o: state.cpp state.hpp sprite.cpp sprite.hpp GameObject.hpp face.hpp
	g++ -c state.cpp -std=c++11 -fmax-errors=5 -Wall -pedantic -g

face.o: face.cpp face.hpp sprite.hpp GameObject.hpp Rect.hpp 
	g++ -c face.cpp -std=c++11 -fmax-errors=5 -Wall -pedantic -g

rect.o: Rect.cpp Rect.hpp
	g++ -c Rect.cpp -std=c++11 -fmax-errors=5 -Wall -pedantic -g

executa:
	valgrind ./game

limpa: 
	rm *.o 

