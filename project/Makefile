main: Wiimote.o ZedBoard.o main.o
	g++ Wiimote.o main.o ZedBoard.o -o main
Wiimote.o: Wiimote.cc Wiimote.h
	g++ -c Wiimote.cc
ZedBoard.o: ZedBoard.cc ZedBoard.h
	g++ -c ZedBoard.cc
main.o: main.cc Wiimote.h ZedBoard.h
	g++ -c main.cc
clean: 
	rm edit Wiimote.o main.o ZedBoard.o