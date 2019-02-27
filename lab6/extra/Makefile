MultiSpeed: GPIO.o MultiSpeed.o
	g++ -std=c++0x GPIO.o MultiSpeed.o -o MultiSpeed
	
GPIO.o: GPIO.cc GPIO.h
	g++ -std=c++0x -c GPIO.cc
MultiSpeed.o: MultiSpeed.cc GPIO.h
	g++ -std=c++0x -c MultiSpeed.cc
clean: 
	rm GPIO.o MultiSpeed.o