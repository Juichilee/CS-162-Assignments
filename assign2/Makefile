CC = g++ -g

EXE = assign2

$(EXE): main.o restaurant.o pizza.o menu.o
	$(CC) main.o restaurant.o pizza.o menu.o -o $(EXE)

restauraunt.o: restaurant.cpp
	$(CC) -c restaurant.cpp

pizza.o: pizza.cpp
	$(CC) -c pizza.cpp

menu.o: menu.cpp
	$(CC) -c menu.cpp

main.o: main.cpp
	$(CC) -c main.cpp

clean:
	rm *.o
