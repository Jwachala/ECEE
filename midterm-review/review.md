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

## Dynamic vs. static instantiation

### arrays

```c++
//dynamic
//init
int *v = new int[n];
//delete
delete[] v;
```

### class instances

```c++
//static
Rectangle r("Static Rectangle");
//dynamic
Rectangle *pr = new Rectangle("Dynamic Rectangle");
delete pr;
```

## challenge

Do the following, in both a single file, and as a multifile project:

- Create a class that contains a virtual function.
- Create a child of that class that overrides that function
- instantiate that class statically and dynamically
- polymorphise the child class back into the parent

### Single File

```c++
#include <iostream>
class Animal{
    int age;
    std::string name;
public:
    Animal(int age, std::string name){
        this->age = age;
        this->name = name;
    }
    virtual void makeNoise(){
        std::cout << "noise!" << '\n';
    }
};
class Dog : public Animal{
    std::string breed;
public:
    Dog(int age, std::string name,std::string breed): Animal(age, name){
        this->breed = breed;
    }
    void makeNoise(){
        std::cout << "boof!" << '\n';
    }
};
int main(){
    Animal Frank(18, "Frank");
    Animal *David = new Animal(23,"David");
    Dog *Fido = new Dog(14,"Fido","greek");
    Animal *AFido;
    AFido = Fido;
    David->makeNoise();
    AFido->makeNoise();
    Fido->makeNoise();
    delete David;
    delete AFido;
}
```

### Multi File

Animal.h

```c++
#include <iostream>

```

Animal.cc

```c++

```

Dog.h

```c++

```

Dog.cc

```c++

```

main.cc

```c++

```

makefile

```make

```