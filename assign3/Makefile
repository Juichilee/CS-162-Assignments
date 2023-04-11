CC = g++ -g
EXE = assign3

$(EXE): tycoon.o tenant.o business.o citizen.o businesscomplex.o apartmentcomplex.o house.o property.o main.o
	$(CC) tycoon.o tenant.o business.o citizen.o businesscomplex.o apartmentcomplex.o house.o property.o main.o -o $(EXE)

tycoon.o: tycoon.cpp
	$(CC) -c tycoon.cpp

tenant.o: tenant.cpp
	$(CC) -c tenant.cpp

business.o: business.cpp
	$(CC) -c business.cpp

citizen.o: citizen.cpp
	$(CC) -c citizen.cpp

businesscomplex.o: businesscomplex.cpp
	$(CC) -c businesscomplex.cpp

apartmentcomplex.o: apartmentcomplex.cpp
	$(CC) -c apartmentcomplex.cpp

house.o: house.cpp
	$(CC) -c house.cpp

property.o: property.cpp
	$(CC) -c property.cpp

main.o: main.cpp
	$(CC) -c main.cpp

clean:
	rm *.o
