# Patrick's EECE2160 Midterm review

Like, the stuff he can't remember

## Multi-file projects

### Class.h file

Contains declarations of functions and classes, not implementations.

```c++
// Car.h
#ifndef CAR_H
#define CAR_H
//start with any #includes for the class you're making
#include <string>
//here is where you'll put the class <thing> {} structure, as well as what's public or private
class Car{
    std::string license;
    int year;
public:
    Car(std::string license, int year); //constructor
    std::string getLicense();
    int getAge();
}; //don't forget this wacky semicolon
#endif
```

### Class.cc file

actually implements stuff in .h file

```c++
// Car.cc
// start by including the .h file
#include "Car.h"
//then do the function implementation, the overall structure doesn't go here.
//need to include class namespace (eg Car::) for all functions
Car::Car(std::string license, int year){ //constructor
    this->license = license;
    this->year = year;
}
std::string Car::getLicense(){
    return license;
}
int Car::getAge(){
    return 2016 - year;
}
```

### main.cc

```c++
//make sure include the .h file
#include <iostream>
#include "Car.h"
int main(){
    // License
    std::string license;
    std::cout << "Enter license: ";
    std::cin >> license;

    // Read year
    int year;
    std::cout << "Enter year: ";
    std::cin >> year;

    // Instantiate car
    Car car(license, year); //static instantiation

    // Print car info
    std::cout << "License: " << car.getLicense() << '\n';
    std::cout << "Age: " << car.getAge() << '\n';
    // Done
    return 0;
}
```

## Inheritance

```c++
//in class declaration
class Name : public ParentName{
    //when implementing function too, to pass to super contructor
    Name(int arg1, int arg2) : ParentName(int arg1){
        //implementation
    }
};
```