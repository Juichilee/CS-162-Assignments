CC = g++

assign1.o: run_netflix.o netflix.o
	$(CC) -o assign1 run_netflix.o netflix.o
netflix: netflix.cpp
	$(CC) -o netflix netflix.cpp
run_netflix: run_netflix.cpp
	$(CC) -o run_netflix netflix.cpp
clean:
	rm *.o
