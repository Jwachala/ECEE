main: GPIO.o main.o
	g++ GPIO.o main.o -o main
GPIO.o: GPIO.cc GPIO.h
	g++ -c GPIO.cc
main.o: main.cc GPIO.h
	g++ -c main.cc
clean: 
	rm GPIO.o main.o