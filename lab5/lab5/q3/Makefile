main: Wiimote.o main.o
	g++ Wiimote.o main.o -o main
Wiimote.o: Wiimote.cc Wiimote.h
	g++ -c Wiimote.cc
main.o: main.cc Wiimote.h
	g++ -c main.cc
clean: 
	rm edit Wiimote.o main.o