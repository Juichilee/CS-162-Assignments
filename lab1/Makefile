CC = g++
exe_file = mult_div
$(exe_file): prog.o
	$(CC) prog.o -o $(exe_file)
prog.o: prog.cpp
	$(CC) -c prog.cpp
clean:
	rm -f*.out*.o$(exe_file)
