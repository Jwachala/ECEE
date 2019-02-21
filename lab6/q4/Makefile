ServoSpeed: GPIO.o ServoSpeed.o
	g++ GPIO.o ServoSpeed.o -o ServoSpeed
	
GPIO.o: GPIO.cc GPIO.h
	g++ -c GPIO.cc
ServoSpeed.o: ServoSpeed.cc GPIO.h
	g++ -c ServoSpeed.cc
clean: 
	rm GPIO.o ServoSpeed.o