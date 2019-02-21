ServoPosition: GPIO.o ServoPosition.o
	g++ GPIO.o ServoPosition.o -o ServoPosition
	
GPIO.o: GPIO.cc GPIO.h
	g++ -c GPIO.cc
ServoPosition.o: ServoPosition.cc GPIO.h
	g++ -c ServoPosition.cc
clean: 
	rm GPIO.o ServoPosition.o