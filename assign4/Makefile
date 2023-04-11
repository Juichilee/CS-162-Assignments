CC = g++ -g
EXE = assign4

$(EXE): game.o ant.o bee.o bug.o harvester.o thrower.o fire.o lthrower.o sthrower.o wall.o ninja.o bodyguard.o main.o
	$(CC) game.o ant.o bee.o bug.o harvester.o thrower.o fire.o lthrower.o sthrower.o wall.o ninja.o bodyguard.o main.o -o $(EXE)

game.o: game.cpp
	$(CC) -c game.cpp

ant.o: ant.cpp
	$(CC) -c ant.cpp

bee.o: bee.cpp
	$(CC) -c bee.cpp

bug.o: bug.cpp
	$(CC) -c bug.cpp

harvester.o: harvester.cpp
	$(CC) -c harvester.cpp

thrower.o: thrower.cpp
	$(CC) -c thrower.cpp

fire.o: fire.cpp
	$(CC) -c fire.cpp

lthrower.o: lthrower.cpp
	$(CC) -c lthrower.cpp

sthrower.o: sthrower.cpp
	$(CC) -c sthrower.cpp

wall.o: wall.cpp
	$(CC) -c wall.cpp

ninja.o: ninja.cpp
	$(CC) -c ninja.cpp

bodyguard.o: bodyguard.cpp
	$(CC) -c bodyguard.cpp

main.o: main.cpp
	$(CC) -c main.cpp

clean:
	rm *.o
