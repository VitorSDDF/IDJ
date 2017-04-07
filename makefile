all: game executa limpa

game:  resources.o tileset.o tilemap.o rect.o sprite.o game.o face.o state.o main.o
	g++ resources.o tileset.o tilemap.o rect.o state.o face.o game.o sprite.o main.o -o game -std=c++11  -fmax-errors=3 -Wall -pedantic -lSDL2 -lSDL2_image -g

main.o: main.cpp game.cpp game.hpp state.hpp
	g++ -c main.cpp -std=c++11 -fmax-errors=5 -Wall -pedantic -g

game.o: game.cpp  game.hpp state.cpp state.hpp
	g++ -c game.cpp -std=c++11 -fmax-errors=5 -Wall -pedantic -g
	
sprite.o:sprite.cpp sprite.hpp resources.hpp
	g++ -c sprite.cpp -std=c++11 -fmax-errors=5 -Wall -pedantic -g

state.o: state.cpp state.hpp sprite.cpp sprite.hpp gameobject.hpp face.hpp tileset.hpp tilemap.hpp
	g++ -c state.cpp -std=c++11 -fmax-errors=5 -Wall -pedantic -g

face.o: face.cpp face.hpp sprite.hpp gameobject.hpp rect.hpp 
	g++ -c face.cpp -std=c++11 -fmax-errors=5 -Wall -pedantic -g

rect.o: rect.cpp rect.hpp
	g++ -c rect.cpp -std=c++11 -fmax-errors=5 -Wall -pedantic -g

tilemap.o: tilemap.cpp tilemap.hpp tileset.hpp
	g++ -c tilemap.cpp -std=c++11 -fmax-errors=5 -Wall -pedantic -g

tileset.o: tileset.cpp tileset.hpp sprite.hpp
	g++ -c tileset.cpp -std=c++11 -fmax-errors=5 -Wall -pedantic -g

resources.o: resources.cpp resources.hpp game.hpp
	g++ -c resources.cpp -std=c++11 -fmax-errors=5 -Wall -pedantic -g

executa:
	./game

limpa: 
	rm *.o 

